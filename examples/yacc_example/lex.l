%option noyywrap
%x COMMENT

%{
/* C declarations go here */
#include <stdio.h>
#include <stdlib.h>
#include "yacc.tab.h" // Include Yacc token definitions
// Potentially add string.h if we use strdup later
%}

INTCON     [0-9]+
IDENFR     [a-zA-Z_][a-zA-Z0-9_]*
STRCON     \"([^\"\\]|\\.)*\"

%%

"const"           { /* printf("CONSTTK const\n"); */ return CONSTTK; }
"int"             { /* printf("INTTK int\n"); */ return INTTK; }
"break"           { /* printf("BREAKTK break\n"); */ return BREAKTK; }
"continue"        { /* printf("CONTINUETK continue\n"); */ return CONTINUETK; }
"if"              { /* printf("IFTK if\n"); */ return IFTK; }
"else"            { /* printf("ELSETK else\n"); */ return ELSETK; }
"while"           { /* printf("WHILETK while\n"); */ return WHILETK; }
"getint"          { /* printf("GETINTTK getint\n"); */ return GETINTTK; }
"printf"          { /* printf("PRINTFTK printf\n"); */ return PRINTFTK; }
"return"          { /* printf("RETURNTK return\n"); */ return RETURNTK; }
"void"            { /* printf("VOIDTK void\n"); */ return VOIDTK; }
"main"            { /* printf("MAINTK main\n"); */ return MAINTK; }

"!="              { /* printf("NEQ !=\n"); */ return NEQ; }
"!"               { /* printf("NOT !\n"); */ return NOT; }
"&&"              { /* printf("AND &&\n"); */ return AND; }
"||"              { /* printf("OR ||\n"); */ return OR; }
"<="              { /* printf("LEQ <=\n"); */ return LEQ; }
"<"               { /* printf("LSS <\n"); */ return LSS; }
">="              { /* printf("GEQ >=\n"); */ return GEQ; }
">"               { /* printf("GRE >\n"); */ return GRE; }
"=="              { /* printf("EQL ==\n"); */ return EQL; }
"="               { /* printf("ASSIGN =\n"); */ return ASSIGN; }
"+"               { /* printf("PLUS +\n"); */ return PLUS; }
"-"               { /* printf("MINU -\n"); */ return MINU; }
"*"               { /* printf("MULT *\n"); */ return MULT; }
"/"               { /* printf("DIV /\n"); */ return DIV; }
"%"               { /* printf("MOD %%\n"); */ return MOD; }

";"               { /* printf("SEMICN ;\n"); */ return SEMICN; }
","               { /* printf("COMMA ,\n"); */ return COMMA; }
"("               { /* printf("LPARENT (\n"); */ return LPARENT; }
")"               { /* printf("RPARENT )\n"); */ return RPARENT; }
"["               { /* printf("LBRACK [\n"); */ return LBRACK; }
"]"               { /* printf("RBRACK ]\n"); */ return RBRACK; }
"{"               { /* printf("LBRACE {\n"); */ return LBRACE; }
"}"               { /* printf("RBRACE }\n"); */ return RBRACE; }

{INTCON}          { /* printf("INTCON %s\n", yytext); */ return INTCON; /* Need yylval later */ }
{IDENFR}          { /* printf("IDENFR %s\n", yytext); */ return IDENFR; /* Need yylval later */ }
{STRCON}          { /* printf("STRCON %s\n", yytext); */ return STRCON; /* Need yylval later */ }

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

/* Removed User code section (main function) */
// int main(int argc, char *argv[]) { ... }