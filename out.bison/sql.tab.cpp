// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "sql.tab.hpp"

// User implementation prologue.

#line 51 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:412
// Unqualified %code blocks.
#line 32 "src/sql.yy" // lalr1.cc:413

#include "driver.hpp"

#line 57 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 143 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  SqlParser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  SqlParser::SqlParser (Driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  SqlParser::~SqlParser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  SqlParser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  SqlParser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  SqlParser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  SqlParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  SqlParser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  SqlParser::symbol_number_type
  SqlParser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  SqlParser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  SqlParser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 13: // APPROXNUM
        value.move< double > (that.value);
        break;

      case 11: // INTNUM
      case 12: // BOOL
      case 18: // COMPARISON
      case 50: // groupby_list
      case 51: // opt_asc_desc
      case 54: // select_opts
      case 55: // select_expr_list
      case 57: // table_references
      case 62: // val_list
      case 63: // opt_val_list
        value.move< int > (that.value);
        break;

      case 9: // NAME
      case 10: // STRING
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  SqlParser::stack_symbol_type&
  SqlParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 13: // APPROXNUM
        value.copy< double > (that.value);
        break;

      case 11: // INTNUM
      case 12: // BOOL
      case 18: // COMPARISON
      case 50: // groupby_list
      case 51: // opt_asc_desc
      case 54: // select_opts
      case 55: // select_expr_list
      case 57: // table_references
      case 62: // val_list
      case 63: // opt_val_list
        value.copy< int > (that.value);
        break;

      case 9: // NAME
      case 10: // STRING
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  SqlParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  SqlParser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  SqlParser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  SqlParser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  SqlParser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  SqlParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  SqlParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  SqlParser::debug_level_type
  SqlParser::debug_level () const
  {
    return yydebug_;
  }

  void
  SqlParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline SqlParser::state_type
  SqlParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  SqlParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  SqlParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  SqlParser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 23 "src/sql.yy" // lalr1.cc:741
{
  // Initialize the initial location.
  yyla.location.begin.filename = yyla.location.end.filename = &driver.file;
}

#line 461 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:741

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 13: // APPROXNUM
        yylhs.value.build< double > ();
        break;

      case 11: // INTNUM
      case 12: // BOOL
      case 18: // COMPARISON
      case 50: // groupby_list
      case 51: // opt_asc_desc
      case 54: // select_opts
      case 55: // select_expr_list
      case 57: // table_references
      case 62: // val_list
      case 63: // opt_val_list
        yylhs.value.build< int > ();
        break;

      case 9: // NAME
      case 10: // STRING
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 6:
#line 101 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_stmt(); }
#line 593 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 105 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_select_nodata(yystack_[1].value.as< int > (), yystack_[0].value.as< int > ()); }
#line 599 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 109 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_select(yystack_[7].value.as< int > (), yystack_[6].value.as< int > (), yystack_[4].value.as< int > ()); }
#line 605 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 113 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_where(); }
#line 611 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 116 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_group_by_list(yystack_[0].value.as< int > ()); }
#line 617 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 120 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_group_by(yystack_[0].value.as< int > ()); yylhs.value.as< int > () = 1; }
#line 623 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 122 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_group_by(yystack_[0].value.as< int > ()); yylhs.value.as< int > () = yystack_[3].value.as< int > () + 1; }
#line 629 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 125 "src/sql.yy" // lalr1.cc:859
    { yylhs.value.as< int > () = 0; }
#line 635 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 126 "src/sql.yy" // lalr1.cc:859
    { yylhs.value.as< int > () = 0; }
#line 641 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 127 "src/sql.yy" // lalr1.cc:859
    { yylhs.value.as< int > () = 1; }
#line 647 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 130 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_having(); }
#line 653 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 132 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_order_by(yystack_[0].value.as< int > ()); }
#line 659 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 135 "src/sql.yy" // lalr1.cc:859
    { yylhs.value.as< int > () = 0; }
#line 665 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 136 "src/sql.yy" // lalr1.cc:859
    { if(yylhs.value.as< int > () & 01) error(yylhs.location, "duplicate ALL option"); yylhs.value.as< int > () = yystack_[1].value.as< int > () | 01; }
#line 671 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 139 "src/sql.yy" // lalr1.cc:859
    { yylhs.value.as< int > () = 1; }
#line 677 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 140 "src/sql.yy" // lalr1.cc:859
    {yylhs.value.as< int > () = yystack_[2].value.as< int > () + 1; }
#line 683 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 141 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_select_all(); yylhs.value.as< int > () = 1; }
#line 689 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 146 "src/sql.yy" // lalr1.cc:859
    { yylhs.value.as< int > () = 1; }
#line 695 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 147 "src/sql.yy" // lalr1.cc:859
    { yylhs.value.as< int > () = yystack_[2].value.as< int > () + 1; }
#line 701 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 154 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_table(NULL, yystack_[1].value.as< std::string > ()); }
#line 707 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 155 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_table(yystack_[3].value.as< std::string > (), yystack_[1].value.as< std::string > ()); }
#line 713 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 158 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_alias(yystack_[0].value.as< std::string > ()); }
#line 719 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 159 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_alias(yystack_[0].value.as< std::string > ()); }
#line 725 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 165 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_name(yystack_[0].value.as< std::string > ()); }
#line 731 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 166 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_fieldname(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ()); }
#line 737 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 167 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_string(yystack_[0].value.as< std::string > ()); }
#line 743 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 168 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_number(yystack_[0].value.as< int > ()); }
#line 749 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 169 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_float(yystack_[0].value.as< double > ()); }
#line 755 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 170 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_bool(yystack_[0].value.as< int > ()); }
#line 761 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 173 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_op(SEO_ADD); }
#line 767 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 174 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_op(SEO_SUB); }
#line 773 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 175 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_op(SEO_MUL); }
#line 779 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 176 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_op(SEO_DIV); }
#line 785 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 177 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_op(SEO_MOD); }
#line 791 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 178 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_op(SEO_NEG); }
#line 797 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 179 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_op(SEO_AND); }
#line 803 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 180 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_op(SEO_OR); }
#line 809 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 181 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_cmp(yystack_[1].value.as< int > ()); }
#line 815 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 182 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_op(SEO_NOT); }
#line 821 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 185 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_op(SEO_IS_NULL); }
#line 827 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 186 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_op(SEO_IS_NULL);
                           driver.sqlp_expr_op(SEO_NOT); }
#line 834 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 54:
#line 190 "src/sql.yy" // lalr1.cc:859
    { yylhs.value.as< int > () = 1; }
#line 840 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 191 "src/sql.yy" // lalr1.cc:859
    { yylhs.value.as< int > () = 1 + yystack_[0].value.as< int > (); }
#line 846 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 56:
#line 194 "src/sql.yy" // lalr1.cc:859
    { yylhs.value.as< int > () = 0; }
#line 852 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 58:
#line 198 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_is_in(yystack_[1].value.as< int > ()); }
#line 858 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 199 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_is_in(yystack_[1].value.as< int > ());
                                       driver.sqlp_expr_op(SEO_NOT); }
#line 865 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 60:
#line 203 "src/sql.yy" // lalr1.cc:859
    {  driver.sqlp_call(yystack_[1].value.as< int > (), yystack_[3].value.as< std::string > ()); }
#line 871 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;


#line 875 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  SqlParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  SqlParser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char SqlParser::yypact_ninf_ = -43;

  const signed char SqlParser::yytable_ninf_ = -1;

  const short int
  SqlParser::yypact_[] =
  {
       2,   -20,   -43,     1,   -14,   -43,   -43,   136,   -43,    19,
      20,   -43,   -35,   -43,   -43,   -43,   -43,    44,    44,   -43,
     -43,   -22,   -43,    53,   -43,   -43,    73,    44,   144,    49,
      75,    44,   -43,    44,    44,   -12,    51,    44,    44,    44,
      44,    44,    44,    79,    48,   -43,   -43,    26,   -43,    61,
      -5,   -18,   -43,   -43,   -43,   110,   120,    56,   -43,    50,
      -6,    29,    29,    49,    49,    49,   -43,    44,    44,   -43,
      96,   -43,    44,    75,    74,   -43,    44,    65,   -43,     3,
     101,   -43,    81,    78,    69,   -43,   -43,    44,    44,    77,
     -43,    94,    80,   101,   122,   -43,    44,   -43,   -43,   -43,
      44,    80,    94,   -43
  };

  const unsigned char
  SqlParser::yydefact_[] =
  {
       0,     0,    22,     0,     0,     6,     4,     0,     1,     0,
       0,     2,    36,    38,    39,    41,    40,     0,     0,    26,
      23,     7,    24,    35,     5,     3,     0,    56,    51,    47,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    37,    54,    57,     0,
      35,     9,    28,    30,    25,    49,    48,     0,    52,     0,
      50,    42,    43,    44,    45,    46,    33,     0,     0,    60,
       0,    31,     0,     0,    11,    53,     0,     0,    55,    35,
      10,    29,     0,    18,     0,    58,    32,     0,     0,    20,
      59,    12,    15,    19,     0,     8,     0,    16,    17,    13,
       0,    15,    21,    14
  };

  const short int
  SqlParser::yypgoto_[] =
  {
     -43,   -43,   148,   -43,   -43,   -43,    52,    54,   -43,   -43,
     -43,   -43,   127,   -43,    86,   -43,   -42,    -7,    10,   -43
  };

  const signed char
  SqlParser::yydefgoto_[] =
  {
      -1,     3,     4,     5,    74,    83,    91,    99,    89,    95,
       7,    21,    22,    51,    52,    53,    45,    47,    48,    49
  };

  const unsigned char
  SqlParser::yytable_[] =
  {
      23,     8,     9,     1,    32,    57,    26,    27,    71,    30,
      28,    29,    32,    38,    39,    40,    41,    42,    31,     6,
      72,    43,    73,    58,    23,    11,    55,    56,    44,    43,
      60,    61,    62,    63,    64,    65,    70,    86,     2,     2,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      40,    41,    42,    12,    13,    14,    15,    16,    24,    25,
      44,    17,    32,    44,    18,    80,    68,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    77,    78,    43,
      92,    93,    46,    44,    50,    59,    84,    44,    66,   101,
      67,    75,    76,    92,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    69,    79,    82,    97,    85,    87,
      98,    88,    90,    94,    44,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    96,    44,    35,    36,    37,    38,
      39,    40,    41,    42,    44,    12,    13,    14,    15,    16,
     100,    10,   102,    17,    44,   103,    18,    19,    54,    81,
       0,    20,    37,    38,    39,    40,    41,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44
  };

  const signed char
  SqlParser::yycheck_[] =
  {
       7,     0,     1,     1,     9,    17,    41,    42,    50,    31,
      17,    18,     9,    19,    20,    21,    22,    23,    40,    39,
      38,    26,    40,    35,    31,    39,    33,    34,    34,    26,
      37,    38,    39,    40,    41,    42,    41,    79,    37,    37,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      21,    22,    23,     9,    10,    11,    12,    13,    39,    39,
      34,    17,     9,    34,    20,    72,    40,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    67,    68,    26,
      87,    88,     9,    34,     9,    34,    76,    34,     9,    96,
      42,    35,    42,   100,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    43,     9,    32,    27,    43,    28,
      30,    33,    43,    36,    34,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    40,    34,    16,    17,    18,    19,
      20,    21,    22,    23,    34,     9,    10,    11,    12,    13,
      28,     3,   100,    17,    34,   101,    20,    21,    31,    73,
      -1,    25,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34
  };

  const unsigned char
  SqlParser::yystos_[] =
  {
       0,     1,    37,    45,    46,    47,    39,    54,     0,     1,
      46,    39,     9,    10,    11,    12,    13,    17,    20,    21,
      25,    55,    56,    61,    39,    39,    41,    42,    61,    61,
      31,    40,     9,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    26,    34,    60,     9,    61,    62,    63,
       9,    57,    58,    59,    56,    61,    61,    17,    35,    34,
      61,    61,    61,    61,    61,    61,     9,    42,    40,    43,
      41,    60,    38,    40,    48,    35,    42,    62,    62,     9,
      61,    58,    32,    49,    62,    43,    60,    28,    33,    52,
      43,    50,    61,    61,    36,    53,    40,    27,    30,    51,
      28,    61,    50,    51
  };

  const unsigned char
  SqlParser::yyr1_[] =
  {
       0,    44,    45,    45,    45,    45,    46,    47,    47,    48,
      48,    49,    49,    50,    50,    51,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    55,    56,    57,    57,
      58,    59,    59,    60,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    62,    62,    63,    63,    61,    61,
      61
  };

  const unsigned char
  SqlParser::yyr2_[] =
  {
       0,     2,     2,     3,     2,     3,     1,     3,     9,     0,
       2,     0,     3,     2,     4,     0,     1,     1,     0,     2,
       0,     3,     0,     2,     1,     3,     1,     2,     1,     3,
       1,     2,     4,     2,     1,     0,     1,     3,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     2,     3,     4,     1,     3,     0,     1,     5,     6,
       4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const SqlParser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"*\"", "\"(\"", "\")\"",
  "\",\"", "\".\"", "\";\"", "NAME", "STRING", "INTNUM", "BOOL",
  "APPROXNUM", "OP_OR", "OP_AND", "IS", "NOT", "COMPARISON", "'+'", "'-'",
  "'*'", "'/'", "'%'", "UMINUS", "ALL", "AS", "ASC", "BY", "COMMENT",
  "DESC", "FROM", "GROUP", "HAVING", "IN", "NULLX", "ORDER", "SELECT",
  "WHERE", "';'", "','", "'.'", "'('", "')'", "$accept", "stmt_list",
  "stmt", "select_stmt", "opt_where", "opt_groupby", "groupby_list",
  "opt_asc_desc", "opt_having", "opt_orderby", "select_opts",
  "select_expr_list", "select_expr", "table_references", "table_reference",
  "table_factor", "opt_as_alias", "expr", "val_list", "opt_val_list", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  SqlParser::yyrline_[] =
  {
       0,    92,    92,    93,    96,    97,   101,   104,   106,   112,
     113,   115,   116,   119,   121,   125,   126,   127,   130,   130,
     132,   132,   135,   136,   139,   140,   141,   144,   146,   147,
     150,   154,   155,   158,   159,   160,   165,   166,   167,   168,
     169,   170,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   185,   186,   190,   191,   194,   195,   198,   199,
     203
  };

  // Print the state stack on the debug stream.
  void
  SqlParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  SqlParser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1330 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:1167
#line 212 "src/sql.yy" // lalr1.cc:1168


void yy::SqlParser::error(const location_type& l,
                          const std::string& m)
{
    driver.error(l, m);
}
