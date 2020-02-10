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

%type  <Node> stream optline pipeline line command units word anything equals subshell

%token <std::string> WORD
%token END 0
%token NEWL
%token PIPE
%token SEMI
%token EQUALS
%token <std::string> SPACE
%token <std::string> VAR
%token <std::string> STR
%token <std::string> DBQ
%token SUBBEGIN
%token SUBEND

%start stream

%%

stream : optline				{ 	$$ = Node("stream","");
									$$.children.push_back($1);
									root = $$; 
								}
       | stream NEWL optline	{	root.children.push_back($3); }
       ;

optline : /*empty*/ 		{ 	$$ = Node("optline","empty");}
        | command			{ 	$$ = Node("optline","has line");
	                     		$$.children.push_back($1);
                       		}
		| pipeline			{ 	$$ = Node("optline","has line");
	                     		$$.children.push_back($1);
                       		}
		| line				{ 	$$ = Node("optline","has line");
	                     		$$.children.push_back($1);
                       		}
		| equals			{ 	$$ = Node("optline","has line");
	                     		$$.children.push_back($1);
                       		}
        ;

pipeline : command					{ 	$$ = $1;	}
		 | pipeline PIPE command 	{ 	$$ = Node("pipeline",""); 
										$$.children.push_back($1);
										$$.children.push_back($3);	}
		 ;

anything :	WORD 			{ $$ = Node("WORD", $1); }
		 |	VAR 			{ $$ = Node("VAR", $1); }
		 |	STR 			{ $$ = Node("STR", $1); }
		 |	DBQ 			{ $$ = Node("DBLQ", $1); }
		 |	EQUALS			{ $$ = Node("EQUALS", "=");}
		 ;

word : WORD 	{ $$ = Node("WORD", $1);}

units : anything anything	{ 	$$ = Node("concatenate",""); 
								$$.children.push_back($1);
								$$.children.push_back($2); }
	 | units anything		{ 	$1.children.push_back($2); 
	 							$$ = $1; 	}
	 ;

command : word						{	$$ = Node("command","");;
										$$.children.push_back($1);	}
		| SPACE word				{	$$ = Node("command","");;
										$$.children.push_back($2);	}
		| command SPACE anything	{	$$ = $1;	
										$$.children.push_back($3);	}
		| command SPACE units		{	$$ = $1;	
										$$.children.push_back($3);	}
		| command SPACE subshell	{	$$ = Node("SUBSHELL","");
										$$.children.push_back($3);	}
		| command SPACE				{	$$ = $1;					}
		;

subshell : SUBBEGIN stream SUBEND 	{ 	$$ = $2;	};

equals  : equals SPACE command		{	$$ = $1;	
										$$.children.push_back($3);	}
		| equals SPACE units		{	$$ = $1;	
										$$.children.push_back($3);	}
		| equals SPACE anything		{	$$ = $1;	
										$$.children.push_back($3);	}
		| equals SPACE				{	$$ = $1;					} 
		| anything EQUALS anything	{	$$ = Node("equals","");
										$$.children.push_back($1); 	
										$$.children.push_back($3);  }
		| anything EQUALS units		{	$$ = Node("equals","");
										$$.children.push_back($1); 	
										$$.children.push_back($3);  }
		| equals SPACE equals		{	$$ = $1;	
										$$.children.push_back($3);	}
		;

line : pipeline					{ 	$$ = $1; }
     | line SEMI pipeline		{	$$ = Node("line","");
	 								$$.children.push_back($1);
									$$.children.push_back($3); }
	 ;
