#include "sql_executor.hpp"

#include <cassert>
#include <iostream>
//#include <type_traits>

using namespace std;

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

std::ostream& operator<<(
        std::ostream& os,
        const SqlExecutor::SymbolReference& r)
{
    r.t_name.empty() ?
                os << r.c_name :
                os << r.t_name << '.' << r.c_name;
    return os << " idx:" << r.idx << " f:0x" << std::hex << r.flags << std::dec;
}


void SqlExecutor::dump_expr_tree(const ExpressionNode& node)
{
    if (!node.right) {
        // leaf node
        cout << node.ot.type << ' ' << node.value << endl;
    }
    else {
        cout << "OPERATOR " << node.ot.op << endl;
        dump_expr_tree(*node.right);
        if (node.left)
            dump_expr_tree(*node.left);
    }
}


void SqlExecutor::SelectContext::dump() const
{
    cout << "n_top: " << n_top << endl;
    cout << "n_select: " << n_select << endl;

    cout << "\nfrom tables:\n";
    for (const auto& r: from_tables)
        cout << r << endl;
    cout << "from tables aliases:\n";
    for (const auto& r: from_table_as)
        cout << r.first << ' ' << r.second << endl;

    cout << "\nselect columns:\n";
    for (const auto& r: select_columns)
        cout << r << endl;
    cout << "select columns aliases:\n";
    for (const auto& r: select_column_as)
        cout << r.first << ' ' << r.second << endl;

    cout << "\nwhere expression:\n";
    dump_expr_tree(*where_expr_tree);

    cout << "\norder by:\n";
    for (const auto& r: order_by_list)
        cout << r << endl;
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
