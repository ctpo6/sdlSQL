#include "driver.hpp"

#include "sql.tab.hpp"

#include <cstdio>
#include <iostream>
#include <string>


using namespace std;


void Driver::sqlp_alias(const std::string& alias)
{
}

void Driver::sqlp_expr_cmp(int comp)
{
    printf("COMPARISON %d\n", comp);
}

void Driver::sqlp_expr_op(enum sqlp_expr_ops op)
{
    printf("OPERATOR %d\n", (int)op);
}

void Driver::sqlp_fieldname(const std::string& db_name, const std::string& name)
{
    printf("FIELDNAME %s.%s\n", db_name.c_str(), name.c_str());
}

void Driver::sqlp_float(double val)
{
    printf("FLOAT %lf\n", val);
}

void Driver::sqlp_name(const std::string& name)
{
    printf("NAME %s\n", name.c_str());
}

void Driver::sqlp_number(int val)
{
    printf("NUMBER %d\n", val);
}

void Driver::sqlp_order_by(int n_list)
{
}

void Driver::sqlp_order_by_list(int n_list)
{
}

void Driver::sqlp_select(int n_expr, int n_tbl_ref)
{
    printf("SELECT %d %d\n", n_expr, n_tbl_ref);
}

void Driver::sqlp_select_all()
{
    printf("SELECTALL\n");
}

void Driver::sqlp_stmt()
{
    printf("STMT\n");
}

void Driver::sqlp_string(const std::string& s)
{
    printf("STRING %s\n", s.c_str());
}

void Driver::sqlp_table(const std::string& db_name, const std::string& name)
{
    if (db_name.empty()) {
        printf("TABLE %s\n", name.c_str());
    }
    else {
        printf("TABLE %s.%s\n", db_name.c_str(), name.c_str());
    }
}

void Driver::sqlp_where()
{
    printf("WHERE\n");
}
