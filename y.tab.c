/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "mini_l.y" /* yacc.c:339  */

 #include <stdio.h>
 #include <stdlib.h>
 void yyerror(const char *msg);
 extern int currLine;
 extern int currPos;
 FILE * yyin;
 int yylex(void);

#line 76 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 11 "mini_l.y" /* yacc.c:355  */

  double dval;
  int ival;
  char* str;

#line 173 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 190 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   205

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    29,    29,    30,    33,    36,    37,    38,    39,    40,
      43,    44,    45,    46,    47,    50,    51,    52,    53,    56,
      57,    58,    61,    62,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    78,    79,    80,    81,    82,
      85,    86,    87,    88,    91,    92,    93,    94,    95,    98,
      99,   100,   103,   104,   107,   108,   111,   112,   115,   116,
     119,   120,   123,   124,   125,   126,   129,   130,   131,   132,
     133,   134,   135,   138,   139,   140,   143,   144,   145,   146,
     149,   150,   151,   154,   155,   156,   159,   162,   163,   164,
     167,   168
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "COLON", "COMMA", "L_PAREN",
  "R_PAREN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "ASSIGN", "EQ", "NEQ",
  "LT", "GT", "LTE", "GTE", "SUB", "ADD", "MULT", "DIV", "MOD", "FUNCTION",
  "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY",
  "END_BODY", "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO",
  "BEGINLOOP", "ENDLOOP", "BREAK", "READ", "WRITE", "AND", "OR", "NOT",
  "TRUE", "FALSE", "RETURN", "NUMBER", "INTEGER", "IDENT", "$accept",
  "program", "function", "funcparams", "funclocals", "funcbody",
  "declaration", "array", "statement", "if", "while", "dowhile", "rwfunc",
  "boolexpr", "boolexpr2", "relandexpr", "relandexpr2", "relexpr",
  "relexpr2", "comp", "expression", "multexpr", "term", "term1", "term2",
  "term3", "var", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -138

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-138)))

#define YYTABLE_NINF -22

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      29,    19,    75,    29,    76,  -138,  -138,    61,     3,    92,
       9,    25,  -138,   101,  -138,     5,   -16,    16,  -138,     3,
      92,    10,  -138,   105,    77,  -138,  -138,  -138,  -138,  -138,
    -138,   130,  -138,     5,    41,   110,   110,    59,  -138,    17,
      17,    -1,    93,  -138,   111,    18,  -138,    98,   110,    26,
     128,  -138,  -138,  -138,   107,    99,   104,    90,  -138,   181,
       8,    22,  -138,  -138,  -138,   114,    21,  -138,  -138,   148,
    -138,   148,    -1,  -138,    -1,  -138,    89,  -138,    -1,   127,
     152,   174,  -138,  -138,    -1,    47,   110,  -138,   110,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,    -1,    -1,    -1,
      -1,    -1,    -1,   102,  -138,    23,   118,  -138,    17,   155,
     126,  -138,  -138,  -138,  -138,   115,  -138,  -138,   158,   160,
    -138,  -138,   130,   143,  -138,   104,    90,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,   147,  -138,  -138,   110,  -138,
      21,  -138,   148,  -138,  -138,    -1,  -138,   165,  -138,    47,
    -138,  -138,  -138,   102,  -138,  -138,  -138,    47,  -138,  -138,
    -138
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     2,     0,     1,     3,     0,     0,     8,
       0,     0,     4,     0,     9,     0,     0,     0,     7,     0,
      13,     0,     6,     0,     0,    22,    20,    21,    19,     5,
      14,     0,    12,     0,     0,     0,     0,     0,    32,     0,
       0,     0,    90,    11,     0,     0,    10,     0,     0,     0,
       0,    63,    64,    84,    90,     0,    52,    56,    61,     0,
      73,    76,    80,    82,    83,     0,     0,    51,    28,    30,
      29,    31,     0,    33,     0,    17,     0,    34,     0,     0,
       0,     0,    81,    60,    87,     0,     0,    53,     0,    57,
      72,    66,    67,    68,    69,    70,    71,     0,     0,     0,
       0,     0,     0,     0,    47,     0,     0,    27,     0,     0,
       0,    18,    15,    16,    24,     0,    65,    85,    88,     0,
      39,    37,     0,     0,    25,    55,    59,    62,    75,    74,
      77,    78,    79,    43,    41,     0,    26,    48,     0,    46,
       0,    49,    50,    91,    23,    87,    86,     0,    38,     0,
      54,    58,    42,     0,    45,    44,    89,     0,    35,    40,
      36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -138,   169,  -138,   164,   146,   108,     6,  -138,   -30,  -137,
      38,    58,   -38,   -33,    74,   116,    78,   112,   151,  -138,
     -34,    -2,  -138,   154,  -138,    60,   -31
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    12,    22,    43,    13,    26,   123,   124,
     136,   107,    68,    55,    87,    56,    89,    57,    58,    97,
      59,    60,    61,    62,    63,   119,    64
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    44,    70,    65,     9,    72,    20,    73,    69,    71,
      14,    30,   158,    24,    81,    80,    49,    27,    67,    77,
     160,    23,   104,    28,   137,    98,    99,    10,    78,    16,
      17,    21,    72,    25,    15,    45,   106,    31,   109,    23,
     110,   100,   101,   102,   114,    45,    44,    53,   120,    54,
     118,     1,    35,    11,    45,    11,    36,    37,   138,   105,
      38,    39,    40,   127,   128,   129,    11,    42,    41,     4,
     141,    42,    45,   135,    53,     5,    42,   142,    35,     7,
     121,   122,    36,    37,     8,    34,    38,    39,    40,    47,
     111,    45,   147,   -21,    41,   -21,    66,    42,   130,   131,
     132,    74,    18,   133,    19,   154,    32,    79,    33,    45,
     106,   118,    75,    84,    76,    74,    48,   112,    45,   139,
      35,   140,    45,   135,    36,    37,    45,    49,    38,    39,
      40,    85,    88,    35,    48,   143,    41,    36,    37,    42,
     134,    38,    39,    40,   148,    49,   149,    86,   152,    41,
     153,   103,    42,   108,    50,    51,    52,   115,    53,   116,
      54,    35,   117,   145,   144,    36,    37,   146,   157,    38,
      39,    40,     6,    51,    52,    90,    53,    41,    54,    46,
      42,   117,    90,    29,   113,    91,    92,    93,    94,    95,
      96,   159,    91,    92,    93,    94,    95,    96,   155,   150,
     126,    83,   125,    82,   151,   156
};

static const yytype_uint8 yycheck[] =
{
      31,    31,    40,    36,     1,     6,     1,    41,    39,    40,
       1,     1,   149,    29,    48,    48,    17,     1,     1,     1,
     157,    15,     1,    17,     1,    17,    18,    24,    10,     4,
       5,    26,     6,    49,    25,    66,    66,    27,    72,    33,
      74,    19,    20,    21,    78,    76,    76,    48,     1,    50,
      84,    22,    31,    50,    85,    50,    35,    36,    35,    38,
      39,    40,    41,    97,    98,    99,    50,    50,    47,    50,
     108,    50,   103,   103,    48,     0,    50,   108,    31,     3,
      33,    34,    35,    36,    23,     8,    39,    40,    41,    48,
       1,   122,   122,     1,    47,     3,    37,    50,   100,   101,
     102,     8,     1,     1,     3,   138,     1,     9,     3,   140,
     140,   145,     1,     6,     3,     8,     6,    28,   149,     1,
      31,     3,   153,   153,    35,    36,   157,    17,    39,    40,
      41,    32,    42,    31,     6,     9,    47,    35,    36,    50,
      38,    39,    40,    41,     1,    17,     3,    43,     1,    47,
       3,    37,    50,     5,    44,    45,    46,    30,    48,     7,
      50,    31,     7,     5,    49,    35,    36,     7,     3,    39,
      40,    41,     3,    45,    46,     1,    48,    47,    50,    33,
      50,     7,     1,    19,    76,    11,    12,    13,    14,    15,
      16,   153,    11,    12,    13,    14,    15,    16,   140,   125,
      88,    50,    86,    49,   126,   145
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    52,    53,    50,     0,    52,     3,    23,     1,
      24,    50,    54,    57,     1,    25,     4,     5,     1,     3,
       1,    26,    55,    57,    29,    49,    58,     1,    57,    54,
       1,    27,     1,     3,     8,    31,    35,    36,    39,    40,
      41,    47,    50,    56,    59,    77,    55,    48,     6,    17,
      44,    45,    46,    48,    50,    64,    66,    68,    69,    71,
      72,    73,    74,    75,    77,    64,    37,     1,    63,    77,
      63,    77,     6,    71,     8,     1,     3,     1,    10,     9,
      64,    71,    74,    69,     6,    32,    43,    65,    42,    67,
       1,    11,    12,    13,    14,    15,    16,    70,    17,    18,
      19,    20,    21,    37,     1,    38,    59,    62,     5,    71,
      71,     1,    28,    56,    71,    30,     7,     7,    71,    76,
       1,    33,    34,    59,    60,    66,    68,    71,    71,    71,
      72,    72,    72,     1,    38,    59,    61,     1,    35,     1,
       3,    63,    77,     9,    49,     5,     7,    59,     1,     3,
      65,    67,     1,     3,    64,    62,    76,     3,    60,    61,
      60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    54,    54,    54,    54,    54,
      55,    55,    55,    55,    55,    56,    56,    56,    56,    57,
      57,    57,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    60,    60,    60,    60,    60,
      61,    61,    61,    61,    62,    62,    62,    62,    62,    63,
      63,    63,    64,    64,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    69,    69,    69,    70,    70,    70,    70,
      70,    70,    70,    71,    71,    71,    72,    72,    72,    72,
      73,    73,    73,    74,    74,    74,    75,    76,    76,    76,
      77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     5,     3,     3,     2,     1,     2,
       3,     3,     2,     1,     2,     3,     3,     2,     3,     3,
       3,     1,     1,     6,     3,     4,     4,     3,     2,     2,
       2,     2,     1,     2,     2,     3,     4,     1,     2,     1,
       3,     1,     2,     1,     3,     3,     2,     1,     2,     3,
       3,     1,     1,     2,     3,     2,     1,     2,     3,     2,
       2,     1,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     1,     1,     1,     3,     4,     0,     1,     3,
       1,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 3:
#line 30 "mini_l.y" /* yacc.c:1646  */
    {printf("program -> function program\n");}
#line 1394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 33 "mini_l.y" /* yacc.c:1646  */
    { printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS\n"); free((yyvsp[-3].str));}
#line 1400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 36 "mini_l.y" /* yacc.c:1646  */
    { printf("funcparams -> declaration SEMICOLON funcparams\n");}
#line 1406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 37 "mini_l.y" /* yacc.c:1646  */
    { printf("funcparams -> END_PARAMS BEGIN_LOCALS funclocals\n");}
#line 1412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 38 "mini_l.y" /* yacc.c:1646  */
    { printf("Syntax error at line %d: expecting \";\"\n", currLine); return 0;}
#line 1418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 39 "mini_l.y" /* yacc.c:1646  */
    { printf("Syntax error at line %d: expecting \"endparams\"\n", currLine); return 0;}
#line 1424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 40 "mini_l.y" /* yacc.c:1646  */
    { printf("Syntax error at line %d: expecting \"beginlocals\"\n", currLine); return 0;}
#line 1430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 43 "mini_l.y" /* yacc.c:1646  */
    { printf("funclocals -> declaration SEMICOLON funclocals\n");}
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 44 "mini_l.y" /* yacc.c:1646  */
    { printf("funclocals -> END_LOCALS BEGIN_BODY funcbody\n");}
#line 1442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 45 "mini_l.y" /* yacc.c:1646  */
    { printf("Syntax error at line %d: expecting \";\"\n", currLine); return 0;}
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 46 "mini_l.y" /* yacc.c:1646  */
    { printf("Syntax error at line %d: expecting \"endlocals\"\n", currLine); return 0;}
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 47 "mini_l.y" /* yacc.c:1646  */
    { printf("Syntax error at line %d: expecting \"beginbody\"\n", currLine); return 0;}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 50 "mini_l.y" /* yacc.c:1646  */
    { printf("funcbody -> statement SEMICOLON END_BODY\n");}
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 51 "mini_l.y" /* yacc.c:1646  */
    { printf("funcbody -> statement SEMICOLON statement\n");}
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 52 "mini_l.y" /* yacc.c:1646  */
    { printf("Syntax error at line %d: expecting \";\"\n", currLine); return 0;}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 53 "mini_l.y" /* yacc.c:1646  */
    { printf("Syntax error at line %d: expecting \"endbody\"\n", currLine); return 0;}
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 56 "mini_l.y" /* yacc.c:1646  */
    { printf("declaration -> IDENT COMMA declaration\n"); free((yyvsp[-2].str));}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 57 "mini_l.y" /* yacc.c:1646  */
    { printf("declaration -> IDENT COLON array\n"); free((yyvsp[-2].str));}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 58 "mini_l.y" /* yacc.c:1646  */
    { printf("Syntax error at line %d: invalid declaration\n", currLine); return 0;}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 61 "mini_l.y" /* yacc.c:1646  */
    { printf("array -> INTEGER\n");}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 62 "mini_l.y" /* yacc.c:1646  */
    { printf("array -> ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 65 "mini_l.y" /* yacc.c:1646  */
    { printf("statement -> var ASSIGN expression\n");}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 66 "mini_l.y" /* yacc.c:1646  */
    { printf("statement -> IF boolexpr THEN if\n");}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 67 "mini_l.y" /* yacc.c:1646  */
    { printf("statement -> WHILE boolexpr BEGINLOOP while\n");}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 68 "mini_l.y" /* yacc.c:1646  */
    { printf("statement -> DO BEGINLOOP dowhile\n");}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 69 "mini_l.y" /* yacc.c:1646  */
    { printf("statement -> READ rwfunc\n");}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 70 "mini_l.y" /* yacc.c:1646  */
    { printf("statement -> WRITE rwfunc\n");}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 71 "mini_l.y" /* yacc.c:1646  */
    { printf("statement -> READ var\n");}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 72 "mini_l.y" /* yacc.c:1646  */
    { printf("statement -> WRITE var\n");}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 73 "mini_l.y" /* yacc.c:1646  */
    { printf("statement -> BREAK\n");}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 74 "mini_l.y" /* yacc.c:1646  */
    { printf("statement -> RETURN expression\n");}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 75 "mini_l.y" /* yacc.c:1646  */
    { printf("Syntax error at line %d: expecting \":=\"\n", currLine); return 0;}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 78 "mini_l.y" /* yacc.c:1646  */
    { printf("if -> statement SEMICOLON if\n");}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 79 "mini_l.y" /* yacc.c:1646  */
    { printf("if -> ELSE statement SEMICOLON if\n");}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 80 "mini_l.y" /* yacc.c:1646  */
    { printf("if -> ENDIF\n");}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 81 "mini_l.y" /* yacc.c:1646  */
    { printf("Syntax error at line %d: expecting \";\"\n", currLine); return 0;}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 82 "mini_l.y" /* yacc.c:1646  */
    { printf("Syntax error at line %d: expecting \"else or endif\"\n", currLine); return 0;}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 85 "mini_l.y" /* yacc.c:1646  */
    { printf("while -> statement SEMICOLON while\n");}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 86 "mini_l.y" /* yacc.c:1646  */
    { printf("while -> ENDLOOP\n");}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 87 "mini_l.y" /* yacc.c:1646  */
    { printf("Syntax error at line %d: expecting \";\"\n", currLine); return 0;}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 88 "mini_l.y" /* yacc.c:1646  */
    { printf("Syntax error at line %d: expecting \"endloop\"\n", currLine); return 0;}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 91 "mini_l.y" /* yacc.c:1646  */
    { printf("dowhile -> statement SEMICOLON dowhile\n");}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 92 "mini_l.y" /* yacc.c:1646  */
    { printf("dowhile -> ENDLOOP WHILE boolexpr\n");}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 93 "mini_l.y" /* yacc.c:1646  */
    { printf("Syntax error at line %d: expecting \";\"\n", currLine); return 0;}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 94 "mini_l.y" /* yacc.c:1646  */
    { printf("Syntax error at line %d: expecting \"endloop\"\n", currLine); return 0;}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 95 "mini_l.y" /* yacc.c:1646  */
    { printf("Syntax error at line %d: expecting \"while\"\n", currLine); return 0;}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 98 "mini_l.y" /* yacc.c:1646  */
    { printf("rwfunc -> var COMMA rwfunc\n");}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 99 "mini_l.y" /* yacc.c:1646  */
    { printf("rwfunc -> var COMMA rwfunc\n");}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 100 "mini_l.y" /* yacc.c:1646  */
    { printf("Syntax error at line %d: expecting \",\"\n", currLine); return 0;}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 103 "mini_l.y" /* yacc.c:1646  */
    { printf("boolexpr -> relandexpr\n");}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 104 "mini_l.y" /* yacc.c:1646  */
    { printf("boolexpr -> relandexpr boolexpr2\n");}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 107 "mini_l.y" /* yacc.c:1646  */
    { printf("boolexpr2 -> OR relandexpr boolexpr2\n");}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 108 "mini_l.y" /* yacc.c:1646  */
    { printf("boolexpr2 -> OR relandexpr\n");}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 111 "mini_l.y" /* yacc.c:1646  */
    { printf("relandexpr -> relexpr\n");}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 112 "mini_l.y" /* yacc.c:1646  */
    { printf("relandexpr -> relexpr relandexpr2\n");}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 115 "mini_l.y" /* yacc.c:1646  */
    { printf("relandexpr2 -> AND relexpr relandexpr2\n");}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 116 "mini_l.y" /* yacc.c:1646  */
    { printf("relandexpr2 -> AND relexpr\n");}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 119 "mini_l.y" /* yacc.c:1646  */
    { printf("relexpr -> NOT relexpr2\n");}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 120 "mini_l.y" /* yacc.c:1646  */
    { printf("relexpr -> relexpr2\n");}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 123 "mini_l.y" /* yacc.c:1646  */
    { printf("relexpr2 -> expression comp expression\n");}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 124 "mini_l.y" /* yacc.c:1646  */
    { printf("relexpr2 -> TRUE\n");}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 125 "mini_l.y" /* yacc.c:1646  */
    { printf("relexpr2 -> FALSE\n");}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 126 "mini_l.y" /* yacc.c:1646  */
    { printf("relexpr2 -> L_PAREN boolexpr R_PAREN\n");}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 129 "mini_l.y" /* yacc.c:1646  */
    { printf("comp -> EQ\n");}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 130 "mini_l.y" /* yacc.c:1646  */
    { printf("comp -> NEQ\n");}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 131 "mini_l.y" /* yacc.c:1646  */
    { printf("comp -> LT\n");}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 132 "mini_l.y" /* yacc.c:1646  */
    { printf("comp -> GT\n");}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 133 "mini_l.y" /* yacc.c:1646  */
    { printf("comp -> LTE\n");}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 134 "mini_l.y" /* yacc.c:1646  */
    { printf("comp -> GTE\n");}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 135 "mini_l.y" /* yacc.c:1646  */
    { printf("Syntax error at line %d: expecting \"comparison operator\"\n", currLine); return 0;}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 138 "mini_l.y" /* yacc.c:1646  */
    { printf("expression -> multexpr\n");}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 139 "mini_l.y" /* yacc.c:1646  */
    { printf("expression -> multexpr ADD expression\n");}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 140 "mini_l.y" /* yacc.c:1646  */
    { printf("expression -> multexpr SUB expression\n");}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 143 "mini_l.y" /* yacc.c:1646  */
    { printf("multexpr -> term\n");}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 144 "mini_l.y" /* yacc.c:1646  */
    { printf("multexpr -> term MULT multexpr\n");}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 145 "mini_l.y" /* yacc.c:1646  */
    { printf("multexpr -> term DIV multexpr\n");}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 146 "mini_l.y" /* yacc.c:1646  */
    { printf("multexpr -> term MOD multexpr\n");}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 149 "mini_l.y" /* yacc.c:1646  */
    { printf("term -> term1\n");}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 150 "mini_l.y" /* yacc.c:1646  */
    { printf("term -> SUB term1\n");}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 151 "mini_l.y" /* yacc.c:1646  */
    { printf("term -> term2\n");}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 154 "mini_l.y" /* yacc.c:1646  */
    { printf("term1 -> var\n");}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 155 "mini_l.y" /* yacc.c:1646  */
    { printf("term1 -> NUMBER\n");}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 156 "mini_l.y" /* yacc.c:1646  */
    { printf("term1 -> L_PAREN expression R_PAREN\n");}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 159 "mini_l.y" /* yacc.c:1646  */
    { printf("term2 -> IDENT L_PAREN term3 R_PAREN\n"); free((yyvsp[-3].str));}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 163 "mini_l.y" /* yacc.c:1646  */
    { printf("term3 -> expression\n");}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 164 "mini_l.y" /* yacc.c:1646  */
    { printf("term3 -> expression COMMA term3\n");}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 167 "mini_l.y" /* yacc.c:1646  */
    { printf("var -> IDENT %s\n", (yyvsp[0].str)); free((yyvsp[0].str));}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 168 "mini_l.y" /* yacc.c:1646  */
    { printf("var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n"); free((yyvsp[-3].str));}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1920 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 170 "mini_l.y" /* yacc.c:1906  */


int main(int argc, char **argv) {
   if (argc > 1) {
      yyin = fopen(argv[1], "r");
      if (yyin == NULL){
         printf("syntax: %s filename\n", argv[0]);
      }//end if
   }//end if
   yyparse(); // Calls yylex() for tokens.
   fclose(yyin);
   return 0;
}

void yyerror(const char *msg) {
	
	printf("** Line %d, position %d: %s\n", currLine, currPos, msg);
}
