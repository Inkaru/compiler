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
  #include <string>
  
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;


#line 64 "binary.tab.cc" // lalr1.cc:413


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
#line 131 "binary.tab.cc" // lalr1.cc:479

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
      case 53: // explist
        value.move< ExpListNode * > (that.value);
        break;

      case 43: // chunk
      case 44: // block
      case 45: // stat
      case 46: // laststat
      case 47: // exp
      case 48: // prefixexp
      case 49: // var
      case 51: // functioncall
      case 52: // args
      case 54: // tableconstructor
      case 55: // fieldlist
      case 56: // field
      case 57: // funcname
      case 58: // funcbody
      case 59: // parlist
        value.move< Node * > (that.value);
        break;

      case 50: // varlist
        value.move< VarListNode * > (that.value);
        break;

      case 26: // NUM
      case 27: // NAME
      case 28: // STRING
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
      case 53: // explist
        value.copy< ExpListNode * > (that.value);
        break;

      case 43: // chunk
      case 44: // block
      case 45: // stat
      case 46: // laststat
      case 47: // exp
      case 48: // prefixexp
      case 49: // var
      case 51: // functioncall
      case 52: // args
      case 54: // tableconstructor
      case 55: // fieldlist
      case 56: // field
      case 57: // funcname
      case 58: // funcbody
      case 59: // parlist
        value.copy< Node * > (that.value);
        break;

      case 50: // varlist
        value.copy< VarListNode * > (that.value);
        break;

      case 26: // NUM
      case 27: // NAME
      case 28: // STRING
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
      case 53: // explist
        yylhs.value.build< ExpListNode * > ();
        break;

      case 43: // chunk
      case 44: // block
      case 45: // stat
      case 46: // laststat
      case 47: // exp
      case 48: // prefixexp
      case 49: // var
      case 51: // functioncall
      case 52: // args
      case 54: // tableconstructor
      case 55: // fieldlist
      case 56: // field
      case 57: // funcname
      case 58: // funcbody
      case 59: // parlist
        yylhs.value.build< Node * > ();
        break;

      case 50: // varlist
        yylhs.value.build< VarListNode * > ();
        break;

      case 26: // NUM
      case 27: // NAME
      case 28: // STRING
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
#line 46 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("chunk","", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());   }
#line 553 "binary.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 48 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("chunk","", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());   }
#line 560 "binary.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 50 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[1].value.as< Node * > ();
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());   }
#line 567 "binary.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 52 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[1].value.as< Node * > ();
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ()); }
#line 574 "binary.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 56 "binary.yy" // lalr1.cc:859
    {	  yylhs.value.as< Node * > () = new StdNode("block","", count++);
                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                  root = yylhs.value.as< Node * > ();                 }
#line 582 "binary.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 62 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new AssignNode("stat", yystack_[2].value.as< VarListNode * > (), yystack_[0].value.as< ExpListNode * > (), count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< VarListNode * > ()); 	
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< ExpListNode * > ());  }
#line 590 "binary.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 65 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("repeat","", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 598 "binary.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 68 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new StdNode("stat","do", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                              }
#line 606 "binary.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 71 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new IfNode("if", yystack_[3].value.as< Node * > (), yystack_[1].value.as< Node * > (), count++);
                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                }
#line 615 "binary.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 75 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new IfElseNode("ifelse", yystack_[5].value.as< Node * > (), yystack_[3].value.as< Node * > (), yystack_[1].value.as< Node * > (), count++);
                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[5].value.as< Node * > ());
                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                }
#line 625 "binary.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 80 "binary.yy" // lalr1.cc:859
    {
                                VarNode* var = new VarNode("var", yystack_[7].value.as< std::string > (), count++);
                                yylhs.value.as< Node * > () = new ForNode("For", var,yystack_[5].value.as< Node * > (),yystack_[3].value.as< Node * > (),yystack_[1].value.as< Node * > (), count++);
                                yylhs.value.as< Node * > ()->children.push_back(var);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[5].value.as< Node * > ());
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                              }
#line 638 "binary.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 88 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("stat","functioncall", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 645 "binary.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 90 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new FunctionNode("function", yystack_[1].value.as< Node * > ()->getValue(), yystack_[0].value.as< Node * > (), count++);
                                    yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ()); }
#line 653 "binary.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 96 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("laststat","RETURN", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< ExpListNode * > ());      }
#line 660 "binary.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 98 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("laststat","BREAK", count++);  }
#line 666 "binary.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 102 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new IntNode("num", yystack_[0].value.as< std::string > (), count++);  }
#line 672 "binary.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 103 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StringNode("String",yystack_[0].value.as< std::string > (), count++);  }
#line 678 "binary.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 104 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();              }
#line 684 "binary.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 105 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();              }
#line 690 "binary.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 106 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new FalseNode(count++);  }
#line 696 "binary.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 107 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new TrueNode(count++);  }
#line 702 "binary.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 108 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new PlusNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 710 "binary.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 111 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new MinusNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 718 "binary.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 114 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new MultNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 726 "binary.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 117 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new DivNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 734 "binary.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 120 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ModNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 742 "binary.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 123 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpoNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 750 "binary.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 126 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","INF", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 758 "binary.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 129 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","SUP", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 766 "binary.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 132 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new EquNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 774 "binary.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 135 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","NEQU", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 782 "binary.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 138 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","INFEQ", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 790 "binary.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 141 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","SUPEQ", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 798 "binary.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 144 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new NegNode("exp", yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());   }
#line 805 "binary.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 146 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","HASH", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 812 "binary.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 150 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();         }
#line 818 "binary.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 151 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();         }
#line 824 "binary.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 152 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[1].value.as< Node * > ();         }
#line 830 "binary.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 155 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new VarNode("var",yystack_[0].value.as< std::string > (), count++);          }
#line 836 "binary.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 156 "binary.yy" // lalr1.cc:859
    {	string name = yystack_[2].value.as< Node * > ()->getValue() + "." + yystack_[0].value.as< std::string > ();
                                  yylhs.value.as< Node * > () = new StdNode("func",name,count++);        }
#line 843 "binary.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 158 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("var","[]", count++);
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());  }
#line 851 "binary.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 163 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< VarListNode * > () = new VarListNode("varlist", count++); 
                                  yylhs.value.as< VarListNode * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 858 "binary.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 165 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< VarListNode * > () = yystack_[2].value.as< VarListNode * > ();
                                  yylhs.value.as< VarListNode * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 865 "binary.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 169 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new FuncCallNode("functioncall", yystack_[1].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ()); 
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 873 "binary.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 174 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StringNode("String",yystack_[0].value.as< std::string > (), count++);}
#line 879 "binary.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 175 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ArgsNode("args", count++); 
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< ExpListNode * > ());         }
#line 886 "binary.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 179 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< ExpListNode * > () = new ExpListNode("explist", count++); 
                                  yylhs.value.as< ExpListNode * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 893 "binary.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 181 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< ExpListNode * > () = yystack_[2].value.as< ExpListNode * > ();
                                  yylhs.value.as< ExpListNode * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 900 "binary.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 185 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new StdNode("tableconstructor","empty", count++);}
#line 906 "binary.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 186 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new StdNode("tableconstructor","", count++);
                                              yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ()); }
#line 913 "binary.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 190 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("fieldlist", "", count++); 
                                      yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 920 "binary.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 192 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[2].value.as< Node * > ();
                                      yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 927 "binary.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 196 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > () ;  }
#line 933 "binary.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 199 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("funcname", yystack_[0].value.as< std::string > (), count++);  }
#line 939 "binary.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 200 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("funcname", yystack_[2].value.as< std::string > (), count++); 
                                    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 946 "binary.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 204 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new StdNode("funcbody","parlist", count++);
                                                yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                                yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ()); }
#line 954 "binary.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 207 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new StdNode("funcbody","empty", count++);
                                                yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ()); }
#line 961 "binary.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 211 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("namelist", "", count++); 
                                      yylhs.value.as< Node * > ()->children.push_back(new StdNode("var",yystack_[0].value.as< std::string > (), count++));         }
#line 968 "binary.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 213 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[2].value.as< Node * > ();
                                    yylhs.value.as< Node * > ()->children.push_back(new StdNode("var",yystack_[0].value.as< std::string > (), count++));         }
#line 975 "binary.tab.cc" // lalr1.cc:859
    break;


#line 979 "binary.tab.cc" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -14;

  const signed char parser::yytable_ninf_ = -45;

  const short int
  parser::yypact_[] =
  {
     204,   144,   144,   -14,   204,   -13,   144,   204,   -12,   -14,
     204,    23,   -14,   -14,    17,    45,    46,    41,    36,   144,
     -14,   -14,   -14,   -14,   144,    -2,    17,   -14,   -14,   -14,
     238,    44,    51,    48,   205,    30,    55,    64,   -14,   -14,
     -14,   144,   144,    54,   -14,   -14,    14,   144,   -14,   238,
      43,   -14,   238,    53,   -14,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     204,   -14,   -12,    39,   -14,     8,   154,   -14,    47,    44,
     -14,   144,    49,    49,    49,    49,    49,    49,    53,    53,
      37,    37,    37,    37,   238,   238,   166,     4,   -14,   204,
     -14,    11,   -14,   -14,   -14,   144,   204,   -14,    58,   204,
      68,   226,    60,   -14,    76,   -14,   204,   -14,   -14,    81,
     -14
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,    16,     0,     0,     0,     0,     0,    40,
       6,     0,     2,     3,     0,    37,     0,    13,     0,     0,
      21,    22,    17,    18,     0,     0,    19,    37,    38,    20,
      48,    15,     0,     0,     0,     0,    55,     0,     4,     5,
       1,     0,     0,     0,    46,    45,     0,     0,    50,    54,
       0,    52,    36,    35,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,     0,     0,    14,     0,     0,    41,    37,     7,
      51,     0,    29,    30,    32,    33,    34,    31,    23,    24,
      25,    26,    27,    28,    49,     8,     0,     0,    56,     0,
      59,     0,    47,    42,    53,     0,     0,    10,     0,     0,
       0,     0,     0,    58,     0,    60,     0,    11,    57,     0,
      12
  };

  const signed char
  parser::yypgoto_[] =
  {
     -14,   -14,    13,    94,    95,    78,     0,     1,   -14,     2,
     -14,    12,   -14,   -14,    32,    42,   -14,   -14
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,    10,    11,    12,    13,    30,    26,    27,    16,    28,
      45,    31,    29,    50,    51,    37,    74,   101
  };

  const signed char
  parser::yytable_[] =
  {
      14,    15,    17,    54,    14,    15,    17,    14,    15,    17,
      14,    15,    17,   102,    33,    36,   109,    32,     1,    67,
      35,    41,   110,    40,   106,    42,   107,    43,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       1,     9,    18,    48,    99,    44,    14,    78,    19,   -38,
      80,   -38,    71,    75,    81,    67,   -43,    46,   -44,    79,
      20,    21,    22,     9,    23,    72,   100,    68,    73,   -38,
      14,    15,    17,    24,   -43,    47,   -44,    69,    66,    25,
     113,    77,   117,    97,    34,    61,    62,    63,    64,    65,
      66,    63,    64,    65,    66,   115,    49,    52,   118,    14,
      15,    17,    53,   120,    38,    39,    14,    15,    17,    14,
      15,    17,   108,   104,    98,     0,    14,    15,    17,   112,
      76,     0,   114,     0,     0,     0,     0,     0,     0,   119,
       0,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,     1,     0,
      18,     0,     0,     0,     0,     0,    19,     0,     0,    49,
       0,     0,     0,   103,     0,     0,     0,     0,    20,    21,
      22,     9,    23,     0,     0,     0,     0,   105,     0,     0,
       0,    24,     0,   111,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       0,     5,     6,     0,    70,     7,     0,     8,     0,     0,
       0,     9,     0,     0,     0,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,   116,     0,     0,
       0,     0,     0,     0,     0,     0,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66
  };

  const signed char
  parser::yycheck_[] =
  {
       0,     0,     0,     5,     4,     4,     4,     7,     7,     7,
      10,    10,    10,     5,    27,    27,     5,     4,     4,    11,
       7,     4,    11,     0,    20,     8,    22,    10,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       4,    27,     6,     7,     5,    28,    46,    46,    12,     8,
       7,    10,    22,    41,    11,    11,    11,    11,    11,    47,
      24,    25,    26,    27,    28,    10,    27,    16,     4,    28,
      70,    70,    70,    37,    29,    29,    29,    29,    41,     1,
      22,    27,    22,    70,     6,    36,    37,    38,    39,    40,
      41,    38,    39,    40,    41,    27,    18,    19,    22,    99,
      99,    99,    24,    22,    10,    10,   106,   106,   106,   109,
     109,   109,    99,    81,    72,    -1,   116,   116,   116,   106,
      42,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     4,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    81,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    11,    -1,    -1,
      -1,    37,    -1,   105,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,
      -1,    17,    18,    -1,    19,    21,    -1,    23,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     4,    13,    14,    15,    17,    18,    21,    23,    27,
      43,    44,    45,    46,    48,    49,    50,    51,     6,    12,
      24,    25,    26,    28,    37,    47,    48,    49,    51,    54,
      47,    53,    44,    27,    47,    44,    27,    57,    45,    46,
       0,     4,     8,    10,    28,    52,    11,    29,     7,    47,
      55,    56,    47,    47,     5,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    11,    16,    29,
      19,    22,    10,     4,    58,    53,    47,    27,    49,    53,
       7,    11,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    44,    57,     5,
      27,    59,     5,     9,    56,    11,    20,    22,    44,     5,
      11,    47,    44,    22,    44,    27,    21,    22,    22,    44,
      22
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    42,    43,    43,    43,    43,    44,    45,    45,    45,
      45,    45,    45,    45,    45,    46,    46,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    48,    48,    48,
      49,    49,    49,    50,    50,    51,    52,    52,    53,    53,
      54,    54,    55,    55,    56,    57,    57,    58,    58,    59,
      59
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     2,     1,     3,     4,     3,
       5,     7,     9,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     1,     1,     3,
       1,     3,     4,     1,     3,     2,     1,     3,     1,     3,
       2,     3,     1,     3,     1,     1,     3,     5,     4,     1,
       3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "END", "error", "$undefined", "NEWL", "BROPEN", "BRCLOSE", "ACOPEN",
  "ACCLOSE", "SQBROPEN", "SQBRCLOSE", "DOT", "COMMA", "HASH", "RETURN",
  "BREAK", "REPEAT", "UNTIL", "FOR", "IF", "THEN", "ELSE", "DO", "STEND",
  "FUNCTION", "FALSE", "TRUE", "NUM", "NAME", "STRING", "EQU", "INF",
  "SUP", "NEQU", "INFEQ", "SUPEQ", "DBEQU", "PLUS", "MINUS", "MULT", "DIV",
  "MOD", "EXPO", "$accept", "chunk", "block", "stat", "laststat", "exp",
  "prefixexp", "var", "varlist", "functioncall", "args", "explist",
  "tableconstructor", "fieldlist", "field", "funcname", "funcbody",
  "parlist", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    46,    46,    48,    50,    52,    56,    62,    65,    68,
      71,    75,    80,    88,    90,    96,    98,   102,   103,   104,
     105,   106,   107,   108,   111,   114,   117,   120,   123,   126,
     129,   132,   135,   138,   141,   144,   146,   150,   151,   152,
     155,   156,   158,   163,   165,   169,   174,   175,   179,   181,
     185,   186,   190,   192,   196,   199,   200,   204,   207,   211,
     213
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
#line 1365 "binary.tab.cc" // lalr1.cc:1167
