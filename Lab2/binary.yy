%skeleton "lalr1.cc" 
%defines
%define api.value.type variant
%define api.token.constructor
%code requires{#include "node.h"}
%code{

  Node root;
  #include <string>
  
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;

}

%type  <Node> stream optline line anything unit

%token <std::string> TEXT
%token END 0 "end of file"
%token NEWL 1 "newline"
%token PIPE 2 "pipe"
%token <std::string> SPACE
%token <std::string> VAR
%token <std::string> STR
%token <std::string> DBQ

%right ';'

%start stream

%%

stream : optline				{ 	$$ = Node("stream","");
									$$.children.push_back($1);
									root = $$; 
								}
       | stream NEWL optline	{	root.children.push_back($3); }
       ;

optline : /*empty*/ 		{ $$ = Node("optline","empty");}
        | line				{ $$ = Node("optline","has line");
	                     		$$.children.push_back($1);
                       		}
        ;

anything :	PIPE 			{ $$ = Node("PIPE", "|"); }
		 |	TEXT 			{ $$ = Node("TEXT", $1); }
		 |	SPACE 			{ $$ = Node("SPACE", $1); }
		 |	VAR 			{ $$ = Node("VAR", $1); }
		 |	STR 			{ $$ = Node("STR", $1); }
		 |	DBQ 			{ $$ = Node("DBLQ", $1); }
		 ;

line : unit					{ 	$$ = Node("line",""); $$.children.push_back($1); }
     | line ';' unit		{	 
							     $1.children.push_back($3); 
							     $$ = $1;	
							}
	 ;

unit : anything				{ $$ = Node("units",""); $$.children.push_back($1); }
	 | unit anything		{ $1.children.push_back($2); $$ = $1; 	}