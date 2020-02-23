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

#line 37 "binary.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "binary.tab.hh"

// User implementation prologue.

#line 51 "binary.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 6 "binary.yy" // lalr1.cc:413


  Node *root;
  int count = 0;
  int init = 0;
  #include <string>
  
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;


#line 65 "binary.tab.cc" // lalr1.cc:413


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
#line 132 "binary.tab.cc" // lalr1.cc:479

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
      switch (that.type_get ())
    {
      case 34: // chunk
      case 35: // block
      case 36: // stat
      case 37: // laststat
      case 38: // exp
      case 39: // prefixexp
      case 40: // var
      case 41: // varlist
      case 42: // functioncall
      case 43: // args
      case 44: // explist
        value.move< Node * > (that.value);
        break;

      case 17: // NUM
      case 18: // NAME
      case 19: // STRING
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 34: // chunk
      case 35: // block
      case 36: // stat
      case 37: // laststat
      case 38: // exp
      case 39: // prefixexp
      case 40: // var
      case 41: // varlist
      case 42: // functioncall
      case 43: // args
      case 44: // explist
        value.copy< Node * > (that.value);
        break;

      case 17: // NUM
      case 18: // NAME
      case 19: // STRING
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
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
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
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

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


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
            symbol_type yylookahead (yylex ());
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
      case 34: // chunk
      case 35: // block
      case 36: // stat
      case 37: // laststat
      case 38: // exp
      case 39: // prefixexp
      case 40: // var
      case 41: // varlist
      case 42: // functioncall
      case 43: // args
      case 44: // explist
        yylhs.value.build< Node * > ();
        break;

      case 17: // NUM
      case 18: // NAME
      case 19: // STRING
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 40 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("chunk","", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());   }
#line 518 "binary.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 42 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("chunk","", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());   }
#line 525 "binary.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 44 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[1].value.as< Node * > ();
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());   }
#line 532 "binary.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 46 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[1].value.as< Node * > ();
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ()); }
#line 539 "binary.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 50 "binary.yy" // lalr1.cc:859
    {	  yylhs.value.as< Node * > () = new StdNode("block","", count++);
                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                  root = yylhs.value.as< Node * > ();                 }
#line 547 "binary.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 56 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("stat","EQU", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 555 "binary.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 59 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("repeat","", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 563 "binary.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 62 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new StdNode("stat","do", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                              }
#line 571 "binary.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 65 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new StdNode("stat","if", count++);
                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                }
#line 580 "binary.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 69 "binary.yy" // lalr1.cc:859
    {
                                yylhs.value.as< Node * > () = new StdNode("stat","for", count++);
                                yylhs.value.as< Node * > ()->children.push_back(new StdNode("var", yystack_[7].value.as< std::string > (), count++));
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[5].value.as< Node * > ());
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                              }
#line 592 "binary.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 76 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("stat","functioncall", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 599 "binary.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 81 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("laststat","RETURN", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());      }
#line 606 "binary.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 83 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("laststat","BREAK", count++);  }
#line 612 "binary.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 87 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new IntNode("num", yystack_[0].value.as< std::string > (), count++);  }
#line 618 "binary.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 88 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StringNode("String",yystack_[0].value.as< std::string > (), count++);  }
#line 624 "binary.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 89 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();              }
#line 630 "binary.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 90 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new PlusNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 638 "binary.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 93 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new MinusNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 646 "binary.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 96 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new MultNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 654 "binary.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 99 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new DivNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 662 "binary.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 102 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ModNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 670 "binary.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 105 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpoNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 678 "binary.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 108 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","INF", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 686 "binary.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 111 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","SUP", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 694 "binary.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 114 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","EQU", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 702 "binary.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 117 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","NEQU", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 710 "binary.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 120 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","INFEQ", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 718 "binary.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 123 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","SUPEQ", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 726 "binary.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 126 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","DBEQU", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 734 "binary.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 131 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();         }
#line 740 "binary.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 132 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();         }
#line 746 "binary.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 133 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[1].value.as< Node * > ();         }
#line 752 "binary.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 136 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("var",yystack_[0].value.as< std::string > (), count++);               }
#line 758 "binary.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 137 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[2].value.as< Node * > ();
                                  StdNode* tmp = new StdNode("dot",yystack_[0].value.as< std::string > (), count++);
                                  yylhs.value.as< Node * > ()->children.push_back(tmp);         }
#line 766 "binary.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 142 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("varlist","", count++); 
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 773 "binary.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 144 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[2].value.as< Node * > ();
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 780 "binary.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 148 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new FuncCallNode("functioncall", yystack_[1].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ()); 
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 788 "binary.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 153 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StringNode("String",yystack_[0].value.as< std::string > (), count++);}
#line 794 "binary.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 154 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ArgsNode("args", count++); 
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());         }
#line 801 "binary.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 158 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpListNode("explist", count++); 
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 808 "binary.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 160 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[2].value.as< Node * > ();
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 815 "binary.tab.cc" // lalr1.cc:859
    break;


#line 819 "binary.tab.cc" // lalr1.cc:859
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
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


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

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


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
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -6;

  const signed char parser::yytable_ninf_ = -38;

  const short int
  parser::yypact_[] =
  {
      76,     8,     8,    -6,    76,     4,     8,    76,    -6,    76,
      24,    -6,    -6,    10,    -5,     6,    45,    -6,    -6,    18,
      10,    -6,    -6,   147,    26,    20,    30,    47,    43,    -6,
      -6,    -6,     8,    42,    -6,    -6,    17,     8,    -6,     8,
       8,     8,     8,     8,     8,     8,     8,     8,     8,     8,
       8,     8,     8,     8,     8,    76,    -6,    25,    -6,    12,
      26,    84,    84,    84,    84,    84,    84,    84,    88,    88,
      31,    31,    31,    31,   147,   147,   116,    49,    -6,     8,
      -6,   134,    76,    71,    -6
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,    14,     0,     0,     0,     0,    34,     6,
       0,     2,     3,     0,    31,     0,    12,    15,    16,     0,
      17,    31,    32,    41,    13,     0,     0,     0,     0,     4,
       5,     1,     0,     0,    39,    38,     0,     0,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     9,     0,    35,    31,
       7,    24,    25,    26,    27,    28,    29,    30,    18,    19,
      20,    21,    22,    23,    42,     8,     0,     0,    40,     0,
      10,     0,     0,     0,    11
  };

  const signed char
  parser::yypgoto_[] =
  {
      -6,    -6,    -1,    81,    83,    56,     0,     1,    -6,    11,
      -6,    21
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     9,    10,    11,    12,    23,    20,    21,    15,    22,
      35,    24
  };

  const signed char
  parser::yytable_[] =
  {
      13,    14,   -36,    25,    13,    14,    28,    13,    14,    13,
      14,    16,     1,    36,    32,    16,    33,   -36,    16,   -37,
      16,     1,    26,    38,    31,    17,     8,    18,    37,    34,
      78,    53,    52,    52,   -37,     8,    13,    59,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,   -32,    54,    57,    77,    13,    14,    19,    60,    56,
      58,    55,    27,    51,   -32,    80,    16,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
       1,    83,    13,    14,     2,     3,     4,    84,     5,     6,
      29,     7,    30,    16,     8,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    46,    47,    48,    49,    50,    51,    48,    49,    50,
      51,     0,     0,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    82,
       0,     0,     0,     0,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51
  };

  const signed char
  parser::yycheck_[] =
  {
       0,     0,     7,     4,     4,     4,     7,     7,     7,     9,
       9,     0,     4,     7,     4,     4,     6,    22,     7,     7,
       9,     4,    18,     5,     0,    17,    18,    19,    22,    19,
       5,    11,     7,     7,    22,    18,    36,    36,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     6,    22,    32,    55,    55,    55,     1,    37,    16,
      18,    14,     6,    32,    19,    16,    55,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       4,    82,    82,    82,     8,     9,    10,    16,    12,    13,
       9,    15,     9,    82,    18,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    27,    28,    29,    30,    31,    32,    29,    30,    31,
      32,    -1,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    15,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     4,     8,     9,    10,    12,    13,    15,    18,    34,
      35,    36,    37,    39,    40,    41,    42,    17,    19,    38,
      39,    40,    42,    38,    44,    35,    18,    38,    35,    36,
      37,     0,     4,     6,    19,    43,     7,    22,     5,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     7,    11,    22,    14,    16,    44,    18,    40,
      44,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    35,     5,     7,
      16,    38,    15,    35,    16
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    33,    34,    34,    34,    34,    35,    36,    36,    36,
      36,    36,    36,    37,    37,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    39,    39,    39,    40,    40,    41,    41,    42,    43,
      43,    44,    44
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     2,     1,     3,     4,     3,
       5,     9,     1,     2,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     3,     1,     3,     1,     3,     2,     1,
       3,     1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "END", "error", "$undefined", "NEWL", "BROPEN", "BRCLOSE", "DOT",
  "COMMA", "RETURN", "BREAK", "REPEAT", "UNTIL", "FOR", "IF", "THEN", "DO",
  "STEND", "NUM", "NAME", "STRING", "INF", "SUP", "EQU", "NEQU", "INFEQ",
  "SUPEQ", "DBEQU", "PLUS", "MINUS", "MULT", "DIV", "MOD", "EXPO",
  "$accept", "chunk", "block", "stat", "laststat", "exp", "prefixexp",
  "var", "varlist", "functioncall", "args", "explist", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    40,    40,    42,    44,    46,    50,    56,    59,    62,
      65,    69,    76,    81,    83,    87,    88,    89,    90,    93,
      96,    99,   102,   105,   108,   111,   114,   117,   120,   123,
     126,   131,   132,   133,   136,   137,   142,   144,   148,   153,
     154,   158,   160
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
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
  parser::yy_reduce_print_ (int yyrule)
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
#line 1164 "binary.tab.cc" // lalr1.cc:1167
