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
    "'!='",
    "'>'",
    "'<'",
    "'>='",
    "'<='"
};
const char* expr_operand_type_str[static_cast<size_t>(ExprOperandType::MAX_)] =
{
    "IDENTIFIER",
    "INT",
    "STRING",
    "NULL"
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
        const SqlExecutor::Identifier& r)
{
    r.t_name.empty() ?
                os << r.c_name :
                os << r.t_name << '.' << r.c_name;
    return os << " idx:" << r.idx << " f:0x" << std::hex << r.flags << std::dec;
}


void SqlExecutor::dump_expr_tree(const ExpressionNode* node)
{
    assert(node);

    if (!node->right) {
        // leaf node
        cout << node->ot.type << ' ' << node->value << endl;
    }
    else {
        cout << "OPERATOR " << node->ot.op << endl;
        dump_expr_tree(node->right.get());
        if (node->left)
            dump_expr_tree(node->left.get());
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

    cout << "\njoin expression(s):\n";
    for (size_t i = 0; i < join_expr_tree.size(); ++i) {
        cout << i << ":\n";
        dump_expr_tree(join_expr_tree[i].get());
    }

    cout << "\nselect columns:\n";
    for (const auto& r: select_columns)
        cout << r << endl;
    cout << "select columns aliases:\n";
    for (const auto& r: select_column_as)
        cout << r.first << ' ' << r.second << endl;

    cout << "\nwhere expression:\n";
    if (where_expr_tree)
        dump_expr_tree(where_expr_tree.get());

    cout << "\norder by:\n";
    for (const auto& r: order_by_list)
        cout << r << endl;
}
