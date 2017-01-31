#ifndef DRIVER_HPP
#define DRIVER_HPP

#include "sql.tab.hpp"

#include <map>
#include <string>


// Tell Flex the lexer's prototype ...
#define YY_DECL \
    yy::SqlParser::symbol_type yylex(Driver& driver)
// ... and declare it for the parser's sake.
YY_DECL;


enum sqlp_col_attribs {
    SCA_NOTNULL		= (1 << 0),
    SCA_DEF_STR		= (1 << 1),
    SCA_DEF_NUM		= (1 << 2),
    SCA_DEF_FLOAT		= (1 << 3),
    SCA_DEF_BOOL		= (1 << 4),
    SCA_AUTOINC		= (1 << 5),
    SCA_UNIQUE_KEY		= (1 << 6),
    SCA_PRIMARY_KEY		= (1 << 7),
    SCA_COMMENT		= (1 << 8),
};


enum sqlp_expr_ops {
    SEO_ADD		= 0,
    SEO_SUB		= 1,
    SEO_MUL		= 2,
    SEO_DIV		= 3,
    SEO_MOD		= 4,
    SEO_NEG		= 5,
    SEO_AND		= 6,
    SEO_OR		= 7,
    SEO_XOR		= 8,
    SEO_BITOR	= 9,
    SEO_BITAND	= 10,
    SEO_BITXOR	= 11,
    SEO_SHIFT	= 12,
    SEO_NOT		= 13,
    SEO_ASSIGN	= 14,
    SEO_IS_NULL	= 15,
    SEO_SHR		= 16,
    SEO_SHL		= 17,
    SEO_BETWEEN	= 18,
    SEO_EXISTS	= 19,
    SEO_IN_SELECT	= 20,
    SEO_LIKE	= 21,
    SEO_REGEX	= 22,
    SEO_STRTOBIN	= 23,
};


enum sqlp_date_intervals {
    SDI_DAY_HOUR		= 0,
    SDI_DAY_MICROSECOND	= 1,
    SDI_DAY_MINUTE		= 2,
    SDI_DAY_SECOND		= 3,
    SDI_YEAR_MONTH		= 4,
    SDI_YEAR		= 5,
    SDI_HOUR_MICROSECOND	= 6,
    SDI_HOUR_MINUTE		= 7,
    SDI_HOUR_SECOND		= 8,
};


// Conducting the whole scanning and parsing of Calc++.
class Driver
{
public:
    std::map<std::string, int> variables;

    int result;

    // The name of the file being parsed.
    // Used later to pass the file name to the location tracker.
    std::string file;

    bool trace_scanning = false;
    bool trace_parsing = false;

public:

    // Handling the scanner.
    void scan_begin();
    void scan_end();

    // Run the parser on file F.
    // Return 0 on success.
    int parse(const std::string& f);


    void sqlp_alias(const std::string& alias);
    void sqlp_assign_at(const std::string& name);
    void sqlp_bool(int val);
    void sqlp_call(int n_args, const std::string& name);
    void sqlp_call_date(int n_args, enum sqlp_expr_ops op);
    void sqlp_call_trim_opts(int trim_opts);
    void sqlp_case(int n_list, int have_else);
    void sqlp_caseval(int n_list, int have_else);
    void sqlp_column(const std::string& name);
    void sqlp_date_interval(enum sqlp_date_intervals interval);
    void sqlp_expr_cmp(int comp);
    void sqlp_expr_cmp_sel(int sel_type, int comp);
    void sqlp_expr_is_bool(int val);
    void sqlp_expr_is_in(int val);
    void sqlp_expr_op(enum sqlp_expr_ops op);
    void sqlp_fieldname(const std::string& db_name, const std::string& name);
    void sqlp_float(double val);
    void sqlp_group_by(int opts);
    void sqlp_group_by_list(int n_list);
    void sqlp_having();
    void sqlp_index(const std::string& name);
    void sqlp_index_hint(int n_indexed, int opts);
    void sqlp_into(int n_cols);
    void sqlp_join(int opts);
    void sqlp_join_expr();
    void sqlp_join_using(int n_cols);
    void sqlp_limit(int two_expr);
    void sqlp_name(const std::string& name);
    void sqlp_now();
    void sqlp_number(int val);
    void sqlp_order_by(int n_list);
    void sqlp_select(int opts, int n_expr, int n_tbl_ref);
    void sqlp_select_all();
    void sqlp_select_nodata(int opts, int n_expr);
    void sqlp_stmt();
    void sqlp_string(const std::string& str);
    void sqlp_subquery();
    void sqlp_subquery_as(const std::string& name);
    void sqlp_table(const std::string& db_name, const std::string& name);
    void sqlp_table_refs(int n_refs);
    void sqlp_uservar(const std::string& str);
    void sqlp_where();

    // Error handling.
    void error(const yy::location& l, const std::string& m);
    void error(const std::string& m);
};

#endif