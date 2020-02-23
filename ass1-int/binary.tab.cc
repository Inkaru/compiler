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
      case 39: // chunk
      case 40: // block
      case 41: // stat
      case 42: // laststat
      case 43: // exp
      case 44: // prefixexp
      case 45: // var
      case 46: // varlist
      case 47: // functioncall
      case 48: // args
      case 49: // explist
      case 50: // tableconstructor
      case 51: // fieldlist
      case 52: // field
        value.move< Node * > (that.value);
        break;

      case 22: // NUM
      case 23: // NAME
      case 24: // STRING
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
      case 39: // chunk
      case 40: // block
      case 41: // stat
      case 42: // laststat
      case 43: // exp
      case 44: // prefixexp
      case 45: // var
      case 46: // varlist
      case 47: // functioncall
      case 48: // args
      case 49: // explist
      case 50: // tableconstructor
      case 51: // fieldlist
      case 52: // field
        value.copy< Node * > (that.value);
        break;

      case 22: // NUM
      case 23: // NAME
      case 24: // STRING
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
      case 39: // chunk
      case 40: // block
      case 41: // stat
      case 42: // laststat
      case 43: // exp
      case 44: // prefixexp
      case 45: // var
      case 46: // varlist
      case 47: // functioncall
      case 48: // args
      case 49: // explist
      case 50: // tableconstructor
      case 51: // fieldlist
      case 52: // field
        yylhs.value.build< Node * > ();
        break;

      case 22: // NUM
      case 23: // NAME
      case 24: // STRING
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
#line 42 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("chunk","", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());   }
#line 527 "binary.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 44 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("chunk","", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());   }
#line 534 "binary.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 46 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[1].value.as< Node * > ();
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());   }
#line 541 "binary.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 48 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[1].value.as< Node * > ();
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ()); }
#line 548 "binary.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 52 "binary.yy" // lalr1.cc:859
    {	  yylhs.value.as< Node * > () = new StdNode("block","", count++);
                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                  root = yylhs.value.as< Node * > ();                 }
#line 556 "binary.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 58 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("stat","EQU", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 564 "binary.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 61 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("repeat","", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 572 "binary.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 64 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new StdNode("stat","do", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                              }
#line 580 "binary.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 67 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new StdNode("stat","if", count++);
                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                }
#line 589 "binary.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 71 "binary.yy" // lalr1.cc:859
    {
                                yylhs.value.as< Node * > () = new StdNode("stat","for", count++);
                                yylhs.value.as< Node * > ()->children.push_back(new StdNode("var", yystack_[7].value.as< std::string > (), count++));
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[5].value.as< Node * > ());
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                              }
#line 601 "binary.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 78 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("stat","functioncall", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 608 "binary.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 83 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("laststat","RETURN", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());      }
#line 615 "binary.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 85 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("laststat","BREAK", count++);  }
#line 621 "binary.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 89 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new IntNode("num", yystack_[0].value.as< std::string > (), count++);  }
#line 627 "binary.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 90 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StringNode("String",yystack_[0].value.as< std::string > (), count++);  }
#line 633 "binary.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 91 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();              }
#line 639 "binary.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 92 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();              }
#line 645 "binary.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 93 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new PlusNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 653 "binary.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 96 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new MinusNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 661 "binary.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 99 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new MultNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 669 "binary.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 102 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new DivNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 677 "binary.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 105 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ModNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 685 "binary.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 108 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpoNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 693 "binary.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 111 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","INF", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 701 "binary.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 114 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","SUP", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 709 "binary.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 117 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","EQU", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 717 "binary.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 120 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","NEQU", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 725 "binary.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 123 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","INFEQ", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 733 "binary.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 126 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","SUPEQ", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 741 "binary.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 129 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","DBEQU", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 749 "binary.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 132 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","NEG", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());   }
#line 756 "binary.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 134 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","HASH", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 763 "binary.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 138 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();         }
#line 769 "binary.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 139 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();         }
#line 775 "binary.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 140 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[1].value.as< Node * > ();         }
#line 781 "binary.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 143 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("var",yystack_[0].value.as< std::string > (), count++);          }
#line 787 "binary.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 144 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[2].value.as< Node * > ();
                                  StdNode* tmp = new StdNode("dot",yystack_[0].value.as< std::string > (), count++);
                                  yylhs.value.as< Node * > ()->children.push_back(tmp);         }
#line 795 "binary.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 147 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("var","[]", count++);
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());  }
#line 803 "binary.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 152 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("varlist","", count++); 
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 810 "binary.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 154 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[2].value.as< Node * > ();
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 817 "binary.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 158 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new FuncCallNode("functioncall", yystack_[1].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ()); 
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 825 "binary.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 163 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StringNode("String",yystack_[0].value.as< std::string > (), count++);}
#line 831 "binary.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 164 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ArgsNode("args", count++); 
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());         }
#line 838 "binary.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 168 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpListNode("explist", count++); 
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 845 "binary.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 170 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[2].value.as< Node * > ();
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 852 "binary.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 174 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new StdNode("tableconstructor","empty", count++);}
#line 858 "binary.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 175 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new StdNode("tableconstructor","", count++);
                                              yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ()); }
#line 865 "binary.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 179 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("fieldlist", "", count++); 
                                      yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 872 "binary.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 181 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[2].value.as< Node * > ();
                                      yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 879 "binary.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 185 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > () ;  }
#line 885 "binary.tab.cc" // lalr1.cc:859
    break;


#line 889 "binary.tab.cc" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -22;

  const signed char parser::yytable_ninf_ = -42;

  const short int
  parser::yypact_[] =
  {
     148,    91,    91,   -22,   148,   -21,    91,   148,   -22,   148,
       3,   -22,   -22,    96,     6,    13,     4,    15,    91,   -22,
     -22,    91,    25,    96,   -22,   -22,   -22,   181,    12,    19,
      16,   150,    23,   -22,   -22,   -22,    91,    91,    51,   -22,
     -22,     2,    91,   -22,   181,    57,   -22,   181,    36,   -22,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,   148,   -22,    21,   101,
     -22,    20,    12,   -22,    91,   121,   121,   121,   121,   121,
     121,   121,    36,    36,    -1,    -1,    -1,    -1,   181,   181,
     114,    55,   -22,   -22,   -22,    91,   -22,   168,   148,    73,
     -22
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,    14,     0,     0,     0,     0,    37,     6,
       0,     2,     3,     0,    34,     0,    12,     0,     0,    15,
      16,     0,     0,    17,    34,    35,    18,    45,    13,     0,
       0,     0,     0,     4,     5,     1,     0,     0,     0,    43,
      42,     0,     0,    47,    51,     0,    49,    33,    32,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,     0,     0,
      38,    34,     7,    48,     0,    25,    26,    27,    28,    29,
      30,    31,    19,    20,    21,    22,    23,    24,    46,     8,
       0,     0,    44,    39,    50,     0,    10,     0,     0,     0,
      11
  };

  const signed char
  parser::yypgoto_[] =
  {
     -22,   -22,     9,    87,    92,    28,     0,     1,   -22,    11,
     -22,    27,   -22,   -22,    31
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     9,    10,    11,    12,    27,    23,    24,    15,    25,
      40,    28,    26,    45,    46
  };

  const signed char
  parser::yytable_[] =
  {
      13,    14,    30,    35,    13,    14,     1,    13,    14,    13,
      14,    16,   -35,    29,   -35,    16,    32,   -40,    16,     1,
      16,    17,    43,    63,    41,     8,    92,    18,   -35,    22,
      49,   -41,    63,   -40,    31,    64,    62,    19,     8,    20,
      42,    13,    71,    65,    67,    44,    47,   -41,    21,    48,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    68,    73,    69,    13,    14,    74,    72,
      59,    60,    61,    62,    70,    91,    96,    16,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,   100,     1,    33,    17,    13,    14,
      36,    34,    44,    18,    37,    94,    38,    99,     0,    16,
      93,     0,     0,    19,     8,    20,     0,     0,     0,     0,
      39,     0,     0,    97,    21,    95,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     1,    57,    58,    59,    60,    61,    62,     0,
       0,     2,     3,     4,     0,     5,     6,     0,     7,    66,
       0,     8,     0,     0,     0,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    98,     0,
       0,     0,     0,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62
  };

  const signed char
  parser::yycheck_[] =
  {
       0,     0,    23,     0,     4,     4,     4,     7,     7,     9,
       9,     0,     8,     4,    10,     4,     7,    11,     7,     4,
       9,     6,     7,    11,    11,    23,     5,    12,    24,     1,
       5,    11,    11,    27,     6,    16,    37,    22,    23,    24,
      27,    41,    41,    27,    21,    17,    18,    27,    33,    21,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    36,     7,    37,    66,    66,    11,    42,
      34,    35,    36,    37,    23,    66,    21,    66,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    21,     4,     9,     6,    98,    98,
       4,     9,    74,    12,     8,    74,    10,    98,    -1,    98,
       9,    -1,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    95,    33,    11,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,     4,    32,    33,    34,    35,    36,    37,    -1,
      -1,    13,    14,    15,    -1,    17,    18,    -1,    20,    19,
      -1,    23,    -1,    -1,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    20,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     4,    13,    14,    15,    17,    18,    20,    23,    39,
      40,    41,    42,    44,    45,    46,    47,     6,    12,    22,
      24,    33,    43,    44,    45,    47,    50,    43,    49,    40,
      23,    43,    40,    41,    42,     0,     4,     8,    10,    24,
      48,    11,    27,     7,    43,    51,    52,    43,    43,     5,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    11,    16,    27,    19,    21,    49,    43,
      23,    45,    49,     7,    11,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    40,     5,     9,    52,    11,    21,    43,    20,    40,
      21
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    38,    39,    39,    39,    39,    40,    41,    41,    41,
      41,    41,    41,    42,    42,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    44,    44,    44,    45,    45,    45,
      46,    46,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    52
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     2,     1,     3,     4,     3,
       5,     9,     1,     2,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     1,     3,     1,     3,     4,
       1,     3,     2,     1,     3,     1,     3,     2,     3,     1,
       3,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "END", "error", "$undefined", "NEWL", "BROPEN", "BRCLOSE", "ACOPEN",
  "ACCLOSE", "SQBROPEN", "SQBRCLOSE", "DOT", "COMMA", "HASH", "RETURN",
  "BREAK", "REPEAT", "UNTIL", "FOR", "IF", "THEN", "DO", "STEND", "NUM",
  "NAME", "STRING", "INF", "SUP", "EQU", "NEQU", "INFEQ", "SUPEQ", "DBEQU",
  "PLUS", "MINUS", "MULT", "DIV", "MOD", "EXPO", "$accept", "chunk",
  "block", "stat", "laststat", "exp", "prefixexp", "var", "varlist",
  "functioncall", "args", "explist", "tableconstructor", "fieldlist",
  "field", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    42,    42,    44,    46,    48,    52,    58,    61,    64,
      67,    71,    78,    83,    85,    89,    90,    91,    92,    93,
      96,    99,   102,   105,   108,   111,   114,   117,   120,   123,
     126,   129,   132,   134,   138,   139,   140,   143,   144,   147,
     152,   154,   158,   163,   164,   168,   170,   174,   175,   179,
     181,   185
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
#line 1253 "binary.tab.cc" // lalr1.cc:1167
