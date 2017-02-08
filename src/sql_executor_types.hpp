#ifndef SQL_EXECUTOR_TYPES_HPP
#define SQL_EXECUTOR_TYPES_HPP

#include <iostream>

enum class ExprOperator
{
    NEG,
    AND,
    OR,
    NOT,
    IS_NULL,
    CMP_EQ,
    CMP_GT,
    CMP_LT,
    CMP_GT_EQ,
    CMP_LT_EQ,
    CMP_NEQ
};
std::ostream& operator<<(std::ostream& os, const ExprOperator e);


enum class ExprOperandType
{
    REF,
    INT,
    STRING
};

#endif