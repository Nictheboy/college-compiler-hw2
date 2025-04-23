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

#define YYDEBUG 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For potential use later (e.g., strdup)

// External functions and variables
extern int yylex();
extern FILE *yyin;
extern char *yytext; // If needed for error reporting

void yyerror(const char *s);


#line 87 "yacc.tab.c"

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
  YYSYMBOL_IDENFR = 3,                     /* IDENFR  */
  YYSYMBOL_INTCON = 4,                     /* INTCON  */
  YYSYMBOL_STRCON = 5,                     /* STRCON  */
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
  YYSYMBOL_VarDefOpt = 56,                 /* VarDefOpt  */
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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   234

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
       0,    46,    46,    58,    59,    63,    64,    65,    69,    70,
      74,    78,    79,    83,    88,    92,    93,    98,    99,   103,
     104,   117,   126,   127,   131,   136,   137,   141,   142,   147,
     148,   156,   157,   162,   163,   167,   168,   173,   174,   178,
     179,   183,   188,   189,   193,   197,   198,   202,   203,   207,
     208,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   228,   229,   233,   235,   236,   240,
     241,   242,   244,   246,   247,   248,   249,   250,   251,   252,
     255,   256,   257,   258,   261,   262,   263,   266,   267,   268,
     269,   270,   273,   274,   275,   278,   279,   282,   283,   285,
     287
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENFR", "INTCON",
  "STRCON", "MAINTK", "CONSTTK", "INTTK", "BREAKTK", "CONTINUETK", "IFTK",
  "ELSETK", "VOIDTK", "WHILETK", "GETINTTK", "PRINTFTK", "RETURNTK", "NOT",
  "AND", "OR", "PLUS", "MINU", "MULT", "DIV", "MOD", "ASSIGN", "SEMICN",
  "COMMA", "LPARENT", "RPARENT", "LBRACK", "RBRACK", "LBRACE", "RBRACE",
  "LSS", "LEQ", "GRE", "GEQ", "EQL", "NEQ", "FUNCALL", "$accept",
  "CompUnit", "CompUnitItemList", "CompUnitItem", "Decl", "ConstDecl",
  "ConstDefList", "ConstDef", "BType", "ConstInitVal",
  "ConstInitValListOpt", "ConstInitValList", "VarDecl", "VarDefList",
  "VarDefOpt", "ArrayDimensionsOpt", "ArrayDimensions", "AssignInitValOpt",
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

#define YYPACT_NINF (-101)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      69,    32,    17,    11,    25,    69,  -101,  -101,  -101,  -101,
      37,    -3,  -101,  -101,  -101,    31,  -101,    16,  -101,  -101,
    -101,  -101,    46,     3,    64,  -101,    45,    44,    71,    51,
    -101,    79,    71,    80,   131,    88,  -101,  -101,  -101,   108,
       9,  -101,    64,   125,  -101,    31,    80,  -101,    90,  -101,
    -101,    32,    80,  -101,    96,   148,    14,    14,    14,    14,
       9,  -101,  -101,  -101,  -101,  -101,  -101,    97,    68,   157,
       6,  -101,  -101,   188,   166,   168,   167,   169,   170,   165,
    -101,  -101,  -101,    71,  -101,   128,  -101,  -101,   173,   171,
    -101,  -101,    66,    14,   172,  -101,  -101,  -101,   174,  -101,
     175,   177,    14,    14,    14,    14,    14,  -101,     6,  -101,
    -101,  -101,  -101,    14,    14,   196,  -101,   176,  -101,  -101,
    -101,    14,  -101,   126,  -101,   178,  -101,  -101,  -101,     9,
    -101,  -101,  -101,    97,    97,  -101,   179,   180,    68,   137,
      89,   187,   191,   182,   184,   151,  -101,   189,    14,  -101,
    -101,  -101,  -101,     6,    14,    14,    14,    14,    14,    14,
      14,    14,   149,   149,    14,   190,  -101,  -101,  -101,    68,
      68,    68,    68,   137,   137,    89,   187,   195,  -101,   160,
    -101,   149,   192,  -101,  -101
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     3,     5,     8,     9,
       0,    25,     6,     7,    14,     0,    37,     0,    38,     1,
       4,    21,     0,     0,     0,    22,    29,    26,    25,     0,
      11,     0,    25,     0,     0,     0,    42,    72,   100,     0,
       0,    24,     0,     0,    10,     0,     0,    23,     0,    39,
      44,     0,     0,    27,    67,     0,     0,     0,     0,     0,
      33,    30,    31,    70,    73,    71,    80,    84,    66,     0,
       0,    12,    41,     0,     0,     0,     0,     0,     0,     0,
      53,    46,    49,    25,    54,     0,    47,    50,     0,    70,
      43,    40,     0,     0,     0,    76,    74,    75,     0,    35,
       0,    34,     0,     0,     0,     0,     0,    28,    17,    13,
      15,    58,    59,     0,     0,     0,    60,     0,    45,    48,
      52,     0,    77,     0,    64,     0,    79,    69,    32,     0,
      81,    82,    83,    85,    86,    19,     0,    18,    87,    92,
      95,    97,    99,     0,     0,     0,    61,     0,     0,    78,
      68,    36,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    65,    20,    88,
      90,    89,    91,    93,    94,    96,    98,    55,    57,     0,
      62,     0,     0,    56,    63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,  -101,   210,   -41,  -101,  -101,   181,   217,  -100,
    -101,  -101,  -101,  -101,   193,   194,  -101,  -101,   -57,  -101,
    -101,   -39,  -101,  -101,  -101,   183,    34,  -101,   135,   -89,
      57,   -38,   -48,  -101,   -23,   -52,    42,   -98,    26,    63,
      67,  -101,   110,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    29,    30,    34,   109,
     136,   137,     9,    10,    25,    26,    27,    41,    61,   100,
     101,    11,    12,    13,    35,    36,    84,    85,    86,    87,
     123,    88,    63,    64,    65,    66,    67,    68,   139,   140,
     141,   142,   143,   110
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      89,    38,    62,    99,    95,    96,    97,    82,   135,    83,
      37,    14,    54,    37,    18,   138,   138,    54,    37,    38,
      16,    98,    62,    17,    55,    19,    23,    56,    24,    55,
      57,    58,    56,    33,    28,    57,    58,    89,    59,   108,
      14,   117,    60,    59,    82,    31,    83,    38,    39,    32,
     130,   131,   132,   168,   124,   125,   169,   170,   171,   172,
     138,   138,   138,   138,    21,    22,    69,    49,    37,    54,
      37,    40,   151,   177,   178,    42,     1,     2,    44,    45,
      72,    55,     3,   147,    56,    38,    91,    57,    58,   105,
     106,    62,   183,    54,    37,    59,   122,     1,    73,    74,
      75,    76,    24,     3,    77,    55,    78,    79,    56,    46,
     167,    57,    58,    48,    89,    89,    51,    80,    52,    59,
     102,   103,   104,    48,    81,    92,   124,    93,   158,   159,
      38,    54,    37,    89,    50,     1,    73,    74,    75,    76,
      53,     3,    77,    55,    78,    79,    56,   133,   134,    57,
      58,    70,    54,    37,   148,    80,   149,    59,    74,    75,
      76,    48,   118,    77,    55,    78,    79,    56,    54,    37,
      57,    58,   154,   155,   156,   157,    80,    94,    59,   164,
      55,   165,    48,    56,   173,   174,    57,    58,   148,   107,
     182,    16,   116,   111,    59,   112,   113,   121,   114,   115,
     120,   145,   126,   146,   127,   129,   160,   181,   153,   128,
     150,   161,   162,   152,   163,    20,   166,   180,    15,   184,
     119,   179,    43,   175,   144,    47,    71,     0,   176,     0,
       0,     0,     0,     0,    90
};

static const yytype_int16 yycheck[] =
{
      48,    24,    40,    60,    56,    57,    58,    48,   108,    48,
       4,     8,     3,     4,     3,   113,   114,     3,     4,    42,
       3,    59,    60,     6,    15,     0,    29,    18,    31,    15,
      21,    22,    18,    30,     3,    21,    22,    85,    29,    33,
       8,    79,    33,    29,    85,    29,    85,    70,    24,     3,
     102,   103,   104,   153,    92,    93,   154,   155,   156,   157,
     158,   159,   160,   161,    27,    28,    42,    33,     4,     3,
       4,    26,   129,   162,   163,    31,     7,     8,    27,    28,
      46,    15,    13,   121,    18,   108,    52,    21,    22,    21,
      22,   129,   181,     3,     4,    29,    30,     7,     8,     9,
      10,    11,    31,    13,    14,    15,    16,    17,    18,    30,
     148,    21,    22,    33,   162,   163,    28,    27,    30,    29,
      23,    24,    25,    33,    34,    29,   164,    31,    39,    40,
     153,     3,     4,   181,     3,     7,     8,     9,    10,    11,
      32,    13,    14,    15,    16,    17,    18,   105,   106,    21,
      22,    26,     3,     4,    28,    27,    30,    29,     9,    10,
      11,    33,    34,    14,    15,    16,    17,    18,     3,     4,
      21,    22,    35,    36,    37,    38,    27,    29,    29,    28,
      15,    30,    33,    18,   158,   159,    21,    22,    28,    32,
      30,     3,    27,    27,    29,    27,    29,    26,    29,    29,
      27,     5,    30,    27,    30,    28,    19,    12,    28,    34,
      32,    20,    30,    34,    30,     5,    27,    27,     1,    27,
      85,   164,    28,   160,   114,    32,    45,    -1,   161,    -1,
      -1,    -1,    -1,    -1,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,    13,    43,    44,    45,    46,    47,    54,
      55,    63,    64,    65,     8,    50,     3,     6,     3,     0,
      45,    27,    28,    29,    31,    56,    57,    58,     3,    48,
      49,    29,     3,    30,    50,    66,    67,     4,    76,    85,
      26,    59,    31,    57,    27,    28,    30,    56,    33,    68,
       3,    28,    30,    32,     3,    15,    18,    21,    22,    29,
      33,    60,    73,    74,    75,    76,    77,    78,    79,    85,
      26,    49,    68,     8,     9,    10,    11,    14,    16,    17,
      27,    34,    46,    63,    68,    69,    70,    71,    73,    74,
      67,    68,    29,    31,    29,    77,    77,    77,    73,    60,
      61,    62,    23,    24,    25,    21,    22,    32,    33,    51,
      85,    27,    27,    29,    29,    29,    27,    73,    34,    70,
      27,    26,    30,    72,    73,    73,    30,    30,    34,    28,
      77,    77,    77,    78,    78,    51,    52,    53,    79,    80,
      81,    82,    83,    84,    84,     5,    27,    73,    28,    30,
      32,    60,    34,    28,    35,    36,    37,    38,    39,    40,
      19,    20,    30,    30,    28,    30,    27,    73,    51,    79,
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
       3,     2,     2,     4,     2,     0,     1,     3,     4,     0,
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
#line 46 "yacc.y"
                       { printf("<CompUnit>\n"); }
#line 1300 "yacc.tab.c"
    break;

  case 8: /* Decl: ConstDecl  */
#line 69 "yacc.y"
                { /* No printf needed here */ }
#line 1306 "yacc.tab.c"
    break;

  case 9: /* Decl: VarDecl  */
#line 70 "yacc.y"
                { /* No printf needed here */ }
#line 1312 "yacc.tab.c"
    break;

  case 10: /* ConstDecl: CONSTTK BType ConstDefList SEMICN  */
#line 74 "yacc.y"
                                        { printf("<ConstDecl>\n"); }
#line 1318 "yacc.tab.c"
    break;

  case 21: /* VarDecl: VarDefList SEMICN  */
#line 117 "yacc.y"
                        { printf("<VarDecl>\n"); }
#line 1324 "yacc.tab.c"
    break;

  case 39: /* FuncDef: FuncPrefix LPARENT RPARENT Block  */
#line 178 "yacc.y"
                                       { printf("<FuncDef>\n"); }
#line 1330 "yacc.tab.c"
    break;

  case 40: /* FuncDef: FuncPrefix LPARENT FuncFParams RPARENT Block  */
#line 179 "yacc.y"
                                                   { printf("<FuncDef>\n"); }
#line 1336 "yacc.tab.c"
    break;

  case 41: /* MainFuncDef: INTTK MAINTK LPARENT RPARENT Block  */
#line 183 "yacc.y"
                                         { printf("<MainFuncDef>\n"); }
#line 1342 "yacc.tab.c"
    break;

  case 45: /* Block: LBRACE BlockItemList RBRACE  */
#line 197 "yacc.y"
                                  { printf("<Block>\n"); }
#line 1348 "yacc.tab.c"
    break;

  case 46: /* Block: LBRACE RBRACE  */
#line 198 "yacc.y"
                    { printf("<Block>\n"); }
#line 1354 "yacc.tab.c"
    break;

  case 51: /* Stmt: LVal ASSIGN Exp SEMICN  */
#line 212 "yacc.y"
                             { printf("<Stmt>\n"); }
#line 1360 "yacc.tab.c"
    break;

  case 52: /* Stmt: Exp SEMICN  */
#line 213 "yacc.y"
                             { printf("<Stmt>\n"); }
#line 1366 "yacc.tab.c"
    break;

  case 53: /* Stmt: SEMICN  */
#line 214 "yacc.y"
                             { printf("<Stmt>\n"); }
#line 1372 "yacc.tab.c"
    break;

  case 54: /* Stmt: Block  */
#line 215 "yacc.y"
                             { printf("<Stmt>\n"); }
#line 1378 "yacc.tab.c"
    break;

  case 55: /* Stmt: IFTK LPARENT Cond RPARENT Stmt  */
#line 216 "yacc.y"
                                                            { printf("<Stmt>\n"); }
#line 1384 "yacc.tab.c"
    break;

  case 56: /* Stmt: IFTK LPARENT Cond RPARENT Stmt ELSETK Stmt  */
#line 217 "yacc.y"
                                                            { printf("<Stmt>\n"); }
#line 1390 "yacc.tab.c"
    break;

  case 57: /* Stmt: WHILETK LPARENT Cond RPARENT Stmt  */
#line 218 "yacc.y"
                                                          { printf("<Stmt>\n"); }
#line 1396 "yacc.tab.c"
    break;

  case 58: /* Stmt: BREAKTK SEMICN  */
#line 219 "yacc.y"
                             { printf("<Stmt>\n"); }
#line 1402 "yacc.tab.c"
    break;

  case 59: /* Stmt: CONTINUETK SEMICN  */
#line 220 "yacc.y"
                             { printf("<Stmt>\n"); }
#line 1408 "yacc.tab.c"
    break;

  case 60: /* Stmt: RETURNTK SEMICN  */
#line 221 "yacc.y"
                             { printf("<Stmt>\n"); }
#line 1414 "yacc.tab.c"
    break;

  case 61: /* Stmt: RETURNTK Exp SEMICN  */
#line 222 "yacc.y"
                             { printf("<Stmt>\n"); }
#line 1420 "yacc.tab.c"
    break;

  case 62: /* Stmt: PRINTFTK LPARENT STRCON RPARENT SEMICN  */
#line 223 "yacc.y"
                                             { /* Basic printf, needs format args */ printf("<Stmt>\n"); }
#line 1426 "yacc.tab.c"
    break;

  case 63: /* Stmt: PRINTFTK LPARENT STRCON COMMA FuncRParams RPARENT SEMICN  */
#line 224 "yacc.y"
                                                               { printf("<Stmt>\n"); }
#line 1432 "yacc.tab.c"
    break;


#line 1436 "yacc.tab.c"

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

#line 289 "yacc.y"
 

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
