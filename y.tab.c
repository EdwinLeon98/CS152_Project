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
 #include <string.h>
 void yyerror(const char *msg);
 extern int currLine;
 extern int currPos;
 extern int errLine;
 FILE * yyin;
 int yylex(void);
 int errors[1000];
 int errInd=0;
 int tmp=0;
 char code[10000][254];
 int top=0;
 int tmp2=0;
 int temp=0;
 int label=0;
 int param=0;
 int inLoop=0;
 char declared[10000][50];
 int d1=0;
 char defined[10000][50];
 int d2=0;
 char called[10000][50];
 int calls[10000];
 int call=0;
 int fCnt=0;
 char hasMain=0;
 char error=0;
 char arrNames[10000][254];
 int arr=0;
 char varNames[10000][254];
 int varInd=0;

#line 102 "y.tab.c" /* yacc.c:339  */

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
    INTEGER = 303,
    IDENT = 304,
    NUMBER = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 37 "mini_l.y" /* yacc.c:355  */

  double dval;
  int ival;
  char* str;
  
  struct VarStruct {
	char* name;
	char* tokentype;
	char* ret_name;
	char type[20];
	char ind_name[100];
  } var_struct;

  struct ArrayStruct {
	char* name;
	int size;
  } arr_struct;

  struct Declaration {
	  int start;
	  char type[20];
	  int size;
  } decl_struct;

  struct ReadWrite {
	  int start;
  } rw_struct;

  struct ExprStruct {
	char* name;
	int value;
	char* tokentype;
	char ret_name[80];
	char* next;
	int start;
	char type[20];
  } expr_struct;

  struct RelExprStruct {
	char ret_name[80];
	int start;
	char inner[50];
	char type[10];
	int done;
	int end;
	int outside;
	int stateStrt;
  } relexpr_struct;

  struct CompStruct {
	char* name;
  } comp_struct;

  struct StatementStruct {
	char* IR[254];
	int stateStrt;
	char ret_name[80];
  } statement_struct;

  struct FuncStruct {
	  char name[80];
	  int start;
	  char* IR[254];
  } func_struct;

#line 259 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 276 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   401

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  220

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
static const yytype_uint16 yyrline[] =
{
       0,   139,   139,   142,   143,   146,   192,   193,   194,   195,
     198,   199,   200,   201,   202,   205,   206,   207,   208,   211,
     212,   213,   214,   215,   216,   219,   255,   286,   317,   318,
     321,   358,   383,   414,   415,   418,   430,   469,   522,   547,
     548,   549,   554,   559,   564,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   583,   584,   585,
     589,   590,   593,   594,   595,   596,   597,   600,   601,   602,
     603,   604,   605,   608,   617,   628,   631,   640,   651,   654,
     655,   674,   675,   694,   713,   716,   733,   749,   765,   766,
     769,   770,   771,   772,   773,   774,   775,   778,   779,   795,
     813,   814,   830,   846,   864,   865,   892,   895,   920,   936,
     939,   959,   960,   965,   968,   988
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
  "TRUE", "FALSE", "RETURN", "INTEGER", "IDENT", "NUMBER", "$accept",
  "prog_start", "functions", "function", "funcparams", "funclocals",
  "funcbody", "declaration1", "declaration2", "statement", "if", "while",
  "dowhile", "rfunc", "wfunc", "boolexpr", "relandexpr", "relexpr",
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

#define YYPACT_NINF -133

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-133)))

#define YYTABLE_NINF -97

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -9,    36,   126,  -133,    -9,    27,    17,  -133,  -133,    90,
     121,   109,    11,    11,    11,    23,  -133,   110,   111,  -133,
      25,  -133,  -133,    30,  -133,    38,    58,  -133,   -12,    39,
      11,    11,  -133,    18,   158,  -133,   188,   114,  -133,   142,
    -133,  -133,  -133,  -133,   265,   265,  -133,    80,    40,    38,
      38,   265,   115,   168,   275,   102,     7,  -133,    41,    45,
       5,   153,  -133,   221,    24,  -133,   175,  -133,  -133,  -133,
    -133,  -133,   167,   154,   275,   118,   253,  -133,  -133,   219,
    -133,    85,   145,   161,  -133,   385,   113,   160,  -133,  -133,
    -133,   275,   105,   174,   174,  -133,  -133,   191,  -133,  -133,
     199,  -133,    52,  -133,    52,   201,   216,    52,    26,   157,
     181,  -133,   209,   377,  -133,  -133,    52,   159,   159,   275,
     275,   108,  -133,  -133,  -133,  -133,  -133,  -133,    52,    52,
      52,    52,    52,    52,  -133,   291,   233,  -133,    28,   225,
    -133,  -133,    47,    51,   223,   226,  -133,  -133,   168,  -133,
    -133,  -133,   119,  -133,   229,   198,  -133,  -133,   234,   246,
    -133,  -133,   336,   230,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,   242,  -133,   306,  -133,  -133,
     128,  -133,   174,  -133,  -133,   191,  -133,  -133,   199,  -133,
      52,    52,   224,  -133,    52,  -133,   255,   159,   159,   291,
     248,  -133,  -133,  -133,  -133,  -133,  -133,  -133,   227,  -133,
     159,  -133,  -133,  -133,   321,  -133,  -133,  -133,  -133,  -133
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     3,     0,     0,     1,     4,     0,
       0,     0,     0,     0,     0,     0,    29,     0,     0,     9,
       0,     8,     7,     6,     5,     0,     0,    28,     0,     0,
       0,     0,    34,     0,     0,    13,     0,    34,    11,     0,
      26,    25,    12,    10,     0,     0,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    43,     0,     0,
       0,   114,    18,     0,     0,    16,     0,    31,    30,    17,
      15,    14,     0,     0,     0,     0,     0,    86,    87,   114,
     108,     0,    79,    81,    84,     0,    97,   100,   104,   106,
     107,     0,     0,     0,     0,    53,    39,    41,    54,    40,
      42,    55,     0,    44,     0,     0,     0,     0,     0,     0,
       0,    23,     0,     0,   105,    83,   111,     0,     0,     0,
       0,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,    56,     0,     0,    70,     0,     0,
      52,    38,     0,     0,     0,     0,    24,    22,    21,    19,
      20,    45,     0,    35,     0,     0,    88,   109,   112,     0,
      61,    59,     0,     0,    48,    36,    80,    82,    85,    99,
      98,   101,   102,   103,    63,     0,    49,     0,    37,    71,
       0,    69,     0,    75,    73,    74,    78,    76,    77,   115,
       0,     0,     0,    27,   111,   110,     0,     0,     0,     0,
       0,    51,    50,    72,    68,    67,    47,    46,     0,   113,
       0,    60,    57,    64,     0,    62,    32,    58,    66,    65
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,   263,  -133,   247,    71,   -35,   256,   228,   -13,
    -115,  -132,   -89,   148,   150,   -53,   171,  -133,   218,  -133,
     -51,    87,  -133,   232,  -133,   116,   -44
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    19,    35,    62,    20,    36,    63,
     164,   176,   140,    96,    99,    81,    82,    83,    84,   128,
      85,    86,    87,    88,    89,   159,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,    64,    92,   165,   178,   141,   101,    64,    93,   103,
      65,   102,    16,     1,    97,   100,    71,    39,    10,    44,
      11,   112,    75,   113,    23,   107,    30,   152,    31,   179,
       9,   -29,   102,   -29,   108,    17,    40,     5,   134,    32,
      16,    32,    95,    75,    94,    45,    98,    17,   183,    64,
      64,   144,   186,   145,    79,    80,   151,   153,   102,    37,
      18,    64,    64,   180,    33,   158,   166,   213,   215,    75,
     147,   150,    18,    64,    64,    79,    80,   168,   169,   170,
     139,   139,   211,   212,    33,     6,   117,    34,    18,    34,
      61,    64,    64,   205,    61,   217,    61,    38,   185,   188,
      61,    79,    80,    91,   163,   163,   135,    34,    74,    66,
      14,    25,    27,    12,   -96,    28,    29,   118,    64,    75,
      69,    70,   175,   175,   102,   -96,     7,   204,    67,   203,
     129,   130,    15,    64,    74,    26,   190,   191,    64,   206,
     207,    51,   136,   158,    13,    75,    76,    77,    78,   196,
      52,    79,    80,    64,    64,    64,    64,   -96,   -96,    46,
     160,   104,    47,    48,   202,    72,    64,    61,    80,   139,
      64,    73,    76,    77,    78,   137,   110,    79,    80,   131,
     132,   133,   111,   109,   163,   163,   175,   175,   119,    49,
      54,    50,   161,   162,    55,    56,   142,   163,    57,    58,
      59,   219,    53,   120,   143,    54,    60,   154,    61,    55,
      56,   155,   138,    57,    58,    59,   156,   148,   171,   172,
     173,    60,   105,    61,   106,   116,   181,   104,   182,   146,
     157,   197,    54,   198,   177,   189,    55,    56,   192,   194,
      57,    58,    59,   199,   149,   200,   193,    54,    60,   214,
      61,    55,    56,   195,   208,    57,    58,    59,   210,    74,
      21,    22,    24,    60,    54,    61,    53,     8,    55,    56,
      75,   174,    57,    58,    59,   216,    68,    42,    43,    54,
      60,    74,    61,    55,    56,    41,   174,    57,    58,    59,
     184,   167,    75,   187,   115,    60,    54,    61,    77,    78,
      55,    56,    79,    80,    57,    58,    59,   114,     0,     0,
     209,     0,    60,     0,    61,     0,     0,     0,     0,    76,
      77,    78,    54,     0,    79,    80,    55,    56,     0,   174,
      57,    58,    59,     0,     0,     0,     0,    54,    60,     0,
      61,    55,    56,     0,   201,    57,    58,    59,     0,     0,
       0,     0,    54,    60,     0,    61,    55,    56,     0,   218,
      57,    58,    59,     0,     0,     0,     0,    54,    60,     0,
      61,    55,    56,     0,     0,    57,    58,    59,   121,     0,
       0,     0,     0,    60,   157,    61,   121,     0,   122,   123,
     124,   125,   126,   127,     0,     0,   122,   123,   124,   125,
     126,   127
};

static const yytype_int16 yycheck[] =
{
      44,    45,    55,   118,   136,    94,     1,    51,     1,    60,
      45,     6,     1,    22,    58,    59,    51,    29,     1,     1,
       3,    74,    17,    74,     1,     1,     1,     1,     3,     1,
       3,     1,     6,     3,    10,    24,    48,     1,    91,     1,
       1,     1,     1,    17,    37,    27,     1,    24,     1,    93,
      94,   102,     1,   104,    49,    50,   107,   108,     6,     1,
      49,   105,   106,    35,    26,   116,   119,   199,   200,    17,
     105,   106,    49,   117,   118,    49,    50,   128,   129,   130,
      93,    94,   197,   198,    26,    49,     1,    49,    49,    49,
      49,   135,   136,   182,    49,   210,    49,    26,   142,   143,
      49,    49,    50,     1,   117,   118,     1,    49,     6,    29,
       1,     1,     1,    23,     6,     4,     5,    32,   162,    17,
      49,    50,   135,   136,     6,    17,     0,   180,    48,     1,
      17,    18,    23,   177,     6,    25,    17,    18,   182,   190,
     191,    27,    37,   194,    23,    17,    44,    45,    46,   162,
       8,    49,    50,   197,   198,   199,   200,    49,    50,     1,
       1,     8,     4,     5,   177,    50,   210,    49,    50,   182,
     214,     3,    44,    45,    46,     1,     9,    49,    50,    19,
      20,    21,    28,     8,   197,   198,   199,   200,    43,     1,
      31,     3,    33,    34,    35,    36,     5,   210,    39,    40,
      41,   214,     1,    42,     5,    31,    47,    50,    49,    35,
      36,    30,    38,    39,    40,    41,     7,     1,   131,   132,
     133,    47,     1,    49,     3,     6,     1,     8,     3,    28,
       7,     1,    31,     3,     1,     9,    35,    36,     9,     5,
      39,    40,    41,     1,    28,     3,    48,    31,    47,     1,
      49,    35,    36,     7,    30,    39,    40,    41,     3,     6,
      13,    14,    15,    47,    31,    49,     1,     4,    35,    36,
      17,    38,    39,    40,    41,    48,    48,    30,    31,    31,
      47,     6,    49,    35,    36,    29,    38,    39,    40,    41,
     142,   120,    17,   143,    76,    47,    31,    49,    45,    46,
      35,    36,    49,    50,    39,    40,    41,    75,    -1,    -1,
     194,    -1,    47,    -1,    49,    -1,    -1,    -1,    -1,    44,
      45,    46,    31,    -1,    49,    50,    35,    36,    -1,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    31,    47,    -1,
      49,    35,    36,    -1,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    31,    47,    -1,    49,    35,    36,    -1,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    31,    47,    -1,
      49,    35,    36,    -1,    -1,    39,    40,    41,     1,    -1,
      -1,    -1,    -1,    47,     7,    49,     1,    -1,    11,    12,
      13,    14,    15,    16,    -1,    -1,    11,    12,    13,    14,
      15,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    52,    53,    54,     1,    49,     0,    53,     3,
       1,     3,    23,    23,     1,    23,     1,    24,    49,    55,
      58,    55,    55,     1,    55,     1,    25,     1,     4,     5,
       1,     3,     1,    26,    49,    56,    59,     1,    56,    29,
      48,    58,    55,    55,     1,    27,     1,     4,     5,     1,
       3,    27,     8,     1,    31,    35,    36,    39,    40,    41,
      47,    49,    57,    60,    77,    57,    29,    48,    59,    56,
      56,    57,    50,     3,     6,    17,    44,    45,    46,    49,
      50,    66,    67,    68,    69,    71,    72,    73,    74,    75,
      77,     1,    66,     1,    37,     1,    64,    77,     1,    65,
      77,     1,     6,    71,     8,     1,     3,     1,    10,     8,
       9,    28,    66,    71,    74,    69,     6,     1,    32,    43,
      42,     1,    11,    12,    13,    14,    15,    16,    70,    17,
      18,    19,    20,    21,    66,     1,    37,     1,    38,    60,
      63,    63,     5,     5,    71,    71,    28,    57,     1,    28,
      57,    71,     1,    71,    50,    30,     7,     7,    71,    76,
       1,    33,    34,    60,    61,    61,    66,    67,    71,    71,
      71,    72,    72,    72,    38,    60,    62,     1,    62,     1,
      35,     1,     3,     1,    64,    77,     1,    65,    77,     9,
      17,    18,     9,    48,     5,     7,    60,     1,     3,     1,
       3,    38,    60,     1,    66,    63,    71,    71,    30,    76,
       3,    61,    61,    62,     1,    62,    48,    61,    38,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    54,    54,    54,
      55,    55,    55,    55,    55,    56,    56,    56,    56,    57,
      57,    57,    57,    57,    57,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    61,    61,    61,
      61,    61,    62,    62,    62,    62,    62,    63,    63,    63,
      63,    63,    63,    64,    64,    64,    65,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    69,    69,    69,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    71,
      72,    72,    72,    72,    73,    73,    73,    74,    74,    74,
      75,    76,    76,    76,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     5,     5,     5,     5,     5,
       3,     3,     3,     3,     5,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     8,     2,     1,
       3,     3,     8,     2,     1,     3,     4,     4,     3,     2,
       2,     2,     2,     1,     2,     3,     5,     5,     4,     4,
       5,     5,     3,     2,     2,     2,     3,     3,     4,     1,
       3,     1,     3,     1,     3,     4,     4,     3,     3,     2,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     3,     2,     1,     3,     1,     1,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     3,     3,     3,     1,     2,     1,     1,     1,     3,
       4,     0,     1,     3,     1,     4
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
        case 2:
#line 139 "mini_l.y" /* yacc.c:1646  */
    {  }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 142 "mini_l.y" /* yacc.c:1646  */
    {  }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 143 "mini_l.y" /* yacc.c:1646  */
    {  }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 146 "mini_l.y" /* yacc.c:1646  */
    { 	char c[] = "func ";
																				strcat(c, (yyvsp[-3].str));
																				strcat(c, "\n");
																				strcpy((yyval.func_struct).name, c);
																				tmp2++;
																				strcpy(defined[d2], (yyvsp[-3].str));
																				if(strcmp(defined[d2], "main") == 0) hasMain = 1;
																				d2++;

																			  	for(int i = 0; i < call; i++) {
																					char found = 0;
																					for(int j = 0; j < d2; j++) {
																						if(strcmp(defined[j], called[i]) == 0) {
																							found = 1;
																							j = d2;
																						}
																					}
																					if(!found) {
																						printf("Error line %d: function \"%s\" called before definition.\n", calls[i], called[i]);
																						error = 1;
																					}
																			  	}

																				if(fCnt > 0) {
																					for(int i = 10000; i > top; i--) {
																						strcpy(code[i], code[i-1]);
																					}
																					strcpy(code[top], "endfunc\n\n");

																					for(int i = 10000; i > top+1; i--) {
																						strcpy(code[i], code[i-1]);
																					}
																					strcpy(code[top+1], (yyval.func_struct).name);
																				}
																				else {
																					for(int i = 10000; i > top; i--) {
																						strcpy(code[i], code[i-1]);
																					}
																					strcpy(code[top], (yyval.func_struct).name);
																				}
																				for(int i = top; i < 10000; i++) {
																					strcpy(declared[i], "");
																				}
																				top = tmp2;
																				fCnt++;
																			}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 192 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"declaration or endparams\"\n", errors[tmp]); }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 193 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"beginparams\"\n", errors[tmp]); }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 194 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]); }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 195 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"identifier\"\n", errors[tmp]); }
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 198 "mini_l.y" /* yacc.c:1646  */
    {  }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 199 "mini_l.y" /* yacc.c:1646  */
    {  }
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 200 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]); }
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 201 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"beginlocals\"\n", errors[tmp]); }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 202 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"declaration or endlocals\"\n", errors[tmp]); }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 205 "mini_l.y" /* yacc.c:1646  */
    {  }
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 206 "mini_l.y" /* yacc.c:1646  */
    {  }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 207 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]); }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 208 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"beginbody\"\n", errors[tmp]); }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 211 "mini_l.y" /* yacc.c:1646  */
    {  }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 212 "mini_l.y" /* yacc.c:1646  */
    {  }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 213 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"statement or endbody\"\n", errors[tmp]); }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 214 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]); }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 215 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"statement\"\n", errors[tmp]); }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 216 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]); }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 219 "mini_l.y" /* yacc.c:1646  */
    { 	
																				for(int i = 0; i < d1; i++) {
																					if(strcmp(declared[i], (yyvsp[-2].str)) == 0) {
																						printf("Error line %d: symbol \"%s\" is already defined.\n", currLine, (yyvsp[-2].str));
																						error = 1;
																					}
																				}
																				if((strcmp((yyvsp[-2].str), "true") == 0) || (strcmp((yyvsp[-2].str), "false") == 0)) {
																					printf("Error line %d: symbol \"%s\" is a reserved keyword and cannot be used to declare variables.\n", currLine, (yyvsp[-2].str));
																					error = 1;
																				}
																				strcpy(declared[d1], (yyvsp[-2].str));
																				d1++;
																				
																				for(int i = tmp2; i > (yyvsp[0].decl_struct).start; i--) {
																					strcpy(code[i], code[i-1]);
																				}
																				if(strcmp((yyvsp[0].decl_struct).type, "var") == 0) {
																					char c[200];
																					sprintf(c, ". %s\n", (yyvsp[-2].str));
																					strcpy(code[(yyvsp[0].decl_struct).start], c);
																					strcpy(varNames[varInd], (yyvsp[-2].str));
																					varInd++;
																				}
																				else if(strcmp((yyvsp[0].decl_struct).type, "array") == 0) {
																					char c[200];
																			  		sprintf(c, ".[] %s, %d\n", (yyvsp[-2].str), (yyvsp[0].decl_struct).size);
																					strcpy(code[(yyvsp[0].decl_struct).start], c);
																					strcpy(arrNames[arr], (yyvsp[-2].str));
																			  		arr++;
																				}
																				(yyval.decl_struct).start = (yyvsp[0].decl_struct).start;
																				strcpy((yyval.decl_struct).type, (yyvsp[0].decl_struct).type);
																				(yyval.decl_struct).size = (yyvsp[0].decl_struct).size;
																			  	tmp2++;
																			}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 255 "mini_l.y" /* yacc.c:1646  */
    {	for(int i = 0; i < d1; i++) {
																					if(strcmp(declared[i], (yyvsp[-2].str)) == 0) {
																						printf("Error line %d: symbol \"%s\" is already defined.\n", currLine, (yyvsp[-2].str));
																						error = 1;
																					}
																				}

																				if((strcmp((yyvsp[-2].str), "true") == 0) || (strcmp((yyvsp[-2].str), "false") == 0)) {
																					printf("Error line %d: symbol \"%s\" is a reserved keyword and cannot be used to declare variables.\n", currLine, (yyvsp[-2].str));
																					error = 1;
																				}

																				strcpy(declared[d1], (yyvsp[-2].str));
																				d1++;

																				strcpy(varNames[varInd], (yyvsp[-2].str));
																				varInd++;
																				
																				char c[200];
																				sprintf(c, ". %s\n", (yyvsp[-2].str));
																				strcpy(code[tmp2], c);
																				(yyval.decl_struct).start = tmp2;
																				strcpy((yyval.decl_struct).type, "var");
																				tmp2++;

																				char c1[200];
																				sprintf(c1, "= %s, $%d\n", (yyvsp[-2].str), param);
																				strcpy(code[tmp2], c1);
																				strcpy((yyval.decl_struct).type, "var");
																				tmp2++;
																			}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 286 "mini_l.y" /* yacc.c:1646  */
    { 	for(int i = 0; i < d1; i++) {
																								if(strcmp(declared[i], (yyvsp[-7].str)) == 0) {
																									printf("Error line %d: symbol \"%s\" is already defined.\n", currLine, (yyvsp[-7].str));
																									error = 1;
																								}
																							}

																							if((strcmp((yyvsp[-7].str), "true") == 0) || (strcmp((yyvsp[-7].str), "false") == 0)) {
																								printf("Error line %d: symbol \"%s\" is a reserved keyword and cannot be used to declare variables.\n", currLine, (yyvsp[-7].str));
																								error = 1;
																							}

																							if((yyvsp[-3].expr_struct).value <= 0) {
																								printf("Error line %d: symbol \"%s\" has array index less than or equal to zero.\n", currLine, (yyvsp[-7].str));
																								error = 1;
																							}

																							strcpy(declared[d1], (yyvsp[-7].str));
																							d1++;

																							strcpy(arrNames[arr], (yyvsp[-7].str));
																			  				arr++;
																							
																							char c[200];
																			  			  	sprintf(c, ".[] %s, %d\n", (yyvsp[-7].str), (yyvsp[-3].expr_struct).value);
																			  			  	strcpy(code[tmp2], c);
																							(yyval.decl_struct).start = tmp2;
																							strcpy((yyval.decl_struct).type, "array");
																							(yyval.decl_struct).size = (yyvsp[-3].expr_struct).value;
																			  			  	tmp2++;
																						}
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 317 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: invalid declaration\n", errors[tmp]); }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 318 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"identifier, endparams, or endlocals\"\n", errors[tmp]); }
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 321 "mini_l.y" /* yacc.c:1646  */
    { 	for(int i = 0; i < d1; i++) {
																					if(strcmp(declared[i], (yyvsp[-2].str)) == 0) {
																						printf("Error line %d: symbol \"%s\" is already defined.\n", currLine, (yyvsp[-2].str));
																						error = 1;
																					}
																				}

																				if((strcmp((yyvsp[-2].str), "true") == 0) || (strcmp((yyvsp[-2].str), "false") == 0)) {
																					printf("Error line %d: symbol \"%s\" is a reserved keyword and cannot be used to declare variables.\n", currLine, (yyvsp[-2].str));
																					error = 1;
																				}

																				strcpy(declared[d1], (yyvsp[-2].str));
																				d1++;
																				
																				for(int i = tmp2; i > (yyvsp[0].decl_struct).start; i--) {
																					strcpy(code[i], code[i-1]);
																				}
																				if(strcmp((yyvsp[0].decl_struct).type, "var") == 0) {
																					char c[200];
																					sprintf(c, ". %s\n", (yyvsp[-2].str));
																					strcpy(code[(yyvsp[0].decl_struct).start], c);
																					strcpy(varNames[varInd], (yyvsp[-2].str));
																					varInd++;
																				}
																				else if(strcmp((yyvsp[0].decl_struct).type, "array") == 0) {
																					char c[200];
																			  		sprintf(c, ".[] %s, %d\n", (yyvsp[-2].str), (yyvsp[0].decl_struct).size);
																					strcpy(code[(yyvsp[0].decl_struct).start], c);
																					strcpy(arrNames[arr], (yyvsp[-2].str));
																			  		arr++;
																				}
																				(yyval.decl_struct).start = (yyvsp[0].decl_struct).start;
																				strcpy((yyval.decl_struct).type, (yyvsp[0].decl_struct).type);
																				(yyval.decl_struct).size = (yyvsp[0].decl_struct).size;
																			  	tmp2++;
																			}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 358 "mini_l.y" /* yacc.c:1646  */
    {	for(int i = 0; i < d1; i++) {
																					if(strcmp(declared[i], (yyvsp[-2].str)) == 0) {
																						printf("Error line %d: symbol \"%s\" is already defined.\n", currLine, (yyvsp[-2].str));
																						error = 1;
																					}
																				}

																				if((strcmp((yyvsp[-2].str), "true") == 0) || (strcmp((yyvsp[-2].str), "false") == 0)) {
																					printf("Error line %d: symbol \"%s\" is a reserved keyword and cannot be used to declare variables.\n", currLine, (yyvsp[-2].str));
																					error = 1;
																				}

																				strcpy(declared[d1], (yyvsp[-2].str));
																				d1++;

																				strcpy(varNames[varInd], (yyvsp[-2].str));
																				varInd++;
																				
																				char c[200];
																				sprintf(c, ". %s\n", (yyvsp[-2].str));
																				strcpy(code[tmp2], c);
																				(yyval.decl_struct).start = tmp2;
																				strcpy((yyval.decl_struct).type, "var");
																				tmp2++;
																			}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 383 "mini_l.y" /* yacc.c:1646  */
    { 	for(int i = 0; i < d1; i++) {
																								if(strcmp(declared[i], (yyvsp[-7].str)) == 0) {
																									printf("Error line %d: symbol \"%s\" is already defined.\n", currLine, (yyvsp[-7].str));
																									error = 1;
																								}
																							}

																							if((strcmp((yyvsp[-7].str), "true") == 0) || (strcmp((yyvsp[-7].str), "false") == 0)) {
																								printf("Error line %d: symbol \"%s\" is a reserved keyword and cannot be used to declare variables.\n", currLine, (yyvsp[-7].str));
																								error = 1;
																							}

																							if((yyvsp[-3].expr_struct).value <= 0) {
																								printf("Error line %d: symbol \"%s\" has array index less than or equal to zero.\n", currLine, (yyvsp[-7].str));
																								error = 1;
																							}

																							strcpy(declared[d1], (yyvsp[-7].str));
																							d1++;

																							strcpy(arrNames[arr], (yyvsp[-7].str));
																			  				arr++;
																							
																							char c[200];
																			  			  	sprintf(c, ".[] %s, %d\n", (yyvsp[-7].str), (yyvsp[-3].expr_struct).value);
																			  			  	strcpy(code[tmp2], c);
																							(yyval.decl_struct).start = tmp2;
																							strcpy((yyval.decl_struct).type, "array");
																							(yyval.decl_struct).size = (yyvsp[-3].expr_struct).value;
																			  			  	tmp2++;
																						}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 414 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: invalid declaration\n", errors[tmp]); }
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 415 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"identifier, endparams, or endlocals\"\n", errors[tmp]); }
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 418 "mini_l.y" /* yacc.c:1646  */
    { char c1[200];
																			  if(strcmp((yyvsp[-2].var_struct).type, "var") == 0) {
																				sprintf(c1, "= %s, %s\n", (yyvsp[-2].var_struct).name, (yyvsp[0].expr_struct).ret_name);
																				strcpy(code[tmp2], c1);
																			  }
																			  else if(strcmp((yyvsp[-2].var_struct).type, "array") == 0) {
																				  sprintf(c1, "[]= %s, %s, %s\n", (yyvsp[-2].var_struct).name, (yyvsp[-2].var_struct).ind_name, (yyvsp[0].expr_struct).ret_name);
																				  strcpy(code[tmp2], c1);
																			  }
																			  (yyval.statement_struct).stateStrt = (yyvsp[0].expr_struct).start;
																			  tmp2++;
																			}
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 430 "mini_l.y" /* yacc.c:1646  */
    { if((yyvsp[0].relexpr_struct).done) {
																				
																				char c0[200];
																				sprintf(c0, ": __label__%d\n", label+1);
																				strcpy(code[(yyvsp[0].relexpr_struct).outside], c0);

																				for(int i = tmp2; i > (yyvsp[-2].relexpr_struct).end; i--) {
																					strcpy(code[i], code[i-1]);
																				}
																				tmp2++;
																				for(int i = tmp2; i > (yyvsp[-2].relexpr_struct).end; i--) {
																					strcpy(code[i], code[i-1]);
																				}
																				tmp2++;
																				for(int i = tmp2; i > (yyvsp[-2].relexpr_struct).end; i--) {
																					strcpy(code[i], code[i-1]);
																				}

																				inLoop -= 1;

																				char c1[200];
																				sprintf(c1, "?:= __label__%d, %s\n", label, (yyvsp[-2].relexpr_struct).ret_name);
																				strcpy(code[(yyvsp[-2].relexpr_struct).end], c1);
																				tmp2++;

																				char c2[200];
																				sprintf(c2, ":= __label__%d\n", label+1);
																				strcpy(code[(yyvsp[-2].relexpr_struct).end+1], c2);
																				tmp2++;

																				char c3[200];
																				sprintf(c3, ": __label__%d\n", label);
																				strcpy(code[(yyvsp[-2].relexpr_struct).end+2], c3);
																				tmp2++;
																				label+=2;
																			  }
																			  (yyval.statement_struct).stateStrt = (yyvsp[-2].relexpr_struct).start;

																			}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 469 "mini_l.y" /* yacc.c:1646  */
    {  if(strcmp((yyvsp[-2].relexpr_struct).type, "nested") && (yyvsp[0].relexpr_struct).done) {
																				for(int i = tmp2; i > (yyvsp[-2].relexpr_struct).end; i--) {
																					strcpy(code[i], code[i-1]);
																				}
																				tmp2++;
																				for(int i = tmp2; i > (yyvsp[-2].relexpr_struct).end; i--) {
																					strcpy(code[i], code[i-1]);
																				}
																				tmp2++;
																				for(int i = tmp2; i > (yyvsp[-2].relexpr_struct).end; i--) {
																					strcpy(code[i], code[i-1]);
																				}

																				inLoop -= 1;

																				char c1[200];
																				sprintf(c1, "?:= __label__%d, %s\n", label, (yyvsp[-2].relexpr_struct).ret_name);
																				strcpy(code[(yyvsp[-2].relexpr_struct).end], c1);
																				tmp2++;

																				char c2[200];
																				sprintf(c2, ":= __label__%d\n", label+1);
																				strcpy(code[(yyvsp[-2].relexpr_struct).end+1], c2);
																				tmp2++;

																				char c3[200];
																				sprintf(c3, ": __label__%d\n", label);
																				strcpy(code[(yyvsp[-2].relexpr_struct).end+2], c3);
																				tmp2++;
																				label+=2;
																			  }

																			  char c1[200];
																			  sprintf(c1, ":= __label__%d\n", label);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, ": __label__%d\n", label-1);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;

																			  char c3[200];
																			  sprintf(c3, ": __label__%d\n", label);
																			  tmp2++;

																			  for(int i = tmp2; i > (yyvsp[-2].relexpr_struct).start; i--) {
																				  strcpy(code[i], code[i-1]);
																			  }
																			  strcpy(code[(yyvsp[-2].relexpr_struct).start], c3);
																			  tmp2++;
																			  label++;
																			}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 522 "mini_l.y" /* yacc.c:1646  */
    { if((yyvsp[0].relexpr_struct).done) {

																				for(int i = tmp2; i > (yyvsp[0].relexpr_struct).stateStrt; i--) {
																					strcpy(code[i], code[i-1]);
																				}

																				char c3[200];
																				sprintf(c3, ": __label__%d\n", label);
																				strcpy(code[(yyvsp[0].relexpr_struct).stateStrt], c3);
																				tmp2++;

																				for(int i = (yyvsp[0].relexpr_struct).start; i <= (yyvsp[0].relexpr_struct).end; i++) {
																					strcpy(code[tmp2], code[i]);
																					tmp2++;
																				}

																				char c1[200];
																				sprintf(c1, "?:= __label__%d, %s\n", label, (yyvsp[0].relexpr_struct).ret_name);
																				strcpy(code[tmp2-1], c1);
																				tmp2++;

																				inLoop -= 1;
																				label++;
																			  }
																			}
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 547 "mini_l.y" /* yacc.c:1646  */
    {  }
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 548 "mini_l.y" /* yacc.c:1646  */
    {  }
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 549 "mini_l.y" /* yacc.c:1646  */
    { char c1[200];
																			  sprintf(c1, ".< %s\n", (yyvsp[0].var_struct).name);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;
																			}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 554 "mini_l.y" /* yacc.c:1646  */
    { char c1[200];
																			  sprintf(c1, ".> %s\n", (yyvsp[0].var_struct).name);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;
																			}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 559 "mini_l.y" /* yacc.c:1646  */
    { if(!inLoop) {
																				printf("Error line %d: break statement not within a loop.\n", currLine);
																				error = 1;
																			  }
																			}
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 564 "mini_l.y" /* yacc.c:1646  */
    { char c1[200];
																			  sprintf(c1, "ret __temp__%d\n", temp-1);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;
																			}
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 569 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \":=\"\n", errors[tmp]); }
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 570 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"expression\"\n", errors[tmp]); }
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 571 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"expression\"\n", errors[tmp]); }
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 572 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"then\"\n", errors[tmp]); }
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 573 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"beginloop\"\n", errors[tmp]); }
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 574 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: \"invalid statement\"\n", errors[tmp]); }
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 575 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: \"invalid statement\"\n", errors[tmp]); }
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 576 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"beginloop\"\n", errors[tmp]); }
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 577 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: \"invalid read\"\n", errors[tmp]); }
#line 2218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 578 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: \"invalid write\"\n", errors[tmp]); }
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 579 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"return expression\"\n", errors[tmp]); }
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 580 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"while loop condition\"\n", errors[tmp]); }
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 583 "mini_l.y" /* yacc.c:1646  */
    { (yyval.relexpr_struct).done = (yyvsp[0].relexpr_struct).done; (yyval.relexpr_struct).outside = (yyvsp[0].relexpr_struct).outside; (yyval.relexpr_struct).stateStrt = (yyvsp[-2].statement_struct).stateStrt; }
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 584 "mini_l.y" /* yacc.c:1646  */
    {  }
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 585 "mini_l.y" /* yacc.c:1646  */
    { (yyval.relexpr_struct).done = 1;
																			  (yyval.relexpr_struct).outside = tmp2;
																			  tmp2++;
																		    }
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 589 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]); }
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 590 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"else or endif\"\n", errors[tmp]); }
#line 2269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 593 "mini_l.y" /* yacc.c:1646  */
    { (yyval.relexpr_struct).done = (yyvsp[0].relexpr_struct).done; }
#line 2275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 594 "mini_l.y" /* yacc.c:1646  */
    { (yyval.relexpr_struct).done = 1; inLoop += 1; }
#line 2281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 595 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]); }
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 596 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"statement or endloop\"\n", errors[tmp]); }
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 597 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"statement or endloop\"\n", errors[tmp]); }
#line 2299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 600 "mini_l.y" /* yacc.c:1646  */
    { (yyval.relexpr_struct).done = (yyvsp[0].relexpr_struct).done; (yyval.relexpr_struct).stateStrt = (yyvsp[-2].statement_struct).stateStrt; strcpy((yyval.relexpr_struct).ret_name, (yyvsp[0].relexpr_struct).ret_name); }
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 601 "mini_l.y" /* yacc.c:1646  */
    { (yyval.relexpr_struct).done = 1; inLoop += 1; strcpy((yyval.relexpr_struct).ret_name, (yyvsp[0].relexpr_struct).ret_name); (yyval.relexpr_struct).start = (yyvsp[0].relexpr_struct).start; (yyval.relexpr_struct).end = (yyvsp[0].relexpr_struct).end; }
#line 2311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 602 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]); }
#line 2317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 603 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"statement or endloop\"\n", errors[tmp]); }
#line 2323 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 604 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"while\"\n", errors[tmp]); }
#line 2329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 605 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"boolean expression\"\n", errors[tmp]); }
#line 2335 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 608 "mini_l.y" /* yacc.c:1646  */
    { 	for(int i = tmp2; i > (yyvsp[0].rw_struct).start; i--) {
																					strcpy(code[i], code[i-1]);
																			  	}
																				char c[] = ".< ";
																			  	strcat(c, (yyvsp[-2].var_struct).name);
																			  	strcat(c, "\n");
																			  	strcpy(code[(yyvsp[0].rw_struct).start], c);
																			  	tmp2++;
																			}
#line 2349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 617 "mini_l.y" /* yacc.c:1646  */
    { char c1[200];
																			  sprintf(c1, ".< %s\n", (yyvsp[-2].var_struct).name);
																			  strcpy(code[tmp2], c1);
																			  (yyval.rw_struct).start = tmp2;
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, ".< %s\n", (yyvsp[0].var_struct).name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			}
#line 2365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 628 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"var\"\n", errors[tmp]); }
#line 2371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 631 "mini_l.y" /* yacc.c:1646  */
    { 	for(int i = tmp2; i > (yyvsp[0].rw_struct).start; i--) {
																				strcpy(code[i], code[i-1]);
																			}
																			char c[] = ".> ";
																			strcat(c, (yyvsp[-2].var_struct).name);
																			strcat(c, "\n");
																			strcpy(code[(yyvsp[0].rw_struct).start], c);
																			tmp2++;
																			}
#line 2385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 640 "mini_l.y" /* yacc.c:1646  */
    { char c1[200];
																			  sprintf(c1, ".> %s\n", (yyvsp[-2].var_struct).name);
																			  strcpy(code[tmp2], c1);
																			  (yyval.rw_struct).start = tmp2;
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, ".> %s\n", (yyvsp[0].var_struct).name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			}
#line 2401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 651 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"var\"\n", errors[tmp]); }
#line 2407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 654 "mini_l.y" /* yacc.c:1646  */
    { (yyval.relexpr_struct).start = (yyvsp[0].relexpr_struct).start; (yyval.relexpr_struct).end = tmp2; }
#line 2413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 655 "mini_l.y" /* yacc.c:1646  */
    { char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "|| __temp__%d, %s, %s\n", temp, (yyvsp[-2].relexpr_struct).ret_name, (yyvsp[0].relexpr_struct).ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;

																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy((yyval.relexpr_struct).ret_name, c3);
																			  temp++;
																			  (yyval.relexpr_struct).start = (yyvsp[-2].relexpr_struct).start;
																			  (yyval.relexpr_struct).end = tmp2;
																			}
#line 2435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 674 "mini_l.y" /* yacc.c:1646  */
    { strcpy((yyval.relexpr_struct).type, (yyvsp[0].relexpr_struct).type); (yyval.relexpr_struct).start = (yyvsp[0].relexpr_struct).start; (yyval.relexpr_struct).end = tmp2; }
#line 2441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 675 "mini_l.y" /* yacc.c:1646  */
    { char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "&& __temp__%d, %s, %s\n", temp, (yyvsp[-2].relexpr_struct).ret_name, (yyvsp[0].relexpr_struct).ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;

																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy((yyval.relexpr_struct).ret_name, c3);
																			  temp++;
																			  (yyval.relexpr_struct).start = (yyvsp[-2].relexpr_struct).start;
																			  (yyval.relexpr_struct).end = tmp2;
																			}
#line 2463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 694 "mini_l.y" /* yacc.c:1646  */
    { char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;
																			  
																			  char c2[200];
																			  sprintf(c2, "! __temp__%d, %s\n", temp, (yyvsp[0].relexpr_struct).ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;

																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy((yyval.relexpr_struct).ret_name, c3);

																			  temp++;
																			  strcpy((yyval.relexpr_struct).type, (yyvsp[0].relexpr_struct).type);
																			  (yyval.relexpr_struct).start = (yyvsp[0].relexpr_struct).start;
																			  (yyval.relexpr_struct).end = tmp2;
																			}
#line 2487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 713 "mini_l.y" /* yacc.c:1646  */
    { strcpy((yyval.relexpr_struct).type, (yyvsp[0].relexpr_struct).type); (yyval.relexpr_struct).start = (yyvsp[0].relexpr_struct).start; (yyval.relexpr_struct).end = tmp2; }
#line 2493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 716 "mini_l.y" /* yacc.c:1646  */
    { char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "%s __temp__%d, %s, %s\n", (yyvsp[-1].comp_struct).name, temp, (yyvsp[-2].expr_struct).ret_name, (yyvsp[0].expr_struct).ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;

																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy((yyval.relexpr_struct).ret_name, c3);
																			  temp++;
																			  (yyval.relexpr_struct).start = (yyvsp[-2].expr_struct).start;
																			  (yyval.relexpr_struct).end = tmp2;
																			}
#line 2515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 733 "mini_l.y" /* yacc.c:1646  */
    { (yyval.relexpr_struct).start = tmp2;
																			  char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "= __temp__%d, %d\n", temp, 1);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			  
																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy((yyval.relexpr_struct).ret_name, c3);
																			  temp++;
																			}
#line 2536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 749 "mini_l.y" /* yacc.c:1646  */
    { (yyval.relexpr_struct).start = tmp2;
																			  char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "= __temp__%d, %d\n", temp, 0);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			  
																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy((yyval.relexpr_struct).ret_name, c3);
																			  temp++;
																			}
#line 2557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 765 "mini_l.y" /* yacc.c:1646  */
    { strcpy((yyval.relexpr_struct).ret_name, (yyvsp[-1].relexpr_struct).ret_name); strcpy((yyval.relexpr_struct).type, "nested"); (yyval.relexpr_struct).start = (yyvsp[-1].relexpr_struct).start; }
#line 2563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 766 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"comparison operator\"\n", errors[tmp]); }
#line 2569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 769 "mini_l.y" /* yacc.c:1646  */
    { (yyval.comp_struct).name = "=="; }
#line 2575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 770 "mini_l.y" /* yacc.c:1646  */
    { (yyval.comp_struct).name = "!="; }
#line 2581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 771 "mini_l.y" /* yacc.c:1646  */
    { (yyval.comp_struct).name = "<"; }
#line 2587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 772 "mini_l.y" /* yacc.c:1646  */
    { (yyval.comp_struct).name = ">"; }
#line 2593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 773 "mini_l.y" /* yacc.c:1646  */
    { (yyval.comp_struct).name = "<="; }
#line 2599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 774 "mini_l.y" /* yacc.c:1646  */
    { (yyval.comp_struct).name = ">="; }
#line 2605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 775 "mini_l.y" /* yacc.c:1646  */
    { tmp--; printf("Syntax error at line %d: expecting \"comparison operator\"\n", errors[tmp]); }
#line 2611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 778 "mini_l.y" /* yacc.c:1646  */
    { strcpy((yyval.expr_struct).ret_name, (yyvsp[0].expr_struct).ret_name); strcpy((yyval.expr_struct).type, (yyvsp[0].expr_struct).type); }
#line 2617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 779 "mini_l.y" /* yacc.c:1646  */
    { char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "+ __temp__%d, %s, %s\n", temp, (yyvsp[-2].expr_struct).ret_name, (yyvsp[0].expr_struct).ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			  
																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy((yyval.expr_struct).ret_name, c3);
																			  temp++;
																			  (yyval.expr_struct).start = (yyvsp[-2].expr_struct).start;
																			}
#line 2638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 795 "mini_l.y" /* yacc.c:1646  */
    { char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "- __temp__%d, %s, %s\n", temp, (yyvsp[-2].expr_struct).ret_name, (yyvsp[0].expr_struct).ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			  
																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy((yyval.expr_struct).ret_name, c3);
																			  temp++;
																			  (yyval.expr_struct).start = (yyvsp[-2].expr_struct).start;
																			}
#line 2659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 813 "mini_l.y" /* yacc.c:1646  */
    { strcpy((yyval.expr_struct).ret_name, (yyvsp[0].expr_struct).ret_name); strcpy((yyval.expr_struct).type, (yyvsp[0].expr_struct).type); }
#line 2665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 814 "mini_l.y" /* yacc.c:1646  */
    { char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "* __temp__%d, %s, %s\n", temp, (yyvsp[-2].expr_struct).ret_name, (yyvsp[0].expr_struct).ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			  
																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy((yyval.expr_struct).ret_name, c3);
																			  temp++;
																			  (yyval.expr_struct).start = (yyvsp[-2].expr_struct).start;
																			}
#line 2686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 830 "mini_l.y" /* yacc.c:1646  */
    { char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "/ __temp__%d, %s, %s\n", temp, (yyvsp[-2].expr_struct).ret_name, (yyvsp[0].expr_struct).ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			  
																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy((yyval.expr_struct).ret_name, c3);
																			  temp++;
																			  (yyval.expr_struct).start = (yyvsp[-2].expr_struct).start;
																			}
#line 2707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 846 "mini_l.y" /* yacc.c:1646  */
    { char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "\% __temp__%d, %s, %s\n", temp, (yyvsp[-2].expr_struct).ret_name, (yyvsp[0].expr_struct).ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			  
																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy((yyval.expr_struct).ret_name, c3);
																			  temp++;
																			  (yyval.expr_struct).start = (yyvsp[-2].expr_struct).start;
																			}
#line 2728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 864 "mini_l.y" /* yacc.c:1646  */
    { strcpy((yyval.expr_struct).ret_name, (yyvsp[0].expr_struct).ret_name); strcpy((yyval.expr_struct).type, (yyvsp[0].expr_struct).type); }
#line 2734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 865 "mini_l.y" /* yacc.c:1646  */
    { char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c4[200];
																			  sprintf(c4, ". __temp__%d\n", temp+1);
																			  strcpy(code[tmp2], c4);
																			  tmp2++;

																			  char c5[200];
																			  sprintf(c5, "= __temp__%d, %d\n", temp+1, 0);
																			  strcpy(code[tmp2], c5);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "- __temp__%d, __temp__%d, %s\n", temp, temp+1, (yyvsp[0].expr_struct).ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			  
																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy((yyval.expr_struct).ret_name, c3);
																			  temp+=2;
																			  (yyval.expr_struct).start = (yyvsp[0].expr_struct).start;
																			  strcpy((yyval.expr_struct).type, (yyvsp[0].expr_struct).type);
																			}
#line 2766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 892 "mini_l.y" /* yacc.c:1646  */
    { strcpy((yyval.expr_struct).ret_name, (yyvsp[0].expr_struct).ret_name); strcpy((yyval.expr_struct).type, (yyvsp[0].expr_struct).type); }
#line 2772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 895 "mini_l.y" /* yacc.c:1646  */
    { char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  (yyval.expr_struct).start = tmp2;
																			  tmp2++;
																			  
																			  if(strcmp((yyvsp[0].var_struct).type, "var") == 0) { 
																				char c2[200];
																				sprintf(c2, "= __temp__%d, %s\n", temp, (yyvsp[0].var_struct).name);
																				strcpy(code[tmp2], c2);
																				tmp2++;
																			  }
																			  else if(strcmp((yyvsp[0].var_struct).type, "array") == 0) { 
																				char c2[200];
																				sprintf(c2, "=[] __temp__%d, %s, %s\n", temp, (yyvsp[0].var_struct).name, (yyvsp[0].var_struct).ind_name);
																				strcpy(code[tmp2], c2);
																				tmp2++;
																			  }

																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy((yyval.expr_struct).ret_name, c3);
																			  strcpy((yyval.expr_struct).type, (yyvsp[0].var_struct).type);
																			  temp++;
																			}
#line 2802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 920 "mini_l.y" /* yacc.c:1646  */
    { char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "= __temp__%d, %s\n", temp, (yyvsp[0].expr_struct).name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;

																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy((yyval.expr_struct).ret_name, c3);
																			  (yyval.expr_struct).value = (yyvsp[0].expr_struct).value;
																			  temp++;
																			}
#line 2823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 936 "mini_l.y" /* yacc.c:1646  */
    { strcpy((yyval.expr_struct).ret_name, (yyvsp[-1].expr_struct).ret_name); }
#line 2829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 939 "mini_l.y" /* yacc.c:1646  */
    { strcpy(called[call], (yyvsp[-3].str));
																			  calls[call] = currLine;
																			  call++;
																			  char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "call %s, __temp__%d\n", (yyvsp[-3].str), temp);
																			  strcpy(code[tmp2], c2);

																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy((yyval.expr_struct).ret_name, c3);
																			  tmp2++;
																			  temp++;
																			}
#line 2852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 959 "mini_l.y" /* yacc.c:1646  */
    {  }
#line 2858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 960 "mini_l.y" /* yacc.c:1646  */
    { char c1[200];
																			  sprintf(c1, "param %s\n", (yyvsp[0].expr_struct).ret_name);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;
																			}
#line 2868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 965 "mini_l.y" /* yacc.c:1646  */
    {  }
#line 2874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 968 "mini_l.y" /* yacc.c:1646  */
    { strcpy((yyval.var_struct).type, "var");
																			  char found = 0;
																			  for(int i = 0; i < d1; i++) {
																					if(strcmp(declared[i], (yyvsp[0].str)) == 0) {
																						found = 1;
																					}
																			  }

																			  if(!found) {
																				  printf("Error line %d: used variable \"%s\" was not previously declared.\n", currLine, (yyvsp[0].str));
																				  error = 1;
																			  }

																			  for(int i = 0; i < arr; i++) {
																					if(strcmp(arrNames[i], (yyvsp[0].str)) == 0) {
																						printf("Error line %d: used array variable \"%s\" without specifying index.\n", currLine, (yyvsp[0].str));
																				  		error = 1;
																					}
																			  }
																			}
#line 2899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 988 "mini_l.y" /* yacc.c:1646  */
    { strcpy((yyval.var_struct).type, "array");
																			  strcpy((yyval.var_struct).ind_name, (yyvsp[-1].expr_struct).ret_name);
																			  char found = 0;
																			  for(int i = 0; i < d1; i++) {
																					if(strcmp(declared[i], (yyvsp[-3].str)) == 0) {
																						found = 1;
																					}
																			  }
																			  if(!found) {
																				  printf("Error line %d: used variable \"%s\" was not previously declared.\n", currLine, (yyvsp[-3].str));
																				  error = 1;
																			  }

																			  for(int i = 0; i < varInd; i++) {
																					if(strcmp(varNames[i], (yyvsp[-3].str)) == 0) {
																						printf("Error line %d: specified array index for symbol \"%s\" which is a non-array variable.\n", currLine, (yyvsp[-3].str));
																				  		error = 1;
																					}
																			  }
																			  
																			}
#line 2925 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2929 "y.tab.c" /* yacc.c:1646  */
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
#line 1010 "mini_l.y" /* yacc.c:1906  */


int main(int argc, char **argv) {
   if (argc > 1) {
      yyin = fopen(argv[1], "r");
      if (yyin == NULL){
         printf("syntax: %s filename\n", argv[0]);
      }//end if
   }//end if
   yyparse(); // Calls yylex() for tokens.
   fclose(yyin);
   if(!hasMain) {
	   printf("Error: no main function definition is given.\n");
	   return 0;
   }
   else if(error) return 0;

   for(int i = 0; i < 10000; i++) {
	   printf(code[i]);
   }
   printf("endfunc\n\n");
   return 0;
}

void yyerror(const char *msg) {
	// errLine = currLine;
	errors[tmp] = currLine;
	tmp++;
	printf("** Line %d, position %d: %s\n", currLine, currPos, msg);
}
