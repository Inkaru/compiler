%top{
#include "binary.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
}
%option noyywrap nounput batch noinput

word                [ \t\v\a]+
o                   [ \t\v\a]*
name                [_a-zA-Z][_a-zA-Z0-9]*

n [0-9]
d2 [1-9]
num ({d2}+{n}?)|{n}

%x DBQUO

%%

\"							 BEGIN(DBQUO);
<DBQUO>\"					 BEGIN(INITIAL);
<DBQUO>[^"]*				 return yy::parser::make_STRING(yytext);

"+"             return yy::parser::make_PLUS();
"-"             return yy::parser::make_MINUS();
"/"             return yy::parser::make_DIV();
"*"             return yy::parser::make_MULT();
"^"             return yy::parser::make_EXPO();
"%"             return yy::parser::make_MOD();

"#"             return yy::parser::make_HASH();

"<"             return yy::parser::make_INF();
"<="            return yy::parser::make_INFEQ();
">"             return yy::parser::make_SUP();
">="            return yy::parser::make_SUPEQ();
"="             return yy::parser::make_EQU();
"=="            return yy::parser::make_DBEQU();
"~="            return yy::parser::make_NEQU();

"("             return yy::parser::make_BROPEN();
")"             return yy::parser::make_BRCLOSE();

"{"             return yy::parser::make_ACOPEN();
"}"             return yy::parser::make_ACCLOSE();

"["             return yy::parser::make_SQBROPEN();
"]"             return yy::parser::make_SQBRCLOSE();

"."             return yy::parser::make_DOT();
","             return yy::parser::make_COMMA();



"return"        return yy::parser::make_RETURN();
"break"         return yy::parser::make_BREAK();

"for"           return yy::parser::make_FOR();
"if"            return yy::parser::make_IF();
"then"          return yy::parser::make_THEN();
"end"           return yy::parser::make_STEND();
"do"            return yy::parser::make_DO();

"repeat"        return yy::parser::make_REPEAT();
"until"         return yy::parser::make_UNTIL();

{num}           return yy::parser::make_NUM(yytext);

{name}          return yy::parser::make_NAME(yytext);


<<EOF>>        return yy::parser::make_END();


%%