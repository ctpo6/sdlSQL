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
#line 34 "src/sql.yy" // lalr1.cc:413

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
      case 18: // COMPARISON
        value.move< ::ExprOperator > (that.value);
        break;

      case 12: // "APPROXNUM"
        value.move< double > (that.value);
        break;

      case 11: // "INTNUM"
      case 13: // "BOOL"
      case 46: // orderby_list
      case 47: // opt_asc_desc
      case 48: // select_expr_list
        value.move< int > (that.value);
        break;

      case 9: // "NAME"
      case 10: // "STRING"
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
      case 18: // COMPARISON
        value.copy< ::ExprOperator > (that.value);
        break;

      case 12: // "APPROXNUM"
        value.copy< double > (that.value);
        break;

      case 11: // "INTNUM"
      case 13: // "BOOL"
      case 46: // orderby_list
      case 47: // opt_asc_desc
      case 48: // select_expr_list
        value.copy< int > (that.value);
        break;

      case 9: // "NAME"
      case 10: // "STRING"
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
    switch (yytype)
    {
            case 9: // "NAME"

#line 83 "src/sql.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 352 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:636
        break;

      case 10: // "STRING"

#line 83 "src/sql.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 359 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:636
        break;

      case 11: // "INTNUM"

#line 83 "src/sql.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< int > (); }
#line 366 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:636
        break;

      case 12: // "APPROXNUM"

#line 83 "src/sql.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< double > (); }
#line 373 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:636
        break;

      case 13: // "BOOL"

#line 83 "src/sql.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< int > (); }
#line 380 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:636
        break;

      case 18: // COMPARISON

#line 83 "src/sql.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ::ExprOperator > (); }
#line 387 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:636
        break;

      case 46: // orderby_list

#line 83 "src/sql.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< int > (); }
#line 394 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:636
        break;

      case 47: // opt_asc_desc

#line 83 "src/sql.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< int > (); }
#line 401 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:636
        break;

      case 48: // select_expr_list

#line 83 "src/sql.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< int > (); }
#line 408 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:636
        break;


      default:
        break;
    }
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
    #line 25 "src/sql.yy" // lalr1.cc:741
{
  // Initialize the initial location.
  yyla.location.begin.filename = yyla.location.end.filename = &driver.file;
}

#line 527 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:741

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
      case 18: // COMPARISON
        yylhs.value.build< ::ExprOperator > ();
        break;

      case 12: // "APPROXNUM"
        yylhs.value.build< double > ();
        break;

      case 11: // "INTNUM"
      case 13: // "BOOL"
      case 46: // orderby_list
      case 47: // opt_asc_desc
      case 48: // select_expr_list
        yylhs.value.build< int > ();
        break;

      case 9: // "NAME"
      case 10: // "STRING"
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
#line 105 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_stmt(); }
#line 658 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 112 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_select(yystack_[4].value.as< int > ()); }
#line 664 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 117 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_from_table_reference(); }
#line 670 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 130 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_table("", yystack_[0].value.as< std::string > ()); }
#line 676 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 132 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_table(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ()); }
#line 682 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 137 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_join(); }
#line 688 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 140 "src/sql.yy" // lalr1.cc:859
    {}
#line 694 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 142 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_top(yystack_[1].value.as< int > ()); }
#line 700 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 145 "src/sql.yy" // lalr1.cc:859
    {}
#line 706 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 147 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_where(); }
#line 712 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 150 "src/sql.yy" // lalr1.cc:859
    {}
#line 718 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 152 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_order_by_list(yystack_[0].value.as< int > ()); }
#line 724 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 157 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_order_by(yystack_[0].value.as< int > ()); yylhs.value.as< int > () = 1; }
#line 730 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 159 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_order_by(yystack_[0].value.as< int > ()); yylhs.value.as< int > () = yystack_[3].value.as< int > () + 1; }
#line 736 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 164 "src/sql.yy" // lalr1.cc:859
    { yylhs.value.as< int > () = 0; }
#line 742 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 166 "src/sql.yy" // lalr1.cc:859
    { yylhs.value.as< int > () = 0; }
#line 748 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 168 "src/sql.yy" // lalr1.cc:859
    { yylhs.value.as< int > () = 1; }
#line 754 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 173 "src/sql.yy" // lalr1.cc:859
    { yylhs.value.as< int > () = 1; }
#line 760 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 175 "src/sql.yy" // lalr1.cc:859
    {yylhs.value.as< int > () = yystack_[2].value.as< int > () + 1; }
#line 766 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 177 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_select_all(); yylhs.value.as< int > () = 1; }
#line 772 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 186 "src/sql.yy" // lalr1.cc:859
    {}
#line 778 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 188 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_alias(yystack_[0].value.as< std::string > ()); }
#line 784 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 190 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_alias(yystack_[0].value.as< std::string > ()); }
#line 790 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 198 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_name(yystack_[0].value.as< std::string > ()); }
#line 796 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 200 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_field(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ()); }
#line 802 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 205 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_string(yystack_[0].value.as< std::string > ()); }
#line 808 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 207 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_number(yystack_[0].value.as< int > ()); }
#line 814 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 209 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_float(yystack_[0].value.as< double > ()); }
#line 820 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 214 "src/sql.yy" // lalr1.cc:859
    {}
#line 826 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 216 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_op(ExprOperator::NEG); }
#line 832 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 218 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_op(ExprOperator::AND); }
#line 838 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 220 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_op(ExprOperator::OR); }
#line 844 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 222 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_cmp(yystack_[1].value.as< ::ExprOperator > ()); }
#line 850 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 224 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_op(ExprOperator::NOT); }
#line 856 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 229 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_op(ExprOperator::IS_NULL); }
#line 862 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 231 "src/sql.yy" // lalr1.cc:859
    { driver.sqlp_expr_op(ExprOperator::IS_NULL); driver.sqlp_expr_op(ExprOperator::NOT); }
#line 868 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
    break;


#line 872 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:859
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


  const signed char SqlParser::yypact_ninf_ = -26;

  const signed char SqlParser::yytable_ninf_ = -1;

  const signed char
  SqlParser::yypact_[] =
  {
       3,    -3,   -25,     1,     6,   -26,   -26,    40,    10,   -26,
      38,    42,   -26,    18,   -26,    45,    11,   -26,    -2,   -26,
     -26,    48,    46,    47,    49,   -26,    50,   -26,   -26,   -26,
     -26,    53,    29,    31,   -26,    -2,   -26,   -26,    54,    -1,
      35,    49,   -26,   -26,    -1,   -26,   -26,   -26,    -1,    -1,
     -26,    12,    43,   -26,    34,    33,    51,   -26,    -1,    -1,
      -5,    -1,    47,    -1,   -26,    25,     5,    41,   -26,   -26,
      61,    21,    12,   -26,    47,   -26,   -26,   -26,    21,   -26
  };

  const unsigned char
  SqlParser::yydefact_[] =
  {
       0,     0,    15,     0,     0,     6,     4,     0,     0,     1,
       0,     0,     2,     0,    28,    33,     0,    26,    30,     5,
       3,     0,     0,     0,     0,    32,     0,    29,    16,    34,
      27,    12,    17,     8,     9,    30,    10,    31,     0,     0,
      19,     0,    11,    13,     0,    36,    37,    38,     0,     0,
      35,    18,     0,     7,     0,     0,    44,    40,     0,     0,
       0,     0,     0,     0,    39,    42,    41,     0,    45,    43,
      20,    23,    14,    46,     0,    24,    25,    21,    23,    22
  };

  const signed char
  SqlParser::yypgoto_[] =
  {
     -26,   -26,    67,   -26,   -26,   -26,    30,   -26,   -26,   -26,
     -26,   -26,   -26,    -6,   -26,    52,    39,    -8,   -24
  };

  const signed char
  SqlParser::yydefgoto_[] =
  {
      -1,     3,     4,     5,    32,    33,    34,    35,    36,     8,
      40,    53,    70,    77,    16,    17,    27,    50,    51
  };

  const unsigned char
  SqlParser::yytable_[] =
  {
      18,     9,    10,    44,     1,     6,     7,    25,    15,    45,
      46,    47,    67,    14,    12,    18,    48,    23,    26,    15,
      55,    60,    68,    61,    56,    57,    58,    59,    60,    21,
      61,     2,    49,     2,    65,    66,    24,    69,    64,    72,
      59,    60,    75,    61,    13,    76,    19,    58,    59,    60,
      20,    61,    22,    28,    71,    29,    15,    41,    31,    37,
      38,    39,    63,    43,    52,    62,    78,    74,    73,    61,
      11,    54,    79,     0,    42,    30
  };

  const signed char
  SqlParser::yycheck_[] =
  {
       8,     0,     1,     4,     1,     8,    31,     9,     9,    10,
      11,    12,    17,     3,     8,    23,    17,     6,    20,     9,
      44,    16,    27,    18,    48,    49,    14,    15,    16,    11,
      18,    30,    33,    30,    58,    59,    25,    61,     5,    63,
      15,    16,    21,    18,     4,    24,     8,    14,    15,    16,
       8,    18,     7,     5,    62,     9,     9,    26,     9,     9,
       7,    32,    28,     9,    29,    22,    74,     6,    27,    18,
       3,    41,    78,    -1,    35,    23
  };

  const unsigned char
  SqlParser::yystos_[] =
  {
       0,     1,    30,    35,    36,    37,     8,    31,    43,     0,
       1,    36,     8,     4,     3,     9,    48,    49,    51,     8,
       8,    11,     7,     6,    25,     9,    20,    50,     5,     9,
      49,     9,    38,    39,    40,    41,    42,     9,     7,    32,
      44,    26,    50,     9,     4,    10,    11,    12,    17,    33,
      51,    52,    29,    45,    40,    52,    52,    52,    14,    15,
      16,    18,    22,    28,     5,    52,    52,    17,    27,    52,
      46,    51,    52,    27,     6,    21,    24,    47,    51,    47
  };

  const unsigned char
  SqlParser::yyr1_[] =
  {
       0,    34,    35,    35,    35,    35,    36,    37,    38,    39,
      39,    40,    41,    41,    42,    43,    43,    44,    44,    45,
      45,    46,    46,    47,    47,    47,    48,    48,    48,    49,
      50,    50,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52
  };

  const unsigned char
  SqlParser::yyr2_[] =
  {
       0,     2,     2,     3,     2,     3,     1,     7,     1,     1,
       1,     2,     1,     3,     5,     0,     4,     0,     2,     0,
       3,     2,     4,     0,     1,     1,     1,     3,     1,     2,
       0,     2,     1,     1,     3,     1,     1,     1,     1,     3,
       2,     3,     3,     3,     2,     3,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const SqlParser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"*\"", "\"(\"", "\")\"",
  "\",\"", "\".\"", "\";\"", "\"NAME\"", "\"STRING\"", "\"INTNUM\"",
  "\"APPROXNUM\"", "\"BOOL\"", "OP_OR", "OP_AND", "IS", "NOT",
  "COMPARISON", "UMINUS", "AS", "ASC", "BY", "COMMENT", "DESC", "FROM",
  "JOIN", "NULLX", "ON", "ORDER", "SELECT", "TOP", "WHERE", "\"-\"",
  "$accept", "stmt_list", "stmt", "select_stmt", "from_table_reference",
  "table_reference", "table_name_expr", "table_name", "join_table",
  "opt_top", "opt_where", "opt_orderby", "orderby_list", "opt_asc_desc",
  "select_expr_list", "select_expr", "opt_as_alias", "field_name", "expr", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  SqlParser::yyrline_[] =
  {
       0,    92,    92,    93,    97,    98,   104,   109,   116,   120,
     121,   125,   129,   131,   136,   140,   141,   145,   146,   150,
     151,   156,   158,   163,   165,   167,   172,   174,   176,   181,
     186,   187,   189,   197,   199,   203,   204,   206,   208,   213,
     215,   217,   219,   221,   223,   228,   230
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
#line 1291 "/home/yuri/work/bison/sdlSQL/out.bison/sql.tab.cpp" // lalr1.cc:1167
#line 240 "src/sql.yy" // lalr1.cc:1168


void yy::SqlParser::error(const location_type& l,
                          const std::string& m)
{
    driver.error(l, m);
}
