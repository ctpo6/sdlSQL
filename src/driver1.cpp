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
}

void Driver::sqlp_expr_op(enum sqlp_expr_ops op)
{
}

void Driver::sqlp_fieldname(const std::string& db_name, const std::string& name)
{
}

void Driver::sqlp_float(double val)
{
}

void Driver::sqlp_name(const std::string& name)
{
}

void Driver::sqlp_number(int val)
{
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

void Driver::sqlp_string(const std::string& str)
{
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
