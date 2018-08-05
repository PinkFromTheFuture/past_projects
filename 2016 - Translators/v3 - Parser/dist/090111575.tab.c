/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#line 2 "090111575.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    /*define o tipo de informação que vamos passar pra ele:*/
    // #define YYSTYPE double
    /*geramos esta funcao com o flex, que eh padrao*/
    extern int yylex();
    extern int parse_multiple_line_comments();
    extern int parse_single_line_comments();
    extern int parse_string();
    extern int g_line_counter;

    typedef struct tree_node_struct {
        char description[255];
        char value[255];
        int node_brother_count;
        struct tree_node_struct *father, *node_brothers_list, *child;
    } NODE;

    // Estrutura usada para adicionar um novo no na arvore
    typedef struct description_and_value_data_for_the_tree {
        char description[255];
        char value[255];
    } description_and_value_data_for_the_tree;

    // Estrutura usada para adicionar novas linhas na Tabela de Símbolos:
    typedef struct data_for_the_symbol_table {
        char name[255];
        char type[255];
        char category[255];
    } data_for_the_symbol_table;

    // Tabela de Símbolos:
    typedef struct symbol_table_struct {
        char name[255];
        char value[255];
        // o escopo pode ser global (no caso de funções) ou o nome da função em que está (no caso de variáveis)
        char scope[255];
        char type[255];
        char category[255];
        struct symbol_table_struct *previous, *next;
    } symbol_table_struct;

    // protótipos de funções
    void printSymbolTable();
    void addSymbolTableLine(data_for_the_symbol_table*);
    void setCurrentScope(const char*);
    NODE* addTreeNode(description_and_value_data_for_the_tree*);
    void addNodeToListOfNodeBrothers(NODE*, NODE*);
    void addChildToTreeNode(NODE*, NODE*);
    void setValueInSymbolTableEntry(char *);
	void printSyntaxTree(NODE* root, int identation_counter);
	void setLastValueByIdentifierName(char *);
    void yyerror (char const *s); /* -> função de tratamento de erros do bison */

	// variáveis globais
    char g_current_scope[255];
    int g_symbol_table_size = 0;
    symbol_table_struct* g_symbol_table_current_line;
    symbol_table_struct *g_symbol_table_first_line;
    char g_last_value_from_st_entry [255];
    description_and_value_data_for_the_tree *g_desc_and_val;
    data_for_the_symbol_table *g_symbol_data;
    int g_syntax_error_flag = 0;

#line 134 "090111575.tab.c" /* yacc.c:339  */

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "090111575.tab.h".  */
#ifndef YY_YY_090111575_TAB_H_INCLUDED
# define YY_YY_090111575_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    OPERATOR = 258,
    Identifier = 259,
    IF = 260,
    ELSE = 261,
    WHILE = 262,
    INT = 263,
    NUMBER = 264,
    STRING = 265,
    TEXT = 266,
    VOID = 267,
    RETURN = 268,
    EqualTo = 269,
    LessThan = 270,
    GreaterThan = 271,
    LessThanOrEqualTo = 272,
    GreaterThanOrEqualTo = 273,
    NotEqualTo = 274,
    IFX = 275
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 70 "090111575.y" /* yacc.c:355  */

    int int_value;
    char str_value[255];
    char char_value;

    struct tree_node_struct *NODE;

#line 203 "090111575.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_090111575_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 218 "090111575.tab.c" /* yacc.c:358  */

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   129

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   275

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
      14,    15,    21,    23,    18,    24,    25,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    26,    19,
       2,    20,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    16,     2,    17,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    27,
      28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   148,   148,   162,   195,   229,   240,   247,   255,   270,
     290,   297,   305,   320,   328,   336,   345,   363,   381,   392,
     404,   420,   430,   440,   448,   456,   468,   480,   488,   496,
     508,   517,   527,   550,   572,   601,   611,   624,   632,   640,
     648,   657,   674,   684,   693,   703,   713,   723,   733,   743,
     754,   768,   782,   791,   805,   819,   828,   844,   856,   868,
     877,   889,   901,   914,   934,   963,   979,   995,  1013,  1031,
    1049
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OPERATOR", "Identifier", "IF", "ELSE",
  "WHILE", "INT", "NUMBER", "STRING", "TEXT", "VOID", "RETURN", "'('",
  "')'", "'{'", "'}'", "','", "';'", "'='", "'*'", "'/'", "'+'", "'-'",
  "'.'", "':'", "EqualTo", "LessThan", "GreaterThan", "LessThanOrEqualTo",
  "GreaterThanOrEqualTo", "NotEqualTo", "IFX", "$accept", "Begin",
  "Function", "FormalArgList", "FormalArg", "ArgList", "Arg",
  "Declaration", "Type", "CompoundStmt", "StmtList", "Stmt", "WhileStmt",
  "IfStmt", "ReturnStmt", "Expr", "Attribution", "Rvalue", "Compare",
  "Addition", "Multiplication", "Term", "Factor", "FunctionCall",
  "StringConcat", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    40,    41,   123,   125,    44,    59,
      61,    42,    47,    43,    45,    46,    58,   269,   270,   271,
     272,   273,   274,   275
};
# endif

#define YYPACT_NINF -58

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-58)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      36,    -4,   -58,   -58,    18,    43,    75,   -58,   -58,    77,
       8,    51,    43,    43,    56,   -58,    86,    76,     1,    43,
     -58,     1,    79,   -58,   -58,   -58,   -58,   -58,    59,    61,
     -10,    89,    96,   -58,    85,    16,    16,   -58,    38,    38,
      93,   109,   -58,   -58,   -58,   -58,    95,    97,   -58,    57,
      78,    83,   -58,   -58,   -58,    91,   -58,   -58,    10,    16,
     111,    34,    16,    16,    37,   -58,   103,   -58,   -58,   -58,
     -58,   -58,    99,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,    38,    38,    38,    22,    22,    39,    -2,    80,
     -58,   -58,   -58,    91,   -58,   106,   -58,   -58,   107,   108,
     -58,   -58,   -58,    78,    83,    83,   -58,   -58,   -58,   -58,
     -58,    10,    10,     1,     1,   -58,    82,   115,   -58,   -58,
       1,   -58
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    18,    19,     0,     2,     0,     5,     1,     0,
       0,     0,     6,     6,     0,     7,     0,     0,     0,     0,
       9,     0,     0,    23,     3,     8,     4,    21,     0,     0,
      60,     0,     0,    61,    62,    35,     0,    20,     0,     0,
       0,     0,    28,    22,    24,    27,     0,     0,    38,    37,
      43,    52,    55,    59,    39,    40,    31,    30,    10,     0,
       0,     0,     0,     0,     0,    36,     0,    60,    62,    58,
      57,    25,    16,    17,    29,    26,    44,    45,    46,    47,
      48,    49,     0,     0,     0,     0,     0,     0,    60,     0,
      11,    13,    14,    15,    41,     0,    70,    68,     0,     0,
      69,    67,    56,    42,    50,    51,    53,    54,    66,    65,
      63,     0,    10,     0,     0,    12,     0,    33,    32,    64,
       0,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,   -58,   112,   105,    14,    17,   -58,     6,   -21,
     -58,   -58,   -58,   -58,   -58,   -27,    88,   -58,   -58,    45,
      23,    70,   -57,   -55,   -53
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,    14,    15,    89,    90,    40,    16,    24,
      28,    43,    44,    45,    46,    47,    48,    49,    82,    50,
      51,    52,    53,    54,    55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      26,    91,    22,    92,    58,    93,     6,    42,    65,    66,
      59,     9,    58,     7,    88,    60,    61,    23,     8,    33,
      30,    34,    12,    60,    61,    33,    67,    34,   106,   107,
      36,    33,    94,    68,    41,    98,    99,     1,    96,    38,
      39,   100,    67,   108,     2,    97,     3,    33,   101,    68,
     109,     2,    36,     3,    91,    91,    92,    92,    93,    93,
      29,    38,    39,    30,    31,    13,    32,     2,    33,     3,
      34,    18,    35,    36,    19,    23,    37,    56,    27,    10,
      57,    11,    38,    39,    76,    77,    78,    79,    80,    81,
      20,    21,   117,   118,    19,   110,    27,   119,   111,   121,
     111,    83,    84,    62,    85,    86,   104,   105,    69,    70,
      63,    64,    71,    72,    74,    95,    75,    87,   102,    59,
     112,   120,   113,   114,    25,    17,   116,   103,   115,    73
};

static const yytype_uint8 yycheck[] =
{
      21,    58,     1,    58,    14,    58,     0,    28,    35,    36,
      20,     5,    14,    17,     4,    25,    26,    16,     0,     9,
       4,    11,    14,    25,    26,     9,     4,    11,    85,    86,
      14,     9,    59,    11,    28,    62,    63,     1,     4,    23,
      24,     4,     4,     4,     8,    11,    10,     9,    11,    11,
      11,     8,    14,    10,   111,   112,   111,   112,   111,   112,
       1,    23,    24,     4,     5,    14,     7,     8,     9,    10,
      11,    15,    13,    14,    18,    16,    17,    16,    17,     4,
      19,     4,    23,    24,    27,    28,    29,    30,    31,    32,
       4,    15,   113,   114,    18,    15,    17,    15,    18,   120,
      18,    23,    24,    14,    21,    22,    83,    84,    38,    39,
      14,    26,    19,     4,    19,     4,    19,    26,    15,    20,
      14,     6,    15,    15,    19,    13,   112,    82,   111,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     8,    10,    35,    36,    42,    17,     0,    42,
       4,     4,    14,    14,    37,    38,    42,    37,    15,    18,
       4,    15,     1,    16,    43,    38,    43,    17,    44,     1,
       4,     5,     7,     9,    11,    13,    14,    17,    23,    24,
      41,    42,    43,    45,    46,    47,    48,    49,    50,    51,
      53,    54,    55,    56,    57,    58,    16,    19,    14,    20,
      25,    26,    14,    14,    26,    49,    49,     4,    11,    55,
      55,    19,     4,    50,    19,    19,    27,    28,    29,    30,
      31,    32,    52,    23,    24,    21,    22,    26,     4,    39,
      40,    56,    57,    58,    49,     4,     4,    11,    49,    49,
       4,    11,    15,    53,    54,    54,    56,    56,     4,    11,
      15,    18,    14,    15,    15,    40,    39,    43,    43,    15,
       6,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    36,    36,    37,    37,    37,    38,
      39,    39,    39,    40,    40,    40,    41,    41,    42,    42,
      43,    43,    44,    44,    45,    45,    45,    45,    45,    45,
      45,    45,    46,    47,    47,    48,    48,    49,    49,    49,
      49,    50,    51,    51,    52,    52,    52,    52,    52,    52,
      53,    53,    53,    54,    54,    54,    55,    55,    55,    55,
      56,    56,    56,    57,    57,    58,    58,    58,    58,    58,
      58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     6,     7,     2,     0,     1,     3,     2,
       0,     1,     3,     1,     1,     1,     2,     2,     1,     1,
       3,     2,     2,     0,     1,     2,     2,     1,     1,     2,
       2,     2,     5,     5,     7,     1,     2,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     3,     3,     1,     3,     2,     2,     1,
       1,     1,     1,     4,     6,     3,     3,     3,     3,     3,
       3
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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
#line 149 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "CStr");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);
                    addChildToTreeNode((yyval.NODE), (yyvsp[0].NODE));
                    if (g_syntax_error_flag == 0)
                    {
                        printf("\nArvore sintatica:\n");
                        printSyntaxTree((yyval.NODE),0);
                        printSymbolTable();
                    }
                }
#line 1373 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 163 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Function");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[-5].NODE));

                    strcpy(g_desc_and_val->description, "Identifier");
                    strcpy(g_desc_and_val->value, (yyvsp[-4].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_desc_and_val->description, "(");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[-2].NODE));

                    strcpy(g_desc_and_val->description, ")");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));

                    setCurrentScope("GLOBAL");
                    strcpy(g_symbol_data->name, (yyvsp[-4].str_value));
                    strcpy(g_symbol_data->type, (yyvsp[-5].NODE)->child->description);
                    strcpy(g_symbol_data->category, "FUNCTION");
                    addSymbolTableLine(g_symbol_data);
                    // o escopo passa a ser o da função inserida:
                    setCurrentScope((yyvsp[-4].str_value));

                }
#line 1410 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 196 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Function");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[-6].NODE));

                    addChildToTreeNode((yyval.NODE),(yyvsp[-5].NODE));

                    strcpy(g_desc_and_val->description, "Identifier");
                    strcpy(g_desc_and_val->value, (yyvsp[-4].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_desc_and_val->description, "(");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[-2].NODE));

                    strcpy(g_desc_and_val->description, ")");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));

                    setCurrentScope("GLOBAL");
                    strcpy(g_symbol_data->name, (yyvsp[-4].str_value));
                    strcpy(g_symbol_data->type, (yyvsp[-5].NODE)->child->description);
                    strcpy(g_symbol_data->category, "FUNCTION");
                    addSymbolTableLine(g_symbol_data);
                    // o escopo passa a ser o da função inserida:
                    setCurrentScope((yyvsp[-4].str_value));
                }
#line 1448 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 230 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "SYNTAX ERROR");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),NULL);
                    g_syntax_error_flag = 1;
                }
#line 1461 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 240 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "FormalArgList");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),NULL);
                }
#line 1473 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 248 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "FormalArgList");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 1485 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 256 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "FormalArgList");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[-2].NODE));

                    strcpy(g_desc_and_val->description, ",");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 1503 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 271 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "FormalArg");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[-1].NODE));

                    strcpy(g_desc_and_val->description, "Identifier");
                    strcpy(g_desc_and_val->value, (yyvsp[0].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    setCurrentScope("-");
                    strcpy(g_symbol_data->name, (yyvsp[0].str_value));
                    strcpy(g_symbol_data->type, (yyvsp[-1].NODE)->child->description);
                    strcpy(g_symbol_data->category, "VARIABLE");
                    addSymbolTableLine(g_symbol_data);
                }
#line 1525 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 290 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "ArgList");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),NULL);
                }
#line 1537 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 298 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "ArgList");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 1549 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 306 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "ArgList");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[-2].NODE));

                    strcpy(g_desc_and_val->description, ",");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 1567 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 321 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Arg");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 1579 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 329 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Arg");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 1591 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 337 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Arg");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 1603 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 346 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Declaration");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[-1].NODE));

                    strcpy(g_desc_and_val->description, "Identifier");
                    strcpy(g_desc_and_val->value, (yyvsp[0].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    setCurrentScope("-");
                    strcpy(g_symbol_data->name, (yyvsp[0].str_value));
                    strcpy(g_symbol_data->type, (yyvsp[-1].NODE)->child->description);
                    strcpy(g_symbol_data->category, "VARIABLE");
                    addSymbolTableLine(g_symbol_data);
                }
#line 1625 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 364 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Declaration");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[-1].NODE));

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));

                    setCurrentScope("-");
                    strcpy(g_symbol_data->name, (yyvsp[0].NODE)->child->value);
                    strcpy(g_symbol_data->type, (yyvsp[-1].NODE)->child->description);
                    strcpy(g_symbol_data->category, "VARIABLE");
                    addSymbolTableLine(g_symbol_data);
                    setValueInSymbolTableEntry((yyvsp[0].NODE)->child->value);
                }
#line 1646 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 382 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Type");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "int");
                    strcpy(g_desc_and_val->value, "");

                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 1661 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 393 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Type");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "string");
                    strcpy(g_desc_and_val->value, "");

                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 1676 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 405 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "CompoundStmt");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "{");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[-1].NODE));

                    strcpy(g_desc_and_val->description, "}");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 1696 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 421 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "SYNTAX ERROR");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),NULL);
                    g_syntax_error_flag = 1;
                }
#line 1709 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 431 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "StmtList");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[-1].NODE));
                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 1722 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 440 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "StmtList");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),NULL);
                }
#line 1734 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 449 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Stmt");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 1746 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 457 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Stmt");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[-1].NODE));

                    strcpy(g_desc_and_val->description, ";");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 1762 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 469 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Stmt");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[-1].NODE));

                    strcpy(g_desc_and_val->description, ";");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 1778 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 481 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Stmt");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 1790 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 489 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Stmt");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 1802 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 497 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Stmt");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[-1].NODE));

                    strcpy(g_desc_and_val->description, ";");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 1818 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 509 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "SYNTAX ERROR");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),NULL);
                    g_syntax_error_flag = 1;
                }
#line 1831 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 518 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "SYNTAX ERROR");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),NULL);
                    g_syntax_error_flag = 1;
                }
#line 1844 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 528 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "WhileStmt");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "WHILE");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_desc_and_val->description, "(");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[-2].NODE));

                    strcpy(g_desc_and_val->description, ")");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 1870 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 551 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "IfStmt");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "IF");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_desc_and_val->description, "(");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[-2].NODE));

                    strcpy(g_desc_and_val->description, ")");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 1896 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 573 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "IfStmt");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "IF");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_desc_and_val->description, "(");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[-4].NODE));

                    strcpy(g_desc_and_val->description, ")");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[-2].NODE));

                    strcpy(g_desc_and_val->description, "ELSE");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 1928 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 602 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "ReturnStmt");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "RETURN");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 1942 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 612 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "ReturnStmt");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "RETURN");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 1958 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 625 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Expr");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 1970 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 633 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Expr");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 1982 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 641 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Expr");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 1994 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 649 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Expr");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 2006 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 658 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Attribution");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "Identifier");
                    strcpy(g_desc_and_val->value, (yyvsp[-2].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_desc_and_val->description, "=");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 2026 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 675 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Rvalue");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[-2].NODE));
                    addChildToTreeNode((yyval.NODE),(yyvsp[-1].NODE));
                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 2040 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 685 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Rvalue");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 2052 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 694 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Compare");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "==");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 2066 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 704 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Compare");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "<");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 2080 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 714 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Compare");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, ">");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 2094 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 724 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Compare");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "<=");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 2108 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 734 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Compare");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, ">=");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 2122 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 744 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Compare");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "!=");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 2136 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 755 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Addition");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[-2].NODE));

                    strcpy(g_desc_and_val->description, "+");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 2154 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 769 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Addition");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[-2].NODE));

                    strcpy(g_desc_and_val->description, "-");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 2172 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 783 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Addition");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 2184 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 792 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Multiplication");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[-2].NODE));

                    strcpy(g_desc_and_val->description, "*");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 2202 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 806 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Multiplication");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[-2].NODE));

                    strcpy(g_desc_and_val->description, "/");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 2220 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 820 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Multiplication");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 2232 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 829 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Term");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "(");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[-1].NODE));

                    strcpy(g_desc_and_val->description, ")");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 2252 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 845 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Term");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "-");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 2268 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 857 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Term");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "+");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 2284 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 869 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Term");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[0].NODE));
                }
#line 2296 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 878 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Factor");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "Identifier");
                    strcpy(g_desc_and_val->value, (yyvsp[0].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    setLastValueByIdentifierName((yyvsp[0].str_value));
                }
#line 2312 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 890 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Factor");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "NUMBER");
                    strcpy(g_desc_and_val->value, (yyvsp[0].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_last_value_from_st_entry, (yyvsp[0].str_value));
                }
#line 2328 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 902 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "Factor");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "TEXT");
                    strcpy(g_desc_and_val->value, (yyvsp[0].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_last_value_from_st_entry, (yyvsp[0].str_value));
                }
#line 2344 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 915 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "FunctionCall");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "Identifier");
                    strcpy(g_desc_and_val->value, (yyvsp[-3].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_desc_and_val->description, "(");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[-1].NODE));

                    strcpy(g_desc_and_val->description, ")");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 2368 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 935 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "FunctionCall");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "Identifier");
                    strcpy(g_desc_and_val->value, (yyvsp[-5].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_desc_and_val->description, ".");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_desc_and_val->description, "Identifier");
                    strcpy(g_desc_and_val->value, (yyvsp[-3].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_desc_and_val->description, "(");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    addChildToTreeNode((yyval.NODE),(yyvsp[-1].NODE));

                    strcpy(g_desc_and_val->description, ")");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 2400 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 964 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "StringConcat");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[-2].NODE));

                    strcpy(g_desc_and_val->description, ":");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_desc_and_val->description, "TEXT");
                    strcpy(g_desc_and_val->value, (yyvsp[0].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 2420 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 980 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "StringConcat");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    addChildToTreeNode((yyval.NODE),(yyvsp[-2].NODE));

                    strcpy(g_desc_and_val->description, ":");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_desc_and_val->description, "Identifier");
                    strcpy(g_desc_and_val->value, (yyvsp[0].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 2440 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 996 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "StringConcat");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "TEXT");
                    strcpy(g_desc_and_val->value, (yyvsp[-2].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_desc_and_val->description, ":");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_desc_and_val->description, "TEXT");
                    strcpy(g_desc_and_val->value, (yyvsp[0].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 2462 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1014 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "StringConcat");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "Identifier");
                    strcpy(g_desc_and_val->value, (yyvsp[-2].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_desc_and_val->description, ":");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_desc_and_val->description, "TEXT");
                    strcpy(g_desc_and_val->value, (yyvsp[0].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 2484 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1032 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "StringConcat");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "TEXT");
                    strcpy(g_desc_and_val->value, (yyvsp[-2].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_desc_and_val->description, ":");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_desc_and_val->description, "Identifier");
                    strcpy(g_desc_and_val->value, (yyvsp[0].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 2506 "090111575.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1050 "090111575.y" /* yacc.c:1646  */
    {
                    strcpy(g_desc_and_val->description, "StringConcat");
                    strcpy(g_desc_and_val->value, "");
                    (yyval.NODE) = addTreeNode(g_desc_and_val);

                    strcpy(g_desc_and_val->description, "Identifier");
                    strcpy(g_desc_and_val->value, (yyvsp[-2].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_desc_and_val->description, ":");
                    strcpy(g_desc_and_val->value, "");
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));

                    strcpy(g_desc_and_val->description, "Identifier");
                    strcpy(g_desc_and_val->value, (yyvsp[0].str_value));
                    addChildToTreeNode((yyval.NODE),addTreeNode(g_desc_and_val));
                }
#line 2528 "090111575.tab.c" /* yacc.c:1646  */
    break;


#line 2532 "090111575.tab.c" /* yacc.c:1646  */
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
#line 1067 "090111575.y" /* yacc.c:1906  */


void printSymbolTable()
{
    symbol_table_struct *aux = g_symbol_table_first_line;

    printf("\n\nTabela de simbolos:\n");

    if(0 < g_symbol_table_size)
    {
        while(aux != NULL)
        {
            printf("\nCATEGORY: %s\nTYPE: %s \nNAME: %s\nSCOPE: %s \nVALUE: %s\n", aux->category, aux->type, aux->name, aux->scope, aux->value);
            // printf("\nNAME: %s\nSCOPE: %s \nTYPE: %s \nCATEGORY: %s\n", aux->name,aux->scope,aux->type,aux->category);
            aux = aux->next;
        }
        printf("\n");
    }
}

void setLastValueByIdentifierName(char * var_name)
{
	symbol_table_struct *aux;
	aux = g_symbol_table_first_line;

	if(0 < g_symbol_table_size)
	{
        while(aux != NULL)
        {
            if(strcmp(aux->name,var_name) == 0)
            {
            	strcpy(g_last_value_from_st_entry , aux->value);
            }
            aux = aux->next;
        }
    }
}

void setValueInSymbolTableEntry(char * var_name)
{
    symbol_table_struct *aux;
    aux = g_symbol_table_first_line;

    if(0 < g_symbol_table_size)
    {
        while(aux != NULL)
        {
            if(strcmp(aux->name,var_name) == 0)
            {
                strcpy(aux->value , g_last_value_from_st_entry);
            }

            aux = aux->next;
        }
    }
}

//Cria uma nova linha na Tabela de Símbolos e aponta o elemento anterior e o que segue
void addSymbolTableLine(data_for_the_symbol_table * data)
{
    symbol_table_struct* line = (symbol_table_struct *) malloc (sizeof(symbol_table_struct));

    if(0 == g_symbol_table_size)
    {
        // preenche a entrada
        strcpy(line->scope,g_current_scope);
        strcpy(line->name ,data->name);
        strcpy(line->type,data->type);
        strcpy(line->category ,data->category);

        line->previous = NULL;
        line->next = NULL;

        // controle:
        g_symbol_table_size++;
        g_symbol_table_current_line = line;
        g_symbol_table_first_line = line;
    }
    else
    {
        strcpy(line->scope,g_current_scope);
        strcpy(line->name ,data->name);
        strcpy(line->type,data->type);
        strcpy(line->category ,data->category);

        line->previous = g_symbol_table_current_line;
        line->next = NULL;

        g_symbol_table_current_line->next = line;
        g_symbol_table_size++;
        g_symbol_table_current_line = line;
    }
}

void setCurrentScope(const char *scopeName)
{
    symbol_table_struct *aux;

    if(strcmp(scopeName,"") !=0)
        strcpy(g_current_scope,scopeName);

    aux = g_symbol_table_first_line;

    if(0 < g_symbol_table_size)
    {
        while(aux != NULL)
        {
            if( strcmp(aux->category,"VARIABLE") == 0 && strcmp(g_current_scope,"GLOBAL") != 0 && strcmp(aux->scope,"-") == 0 && strcmp(scopeName,"-") != 0 )
                strcpy(aux->scope,scopeName);
            aux = aux->next;
        }
    }
}

void addNodeToListOfNodeBrothers(NODE *root, NODE *item)
{
    int flag = 0;
    NODE *temp;

    if(item != NULL)
    {
        // se é o primeiro filho
        if (root->node_brothers_list == NULL)
        {
            root->node_brothers_list = item;
        }
        // se não é o primeiro filho
        else
        {
            //add a new child in a child list
            temp = root->node_brothers_list;

            while(0 == flag)
            {
                if(temp->node_brothers_list != NULL)
                    temp = temp->node_brothers_list;
                else
                    flag = 1;
            }

            //effect of the add
            temp->node_brothers_list = item;
        }
    }
}

// cria um novo nodo para ser preenchido depois. aloca memória pra ele, basicamente
NODE *addTreeNode(description_and_value_data_for_the_tree *g_desc_and_val)
{
    NODE *node;

    node = (NODE *) malloc (sizeof(NODE));

    strcpy(node->description , g_desc_and_val->description);
    strcpy(node->value , g_desc_and_val->value);

    node->node_brother_count = 0;
    node->father = NULL;
    node->child = NULL;
    node->node_brothers_list = NULL;

    return node;
}

void addChildToTreeNode(NODE *root, NODE *item)
{
    int flag = 0;
    NODE *temp;

    if(item != NULL)
    {
        // se é o primeiro filho
        if (root->child == NULL)
        {
            item->father = root;
            root->child = item;
        }
        // se não é o primeiro filho
        else
        {
            addNodeToListOfNodeBrothers(root->child, item);
        }

        root->node_brother_count++;
        temp = item;

        // atualiza quem é o nodo pai deste
        while(flag == 0)
        {
            if(temp != NULL)
            {
                temp = temp->node_brothers_list;

                if(temp != NULL)
                {
                    temp->father = root;
                }
            }
            else
            {
                flag = 1;
            }
        }
    }
}

void printSyntaxTree(NODE* root, int identation_counter)
{
    NODE* aux = NULL;
    int i=0;

    if (root != NULL)
    {
        for(i = 0; i < identation_counter; i++) { printf("|   "); }

        printf("%s %s\n", root->description, root->value);

        aux = root->child;

        // chamada recursiva para imprimir os filhos.
        while (aux != NULL)
        {
            printSyntaxTree(aux, identation_counter + 1);
            aux = aux->node_brothers_list;
        }
    }
}

/* Epílogo ( código no final do arquivo ) */
/* Chamado quando há um erro sintático na entrada . */
void yyerror ( char const *s)
{
    printf ("Line %d: %s\n", g_line_counter, s);
}

int main ( void )
{
    g_desc_and_val = (description_and_value_data_for_the_tree*) malloc(sizeof(description_and_value_data_for_the_tree));
    g_symbol_data = (data_for_the_symbol_table*) malloc(sizeof(data_for_the_symbol_table));

    /* Chama o parser . */
    return yyparse ();
}
