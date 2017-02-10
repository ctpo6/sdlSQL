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
    cout << "select context dump:\n";
    ctx_.dump();

    return 0;
}


int SqlExecutor::init_select_context(
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
            assert(itb->op_ == EmitOp::FIELD);

            SymbolReference ref;
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
        ref.t_name = itb->name1_;
        ref.c_name = itb->name2_;
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
