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
#line 1 "expresiones.y"

#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "tabla.h"
#include "lista.h"
#include <map>

using namespace std;

//elementos externos al analizador sintácticos por haber sido declarados en el analizador léxico      			
extern int n_lineas;
extern int yylex();
bool errorSemantico = false;
tablaSim tabla;
lista list;
tipo_datoTS dato;
tipo_datoTS datosVar[100];
tipo_datoLista datosLis;
tipo_valorLista valorLista;
int pos;
int contVar=0;
int contLis=0;
bool ejecutar = true;

extern FILE* yyin;
extern FILE* yyout;

//definición de procedimientos auxiliares


void yyerror(const char* s){
	if(!errorSemantico)
		cout << "Error sintáctico en la instrucción " << n_lineas << endl; 
	errorSemantico=false;
	ejecutar=true;
}


#line 111 "expresiones.c"

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
#ifndef YY_YY_EXPRESIONES_H_INCLUDED
# define YY_YY_EXPRESIONES_H_INCLUDED
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
    ASIGNACION = 258,
    COMP_ARIT1 = 259,
    COMP_ARIT2 = 260,
    COMP_IGUAL = 261,
    COMP_DIST = 262,
    COMP_Y = 263,
    COMP_O = 264,
    COMP_NO = 265,
    SUBRANGO = 266,
    ENTERO = 267,
    REAL = 268,
    VARIABLE = 269,
    BOOL = 270,
    NOMBRE_LISTA = 271,
    TIPO_VAL = 272,
    LISTA = 273,
    VARIABLES = 274,
    INICIO = 275,
    FIN = 276,
    SI = 277,
    SI_NO = 278,
    ESCRIBIR = 279,
    NUEVALINEA = 280,
    PRIMERO = 281,
    ULTIMO = 282,
    ENESIMO = 283,
    CADENA_CARACT = 284,
    si_simple = 285,
    menos = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "expresiones.y"

	int c_entero;
	float c_float;
	char c_cadena[25];
	char c_texto [100];
	bool c_bool;
	struct {
		float valor;
		bool esReal;
	} c_expresion;

#line 207 "expresiones.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EXPRESIONES_H_INCLUDED  */



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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   415

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  249

#define YYUNDEFTOK  2
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    39,     2,     2,
      45,    46,    37,    35,    32,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
      33,    42,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    97,    97,    98,   100,   101,   103,   104,   106,   108,
     123,   132,   142,   159,   175,   185,   196,   216,   218,   219,
     221,   233,   249,   262,   279,   285,   293,   295,   296,   297,
     298,   300,   302,   302,   304,   305,   305,   307,   335,   386,
     406,   426,   446,   447,   452,   480,   531,   552,   572,   592,
     593,   599,   636,   674,   679,   684,   709,   719,   727,   746,
     766,   788,   813,   824,   832,   852,   872,   892,   894,   896,
     915,   917,   919,   921,   933,   947,   949,   952,   953,   954,
     955,   956,   957,   958,   959,   960,   961,   962,   963,   964
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASIGNACION", "COMP_ARIT1", "COMP_ARIT2",
  "COMP_IGUAL", "COMP_DIST", "COMP_Y", "COMP_O", "COMP_NO", "SUBRANGO",
  "ENTERO", "REAL", "VARIABLE", "BOOL", "NOMBRE_LISTA", "TIPO_VAL",
  "LISTA", "VARIABLES", "INICIO", "FIN", "SI", "SI_NO", "ESCRIBIR",
  "NUEVALINEA", "PRIMERO", "ULTIMO", "ENESIMO", "CADENA_CARACT",
  "si_simple", "';'", "','", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "menos", "'\\n'", "'='", "'{'", "'}'", "'('", "')'", "'['", "']'",
  "$accept", "saltoLinea", "saltoLineaOpcional", "entrada", "bListas",
  "secListas", "bVariables", "saltosVariables", "secVariables", "var",
  "bInicio", "bloqueInstruc", "condicional", "parteSi", "$@1", "parteSiNo",
  "$@2", "secInstruc", "listaNum", "listaLog", "secuenciaVal", "exprNum",
  "exprBool", YY_NULLPTR
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
     285,    59,    44,    60,    62,    43,    45,    42,    47,    37,
     286,    10,    61,   123,   125,    40,    41,    91,    93
};
# endif

#define YYPACT_NINF (-210)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-62)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,    -2,    51,   -21,  -210,   -14,  -210,  -210,    62,   -21,
      35,    27,  -210,    55,    36,   -21,   -21,    69,   100,   101,
     101,   171,   178,    20,   112,    23,   119,  -210,   128,   168,
     178,   101,   101,   112,   163,   130,   146,   165,   353,  -210,
     180,     5,   118,  -210,  -210,    16,  -210,    84,   118,    67,
      73,   111,   102,   325,   157,  -210,   193,  -210,   112,   189,
     259,   233,   118,   273,  -210,  -210,  -210,     5,  -210,  -210,
     208,   186,   198,   112,  -210,   219,  -210,    84,  -210,    88,
       3,   -21,    84,   -21,   118,   -21,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,   118,   118,
     118,   118,   226,   120,   124,   129,   219,  -210,  -210,  -210,
     194,   197,   199,   143,   266,    17,   -15,   217,   225,   232,
    -210,    11,   354,   112,  -210,   253,   273,  -210,   289,  -210,
    -210,   112,   354,   112,   325,   112,   354,   354,   354,   354,
     344,   354,   354,   196,   196,  -210,  -210,  -210,  -210,  -210,
     297,   243,   276,   -21,   -21,   -21,   277,   280,   300,  -210,
    -210,  -210,   301,   303,   313,   294,   279,    63,   291,   293,
     307,   179,   306,    68,   -21,   309,   112,   112,   112,   304,
     308,   323,  -210,   324,   326,   337,    70,   331,   339,   340,
    -210,   354,  -210,  -210,   355,   370,   371,  -210,  -210,   363,
     112,   -21,   364,   365,    84,   110,  -210,  -210,    84,   381,
     382,   383,   270,   356,   357,   368,  -210,   112,  -210,  -210,
     305,  -210,   310,   358,   359,   369,   184,   375,   376,    84,
     377,   270,  -210,  -210,  -210,    84,   -21,  -210,  -210,   322,
    -210,   216,   327,   112,   378,   -21,  -210,  -210,   112
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     0,     5,     0,     1,     2,     0,     0,
       0,     0,     3,     8,     0,     0,     0,     0,     0,     0,
       0,    17,     0,     0,     7,     0,     0,    24,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,    28,
      34,     0,     0,    67,    68,    69,    77,     0,     0,     0,
       0,     0,    51,    53,     0,    21,     0,    20,    19,     0,
       0,     0,     0,     0,    43,    26,    30,     0,    35,    31,
       0,     0,     0,    27,    69,     0,    89,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,     0,     0,     0,    51,    25,    23,    22,
       0,     0,     0,     0,     0,     0,    69,     0,     0,     0,
      57,     0,    56,    29,     4,     0,     0,    50,     0,    76,
      78,     9,    52,    10,    54,    11,    81,    82,    83,    84,
       0,    79,    80,    70,    71,    72,    73,    74,    85,    86,
      87,    88,     0,     0,     0,     0,     0,     0,     0,    38,
      37,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,    15,     0,
       0,     0,     4,     0,     0,     0,    69,     0,     0,     0,
      63,    62,    42,     4,     0,     0,     0,    45,    44,     0,
      12,     0,     0,     0,     0,     0,    58,    59,     0,     0,
       0,     0,     0,     0,     0,     0,    49,    16,    39,    40,
       0,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,    64,    65,     0,     0,    46,    47,     0,
      41,     0,     0,    36,     0,     0,    66,    48,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -210,    -9,  -120,  -210,  -210,  -210,  -210,  -210,   389,   251,
    -210,  -209,   -37,  -210,  -210,  -210,  -210,   -36,   360,   361,
     285,    -7,   -34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     1,     2,     5,    13,    10,    21,    22,    28,
      16,    38,    39,    40,   182,    69,   124,    41,    50,    51,
     121,    75,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    66,    67,   226,   167,     9,    23,    24,    76,    98,
      99,   100,   101,    33,    80,    -6,     3,   -55,    52,    70,
       7,    58,   241,    98,    99,   100,   101,   114,   115,    71,
      72,   -55,    73,    42,    34,    43,    44,    45,    46,     4,
      78,    79,    35,   165,    36,    37,     7,   106,   -24,   130,
     134,     6,    19,    20,   113,    15,   122,   166,   123,    47,
     -24,    12,   205,   161,   148,   149,   150,   151,    48,    17,
     128,    18,   131,   212,   133,   132,   135,    12,    11,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   172,    86,    87,    88,    89,    43,    44,    74,    56,
     165,   231,   -61,    12,     4,    82,    86,    87,    88,    89,
     193,    81,    25,    90,   199,    27,   -61,    83,   171,   122,
      47,    91,    92,    93,    94,    95,    96,    97,    42,    77,
      43,    44,    74,    46,   129,    91,    92,    93,    94,    95,
      96,    97,    26,    84,   176,   177,   178,    86,    87,    88,
      89,     4,    56,    12,    47,    85,    82,   221,   191,    55,
      56,    84,    54,    48,   153,   200,    61,    42,   154,   102,
      44,    45,    46,   155,   159,    62,    91,    92,    93,    94,
      95,    96,    97,    86,    87,    88,    89,    19,    20,    66,
      67,    63,   217,    47,    31,    32,    64,   220,    34,    57,
      56,   222,    48,    68,    66,    67,    35,   107,    36,    37,
     197,   125,    91,    92,    93,    94,    95,    96,    97,     7,
     108,    56,   239,    86,    87,    88,    89,   243,   242,   127,
      34,   126,   236,    95,    96,    97,   248,   152,    35,   156,
      36,    37,   157,    42,   158,    43,    44,    74,    46,    98,
      99,   100,    91,    92,    93,    94,    95,    96,    97,   110,
     111,   112,   162,    42,   245,    43,    44,    74,    46,    47,
     163,    29,    98,    99,   100,   101,    49,   164,    48,   168,
     169,   170,    59,    60,    34,    43,    44,   116,   175,    47,
     109,    56,    35,   179,    36,    37,   180,   160,    48,   117,
     118,   119,   120,    98,    99,   103,    43,    44,   186,    47,
     192,     4,    98,    99,   100,   101,   181,   183,    77,   184,
     187,   188,   189,   190,    93,    94,    95,    96,    97,   185,
      47,    98,    99,   100,   101,   129,   194,   198,   195,    77,
      93,    94,    95,    96,    97,    93,    94,    95,    96,    97,
     202,   230,   196,   201,   203,   204,   232,    93,    94,    95,
      96,    97,    93,    94,    95,    96,    97,    34,   244,   208,
     206,   213,   207,   246,    65,    35,   209,    36,    37,    93,
      94,    95,    96,    97,   210,   211,   214,   215,   174,    93,
      94,    95,    96,    97,   216,   218,   219,   223,   224,   225,
     229,   235,   227,   228,   233,   234,   237,   238,   240,   247,
      30,   173,     0,     0,   104,   105
};

static const yytype_int16 yycheck[] =
{
       9,    38,    38,   212,   124,    19,    15,    16,    42,     6,
       7,     8,     9,    22,    48,     0,    18,    32,    25,    14,
      41,    30,   231,     6,     7,     8,     9,    61,    62,    24,
      25,    46,    41,    10,    14,    12,    13,    14,    15,    41,
      47,    48,    22,    32,    24,    25,    41,    54,    32,    46,
      84,     0,    16,    17,    61,    20,    63,    46,    67,    36,
      44,    41,   182,    46,    98,    99,   100,   101,    45,    42,
      77,    16,    81,   193,    83,    82,    85,    41,    16,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,   125,     4,     5,     6,     7,    12,    13,    14,    32,
      32,   221,    32,    41,    41,    32,     4,     5,     6,     7,
      47,    44,    43,    11,    46,    14,    46,    44,   125,   126,
      36,    33,    34,    35,    36,    37,    38,    39,    10,    45,
      12,    13,    14,    15,    46,    33,    34,    35,    36,    37,
      38,    39,    42,    32,   153,   154,   155,     4,     5,     6,
       7,    41,    32,    41,    36,    44,    32,    47,   165,    31,
      32,    32,    43,    45,    44,   174,     3,    10,    44,    12,
      13,    14,    15,    44,    31,    45,    33,    34,    35,    36,
      37,    38,    39,     4,     5,     6,     7,    16,    17,   226,
     226,    45,   201,    36,    16,    17,    31,   204,    14,    31,
      32,   208,    45,    23,   241,   241,    22,    14,    24,    25,
      31,     3,    33,    34,    35,    36,    37,    38,    39,    41,
      31,    32,   229,     4,     5,     6,     7,   236,   235,    31,
      14,    45,    48,    37,    38,    39,   245,    11,    22,    45,
      24,    25,    45,    10,    45,    12,    13,    14,    15,     6,
       7,     8,    33,    34,    35,    36,    37,    38,    39,    26,
      27,    28,    45,    10,    48,    12,    13,    14,    15,    36,
      45,    20,     6,     7,     8,     9,    25,    45,    45,    26,
      27,    28,    31,    32,    14,    12,    13,    14,    12,    36,
      31,    32,    22,    16,    24,    25,    16,    31,    45,    26,
      27,    28,    29,     6,     7,    54,    12,    13,    14,    36,
      31,    41,     6,     7,     8,     9,    16,    16,    45,    16,
      26,    27,    28,    29,    35,    36,    37,    38,    39,    16,
      36,     6,     7,     8,     9,    46,    45,    31,    45,    45,
      35,    36,    37,    38,    39,    35,    36,    37,    38,    39,
      46,    46,    45,    44,    46,    32,    46,    35,    36,    37,
      38,    39,    35,    36,    37,    38,    39,    14,    46,    32,
      46,    16,    46,    46,    21,    22,    45,    24,    25,    35,
      36,    37,    38,    39,    45,    45,    16,    16,    44,    35,
      36,    37,    38,    39,    31,    31,    31,    16,    16,    16,
      32,    32,    46,    46,    46,    46,    31,    31,    31,    31,
      21,   126,    -1,    -1,    54,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,    52,    18,    41,    53,     0,    41,    50,    19,
      55,    16,    41,    54,    50,    20,    59,    42,    16,    16,
      17,    56,    57,    50,    50,    43,    42,    14,    58,    58,
      57,    16,    17,    50,    14,    22,    24,    25,    60,    61,
      62,    66,    10,    12,    13,    14,    15,    36,    45,    58,
      67,    68,    70,    71,    43,    31,    32,    31,    50,    58,
      58,     3,    45,    45,    31,    21,    61,    66,    23,    64,
      14,    24,    25,    50,    14,    70,    71,    45,    70,    70,
      71,    44,    32,    44,    32,    44,     4,     5,     6,     7,
      11,    33,    34,    35,    36,    37,    38,    39,     6,     7,
       8,     9,    12,    58,    67,    68,    70,    14,    31,    31,
      26,    27,    28,    70,    71,    71,    14,    26,    27,    28,
      29,    69,    70,    50,    65,     3,    45,    31,    70,    46,
      46,    50,    70,    50,    71,    50,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    71,    71,
      71,    71,    11,    44,    44,    44,    45,    45,    45,    31,
      31,    46,    45,    45,    45,    32,    46,    51,    26,    27,
      28,    70,    71,    69,    44,    12,    50,    50,    50,    16,
      16,    16,    63,    16,    16,    16,    14,    26,    27,    28,
      29,    70,    31,    47,    45,    45,    45,    31,    31,    46,
      50,    44,    46,    46,    32,    51,    46,    46,    32,    45,
      45,    45,    51,    16,    16,    16,    31,    50,    31,    31,
      70,    47,    70,    16,    16,    16,    60,    46,    46,    32,
      46,    51,    46,    46,    46,    32,    48,    31,    31,    70,
      31,    60,    70,    50,    46,    48,    46,    31,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    52,    53,    54,
      54,    54,    54,    54,    54,    54,    54,    55,    56,    56,
      57,    57,    57,    57,    58,    58,    59,    60,    60,    60,
      60,    61,    63,    62,    64,    65,    64,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     0,     5,     3,     6,
       6,     6,     8,     7,     7,     7,     9,     3,     2,     3,
       3,     3,     4,     4,     1,     3,     4,     2,     1,     3,
       2,     2,     0,    11,     0,     0,     8,     4,     4,     7,
       7,     9,     5,     2,     5,     5,     8,     8,    10,     6,
       3,     1,     3,     1,     3,     1,     1,     1,     4,     4,
       6,     3,     3,     3,     6,     6,     8,     1,     1,     1,
       3,     3,     3,     3,     3,     2,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2
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
  case 6:
#line 103 "expresiones.y"
                        {;}
#line 1568 "expresiones.c"
    break;

  case 9:
#line 108 "expresiones.y"
                                                                {if(!errorSemantico){
									strcpy(datosLis.identificador, (yyvsp[-5].c_cadena));
									datosLis.numDatos = contVar;
									datosLis.tipo = 3;
									int i=0;
									while(i<contVar){
										strcpy(datosLis.datos[i].valor_iden, datosVar[i].identificador);
										i++;
									}
									list.insertar(datosLis);
									datosLis.numDatos=0;
									contVar = 0;
								}
								errorSemantico=false;
								}
#line 1588 "expresiones.c"
    break;

  case 10:
#line 123 "expresiones.y"
                                                        {if(!errorSemantico){
								strcpy(datosLis.identificador, (yyvsp[-5].c_cadena));
								datosLis.numDatos = contLis;
								list.insertar(datosLis);
								datosLis.numDatos=0;
								contLis = 0;
							}
							errorSemantico=false;
							}
#line 1602 "expresiones.c"
    break;

  case 11:
#line 132 "expresiones.y"
                                                        {if(!errorSemantico){
								strcpy(datosLis.identificador, (yyvsp[-5].c_cadena));
								datosLis.tipo = 2;
								datosLis.numDatos = contLis;
								list.insertar(datosLis);
								datosLis.numDatos=0;
								contLis = 0;
							}
							errorSemantico=false;
							}
#line 1617 "expresiones.c"
    break;

  case 12:
#line 142 "expresiones.y"
                                                                        {if(!errorSemantico){
										int mayor = int((yyvsp[-2].c_expresion).valor);
										int menor = int((yyvsp[-4].c_expresion).valor);
										int i = 0;
										strcpy(datosLis.identificador, (yyvsp[-7].c_cadena));
										datosLis.tipo = 0;
										while (menor <= mayor){
											datosLis.datos[i].valor_entero = menor;
											menor++;
											i++;
										}
										datosLis.numDatos= i;
										list.insertar(datosLis);
										datosLis.numDatos=0;
									}
									errorSemantico=false;
									}
#line 1639 "expresiones.c"
    break;

  case 13:
#line 159 "expresiones.y"
                                                                        {if(!errorSemantico){
										strcpy(datosLis.identificador, (yyvsp[-5].c_cadena));
										datosLis.numDatos = contVar;
										datosLis.tipo = 3;
										int i=0;
										while(i<contVar){
											strcpy(datosLis.datos[i].valor_iden, datosVar[i].identificador);
											i++;
										}
										list.insertar(datosLis);
										datosLis.numDatos=0;
										contVar = 0;
									}
									errorSemantico=false;
									}
#line 1659 "expresiones.c"
    break;

  case 14:
#line 175 "expresiones.y"
                                                                {if(!errorSemantico){
										strcpy(datosLis.identificador, (yyvsp[-5].c_cadena));
										datosLis.numDatos = contLis;
										list.insertar(datosLis);
										datosLis.numDatos=0;
										contLis = 0;
									}
									errorSemantico=false;
									}
#line 1673 "expresiones.c"
    break;

  case 15:
#line 185 "expresiones.y"
                                                                {if(!errorSemantico){
										strcpy(datosLis.identificador, (yyvsp[-5].c_cadena));
										datosLis.tipo = 2;
										datosLis.numDatos = contLis;
										list.insertar(datosLis);
										datosLis.numDatos=0;
										contLis = 0;
									}
									errorSemantico=false;
									}
#line 1688 "expresiones.c"
    break;

  case 16:
#line 196 "expresiones.y"
                                                                                {if(!errorSemantico){
											int mayor = (yyvsp[-2].c_entero);
											int menor = (yyvsp[-4].c_entero);
											if(menor<mayor){
												int i = 0;
												strcpy(datosLis.identificador, (yyvsp[-7].c_cadena));
												datosLis.tipo = 0;
												while (menor <= mayor){
													datosLis.datos[i].valor_entero = menor;
													menor++;
													i++;
												}
												datosLis.numDatos= i;
												list.insertar(datosLis);
												datosLis.numDatos=0;
											}
										}
										errorSemantico=false;
										}
#line 1712 "expresiones.c"
    break;

  case 20:
#line 221 "expresiones.y"
                                        {if(!errorSemantico){
						dato.tipo = (yyvsp[-2].c_entero);
						int i=0;
						while(i<contVar){
							strcpy(dato.identificador, datosVar[i].identificador);
							tabla.insertar(dato);
							i++;
						}
						contVar=0;
					}
					errorSemantico=false;
					}
#line 1729 "expresiones.c"
    break;

  case 21:
#line 233 "expresiones.y"
                                        {if(!errorSemantico){
						tipo_datoLista valorLista;
						if(list.encontrarLista((yyvsp[-2].c_cadena), valorLista)){
							dato.tipo = valorLista.tipo;
							strcpy(dato.nomLista, (yyvsp[-2].c_cadena));
							int i=0;
							while(i<contVar){
								strcpy(dato.identificador, datosVar[i].identificador);
								tabla.insertar(dato);
								i++;
							}
							contVar=0;
						}
					}
					errorSemantico=false;
					}
#line 1750 "expresiones.c"
    break;

  case 22:
#line 249 "expresiones.y"
                                        {if(!errorSemantico){
							dato.tipo = (yyvsp[-2].c_entero);
							int i=0;
							while(i<contVar){
								strcpy(dato.identificador, datosVar[i].identificador);
								tabla.insertar(dato);
								i++;
							}
							contVar=0;
						}
						errorSemantico=false;
						}
#line 1767 "expresiones.c"
    break;

  case 23:
#line 262 "expresiones.y"
                                                {if(!errorSemantico){
						tipo_datoLista valorLista;
						if(list.encontrarLista((yyvsp[-2].c_cadena), valorLista)){
							dato.tipo = valorLista.tipo;
							strcpy(dato.nomLista, (yyvsp[-2].c_cadena));
							int i=0;
							while(i<contVar){
								strcpy(dato.identificador, datosVar[i].identificador);
								tabla.insertar(dato);
								i++;
							}
							contVar=0;
						}
					}
					errorSemantico=false;
					}
#line 1788 "expresiones.c"
    break;

  case 24:
#line 279 "expresiones.y"
                                        {if(!errorSemantico){
						strcpy(datosVar[contVar].identificador, (yyvsp[0].c_cadena));
						contVar++;
						datosLis.tipo = 3;
					}
					}
#line 1799 "expresiones.c"
    break;

  case 25:
#line 285 "expresiones.y"
                                        {if(!errorSemantico){
						strcpy(datosVar[contVar].identificador, (yyvsp[0].c_cadena));
						contVar++;
						datosLis.tipo = 3;
					}
					}
#line 1810 "expresiones.c"
    break;

  case 31:
#line 300 "expresiones.y"
                                {ejecutar=true;}
#line 1816 "expresiones.c"
    break;

  case 32:
#line 302 "expresiones.y"
                            {ejecutar=(yyvsp[-1].c_bool);}
#line 1822 "expresiones.c"
    break;

  case 35:
#line 305 "expresiones.y"
               {ejecutar=!ejecutar;}
#line 1828 "expresiones.c"
    break;

  case 37:
#line 307 "expresiones.y"
                                                {if(ejecutar){
							if(!errorSemantico){
								
								if(tabla.buscar((yyvsp[-3].c_cadena), dato, pos)){
									if(dato.tipo == 2){
										dato.valor.valor_bool = (yyvsp[-1].c_bool);
										if(!tabla.modificar(pos, dato.valor)){
											cout<< "Error al modificar" << endl;
										}
									}
									else if(dato.tipo == 0){
										cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo entero y recibe un logico" 									<< endl;
										errorSemantico=true;
									}
									else if(dato.tipo == 1){
										cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo real y recibe un logico" 										<< endl;
										errorSemantico=true;
									}
								}
								else{
									cout<< "Error semántico en la instrucción "<< n_lineas << ": la variable "<< (yyvsp[-3].c_cadena) << " no existe" << endl; 
	       							errorSemantico=true;
								}
							}	
							errorSemantico=false;
						}
						
						}
#line 1861 "expresiones.c"
    break;

  case 38:
#line 335 "expresiones.y"
                                                {if(ejecutar){
							if(!errorSemantico){
								if((yyvsp[-1].c_expresion).esReal){
									if(tabla.buscar((yyvsp[-3].c_cadena), dato, pos)){
										if(dato.tipo == 1){
											dato.valor.valor_real = (yyvsp[-1].c_expresion).valor;
											if(!tabla.modificar(pos, dato.valor)){
												cout<< "Error al modificar" << endl;
											}
										}
										else if(dato.tipo == 0){
											cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo entero y recibe un real" 										<< endl;
											errorSemantico=true;
										}
										else if(dato.tipo == 2){
											cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo logico y recibe un real" 										<< endl;
											errorSemantico=true;
										}
									}
									else{
										cout<< "Error semántico en la instrucción "<< n_lineas << ": la variable "<< (yyvsp[-3].c_cadena) << " no existe" << endl; 
		       							errorSemantico=true;
									}
								}
								else{
									if(tabla.buscar((yyvsp[-3].c_cadena), dato, pos)){
										if(dato.tipo == 0){
											dato.valor.valor_entero = (yyvsp[-1].c_expresion).valor;
											if(!tabla.modificar(pos, dato.valor)){
												cout<< "Error al modificar" << endl;
											}
										}
										else if(dato.tipo == 1){
											cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo real y recibe un entero" 										<< endl;
											errorSemantico=true;
										}
										else if(dato.tipo == 2){
											cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo logico y recibe un entero" 									<< endl;
											errorSemantico=true;
										}
									}
									else{
										cout<< "Error semántico en la instrucción "<< n_lineas << ": la variable "<< (yyvsp[-3].c_cadena) << " no existe" << endl; 
		       							errorSemantico=true;
									} 
								}
						}
						errorSemantico=false;
					}
					
					}
#line 1917 "expresiones.c"
    break;

  case 39:
#line 386 "expresiones.y"
                                                                        {if(ejecutar){
										if(tabla.buscar((yyvsp[-6].c_cadena), dato, pos)){
											if(strcmp(dato.nomLista, (yyvsp[-2].c_cadena))==0){
												tipo_datoLista valorLista; 
												if(list.encontrarLista((yyvsp[-2].c_cadena), valorLista)){
													if(valorLista.tipo == 0)
														dato.valor.valor_entero=valorLista.datos[0].valor_entero;
													else if(valorLista.tipo == 1)
														dato.valor.valor_real=valorLista.datos[0].valor_real;
													else if(valorLista.tipo == 2)
														dato.valor.valor_bool=valorLista.datos[0].valor_bool;
													else 
														strcpy(dato.valor.valor_iden, valorLista.datos[0].valor_iden);
													tabla.modificar(pos, dato.valor);
												}
											}
										}
									}
									
									}
#line 1942 "expresiones.c"
    break;

  case 40:
#line 406 "expresiones.y"
                                                                        {if(ejecutar){
										if(tabla.buscar((yyvsp[-6].c_cadena), dato, pos)){
											if(strcmp(dato.nomLista, (yyvsp[-2].c_cadena))==0){
												tipo_datoLista valorLista;
												if(list.encontrarLista((yyvsp[-2].c_cadena), valorLista)){
													if(valorLista.tipo == 0)
														dato.valor.valor_entero=valorLista.datos[valorLista.numDatos-1].valor_entero;
													else if(valorLista.tipo == 1)
														dato.valor.valor_real=valorLista.datos[valorLista.numDatos-1].valor_real;
													else if(valorLista.tipo == 2)
														dato.valor.valor_bool=valorLista.datos[valorLista.numDatos-1].valor_bool;
													else 
														strcpy(dato.valor.valor_iden, valorLista.datos[valorLista.numDatos-1].valor_iden);
													tabla.modificar(pos, dato.valor);
												}
											}
										}
									}
							
									}
#line 1967 "expresiones.c"
    break;

  case 41:
#line 426 "expresiones.y"
                                                                        {if(ejecutar){
											if(tabla.buscar((yyvsp[-8].c_cadena), dato, pos)){
												if(strcmp(dato.nomLista, (yyvsp[-4].c_cadena))==0){
													tipo_datoLista valorLista;
													if(list.encontrarLista((yyvsp[-4].c_cadena), valorLista)){
														if(valorLista.tipo == 0)
															dato.valor.valor_entero=valorLista.datos[int((yyvsp[-2].c_expresion).valor)-1].valor_entero;
														else if(valorLista.tipo == 1)
															dato.valor.valor_real=valorLista.datos[int((yyvsp[-2].c_expresion).valor)-1].valor_real;
														else if(valorLista.tipo == 2)
															dato.valor.valor_bool=valorLista.datos[int((yyvsp[-2].c_expresion).valor)-1].valor_bool;
														else 
															strcpy(dato.valor.valor_iden, valorLista.datos[int((yyvsp[-2].c_expresion).valor)-1].valor_iden);
														tabla.modificar(pos, dato.valor);
													}
												}
											}
										}
										
										}
#line 1992 "expresiones.c"
    break;

  case 43:
#line 447 "expresiones.y"
                                        {if(ejecutar){
						fprintf(yyout, "cout << endl;\n");
					}
					
					}
#line 2002 "expresiones.c"
    break;

  case 44:
#line 452 "expresiones.y"
                                                        {if(ejecutar){
								if(!errorSemantico){
									if(tabla.buscar((yyvsp[-3].c_cadena), dato, pos)){
										if(dato.tipo == 2){
											dato.valor.valor_bool = (yyvsp[-1].c_bool);
											if(!tabla.modificar(pos, dato.valor)){
												cout<< "Error al modificar" << endl;
											}
										}
										else if(dato.tipo == 0){
											cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo entero y recibe un logico" 									<< endl;
											errorSemantico=true;
										}
										else if(dato.tipo == 1){
											cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo real y recibe un logico" 										<< endl;
											errorSemantico=true;
										}
									}
									else{
										cout<< "Error semántico en la instrucción "<< n_lineas << ": la variable "<< (yyvsp[-3].c_cadena) << " no existe" << endl; 
		       							errorSemantico=true;
										}
								}	
								errorSemantico=false;
							}
							
							}
#line 2034 "expresiones.c"
    break;

  case 45:
#line 480 "expresiones.y"
                                                        {if(ejecutar){
								if(!errorSemantico){
									if((yyvsp[-1].c_expresion).esReal){
										if(tabla.buscar((yyvsp[-3].c_cadena), dato, pos)){
											if(dato.tipo == 1){
												dato.valor.valor_real = (yyvsp[-1].c_expresion).valor;
												if(!tabla.modificar(pos, dato.valor)){
													cout<< "Error al modificar" << endl;
												}
											}
											else if(dato.tipo == 0){
												cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo entero y recibe un real" 										<< endl;
												errorSemantico=true;
											}
											else if(dato.tipo == 2){
												cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo logico y recibe un real" 										<< endl;
												errorSemantico=true;
											}
										}
										else{
											cout<< "Error semántico en la instrucción "<< n_lineas << ": la variable "<< (yyvsp[-3].c_cadena) << " no existe" << endl; 
			       							errorSemantico=true;
										}
									}
									else{
										if(tabla.buscar((yyvsp[-3].c_cadena), dato, pos)){
											if(dato.tipo == 0){
												dato.valor.valor_entero = (yyvsp[-1].c_expresion).valor;
												if(!tabla.modificar(pos, dato.valor)){
													cout<< "Error al modificar" << endl;
												}
											}
											else if(dato.tipo == 1){
												cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo real y recibe un entero" 										<< endl;
												errorSemantico=true;
											}
											else if(dato.tipo == 2){
												cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo logico y recibe un entero" 									<< endl;
												errorSemantico=true;
											}
										}
										else{
											cout<< "Error semántico en la instrucción "<< n_lineas << ": la variable "<< (yyvsp[-3].c_cadena) << " no existe" << endl; 
			       							errorSemantico=true;
										} 
									}
								}
								errorSemantico=false;
							}
							
							}
#line 2090 "expresiones.c"
    break;

  case 46:
#line 531 "expresiones.y"
                                                                                {if(ejecutar){
												if(tabla.buscar((yyvsp[-6].c_cadena), dato, pos)){
													if(strcmp(dato.nomLista, (yyvsp[-2].c_cadena))==0){
														tipo_datoLista valorLista;
														if(list.encontrarLista((yyvsp[-2].c_cadena), valorLista)){
															if(valorLista.tipo == 0)
																dato.valor.valor_entero=valorLista.datos[0].valor_entero;
															else if(valorLista.tipo == 1)
																dato.valor.valor_real=valorLista.datos[0].valor_real;
															else if(valorLista.tipo == 2)
																dato.valor.valor_bool=valorLista.datos[0].valor_bool;
															else 
																strcpy(dato.valor.valor_iden, valorLista.datos[0].valor_iden);
															tabla.modificar(pos, dato.valor);
														}
													}
												}
											}
											
											}
#line 2115 "expresiones.c"
    break;

  case 47:
#line 552 "expresiones.y"
                                                                                {if(ejecutar){
												if(tabla.buscar((yyvsp[-6].c_cadena), dato, pos)){
													if(strcmp(dato.nomLista, (yyvsp[-2].c_cadena))==0){
														tipo_datoLista valorLista;
														if(list.encontrarLista((yyvsp[-2].c_cadena), valorLista)){
															if(valorLista.tipo == 0)
																dato.valor.valor_entero=valorLista.datos[valorLista.numDatos-1].valor_entero;
															else if(valorLista.tipo == 1)
																dato.valor.valor_real=valorLista.datos[valorLista.numDatos-1].valor_real;
															else if(valorLista.tipo == 2)
																dato.valor.valor_bool=valorLista.datos[valorLista.numDatos-1].valor_bool;
															else 
																strcpy(dato.valor.valor_iden, valorLista.datos[valorLista.numDatos-1].valor_iden);
															tabla.modificar(pos, dato.valor);
														}
													}
												}
											}
											
											}
#line 2140 "expresiones.c"
    break;

  case 48:
#line 572 "expresiones.y"
                                                                                        {if(ejecutar){
												if(tabla.buscar((yyvsp[-8].c_cadena), dato, pos)){
													if(strcmp(dato.nomLista, (yyvsp[-4].c_cadena))==0){
														tipo_datoLista valorLista;
														if(list.encontrarLista((yyvsp[-4].c_cadena), valorLista)){
															if(valorLista.tipo == 0)
																dato.valor.valor_entero=valorLista.datos[int((yyvsp[-2].c_expresion).valor)-1].valor_entero;
															else if(valorLista.tipo == 1)
																dato.valor.valor_real=valorLista.datos[int((yyvsp[-2].c_expresion).valor)-1].valor_real;
															else if(valorLista.tipo == 2)
																dato.valor.valor_bool=valorLista.datos[int((yyvsp[-2].c_expresion).valor)-1].valor_bool;
															else 
																strcpy(dato.valor.valor_iden, valorLista.datos[int((yyvsp[-2].c_expresion).valor)-1].valor_iden);
															tabla.modificar(pos, dato.valor);
														}
													}
												}
											}
											
											}
#line 2165 "expresiones.c"
    break;

  case 50:
#line 593 "expresiones.y"
                                                {if(ejecutar){
							fprintf(yyout, "cout << endl;\n");
						}
						
						}
#line 2175 "expresiones.c"
    break;

  case 51:
#line 599 "expresiones.y"
                                        {if(!errorSemantico){
						if(contLis == 0){
							if((yyvsp[0].c_expresion).esReal){
								datosLis.tipo = 1;
								datosLis.datos[contLis].valor_real = (yyvsp[0].c_expresion).valor;
								contLis++;
							}
							else{
								datosLis.tipo = 0;
								datosLis.datos[contLis].valor_entero = (yyvsp[0].c_expresion).valor;
								contLis++;
							}
						}
						else{
							if(datosLis.tipo == 0){
								if((yyvsp[0].c_expresion).esReal){
									cout<< "Error semántico en la instrucción "<< n_lineas << ": no se pueden introducir elementos de distinto tipo del de la lista" 										<< endl; 	
       								errorSemantico=true;
								}
								else{
									datosLis.datos[contLis].valor_entero = (yyvsp[0].c_expresion).valor;
									contLis++;
								}
							}
							else if(datosLis.tipo==1){
								if(!(yyvsp[0].c_expresion).esReal){
									cout<< "Error semántico en la instrucción "<< n_lineas << ": no se pueden introducir elementos de distinto tipo del de la lista" 										<< endl; 	
       								errorSemantico=true;
								}
								else{
									datosLis.datos[contLis].valor_real = (yyvsp[0].c_expresion).valor;
									contLis++;
								}
							}
						}
					}
					}
#line 2217 "expresiones.c"
    break;

  case 52:
#line 636 "expresiones.y"
                                        {if(!errorSemantico){
						if(contLis == 0){
							if((yyvsp[0].c_expresion).esReal){
								datosLis.tipo = 1;
								datosLis.datos[contLis].valor_real = (yyvsp[0].c_expresion).valor;
								contLis++;
							}
							else{
								datosLis.tipo = 0;
								datosLis.datos[contLis].valor_entero = (yyvsp[0].c_expresion).valor;
								contLis++;
							}
						}
						else{
							if(datosLis.tipo == 0){
								if((yyvsp[0].c_expresion).esReal){
									cout<< "Error semántico en la instrucción "<< n_lineas << ": no se pueden introducir elementos de distinto tipo del de la lista" 										<< endl; 	
       								errorSemantico=true;
								}
								else{
									datosLis.datos[contLis].valor_entero = (yyvsp[0].c_expresion).valor;
									contLis++;
								}
							}
							else if(datosLis.tipo==1){
								if(!(yyvsp[0].c_expresion).esReal){
									cout<< "Error semántico en la instrucción "<< n_lineas << ": no se pueden introducir elementos de distinto tipo del de la lista" 										<< endl; 	
       								errorSemantico=true;
								}
								else{
									datosLis.datos[contLis].valor_real = (yyvsp[0].c_expresion).valor;
									contLis++;
								}
							}
						}
					}
					}
#line 2259 "expresiones.c"
    break;

  case 53:
#line 674 "expresiones.y"
                                        {if(!errorSemantico){
						datosLis.datos[contLis].valor_bool = (yyvsp[0].c_bool);
						contLis++;
					}
					}
#line 2269 "expresiones.c"
    break;

  case 54:
#line 679 "expresiones.y"
                                        {if(!errorSemantico){
						datosLis.datos[contLis].valor_bool = (yyvsp[0].c_bool);
						contLis++;
					}}
#line 2278 "expresiones.c"
    break;

  case 55:
#line 684 "expresiones.y"
                                        {if(ejecutar){
						if(!errorSemantico){
							if(tabla.buscar((yyvsp[0].c_cadena), dato, pos)){
								if(dato.tipo == 0)
									
									fprintf(yyout, "%s %d %s", "cout <<", dato.valor.valor_entero , ";\n");
								else if(dato.tipo == 1)
									fprintf(yyout, "%s %f %s", "cout <<", dato.valor.valor_real , ";\n");
								else if(dato.tipo == 2){
									if(dato.valor.valor_bool)
										fprintf(yyout, "cout << true;\n");
									else
										fprintf(yyout, "cout << false;\n");
								}
								else
									fprintf(yyout, "%s %s %s", "cout <<", dato.valor.valor_iden , ";\n");
							}
							else{
	       						cout<< "Error semántico en la instrucción "<< n_lineas << ": la variable "<< (yyvsp[0].c_cadena) << " no existe" << endl; 
	       						errorSemantico=true;
	       					}
						}
					}
					
					}
#line 2308 "expresiones.c"
    break;

  case 56:
#line 709 "expresiones.y"
                                        {if(ejecutar){
						if(!errorSemantico){
							if((yyvsp[0].c_expresion).esReal)
								fprintf(yyout, "%s %f %s", "cout <<", (yyvsp[0].c_expresion).valor, ";\n");
							else
								fprintf(yyout, "%s %d %s", "cout <<", int((yyvsp[0].c_expresion).valor), ";\n");
						}
					}
					
					}
#line 2323 "expresiones.c"
    break;

  case 57:
#line 719 "expresiones.y"
                                        {if(ejecutar){
						if(!errorSemantico){
							fprintf(yyout, "%s %s %s", "cout <<", (yyvsp[0].c_texto), ";\n");
						}
					}
					
					}
#line 2335 "expresiones.c"
    break;

  case 58:
#line 727 "expresiones.y"
                                        {if(ejecutar){
						tipo_datoLista valorLista;
						if(list.encontrarLista((yyvsp[-1].c_cadena), valorLista)){
							if(valorLista.tipo == 0)
								fprintf(yyout, "%s %d %s", "cout <<", valorLista.datos[0].valor_entero , ";\n");
							else if(valorLista.tipo == 1)
								fprintf(yyout, "%s %f %s", "cout <<", valorLista.datos[0].valor_real , ";\n");
							else if(valorLista.tipo == 2){
								if(valorLista.datos[0].valor_bool)
									fprintf(yyout, "cout << true;\n");
								else
									fprintf(yyout, "cout << false;\n");
							}
							else 
								fprintf(yyout, "%s %s %s", "cout <<", valorLista.datos[0].valor_iden , ";\n");
						}
					}
					
					}
#line 2359 "expresiones.c"
    break;

  case 59:
#line 746 "expresiones.y"
                                        {if(ejecutar){
						tipo_datoLista valorLista;
						if(list.encontrarLista((yyvsp[-1].c_cadena), valorLista)){
							if(valorLista.tipo == 0)
								fprintf(yyout, "%s %d %s", "cout <<", valorLista.datos[valorLista.numDatos-1].valor_entero , ";\n");
							else if(valorLista.tipo == 1)
								fprintf(yyout, "%s %f %s", "cout <<", valorLista.datos[valorLista.numDatos-1].valor_real , ";\n");
							else if(valorLista.tipo == 2){
								if(valorLista.datos[valorLista.numDatos-1].valor_bool)
									fprintf(yyout, "cout << true;\n");
								else
									fprintf(yyout, "cout << false;\n");
							}
							else 
								fprintf(yyout, "%s %s %s", "cout <<", valorLista.datos[valorLista.numDatos-1].valor_iden , ";\n");
						}
					}
					
					}
#line 2383 "expresiones.c"
    break;

  case 60:
#line 766 "expresiones.y"
                                                {if(ejecutar){
							tipo_datoLista valorLista;
							if(list.encontrarLista((yyvsp[-3].c_cadena), valorLista)){
								if(valorLista.tipo == 0)
									fprintf(yyout, "%s %d %s", "cout <<", valorLista.datos[int((yyvsp[-1].c_expresion).valor)-1].valor_entero , ";\n");
								else if(valorLista.tipo == 1)
									cout<<"cout << " << valorLista.datos[int((yyvsp[-1].c_expresion).valor)-1].valor_real <<endl;
								else if(valorLista.tipo == 2){
									if(valorLista.datos[int((yyvsp[-1].c_expresion).valor-1)].valor_bool)
										
										fprintf(yyout, "cout << true;\n");
									else
										
										fprintf(yyout, "cout << false;\n");
								}
								else 
									fprintf(yyout, "%s %s %s", "cout <<", valorLista.datos[int((yyvsp[-1].c_expresion).valor)-1].valor_iden , ";\n");
							}
						}
						
						}
#line 2409 "expresiones.c"
    break;

  case 61:
#line 788 "expresiones.y"
                                                        {if(ejecutar){
								if(!errorSemantico){
									if(tabla.buscar((yyvsp[0].c_cadena), dato, pos)){
										if(dato.tipo == 0)
											fprintf(yyout, "%s %d %s", "cout <<", dato.valor.valor_entero , ";\n");
										else if(dato.tipo == 1)
											fprintf(yyout, "%s %f %s", "cout <<", dato.valor.valor_real , ";\n");
										else if(dato.tipo == 2){
											if(dato.valor.valor_bool)
												fprintf(yyout, "cout << true;\n");
											else
												fprintf(yyout, "cout << false;\n");
										}
										else
											fprintf(yyout, "%s %s %s", "cout <<", dato.valor.valor_iden , ";\n");
									}
									else{
			       						cout<< "Error semántico en la instrucción "<< n_lineas << ": la variable "<< (yyvsp[0].c_cadena) << " no existe" << endl; 
			       						errorSemantico=true;
			       					}
								}
							}
							
							}
#line 2438 "expresiones.c"
    break;

  case 62:
#line 813 "expresiones.y"
                                                        {if(ejecutar){
								if(!errorSemantico){
									if((yyvsp[0].c_expresion).esReal)
										fprintf(yyout, "%s %f %s", "cout <<", (yyvsp[0].c_expresion).valor, ";\n");
									else
										fprintf(yyout, "%s %d %s", "cout <<", int((yyvsp[0].c_expresion).valor), ";\n");
								}
							}
							
							}
#line 2453 "expresiones.c"
    break;

  case 63:
#line 824 "expresiones.y"
                                                {if(ejecutar){
								if(!errorSemantico){
									fprintf(yyout, "%s %s %s", "cout <<", (yyvsp[0].c_texto), ";\n");
								}
							}
							
							}
#line 2465 "expresiones.c"
    break;

  case 64:
#line 832 "expresiones.y"
                                                        {if(ejecutar){
								tipo_datoLista valorLista;
								if(list.encontrarLista((yyvsp[-1].c_cadena), valorLista)){
									if(valorLista.tipo == 0)
										fprintf(yyout, "%s %d %s", "cout <<", valorLista.datos[0].valor_entero , ";\n");
									else if(valorLista.tipo == 1)
										fprintf(yyout, "%s %f %s", "cout <<", valorLista.datos[0].valor_real , ";\n");
									else if(valorLista.tipo == 2){
										if(valorLista.datos[0].valor_bool)
											fprintf(yyout, "cout << true;\n");
										else
											fprintf(yyout, "cout << false;\n");
									}
									else 
										fprintf(yyout, "%s %s %s", "cout <<", valorLista.datos[0].valor_iden , ";\n");
								}
							}
							
							}
#line 2489 "expresiones.c"
    break;

  case 65:
#line 852 "expresiones.y"
                                                        {if(ejecutar){
								tipo_datoLista valorLista;
								if(list.encontrarLista((yyvsp[-1].c_cadena), valorLista)){
									if(valorLista.tipo == 0)
										fprintf(yyout, "%s %d %s", "cout <<", valorLista.datos[valorLista.numDatos-1].valor_entero, ";\n");
									else if(valorLista.tipo == 1)
										fprintf(yyout, "%s %f %s", "cout <<", valorLista.datos[valorLista.numDatos-1].valor_real, ";\n");
									else if(valorLista.tipo == 2){
										if(valorLista.datos[valorLista.numDatos-1].valor_bool)
											fprintf(yyout, "cout << true;\n");
										else
											fprintf(yyout, "cout << false;\n");
									}
									else 
										fprintf(yyout, "%s %s %s", "cout <<", valorLista.datos[valorLista.numDatos-1].valor_iden, ";\n");
								}
							}
							
							}
#line 2513 "expresiones.c"
    break;

  case 66:
#line 872 "expresiones.y"
                                                                {if(ejecutar){
										tipo_datoLista valorLista;
										if(list.encontrarLista((yyvsp[-3].c_cadena), valorLista)){
											if(valorLista.tipo == 0)
												fprintf(yyout, "%s %d %s", "cout <<", valorLista.datos[int((yyvsp[-1].c_expresion).valor)-1].valor_entero, ";\n");
											else if(valorLista.tipo == 1)
												fprintf(yyout, "%s %f %s", "cout <<", valorLista.datos[int((yyvsp[-1].c_expresion).valor)-1].valor_real, ";\n");
											else if(valorLista.tipo == 2){
												if(valorLista.datos[int((yyvsp[-1].c_expresion).valor-1)].valor_bool)
													fprintf(yyout, "cout << true;\n");
												else
													fprintf(yyout, "cout << false;\n");
											}
											else 
												fprintf(yyout, "%s %s %s", "cout <<", valorLista.datos[int((yyvsp[-1].c_expresion).valor)-1].valor_iden, ";\n");
										}
									}
									
									}
#line 2537 "expresiones.c"
    break;

  case 67:
#line 892 "expresiones.y"
                                {(yyval.c_expresion).valor=(yyvsp[0].c_entero);
					(yyval.c_expresion).esReal=false;}
#line 2544 "expresiones.c"
    break;

  case 68:
#line 894 "expresiones.y"
                                {(yyval.c_expresion).valor=(yyvsp[0].c_float);
       				(yyval.c_expresion).esReal=true;}
#line 2551 "expresiones.c"
    break;

  case 69:
#line 896 "expresiones.y"
                                        {if(tabla.buscar((yyvsp[0].c_cadena), dato, pos)){
       					if(dato.tipo == 0){
       						(yyval.c_expresion).valor = dato.valor.valor_entero;
       						(yyval.c_expresion).esReal = false;
       					}
       					else if(dato.tipo == 1){
       						(yyval.c_expresion).valor = dato.valor.valor_real;
       						(yyval.c_expresion).esReal = true;
       					}
       					else{
       						cout<< "Error semántico en la instrucción "<< n_lineas << ": no se permiten variables de tipo lógico a la derecha de la igualdad" << endl; 
       						errorSemantico=true;
       					}
       				}
       				else{
       					cout<< "Error semántico en la instrucción "<< n_lineas << ": la variable "<< (yyvsp[0].c_cadena) << " no existe" << endl; 
       					errorSemantico=true;
       				}
       				}
#line 2575 "expresiones.c"
    break;

  case 70:
#line 915 "expresiones.y"
                                        {(yyval.c_expresion).valor=(yyvsp[-2].c_expresion).valor+(yyvsp[0].c_expresion).valor;
       				(yyval.c_expresion).esReal=(yyvsp[-2].c_expresion).esReal||(yyvsp[0].c_expresion).esReal;}
#line 2582 "expresiones.c"
    break;

  case 71:
#line 917 "expresiones.y"
                                        {(yyval.c_expresion).valor=(yyvsp[-2].c_expresion).valor-(yyvsp[0].c_expresion).valor;
       				(yyval.c_expresion).esReal=(yyvsp[-2].c_expresion).esReal||(yyvsp[0].c_expresion).esReal;}
#line 2589 "expresiones.c"
    break;

  case 72:
#line 919 "expresiones.y"
                                        {(yyval.c_expresion).valor=(yyvsp[-2].c_expresion).valor*(yyvsp[0].c_expresion).valor;
       				(yyval.c_expresion).esReal=(yyvsp[-2].c_expresion).esReal||(yyvsp[0].c_expresion).esReal;}
#line 2596 "expresiones.c"
    break;

  case 73:
#line 921 "expresiones.y"
                                        {(yyval.c_expresion).esReal=(yyvsp[-2].c_expresion).esReal||(yyvsp[0].c_expresion).esReal;
       				if((yyvsp[0].c_expresion).valor!=0){
       					if((yyval.c_expresion).esReal)
       						(yyval.c_expresion).valor=(yyvsp[-2].c_expresion).valor/(yyvsp[0].c_expresion).valor;
       					else
       						(yyval.c_expresion).valor=int((yyvsp[-2].c_expresion).valor)/int((yyvsp[0].c_expresion).valor);
       				}
       				else{
       					cout<< "Error semántico en la instrucción "<< n_lineas << ": división por cero" << endl; 
       					errorSemantico=true;
       				}
       				}
#line 2613 "expresiones.c"
    break;

  case 74:
#line 933 "expresiones.y"
                                        {if((yyvsp[-2].c_expresion).esReal||(yyvsp[0].c_expresion).esReal){
       					cout<< "Error semántico en la instrucción "<< n_lineas << ": se usa la operación % con operandos reales" << endl; 
       					errorSemantico=true;
       				}
       				else{
       					if((yyvsp[0].c_expresion).valor!=0){
       						(yyval.c_expresion).valor=int((yyvsp[-2].c_expresion).valor)%int((yyvsp[0].c_expresion).valor);
       					}
       					else{
       						cout<< "Error semántico en la instrucción "<< n_lineas << ": modulo de division por cero" << endl; 
       						errorSemantico=true;	
       					}
       				}
       				(yyval.c_expresion).esReal=false;}
#line 2632 "expresiones.c"
    break;

  case 75:
#line 947 "expresiones.y"
                                        {(yyval.c_expresion).valor=-(yyvsp[0].c_expresion).valor;
					(yyval.c_expresion).esReal=(yyvsp[0].c_expresion).esReal;}
#line 2639 "expresiones.c"
    break;

  case 76:
#line 949 "expresiones.y"
                                {(yyval.c_expresion).valor=(yyvsp[-1].c_expresion).valor;
					(yyval.c_expresion).esReal=(yyvsp[-1].c_expresion).esReal;}
#line 2646 "expresiones.c"
    break;

  case 77:
#line 952 "expresiones.y"
                                        {(yyval.c_bool)=(yyvsp[0].c_bool);}
#line 2652 "expresiones.c"
    break;

  case 78:
#line 953 "expresiones.y"
                                        {(yyval.c_bool)=(yyvsp[-1].c_bool);}
#line 2658 "expresiones.c"
    break;

  case 79:
#line 954 "expresiones.y"
                                        {(yyval.c_bool)=(yyvsp[-2].c_expresion).valor<(yyvsp[0].c_expresion).valor;}
#line 2664 "expresiones.c"
    break;

  case 80:
#line 955 "expresiones.y"
                                        {(yyval.c_bool)=(yyvsp[-2].c_expresion).valor>(yyvsp[0].c_expresion).valor;}
#line 2670 "expresiones.c"
    break;

  case 81:
#line 956 "expresiones.y"
                                        {(yyval.c_bool)=(yyvsp[-2].c_expresion).valor<=(yyvsp[0].c_expresion).valor;}
#line 2676 "expresiones.c"
    break;

  case 82:
#line 957 "expresiones.y"
                                        {(yyval.c_bool)=(yyvsp[-2].c_expresion).valor>=(yyvsp[0].c_expresion).valor;}
#line 2682 "expresiones.c"
    break;

  case 83:
#line 958 "expresiones.y"
                                        {(yyval.c_bool)=(yyvsp[-2].c_expresion).valor==(yyvsp[0].c_expresion).valor;}
#line 2688 "expresiones.c"
    break;

  case 84:
#line 959 "expresiones.y"
                                        {(yyval.c_bool)=(yyvsp[-2].c_expresion).valor!=(yyvsp[0].c_expresion).valor;}
#line 2694 "expresiones.c"
    break;

  case 85:
#line 960 "expresiones.y"
                                       {(yyval.c_bool)=(yyvsp[-2].c_bool)==(yyvsp[0].c_bool);}
#line 2700 "expresiones.c"
    break;

  case 86:
#line 961 "expresiones.y"
                                        {(yyval.c_bool)=(yyvsp[-2].c_bool)!=(yyvsp[0].c_bool);}
#line 2706 "expresiones.c"
    break;

  case 87:
#line 962 "expresiones.y"
                                        {(yyval.c_bool)=(yyvsp[-2].c_bool)&&(yyvsp[0].c_bool);}
#line 2712 "expresiones.c"
    break;

  case 88:
#line 963 "expresiones.y"
                                        {(yyval.c_bool)=(yyvsp[-2].c_bool)||(yyvsp[0].c_bool);}
#line 2718 "expresiones.c"
    break;

  case 89:
#line 964 "expresiones.y"
                                        {(yyval.c_bool)=!(yyvsp[0].c_bool);}
#line 2724 "expresiones.c"
    break;


#line 2728 "expresiones.c"

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
#line 967 "expresiones.y"


int main(int argc, char *argv[]){
     
     n_lineas = 1;
     int i = 0;
     int numDatos = 0;
     tipo_datoTS dato;
     
     yyin = fopen(argv[1],"rt");
     yyout = fopen(argv[2], "wt");
     
     
     fprintf(yyout, "%s %s %s %s","#include <iostream>\n","using namespace std;\n","int main(){\n","\n // Inicio del bloque de código\n");
     yyparse();
      fprintf(yyout, "%s %s %s ","// Final del bloque de código\n","\nreturn 0;\n","}\n");
     	
     fclose(yyin);
     fclose(yyout);
     return 0;
}
