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
%token SPACE 1 "space"
%%
number : BIT               {                   					total += $1[0]-'0';		}
       | number BIT        { total = total<<1; 					total += $2[0]-'0';		}
       | number SPACE 	   { std::cout << total << std::endl; 	total = 0;				}
       | number END 	   { std::cout << total << std::endl; 	total = 0;	return total;			}
       ;