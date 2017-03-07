#include "driver.hpp"

#include "sql.tab.hpp"

#include <cstdio>
#include <string>


using namespace std;


void Driver::emit_alias(const std::string& alias)
{
    printf("AS %s\n", alias.c_str());
    emit(ParserOpCode::AS, string(), alias);
}

void Driver::emit_expr_cmp(ExprOperator comp)
{
    printf("COMPARISON %d\n", (int)comp);
    emit(ParserOpCode::COMPARISON, (int)comp);
}

void Driver::emit_expr_op(ExprOperator op)
{
    printf("OPERATOR %d\n", (int)op);
    emit(ParserOpCode::OPERATOR, (int)op);
}

void Driver::emit_field(const std::string& tbl_name, const std::string& col_name)
{
    printf("FIELD %s.%s\n", tbl_name.c_str(), col_name.c_str());
    emit(ParserOpCode::FIELD, tbl_name, col_name);
}

void Driver::emit_float(double val)
{
    printf("FLOAT %lf\n", val);
}

void Driver::emit_from_table_reference()
{
    printf("FROM\n");
    emit(ParserOpCode::FROM);
}

void Driver::emit_join()
{
    printf("JOIN\n");
    emit(ParserOpCode::JOIN);
}

void Driver::emit_name(const std::string& name)
{
    printf("NAME %s\n", name.c_str());
    emit(ParserOpCode::NAME, string(), name);
}

void Driver::emit_null()
{
    printf("NULL\n");
    emit(ParserOpCode::NULLX);
}

void Driver::emit_number(int val)
{
    printf("NUMBER %d\n", val);
    emit(ParserOpCode::NUMBER, val);
}

void Driver::emit_order_by(int desc)
{
    printf("%s\n", desc ? "DESC" : "ASC");
    emit(desc ? ParserOpCode::DESC : ParserOpCode::ASC);
}

void Driver::emit_order_by_list(int n_list)
{
    printf("ORDER BY %d\n", n_list);
    emit(ParserOpCode::ORDER_BY, n_list);
}

void Driver::emit_select(int n_expr)
{
    printf("SELECT %d\n", n_expr);
    emit(ParserOpCode::SELECT, n_expr);
}

void Driver::emit_select_all()
{
    printf("SELECTALL\n");
    emit(ParserOpCode::SELECT_ALL);
}

void Driver::emit_stmt()
{
    printf("STMT\n");
}

void Driver::emit_string(const std::string& s)
{
    printf("STRING %s\n", s.c_str());
    emit(ParserOpCode::STRING, s);
}

void Driver::emit_table(const std::string& db_name, const std::string& tbl_name)
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

void Driver::emit_top(int num)
{
    printf("TOP %d\n", num);
    emit(ParserOpCode::TOP, num);
}

void Driver::emit_where()
{
    printf("WHERE\n");
    emit(ParserOpCode::WHERE);
}
