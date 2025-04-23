#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// --- DOT Dump Function Declarations ---
static void assign_dot_ids(BaseAST* node, int* counter);
static void assign_list_ids(ASTList* list, int* counter);
static void dump_all_nodes_dot(BaseAST* node, FILE* fp);
static void dump_list_nodes_dot(ASTList* list, FILE* fp);
static void dump_all_edges_dot(BaseAST* node, FILE* fp);
static void dump_list_edges_dot(ASTList* list, int parent_id, const char* edge_label_base, FILE* fp);

// Add missing forward declarations for helper functions used in dump_all_nodes_dot
static const char* node_type_to_string(NodeType type);
static const char* systype_to_string(SysYType type);
static const char* unaryop_to_string(UnaryOp op);
static const char* binaryop_to_string(BinaryOp op);

// Simple helper for unique node IDs in DOT
static int dot_node_counter = 0;
static int get_node_id(BaseAST* node) {
    // In a more robust implementation, you might store the ID in the node itself
    // or use the pointer address as a unique identifier.
    // Using a simple counter for this example.
    (void)node; // Avoid unused parameter warning if node isn't used directly
    return dot_node_counter++;
}

// --- Implementation of Helper Functions ---

// Implementation for add_ast_list_node
void add_ast_list_node(ASTListNode** head, BaseAST* item) {
    ASTListNode* new_node = (ASTListNode*)malloc(sizeof(ASTListNode));
    if (!new_node) {
        perror("Failed to allocate AST list node");
        exit(EXIT_FAILURE);
    }
    new_node->item = item;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        ASTListNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Initialize base AST fields
void init_base_ast(BaseAST* node, NodeType type, void (*free_func)(BaseAST*)) {
    node->node_type = type;
    node->dot_id = -1; // Initialize dot_id
    node->free_node = free_func ? free_func : free_default;
}

// Create an empty ASTList container
ASTList* create_ast_list() {
    ASTList* list = (ASTList*)malloc(sizeof(ASTList));
    if (!list) {
        perror("Failed to allocate ASTList");
        exit(EXIT_FAILURE);
    }
    init_base_ast((BaseAST*)list, NODE_ASTLIST, free_ast_list_node);
    list->head = NULL;
    return list;
}

// --- Specific Node Creation Functions ---

CompUnitAST* create_comp_unit(ASTList* items) {
    CompUnitAST* node = (CompUnitAST*)malloc(sizeof(CompUnitAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_COMPUNIT, free_default);
    node->items = items;
    return node;
}

ConstDeclListAST* create_const_decl_list(TypeAST* btype, ASTList* defs) {
    ConstDeclListAST* node = (ConstDeclListAST*)malloc(sizeof(ConstDeclListAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_CONSTDECLLIST, free_const_decl_list);
    node->btype = btype;
    node->const_defs = defs;
    return node;
}

ConstDefAST* create_const_def(char* ident, ASTList* dims, BaseAST* init_val) {
    ConstDefAST* node = (ConstDefAST*)malloc(sizeof(ConstDefAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_CONSTDEF, free_const_def);
    node->ident = ident;
    node->array_dims = dims;
    node->init_val = init_val;
    return node;
}

TypeAST* create_type(SysYType type) {
    TypeAST* node = (TypeAST*)malloc(sizeof(TypeAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_TYPE, free_default);
    node->type = type;
    return node;
}

VarDeclListAST* create_var_decl_list(TypeAST* btype, ASTList* defs) {
    VarDeclListAST* node = (VarDeclListAST*)malloc(sizeof(VarDeclListAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_VARDECLLIST, free_var_decl_list);
    node->btype = btype;
    node->var_defs = defs;
    return node;
}

VarDefAST* create_var_def(char* ident, ASTList* dims, BaseAST* init_val) {
    VarDefAST* node = (VarDefAST*)malloc(sizeof(VarDefAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_VARDEF, free_var_def);
    node->ident = ident;
    node->array_dims = dims;
    node->init_val = init_val;
    return node;
}

FuncIdInfoAST* create_func_id_info(SysYType ret_type, char* ident) {
    FuncIdInfoAST* node = (FuncIdInfoAST*)malloc(sizeof(FuncIdInfoAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_FUNCIDINFO, free_func_id_info);
    node->return_type = ret_type;
    node->ident = ident;
    return node;
}

FuncDefAST* create_func_def(FuncIdInfoAST* prefix, ASTList* params, ASTList* block) {
    FuncDefAST* node = (FuncDefAST*)malloc(sizeof(FuncDefAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_FUNCDEF, free_func_def);
    node->prefix = prefix;
    node->params = params;
    node->block = block;
    return node;
}

MainFuncDefAST* create_main_func_def(ASTList* block) {
    MainFuncDefAST* node = (MainFuncDefAST*)malloc(sizeof(MainFuncDefAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_MAINFUNCDEF, free_main_func_def);
    node->block = block;
    return node;
}

FuncParamAST* create_func_param(TypeAST* btype, char* ident, int is_array, ASTList* dims) {
    FuncParamAST* node = (FuncParamAST*)malloc(sizeof(FuncParamAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_FUNCPARAM, free_func_param);
    node->btype = btype;
    node->ident = ident;
    node->is_array = is_array;
    node->array_dims = dims;
    return node;
}

AssignStmtAST* create_assign_stmt(BaseAST* lval, BaseAST* exp) {
    AssignStmtAST* node = (AssignStmtAST*)malloc(sizeof(AssignStmtAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_ASSIGNSTMT, free_assign_stmt);
    node->lval = lval;
    node->exp = exp;
    return node;
}

ExpStmtAST* create_exp_stmt(BaseAST* exp) {
    ExpStmtAST* node = (ExpStmtAST*)malloc(sizeof(ExpStmtAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_EXPSTMT, free_exp_stmt);
    node->exp = exp;
    return node;
}

EmptyStmtAST* create_empty_stmt() {
    EmptyStmtAST* node = (EmptyStmtAST*)malloc(sizeof(EmptyStmtAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_EMPTYSTMT, free_default);
    return node;
}

IfStmtAST* create_if_stmt(BaseAST* cond, BaseAST* then_stmt, BaseAST* else_stmt) {
    IfStmtAST* node = (IfStmtAST*)malloc(sizeof(IfStmtAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_IFSTMT, free_if_stmt);
    node->cond = cond;
    node->then_stmt = then_stmt;
    node->else_stmt = else_stmt;
    return node;
}

WhileStmtAST* create_while_stmt(BaseAST* cond, BaseAST* body) {
    WhileStmtAST* node = (WhileStmtAST*)malloc(sizeof(WhileStmtAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_WHILESTMT, free_while_stmt);
    node->cond = cond;
    node->body_stmt = body;
    return node;
}

BreakStmtAST* create_break_stmt() {
    BreakStmtAST* node = (BreakStmtAST*)malloc(sizeof(BreakStmtAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_BREAKSTMT, free_default);
    return node;
}

ContinueStmtAST* create_continue_stmt() {
    ContinueStmtAST* node = (ContinueStmtAST*)malloc(sizeof(ContinueStmtAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_CONTINUESTMT, free_default);
    return node;
}

ReturnStmtAST* create_return_stmt(BaseAST* exp) {
    ReturnStmtAST* node = (ReturnStmtAST*)malloc(sizeof(ReturnStmtAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_RETURNSTMT, free_return_stmt);
    node->return_exp = exp;
    return node;
}

PrintfStmtAST* create_printf_stmt(char* format, ASTList* args) {
    PrintfStmtAST* node = (PrintfStmtAST*)malloc(sizeof(PrintfStmtAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_PRINTFSTMT, free_printf_stmt);
    node->format_str = format;
    node->args = args;
    return node;
}

VarRefAST* create_var_ref(char* ident, ASTList* indices) {
    VarRefAST* node = (VarRefAST*)malloc(sizeof(VarRefAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_VARREF, free_var_ref);
    node->ident = ident;
    node->array_indices = indices;
    return node;
}

NumberAST* create_number(int value) {
    NumberAST* node = (NumberAST*)malloc(sizeof(NumberAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_NUMBER, free_default);
    node->value = value;
    return node;
}

UnaryOpAST* create_unary_op(UnaryOp op, BaseAST* operand) {
    UnaryOpAST* node = (UnaryOpAST*)malloc(sizeof(UnaryOpAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_UNARYOP, free_unary_op);
    node->op = op;
    node->operand = operand;
    return node;
}

BinaryOpAST* create_binary_op(BinaryOp op, BaseAST* left, BaseAST* right) {
    BinaryOpAST* node = (BinaryOpAST*)malloc(sizeof(BinaryOpAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_BINARYOP, free_binary_op);
    node->op = op;
    node->left_operand = left;
    node->right_operand = right;
    return node;
}

FuncCallAST* create_func_call(char* func_ident, ASTList* args) {
    FuncCallAST* node = (FuncCallAST*)malloc(sizeof(FuncCallAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_FUNCCALL, free_func_call);
    node->func_ident = func_ident;
    node->args = args;
    return node;
}

GetIntAST* create_getint() {
    GetIntAST* node = (GetIntAST*)malloc(sizeof(GetIntAST));
    if (!node) { perror("malloc failed"); exit(EXIT_FAILURE); }
    init_base_ast((BaseAST*)node, NODE_GETINT, free_default);
    return node;
}

// --- DOT Dump Function Implementations ---

// Main function to generate DOT output for the entire AST
// For simplicity, this prints to stdout. Could be modified to return a string.
void dump_ast_dot_to_file(BaseAST* root, const char* filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("Failed to open DOT output file");
        return;
    }

    fprintf(fp, "digraph AST {\n");
    fprintf(fp, "  node [shape=box, style=filled, fontname=\"Helvetica\"];\n"); // Default style

    if (root) {
        int node_counter = 0;
        // Pass 1: Assign unique IDs
        assign_dot_ids(root, &node_counter);

        // Pass 2: Dump all node definitions
        dump_all_nodes_dot(root, fp);

        // Pass 3: Dump all edge definitions
        dump_all_edges_dot(root, fp);
    }

    fprintf(fp, "}\n");
    fclose(fp);
    printf("AST DOT graph saved to %s\n", filename);
}


// --- Pass 1: Assign DOT IDs ---
static void assign_dot_ids(BaseAST* node, int* counter) {
    if (!node || node->dot_id != -1) return; // Already visited or NULL

    node->dot_id = (*counter)++; // Assign current ID and increment

    // Recursively assign IDs to children based on node type
    switch (node->node_type) {
        case NODE_COMPUNIT:
            assign_list_ids(((CompUnitAST*)node)->items, counter);
            break;
        case NODE_CONSTDECLLIST: {
            ConstDeclListAST* n = (ConstDeclListAST*)node;
            assign_dot_ids((BaseAST*)n->btype, counter);
            assign_list_ids(n->const_defs, counter);
            break;
        }
        case NODE_CONSTDEF: {
            ConstDefAST* n = (ConstDefAST*)node;
            assign_list_ids(n->array_dims, counter);
            assign_dot_ids(n->init_val, counter);
            break;
        }
        case NODE_TYPE: /* Leaf node */ break;
        case NODE_VARDECLLIST: {
            VarDeclListAST* n = (VarDeclListAST*)node;
            assign_dot_ids((BaseAST*)n->btype, counter);
            assign_list_ids(n->var_defs, counter);
            break;
        }
        case NODE_VARDEF: {
            VarDefAST* n = (VarDefAST*)node;
            assign_list_ids(n->array_dims, counter);
            assign_dot_ids(n->init_val, counter);
            break;
        }
        case NODE_FUNCIDINFO: /* Leaf node (contains data, not child nodes) */ break;
        case NODE_FUNCDEF: {
            FuncDefAST* n = (FuncDefAST*)node;
            assign_dot_ids((BaseAST*)n->prefix, counter);
            assign_list_ids(n->params, counter);
            assign_list_ids(n->block, counter); // Block is a list
            break;
        }
        case NODE_MAINFUNCDEF:
            assign_list_ids(((MainFuncDefAST*)node)->block, counter); // Block is a list
            break;
        case NODE_FUNCPARAM: {
            FuncParamAST* n = (FuncParamAST*)node;
            assign_dot_ids((BaseAST*)n->btype, counter);
            assign_list_ids(n->array_dims, counter);
            break;
        }
        case NODE_ASSIGNSTMT: {
            AssignStmtAST* n = (AssignStmtAST*)node;
            assign_dot_ids(n->lval, counter);
            assign_dot_ids(n->exp, counter);
            break;
        }
        case NODE_EXPSTMT:
            assign_dot_ids(((ExpStmtAST*)node)->exp, counter);
            break;
        case NODE_EMPTYSTMT: /* Leaf node */ break;
        case NODE_IFSTMT: {
            IfStmtAST* n = (IfStmtAST*)node;
            assign_dot_ids(n->cond, counter);
            assign_dot_ids(n->then_stmt, counter);
            assign_dot_ids(n->else_stmt, counter);
            break;
        }
        case NODE_WHILESTMT: {
            WhileStmtAST* n = (WhileStmtAST*)node;
            assign_dot_ids(n->cond, counter);
            assign_dot_ids(n->body_stmt, counter);
            break;
        }
        case NODE_BREAKSTMT: /* Leaf node */ break;
        case NODE_CONTINUESTMT: /* Leaf node */ break;
        case NODE_RETURNSTMT:
            assign_dot_ids(((ReturnStmtAST*)node)->return_exp, counter);
            break;
        case NODE_PRINTFSTMT:
            assign_list_ids(((PrintfStmtAST*)node)->args, counter);
            break;
        case NODE_VARREF:
            assign_list_ids(((VarRefAST*)node)->array_indices, counter);
            break;
        case NODE_NUMBER: /* Leaf node */ break;
        case NODE_UNARYOP:
            assign_dot_ids(((UnaryOpAST*)node)->operand, counter);
            break;
        case NODE_BINARYOP: {
            BinaryOpAST* n = (BinaryOpAST*)node;
            assign_dot_ids(n->left_operand, counter);
            assign_dot_ids(n->right_operand, counter);
            break;
        }
        case NODE_FUNCCALL:
            assign_list_ids(((FuncCallAST*)node)->args, counter);
            break;
        case NODE_GETINT: /* Leaf node */ break;
        case NODE_ASTLIST: // Should be handled by assign_list_ids
             fprintf(stderr, "Warning: assign_dot_ids called directly on ASTList\n");
             assign_list_ids((ASTList*)node, counter);
            break;
        default:
            fprintf(stderr, "Warning: Unhandled node type %d in assign_dot_ids\n", node->node_type);
            break;
    }
}

static void assign_list_ids(ASTList* list, int* counter) {
    if (!list) return;
    ASTListNode* current = list->head;
    while (current) {
        assign_dot_ids(current->item, counter);
        current = current->next;
    }
}


// --- Pass 2: Dump Node Definitions ---
static void dump_all_nodes_dot(BaseAST* node, FILE* fp) {
    if (!node || node->dot_id == -1) return; // Should have ID assigned

    char label[512];
    const char* shape = "box";
    const char* fillcolor = "lightgrey";
    int current_id = node->dot_id;

    // Determine label, shape, fillcolor based on type
    switch (node->node_type) {
        case NODE_COMPUNIT:
            snprintf(label, sizeof(label), "CompUnit");
            fillcolor="lightblue";
            break;
        case NODE_CONSTDECLLIST:
             snprintf(label, sizeof(label), "ConstDeclList");
             fillcolor = "lightyellow";
             break;
         case NODE_CONSTDEF: {
             ConstDefAST* n = (ConstDefAST*)node;
             snprintf(label, sizeof(label), "ConstDef\\nident: %s", n->ident);
             fillcolor = "yellow";
             break;
         }
         case NODE_TYPE: {
             TypeAST* n = (TypeAST*)node;
             snprintf(label, sizeof(label), "Type: %s", systype_to_string(n->type));
             shape = "ellipse";
             fillcolor = "white";
             break;
         }
        case NODE_VARDECLLIST:
             snprintf(label, sizeof(label), "VarDeclList");
             fillcolor = "lightgreen";
             break;
         case NODE_VARDEF: {
             VarDefAST* n = (VarDefAST*)node;
             // Note: Removed (has init) for cleaner graph, init edge shows this
             snprintf(label, sizeof(label), "VarDef\\nident: %s", n->ident);
             fillcolor = "green";
             break;
         }
         case NODE_FUNCIDINFO: {
             FuncIdInfoAST* n = (FuncIdInfoAST*)node;
             snprintf(label, sizeof(label), "FuncIdInfo\\ntype: %s\\nident: %s", systype_to_string(n->return_type), n->ident);
             fillcolor = "orange";
             break;
         }
         case NODE_FUNCDEF:
             snprintf(label, sizeof(label), "FuncDef");
             fillcolor = "coral";
             break;
        case NODE_MAINFUNCDEF:
             snprintf(label, sizeof(label), "MainFuncDef");
             fillcolor = "red";
             break;
         case NODE_FUNCPARAM: {
            FuncParamAST* n = (FuncParamAST*)node;
            snprintf(label, sizeof(label), "FuncParam\\nident: %s%s", n->ident, n->is_array ? "\\n(array)" : "");
            fillcolor = "pink";
            break;
        }
        case NODE_ASSIGNSTMT:
            snprintf(label, sizeof(label), "AssignStmt");
            fillcolor = "lightblue";
            break;
        case NODE_EXPSTMT:
             snprintf(label, sizeof(label), "ExpStmt");
             fillcolor = "grey";
             break;
        case NODE_EMPTYSTMT:
             snprintf(label, sizeof(label), "EmptyStmt");
             fillcolor = "white";
             break;
        case NODE_IFSTMT:
            snprintf(label, sizeof(label), "IfStmt");
            fillcolor = "cyan";
            break;
        case NODE_WHILESTMT:
            snprintf(label, sizeof(label), "WhileStmt");
             fillcolor = "magenta";
             break;
        case NODE_BREAKSTMT:
             snprintf(label, sizeof(label), "BreakStmt");
             fillcolor = "tomato";
             break;
         case NODE_CONTINUESTMT:
             snprintf(label, sizeof(label), "ContinueStmt");
             fillcolor = "orange";
             break;
        case NODE_RETURNSTMT:
            snprintf(label, sizeof(label), "ReturnStmt");
             fillcolor = "gold";
            break;
        case NODE_PRINTFSTMT: {
             PrintfStmtAST* n = (PrintfStmtAST*)node;
             char escaped_format[256]; // Simple escaping for dot
             char* esc_ptr = escaped_format;
             const char* fmt_ptr = n->format_str ? n->format_str : "";
             while (*fmt_ptr && ((size_t)(esc_ptr - escaped_format)) < sizeof(escaped_format) - 3) {
                 if (*fmt_ptr == '\\\\' || *fmt_ptr == '"') *esc_ptr++ = '\\\\';
                 *esc_ptr++ = *fmt_ptr++;
             }
             *esc_ptr = '\0';
             snprintf(label, sizeof(label), "PrintfStmt\\nformat: \\\"%s\\\"", escaped_format);
             fillcolor = "skyblue";
             break;
         }
        case NODE_VARREF: {
             VarRefAST* n = (VarRefAST*)node;
             snprintf(label, sizeof(label), "VarRef\\nident: %s", n->ident);
             shape = "ellipse";
             fillcolor = "palegreen";
             break;
        }
        case NODE_NUMBER: {
            NumberAST* n = (NumberAST*)node;
            snprintf(label, sizeof(label), "Number\\nvalue: %d", n->value);
            shape = "ellipse";
            fillcolor = "pink";
            break;
        }
        case NODE_UNARYOP: {
            UnaryOpAST* n = (UnaryOpAST*)node;
            snprintf(label, sizeof(label), "UnaryOp\\nop: %s", unaryop_to_string(n->op));
            fillcolor = "purple"; // Example color
            break;
        }
        case NODE_BINARYOP: {
            BinaryOpAST* n = (BinaryOpAST*)node;
            snprintf(label, sizeof(label), "BinaryOp\\nop: %s", binaryop_to_string(n->op));
            fillcolor = "violet"; // Example color
            break;
        }
        case NODE_FUNCCALL: {
            FuncCallAST* n = (FuncCallAST*)node;
            snprintf(label, sizeof(label), "FuncCall\\nident: %s", n->func_ident);
            fillcolor = "yellowgreen";
            break;
        }
        case NODE_GETINT:
            snprintf(label, sizeof(label), "GetInt");
            fillcolor = "tan";
            break;
        case NODE_ASTLIST:
            // ASTList nodes are containers, don't print them directly.
            // Recurse into the list items instead.
            dump_list_nodes_dot((ASTList*)node, fp);
            return; // IMPORTANT: Return here to avoid printing the list node itself
        default:
            snprintf(label, sizeof(label), "Unknown Node\nType: %d", node->node_type);
            fillcolor = "black"; // Make errors obvious
            shape = "octagon";
            break;
    }

    // Print the node definition
    fprintf(fp, "  node%d [label=\"%s\", shape=%s, fillcolor=%s];\n",
            current_id, label, shape, fillcolor);

    // Recurse AFTER printing the current node's definition
    switch (node->node_type) {
        // Only recurse into children that ARE NOT lists (lists handled separately)
        case NODE_CONSTDECLLIST:
            dump_all_nodes_dot((BaseAST*)((ConstDeclListAST*)node)->btype, fp);
            dump_list_nodes_dot(((ConstDeclListAST*)node)->const_defs, fp);
            break;
        case NODE_CONSTDEF:
            dump_list_nodes_dot(((ConstDefAST*)node)->array_dims, fp);
            dump_all_nodes_dot(((ConstDefAST*)node)->init_val, fp);
            break;
        case NODE_VARDECLLIST:
            dump_all_nodes_dot((BaseAST*)((VarDeclListAST*)node)->btype, fp);
            dump_list_nodes_dot(((VarDeclListAST*)node)->var_defs, fp);
            break;
        case NODE_VARDEF:
            dump_list_nodes_dot(((VarDefAST*)node)->array_dims, fp);
            dump_all_nodes_dot(((VarDefAST*)node)->init_val, fp);
            break;
        case NODE_FUNCDEF:
            dump_all_nodes_dot((BaseAST*)((FuncDefAST*)node)->prefix, fp);
            dump_list_nodes_dot(((FuncDefAST*)node)->params, fp);
            dump_list_nodes_dot(((FuncDefAST*)node)->block, fp);
            break;
        case NODE_MAINFUNCDEF:
            dump_list_nodes_dot(((MainFuncDefAST*)node)->block, fp);
            break;
        case NODE_FUNCPARAM:
             dump_all_nodes_dot((BaseAST*)((FuncParamAST*)node)->btype, fp);
             dump_list_nodes_dot(((FuncParamAST*)node)->array_dims, fp);
             break;
        case NODE_ASSIGNSTMT:
            dump_all_nodes_dot(((AssignStmtAST*)node)->lval, fp);
            dump_all_nodes_dot(((AssignStmtAST*)node)->exp, fp);
            break;
        case NODE_EXPSTMT:
            dump_all_nodes_dot(((ExpStmtAST*)node)->exp, fp);
            break;
        case NODE_IFSTMT:
            dump_all_nodes_dot(((IfStmtAST*)node)->cond, fp);
            dump_all_nodes_dot(((IfStmtAST*)node)->then_stmt, fp);
            dump_all_nodes_dot(((IfStmtAST*)node)->else_stmt, fp);
            break;
        case NODE_WHILESTMT:
            dump_all_nodes_dot(((WhileStmtAST*)node)->cond, fp);
            dump_all_nodes_dot(((WhileStmtAST*)node)->body_stmt, fp);
            break;
        case NODE_RETURNSTMT:
            dump_all_nodes_dot(((ReturnStmtAST*)node)->return_exp, fp);
            break;
        case NODE_PRINTFSTMT:
             dump_list_nodes_dot(((PrintfStmtAST*)node)->args, fp);
             break;
        case NODE_VARREF:
             dump_list_nodes_dot(((VarRefAST*)node)->array_indices, fp);
             break;
        case NODE_UNARYOP:
            dump_all_nodes_dot(((UnaryOpAST*)node)->operand, fp);
            break;
        case NODE_BINARYOP:
            dump_all_nodes_dot(((BinaryOpAST*)node)->left_operand, fp);
            dump_all_nodes_dot(((BinaryOpAST*)node)->right_operand, fp);
            break;
        case NODE_FUNCCALL:
             dump_list_nodes_dot(((FuncCallAST*)node)->args, fp);
             break;
        case NODE_COMPUNIT: // Handles its list items
             dump_list_nodes_dot(((CompUnitAST*)node)->items, fp);
             break;
         // Leaf nodes and list nodes handled above or have no children to recurse into here
        case NODE_TYPE:
        case NODE_FUNCIDINFO:
        case NODE_EMPTYSTMT:
        case NODE_BREAKSTMT:
        case NODE_CONTINUESTMT:
        case NODE_NUMBER:
        case NODE_GETINT:
        case NODE_ASTLIST: // Already handled
        default:
             break; // No standard children to recurse into
    }
}

static void dump_list_nodes_dot(ASTList* list, FILE* fp) {
    if (!list) return;
    ASTListNode* current = list->head;
    while (current) {
        dump_all_nodes_dot(current->item, fp); // Dump each item in the list
        current = current->next;
    }
}


// --- Pass 3: Dump Edge Definitions ---
static void dump_all_edges_dot(BaseAST* node, FILE* fp) {
     if (!node || node->dot_id == -1) return; // Should have ID assigned

     int current_id = node->dot_id;

     // Print edges based on node type and recurse
     switch (node->node_type) {
        case NODE_COMPUNIT:
             dump_list_edges_dot(((CompUnitAST*)node)->items, current_id, "item", fp);
             break;
        case NODE_CONSTDECLLIST: {
            ConstDeclListAST* n = (ConstDeclListAST*)node;
            if (n->btype) fprintf(fp, "  node%d -> node%d [label=\"type\"];\n", current_id, n->btype->base.dot_id);
            dump_all_edges_dot((BaseAST*)n->btype, fp);
            dump_list_edges_dot(n->const_defs, current_id, "def", fp);
            break;
        }
        case NODE_CONSTDEF: {
            ConstDefAST* n = (ConstDefAST*)node;
            dump_list_edges_dot(n->array_dims, current_id, "dim", fp);
            if (n->init_val) fprintf(fp, "  node%d -> node%d [label=\"init\"];\n", current_id, n->init_val->dot_id);
            dump_all_edges_dot(n->init_val, fp);
            break;
        }
        case NODE_TYPE: /* Leaf */ break;
        case NODE_VARDECLLIST: {
            VarDeclListAST* n = (VarDeclListAST*)node;
            if (n->btype) fprintf(fp, "  node%d -> node%d [label=\"type\"];\n", current_id, n->btype->base.dot_id);
            dump_all_edges_dot((BaseAST*)n->btype, fp);
            dump_list_edges_dot(n->var_defs, current_id, "def", fp);
            break;
        }
        case NODE_VARDEF: {
            VarDefAST* n = (VarDefAST*)node;
            dump_list_edges_dot(n->array_dims, current_id, "dim", fp);
            if (n->init_val) fprintf(fp, "  node%d -> node%d [label=\"init\"];\n", current_id, n->init_val->dot_id);
            dump_all_edges_dot(n->init_val, fp);
            break;
        }
        case NODE_FUNCIDINFO: /* Leaf */ break;
        case NODE_FUNCDEF: {
            FuncDefAST* n = (FuncDefAST*)node;
            if (n->prefix) fprintf(fp, "  node%d -> node%d [label=\"prefix\"];\n", current_id, n->prefix->base.dot_id);
            dump_all_edges_dot((BaseAST*)n->prefix, fp);
            dump_list_edges_dot(n->params, current_id, "param", fp);
            dump_list_edges_dot(n->block, current_id, "block_item", fp);
            break;
        }
        case NODE_MAINFUNCDEF:
            dump_list_edges_dot(((MainFuncDefAST*)node)->block, current_id, "block_item", fp);
            break;
        case NODE_FUNCPARAM: {
             FuncParamAST* n = (FuncParamAST*)node;
             if (n->btype) fprintf(fp, "  node%d -> node%d [label=\"type\"];\n", current_id, n->btype->base.dot_id);
             dump_all_edges_dot((BaseAST*)n->btype, fp);
             dump_list_edges_dot(n->array_dims, current_id, "dim", fp);
             break;
        }
        case NODE_ASSIGNSTMT: {
            AssignStmtAST* n = (AssignStmtAST*)node;
            if (n->lval) fprintf(fp, "  node%d -> node%d [label=\"lval\"];\n", current_id, n->lval->dot_id);
            dump_all_edges_dot(n->lval, fp);
            if (n->exp) fprintf(fp, "  node%d -> node%d [label=\"rval\"];\n", current_id, n->exp->dot_id);
            dump_all_edges_dot(n->exp, fp);
            break;
        }
        case NODE_EXPSTMT: {
             ExpStmtAST* n = (ExpStmtAST*)node;
             if (n->exp) fprintf(fp, "  node%d -> node%d [label=\"exp\"];\n", current_id, n->exp->dot_id);
             dump_all_edges_dot(n->exp, fp);
             break;
         }
        case NODE_EMPTYSTMT: /* Leaf */ break;
        case NODE_IFSTMT: {
            IfStmtAST* n = (IfStmtAST*)node;
            if (n->cond) fprintf(fp, "  node%d -> node%d [label=\"cond\"];\n", current_id, n->cond->dot_id);
            dump_all_edges_dot(n->cond, fp);
            if (n->then_stmt) fprintf(fp, "  node%d -> node%d [label=\"then\"];\n", current_id, n->then_stmt->dot_id);
            dump_all_edges_dot(n->then_stmt, fp);
            if (n->else_stmt) fprintf(fp, "  node%d -> node%d [label=\"else\"];\n", current_id, n->else_stmt->dot_id);
            dump_all_edges_dot(n->else_stmt, fp);
            break;
        }
        case NODE_WHILESTMT: {
            WhileStmtAST* n = (WhileStmtAST*)node;
            if (n->cond) fprintf(fp, "  node%d -> node%d [label=\"cond\"];\n", current_id, n->cond->dot_id);
            dump_all_edges_dot(n->cond, fp);
            if (n->body_stmt) fprintf(fp, "  node%d -> node%d [label=\"body\"];\n", current_id, n->body_stmt->dot_id);
            dump_all_edges_dot(n->body_stmt, fp);
            break;
        }
        case NODE_BREAKSTMT: /* Leaf */ break;
        case NODE_CONTINUESTMT: /* Leaf */ break;
        case NODE_RETURNSTMT: {
             ReturnStmtAST* n = (ReturnStmtAST*)node;
             if (n->return_exp) fprintf(fp, "  node%d -> node%d [label=\"value\"];\n", current_id, n->return_exp->dot_id);
             dump_all_edges_dot(n->return_exp, fp);
             break;
        }
        case NODE_PRINTFSTMT:
             dump_list_edges_dot(((PrintfStmtAST*)node)->args, current_id, "arg", fp);
             break;
        case NODE_VARREF:
             dump_list_edges_dot(((VarRefAST*)node)->array_indices, current_id, "index", fp); // Use "index" for clarity
             break;
        case NODE_NUMBER: /* Leaf */ break;
        case NODE_UNARYOP: {
            UnaryOpAST* n = (UnaryOpAST*)node;
            if (n->operand) fprintf(fp, "  node%d -> node%d [label=\"operand\"];\n", current_id, n->operand->dot_id);
            dump_all_edges_dot(n->operand, fp);
            break;
        }
        case NODE_BINARYOP: {
            BinaryOpAST* n = (BinaryOpAST*)node;
            if (n->left_operand) fprintf(fp, "  node%d -> node%d [label=\"lhs\"];\n", current_id, n->left_operand->dot_id);
            dump_all_edges_dot(n->left_operand, fp);
            if (n->right_operand) fprintf(fp, "  node%d -> node%d [label=\"rhs\"];\n", current_id, n->right_operand->dot_id);
            dump_all_edges_dot(n->right_operand, fp);
            break;
        }
        case NODE_FUNCCALL:
            dump_list_edges_dot(((FuncCallAST*)node)->args, current_id, "arg", fp);
            break;
        case NODE_GETINT: /* Leaf */ break;
        case NODE_ASTLIST:
            // Handled by dump_list_edges_dot called from parent
            dump_list_edges_dot((ASTList*)node, -1, "list_item", fp); // -1 indicates no direct parent edge
            break;
         default:
             // No edges to print or unknown node type
             break;
     }
}

static void dump_list_edges_dot(ASTList* list, int parent_id, const char* edge_label_base, FILE* fp) {
    if (!list) return;
    ASTListNode* current = list->head;
    int i = 0;
    while (current) {
        if (current->item && current->item->dot_id != -1) {
             // Only print edge if parent_id is valid (i.e., not called directly on list)
             if (parent_id != -1) {
                 fprintf(fp, "  node%d -> node%d [label=\"%s_%d\"];\n",
                        parent_id, current->item->dot_id, edge_label_base, i);
             }
            // Recurse to print edges originating FROM the list item
            dump_all_edges_dot(current->item, fp);
        }
        current = current->next;
        i++;
    }
}


// --- Helper Function Implementations (Keep These) ---
static const char* node_type_to_string(NodeType type) {
    switch(type) {
        // Add cases for all NodeType values
        case NODE_COMPUNIT: return "CompUnit";
        case NODE_NUMBER: return "Number";
        // ... etc. ...
        default: return "Unknown";
    }
}

static const char* systype_to_string(SysYType type) {
    switch(type) {
        case SYSY_INT: return "int";
        case SYSY_VOID: return "void";
        default: return "unknown";
    }
}

static const char* unaryop_to_string(UnaryOp op) {
     switch(op) {
        case UNARY_POS: return "+";
        case UNARY_NEG: return "-";
        case UNARY_NOT: return "!";
        default: return "?";
    }
}
static const char* binaryop_to_string(BinaryOp op) {
     switch(op) {
        case BINOP_ADD: return "+";
        case BINOP_SUB: return "-";
        case BINOP_MUL: return "*";
        case BINOP_DIV: return "/";
        case BINOP_MOD: return "%";
        case BINOP_LT: return "<";
        case BINOP_GT: return ">";
        case BINOP_LE: return "<=";
        case BINOP_GE: return ">=";
        case BINOP_EQ: return "==";
        case BINOP_NE: return "!=";
        case BINOP_LAND: return "&&";
        case BINOP_LOR: return "||";
        default: return "?";
    }
}


// --- Memory Management Functions ---

// Function to free the entire AST tree starting from the root
void free_ast(BaseAST* root) {
    if (!root) return;

    // Call the node-specific free function first (to handle children and specific data)
    if (root->free_node) {
        root->free_node(root);
    }

    // Then free the node itself (unless the specific free function already did)
    // Note: A convention is needed. Either specific free functions free the node,
    // or free_ast does. Here, we assume free_ast frees the node itself *after*
    // the specific function frees its contents.
    // Let's assume free_default does nothing and specific free functions
    // recursively call free_ast on children BUT DO NOT free the node itself.
    free(root);
}

// Generic function to free a linked list of AST nodes
void free_ast_list(ASTListNode* head) {
    ASTListNode* current = head;
    ASTListNode* next;
    while (current != NULL) {
        if (current->item) {
            free_ast(current->item); // Recursively free the item in the list
        }
        next = current->next;
        free(current); // Free the list node itself
        current = next;
    }
}

// --- Specific Free Functions ---

// Default free function (for nodes with no specific data or children to free)
void free_default(BaseAST* node) {
    // Does nothing extra by default. Child freeing is handled by recursion in free_ast
    // for nodes containing direct BaseAST pointers, or via list freeing for ASTList.
    (void)node; // Avoid unused parameter warning
}

// Free function for ASTList nodes
void free_ast_list_node(BaseAST* node) {
    if (!node) return;
    ASTList* list = (ASTList*)node;
    free_ast_list(list->head); // Free the linked list nodes and their items
    // Do not free 'list' itself here, free_ast() will do it.
}

void free_const_decl_list(BaseAST* node) {
    if (!node) return;
    ConstDeclListAST* specific_node = (ConstDeclListAST*)node;
    free_ast((BaseAST*)specific_node->btype);
    free_ast((BaseAST*)specific_node->const_defs); // Free the list
}

void free_const_def(BaseAST* node) {
    if (!node) return;
    ConstDefAST* specific_node = (ConstDefAST*)node;
    free(specific_node->ident); // Free the string
    free_ast((BaseAST*)specific_node->array_dims); // Free the list (if any)
    free_ast(specific_node->init_val);
}

void free_var_decl_list(BaseAST* node) {
    if (!node) return;
    VarDeclListAST* specific_node = (VarDeclListAST*)node;
    free_ast((BaseAST*)specific_node->btype);
    free_ast((BaseAST*)specific_node->var_defs); // Free the list
}

void free_var_def(BaseAST* node) {
    if (!node) return;
    VarDefAST* specific_node = (VarDefAST*)node;
    free(specific_node->ident); // Free the string
    free_ast((BaseAST*)specific_node->array_dims); // Free the list (if any)
    free_ast(specific_node->init_val);
}

void free_func_id_info(BaseAST* node) {
    if (!node) return;
    FuncIdInfoAST* specific_node = (FuncIdInfoAST*)node;
    free(specific_node->ident); // Free the string
}

void free_func_def(BaseAST* node) {
    if (!node) return;
    FuncDefAST* specific_node = (FuncDefAST*)node;
    free_ast((BaseAST*)specific_node->prefix);
    free_ast((BaseAST*)specific_node->params); // Free the list (if any)
    free_ast((BaseAST*)specific_node->block);  // Free the block list
}

void free_main_func_def(BaseAST* node) {
    if (!node) return;
    MainFuncDefAST* specific_node = (MainFuncDefAST*)node;
    free_ast((BaseAST*)specific_node->block); // Free the block list
}

void free_func_param(BaseAST* node) {
    if (!node) return;
    FuncParamAST* specific_node = (FuncParamAST*)node;
    free_ast((BaseAST*)specific_node->btype);
    free(specific_node->ident); // Free the string
    free_ast((BaseAST*)specific_node->array_dims); // Free the list (if any)
}

void free_assign_stmt(BaseAST* node) {
    if (!node) return;
    AssignStmtAST* specific_node = (AssignStmtAST*)node;
    free_ast(specific_node->lval);
    free_ast(specific_node->exp);
}

void free_exp_stmt(BaseAST* node) {
    if (!node) return;
    ExpStmtAST* specific_node = (ExpStmtAST*)node;
    free_ast(specific_node->exp); // Free expression (if any)
}

void free_if_stmt(BaseAST* node) {
    if (!node) return;
    IfStmtAST* specific_node = (IfStmtAST*)node;
    free_ast(specific_node->cond);
    free_ast(specific_node->then_stmt);
    free_ast(specific_node->else_stmt); // Free else (if any)
}

void free_while_stmt(BaseAST* node) {
    if (!node) return;
    WhileStmtAST* specific_node = (WhileStmtAST*)node;
    free_ast(specific_node->cond);
    free_ast(specific_node->body_stmt);
}

void free_return_stmt(BaseAST* node) {
    if (!node) return;
    ReturnStmtAST* specific_node = (ReturnStmtAST*)node;
    free_ast(specific_node->return_exp); // Free expression (if any)
}

void free_printf_stmt(BaseAST* node) {
    if (!node) return;
    PrintfStmtAST* specific_node = (PrintfStmtAST*)node;
    free(specific_node->format_str); // Free the format string
    free_ast((BaseAST*)specific_node->args); // Free the argument list (if any)
}

void free_var_ref(BaseAST* node) {
    if (!node) return;
    VarRefAST* specific_node = (VarRefAST*)node;
    free(specific_node->ident); // Free the identifier string
    free_ast((BaseAST*)specific_node->array_indices); // Free index list (if any)
}

void free_unary_op(BaseAST* node) {
    if (!node) return;
    UnaryOpAST* specific_node = (UnaryOpAST*)node;
    free_ast(specific_node->operand);
}

void free_binary_op(BaseAST* node) {
    if (!node) return;
    BinaryOpAST* specific_node = (BinaryOpAST*)node;
    free_ast(specific_node->left_operand);
    free_ast(specific_node->right_operand);
}

void free_func_call(BaseAST* node) {
    if (!node) return;
    FuncCallAST* specific_node = (FuncCallAST*)node;
    free(specific_node->func_ident); // Free the function name string
    free_ast((BaseAST*)specific_node->args); // Free argument list (if any)
} 