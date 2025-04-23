%{
// #include "ast.h" // Removed from here
#define YYDEBUG 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For potential use later (e.g., strdup)

// External functions and variables
extern int yylex();
extern FILE *yyin;
extern char *yytext; // If needed for error reporting
// BaseAST *root = NULL; // Removed from here

// Forward declaration for the BaseAST struct and dump function
struct BaseAST; // Forward declare the struct type
void dump_ast_dot_to_file(struct BaseAST* root, const char* filename);

void yyerror(const char *s);

%}

// Ensure AST types are known before YYSTYPE definition in yacc.tab.h
%code requires {
  #include "ast.h"
}

// Global variables accessible within parser actions and main
%code {
  BaseAST *root = NULL; // Define global C root pointer HERE
}

// --- Add the missing %union --- 
%union {
    BaseAST* ast_ptr;
    int int_val;
    char* str_val;
}

/* Token Definitions (Matching lex.l and README) */
%token <str_val> IDENT STR_CONST // Changed from IDENFR/STRCON
%token <int_val> INT_CONST       // Changed from INTCON
%token MAINTK CONSTTK INTTK BREAKTK CONTINUETK IFTK ELSETK VOIDTK WHILETK GETINTTK PRINTFTK RETURNTK
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

/* AST Type Declarations (Assuming these exist or need adjustment based on ast.h) */
// It's crucial that these %type declarations match the non-terminals
// that will return BaseAST* pointers in their actions.
%type <ast_ptr> CompUnit CompUnitItemList CompUnitItem Decl ConstDecl VarDecl
%type <ast_ptr> ConstDefList ConstDef ConstInitVal ConstInitValListOpt ConstInitValList
%type <ast_ptr> VarDefList VarDef InitVal InitValListOpt InitValList // Add VarDef here
%type <ast_ptr> ArrayDimensionsOpt ArrayDimensions ConstExp BType
%type <ast_ptr> FuncPrefix FuncDef MainFuncDef FuncFParams FuncFParam Block BlockItemList BlockItem Stmt
%type <ast_ptr> Exp LVal PrimaryExp Number UnaryExp MulExp AddExp RelExp EqExp LAndExp LOrExp Cond FuncRParams
%type <ast_ptr> AssignInitValOpt // Add AssignInitValOpt here
// Removed AssignInitVal from type list as it's unused

/* Start Symbol */
%start CompUnit

%%

/* Removed Program rule */
// Program
//     : CompUnit { printf("<CompUnit>\n"); } 

CompUnit
    : CompUnitItemList {
        CompUnitAST* comp_unit = create_comp_unit((ASTList*)$1); // Create CompUnitAST
        $$ = (BaseAST*)comp_unit; // The value of this rule is the CompUnitAST
        root = $$;               // Assign the CompUnitAST to the global root
    }
    ;

/* Removed Decls and FuncDefs rules */
// Decls : /* empty */ 
//       | Decls Decl 
//       ;
// FuncDefs : /* empty */
//          | FuncDefs FuncDef
//          ;

CompUnitItemList
    : CompUnitItem     {
        ASTList* list = create_ast_list();
        if ($1) {
            add_ast_list_node(&list->head, $1);
        }
        $$ = (BaseAST*)list;
        /* Create list, add first item (if not null) */
    }
    | CompUnitItemList CompUnitItem {
        ASTList* list = (ASTList*)$1; // Cast existing list
        if ($2) {
            add_ast_list_node(&list->head, $2);
        }
        $$ = $1; // Pass the modified list up
        /* Add subsequent item (if not null) */
    }
    ;

CompUnitItem // Return value might be null if rule is empty/error?
    : Decl    { $$ = $1; }
    | FuncDef { $$ = $1; }
    | MainFuncDef { $$ = $1; }
    ;

Decl
    : ConstDecl { $$ = $1; }
    | VarDecl   { $$ = $1; }
    ;

ConstDecl
    : CONSTTK BType ConstDefList SEMICN { $$ = (BaseAST*)create_const_decl_list((TypeAST*)$2, (ASTList*)$3); }
    ;

ConstDefList
    : ConstDef {
        ASTList* list = create_ast_list();
        add_ast_list_node(&list->head, $1);
        $$ = (BaseAST*)list;
    }
    | ConstDefList COMMA ConstDef {
        ASTList* list = (ASTList*)$1;
        add_ast_list_node(&list->head, $3);
        $$ = $1;
    }
    ;

ConstDef
    : IDENT ArrayDimensionsOpt ASSIGN ConstInitVal { $$ = (BaseAST*)create_const_def($1, (ASTList*)$2, $4); /* free($1) is assumed handled by create_ */ }
    ;

// Assuming BType is only INT for now based on SysY subset
BType
    : INTTK { $$ = (BaseAST*)create_type(SYSY_INT); }
    ;

ConstInitVal
    : ConstExp { $$ = $1; }
    | LBRACE ConstInitValListOpt RBRACE { $$ = $2 ? $2 : (BaseAST*)create_ast_list(); /* Use C list */ }
    ;

/* Added ConstInitValListOpt and ConstInitValList rules */
ConstInitValListOpt
    : /* empty */ { $$ = NULL; /* Use NULL */ }
    | ConstInitValList { $$ = $1; }
    ;

ConstInitValList
    : ConstInitVal {
        ASTList* list = create_ast_list();
        add_ast_list_node(&list->head, $1);
        $$ = (BaseAST*)list;
     }
    | ConstInitValList COMMA ConstInitVal {
        ASTList* list = (ASTList*)$1;
        add_ast_list_node(&list->head, $3);
        $$ = $1;
    }
    ;

/* VarDecl
    : BType VarDefList SEMICN { printf("<VarDecl>\n"); }
    ;

VarDefList
    : BType VarDef
    | VarDefList COMMA VarDef
    ; */

VarDecl
    : BType VarDefList SEMICN { $$ = (BaseAST*)create_var_decl_list((TypeAST*)$1, (ASTList*)$2); }
    ;

/* VarDefList
    : BType VarDef
    | VarDefList COMMA VarDef
    ; */

VarDefList
    : VarDef {
        ASTList* list = create_ast_list();
        add_ast_list_node(&list->head, $1);
        $$ = (BaseAST*)list;
    }
    | VarDefList COMMA VarDef {
        ASTList* list = (ASTList*)$1;
        add_ast_list_node(&list->head, $3);
        $$ = $1;
    }
    ;

VarDef // Add VarDef back to %type <ast_ptr> list above!
    : IDENT ArrayDimensionsOpt AssignInitValOpt { $$ = (BaseAST*)create_var_def($1, (ASTList*)$2, $3); /* free($1) is assumed handled by create_ */ }
    ;

// --- MOVE ArrayDimension rules HERE --- 
ArrayDimensionsOpt
    : /* empty */ { $$ = NULL; /* Use NULL */ }
    | ArrayDimensions { $$ = $1; }
    ;

ArrayDimensions
    : LBRACK ConstExp RBRACK {
        ASTList* list = create_ast_list();
        add_ast_list_node(&list->head, $2);
        $$ = (BaseAST*)list;
    }
    | ArrayDimensions LBRACK ConstExp RBRACK {
        ASTList* list = (ASTList*)$1;
        add_ast_list_node(&list->head, $3);
        $$ = $1;
    }
    ;
// --- End MOVE --- 

AssignInitValOpt
    : /* empty */ { $$ = NULL; /* Use NULL */ }
    | ASSIGN InitVal { $$ = $2; /* Pass InitVal AST up */ }
    ;

InitVal
    : Exp { $$ = $1; }
    | LBRACE InitValListOpt RBRACE { $$ = $2 ? $2 : (BaseAST*)create_ast_list(); /* Use C list */ }
    ;

/* Added InitValListOpt and InitValList rules */
InitValListOpt
    : /* empty */ { $$ = NULL; /* Use NULL */ }
    | InitValList { $$ = $1; }
    ;

InitValList
    : InitVal {
        ASTList* list = create_ast_list();
        add_ast_list_node(&list->head, $1);
        $$ = (BaseAST*)list;
     }
    | InitValList COMMA InitVal {
        ASTList* list = (ASTList*)$1;
        add_ast_list_node(&list->head, $3);
        $$ = $1;
    }
    ;

/* Added FuncPrefix rule */
FuncPrefix
    : BType IDENT { $$ = (BaseAST*)create_func_id_info(SYSY_INT, $2); /* free($2) is assumed handled by create_ */ }
    | VOIDTK IDENT { $$ = (BaseAST*)create_func_id_info(SYSY_VOID, $2); /* free($2) is assumed handled by create_ */ }
    ;

FuncDef
    : FuncPrefix LPARENT RPARENT Block { $$ = (BaseAST*)create_func_def((FuncIdInfoAST*)$1, NULL, (ASTList*)$4); }
    | FuncPrefix LPARENT FuncFParams RPARENT Block { $$ = (BaseAST*)create_func_def((FuncIdInfoAST*)$1, (ASTList*)$3, (ASTList*)$5); }
    ;

MainFuncDef
    : INTTK MAINTK LPARENT RPARENT Block { $$ = (BaseAST*)create_main_func_def((ASTList*)$5); }
    ;

// Basic FuncFParams - expand later if needed
FuncFParams
    : FuncFParam {
        ASTList* list = create_ast_list();
        add_ast_list_node(&list->head, $1);
        $$ = (BaseAST*)list;
     }
    | FuncFParams COMMA FuncFParam {
        ASTList* list = (ASTList*)$1;
        add_ast_list_node(&list->head, $3);
        $$ = $1;
    }
    ;

FuncFParam
    : BType IDENT { $$ = (BaseAST*)create_func_param((TypeAST*)$1, $2, 0, NULL); /* free($2) is assumed handled by create_ */ }
    ;

Block
    : LBRACE BlockItemList RBRACE { $$ = $2; }
    | LBRACE RBRACE { $$ = (BaseAST*)create_ast_list(); }
    ;

BlockItemList
    : BlockItem {
        ASTList* list = create_ast_list();
        if($1) add_ast_list_node(&list->head, $1);
        $$ = (BaseAST*)list;
      }
    | BlockItemList BlockItem {
        ASTList* list = (ASTList*)$1;
        if($2) add_ast_list_node(&list->head, $2);
        $$ = $1;
    }
    ;

BlockItem
    : Decl { $$ = $1; }
    | Stmt { $$ = $1; }
    ;

Stmt
    : LVal ASSIGN Exp SEMICN { $$ = (BaseAST*)create_assign_stmt($1, $3); }
    | Exp SEMICN             { $$ = (BaseAST*)create_exp_stmt($1); }
    | SEMICN                 { $$ = (BaseAST*)create_empty_stmt(); }
    | Block                  { $$ = $1; }
    | IFTK LPARENT Cond RPARENT Stmt { $$ = (BaseAST*)create_if_stmt($3, $5, NULL); }
    | IFTK LPARENT Cond RPARENT Stmt ELSETK Stmt { $$ = (BaseAST*)create_if_stmt($3, $5, $7); }
    | WHILETK LPARENT Cond RPARENT Stmt { $$ = (BaseAST*)create_while_stmt($3, $5); }
    | BREAKTK SEMICN         { $$ = (BaseAST*)create_break_stmt(); }
    | CONTINUETK SEMICN      { $$ = (BaseAST*)create_continue_stmt(); }
    | RETURNTK SEMICN        { $$ = (BaseAST*)create_return_stmt(NULL); }
    | RETURNTK Exp SEMICN    { $$ = (BaseAST*)create_return_stmt($2); }
    | PRINTFTK LPARENT STR_CONST RPARENT SEMICN { $$ = (BaseAST*)create_printf_stmt($3, NULL); /* free($3) is assumed handled by create_ */ }
    | PRINTFTK LPARENT STR_CONST COMMA FuncRParams RPARENT SEMICN { $$ = (BaseAST*)create_printf_stmt($3, (ASTList*)$5); /* free($3) is assumed handled by create_ */ }
    ;

FuncRParams
    : Exp {
        ASTList* list = create_ast_list();
        add_ast_list_node(&list->head, $1);
        $$ = (BaseAST*)list;
      }
    | FuncRParams COMMA Exp {
        ASTList* list = (ASTList*)$1;
        add_ast_list_node(&list->head, $3);
        $$ = $1;
    }
    ;

// Expressions (Need full hierarchy based on precedence)
Exp : AddExp { $$ = $1; } ;
LVal
    : IDENT { $$ = (BaseAST*)create_var_ref($1, NULL); /* free($1) is assumed handled by create_ */ }
    | IDENT LBRACK Exp RBRACK {
        ASTList* indices = create_ast_list();
        add_ast_list_node(&indices->head, $3);
        $$ = (BaseAST*)create_var_ref($1, indices); /* free($1) is assumed handled by create_ */
        // TODO: Extend LVal rule to handle multi-dimensional arrays if needed
    }
    ;

PrimaryExp
    : LPARENT Exp RPARENT { $$ = $2; }
    | LVal { $$ = $1; }
    | Number { $$ = $1; }
    ;
Number : INT_CONST { $$ = (BaseAST*)create_number($1); } ;
UnaryExp
    : PrimaryExp { $$ = $1; }
    | PLUS UnaryExp { $$ = (BaseAST*)create_unary_op(UNARY_POS, $2); }
    | MINU UnaryExp { $$ = (BaseAST*)create_unary_op(UNARY_NEG, $2); }
    | NOT UnaryExp { $$ = (BaseAST*)create_unary_op(UNARY_NOT, $2); }
    | IDENT LPARENT RPARENT %prec FUNCALL { $$ = (BaseAST*)create_func_call($1, NULL); /* free($1) is assumed handled by create_ */ }
    | IDENT LPARENT FuncRParams RPARENT %prec FUNCALL { $$ = (BaseAST*)create_func_call($1, (ASTList*)$3); /* free($1) is assumed handled by create_ */ }
    | GETINTTK LPARENT RPARENT { $$ = (BaseAST*)create_getint(); }
    ;
MulExp
    : UnaryExp { $$ = $1; }
    | MulExp MULT UnaryExp { $$ = (BaseAST*)create_binary_op(BINOP_MUL, $1, $3); }
    | MulExp DIV UnaryExp { $$ = (BaseAST*)create_binary_op(BINOP_DIV, $1, $3); }
    | MulExp MOD UnaryExp { $$ = (BaseAST*)create_binary_op(BINOP_MOD, $1, $3); }
    ;
AddExp
    : MulExp { $$ = $1; }
    | AddExp PLUS MulExp { $$ = (BaseAST*)create_binary_op(BINOP_ADD, $1, $3); }
    | AddExp MINU MulExp { $$ = (BaseAST*)create_binary_op(BINOP_SUB, $1, $3); }
    ;
RelExp
    : AddExp { $$ = $1; }
    | RelExp LSS AddExp { $$ = (BaseAST*)create_binary_op(BINOP_LT, $1, $3); }
    | RelExp GRE AddExp { $$ = (BaseAST*)create_binary_op(BINOP_GT, $1, $3); }
    | RelExp LEQ AddExp { $$ = (BaseAST*)create_binary_op(BINOP_LE, $1, $3); }
    | RelExp GEQ AddExp { $$ = (BaseAST*)create_binary_op(BINOP_GE, $1, $3); }
    ;
EqExp
    : RelExp { $$ = $1; }
    | EqExp EQL RelExp { $$ = (BaseAST*)create_binary_op(BINOP_EQ, $1, $3); }
    | EqExp NEQ RelExp { $$ = (BaseAST*)create_binary_op(BINOP_NE, $1, $3); }
    ;
LAndExp
    : EqExp { $$ = $1; }
    | LAndExp AND EqExp { $$ = (BaseAST*)create_binary_op(BINOP_LAND, $1, $3); }
    ;
LOrExp
    : LAndExp { $$ = $1; }
    | LOrExp OR LAndExp { $$ = (BaseAST*)create_binary_op(BINOP_LOR, $1, $3); }
    ;
Cond : LOrExp { $$ = $1; } ; // Condition expression for if/while
// ConstExp : AddExp ; // Old ConstExp definition
ConstExp : Number { $$ = $1; } ; // Restrict ConstExp to Number

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
    int parse_result = yyparse(); // 0 on success

    // Close the file if it was opened
    if (yyin != stdin) {
        fclose(yyin);
    }

    if (parse_result == 0) { // Success
        printf("Parsing completed successfully.\n");
        if (root) {
           dump_ast_dot_to_file(root, "ast.dot");
           free_ast(root); // Free the allocated AST memory
        }
    } else {
        // Error message already printed by yyerror
        return 1; // Indicate failure
    }

    return 0; // Indicate success
}