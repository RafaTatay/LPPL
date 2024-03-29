/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 4 "src/asin.y"

#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"
#include "libgci.h"
#include "asin.h"

extern int yylineno;

#line 81 "asin.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_ASIN_H_INCLUDED
# define YY_YY_ASIN_H_INCLUDED
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
    MAS_ = 258,
    MENOS_ = 259,
    POR_ = 260,
    DIV_ = 261,
    AND_ = 262,
    OR_ = 263,
    ASIGNAR_ = 264,
    NOT_ = 265,
    IGUAL_ = 266,
    NOTIGUAL_ = 267,
    MAYOR_ = 268,
    MENOR_ = 269,
    MAYORIG_ = 270,
    MENORIG_ = 271,
    LLAVE1_ = 272,
    LLAVE2_ = 273,
    PARENTESIS1_ = 274,
    PARENTESIS2_ = 275,
    CORCHETE1_ = 276,
    CORCHETE2_ = 277,
    PUNTOCOMA_ = 278,
    COMA_ = 279,
    FOR_ = 280,
    IF_ = 281,
    ELSE_ = 282,
    INT_ = 283,
    BOOL_ = 284,
    READ_ = 285,
    PRINT_ = 286,
    RETURN_ = 287,
    TRUE_ = 288,
    FALSE_ = 289,
    CTE_ = 290,
    ID_ = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "src/asin.y"

  int   cent;  /* Para el terminal "cte" entera: creo un atr que es un entero             */
  char *ident; /* Nombre del identificador */
  Lista lista;
  Expresion expresion; /*Para guardar tipo y posicion de simbolos no terminales*/
  Ifelse ifelse; /*Para el ifelse ahcerlo igual que en las transparencias*/
  Forexpre forexpre; /*Para hace rel for igual que en las transparencias*/

#line 179 "asin.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASIN_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   153

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

#define YYUNDEFTOK  2
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    48,    48,    48,    75,    76,    84,    85,    88,    95,
     108,   122,   129,   130,   133,   134,   138,   145,   137,   173,
     174,   178,   187,   196,   211,   196,   237,   238,   242,   243,
     246,   247,   248,   249,   250,   253,   254,   257,   264,   275,
     283,   274,   295,   300,   308,   294,   329,   330,   333,   334,
     348,   373,   374,   393,   394,   409,   410,   425,   426,   439,
     440,   453,   454,   488,   495,   499,   508,   531,   530,   558,
     559,   562,   568,   567,   575,   576,   579,   580,   583,   584,
     585,   586,   589,   590,   593,   594,   597,   598,   599
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAS_", "MENOS_", "POR_", "DIV_", "AND_",
  "OR_", "ASIGNAR_", "NOT_", "IGUAL_", "NOTIGUAL_", "MAYOR_", "MENOR_",
  "MAYORIG_", "MENORIG_", "LLAVE1_", "LLAVE2_", "PARENTESIS1_",
  "PARENTESIS2_", "CORCHETE1_", "CORCHETE2_", "PUNTOCOMA_", "COMA_",
  "FOR_", "IF_", "ELSE_", "INT_", "BOOL_", "READ_", "PRINT_", "RETURN_",
  "TRUE_", "FALSE_", "CTE_", "ID_", "$accept", "programa", "@1",
  "listDecla", "decla", "declaVar", "const", "tipoSimp", "declaFunc", "@2",
  "@3", "paramForm", "listParamForm", "bloque", "@4", "$@5",
  "declaVarLocal", "listInst", "inst", "instExpre", "instEntSal",
  "instSelec", "@6", "@7", "instIter", "@8", "@9", "$@10", "expreOp",
  "expre", "expreLogic", "expreIgual", "expreRel", "expreAd", "expreMul",
  "expreUna", "expreSufi", "$@11", "paramAct", "listParamAct", "$@12",
  "opLogic", "opIgual", "opRel", "opAd", "opMul", "opUna", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF (-127)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-73)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
    -127,     2,   -13,  -127,  -127,  -127,   -13,  -127,  -127,   -31,
    -127,  -127,     1,   -26,   -24,  -127,     0,  -127,  -127,  -127,
      11,    35,   -13,  -127,    36,    26,     3,  -127,  -127,    44,
    -127,   -13,  -127,  -127,  -127,    47,  -127,   -13,  -127,    34,
      10,     1,  -127,  -127,  -127,  -127,    91,  -127,    53,    58,
      69,    78,    91,    28,  -127,  -127,  -127,  -127,  -127,  -127,
      68,    31,    49,    40,    72,    84,  -127,  -127,   101,    48,
      79,    91,    91,    62,    91,  -127,    91,    91,    88,  -127,
    -127,  -127,   101,  -127,  -127,   101,  -127,  -127,  -127,  -127,
     101,  -127,  -127,   101,  -127,  -127,   101,    29,  -127,  -127,
    -127,    80,  -127,    92,    95,   102,    98,  -127,   106,    91,
      49,    40,    72,    84,  -127,    91,  -127,  -127,   100,   107,
     111,   122,   108,   113,  -127,   116,    91,    83,  -127,  -127,
    -127,    91,   115,  -127,  -127,   117,  -127,  -127,    91,  -127,
     114,  -127,    91,    83,   123,  -127,  -127,    83,  -127
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    14,    15,     3,     4,     6,     0,
       7,     5,    16,     0,     0,     8,     0,    12,    13,    11,
       0,     0,    19,     9,     0,     0,     0,    20,    10,    21,
      17,     0,    23,    22,    18,     0,    26,    28,    27,     0,
       0,     0,    86,    87,    88,    28,     0,    36,     0,     0,
       0,     0,     0,    65,    63,    29,    31,    32,    33,    34,
       0,    48,    51,    53,    55,    57,    59,    61,     0,     0,
       0,    46,     0,     0,     0,    24,     0,     0,     0,    35,
      74,    75,     0,    76,    77,     0,    78,    79,    80,    81,
       0,    82,    83,     0,    84,    85,     0,    65,    62,    30,
      64,     0,    47,     0,     0,     0,     0,    49,     0,    69,
      52,    54,    56,    58,    60,     0,    42,    39,     0,     0,
       0,    66,    71,     0,    70,     0,     0,     0,    37,    38,
      25,     0,     0,    68,    66,     0,    40,    50,     0,    43,
       0,    73,    46,     0,     0,    41,    44,     0,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,  -127,   136,   109,   131,   -19,  -127,  -127,
    -127,  -127,   118,  -127,  -127,  -127,  -127,   103,  -126,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,     5,   -46,
    -127,    63,    65,    61,    59,   -64,  -127,  -127,  -127,    15,
    -127,  -127,  -127,  -127,  -127,  -127,  -127
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,    54,     9,    10,    16,
      32,    26,    27,    34,    35,   106,    37,    40,    55,    56,
      57,    58,   127,   140,    59,   126,   142,   147,   101,    60,
      61,    62,    63,    64,    65,    66,    67,    78,   123,   124,
     132,    82,    85,    90,    93,    96,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,   136,     3,    25,    98,    12,    75,    17,    18,    19,
      13,    21,    25,    42,    43,     4,     5,   145,    39,    22,
      44,   148,    14,    30,    15,   102,   103,    45,   105,    46,
     107,   108,   114,    47,    23,    48,    49,    76,    80,    81,
      50,    51,    52,    17,    18,    19,    53,   -67,   -67,    77,
     115,    42,    43,    86,    87,    88,    89,    24,    44,    28,
      83,    84,    29,   122,    36,    45,    99,    46,    31,   125,
      41,    47,    71,    48,    49,    91,    92,    72,    50,    51,
     135,    17,    18,    19,    53,   137,    42,    43,    73,    94,
      95,    79,   122,    44,    42,    43,   102,    74,   104,   100,
      45,    44,    46,   116,    42,    43,    47,   109,    48,    49,
      46,    44,   117,    50,    51,   118,    17,    18,    19,    53,
      46,   120,   119,   128,    17,    18,    19,    53,   121,   130,
     129,   131,   -72,   133,    17,    18,    19,    97,   134,   138,
     139,   143,    11,   146,    20,   110,    38,   144,    69,    33,
     111,   112,   113,   141
};

static const yytype_uint8 yycheck[] =
{
      46,   127,     0,    22,    68,    36,    52,    33,    34,    35,
       9,    35,    31,     3,     4,    28,    29,   143,    37,    19,
      10,   147,    21,    20,    23,    71,    72,    17,    74,    19,
      76,    77,    96,    23,    23,    25,    26,     9,     7,     8,
      30,    31,    32,    33,    34,    35,    36,    19,    19,    21,
      21,     3,     4,    13,    14,    15,    16,    22,    10,    23,
      11,    12,    36,   109,    17,    17,    18,    19,    24,   115,
      36,    23,    19,    25,    26,     3,     4,    19,    30,    31,
     126,    33,    34,    35,    36,   131,     3,     4,    19,     5,
       6,    23,   138,    10,     3,     4,   142,    19,    36,    20,
      17,    10,    19,    23,     3,     4,    23,    19,    25,    26,
      19,    10,    20,    30,    31,    20,    33,    34,    35,    36,
      19,    23,    20,    23,    33,    34,    35,    36,    22,    18,
      23,     9,    24,    20,    33,    34,    35,    36,    22,    24,
      23,    27,     6,    20,    13,    82,    37,   142,    45,    31,
      85,    90,    93,   138
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,    28,    29,    40,    41,    42,    44,
      45,    41,    36,     9,    21,    23,    46,    33,    34,    35,
      43,    35,    19,    23,    22,    44,    48,    49,    23,    36,
      20,    24,    47,    49,    50,    51,    17,    53,    42,    44,
      54,    36,     3,     4,    10,    17,    19,    23,    25,    26,
      30,    31,    32,    36,    43,    55,    56,    57,    58,    61,
      66,    67,    68,    69,    70,    71,    72,    73,    83,    54,
      66,    19,    19,    19,    19,    66,     9,    21,    74,    23,
       7,     8,    78,    11,    12,    79,    13,    14,    15,    16,
      80,     3,     4,    81,     5,     6,    82,    36,    72,    18,
      20,    65,    66,    66,    36,    66,    52,    66,    66,    19,
      68,    69,    70,    71,    72,    21,    23,    20,    20,    20,
      23,    22,    66,    75,    76,    66,    62,    59,    23,    23,
      18,     9,    77,    20,    22,    66,    55,    66,    24,    23,
      60,    76,    63,    27,    65,    55,    20,    64,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    39,    38,    40,    40,    41,    41,    42,    42,
      42,    43,    43,    43,    44,    44,    46,    47,    45,    48,
      48,    49,    49,    51,    52,    50,    53,    53,    54,    54,
      55,    55,    55,    55,    55,    56,    56,    57,    57,    59,
      60,    58,    62,    63,    64,    61,    65,    65,    66,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    73,    73,    73,    73,    74,    73,    75,
      75,    76,    77,    76,    78,    78,    79,    79,    80,    80,
      80,    80,    81,    81,    82,    82,    83,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     3,     5,
       6,     1,     1,     1,     1,     1,     0,     0,     8,     0,
       1,     2,     4,     0,     0,     9,     0,     2,     0,     2,
       3,     1,     1,     1,     1,     2,     1,     5,     5,     0,
       0,     9,     0,     0,     0,    12,     0,     1,     1,     3,
       6,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     2,     1,     3,     1,     4,     0,     5,     0,
       1,     1,     0,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 48 "src/asin.y"
                    {       
                            niv = 0;   /* Nivel de anidamiento "global" o "local" */
                            dvar = 0;  /* Desplazamiento en el Segmento de Variables */
                            cargaContexto(niv);
                            si = 0; /* Se refiere a la Siguiente Instrucción*/
		             

                            (yyval.lista).ref=creaLans(si);   //var globales
                            emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(-1));

                            (yyval.lista).talla=creaLans(si);
                            emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));
		       }
#line 1475 "asin.c"
    break;

  case 3:
#line 62 "src/asin.y"
                    {
		              if(verTdS)
		                     mostrarTdS(); 
                            if((yyvsp[0].lista).ref == 0)
		                     yyerror("No hay main en el programa");
                            else if ((yyvsp[0].lista).ref > 1)
                                   yyerror("El programa tiene más de un main");
                            completaLans((yyvsp[-1].lista).ref, crArgEnt(dvar));
                            completaLans((yyvsp[-1].lista).talla, crArgEtq((yyvsp[0].lista).talla));
                              
		       }
#line 1491 "asin.c"
    break;

  case 4:
#line 75 "src/asin.y"
                          { (yyval.lista).ref =(yyvsp[0].lista).ref; (yyval.lista).talla=(yyvsp[0].lista).talla;}
#line 1497 "asin.c"
    break;

  case 5:
#line 77 "src/asin.y"
                     {
		              (yyval.lista).ref = (yyvsp[-1].lista).ref + (yyvsp[0].lista).ref;    
                            if((yyvsp[-1].lista).talla!=-1) (yyval.lista).talla=(yyvsp[-1].lista).talla;
                            else { (yyval.lista).talla=(yyvsp[0].lista).talla; } 
		       }
#line 1507 "asin.c"
    break;

  case 6:
#line 84 "src/asin.y"
                              { (yyval.lista).ref = 0; (yyval.lista).talla = -1; }
#line 1513 "asin.c"
    break;

  case 7:
#line 85 "src/asin.y"
                               {(yyval.lista).ref = (yyvsp[0].lista).ref; (yyval.lista).talla = (yyvsp[0].lista).talla;}
#line 1519 "asin.c"
    break;

  case 8:
#line 89 "src/asin.y"
                      {
		              if(!insTdS((yyvsp[-1].ident),VARIABLE,(yyvsp[-2].cent),niv,dvar,-1))
		                     yyerror("Identificador de variable repetido");
		              else
		                     dvar += TALLA_TIPO_SIMPLE;
		       }
#line 1530 "asin.c"
    break;

  case 9:
#line 96 "src/asin.y"
                     {
		              if(!insTdS((yyvsp[-3].ident), VARIABLE, (yyvsp[-4].cent), niv, dvar, -1))
		                     yyerror("Ya existe una variable con el mismo identificador.");
                            else if (! (((((yyvsp[-4].cent) == T_ENTERO) && ((yyvsp[-1].expresion).tipo == T_ENTERO))) || (((yyvsp[-4].cent) == T_LOGICO) && ((yyvsp[-1].expresion).tipo == T_LOGICO))))
                                   yyerror("Error de tipos en la inicialización de variables");
		              else
		                     dvar += TALLA_TIPO_SIMPLE;
                            /*No tengo la posicion de ID:Voy a la TdS y usando sim obtengo su posicion*/ 
                            SIMB sim = obtTdS((yyvsp[-3].ident)); /* Esto accede a la TdS y obtiene la info de $3 que es ID_ */
                            emite(EASIG,crArgEnt((yyvsp[-1].expresion).pos) , crArgNul(),crArgPos(sim.n,sim.d));
                            /*NOTA: Cuando use sim.d para cargar el nivel usa sim.n */
		       }
#line 1547 "asin.c"
    break;

  case 10:
#line 109 "src/asin.y"
                     {    
                            int numelem = (yyvsp[-2].cent);
                            if ((yyvsp[-2].cent) <= 0) {
                                   yyerror("Talla inapropiada del array");
                                   numelem = 0;
                            }        
                            int refe = insTdA((yyvsp[-5].cent), numelem);
                            if ( ! insTdS((yyvsp[-4].ident), VARIABLE, T_ARRAY, niv, dvar, refe) )
                                   yyerror ("Identificador del array repetido");
                            else dvar += numelem * TALLA_TIPO_SIMPLE;
                     }
#line 1563 "asin.c"
    break;

  case 11:
#line 125 "src/asin.y"
                     {
                      (yyval.expresion).tipo = T_ENTERO; /*Antes era solo $$ = T_ENTERO-> añadimos expresion a header.h y modificamos type de cent en union*/
                      (yyval.expresion).pos = (yyvsp[0].cent);
                     }
#line 1572 "asin.c"
    break;

  case 12:
#line 129 "src/asin.y"
                           {(yyval.expresion).tipo = T_LOGICO; (yyval.expresion).pos = TRUE;}
#line 1578 "asin.c"
    break;

  case 13:
#line 130 "src/asin.y"
                            {(yyval.expresion).tipo = T_LOGICO; (yyval.expresion).pos = FALSE;}
#line 1584 "asin.c"
    break;

  case 14:
#line 133 "src/asin.y"
                          {(yyval.cent) = T_ENTERO;}
#line 1590 "asin.c"
    break;

  case 15:
#line 134 "src/asin.y"
                           {(yyval.cent) = T_LOGICO;}
#line 1596 "asin.c"
    break;

  case 16:
#line 138 "src/asin.y"
                     { /* Gestion del contexto y guardar ‘‘dvar’’ */ 
                            niv++;
                            cargaContexto(niv);
                            (yyval.cent) = dvar;
                            dvar = 0;
                     }
#line 1607 "asin.c"
    break;

  case 17:
#line 145 "src/asin.y"
                     { /* Insertar informacion de la funcion en la TdS */ 

                            if(!insTdS((yyvsp[-4].ident), FUNCION, (yyvsp[-5].cent), niv-1, si, (yyvsp[-1].lista).ref)) 
                            /* Al poner si, nos guardamos la linea de codigo en 
                                                 la que empieza la función - Se usa en los CALL*/
		                     yyerror("Ya existe una funcion con el mismo identificador.");

                            if (strcmp((yyvsp[-4].ident),"main\0")==0){ (yyval.cent)=si; } 
                            else{(yyval.cent)=-1;}
                            
                             
                     }
#line 1624 "asin.c"
    break;

  case 18:
#line 158 "src/asin.y"
                     {/* Mostrar la informacion de la funcion en la TdS */
                            if(strcmp((yyvsp[-6].ident), "main\0") == 0){   /* los dominios coinciden */
                                   (yyval.lista).ref = 1;
                            }
                            else { (yyval.lista).ref = 0;} 
                            if(verTdS)
		                     mostrarTdS();
                      /* Gestion del contexto y recuperar ‘‘dvar’’ */
                            descargaContexto(niv); 
			       niv--; 
			       dvar = (yyvsp[-5].cent);
                            (yyval.lista).talla=(yyvsp[-1].cent);
			}
#line 1642 "asin.c"
    break;

  case 19:
#line 173 "src/asin.y"
                     {(yyval.lista).ref = insTdD(-1, T_VACIO);    (yyval.lista).talla = 0;}
#line 1648 "asin.c"
    break;

  case 20:
#line 175 "src/asin.y"
                     {(yyval.lista).ref = (yyvsp[0].lista).ref;    (yyval.lista).talla = (yyvsp[0].lista).talla;}
#line 1654 "asin.c"
    break;

  case 21:
#line 179 "src/asin.y"
                     {
                            (yyval.lista).ref = insTdD(-1, (yyvsp[-1].cent));   
                            (yyval.lista).talla = TALLA_SEGENLACES + TALLA_TIPO_SIMPLE; /* El más a la derecha del todo */
                            if ( ! insTdS((yyvsp[0].ident), PARAMETRO, (yyvsp[-1].cent), niv, -(yyval.lista).talla, -1) )     /* Los parametros se ordenan en orden inverso */
                                   yyerror ("La función ya tiene un parámetro con el mismo identificador");
                            
		              
                     }
#line 1667 "asin.c"
    break;

  case 22:
#line 188 "src/asin.y"
                     {
                            (yyval.lista).ref = insTdD((yyvsp[0].lista).ref, (yyvsp[-3].cent));   
                            (yyval.lista).talla = TALLA_TIPO_SIMPLE + (yyvsp[0].lista).talla;
                            if ( ! insTdS((yyvsp[-2].ident), PARAMETRO, (yyvsp[-3].cent), niv, -(yyval.lista).talla, -1) )
                                   yyerror ("La función ya tiene un parámetro con el mismo identificador");
                     }
#line 1678 "asin.c"
    break;

  case 23:
#line 196 "src/asin.y"
                     {
                     /*********** Cargar los enlaces de control */
                     emite(PUSHFP, crArgNul(),crArgNul(),crArgNul());
                     emite(FPTOP, crArgNul(),crArgNul(),crArgNul());
                     
                     /*********** Reservar de espacio para variables locales y temporales */
                     /*Para hacer los que en las transpas ahcen con D.d = creaLans(Omega) hacemos*/
                     (yyval.cent) = creaLans(si); /* D.d = CreaLans(Omega)*/

                     /*-1 correpsonde a el circulo con x que usabamos en teoria*/
                     emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(-1)); 
                     
                     }
#line 1696 "asin.c"
    break;

  case 24:
#line 211 "src/asin.y"
                     {
                            INF inf = obtTdD(-1);
			       if (inf.tipo != T_ERROR) {
				       if (inf.tipo != (yyvsp[0].expresion).tipo) {
					       yyerror("Error de tipos en el return"); 
				       }                                       
			       }
                            else if( inf.tipo == T_ERROR){
                                   yyerror("En la declaracion de la funcion");
                            }
                            /****** Completar la reserva para las variables locales y temporales */
                            completaLans((yyvsp[-5].cent), crArgEnt(dvar));
                            /****** Guardar el valor de retorno */
                            int dret = TALLA_SEGENLACES + TALLA_TIPO_SIMPLE + inf.tsp;
                            emite(EASIG, crArgPos(niv, (yyvsp[0].expresion).pos), crArgNul(), crArgPos(niv, -dret)); /* Para obtener el valor del return*/
                            /****** Liberar el segmento de variables locales y temporales */
                            emite(TOPFP, crArgNul(), crArgNul(), crArgNul() );
                            /****** Descargar los enlaces de control */
                            emite(FPPOP, crArgNul(), crArgNul(), crArgNul() );
                            /****** Emitir FIN si es ‘‘main’’ y RETURN si no es */
                            if (strcmp(inf.nom,"main\0") == 0) { emite(FIN, crArgNul(), crArgNul(), crArgNul()); 
                            }else { emite(RET, crArgNul(), crArgNul(), crArgNul()); } 
                     }
#line 1724 "asin.c"
    break;

  case 26:
#line 237 "src/asin.y"
                     {(yyval.cent) = T_VACIO;}
#line 1730 "asin.c"
    break;

  case 27:
#line 239 "src/asin.y"
                     {(yyval.cent) = (yyvsp[-1].cent) + (yyvsp[0].cent);}
#line 1736 "asin.c"
    break;

  case 37:
#line 258 "src/asin.y"
                     {
                            SIMB sim = obtTdS((yyvsp[-2].ident)); /* Esto accede a la TdS y obtiene la info de $3 que es ID_ */
                            if(sim.t == T_ERROR){ yyerror("No esta declarada");}
                            else if(sim.t != T_ENTERO){ yyerror("El argumento del 'Read' debe ser 'entero'");}
                            emite(EREAD, crArgNul(), crArgNul(),crArgPos(sim.n, sim.d) );
                     }
#line 1747 "asin.c"
    break;

  case 38:
#line 265 "src/asin.y"
                     {
                            if((yyvsp[-2].expresion).tipo != T_ENTERO){ yyerror("La expresion del 'print' debe ser 'entera'");}
                            /*Ahora mismo expre solo guarda el tipo, habrá que hacer con expre y todas las expre lo mismo que con const*/
                            /*Así tednrá tipo y posicion*/
                            emite(EWRITE, crArgNul(), crArgNul(),crArgPos(niv, (yyvsp[-2].expresion).pos) ); /*Cambiar expre por expre.pos*/
                            /*NOTA: CAMBIA TODOS LOS USOS DE EXPRE CON $i por $i.tipo al meterlo como const*/
                     }
#line 1759 "asin.c"
    break;

  case 39:
#line 275 "src/asin.y"
                     {
                            if((yyvsp[-1].expresion).tipo != T_ERROR && (yyvsp[-1].expresion).tipo != T_LOGICO) { yyerror("La expresion del `if' debe ser 'logico'");}
                            /*USamos $<ifelse>$.lf y no $$.lf porque el instSelec (Estrucutra IF)*/
                            /*aun no se ha termiando de procesar, sol opuedo hacer $$.lf si estuviese al final*/
                            (yyval.ifelse).lf = creaLans(si);
                            emite(EIGUAL, crArgPos(niv,(yyvsp[-1].expresion).pos), crArgEnt(0), crArgEnt(-1));
                     }
#line 1771 "asin.c"
    break;

  case 40:
#line 283 "src/asin.y"
                     {
                            (yyval.ifelse).fin = creaLans(si); 
                            emite(GOTOS, crArgNul(),crArgNul(),crArgEnt(-1));
                            completaLans((yyvsp[-1].ifelse).lf,crArgEtq(si));
                     }
#line 1781 "asin.c"
    break;

  case 41:
#line 289 "src/asin.y"
                     {
                            completaLans((yyvsp[-2].ifelse).fin,crArgEtq(si));
                     }
#line 1789 "asin.c"
    break;

  case 42:
#line 295 "src/asin.y"
                     {
                            (yyval.forexpre).ini = si; /*NOTA: METER COSAS EN MITAD REGLA HACE QUE SEA UN $ más -> cambiar refenrencias anteriores*/
                            /*$5 ahora sera $6 y $7 sera $9(porque hay 2 por medio) */ 
                     }
#line 1798 "asin.c"
    break;

  case 43:
#line 300 "src/asin.y"
                     {
                            (yyval.forexpre).lv = creaLans(si); 
                            emite(EIGUAL, crArgPos(niv,(yyvsp[-1].expresion).pos), crArgEnt(1), crArgEnt(-1));
                            (yyval.forexpre).lf = creaLans(si);
                            emite(GOTOS, crArgNul(),crArgNul(),crArgEnt(-1));
                            (yyval.forexpre).aux = si;
                     }
#line 1810 "asin.c"
    break;

  case 44:
#line 308 "src/asin.y"
                     {
                            
                            if ((yyvsp[-7].expresion).tipo != T_ERROR && (yyvsp[-4].expresion).tipo != T_ERROR && (yyvsp[-1].expresion).tipo != T_ERROR){
                                   if ((yyvsp[-7].expresion).tipo != T_VACIO && (yyvsp[-7].expresion).tipo != T_ENTERO && (yyvsp[-7].expresion).tipo != T_LOGICO) {
                                          yyerror("Las expresiones opcionales han de ser de tipo simple. ");
                                   }
                                   else if ((yyvsp[-1].expresion).tipo != T_VACIO && (yyvsp[-1].expresion).tipo != T_ENTERO && (yyvsp[-1].expresion).tipo != T_LOGICO) {
                                          yyerror("Las expresiones opcionales han de ser de tipo simple. ");
                                   } 
                                   else if ((yyvsp[-4].expresion).tipo != T_LOGICO) yyerror("La condicion del for debe ser de tipo logico. ");
                            } 
                            emite(GOTOS, crArgNul(),crArgNul(),crArgEnt((yyvsp[-5].forexpre).ini));
                            completaLans((yyvsp[-2].forexpre).lv,crArgEtq(si));
                     }
#line 1829 "asin.c"
    break;

  case 45:
#line 322 "src/asin.y"
                         {
                            emite(GOTOS, crArgNul(),crArgNul(),crArgEnt((yyvsp[-4].forexpre).aux));
                            completaLans((yyvsp[-4].forexpre).lf,crArgEtq(si));
                     }
#line 1838 "asin.c"
    break;

  case 46:
#line 329 "src/asin.y"
                     {(yyval.expresion).tipo = T_VACIO;}
#line 1844 "asin.c"
    break;

  case 47:
#line 330 "src/asin.y"
                            {(yyval.expresion).tipo = (yyvsp[0].expresion).tipo;}
#line 1850 "asin.c"
    break;

  case 48:
#line 333 "src/asin.y"
                                 {(yyval.expresion).tipo = (yyvsp[0].expresion).tipo; (yyval.expresion).pos = (yyvsp[0].expresion).pos;}
#line 1856 "asin.c"
    break;

  case 49:
#line 335 "src/asin.y"
                     {
                     SIMB sim = obtTdS((yyvsp[-2].ident));
                     (yyval.expresion).tipo = T_ERROR;
                     if ((yyvsp[0].expresion).tipo != T_ERROR){
                            if(sim.t == T_ERROR){ yyerror("Objeto no declarado");}
                            else if (sim.t == T_ARRAY){ yyerror("La variable debe ser de tipo array");}
                            else if (sim.t != (yyvsp[0].expresion).tipo){yyerror("En la asignacion a una variable simple");}
                            else{ (yyval.expresion).tipo = (yyvsp[0].expresion).tipo;}
                            }
                     emite(EASIG, crArgPos(niv, (yyvsp[0].expresion).pos), crArgNul(), crArgPos(sim.n, sim.d));
                     (yyval.expresion).pos = creaVarTemp();
                     emite(EASIG, crArgPos(niv,(yyvsp[0].expresion).pos), crArgNul(),crArgPos(niv, (yyval.expresion).pos));
                     }
#line 1874 "asin.c"
    break;

  case 50:
#line 349 "src/asin.y"
                     {
                     SIMB sim = obtTdS((yyvsp[-5].ident));
                     (yyval.expresion).tipo = T_ERROR;
                     if((yyvsp[-3].expresion).tipo != T_ERROR && (yyvsp[0].expresion).tipo != T_ERROR){
                            if(sim.t == T_ERROR){ yyerror("Expresion no declarada");}
                            else if(sim.t != T_ARRAY){ yyerror("La variable debe ser de tipo array");}
                            else if ((yyvsp[-3].expresion).tipo != T_ENTERO){ yyerror("El indice del array debe ser entero");}
                            else{
                                   DIM dim = obtTdA(sim.ref);
                                   if(dim.telem != T_ERROR){
                                          if(dim.telem != (yyvsp[0].expresion).tipo){yyerror("Error de tipos en la asignacion a un `array'");}
                                          else{ (yyval.expresion).tipo = (yyvsp[-3].expresion).tipo;}
                                          }
                                   }
                            }
                     
                     emite(EMULT, crArgPos(niv, (yyvsp[-3].expresion).pos), crArgEnt(TALLA_TIPO_SIMPLE) , crArgPos(niv, (yyvsp[-3].expresion).pos));
                     (yyval.expresion).pos = creaVarTemp();
                     emite(EVA, crArgPos(sim.n,sim.d), crArgPos(niv,(yyvsp[-3].expresion).pos),crArgPos(niv,(yyvsp[0].expresion).pos));
                     /*Añado esto porque en todas las asignaciones de expre tengo que hacer esto: a[b=2]=true o a[b[3]=2]=5(el b=2)*/
                     emite(EASIG, crArgPos(niv,(yyvsp[0].expresion).pos), crArgNul(),crArgPos(niv, (yyval.expresion).pos));
                     }
#line 1901 "asin.c"
    break;

  case 51:
#line 373 "src/asin.y"
                                 {(yyval.expresion).tipo = (yyvsp[0].expresion).tipo; (yyval.expresion).pos = (yyvsp[0].expresion).pos;}
#line 1907 "asin.c"
    break;

  case 52:
#line 375 "src/asin.y"
                     {
                     (yyval.expresion).tipo = T_ERROR;
                     if((yyvsp[-2].expresion).tipo != T_ERROR && (yyvsp[0].expresion).tipo != T_ERROR){
                            if((yyvsp[-2].expresion).tipo != (yyvsp[0].expresion).tipo){ yyerror("Error en la expresion logica");}
                            else if((yyvsp[-2].expresion).tipo != T_LOGICO){ yyerror("La expresion logica debe ser booleana");}
                            else{ (yyval.expresion).tipo = T_LOGICO;}
                            } 
                     (yyval.expresion).pos = creaVarTemp();
                     if ((yyvsp[-1].cent) == EMULT){   /* es un AND */ //Dif
                            emite(EMULT, crArgPos(niv, (yyvsp[-2].expresion).pos), crArgPos(niv, (yyvsp[0].expresion).pos), crArgPos(niv, (yyval.expresion).pos));
                     } else if ((yyvsp[-1].cent) == ESUM){    /* es un OR */ //Dif
                            emite(ESUM, crArgPos(niv, (yyvsp[-2].expresion).pos), crArgPos(niv, (yyvsp[0].expresion).pos), crArgPos(niv, (yyval.expresion).pos));
                            emite(EMENEQ, crArgPos(niv, (yyval.expresion).pos), crArgEnt(1), crArgEtq(si + 2));
                            emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, (yyval.expresion).pos));
                     }               
                     }
#line 1928 "asin.c"
    break;

  case 53:
#line 393 "src/asin.y"
                               {(yyval.expresion).tipo = (yyvsp[0].expresion).tipo; (yyval.expresion).pos = (yyvsp[0].expresion).pos;}
#line 1934 "asin.c"
    break;

  case 54:
#line 395 "src/asin.y"
                     {
                     (yyval.expresion).tipo = T_ERROR;
                     if((yyvsp[-2].expresion).tipo != T_ERROR && (yyvsp[0].expresion).tipo != T_ERROR && (yyvsp[-2].expresion).tipo != T_ENTERO){
                            if((yyvsp[-2].expresion).tipo != (yyvsp[0].expresion).tipo){ yyerror("Error en la expresion de igualdad");}
                            else if((yyvsp[-2].expresion).tipo != T_LOGICO){ yyerror("La expresion de igualdad debe ser booleana");}
                            else{ (yyval.expresion).tipo = T_LOGICO;}
                            }
                     (yyval.expresion).pos = creaVarTemp();
                     emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, (yyval.expresion).pos));
                     emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].expresion).pos), crArgPos(niv, (yyvsp[0].expresion).pos), crArgEtq(si + 2));  /*Puede ser == o !=*/
                     emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, (yyval.expresion).pos));
                     }
#line 1951 "asin.c"
    break;

  case 55:
#line 409 "src/asin.y"
                              {(yyval.expresion).tipo = (yyvsp[0].expresion).tipo; (yyval.expresion).pos = (yyvsp[0].expresion).pos;}
#line 1957 "asin.c"
    break;

  case 56:
#line 411 "src/asin.y"
                     {
                     (yyval.expresion).tipo = T_ERROR;
                     if((yyvsp[-2].expresion).tipo != T_ERROR && (yyvsp[0].expresion).tipo != T_ERROR){
                            if((yyvsp[-2].expresion).tipo != (yyvsp[0].expresion).tipo){ yyerror("Error en la expresion relacional");}
                            else if((yyvsp[-2].expresion).tipo == T_LOGICO){ yyerror("La expresion relacional debe ser booleana");}
                            else{ (yyval.expresion).tipo = T_LOGICO;}
                     }
                     (yyval.expresion).pos = creaVarTemp();
                     emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, (yyval.expresion).pos));
                     emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].expresion).pos), crArgPos(niv, (yyvsp[0].expresion).pos), crArgEtq(si + 2));  /*Puede ser == o !=*/
                     emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, (yyval.expresion).pos));
                     }
#line 1974 "asin.c"
    break;

  case 57:
#line 425 "src/asin.y"
                               {(yyval.expresion).tipo = (yyvsp[0].expresion).tipo; (yyval.expresion).pos = (yyvsp[0].expresion).pos;}
#line 1980 "asin.c"
    break;

  case 58:
#line 427 "src/asin.y"
                     {
                     (yyval.expresion).tipo = T_ERROR;
                     if((yyvsp[-2].expresion).tipo != T_ERROR && (yyvsp[0].expresion).tipo != T_ERROR){
                            if((yyvsp[-2].expresion).tipo != (yyvsp[0].expresion).tipo){ yyerror("Error en la expresion aditiva");}
                            else if((yyvsp[-2].expresion).tipo != T_ENTERO){ yyerror("la expresion aditiva debe ser de tipo entero");}
                            else{ (yyval.expresion).tipo = T_ENTERO;}
                     }
                     (yyval.expresion).pos = creaVarTemp();
                     emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].expresion).pos), crArgPos(niv, (yyvsp[0].expresion).pos), crArgPos(niv, (yyval.expresion).pos));
                     }
#line 1995 "asin.c"
    break;

  case 59:
#line 439 "src/asin.y"
                               {(yyval.expresion).tipo = (yyvsp[0].expresion).tipo; (yyval.expresion).pos = (yyvsp[0].expresion).pos;}
#line 2001 "asin.c"
    break;

  case 60:
#line 441 "src/asin.y"
                     {
                     (yyval.expresion).tipo = T_ERROR;
                     if((yyvsp[-2].expresion).tipo != T_ERROR && (yyvsp[0].expresion).tipo != T_ERROR){
                            if((yyvsp[-2].expresion).tipo != (yyvsp[0].expresion).tipo){ yyerror("Error en la expresion multiplicativa");}
                            else if((yyvsp[-2].expresion).tipo != T_ENTERO){ yyerror("La expresion multiplicativa debe ser de tipo entero");}
                            else{ (yyval.expresion).tipo = T_ENTERO;}
                     }
                     (yyval.expresion).pos = creaVarTemp();
                     emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].expresion).pos), crArgPos(niv, (yyvsp[0].expresion).pos), crArgPos(niv, (yyval.expresion).pos));
                     }
#line 2016 "asin.c"
    break;

  case 61:
#line 453 "src/asin.y"
                                {(yyval.expresion).tipo = (yyvsp[0].expresion).tipo; (yyval.expresion).pos = (yyvsp[0].expresion).pos;}
#line 2022 "asin.c"
    break;

  case 62:
#line 455 "src/asin.y"
                     {
                     (yyval.expresion).tipo = T_ERROR;
                     if((yyvsp[0].expresion).tipo != T_ERROR){
                            if( (yyvsp[0].expresion).tipo == T_ENTERO){
                                   if( (yyvsp[-1].cent) == EDIF){
                                   yyerror("Error en expresion unaria");
                                   } else{
                                          (yyval.expresion).tipo = T_ENTERO;
                                   }      
                            }else if((yyvsp[0].expresion).tipo == T_LOGICO){
                                   if ((yyvsp[-1].cent)==ESUM || (yyvsp[-1].cent) == EDIF) {   //si es + o -, no puede ser logico
                                          yyerror("Operacion entera invalidada en expresion logica");
                                          
                                   } else {
                                          (yyval.expresion).tipo = T_LOGICO;
                                   }
                            } 
                     }
                     (yyval.expresion).pos = creaVarTemp();
                     if ((yyvsp[-1].cent) == ESIG) { /*NOT*/
                            (yyval.expresion).pos = creaVarTemp();
                            emite(EDIF, crArgEnt(1), crArgPos(niv, (yyvsp[0].expresion).pos), crArgPos(niv, (yyval.expresion).pos));    
                     }
                     else if( (yyvsp[-1].cent) == EDIF){
                            (yyval.expresion).pos = creaVarTemp();
                            emite(ESIG, crArgPos(niv, (yyvsp[0].expresion).pos), crArgNul(), crArgPos(niv, (yyval.expresion).pos));
                     } 
                     else { 
                            (yyval.expresion).pos = (yyvsp[0].expresion).pos;
                     } 
                     }
#line 2058 "asin.c"
    break;

  case 63:
#line 489 "src/asin.y"
                     {
                     (yyval.expresion).tipo = (yyvsp[0].expresion).tipo;

                     (yyval.expresion).pos = creaVarTemp();
                     emite(EASIG, crArgEnt((yyvsp[0].expresion).pos), crArgNul(), crArgPos(niv, (yyval.expresion).pos));
                     }
#line 2069 "asin.c"
    break;

  case 64:
#line 495 "src/asin.y"
                                                      {
                     (yyval.expresion).tipo = (yyvsp[-1].expresion).tipo;
                     (yyval.expresion).pos = (yyvsp[-1].expresion).pos;
                     }
#line 2078 "asin.c"
    break;

  case 65:
#line 500 "src/asin.y"
                     { 
                     SIMB sim = obtTdS((yyvsp[0].ident)); 
                     (yyval.expresion).tipo = T_ERROR;
                            if(sim.t == T_ERROR) {yyerror("Objeto no declarado");}
                            else{(yyval.expresion).tipo = sim.t;} 
                     (yyval.expresion).pos = creaVarTemp();
                     emite(EASIG, crArgPos(sim.n, sim.d), crArgNul(), crArgPos(niv, (yyval.expresion).pos));
                     }
#line 2091 "asin.c"
    break;

  case 66:
#line 509 "src/asin.y"
                     { 
                     SIMB sim = obtTdS((yyvsp[-3].ident)); 
                     (yyval.expresion).tipo = T_ERROR;
                     if(sim.t == T_ERROR) {yyerror("Objeto no declarado");}
                     else{
                     if(sim.t != T_ARRAY){
		              yyerror("ID debe ser de tipo array");
			}else{
				if ((yyvsp[-1].expresion).tipo != T_ENTERO ) {yyerror("Indice no entero");}
				else {
					DIM dim = obtTdA(sim.ref);
					(yyval.expresion).tipo = dim.telem;
				}
		       }
                     
                     emite(EMULT, crArgPos(niv, (yyvsp[-1].expresion).pos), crArgEnt(TALLA_TIPO_SIMPLE) , crArgPos(niv, (yyvsp[-1].expresion).pos));
                     (yyval.expresion).pos = creaVarTemp();
                     emite(EAV, crArgPos(sim.n,sim.d), crArgPos(niv,(yyvsp[-1].expresion).pos),crArgPos(niv,(yyval.expresion).pos));
	              }
                   
                     }
#line 2117 "asin.c"
    break;

  case 67:
#line 531 "src/asin.y"
                     {
                            emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(TALLA_TIPO_SIMPLE));
                     }
#line 2125 "asin.c"
    break;

  case 68:
#line 535 "src/asin.y"
                     { 
                     
                     SIMB sim = obtTdS((yyvsp[-4].ident)); 
                     INF inf = obtTdD(sim.ref);
                     (yyval.expresion).tipo = T_ERROR;
		       if(sim.t == T_ERROR) {yyerror("Objeto no declarado");}
		       else{             
			       if (inf.tipo == T_ERROR) { 
				       yyerror("No se encuentra la función"); 
			       } else if (!(cmpDom(sim.ref, (yyvsp[-1].cent)))) {
                                   yyerror("En el dominio de los parametros actuales");
                            } else { 
                                   (yyval.expresion).tipo = inf.tipo;
                            }
                     }
                     
                     emite(CALL, crArgNul(), crArgNul(), crArgEtq(sim.d));
                     emite(DECTOP, crArgNul(), crArgNul(), crArgEnt(inf.tsp));
                     (yyval.expresion).pos = creaVarTemp();
                     emite(EPOP, crArgNul(), crArgNul(), crArgPos(niv, (yyval.expresion).pos));
                     }
#line 2151 "asin.c"
    break;

  case 69:
#line 558 "src/asin.y"
                    {(yyval.cent) = insTdD(-1,T_VACIO);}
#line 2157 "asin.c"
    break;

  case 70:
#line 559 "src/asin.y"
                                 { (yyval.cent) = (yyvsp[0].cent);}
#line 2163 "asin.c"
    break;

  case 71:
#line 563 "src/asin.y"
              {
                     (yyval.cent) = insTdD(-1,(yyvsp[0].expresion).tipo); //Creo la referencia del dominio 
                     emite(EPUSH,crArgNul(),crArgNul(),crArgPos(niv, (yyvsp[0].expresion).pos));
              }
#line 2172 "asin.c"
    break;

  case 72:
#line 568 "src/asin.y"
              {
                     emite(EPUSH,crArgNul(),crArgNul(),crArgPos(niv, (yyvsp[0].expresion).pos));
              }
#line 2180 "asin.c"
    break;

  case 73:
#line 572 "src/asin.y"
                     {(yyval.cent) = insTdD((yyvsp[0].cent),(yyvsp[-3].expresion).tipo);}
#line 2186 "asin.c"
    break;

  case 74:
#line 575 "src/asin.y"
                          {(yyval.cent) = EMULT;}
#line 2192 "asin.c"
    break;

  case 75:
#line 576 "src/asin.y"
                         {(yyval.cent) = ESUM;}
#line 2198 "asin.c"
    break;

  case 76:
#line 579 "src/asin.y"
                            {(yyval.cent) = EIGUAL;}
#line 2204 "asin.c"
    break;

  case 77:
#line 580 "src/asin.y"
                               {(yyval.cent) = EDIST;}
#line 2210 "asin.c"
    break;

  case 78:
#line 583 "src/asin.y"
                            {(yyval.cent) = EMAY;}
#line 2216 "asin.c"
    break;

  case 79:
#line 584 "src/asin.y"
                            {(yyval.cent) = EMEN;}
#line 2222 "asin.c"
    break;

  case 80:
#line 585 "src/asin.y"
                              {(yyval.cent) = EMAYEQ;}
#line 2228 "asin.c"
    break;

  case 81:
#line 586 "src/asin.y"
                              {(yyval.cent) = EMENEQ;}
#line 2234 "asin.c"
    break;

  case 82:
#line 589 "src/asin.y"
                          {(yyval.cent) = ESUM;}
#line 2240 "asin.c"
    break;

  case 83:
#line 590 "src/asin.y"
                            {(yyval.cent) = EDIF;}
#line 2246 "asin.c"
    break;

  case 84:
#line 593 "src/asin.y"
                          {(yyval.cent) = EMULT;}
#line 2252 "asin.c"
    break;

  case 85:
#line 594 "src/asin.y"
                          {(yyval.cent) = EDIVI;}
#line 2258 "asin.c"
    break;

  case 86:
#line 597 "src/asin.y"
                          {(yyval.cent) = ESUM;}
#line 2264 "asin.c"
    break;

  case 87:
#line 598 "src/asin.y"
                            {(yyval.cent) = EDIF;}
#line 2270 "asin.c"
    break;

  case 88:
#line 599 "src/asin.y"
                           {(yyval.cent) = ESIG;}
#line 2276 "asin.c"
    break;


#line 2280 "asin.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 605 "src/asin.y"

/*****************************************************************************/
/*****AQUI IRIA EL MAIN PERO LO TENEMOS A APARTE: PRINCIPAL.C*********/
