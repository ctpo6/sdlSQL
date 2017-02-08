#include "sql_executor.hpp"

#include <cassert>
#include <iostream>
#include <type_traits>

using namespace std;


std::ostream& operator<<(std::ostream& os, const ExprOperator e)
{
    return os << static_cast<std::underlying_type<ExprOperator>::type>(e);
}


int SqlExecutor::walk()
{
    cout << "\nwalk:\n";

    if (emit_.empty())
        return 1;

    auto ite = emit_.end() - 1;
    if (ite->op_ != EmitOp::SELECT)
        return 1;

    int n_select = ite->int_;
    if (n_select < 1)
        return 1;
    cout << "SELECT " << n_select << endl;
    --ite;

    int n_top = 0;
    auto itb = emit_.begin();
    if (itb->op_ == EmitOp::TOP) {
        n_top = itb->int_;
        ++itb;
        cout << "TOP " << n_top << endl;
    }

    bool f_select_all = false;

    for (int i = 0; i < n_select; ++i) {
        assert(!f_select_all);  // can be set only once
        assert(itb->op_ == EmitOp::SELECT_ALL || itb->op_ == EmitOp::FIELD);
        if (itb->op_ == EmitOp::SELECT_ALL) {
            f_select_all = true;
            cout << "SELECT_ALL" << endl;
        }
        else {
            cout << "FIELD " << itb->name1_ << ' ' << itb->name2_ << endl;
        }
        ++itb;

        if (itb->op_ == EmitOp::AS) {
            cout << "AS " << itb->name2_ << endl;
            ++itb;
        }
    }
    // itb now points to the begin of FROM part

    // ORDER BY
    if (ite->op_ == EmitOp::ORDER_BY) {
        if (walk_order_by(ite, ite) != 0) {
            return 1;
        }
    }

    // WHERE
    if (ite->op_ == EmitOp::WHERE) {
        if (walk_where(ite, ite) != 0) {
            return 1;
        }
    }

    return 0;
}


SqlExecutor::ExpressionNodePtr SqlExecutor::build_expr_tree(
        const EmitRecordContainer::iterator start,
        const EmitRecordContainer::iterator end,
        EmitRecordContainer::iterator& out)
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
            node->ot.type = ExprOperandType::REF;
            node->value = it->name2_;
            break;
        case EmitOp::FIELD:
            node->ot.type = ExprOperandType::REF;
            node->value = it->name1_ + "." + it->name2_;
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


int SqlExecutor::walk_where(
        const EmitRecordContainer::iterator start,
        EmitRecordContainer::iterator& next_part)
{
    assert(start->op_ == EmitOp::WHERE);
    cout << "WHERE" << endl;

    auto it = start - 1;
    while (it->op_ != EmitOp::FROM) {
        --it;
    }
    assert(start - it > 1);

    next_part = it;

    where_expr_tree_ = build_expr_tree(start - 1, it, it);
    assert(it == next_part); // check that PN was visited completely

    return 0;
}


int SqlExecutor::walk_order_by(
        const EmitRecordContainer::iterator start,
        EmitRecordContainer::iterator& next_part)
{
    assert(start->op_ == EmitOp::ORDER_BY);
    cout << "ORDER BY" << endl;

    auto it = start - 1;
    while (it->op_ != EmitOp::WHERE && it->op_ != EmitOp::FROM) {
        --it;
    }
    assert(start - it > 1);

    next_part = it;

    ++it;
    while (it->op_ != EmitOp::ORDER_BY) {
        assert(it->op_ == EmitOp::FIELD || it->op_ == EmitOp::NAME);
        if (it->op_ == EmitOp::NAME) {
            cout << "NAME " << it->name2_ << endl;
        }
        else {
            cout << "FIELD " << it->name1_ << '.' << it->name2_ << endl;
        }
        ++it;

        if (it->op_ == EmitOp::ASC) {
            cout << "ASC" << endl;
            ++it;
        }
        else if (it->op_ == EmitOp::DESC) {
            cout << "DESC" << endl;
            ++it;
        }
    }

    return 0;
}


int SqlExecutor::execute()
{
    return walk();
}


SqlExecutor::EmitRecord SqlExecutor::make_emit_record(EmitOp op)
{
    EmitRecord e;
    e.op_ = op;
    return e;
}


SqlExecutor::EmitRecord SqlExecutor::make_emit_record(
        EmitOp op,
        int param)
{
    EmitRecord e;
    e.op_ = op;
    e.int_ = param;
    return e;
}

SqlExecutor::EmitRecord SqlExecutor::make_emit_record(
        EmitOp op,
        const std::string& param)
{
    EmitRecord e;
    e.op_ = op;
    e.string_ = param;
    return e;
}

SqlExecutor::EmitRecord SqlExecutor::make_emit_record(
        EmitOp op,
        const std::string& name1,
        const std::string& name2)
{
    EmitRecord e;
    e.op_ = op;
    e.name1_ = name1;
    e.name2_ = name2;
    return e;
}


void SqlExecutor::emit(EmitOp op)
{
    emit_.push_back(make_emit_record(op));
}

void SqlExecutor::emit(EmitOp op, int param)
{
    emit_.push_back(make_emit_record(op, param));
}

void SqlExecutor::emit(EmitOp op, const std::string& param)
{
    emit_.push_back(make_emit_record(op, param));
}

void SqlExecutor::emit(EmitOp op,
                    const std::string& name1,
                    const std::string& name2)
{
    emit_.push_back(make_emit_record(op, name1, name2));
}
