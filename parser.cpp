/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"

    #include <cstring>
    #include "../../dom_tree.h"
    #include "parser.hpp"

    extern int yylex();
    extern FILE *yyin;
    void yyerror(const char *s) {
    extern int yylineno; // Declare yylineno here
    fprintf(stderr, "Parse error! Message: %s at line %d\n", s, yylineno);
    exit(-1);
}

    using namespace std;
    DOMNode* root = nullptr;

#line 88 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TEXT = 3,                       /* TEXT  */
  YYSYMBOL_DOCTYPE = 4,                    /* DOCTYPE  */
  YYSYMBOL_HTML_OPEN = 5,                  /* HTML_OPEN  */
  YYSYMBOL_HTML_CLOSE = 6,                 /* HTML_CLOSE  */
  YYSYMBOL_HEAD_OPEN = 7,                  /* HEAD_OPEN  */
  YYSYMBOL_HEAD_CLOSE = 8,                 /* HEAD_CLOSE  */
  YYSYMBOL_TITLE_OPEN = 9,                 /* TITLE_OPEN  */
  YYSYMBOL_TITLE_CLOSE = 10,               /* TITLE_CLOSE  */
  YYSYMBOL_BODY_OPEN = 11,                 /* BODY_OPEN  */
  YYSYMBOL_BODY_CLOSE = 12,                /* BODY_CLOSE  */
  YYSYMBOL_DIV_OPEN = 13,                  /* DIV_OPEN  */
  YYSYMBOL_DIV_CLOSE = 14,                 /* DIV_CLOSE  */
  YYSYMBOL_P_OPEN = 15,                    /* P_OPEN  */
  YYSYMBOL_P_CLOSE = 16,                   /* P_CLOSE  */
  YYSYMBOL_H1_OPEN = 17,                   /* H1_OPEN  */
  YYSYMBOL_H1_CLOSE = 18,                  /* H1_CLOSE  */
  YYSYMBOL_H2_OPEN = 19,                   /* H2_OPEN  */
  YYSYMBOL_H2_CLOSE = 20,                  /* H2_CLOSE  */
  YYSYMBOL_H3_OPEN = 21,                   /* H3_OPEN  */
  YYSYMBOL_H3_CLOSE = 22,                  /* H3_CLOSE  */
  YYSYMBOL_H4_OPEN = 23,                   /* H4_OPEN  */
  YYSYMBOL_H4_CLOSE = 24,                  /* H4_CLOSE  */
  YYSYMBOL_H5_OPEN = 25,                   /* H5_OPEN  */
  YYSYMBOL_H5_CLOSE = 26,                  /* H5_CLOSE  */
  YYSYMBOL_NAV_OPEN = 27,                  /* NAV_OPEN  */
  YYSYMBOL_NAV_CLOSE = 28,                 /* NAV_CLOSE  */
  YYSYMBOL_UL_OPEN = 29,                   /* UL_OPEN  */
  YYSYMBOL_UL_CLOSE = 30,                  /* UL_CLOSE  */
  YYSYMBOL_LI_OPEN = 31,                   /* LI_OPEN  */
  YYSYMBOL_LI_CLOSE = 32,                  /* LI_CLOSE  */
  YYSYMBOL_HEADER_OPEN = 33,               /* HEADER_OPEN  */
  YYSYMBOL_HEADER_CLOSE = 34,              /* HEADER_CLOSE  */
  YYSYMBOL_FOOTER_OPEN = 35,               /* FOOTER_OPEN  */
  YYSYMBOL_FOOTER_CLOSE = 36,              /* FOOTER_CLOSE  */
  YYSYMBOL_SECTION_OPEN = 37,              /* SECTION_OPEN  */
  YYSYMBOL_SECTION_CLOSE = 38,             /* SECTION_CLOSE  */
  YYSYMBOL_ARTICLE_OPEN = 39,              /* ARTICLE_OPEN  */
  YYSYMBOL_ARTICLE_CLOSE = 40,             /* ARTICLE_CLOSE  */
  YYSYMBOL_ASIDE_OPEN = 41,                /* ASIDE_OPEN  */
  YYSYMBOL_ASIDE_CLOSE = 42,               /* ASIDE_CLOSE  */
  YYSYMBOL_OL_OPEN = 43,                   /* OL_OPEN  */
  YYSYMBOL_OL_CLOSE = 44,                  /* OL_CLOSE  */
  YYSYMBOL_A_OPEN = 45,                    /* A_OPEN  */
  YYSYMBOL_A_CLOSE = 46,                   /* A_CLOSE  */
  YYSYMBOL_STRONG_OPEN = 47,               /* STRONG_OPEN  */
  YYSYMBOL_STRONG_CLOSE = 48,              /* STRONG_CLOSE  */
  YYSYMBOL_EM_OPEN = 49,                   /* EM_OPEN  */
  YYSYMBOL_EM_CLOSE = 50,                  /* EM_CLOSE  */
  YYSYMBOL_U_OPEN = 51,                    /* U_OPEN  */
  YYSYMBOL_U_CLOSE = 52,                   /* U_CLOSE  */
  YYSYMBOL_SMALL_OPEN = 53,                /* SMALL_OPEN  */
  YYSYMBOL_SMALL_CLOSE = 54,               /* SMALL_CLOSE  */
  YYSYMBOL_PRE_OPEN = 55,                  /* PRE_OPEN  */
  YYSYMBOL_PRE_CLOSE = 56,                 /* PRE_CLOSE  */
  YYSYMBOL_BLOCKQUOTE_OPEN = 57,           /* BLOCKQUOTE_OPEN  */
  YYSYMBOL_BLOCKQUOTE_CLOSE = 58,          /* BLOCKQUOTE_CLOSE  */
  YYSYMBOL_CODE_OPEN = 59,                 /* CODE_OPEN  */
  YYSYMBOL_CODE_CLOSE = 60,                /* CODE_CLOSE  */
  YYSYMBOL_IMG_TAG = 61,                   /* IMG_TAG  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_start = 63,                     /* start  */
  YYSYMBOL_html = 64,                      /* html  */
  YYSYMBOL_head = 65,                      /* head  */
  YYSYMBOL_title = 66,                     /* title  */
  YYSYMBOL_body = 67,                      /* body  */
  YYSYMBOL_body_content = 68,              /* body_content  */
  YYSYMBOL_paragraph = 69,                 /* paragraph  */
  YYSYMBOL_div = 70,                       /* div  */
  YYSYMBOL_h1 = 71,                        /* h1  */
  YYSYMBOL_h2 = 72,                        /* h2  */
  YYSYMBOL_h3 = 73,                        /* h3  */
  YYSYMBOL_h4 = 74,                        /* h4  */
  YYSYMBOL_h5 = 75,                        /* h5  */
  YYSYMBOL_nav = 76,                       /* nav  */
  YYSYMBOL_header = 77,                    /* header  */
  YYSYMBOL_unordered_list = 78,            /* unordered_list  */
  YYSYMBOL_unordered_list_content = 79,    /* unordered_list_content  */
  YYSYMBOL_list_item = 80,                 /* list_item  */
  YYSYMBOL_section = 81,                   /* section  */
  YYSYMBOL_strong = 82,                    /* strong  */
  YYSYMBOL_em = 83,                        /* em  */
  YYSYMBOL_u = 84,                         /* u  */
  YYSYMBOL_small = 85,                     /* small  */
  YYSYMBOL_blockquote = 86,                /* blockquote  */
  YYSYMBOL_text = 87                       /* text  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  88

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   316


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    74,    85,    95,   102,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   133,   140,   148,   155,   161,   167,
     173,   180,   188,   196,   204,   205,   210,   217,   225,   232,
     239,   246,   253,   261
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TEXT", "DOCTYPE",
  "HTML_OPEN", "HTML_CLOSE", "HEAD_OPEN", "HEAD_CLOSE", "TITLE_OPEN",
  "TITLE_CLOSE", "BODY_OPEN", "BODY_CLOSE", "DIV_OPEN", "DIV_CLOSE",
  "P_OPEN", "P_CLOSE", "H1_OPEN", "H1_CLOSE", "H2_OPEN", "H2_CLOSE",
  "H3_OPEN", "H3_CLOSE", "H4_OPEN", "H4_CLOSE", "H5_OPEN", "H5_CLOSE",
  "NAV_OPEN", "NAV_CLOSE", "UL_OPEN", "UL_CLOSE", "LI_OPEN", "LI_CLOSE",
  "HEADER_OPEN", "HEADER_CLOSE", "FOOTER_OPEN", "FOOTER_CLOSE",
  "SECTION_OPEN", "SECTION_CLOSE", "ARTICLE_OPEN", "ARTICLE_CLOSE",
  "ASIDE_OPEN", "ASIDE_CLOSE", "OL_OPEN", "OL_CLOSE", "A_OPEN", "A_CLOSE",
  "STRONG_OPEN", "STRONG_CLOSE", "EM_OPEN", "EM_CLOSE", "U_OPEN",
  "U_CLOSE", "SMALL_OPEN", "SMALL_CLOSE", "PRE_OPEN", "PRE_CLOSE",
  "BLOCKQUOTE_OPEN", "BLOCKQUOTE_CLOSE", "CODE_OPEN", "CODE_CLOSE",
  "IMG_TAG", "$accept", "start", "html", "head", "title", "body",
  "body_content", "paragraph", "div", "h1", "h2", "h3", "h4", "h5", "nav",
  "header", "unordered_list", "unordered_list_content", "list_item",
  "section", "strong", "em", "u", "small", "blockquote", "text", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-13)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -2,    -1,     6,     1,   -13,   -13,     3,    12,     7,     8,
     -13,    21,     4,   -13,   -12,   -13,   -13,   -13,   -13,    26,
      26,    26,    26,    26,    26,   -13,     0,   -13,   -13,    26,
      26,    26,    26,    26,   -13,   -13,   -13,   -13,   -13,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,
       5,   -13,    17,    18,    20,    24,    23,    22,    36,    26,
      13,   -13,    57,    82,     2,    10,    14,    25,     9,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,   -13,    39,   -13,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     1,     0,     0,     0,     0,
       7,     0,     0,     4,     0,     3,     5,     6,     7,     0,
       0,     0,     0,     0,     0,     7,     0,     7,     7,     0,
       0,     0,     0,     0,     8,    18,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    19,    20,    21,    22,    23,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,    25,
      24,    26,    27,    28,    29,    30,    31,     0,    33,    35,
      32,    37,    38,    39,    40,    41,    42,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -13,   -13,   -13,   -13,   -13,   -13,    98,   -13,   -13,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,    15,   -13,
     -13,   -13,   -13,   -13,   -13,   120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     4,     7,     9,    11,    14,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    60,    61,    44,
      45,    46,    47,    48,    49,    52
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      17,    18,     1,    19,     3,    20,     5,    21,     6,    22,
      12,    23,     8,    24,    16,    25,    13,    26,    18,    69,
      19,    27,    20,    10,    21,    28,    22,    15,    23,    51,
      24,    59,    25,    70,    26,    29,    71,    30,    27,    31,
      72,    32,    28,    78,    59,    33,    73,    74,    75,    18,
      82,    19,    29,    20,    30,    21,    31,    22,    32,    23,
      83,    24,    33,    25,    76,    26,    84,    86,     0,    27,
      18,    87,    19,    28,    20,    79,    21,     0,    22,    85,
      23,     0,    24,    29,    25,    30,    26,    31,     0,    32,
      27,    80,     0,    33,    28,    18,     0,    19,     0,    20,
       0,    21,     0,    22,    29,    23,    30,    24,    31,    25,
      32,    26,     0,     0,    33,    27,    50,     0,     0,    28,
      81,     0,     0,    58,     0,    62,    63,     0,     0,    29,
       0,    30,     0,    31,     0,    32,     0,     0,     0,    33,
      53,    54,    55,    56,    57,     0,     0,     0,     0,    64,
      65,    66,    67,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77
};

static const yytype_int8 yycheck[] =
{
      12,    13,     4,    15,     5,    17,     0,    19,     7,    21,
       3,    23,     9,    25,    10,    27,     8,    29,    13,    14,
      15,    33,    17,    11,    19,    37,    21,     6,    23,     3,
      25,    31,    27,    16,    29,    47,    18,    49,    33,    51,
      20,    53,    37,    30,    31,    57,    22,    24,    26,    13,
      48,    15,    47,    17,    49,    19,    51,    21,    53,    23,
      50,    25,    57,    27,    28,    29,    52,    58,    -1,    33,
      13,    32,    15,    37,    17,    60,    19,    -1,    21,    54,
      23,    -1,    25,    47,    27,    49,    29,    51,    -1,    53,
      33,    34,    -1,    57,    37,    13,    -1,    15,    -1,    17,
      -1,    19,    -1,    21,    47,    23,    49,    25,    51,    27,
      53,    29,    -1,    -1,    57,    33,    18,    -1,    -1,    37,
      38,    -1,    -1,    25,    -1,    27,    28,    -1,    -1,    47,
      -1,    49,    -1,    51,    -1,    53,    -1,    -1,    -1,    57,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    63,     5,    64,     0,     7,    65,     9,    66,
      11,    67,     3,     8,    68,     6,    10,    12,    13,    15,
      17,    19,    21,    23,    25,    27,    29,    33,    37,    47,
      49,    51,    53,    57,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    81,    82,    83,    84,    85,    86,
      68,     3,    87,    87,    87,    87,    87,    87,    68,    31,
      79,    80,    68,    68,    87,    87,    87,    87,    87,    14,
      16,    18,    20,    22,    24,    26,    28,    87,    30,    80,
      34,    38,    48,    50,    52,    54,    58,    32
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    64,    65,    66,    67,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    79,    80,    81,    82,    83,
      84,    85,    86,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     4,     3,     3,     3,     0,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     2,     3,     3,     3,     3,
       3,     3,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* start: DOCTYPE html  */
#line 64 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                 {
        root = new DOMNode(ROOT);
        DOMNodeList* nodeList = new DOMNodeList();
        nodeList->push_back((yyvsp[0].domNode));   // Wrap the single node in a list
        root->appendChildren(*nodeList);
    }
#line 1247 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 3: /* html: HTML_OPEN head body HTML_CLOSE  */
#line 74 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                                   {
        (yyval.domNode) = new DOMNode(HTML);
        DOMNodeList* htmlContent = new DOMNodeList();
        htmlContent->push_back((yyvsp[-2].domNode));  // Head node
        htmlContent->push_back((yyvsp[-1].domNode));  // Body node
        (yyval.domNode)->appendChildren(*htmlContent);
    }
#line 1259 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 4: /* head: HEAD_OPEN title HEAD_CLOSE  */
#line 85 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                               {
        (yyval.domNode) = new DOMNode(HEAD);
        DOMNodeList* headContent = new DOMNodeList();
        headContent->push_back((yyvsp[-1].domNode));  // Title node
        (yyval.domNode)->appendChildren(*headContent);
    }
#line 1270 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 5: /* title: TITLE_OPEN TEXT TITLE_CLOSE  */
#line 95 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                                {
        (yyval.domNode) = new DOMNode(TITLE, (yyvsp[-1].text));  // Text inside title
    }
#line 1278 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 6: /* body: BODY_OPEN body_content BODY_CLOSE  */
#line 102 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                                      {
        (yyval.domNode) = new DOMNode(BODY);
        (yyval.domNode)->appendChildren(*(yyvsp[-1].domNodeList));  // Append body content (list of nodes)
    }
#line 1287 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 7: /* body_content: %empty  */
#line 110 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                { (yyval.domNodeList) = new DOMNodeList(); }
#line 1293 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 8: /* body_content: body_content paragraph  */
#line 111 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                             { (yyvsp[-1].domNodeList)->push_back((yyvsp[0].domNode)); (yyval.domNodeList) = (yyvsp[-1].domNodeList); }
#line 1299 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 9: /* body_content: body_content h1  */
#line 112 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                      { (yyvsp[-1].domNodeList)->push_back((yyvsp[0].domNode)); (yyval.domNodeList) = (yyvsp[-1].domNodeList); }
#line 1305 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 10: /* body_content: body_content h2  */
#line 113 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                      { (yyvsp[-1].domNodeList)->push_back((yyvsp[0].domNode)); (yyval.domNodeList) = (yyvsp[-1].domNodeList); }
#line 1311 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 11: /* body_content: body_content h3  */
#line 114 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                      { (yyvsp[-1].domNodeList)->push_back((yyvsp[0].domNode)); (yyval.domNodeList) = (yyvsp[-1].domNodeList); }
#line 1317 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 12: /* body_content: body_content h4  */
#line 115 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                      { (yyvsp[-1].domNodeList)->push_back((yyvsp[0].domNode)); (yyval.domNodeList) = (yyvsp[-1].domNodeList); }
#line 1323 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 13: /* body_content: body_content h5  */
#line 116 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                      { (yyvsp[-1].domNodeList)->push_back((yyvsp[0].domNode)); (yyval.domNodeList) = (yyvsp[-1].domNodeList); }
#line 1329 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 14: /* body_content: body_content nav  */
#line 117 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                       { (yyvsp[-1].domNodeList)->push_back((yyvsp[0].domNode)); (yyval.domNodeList) = (yyvsp[-1].domNodeList); }
#line 1335 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 15: /* body_content: body_content header  */
#line 118 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                          { (yyvsp[-1].domNodeList)->push_back((yyvsp[0].domNode)); (yyval.domNodeList) = (yyvsp[-1].domNodeList); }
#line 1341 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 16: /* body_content: body_content unordered_list  */
#line 119 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                                  { (yyvsp[-1].domNodeList)->push_back((yyvsp[0].domNode)); (yyval.domNodeList) = (yyvsp[-1].domNodeList); }
#line 1347 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 17: /* body_content: body_content section  */
#line 120 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                           { (yyvsp[-1].domNodeList)->push_back((yyvsp[0].domNode)); (yyval.domNodeList) = (yyvsp[-1].domNodeList); }
#line 1353 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 18: /* body_content: body_content div  */
#line 121 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                       { (yyvsp[-1].domNodeList)->push_back((yyvsp[0].domNode)); (yyval.domNodeList) = (yyvsp[-1].domNodeList); }
#line 1359 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 19: /* body_content: body_content strong  */
#line 122 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                          { (yyvsp[-1].domNodeList)->push_back((yyvsp[0].domNode)); (yyval.domNodeList) = (yyvsp[-1].domNodeList); }
#line 1365 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 20: /* body_content: body_content em  */
#line 123 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                      { (yyvsp[-1].domNodeList)->push_back((yyvsp[0].domNode)); (yyval.domNodeList) = (yyvsp[-1].domNodeList); }
#line 1371 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 21: /* body_content: body_content u  */
#line 124 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                     { (yyvsp[-1].domNodeList)->push_back((yyvsp[0].domNode)); (yyval.domNodeList) = (yyvsp[-1].domNodeList); }
#line 1377 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 22: /* body_content: body_content small  */
#line 125 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                         { (yyvsp[-1].domNodeList)->push_back((yyvsp[0].domNode)); (yyval.domNodeList) = (yyvsp[-1].domNodeList); }
#line 1383 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 23: /* body_content: body_content blockquote  */
#line 126 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                              { (yyvsp[-1].domNodeList)->push_back((yyvsp[0].domNode)); (yyval.domNodeList) = (yyvsp[-1].domNodeList); }
#line 1389 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 24: /* paragraph: P_OPEN text P_CLOSE  */
#line 133 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                        {
        (yyval.domNode) = new DOMNode(P, (yyvsp[-1].text));  // Text inside paragraph
    }
#line 1397 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 25: /* div: DIV_OPEN body_content DIV_CLOSE  */
#line 140 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                                    {
        (yyval.domNode) = new DOMNode(DIV);
        (yyval.domNode)->appendChildren(*(yyvsp[-1].domNodeList));  // Content inside div
    }
#line 1406 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 26: /* h1: H1_OPEN text H1_CLOSE  */
#line 148 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                          {
        (yyval.domNode) = new DOMNode(H1, (yyvsp[-1].text));  // Text inside h1
    }
#line 1414 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 27: /* h2: H2_OPEN text H2_CLOSE  */
#line 155 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                          {
        (yyval.domNode) = new DOMNode(H2, (yyvsp[-1].text));  // Text inside h2
    }
#line 1422 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 28: /* h3: H3_OPEN text H3_CLOSE  */
#line 161 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                          {
        (yyval.domNode) = new DOMNode(H3, (yyvsp[-1].text));  // Text inside h2
    }
#line 1430 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 29: /* h4: H4_OPEN text H4_CLOSE  */
#line 167 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                          {
        (yyval.domNode) = new DOMNode(H4, (yyvsp[-1].text));  // Text inside h2
    }
#line 1438 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 30: /* h5: H5_OPEN text H5_CLOSE  */
#line 173 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                          {
        (yyval.domNode) = new DOMNode(H5, (yyvsp[-1].text));  // Text inside h2
    }
#line 1446 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 31: /* nav: NAV_OPEN body_content NAV_CLOSE  */
#line 180 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                                    {
        (yyval.domNode) = new DOMNode(NAV);
        (yyval.domNode)->appendChildren(*(yyvsp[-1].domNodeList));  // Content inside nav
    }
#line 1455 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 32: /* header: HEADER_OPEN body_content HEADER_CLOSE  */
#line 188 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                                          {
        (yyval.domNode) = new DOMNode(HEADER);
        (yyval.domNode)->appendChildren(*(yyvsp[-1].domNodeList));  // Content inside header
    }
#line 1464 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 33: /* unordered_list: UL_OPEN unordered_list_content UL_CLOSE  */
#line 196 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                                            {
        (yyval.domNode) = new DOMNode(UL);
        (yyval.domNode)->appendChildren(*(yyvsp[-1].domNodeList));  // List items inside ul
    }
#line 1473 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 34: /* unordered_list_content: list_item  */
#line 204 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
              { (yyval.domNodeList) = new DOMNodeList(); (yyval.domNodeList)->push_back((yyvsp[0].domNode)); }
#line 1479 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 35: /* unordered_list_content: unordered_list_content list_item  */
#line 205 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                                       { (yyvsp[-1].domNodeList)->push_back((yyvsp[0].domNode)); (yyval.domNodeList) = (yyvsp[-1].domNodeList); }
#line 1485 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 36: /* list_item: LI_OPEN text LI_CLOSE  */
#line 210 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                          {
        (yyval.domNode) = new DOMNode(LI, (yyvsp[-1].text));  // Text inside list item
    }
#line 1493 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 37: /* section: SECTION_OPEN body_content SECTION_CLOSE  */
#line 217 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                                            {
        (yyval.domNode) = new DOMNode(SECTION);
        (yyval.domNode)->appendChildren(*(yyvsp[-1].domNodeList));  // Content inside section
    }
#line 1502 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 38: /* strong: STRONG_OPEN text STRONG_CLOSE  */
#line 225 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                                  {
        (yyval.domNode) = new DOMNode(STRONG, (yyvsp[-1].text));  // Text inside strong (bold)
    }
#line 1510 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 39: /* em: EM_OPEN text EM_CLOSE  */
#line 232 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                          {
        (yyval.domNode) = new DOMNode(EM, (yyvsp[-1].text));  // Text inside em (italic)
    }
#line 1518 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 40: /* u: U_OPEN text U_CLOSE  */
#line 239 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                        {
        (yyval.domNode) = new DOMNode(U, (yyvsp[-1].text));  // Text inside u (underline)
    }
#line 1526 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 41: /* small: SMALL_OPEN text SMALL_CLOSE  */
#line 246 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                                {
        (yyval.domNode) = new DOMNode(SMALL, (yyvsp[-1].text));  // Text inside small (smaller font)
    }
#line 1534 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 42: /* blockquote: BLOCKQUOTE_OPEN text BLOCKQUOTE_CLOSE  */
#line 253 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
                                          {
        (yyval.domNode) = new DOMNode(BLOCK_QUOTE, (yyvsp[-1].text));  // Create a DOMNode for blockquote with its text content
    }
#line 1542 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;

  case 43: /* text: TEXT  */
#line 261 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
         {
        (yyval.text) = strdup((yyvsp[0].text));  // Return raw text
    }
#line 1550 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"
    break;


#line 1554 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 266 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"

