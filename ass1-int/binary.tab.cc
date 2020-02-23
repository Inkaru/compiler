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
      case 52: // explist
        value.move< ExpListNode * > (that.value);
        break;

      case 42: // chunk
      case 43: // block
      case 44: // stat
      case 45: // laststat
      case 46: // exp
      case 47: // prefixexp
      case 48: // var
      case 50: // functioncall
      case 51: // args
      case 53: // tableconstructor
      case 54: // fieldlist
      case 55: // field
      case 56: // funcname
      case 57: // funcbody
      case 58: // parlist
        value.move< Node * > (that.value);
        break;

      case 49: // varlist
        value.move< VarListNode * > (that.value);
        break;

      case 25: // NUM
      case 26: // NAME
      case 27: // STRING
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
      case 52: // explist
        value.copy< ExpListNode * > (that.value);
        break;

      case 42: // chunk
      case 43: // block
      case 44: // stat
      case 45: // laststat
      case 46: // exp
      case 47: // prefixexp
      case 48: // var
      case 50: // functioncall
      case 51: // args
      case 53: // tableconstructor
      case 54: // fieldlist
      case 55: // field
      case 56: // funcname
      case 57: // funcbody
      case 58: // parlist
        value.copy< Node * > (that.value);
        break;

      case 49: // varlist
        value.copy< VarListNode * > (that.value);
        break;

      case 25: // NUM
      case 26: // NAME
      case 27: // STRING
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
      case 52: // explist
        yylhs.value.build< ExpListNode * > ();
        break;

      case 42: // chunk
      case 43: // block
      case 44: // stat
      case 45: // laststat
      case 46: // exp
      case 47: // prefixexp
      case 48: // var
      case 50: // functioncall
      case 51: // args
      case 53: // tableconstructor
      case 54: // fieldlist
      case 55: // field
      case 56: // funcname
      case 57: // funcbody
      case 58: // parlist
        yylhs.value.build< Node * > ();
        break;

      case 49: // varlist
        yylhs.value.build< VarListNode * > ();
        break;

      case 25: // NUM
      case 26: // NAME
      case 27: // STRING
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
    { yylhs.value.as< Node * > () = new StdNode("stat","if", count++);
                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                }
#line 615 "binary.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 75 "binary.yy" // lalr1.cc:859
    {
                                yylhs.value.as< Node * > () = new StdNode("stat","for", count++);
                                yylhs.value.as< Node * > ()->children.push_back(new StdNode("var", yystack_[7].value.as< std::string > (), count++));
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[5].value.as< Node * > ());
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                              }
#line 627 "binary.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 82 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("stat","functioncall", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 634 "binary.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 84 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new StdNode("function", "", count++);
                                    yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ()); }
#line 642 "binary.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 90 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("laststat","RETURN", count++);
                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< ExpListNode * > ());      }
#line 649 "binary.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 92 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("laststat","BREAK", count++);  }
#line 655 "binary.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 96 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new IntNode("num", yystack_[0].value.as< std::string > (), count++);  }
#line 661 "binary.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 97 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StringNode("String",yystack_[0].value.as< std::string > (), count++);  }
#line 667 "binary.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 98 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();              }
#line 673 "binary.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 99 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();              }
#line 679 "binary.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 100 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new FalseNode(count++);  }
#line 685 "binary.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 101 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new TrueNode(count++);  }
#line 691 "binary.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 102 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new PlusNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 699 "binary.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 105 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new MinusNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 707 "binary.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 108 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new MultNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 715 "binary.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 111 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new DivNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 723 "binary.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 114 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ModNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 731 "binary.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 117 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpoNode("exp", yystack_[2].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 739 "binary.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 120 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","INF", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 747 "binary.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 123 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","SUP", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 755 "binary.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 126 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","EQU", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 763 "binary.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 129 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","NEQU", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 771 "binary.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 132 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","INFEQ", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 779 "binary.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 135 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","SUPEQ", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 787 "binary.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 138 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","DBEQU", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ()); 	
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 795 "binary.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 141 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new NegNode("exp", yystack_[0].value.as< Node * > (), count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());   }
#line 802 "binary.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 143 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ExpNodeImpl("exp","HASH", count++);
										    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());  }
#line 809 "binary.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 147 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();         }
#line 815 "binary.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 148 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();         }
#line 821 "binary.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 149 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[1].value.as< Node * > ();         }
#line 827 "binary.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 152 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new VarNode("var",yystack_[0].value.as< std::string > (), count++);          }
#line 833 "binary.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 153 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[2].value.as< Node * > ();
                                  StdNode* tmp = new StdNode("dot",yystack_[0].value.as< std::string > (), count++);
                                  yylhs.value.as< Node * > ()->children.push_back(tmp);         }
#line 841 "binary.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 156 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("var","[]", count++);
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());  }
#line 849 "binary.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 161 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< VarListNode * > () = new VarListNode("varlist", count++); 
                                  yylhs.value.as< VarListNode * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 856 "binary.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 163 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< VarListNode * > () = yystack_[2].value.as< VarListNode * > ();
                                  yylhs.value.as< VarListNode * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 863 "binary.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 167 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new FuncCallNode("functioncall", yystack_[1].value.as< Node * > (), yystack_[0].value.as< Node * > (), count++);
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ()); 
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 871 "binary.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 172 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StringNode("String",yystack_[0].value.as< std::string > (), count++);}
#line 877 "binary.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 173 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new ArgsNode("args", count++); 
                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< ExpListNode * > ());         }
#line 884 "binary.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 177 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< ExpListNode * > () = new ExpListNode("explist", count++); 
                                  yylhs.value.as< ExpListNode * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 891 "binary.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 179 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< ExpListNode * > () = yystack_[2].value.as< ExpListNode * > ();
                                  yylhs.value.as< ExpListNode * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 898 "binary.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 183 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new StdNode("tableconstructor","empty", count++);}
#line 904 "binary.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 184 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new StdNode("tableconstructor","", count++);
                                              yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ()); }
#line 911 "binary.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 188 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("fieldlist", "", count++); 
                                      yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 918 "binary.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 190 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[2].value.as< Node * > ();
                                      yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 925 "binary.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 194 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > () ;  }
#line 931 "binary.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 197 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("funcname", yystack_[0].value.as< std::string > (), count++);  }
#line 937 "binary.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 198 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("funcname", yystack_[2].value.as< std::string > (), count++); 
                                    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());         }
#line 944 "binary.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 202 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new StdNode("funcbody","parlist", count++);
                                                yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                                yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ()); }
#line 952 "binary.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 205 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node * > () = new StdNode("funcbody","empty", count++);
                                                yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ()); }
#line 959 "binary.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 209 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = new StdNode("namelist", "", count++); 
                                      yylhs.value.as< Node * > ()->children.push_back(new StdNode("var",yystack_[0].value.as< std::string > (), count++));         }
#line 966 "binary.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 211 "binary.yy" // lalr1.cc:859
    {	yylhs.value.as< Node * > () = yystack_[2].value.as< Node * > ();
                                    yylhs.value.as< Node * > ()->children.push_back(new StdNode("var",yystack_[0].value.as< std::string > (), count++));         }
#line 973 "binary.tab.cc" // lalr1.cc:859
    break;


#line 977 "binary.tab.cc" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -24;

  const signed char parser::yytable_ninf_ = -45;

  const short int
  parser::yypact_[] =
  {
      71,    54,    54,   -24,    71,   -13,    54,    71,   -12,   -24,
      71,    22,   -24,   -24,    13,    46,    84,    41,    38,    54,
     -24,   -24,   -24,   -24,    54,    -2,    13,   -24,   -24,   -24,
     229,     4,     9,    24,   195,    31,    45,    52,   -24,   -24,
     -24,    54,    54,    43,   -24,   -24,    44,    54,   -24,   229,
      32,   -24,   229,    69,   -24,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    71,   -24,   -12,    15,   -24,    48,   143,   -24,    85,
       4,   -24,    54,    94,    94,    94,    94,    94,    94,    94,
      69,    69,    27,    27,    27,    27,   229,   229,   173,    73,
     -24,    71,   -24,    87,   -24,   -24,   -24,    54,   -24,    83,
      71,    93,   216,   -24,    99,   -24,    71,   -24,   100,   -24
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,    15,     0,     0,     0,     0,     0,    40,
       6,     0,     2,     3,     0,    37,     0,    12,     0,     0,
      20,    21,    16,    17,     0,     0,    18,    37,    38,    19,
      48,    14,     0,     0,     0,     0,    55,     0,     4,     5,
       1,     0,     0,     0,    46,    45,     0,     0,    50,    54,
       0,    52,    36,    35,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     0,     0,    13,     0,     0,    41,    37,
       7,    51,     0,    28,    29,    30,    31,    32,    33,    34,
      22,    23,    24,    25,    26,    27,    49,     8,     0,     0,
      56,     0,    59,     0,    47,    42,    53,     0,    10,     0,
       0,     0,     0,    58,     0,    60,     0,    57,     0,    11
  };

  const signed char
  parser::yypgoto_[] =
  {
     -24,   -24,    12,   114,   115,    81,     0,     1,   -24,     2,
     -24,   -23,   -24,   -24,    53,    80,   -24,   -24
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,    10,    11,    12,    13,    30,    26,    27,    16,    28,
      45,    31,    29,    50,    51,    37,    75,   103
  };

  const signed char
  parser::yytable_[] =
  {
      14,    15,    17,    54,    14,    15,    17,    14,    15,    17,
      14,    15,    17,    33,    36,    68,    32,    41,    76,    35,
     101,    42,    40,    43,    80,    69,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    81,
      44,   102,     1,    82,    18,    48,    14,    79,     1,   -38,
      19,   -38,    72,   104,    70,    73,    74,   -43,     1,    68,
      18,    20,    21,    22,     9,    23,    19,    67,   -38,    78,
       9,    14,    15,    17,    24,     1,   -43,    20,    21,    22,
       9,    23,    25,    99,     2,     3,     4,    34,     5,     6,
      24,     7,   110,     8,   108,    46,   -44,     9,   111,    49,
      52,    14,    15,    17,   113,    53,    64,    65,    66,    67,
      14,    15,    17,   109,    47,   -44,    14,    15,    17,   115,
     117,   119,   114,    77,    38,    39,     0,     0,   118,    62,
      63,    64,    65,    66,    67,   106,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,   105,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,     0,     0,     0,     0,
       0,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,   107,     0,     0,     0,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    71,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,   116,     0,     0,     0,
       0,     0,     0,     0,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67
  };

  const signed char
  parser::yycheck_[] =
  {
       0,     0,     0,     5,     4,     4,     4,     7,     7,     7,
      10,    10,    10,    26,    26,    11,     4,     4,    41,     7,
       5,     8,     0,    10,    47,    16,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     7,
      27,    26,     4,    11,     6,     7,    46,    46,     4,     8,
      12,    10,    21,     5,    30,    10,     4,    11,     4,    11,
       6,    23,    24,    25,    26,    27,    12,    40,    27,    26,
      26,    71,    71,    71,    36,     4,    30,    23,    24,    25,
      26,    27,     1,    71,    13,    14,    15,     6,    17,    18,
      36,    20,     5,    22,    21,    11,    11,    26,    11,    18,
      19,   101,   101,   101,    21,    24,    37,    38,    39,    40,
     110,   110,   110,   101,    30,    30,   116,   116,   116,    26,
      21,    21,   110,    42,    10,    10,    -1,    -1,   116,    35,
      36,    37,    38,    39,    40,    82,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     9,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    11,    -1,    -1,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     4,    13,    14,    15,    17,    18,    20,    22,    26,
      42,    43,    44,    45,    47,    48,    49,    50,     6,    12,
      23,    24,    25,    27,    36,    46,    47,    48,    50,    53,
      46,    52,    43,    26,    46,    43,    26,    56,    44,    45,
       0,     4,     8,    10,    27,    51,    11,    30,     7,    46,
      54,    55,    46,    46,     5,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    11,    16,
      30,    19,    21,    10,     4,    57,    52,    46,    26,    48,
      52,     7,    11,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    43,
      56,     5,    26,    58,     5,     9,    55,    11,    21,    43,
       5,    11,    46,    21,    43,    26,    20,    21,    43,    21
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    41,    42,    42,    42,    42,    43,    44,    44,    44,
      44,    44,    44,    44,    45,    45,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    47,    47,    47,
      48,    48,    48,    49,    49,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    56,    56,    57,    57,    58,
      58
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     2,     1,     3,     4,     3,
       5,     9,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
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
  "BREAK", "REPEAT", "UNTIL", "FOR", "IF", "THEN", "DO", "STEND",
  "FUNCTION", "FALSE", "TRUE", "NUM", "NAME", "STRING", "INF", "SUP",
  "EQU", "NEQU", "INFEQ", "SUPEQ", "DBEQU", "PLUS", "MINUS", "MULT", "DIV",
  "MOD", "EXPO", "$accept", "chunk", "block", "stat", "laststat", "exp",
  "prefixexp", "var", "varlist", "functioncall", "args", "explist",
  "tableconstructor", "fieldlist", "field", "funcname", "funcbody",
  "parlist", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    46,    46,    48,    50,    52,    56,    62,    65,    68,
      71,    75,    82,    84,    90,    92,    96,    97,    98,    99,
     100,   101,   102,   105,   108,   111,   114,   117,   120,   123,
     126,   129,   132,   135,   138,   141,   143,   147,   148,   149,
     152,   153,   156,   161,   163,   167,   172,   173,   177,   179,
     183,   184,   188,   190,   194,   197,   198,   202,   205,   209,
     211
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
#line 1358 "binary.tab.cc" // lalr1.cc:1167
