%option noyywrap
%x COMMENT

%{
/* C declarations go here */
#include <stdio.h>
#include <stdlib.h>
%}

INTCON     [0-9]+
IDENFR     [a-zA-Z_][a-zA-Z0-9_]*
STRCON     \"([^\"\\]|\\.)*\"

%%

"const"           { printf("CONSTTK const\n"); }
"int"             { printf("INTTK int\n"); }
"break"           { printf("BREAKTK break\n"); }
"continue"        { printf("CONTINUETK continue\n"); }
"if"              { printf("IFTK if\n"); }
"else"            { printf("ELSETK else\n"); }
"while"           { printf("WHILETK while\n"); }
"getint"          { printf("GETINTTK getint\n"); }
"printf"          { printf("PRINTFTK printf\n"); }
"return"          { printf("RETURNTK return\n"); }
"void"            { printf("VOIDTK void\n"); }
"main"            { printf("MAINTK main\n"); }

"!="              { printf("NEQ !=\n"); }
"!"               { printf("NOT !\n"); }
"&&"              { printf("AND &&\n"); }
"||"              { printf("OR ||\n"); }
"<="              { printf("LEQ <=\n"); }
"<"               { printf("LSS <\n"); }
">="              { printf("GEQ >=\n"); }
">"               { printf("GRE >\n"); }
"=="              { printf("EQL ==\n"); }
"="               { printf("ASSIGN =\n"); }
"+"               { printf("PLUS +\n"); }
"-"               { printf("MINU -\n"); }
"*"               { printf("MULT *\n"); }
"/"               { printf("DIV /\n"); }
"%"               { printf("MOD %%\n"); }

";"               { printf("SEMICN ;\n"); }
","               { printf("COMMA ,\n"); }
"("               { printf("LPARENT (\n"); }
")"               { printf("RPARENT )\n"); }
"["               { printf("LBRACK [\n"); }
"]"               { printf("RBRACK ]\n"); }
"{"               { printf("LBRACE {\n"); }
"}"               { printf("RBRACE }\n"); }

{INTCON}          { printf("INTCON %s\n", yytext); }
{IDENFR}          { printf("IDENFR %s\n", yytext); }
{STRCON}          { printf("STRCON %s\n", yytext); }

"//".*            { /* Ignore single-line comments */ }
"/*"              { BEGIN(COMMENT); }

<COMMENT>{
  "*/"            { BEGIN(INITIAL); }
  [^*\n]+         { /* Eat non-star, non-newline characters */ }
  "*"             { /* Eat the star, do nothing */ }
  \n              { /* Explicitly consume newlines within comments */ }
}

[ \t\r\n]+        ;   /* Ignore whitespace */

.                 { /* Optionally print an error for unknown characters */
                    /* fprintf(stderr, "Error: Unknown character '%s'\n", yytext); */
                  }

%%

/* User code section (main function) */
int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *fin = fopen(argv[1], "r");
        if (!fin) {
            perror(argv[1]);
            return 1;
        }
        yyin = fin;
    } else {
        yyin = stdin;
    }
    
    yylex(); // Run the lexer

    if (yyin != stdin) {
        fclose(yyin);
    }

    return 0;
}