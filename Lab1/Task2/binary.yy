%skeleton "lalr1.cc" 
%defines
%define api.value.type variant
%define api.token.constructor
%code{
  #include <string>
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
}
%type  <std::string> text
%token <std::string> LINE
%token END 0 "end of file"
%token NL 1 "newline"
%token PIPE 2 "pipe"
%token SEMI 3 "semicolon"
%token <std::string> SPACE
%token <std::string> VAR
%token <std::string> STR
%token <std::string> DBQ
%%
text : 	LINE 			{std::cout << "Text ->" << $1 << "<-"<< std::endl;}
	 |	NL 				{std::cout << "NL:" << std::endl;}
	 |	PIPE 			{std::cout << "Pipe" << std::endl;}
	 |	SEMI 			{std::cout << "Semi" << std::endl;}
	 |	SPACE 			{std::cout << "Blank: size " << $1.size() << std::endl;}
	 |	VAR 			{std::cout << "Var ->" << $1.erase(0,1) << "<-"<< std::endl;}
	 |	STR 			{std::cout << "Quoted ->" << $1.substr(1, $1.size() - 2) << "<-"<< std::endl;}
	 |	DBQ 			{std::cout << "DblQuoted ->" << $1 << "<-"<< std::endl;}
	 |	text LINE 		{std::cout << "Text ->" << $2 << "<-" << std::endl;}
	 |	text NL			{std::cout << "NL:" << std::endl;}
	 |	text PIPE		{std::cout << "Pipe" << std::endl;}
	 |	text SEMI		{std::cout << "Semi" << std::endl;}
	 |	text SPACE 		{std::cout << "Blank: size " << $2.size() << std::endl;}
	 |	text VAR 		{std::cout << "Var ->" << $2.erase(0,1) << "<-"<< std::endl;}
	 |	text STR 		{std::cout << "Quoted ->" << $2.substr(1, $2.size() - 2) << "<-"<< std::endl;}
	 |	text DBQ 		{std::cout << "DblQuoted ->" << $2 << "<-"<< std::endl;}
	 ;