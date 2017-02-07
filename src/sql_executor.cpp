#include "sql_executor.hpp"

#include <cassert>
#include <iostream>

using namespace std;


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
    if ()

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
