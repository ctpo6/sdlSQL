#include "sql_executor.hpp"

#include <cassert>
#include <iostream>
//#include <type_traits>

namespace {
const char* expr_operator_str[static_cast<size_t>(ExprOperator::MAX_)] =
{
    "'-'",
    "'AND'",
    "'OR'",
    "'NOT'",
    "'IS NULL'",
    "'='",
    "'>'",
    "'<'",
    "'>='",
    "'<='",
    "'!='"
};
const char* expr_operand_type_str[static_cast<size_t>(ExprOperandType::MAX_)] =
{
    "REF",
    "INT",
    "STRING"
};
}

std::ostream& operator<<(std::ostream& os, const ExprOperator e)
{
#if 0
    return os << static_cast<std::underlying_type<ExprOperator>::type>(e);
#endif
    size_t idx = static_cast<size_t>(e);
    assert(idx < static_cast<size_t>(ExprOperator::MAX_));
    assert(expr_operator_str[idx] && "update the code!");
    return os << expr_operator_str[idx];
}

std::ostream& operator<<(std::ostream& os, const ExprOperandType e)
{
    size_t idx = static_cast<size_t>(e);
    assert(idx < static_cast<size_t>(ExprOperandType::MAX_));
    assert(expr_operand_type_str[idx] && "update the code!");
    return os << expr_operand_type_str[idx];
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
