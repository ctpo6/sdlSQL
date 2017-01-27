/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 18 "src/sql.yy" /* yacc.c:339  */

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

const char *filename;

#line 74 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "sql.tab.hpp".  */
#ifndef YY_YY_HOME_YURI_WORK_BISON_SDLSQL_OUT_BISON_SQL_TAB_HPP_INCLUDED
# define YY_YY_HOME_YURI_WORK_BISON_SDLSQL_OUT_BISON_SQL_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 32 "src/sql.yy" /* yacc.c:355  */


extern const char *filename;

typedef struct YYLTYPE {
  int first_line;
  int first_column;
  int last_line;
  int last_column;
  const char *filename;
} YYLTYPE;
# define YYLTYPE_IS_DECLARED 1

# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)                                                            \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	  (Current).filename     = YYRHSLOC (Rhs, 1).filename;	        \
	}								\
      else								\
	{ /* empty RHS */						\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	  (Current).filename  = NULL;					\
	}								\
    while (0)

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif

struct psql_state;

#line 145 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NAME = 258,
    STRING = 259,
    INTNUM = 260,
    BOOL = 261,
    APPROXNUM = 262,
    USERVAR = 263,
    ASSIGN = 264,
    OR = 265,
    XOR = 266,
    ANDOP = 267,
    IN = 268,
    IS = 269,
    LIKE = 270,
    REGEXP = 271,
    NOT = 272,
    BETWEEN = 273,
    COMPARISON = 274,
    SHIFT = 275,
    MOD = 276,
    UMINUS = 277,
    ADD = 278,
    ALL = 279,
    ALTER = 280,
    ANALYZE = 281,
    AND = 282,
    ANY = 283,
    AS = 284,
    ASC = 285,
    AUTO_INCREMENT = 286,
    BEFORE = 287,
    BIGINT = 288,
    BINARY = 289,
    BIT = 290,
    BLOB = 291,
    BOTH = 292,
    BY = 293,
    CALL = 294,
    CASCADE = 295,
    CASE = 296,
    CHANGE = 297,
    CHAR = 298,
    CHECK = 299,
    COLLATE = 300,
    COLUMN = 301,
    COMMENT = 302,
    CONDITION = 303,
    CONSTRAINT = 304,
    CONTINUE = 305,
    CONVERT = 306,
    CREATE = 307,
    CROSS = 308,
    CURRENT_DATE = 309,
    CURRENT_TIME = 310,
    CURRENT_TIMESTAMP = 311,
    CURRENT_USER = 312,
    CURSOR = 313,
    DATABASE = 314,
    DATABASES = 315,
    DATE = 316,
    DATETIME = 317,
    DAY_HOUR = 318,
    DAY_MICROSECOND = 319,
    DAY_MINUTE = 320,
    DAY_SECOND = 321,
    DECIMAL = 322,
    DECLARE = 323,
    DEFAULT = 324,
    DELAYED = 325,
    DELETE = 326,
    DESC = 327,
    DESCRIBE = 328,
    DETERMINISTIC = 329,
    DISTINCT = 330,
    DISTINCTROW = 331,
    DIV = 332,
    DOUBLE = 333,
    DROP = 334,
    DUAL = 335,
    EACH = 336,
    ELSE = 337,
    ELSEIF = 338,
    ENCLOSED = 339,
    END = 340,
    ENUM = 341,
    ESCAPED = 342,
    EXISTS = 343,
    EXIT = 344,
    EXPLAIN = 345,
    FETCH = 346,
    FLOAT = 347,
    FOR = 348,
    FORCE = 349,
    FOREIGN = 350,
    FROM = 351,
    FULLTEXT = 352,
    GRANT = 353,
    GROUP = 354,
    HAVING = 355,
    HIGH_PRIORITY = 356,
    HOUR_MICROSECOND = 357,
    HOUR_MINUTE = 358,
    HOUR_SECOND = 359,
    IF = 360,
    IGNORE = 361,
    INDEX = 362,
    INFILE = 363,
    INNER = 364,
    INOUT = 365,
    INSENSITIVE = 366,
    INSERT = 367,
    INT = 368,
    INTEGER = 369,
    INTERVAL = 370,
    INTO = 371,
    ITERATE = 372,
    JOIN = 373,
    KEY = 374,
    KEYS = 375,
    KILL = 376,
    LEADING = 377,
    LEAVE = 378,
    LEFT = 379,
    LIMIT = 380,
    LINES = 381,
    LOAD = 382,
    LOCALTIME = 383,
    LOCALTIMESTAMP = 384,
    LOCK = 385,
    LONG = 386,
    LONGBLOB = 387,
    LONGTEXT = 388,
    LOOP = 389,
    LOW_PRIORITY = 390,
    MATCH = 391,
    MEDIUMBLOB = 392,
    MEDIUMINT = 393,
    MEDIUMTEXT = 394,
    MINUTE_MICROSECOND = 395,
    MINUTE_SECOND = 396,
    MODIFIES = 397,
    NATURAL = 398,
    NO_WRITE_TO_BINLOG = 399,
    NULLX = 400,
    NUMBER = 401,
    ON = 402,
    ONDUPLICATE = 403,
    OPTIMIZE = 404,
    OPTION = 405,
    OPTIONALLY = 406,
    ORDER = 407,
    OUT = 408,
    OUTER = 409,
    OUTFILE = 410,
    PRECISION = 411,
    PRIMARY = 412,
    PROCEDURE = 413,
    PURGE = 414,
    QUICK = 415,
    READ = 416,
    READS = 417,
    REAL = 418,
    REFERENCES = 419,
    RELEASE = 420,
    RENAME = 421,
    REPEAT = 422,
    REPLACE = 423,
    REQUIRE = 424,
    RESTRICT = 425,
    RETURN = 426,
    REVOKE = 427,
    RIGHT = 428,
    ROLLUP = 429,
    SCHEMA = 430,
    SCHEMAS = 431,
    SECOND_MICROSECOND = 432,
    SELECT = 433,
    SENSITIVE = 434,
    SEPARATOR = 435,
    SET = 436,
    SHOW = 437,
    SMALLINT = 438,
    SOME = 439,
    SONAME = 440,
    SPATIAL = 441,
    SPECIFIC = 442,
    SQL = 443,
    SQLEXCEPTION = 444,
    SQLSTATE = 445,
    SQLWARNING = 446,
    SQL_BIG_RESULT = 447,
    SQL_CALC_FOUND_ROWS = 448,
    SQL_SMALL_RESULT = 449,
    SSL = 450,
    STARTING = 451,
    STRAIGHT_JOIN = 452,
    TABLE = 453,
    TEMPORARY = 454,
    TEXT = 455,
    TERMINATED = 456,
    THEN = 457,
    TIME = 458,
    TIMESTAMP = 459,
    TINYBLOB = 460,
    TINYINT = 461,
    TINYTEXT = 462,
    TO = 463,
    TRAILING = 464,
    TRIGGER = 465,
    UNDO = 466,
    UNION = 467,
    UNIQUE = 468,
    UNLOCK = 469,
    UNSIGNED = 470,
    UPDATE = 471,
    USAGE = 472,
    USE = 473,
    USING = 474,
    UTC_DATE = 475,
    UTC_TIME = 476,
    UTC_TIMESTAMP = 477,
    VALUES = 478,
    VARBINARY = 479,
    VARCHAR = 480,
    VARYING = 481,
    WHEN = 482,
    WHERE = 483,
    WHILE = 484,
    WITH = 485,
    WRITE = 486,
    YEAR = 487,
    YEAR_MONTH = 488,
    ZEROFILL = 489,
    FSUBSTRING = 490,
    FTRIM = 491,
    FDATE_ADD = 492,
    FDATE_SUB = 493,
    FCOUNT = 494
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 73 "src/sql.yy" /* yacc.c:355  */

	int intval;
	double floatval;
	char *strval;
	int subtok;

#line 404 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (yyscan_t scanner, struct psql_state *pstate);

#endif /* !YY_YY_HOME_YURI_WORK_BISON_SDLSQL_OUT_BISON_SQL_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 80 "src/sql.yy" /* yacc.c:358  */

#include "sql.lex.hpp"
#include "sql-parser.hpp"
#line 358 "src/sql.yy" /* yacc.c:358  */

void yyerror(YYLTYPE *, yyscan_t scanner, struct psql_state *pstate, const char *s, ...);
void lyyerror(YYLTYPE t, const char *s, ...);
 

#line 443 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1546

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  254
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  315
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  646

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   494

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    18,     2,     2,     2,    28,    22,     2,
     252,   253,    26,    24,   250,    25,   251,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   249,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    21,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    19,    20,    23,    29,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   367,   367,   368,   371,   372,   376,   379,   381,   387,
     388,   390,   391,   395,   397,   401,   402,   403,   406,   407,
     410,   410,   412,   412,   415,   415,   416,   419,   420,   423,
     424,   426,   427,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   442,   443,   444,   447,   449,   450,   453,   454,
     458,   459,   461,   462,   465,   466,   469,   470,   471,   475,
     477,   479,   481,   483,   487,   488,   489,   492,   493,   496,
     497,   500,   501,   502,   505,   505,   508,   509,   513,   515,
     517,   519,   522,   523,   526,   527,   530,   535,   538,   543,
     544,   545,   546,   549,   554,   555,   559,   559,   561,   569,
     572,   578,   579,   582,   583,   584,   585,   586,   589,   589,
     592,   593,   596,   597,   600,   601,   602,   603,   606,   612,
     618,   621,   624,   627,   633,   636,   642,   648,   654,   657,
     664,   665,   666,   670,   673,   676,   679,   687,   691,   692,
     695,   696,   702,   706,   707,   710,   711,   716,   719,   723,
     728,   733,   737,   743,   748,   749,   752,   752,   755,   756,
     757,   758,   759,   762,   763,   764,   765,   766,   767,   768,
     769,   770,   771,   772,   773,   774,   777,   778,   779,   782,
     783,   786,   787,   788,   791,   792,   793,   797,   798,   799,
     800,   801,   802,   803,   804,   805,   806,   807,   808,   809,
     810,   811,   812,   813,   814,   815,   816,   817,   818,   819,
     820,   821,   822,   823,   824,   825,   826,   829,   830,   833,
     836,   837,   838,   841,   842,   847,   851,   854,   855,   857,
     858,   864,   867,   869,   869,   872,   874,   879,   880,   881,
     882,   883,   884,   885,   888,   889,   890,   891,   892,   893,
     894,   895,   896,   897,   898,   899,   900,   901,   902,   903,
     904,   905,   906,   907,   908,   909,   912,   913,   914,   915,
     918,   922,   923,   926,   927,   930,   931,   932,   933,   934,
     937,   941,   942,   944,   945,   946,   947,   948,   951,   952,
     953,   956,   957,   960,   961,   962,   963,   964,   965,   966,
     967,   968,   971,   972,   973,   974,   977,   978,   981,   982,
     985,   986,   989,   990,   991,   994
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "STRING", "INTNUM", "BOOL",
  "APPROXNUM", "USERVAR", "ASSIGN", "OR", "XOR", "ANDOP", "IN", "IS",
  "LIKE", "REGEXP", "NOT", "'!'", "BETWEEN", "COMPARISON", "'|'", "'&'",
  "SHIFT", "'+'", "'-'", "'*'", "'/'", "'%'", "MOD", "'^'", "UMINUS",
  "ADD", "ALL", "ALTER", "ANALYZE", "AND", "ANY", "AS", "ASC",
  "AUTO_INCREMENT", "BEFORE", "BIGINT", "BINARY", "BIT", "BLOB", "BOTH",
  "BY", "CALL", "CASCADE", "CASE", "CHANGE", "CHAR", "CHECK", "COLLATE",
  "COLUMN", "COMMENT", "CONDITION", "CONSTRAINT", "CONTINUE", "CONVERT",
  "CREATE", "CROSS", "CURRENT_DATE", "CURRENT_TIME", "CURRENT_TIMESTAMP",
  "CURRENT_USER", "CURSOR", "DATABASE", "DATABASES", "DATE", "DATETIME",
  "DAY_HOUR", "DAY_MICROSECOND", "DAY_MINUTE", "DAY_SECOND", "DECIMAL",
  "DECLARE", "DEFAULT", "DELAYED", "DELETE", "DESC", "DESCRIBE",
  "DETERMINISTIC", "DISTINCT", "DISTINCTROW", "DIV", "DOUBLE", "DROP",
  "DUAL", "EACH", "ELSE", "ELSEIF", "ENCLOSED", "END", "ENUM", "ESCAPED",
  "EXISTS", "EXIT", "EXPLAIN", "FETCH", "FLOAT", "FOR", "FORCE", "FOREIGN",
  "FROM", "FULLTEXT", "GRANT", "GROUP", "HAVING", "HIGH_PRIORITY",
  "HOUR_MICROSECOND", "HOUR_MINUTE", "HOUR_SECOND", "IF", "IGNORE",
  "INDEX", "INFILE", "INNER", "INOUT", "INSENSITIVE", "INSERT", "INT",
  "INTEGER", "INTERVAL", "INTO", "ITERATE", "JOIN", "KEY", "KEYS", "KILL",
  "LEADING", "LEAVE", "LEFT", "LIMIT", "LINES", "LOAD", "LOCALTIME",
  "LOCALTIMESTAMP", "LOCK", "LONG", "LONGBLOB", "LONGTEXT", "LOOP",
  "LOW_PRIORITY", "MATCH", "MEDIUMBLOB", "MEDIUMINT", "MEDIUMTEXT",
  "MINUTE_MICROSECOND", "MINUTE_SECOND", "MODIFIES", "NATURAL",
  "NO_WRITE_TO_BINLOG", "NULLX", "NUMBER", "ON", "ONDUPLICATE", "OPTIMIZE",
  "OPTION", "OPTIONALLY", "ORDER", "OUT", "OUTER", "OUTFILE", "PRECISION",
  "PRIMARY", "PROCEDURE", "PURGE", "QUICK", "READ", "READS", "REAL",
  "REFERENCES", "RELEASE", "RENAME", "REPEAT", "REPLACE", "REQUIRE",
  "RESTRICT", "RETURN", "REVOKE", "RIGHT", "ROLLUP", "SCHEMA", "SCHEMAS",
  "SECOND_MICROSECOND", "SELECT", "SENSITIVE", "SEPARATOR", "SET", "SHOW",
  "SMALLINT", "SOME", "SONAME", "SPATIAL", "SPECIFIC", "SQL",
  "SQLEXCEPTION", "SQLSTATE", "SQLWARNING", "SQL_BIG_RESULT",
  "SQL_CALC_FOUND_ROWS", "SQL_SMALL_RESULT", "SSL", "STARTING",
  "STRAIGHT_JOIN", "TABLE", "TEMPORARY", "TEXT", "TERMINATED", "THEN",
  "TIME", "TIMESTAMP", "TINYBLOB", "TINYINT", "TINYTEXT", "TO", "TRAILING",
  "TRIGGER", "UNDO", "UNION", "UNIQUE", "UNLOCK", "UNSIGNED", "UPDATE",
  "USAGE", "USE", "USING", "UTC_DATE", "UTC_TIME", "UTC_TIMESTAMP",
  "VALUES", "VARBINARY", "VARCHAR", "VARYING", "WHEN", "WHERE", "WHILE",
  "WITH", "WRITE", "YEAR", "YEAR_MONTH", "ZEROFILL", "FSUBSTRING", "FTRIM",
  "FDATE_ADD", "FDATE_SUB", "FCOUNT", "';'", "','", "'.'", "'('", "')'",
  "$accept", "stmt_list", "stmt", "select_stmt", "opt_where",
  "opt_groupby", "groupby_list", "opt_asc_desc", "opt_with_rollup",
  "opt_having", "opt_orderby", "opt_limit", "opt_into_list", "column_list",
  "select_opts", "select_expr_list", "select_expr", "table_references",
  "table_reference", "table_factor", "opt_as", "opt_as_alias",
  "join_table", "opt_inner_cross", "opt_outer", "left_or_right",
  "opt_left_or_right_outer", "opt_join_condition", "join_condition",
  "index_hint", "opt_for_join", "index_list", "table_subquery",
  "delete_stmt", "delete_opts", "delete_list", "opt_dot_star",
  "insert_stmt", "opt_ondupupdate", "insert_opts", "opt_into",
  "opt_col_names", "insert_vals_list", "insert_vals", "insert_asgn_list",
  "replace_stmt", "update_stmt", "update_opts", "update_asgn_list",
  "create_database_stmt", "opt_if_not_exists", "drop_database_stmt",
  "opt_if_exists", "create_table_stmt", "create_col_list",
  "create_definition", "$@1", "column_atts", "opt_length", "opt_binary",
  "opt_uz", "opt_csc", "data_type", "enum_list", "create_select_statement",
  "opt_ignore_replace", "opt_temporary", "drop_table_stmt", "table_list",
  "set_stmt", "set_list", "set_expr", "expr", "val_list", "opt_val_list",
  "trim_ltb", "interval_exp", "case_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    33,   273,
     274,   124,    38,   275,    43,    45,    42,    47,    37,   276,
      94,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,    59,
      44,    46,    40,    41
};
# endif

#define YYPACT_NINF -377

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-377)))

#define YYTABLE_NINF -150

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-150)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     970,  -217,   -39,  -377,   -38,  -377,  -377,  -377,    58,     5,
      21,  -187,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,    30,    30,  -377,   -88,    56,    40,    40,
     -27,   159,   159,   131,   241,    29,  -377,   213,     6,  -377,
      38,    45,  -377,    65,   286,   297,    30,    55,   327,  -377,
    -377,  -377,   -59,   252,   353,   367,    40,  -377,  -377,  -377,
    -377,  -377,   371,   399,   -64,  -377,  -377,  -377,  -377,   400,
     680,   680,   680,  -377,  -377,   680,   355,  -377,  -377,  -377,
    -377,  -377,   161,  -377,  -377,  -377,  -377,  -377,   181,   186,
     197,   205,   211,   -57,  -377,  1451,   680,   680,    58,     7,
      14,    16,    -1,  -134,   145,  -377,  -377,   438,  -377,  -377,
    -377,  -377,  -377,   480,   464,  -377,    48,    63,     6,   488,
    -377,  -377,  -377,   226,  -154,   -32,   514,   680,   680,  1245,
    1245,  -377,  -377,   680,   994,   -71,   343,   680,   304,   680,
     680,   382,     6,   680,  -377,   680,   680,   680,   282,    18,
     680,   680,   380,   680,     8,   680,   680,   680,   680,   680,
     680,   680,   680,   680,   680,   528,  -377,  1516,  1516,  -377,
     533,   -48,   288,    43,   539,     6,  -377,  -377,  -377,   -83,
    -377,     6,   408,   381,  -377,   540,    -4,  -377,   680,   385,
       6,  -185,    55,  -377,  -377,   315,   544,   301,   -35,   544,
      -5,  -377,   822,  -377,   311,  1516,  1073,   -47,   680,  -377,
     680,   313,   801,   316,  -377,  -377,  -377,   320,   680,   870,
     919,   322,   759,  -185,  -377,  1231,  1102,   733,   423,  -377,
      22,  -377,   888,   888,   324,   680,   680,  1489,   337,   340,
     341,   343,   692,   971,   476,   532,   314,   314,   537,   537,
     537,   537,  -377,  -377,    31,   451,   466,   468,  -377,  -377,
    -377,   -17,  -135,   145,   381,   381,   470,   448,     6,  -377,
     478,  -377,  -377,  -377,   603,   116,  -377,   438,  1516,   560,
     474,  -185,  -377,  -377,   321,   589,  -100,  -377,  -377,    66,
     359,   455,  -100,   359,   455,   680,  -377,   680,   680,  -377,
    1375,  1151,  -377,   680,  -377,  -377,  1279,   489,   489,  -377,
    -377,   506,   363,   372,  -377,  -377,   423,   888,   888,   680,
     343,   343,   343,   378,   -48,   513,   513,   513,   680,   621,
     638,   385,  -377,  -377,     6,   680,   -95,     6,    28,   108,
     390,   391,   516,    85,  -377,   642,   343,   680,   680,  -377,
    -377,  -377,  -377,   490,   518,   644,  -377,   362,  -377,   520,
     -97,  -377,  -377,   -97,  -377,  -377,  1516,  1396,  -377,   680,
      64,   680,   680,   397,   398,   605,   545,  -377,  -377,   402,
     404,   844,   406,   407,   409,  -377,  -377,   526,   411,   412,
     414,  1516,   641,   -16,   474,  -377,  1516,   680,   420,  -377,
    -377,   -95,   116,  -377,   421,   424,   301,   301,   425,   116,
     -45,  1140,  -377,   432,  1417,   940,  -377,  1516,   450,   669,
    -377,  -377,  -377,   171,  1516,   439,  -377,  -377,  -377,  1516,
     680,  -377,   437,   962,  -377,  -377,   680,   680,   385,  -377,
    -377,  -377,  -377,  -377,  -377,   689,   689,   689,   680,   680,
     696,  -377,  1516,   301,  -377,   189,   301,   301,   206,   219,
     301,  -377,  -377,   449,   449,   449,  -377,   449,  -377,  -377,
     449,   449,   452,   449,   449,   449,  -377,   657,  -377,   449,
     657,   449,   454,   449,   657,  -377,  -377,  -377,   449,   657,
     456,   458,  -377,  -377,   680,  -377,  -377,  -377,   680,   544,
     615,   631,  -377,   520,   780,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,    23,  1516,   474,  -377,   221,
     225,   227,  1516,  1516,   682,   231,   -18,   232,   239,  -377,
    -377,   259,   698,  -377,  -377,  -377,  -377,  -377,  -377,   703,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,   703,  -377,
    -377,  -377,  -377,   706,   719,   985,  1417,  1516,   475,  -377,
    1516,  -377,  1516,   260,  -377,   543,  -377,   602,   726,  -377,
    -377,  -377,   680,  -377,  -377,  -377,  -377,  -377,   261,  -175,
     191,  -175,  -175,  -377,   266,  -175,  -175,  -175,   191,  -175,
     191,  -175,   268,  -175,   191,  -175,   191,   479,   486,   577,
    -377,   729,   377,  -377,  -377,   612,  -101,  -377,  -377,  -377,
     301,  -377,  -377,  1516,   736,  -377,  -377,  -377,   552,   747,
     794,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,   301,   569,   587,   849,  -377,  -377,   191,
     191,   191,   279,  -377,  -377,  -377
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,   223,    92,   223,   103,   103,    33,     0,   103,
       0,     0,     6,    87,    99,   124,   128,   137,   142,   147,
     225,   231,     4,   140,   140,   224,     0,     0,   145,   145,
       0,   109,   109,     0,     0,   232,   233,     0,     0,     1,
       0,     0,     2,     0,     0,     0,   140,    96,     0,    91,
      89,    90,     0,     0,     0,     0,   145,   105,   106,   107,
     108,   104,     0,     0,   237,   240,   241,   243,   242,   238,
       0,     0,     0,    44,    34,     0,     0,   313,   314,   312,
      35,    36,     0,    37,    40,    41,    39,    38,     0,     0,
       0,     0,     0,     7,    42,    58,     0,     0,     0,   107,
     104,    58,     0,     0,    46,    48,    49,    55,     5,     3,
     141,   138,   139,     0,     0,    94,     9,     0,     0,     0,
     146,   143,   144,     0,   110,   110,     0,   273,     0,   263,
     264,   250,   315,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,   236,   235,   234,
       0,    81,     0,     0,     0,     0,    66,    65,    69,    73,
      70,     0,     0,    67,    54,     0,   220,    97,     0,    22,
       0,     9,    96,   227,   228,   226,     0,     0,     0,     0,
       0,   239,   271,   274,     0,   265,     0,     0,     0,   304,
       0,     0,   271,     0,   290,   288,   289,     0,     0,     0,
       0,     0,     0,     9,    43,   252,   253,   251,     0,   268,
       0,   266,   308,   310,     0,     0,     0,     0,     0,     0,
       0,     0,   254,   259,   260,   262,   244,   245,   246,   247,
     248,   249,   261,    56,    58,     0,     0,     0,    50,    86,
      53,     0,     9,    47,    67,    67,     0,    60,     0,    68,
       0,    52,   221,   222,     0,   156,   151,    55,    10,     0,
      24,     9,    93,    95,     0,     0,   101,    29,    30,     0,
       0,   101,   101,     0,   101,     0,   280,     0,     0,   302,
       0,     0,   279,     0,   283,   286,     0,     0,     0,   281,
     282,    11,     0,     0,   269,   267,     0,   309,   311,     0,
       0,     0,     0,     0,    81,    83,    83,    83,     0,     0,
       0,    22,    71,    72,     0,     0,    75,     0,   220,     0,
       0,     0,     0,     0,   154,     0,     0,     0,     0,    88,
      98,   229,   230,     0,     0,     0,   118,     0,   111,     0,
     101,   119,   126,   101,   127,   272,   306,     0,   305,     0,
       0,     0,     0,     0,     0,     0,    20,   277,   275,     0,
       0,   270,     0,     0,     0,   255,    51,     0,     0,     0,
       0,   133,     0,     0,    24,    63,    61,     0,     0,    59,
      74,     0,   156,   153,     0,     0,     0,     0,     0,   156,
     220,     0,   219,    23,    15,    25,   121,   120,     0,     0,
      31,    32,   115,     0,   114,     0,   100,   125,   303,   307,
       0,   284,     0,     0,   291,   292,     0,     0,    22,   278,
     276,   258,   256,   257,    82,     0,     0,     0,     0,     0,
       0,   129,    76,     0,    62,     0,     0,     0,     0,     0,
       0,   155,   150,   176,   176,   176,   208,   176,   198,   201,
     176,   176,     0,   176,   176,   176,   210,   179,   209,   176,
     179,   176,     0,   176,   179,   199,   200,   207,   176,   179,
       0,     0,   202,   163,     0,    16,    17,    13,     0,     0,
       0,     0,   112,     0,     0,   287,   293,   294,   295,   296,
     299,   300,   301,   298,   297,    18,    21,    24,    84,     0,
       0,     0,   134,   135,     0,     0,   220,     0,     0,   160,
     159,     0,     0,   181,   205,   187,   184,   181,   181,     0,
     181,   181,   181,   180,   184,   181,   184,   181,     0,   181,
     184,   181,   184,     0,     0,   157,    15,    26,   102,   123,
     122,   117,   116,     0,   285,     0,    12,    27,     0,    80,
      79,    78,     0,    77,   152,   161,   162,   158,     0,   193,
     203,   197,   195,   217,     0,   196,   191,   192,   214,   190,
     213,   194,     0,   189,   212,   188,   211,     0,     0,     0,
     170,     0,     0,   174,   165,     0,     0,    14,   113,    19,
       0,     8,    85,   136,     0,   177,   182,   183,     0,     0,
       0,   184,   184,   206,   184,   164,   175,   166,   167,   169,
     168,   173,   172,     0,    28,     0,     0,   186,   218,   215,
     216,   204,     0,   178,   185,   171
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -377,  -377,   845,    90,   -13,  -377,   418,   300,  -377,  -377,
    -291,  -376,  -377,  -239,  -377,  -377,   714,    81,   683,  -128,
     611,   -94,  -377,  -377,   127,  -377,  -377,  -377,   519,   595,
      96,    -3,  -377,  -377,  -377,   873,   730,  -377,    54,   428,
     891,   812,   665,   477,  -198,  -377,  -377,  -377,  -377,  -377,
     166,  -377,   184,  -377,   601,   617,  -377,  -377,   107,  -247,
     -87,  -269,  -377,   481,  -307,  -377,  1023,  -377,  -377,  -377,
    -377,   930,   -33,  -132,  -377,  -377,   722,   898
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,   189,   376,   413,   497,   566,   438,
     280,   349,   611,   289,    33,    93,    94,   103,   104,   105,
     185,   166,   106,   182,   270,   183,   266,   399,   400,   258,
     388,   519,   107,    13,    27,    52,   115,    14,   356,    31,
      62,   198,   360,   423,   286,    15,    16,    38,   262,    17,
      44,    18,    54,    19,   343,   344,   345,   555,   533,   544,
     579,   580,   493,   584,   276,   277,    26,    20,   195,    21,
      35,    36,   202,   203,   204,   218,   373,   135
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      95,   292,   101,   328,   449,   213,   217,   171,  -130,   101,
    -132,    64,    65,    66,    67,    68,    69,  -131,   451,   144,
     208,    39,    40,   209,   229,    70,    71,   632,   314,    23,
      28,   403,    22,    72,   144,   230,   196,   129,   130,   131,
     394,   238,   132,   134,   298,   239,   118,   299,   142,   616,
     264,    75,   188,   267,   165,   255,   174,   354,    76,    47,
     354,   397,    42,   167,   168,   175,    34,   256,   617,   165,
     272,    77,    78,    79,   145,   146,   147,   148,   149,   150,
     151,   152,     2,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   205,   313,   272,   197,   265,
     206,     3,   188,   462,   212,    82,   219,   220,   222,     4,
      95,   272,   225,   226,   227,   330,   175,   232,   233,    46,
     237,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   273,   398,    64,    65,    66,    67,    68,    69,
     336,   567,     5,   272,    43,    24,    29,   517,    70,    71,
     355,   633,     7,   425,    53,   278,    72,    73,   199,   273,
     324,    48,   110,   365,    74,   210,   430,   458,   459,    25,
      25,    49,   231,   273,    75,   300,   315,   301,   282,   257,
      56,    76,     7,   173,   380,   306,     7,   126,   127,   210,
      45,   119,   172,   143,    77,    78,    79,   290,     6,   191,
      50,   240,   317,   318,  -148,   273,   395,   176,     7,   401,
     311,     8,   113,    55,   525,    80,    81,   527,   528,   574,
     197,   531,   339,   223,   404,    51,   211,   293,    82,   193,
     194,  -149,   340,   546,   329,   450,   405,   550,    57,   432,
     123,    83,   552,   618,   341,   619,     9,   274,   275,   331,
      96,   102,    88,    89,    90,    91,    92,  -130,   102,  -132,
     241,    97,   565,   177,   366,   367,  -131,   170,   350,    58,
     370,   281,   -64,   494,    59,   588,   -96,   590,   178,    98,
     402,   594,   342,   596,    60,   188,   381,   108,   291,   111,
     294,   190,    57,   175,   109,   391,   260,   179,   -96,   114,
     112,   558,   396,    61,   287,   288,   114,    64,    65,    66,
      67,    68,    69,   119,   414,   415,   357,   431,   312,   358,
     417,    70,    71,    58,   351,   352,   424,   180,    99,    72,
     116,   323,    84,    85,    86,   409,   429,    87,   410,   433,
     160,   161,   162,   163,   164,   361,   362,    75,   364,   120,
     214,   181,   639,   640,    76,   641,   121,   100,    64,    65,
      66,    67,    68,    69,   452,   420,   421,    77,    78,    79,
     122,   634,    70,    71,   124,    88,    89,    90,    91,    92,
      72,   627,   628,   629,   630,    64,    65,    66,    67,    68,
      69,   332,   333,   234,   642,   235,   236,   504,    75,    70,
      71,    82,   125,   414,   516,    76,   379,    72,   221,   128,
     382,   383,   384,   136,   426,   522,   523,   427,    77,    78,
      79,   501,   389,   390,   502,    75,    64,    65,    66,    67,
      68,    69,    76,   137,    32,   215,   412,    37,   138,   409,
      70,    71,   526,   520,   521,    77,    78,    79,    72,   139,
     581,   582,    82,   585,   586,   587,   357,   140,   589,   529,
     591,   556,   593,   141,   595,   557,    75,   560,   562,   357,
     424,   568,   530,    76,   569,   568,   184,   568,   570,    82,
     571,   357,   357,   186,   573,   575,    77,    78,    79,   357,
     187,   192,   576,    64,    65,    66,    67,    68,    69,   157,
     158,   159,   160,   161,   162,   163,   164,    70,    71,   357,
     501,   614,   577,   608,   615,    72,   620,   201,   620,   621,
      82,   622,   216,    64,    65,    66,    67,    68,    69,   357,
       7,   253,   645,    75,   228,   268,   254,    70,    71,   613,
      76,   259,   261,   271,   269,    72,   279,   285,    88,    89,
      90,    91,    92,    77,    78,    79,   158,   159,   160,   161,
     162,   163,   164,    75,   296,   284,   302,   164,   416,   304,
      76,   534,   535,   305,   536,   309,   316,   537,   538,   325,
     540,   541,   542,    77,    78,    79,   545,    82,   547,   320,
     549,   133,   321,   322,   326,   551,   327,   334,   422,    88,
      89,    90,    91,    92,   335,   337,   338,   347,   348,   353,
       7,   359,   354,   372,   375,   387,   377,    82,    64,    65,
      66,    67,    68,    69,   392,   378,    88,    89,    90,    91,
      92,   385,    70,    71,    64,    65,    66,    67,    68,    69,
      72,   393,   406,   407,   408,   411,   418,   419,    70,    71,
     434,   435,   436,   444,   437,   439,    72,   440,    75,   441,
     442,   448,   443,   445,   446,    76,   447,    88,    89,    90,
      91,    92,   453,   456,    75,   499,   457,   460,    77,    78,
      79,    76,   494,    64,    65,    66,    67,    68,    69,   500,
     505,   503,   518,   559,    77,    78,    79,    70,    71,   524,
     543,   532,   572,   578,   539,    72,   548,   583,   553,   561,
     554,   597,    82,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    75,   598,   355,   609,   610,    82,   612,
      76,   625,   623,   626,    88,    89,    90,    91,    92,   624,
     631,   635,   636,    77,    78,    79,   148,   149,   150,   151,
     152,   637,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    88,    89,    90,    91,    92,   145,
     146,   147,   148,   149,   150,   151,   152,    82,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     145,   146,   147,   148,   149,   150,   151,   152,   638,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   145,   146,   147,   148,   149,   150,   151,   152,   357,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   145,   146,   147,   148,   149,   150,   151,   152,
     643,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   644,   515,    41,   607,   224,   263,    88,
      89,    90,    91,    92,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    88,    89,    90,    91,    92,
     145,   146,   147,   148,   149,   150,   151,   152,   346,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,  -150,  -150,  -150,  -150,   152,   303,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   386,
     454,   117,   283,    63,    88,    89,    90,    91,    92,   145,
     146,   147,   148,   149,   150,   151,   152,   200,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     145,   146,   147,   148,   149,   150,   151,   152,   363,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,     1,   145,   146,   147,   148,   149,   150,   151,   152,
     563,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   599,   455,   145,   146,   147,   148,   149,   150,
     151,   152,   310,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   600,   461,    30,   169,   592,
     374,     2,   207,   564,   506,   507,   508,   509,     0,     0,
       0,   601,     0,     0,     0,     0,     0,     0,     0,     0,
       3,   295,     0,     0,     0,     0,     0,     0,     4,     0,
       0,     0,     0,   602,     0,     0,     0,     0,     0,     0,
       0,     0,   295,   510,   511,   512,     0,     0,     0,     0,
       0,     0,     0,   145,   146,   147,   148,   149,   150,   151,
     152,     5,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   603,   147,   148,   149,   150,   151,   152,
     307,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,     0,     0,     0,     0,     0,     0,   604,
       0,     0,     0,     0,     0,     0,     0,     6,     0,     0,
       0,   605,     0,     0,     0,     0,     0,     7,     0,     0,
       8,   145,   146,   147,   148,   149,   150,   151,   152,   308,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   463,   464,   465,   466,     0,     0,     0,     0,
     498,     0,   467,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     0,   513,   514,     0,     0,   606,     0,     0,
     468,   469,     0,     0,     0,     0,   470,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   471,     0,     0,
     133,     0,     0,     0,     0,   472,     0,     0,     0,     0,
       0,   473,   146,   147,   148,   149,   150,   151,   152,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   474,   475,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,     0,     0,     0,     0,
       0,   476,   477,     0,   297,     0,   478,   479,   480,   145,
     146,   147,   148,   149,   150,   151,   152,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
       0,     0,   481,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     482,     0,   483,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   484,
       0,     0,   485,   486,   487,   488,   489,     0,     0,     0,
       0,     0,   369,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   490,   491,     0,     0,     0,     0,     0,
       0,   492,     0,     0,   371,   145,   146,   147,   148,   149,
     150,   151,   152,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   145,   146,   147,   148,
     149,   150,   151,   152,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   145,   146,   147,
     148,   149,   150,   151,   152,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,     0,     0,
       0,     0,     0,     0,   144,     0,   495,     0,     0,     0,
       0,   145,   146,   147,   148,   149,   150,   151,   152,   368,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,     0,     0,     0,     0,     0,     0,     0,   165,
     428,     0,     0,     0,     0,     0,     0,     0,   496,   145,
     146,   147,   148,   149,   150,   151,   152,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
       0,     0,     0,     0,     0,   319,   145,   146,   147,   148,
     149,   150,   151,   152,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164
};

static const yytype_int16 yycheck[] =
{
      33,   199,     3,    20,    20,   137,   138,   101,     3,     3,
       3,     3,     4,     5,     6,     7,     8,     3,   394,     3,
      91,     0,     1,    94,     6,    17,    18,   128,     6,    68,
      68,   338,   249,    25,     3,    17,   190,    70,    71,    72,
     331,    33,    75,    76,    91,    37,   105,    94,   105,   224,
     133,    43,   237,   181,    38,   103,   190,   157,    50,     3,
     157,   156,   249,    96,    97,   250,     8,   115,   243,    38,
     115,    63,    64,    65,    10,    11,    12,    13,    14,    15,
      16,    17,    61,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   128,   228,   115,   252,   182,
     133,    80,   237,   410,   137,    97,   139,   140,   141,    88,
     143,   115,   145,   146,   147,   250,   250,   150,   151,   207,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   177,   228,     3,     4,     5,     6,     7,     8,
     268,   517,   121,   115,   114,   184,   184,   438,    17,    18,
     250,   252,   187,   250,   114,   188,    25,    26,   190,   177,
     254,   105,    97,   295,    33,   236,   102,   406,   407,   208,
     208,   115,   154,   177,    43,   208,   154,   210,   191,   227,
     207,    50,   187,   102,   316,   218,   187,   251,   252,   236,
      24,   250,   102,   250,    63,    64,    65,   232,   177,   118,
     144,   193,   235,   236,   249,   177,   334,    62,   187,   337,
     223,   190,    46,    29,   453,    84,    85,   456,   457,   526,
     252,   460,   106,   142,   116,   169,   136,   232,    97,     3,
       4,   249,   116,   480,   251,   251,   128,   484,    79,   371,
      56,   110,   489,    52,   128,    54,   225,   251,   252,   262,
       9,   252,   244,   245,   246,   247,   248,   252,   252,   252,
     252,    20,   239,   118,   297,   298,   252,   251,   281,   110,
     303,   190,   127,   250,   115,   544,   228,   546,   133,   250,
     252,   550,   166,   552,   125,   237,   319,   249,   198,     3,
     200,   228,    79,   250,   249,   328,   253,   152,   250,   251,
       3,   499,   335,   144,     3,     4,   251,     3,     4,     5,
       6,     7,     8,   250,   347,   348,   250,   253,   228,   253,
     353,    17,    18,   110,     3,     4,   359,   182,   115,    25,
       3,   241,   201,   202,   203,   250,   369,   206,   253,   372,
      26,    27,    28,    29,    30,   291,   292,    43,   294,    97,
      46,   206,   621,   622,    50,   624,     3,   144,     3,     4,
       5,     6,     7,     8,   397,     3,     4,    63,    64,    65,
       3,   610,    17,    18,     3,   244,   245,   246,   247,   248,
      25,     4,     5,     6,     7,     3,     4,     5,     6,     7,
       8,   264,   265,    13,   633,    15,    16,   430,    43,    17,
      18,    97,     3,   436,   437,    50,   316,    25,    26,     9,
     320,   321,   322,   252,   360,   448,   449,   363,    63,    64,
      65,   250,   326,   327,   253,    43,     3,     4,     5,     6,
       7,     8,    50,   252,     6,   131,   346,     9,   252,   250,
      17,    18,   253,   446,   447,    63,    64,    65,    25,   252,
     537,   538,    97,   540,   541,   542,   250,   252,   545,   253,
     547,   494,   549,   252,   551,   498,    43,   500,   501,   250,
     503,   250,   253,    50,   253,   250,    38,   250,   253,    97,
     253,   250,   250,     3,   253,   253,    63,    64,    65,   250,
      26,     3,   253,     3,     4,     5,     6,     7,     8,    23,
      24,    25,    26,    27,    28,    29,    30,    17,    18,   250,
     250,   250,   253,   253,   253,    25,   250,     3,   250,   253,
      97,   253,   218,     3,     4,     5,     6,     7,     8,   250,
     187,     3,   253,    43,   252,   127,     3,    17,    18,   572,
      50,   253,     3,     3,   163,    25,   161,     3,   244,   245,
     246,   247,   248,    63,    64,    65,    24,    25,    26,    27,
      28,    29,    30,    43,   253,   250,   253,    30,    78,   253,
      50,   464,   465,   253,   467,   253,   252,   470,   471,   128,
     473,   474,   475,    63,    64,    65,   479,    97,   481,   252,
     483,   236,   252,   252,   128,   488,   128,   127,    78,   244,
     245,   246,   247,   248,   156,   127,     3,    47,   134,    20,
     187,   252,   157,   124,   108,   102,   253,    97,     3,     4,
       5,     6,     7,     8,     3,   253,   244,   245,   246,   247,
     248,   253,    17,    18,     3,     4,     5,     6,     7,     8,
      25,     3,   252,   252,   128,     3,   128,     3,    17,    18,
     253,   253,    47,   127,   109,   253,    25,   253,    43,   253,
     253,    20,   253,   252,   252,    50,   252,   244,   245,   246,
     247,   248,   252,   252,    43,   225,   252,   252,    63,    64,
      65,    50,   250,     3,     4,     5,     6,     7,     8,    20,
     253,   252,     3,    78,    63,    64,    65,    17,    18,     3,
      43,   252,    20,     5,   252,    25,   252,     4,   252,    78,
     252,     5,    97,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    43,     5,   250,   183,   125,    97,     3,
      50,   154,   253,     4,   244,   245,   246,   247,   248,   253,
     128,     5,   190,    63,    64,    65,    13,    14,    15,    16,
      17,     4,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,   244,   245,   246,   247,   248,    10,
      11,    12,    13,    14,    15,    16,    17,    97,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      10,    11,    12,    13,    14,    15,    16,    17,     4,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    10,    11,    12,    13,    14,    15,    16,    17,   250,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    10,    11,    12,    13,    14,    15,    16,    17,
     253,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     4,   436,    10,   556,   143,   175,   244,
     245,   246,   247,   248,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   244,   245,   246,   247,   248,
      10,    11,    12,    13,    14,    15,    16,    17,   277,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    13,    14,    15,    16,    17,   105,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,   324,
     401,    48,   192,    32,   244,   245,   246,   247,   248,    10,
      11,    12,    13,    14,    15,    16,    17,   125,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      10,    11,    12,    13,    14,    15,    16,    17,   293,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     1,    10,    11,    12,    13,    14,    15,    16,    17,
     503,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    17,   402,    10,    11,    12,    13,    14,    15,
      16,    17,   253,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    40,   409,     4,    98,   548,
     308,    61,   134,   253,    72,    73,    74,    75,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,   250,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   250,   111,   112,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,   121,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,    12,    13,    14,    15,    16,    17,
     250,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,   154,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,   166,    -1,    -1,    -1,    -1,    -1,   187,    -1,    -1,
     190,    10,    11,    12,    13,    14,    15,    16,    17,   250,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
     250,    -1,    52,    -1,    -1,   225,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   241,   242,    -1,    -1,   222,    -1,    -1,
      70,    71,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,
     236,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,   101,    11,    12,    13,    14,    15,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,   122,   123,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,   141,   142,    -1,   211,    -1,   146,   147,   148,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,
      -1,    -1,   212,   213,   214,   215,   216,    -1,    -1,    -1,
      -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   233,   234,    -1,    -1,    -1,    -1,    -1,
      -1,   241,    -1,    -1,   105,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    39,    -1,    -1,    -1,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    94,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    36,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    61,    80,    88,   121,   177,   187,   190,   225,
     255,   256,   257,   287,   291,   299,   300,   303,   305,   307,
     321,   323,   249,    68,   184,   208,   320,   288,    68,   184,
     320,   293,   293,   268,     8,   324,   325,   293,   301,     0,
       1,   256,   249,   114,   304,   304,   207,     3,   105,   115,
     144,   169,   289,   114,   306,   306,   207,    79,   110,   115,
     125,   144,   294,   294,     3,     4,     5,     6,     7,     8,
      17,    18,    25,    26,    33,    43,    50,    63,    64,    65,
      84,    85,    97,   110,   201,   202,   203,   206,   244,   245,
     246,   247,   248,   269,   270,   326,     9,    20,   250,   115,
     144,     3,   252,   271,   272,   273,   276,   286,   249,   249,
      97,     3,     3,   304,   251,   290,     3,   289,   105,   250,
      97,     3,     3,   306,     3,     3,   251,   252,     9,   326,
     326,   326,   326,   236,   326,   331,   252,   252,   252,   252,
     252,   252,   105,   250,     3,    10,    11,    12,    13,    14,
      15,    16,    17,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    38,   275,   326,   326,   325,
     251,   275,   257,   271,   190,   250,    62,   118,   133,   152,
     182,   206,   277,   279,    38,   274,     3,    26,   237,   258,
     228,   271,     3,     3,     4,   322,   190,   252,   295,   190,
     295,     3,   326,   327,   328,   326,   326,   331,    91,    94,
     236,   257,   326,   327,    46,   131,   218,   327,   329,   326,
     326,    26,   326,   271,   270,   326,   326,   326,   252,     6,
      17,   154,   326,   326,    13,    15,    16,   326,    33,    37,
     193,   252,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,     3,     3,   103,   115,   227,   283,   253,
     253,     3,   302,   272,   133,   182,   280,   273,   127,   163,
     278,     3,   115,   177,   251,   252,   318,   319,   326,   161,
     264,   271,   258,   290,   250,     3,   298,     3,     4,   267,
     232,   257,   298,   232,   257,   250,   253,   211,    91,    94,
     326,   326,   253,   105,   253,   253,   326,   250,   250,   253,
     253,   258,   257,   327,     6,   154,   252,   326,   326,    36,
     252,   252,   252,   257,   275,   128,   128,   128,    20,   251,
     250,   258,   278,   278,   127,   156,   273,   127,     3,   106,
     116,   128,   166,   308,   309,   310,   274,    47,   134,   265,
     258,     3,     4,    20,   157,   250,   292,   250,   253,   252,
     296,   292,   292,   296,   292,   327,   326,   326,    94,   211,
     326,   105,   124,   330,   330,   108,   259,   253,   253,   257,
     327,   326,   257,   257,   257,   253,   283,   102,   284,   284,
     284,   326,     3,     3,   264,   273,   326,   156,   228,   281,
     282,   273,   252,   318,   116,   128,   252,   252,   128,   250,
     253,     3,   257,   260,   326,   326,    78,   326,   128,     3,
       3,     4,    78,   297,   326,   250,   292,   292,    94,   326,
     102,   253,   327,   326,   253,   253,    47,   109,   263,   253,
     253,   253,   253,   253,   127,   252,   252,   252,    20,    20,
     251,   265,   326,   252,   282,   308,   252,   252,   267,   267,
     252,   309,   318,    42,    43,    44,    45,    52,    70,    71,
      76,    87,    95,   101,   122,   123,   141,   142,   146,   147,
     148,   172,   190,   192,   209,   212,   213,   214,   215,   216,
     233,   234,   241,   316,   250,    39,    81,   261,   250,   225,
      20,   250,   253,   252,   326,   253,    72,    73,    74,    75,
     111,   112,   113,   241,   242,   260,   326,   264,     3,   285,
     285,   285,   326,   326,     3,   267,   253,   267,   267,   253,
     253,   267,   252,   312,   312,   312,   312,   312,   312,   252,
     312,   312,   312,    43,   313,   312,   313,   312,   252,   312,
     313,   312,   313,   252,   252,   311,   326,   326,   298,    78,
     326,    78,   326,   297,   253,   239,   262,   265,   250,   253,
     253,   253,    20,   253,   318,   253,   253,   253,     5,   314,
     315,   314,   314,     4,   317,   314,   314,   314,   315,   314,
     315,   314,   317,   314,   315,   314,   315,     5,     5,    17,
      40,    56,    78,   128,   154,   166,   222,   261,   253,   183,
     125,   266,     3,   326,   250,   253,   224,   243,    52,    54,
     250,   253,   253,   253,   253,   154,     4,     4,     5,     6,
       7,   128,   128,   252,   267,     5,   190,     4,     4,   315,
     315,   315,   267,   253,     4,   253
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   254,   255,   255,   255,   255,   256,   257,   257,   258,
     258,   259,   259,   260,   260,   261,   261,   261,   262,   262,
     263,   263,   264,   264,   265,   265,   265,   266,   266,   267,
     267,   267,   267,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   269,   269,   269,   270,   271,   271,   272,   272,
     273,   273,   273,   273,   274,   274,   275,   275,   275,   276,
     276,   276,   276,   276,   277,   277,   277,   278,   278,   279,
     279,   280,   280,   280,   281,   281,   282,   282,   283,   283,
     283,   283,   284,   284,   285,   285,   286,   256,   287,   288,
     288,   288,   288,   287,   289,   289,   290,   290,   287,   256,
     291,   292,   292,   293,   293,   293,   293,   293,   294,   294,
     295,   295,   296,   296,   297,   297,   297,   297,   291,   291,
     298,   298,   298,   298,   256,   299,   299,   299,   256,   300,
     301,   301,   301,   302,   302,   302,   302,   256,   303,   303,
     304,   304,   256,   305,   305,   306,   306,   256,   307,   307,
     307,   307,   307,   307,   308,   308,   310,   309,   309,   309,
     309,   309,   309,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   312,   312,   312,   313,
     313,   314,   314,   314,   315,   315,   315,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   317,   317,   318,
     319,   319,   319,   320,   320,   256,   321,   322,   322,   322,
     322,   256,   323,   324,   324,   325,   325,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   327,   327,   328,   328,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   329,   329,
     329,   326,   326,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   326,   326,   326,   326,   331,   331,   326,   326,
     326,   326,   326,   326,   326,   326
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     2,     3,     1,     3,    11,     0,
       2,     0,     4,     2,     4,     0,     1,     1,     0,     2,
       0,     2,     0,     3,     0,     2,     4,     0,     2,     1,
       1,     3,     3,     0,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     3,     1,     2,     1,     3,     1,     1,
       3,     5,     3,     3,     1,     0,     2,     1,     0,     5,
       3,     5,     6,     5,     0,     1,     1,     0,     1,     1,
       1,     2,     2,     0,     1,     0,     2,     4,     6,     6,
       6,     0,     2,     0,     1,     3,     3,     1,     7,     2,
       2,     2,     0,     6,     2,     4,     0,     2,     7,     1,
       8,     0,     4,     0,     2,     2,     2,     2,     1,     0,
       0,     3,     3,     5,     1,     1,     3,     3,     7,     7,
       3,     3,     5,     5,     1,     8,     7,     7,     1,     8,
       0,     2,     2,     3,     5,     5,     7,     1,     4,     4,
       0,     2,     1,     4,     4,     0,     2,     1,     8,    10,
       9,     6,    11,     8,     1,     3,     0,     4,     5,     4,
       4,     5,     5,     0,     3,     2,     3,     3,     3,     3,
       2,     5,     3,     3,     2,     3,     0,     3,     5,     0,
       1,     0,     2,     2,     0,     4,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     3,     5,     2,     4,     1,     1,     1,
       1,     3,     3,     3,     3,     5,     5,     1,     3,     3,
       0,     1,     1,     0,     1,     1,     5,     1,     1,     3,
       3,     1,     2,     1,     3,     3,     3,     1,     1,     3,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     5,     6,     6,     6,     3,
       3,     3,     3,     2,     2,     3,     3,     4,     3,     4,
       5,     1,     3,     0,     1,     5,     6,     5,     6,     4,
       4,     4,     4,     4,     6,     8,     4,     7,     1,     1,
       1,     6,     6,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     6,     3,     5,     4,     5,     3,     4,
       3,     4,     1,     1,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (&yylloc, scanner, pstate, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, scanner, pstate); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, struct psql_state *pstate)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (pstate);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, struct psql_state *pstate)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, scanner, pstate);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, yyscan_t scanner, struct psql_state *pstate)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , scanner, pstate);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, scanner, pstate); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yyscan_t scanner, struct psql_state *pstate)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (pstate);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 3: /* NAME  */
#line 363 "src/sql.yy" /* yacc.c:1257  */
      { printf ("free at %d %s\n",(*yylocationp).first_line, ((*yyvaluep).strval)); free(((*yyvaluep).strval)); }
#line 2042 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1257  */
        break;

    case 4: /* STRING  */
#line 363 "src/sql.yy" /* yacc.c:1257  */
      { printf ("free at %d %s\n",(*yylocationp).first_line, ((*yyvaluep).strval)); free(((*yyvaluep).strval)); }
#line 2048 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1257  */
        break;

    case 8: /* USERVAR  */
#line 363 "src/sql.yy" /* yacc.c:1257  */
      { printf ("free at %d %s\n",(*yylocationp).first_line, ((*yyvaluep).strval)); free(((*yyvaluep).strval)); }
#line 2054 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t scanner, struct psql_state *pstate)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
#line 376 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_stmt(pstate); }
#line 2348 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 380 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_select_nodata(pstate, (yyvsp[-1].intval), (yyvsp[0].intval)); }
#line 2354 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 384 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_select(pstate, (yyvsp[-9].intval), (yyvsp[-8].intval), (yyvsp[-6].intval)); }
#line 2360 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 388 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_where(pstate); }
#line 2366 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 392 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_group_by_list(pstate, (yyvsp[-1].intval), (yyvsp[0].intval)); }
#line 2372 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 396 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_group_by(pstate, (yyvsp[0].intval)); (yyval.intval) = 1; }
#line 2378 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 398 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_group_by(pstate, (yyvsp[0].intval)); (yyval.intval) = (yyvsp[-3].intval) + 1; }
#line 2384 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 401 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2390 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 402 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2396 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 403 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2402 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 406 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2408 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 407 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2414 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 410 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_having(pstate); }
#line 2420 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 412 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_order_by(pstate, (yyvsp[0].intval)); }
#line 2426 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 415 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_limit(pstate, 0); }
#line 2432 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 416 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_limit(pstate, 1); }
#line 2438 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 420 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_into(pstate, (yyvsp[0].intval)); }
#line 2444 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 423 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_column(pstate, (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = 1; }
#line 2450 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 424 "src/sql.yy" /* yacc.c:1646  */
    { lyyerror((yylsp[0]), "string %s found where name required", (yyvsp[0].strval));
                              sqlp_column(pstate, (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = 1; }
#line 2457 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 426 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_column(pstate, (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 2463 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 427 "src/sql.yy" /* yacc.c:1646  */
    { lyyerror((yylsp[0]), "string %s found where name required", (yyvsp[-2].intval));
                            sqlp_column(pstate, (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 2470 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 431 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2476 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 432 "src/sql.yy" /* yacc.c:1646  */
    { if((yyval.intval) & 01) lyyerror((yylsp[0]),"duplicate ALL option"); (yyval.intval) = (yyvsp[-1].intval) | 01; }
#line 2482 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 433 "src/sql.yy" /* yacc.c:1646  */
    { if((yyval.intval) & 02) lyyerror((yylsp[0]),"duplicate DISTINCT option"); (yyval.intval) = (yyvsp[-1].intval) | 02; }
#line 2488 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 434 "src/sql.yy" /* yacc.c:1646  */
    { if((yyval.intval) & 04) lyyerror((yylsp[0]),"duplicate DISTINCTROW option"); (yyval.intval) = (yyvsp[-1].intval) | 04; }
#line 2494 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 435 "src/sql.yy" /* yacc.c:1646  */
    { if((yyval.intval) & 010) lyyerror((yylsp[0]),"duplicate HIGH_PRIORITY option"); (yyval.intval) = (yyvsp[-1].intval) | 010; }
#line 2500 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 436 "src/sql.yy" /* yacc.c:1646  */
    { if((yyval.intval) & 020) lyyerror((yylsp[0]),"duplicate STRAIGHT_JOIN option"); (yyval.intval) = (yyvsp[-1].intval) | 020; }
#line 2506 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 437 "src/sql.yy" /* yacc.c:1646  */
    { if((yyval.intval) & 040) lyyerror((yylsp[0]),"duplicate SQL_SMALL_RESULT option"); (yyval.intval) = (yyvsp[-1].intval) | 040; }
#line 2512 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 438 "src/sql.yy" /* yacc.c:1646  */
    { if((yyval.intval) & 0100) lyyerror((yylsp[0]),"duplicate SQL_BIG_RESULT option"); (yyval.intval) = (yyvsp[-1].intval) | 0100; }
#line 2518 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 439 "src/sql.yy" /* yacc.c:1646  */
    { if((yyval.intval) & 0200) lyyerror((yylsp[0]),"duplicate SQL_CALC_FOUND_ROWS option"); (yyval.intval) = (yyvsp[-1].intval) | 0200; }
#line 2524 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 442 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2530 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 443 "src/sql.yy" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 2536 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 444 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_select_all(pstate); (yyval.intval) = 1; }
#line 2542 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 449 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2548 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 450 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 2554 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 458 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_table(pstate, NULL, (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 2560 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 459 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_table(pstate, (yyvsp[-4].strval), (yyvsp[-2].strval));
                               free((yyvsp[-4].strval)); free((yyvsp[-2].strval)); }
#line 2567 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 461 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_subquery_as(pstate, (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2573 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 462 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_table_refs(pstate, (yyvsp[-1].intval)); }
#line 2579 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 469 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_alias(pstate, (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2585 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 470 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_alias(pstate, (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 2591 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 476 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_join(pstate, 0100+(yyvsp[-3].intval)); }
#line 2597 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 478 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_join(pstate, 0200); }
#line 2603 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 480 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_join(pstate, 0200); }
#line 2609 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 482 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_join(pstate, 0300+(yyvsp[-4].intval)+(yyvsp[-3].intval)); }
#line 2615 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 484 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_join(pstate, 0400+(yyvsp[-2].intval)); }
#line 2621 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 487 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2627 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 488 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2633 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 489 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 2; }
#line 2639 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 492 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2645 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 493 "src/sql.yy" /* yacc.c:1646  */
    {(yyval.intval) = 4; }
#line 2651 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 496 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2657 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 497 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 2; }
#line 2663 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 500 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 1 + (yyvsp[0].intval); }
#line 2669 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 501 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 2 + (yyvsp[0].intval); }
#line 2675 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 502 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2681 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 508 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_join_expr(pstate); }
#line 2687 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 509 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_join_using(pstate, (yyvsp[-1].intval)); }
#line 2693 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 514 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_index_hint(pstate, (yyvsp[-1].intval), 010+(yyvsp[-3].intval)); }
#line 2699 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 516 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_index_hint(pstate, (yyvsp[-1].intval), 020+(yyvsp[-3].intval)); }
#line 2705 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 518 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_index_hint(pstate, (yyvsp[-1].intval), 030+(yyvsp[-3].intval)); }
#line 2711 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 522 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2717 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 523 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2723 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 526 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_index(pstate, (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = 1; }
#line 2729 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 527 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_index(pstate, (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 2735 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 530 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_subquery(pstate); }
#line 2741 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 535 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_stmt(pstate); }
#line 2747 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 540 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_delete(pstate, (yyvsp[-5].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 2753 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 543 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) + 01; }
#line 2759 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 544 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) + 02; }
#line 2765 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 545 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) + 04; }
#line 2771 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 546 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2777 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 552 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_delete_multi(pstate, (yyvsp[-4].intval), (yyvsp[-3].intval), (yyvsp[-1].intval)); }
#line 2783 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 554 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_table(pstate, NULL, (yyvsp[-1].strval)); free((yyvsp[-1].strval)); (yyval.intval) = 1; }
#line 2789 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 556 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_table(pstate, NULL, (yyvsp[-1].strval)); free((yyvsp[-1].strval)); (yyval.intval) = (yyvsp[-3].intval) + 1; }
#line 2795 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 564 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_delete_multi(pstate, (yyvsp[-5].intval), (yyvsp[-3].intval), (yyvsp[-1].intval)); }
#line 2801 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 569 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_stmt(pstate); }
#line 2807 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 575 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_insert(pstate, (yyvsp[-6].intval), (yyvsp[-1].intval), (yyvsp[-4].strval)); free((yyvsp[-4].strval)); }
#line 2813 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 579 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_ins_dup_update(pstate, (yyvsp[0].intval)); }
#line 2819 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 582 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2825 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 583 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 01 ; }
#line 2831 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 584 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 02 ; }
#line 2837 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 585 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 04 ; }
#line 2843 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 586 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 010 ; }
#line 2849 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 593 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_ins_cols(pstate, (yyvsp[-1].intval)); }
#line 2855 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 596 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_values(pstate, (yyvsp[-1].intval)); (yyval.intval) = 1; }
#line 2861 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 597 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_values(pstate, (yyvsp[-1].intval)); (yyval.intval) = (yyvsp[-4].intval) + 1; }
#line 2867 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 600 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 2873 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 601 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_ins_default(pstate); (yyval.intval) = 1; }
#line 2879 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 602 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 2885 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 603 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_ins_default(pstate); (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 2891 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 609 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_insert_assn(pstate, (yyvsp[-5].intval), (yyvsp[-1].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 2897 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 614 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_insert_sel(pstate, (yyvsp[-5].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 2903 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 619 "src/sql.yy" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) { lyyerror((yylsp[-1]),"bad insert assignment to %s", (yyvsp[-2].strval)); YYERROR; }
       sqlp_assign(pstate, NULL, (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 2910 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 622 "src/sql.yy" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) { lyyerror((yylsp[-1]),"bad insert assignment to %s", (yyvsp[-2].strval)); YYERROR; }
                 sqlp_ins_default(pstate); sqlp_assign(pstate, NULL, (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 2917 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 625 "src/sql.yy" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) { lyyerror((yylsp[-1]),"bad insert assignment to %s", (yyvsp[-4].intval)); YYERROR; }
                 sqlp_assign(pstate, NULL, (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = (yyvsp[-4].intval) + 1; }
#line 2924 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 628 "src/sql.yy" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) { lyyerror((yylsp[-1]),"bad insert assignment to %s", (yyvsp[-4].intval)); YYERROR; }
                 sqlp_ins_default(pstate); sqlp_assign(pstate, NULL, (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = (yyvsp[-4].intval) + 1; }
#line 2931 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 633 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_stmt(pstate); }
#line 2937 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 639 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_replace_vals(pstate, (yyvsp[-6].intval), (yyvsp[-1].intval), (yyvsp[-4].strval)); free((yyvsp[-4].strval)); }
#line 2943 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 645 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_replace_assn(pstate, (yyvsp[-5].intval), (yyvsp[-1].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 2949 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 650 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_replace_sel(pstate, (yyvsp[-5].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 2955 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 654 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_stmt(pstate); }
#line 2961 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 661 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_update(pstate, (yyvsp[-6].intval), (yyvsp[-5].intval), (yyvsp[-3].intval)); }
#line 2967 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 664 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 2973 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 665 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 01 ; }
#line 2979 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 666 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 010 ; }
#line 2985 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 671 "src/sql.yy" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) { lyyerror((yylsp[-1]),"bad update assignment to %s", (yyvsp[-2].strval)); YYERROR; }
	 sqlp_assign(pstate, NULL, (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 2992 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 674 "src/sql.yy" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) { lyyerror((yylsp[-1]),"bad update assignment to %s", (yyvsp[-4].strval)); YYERROR; }
	 sqlp_assign(pstate, (yyvsp[-4].strval), (yyvsp[-2].strval)); free((yyvsp[-4].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 2999 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 677 "src/sql.yy" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) { lyyerror((yylsp[-1]),"bad update assignment to %s", (yyvsp[-2].strval)); YYERROR; }
	 sqlp_assign(pstate, NULL, (yyvsp[-2].strval)); free((yyvsp[-2].strval)); (yyval.intval) = (yyvsp[-4].intval) + 1; }
#line 3006 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 680 "src/sql.yy" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) { lyyerror((yylsp[-1]),"bad update  assignment to %s.$s", (yyvsp[-4].strval), (yyvsp[-2].strval)); YYERROR; }
	 sqlp_assign(pstate, (yyvsp[-4].strval), (yyvsp[-2].strval)); free((yyvsp[-4].strval)); free((yyvsp[-2].strval)); (yyval.intval) = 1; }
#line 3013 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 687 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_stmt(pstate); }
#line 3019 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 691 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_create_db(pstate, (yyvsp[-1].intval), (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3025 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 692 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_create_db(pstate, (yyvsp[-1].intval), (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3031 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 695 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3037 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 696 "src/sql.yy" /* yacc.c:1646  */
    { if(!(yyvsp[0].subtok)) { lyyerror((yylsp[0]),"IF EXISTS doesn't exist"); YYERROR; }
                        (yyval.intval) = (yyvsp[0].subtok); /* NOT EXISTS hack */ }
#line 3044 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 702 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_stmt(pstate); }
#line 3050 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 706 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_drop_db(pstate, (yyvsp[-1].intval), (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3056 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 707 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_drop_db(pstate, (yyvsp[-1].intval), (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3062 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 710 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3068 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 711 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 3074 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 716 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_stmt(pstate); }
#line 3080 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 720 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_create_tbl(pstate, (yyvsp[-6].intval), (yyvsp[-4].intval), (yyvsp[-1].intval), NULL, (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 3086 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 724 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_create_tbl(pstate, (yyvsp[-8].intval), (yyvsp[-6].intval), (yyvsp[-1].intval), (yyvsp[-5].strval), (yyvsp[-3].strval));
                          free((yyvsp[-5].strval)); free((yyvsp[-3].strval)); }
#line 3093 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 730 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_create_tbl_sel(pstate, (yyvsp[-7].intval), (yyvsp[-5].intval), (yyvsp[-2].intval), NULL, (yyvsp[-4].strval)); free((yyvsp[-4].strval)); }
#line 3099 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 734 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_create_tbl_sel(pstate, (yyvsp[-4].intval), (yyvsp[-2].intval), 0, NULL, (yyvsp[-1].strval)); free((yyvsp[-1].strval)); }
#line 3105 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 739 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_create_tbl_sel(pstate, (yyvsp[-9].intval), (yyvsp[-7].intval), 0, (yyvsp[-6].strval), (yyvsp[-4].strval));
                              free((yyvsp[-6].strval)); free((yyvsp[-4].strval)); }
#line 3112 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 744 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_create_tbl_sel(pstate, (yyvsp[-6].intval), (yyvsp[-4].intval), 0, (yyvsp[-3].strval), (yyvsp[-1].strval));
                          free((yyvsp[-3].strval)); free((yyvsp[-1].strval)); }
#line 3119 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 748 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 3125 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 749 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 3131 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 752 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_start_col(pstate); }
#line 3137 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 753 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_def_col(pstate, (yyvsp[-1].intval), (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 3143 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 755 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_col_key_pri(pstate, (yyvsp[-1].intval)); }
#line 3149 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 756 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_col_key(pstate, (yyvsp[-1].intval)); }
#line 3155 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 757 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_col_key(pstate, (yyvsp[-1].intval)); }
#line 3161 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 758 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_col_key_textidx(pstate, (yyvsp[-1].intval)); }
#line 3167 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 759 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_col_key_textidx(pstate, (yyvsp[-1].intval)); }
#line 3173 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 762 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3179 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 763 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_col_attr(pstate, SCA_NOTNULL); (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 3185 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 765 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_col_def_str(pstate, (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 3191 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 766 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_col_def_num(pstate, (yyvsp[0].intval)); (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 3197 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 767 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_col_def_float(pstate, (yyvsp[0].floatval)); (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 3203 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 768 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_col_def_bool(pstate, (yyvsp[0].intval)); (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 3209 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 769 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_col_attr(pstate, SCA_AUTOINC); (yyval.intval) = (yyvsp[-1].intval) + 1; }
#line 3215 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 770 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_col_attr_uniq(pstate, (yyvsp[-1].intval)); (yyval.intval) = (yyvsp[-4].intval) + 1; }
#line 3221 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 771 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_col_attr_uniq(pstate, 0); (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 3227 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 772 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_col_attr(pstate, SCA_PRIMARY_KEY); (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 3233 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 773 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_col_attr(pstate, SCA_PRIMARY_KEY); (yyval.intval) = (yyvsp[-1].intval) + 1; }
#line 3239 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 774 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_col_attr_comm(pstate, (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 3245 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 777 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3251 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 778 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval); }
#line 3257 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 779 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-3].intval) + 1000*(yyvsp[-1].intval); }
#line 3263 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 782 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3269 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 783 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 4000; }
#line 3275 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 786 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3281 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 787 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 1000; }
#line 3287 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 788 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-1].intval) | 2000; }
#line 3293 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 792 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_col_charset(pstate, (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3299 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 793 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_col_collate(pstate, (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3305 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 797 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 10000 + (yyvsp[0].intval); }
#line 3311 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 798 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 10000 + (yyvsp[-1].intval); }
#line 3317 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 799 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 20000 + (yyvsp[-1].intval) + (yyvsp[0].intval); }
#line 3323 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 800 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 30000 + (yyvsp[-1].intval) + (yyvsp[0].intval); }
#line 3329 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 801 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 40000 + (yyvsp[-1].intval) + (yyvsp[0].intval); }
#line 3335 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 802 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 50000 + (yyvsp[-1].intval) + (yyvsp[0].intval); }
#line 3341 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 803 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 60000 + (yyvsp[-1].intval) + (yyvsp[0].intval); }
#line 3347 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 804 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 70000 + (yyvsp[-1].intval) + (yyvsp[0].intval); }
#line 3353 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 805 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 80000 + (yyvsp[-1].intval) + (yyvsp[0].intval); }
#line 3359 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 806 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 90000 + (yyvsp[-1].intval) + (yyvsp[0].intval); }
#line 3365 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 807 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 110000 + (yyvsp[-1].intval) + (yyvsp[0].intval); }
#line 3371 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 808 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 100001; }
#line 3377 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 809 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 100002; }
#line 3383 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 810 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 100003; }
#line 3389 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 811 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 100004; }
#line 3395 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 812 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 100005; }
#line 3401 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 813 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 120000 + (yyvsp[-1].intval); }
#line 3407 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 814 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 130000 + (yyvsp[-2].intval); }
#line 3413 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 815 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 140000 + (yyvsp[0].intval); }
#line 3419 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 816 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 150000 + (yyvsp[-1].intval); }
#line 3425 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 817 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 160001; }
#line 3431 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 818 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 160002; }
#line 3437 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 819 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 160003; }
#line 3443 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 820 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 160004; }
#line 3449 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 821 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 170000 + (yyvsp[-1].intval); }
#line 3455 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 822 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 171000 + (yyvsp[-1].intval); }
#line 3461 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 823 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 172000 + (yyvsp[-1].intval); }
#line 3467 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 824 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 173000 + (yyvsp[-1].intval); }
#line 3473 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 825 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 200000 + (yyvsp[-2].intval); }
#line 3479 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 826 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 210000 + (yyvsp[-2].intval); }
#line 3485 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 829 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_enum_val(pstate, (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = 1; }
#line 3491 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 830 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_enum_val(pstate, (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 3497 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 833 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_create_sel(pstate, (yyvsp[-2].intval)); }
#line 3503 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 836 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3509 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 837 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 3515 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 838 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 2; }
#line 3521 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 841 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3527 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 842 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 1;}
#line 3533 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 847 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_stmt(pstate); }
#line 3539 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 851 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_drop_table(pstate, (yyvsp[-3].intval), (yyvsp[-1].intval), (yyvsp[0].intval)); }
#line 3545 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 854 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_table(pstate, NULL, (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = 1; }
#line 3551 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 855 "src/sql.yy" /* yacc.c:1646  */
    { lyyerror((yylsp[0]), "string %s found where name required", (yyvsp[0].strval));
                              sqlp_table(pstate, NULL, (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = 1; }
#line 3558 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 857 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_table(pstate, NULL, (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 3564 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 858 "src/sql.yy" /* yacc.c:1646  */
    { lyyerror((yylsp[0]), "string %s found where name required", (yyvsp[-2].intval));
                            sqlp_table(pstate, NULL, (yyvsp[0].strval)); free((yyvsp[0].strval)); (yyval.intval) = (yyvsp[-2].intval) + 1; }
#line 3571 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 864 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_stmt(pstate); }
#line 3577 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 872 "src/sql.yy" /* yacc.c:1646  */
    { if ((yyvsp[-1].subtok) != 4) { lyyerror((yylsp[-1]),"bad set to @%s", (yyvsp[-2].strval)); YYERROR; }
		 sqlp_set(pstate, (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 3584 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 874 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_set(pstate, (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 3590 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 879 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_name(pstate, (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3596 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 880 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_uservar(pstate, (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3602 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 881 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_fieldname(pstate, (yyvsp[-2].strval), (yyvsp[0].strval)); free((yyvsp[-2].strval)); free((yyvsp[0].strval)); }
#line 3608 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 882 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_string(pstate, (yyvsp[0].strval)); free((yyvsp[0].strval)); }
#line 3614 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 883 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_number(pstate, (yyvsp[0].intval)); }
#line 3620 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 884 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_float(pstate, (yyvsp[0].floatval)); }
#line 3626 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 885 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_bool(pstate, (yyvsp[0].intval)); }
#line 3632 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 888 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_ADD); }
#line 3638 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 889 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_SUB); }
#line 3644 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 890 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_MUL); }
#line 3650 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 891 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_DIV); }
#line 3656 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 892 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_MOD); }
#line 3662 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 893 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_MOD); }
#line 3668 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 894 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_NEG); }
#line 3674 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 895 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_AND); }
#line 3680 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 896 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_OR); }
#line 3686 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 897 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_XOR); }
#line 3692 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 898 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_cmp(pstate, (yyvsp[-1].subtok)); }
#line 3698 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 899 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_cmp_sel(pstate, 0, (yyvsp[-3].subtok)); }
#line 3704 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 900 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_cmp_sel(pstate, 1, (yyvsp[-4].subtok)); }
#line 3710 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 901 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_cmp_sel(pstate, 2, (yyvsp[-4].subtok)); }
#line 3716 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 902 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_cmp_sel(pstate, 3, (yyvsp[-4].subtok)); }
#line 3722 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 903 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_BITOR); }
#line 3728 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 904 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_BITAND); }
#line 3734 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 905 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_BITXOR); }
#line 3740 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 906 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, (yyvsp[-1].subtok) == 1 ? SEO_SHL : SEO_SHR); }
#line 3746 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 907 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_NOT); }
#line 3752 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 908 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_NOT); }
#line 3758 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 909 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_assign_at(pstate, (yyvsp[-2].strval)); free((yyvsp[-2].strval)); }
#line 3764 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 912 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_IS_NULL); }
#line 3770 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 913 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_IS_NULL); sqlp_expr_op(pstate, SEO_NOT); }
#line 3776 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 914 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_is_bool(pstate, (yyvsp[0].intval)); }
#line 3782 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 915 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_is_bool(pstate, (yyvsp[0].intval)); sqlp_expr_op(pstate, SEO_NOT); }
#line 3788 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 918 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_BETWEEN); }
#line 3794 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 922 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 3800 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 923 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 1 + (yyvsp[0].intval); }
#line 3806 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 926 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 3812 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 930 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_is_in(pstate, (yyvsp[-1].intval)); }
#line 3818 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 931 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_is_in(pstate, (yyvsp[-1].intval)); sqlp_expr_op(pstate, SEO_NOT); }
#line 3824 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 932 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_IN_SELECT); }
#line 3830 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 933 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_IN_SELECT); sqlp_expr_op(pstate, SEO_NOT); }
#line 3836 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 934 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_EXISTS); if((yyvsp[-3].subtok))sqlp_expr_op(pstate, SEO_NOT); }
#line 3842 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 937 "src/sql.yy" /* yacc.c:1646  */
    {  sqlp_call(pstate, (yyvsp[-1].intval), (yyvsp[-3].strval)); free((yyvsp[-3].strval)); }
#line 3848 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 941 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_call(pstate, 0, "COUNTALL"); }
#line 3854 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 942 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_call(pstate, 1, "COUNT"); }
#line 3860 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 944 "src/sql.yy" /* yacc.c:1646  */
    {  sqlp_call(pstate, (yyvsp[-1].intval), "SUBSTR");}
#line 3866 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 945 "src/sql.yy" /* yacc.c:1646  */
    {  sqlp_call(pstate, 2, "SUBSTR"); }
#line 3872 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 946 "src/sql.yy" /* yacc.c:1646  */
    {  sqlp_call(pstate, 3, "SUBSTR"); }
#line 3878 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 947 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_call(pstate, (yyvsp[-1].intval), "TRIM"); }
#line 3884 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 948 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_call(pstate, 3, "TRIM"); }
#line 3890 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 951 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_call_trim_opts(pstate, 0); }
#line 3896 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 952 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_call_trim_opts(pstate, 1); }
#line 3902 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 953 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_call_trim_opts(pstate, 2); }
#line 3908 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 956 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_call_date(pstate, 3, SEO_ADD); }
#line 3914 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 957 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_call_date(pstate, 3, SEO_SUB); }
#line 3920 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 960 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_date_interval(pstate, SDI_DAY_HOUR); }
#line 3926 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 961 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_date_interval(pstate, SDI_DAY_MICROSECOND); }
#line 3932 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 962 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_date_interval(pstate, SDI_DAY_MINUTE); }
#line 3938 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 963 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_date_interval(pstate, SDI_DAY_SECOND); }
#line 3944 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 964 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_date_interval(pstate, SDI_YEAR_MONTH); }
#line 3950 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 965 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_date_interval(pstate, SDI_YEAR); }
#line 3956 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 966 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_date_interval(pstate, SDI_HOUR_MICROSECOND); }
#line 3962 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 967 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_date_interval(pstate, SDI_HOUR_MINUTE); }
#line 3968 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 968 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_date_interval(pstate, SDI_HOUR_SECOND); }
#line 3974 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 971 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_caseval(pstate, (yyvsp[-1].intval), 0); }
#line 3980 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 972 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_caseval(pstate, (yyvsp[-3].intval), 1); }
#line 3986 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 973 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_case(pstate, (yyvsp[-1].intval), 0); }
#line 3992 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 974 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_case(pstate, (yyvsp[-3].intval), 1); }
#line 3998 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 977 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 4004 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 978 "src/sql.yy" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-4].intval)+1; }
#line 4010 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 981 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_LIKE); }
#line 4016 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 982 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_LIKE); sqlp_expr_op(pstate, SEO_NOT); }
#line 4022 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 985 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_REGEX); }
#line 4028 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 986 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_REGEX); sqlp_expr_op(pstate, SEO_NOT); }
#line 4034 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 989 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_now(pstate); }
#line 4040 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 990 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_now(pstate); }
#line 4046 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 991 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_now(pstate); }
#line 4052 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 994 "src/sql.yy" /* yacc.c:1646  */
    { sqlp_expr_op(pstate, SEO_STRTOBIN); }
#line 4058 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
    break;


#line 4062 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, scanner, pstate, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, scanner, pstate, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, scanner, pstate);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, scanner, pstate);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, scanner, pstate, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, scanner, pstate);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, scanner, pstate);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 997 "src/sql.yy" /* yacc.c:1906  */


void
yyerror(YYLTYPE *t, struct psql_state *pstate, const char *s, ...)
{
  va_list ap;
  va_start(ap, s);

  if(t->first_line)
    fprintf(stderr, "%s:%d.%d-%d.%d: error: ", t->filename, t->first_line, t->first_column,
	    t->last_line, t->last_column);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
}


void yyerror(YYLTYPE *t,
             yyscan_t scanner,
             struct psql_state *pstate,
             const char *s,
             ...)
{
    va_list ap;
    va_start(ap, s);
    yyerror(t, pstate, s, ap);
}


void
lyyerror(YYLTYPE t, const char *s, ...)
{
  va_list ap;
  va_start(ap, s);

  if(t.first_line)
    fprintf(stderr, "%s:%d.%d-%d.%d: error: ", t.filename, t.first_line, t.first_column,
	    t.last_line, t.last_column);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
}


int
main(int ac, char **av)
{
  FILE *in_f;
  struct psql_state pstate;

  if(ac > 1 && !strcmp(av[1], "-d")) {
    yydebug = 1; ac--; av++;
  }

  memset(&pstate, 0, sizeof(pstate));
  if (yylex_init_extra(&pstate, &pstate.scanner))
  	return 1;

  if(ac > 1) {
    if((in_f = fopen(av[1], "r")) == NULL) {
      perror(av[1]);
      exit(1);
    }
    filename = av[1];
  } else {
    filename = "(stdin)";
    in_f = stdin;
  }

  yyset_in(in_f, pstate.scanner);

  if(!yyparse(pstate.scanner, &pstate)) {
    printf("SQL parse worked\n");
    return 0;
  } else {
    printf("SQL parse failed\n");
    return 1;
  }
} /* main */
