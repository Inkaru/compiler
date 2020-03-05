%skeleton "lalr1.cc" 
%defines
%define api.value.type variant
%define api.token.constructor
%code requires{#include "node.h"}
%code{

  Node *root;
  int count = 0;
  #include <string>
  
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;

}

%type <Node *> chunk stat laststat block exp prefixexp var functioncall args tableconstructor field fieldlist funcname funcbody parlist

%type <VarListNode *> varlist
%type <ExpListNode *> explist

%token END 0
%token NEWL
%token BROPEN BRCLOSE
%token ACOPEN ACCLOSE
%token SQBROPEN SQBRCLOSE
%token DOT COMMA HASH
%token RETURN BREAK
%token REPEAT UNTIL
%token FOR IF THEN ELSE DO STEND
%token FUNCTION
%token FALSE TRUE
%token <std::string> NUM
%token <std::string> NAME
%token <std::string> STRING
%token EQU
%left INF SUP NEQU INFEQ SUPEQ DBEQU
%left PLUS MINUS
%left MULT DIV MOD
%right EXPO

%start block

%%

chunk : stat                 {	$$ = new StdNode("chunk","", count++);
                                $$->children.push_back($1);   }
       | laststat             {	$$ = new StdNode("chunk","", count++);
                                $$->children.push_back($1);   }
       | chunk stat          {	$$ = $1;
                                $$->children.push_back($2);   }
       | chunk laststat      {	$$ = $1;
                                $$->children.push_back($2); }
       ;

block : chunk {	  $$ = new StdNode("block","", count++);
                  $$->children.push_back($1);
                  root = $$;                 }
      ;


stat : varlist EQU explist    {	$$ = new AssignNode("stat", $1, $3, count++);
                                $$->children.push_back($1); 	
                                $$->children.push_back($3);  }
     | REPEAT block UNTIL exp {	$$ = new RepeatNode("repeat", $2,$4, count++);
                                $$->children.push_back($2); 	
                                $$->children.push_back($4);  }
     | DO block STEND         { $$ = new StdNode("stat","do", count++);
                                $$->children.push_back($2);
                              }
     | IF exp THEN block STEND { $$ = new IfNode("if", $2, $4, count++);
                                 $$->children.push_back($2);
                                 $$->children.push_back($4);
                                }
     | IF exp THEN block ELSE block STEND { $$ = new IfElseNode("ifelse", $2, $4, $6, count++);
                                 $$->children.push_back($2);
                                 $$->children.push_back($4);
                                 $$->children.push_back($6);
                                }
     | FOR NAME EQU exp COMMA exp DO block STEND {
                                VarNode* var = new VarNode("var", $2, count++);
                                $$ = new ForNode("For", var,$4,$6,$8, count++);
                                $$->children.push_back(var);
                                $$->children.push_back($4);
                                $$->children.push_back($6);
                                $$->children.push_back($8);
                              } 
     | functioncall           {	$$ = new StdNode("stat","functioncall", count++);
                                $$->children.push_back($1);  }
     | FUNCTION funcname funcbody { $$ = new FunctionNode("function", $2->getValue(), $3, count++);
                                    $$->children.push_back($2);
                                    $$->children.push_back($3); }
     ;


laststat : RETURN explist     {	$$ = new LastStatNode("laststat","RETURN", $2, count++);
                                $$->children.push_back($2);      }
         | BREAK              {	$$ = new LastStatNode("laststat","BREAK", nullptr, count++);  }
         ;


exp : NUM             {	$$ = new IntNode("num", $1, count++);  }
    | STRING          {	$$ = new StringNode("String",$1, count++);  }
    | prefixexp       {	$$ = $1;              }
    | tableconstructor{ $$ = $1;              }
    | FALSE           { $$ = new FalseNode(count++);  }
    | TRUE            { $$ = new TrueNode(count++);  }
    | exp PLUS exp    {	$$ = new PlusNode("exp", $1, $3, count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp MINUS exp   {	$$ = new MinusNode("exp", $1, $3, count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp MULT exp    {	$$ = new MultNode("exp", $1, $3, count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp DIV exp     {	$$ = new DivNode("exp", $1, $3, count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp MOD exp     {	$$ = new ModNode("exp", $1, $3, count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp EXPO exp    {	$$ = new ExpoNode("exp", $1, $3, count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp INF exp     {	$$ = new InfNode("exp", $1, $3, count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp SUP exp     {	$$ = new SupNode("exp", $1,$3, count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp DBEQU exp     {	$$ = new DbEquNode("exp", $1, $3, count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp NEQU exp    {	$$ = new NequNode("exp",$1, $3, count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp INFEQ exp   {	$$ = new InfEquNode("exp",$1, $3, count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp SUPEQ exp   {	$$ = new SupEquNode("exp",$1, $3, count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | MINUS exp       {	$$ = new NegNode("exp", $2, count++);
										    $$->children.push_back($2);   }
    | HASH exp        {	$$ = new HashNode("exp", $2, count++);
										    $$->children.push_back($2);  }
    ;

prefixexp : var                 {	$$ = $1;         }
          | functioncall        {	$$ = $1;         }
          | BROPEN exp BRCLOSE  {	$$ = $2;         }
          ;

var : NAME                      {	$$ = new VarNode("var",$1, count++);          }
    | prefixexp DOT NAME        {	string name = $1->getValue() + "." + $3;
                                  $$ = new StdNode("func",name,count++);        }
    | prefixexp SQBROPEN exp SQBRCLOSE {	$$ = new TabNode("var",$1,$3, count++);
                                          $$->children.push_back($1);
                                          $$->children.push_back($3);  }
    ;

varlist : var                   {	$$ = new VarListNode("varlist", count++); 
                                  $$->children.push_back($1);         }
        | varlist COMMA var     {	$$ = $1;
                                  $$->children.push_back($3);         }
        ;  

functioncall : prefixexp args   {	$$ = new FuncCallNode("functioncall", $1, $2, count++);
                                  $$->children.push_back($1); 
                                  $$->children.push_back($2);         }
             ;

args : STRING                   {	$$ = new StringNode("String",$1, count++);}
     | BROPEN explist BRCLOSE   {	$$ = new ArgsNode("args", count++); 
                                  $$->children.push_back($2);         }
     ;

explist : exp                   {	$$ = new ExpListNode("explist", count++); 
                                  $$->children.push_back($1);         }
        | explist COMMA exp     {	$$ = $1;
                                  $$->children.push_back($3);         }
        ; 

tableconstructor : ACOPEN ACCLOSE           { $$ = new TableConstructorNode("tableconstructor","empty", nullptr, count++);}
                 | ACOPEN fieldlist ACCLOSE { $$ = new TableConstructorNode("tableconstructor","", $2,count++);
                                              $$->children.push_back($2); }
                 ;

fieldlist : field                   {	$$ = new StdNode("fieldlist", "", count++); 
                                      $$->children.push_back($1);         }
          | fieldlist COMMA field   {	$$ = $1;
                                      $$->children.push_back($3);         }
          ;

field : exp {	$$ = $1 ;  }
      ;

funcname : NAME                   {	$$ = new StdNode("funcname", $1, count++);  }
         | NAME DOT funcname      {	$$ = new StdNode("funcname", $1, count++); 
                                    $$->children.push_back($3);         }
         ;

funcbody : BROPEN parlist BRCLOSE block STEND { $$ = new StdNode("funcbody","parlist", count++);
                                                $$->children.push_back($2);
                                                $$->children.push_back($4); }
         | BROPEN BRCLOSE block STEND { $$ = new StdNode("funcbody","empty", count++);
                                                $$->children.push_back($3); }
         ;

parlist : NAME                    {	$$ = new StdNode("namelist", "", count++); 
                                      $$->children.push_back(new StdNode("var",$1, count++));         }
        | parlist COMMA NAME      {	$$ = $1;
                                    $$->children.push_back(new StdNode("var",$3, count++));         }
        ;
