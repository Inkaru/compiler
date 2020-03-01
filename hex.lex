DIG [0-9a-f]
%%
0x{DIG}+ { printf("Tok: %s\\n", yytext); }
%%
int main(int argc, char **argv)
{
  yylex();
}