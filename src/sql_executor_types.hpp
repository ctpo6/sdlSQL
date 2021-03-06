#ifndef SQL_EXECUTOR_TYPES_HPP
#define SQL_EXECUTOR_TYPES_HPP

#include "types.hpp"

#include <ostream>
#include <string>
#include <utility>


enum class ParserOpCode
{
    AS,
    ASC,
    COMPARISON,
    DESC,
    FIELD,
    FROM,
    JOIN,
    NAME,
    NULLX,
    NUMBER,
    OPERATOR,
    ORDER_BY,
    STRING,
    TABLE,
    TOP,
    SELECT,
    SELECT_ALL,
    WHERE,
};


struct ParserCommand
{
    ParserOpCode op_;

    sdl::sql::Value param;

    // column or table identifier: name1_.name2_
    // column or table alias: name2_
    std::string name1_;
    std::string name2_;

    explicit ParserCommand(ParserOpCode op) : op_(op) {}

    explicit ParserCommand(sdl::sql::null_t)
        : op_(ParserOpCode::NULLX), param(sdl::sql::null_t{}) {}

    explicit ParserCommand(ParserOpCode op,
                           int v)
        : op_(op), param(v) {}

    explicit ParserCommand(ParserOpCode op,
                           std::string v)
        : op_(op), param(std::move(v)) {}

    explicit ParserCommand(ParserOpCode op,
                           std::string name1,
                           std::string name2)
        : op_(op), name1_(std::move(name1)), name2_(std::move(name2)) {}
};


enum class ExprOperator
{
    NEG = 0,
    AND,
    OR,
    NOT,
    IS_NULL,
    CMP_EQ,
    CMP_NEQ,
    CMP_GT,
    CMP_LT,
    CMP_GT_EQ,
    CMP_LT_EQ,

    // add new values above
    MAX_
};
std::ostream& operator<<(std::ostream& os, const ExprOperator e);

enum class ExprOperandType
{
    IDENTIFIER = 0,
    INT,
    STRING,
    NULLX,

    // add new values above
    MAX_
};
std::ostream& operator<<(std::ostream& os, const ExprOperandType e);

#endif