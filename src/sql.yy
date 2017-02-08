%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0.4"

%defines
%define parser_class_name {SqlParser}

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires
{
#include "sql_executor_types.hpp"

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
%left <::ExprOperator> COMPARISON
%nonassoc UMINUS

%token AS
%token ASC
%token BY
%token COMMENT
%token DESC
%token FROM
%token JOIN
%token NOT
%token NULLX
%token ON
%token ORDER
%token SELECT
%token TOP
%token WHERE

%type <int> opt_asc_desc
%type <int> orderby_list
%type <int> select_expr_list

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
    SELECT opt_top select_expr_list
    FROM from_table_reference
    opt_where opt_orderby
        { driver.sqlp_select($3); } ;
    ;

from_table_reference:
    table_reference
        { driver.sqlp_from_table_reference(); }

table_reference:
    table_name_expr
|   join_table
    ;

table_name_expr:
    table_name opt_as_alias
    ;

table_name:
    NAME
        { driver.sqlp_table("", $1); }
|   NAME "." NAME
        { driver.sqlp_table($1, $3); }
    ;

join_table:
    table_reference JOIN table_name_expr ON expr   /* inner join */
        { driver.sqlp_join(); }

opt_top:
    %empty {}
|   TOP "(" INTNUM ")"
        { driver.sqlp_top($3); }

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
    field_name opt_asc_desc
        { driver.sqlp_order_by($2); $$ = 1; }
|   orderby_list "," field_name opt_asc_desc
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
    field_name opt_as_alias
    ;


opt_as_alias:
    %empty {}
|   AS NAME
        { driver.sqlp_alias($2); }
|   NAME
        { driver.sqlp_alias($1); }
    ;

   /**** expressions ****/


field_name:
    NAME
        { driver.sqlp_name($1); }
|   NAME "." NAME
        { driver.sqlp_field($1, $3); }

expr:
    field_name
|   STRING
        { driver.sqlp_string($1); }
|   INTNUM
        { driver.sqlp_number($1); }
|   APPROXNUM
        { driver.sqlp_float($1); }
    ;

expr:
    "(" expr ")"
        {}
|   "-" expr %prec UMINUS
        { driver.sqlp_expr_op(ExprOperator::NEG); }
|   expr OP_AND expr
        { driver.sqlp_expr_op(ExprOperator::AND); }
|   expr OP_OR expr
        { driver.sqlp_expr_op(ExprOperator::OR); }
|   expr COMPARISON expr
        { driver.sqlp_expr_cmp($2); }
|   NOT expr
        { driver.sqlp_expr_op(ExprOperator::NOT); }
    ;

expr:
    expr IS NULLX
        { driver.sqlp_expr_op(ExprOperator::IS_NULL); }
|   expr IS NOT NULLX
        { driver.sqlp_expr_op(ExprOperator::IS_NULL); driver.sqlp_expr_op(ExprOperator::NOT); }
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
