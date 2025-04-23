#ifndef AST_H
#define AST_H

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h> // Include for NULL definition

// Forward declarations of all AST node types
typedef struct BaseAST BaseAST;
typedef struct CompUnitListAST CompUnitListAST;
typedef struct DefListAST DefListAST;
typedef struct InitListAST InitListAST;
typedef struct DimListAST DimListAST;
typedef struct ParamListAST ParamListAST;
typedef struct BlockListAST BlockListAST;
typedef struct ArgListAST ArgListAST;
typedef struct ConstDeclListAST ConstDeclListAST;
typedef struct ConstDefAST ConstDefAST;
typedef struct TypeAST TypeAST;
typedef struct VarDeclListAST VarDeclListAST;
typedef struct VarDefAST VarDefAST;
typedef struct FuncIdInfoAST FuncIdInfoAST;
typedef struct FuncDefAST FuncDefAST;
typedef struct MainFuncDefAST MainFuncDefAST;
typedef struct FuncParamAST FuncParamAST;
typedef struct AssignStmtAST AssignStmtAST;
typedef struct ExpStmtAST ExpStmtAST;
typedef struct EmptyStmtAST EmptyStmtAST;
typedef struct IfStmtAST IfStmtAST;
typedef struct WhileStmtAST WhileStmtAST;
typedef struct BreakStmtAST BreakStmtAST;
typedef struct ContinueStmtAST ContinueStmtAST;
typedef struct ReturnStmtAST ReturnStmtAST;
typedef struct PrintfStmtAST PrintfStmtAST;
typedef struct VarRefAST VarRefAST;
typedef struct NumberAST NumberAST;
typedef struct UnaryOpAST UnaryOpAST;
typedef struct BinaryOpAST BinaryOpAST;
typedef struct FuncCallAST FuncCallAST;
typedef struct GetIntAST GetIntAST;


// --- Enums ---

// Add NodeType enum
typedef enum {
    NODE_UNKNOWN,
    NODE_ASTLIST,
    NODE_COMPUNIT,
    NODE_CONSTDECLLIST,
    NODE_CONSTDEF,
    NODE_TYPE,
    NODE_VARDECLLIST,
    NODE_VARDEF,
    NODE_FUNCIDINFO,
    NODE_FUNCDEF,
    NODE_MAINFUNCDEF,
    NODE_FUNCPARAM,
    NODE_ASSIGNSTMT,
    NODE_EXPSTMT,
    NODE_EMPTYSTMT,
    NODE_IFSTMT,
    NODE_WHILESTMT,
    NODE_BREAKSTMT,
    NODE_CONTINUESTMT,
    NODE_RETURNSTMT,
    NODE_PRINTFSTMT,
    NODE_VARREF,
    NODE_NUMBER,
    NODE_UNARYOP,
    NODE_BINARYOP,
    NODE_FUNCCALL,
    NODE_GETINT
} NodeType;

// SysY Basic Types (Add more if needed, e.g., FLOAT)
typedef enum {
    SYSY_INT,
    SYSY_VOID
    // Add SYSY_FLOAT etc. if your language supports it
} SysYType;

// Unary Operators
typedef enum {
    UNARY_POS, // +
    UNARY_NEG, // -
    UNARY_NOT  // !
} UnaryOp;

// Binary Operators (Grouped by type)
typedef enum {
    // Arithmetic
    BINOP_ADD, BINOP_SUB, BINOP_MUL, BINOP_DIV, BINOP_MOD,
    // Relational
    BINOP_LT, BINOP_GT, BINOP_LE, BINOP_GE,
    // Equality
    BINOP_EQ, BINOP_NE,
    // Logical
    BINOP_LAND, BINOP_LOR,
    // Note: No ASSIGN here, it's usually a statement
} BinaryOp;

// --- Base Structure ---
// All AST nodes can be cast to this base type.
// We can add a 'type' enum field here if needed for easier type checking in C.
typedef struct BaseAST {
   NodeType node_type; // Add node type field
   // Add a NodeType enum field if needed: NodeType node_type;
   // Add line number tracking: int lineno;
   int dot_id; // Unique ID for DOT graph generation
   void (*free_node)(struct BaseAST* node); // Function pointer for freeing node-specific data
} BaseAST;

// --- Helper for Lists (using a simple linked list) ---
typedef struct ASTListNode {
    BaseAST* item;
    struct ASTListNode* next;
} ASTListNode;

// Generic function to add an item to a linked list (Declaration only)
void add_ast_list_node(ASTListNode** head, BaseAST* item);

// Generic function to free a linked list (Declaration only)
void free_ast_list(ASTListNode* head);


// --- AST Node Definitions (C Structs) ---

// Represents a list in the grammar (e.g., CompUnitItemList, DefList, InitValList)
// Using a generic linked list approach for simplicity.
typedef struct ASTList {
    BaseAST base;        // Inherit base fields (like free_node)
    ASTListNode* head;  // Head of the linked list
} ASTList; // Use this for CompUnitListAST, DefListAST, InitListAST, DimListAST, ParamListAST, BlockListAST, ArgListAST


// CompUnit ::= CompUnitItemList
typedef struct CompUnitAST {
    BaseAST base;
    ASTList* items; // Points to an ASTList structure containing CompUnitItems
} CompUnitAST;

// CompUnitItem ::= Decl | FuncDef | MainFuncDef (Handled by the items list in CompUnitAST)

// Decl ::= ConstDecl | VarDecl (Handled by specific Decl types below)

// ConstDecl ::= CONSTTK BType ConstDefList SEMICN
typedef struct ConstDeclListAST {
    BaseAST base;
    TypeAST* btype;
    ASTList* const_defs; // List of ConstDef
} ConstDeclListAST;

// ConstDef ::= IDENT ArrayDimensionsOpt ASSIGN ConstInitVal
typedef struct ConstDefAST {
    BaseAST base;
    char* ident; // Remember to free!
    ASTList* array_dims; // List of ConstExp for dimensions (or NULL)
    BaseAST* init_val; // ConstInitVal node
} ConstDefAST;

// BType ::= INTTK | ...
typedef struct TypeAST {
    BaseAST base;
    SysYType type;
} TypeAST;

// ConstInitVal ::= ConstExp | LBRACE ConstInitValListOpt RBRACE
// ConstInitValListOpt ::= /* empty */ | ConstInitValList
// ConstInitValList ::= ConstInitVal | ConstInitValList COMMA ConstInitVal
// InitVal, InitValListOpt, InitValList are similar (reuse ASTList for lists)
// For single values like ConstExp or Exp, point directly to that node.
// For lists like {1, 2}, use an ASTList containing ConstExp/Exp nodes.

// VarDecl ::= BType VarDefList SEMICN
typedef struct VarDeclListAST {
    BaseAST base;
    TypeAST* btype;
    ASTList* var_defs; // List of VarDef
} VarDeclListAST;

// VarDef ::= IDENT ArrayDimensionsOpt AssignInitValOpt
typedef struct VarDefAST {
    BaseAST base;
    char* ident; // Remember to free!
    ASTList* array_dims; // List of ConstExp for dimensions (or NULL)
    BaseAST* init_val; // InitVal node (or NULL if no assignment)
} VarDefAST;

// ArrayDimensionsOpt ::= /* empty */ | ArrayDimensions
// ArrayDimensions ::= LBRACK ConstExp RBRACK | ArrayDimensions LBRACK ConstExp RBRACK
// Use ASTList containing ConstExp nodes for ArrayDimensions.

// AssignInitValOpt ::= /* empty */ | ASSIGN InitVal
// Handled within VarDefAST (init_val field is NULL or points to InitVal)

// FuncPrefix ::= (INTTK | VOIDTK) IDENT
typedef struct FuncIdInfoAST {
    BaseAST base;
    SysYType return_type;
    char* ident; // Remember to free!
} FuncIdInfoAST;

// FuncDef ::= FuncPrefix LPARENT FuncFParams? RPARENT Block
typedef struct FuncDefAST {
    BaseAST base;
    FuncIdInfoAST* prefix;
    ASTList* params; // List of FuncFParam (or NULL)
    ASTList* block; // Block node (represented as ASTList of BlockItems)
} FuncDefAST;

// MainFuncDef ::= INTTK MAINTK LPARENT RPARENT Block
typedef struct MainFuncDefAST {
    BaseAST base;
    ASTList* block; // Block node (represented as ASTList of BlockItems)
} MainFuncDefAST;

// FuncFParams ::= FuncFParam | FuncFParams COMMA FuncFParam
// Use ASTList containing FuncParamAST nodes.

// FuncFParam ::= BType IDENT ArrayDimensionsOpt // SysY allows array params
typedef struct FuncParamAST {
    BaseAST base;
    TypeAST* btype;
    char* ident; // Remember to free!
    int is_array; // Flag indicating if it's an array parameter (e.g., int a[])
    ASTList* array_dims; // Dimensions (often first dim is empty for params) - or NULL
} FuncParamAST;

// Block ::= LBRACE BlockItemList? RBRACE
// BlockItemList ::= BlockItem | BlockItemList BlockItem
// BlockItem ::= Decl | Stmt
// Use ASTList containing Decl or Stmt nodes for Block and BlockItemList.

// --- Statements ---

// Stmt ::= LVal ASSIGN Exp SEMICN
typedef struct AssignStmtAST {
    BaseAST base;
    BaseAST* lval; // LVal node (VarRefAST)
    BaseAST* exp;  // Expression node
} AssignStmtAST;

// Stmt ::= Exp SEMICN
typedef struct ExpStmtAST {
    BaseAST base;
    BaseAST* exp; // Expression node (or NULL if just SEMICN)
} ExpStmtAST;

// Stmt ::= SEMICN (Represented by ExpStmtAST with exp = NULL, or a dedicated type)
typedef struct EmptyStmtAST {
    BaseAST base;
} EmptyStmtAST;


// Stmt ::= Block (Represented by the Block's ASTList)

// Stmt ::= IFTK LPARENT Cond RPARENT Stmt (ELSETK Stmt)?
typedef struct IfStmtAST {
    BaseAST base;
    BaseAST* cond; // Condition expression
    BaseAST* then_stmt; // Statement or Block
    BaseAST* else_stmt; // Statement or Block (or NULL)
} IfStmtAST;

// Stmt ::= WHILETK LPARENT Cond RPARENT Stmt
typedef struct WhileStmtAST {
    BaseAST base;
    BaseAST* cond; // Condition expression
    BaseAST* body_stmt; // Statement or Block
} WhileStmtAST;

// Stmt ::= BREAKTK SEMICN
typedef struct BreakStmtAST {
    BaseAST base;
} BreakStmtAST;

// Stmt ::= CONTINUETK SEMICN
typedef struct ContinueStmtAST {
    BaseAST base;
} ContinueStmtAST;

// Stmt ::= RETURNTK Exp? SEMICN
typedef struct ReturnStmtAST {
    BaseAST base;
    BaseAST* return_exp; // Expression node (or NULL)
} ReturnStmtAST;

// Stmt ::= PRINTFTK LPARENT STR_CONST (COMMA FuncRParams)? RPARENT SEMICN
typedef struct PrintfStmtAST {
    BaseAST base;
    char* format_str; // Remember to free!
    ASTList* args; // List of expression nodes (or NULL)
} PrintfStmtAST;

// --- Expressions ---

// LVal ::= IDENT (LBRACK Exp RBRACK)* // Simplified: handle one level of array access
typedef struct VarRefAST {
    BaseAST base;
    char* ident; // Remember to free!
    ASTList* array_indices; // List of Exp nodes for indices (or NULL)
} VarRefAST;

// Number ::= INT_CONST
typedef struct NumberAST {
    BaseAST base;
    int value;
} NumberAST;

// UnaryExp ::= PrimaryExp | (PLUS | MINU | NOT) UnaryExp | Call
typedef struct UnaryOpAST {
    BaseAST base;
    UnaryOp op;
    BaseAST* operand; // Expression node
} UnaryOpAST;

// Binary Expressions (AddExp, MulExp, RelExp, EqExp, LAndExp, LOrExp)
typedef struct BinaryOpAST {
    BaseAST base;
    BinaryOp op;
    BaseAST* left_operand;
    BaseAST* right_operand;
} BinaryOpAST;

// FuncCall ::= IDENT LPARENT FuncRParams? RPARENT
typedef struct FuncCallAST {
    BaseAST base;
    char* func_ident; // Remember to free!
    ASTList* args;   // List of expression nodes (or NULL)
} FuncCallAST;

// GETINTTK LPARENT RPARENT
typedef struct GetIntAST {
    BaseAST base;
} GetIntAST;

// PrimaryExp ::= LPARENT Exp RPARENT | LVal | Number
// Exp, Cond simply pass through their child nodes.


// --- Helper Function Declarations ---

// Function to create a new AST node (allocates and initializes base)
// Specific create functions are needed for each node type.
// BaseAST* create_base_ast(size_t specific_node_size, void (*free_func)(BaseAST*));
void init_base_ast(BaseAST* node, NodeType type, void (*free_func)(BaseAST*)); // Add NodeType type

// Specific node creation functions
CompUnitAST* create_comp_unit(ASTList* items);
ASTList* create_ast_list(); // Creates an empty list container
ConstDeclListAST* create_const_decl_list(TypeAST* btype, ASTList* defs);
ConstDefAST* create_const_def(char* ident, ASTList* dims, BaseAST* init_val);
TypeAST* create_type(SysYType type);
VarDeclListAST* create_var_decl_list(TypeAST* btype, ASTList* defs);
VarDefAST* create_var_def(char* ident, ASTList* dims, BaseAST* init_val);
FuncIdInfoAST* create_func_id_info(SysYType ret_type, char* ident);
FuncDefAST* create_func_def(FuncIdInfoAST* prefix, ASTList* params, ASTList* block);
MainFuncDefAST* create_main_func_def(ASTList* block);
FuncParamAST* create_func_param(TypeAST* btype, char* ident, int is_array, ASTList* dims);
AssignStmtAST* create_assign_stmt(BaseAST* lval, BaseAST* exp);
ExpStmtAST* create_exp_stmt(BaseAST* exp);
EmptyStmtAST* create_empty_stmt();
IfStmtAST* create_if_stmt(BaseAST* cond, BaseAST* then_stmt, BaseAST* else_stmt);
WhileStmtAST* create_while_stmt(BaseAST* cond, BaseAST* body);
BreakStmtAST* create_break_stmt();
ContinueStmtAST* create_continue_stmt();
ReturnStmtAST* create_return_stmt(BaseAST* exp);
PrintfStmtAST* create_printf_stmt(char* format, ASTList* args);
VarRefAST* create_var_ref(char* ident, ASTList* indices);
NumberAST* create_number(int value);
UnaryOpAST* create_unary_op(UnaryOp op, BaseAST* operand);
BinaryOpAST* create_binary_op(BinaryOp op, BaseAST* left, BaseAST* right);
FuncCallAST* create_func_call(char* func_ident, ASTList* args);
GetIntAST* create_getint();


// Function to free the entire AST tree starting from the root (Declaration only)
void free_ast(BaseAST* root);

// Specific free functions (Declarations only)
void free_default(BaseAST* node);
void free_ast_list_node(BaseAST* node); // Frees an ASTList
void free_const_decl_list(BaseAST* node);
void free_const_def(BaseAST* node);
void free_var_decl_list(BaseAST* node);
void free_var_def(BaseAST* node);
void free_func_id_info(BaseAST* node);
void free_func_def(BaseAST* node);
void free_main_func_def(BaseAST* node);
void free_func_param(BaseAST* node);
void free_assign_stmt(BaseAST* node);
void free_exp_stmt(BaseAST* node);
void free_if_stmt(BaseAST* node);
void free_while_stmt(BaseAST* node);
void free_return_stmt(BaseAST* node);
void free_printf_stmt(BaseAST* node);
void free_var_ref(BaseAST* node);
void free_unary_op(BaseAST* node);
void free_binary_op(BaseAST* node);
void free_func_call(BaseAST* node);

// Declaration for the DOT dump function
char* dump_ast_dot(BaseAST* root);

// REMOVE inline implementations for add_ast_list_node and free_default from here

#endif // AST_H


