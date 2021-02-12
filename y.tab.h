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
    IDENT = 258,
    SEMICOLON = 259,
    COLON = 260,
    COMMA = 261,
    L_PAREN = 262,
    R_PAREN = 263,
    L_SQUARE_BRACKET = 264,
    R_SQUARE_BRACKET = 265,
    ASSIGN = 266,
    EQ = 267,
    NEQ = 268,
    LT = 269,
    GT = 270,
    LTE = 271,
    GTE = 272,
    SUB = 273,
    ADD = 274,
    MULT = 275,
    DIV = 276,
    MOD = 277,
    FUNCTION = 278,
    BEGIN_PARAMS = 279,
    END_PARAMS = 280,
    BEGIN_LOCALS = 281,
    END_LOCALS = 282,
    BEGIN_BODY = 283,
    END_BODY = 284,
    ARRAY = 285,
    OF = 286,
    IF = 287,
    THEN = 288,
    ENDIF = 289,
    ELSE = 290,
    WHILE = 291,
    DO = 292,
    BEGINLOOP = 293,
    ENDLOOP = 294,
    BREAK = 295,
    READ = 296,
    WRITE = 297,
    AND = 298,
    OR = 299,
    NOT = 300,
    TRUE = 301,
    FALSE = 302,
    RETURN = 303,
    NUMBER = 304,
    INTEGER = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 10 "mini_l.y" /* yacc.c:1909  */

  double dval;
  int ival;

#line 110 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
