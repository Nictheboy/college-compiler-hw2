/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_YACC_TAB_H_INCLUDED
# define YY_YY_YACC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 24 "yacc.y"

  #include "ast.h"

#line 53 "yacc.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENT = 258,                   /* IDENT  */
    STR_CONST = 259,               /* STR_CONST  */
    INT_CONST = 260,               /* INT_CONST  */
    MAINTK = 261,                  /* MAINTK  */
    CONSTTK = 262,                 /* CONSTTK  */
    INTTK = 263,                   /* INTTK  */
    BREAKTK = 264,                 /* BREAKTK  */
    CONTINUETK = 265,              /* CONTINUETK  */
    IFTK = 266,                    /* IFTK  */
    ELSETK = 267,                  /* ELSETK  */
    VOIDTK = 268,                  /* VOIDTK  */
    WHILETK = 269,                 /* WHILETK  */
    GETINTTK = 270,                /* GETINTTK  */
    PRINTFTK = 271,                /* PRINTFTK  */
    RETURNTK = 272,                /* RETURNTK  */
    NOT = 273,                     /* NOT  */
    AND = 274,                     /* AND  */
    OR = 275,                      /* OR  */
    PLUS = 276,                    /* PLUS  */
    MINU = 277,                    /* MINU  */
    MULT = 278,                    /* MULT  */
    DIV = 279,                     /* DIV  */
    MOD = 280,                     /* MOD  */
    ASSIGN = 281,                  /* ASSIGN  */
    SEMICN = 282,                  /* SEMICN  */
    COMMA = 283,                   /* COMMA  */
    LPARENT = 284,                 /* LPARENT  */
    RPARENT = 285,                 /* RPARENT  */
    LBRACK = 286,                  /* LBRACK  */
    RBRACK = 287,                  /* RBRACK  */
    LBRACE = 288,                  /* LBRACE  */
    RBRACE = 289,                  /* RBRACE  */
    LSS = 290,                     /* LSS  */
    LEQ = 291,                     /* LEQ  */
    GRE = 292,                     /* GRE  */
    GEQ = 293,                     /* GEQ  */
    EQL = 294,                     /* EQL  */
    NEQ = 295,                     /* NEQ  */
    FUNCALL = 296                  /* FUNCALL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "yacc.y"

    BaseAST* ast_ptr;
    int int_val;
    char* str_val;

#line 117 "yacc.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */
