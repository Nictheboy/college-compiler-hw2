%{
#define YYDEBUG 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For potential use later (e.g., strdup)

// External functions and variables
extern int yylex();
extern FILE *yyin;
extern char *yytext; // If needed for error reporting

void yyerror(const char *s);

%}

/* Token Definitions (Matching lex.l and README) */
%token IDENFR INTCON STRCON MAINTK CONSTTK INTTK BREAKTK CONTINUETK IFTK ELSETK VOIDTK WHILETK GETINTTK PRINTFTK RETURNTK
%token NOT AND OR PLUS MINU MULT DIV MOD ASSIGN SEMICN COMMA LPARENT RPARENT LBRACK RBRACK LBRACE RBRACE
%token LSS LEQ GRE GEQ EQL NEQ

/* Operator Precedence and Associativity (Example - adjust as needed for SysY) */
%right ASSIGN
%left OR
%left AND
%left EQL NEQ
%left LSS LEQ GRE GEQ
%left PLUS MINU
%left MULT DIV MOD
%right NOT // Unary operators often have high precedence
%nonassoc FUNCALL // Declare FUNCALL for precedence rule
%left LBRACK RBRACK // Add precedence for brackets
// Add precedence for unary minus if needed

/* Start Symbol */
%start CompUnit

%%

/* Removed Program rule */
// Program
//     : CompUnit { printf("<CompUnit>\n"); } 

CompUnit
    // : Decls FuncDefs MainFuncDef { printf("<CompUnit>\n"); } // Old structure
    : CompUnitItemList { printf("<CompUnit>\n"); } // New: List of items, print at end
    ;

/* Removed Decls and FuncDefs rules */
// Decls : /* empty */ 
//       | Decls Decl 
//       ;
// FuncDefs : /* empty */
//          | FuncDefs FuncDef
//          ;

CompUnitItemList // New rule: One or more items
    : CompUnitItem
    | CompUnitItemList CompUnitItem
    ;

CompUnitItem // New rule: An item is Decl, FuncDef, or MainFuncDef
    : Decl
    | FuncDef
    | MainFuncDef
    ;

Decl
    : ConstDecl { /* No printf needed here */ }
    | VarDecl   { /* No printf needed here */ }
    ;

ConstDecl
    : CONSTTK BType ConstDefList SEMICN { printf("<ConstDecl>\n"); }
    ;

ConstDefList
    : ConstDef
    | ConstDefList COMMA ConstDef
    ;

ConstDef
    : IDENFR ArrayDimensionsOpt ASSIGN ConstInitVal
    ;

// Assuming BType is only INT for now based on SysY subset
BType
    : INTTK
    ;

ConstInitVal
    : ConstExp
    | LBRACE ConstInitValListOpt RBRACE // Added array initializer
    ;

/* Added ConstInitValListOpt and ConstInitValList rules */
ConstInitValListOpt
    : /* empty */
    | ConstInitValList
    ;

ConstInitValList
    : ConstInitVal
    | ConstInitValList COMMA ConstInitVal
    ;

/* VarDecl
    : BType VarDefList SEMICN { printf("<VarDecl>\n"); }
    ;

VarDefList
    : VarDef
    | VarDefList COMMA VarDef
    ; */

VarDecl
    : VarDefList SEMICN { printf("<VarDecl>\n"); }
    ;

/* VarDefList
    : BType VarDef
    | VarDefList COMMA VarDef
    ; */

VarDefList
    : FuncPrefix VarDefOpt
    | VarDefList COMMA IDENFR VarDefOpt
    ;

VarDefOpt
    : ArrayDimensionsOpt AssignInitValOpt
    ;

// --- MOVE ArrayDimension rules HERE --- 
ArrayDimensionsOpt
    : /* empty */
    | ArrayDimensions
    ;

ArrayDimensions
    : LBRACK ConstExp RBRACK
    | ArrayDimensions LBRACK ConstExp RBRACK
    ;
// --- End MOVE --- 

AssignInitValOpt
    : /* empty */
    | ASSIGN InitVal
    ;

AssignInitVal
    : ASSIGN InitVal
    ;

InitVal
    : Exp
    | LBRACE InitValListOpt RBRACE // Added array initializer
    ;

/* Added InitValListOpt and InitValList rules */
InitValListOpt
    : /* empty */
    | InitValList
    ;

InitValList
    : InitVal
    | InitValList COMMA InitVal
    ;

/* Added FuncPrefix rule */
FuncPrefix
    : INTTK IDENFR
    | VOIDTK IDENFR
    ;

FuncDef
    : FuncPrefix LPARENT RPARENT Block { printf("<FuncDef>\n"); }
    | FuncPrefix LPARENT FuncFParams RPARENT Block { printf("<FuncDef>\n"); }
    ;

MainFuncDef
    : INTTK MAINTK LPARENT RPARENT Block { printf("<MainFuncDef>\n"); }
    ;

// Basic FuncFParams - expand later if needed
FuncFParams
    : FuncFParam
    | FuncFParams COMMA FuncFParam
    ;

FuncFParam
    : BType IDENFR // Add array markers `[]` later if needed
    ;

Block
    : LBRACE BlockItemList RBRACE { printf("<Block>\n"); }
    | LBRACE RBRACE { printf("<Block>\n"); } /* Empty block */
    ;

BlockItemList
    : BlockItem
    | BlockItemList BlockItem
    ;

BlockItem
    : Decl
    | Stmt
    ;

Stmt
    : LVal ASSIGN Exp SEMICN { printf("<Stmt>\n"); }                  /* Assignment (Uses LVal) */
    | Exp SEMICN             { printf("<Stmt>\n"); }                  /* Expression statement */
    | SEMICN                 { printf("<Stmt>\n"); }                  /* Empty statement */
    | Block                  { printf("<Stmt>\n"); }           /* Block statement - Add print back */
    | IFTK LPARENT Cond RPARENT Stmt                        { printf("<Stmt>\n"); }                  /* If */
    | IFTK LPARENT Cond RPARENT Stmt ELSETK Stmt            { printf("<Stmt>\n"); }                  /* If-Else */
    | WHILETK LPARENT Cond RPARENT Stmt                   { printf("<Stmt>\n"); }                  /* While */
    | BREAKTK SEMICN         { printf("<Stmt>\n"); }                  /* Break */
    | CONTINUETK SEMICN      { printf("<Stmt>\n"); }                  /* Continue */
    | RETURNTK SEMICN        { printf("<Stmt>\n"); }                  /* Return void */
    | RETURNTK Exp SEMICN    { printf("<Stmt>\n"); }                  /* Return value */
    | PRINTFTK LPARENT STRCON RPARENT SEMICN { /* Basic printf, needs format args */ printf("<Stmt>\n"); }
    | PRINTFTK LPARENT STRCON COMMA FuncRParams RPARENT SEMICN { printf("<Stmt>\n"); }
    ;

FuncRParams
    : Exp
    | FuncRParams COMMA Exp
    ;

// Expressions (Need full hierarchy based on precedence)
Exp : AddExp ;
LVal
    : IDENFR
    | IDENFR LBRACK Exp RBRACK
    ;

PrimaryExp
    : LPARENT Exp RPARENT
    | LVal
    | Number
    ;
Number : INTCON ; // Ensure Number rule is present
UnaryExp
    : PrimaryExp
    | PLUS UnaryExp
    | MINU UnaryExp
    | NOT UnaryExp
    | IDENFR LPARENT RPARENT       %prec FUNCALL
    | IDENFR LPARENT FuncRParams RPARENT %prec FUNCALL
    | GETINTTK LPARENT RPARENT   // Rule for getint() call
    ;
MulExp
    : UnaryExp
    | MulExp MULT UnaryExp
    | MulExp DIV UnaryExp
    | MulExp MOD UnaryExp
    ;
AddExp
    : MulExp
    | AddExp PLUS MulExp
    | AddExp MINU MulExp
    ;
RelExp
    : AddExp
    | RelExp LSS AddExp
    | RelExp GRE AddExp
    | RelExp LEQ AddExp
    | RelExp GEQ AddExp
    ;
EqExp
    : RelExp
    | EqExp EQL RelExp
    | EqExp NEQ RelExp
    ;
LAndExp
    : EqExp
    | LAndExp AND EqExp
    ;
LOrExp
    : LAndExp
    | LOrExp OR LAndExp
    ;
Cond : LOrExp ; // Condition expression for if/while
// ConstExp : AddExp ; // Old ConstExp definition
ConstExp : Number ; // Restrict ConstExp to Number

%% 

/* User code section */

void yyerror(const char *s) {
    // Add line number reporting if possible (yylineno)
    fprintf(stderr, "Syntax error: %s near '%s'\n", s, yytext); 
    // Consider adding line number: fprintf(stderr, "Syntax error on line %d: %s near '%s'\n", yylineno, s, yytext);
    exit(1); // Exit on first error for simplicity in testing
}

// Need yylineno definition if used in yyerror
// extern int yylineno;

int main(int argc, char *argv[]) {
    // Default to stdin if no file provided
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

    yydebug = 0; // Set back to 0
    if (yyparse() == 0) { // 0 on success
        // Optional: Print success message
        // printf("Parsing completed successfully.\n");
    } else {
        // Error message already printed by yyerror
        return 1;
    }

    // Close the file if it was opened
    if (yyin != stdin) {
        fclose(yyin);
    }

    return 0;
}