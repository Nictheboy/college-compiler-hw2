%option noyywrap
%x COMMENT

%{
/* C declarations go here */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Need for strdup
#include "yacc.tab.h" // Include Yacc token definitions

// Helper function to duplicate string for yylval
char* copy_string(const char* s) {
    char* p = (char*)malloc(strlen(s) + 1);
    if (p) strcpy(p, s);
    return p;
}
%}

/* Regex definitions - Use names matching yacc tokens if different */
INT_CONST_RE   [0-9]+
IDENT_RE       [a-zA-Z_][a-zA-Z0-9_]*
STR_CONST_RE   \"([^\"\\]|\\.)*\"

%%

"const"           { return CONSTTK; }
"int"             { return INTTK; }
"break"           { return BREAKTK; }
"continue"        { return CONTINUETK; }
"if"              { return IFTK; }
"else"            { return ELSETK; }
"while"           { return WHILETK; }
"getint"          { return GETINTTK; }
"printf"          { return PRINTFTK; }
"return"          { return RETURNTK; }
"void"            { return VOIDTK; }
"main"            { return MAINTK; }

"!="              { return NEQ; }
"!"               { return NOT; }
"&&"              { return AND; }
"||"              { return OR; }
"<="              { return LEQ; }
"<"               { return LSS; }
">="              { return GEQ; }
">"               { return GRE; }
"=="              { return EQL; }
"="               { return ASSIGN; }
"+"               { return PLUS; }
"-"               { return MINU; }
"*"               { return MULT; }
"/"               { return DIV; }
"%"               { return MOD; }

";"               { return SEMICN; }
","               { return COMMA; }
"("               { return LPARENT; }
")"               { return RPARENT; }
"["               { return LBRACK; }
"]"               { return RBRACK; }
"{"               { return LBRACE; }
"}"               { return RBRACE; }

{INT_CONST_RE}    { yylval.int_val = atoi(yytext); return INT_CONST; }
{IDENT_RE}        { yylval.str_val = copy_string(yytext); return IDENT; }
{STR_CONST_RE}    { yylval.str_val = copy_string(yytext); return STR_CONST; }

"//".*            { /* Ignore */ }
"/*"              { BEGIN(COMMENT); }
<COMMENT>{
  "*/"            { BEGIN(INITIAL); }
  [^*\n]+         { /* Ignore - Fixed \n */ }
  "*"             { /* Ignore */ }
  \n              { /* Ignore */ }
}
[ \t\r\n]+        ;   /* Ignore */

.                 { fprintf(stderr, "Error: Unknown character '%s'\n", yytext); /* Report errors */ }

%%

/* No main function needed here */