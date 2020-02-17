%skeleton "lalr1.cc" 
%defines
%define api.value.type variant
%define api.token.constructor
%code requires{#include "node.h"}
%code{

  Node *root;
  int count = 0;
  int init = 0;
  #include <string>
  
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;

}

%type <Node *> chunk stat laststat block exp prefixexp var varlist functioncall args explist

%token END 0
%token NEWL
%token BROPEN BRCLOSE
%token DOT COMMA
%token RETURN BREAK
%token REPEAT UNTIL
%token <std::string> NUM
%token <std::string> NAME
%token <std::string> STRING

%left INF SUP EQU NEQU INFEQ SUPEQ DBEQU
%left PLUS MINUS
%left MULT DIV
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

stat : varlist EQU explist    {	$$ = new StdNode("stat","EQU", count++);
                                $$->children.push_back($1); 	
                                $$->children.push_back($3);  }
     | REPEAT block UNTIL exp {	$$ = new StdNode("repeat","", count++);
                                $$->children.push_back($2); 	
                                $$->children.push_back($4);  }
     | functioncall           {	$$ = new StdNode("stat","functioncall", count++);
                                $$->children.push_back($1);  }
     ;

laststat : RETURN explist     {	$$ = new StdNode("laststat","RETURN", count++);
                                $$->children.push_back($2);      }
         | BREAK              {	$$ = new StdNode("laststat","BREAK", count++);  }
         ;


exp : NUM             {	$$ = new IntNode("num", $1, count++);  }
    | STRING          {	$$ = new StdNode("String",$1, count++);  }
    | prefixexp       {	$$ = $1;              }
    | exp PLUS exp    {	$$ = new PlusNode("exp", $1, $3, count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp MINUS exp   {	$$ = new StdNode("exp","MINUS", count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp MULT exp    {	$$ = new StdNode("exp","MULT", count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp DIV exp     {	$$ = new StdNode("exp","DIV", count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp EXPO exp    {	$$ = new StdNode("exp","EXPO", count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp INF exp     {	$$ = new StdNode("exp","INF", count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp SUP exp     {	$$ = new StdNode("exp","SUP", count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp EQU exp     {	$$ = new StdNode("exp","EQU", count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp NEQU exp    {	$$ = new StdNode("exp","NEQU", count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp INFEQ exp   {	$$ = new StdNode("exp","INFEQ", count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp SUPEQ exp   {	$$ = new StdNode("exp","SUPEQ", count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    | exp DBEQU exp   {	$$ = new StdNode("exp","DBEQU", count++);
										    $$->children.push_back($1); 	
										    $$->children.push_back($3);  }
    ;

prefixexp : var                 {	$$ = new StdNode("prefixexp","", count++);  
                                  $$->children.push_back($1);         }
          | functioncall        {	$$ = new StdNode("prefixexp","", count++);  
                                  $$->children.push_back($1);         }
          | BROPEN exp BRCLOSE  {	$$ = new StdNode("prefixexp","", count++);  
                                  $$->children.push_back($2);         }
          ;

var : NAME                      {	$$ = new StdNode("var",$1, count++);               }
    | prefixexp DOT NAME        {	$$ = new StdNode("dot",$3, count++);
                                  $$->children.push_back($1);         }
    ;

varlist : var                   {	$$ = new StdNode("varlist","", count++); 
                                  $$->children.push_back($1);         }
        | varlist COMMA var     {	$$ = $1;
                                  $$->children.push_back($3);         }
        ;  

functioncall : prefixexp args   {	$$ = new StdNode("functioncall","", count++);
                                  $$->children.push_back($1); 
                                  $$->children.push_back($2);         }
             ;

args : BROPEN explist BRCLOSE   {	$$ = new StdNode("args","", count++); 
                                  $$->children.push_back($2);         }
     | STRING                   {	$$ = new StdNode("String",$1, count++);              }
     ;

explist : exp                   {	$$ = new StdNode("explist","", count++); 
                                  $$->children.push_back($1);         }
        | explist COMMA exp     {	$$ = $1;
                                  $$->children.push_back($3);         }
        ; 