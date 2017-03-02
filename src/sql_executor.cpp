#include "sql_executor.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>

using namespace std;


int SqlExecutor::execute(ParserCommandContainer const& commands)
{
    if (init_select_context(commands) != 0) {
        return 1;
    }
    cout << "\nSELECT context dump:\n";
    ctx_.dump();

    execute2();

    dump_result();

    return 0;
}


void SqlExecutor::execute2()
{
    if (ctx_.from_tables.size() == 1) {
        // simple FROM (without JOIN)

        size_t table_idx = db_ctx_.get_table_idx(ctx_.from_tables[0].t_name);
        ctx_.table_idx_to_join_pos[table_idx] = 0;

        const sdl::db::datatable& table = db_ctx_.get_table(table_idx);

        for (auto it = table._record.begin();
             it != table._record.end();
             ++it)
        {
            vector<record_iterator> row {it};
            if (execute_where(row))
                eres_.push_back(std::move(row));
        }
    }
    else {
        // FROM + inner JOIN

        assert(ctx_.from_tables.size() == ctx_.join_expr_tree.size() + 1);

        deque<vector<record_iterator>> prev_res;

        // initialize prev_res with all rows of the FROM table
        {
            size_t table_idx = db_ctx_.get_table_idx(ctx_.from_tables[0].t_name);
            ctx_.table_idx_to_join_pos[table_idx] = 0;

            const sdl::db::datatable& table = db_ctx_.get_table(table_idx);

            for (auto it = table._record.begin();
                 it != table._record.end();
                 ++it)
            {
                prev_res.push_back({it});
            }
        }

        // iterate over JOIN tables;
        // each pass produces prev_res elements of increased size
        for (size_t join_idx = 0;
             join_idx < ctx_.join_expr_tree.size();
             ++join_idx)
        {
            size_t table_idx = db_ctx_.get_table_idx(
                        ctx_.from_tables[join_idx + 1].t_name);
            ctx_.table_idx_to_join_pos[table_idx] = join_idx + 1;

            // current JOIN table
            const sdl::db::datatable& table = db_ctx_.get_table(table_idx);

            deque<vector<record_iterator>> cur_res;

            vector<record_iterator> row(join_idx + 2);

            // iterate over results of the previous JOIN
            for (size_t i = 0; i < prev_res.size(); ++i) {
                std::copy(prev_res[i].begin(), prev_res[i].end(), row.begin());

                // iterate over records of current JOIN table

                for (row.back() = table._record.begin();
                     row.back() != table._record.end();
                     ++row.back())
                {
                    if (execute_join(row)
                            // for the final JOIN also apply WHERE
                            && (join_idx < ctx_.join_expr_tree.size() - 1
                                || execute_where(row)))
                    {
                        cur_res.push_back(row);
                    }
                }
            }

            prev_res.swap(cur_res);
        }

        eres_.swap(prev_res);
    }

    execute_order_by();

    if (ctx_.n_top)
        eres_.resize(ctx_.n_top);
}


bool SqlExecutor::execute_join(std::vector<record_iterator> const& row)
{
    using sdl::sql::Value;

    assert(row.size() >= 2);
    assert(row.size() <= ctx_.join_expr_tree.size() + 1);

    Value value;

    // given N = row.size(),
    // row[0] points to the record of the FROM table,
    // row[1] - of the JOIN table [0], ..., row[N-1] - of the JOIN table [N-2]
    // row[0], row[1], ..., row[N-2] records are already checked
    // so we use JOIN expr [N-2] to check a tuple <row[0], ..., row[N-1]>
    assert(execute_expr(row, ctx_.join_expr_tree[row.size() - 2].get(), value) == 0);
    assert(value.which() == static_cast<int>(sdl::sql::ValueType::BOOL));

    return boost::get<bool>(value);
}


bool SqlExecutor::execute_where(std::vector<record_iterator> const& row)
{
    using sdl::sql::Value;

    if (!ctx_.where_expr_tree)
        return true;

    Value value;
    assert(execute_expr(row, ctx_.where_expr_tree.get(), value) == 0);
    assert(value.which() == static_cast<int>(sdl::sql::ValueType::BOOL));

    return boost::get<bool>(value);
}


int SqlExecutor::execute_expr(
        std::vector<record_iterator> const& row,
        ExpressionNode* node,
        sdl::sql::Value& value)
{
    using sdl::sql::Value;
    using sdl::sql::ValueType;

    assert(node);

    if (!node->right) {
        if (node->ot.type != ExprOperandType::IDENTIFIER) {
            // constant value
            value = boost::get<Value>(node->value);
        }
        else {
            // identifier
            Identifier& r = boost::get<Identifier>(node->value);
            size_t t_idx = ctx_.ref_table[r.idx].t_idx;
            size_t join_pos = ctx_.table_idx_to_join_pos.at(t_idx);
            size_t c_idx = ctx_.ref_table[r.idx].c_idx;
            value = sdl::sql::make_value(*row[join_pos], c_idx);
        }
    }
    else {
        // operation
        int r;

        auto op = node->ot.op;

        bool unary =
                op == ExprOperator::NEG
                || op == ExprOperator::NOT;

        if (unary) {
            assert(node->right && !node->left);

            switch (op) {
            case ExprOperator::NOT:
            {
                Value v;
                if ((r = execute_expr(row, node->right.get(), v)) != 0)
                    return r;
                if (v.which() != static_cast<int>(ValueType::BOOL))
                    return 2;
                value = !boost::get<bool>(v);
            }
                break;
            case ExprOperator::NEG:
            {
                Value v;
                if ((r = execute_expr(row, node->right.get(), v)) != 0)
                    return r;
                if (v.which() != static_cast<int>(ValueType::INT32_T))
                    return 2;
                value = -boost::get<int32_t>(v);
            }
                break;
            default:
                assert(false && "unexpected");
            }

        }
        else {
            assert(node->left && node->right);

            switch (op) {
            case ExprOperator::CMP_EQ:
            case ExprOperator::CMP_NEQ:
            case ExprOperator::CMP_GT:
            case ExprOperator::CMP_LT:
            case ExprOperator::CMP_GT_EQ:
            case ExprOperator::CMP_LT_EQ:
            {
                Value v_left;
                if ((r = execute_expr(row, node->left.get(), v_left)) != 0)
                    return r;
                Value v_right;
                if ((r = execute_expr(row, node->right.get(), v_right)) != 0)
                    return r;

                // TODO
                // now operand types must be the same
                if (v_left.which() != v_right.which()) {
                    cerr << "return 2: "
                         << v_left << ' ' << v_left.which() << " : "
                         << v_right << ' ' << v_right.which() << endl;
                    return 2;   // incompatible operand types
                }

                switch (op) {
                case ExprOperator::CMP_EQ:
                    value = v_left == v_right;
                    break;
                case ExprOperator::CMP_NEQ:
                    value = v_left != v_right;
                    break;
                case ExprOperator::CMP_GT:
                    value = v_left > v_right;
                    break;
                case ExprOperator::CMP_LT:
                    value = v_left < v_right;
                    break;
                case ExprOperator::CMP_GT_EQ:
                    value = v_left >= v_right;
                    break;
                case ExprOperator::CMP_LT_EQ:
                    value = v_left <= v_right;
                    break;
                default:
                    assert(false && "unexpected");
                }
            }
                break;
            case ExprOperator::AND:
            {
                Value v;
                if ((r = execute_expr(row, node->left.get(), v)) != 0)
                    return r;
                if (v.which() != static_cast<int>(ValueType::BOOL))
                    return 2;
                if (boost::get<bool>(v) == false) {
                    value = false;
                }
                else {
                    if ((r = execute_expr(row, node->right.get(), v)) != 0)
                        return r;
                    if (v.which() != static_cast<int>(ValueType::BOOL))
                        return 2;
                    value = v;
                }
            }
                break;
            case ExprOperator::OR:
            {
                Value v;
                if ((r = execute_expr(row, node->left.get(), v)) != 0)
                    return r;
                if (v.which() != static_cast<int>(ValueType::BOOL))
                    return 2;
                if (boost::get<bool>(v) == true) {
                    value = true;
                }
                else {
                    if ((r = execute_expr(row, node->right.get(), v)) != 0)
                        return r;
                    if (v.which() != static_cast<int>(ValueType::BOOL))
                        return 2;
                    value = v;
                }
            }
                break;
            default:
                assert(false && "not implemented");
            }
        }
    }

    return 0;
}


void SqlExecutor::execute_order_by()
{
    if (ctx_.order_by_list.empty())
        return;

    struct comparer
    {
        SelectContext const& ctx_;

        explicit comparer(SelectContext const& ctx) : ctx_(ctx) {}

        /*
         * Compares 2 composite rows (join table result) accordingly to
         * order_list.
         */
        bool operator()(std::vector<record_iterator> const& record1,
                        std::vector<record_iterator> const& record2)
        {
            using sdl::sql::Value;

            for (size_t i = 0; i < ctx_.order_by_list.size(); ++i) {
                size_t ref_idx = ctx_.order_by_list[i].idx;

                size_t t_idx = ctx_.ref_table[ref_idx].t_idx;
                size_t c_idx = ctx_.ref_table[ref_idx].c_idx;

                size_t join_pos = ctx_.table_idx_to_join_pos.at(t_idx);
                assert(join_pos < record1.size());

                Value v1 = sdl::sql::make_value(*record1[join_pos], c_idx);
                Value v2 = sdl::sql::make_value(*record2[join_pos], c_idx);

                bool desc = (ctx_.order_by_list[i].flags & F_ORDER_BY_DESC) != 0;
                if (!desc) {
                    if (v1 < v2)
                        return true;
                    else if (v1 > v2)
                        return false;
                }
                else {
                    if (v1 > v2)
                        return true;
                    else if (v1 > v2)
                        return false;
                }

            }
            return false;   // *it1 == *it2
        }
    }
    custom_less(ctx_);

    std::sort(eres_.begin(), eres_.end(), custom_less);
}


void SqlExecutor::dump_result()
{
    cout << "\nResult:\n";

    for (const Identifier& r: ctx_.select_columns) {
        cout << r.t_name << '.' << r.c_name << ' ';
    }
    cout << endl;

    for (vector<record_iterator> const& row: eres_) {
        for (Identifier const& r: ctx_.select_columns) {
            assert(r.idx < ctx_.ref_table.size());
            size_t t_idx = ctx_.ref_table[r.idx].t_idx;
            size_t c_idx = ctx_.ref_table[r.idx].c_idx;
            size_t join_pos = ctx_.table_idx_to_join_pos.at(t_idx);
           cout << sdl::sql::make_value(*row[join_pos], c_idx) << ' ';
        }
        cout << endl;
    }

    cout << '\n' << eres_.size() << " row(s)" << endl;
}


int SqlExecutor::init_select_context(const ParserCommandContainer& cmd)
{
    if (init_select_context1(cmd) != 0)
        return 1;
    if (check_select_context() != 0)
        return 1;
    return 0;
}


int SqlExecutor::check_select_context()
{
    if (check_select_context_from_join() != 0)
        return 1;

    if (check_select_context_select() != 0)
        return 1;

    // check WHERE
    if (check_select_context_where() != 0)
        return 1;

    // check ORDER BY
    if (check_select_context_order_by() != 0)
        return 1;

    // SELECTALL
    if (ctx_.select_columns.empty()) {
        for (Identifier const& tr: ctx_.from_tables) {
            vector<string> c_names = db_ctx_.get_table_column_names(tr.t_name);
            for (auto& s: c_names) {
                Identifier r;
                r.t_name = tr.t_name;
                r.c_name = std::move(s);
                ctx_.select_columns.push_back(std::move(r));
            }
        }
    }

    // add entries to ref_table for select_columns
    for (Identifier& r: ctx_.select_columns) {
        ColumnRef cref;
        cref.t_idx = db_ctx_.get_table_idx(r.t_name);
        cref.c_idx = db_ctx_.get_column_position(r.t_name, r.c_name);
        r.idx = ctx_.ref_table.size();
        ctx_.ref_table.push_back(cref);
    }

    return 0;
}


int SqlExecutor::check_select_context_from_join()
{
    assert(!ctx_.from_tables.empty());
    assert(ctx_.from_tables.size() - 1 == ctx_.join_expr_tree.size());

    // check existence of tables in FROM and JOIN clauses
    for (Identifier& r: ctx_.from_tables) {
        if (!db_ctx_.has_table(r.t_name)) {
            cerr << "Error: FROM: table doesn't exist: " << r.t_name << endl;
            return 1;
        }
    }

    for (size_t i = 0; i < ctx_.join_expr_tree.size(); ++i) {
        sdl::sql::ValueType et;
        if (check_join_expr(i, ctx_.join_expr_tree[i].get(), et) != 0)
            return 1;

        if (et != sdl::sql::ValueType::BOOL) {
            cerr << "Error: JOIN: expression result type is not boolean"
                 << endl;
            return 1;
        }
    }

    return 0;
}


int SqlExecutor::check_select_context_select()
{
    // check identifiers in SELECT
    for (Identifier& r: ctx_.select_columns) {
        if (r.t_name.empty()) {
            if (ctx_.from_tables.size() > 1) {
                cerr << "Error: SELECT: identifier is ambiguous: "
                     << r.c_name << endl;
                return 1;
            }
            r.t_name = ctx_.from_tables[0].t_name;
        }
        else {
            auto it1 = ctx_.from_table_as.find(r.t_name);
            if (it1 == ctx_.from_table_as.end()) {
                auto it2 = find_if(
                            ctx_.from_tables.begin(),
                            ctx_.from_tables.end(),
                            [&r](const Identifier& t)
                {
                    /*
                     * name of the table which have an alias can't be used for
                     * column reference:
                     *
                     * -- error
                     * select Orders.shipname
                     * from Orders O;
                    */
                    return (t.flags & F_HAS_ALIAS) == 0 &&
                            t.t_name == r.t_name;
                });
                if (it2 == ctx_.from_tables.end()) {
                    cerr << "Error: SELECT: identifier could not be found: "
                         << r.t_name << '.' << r.c_name << endl;
                    return 1;
                }
            }
            else {
                // replace alias with real table name
                r.t_name = ctx_.from_tables[it1->second].t_name;
            }
        }

        if (!db_ctx_.has_table_column(r.t_name, r.c_name)) {
            cerr << "Error: SELECT: field references unknown column: "
                 << r.t_name << '.' << r.c_name << endl;
            return 1;
        }
    }

    return 0;
}


int SqlExecutor::check_select_context_where()
{
    // WHERE isn't specified
    if (!ctx_.where_expr_tree)
        return 0;

    sdl::sql::ValueType et;
    if (check_where_expr(ctx_.where_expr_tree.get(), et) != 0)
        return 1;

    if (et != sdl::sql::ValueType::BOOL) {
        cerr << "ERROR: WHERE: expression result type is not boolean"
             << endl;
        return 1;
    }

    return 0;
}


int SqlExecutor::check_join_expr(
        size_t expr_idx,
        ExpressionNode* node,
        sdl::sql::ValueType& expr_type)
{
    using sdl::sql::Value;
    using sdl::sql::ValueType;

    assert(node);

    if (!node->right) {
        // leaf node

        if (node->ot.type == ExprOperandType::IDENTIFIER) {
            // column identifier

            Identifier& r = boost::get<Identifier>(node->value);

            // check identifier

            if (r.t_name.empty()) {
                cerr << "Error: JOIN: identifier is ambiguous: "
                     << r.c_name << endl;
                return 1;
            }

            // search in table aliases
            auto it1 = ctx_.from_table_as.find(r.t_name);
            if (it1 != ctx_.from_table_as.end()) {
                if (it1->second > expr_idx + 1) {
                    cerr << "Error: JOIN: identifier could not be found: "
                         << r.t_name << '.' << r.c_name << endl;
                    return 1;
                }
                r.t_name = ctx_.from_tables[it1->second].t_name;
            }
            else {
                // search in table names
                auto it2 = std::find_if(
                            ctx_.from_tables.begin(),
                            ctx_.from_tables.begin() + expr_idx + 2,
                            [&r](const Identifier& t)
                {
                    return (t.flags & F_HAS_ALIAS) == 0 &&
                            t.t_name == r.t_name;
                });
                if (it2 == ctx_.from_tables.begin() + expr_idx + 2) {
                    cerr << "Error: JOIN: identifier could not be found: "
                         << r.t_name << '.' << r.c_name << endl;
                    return 1;
                }
            }

            // check r' t_name c_name
            if (!db_ctx_.has_table_column(r.t_name, r.c_name)) {
                cerr << "Error: JOIN: table column not found: "
                     << r.t_name << '.' << r.c_name << endl;
                return 1;
            }

            // TODO: now, for simplicity, ref_tables can contain duplicates
            ColumnRef cref;
            cref.t_idx = db_ctx_.get_table_idx(r.t_name);
            cref.c_idx = db_ctx_.get_column_position(r.t_name, r.c_name);
            r.idx = ctx_.ref_table.size();
            ctx_.ref_table.push_back(cref);

            ValueType type = db_ctx_.get_column_value_type(
                        r.t_name, r.c_name);
            assert(type != ValueType::UNKNOWN && "data type is not supported");

            expr_type = type;
        }
        else {
            // constant value

            switch (node->ot.type) {
            case ExprOperandType::INT:
                assert(boost::get<Value>(node->value).which() ==
                                (int)ValueType::INT32_T);
                expr_type = ValueType::INT32_T;
                break;
            case ExprOperandType::STRING:
                assert(boost::get<Value>(node->value).which() ==
                                (int)ValueType::STRING);
                expr_type = ValueType::STRING;
                break;
            default:
                assert(false && "unexpected");
            }
        }
    }
    else {
        // operation

        auto op = node->ot.op;

        bool unary =
                op == ExprOperator::NEG
                || op == ExprOperator::NOT;
        assert(!(unary && node->left));

        ValueType et_right;
        if (check_join_expr(expr_idx, node->right.get(), et_right) != 0)
            return 1;

        bool error = false;

        if (unary) {
            switch (op) {
            case ExprOperator::NOT:
                if (et_right != ValueType::BOOL)
                    error = true;
                else
                    expr_type = ValueType::BOOL;
                break;
            case ExprOperator::NEG:
                if (et_right != ValueType::INT32_T)
                    error = true;
                else
                    expr_type = et_right;
                break;
            default:
                assert(false && "unexpected");
            }
        }
        else {
            ValueType et_left;
            if (check_join_expr(expr_idx, node->left.get(), et_left) != 0)
                return 1;

            switch (op) {
            case ExprOperator::AND:
            case ExprOperator::OR:
                if (et_left != ValueType::BOOL
                        || et_right != ValueType::BOOL)
                    error = true;
                else
                    expr_type = ValueType::BOOL;
                break;
            case ExprOperator::CMP_EQ:
            case ExprOperator::CMP_NEQ:
            case ExprOperator::CMP_GT:
            case ExprOperator::CMP_LT:
            case ExprOperator::CMP_GT_EQ:
            case ExprOperator::CMP_LT_EQ:
                if (et_left == ValueType::STRING
                        && et_right == ValueType::STRING)
                {
                    expr_type = ValueType::BOOL;
                }
                // TODO add more numeric types here
                else if (et_left == ValueType::INT32_T
                         && et_right == ValueType::INT32_T)
                {
                    expr_type = ValueType::BOOL;
                }
                else {
                    error = true;
                }
                break;
            default:
                assert(false && "unexcpected");
            }
        }

        if (error) {
            cerr << "Error: JOIN: incompatible operand types" << endl;
            return 1;
        }
    }

    return 0;
}


int SqlExecutor::check_where_expr(
        ExpressionNode* node,
        sdl::sql::ValueType& expr_type)
{
    using sdl::sql::Value;
    using sdl::sql::ValueType;

    assert(node);

    if (!node->right) {
        // leaf node

        if (node->ot.type == ExprOperandType::IDENTIFIER) {
            // column identifier

            Identifier& r = boost::get<Identifier>(node->value);

            // first check identifier

            if (r.t_name.empty()) {
                /*
                 * select *
                 * from Orders
                 * where shipcountry = 'Brazil';
                 */
                if (ctx_.from_tables.size() > 1) {
                    cerr << "Error: WHERE: identifier could not be found: "
                         << r.c_name << endl;
                    return 1;
                }
                r.t_name = ctx_.from_tables[0].t_name;
            }
            else {
                auto it1 = ctx_.from_table_as.find(r.t_name);
                if (it1 != ctx_.from_table_as.end()) {
                    /*
                     * select *
                     * from Orders O
                     * where O.shipcountry = 'Brazil';
                     */
                    r.t_name = ctx_.from_tables[it1->second].t_name;
                }
                else {
                    auto it2 = find_if(
                                ctx_.from_tables.begin(),
                                ctx_.from_tables.end(),
                                [&r](const Identifier& t)
                    {
                        return (t.flags & F_HAS_ALIAS) == 0 &&
                                t.t_name == r.t_name;
                    });
                    if (it2 == ctx_.from_tables.end()) {
                        /*
                         * select shipname
                         * from Orders O
                         * where Orders.shipcountry = 'Brazil';
                         */
                        cerr << "Error: WHERE: identifier could not be found: "
                             << r.t_name << '.' << r.c_name << endl;
                        return 1;
                    }
                }
            }

            // check r' t_name c_name
            if (!db_ctx_.has_table_column(r.t_name, r.c_name)) {
                cerr << "Error: WHERE: table column not found: "
                     << r.t_name << '.' << r.c_name << endl;
                return 1;
            }

            // TODO: now, for simplicity, ref_tables can contain duplicates
            ColumnRef cref;
            cref.t_idx = db_ctx_.get_table_idx(r.t_name);
            cref.c_idx = db_ctx_.get_column_position(r.t_name, r.c_name);
            r.idx = ctx_.ref_table.size();
            ctx_.ref_table.push_back(cref);

            ValueType type = db_ctx_.get_column_value_type(
                        r.t_name, r.c_name);
            assert(type != ValueType::UNKNOWN && "data type is not supported");

            expr_type = type;
        }
        else {
            // constant value

            switch (node->ot.type) {
            case ExprOperandType::INT:
                assert(boost::get<Value>(node->value).which() ==
                                (int)ValueType::INT32_T);
                expr_type = ValueType::INT32_T;
                break;
            case ExprOperandType::STRING:
                assert(boost::get<Value>(node->value).which() ==
                                (int)ValueType::STRING);
                expr_type = ValueType::STRING;
                break;
            default:
                assert(false && "unexpected");
            }
        }
    }
    else {
        // operation

        auto op = node->ot.op;

        bool unary =
                op == ExprOperator::NEG
                || op == ExprOperator::NOT;
        assert(!(unary && node->left));

        ValueType et_right;
        if (check_where_expr(node->right.get(), et_right) != 0)
            return 1;

        bool error = false;

        if (unary) {
            switch (op) {
            case ExprOperator::NOT:
                if (et_right != ValueType::BOOL)
                    error = true;
                else
                    expr_type = ValueType::BOOL;
                break;
            case ExprOperator::NEG:
                if (et_right != ValueType::INT32_T)
                    error = true;
                else
                    expr_type = et_right;
                break;
            default:
                assert(false && "unexpected");
            }
        }
        else {
            ValueType et_left;
            if (check_where_expr(node->left.get(), et_left) != 0)
                return 1;

            switch (op) {
            case ExprOperator::AND:
            case ExprOperator::OR:
                if (et_left != ValueType::BOOL
                        || et_right != ValueType::BOOL)
                    error = true;
                else
                    expr_type = ValueType::BOOL;
                break;
            case ExprOperator::CMP_EQ:
            case ExprOperator::CMP_NEQ:
            case ExprOperator::CMP_GT:
            case ExprOperator::CMP_LT:
            case ExprOperator::CMP_GT_EQ:
            case ExprOperator::CMP_LT_EQ:
                if (et_left == ValueType::STRING
                        && et_right == ValueType::STRING)
                {
                    expr_type = ValueType::BOOL;
                }
                // TODO add more numeric types here
                else if (et_left == ValueType::INT32_T
                         && et_right == ValueType::INT32_T)
                {
                    expr_type = ValueType::BOOL;
                }
                else {
                    error = true;
                }
                break;
            default:
                assert(false && "unexcpected");
            }
        }

        if (error) {
            cerr << "Error: WHERE: incompatible operand types" << endl;
            return 1;
        }
    }

    return 0;
}


int SqlExecutor::check_select_context_order_by()
{
    for (Identifier& r: ctx_.order_by_list) {
        if (r.t_name.empty()) {
            auto it = ctx_.select_column_as.find(r.c_name);
            if (it != ctx_.select_column_as.end()) {
                /*
                 * select shipname as sname
                 * from Orders O
                 * order by sname;
                 */
                // replace field alias with real table.column
                r.t_name = ctx_.select_columns[it->second].t_name;
                r.c_name = ctx_.select_columns[it->second].c_name;
            }
            else {
                /*
                 * select shipname
                 * from Orders
                 * order by shipcountry;
                 */
                // if there is a single table in FROM, we can take it's name
                if (ctx_.from_tables.size() > 1) {
                    cerr << "Error: ORDER BY: field reference is ambiguous: "
                         << r.c_name << endl;
                    return 1;
                }
                r.t_name = ctx_.from_tables[0].t_name;
            }
        }
        else {
            auto it1 = ctx_.from_table_as.find(r.t_name);
            if (it1 != ctx_.from_table_as.end()) {
                /*
                 * select shipname
                 * from Orders O
                 * order by O.shipcountry;
                 */
                r.t_name = ctx_.from_tables[it1->second].t_name;
            }
            else {
                auto it2 = find_if(
                            ctx_.from_tables.begin(),
                            ctx_.from_tables.end(),
                            [&r](const Identifier& t)
                {
                    return (t.flags & F_HAS_ALIAS) == 0 &&
                            t.t_name == r.t_name;
                });
                if (it2 == ctx_.from_tables.end()) {
                    /*
                     * select shipname
                     * from Orders O
                     * order by Orders.shipcountry;
                     */
                    cerr << "Error: ORDER BY: The multi-part identifier '"
                         << r.t_name << '.' << r.c_name
                         << "' could not be found" << endl;
                    return 1;
                }
            }
        }

        // check r' t_name c_name
        if (!db_ctx_.has_table_column(r.t_name, r.c_name)) {
            cerr << "Error: ORDER BY: field references unknown column: "
                 << r.t_name << '.' << r.c_name << endl;
            return 1;
        }

        // TODO: now, for simplicity, ref_tables can contain duplicates
        ColumnRef cref;
        cref.t_idx = db_ctx_.get_table_idx(r.t_name);
        cref.c_idx = db_ctx_.get_column_position(r.t_name, r.c_name);
        r.idx = ctx_.ref_table.size();
        ctx_.ref_table.push_back(cref);
    }

    return 0;
}


int SqlExecutor::init_select_context1(const ParserCommandContainer& cmd)
{
    if (cmd.empty())
        return 1;

    auto ite = cmd.end() - 1;
    if (ite->op_ != ParserOpCode::SELECT)
        return 1;

    ctx_.n_select = ite->int_;
    if (ctx_.n_select < 1)
        return 1;
    --ite;

    ctx_.n_top = 0;
    auto itb = cmd.begin();
    if (itb->op_ == ParserOpCode::TOP) {
        ctx_.n_top = itb->int_;
        ++itb;
    }

    // SELECT
    if (ctx_.n_select == 1 && itb->op_ == ParserOpCode::SELECT_ALL) {
        ++itb;
    }
    else {
        for (int i = 0; i < ctx_.n_select; ++i) {
            assert(itb->op_ == ParserOpCode::FIELD || itb->op_ == ParserOpCode::NAME);

            Identifier ref;
            if (itb->op_ == ParserOpCode::FIELD)
                ref.t_name = itb->name1_;
            ref.c_name = itb->name2_;
            ctx_.select_columns.push_back(std::move(ref));

            ++itb;

            if (itb->op_ == ParserOpCode::AS) {
                auto res = ctx_.select_column_as.insert(
                            make_pair(itb->name2_,
                                      ctx_.select_columns.size() - 1));
                if (!res.second) {
                    cerr << "Error: duplicated column alias: "
                         << itb->name2_
                         << endl;
                    return 1;
                }
                ++itb;
            }
        }
    }

    // itb now points to the begin of FROM part

    // ORDER BY
    if (ite->op_ == ParserOpCode::ORDER_BY) {
        if (init_select_context_order_by(ite, ite) != 0) {
            return 1;
        }
    }

    // WHERE
    if (ite->op_ == ParserOpCode::WHERE) {
        if (init_select_context_where(ite, ite) != 0) {
            return 1;
        }
        assert(ctx_.where_expr_tree);
    }

    /*
     * TABLE Customers  <--- itb
     * AS c
     * ...
     * JOIN
     * FROM             <--- ite
     */
    assert(ite->op_ == ParserOpCode::FROM);
    assert(ite - itb >= 1);

    // FROM
    if (init_select_context_from(itb, ite) != 0) {
        return 1;
    }

    return 0;
}


int SqlExecutor::init_select_context_from(
        const ParserCommandContainer::const_iterator start,
        const ParserCommandContainer::const_iterator end)
{
    /*
     * TABLE Customers  <--- start
     * AS c
     * ...
     * JOIN
     * FROM             <--- end
     */

    auto itb = start;

    // process the main TABLE statement (which is not a part of JOIN)
    if (init_select_context_from_add_table(itb, itb) != 0)
        return 1;

    // process JOIN parts (if any)
    /*
     * ...
     * TABLE Orders     <--- itb
     * AS O
     * FIELD C.custid
     * FIELD O.custid
     * COMPARISON 4
     * JOIN
     * ...
     * ...
     * JOIN
     * FROM             <--- end
     */
    while (itb != end) {
        if (init_select_context_from_add_table(itb, itb) != 0)
            return 1;
        if (init_select_context_from_add_join(itb, end, itb) != 0)
            return 1;
    }

    return 0;
}


int SqlExecutor::init_select_context_from_add_join(
        const ParserCommandContainer::const_iterator start,
        const ParserCommandContainer::const_iterator end,
        ParserCommandContainer::const_iterator& next_part)
{
    /*
     * FIELD C.custid   <--- start
     * FIELD O.custid
     * COMPARISON 4
     * JOIN
     * ...
     * ...
     * JOIN
     * FROM             <--- end
     */

    auto it_join = std::find_if(start, end, [](auto const& e)
    {
        return e.op_ == ParserOpCode::JOIN;
    });
    assert(it_join != end);
    assert(it_join > start);

    next_part = it_join + 1;

    ParserCommandContainer::const_iterator dummy;
    ExpressionNodePtr node = build_expr_tree(it_join - 1, start - 1, dummy);

    ctx_.join_expr_tree.push_back(std::move(node));

    return 0;
}


int SqlExecutor::init_select_context_from_add_table(
        const ParserCommandContainer::const_iterator start,
        ParserCommandContainer::const_iterator& next_part)
{
    auto it = start;

    assert(it->op_ == ParserOpCode::TABLE);

    Identifier ref;
    ref.t_name = it->name2_;
    ctx_.from_tables.push_back(std::move(ref));
    ++it;

    if (it->op_ == ParserOpCode::AS) {
        auto res = ctx_.from_table_as.insert(
                    make_pair(it->name2_, ctx_.from_tables.size() - 1));
        if (!res.second) {
            cerr << "Error: duplicated table alias: "
                 << it->name2_
                 << endl;
            return 1;
        }
        ctx_.from_tables.back().flags |= F_HAS_ALIAS;
        ++it;
    }

    next_part = it;

    return 0;
}


int SqlExecutor::init_select_context_where(
        const ParserCommandContainer::const_iterator start,
        ParserCommandContainer::const_iterator& next_part)
{
    assert(start->op_ == ParserOpCode::WHERE);

    auto it = start - 1;
    while (it->op_ != ParserOpCode::FROM) {
        --it;
    }
    assert(start - it > 1);

    next_part = it;

    ctx_.where_expr_tree = build_expr_tree(start - 1, it, it);
    assert(it == next_part); // check that PN was visited completely

    return 0;
}


int SqlExecutor::init_select_context_order_by(
        const ParserCommandContainer::const_iterator start,
        ParserCommandContainer::const_iterator& next_part)
{
    assert(start->op_ == ParserOpCode::ORDER_BY);
//    cout << "ORDER BY" << endl;

    auto it = start - 1;
    while (it->op_ != ParserOpCode::WHERE && it->op_ != ParserOpCode::FROM) {
        --it;
    }
    assert(start - it > 1);

    next_part = it;

    ++it;
    while (it->op_ != ParserOpCode::ORDER_BY) {
        assert(it->op_ == ParserOpCode::FIELD || it->op_ == ParserOpCode::NAME);

        Identifier ref;

        if (it->op_ == ParserOpCode::FIELD)
            ref.t_name = it->name1_;
        ref.c_name = it->name2_;
        ++it;

        if (it->op_ == ParserOpCode::ASC) {
            ++it;
        }
        else if (it->op_ == ParserOpCode::DESC) {
            ref.flags = F_ORDER_BY_DESC;
            ++it;
        }

        ctx_.order_by_list.push_back(std::move(ref));
    }

    return 0;
}


/*
 * FROM             <--- end
 * ...
 * OPERATOR 6       <--- start
 * WHERE
 *
 *
 */
SqlExecutor::ExpressionNodePtr SqlExecutor::build_expr_tree(
        const ParserCommandContainer::const_iterator start,
        const ParserCommandContainer::const_iterator end,
        ParserCommandContainer::const_iterator& out)
{
    ExpressionNodePtr node(new ExpressionNode);

    auto it = start;
    if (it->op_ == ParserOpCode::OPERATOR || it->op_ == ParserOpCode::COMPARISON) {
        node->ot.op = static_cast<ExprOperator>(it->int_);

        --it;
        assert(it >= end);

        node->right = build_expr_tree(it, end, it);

        // unary
        if (!(node->ot.op == ExprOperator::NOT
                || node->ot.op == ExprOperator::NEG
                || node->ot.op == ExprOperator::IS_NULL))
        {
            node->left = build_expr_tree(it, end, it);
        }
    }
    else {
        switch (it->op_)
        {

        case ParserOpCode::NAME:
        {
            Identifier ref;
            ref.c_name = it->name2_;

            node->ot.type = ExprOperandType::IDENTIFIER;
            node->value = std::move(ref);
        }
            break;

        case ParserOpCode::FIELD:
        {
            Identifier ref;
            ref.t_name = it->name1_;
            ref.c_name = it->name2_;

            node->ot.type = ExprOperandType::IDENTIFIER;
            node->value = std::move(ref);
        }
            break;

        case ParserOpCode::NUMBER:
            node->ot.type = ExprOperandType::INT;
            node->value = it->int_;
            break;

        case ParserOpCode::STRING:
            node->ot.type = ExprOperandType::STRING;
            node->value = it->string_;
            break;

        default:
            assert(false && "unexpected");
        }

        --it;
        assert(it >= end);
    }

    out = it;

    return node;
}
