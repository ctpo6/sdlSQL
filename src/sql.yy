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

%token <std::string>    NAME
%token <std::string>    STRING
%token <int>            INTNUM
%token <int>            BOOL
%token <double>         APPROXNUM

/* operators and precedence levels */
%left OP_OR
%left OP_AND
%nonassoc IS
%left NOT
%left <int> COMPARISON /* = <> < > <= >= <=> */
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS

%token ALL
%token AS
%token ASC
%token BY
%token COMMENT
%token DESC
%token FROM
%token GROUP
%token HAVING
%token IN
%token NOT
%token NULLX
%token ORDER
%token SELECT
%token WHERE

 /* functions with special syntax */
/*%token FCOUNT*/

%type <int> select_opts select_expr_list
%type <int> val_list opt_val_list
%type <int> groupby_list opt_asc_desc
%type <int> table_references

%%

%start stmt_list;

stmt_list: stmt ';'
  | stmt_list stmt ';'
  ;

stmt_list: error ';'
   | stmt_list error ';' ;

   /* statements: select statement */

stmt: select_stmt { driver.sqlp_stmt(); }
   ;

select_stmt: SELECT select_opts select_expr_list
                        { driver.sqlp_select_nodata($2, $3); } ;
    | SELECT select_opts select_expr_list
     FROM table_references
     opt_where opt_groupby opt_having opt_orderby
     { driver.sqlp_select($2, $3, $5); } ;
;

opt_where: /* nil */ 
   | WHERE expr { driver.sqlp_where(); };

opt_groupby: /* nil */ 
   | GROUP BY groupby_list { driver.sqlp_group_by_list($3); }
;

groupby_list: expr opt_asc_desc
                             { driver.sqlp_group_by($2); $$ = 1; }
   | groupby_list ',' expr opt_asc_desc
                             { driver.sqlp_group_by($4); $$ = $1 + 1; }
   ;

opt_asc_desc: /* nil */ { $$ = 0; }
   | ASC                { $$ = 0; }
   | DESC               { $$ = 1; }
    ;

opt_having: /* nil */ | HAVING expr { driver.sqlp_having(); };

opt_orderby: /* nil */ | ORDER BY groupby_list { driver.sqlp_order_by($3); }
   ;

select_opts:                      { $$ = 0; }
| select_opts ALL                 { if($$ & 01) error(@$, "duplicate ALL option"); $$ = $1 | 01; }
    ;

select_expr_list: select_expr { $$ = 1; }
    | select_expr_list ',' select_expr {$$ = $1 + 1; }
    | '*' { driver.sqlp_select_all(); $$ = 1; }
    ;

select_expr: expr opt_as_alias ;

table_references:    table_reference { $$ = 1; }
    | table_references ',' table_reference { $$ = $1 + 1; }
    ;

table_reference:  table_factor
;

table_factor:
    NAME opt_as_alias { driver.sqlp_table(NULL, $1); }
  | NAME '.' NAME opt_as_alias { driver.sqlp_table($1, $3); }
  ;

opt_as_alias: AS NAME { driver.sqlp_alias($2); }
  | NAME              { driver.sqlp_alias($1); }
  | /* nil */
  ;

   /**** expressions ****/

expr: NAME          { driver.sqlp_name($1); }
   | NAME '.' NAME { driver.sqlp_fieldname($1, $3); }
   | STRING        { driver.sqlp_string($1); }
   | INTNUM        { driver.sqlp_number($1); }
   | APPROXNUM     { driver.sqlp_float($1); }
   | BOOL          { driver.sqlp_bool($1); }
   ;

expr: expr '+' expr { driver.sqlp_expr_op(SEO_ADD); }
   | expr '-' expr { driver.sqlp_expr_op(SEO_SUB); }
   | expr '*' expr { driver.sqlp_expr_op(SEO_MUL); }
   | expr '/' expr { driver.sqlp_expr_op(SEO_DIV); }
   | expr '%' expr { driver.sqlp_expr_op(SEO_MOD); }
   | '-' expr %prec UMINUS { driver.sqlp_expr_op(SEO_NEG); }
   | expr OP_AND expr { driver.sqlp_expr_op(SEO_AND); }
   | expr OP_OR expr { driver.sqlp_expr_op(SEO_OR); }
   | expr COMPARISON expr { driver.sqlp_expr_cmp($2); }
   | NOT expr { driver.sqlp_expr_op(SEO_NOT); }
   ;    

expr:  expr IS NULLX     { driver.sqlp_expr_op(SEO_IS_NULL); }
   |   expr IS NOT NULLX { driver.sqlp_expr_op(SEO_IS_NULL);
                           driver.sqlp_expr_op(SEO_NOT); }
   ;

val_list: expr { $$ = 1; }
   | expr ',' val_list { $$ = 1 + $3; }
   ;

opt_val_list: /* nil */ { $$ = 0; }
   | val_list
   ;

expr: expr IN '(' val_list ')'       { driver.sqlp_expr_is_in($4); }
   | expr NOT IN '(' val_list ')'    { driver.sqlp_expr_is_in($5);
                                       driver.sqlp_expr_op(SEO_NOT); }
   ;

expr: NAME '(' opt_val_list ')' {  driver.sqlp_call($3, $1); }
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
