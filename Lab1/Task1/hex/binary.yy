%skeleton "lalr1.cc" 
%defines
%define api.value.type variant
%define api.token.constructor
%code{
  unsigned int total = 0;
  #include <string>
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
}
%token <std::string> BIT
%type <std::string> number
%token END 0 "end of file"
%%
number : BIT               {                   if($1[0]-'0' < 10 ){total += $1[0]-'0';} 
												else {total += $1[0]-'A' + 10;} }
       | number BIT        { total = total<<4; if($2[0]-'0' < 10 ){total += $2[0]-'0';} 
												else {total += $2[0]-'A' + 10;} }
       ;