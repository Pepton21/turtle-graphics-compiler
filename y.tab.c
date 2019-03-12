
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.txt"

#include <stdio.h>
#include <string.h>
#include "parse_tree.h"
#include "psHeaderFooter.h"

using namespace std;

BaseNode* root;
int yylex();
bool has_syntax_error = false;
void yyerror(const char * s);


/* Line 189 of yacc.c  */
#line 88 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     INT_LITERAL = 259,
     REAL_LITERAL = 260,
     STRING_LITERAL = 261,
     BOOL_LITERAL = 262,
     INT = 263,
     REAL = 264,
     BOOL = 265,
     STRING = 266,
     FUNCTION = 267,
     SEMICOLUMN = 268,
     COMMA = 269,
     PLUS = 270,
     MINUS = 271,
     MULTIPLY = 272,
     DIVIDE = 273,
     MODULO = 274,
     EXCLAM = 275,
     COLON = 276,
     L_OP = 277,
     G_OP = 278,
     EQ_OP = 279,
     NE_OP = 280,
     LE_OP = 281,
     GE_OP = 282,
     AND_OP = 283,
     OR_OP = 284,
     INC_OP = 285,
     DEC_OP = 286,
     OPEN_CURLY_BRACKET = 287,
     CLOSED_CURLY_BRACKET = 288,
     OPEN_BRACKET = 289,
     CLOSED_BRACKET = 290,
     ASSIGN = 291,
     ADD_ASSIGN = 292,
     SUB_ASSIGN = 293,
     MUL_ASSIGN = 294,
     DIV_ASSIGN = 295,
     MOD_ASSIGN = 296,
     CONTINUE = 297,
     BREAK = 298,
     RETURN = 299,
     DO = 300,
     FOR = 301,
     WHILE = 302,
     ELSE = 303,
     IF = 304
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 17 "parser.txt"

  char str[100];
  double dbl;
  int no;
  BaseNode* ptr;



/* Line 214 of yacc.c  */
#line 182 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 207 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   208

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    21,    26,
      37,    45,    47,    48,    52,    54,    58,    60,    62,    64,
      66,    68,    71,    75,    78,    79,    82,    84,    90,    98,
     107,   115,   121,   125,   129,   132,   136,   139,   141,   143,
     145,   147,   149,   151,   153,   155,   157,   159,   161,   163,
     165,   167,   169,   173,   175,   179,   181,   184,   186,   190,
     194,   196,   198,   200,   202,   204,   206,   210,   212,   214,
     216,   220,   222,   224,   226,   228,   231,   233,   235,   237,
     239,   241,   245,   247,   249,   254,   256,   257,   261,   263,
     265,   267,   269
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    52,    -1,    52,    53,    -1,    53,    -1,
      54,    -1,    55,    -1,     3,    21,    70,    36,    71,    13,
      -1,     3,    21,    70,    13,    -1,    12,     3,    34,    56,
      35,    21,    70,    36,    59,    65,    -1,    12,     3,    34,
      56,    35,    36,    59,    -1,    57,    -1,    -1,    57,    14,
      58,    -1,    58,    -1,     3,    21,    70,    -1,    62,    -1,
      60,    -1,    63,    -1,    64,    -1,    54,    -1,    85,    13,
      -1,    32,    61,    33,    -1,    61,    59,    -1,    -1,    66,
      13,    -1,    13,    -1,    49,    34,    72,    35,    59,    -1,
      49,    34,    72,    35,    59,    48,    59,    -1,    46,    34,
      59,    72,    13,    67,    35,    59,    -1,    46,    34,    59,
      72,    13,    35,    59,    -1,    47,    34,    72,    35,    59,
      -1,    44,    67,    13,    -1,     3,    68,    67,    -1,     3,
      69,    -1,     3,    68,    66,    -1,     3,    69,    -1,    71,
      -1,    36,    -1,    37,    -1,    38,    -1,    39,    -1,    40,
      -1,    41,    -1,    30,    -1,    31,    -1,     8,    -1,     9,
      -1,    10,    -1,    11,    -1,    72,    -1,    77,    -1,    72,
      29,    73,    -1,    73,    -1,    73,    28,    74,    -1,    74,
      -1,    20,    74,    -1,    75,    -1,    77,    76,    77,    -1,
      83,    76,    83,    -1,    22,    -1,    23,    -1,    24,    -1,
      25,    -1,    26,    -1,    27,    -1,    77,    78,    79,    -1,
      79,    -1,    15,    -1,    16,    -1,    79,    80,    81,    -1,
      81,    -1,    17,    -1,    18,    -1,    19,    -1,    82,    83,
      -1,    83,    -1,    15,    -1,    16,    -1,     3,    -1,    84,
      -1,    34,    67,    35,    -1,    85,    -1,    88,    -1,     3,
      34,    86,    35,    -1,    87,    -1,    -1,    87,    14,    67,
      -1,    67,    -1,     4,    -1,     5,    -1,     6,    -1,     7,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    79,    79,    81,    82,    84,    85,    87,    89,    91,
      93,    96,    97,    99,   100,   102,   104,   105,   106,   107,
     108,   109,   111,   113,   114,   116,   117,   119,   121,   124,
     126,   128,   131,   133,   134,   136,   137,   138,   140,   141,
     142,   143,   144,   145,   147,   148,   150,   151,   152,   153,
     155,   156,   158,   159,   161,   162,   164,   165,   167,   168,
     170,   171,   172,   173,   174,   175,   177,   178,   180,   181,
     183,   184,   186,   187,   188,   190,   191,   193,   194,   196,
     197,   200,   201,   202,   204,   207,   208,   210,   211,   213,
     214,   215,   216
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INT_LITERAL",
  "REAL_LITERAL", "STRING_LITERAL", "BOOL_LITERAL", "INT", "REAL", "BOOL",
  "STRING", "FUNCTION", "SEMICOLUMN", "COMMA", "PLUS", "MINUS", "MULTIPLY",
  "DIVIDE", "MODULO", "EXCLAM", "COLON", "L_OP", "G_OP", "EQ_OP", "NE_OP",
  "LE_OP", "GE_OP", "AND_OP", "OR_OP", "INC_OP", "DEC_OP",
  "OPEN_CURLY_BRACKET", "CLOSED_CURLY_BRACKET", "OPEN_BRACKET",
  "CLOSED_BRACKET", "ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "CONTINUE", "BREAK", "RETURN", "DO", "FOR",
  "WHILE", "ELSE", "IF", "$accept", "program", "decl_list", "decl",
  "var_decl", "fun_decl", "params", "param_list", "param", "statement",
  "compound_stmt", "stmt_list", "expression_stmt", "selection_stmt",
  "iteration_stmt", "return_stmt", "assignment_expr", "expression",
  "assignment_op", "postfix_op", "type_spec", "simple_expr", "or_expr",
  "and_expr", "not_expr", "rel_expr", "rel_op", "sum_expr", "sum_op",
  "term", "mul_op", "unary_expr", "unary_op", "factor", "immutable",
  "call", "args", "arg_list", "constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    54,    54,    55,
      55,    56,    56,    57,    57,    58,    59,    59,    59,    59,
      59,    59,    60,    61,    61,    62,    62,    63,    63,    64,
      64,    64,    65,    66,    66,    67,    67,    67,    68,    68,
      68,    68,    68,    68,    69,    69,    70,    70,    70,    70,
      71,    71,    72,    72,    73,    73,    74,    74,    75,    75,
      76,    76,    76,    76,    76,    76,    77,    77,    78,    78,
      79,    79,    80,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    84,    85,    86,    86,    87,    87,    88,
      88,    88,    88
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     6,     4,    10,
       7,     1,     0,     3,     1,     3,     1,     1,     1,     1,
       1,     2,     3,     2,     0,     2,     1,     5,     7,     8,
       7,     5,     3,     3,     2,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     2,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     3,     1,     1,     4,     1,     0,     3,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     4,     5,     6,     0,     0,
       1,     3,    46,    47,    48,    49,     0,    12,     8,     0,
       0,     0,    11,    14,    79,    89,    90,    91,    92,    77,
      78,     0,     0,     0,    50,    53,    55,    57,    51,    67,
      71,     0,    76,    80,    82,    83,     0,     0,     0,    86,
      56,     0,    79,     0,    37,     7,     0,     0,    68,    69,
      60,    61,    62,    63,    64,    65,     0,     0,    72,    73,
      74,     0,    75,     0,    15,     0,     0,    13,    88,     0,
      85,    44,    45,    38,    39,    40,    41,    42,    43,     0,
      36,    81,    52,    54,    58,    76,    66,    70,    59,     0,
       0,    26,    24,     0,     0,     0,    20,    10,    17,    16,
      18,    19,     0,     0,    84,     0,     0,    35,     0,     0,
      34,     0,     0,     0,     0,    25,    21,    87,     0,    33,
      22,    23,     0,     0,     0,     0,     9,     0,     0,     0,
       0,     0,    31,    27,    32,     0,     0,     0,    30,     0,
      28,    29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,   106,     7,    21,    22,    23,   107,
     108,   121,   109,   110,   111,   136,   112,    53,   119,   120,
      16,    54,    34,    35,    36,    37,    66,    38,    67,    39,
      71,    40,    41,    42,    43,    44,    79,    80,    45
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -105
static const yytype_int16 yypact[] =
{
      24,   -14,    20,    53,    24,  -105,  -105,  -105,    30,    22,
    -105,  -105,  -105,  -105,  -105,  -105,    -3,    60,  -105,    99,
      55,    39,    51,  -105,    49,  -105,  -105,  -105,  -105,  -105,
    -105,    99,   119,    71,    56,    58,  -105,  -105,   151,    52,
    -105,     9,   181,  -105,  -105,  -105,    30,   -12,    60,   119,
    -105,   151,   149,    54,  -105,  -105,    99,    99,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,   125,   125,  -105,  -105,
    -105,   125,  -105,     9,  -105,    30,     5,  -105,  -105,    61,
      73,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,    94,
    -105,  -105,    58,  -105,    44,  -105,    52,  -105,  -105,    62,
     124,  -105,  -105,    65,    66,    74,  -105,  -105,  -105,  -105,
    -105,  -105,    98,   100,  -105,   119,   161,  -105,     5,   119,
    -105,    -2,     5,    99,    99,  -105,  -105,  -105,    63,  -105,
    -105,  -105,    99,    13,    26,   119,  -105,    -7,     5,     5,
     103,    75,  -105,    64,  -105,     5,    83,     5,  -105,     5,
    -105,  -105
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,  -105,  -105,   123,    17,  -105,  -105,  -105,    88,    -1,
    -105,  -105,  -105,  -105,  -105,  -105,    67,   -47,    90,    91,
     -41,   128,  -104,    93,   -28,  -105,   108,   -31,  -105,    84,
    -105,    81,  -105,    -9,  -105,   -72,  -105,  -105,  -105
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      51,   100,    78,    50,   113,    74,   141,     8,   100,    75,
      18,   101,    24,    25,    26,    27,    28,     6,   101,   133,
     134,     6,    56,     9,    76,    51,    51,     1,   137,    93,
     102,   130,    72,    19,    99,    94,     2,   102,    12,    13,
      14,    15,    56,    32,   103,   104,   113,   105,   138,   113,
     113,   103,   104,    10,   105,    56,    17,    95,    95,    58,
      59,   139,    95,    20,    98,    48,   113,   113,   127,    68,
      69,    70,   129,   113,    47,   113,    46,   113,    52,    25,
      26,    27,    28,    49,    55,    56,    57,   115,   140,    91,
      29,    30,    51,    51,   146,    31,   114,   116,   118,   122,
     123,    51,    24,    25,    26,    27,    28,   135,   124,    32,
     145,   125,   147,   126,    29,    30,   144,   128,   149,    31,
     131,   132,    52,    25,    26,    27,    28,    11,    24,    25,
      26,    27,    28,    32,    29,    30,    77,   142,   143,    31,
      29,    30,    89,    90,   148,     8,   150,    33,   151,    92,
      73,    96,    97,    32,    81,    82,   117,     0,    49,    32,
      83,    84,    85,    86,    87,    88,    58,    59,     0,     0,
       0,     0,     0,    60,    61,    62,    63,    64,    65,    81,
      82,     0,     0,    49,     0,    83,    84,    85,    86,    87,
      88,    81,    82,     0,     0,     0,     0,    83,    84,    85,
      86,    87,    88,    60,    61,    62,    63,    64,    65
};

static const yytype_int16 yycheck[] =
{
      31,     3,    49,    31,    76,    46,    13,    21,     3,    21,
      13,    13,     3,     4,     5,     6,     7,     0,    13,   123,
     124,     4,    29,     3,    36,    56,    57,     3,   132,    57,
      32,    33,    41,    36,    75,    66,    12,    32,     8,     9,
      10,    11,    29,    34,    46,    47,   118,    49,    35,   121,
     122,    46,    47,     0,    49,    29,    34,    66,    67,    15,
      16,    35,    71,     3,    73,    14,   138,   139,   115,    17,
      18,    19,   119,   145,    35,   147,    21,   149,     3,     4,
       5,     6,     7,    34,    13,    29,    28,    14,   135,    35,
      15,    16,   123,   124,   141,    20,    35,     3,    36,    34,
      34,   132,     3,     4,     5,     6,     7,    44,    34,    34,
      35,    13,    48,    13,    15,    16,    13,   118,    35,    20,
     121,   122,     3,     4,     5,     6,     7,     4,     3,     4,
       5,     6,     7,    34,    15,    16,    48,   138,   139,    20,
      15,    16,    52,    52,   145,    21,   147,    19,   149,    56,
      42,    67,    71,    34,    30,    31,    89,    -1,    34,    34,
      36,    37,    38,    39,    40,    41,    15,    16,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    30,
      31,    -1,    -1,    34,    -1,    36,    37,    38,    39,    40,
      41,    30,    31,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    22,    23,    24,    25,    26,    27
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    12,    51,    52,    53,    54,    55,    21,     3,
       0,    53,     8,     9,    10,    11,    70,    34,    13,    36,
       3,    56,    57,    58,     3,     4,     5,     6,     7,    15,
      16,    20,    34,    71,    72,    73,    74,    75,    77,    79,
      81,    82,    83,    84,    85,    88,    21,    35,    14,    34,
      74,    77,     3,    67,    71,    13,    29,    28,    15,    16,
      22,    23,    24,    25,    26,    27,    76,    78,    17,    18,
      19,    80,    83,    76,    70,    21,    36,    58,    67,    86,
      87,    30,    31,    36,    37,    38,    39,    40,    41,    68,
      69,    35,    73,    74,    77,    83,    79,    81,    83,    70,
       3,    13,    32,    46,    47,    49,    54,    59,    60,    62,
      63,    64,    66,    85,    35,    14,     3,    66,    36,    68,
      69,    61,    34,    34,    34,    13,    13,    67,    59,    67,
      33,    59,    59,    72,    72,    44,    65,    72,    35,    35,
      67,    13,    59,    59,    13,    35,    67,    48,    59,    35,
      59,    59
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 79 "parser.txt"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); root = (yyvsp[(1) - (1)].ptr);  ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 81 "parser.txt"
    { (yyval.ptr) -> addNode((yyvsp[(2) - (2)].ptr)); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 82 "parser.txt"
    { (yyval.ptr) = new ListNode(yylloc.first_line, "decl_list"); (yyval.ptr) -> addNode((yyvsp[(1) - (1)].ptr)); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 84 "parser.txt"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 85 "parser.txt"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 88 "parser.txt"
    { (yyval.ptr) = new TernaryNode(yylloc.first_line, "decl", new ValNode<string>("IDENTIFIER",(yyvsp[(1) - (6)].str), yylloc.first_line), (yyvsp[(3) - (6)].ptr), (yyvsp[(5) - (6)].ptr)); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 89 "parser.txt"
    { (yyval.ptr) = new BinaryNode(yylloc.first_line, "decl", new ValNode<string>("IDENTIFIER", (yyvsp[(1) - (4)].str), yylloc.first_line), (yyvsp[(3) - (4)].ptr)); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 92 "parser.txt"
    { (yyval.ptr) = new QuaternaryNode(yylloc.first_line, "fun_decl", new ValNode<string>("IDENTIFIER", (yyvsp[(2) - (10)].str), yylloc.first_line), (yyvsp[(4) - (10)].ptr), (yyvsp[(7) - (10)].ptr), (yyvsp[(9) - (10)].ptr)); (yyval.ptr) -> addNode((yyvsp[(10) - (10)].ptr));;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 94 "parser.txt"
    { (yyval.ptr) = new TernaryNode(yylloc.first_line, "fun_decl", new ValNode<string>("IDENTIFIER", (yyvsp[(2) - (7)].str), yylloc.first_line), (yyvsp[(4) - (7)].ptr), (yyvsp[(7) - (7)].ptr)); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 96 "parser.txt"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 97 "parser.txt"
    { (yyval.ptr) = new ListNode(yylloc.first_line, "param_list"); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 99 "parser.txt"
    { (yyval.ptr) -> addNode((yyvsp[(3) - (3)].ptr)); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 100 "parser.txt"
    { (yyval.ptr) = new ListNode(yylloc.first_line, "param_list"); (yyval.ptr) -> addNode((yyvsp[(1) - (1)].ptr)); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 102 "parser.txt"
    { (yyval.ptr) = new BinaryNode(yylloc.first_line, "param", new ValNode<string>("IDENTIFIER", (yyvsp[(1) - (3)].str), yylloc.first_line), (yyvsp[(3) - (3)].ptr)); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 104 "parser.txt"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 105 "parser.txt"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 106 "parser.txt"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 107 "parser.txt"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 108 "parser.txt"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 109 "parser.txt"
    { (yyval.ptr) = new UnaryNode(yylloc.first_line, "statement_call", (yyvsp[(1) - (2)].ptr)); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 111 "parser.txt"
    { (yyval.ptr) = (yyvsp[(2) - (3)].ptr); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 113 "parser.txt"
    { (yyval.ptr) -> addNode((yyvsp[(2) - (2)].ptr)); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 114 "parser.txt"
    { (yyval.ptr) = new ListNode(yylloc.first_line, "statement_list"); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 116 "parser.txt"
    { (yyval.ptr) = new UnaryNode(yylloc.first_line, "expression_stmt", (yyvsp[(1) - (2)].ptr)); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 117 "parser.txt"
    { (yyval.ptr) = new ListNode(yylloc.first_line, "expression_stmt"); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 120 "parser.txt"
    { (yyval.ptr) = new BinaryNode(yylloc.first_line, "if", (yyvsp[(3) - (5)].ptr), (yyvsp[(5) - (5)].ptr)); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 122 "parser.txt"
    { (yyval.ptr) = new TernaryNode(yylloc.first_line, "if_else", (yyvsp[(3) - (7)].ptr), (yyvsp[(5) - (7)].ptr), (yyvsp[(7) - (7)].ptr)); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 125 "parser.txt"
    { (yyval.ptr) = new QuaternaryNode(yylloc.first_line, "for", (yyvsp[(3) - (8)].ptr), (yyvsp[(4) - (8)].ptr), (yyvsp[(6) - (8)].ptr), (yyvsp[(8) - (8)].ptr)); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 127 "parser.txt"
    { (yyval.ptr) = new TernaryNode(yylloc.first_line, "for", (yyvsp[(3) - (7)].ptr), (yyvsp[(4) - (7)].ptr), (yyvsp[(7) - (7)].ptr)); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 129 "parser.txt"
    { (yyval.ptr) = new BinaryNode(yylloc.first_line, "while", (yyvsp[(3) - (5)].ptr), (yyvsp[(5) - (5)].ptr)); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 131 "parser.txt"
    { (yyval.ptr) = new UnaryNode(yylloc.first_line, "return_value", (yyvsp[(2) - (3)].ptr)); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 133 "parser.txt"
    { (yyval.ptr) = new TernaryNode(yylloc.first_line, "assignment_expr", new ValNode<string>("IDENTIFIER", (yyvsp[(1) - (3)].str), yylloc.first_line), (yyvsp[(2) - (3)].ptr), (yyvsp[(3) - (3)].ptr)); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 134 "parser.txt"
    { (yyval.ptr) = new BinaryNode(yylloc.first_line, "assignment_expr", new ValNode<string>("IDENTIFIER", (yyvsp[(1) - (2)].str), yylloc.first_line), (yyvsp[(2) - (2)].ptr)); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 136 "parser.txt"
    { (yyval.ptr) = new TernaryNode(yylloc.first_line, "assignment_expr", new ValNode<string>("IDENTIFIER", (yyvsp[(1) - (3)].str), yylloc.first_line), (yyvsp[(2) - (3)].ptr), (yyvsp[(3) - (3)].ptr)); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 137 "parser.txt"
    { (yyval.ptr) = new BinaryNode(yylloc.first_line, "assignment_expr", new ValNode<string>("IDENTIFIER", (yyvsp[(1) - (2)].str), yylloc.first_line), (yyvsp[(2) - (2)].ptr)); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 138 "parser.txt"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 140 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("assignment_op", "=", yylloc.first_line); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 141 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("assignment_op", "+=", yylloc.first_line); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 142 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("assignment_op", "-=", yylloc.first_line); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 143 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("assignment_op", "*=", yylloc.first_line); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 144 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("assignment_op", "/=", yylloc.first_line); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 145 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("assignment_op", "%=", yylloc.first_line); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 147 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("postfix_op", "++", yylloc.first_line); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 148 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("postfix_op", "--", yylloc.first_line); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 150 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("type", "int", yylloc.first_line); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 151 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("type", "double", yylloc.first_line); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 152 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("type", "bool", yylloc.first_line); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 153 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("type", "string", yylloc.first_line); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 155 "parser.txt"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 156 "parser.txt"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 158 "parser.txt"
    { (yyval.ptr) -> addNode((yyvsp[(3) - (3)].ptr)); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 159 "parser.txt"
    { (yyval.ptr) = new ListNode(yylloc.first_line, "or_expr"); (yyval.ptr) -> addNode((yyvsp[(1) - (1)].ptr)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 161 "parser.txt"
    { (yyval.ptr) -> addNode((yyvsp[(3) - (3)].ptr)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 162 "parser.txt"
    { (yyval.ptr) = new ListNode(yylloc.first_line, "and_expr"); (yyval.ptr) -> addNode((yyvsp[(1) - (1)].ptr)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 164 "parser.txt"
    { (yyval.ptr) = new UnaryNode(yylloc.first_line, "not", (yyvsp[(2) - (2)].ptr)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 165 "parser.txt"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 167 "parser.txt"
    { (yyval.ptr) = new TernaryNode(yylloc.first_line, "rel_expr", (yyvsp[(1) - (3)].ptr),(yyvsp[(2) - (3)].ptr),(yyvsp[(3) - (3)].ptr)); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 168 "parser.txt"
    { (yyval.ptr) = new TernaryNode(yylloc.first_line, "rel_expr", (yyvsp[(1) - (3)].ptr),(yyvsp[(2) - (3)].ptr),(yyvsp[(3) - (3)].ptr)); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 170 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("rel_op", "lt", yylloc.first_line); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 171 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("rel_op", "gt", yylloc.first_line); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 172 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("rel_op", "eq", yylloc.first_line); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 173 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("rel_op", "ne", yylloc.first_line); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 174 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("rel_op", "le", yylloc.first_line); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 175 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("rel_op", "ge", yylloc.first_line); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 177 "parser.txt"
    { (yyval.ptr) -> addNode(new BinaryNode(yylloc.first_line, "sum_with",(yyvsp[(2) - (3)].ptr), (yyvsp[(3) - (3)].ptr))); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 178 "parser.txt"
    { (yyval.ptr) = new ListNode(yylloc.first_line, "sum_expr"); (yyval.ptr) -> addNode((yyvsp[(1) - (1)].ptr)); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 180 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("sum_op", "add", yylloc.first_line); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 181 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("sum_op", "sub", yylloc.first_line); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 183 "parser.txt"
    { (yyval.ptr) -> addNode(new BinaryNode(yylloc.first_line, "mul_with", (yyvsp[(2) - (3)].ptr), (yyvsp[(3) - (3)].ptr))); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 184 "parser.txt"
    { (yyval.ptr) = new ListNode(yylloc.first_line, "term"); (yyval.ptr) -> addNode((yyvsp[(1) - (1)].ptr)); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 186 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("mul_op", "mul", yylloc.first_line); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 187 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("mul_op", "div", yylloc.first_line); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 188 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("mul_op", "mod", yylloc.first_line); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 190 "parser.txt"
    { (yyval.ptr) = new BinaryNode(yylloc.first_line, "unary_expr", (yyvsp[(1) - (2)].ptr), (yyvsp[(2) - (2)].ptr));  ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 191 "parser.txt"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 193 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("unary_op", "+", yylloc.first_line); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 194 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("unary_op", "-", yylloc.first_line); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 196 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("IDENTIFIER", (yyvsp[(1) - (1)].str), yylloc.first_line); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 197 "parser.txt"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 200 "parser.txt"
    { (yyval.ptr) = (yyvsp[(2) - (3)].ptr); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 201 "parser.txt"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 202 "parser.txt"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 205 "parser.txt"
    { (yyval.ptr) = new BinaryNode(yylloc.first_line,"call", new ValNode<string>("IDENTIFIER", (yyvsp[(1) - (4)].str), yylloc.first_line), (yyvsp[(3) - (4)].ptr)); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 207 "parser.txt"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 208 "parser.txt"
    { (yyval.ptr) = new ListNode(yylloc.first_line, "argument_list"); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 210 "parser.txt"
    { (yyval.ptr) -> addNode((yyvsp[(3) - (3)].ptr)); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 211 "parser.txt"
    { (yyval.ptr) = new ListNode(yylloc.first_line, "argument_list"); (yyval.ptr) -> addNode((yyvsp[(1) - (1)].ptr)); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 213 "parser.txt"
    { (yyval.ptr) = new ValNode<int>("int", (yyvsp[(1) - (1)].no), yylloc.first_line);;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 214 "parser.txt"
    { (yyval.ptr) = new ValNode<double>("double", (yyvsp[(1) - (1)].dbl), yylloc.first_line);;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 215 "parser.txt"
    { (yyval.ptr) = new ValNode<string>("string", (yyvsp[(1) - (1)].str), yylloc.first_line);;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 216 "parser.txt"
    { (yyval.ptr) = new ValNode<int>("bool", (yyvsp[(1) - (1)].no), yylloc.first_line); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2235 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 218 "parser.txt"


void yyerror(const char *s) {
  //fprintf(stdout, "error on line %d:%d: %s\n",yylloc.first_line, yylloc.first_column, s);
  has_syntax_error = true;
  fprintf(stderr, "error on line %d: %s\n", yylloc.last_line, s);
  //fprintf(stdout, "error: %s\n", s);
}

int yywrap() {
  return 1;
}

int main(int argc, char *argv[]) {
  
  if (argc != 2){
	cout << "Compiler expects 1 argument: source code file name!\n";
	cout << "Example: turtle source.turtle\n";
	return 1;
  }
  
  if(strlen(argv[1]) <=7 || strcmp(argv[1] + strlen(argv[1]) - 7, ".turtle")!=0){
	cout << "Invalid input file: File extension must be '.turtle'!\n";
	return 1;
  }
  
  char 	base[300] = "",
		tree[300] = "", 
		semantic[300] = "", 
		code[300] = "";
  strncpy(base, argv[1], strlen(argv[1]) - 7);
  strcat(strcat(tree, base), ".ast");
  strcat(strcat(semantic, base), ".pt");
  strcat(strcat(code, base), ".ps");
  
  freopen(argv[1],"r",stdin);
  
  yyparse();
  
  if (has_syntax_error)
	return 1;
  freopen(tree,"w",stdout);
  root->printNode(0);
  
  freopen(semantic,"w",stdout);
  root->initSemantic();
  string retSem = root->printSemantic(0, 0, "none", root);
  if(retSem=="error")
	return 1;
	
  freopen(code,"w",stdout);
  printHeader();
  root -> generateCode();
  printFooter();
  
  return 0;
}
