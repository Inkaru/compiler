%top{
#include "binary.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
}
%option noyywrap nounput batch noinput
%%


\|{1}      	{ return yy::parser::make_PIPE(); }
;{1}	 	{ return yy::parser::make_SEMI(); }
[ \t]+       { return yy::parser::make_SPACE(yytext); }
[^ \|\n\t]+    { return yy::parser::make_LINE(yytext); }
\n         	{ return yy::parser::make_NL(); }
<<EOF>>     return yy::parser::make_END();
%%