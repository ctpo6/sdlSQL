#include "driver.hpp"

#include "sql.tab.hpp"

#include <cstdio>
#include <iostream>
#include <string>


using namespace std;


void Driver::sqlp_alias(const std::string& alias)
{
    printf("AS %s\n", alias.c_str());
    exec_.emit(SqlExecutor::EmitOp::AS, string(), alias);
}

void Driver::sqlp_expr_cmp(int comp)
{
    printf("COMPARISON %d\n", comp);
    exec_.emit(SqlExecutor::EmitOp::COMPARISON, comp);
}

void Driver::sqlp_expr_op(enum sqlp_expr_ops op)
{
    printf("OPERATOR %d\n", (int)op);
    exec_.emit(SqlExecutor::EmitOp::OPERATOR, (int)op);
}

void Driver::sqlp_field(const std::string& tbl_name, const std::string& col_name)
{
    printf("FIELD %s.%s\n", tbl_name.c_str(), col_name.c_str());
    exec_.emit(SqlExecutor::EmitOp::FIELD, tbl_name, col_name);
}

void Driver::sqlp_float(double val)
{
    printf("FLOAT %lf\n", val);
}

void Driver::sqlp_from_table_reference()
{
    printf("FROM\n");
    exec_.emit(SqlExecutor::EmitOp::FROM);
}

void Driver::sqlp_join()
{
    printf("JOIN\n");
    exec_.emit(SqlExecutor::EmitOp::JOIN);
}

void Driver::sqlp_name(const std::string& name)
{
    printf("NAME %s\n", name.c_str());
    exec_.emit(SqlExecutor::EmitOp::NAME, string(), name);
}

void Driver::sqlp_number(int val)
{
    printf("NUMBER %d\n", val);
    exec_.emit(SqlExecutor::EmitOp::NUMBER, val);
}

void Driver::sqlp_order_by(int desc)
{
    printf("%s\n", desc ? "DESC" : "ASC");
    exec_.emit(desc ? SqlExecutor::EmitOp::DESC : SqlExecutor::EmitOp::ASC);
}

void Driver::sqlp_order_by_list(int n_list)
{
    printf("ORDER BY %d\n", n_list);
    exec_.emit(SqlExecutor::EmitOp::ORDER_BY, n_list);
}

void Driver::sqlp_select(int n_expr)
{
    printf("SELECT %d\n", n_expr);
    exec_.emit(SqlExecutor::EmitOp::SELECT, n_expr);
}

void Driver::sqlp_select_all()
{
    printf("SELECTALL\n");
    exec_.emit(SqlExecutor::EmitOp::SELECT_ALL);
}

void Driver::sqlp_stmt()
{
    printf("STMT\n");
}

void Driver::sqlp_string(const std::string& s)
{
    printf("STRING %s\n", s.c_str());
    exec_.emit(SqlExecutor::EmitOp::STRING, s);
}

void Driver::sqlp_table(const std::string& db_name, const std::string& tbl_name)
{
    if (db_name.empty()) {
        printf("TABLE %s\n", tbl_name.c_str());
        exec_.emit(SqlExecutor::EmitOp::TABLE, string(), tbl_name);
    }
    else {
        printf("TABLE %s.%s\n", db_name.c_str(), tbl_name.c_str());
        exec_.emit(SqlExecutor::EmitOp::TABLE, db_name, tbl_name);
    }
}

void Driver::sqlp_top(int num)
{
    printf("TOP %d\n", num);
    exec_.emit(SqlExecutor::EmitOp::TOP, num);
}

void Driver::sqlp_where()
{
    printf("WHERE\n");
    exec_.emit(SqlExecutor::EmitOp::WHERE);
}
