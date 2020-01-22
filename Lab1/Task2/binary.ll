%top{
#include "binary.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
}
%option noyywrap nounput batch noinput

%Start ESCAPE
%%

\\ { printf("ESCAPING"); BEGIN ESCAPE;}

<INITIAL>\|{1}      { return yy::parser::make_PIPE(); }
<INITIAL>;{1}	 	{ return yy::parser::make_SEMI(); }
[ \t]+       { return yy::parser::make_SPACE(yytext); }
\n         	{ return yy::parser::make_NL(); }
<ESCAPE>[^ \n\t]+    { return yy::parser::make_LINE(yytext); }
<INITIAL>[^ \n\t\|;]+   { return yy::parser::make_LINE(yytext); }
<<EOF>>     return yy::parser::make_END();
%%