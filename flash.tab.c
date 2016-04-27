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
#line 1 "flash.y" /* yacc.c:339  */
/*************************************************************************
Compiler for the Simple language
***************************************************************************/
/*=========================================================================
C Libraries, Symbol Table, Code Generator & other C code
=========================================================================*/
#include <stdio.h>
/* For I/O																*/
#include <stdlib.h>

/* For malloc here and in symbol table									*/
#include <string.h>
/* For strcmp in symbol table											*/
#include "ST.h"
/* Symbol Table															*/
#include "SM.h"
/* Stack Machine														*/
#include "CG.h"
/* Code Generator														*/
#define YYDEBUG 1
/* For Debugging														*/
int errors;
/* Error Count*/
/*-------------------------------------------------------------------------
				The following support backpatching
-------------------------------------------------------------------------*/
int block_offset = 0;
int block_in()
{
 return block_offset++;
}
int block_out()
{
 return block_offset++;
}
struct lbs
/* Labels for data, if and while*/
{
	int for_goto;
	int for_jmp_false;
};
struct lbs * newlblrec() /*      Allocate space for the labels			*/
{
	return (struct lbs *) malloc(sizeof(struct lbs));
}
/*-------------------------------------------------------------------------
				Install identifier & check if previously defined.
-------------------------------------------------------------------------*/
install ( char *sym_name ,int type, int block)
{
	symrec *s;
	s = getsym (sym_name);
	if (s == 0) {
		s = putsym (sym_name,type, block);
	}
	else if (s->block_offset != block){
		s = putsym (sym_name,type, block);
	}
	else { errors++;
		printf( "%s is already defined\n", sym_name );
	}
}
/*-------------------------------------------------------------------------
				If identifier is defined, generate code
-------------------------------------------------------------------------*/
context_check( enum code_ops operation, char *sym_name ,int type)
{   symrec *identifier;
	identifier = getsym( sym_name );
	if ( identifier == 0 ) { 
		errors++;
		printf( "%s", sym_name );
		printf( "%s\n", " is an undeclared identifier" );
		}
	else if (type != -1 && identifier->type != type) {
		printf( "%s", sym_name );
		printf( "%s\n", " type error!" );
		}
	else gen_code( operation, identifier->offset );
}

context_check_fun( enum code_ops operation, char *sym_name ,int type)		
{   symrec *identifier;		
	identifier = getsym( sym_name );		
	if ( identifier == 0 ) { 		
		errors++;		
		printf( "%s", sym_name );		
		printf( "%s\n", " is an undeclared identifier" );		
		}		
	else if (type != -1 && identifier->type != type) {		
		printf( "%s", sym_name );		
		printf( "%s\n", " type error!" );		
		}		
	else gen_fun( operation, identifier->name );		
}
/*=========================================================================
							SEMANTIC RECORDS
=========================================================================*/

#line 165 "flash.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "flash.tab.h".  */
#ifndef YY_YY_FLASH_TAB_H_INCLUDED
# define YY_YY_FLASH_TAB_H_INCLUDED
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
    STRING = 258,
    BOOLEAN = 259,
    NUMBER = 260,
    IDENTIFIER = 261,
    IF = 262,
    WHILE = 263,
    SKIP = 264,
    THEN = 265,
    ELSE = 266,
    FI = 267,
    DO = 268,
    END = 269,
    INTEGER = 270,
    READ = 271,
    WRITE = 272,
    LET = 273,
    IN = 274,
    BOOLE = 275,
    STR = 276,
    STACK = 277,
    ASSGNOP = 278,
    LEQ = 279,
    GEQ = 280,
    ONTO = 281,
    OUTFROM = 282,
    FUN = 283,
    END_FUN = 284,
    RETURN = 285,
    CALL = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
#line 99 "flash.y" /* yacc.c:355  */
union semrec
{
#line 100 "flash.y" /* yacc.c:355  */

int	intval;								/* Integer value */
char *id;								/* Identifiers	*/
struct lbs *lbls;						/* For backpatching	*/
char *boolval;	
char *strval;						

#line 245 "flash.tab.c" /* yacc.c:355  */
};
#line 99 "flash.y" /* yacc.c:355  */
typedef union semrec YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_FLASH_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 262 "flash.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   245

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    43,     2,     2,     2,     2,
      38,    39,    34,    33,    40,    32,    46,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
      41,    45,    42,     2,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    36,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   133,   133,   130,   137,   138,   140,   141,   142,   143,
     144,   146,   147,   149,   149,   155,   156,   158,   159,   160,
     161,   163,   164,   166,   167,   170,   171,   173,   174,   176,
     177,   179,   180,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   198,   199,
     196,   205,   209,   205,   217,   219,   220,   217,   226,   230,
     226,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   253,   254,   256,   257,   258
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "BOOLEAN", "NUMBER",
  "IDENTIFIER", "IF", "WHILE", "SKIP", "THEN", "ELSE", "FI", "DO", "END",
  "INTEGER", "READ", "WRITE", "LET", "IN", "BOOLE", "STR", "STACK",
  "ASSGNOP", "LEQ", "GEQ", "ONTO", "OUTFROM", "FUN", "END_FUN", "RETURN",
  "CALL", "'-'", "'+'", "'*'", "'/'", "'^'", "';'", "'('", "')'", "','",
  "'<'", "'>'", "'#'", "'@'", "'='", "'.'", "$accept", "program", "$@1",
  "declaration", "declarations", "functions", "fun", "$@2", "parameter",
  "parameters", "arguments", "argument", "id_seqi", "id_seqb", "id_seqs",
  "commands", "command", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9",
  "$@10", "$@11", "$@12", "exp_int", "exp_bol", "exp_str", YY_NULLPTR
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
     285,   286,    45,    43,    42,    47,    94,    59,    40,    41,
      44,    60,    62,    35,    64,    61,    46
};
# endif

#define YYPACT_NINF -63

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-63)))

#define YYTABLE_NINF -78

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -12,   -63,    30,    13,   -63,   -63,   -63,   -63,   -63,     7,
     -63,    51,    25,    52,    67,    40,   -63,    72,   -63,    -8,
      23,    55,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,    58,    46,   -15,    19,    81,   -63,   -63,     8,    12,
      88,    91,    65,   -63,    -2,    66,    76,   -63,   -63,   -63,
      21,   157,   -63,    21,   110,   -63,   109,   113,   -63,   110,
      90,   157,   -63,    86,   -63,     0,   -63,    79,   157,   -63,
      84,    21,    21,   135,    21,    21,    21,    21,    21,    21,
      21,    21,    21,    21,   121,   123,   157,   -63,   -63,   -63,
     -63,   -63,   -63,    84,   136,   -63,   137,   139,   140,   -63,
     -63,    90,   171,   185,   -63,   157,   157,   198,   198,   200,
     200,   200,   157,   157,   157,   -63,   -63,   134,   145,   114,
     146,   124,   129,   138,    13,    84,    21,    21,   148,   148,
     -63,   -63,   -63,   133,   -63,   -63,   -63,    74,   161,   172,
      92,   104,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     120,   132,   -63,   -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,    11,     1,     6,    25,    27,    29,     0,
       5,     0,     0,     0,     0,     0,     2,     0,    12,     0,
       0,     0,    10,    31,    13,     7,    26,     8,    28,     9,
      30,     0,     0,     0,     0,    51,    33,     3,     0,     0,
       0,     0,     0,    15,     0,     0,     0,    74,    61,    62,
       0,    47,    54,     0,     0,    38,     0,     0,    62,     0,
       0,    41,    36,     0,    32,     0,    76,    62,    44,    45,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    75,    59,    39,
      40,    42,    77,    43,    21,    17,     0,     0,     0,     4,
      16,     0,     0,     0,    73,    67,    66,    69,    68,    70,
      71,    72,    63,    65,    64,    31,    31,     0,     0,     0,
       0,     0,     0,     0,    31,    78,    34,    35,    48,    55,
      31,    31,    37,    22,    18,    19,    20,     0,     0,     0,
       0,     0,    24,    14,    49,    56,    53,    60,    31,    31,
       0,     0,    50,    57
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,   -63,    85,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -62,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -34,    17,   -53
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    23,     3,    10,    11,    18,    32,    65,   100,
     119,   120,    12,    13,    14,    31,    42,    84,   138,   148,
      53,   117,    85,   139,   149,    54,   118,   113,    52,    70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    66,    47,    48,    67,    61,     1,    93,    44,    95,
      68,    45,    46,    15,    55,    96,    73,    48,    58,    86,
      97,    98,     5,    47,    48,    49,    48,    58,     6,    25,
       4,    19,    26,     7,     8,     9,    50,   102,   103,    99,
     105,   106,   107,   108,   109,   110,   111,   112,   125,   114,
      50,    56,    57,   128,   129,    59,    60,    50,    20,    50,
      27,    69,   137,    28,    33,    34,    35,    36,   140,   141,
      16,    88,    37,    21,    38,    39,    91,    22,    24,    17,
      33,    34,    35,    36,    43,   -58,   150,   151,    40,    41,
      38,    39,    29,    66,    62,    30,    92,    63,    33,    34,
      35,    36,    64,   143,    40,    41,   146,    71,    38,    39,
      33,    34,    35,    36,    47,    89,    87,    72,   147,    90,
      38,    39,    40,    41,    94,   -77,    33,    34,    35,    36,
     101,   115,   152,   116,    40,    41,    38,    39,    33,    34,
      35,    36,   -23,   121,   153,   122,   123,   130,    38,    39,
      40,    41,   133,   132,    33,    34,    35,    36,   131,    74,
      75,   134,    40,    41,    38,    39,   135,    76,    77,    78,
      79,    80,   144,   142,   104,   136,    81,    82,    40,    41,
      83,    74,    75,   145,   124,     0,     0,     0,     0,    76,
      77,    78,    79,    80,     0,    74,    75,     0,    81,    82,
       0,     0,    83,    76,    77,    78,    79,    80,     0,    74,
      75,     0,    81,   126,     0,     0,    83,    76,    77,    78,
      79,    80,    74,    75,    74,    75,    81,   127,     0,     0,
      83,     0,    78,    79,    80,     0,    80,     0,     0,    81,
      82,    81,    82,    83,     0,    83
};

static const yytype_int16 yycheck[] =
{
      34,     3,     4,     5,     6,    39,    18,    60,    23,     9,
      44,    26,    27,     6,     6,    15,    50,     5,     6,    53,
      20,    21,     9,     4,     5,     6,     5,     6,    15,    37,
       0,     6,    40,    20,    21,    22,    38,    71,    72,    39,
      74,    75,    76,    77,    78,    79,    80,    81,   101,    83,
      38,    43,    44,   115,   116,    43,    44,    38,     6,    38,
      37,    44,   124,    40,     6,     7,     8,     9,   130,   131,
      19,    54,    14,     6,    16,    17,    59,    37,     6,    28,
       6,     7,     8,     9,    38,     4,   148,   149,    30,    31,
      16,    17,    37,     3,     6,    40,     6,     6,     6,     7,
       8,     9,    37,    29,    30,    31,    14,    41,    16,    17,
       6,     7,     8,     9,     4,     6,     6,    41,    14,     6,
      16,    17,    30,    31,    38,    46,     6,     7,     8,     9,
      46,    10,    12,    10,    30,    31,    16,    17,     6,     7,
       8,     9,     6,     6,    12,     6,     6,    13,    16,    17,
      30,    31,     6,    39,     6,     7,     8,     9,    13,    24,
      25,    37,    30,    31,    16,    17,    37,    32,    33,    34,
      35,    36,    11,    40,    39,    37,    41,    42,    30,    31,
      45,    24,    25,    11,    99,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    24,    25,    -1,    41,    42,
      -1,    -1,    45,    32,    33,    34,    35,    36,    -1,    24,
      25,    -1,    41,    42,    -1,    -1,    45,    32,    33,    34,
      35,    36,    24,    25,    24,    25,    41,    42,    -1,    -1,
      45,    -1,    34,    35,    36,    -1,    36,    -1,    -1,    41,
      42,    41,    42,    45,    -1,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    48,    50,     0,     9,    15,    20,    21,    22,
      51,    52,    59,    60,    61,     6,    19,    28,    53,     6,
       6,     6,    37,    49,     6,    37,    40,    37,    40,    37,
      40,    62,    54,     6,     7,     8,     9,    14,    16,    17,
      30,    31,    63,    38,    23,    26,    27,     4,     5,     6,
      38,    74,    75,    67,    72,     6,    43,    44,     6,    43,
      44,    74,     6,     6,    37,    55,     3,     6,    74,    75,
      76,    41,    41,    74,    24,    25,    32,    33,    34,    35,
      36,    41,    42,    45,    64,    69,    74,     6,    75,     6,
       6,    75,     6,    76,    38,     9,    15,    20,    21,    39,
      56,    46,    74,    74,    39,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    10,    10,    68,    73,    57,
      58,     6,     6,     6,    50,    76,    42,    42,    62,    62,
      13,    13,    39,     6,    37,    37,    37,    62,    65,    70,
      62,    62,    40,    29,    11,    11,    14,    14,    66,    71,
      62,    62,    12,    12
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    49,    48,    50,    50,    51,    51,    51,    51,
      51,    52,    52,    54,    53,    55,    55,    56,    56,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    60,    61,
      61,    62,    62,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    64,    65,    66,
      63,    67,    68,    63,    69,    70,    71,    63,    72,    73,
      63,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    75,    75,    76,    76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     7,     0,     2,     1,     4,     4,     4,
       3,     0,     2,     0,     9,     0,     2,     1,     3,     3,
       3,     0,     2,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     1,     5,     5,     2,     5,     2,     3,
       3,     2,     3,     3,     3,     3,     3,     0,     0,     0,
      10,     0,     0,     7,     0,     0,     0,    10,     0,     0,
       7,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     3
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
#line 133 "flash.y" /* yacc.c:1646  */
    {	gen_code( DATA, data_location() - 1 );				}
#line 1460 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 135 "flash.y" /* yacc.c:1646  */
    {	gen_code( HALT, 0 ); YYACCEPT;						}
#line 1466 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 141 "flash.y" /* yacc.c:1646  */
    {	install( (yyvsp[-1].id) , 1, block_offset);  gen_code_bool_str(DEF, "0");}
#line 1472 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 142 "flash.y" /* yacc.c:1646  */
    {	install( (yyvsp[-1].id) , 0, block_offset);  gen_code_bool_str(DEF, "true");}
#line 1478 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 143 "flash.y" /* yacc.c:1646  */
    {	install( (yyvsp[-1].id) , 2, block_offset);  gen_code_bool_str(DEF, "str");}
#line 1484 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 144 "flash.y" /* yacc.c:1646  */
    { install((yyvsp[-1].id), 4, block_offset); gen_code_bool_str(DEF, "stk");  }
#line 1490 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 149 "flash.y" /* yacc.c:1646  */
    { block_in(); gen_fun( FUN_INIT, (yyvsp[0].id)); install((yyvsp[0].id), 3, block_offset); }
#line 1496 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 153 "flash.y" /* yacc.c:1646  */
    { gen_code( FUN_EN, 0); block_out(); }
#line 1502 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 159 "flash.y" /* yacc.c:1646  */
    {	install( (yyvsp[-1].id) , 1, block_offset );context_check(PARA_INT , (yyvsp[-1].id), -1);					}
#line 1508 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 160 "flash.y" /* yacc.c:1646  */
    {	install( (yyvsp[-1].id) , 0, block_offset );context_check(PARA_BOOL , (yyvsp[-1].id), -1);					}
#line 1514 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 161 "flash.y" /* yacc.c:1646  */
    {	install( (yyvsp[-1].id) , 2, block_offset );context_check(PARA_STR , (yyvsp[-1].id), -1);						}
#line 1520 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 164 "flash.y" /* yacc.c:1646  */
    { context_check(PARA_INT , (yyvsp[0].id),-1);				}
#line 1526 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 167 "flash.y" /* yacc.c:1646  */
    {	context_check(PARA_INT , (yyvsp[-1].id),-1);			}
#line 1532 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 171 "flash.y" /* yacc.c:1646  */
    {	install( (yyvsp[-1].id) , 1, block_offset); gen_code_bool_str(DEF, "0");			}
#line 1538 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 174 "flash.y" /* yacc.c:1646  */
    {	install( (yyvsp[-1].id) , 0, block_offset); gen_code_bool_str(DEF, "true");			}
#line 1544 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 177 "flash.y" /* yacc.c:1646  */
    {	install( (yyvsp[-1].id) , 2, block_offset); gen_code_bool_str(DEF, "str");			}
#line 1550 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 183 "flash.y" /* yacc.c:1646  */
    { context_check(ADDSTK, (yyvsp[-4].id), 4);      }
#line 1556 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 184 "flash.y" /* yacc.c:1646  */
    { context_check(REMSTK, (yyvsp[-4].id), 4);      }
#line 1562 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 185 "flash.y" /* yacc.c:1646  */
    { context_check( POP, (yyvsp[0].id) ,-1); 						}
#line 1568 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 186 "flash.y" /* yacc.c:1646  */
    { context_check_fun(FUN_CALL, (yyvsp[-3].id), 3);		}
#line 1574 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 187 "flash.y" /* yacc.c:1646  */
    {    context_check( READ_INT, (yyvsp[0].id) , 1);				}
#line 1580 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 188 "flash.y" /* yacc.c:1646  */
    {    context_check( READ_BOL, (yyvsp[0].id) , 0);			}
#line 1586 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 189 "flash.y" /* yacc.c:1646  */
    {    context_check( READ_STR, (yyvsp[0].id) , 2);			}
#line 1592 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 190 "flash.y" /* yacc.c:1646  */
    {	gen_code( WRITE_INT, 1 );							}
#line 1598 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 191 "flash.y" /* yacc.c:1646  */
    {	gen_code( WRITE_BOL, 0 );						}
#line 1604 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 192 "flash.y" /* yacc.c:1646  */
    {	gen_code( WRITE_STR, 2 );						}
#line 1610 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 193 "flash.y" /* yacc.c:1646  */
    { context_check( STORE, (yyvsp[-2].id) , 1);   		}
#line 1616 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 194 "flash.y" /* yacc.c:1646  */
    { context_check( STORE, (yyvsp[-2].id) , 0);   		}
#line 1622 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 195 "flash.y" /* yacc.c:1646  */
    { context_check( STORE, (yyvsp[-2].id) , 2);   		}
#line 1628 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 196 "flash.y" /* yacc.c:1646  */
    {	(yyvsp[-1].lbls) = (struct lbs *) newlblrec();
					(yyvsp[-1].lbls)->for_jmp_false = reserve_loc(); 					}
#line 1635 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 198 "flash.y" /* yacc.c:1646  */
    { (yyvsp[-4].lbls)->for_goto = reserve_loc(); 					}
#line 1641 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 199 "flash.y" /* yacc.c:1646  */
    { back_patch( (yyvsp[-6].lbls)->for_jmp_false,
							JMP_FALSE,
							gen_label() ); 								}
#line 1649 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 204 "flash.y" /* yacc.c:1646  */
    { back_patch( (yyvsp[-9].lbls)->for_goto, GOTO, gen_label() ); 		}
#line 1655 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 205 "flash.y" /* yacc.c:1646  */
    { (yyvsp[0].lbls) = (struct lbs *) newlblrec();
				  (yyvsp[0].lbls)->for_goto = gen_label(); 							}
#line 1662 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 209 "flash.y" /* yacc.c:1646  */
    { (yyvsp[-2].lbls)->for_jmp_false = reserve_loc();					}
#line 1668 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 213 "flash.y" /* yacc.c:1646  */
    { gen_code( GOTO, (yyvsp[-6].lbls)->for_goto );
				  back_patch( (yyvsp[-6].lbls)->for_jmp_false,
						JMP_FALSE,
						gen_label() );									}
#line 1677 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 217 "flash.y" /* yacc.c:1646  */
    {	(yyvsp[-1].lbls) = (struct lbs *) newlblrec();
					(yyvsp[-1].lbls)->for_jmp_false = reserve_loc(); 					}
#line 1684 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 219 "flash.y" /* yacc.c:1646  */
    { (yyvsp[-4].lbls)->for_goto = reserve_loc(); 					}
#line 1690 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 220 "flash.y" /* yacc.c:1646  */
    { back_patch( (yyvsp[-6].lbls)->for_jmp_false,
							JMP_FALSE,
							gen_label() ); 								}
#line 1698 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 225 "flash.y" /* yacc.c:1646  */
    { back_patch( (yyvsp[-9].lbls)->for_goto, GOTO, gen_label() ); 		}
#line 1704 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 226 "flash.y" /* yacc.c:1646  */
    { (yyvsp[0].lbls) = (struct lbs *) newlblrec();
				  (yyvsp[0].lbls)->for_goto = gen_label(); 							}
#line 1711 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 230 "flash.y" /* yacc.c:1646  */
    { (yyvsp[-2].lbls)->for_jmp_false = reserve_loc();					}
#line 1717 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 234 "flash.y" /* yacc.c:1646  */
    { gen_code( GOTO, (yyvsp[-6].lbls)->for_goto );
				  back_patch( (yyvsp[-6].lbls)->for_jmp_false,
						JMP_FALSE,
						gen_label() );									}
#line 1726 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 239 "flash.y" /* yacc.c:1646  */
    { gen_code( LD_INT, (yyvsp[0].intval) );							}
#line 1732 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 240 "flash.y" /* yacc.c:1646  */
    { context_check( LD_VAR, (yyvsp[0].id) , -1);						}
#line 1738 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 241 "flash.y" /* yacc.c:1646  */
    { gen_code( LT, 0 );								}
#line 1744 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 242 "flash.y" /* yacc.c:1646  */
    { gen_code( EQ, 0 );								}
#line 1750 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 243 "flash.y" /* yacc.c:1646  */
    { gen_code( GT, 0 );								}
#line 1756 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 244 "flash.y" /* yacc.c:1646  */
    { gen_code( GTEQ, 0 );								}
#line 1762 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 245 "flash.y" /* yacc.c:1646  */
    { gen_code( LTEQ, 0 );								}
#line 1768 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 246 "flash.y" /* yacc.c:1646  */
    { gen_code( ADD, 0 );								}
#line 1774 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 247 "flash.y" /* yacc.c:1646  */
    { gen_code( SUB, 0 );								}
#line 1780 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 248 "flash.y" /* yacc.c:1646  */
    { gen_code( MULT, 0 );								}
#line 1786 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 249 "flash.y" /* yacc.c:1646  */
    { gen_code( DIV, 0 );								}
#line 1792 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 250 "flash.y" /* yacc.c:1646  */
    { gen_code( PWR, 0 );								}
#line 1798 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 253 "flash.y" /* yacc.c:1646  */
    { gen_code_bool_str( LD_BOL, (yyvsp[0].boolval) );							}
#line 1804 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 254 "flash.y" /* yacc.c:1646  */
    { context_check( LD_VAR, (yyvsp[0].id) ,-1);							}
#line 1810 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 256 "flash.y" /* yacc.c:1646  */
    { gen_code_bool_str( LD_STR, (yyvsp[0].strval) );							}
#line 1816 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 257 "flash.y" /* yacc.c:1646  */
    { context_check( LD_VAR, (yyvsp[0].id) ,-1);							}
#line 1822 "flash.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 258 "flash.y" /* yacc.c:1646  */
    { gen_code(ADD_STR, 0);								}
#line 1828 "flash.tab.c" /* yacc.c:1646  */
    break;


#line 1832 "flash.tab.c" /* yacc.c:1646  */
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
#line 260 "flash.y" /* yacc.c:1906  */

/*=========================================================================
MAIN
=========================================================================*/
main( int argc, char *argv[] )
{   extern FILE *yyin;
	++argv; --argc;
	
	if (argv[0] == NULL || strstr(argv[0], ".fl") == NULL) {
		printf ( "Input file is not a Flash file \n" );
		exit(1);
	}
	
	yyin = fopen( argv[0], "r" );
	
	/*yydebug = 1;*/
	errors = 0;
	yyparse ();
	printf ( "Parse Completed\n" );
	if ( errors == 0 )
	{	
		char *outFile = malloc(strlen(argv[0])+strlen(".cls")+1);
		strcpy(outFile, argv[0]);
		strcat(outFile, ".cls");
		FILE *fp = fopen(outFile,"w+");
		print_code (fp);
		fclose(fp);
	}
}
/*=========================================================================
YYERROR
=========================================================================*/
yyerror ( char *s ) /* Called by yyparse on error */
{
errors++;
printf ("%s\n", s);
}
/**************************** End Grammar File ***************************/
