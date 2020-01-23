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
%%
text : 	LINE 			{std::cout << "Text ->" << $1 << "<-"<< std::endl;}
	 |	NL 				{std::cout << "NL:" << std::endl;}
	 |	PIPE 			{std::cout << "Pipe" << std::endl;}
	 |	SEMI 			{std::cout << "Semi" << std::endl;}
	 |	SPACE 			{std::cout << "Blank: size " << $1.size() << std::endl;}
	 |	text LINE 		{std::cout << "Text ->" << $2 << "<-" << std::endl;}
	 |	text NL			{std::cout << "NL:" << std::endl;}
	 |	text PIPE		{std::cout << "Pipe" << std::endl;}
	 |	text SEMI		{std::cout << "Semi" << std::endl;}
	 |	text SPACE 		{std::cout << "Blank: size " << $2.size() << std::endl;}
	 ;