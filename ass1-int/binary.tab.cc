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
      case 33: // chunk
      case 34: // block
      case 35: // stat
      case 36: // laststat
      case 37: // exp
      case 38: // prefixexp
      case 39: // var
      case 40: // varlist
      case 41: // functioncall
      case 42: // args
      case 43: // explist
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
      case 33: // chunk
      case 34: // block
      case 35: // stat
      case 36: // laststat
      case 37: // exp
      case 38: // prefixexp
      case 39: // var
      case 40: // varlist
      case 41: // functioncall
      case 42: // args
      case 43: // explist
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
      case 33: // chunk
      case 34: // block
      case 35: // stat
      case 36: // laststat
      case 37: // exp
      case 38: // prefixexp
      case 39: // var
      case 40: // varlist
      case 41: // functioncall
      case 42: // args
      case 43: // explist
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
#line 55 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("stat","EQU", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 555 "binary.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 58 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("repeat","", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 563 "binary.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 61 "binary.yy" // lalr1.cc:859
    {
                                yylhs.value.as< Node * > () = new StdNode("stat","for", count++);
                                yylhs.value.as< Node * > ()->children.push_back(new StdNode("var", yystack_[7].value.as< std::string > (), count++));
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[5].value.as< Node * > ());
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                              }
#line 575 "binary.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 68 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("stat","functioncall", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 582 "binary.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 73 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("laststat","RETURN", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());      }
#line 589 "binary.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 75 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("laststat","BREAK", count++);  }
#line 595 "binary.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 79 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new IntNode("num", yystack_[0].value.as< std::string > (), count++);  }
#line 601 "binary.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 80 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StringNode("String",yystack_[0].value.as< std::string > (), count++);  }
#line 607 "binary.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 81 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();              }
#line 613 "binary.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 82 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new PlusNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 621 "binary.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 85 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new MinusNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 629 "binary.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 88 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new MultNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 637 "binary.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 91 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new DivNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 645 "binary.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 94 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpoNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 653 "binary.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 97 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","INF", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 661 "binary.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 100 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","SUP", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 669 "binary.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 103 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","EQU", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 677 "binary.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 106 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","NEQU", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 685 "binary.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 109 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","INFEQ", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 693 "binary.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 112 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","SUPEQ", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 701 "binary.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 115 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","DBEQU", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 709 "binary.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 120 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();         }
#line 715 "binary.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 121 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();         }
#line 721 "binary.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 122 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[1].value.as< Node * > ();         }
#line 727 "binary.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 125 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("var",yystack_[0].value.as< std::string > (), count++);               }
#line 733 "binary.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 126 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[2].value.as< Node * > ();
                                  StdNode* tmp = new StdNode("dot",yystack_[0].value.as< std::string > (), count++);
                                  yylhs.value.as< Node * > ()->children.push_back(tmp);         }
#line 741 "binary.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 131 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("varlist","", count++); 
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 748 "binary.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 133 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[2].value.as< Node * > ();
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 755 "binary.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 137 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new FuncCallNode("functioncall", yystack_[1].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ()); 
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 763 "binary.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 142 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StringNode("String",yystack_[0].value.as< std::string > (), count++);}
#line 769 "binary.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 143 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ArgsNode("args", count++); 
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());         }
#line 776 "binary.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 147 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpListNode("explist", count++); 
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 783 "binary.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 149 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[2].value.as< Node * > ();
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 790 "binary.tab.cc" // lalr1.cc:859
    break;


#line 794 "binary.tab.cc" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -18;

  const signed char parser::yytable_ninf_ = -35;

  const signed char
  parser::yypact_[] =
  {
     114,    11,    11,   -18,   114,    16,   -18,   114,    35,   -18,
     -18,    56,    54,    71,   115,   -18,   -18,    60,    56,   -18,
     -18,   116,    36,    31,    37,   -18,   -18,   -18,    11,    46,
     -18,   -18,    59,    11,   -18,    11,    11,    11,    11,    11,
      11,    11,    11,    11,    11,    11,    11,    11,    11,    11,
      61,   -18,    95,    36,    10,    10,    10,    10,    10,    10,
      10,   -17,   -17,    38,    38,    38,   116,   116,    85,   -18,
      11,    -4,   114,    51,   -18
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,    12,     0,     0,    31,     6,     0,     2,
       3,     0,    28,     0,    10,    13,    14,     0,    15,    28,
      29,    38,    11,     0,     0,     4,     5,     1,     0,     0,
      36,    35,     0,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    28,     7,    21,    22,    23,    24,    25,    26,
      27,    16,    17,    18,    19,    20,    39,     8,     0,    37,
       0,     0,     0,     0,     9
  };

  const signed char
  parser::yypgoto_[] =
  {
     -18,   -18,    -1,    63,    87,     9,     0,     1,   -18,     2,
     -18,     3
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     7,     8,     9,    10,    21,    18,    19,    13,    20,
      31,    22
  };

  const signed char
  parser::yytable_[] =
  {
      11,    12,    14,    23,    11,    12,    14,    11,    12,    14,
      17,    72,    44,    45,    46,     1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    15,     6,
      16,    50,    11,    52,    24,    27,    53,    42,    43,    44,
      45,    46,    48,    47,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    49,
      28,   -33,    29,     1,    51,    34,    69,    74,    47,    46,
      25,    73,    11,    12,    14,    30,   -33,     6,    32,    71,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    70,    33,    26,     0,     0,     0,     0,     0,
       0,     0,   -34,     0,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,   -34,     1,     0,
       0,   -29,     2,     3,     4,     0,     5,     0,     0,     0,
       0,     0,     6,     0,   -29,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46
  };

  const signed char
  parser::yycheck_[] =
  {
       0,     0,     0,     4,     4,     4,     4,     7,     7,     7,
       1,    15,    29,    30,    31,     4,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    17,    18,
      19,    28,    32,    32,    18,     0,    33,    27,    28,    29,
      30,    31,    11,     7,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    22,
       4,     7,     6,     4,    18,     5,     5,    16,     7,    31,
       7,    72,    72,    72,    72,    19,    22,    18,     7,    70,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     7,    22,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     7,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    22,     4,    -1,
      -1,     6,     8,     9,    10,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    19,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     4,     8,     9,    10,    12,    18,    33,    34,    35,
      36,    38,    39,    40,    41,    17,    19,    37,    38,    39,
      41,    37,    43,    34,    18,    35,    36,     0,     4,     6,
      19,    42,     7,    22,     5,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     7,    11,    22,
      43,    18,    39,    43,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,     5,
       7,    37,    15,    34,    16
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    32,    33,    33,    33,    33,    34,    35,    35,    35,
      35,    36,    36,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    38,    38,
      38,    39,    39,    40,    40,    41,    42,    42,    43,    43
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     2,     1,     3,     4,     9,
       1,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       3,     1,     3,     1,     3,     2,     1,     3,     1,     3
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
  "SUPEQ", "DBEQU", "PLUS", "MINUS", "MULT", "DIV", "EXPO", "$accept",
  "chunk", "block", "stat", "laststat", "exp", "prefixexp", "var",
  "varlist", "functioncall", "args", "explist", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    40,    40,    42,    44,    46,    50,    55,    58,    61,
      68,    73,    75,    79,    80,    81,    82,    85,    88,    91,
      94,    97,   100,   103,   106,   109,   112,   115,   120,   121,
     122,   125,   126,   131,   133,   137,   142,   143,   147,   149
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
#line 1127 "binary.tab.cc" // lalr1.cc:1167
