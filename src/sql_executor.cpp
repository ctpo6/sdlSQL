#include "sql_executor.hpp"

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

    return 0;
}


int SqlExecutor::init_select_context(
        const EmitRecordContainer& em,
        SelectContext& ctx)
{
    if (init_select_context1(emit_, ctx_) != 0) {
        return 1;
    }
    if (init_select_context2(db_ctx_, ctx_) != 0) {
        return 1;
    }
    return 0;
}


int SqlExecutor::init_select_context2(
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

    string single_table_name = ctx.from_tables.size() == 1 ?
                ctx.from_tables[0].t_name : string();

    // check identifiers in SELECT
    for (SymbolReference& r: ctx.select_columns) {
        if (r.t_name.empty()) {
            if (single_table_name.empty()) {
                cerr << "Error: SELECT: missing table name for column: "
                     << r.c_name << endl;
                return 1;
            }
            r.t_name = single_table_name;
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

    // check WHERE

    // check ORDER BY
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
                 * from Orders O
                 * order by shipcountry;
                 */
                // if there is a single table in FROM, we can take it's name
                if (single_table_name.empty()) {
                    cerr << "ERROR: ORDER BY: field reference is ambiguous (table is not specified): "
                         << r.c_name << endl;
                    return 1;
                }
                r.t_name = single_table_name;
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
                    cerr << "ERROR: ORDER BY: The multi-part identifier '"
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

    auto ite = end - 1;
    if (ite->op_ == EmitOp::JOIN) {
        cerr << "Error: JOIN is not implemented" << endl;
        return 1;
    }

    auto itb = start;
    assert(itb->op_ == EmitOp::TABLE);

    {
        SymbolReference ref;
        ref.t_name = itb->name2_;
        ctx.from_tables.push_back(std::move(ref));
        ++itb;
    }

    if (itb->op_ == EmitOp::AS) {
        auto res = ctx.from_table_as.insert(make_pair(itb->name2_, 0));
        if (!res.second) {
            cerr << "Error: duplicated column alias: "
                 << itb->name2_
                 << endl;
            return 1;
        }
        ctx.from_tables.back().flags |= F_HAS_ALIAS;
        ++itb;
    }

    assert(itb - 1 == ite);

    return 0;
}


int SqlExecutor::init_select_context_where(
        const EmitRecordContainer::const_iterator start,
        EmitRecordContainer::const_iterator& next_part,
        SelectContext& ctx)
{
    assert(start->op_ == EmitOp::WHERE);
//    cout << "WHERE" << endl;

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
                || node->ot.op == ExprOperator::IS_NULL)) {
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
