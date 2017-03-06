#include "driver.hpp"

#include "sql.tab.hpp"

#include <cstdio>
#include <iostream>
#include <string>


using namespace std;


void Driver::sqlp_alias(const std::string& alias)
{
    printf("AS %s\n", alias.c_str());
    emit(ParserOpCode::AS, string(), alias);
}

void Driver::sqlp_expr_cmp(ExprOperator comp)
{
    printf("COMPARISON %d\n", (int)comp);
    emit(ParserOpCode::COMPARISON, (int)comp);
}

void Driver::sqlp_expr_op(ExprOperator op)
{
    printf("OPERATOR %d\n", (int)op);
    emit(ParserOpCode::OPERATOR, (int)op);
}

void Driver::sqlp_field(const std::string& tbl_name, const std::string& col_name)
{
    printf("FIELD %s.%s\n", tbl_name.c_str(), col_name.c_str());
    emit(ParserOpCode::FIELD, tbl_name, col_name);
}

void Driver::sqlp_float(double val)
{
    printf("FLOAT %lf\n", val);
}

void Driver::sqlp_from_table_reference()
{
    printf("FROM\n");
    emit(ParserOpCode::FROM);
}

void Driver::sqlp_join()
{
    printf("JOIN\n");
    emit(ParserOpCode::JOIN);
}

void Driver::sqlp_name(const std::string& name)
{
    printf("NAME %s\n", name.c_str());
    emit(ParserOpCode::NAME, string(), name);
}

void Driver::sqlp_null()
{
    printf("NULL\n");
    emit(ParserOpCode::NULLX);
}

void Driver::sqlp_number(int val)
{
    printf("NUMBER %d\n", val);
    emit(ParserOpCode::NUMBER, val);
}

void Driver::sqlp_order_by(int desc)
{
    printf("%s\n", desc ? "DESC" : "ASC");
    emit(desc ? ParserOpCode::DESC : ParserOpCode::ASC);
}

void Driver::sqlp_order_by_list(int n_list)
{
    printf("ORDER BY %d\n", n_list);
    emit(ParserOpCode::ORDER_BY, n_list);
}

void Driver::sqlp_select(int n_expr)
{
    printf("SELECT %d\n", n_expr);
    emit(ParserOpCode::SELECT, n_expr);
}

void Driver::sqlp_select_all()
{
    printf("SELECTALL\n");
    emit(ParserOpCode::SELECT_ALL);
}

void Driver::sqlp_stmt()
{
    printf("STMT\n");
}

void Driver::sqlp_string(const std::string& s)
{
    printf("STRING %s\n", s.c_str());
    emit(ParserOpCode::STRING, s);
}

void Driver::sqlp_table(const std::string& db_name, const std::string& tbl_name)
{
    if (db_name.empty()) {
        printf("TABLE %s\n", tbl_name.c_str());
        emit(ParserOpCode::TABLE, string(), tbl_name);
    }
    else {
        printf("TABLE %s.%s\n", db_name.c_str(), tbl_name.c_str());
        emit(ParserOpCode::TABLE, db_name, tbl_name);
    }
}

void Driver::sqlp_top(int num)
{
    printf("TOP %d\n", num);
    emit(ParserOpCode::TOP, num);
}

void Driver::sqlp_where()
{
    printf("WHERE\n");
    emit(ParserOpCode::WHERE);
}
