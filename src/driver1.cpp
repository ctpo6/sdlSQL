#include "driver.hpp"

#include "sql.tab.hpp"

#include <iostream>
#include <string>


using namespace std;


void Driver::sqlp_alias(const std::string& alias)
{
}

void Driver::sqlp_assign_at(const std::string& name)
{
}

void Driver::sqlp_bool(int val)
{
}

void Driver::sqlp_call(int n_args, const string& name)
{
}

void Driver::sqlp_call_date(int n_args, enum sqlp_expr_ops op)
{
}

void Driver::sqlp_call_trim_opts(int trim_opts)
{
}

void Driver::sqlp_case(int n_list, int have_else)
{
}

void Driver::sqlp_caseval(int n_list, int have_else)
{
}

void Driver::sqlp_column(const std::string& name)
{
}

void Driver::sqlp_date_interval(enum sqlp_date_intervals interval)
{
}

void Driver::sqlp_expr_cmp(int comp)
{
}

void Driver::sqlp_expr_cmp_sel(int sel_type, int comp)
{
}

void Driver::sqlp_expr_is_bool(int val)
{
}

void Driver::sqlp_expr_is_in(int val)
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

void Driver::sqlp_group_by(int opts)
{
}

void Driver::sqlp_group_by_list(int n_list)
{
}

void Driver::sqlp_having()
{
}

void Driver::sqlp_index(const std::string& name)
{
}

void Driver::sqlp_index_hint(int n_indexed, int opts)
{
}

void Driver::sqlp_into(int n_cols)
{
}

void Driver::sqlp_join(int opts)
{
}

void Driver::sqlp_join_expr()
{
}

void Driver::sqlp_join_using(int n_cols)
{
}

void Driver::sqlp_limit(int two_expr)
{
}

void Driver::sqlp_name(const std::string& name)
{
}

void Driver::sqlp_now()
{
}

void Driver::sqlp_number(int val)
{
}

void Driver::sqlp_order_by(int n_list)
{
}

void Driver::sqlp_select(int opts, int n_expr, int n_tbl_ref)
{
}

void Driver::sqlp_select_all()
{
}

void Driver::sqlp_select_nodata(int opts, int n_expr)
{
}

void Driver::sqlp_stmt()
{
}

void Driver::sqlp_string(const std::string& str)
{
}

void Driver::sqlp_subquery()
{
}

void Driver::sqlp_subquery_as(const std::string& name)
{
}

void Driver::sqlp_table(const std::string& db_name, const std::string& name)
{
}

void Driver::sqlp_table_refs(int n_refs)
{
}

void Driver::sqlp_uservar(const std::string& str)
{
}

void Driver::sqlp_where()
{
}
