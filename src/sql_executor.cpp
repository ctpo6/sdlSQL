#include "sql_executor.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>

using namespace std;


int SqlExecutor::execute()
{
    cout << "init_select_context...\n";
    if (init_select_context(emit_, ctx_) != 0) {
        return 1;
    }
    cout << "\nselect context dump:\n";
    ctx_.dump();

    execute1();

    dump_result();

    return 0;
}


void SqlExecutor::execute1()
{
    const sdl::db::datatable& table = db_ctx_.get_table(
                ctx_.from_tables[0].t_name);
    for (auto it = table._record.begin();
         it != table._record.end();
         ++it)
    {
        if (execute_where(it))
            res_.records.push_back(it);
    }

    execute_order_by();

    if (ctx_.n_top)
        res_.records.resize(ctx_.n_top);
}


bool SqlExecutor::execute_where(ExecutionResult::record_iterator it)
{
    using sdl::sql::Value;

    if (!ctx_.where_expr_tree)
        return true;

    Value value;
    assert(execute_expr(it, ctx_.where_expr_tree.get(), value) == 0);
    assert(value.which() == static_cast<int>(sdl::sql::ValueType::BOOL));

    return boost::get<bool>(value);
}


int SqlExecutor::execute_expr(
        ExecutionResult::record_iterator record_it,
        ExpressionNode* node,
        sdl::sql::Value& value)
{
    using sdl::sql::Value;
    using sdl::sql::ValueType;

    assert(node);

    if (!node->right) {
        if (node->ot.type != ExprOperandType::REF) {
            // constant value
            value = boost::get<Value>(node->value);
        }
        else {
            // column identifier
            SymbolReference& r = boost::get<SymbolReference>(node->value);
            value = sdl::sql::make_value(
                        *record_it, ctx_.where_symbol_table[r.idx]);
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
                if ((r = execute_expr(record_it, node->right.get(), v)) != 0)
                    return r;
                if (v.which() != static_cast<int>(ValueType::BOOL))
                    return 2;
                value = !boost::get<bool>(v);
            }
                break;
            case ExprOperator::NEG:
            {
                Value v;
                if ((r = execute_expr(record_it, node->right.get(), v)) != 0)
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
                if ((r = execute_expr(record_it, node->left.get(), v_left)) != 0)
                    return r;
                Value v_right;
                if ((r = execute_expr(record_it, node->right.get(), v_right)) != 0)
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
                if ((r = execute_expr(record_it, node->left.get(), v)) != 0)
                    return r;
                if (v.which() != static_cast<int>(ValueType::BOOL))
                    return 2;
                if (boost::get<bool>(v) == false) {
                    value = false;
                }
                else {
                    if ((r = execute_expr(record_it, node->right.get(), v)) != 0)
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
                if ((r = execute_expr(record_it, node->left.get(), v)) != 0)
                    return r;
                if (v.which() != static_cast<int>(ValueType::BOOL))
                    return 2;
                if (boost::get<bool>(v) == true) {
                    value = true;
                }
                else {
                    if ((r = execute_expr(record_it, node->right.get(), v)) != 0)
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
        // pairs: <col_idx, asc/desc flag>
        vector<pair<size_t, bool>> order_list;

        comparer(DatabaseContext const& db_ctx,
                 vector<SymbolReference> const& ol) :
            order_list(ol.size())
        {
            for (size_t i = 0; i < order_list.size(); ++i) {
                order_list[i].first = db_ctx.get_column_position(
                            ol[i].t_name,
                            ol[i].c_name);
                order_list[i].second = (ol[i].flags & F_ORDER_BY_DESC) != 0;
            }
        }

        bool operator()(ExecutionResult::record_iterator it1,
                        ExecutionResult::record_iterator it2)
        {
            for (size_t i = 0; i < order_list.size(); ++i) {
                size_t col_idx = order_list[i].first;
                sdl::sql::Value v1 = sdl::sql::make_value(*it1, col_idx);
                sdl::sql::Value v2 = sdl::sql::make_value(*it2, col_idx);

                bool desc = order_list[i].second;
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
    custom_less(db_ctx_, ctx_.order_by_list);

    std::sort(res_.records.begin(), res_.records.end(), custom_less);
}


void SqlExecutor::dump_result()
{
    cout << "\nResult:\n";

    for (const SymbolReference& r: ctx_.select_columns) {
        cout << r.t_name << '.' << r.c_name << ' ';
    }
    cout << endl;

    vector<size_t> col_idx(ctx_.select_columns.size());
    for (size_t i = 0; i < ctx_.select_columns.size(); ++i) {
        col_idx[i] = db_ctx_.get_column_position(
                    ctx_.select_columns[i].t_name,
                    ctx_.select_columns[i].c_name);
    }

    for (auto record_it: res_.records) {
        for (size_t idx: col_idx) {
            cout << sdl::sql::make_value(*record_it, idx) << ' ';
        }
        cout << endl;
    }

    cout << '\n' << res_.records.size() << " row(s)" << endl;
}


int SqlExecutor::init_select_context(
        const EmitRecordContainer& em,
        SelectContext& ctx)
{
    if (init_select_context1(emit_, ctx_) != 0) {
        return 1;
    }
    if (check_select_context(db_ctx_, ctx_) != 0) {
        return 1;
    }
    return 0;
}


int SqlExecutor::check_select_context(
        const DatabaseContext& db_ctx,
        SelectContext& ctx)
{
    // check existence of tables in FROM and JOIN clauses
    assert(!ctx.from_tables.empty());
    for (SymbolReference& r: ctx.from_tables) {
        if (!db_ctx.has_table(r.t_name)) {
            cerr << "Error: FROM: table doesn't exist: " << r.t_name << endl;
            return 1;
        }
    }

    if (check_select_context_select(db_ctx, ctx) != 0)
        return 1;

    // check WHERE
    if (check_select_context_where(db_ctx, ctx) != 0)
        return 1;

    // check ORDER BY
    if (check_select_context_order_by(db_ctx, ctx) != 0)
        return 1;

    // SELECTALL
    if (ctx.select_columns.empty()) {
        const string& t_name = ctx.from_tables[0].t_name;
        vector<string> c_names = db_ctx.get_table_column_names(t_name);
        for (auto& s: c_names) {
            SymbolReference r;
            r.t_name = t_name;
            r.c_name = std::move(s);
            ctx.select_columns.push_back(std::move(r));
        }
    }

    return 0;
}


int SqlExecutor::check_select_context_select(
        const DatabaseContext& db_ctx,
        SelectContext& ctx)
{
    // check identifiers in SELECT
    for (SymbolReference& r: ctx.select_columns) {
        if (r.t_name.empty()) {
            if (ctx.from_tables.size() > 1) {
                cerr << "Error: SELECT: missing table name for column: "
                     << r.c_name << endl;
                return 1;
            }
            r.t_name = ctx.from_tables[0].t_name;
        }
        else {
            auto it1 = ctx.from_table_as.find(r.t_name);
            if (it1 == ctx.from_table_as.end()) {
                auto it2 = find_if(
                            ctx.from_tables.begin(),
                            ctx.from_tables.end(),
                            [&r](const SymbolReference& t)
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
                if (it2 == ctx.from_tables.end()) {
                    cerr << "Error: SELECT: The multi-part identifier '"
                         << r.t_name << '.' << r.c_name
                         << "' could not be found" << endl;
                    return 1;
                }
            }
            else {
                // replace alias with real table name
                r.t_name = ctx.from_tables[it1->second].t_name;
            }
        }

        if (!db_ctx.has_table_column(r.t_name, r.c_name)) {
            cerr << "Error: SELECT: field references unknown column: "
                 << r.t_name << '.' << r.c_name << endl;
            return 1;
        }
    }

    return 0;
}


int SqlExecutor::check_select_context_where(
        const DatabaseContext& db_ctx,
        SelectContext& ctx)
{
    // WHERE isn't specified
    if (!ctx.where_expr_tree)
        return 0;

    sdl::sql::ValueType et;
    if (check_where_expr(db_ctx, ctx, ctx.where_expr_tree.get(), et) != 0)
        return 1;

    if (et != sdl::sql::ValueType::BOOL) {
        cerr << "ERROR: WHERE: the expression result type is not boolean"
             << endl;
        return 1;
    }

    return 0;
}


int SqlExecutor::check_where_expr(
        const DatabaseContext& db_ctx,
        SelectContext& ctx,
        ExpressionNode* node,
        sdl::sql::ValueType& expr_type)
{
    using sdl::sql::Value;
    using sdl::sql::ValueType;

    assert(node);

    if (!node->right) {
        // leaf node

        if (node->ot.type == ExprOperandType::REF) {
            // column identifier

            SymbolReference& r = boost::get<SymbolReference>(node->value);

            // first check identifier

            if (r.t_name.empty()) {
                /*
                 * select *
                 * from Orders
                 * where shipcountry = 'Brazil';
                 */
                if (ctx.from_tables.size() > 1) {
                    cerr << "Error: WHERE: identifier could not be found: "
                         << r.c_name << endl;
                    return 1;
                }
                r.t_name = ctx.from_tables[0].t_name;
            }
            else {
                auto it1 = ctx.from_table_as.find(r.t_name);
                if (it1 != ctx.from_table_as.end()) {
                    /*
                     * select *
                     * from Orders O
                     * where O.shipcountry = 'Brazil';
                     */
                    r.t_name = ctx.from_tables[it1->second].t_name;
                }
                else {
                    auto it2 = find_if(
                                ctx.from_tables.begin(),
                                ctx.from_tables.end(),
                                [&r](const SymbolReference& t)
                    {
                        return (t.flags & F_HAS_ALIAS) == 0 &&
                                t.t_name == r.t_name;
                    });
                    if (it2 == ctx.from_tables.end()) {
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
            if (!db_ctx.has_table_column(r.t_name, r.c_name)) {
                cerr << "Error: WHERE: table column not found: "
                     << r.t_name << '.' << r.c_name << endl;
                return 1;
            }

            // add to symbol table; not it contains only column indexes

            // TODO
            // now, for simplicity, don't check duplicates
            size_t col_idx = db_ctx.get_column_position(r.t_name, r.c_name);
            r.idx = ctx.where_symbol_table.size();
            ctx.where_symbol_table.push_back(col_idx);

            ValueType type = db_ctx.get_column_value_type(
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
        if (check_where_expr(db_ctx, ctx, node->right.get(), et_right) != 0)
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
            if (check_where_expr(db_ctx, ctx, node->left.get(), et_left) != 0)
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


int SqlExecutor::check_select_context_order_by(
        const DatabaseContext& db_ctx,
        SelectContext& ctx)
{
    for (SymbolReference& r: ctx.order_by_list) {
        if (r.t_name.empty()) {
            auto it = ctx.select_column_as.find(r.c_name);
            if (it != ctx.select_column_as.end()) {
                /*
                 * select shipname as sname
                 * from Orders O
                 * order by sname;
                 */
                // replace field alias with real table.column
                r.t_name = ctx.select_columns[it->second].t_name;
                r.c_name = ctx.select_columns[it->second].c_name;
            }
            else {
                /*
                 * select shipname
                 * from Orders
                 * order by shipcountry;
                 */
                // if there is a single table in FROM, we can take it's name
                if (ctx.from_tables.size() > 1) {
                    cerr << "Error: ORDER BY: field reference is ambiguous: "
                         << r.c_name << endl;
                    return 1;
                }
                r.t_name = ctx.from_tables[0].t_name;
            }
        }
        else {
            auto it1 = ctx.from_table_as.find(r.t_name);
            if (it1 != ctx.from_table_as.end()) {
                /*
                 * select shipname
                 * from Orders O
                 * order by O.shipcountry;
                 */
                r.t_name = ctx.from_tables[it1->second].t_name;
            }
            else {
                auto it2 = find_if(
                            ctx.from_tables.begin(),
                            ctx.from_tables.end(),
                            [&r](const SymbolReference& t)
                {
                    return (t.flags & F_HAS_ALIAS) == 0 &&
                            t.t_name == r.t_name;
                });
                if (it2 == ctx.from_tables.end()) {
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
        if (!db_ctx.has_table_column(r.t_name, r.c_name)) {
            cerr << "Error: ORDER BY: field references unknown column: "
                 << r.t_name << '.' << r.c_name << endl;
            return 1;
        }
    }

    return 0;
}


int SqlExecutor::init_select_context1(
        const EmitRecordContainer& em,
        SelectContext& ctx)
{
    if (em.empty())
        return 1;

    auto ite = em.end() - 1;
    if (ite->op_ != EmitOp::SELECT)
        return 1;

    ctx.n_select = ite->int_;
    if (ctx.n_select < 1)
        return 1;
    --ite;

    ctx.n_top = 0;
    auto itb = em.begin();
    if (itb->op_ == EmitOp::TOP) {
        ctx.n_top = itb->int_;
        ++itb;
    }

    // SELECT
    if (ctx.n_select == 1 && itb->op_ == EmitOp::SELECT_ALL) {
        ++itb;
    }
    else {
        for (int i = 0; i < ctx.n_select; ++i) {
            assert(itb->op_ == EmitOp::FIELD || itb->op_ == EmitOp::NAME);

            SymbolReference ref;
            if (itb->op_ == EmitOp::FIELD)
                ref.t_name = itb->name1_;
            ref.c_name = itb->name2_;
            ctx.select_columns.push_back(std::move(ref));

            ++itb;

            if (itb->op_ == EmitOp::AS) {
                auto res = ctx.select_column_as.insert(
                            make_pair(itb->name2_,
                                      ctx.select_columns.size() - 1));
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
    if (ite->op_ == EmitOp::ORDER_BY) {
        if (init_select_context_order_by(ite, ite, ctx) != 0) {
            return 1;
        }
    }

    // WHERE
    if (ite->op_ == EmitOp::WHERE) {
        if (init_select_context_where(ite, ite, ctx) != 0) {
            return 1;
        }
        assert(ctx.where_expr_tree);
    }

    /*
     * TABLE Customers  <--- itb
     * AS c
     * ...
     * JOIN
     * FROM             <--- ite
     */
    assert(ite->op_ == EmitOp::FROM);
    assert(ite - itb >= 1);

    // FROM
    if (init_select_context_from(itb, ite, ctx) != 0) {
        return 1;
    }

    return 0;
}


int SqlExecutor::init_select_context_from(
        const EmitRecordContainer::const_iterator start,
        const EmitRecordContainer::const_iterator end,
        SelectContext& ctx)
{
    /*
     * TABLE Customers  <--- start
     * AS c
     * ...
     * JOIN
     * FROM             <--- end
     */

//    auto ite = end - 1;
//    if (ite->op_ == EmitOp::JOIN) {
//        cerr << "Error: JOIN is not implemented" << endl;
//        return 1;
//    }

    auto itb = start;
    if (init_select_context_from_add_table(itb, itb, ctx) != 0)
        return 1;
    assert(itb == end);

    return 0;
}


int SqlExecutor::init_select_context_from_add_table(
        const EmitRecordContainer::const_iterator start,
        EmitRecordContainer::const_iterator& next_part,
        SelectContext& ctx)
{
    auto it = start;

    assert(it->op_ == EmitOp::TABLE);

    SymbolReference ref;
    ref.t_name = it->name2_;
    ctx.from_tables.push_back(std::move(ref));
    ++it;

    if (it->op_ == EmitOp::AS) {
        auto res = ctx.from_table_as.insert(make_pair(it->name2_, 0));
        if (!res.second) {
            cerr << "Error: duplicated table alias: "
                 << it->name2_
                 << endl;
            return 1;
        }
        ctx.from_tables.back().flags |= F_HAS_ALIAS;
        ++it;
    }

    next_part = it;

    return 0;
}


int SqlExecutor::init_select_context_where(
        const EmitRecordContainer::const_iterator start,
        EmitRecordContainer::const_iterator& next_part,
        SelectContext& ctx)
{
    assert(start->op_ == EmitOp::WHERE);

    auto it = start - 1;
    while (it->op_ != EmitOp::FROM) {
        --it;
    }
    assert(start - it > 1);

    next_part = it;

    ctx.where_expr_tree = build_expr_tree(start - 1, it, it);
    assert(it == next_part); // check that PN was visited completely

    return 0;
}


int SqlExecutor::init_select_context_order_by(
        const EmitRecordContainer::const_iterator start,
        EmitRecordContainer::const_iterator& next_part,
        SelectContext& ctx)
{
    assert(start->op_ == EmitOp::ORDER_BY);
//    cout << "ORDER BY" << endl;

    auto it = start - 1;
    while (it->op_ != EmitOp::WHERE && it->op_ != EmitOp::FROM) {
        --it;
    }
    assert(start - it > 1);

    next_part = it;

    ++it;
    while (it->op_ != EmitOp::ORDER_BY) {
        assert(it->op_ == EmitOp::FIELD || it->op_ == EmitOp::NAME);

        SymbolReference ref;

        if (it->op_ == EmitOp::FIELD)
            ref.t_name = it->name1_;
        ref.c_name = it->name2_;
        ++it;

        if (it->op_ == EmitOp::ASC) {
            ++it;
        }
        else if (it->op_ == EmitOp::DESC) {
            ref.flags = F_ORDER_BY_DESC;
            ++it;
        }

        ctx.order_by_list.push_back(std::move(ref));
    }

    return 0;
}


SqlExecutor::ExpressionNodePtr SqlExecutor::build_expr_tree(
        const EmitRecordContainer::const_iterator start,
        const EmitRecordContainer::const_iterator end,
        EmitRecordContainer::const_iterator& out)
{
    ExpressionNodePtr node(new ExpressionNode);

    auto it = start;
    if (it->op_ == EmitOp::OPERATOR || it->op_ == EmitOp::COMPARISON) {
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

        case EmitOp::NAME:
        {
            SymbolReference ref;
            ref.c_name = it->name2_;

            node->ot.type = ExprOperandType::REF;
            node->value = std::move(ref);
        }
            break;

        case EmitOp::FIELD:
        {
            SymbolReference ref;
            ref.t_name = it->name1_;
            ref.c_name = it->name2_;

            node->ot.type = ExprOperandType::REF;
            node->value = std::move(ref);
        }
            break;

        case EmitOp::NUMBER:
            node->ot.type = ExprOperandType::INT;
            node->value = it->int_;
            break;

        case EmitOp::STRING:
            node->ot.type = ExprOperandType::STRING;
            node->value = it->string_;
            break;

        default:
            assert(false && "unexpected EmitOp");
        }

        --it;
        assert(it >= end);
    }

    out = it;

    return node;
}
