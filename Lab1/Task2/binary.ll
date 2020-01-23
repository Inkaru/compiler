%top{
#include "binary.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
}
%option noyywrap nounput batch noinput
ALPHA [A-Za-z0-9]+ 
%%
\${ALPHA}					{ return yy::parser::make_VAR(yytext); 	}
\'{1}[^'\n]*[']{1}				{ return yy::parser::make_STR(yytext); 	}
\|{1}						{ return yy::parser::make_PIPE(); 		}
;{1}						{ return yy::parser::make_SEMI(); 		}
[ \t]+						{ return yy::parser::make_SPACE(yytext);}
(\\[\\\|; ]{1}|{ALPHA})*	{ return yy::parser::make_LINE(yytext); }
\\n|\n						{ return yy::parser::make_NL(); 		}
<<EOF>>						{ return yy::parser::make_END();		}
%%