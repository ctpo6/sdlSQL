%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0.4"

%defines
%define parser_class_name {SqlParser}

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires
{
#include <string>

class Driver;
}

// The parsing context.
%param { Driver& driver }

%locations
%initial-action
{
  // Initialize the initial location.
  @$.begin.filename = @$.end.filename = &driver.file;
};

    /*%define parse.trace*/
%define parse.error verbose

%code
{
#include "driver.hpp"
}


%define api.token.prefix {TOK_}
%token
    END 0       "end of file"
    S_STAR      "*"
    S_LPAREN    "("
    S_RPAREN    ")"
    S_COMMA     ","
    S_DOT       "."
    S_SEMICOLON ";"
;

%token <std::string>    NAME        "NAME"
%token <std::string>    STRING      "STRING"
%token <int>            INTNUM      "INTNUM"
%token <double>         APPROXNUM   "APPROXNUM"
%token <int>            BOOL        "BOOL"

/* operators and precedence levels */
%left OP_OR
%left OP_AND
%nonassoc IS
%left NOT
%left <int> COMPARISON /* = <> < > <= >= <=> */
%nonassoc UMINUS

%token AS
%token ASC
%token BY
%token COMMENT
%token DESC
%token FROM
%token NOT
%token NULLX
%token ORDER
%token SELECT
%token WHERE

%type <int> opt_asc_desc
%type <int> orderby_list
%type <int> select_expr_list
%type <int> table_references

%printer { yyoutput << $$; } <*>;



%%

%start stmt_list;

stmt_list:
    stmt ";"
|   stmt_list stmt ";"
    ;

stmt_list:
    error ";"
|   stmt_list error ";"
    ;

   /* statements: select statement */

stmt:
    select_stmt
        { driver.sqlp_stmt(); }
    ;

select_stmt:
    SELECT select_expr_list
    FROM table_references
    opt_where opt_orderby
        { driver.sqlp_select($2, $4); } ;
    ;

opt_where:
    %empty {}
|   WHERE expr
        { driver.sqlp_where(); };

opt_orderby:
    %empty {}
|   ORDER BY orderby_list
        { driver.sqlp_order_by_list($3); }
    ;

orderby_list:
    expr opt_asc_desc
        { driver.sqlp_order_by($2); $$ = 1; }
|   orderby_list "," expr opt_asc_desc
        { driver.sqlp_order_by($4); $$ = $1 + 1; }
    ;

opt_asc_desc:
    %empty
        { $$ = 0; }
|   ASC
        { $$ = 0; }
|   DESC
        { $$ = 1; }
    ;

select_expr_list:
    select_expr
        { $$ = 1; }
|   select_expr_list "," select_expr
        {$$ = $1 + 1; }
|   "*"
        { driver.sqlp_select_all(); $$ = 1; }
    ;

select_expr:
    expr opt_as_alias
    ;

table_references:
    table_reference
        { $$ = 1; }
|   table_references "," table_reference
        { $$ = $1 + 1; }
    ;

table_reference:
    table_factor
    ;

table_factor:
    NAME opt_as_alias
        { driver.sqlp_table("", $1); }
|   NAME "." NAME opt_as_alias
        { driver.sqlp_table($1, $3); }
    ;

opt_as_alias:
    %empty {}
|   AS NAME
        { driver.sqlp_alias($2); }
|   NAME
        { driver.sqlp_alias($1); }
    ;

   /**** expressions ****/

expr:
    NAME
        { driver.sqlp_name($1); }
|   NAME "." NAME
        { driver.sqlp_fieldname($1, $3); }
|   STRING
        { driver.sqlp_string($1); }
|   INTNUM
        { driver.sqlp_number($1); }
|   APPROXNUM
        { driver.sqlp_float($1); }
    ;

expr:
|   "-" expr %prec UMINUS
        { driver.sqlp_expr_op(SEO_NEG); }
|   expr OP_AND expr
        { driver.sqlp_expr_op(SEO_AND); }
|   expr OP_OR expr
        { driver.sqlp_expr_op(SEO_OR); }
|   expr COMPARISON expr
        { driver.sqlp_expr_cmp($2); }
|   NOT expr
        { driver.sqlp_expr_op(SEO_NOT); }
    ;

expr:
    expr IS NULLX
        { driver.sqlp_expr_op(SEO_IS_NULL); }
|   expr IS NOT NULLX
        { driver.sqlp_expr_op(SEO_IS_NULL); driver.sqlp_expr_op(SEO_NOT); }
    ;

  /* functions with special syntax */
/*
expr: FCOUNT '(' '*' ')' { driver.sqlp_call(0, "COUNTALL"); }
   | FCOUNT '(' expr ')' { driver.sqlp_call(1, "COUNT"); }
*/

%%

void yy::SqlParser::error(const location_type& l,
                          const std::string& m)
{
    driver.error(l, m);
}
