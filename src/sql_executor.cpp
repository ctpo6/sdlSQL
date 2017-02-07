#include "sql_executor.hpp"


int SqlExecutor::walk()
{
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
