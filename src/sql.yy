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

%define parse.trace
%define parse.error verbose

%code
{
#include "driver.hpp"
}


%define api.token.prefix {TOK_}
%token
  END  0  "end of file"
  ASSIGN  ":="
  MINUS   "-"
  PLUS    "+"
  STAR    "*"
  SLASH   "/"
  LPAREN  "("
  RPAREN  ")"
;

%token <std::string> NAME "name"
%token <std::string> STRING "string"
%token <int> INTNUM "intnum"
%token <int> BOOL "bool"
%token <double> APPROXNUM "approxnum"

/* user @abc names */
%token <std::string> USERVAR

/* operators and precedence levels */
%right ASSIGN
%left OR
%left XOR
%left ANDOP
%nonassoc IN IS LIKE REGEXP
%left NOT '!'
%left BETWEEN
%left <subtok> COMPARISON /* = <> < > <= >= <=> */
%left '|'
%left '&'
%left <subtok> SHIFT /* << >> */
%left '+' '-'
%left '*' '/' '%' MOD
%left '^'
%nonassoc UMINUS

%token ADD
%token ALL
%token ALTER
%token ANALYZE
%token AND
%token ANY
%token AS
%token ASC
%token AUTO_INCREMENT
%token BEFORE
%token BETWEEN
%token BIGINT
%token BINARY
%token BIT
%token BLOB
%token BOTH
%token BY
%token CALL
%token CASCADE
%token CASE
%token CHANGE
%token CHAR
%token CHECK
%token COLLATE
%token COLUMN
%token COMMENT
%token CONDITION
%token CONSTRAINT
%token CONTINUE
%token CONVERT
%token CREATE
%token CROSS
%token CURRENT_DATE
%token CURRENT_TIME
%token CURRENT_TIMESTAMP
%token CURRENT_USER
%token CURSOR
%token DATABASE
%token DATABASES
%token DATE
%token DATETIME
%token DAY_HOUR
%token DAY_MICROSECOND
%token DAY_MINUTE
%token DAY_SECOND
%token DECIMAL
%token DECLARE
%token DEFAULT
%token DELAYED
%token DELETE
%token DESC
%token DESCRIBE
%token DETERMINISTIC
%token DISTINCT
%token DISTINCTROW
%token DIV
%token DOUBLE
%token DROP
%token DUAL
%token EACH
%token ELSE
%token ELSEIF
%token ENCLOSED
%token END
%token ENUM
%token ESCAPED
%token <subtok> EXISTS
%token EXIT
%token EXPLAIN
%token FETCH
%token FLOAT
%token FOR
%token FORCE
%token FOREIGN
%token FROM
%token FULLTEXT
%token GRANT
%token GROUP
%token HAVING
%token HIGH_PRIORITY
%token HOUR_MICROSECOND
%token HOUR_MINUTE
%token HOUR_SECOND
%token IF
%token IGNORE
%token IN
%token INDEX
%token INFILE
%token INNER
%token INOUT
%token INSENSITIVE
%token INSERT
%token INT
%token INTEGER
%token INTERVAL
%token INTO
%token ITERATE
%token JOIN
%token KEY
%token KEYS
%token KILL
%token LEADING
%token LEAVE
%token LEFT
%token LIKE
%token LIMIT
%token LINES
%token LOAD
%token LOCALTIME
%token LOCALTIMESTAMP
%token LOCK
%token LONG
%token LONGBLOB
%token LONGTEXT
%token LOOP
%token LOW_PRIORITY
%token MATCH
%token MEDIUMBLOB
%token MEDIUMINT
%token MEDIUMTEXT
%token MINUTE_MICROSECOND
%token MINUTE_SECOND
%token MOD
%token MODIFIES
%token NATURAL
%token NOT
%token NO_WRITE_TO_BINLOG
%token NULLX
%token NUMBER
%token ON
%token ONDUPLICATE
%token OPTIMIZE
%token OPTION
%token OPTIONALLY
%token OR
%token ORDER
%token OUT
%token OUTER
%token OUTFILE
%token PRECISION
%token PRIMARY
%token PROCEDURE
%token PURGE
%token QUICK
%token READ
%token READS
%token REAL
%token REFERENCES
%token REGEXP
%token RELEASE
%token RENAME
%token REPEAT
%token REPLACE
%token REQUIRE
%token RESTRICT
%token RETURN
%token REVOKE
%token RIGHT
%token ROLLUP
%token SCHEMA
%token SCHEMAS
%token SECOND_MICROSECOND
%token SELECT
%token SENSITIVE
%token SEPARATOR
%token SET
%token SHOW
%token SMALLINT
%token SOME
%token SONAME
%token SPATIAL
%token SPECIFIC
%token SQL
%token SQLEXCEPTION
%token SQLSTATE
%token SQLWARNING
%token SQL_BIG_RESULT
%token SQL_CALC_FOUND_ROWS
%token SQL_SMALL_RESULT
%token SSL
%token STARTING
%token STRAIGHT_JOIN
%token TABLE
%token TEMPORARY
%token TEXT
%token TERMINATED
%token THEN
%token TIME
%token TIMESTAMP
%token TINYBLOB
%token TINYINT
%token TINYTEXT
%token TO
%token TRAILING
%token TRIGGER
%token UNDO
%token UNION
%token UNIQUE
%token UNLOCK
%token UNSIGNED
%token UPDATE
%token USAGE
%token USE
%token USING
%token UTC_DATE
%token UTC_TIME
%token UTC_TIMESTAMP
%token VALUES
%token VARBINARY
%token VARCHAR
%token VARYING
%token WHEN
%token WHERE
%token WHILE
%token WITH
%token WRITE
%token XOR
%token YEAR
%token YEAR_MONTH
%token ZEROFILL

 /* functions with special syntax */
%token FSUBSTRING
%token FTRIM
%token FDATE_ADD FDATE_SUB
%token FCOUNT

%type <int> select_opts select_expr_list
%type <int> val_list opt_val_list case_list
%type <int> groupby_list opt_with_rollup opt_asc_desc
%type <int> table_references opt_inner_cross opt_outer
%type <int> left_or_right opt_left_or_right_outer column_list
%type <int> index_list opt_for_join

%type <int> delete_opts delete_list
%type <int> insert_opts insert_vals insert_vals_list
%type <int> insert_asgn_list opt_if_not_exists update_opts update_asgn_list
%type <int> opt_if_exists table_list
%type <int> opt_temporary opt_length opt_binary opt_uz enum_list
%type <int> column_atts data_type opt_ignore_replace create_col_list



%%

%start stmt_list

stmt_list: stmt ';'
  | stmt_list stmt ';'
  ;

stmt_list: error ';'
   | stmt_list error ';' ;

   /* statements: select statement */

stmt: select_stmt { sqlp_stmt(pstate); }
   ;

select_stmt: SELECT select_opts select_expr_list
                        { sqlp_select_nodata(pstate, $2, $3); } ;
    | SELECT select_opts select_expr_list
     FROM table_references
     opt_where opt_groupby opt_having opt_orderby opt_limit
     opt_into_list { sqlp_select(pstate, $2, $3, $5); } ;
;

opt_where: /* nil */ 
   | WHERE expr { sqlp_where(pstate); };

opt_groupby: /* nil */ 
   | GROUP BY groupby_list opt_with_rollup
                             { sqlp_group_by_list(pstate, $3, $4); }
;

groupby_list: expr opt_asc_desc
                             { sqlp_group_by(pstate, $2); $$ = 1; }
   | groupby_list ',' expr opt_asc_desc
                             { sqlp_group_by(pstate, $4); $$ = $1 + 1; }
   ;

opt_asc_desc: /* nil */ { $$ = 0; }
   | ASC                { $$ = 0; }
   | DESC               { $$ = 1; }
    ;

opt_with_rollup: /* nil */  { $$ = 0; }
   | WITH ROLLUP  { $$ = 1; }
   ;

opt_having: /* nil */ | HAVING expr { sqlp_having(pstate); };

opt_orderby: /* nil */ | ORDER BY groupby_list { sqlp_order_by(pstate, $3); }
   ;

opt_limit: /* nil */ | LIMIT expr { sqlp_limit(pstate, 0); }
  | LIMIT expr ',' expr             { sqlp_limit(pstate, 1); }
  ; 

opt_into_list: /* nil */ 
   | INTO column_list { sqlp_into(pstate, $2); }
   ;

column_list: NAME          { sqlp_column(pstate, $1); free($1); $$ = 1; }
  | STRING                 { lyyerror(@1, "string %s found where name required", $1);
                              sqlp_column(pstate, $1); free($1); $$ = 1; }
  | column_list ',' NAME   { sqlp_column(pstate, $3); free($3); $$ = $1 + 1; }
  | column_list ',' STRING { lyyerror(@3, "string %s found where name required", $1);
                            sqlp_column(pstate, $3); free($3); $$ = $1 + 1; }
  ;

select_opts:                          { $$ = 0; }
| select_opts ALL                 { if($$ & 01) lyyerror(@2,"duplicate ALL option"); $$ = $1 | 01; }
| select_opts DISTINCT            { if($$ & 02) lyyerror(@2,"duplicate DISTINCT option"); $$ = $1 | 02; }
| select_opts DISTINCTROW         { if($$ & 04) lyyerror(@2,"duplicate DISTINCTROW option"); $$ = $1 | 04; }
| select_opts HIGH_PRIORITY       { if($$ & 010) lyyerror(@2,"duplicate HIGH_PRIORITY option"); $$ = $1 | 010; }
| select_opts STRAIGHT_JOIN       { if($$ & 020) lyyerror(@2,"duplicate STRAIGHT_JOIN option"); $$ = $1 | 020; }
| select_opts SQL_SMALL_RESULT    { if($$ & 040) lyyerror(@2,"duplicate SQL_SMALL_RESULT option"); $$ = $1 | 040; }
| select_opts SQL_BIG_RESULT      { if($$ & 0100) lyyerror(@2,"duplicate SQL_BIG_RESULT option"); $$ = $1 | 0100; }
| select_opts SQL_CALC_FOUND_ROWS { if($$ & 0200) lyyerror(@2,"duplicate SQL_CALC_FOUND_ROWS option"); $$ = $1 | 0200; }
    ;

select_expr_list: select_expr { $$ = 1; }
    | select_expr_list ',' select_expr {$$ = $1 + 1; }
    | '*' { sqlp_select_all(pstate); $$ = 1; }
    ;

select_expr: expr opt_as_alias ;

table_references:    table_reference { $$ = 1; }
    | table_references ',' table_reference { $$ = $1 + 1; }
    ;

table_reference:  table_factor
  | join_table
;

table_factor:
    NAME opt_as_alias index_hint { sqlp_table(pstate, NULL, $1); free($1); }
  | NAME '.' NAME opt_as_alias index_hint { sqlp_table(pstate, $1, $3);
                               free($1); free($3); }
  | table_subquery opt_as NAME { sqlp_subquery_as(pstate, $3); free($3); }
  | '(' table_references ')' { sqlp_table_refs(pstate, $2); }
  ;

opt_as: AS 
  | /* nil */
  ;

opt_as_alias: AS NAME { sqlp_alias(pstate, $2); free($2); }
  | NAME              { sqlp_alias(pstate, $1); free($1); }
  | /* nil */
  ;

join_table:
    table_reference opt_inner_cross JOIN table_factor opt_join_condition
                  { sqlp_join(pstate, 0100+$2); }
  | table_reference STRAIGHT_JOIN table_factor
                  { sqlp_join(pstate, 0200); }
  | table_reference STRAIGHT_JOIN table_factor ON expr
                  { sqlp_join(pstate, 0200); }
  | table_reference left_or_right opt_outer JOIN table_factor join_condition
                  { sqlp_join(pstate, 0300+$2+$3); }
  | table_reference NATURAL opt_left_or_right_outer JOIN table_factor
                  { sqlp_join(pstate, 0400+$3); }
  ;

opt_inner_cross: /* nil */ { $$ = 0; }
   | INNER { $$ = 1; }
   | CROSS  { $$ = 2; }
;

opt_outer: /* nil */  { $$ = 0; }
   | OUTER {$$ = 4; }
   ;

left_or_right: LEFT { $$ = 1; }
    | RIGHT { $$ = 2; }
    ;

opt_left_or_right_outer: LEFT opt_outer { $$ = 1 + $2; }
   | RIGHT opt_outer  { $$ = 2 + $2; }
   | /* nil */ { $$ = 0; }
   ;

opt_join_condition: join_condition | /* nil */ ;

join_condition:
    ON expr { sqlp_join_expr(pstate); }
    | USING '(' column_list ')' { sqlp_join_using(pstate, $3); }
    ;

index_hint:
     USE KEY opt_for_join '(' index_list ')'
                  { sqlp_index_hint(pstate, $5, 010+$3); }
   | IGNORE KEY opt_for_join '(' index_list ')'
                  { sqlp_index_hint(pstate, $5, 020+$3); }
   | FORCE KEY opt_for_join '(' index_list ')'
                  { sqlp_index_hint(pstate, $5, 030+$3); }
   | /* nil */
   ;

opt_for_join: FOR JOIN { $$ = 1; }
   | /* nil */ { $$ = 0; }
   ;

index_list: NAME  { sqlp_index(pstate, $1); free($1); $$ = 1; }
   | index_list ',' NAME { sqlp_index(pstate, $3); free($3); $$ = $1 + 1; }
   ;

table_subquery: '(' select_stmt ')' { sqlp_subquery(pstate); }
   ;


   /**** expressions ****/

expr: NAME          { sqlp_name(pstate, $1); free($1); }
   | USERVAR         { sqlp_uservar(pstate, $1); free($1); }
   | NAME '.' NAME { sqlp_fieldname(pstate, $1, $3); free($1); free($3); }
   | STRING        { sqlp_string(pstate, $1); free($1); }
   | INTNUM        { sqlp_number(pstate, $1); }
   | APPROXNUM     { sqlp_float(pstate, $1); }
   | BOOL          { sqlp_bool(pstate, $1); }
   ;

expr: expr '+' expr { sqlp_expr_op(pstate, SEO_ADD); }
   | expr '-' expr { sqlp_expr_op(pstate, SEO_SUB); }
   | expr '*' expr { sqlp_expr_op(pstate, SEO_MUL); }
   | expr '/' expr { sqlp_expr_op(pstate, SEO_DIV); }
   | expr '%' expr { sqlp_expr_op(pstate, SEO_MOD); }
   | expr MOD expr { sqlp_expr_op(pstate, SEO_MOD); }
   | '-' expr %prec UMINUS { sqlp_expr_op(pstate, SEO_NEG); }
   | expr ANDOP expr { sqlp_expr_op(pstate, SEO_AND); }
   | expr OR expr { sqlp_expr_op(pstate, SEO_OR); }
   | expr XOR expr { sqlp_expr_op(pstate, SEO_XOR); }
   | expr COMPARISON expr { sqlp_expr_cmp(pstate, $2); }
   | expr COMPARISON '(' select_stmt ')' { sqlp_expr_cmp_sel(pstate, 0, $2); }
   | expr COMPARISON ANY '(' select_stmt ')' { sqlp_expr_cmp_sel(pstate, 1, $2); }
   | expr COMPARISON SOME '(' select_stmt ')' { sqlp_expr_cmp_sel(pstate, 2, $2); }
   | expr COMPARISON ALL '(' select_stmt ')' { sqlp_expr_cmp_sel(pstate, 3, $2); }
   | expr '|' expr { sqlp_expr_op(pstate, SEO_BITOR); }
   | expr '&' expr { sqlp_expr_op(pstate, SEO_BITAND); }
   | expr '^' expr { sqlp_expr_op(pstate, SEO_BITXOR); }
   | expr SHIFT expr { sqlp_expr_op(pstate, $2 == 1 ? SEO_SHL : SEO_SHR); }
   | NOT expr { sqlp_expr_op(pstate, SEO_NOT); }
   | '!' expr { sqlp_expr_op(pstate, SEO_NOT); }
   | USERVAR ASSIGN expr { sqlp_assign_at(pstate, $1); free($1); }
   ;    

expr:  expr IS NULLX     { sqlp_expr_op(pstate, SEO_IS_NULL); }
   |   expr IS NOT NULLX { sqlp_expr_op(pstate, SEO_IS_NULL); sqlp_expr_op(pstate, SEO_NOT); }
   |   expr IS BOOL      { sqlp_expr_is_bool(pstate, $3); }
   |   expr IS NOT BOOL  { sqlp_expr_is_bool(pstate, $4); sqlp_expr_op(pstate, SEO_NOT); }
   ;

expr: expr BETWEEN expr AND expr %prec BETWEEN { sqlp_expr_op(pstate, SEO_BETWEEN); }
   ;


val_list: expr { $$ = 1; }
   | expr ',' val_list { $$ = 1 + $3; }
   ;

opt_val_list: /* nil */ { $$ = 0; }
   | val_list
   ;

expr: expr IN '(' val_list ')'       { sqlp_expr_is_in(pstate, $4); }
   | expr NOT IN '(' val_list ')'    { sqlp_expr_is_in(pstate, $5); sqlp_expr_op(pstate, SEO_NOT); }
   | expr IN '(' select_stmt ')'     { sqlp_expr_op(pstate, SEO_IN_SELECT); }
   | expr NOT IN '(' select_stmt ')' { sqlp_expr_op(pstate, SEO_IN_SELECT); sqlp_expr_op(pstate, SEO_NOT); }
   | EXISTS '(' select_stmt ')'      { sqlp_expr_op(pstate, SEO_EXISTS); if($1)sqlp_expr_op(pstate, SEO_NOT); }
   ;

expr: NAME '(' opt_val_list ')' {  sqlp_call(pstate, $3, $1); free($1); }
   ;

  /* functions with special syntax */
expr: FCOUNT '(' '*' ')' { sqlp_call(pstate, 0, "COUNTALL"); }
   | FCOUNT '(' expr ')' { sqlp_call(pstate, 1, "COUNT"); } 

expr: FSUBSTRING '(' val_list ')' {  sqlp_call(pstate, $3, "SUBSTR");}
   | FSUBSTRING '(' expr FROM expr ')' {  sqlp_call(pstate, 2, "SUBSTR"); }
   | FSUBSTRING '(' expr FROM expr FOR expr ')' {  sqlp_call(pstate, 3, "SUBSTR"); }
| FTRIM '(' val_list ')' { sqlp_call(pstate, $3, "TRIM"); }
   | FTRIM '(' trim_ltb expr FROM val_list ')' { sqlp_call(pstate, 3, "TRIM"); }
   ;

trim_ltb: LEADING { sqlp_call_trim_opts(pstate, 0); }
   | TRAILING { sqlp_call_trim_opts(pstate, 1); }
   | BOTH { sqlp_call_trim_opts(pstate, 2); }
   ;

expr: FDATE_ADD '(' expr ',' interval_exp ')' { sqlp_call_date(pstate, 3, SEO_ADD); }
   |  FDATE_SUB '(' expr ',' interval_exp ')' { sqlp_call_date(pstate, 3, SEO_SUB); }
   ;

interval_exp: INTERVAL expr DAY_HOUR { sqlp_date_interval(pstate, SDI_DAY_HOUR); }
   | INTERVAL expr DAY_MICROSECOND { sqlp_date_interval(pstate, SDI_DAY_MICROSECOND); }
   | INTERVAL expr DAY_MINUTE { sqlp_date_interval(pstate, SDI_DAY_MINUTE); }
   | INTERVAL expr DAY_SECOND { sqlp_date_interval(pstate, SDI_DAY_SECOND); }
   | INTERVAL expr YEAR_MONTH { sqlp_date_interval(pstate, SDI_YEAR_MONTH); }
   | INTERVAL expr YEAR       { sqlp_date_interval(pstate, SDI_YEAR); }
   | INTERVAL expr HOUR_MICROSECOND { sqlp_date_interval(pstate, SDI_HOUR_MICROSECOND); }
   | INTERVAL expr HOUR_MINUTE { sqlp_date_interval(pstate, SDI_HOUR_MINUTE); }
   | INTERVAL expr HOUR_SECOND { sqlp_date_interval(pstate, SDI_HOUR_SECOND); }
   ;

expr: CASE expr case_list END           { sqlp_caseval(pstate, $3, 0); }
   |  CASE expr case_list ELSE expr END { sqlp_caseval(pstate, $3, 1); }
   |  CASE case_list END                { sqlp_case(pstate, $2, 0); }
   |  CASE case_list ELSE expr END      { sqlp_case(pstate, $2, 1); }
   ;

case_list: WHEN expr THEN expr     { $$ = 1; }
         | case_list WHEN expr THEN expr { $$ = $1+1; } 
   ;

expr: expr LIKE expr { sqlp_expr_op(pstate, SEO_LIKE); }
   | expr NOT LIKE expr { sqlp_expr_op(pstate, SEO_LIKE); sqlp_expr_op(pstate, SEO_NOT); }
   ;

expr: expr REGEXP expr { sqlp_expr_op(pstate, SEO_REGEX); }
   | expr NOT REGEXP expr { sqlp_expr_op(pstate, SEO_REGEX); sqlp_expr_op(pstate, SEO_NOT); }
   ;

expr: CURRENT_TIMESTAMP { sqlp_now(pstate); };
   | CURRENT_DATE	{ sqlp_now(pstate); };
   | CURRENT_TIME	{ sqlp_now(pstate); };
   ;

expr: BINARY expr %prec UMINUS { sqlp_expr_op(pstate, SEO_STRTOBIN); }
   ;

%%

void yy::SqlParser::error(const location_type& l,
                          const std::string& m)
{
    driver.error(l, m);
}
