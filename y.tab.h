/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON = 258,
    COLON = 259,
    COMMA = 260,
    L_PAREN = 261,
    R_PAREN = 262,
    L_SQUARE_BRACKET = 263,
    R_SQUARE_BRACKET = 264,
    ASSIGN = 265,
    EQ = 266,
    NEQ = 267,
    LT = 268,
    GT = 269,
    LTE = 270,
    GTE = 271,
    SUB = 272,
    ADD = 273,
    MULT = 274,
    DIV = 275,
    MOD = 276,
    FUNCTION = 277,
    BEGIN_PARAMS = 278,
    END_PARAMS = 279,
    BEGIN_LOCALS = 280,
    END_LOCALS = 281,
    BEGIN_BODY = 282,
    END_BODY = 283,
    ARRAY = 284,
    OF = 285,
    IF = 286,
    THEN = 287,
    ENDIF = 288,
    ELSE = 289,
    WHILE = 290,
    DO = 291,
    BEGINLOOP = 292,
    ENDLOOP = 293,
    BREAK = 294,
    READ = 295,
    WRITE = 296,
    AND = 297,
    OR = 298,
    NOT = 299,
    TRUE = 300,
    FALSE = 301,
    RETURN = 302,
    NUMBER = 303,
    INTEGER = 304,
    IDENT = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 11 "mini_l.y" /* yacc.c:1909  */

  double dval;
  int ival;
  char* str;

#line 111 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
