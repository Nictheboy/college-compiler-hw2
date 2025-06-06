/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "yacc.y"

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


#line 93 "yacc.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "yacc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENT = 3,                      /* IDENT  */
  YYSYMBOL_STR_CONST = 4,                  /* STR_CONST  */
  YYSYMBOL_INT_CONST = 5,                  /* INT_CONST  */
  YYSYMBOL_MAINTK = 6,                     /* MAINTK  */
  YYSYMBOL_CONSTTK = 7,                    /* CONSTTK  */
  YYSYMBOL_INTTK = 8,                      /* INTTK  */
  YYSYMBOL_BREAKTK = 9,                    /* BREAKTK  */
  YYSYMBOL_CONTINUETK = 10,                /* CONTINUETK  */
  YYSYMBOL_IFTK = 11,                      /* IFTK  */
  YYSYMBOL_ELSETK = 12,                    /* ELSETK  */
  YYSYMBOL_VOIDTK = 13,                    /* VOIDTK  */
  YYSYMBOL_WHILETK = 14,                   /* WHILETK  */
  YYSYMBOL_GETINTTK = 15,                  /* GETINTTK  */
  YYSYMBOL_PRINTFTK = 16,                  /* PRINTFTK  */
  YYSYMBOL_RETURNTK = 17,                  /* RETURNTK  */
  YYSYMBOL_NOT = 18,                       /* NOT  */
  YYSYMBOL_AND = 19,                       /* AND  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_PLUS = 21,                      /* PLUS  */
  YYSYMBOL_MINU = 22,                      /* MINU  */
  YYSYMBOL_MULT = 23,                      /* MULT  */
  YYSYMBOL_DIV = 24,                       /* DIV  */
  YYSYMBOL_MOD = 25,                       /* MOD  */
  YYSYMBOL_ASSIGN = 26,                    /* ASSIGN  */
  YYSYMBOL_SEMICN = 27,                    /* SEMICN  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_LPARENT = 29,                   /* LPARENT  */
  YYSYMBOL_RPARENT = 30,                   /* RPARENT  */
  YYSYMBOL_LBRACK = 31,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 32,                    /* RBRACK  */
  YYSYMBOL_LBRACE = 33,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 34,                    /* RBRACE  */
  YYSYMBOL_LSS = 35,                       /* LSS  */
  YYSYMBOL_LEQ = 36,                       /* LEQ  */
  YYSYMBOL_GRE = 37,                       /* GRE  */
  YYSYMBOL_GEQ = 38,                       /* GEQ  */
  YYSYMBOL_EQL = 39,                       /* EQL  */
  YYSYMBOL_NEQ = 40,                       /* NEQ  */
  YYSYMBOL_FUNCALL = 41,                   /* FUNCALL  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_CompUnit = 43,                  /* CompUnit  */
  YYSYMBOL_CompUnitItemList = 44,          /* CompUnitItemList  */
  YYSYMBOL_CompUnitItem = 45,              /* CompUnitItem  */
  YYSYMBOL_Decl = 46,                      /* Decl  */
  YYSYMBOL_ConstDecl = 47,                 /* ConstDecl  */
  YYSYMBOL_ConstDefList = 48,              /* ConstDefList  */
  YYSYMBOL_ConstDef = 49,                  /* ConstDef  */
  YYSYMBOL_BType = 50,                     /* BType  */
  YYSYMBOL_ConstInitVal = 51,              /* ConstInitVal  */
  YYSYMBOL_ConstInitValListOpt = 52,       /* ConstInitValListOpt  */
  YYSYMBOL_ConstInitValList = 53,          /* ConstInitValList  */
  YYSYMBOL_VarDecl = 54,                   /* VarDecl  */
  YYSYMBOL_VarDefList = 55,                /* VarDefList  */
  YYSYMBOL_VarDef = 56,                    /* VarDef  */
  YYSYMBOL_ArrayDimensionsOpt = 57,        /* ArrayDimensionsOpt  */
  YYSYMBOL_ArrayDimensions = 58,           /* ArrayDimensions  */
  YYSYMBOL_AssignInitValOpt = 59,          /* AssignInitValOpt  */
  YYSYMBOL_InitVal = 60,                   /* InitVal  */
  YYSYMBOL_InitValListOpt = 61,            /* InitValListOpt  */
  YYSYMBOL_InitValList = 62,               /* InitValList  */
  YYSYMBOL_FuncPrefix = 63,                /* FuncPrefix  */
  YYSYMBOL_FuncDef = 64,                   /* FuncDef  */
  YYSYMBOL_MainFuncDef = 65,               /* MainFuncDef  */
  YYSYMBOL_FuncFParams = 66,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 67,                /* FuncFParam  */
  YYSYMBOL_Block = 68,                     /* Block  */
  YYSYMBOL_BlockItemList = 69,             /* BlockItemList  */
  YYSYMBOL_BlockItem = 70,                 /* BlockItem  */
  YYSYMBOL_Stmt = 71,                      /* Stmt  */
  YYSYMBOL_FuncRParams = 72,               /* FuncRParams  */
  YYSYMBOL_Exp = 73,                       /* Exp  */
  YYSYMBOL_LVal = 74,                      /* LVal  */
  YYSYMBOL_PrimaryExp = 75,                /* PrimaryExp  */
  YYSYMBOL_Number = 76,                    /* Number  */
  YYSYMBOL_UnaryExp = 77,                  /* UnaryExp  */
  YYSYMBOL_MulExp = 78,                    /* MulExp  */
  YYSYMBOL_AddExp = 79,                    /* AddExp  */
  YYSYMBOL_RelExp = 80,                    /* RelExp  */
  YYSYMBOL_EqExp = 81,                     /* EqExp  */
  YYSYMBOL_LAndExp = 82,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 83,                    /* LOrExp  */
  YYSYMBOL_Cond = 84,                      /* Cond  */
  YYSYMBOL_ConstExp = 85                   /* ConstExp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */
#line 29 "yacc.y"

  BaseAST *root = NULL; // Define global C root pointer HERE

#line 217 "yacc.tab.c"

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   233

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    82,    82,    98,   106,   117,   118,   119,   123,   124,
     128,   132,   137,   145,   150,   154,   155,   160,   161,   165,
     170,   187,   196,   201,   209,   214,   215,   219,   224,   233,
     234,   238,   239,   244,   245,   249,   254,   263,   264,   268,
     269,   273,   278,   283,   291,   295,   296,   300,   305,   313,
     314,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   334,   339,   347,   349,   350,   359,
     360,   361,   363,   365,   366,   367,   368,   369,   370,   371,
     374,   375,   376,   377,   380,   381,   382,   385,   386,   387,
     388,   389,   392,   393,   394,   397,   398,   401,   402,   404,
     406
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENT", "STR_CONST",
  "INT_CONST", "MAINTK", "CONSTTK", "INTTK", "BREAKTK", "CONTINUETK",
  "IFTK", "ELSETK", "VOIDTK", "WHILETK", "GETINTTK", "PRINTFTK",
  "RETURNTK", "NOT", "AND", "OR", "PLUS", "MINU", "MULT", "DIV", "MOD",
  "ASSIGN", "SEMICN", "COMMA", "LPARENT", "RPARENT", "LBRACK", "RBRACK",
  "LBRACE", "RBRACE", "LSS", "LEQ", "GRE", "GEQ", "EQL", "NEQ", "FUNCALL",
  "$accept", "CompUnit", "CompUnitItemList", "CompUnitItem", "Decl",
  "ConstDecl", "ConstDefList", "ConstDef", "BType", "ConstInitVal",
  "ConstInitValListOpt", "ConstInitValList", "VarDecl", "VarDefList",
  "VarDef", "ArrayDimensionsOpt", "ArrayDimensions", "AssignInitValOpt",
  "InitVal", "InitValListOpt", "InitValList", "FuncPrefix", "FuncDef",
  "MainFuncDef", "FuncFParams", "FuncFParam", "Block", "BlockItemList",
  "BlockItem", "Stmt", "FuncRParams", "Exp", "LVal", "PrimaryExp",
  "Number", "UnaryExp", "MulExp", "AddExp", "RelExp", "EqExp", "LAndExp",
  "LOrExp", "Cond", "ConstExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-143)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-38)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,     3,    12,    34,    48,    18,  -143,  -143,  -143,    53,
    -143,    31,  -143,  -143,  -143,    78,    58,  -143,  -143,  -143,
     -14,    13,  -143,     0,    70,    47,  -143,    59,   102,    82,
      79,  -143,   108,    83,   114,    19,  -143,    94,  -143,    78,
      83,  -143,  -143,    89,    97,  -143,   102,    70,  -143,   126,
    -143,  -143,     3,    83,     2,  -143,  -143,  -143,    32,    95,
     204,   204,   204,   204,    97,  -143,  -143,  -143,  -143,  -143,
    -143,     9,    56,    93,   100,   101,   109,   110,   116,    61,
    -143,  -143,  -143,   108,  -143,   158,  -143,  -143,   119,   123,
    -143,  -143,     2,  -143,  -143,   199,   204,   120,  -143,  -143,
    -143,   121,  -143,   118,   128,   204,   204,   204,   204,   204,
    -143,  -143,  -143,   204,   204,   150,  -143,   130,  -143,  -143,
    -143,   204,  -143,   124,   134,  -143,    39,  -143,   132,  -143,
    -143,  -143,    97,  -143,  -143,  -143,     9,     9,    56,     8,
      45,   151,   157,   141,   148,    40,  -143,   154,  -143,     2,
     204,  -143,  -143,  -143,   204,   204,   204,   204,   204,   204,
     204,   204,   179,   179,   204,   156,  -143,  -143,  -143,    56,
      56,    56,    56,     8,     8,    45,   151,   174,  -143,    43,
    -143,   179,   171,  -143,  -143
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    14,     0,     0,     2,     3,     5,     8,     0,
       9,     0,     6,     7,    14,     0,     0,    38,     1,     4,
      25,     0,    22,     0,    25,     0,    11,     0,     0,    29,
      26,    21,     0,     0,     0,     0,    42,     0,    10,     0,
       0,    72,   100,     0,     0,    24,     0,    25,    23,     0,
      39,    44,     0,     0,     0,    12,    41,    27,    67,     0,
       0,     0,     0,     0,    33,    30,    31,    70,    73,    71,
      80,    84,    66,     0,     0,     0,     0,     0,     0,     0,
      53,    46,    49,     0,    54,     0,    47,    50,     0,    70,
      43,    40,    17,    13,    15,     0,     0,     0,    76,    74,
      75,     0,    35,     0,    34,     0,     0,     0,     0,     0,
      28,    58,    59,     0,     0,     0,    60,     0,    45,    48,
      52,     0,    19,     0,    18,    77,     0,    64,     0,    79,
      69,    32,     0,    81,    82,    83,    85,    86,    87,    92,
      95,    97,    99,     0,     0,     0,    61,     0,    16,     0,
       0,    78,    68,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    20,    65,    88,
      90,    89,    91,    93,    94,    96,    98,    55,    57,     0,
      62,     0,     0,    56,    63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,  -143,   194,   -43,  -143,  -143,   164,     1,   -87,
    -143,  -143,  -143,  -143,   173,   186,  -143,  -143,   -60,  -143,
    -143,  -143,  -143,  -143,  -143,   159,   -24,  -143,   131,  -142,
      49,   -41,   -49,  -143,   -27,   -48,    -5,   -62,   -53,    55,
      57,  -143,   113,   -18
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    25,    26,     9,    93,
     123,   124,    10,    21,    22,    29,    30,    45,    65,   103,
     104,    11,    12,    13,    35,    36,    84,    85,    86,    87,
     126,    88,    67,    68,    69,    70,    71,    72,   139,   140,
     141,   142,   143,    94
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      89,    42,    15,    66,   102,   122,    82,    41,    14,    50,
      43,    14,    98,    99,   100,   -37,    56,    28,    16,    42,
     177,   178,   101,    66,    34,     1,     2,    42,    73,    91,
      33,     3,   105,   106,   107,    92,    89,    17,   117,   183,
      31,    32,    82,   154,   155,   156,   157,    52,    18,    53,
      83,   138,   138,    34,   127,   128,    20,   133,   134,   135,
      23,    95,   167,    96,    58,    42,    41,   150,   164,   151,
     165,   150,   153,   182,    38,    39,    59,   108,   109,    60,
     147,    24,    61,    62,   158,   159,    83,    27,   116,    40,
      63,    66,   169,   170,   171,   172,   138,   138,   138,   138,
      58,    28,    41,   136,   137,   173,   174,    41,    44,   168,
      46,    47,    59,    89,    89,    60,    49,    51,    61,    62,
      54,    57,    42,   127,    97,   110,    63,   111,   112,    58,
      64,    41,    89,     1,    14,    74,    75,    76,   113,   114,
      77,    59,    78,    79,    60,   115,   120,    61,    62,   121,
     129,   130,   131,    80,   145,    63,   132,   146,   148,    49,
      81,    58,   149,    41,   152,     1,    14,    74,    75,    76,
     160,   162,    77,    59,    78,    79,    60,   161,   163,    61,
      62,   166,    58,   180,    41,    80,   181,    63,    74,    75,
      76,    49,   118,    77,    59,    78,    79,    60,   184,    19,
      61,    62,    58,    55,    41,    48,    80,    58,    63,    41,
      37,    90,    49,   179,    59,   175,   119,    60,   176,    59,
      61,    62,    60,     0,     0,    61,    62,   144,    63,   125,
       0,     0,     0,    63
};

static const yytype_int16 yycheck[] =
{
      49,    28,     1,    44,    64,    92,    49,     5,     8,    33,
      28,     8,    60,    61,    62,    29,    40,    31,     6,    46,
     162,   163,    63,    64,    23,     7,     8,    54,    46,    53,
      30,    13,    23,    24,    25,    33,    85,     3,    79,   181,
      27,    28,    85,    35,    36,    37,    38,    28,     0,    30,
      49,   113,   114,    52,    95,    96,     3,   105,   106,   107,
      29,    29,   149,    31,     3,    92,     5,    28,    28,    30,
      30,    28,   132,    30,    27,    28,    15,    21,    22,    18,
     121,     3,    21,    22,    39,    40,    85,    29,    27,    30,
      29,   132,   154,   155,   156,   157,   158,   159,   160,   161,
       3,    31,     5,   108,   109,   158,   159,     5,    26,   150,
      31,     3,    15,   162,   163,    18,    33,     3,    21,    22,
      26,    32,   149,   164,    29,    32,    29,    27,    27,     3,
      33,     5,   181,     7,     8,     9,    10,    11,    29,    29,
      14,    15,    16,    17,    18,    29,    27,    21,    22,    26,
      30,    30,    34,    27,     4,    29,    28,    27,    34,    33,
      34,     3,    28,     5,    32,     7,     8,     9,    10,    11,
      19,    30,    14,    15,    16,    17,    18,    20,    30,    21,
      22,    27,     3,    27,     5,    27,    12,    29,     9,    10,
      11,    33,    34,    14,    15,    16,    17,    18,    27,     5,
      21,    22,     3,    39,     5,    32,    27,     3,    29,     5,
      24,    52,    33,   164,    15,   160,    85,    18,   161,    15,
      21,    22,    18,    -1,    -1,    21,    22,   114,    29,    30,
      -1,    -1,    -1,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,    13,    43,    44,    45,    46,    47,    50,
      54,    63,    64,    65,     8,    50,     6,     3,     0,    45,
       3,    55,    56,    29,     3,    48,    49,    29,    31,    57,
      58,    27,    28,    30,    50,    66,    67,    57,    27,    28,
      30,     5,    76,    85,    26,    59,    31,     3,    56,    33,
      68,     3,    28,    30,    26,    49,    68,    32,     3,    15,
      18,    21,    22,    29,    33,    60,    73,    74,    75,    76,
      77,    78,    79,    85,     9,    10,    11,    14,    16,    17,
      27,    34,    46,    50,    68,    69,    70,    71,    73,    74,
      67,    68,    33,    51,    85,    29,    31,    29,    77,    77,
      77,    73,    60,    61,    62,    23,    24,    25,    21,    22,
      32,    27,    27,    29,    29,    29,    27,    73,    34,    70,
      27,    26,    51,    52,    53,    30,    72,    73,    73,    30,
      30,    34,    28,    77,    77,    77,    78,    78,    79,    80,
      81,    82,    83,    84,    84,     4,    27,    73,    34,    28,
      28,    30,    32,    60,    35,    36,    37,    38,    39,    40,
      19,    20,    30,    30,    28,    30,    27,    51,    73,    79,
      79,    79,    79,    80,    80,    81,    82,    71,    71,    72,
      27,    12,    30,    71,    27
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    46,    46,
      47,    48,    48,    49,    50,    51,    51,    52,    52,    53,
      53,    54,    55,    55,    56,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    61,    62,    62,    63,    63,    64,
      64,    65,    66,    66,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    72,    72,    73,    74,    74,    75,
      75,    75,    76,    77,    77,    77,    77,    77,    77,    77,
      78,    78,    78,    78,    79,    79,    79,    80,    80,    80,
      80,    80,    81,    81,    81,    82,    82,    83,    83,    84,
      85
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       4,     1,     3,     4,     1,     1,     3,     0,     1,     1,
       3,     3,     1,     3,     3,     0,     1,     3,     4,     0,
       2,     1,     3,     0,     1,     1,     3,     2,     2,     4,
       5,     5,     1,     3,     2,     3,     2,     1,     2,     1,
       1,     4,     2,     1,     1,     5,     7,     5,     2,     2,
       2,     3,     5,     7,     1,     3,     1,     1,     4,     3,
       1,     1,     1,     1,     2,     2,     2,     3,     4,     3,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* CompUnit: CompUnitItemList  */
#line 82 "yacc.y"
                       {
        CompUnitAST* comp_unit = create_comp_unit((ASTList*)(yyvsp[0].ast_ptr)); // Create CompUnitAST
        (yyval.ast_ptr) = (BaseAST*)comp_unit; // The value of this rule is the CompUnitAST
        root = (yyval.ast_ptr);               // Assign the CompUnitAST to the global root
    }
#line 1316 "yacc.tab.c"
    break;

  case 3: /* CompUnitItemList: CompUnitItem  */
#line 98 "yacc.y"
                       {
        ASTList* list = create_ast_list();
        if ((yyvsp[0].ast_ptr)) {
            add_ast_list_node(&list->head, (yyvsp[0].ast_ptr));
        }
        (yyval.ast_ptr) = (BaseAST*)list;
        /* Create list, add first item (if not null) */
    }
#line 1329 "yacc.tab.c"
    break;

  case 4: /* CompUnitItemList: CompUnitItemList CompUnitItem  */
#line 106 "yacc.y"
                                    {
        ASTList* list = (ASTList*)(yyvsp[-1].ast_ptr); // Cast existing list
        if ((yyvsp[0].ast_ptr)) {
            add_ast_list_node(&list->head, (yyvsp[0].ast_ptr));
        }
        (yyval.ast_ptr) = (yyvsp[-1].ast_ptr); // Pass the modified list up
        /* Add subsequent item (if not null) */
    }
#line 1342 "yacc.tab.c"
    break;

  case 5: /* CompUnitItem: Decl  */
#line 117 "yacc.y"
              { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1348 "yacc.tab.c"
    break;

  case 6: /* CompUnitItem: FuncDef  */
#line 118 "yacc.y"
              { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1354 "yacc.tab.c"
    break;

  case 7: /* CompUnitItem: MainFuncDef  */
#line 119 "yacc.y"
                  { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1360 "yacc.tab.c"
    break;

  case 8: /* Decl: ConstDecl  */
#line 123 "yacc.y"
                { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1366 "yacc.tab.c"
    break;

  case 9: /* Decl: VarDecl  */
#line 124 "yacc.y"
                { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1372 "yacc.tab.c"
    break;

  case 10: /* ConstDecl: CONSTTK BType ConstDefList SEMICN  */
#line 128 "yacc.y"
                                        { (yyval.ast_ptr) = (BaseAST*)create_const_decl_list((TypeAST*)(yyvsp[-2].ast_ptr), (ASTList*)(yyvsp[-1].ast_ptr)); }
#line 1378 "yacc.tab.c"
    break;

  case 11: /* ConstDefList: ConstDef  */
#line 132 "yacc.y"
               {
        ASTList* list = create_ast_list();
        add_ast_list_node(&list->head, (yyvsp[0].ast_ptr));
        (yyval.ast_ptr) = (BaseAST*)list;
    }
#line 1388 "yacc.tab.c"
    break;

  case 12: /* ConstDefList: ConstDefList COMMA ConstDef  */
#line 137 "yacc.y"
                                  {
        ASTList* list = (ASTList*)(yyvsp[-2].ast_ptr);
        add_ast_list_node(&list->head, (yyvsp[0].ast_ptr));
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr);
    }
#line 1398 "yacc.tab.c"
    break;

  case 13: /* ConstDef: IDENT ArrayDimensionsOpt ASSIGN ConstInitVal  */
#line 145 "yacc.y"
                                                   { (yyval.ast_ptr) = (BaseAST*)create_const_def((yyvsp[-3].str_val), (ASTList*)(yyvsp[-2].ast_ptr), (yyvsp[0].ast_ptr)); /* free($1) is assumed handled by create_ */ }
#line 1404 "yacc.tab.c"
    break;

  case 14: /* BType: INTTK  */
#line 150 "yacc.y"
            { (yyval.ast_ptr) = (BaseAST*)create_type(SYSY_INT); }
#line 1410 "yacc.tab.c"
    break;

  case 15: /* ConstInitVal: ConstExp  */
#line 154 "yacc.y"
               { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1416 "yacc.tab.c"
    break;

  case 16: /* ConstInitVal: LBRACE ConstInitValListOpt RBRACE  */
#line 155 "yacc.y"
                                        { (yyval.ast_ptr) = (yyvsp[-1].ast_ptr) ? (yyvsp[-1].ast_ptr) : (BaseAST*)create_ast_list(); /* Use C list */ }
#line 1422 "yacc.tab.c"
    break;

  case 17: /* ConstInitValListOpt: %empty  */
#line 160 "yacc.y"
                  { (yyval.ast_ptr) = NULL; /* Use NULL */ }
#line 1428 "yacc.tab.c"
    break;

  case 18: /* ConstInitValListOpt: ConstInitValList  */
#line 161 "yacc.y"
                       { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1434 "yacc.tab.c"
    break;

  case 19: /* ConstInitValList: ConstInitVal  */
#line 165 "yacc.y"
                   {
        ASTList* list = create_ast_list();
        add_ast_list_node(&list->head, (yyvsp[0].ast_ptr));
        (yyval.ast_ptr) = (BaseAST*)list;
     }
#line 1444 "yacc.tab.c"
    break;

  case 20: /* ConstInitValList: ConstInitValList COMMA ConstInitVal  */
#line 170 "yacc.y"
                                          {
        ASTList* list = (ASTList*)(yyvsp[-2].ast_ptr);
        add_ast_list_node(&list->head, (yyvsp[0].ast_ptr));
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr);
    }
#line 1454 "yacc.tab.c"
    break;

  case 21: /* VarDecl: BType VarDefList SEMICN  */
#line 187 "yacc.y"
                              { (yyval.ast_ptr) = (BaseAST*)create_var_decl_list((TypeAST*)(yyvsp[-2].ast_ptr), (ASTList*)(yyvsp[-1].ast_ptr)); }
#line 1460 "yacc.tab.c"
    break;

  case 22: /* VarDefList: VarDef  */
#line 196 "yacc.y"
             {
        ASTList* list = create_ast_list();
        add_ast_list_node(&list->head, (yyvsp[0].ast_ptr));
        (yyval.ast_ptr) = (BaseAST*)list;
    }
#line 1470 "yacc.tab.c"
    break;

  case 23: /* VarDefList: VarDefList COMMA VarDef  */
#line 201 "yacc.y"
                              {
        ASTList* list = (ASTList*)(yyvsp[-2].ast_ptr);
        add_ast_list_node(&list->head, (yyvsp[0].ast_ptr));
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr);
    }
#line 1480 "yacc.tab.c"
    break;

  case 24: /* VarDef: IDENT ArrayDimensionsOpt AssignInitValOpt  */
#line 209 "yacc.y"
                                                { (yyval.ast_ptr) = (BaseAST*)create_var_def((yyvsp[-2].str_val), (ASTList*)(yyvsp[-1].ast_ptr), (yyvsp[0].ast_ptr)); /* free($1) is assumed handled by create_ */ }
#line 1486 "yacc.tab.c"
    break;

  case 25: /* ArrayDimensionsOpt: %empty  */
#line 214 "yacc.y"
                  { (yyval.ast_ptr) = NULL; /* Use NULL */ }
#line 1492 "yacc.tab.c"
    break;

  case 26: /* ArrayDimensionsOpt: ArrayDimensions  */
#line 215 "yacc.y"
                      { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1498 "yacc.tab.c"
    break;

  case 27: /* ArrayDimensions: LBRACK ConstExp RBRACK  */
#line 219 "yacc.y"
                             {
        ASTList* list = create_ast_list();
        add_ast_list_node(&list->head, (yyvsp[-1].ast_ptr));
        (yyval.ast_ptr) = (BaseAST*)list;
    }
#line 1508 "yacc.tab.c"
    break;

  case 28: /* ArrayDimensions: ArrayDimensions LBRACK ConstExp RBRACK  */
#line 224 "yacc.y"
                                             {
        ASTList* list = (ASTList*)(yyvsp[-3].ast_ptr);
        add_ast_list_node(&list->head, (yyvsp[-1].ast_ptr));
        (yyval.ast_ptr) = (yyvsp[-3].ast_ptr);
    }
#line 1518 "yacc.tab.c"
    break;

  case 29: /* AssignInitValOpt: %empty  */
#line 233 "yacc.y"
                  { (yyval.ast_ptr) = NULL; /* Use NULL */ }
#line 1524 "yacc.tab.c"
    break;

  case 30: /* AssignInitValOpt: ASSIGN InitVal  */
#line 234 "yacc.y"
                     { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); /* Pass InitVal AST up */ }
#line 1530 "yacc.tab.c"
    break;

  case 31: /* InitVal: Exp  */
#line 238 "yacc.y"
          { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1536 "yacc.tab.c"
    break;

  case 32: /* InitVal: LBRACE InitValListOpt RBRACE  */
#line 239 "yacc.y"
                                   { (yyval.ast_ptr) = (yyvsp[-1].ast_ptr) ? (yyvsp[-1].ast_ptr) : (BaseAST*)create_ast_list(); /* Use C list */ }
#line 1542 "yacc.tab.c"
    break;

  case 33: /* InitValListOpt: %empty  */
#line 244 "yacc.y"
                  { (yyval.ast_ptr) = NULL; /* Use NULL */ }
#line 1548 "yacc.tab.c"
    break;

  case 34: /* InitValListOpt: InitValList  */
#line 245 "yacc.y"
                  { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1554 "yacc.tab.c"
    break;

  case 35: /* InitValList: InitVal  */
#line 249 "yacc.y"
              {
        ASTList* list = create_ast_list();
        add_ast_list_node(&list->head, (yyvsp[0].ast_ptr));
        (yyval.ast_ptr) = (BaseAST*)list;
     }
#line 1564 "yacc.tab.c"
    break;

  case 36: /* InitValList: InitValList COMMA InitVal  */
#line 254 "yacc.y"
                                {
        ASTList* list = (ASTList*)(yyvsp[-2].ast_ptr);
        add_ast_list_node(&list->head, (yyvsp[0].ast_ptr));
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr);
    }
#line 1574 "yacc.tab.c"
    break;

  case 37: /* FuncPrefix: BType IDENT  */
#line 263 "yacc.y"
                  { (yyval.ast_ptr) = (BaseAST*)create_func_id_info(SYSY_INT, (yyvsp[0].str_val)); /* free($2) is assumed handled by create_ */ }
#line 1580 "yacc.tab.c"
    break;

  case 38: /* FuncPrefix: VOIDTK IDENT  */
#line 264 "yacc.y"
                   { (yyval.ast_ptr) = (BaseAST*)create_func_id_info(SYSY_VOID, (yyvsp[0].str_val)); /* free($2) is assumed handled by create_ */ }
#line 1586 "yacc.tab.c"
    break;

  case 39: /* FuncDef: FuncPrefix LPARENT RPARENT Block  */
#line 268 "yacc.y"
                                       { (yyval.ast_ptr) = (BaseAST*)create_func_def((FuncIdInfoAST*)(yyvsp[-3].ast_ptr), NULL, (ASTList*)(yyvsp[0].ast_ptr)); }
#line 1592 "yacc.tab.c"
    break;

  case 40: /* FuncDef: FuncPrefix LPARENT FuncFParams RPARENT Block  */
#line 269 "yacc.y"
                                                   { (yyval.ast_ptr) = (BaseAST*)create_func_def((FuncIdInfoAST*)(yyvsp[-4].ast_ptr), (ASTList*)(yyvsp[-2].ast_ptr), (ASTList*)(yyvsp[0].ast_ptr)); }
#line 1598 "yacc.tab.c"
    break;

  case 41: /* MainFuncDef: INTTK MAINTK LPARENT RPARENT Block  */
#line 273 "yacc.y"
                                         { (yyval.ast_ptr) = (BaseAST*)create_main_func_def((ASTList*)(yyvsp[0].ast_ptr)); }
#line 1604 "yacc.tab.c"
    break;

  case 42: /* FuncFParams: FuncFParam  */
#line 278 "yacc.y"
                 {
        ASTList* list = create_ast_list();
        add_ast_list_node(&list->head, (yyvsp[0].ast_ptr));
        (yyval.ast_ptr) = (BaseAST*)list;
     }
#line 1614 "yacc.tab.c"
    break;

  case 43: /* FuncFParams: FuncFParams COMMA FuncFParam  */
#line 283 "yacc.y"
                                   {
        ASTList* list = (ASTList*)(yyvsp[-2].ast_ptr);
        add_ast_list_node(&list->head, (yyvsp[0].ast_ptr));
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr);
    }
#line 1624 "yacc.tab.c"
    break;

  case 44: /* FuncFParam: BType IDENT  */
#line 291 "yacc.y"
                  { (yyval.ast_ptr) = (BaseAST*)create_func_param((TypeAST*)(yyvsp[-1].ast_ptr), (yyvsp[0].str_val), 0, NULL); /* free($2) is assumed handled by create_ */ }
#line 1630 "yacc.tab.c"
    break;

  case 45: /* Block: LBRACE BlockItemList RBRACE  */
#line 295 "yacc.y"
                                  { (yyval.ast_ptr) = (yyvsp[-1].ast_ptr); }
#line 1636 "yacc.tab.c"
    break;

  case 46: /* Block: LBRACE RBRACE  */
#line 296 "yacc.y"
                    { (yyval.ast_ptr) = (BaseAST*)create_ast_list(); }
#line 1642 "yacc.tab.c"
    break;

  case 47: /* BlockItemList: BlockItem  */
#line 300 "yacc.y"
                {
        ASTList* list = create_ast_list();
        if((yyvsp[0].ast_ptr)) add_ast_list_node(&list->head, (yyvsp[0].ast_ptr));
        (yyval.ast_ptr) = (BaseAST*)list;
      }
#line 1652 "yacc.tab.c"
    break;

  case 48: /* BlockItemList: BlockItemList BlockItem  */
#line 305 "yacc.y"
                              {
        ASTList* list = (ASTList*)(yyvsp[-1].ast_ptr);
        if((yyvsp[0].ast_ptr)) add_ast_list_node(&list->head, (yyvsp[0].ast_ptr));
        (yyval.ast_ptr) = (yyvsp[-1].ast_ptr);
    }
#line 1662 "yacc.tab.c"
    break;

  case 49: /* BlockItem: Decl  */
#line 313 "yacc.y"
           { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1668 "yacc.tab.c"
    break;

  case 50: /* BlockItem: Stmt  */
#line 314 "yacc.y"
           { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1674 "yacc.tab.c"
    break;

  case 51: /* Stmt: LVal ASSIGN Exp SEMICN  */
#line 318 "yacc.y"
                             { (yyval.ast_ptr) = (BaseAST*)create_assign_stmt((yyvsp[-3].ast_ptr), (yyvsp[-1].ast_ptr)); }
#line 1680 "yacc.tab.c"
    break;

  case 52: /* Stmt: Exp SEMICN  */
#line 319 "yacc.y"
                             { (yyval.ast_ptr) = (BaseAST*)create_exp_stmt((yyvsp[-1].ast_ptr)); }
#line 1686 "yacc.tab.c"
    break;

  case 53: /* Stmt: SEMICN  */
#line 320 "yacc.y"
                             { (yyval.ast_ptr) = (BaseAST*)create_empty_stmt(); }
#line 1692 "yacc.tab.c"
    break;

  case 54: /* Stmt: Block  */
#line 321 "yacc.y"
                             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1698 "yacc.tab.c"
    break;

  case 55: /* Stmt: IFTK LPARENT Cond RPARENT Stmt  */
#line 322 "yacc.y"
                                     { (yyval.ast_ptr) = (BaseAST*)create_if_stmt((yyvsp[-2].ast_ptr), (yyvsp[0].ast_ptr), NULL); }
#line 1704 "yacc.tab.c"
    break;

  case 56: /* Stmt: IFTK LPARENT Cond RPARENT Stmt ELSETK Stmt  */
#line 323 "yacc.y"
                                                 { (yyval.ast_ptr) = (BaseAST*)create_if_stmt((yyvsp[-4].ast_ptr), (yyvsp[-2].ast_ptr), (yyvsp[0].ast_ptr)); }
#line 1710 "yacc.tab.c"
    break;

  case 57: /* Stmt: WHILETK LPARENT Cond RPARENT Stmt  */
#line 324 "yacc.y"
                                        { (yyval.ast_ptr) = (BaseAST*)create_while_stmt((yyvsp[-2].ast_ptr), (yyvsp[0].ast_ptr)); }
#line 1716 "yacc.tab.c"
    break;

  case 58: /* Stmt: BREAKTK SEMICN  */
#line 325 "yacc.y"
                             { (yyval.ast_ptr) = (BaseAST*)create_break_stmt(); }
#line 1722 "yacc.tab.c"
    break;

  case 59: /* Stmt: CONTINUETK SEMICN  */
#line 326 "yacc.y"
                             { (yyval.ast_ptr) = (BaseAST*)create_continue_stmt(); }
#line 1728 "yacc.tab.c"
    break;

  case 60: /* Stmt: RETURNTK SEMICN  */
#line 327 "yacc.y"
                             { (yyval.ast_ptr) = (BaseAST*)create_return_stmt(NULL); }
#line 1734 "yacc.tab.c"
    break;

  case 61: /* Stmt: RETURNTK Exp SEMICN  */
#line 328 "yacc.y"
                             { (yyval.ast_ptr) = (BaseAST*)create_return_stmt((yyvsp[-1].ast_ptr)); }
#line 1740 "yacc.tab.c"
    break;

  case 62: /* Stmt: PRINTFTK LPARENT STR_CONST RPARENT SEMICN  */
#line 329 "yacc.y"
                                                { (yyval.ast_ptr) = (BaseAST*)create_printf_stmt((yyvsp[-2].str_val), NULL); /* free($3) is assumed handled by create_ */ }
#line 1746 "yacc.tab.c"
    break;

  case 63: /* Stmt: PRINTFTK LPARENT STR_CONST COMMA FuncRParams RPARENT SEMICN  */
#line 330 "yacc.y"
                                                                  { (yyval.ast_ptr) = (BaseAST*)create_printf_stmt((yyvsp[-4].str_val), (ASTList*)(yyvsp[-2].ast_ptr)); /* free($3) is assumed handled by create_ */ }
#line 1752 "yacc.tab.c"
    break;

  case 64: /* FuncRParams: Exp  */
#line 334 "yacc.y"
          {
        ASTList* list = create_ast_list();
        add_ast_list_node(&list->head, (yyvsp[0].ast_ptr));
        (yyval.ast_ptr) = (BaseAST*)list;
      }
#line 1762 "yacc.tab.c"
    break;

  case 65: /* FuncRParams: FuncRParams COMMA Exp  */
#line 339 "yacc.y"
                            {
        ASTList* list = (ASTList*)(yyvsp[-2].ast_ptr);
        add_ast_list_node(&list->head, (yyvsp[0].ast_ptr));
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr);
    }
#line 1772 "yacc.tab.c"
    break;

  case 66: /* Exp: AddExp  */
#line 347 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1778 "yacc.tab.c"
    break;

  case 67: /* LVal: IDENT  */
#line 349 "yacc.y"
            { (yyval.ast_ptr) = (BaseAST*)create_var_ref((yyvsp[0].str_val), NULL); /* free($1) is assumed handled by create_ */ }
#line 1784 "yacc.tab.c"
    break;

  case 68: /* LVal: IDENT LBRACK Exp RBRACK  */
#line 350 "yacc.y"
                              {
        ASTList* indices = create_ast_list();
        add_ast_list_node(&indices->head, (yyvsp[-1].ast_ptr));
        (yyval.ast_ptr) = (BaseAST*)create_var_ref((yyvsp[-3].str_val), indices); /* free($1) is assumed handled by create_ */
        // TODO: Extend LVal rule to handle multi-dimensional arrays if needed
    }
#line 1795 "yacc.tab.c"
    break;

  case 69: /* PrimaryExp: LPARENT Exp RPARENT  */
#line 359 "yacc.y"
                          { (yyval.ast_ptr) = (yyvsp[-1].ast_ptr); }
#line 1801 "yacc.tab.c"
    break;

  case 70: /* PrimaryExp: LVal  */
#line 360 "yacc.y"
           { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1807 "yacc.tab.c"
    break;

  case 71: /* PrimaryExp: Number  */
#line 361 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1813 "yacc.tab.c"
    break;

  case 72: /* Number: INT_CONST  */
#line 363 "yacc.y"
                   { (yyval.ast_ptr) = (BaseAST*)create_number((yyvsp[0].int_val)); }
#line 1819 "yacc.tab.c"
    break;

  case 73: /* UnaryExp: PrimaryExp  */
#line 365 "yacc.y"
                 { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1825 "yacc.tab.c"
    break;

  case 74: /* UnaryExp: PLUS UnaryExp  */
#line 366 "yacc.y"
                    { (yyval.ast_ptr) = (BaseAST*)create_unary_op(UNARY_POS, (yyvsp[0].ast_ptr)); }
#line 1831 "yacc.tab.c"
    break;

  case 75: /* UnaryExp: MINU UnaryExp  */
#line 367 "yacc.y"
                    { (yyval.ast_ptr) = (BaseAST*)create_unary_op(UNARY_NEG, (yyvsp[0].ast_ptr)); }
#line 1837 "yacc.tab.c"
    break;

  case 76: /* UnaryExp: NOT UnaryExp  */
#line 368 "yacc.y"
                   { (yyval.ast_ptr) = (BaseAST*)create_unary_op(UNARY_NOT, (yyvsp[0].ast_ptr)); }
#line 1843 "yacc.tab.c"
    break;

  case 77: /* UnaryExp: IDENT LPARENT RPARENT  */
#line 369 "yacc.y"
                                          { (yyval.ast_ptr) = (BaseAST*)create_func_call((yyvsp[-2].str_val), NULL); /* free($1) is assumed handled by create_ */ }
#line 1849 "yacc.tab.c"
    break;

  case 78: /* UnaryExp: IDENT LPARENT FuncRParams RPARENT  */
#line 370 "yacc.y"
                                                      { (yyval.ast_ptr) = (BaseAST*)create_func_call((yyvsp[-3].str_val), (ASTList*)(yyvsp[-1].ast_ptr)); /* free($1) is assumed handled by create_ */ }
#line 1855 "yacc.tab.c"
    break;

  case 79: /* UnaryExp: GETINTTK LPARENT RPARENT  */
#line 371 "yacc.y"
                               { (yyval.ast_ptr) = (BaseAST*)create_getint(); }
#line 1861 "yacc.tab.c"
    break;

  case 80: /* MulExp: UnaryExp  */
#line 374 "yacc.y"
               { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1867 "yacc.tab.c"
    break;

  case 81: /* MulExp: MulExp MULT UnaryExp  */
#line 375 "yacc.y"
                           { (yyval.ast_ptr) = (BaseAST*)create_binary_op(BINOP_MUL, (yyvsp[-2].ast_ptr), (yyvsp[0].ast_ptr)); }
#line 1873 "yacc.tab.c"
    break;

  case 82: /* MulExp: MulExp DIV UnaryExp  */
#line 376 "yacc.y"
                          { (yyval.ast_ptr) = (BaseAST*)create_binary_op(BINOP_DIV, (yyvsp[-2].ast_ptr), (yyvsp[0].ast_ptr)); }
#line 1879 "yacc.tab.c"
    break;

  case 83: /* MulExp: MulExp MOD UnaryExp  */
#line 377 "yacc.y"
                          { (yyval.ast_ptr) = (BaseAST*)create_binary_op(BINOP_MOD, (yyvsp[-2].ast_ptr), (yyvsp[0].ast_ptr)); }
#line 1885 "yacc.tab.c"
    break;

  case 84: /* AddExp: MulExp  */
#line 380 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1891 "yacc.tab.c"
    break;

  case 85: /* AddExp: AddExp PLUS MulExp  */
#line 381 "yacc.y"
                         { (yyval.ast_ptr) = (BaseAST*)create_binary_op(BINOP_ADD, (yyvsp[-2].ast_ptr), (yyvsp[0].ast_ptr)); }
#line 1897 "yacc.tab.c"
    break;

  case 86: /* AddExp: AddExp MINU MulExp  */
#line 382 "yacc.y"
                         { (yyval.ast_ptr) = (BaseAST*)create_binary_op(BINOP_SUB, (yyvsp[-2].ast_ptr), (yyvsp[0].ast_ptr)); }
#line 1903 "yacc.tab.c"
    break;

  case 87: /* RelExp: AddExp  */
#line 385 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1909 "yacc.tab.c"
    break;

  case 88: /* RelExp: RelExp LSS AddExp  */
#line 386 "yacc.y"
                        { (yyval.ast_ptr) = (BaseAST*)create_binary_op(BINOP_LT, (yyvsp[-2].ast_ptr), (yyvsp[0].ast_ptr)); }
#line 1915 "yacc.tab.c"
    break;

  case 89: /* RelExp: RelExp GRE AddExp  */
#line 387 "yacc.y"
                        { (yyval.ast_ptr) = (BaseAST*)create_binary_op(BINOP_GT, (yyvsp[-2].ast_ptr), (yyvsp[0].ast_ptr)); }
#line 1921 "yacc.tab.c"
    break;

  case 90: /* RelExp: RelExp LEQ AddExp  */
#line 388 "yacc.y"
                        { (yyval.ast_ptr) = (BaseAST*)create_binary_op(BINOP_LE, (yyvsp[-2].ast_ptr), (yyvsp[0].ast_ptr)); }
#line 1927 "yacc.tab.c"
    break;

  case 91: /* RelExp: RelExp GEQ AddExp  */
#line 389 "yacc.y"
                        { (yyval.ast_ptr) = (BaseAST*)create_binary_op(BINOP_GE, (yyvsp[-2].ast_ptr), (yyvsp[0].ast_ptr)); }
#line 1933 "yacc.tab.c"
    break;

  case 92: /* EqExp: RelExp  */
#line 392 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1939 "yacc.tab.c"
    break;

  case 93: /* EqExp: EqExp EQL RelExp  */
#line 393 "yacc.y"
                       { (yyval.ast_ptr) = (BaseAST*)create_binary_op(BINOP_EQ, (yyvsp[-2].ast_ptr), (yyvsp[0].ast_ptr)); }
#line 1945 "yacc.tab.c"
    break;

  case 94: /* EqExp: EqExp NEQ RelExp  */
#line 394 "yacc.y"
                       { (yyval.ast_ptr) = (BaseAST*)create_binary_op(BINOP_NE, (yyvsp[-2].ast_ptr), (yyvsp[0].ast_ptr)); }
#line 1951 "yacc.tab.c"
    break;

  case 95: /* LAndExp: EqExp  */
#line 397 "yacc.y"
            { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1957 "yacc.tab.c"
    break;

  case 96: /* LAndExp: LAndExp AND EqExp  */
#line 398 "yacc.y"
                        { (yyval.ast_ptr) = (BaseAST*)create_binary_op(BINOP_LAND, (yyvsp[-2].ast_ptr), (yyvsp[0].ast_ptr)); }
#line 1963 "yacc.tab.c"
    break;

  case 97: /* LOrExp: LAndExp  */
#line 401 "yacc.y"
              { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1969 "yacc.tab.c"
    break;

  case 98: /* LOrExp: LOrExp OR LAndExp  */
#line 402 "yacc.y"
                        { (yyval.ast_ptr) = (BaseAST*)create_binary_op(BINOP_LOR, (yyvsp[-2].ast_ptr), (yyvsp[0].ast_ptr)); }
#line 1975 "yacc.tab.c"
    break;

  case 99: /* Cond: LOrExp  */
#line 404 "yacc.y"
              { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1981 "yacc.tab.c"
    break;

  case 100: /* ConstExp: Number  */
#line 406 "yacc.y"
                  { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1987 "yacc.tab.c"
    break;


#line 1991 "yacc.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 408 "yacc.y"
 

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
