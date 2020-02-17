%skeleton "lalr1.cc" 
%defines
%define api.value.type variant
%define api.token.constructor
%code requires{#include "node.h"}
%code{

  Node root;
  int count = 0;
  #include <string>
  
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;

}

%type <Node> chunck stat laststat block exp prefixexp var varlist functioncall args explist

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

chunck : stat                 {	$$ = Node("chunck","", count++);
                                $$.children.push_back($1);   }
       | laststat             {	$$ = Node("chunck","", count++);
                                $$.children.push_back($1);   }
       | chunck stat          {	$$ = $1;
                                $$.children.push_back($2);   }
       | chunck laststat      {	$$ = $1;
                                  $$.children.push_back($2); }
       ;

block : chunck {	$$ = Node("block","", count++);
                  $$.children.push_back($1);
                  root = $$;                 }
      ;

stat : varlist EQU explist    {	$$ = Node("stat","EQU", count++);
                                $$.children.push_back($1); 	
                                $$.children.push_back($3);  }
     | REPEAT block UNTIL exp {	$$ = Node("repeat","", count++);
                                $$.children.push_back($2); 	
                                $$.children.push_back($4);  }
     | functioncall           {	$$ = Node("stat","functioncall", count++);
                                $$.children.push_back($1);  }
     ;

laststat : RETURN explist     {	$$ = Node("laststat","RETURN", count++);
                                $$.children.push_back($2);      }
         | BREAK              {	$$ = Node("laststat","BREAK", count++);  }
         ;


exp : NUM             {	$$ = Node("num",$1, count++);  }
    | STRING          {	$$ = Node("String",$1, count++);  }
    | prefixexp       {	$$ = $1;              }
    | exp PLUS exp    {	$$ = Node("exp","PLUS", count++);
										    $$.children.push_back($1); 	
										    $$.children.push_back($3);  }
    | exp MINUS exp   {	$$ = Node("exp","MINUS", count++);
										    $$.children.push_back($1); 	
										    $$.children.push_back($3);  }
    | exp MULT exp    {	$$ = Node("exp","MULT", count++);
										    $$.children.push_back($1); 	
										    $$.children.push_back($3);  }
    | exp DIV exp     {	$$ = Node("exp","DIV", count++);
										    $$.children.push_back($1); 	
										    $$.children.push_back($3);  }
    | exp EXPO exp    {	$$ = Node("exp","EXPO", count++);
										    $$.children.push_back($1); 	
										    $$.children.push_back($3);  }
    | exp INF exp    {	$$ = Node("exp","INF", count++);
										    $$.children.push_back($1); 	
										    $$.children.push_back($3);  }
    | exp SUP exp   {	$$ = Node("exp","SUP", count++);
										    $$.children.push_back($1); 	
										    $$.children.push_back($3);  }
    | exp EQU exp    {	$$ = Node("exp","EQU", count++);
										    $$.children.push_back($1); 	
										    $$.children.push_back($3);  }
    | exp NEQU exp     {	$$ = Node("exp","NEQU", count++);
										    $$.children.push_back($1); 	
										    $$.children.push_back($3);  }
    | exp INFEQ exp    {	$$ = Node("exp","INFEQ", count++);
										    $$.children.push_back($1); 	
										    $$.children.push_back($3);  }
    | exp SUPEQ exp   {	$$ = Node("exp","SUPEQ", count++);
										    $$.children.push_back($1); 	
										    $$.children.push_back($3);  }
    | exp DBEQU exp   {	$$ = Node("exp","DBEQU", count++);
										    $$.children.push_back($1); 	
										    $$.children.push_back($3);  }
    ;

prefixexp : var                 {	$$ = Node("prefixexp","", count++);  
                                  $$.children.push_back($1);         }
          | functioncall        {	$$ = Node("prefixexp","", count++);  
                                  $$.children.push_back($1);         }
          | BROPEN exp BRCLOSE  {	$$ = Node("prefixexp","", count++);  
                                  $$.children.push_back($2);         }
          ;

var : NAME                      {	$$ = Node("var",$1, count++);               }
    | prefixexp DOT NAME        {	$$ = Node("dot",$3, count++);
                                  $$.children.push_back($1);         }
    ;

varlist : var                   {	$$ = Node("varlist","", count++); 
                                  $$.children.push_back($1);         }
        | varlist COMMA var     {	$$ = $1;
                                  $$.children.push_back($3);         }
        ;  

functioncall : prefixexp args   {	$$ = Node("functioncall","", count++);
                                  $$.children.push_back($1); 
                                  $$.children.push_back($2);         }
             ;

args : BROPEN explist BRCLOSE   {	$$ = Node("args","", count++); 
                                  $$.children.push_back($2);         }
     | STRING                   {	$$ = Node("String",$1, count++);              }
     ;

explist : exp                   {	$$ = Node("explist","", count++); 
                                  $$.children.push_back($1);         }
        | explist COMMA exp     {	$$ = $1;
                                  $$.children.push_back($3);         }
        ; 