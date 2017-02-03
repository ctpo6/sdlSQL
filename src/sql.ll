%{
#include "driver.hpp"

#include "sql.tab.hpp"

#include <cerrno>
#include <climits>
#include <cstdlib>
#include <string>

// Work around an incompatibility in flex (at least versions
// 2.5.31 through 2.5.33): it generates code that does
// not conform to C89.  See Debian bug 333231
// <http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=333231>.
#undef yywrap
#define yywrap() 1

// The location of the current token.
static yy::location loc;

int oldstate;

%}

%option noyywrap nounput batch noinput case-insensitive

%x COMMENT
blank [ \t]


%{
// Code run each time a pattern is matched.
#define YY_USER_ACTION loc.columns(yyleng);
%}


%%

%{
    // Code run each time yylex is called.
    loc.step();
%}


  /* keywords */
AND     { return yy::SqlParser::make_OP_AND(loc); }
AS      { return yy::SqlParser::make_AS(loc); }
ASC     { return yy::SqlParser::make_ASC(loc); }
BY      { return yy::SqlParser::make_BY(loc); }
COMMENT { return yy::SqlParser::make_COMMENT(loc); }
DESC    { return yy::SqlParser::make_DESC(loc); }
FROM    { return yy::SqlParser::make_FROM(loc); }
JOIN    { return yy::SqlParser::make_JOIN(loc); }
NOT     { return yy::SqlParser::make_NOT(loc); }
NULL    { return yy::SqlParser::make_NULLX(loc); }
ON      { return yy::SqlParser::make_ON(loc); }
OR      { return yy::SqlParser::make_OP_OR(loc); }
ORDER   { return yy::SqlParser::make_ORDER(loc); }
SELECT  { return yy::SqlParser::make_SELECT(loc); }
TOP     { return yy::SqlParser::make_TOP(loc); }
WHERE   { return yy::SqlParser::make_WHERE(loc); }

   /* numbers */

-?[0-9]+    {
    errno = 0;
    long n = strtol(yytext, NULL, 10);
    if (errno == ERANGE) {
        driver.error(loc, "integer is out of range");
    }
    return yy::SqlParser::make_INTNUM(n, loc);
}

-?[0-9]+"."[0-9]* |
-?"."[0-9]+	|
-?[0-9]+E[-+]?[0-9]+	|
-?[0-9]+"."[0-9]*E[-+]?[0-9]+ |
-?"."[0-9]*E[-+]?[0-9]+     {
    errno = 0;
    double n = strtod(yytext, NULL);
    if (errno == ERANGE) {
        driver.error(loc, "floating point is out of range");
    }
    return yy::SqlParser::make_APPROXNUM(n, loc);
}

   /* strings */

'(\\.|''|[^'\n])*'	|
\"(\\.|\"\"|[^"\n])*\"  { return yy::SqlParser::make_STRING(yytext, loc); }

'(\\.|[^'\n])*$         { driver.error(loc, std::string("unclosed string: ") + yytext); }
\"(\\.|[^"\n])*$        { driver.error(loc, std::string("unclosed string: ") + yytext); }

   /* operators */

    /*[-+&~|^/%*(),.;!]   { return yytext[0]; }*/
"*"     { return yy::SqlParser::make_S_STAR(loc); }
"("     { return yy::SqlParser::make_S_LPAREN(loc); }
")"     { return yy::SqlParser::make_S_RPAREN(loc); }
","     { return yy::SqlParser::make_S_COMMA(loc); }
"."     { return yy::SqlParser::make_S_DOT(loc); }
";"     { return yy::SqlParser::make_S_SEMICOLON(loc); }

"&&"	{ return yy::SqlParser::make_OP_AND(loc); }
"||"    { return yy::SqlParser::make_OP_OR(loc); }

"="     { return yy::SqlParser::make_COMPARISON(4, loc); }
"<=>"	{ return yy::SqlParser::make_COMPARISON(12, loc); }
">="	{ return yy::SqlParser::make_COMPARISON(6, loc); }
">"     { return yy::SqlParser::make_COMPARISON(2, loc); }
"<="	{ return yy::SqlParser::make_COMPARISON(5, loc); }
"<"     { return yy::SqlParser::make_COMPARISON(1, loc); }
"!="	|
"<>"	{ return yy::SqlParser::make_COMPARISON(3, loc); }

        /* functions */

	/* 
         peek ahead and return function if name(
    */
    /*
    COUNT    { int c = yyinput(pstate->scanner); unput(c);
           if(c == '(') return FCOUNT;
           yylval->strval = strdup(yytext);
           return NAME; }
    */

[A-Za-z][A-Za-z0-9_]*	{ return yy::SqlParser::make_NAME(yytext, loc); }
`[^`/\\.\n]+`           { return yy::SqlParser::make_NAME(
                            std::string(yytext + 1, yyleng - 2), loc); }

`[^`\n]*$               { driver.error(loc, std::string("unterminated quoted name: ") + yytext); }


	/* comments */   
#.*		;
"--"[ \t].*	;

"/*"                { oldstate = YY_START; BEGIN COMMENT; }
<COMMENT>"*/"       { BEGIN oldstate; }
<COMMENT>.   ;
<COMMENT>\n         { loc.lines(yyleng); loc.step(); }
<COMMENT><<EOF>>    { driver.error(loc, "unclosed comment"); }

	        /* everything else */
{blank}+   { loc.step(); }
[\n]+      { loc.lines(yyleng); loc.step(); }
.          { driver.error(loc, "invalid character"); }
<<EOF>>    { return yy::SqlParser::make_END(loc); }


%%

void Driver::scan_begin()
{
  yy_flex_debug = trace_scanning;
  if (file.empty() || file == "-") {
      yyin = stdin;
  }
  else if (!(yyin = fopen(file.c_str(), "r"))) {
      error("cannot open " + file + ": " + strerror(errno));
      exit(EXIT_FAILURE);
  }
}


void Driver::scan_end()
{
  fclose(yyin);
}
