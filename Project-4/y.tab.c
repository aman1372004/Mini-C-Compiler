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
#line 1 "parser.y"

	#include <bits/stdc++.h>
	#include "symboltable.h"
	#include "lex.yy.c"

	using namespace std;

	int yyerror(char *msg);

	#define SYMBOL_TABLE symbol_table_list[current_scope].symbol_table

  	extern entry_t** constant_table;

	int current_dtype;

	table_t symbol_table_list[NUM_TABLES];

	int is_declaration = 0;
	int is_loop = 0;
	int is_func = 0;
	int func_type;

	int param_list[10];
	int p_idx = 0;
	int p=0;
  	int rhs = 0;

	void type_check(int,int,int);
	vector<int> merge(vector<int>& v1, vector<int>& v2);
	void backpatch(vector<int>&, int);
	void gencode(string);
	void gencode_math(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op);
	void gencode_rel(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op);
	void printlist(vector<int>);

	int nextinstr = 0;
	int temp_var_number = 0;

	vector<string> ICG;


#line 113 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    DEC_CONSTANT = 259,            /* DEC_CONSTANT  */
    HEX_CONSTANT = 260,            /* HEX_CONSTANT  */
    CHAR_CONSTANT = 261,           /* CHAR_CONSTANT  */
    FLOAT_CONSTANT = 262,          /* FLOAT_CONSTANT  */
    STRING = 263,                  /* STRING  */
    LOGICAL_AND = 264,             /* LOGICAL_AND  */
    LOGICAL_OR = 265,              /* LOGICAL_OR  */
    LS_EQ = 266,                   /* LS_EQ  */
    GR_EQ = 267,                   /* GR_EQ  */
    EQ = 268,                      /* EQ  */
    NOT_EQ = 269,                  /* NOT_EQ  */
    MUL_ASSIGN = 270,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 271,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 272,              /* MOD_ASSIGN  */
    ADD_ASSIGN = 273,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 274,              /* SUB_ASSIGN  */
    INCREMENT = 275,               /* INCREMENT  */
    DECREMENT = 276,               /* DECREMENT  */
    SHORT = 277,                   /* SHORT  */
    INT = 278,                     /* INT  */
    LONG = 279,                    /* LONG  */
    LONG_LONG = 280,               /* LONG_LONG  */
    SIGNED = 281,                  /* SIGNED  */
    UNSIGNED = 282,                /* UNSIGNED  */
    CONST = 283,                   /* CONST  */
    VOID = 284,                    /* VOID  */
    CHAR = 285,                    /* CHAR  */
    FLOAT = 286,                   /* FLOAT  */
    CHAR_STAR = 287,               /* CHAR_STAR  */
    IF = 288,                      /* IF  */
    FOR = 289,                     /* FOR  */
    WHILE = 290,                   /* WHILE  */
    CONTINUE = 291,                /* CONTINUE  */
    BREAK = 292,                   /* BREAK  */
    RETURN = 293,                  /* RETURN  */
    UMINUS = 294,                  /* UMINUS  */
    LOWER_THAN_ELSE = 295,         /* LOWER_THAN_ELSE  */
    ELSE = 296                     /* ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define DEC_CONSTANT 259
#define HEX_CONSTANT 260
#define CHAR_CONSTANT 261
#define FLOAT_CONSTANT 262
#define STRING 263
#define LOGICAL_AND 264
#define LOGICAL_OR 265
#define LS_EQ 266
#define GR_EQ 267
#define EQ 268
#define NOT_EQ 269
#define MUL_ASSIGN 270
#define DIV_ASSIGN 271
#define MOD_ASSIGN 272
#define ADD_ASSIGN 273
#define SUB_ASSIGN 274
#define INCREMENT 275
#define DECREMENT 276
#define SHORT 277
#define INT 278
#define LONG 279
#define LONG_LONG 280
#define SIGNED 281
#define UNSIGNED 282
#define CONST 283
#define VOID 284
#define CHAR 285
#define FLOAT 286
#define CHAR_STAR 287
#define IF 288
#define FOR 289
#define WHILE 290
#define CONTINUE 291
#define BREAK 292
#define RETURN 293
#define UMINUS 294
#define LOWER_THAN_ELSE 295
#define ELSE 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 44 "parser.y"

	int data_type;
	entry_t* entry;
	content_t* content;
	string* op;
	vector<int>* nextlist;
	int instr;

#line 257 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_DEC_CONSTANT = 4,               /* DEC_CONSTANT  */
  YYSYMBOL_HEX_CONSTANT = 5,               /* HEX_CONSTANT  */
  YYSYMBOL_CHAR_CONSTANT = 6,              /* CHAR_CONSTANT  */
  YYSYMBOL_FLOAT_CONSTANT = 7,             /* FLOAT_CONSTANT  */
  YYSYMBOL_STRING = 8,                     /* STRING  */
  YYSYMBOL_LOGICAL_AND = 9,                /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 10,                /* LOGICAL_OR  */
  YYSYMBOL_LS_EQ = 11,                     /* LS_EQ  */
  YYSYMBOL_GR_EQ = 12,                     /* GR_EQ  */
  YYSYMBOL_EQ = 13,                        /* EQ  */
  YYSYMBOL_NOT_EQ = 14,                    /* NOT_EQ  */
  YYSYMBOL_MUL_ASSIGN = 15,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 16,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 17,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 18,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 19,                /* SUB_ASSIGN  */
  YYSYMBOL_INCREMENT = 20,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 21,                 /* DECREMENT  */
  YYSYMBOL_SHORT = 22,                     /* SHORT  */
  YYSYMBOL_INT = 23,                       /* INT  */
  YYSYMBOL_LONG = 24,                      /* LONG  */
  YYSYMBOL_LONG_LONG = 25,                 /* LONG_LONG  */
  YYSYMBOL_SIGNED = 26,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 27,                  /* UNSIGNED  */
  YYSYMBOL_CONST = 28,                     /* CONST  */
  YYSYMBOL_VOID = 29,                      /* VOID  */
  YYSYMBOL_CHAR = 30,                      /* CHAR  */
  YYSYMBOL_FLOAT = 31,                     /* FLOAT  */
  YYSYMBOL_CHAR_STAR = 32,                 /* CHAR_STAR  */
  YYSYMBOL_IF = 33,                        /* IF  */
  YYSYMBOL_FOR = 34,                       /* FOR  */
  YYSYMBOL_WHILE = 35,                     /* WHILE  */
  YYSYMBOL_CONTINUE = 36,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 37,                     /* BREAK  */
  YYSYMBOL_RETURN = 38,                    /* RETURN  */
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_40_ = 40,                       /* '='  */
  YYSYMBOL_41_ = 41,                       /* '<'  */
  YYSYMBOL_42_ = 42,                       /* '>'  */
  YYSYMBOL_43_ = 43,                       /* '+'  */
  YYSYMBOL_44_ = 44,                       /* '-'  */
  YYSYMBOL_45_ = 45,                       /* '*'  */
  YYSYMBOL_46_ = 46,                       /* '/'  */
  YYSYMBOL_47_ = 47,                       /* '%'  */
  YYSYMBOL_48_ = 48,                       /* '!'  */
  YYSYMBOL_UMINUS = 49,                    /* UMINUS  */
  YYSYMBOL_LOWER_THAN_ELSE = 50,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_ELSE = 51,                      /* ELSE  */
  YYSYMBOL_52_ = 52,                       /* '('  */
  YYSYMBOL_53_ = 53,                       /* ')'  */
  YYSYMBOL_54_ = 54,                       /* '{'  */
  YYSYMBOL_55_ = 55,                       /* '}'  */
  YYSYMBOL_56_ = 56,                       /* ';'  */
  YYSYMBOL_57_ = 57,                       /* '['  */
  YYSYMBOL_58_ = 58,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_starter = 60,                   /* starter  */
  YYSYMBOL_builder = 61,                   /* builder  */
  YYSYMBOL_function = 62,                  /* function  */
  YYSYMBOL_63_1 = 63,                      /* $@1  */
  YYSYMBOL_64_2 = 64,                      /* $@2  */
  YYSYMBOL_type = 65,                      /* type  */
  YYSYMBOL_pointer = 66,                   /* pointer  */
  YYSYMBOL_data_type = 67,                 /* data_type  */
  YYSYMBOL_sign_specifier = 68,            /* sign_specifier  */
  YYSYMBOL_type_specifier = 69,            /* type_specifier  */
  YYSYMBOL_argument_list = 70,             /* argument_list  */
  YYSYMBOL_arguments = 71,                 /* arguments  */
  YYSYMBOL_arg = 72,                       /* arg  */
  YYSYMBOL_stmt = 73,                      /* stmt  */
  YYSYMBOL_compound_stmt = 74,             /* compound_stmt  */
  YYSYMBOL_75_3 = 75,                      /* $@3  */
  YYSYMBOL_statements = 76,                /* statements  */
  YYSYMBOL_single_stmt = 77,               /* single_stmt  */
  YYSYMBOL_for_block = 78,                 /* for_block  */
  YYSYMBOL_79_4 = 79,                      /* $@4  */
  YYSYMBOL_80_5 = 80,                      /* $@5  */
  YYSYMBOL_if_block = 81,                  /* if_block  */
  YYSYMBOL_while_block = 82,               /* while_block  */
  YYSYMBOL_83_6 = 83,                      /* $@6  */
  YYSYMBOL_84_7 = 84,                      /* $@7  */
  YYSYMBOL_declaration = 85,               /* declaration  */
  YYSYMBOL_declaration_list = 86,          /* declaration_list  */
  YYSYMBOL_sub_decl = 87,                  /* sub_decl  */
  YYSYMBOL_expression_stmt = 88,           /* expression_stmt  */
  YYSYMBOL_expression = 89,                /* expression  */
  YYSYMBOL_sub_expr = 90,                  /* sub_expr  */
  YYSYMBOL_assignment_expr = 91,           /* assignment_expr  */
  YYSYMBOL_unary_expr = 92,                /* unary_expr  */
  YYSYMBOL_lhs = 93,                       /* lhs  */
  YYSYMBOL_identifier = 94,                /* identifier  */
  YYSYMBOL_assign = 95,                    /* assign  */
  YYSYMBOL_arithmetic_expr = 96,           /* arithmetic_expr  */
  YYSYMBOL_constant = 97,                  /* constant  */
  YYSYMBOL_array_access = 98,              /* array_access  */
  YYSYMBOL_array_index = 99,               /* array_index  */
  YYSYMBOL_function_call = 100,            /* function_call  */
  YYSYMBOL_parameter_list = 101,           /* parameter_list  */
  YYSYMBOL_parameter = 102,                /* parameter  */
  YYSYMBOL_M = 103,                        /* M  */
  YYSYMBOL_N = 104                         /* N  */
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
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   456

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  199

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
       2,     2,     2,    48,     2,     2,     2,    47,     2,     2,
      52,    53,    45,    43,    39,    44,     2,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    56,
      41,    40,    42,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
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
      35,    36,    37,    38,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   119,   119,   120,   123,   124,   129,   137,   128,   151,
     152,   155,   156,   159,   160,   163,   164,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   182,   183,
     186,   187,   191,   198,   199,   206,   204,   222,   230,   234,
     240,   246,   251,   252,   253,   262,   270,   277,   288,   288,
     288,   301,   310,   323,   323,   323,   334,   335,   336,   339,
     340,   343,   344,   345,   349,   356,   359,   365,   375,   381,
     388,   395,   402,   409,   416,   426,   436,   444,   450,   455,
     463,   473,   483,   490,   500,   512,   520,   528,   536,   544,
     545,   548,   567,   568,   569,   570,   571,   572,   575,   583,
     591,   599,   607,   615,   623,   633,   640,   648,   649,   650,
     651,   654,   681,   682,   685,   693,   703,   704,   707,   712,
     719,   722
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "DEC_CONSTANT", "HEX_CONSTANT", "CHAR_CONSTANT", "FLOAT_CONSTANT",
  "STRING", "LOGICAL_AND", "LOGICAL_OR", "LS_EQ", "GR_EQ", "EQ", "NOT_EQ",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "INCREMENT", "DECREMENT", "SHORT", "INT", "LONG", "LONG_LONG", "SIGNED",
  "UNSIGNED", "CONST", "VOID", "CHAR", "FLOAT", "CHAR_STAR", "IF", "FOR",
  "WHILE", "CONTINUE", "BREAK", "RETURN", "','", "'='", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UMINUS", "LOWER_THAN_ELSE",
  "ELSE", "'('", "')'", "'{'", "'}'", "';'", "'['", "']'", "$accept",
  "starter", "builder", "function", "$@1", "$@2", "type", "pointer",
  "data_type", "sign_specifier", "type_specifier", "argument_list",
  "arguments", "arg", "stmt", "compound_stmt", "$@3", "statements",
  "single_stmt", "for_block", "$@4", "$@5", "if_block", "while_block",
  "$@6", "$@7", "declaration", "declaration_list", "sub_decl",
  "expression_stmt", "expression", "sub_expr", "assignment_expr",
  "unary_expr", "lhs", "identifier", "assign", "arithmetic_expr",
  "constant", "array_access", "array_index", "function_call",
  "parameter_list", "parameter", "M", "N", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-135)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-90)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     389,  -135,    10,    10,    -7,  -135,    11,    18,  -135,  -135,
    -135,  -135,  -135,  -135,   376,  -135,  -135,    44,     8,   419,
    -135,  -135,   -34,  -135,  -135,   291,   407,    23,   -24,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,    17,   407,   132,     8,
    -135,  -135,    44,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,    44,   334,  -135,  -135,   378,  -135,    22,  -135,  -135,
    -135,     5,  -135,  -135,  -135,  -135,    24,    24,  -135,    57,
     409,  -135,  -135,  -135,  -135,  -135,    -8,   405,  -135,  -135,
     327,   272,    24,    24,    24,    24,    24,  -135,    10,    16,
      53,  -135,  -135,  -135,   284,  -135,   347,  -135,   407,   118,
     409,  -135,     7,  -135,   136,   136,  -135,  -135,  -135,  -135,
    -135,   405,  -135,  -135,  -135,   284,   284,   284,   284,   284,
     284,   278,  -135,    59,  -135,   284,   284,  -135,  -135,    79,
      79,  -135,  -135,  -135,  -135,  -135,   301,   353,  -135,    52,
    -135,   220,    65,    66,  -135,    67,    84,   124,    44,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,   174,    86,   284,   215,
      91,  -135,  -135,  -135,    -2,  -135,    48,   347,  -135,  -135,
      50,   284,  -135,   284,  -135,   215,  -135,    63,   347,   220,
    -135,  -135,    95,   284,  -135,  -135,    69,   220,  -135,  -135,
    -135,   220,  -135,  -135,  -135,  -135,   220,  -135,  -135
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    91,     0,     0,    19,    17,    20,    22,    15,    16,
      26,    24,    25,    27,     0,     3,     4,     0,    10,     0,
      14,     5,     0,    60,    61,     0,     0,    89,    90,    88,
      87,    18,    21,    23,     1,     2,     0,     0,    89,    12,
       9,    13,     0,    57,    95,    96,    97,    93,    94,    92,
      58,     0,     0,    85,    86,     0,    56,     0,    11,    59,
      84,     0,   107,   108,   109,   110,     0,     0,    83,   105,
      80,   106,    81,    82,   113,   112,     0,    29,   105,   104,
       0,     0,     0,     0,     0,     0,     0,   111,     0,     0,
      28,    31,   103,   119,     0,   115,   118,    78,    79,   105,
      77,    90,     0,   117,    98,    99,   100,   101,   102,    32,
       7,     0,    76,   120,   120,     0,     0,     0,     0,     0,
       0,     0,   114,     0,    30,     0,     0,    73,    72,    70,
      71,    69,    68,   116,    35,     8,    74,    75,    38,   120,
      36,     0,     0,     0,   120,     0,     0,     0,     0,    37,
      33,    34,    40,    39,    41,    42,    89,     0,     0,     0,
       0,    45,    46,    44,     0,    43,     0,    67,    65,   120,
       0,     0,    47,     0,   120,     0,    64,     0,    66,     0,
     120,   120,    51,     0,    53,   121,     0,     0,   120,    48,
      54,     0,   121,    55,    52,   120,     0,    49,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,   141,  -135,  -135,  -135,     4,   111,  -135,  -135,
     137,  -135,  -135,    54,   -30,    36,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,   110,   -16,   121,   -11,
    -134,   -22,    21,     6,  -135,     0,   144,   267,   119,    19,
    -135,   125,  -135,    71,   -69,   -19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    14,    15,    16,    57,   123,   148,    40,    18,    19,
      20,    89,    90,    91,   149,   150,   138,   139,   151,   152,
     192,   198,   153,   154,   187,   193,   155,    22,    23,   169,
     170,   167,    97,    98,    26,    99,    51,   100,    71,   101,
      76,   157,   102,   103,   125,   188
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    36,    29,    30,    17,    42,    25,   113,   114,   115,
     116,   117,   118,     1,    27,   -63,    31,    38,    17,    28,
      25,    24,    43,    37,   166,    53,    54,     1,    62,    63,
      64,    65,   -63,    28,    32,    24,    28,   177,    24,   119,
     120,    33,    27,    53,    54,   126,   121,     1,    37,   186,
      87,    61,    69,    39,   172,    74,    42,    60,    68,    96,
     122,    28,   -62,    24,     2,     3,    78,    78,    66,   110,
     141,    72,   112,    56,    77,   160,    67,    53,    54,   -62,
      55,    88,    78,    78,    78,    78,    78,   173,   109,   173,
     115,   116,   111,   127,   128,   129,   130,   131,   132,    96,
     175,   174,   173,   136,   137,   179,   176,   140,   173,    81,
      21,   183,   184,   134,    55,    88,   181,   158,   159,   191,
     119,   120,   189,   161,    21,   164,   196,     1,    62,    63,
      64,    65,    36,   -89,   -89,   -89,   -89,   -89,    53,    54,
     162,   156,   165,   171,     2,     3,   185,    25,    27,   182,
      58,   178,    53,    54,    37,    35,    41,   190,   -89,   135,
      28,   194,    24,    59,   180,   124,   197,    28,    66,    24,
      52,   -62,    94,   195,    75,    55,    67,    73,     0,   156,
     163,    84,    85,    86,    -6,    25,     0,   156,   -62,    55,
       0,   156,   133,    25,    53,    54,   156,    25,    28,     0,
      24,     0,    25,     0,     0,     0,    28,     0,    24,     0,
      28,     0,    24,   -62,     0,    28,     0,    24,     1,    62,
      63,    64,    65,     1,     0,     0,    81,     0,     0,     0,
     -62,    55,     0,     0,     0,     2,     3,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,    13,   142,   143,   144,   145,   146,   147,    66,
       0,     0,     0,    94,     0,     0,     0,    67,     0,     0,
       0,   168,     0,     0,   134,     1,    62,    63,    64,    65,
      93,     1,    62,    63,    64,    65,    93,     1,    62,    63,
      64,    65,     2,     3,     0,     0,     0,     0,     2,     3,
       0,     0,     0,     0,     2,     3,    44,    45,    46,    47,
      48,     0,   115,   116,   117,   118,    66,     0,     0,    70,
      94,     0,    66,     0,    67,    95,    94,     0,    66,     0,
      67,    49,    94,    79,    80,     0,    67,     1,    62,    63,
      64,    65,   119,   120,     0,     0,     0,    50,     0,   104,
     105,   106,   107,   108,     2,     3,   113,   114,   115,   116,
     117,   118,   113,     0,   115,   116,   117,   118,     0,     0,
      82,    83,    84,    85,    86,     0,    34,     0,    66,     1,
      92,     1,    62,    63,    64,    65,    67,     0,   119,   120,
       0,     0,     1,     0,   119,   120,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,    13,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,    13,    44,    45,    46,    47,    48,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,    13,     0,     0,
       0,     4,     5,     6,     7,     0,     0,    49,    10,    11,
      12,    13,    82,    83,    84,    85,    86
};

static const yytype_int16 yycheck[] =
{
       0,    17,     2,     3,     0,    39,     0,     9,    10,    11,
      12,    13,    14,     3,    14,    39,    23,    17,    14,     0,
      14,     0,    56,    17,   158,    20,    21,     3,     4,     5,
       6,     7,    56,    14,    23,    14,    17,   171,    17,    41,
      42,    23,    42,    20,    21,   114,    39,     3,    42,   183,
      58,    51,    52,    45,    56,    55,    39,    51,    52,    81,
      53,    42,    39,    42,    20,    21,    66,    67,    44,    53,
     139,    52,    94,    56,    52,   144,    52,    20,    21,    56,
      57,    77,    82,    83,    84,    85,    86,    39,    88,    39,
      11,    12,    39,   115,   116,   117,   118,   119,   120,   121,
     169,    53,    39,   125,   126,   174,    56,    55,    39,    52,
       0,   180,   181,    54,    57,   111,    53,    52,    52,   188,
      41,    42,    53,    56,    14,   147,   195,     3,     4,     5,
       6,     7,   148,    15,    16,    17,    18,    19,    20,    21,
      56,   141,    56,    52,    20,    21,    51,   141,   148,   179,
      39,   173,    20,    21,   148,    14,    19,   187,    40,   123,
     141,   191,   141,    42,   175,   111,   196,   148,    44,   148,
      26,    39,    48,   192,    55,    57,    52,    52,    -1,   179,
      56,    45,    46,    47,    52,   179,    -1,   187,    56,    57,
      -1,   191,   121,   187,    20,    21,   196,   191,   179,    -1,
     179,    -1,   196,    -1,    -1,    -1,   187,    -1,   187,    -1,
     191,    -1,   191,    39,    -1,   196,    -1,   196,     3,     4,
       5,     6,     7,     3,    -1,    -1,    52,    -1,    -1,    -1,
      56,    57,    -1,    -1,    -1,    20,    21,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    44,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    56,    -1,    -1,    54,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,    20,    21,    -1,    -1,    -1,    -1,    20,    21,
      -1,    -1,    -1,    -1,    20,    21,    15,    16,    17,    18,
      19,    -1,    11,    12,    13,    14,    44,    -1,    -1,    52,
      48,    -1,    44,    -1,    52,    53,    48,    -1,    44,    -1,
      52,    40,    48,    66,    67,    -1,    52,     3,     4,     5,
       6,     7,    41,    42,    -1,    -1,    -1,    56,    -1,    82,
      83,    84,    85,    86,    20,    21,     9,    10,    11,    12,
      13,    14,     9,    -1,    11,    12,    13,    14,    -1,    -1,
      43,    44,    45,    46,    47,    -1,     0,    -1,    44,     3,
      53,     3,     4,     5,     6,     7,    52,    -1,    41,    42,
      -1,    -1,     3,    -1,    41,    42,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    32,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      31,    32,    15,    16,    17,    18,    19,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    31,    32,    -1,    -1,
      -1,    22,    23,    24,    25,    -1,    -1,    40,    29,    30,
      31,    32,    43,    44,    45,    46,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    20,    21,    22,    23,    24,    25,    26,    27,
      29,    30,    31,    32,    60,    61,    62,    65,    67,    68,
      69,    85,    86,    87,    91,    92,    93,    94,    98,    94,
      94,    23,    23,    23,     0,    61,    86,    92,    94,    45,
      66,    69,    39,    56,    15,    16,    17,    18,    19,    40,
      56,    95,    95,    20,    21,    57,    56,    63,    66,    87,
      92,    94,     4,     5,     6,     7,    44,    52,    92,    94,
      96,    97,    98,   100,    94,    97,    99,    52,    94,    96,
      96,    52,    43,    44,    45,    46,    47,    58,    65,    70,
      71,    72,    53,     8,    48,    53,    90,    91,    92,    94,
      96,    98,   101,   102,    96,    96,    96,    96,    96,    94,
      53,    39,    90,     9,    10,    11,    12,    13,    14,    41,
      42,    39,    53,    64,    72,   103,   103,    90,    90,    90,
      90,    90,    90,   102,    54,    74,    90,    90,    75,    76,
      55,   103,    33,    34,    35,    36,    37,    38,    65,    73,
      74,    77,    78,    81,    82,    85,    94,   100,    52,    52,
     103,    56,    56,    56,    90,    56,    89,    90,    56,    88,
      89,    52,    56,    39,    53,   103,    56,    89,    90,   103,
      88,    53,    73,   103,   103,    51,    89,    83,   104,    53,
      73,   103,    79,    84,    73,   104,   103,    73,    80
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    63,    64,    62,    65,
      65,    66,    66,    67,    67,    68,    68,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      71,    71,    72,    73,    73,    75,    74,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    79,    80,
      78,    81,    81,    83,    84,    82,    85,    85,    85,    86,
      86,    87,    87,    87,    88,    88,    89,    89,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      91,    91,    91,    91,    91,    92,    92,    92,    92,    93,
      93,    94,    95,    95,    95,    95,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    97,    97,    97,
      97,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   104
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     0,     0,     8,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     2,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     0,
       3,     1,     2,     1,     1,     0,     4,     3,     0,     1,
       1,     1,     1,     2,     2,     2,     2,     3,     0,     0,
      13,     6,    10,     0,     0,     9,     3,     2,     2,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     4,     4,     2,     1,     1,     1,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     4,     3,     3,     1,     1,     1,
       0,     0
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
  case 6: /* $@1: %empty  */
#line 129 "parser.y"
                        {
				func_type = current_dtype;
				is_declaration = 0;
				current_scope = create_new_scope();
				gencode((yyvsp[0].entry)->lexeme + string(":"));
			}
#line 1542 "y.tab.c"
    break;

  case 7: /* $@2: %empty  */
#line 137 "parser.y"
                        {
				is_declaration = 0;
				fill_parameter_list((yyvsp[-4].entry),param_list,p_idx);
				p_idx = 0;
				is_func = 1;
				p=1;
			}
#line 1554 "y.tab.c"
    break;

  case 8: /* function: type identifier $@1 '(' argument_list ')' $@2 compound_stmt  */
#line 145 "parser.y"
                                {   is_func = 0;	}
#line 1560 "y.tab.c"
    break;

  case 9: /* type: data_type pointer  */
#line 151 "parser.y"
                            {is_declaration = 1; }
#line 1566 "y.tab.c"
    break;

  case 10: /* type: data_type  */
#line 152 "parser.y"
                                    {is_declaration = 1; }
#line 1572 "y.tab.c"
    break;

  case 17: /* type_specifier: INT  */
#line 167 "parser.y"
                                       {current_dtype = INT;}
#line 1578 "y.tab.c"
    break;

  case 18: /* type_specifier: SHORT INT  */
#line 168 "parser.y"
                                       {current_dtype = SHORT;}
#line 1584 "y.tab.c"
    break;

  case 19: /* type_specifier: SHORT  */
#line 169 "parser.y"
                                       {current_dtype = SHORT;}
#line 1590 "y.tab.c"
    break;

  case 20: /* type_specifier: LONG  */
#line 170 "parser.y"
                                       {current_dtype = LONG;}
#line 1596 "y.tab.c"
    break;

  case 21: /* type_specifier: LONG INT  */
#line 171 "parser.y"
                                           {current_dtype = LONG;}
#line 1602 "y.tab.c"
    break;

  case 22: /* type_specifier: LONG_LONG  */
#line 172 "parser.y"
                                       {current_dtype = LONG_LONG;}
#line 1608 "y.tab.c"
    break;

  case 23: /* type_specifier: LONG_LONG INT  */
#line 173 "parser.y"
                                       {current_dtype = LONG_LONG;}
#line 1614 "y.tab.c"
    break;

  case 24: /* type_specifier: CHAR  */
#line 174 "parser.y"
                                                                   {current_dtype = CHAR;}
#line 1620 "y.tab.c"
    break;

  case 25: /* type_specifier: FLOAT  */
#line 175 "parser.y"
                                                                   {current_dtype = FLOAT;}
#line 1626 "y.tab.c"
    break;

  case 26: /* type_specifier: VOID  */
#line 176 "parser.y"
                                                                   {current_dtype = VOID;}
#line 1632 "y.tab.c"
    break;

  case 27: /* type_specifier: CHAR_STAR  */
#line 177 "parser.y"
                                                                   {current_dtype = STRING;}
#line 1638 "y.tab.c"
    break;

  case 32: /* arg: type identifier  */
#line 191 "parser.y"
                        {
							param_list[p_idx++] = (yyvsp[0].entry)->data_type;
							gencode(string("arg ") + (yyvsp[0].entry)->lexeme);
						}
#line 1647 "y.tab.c"
    break;

  case 33: /* stmt: compound_stmt  */
#line 198 "parser.y"
                                {(yyval.content) = new content_t(); (yyval.content)=(yyvsp[0].content);}
#line 1653 "y.tab.c"
    break;

  case 34: /* stmt: single_stmt  */
#line 199 "parser.y"
                                {(yyval.content) = new content_t(); (yyval.content)=(yyvsp[0].content);}
#line 1659 "y.tab.c"
    break;

  case 35: /* $@3: %empty  */
#line 206 "parser.y"
                                {
					if(!p)current_scope = create_new_scope();
					else p = 0;
				}
#line 1668 "y.tab.c"
    break;

  case 36: /* compound_stmt: '{' $@3 statements '}'  */
#line 215 "parser.y"
                                {
					current_scope = exit_scope();
					(yyval.content) = new content_t();
					(yyval.content) = (yyvsp[-1].content);
				}
#line 1678 "y.tab.c"
    break;

  case 37: /* statements: statements M stmt  */
#line 222 "parser.y"
                                {
									backpatch((yyvsp[-2].content)->nextlist,(yyvsp[-1].instr));
									(yyval.content) = new content_t();
									(yyval.content)->nextlist = (yyvsp[0].content)->nextlist;
									(yyval.content)->breaklist = merge((yyvsp[-2].content)->breaklist,(yyvsp[0].content)->breaklist);
									(yyval.content)->continuelist = merge((yyvsp[-2].content)->continuelist,(yyvsp[0].content)->continuelist);
								}
#line 1690 "y.tab.c"
    break;

  case 38: /* statements: %empty  */
#line 230 "parser.y"
                                                        {	(yyval.content) = new content_t();	}
#line 1696 "y.tab.c"
    break;

  case 39: /* single_stmt: if_block  */
#line 234 "parser.y"
                        {
							(yyval.content) = new content_t();
							(yyval.content) = (yyvsp[0].content);
							backpatch((yyval.content)->nextlist, nextinstr);
						}
#line 1706 "y.tab.c"
    break;

  case 40: /* single_stmt: for_block  */
#line 240 "parser.y"
                                {
							(yyval.content) = new content_t();
							(yyval.content) = (yyvsp[0].content);
							backpatch((yyval.content)->nextlist, nextinstr);
						}
#line 1716 "y.tab.c"
    break;

  case 41: /* single_stmt: while_block  */
#line 246 "parser.y"
                             {
							(yyval.content) = new content_t();
							(yyval.content) = (yyvsp[0].content);
							backpatch((yyval.content)->nextlist, nextinstr);
						 }
#line 1726 "y.tab.c"
    break;

  case 42: /* single_stmt: declaration  */
#line 251 "parser.y"
                                        {(yyval.content) = new content_t();}
#line 1732 "y.tab.c"
    break;

  case 43: /* single_stmt: function_call ';'  */
#line 252 "parser.y"
                                        {(yyval.content) = new content_t();}
#line 1738 "y.tab.c"
    break;

  case 44: /* single_stmt: RETURN ';'  */
#line 253 "parser.y"
                                          {
								if(is_func)
								{
									if(func_type != VOID)
										yyerror("return type (VOID) does not match function type");
								}
							  	else yyerror("return statement not inside function definition");
							}
#line 1751 "y.tab.c"
    break;

  case 45: /* single_stmt: CONTINUE ';'  */
#line 262 "parser.y"
                                        {
								if(!is_loop)
									yyerror("Illegal use of continue");
								(yyval.content) = new content_t();
								(yyval.content)->continuelist = {nextinstr};
								gencode("goto _");
							}
#line 1763 "y.tab.c"
    break;

  case 46: /* single_stmt: BREAK ';'  */
#line 270 "parser.y"
                                        {
								if(!is_loop) {yyerror("Illegal use of break");}
								(yyval.content) = new content_t();
								(yyval.content)->breaklist = {nextinstr};
								gencode("goto _");
						    }
#line 1774 "y.tab.c"
    break;

  case 47: /* single_stmt: RETURN sub_expr ';'  */
#line 278 "parser.y"
                                                        {
								if(is_func)
								{
									if(func_type != (yyvsp[-1].content)->data_type)
										yyerror("return type does not match function type");
								}
								else yyerror("return statement not in function definition");
							}
#line 1787 "y.tab.c"
    break;

  case 48: /* $@4: %empty  */
#line 288 "parser.y"
                                                                      {is_loop = 1;}
#line 1793 "y.tab.c"
    break;

  case 49: /* $@5: %empty  */
#line 288 "parser.y"
                                                                                              {is_loop = 0;}
#line 1799 "y.tab.c"
    break;

  case 50: /* for_block: FOR '(' expression_stmt M expression_stmt M expression ')' $@4 N M stmt $@5  */
#line 289 "parser.y"
                 {
				backpatch((yyvsp[-8].content)->truelist,(yyvsp[-2].instr));
				backpatch((yyvsp[-1].content)->nextlist,(yyvsp[-7].instr));
				backpatch((yyvsp[-1].content)->continuelist, (yyvsp[-7].instr));
				backpatch((yyvsp[-3].content)->nextlist, (yyvsp[-9].instr));
				(yyval.content) = new content_t();
				(yyval.content)->nextlist = merge((yyvsp[-8].content)->falselist,(yyvsp[-1].content)->breaklist);
				gencode(string("goto ") + to_string((yyvsp[-7].instr)));
			 }
#line 1813 "y.tab.c"
    break;

  case 51: /* if_block: IF '(' expression ')' M stmt  */
#line 302 "parser.y"
                        {
				backpatch((yyvsp[-3].content)->truelist,(yyvsp[-1].instr));
				(yyval.content) = new content_t();
				(yyval.content)->nextlist = merge((yyvsp[-3].content)->falselist,(yyvsp[0].content)->nextlist);
				(yyval.content)->breaklist = (yyvsp[0].content)->breaklist;
				(yyval.content)->continuelist = (yyvsp[0].content)->continuelist;
			}
#line 1825 "y.tab.c"
    break;

  case 52: /* if_block: IF '(' expression ')' M stmt ELSE N M stmt  */
#line 311 "parser.y"
                        {
				backpatch((yyvsp[-7].content)->truelist,(yyvsp[-5].instr));
				backpatch((yyvsp[-7].content)->falselist,(yyvsp[-1].instr));

				(yyval.content) = new content_t();
				vector<int> temp = merge((yyvsp[-4].content)->nextlist,(yyvsp[-2].content)->nextlist);
				(yyval.content)->nextlist = merge(temp,(yyvsp[0].content)->nextlist);
				(yyval.content)->breaklist = merge((yyvsp[0].content)->breaklist,(yyvsp[-4].content)->breaklist);
				(yyval.content)->continuelist = merge((yyvsp[0].content)->continuelist,(yyvsp[-4].content)->continuelist);
			}
#line 1840 "y.tab.c"
    break;

  case 53: /* $@6: %empty  */
#line 323 "parser.y"
                                              {is_loop = 1;}
#line 1846 "y.tab.c"
    break;

  case 54: /* $@7: %empty  */
#line 323 "parser.y"
                                                                  {is_loop = 0;}
#line 1852 "y.tab.c"
    break;

  case 55: /* while_block: WHILE M '(' expression ')' M $@6 stmt $@7  */
#line 324 "parser.y"
                        {
				backpatch((yyvsp[-1].content)->nextlist,(yyvsp[-7].instr));
				backpatch((yyvsp[-5].content)->truelist,(yyvsp[-3].instr));
				backpatch((yyvsp[-1].content)->continuelist, (yyvsp[-7].instr));
				(yyval.content) = new content_t();
				(yyval.content)->nextlist = merge((yyvsp[-5].content)->falselist,(yyvsp[-1].content)->breaklist);
				gencode(string("goto ") + to_string((yyvsp[-7].instr)));
			}
#line 1865 "y.tab.c"
    break;

  case 56: /* declaration: type declaration_list ';'  */
#line 334 "parser.y"
                                                        {is_declaration = 0;}
#line 1871 "y.tab.c"
    break;

  case 64: /* expression_stmt: expression ';'  */
#line 350 "parser.y"
                                        {
						(yyval.content) = new content_t(); 
						(yyval.content)->truelist = (yyvsp[-1].content)->truelist; 
						(yyval.content)->falselist = (yyvsp[-1].content)->falselist;
					}
#line 1881 "y.tab.c"
    break;

  case 65: /* expression_stmt: ';'  */
#line 356 "parser.y"
                                        {	(yyval.content) = new content_t();	}
#line 1887 "y.tab.c"
    break;

  case 66: /* expression: expression ',' sub_expr  */
#line 360 "parser.y"
                                {
					(yyval.content) = new content_t();
					(yyval.content)->truelist = (yyvsp[0].content)->truelist; 
					(yyval.content)->falselist = (yyvsp[0].content)->falselist;
				}
#line 1897 "y.tab.c"
    break;

  case 67: /* expression: sub_expr  */
#line 366 "parser.y"
                                {
					(yyval.content) = new content_t(); 
					(yyval.content)->truelist = (yyvsp[0].content)->truelist; 
					(yyval.content)->falselist = (yyvsp[0].content)->falselist;
				}
#line 1907 "y.tab.c"
    break;

  case 68: /* sub_expr: sub_expr '>' sub_expr  */
#line 376 "parser.y"
                        {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" > "));
			}
#line 1917 "y.tab.c"
    break;

  case 69: /* sub_expr: sub_expr '<' sub_expr  */
#line 382 "parser.y"
                        {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" < "));
			}
#line 1927 "y.tab.c"
    break;

  case 70: /* sub_expr: sub_expr EQ sub_expr  */
#line 389 "parser.y"
                        {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" == "));
			}
#line 1937 "y.tab.c"
    break;

  case 71: /* sub_expr: sub_expr NOT_EQ sub_expr  */
#line 396 "parser.y"
                        {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" != "));
			}
#line 1947 "y.tab.c"
    break;

  case 72: /* sub_expr: sub_expr GR_EQ sub_expr  */
#line 403 "parser.y"
                        {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" >= "));
			}
#line 1957 "y.tab.c"
    break;

  case 73: /* sub_expr: sub_expr LS_EQ sub_expr  */
#line 410 "parser.y"
                        {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" <= "));
			}
#line 1967 "y.tab.c"
    break;

  case 74: /* sub_expr: sub_expr LOGICAL_AND M sub_expr  */
#line 417 "parser.y"
                        {
				type_check((yyvsp[-3].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[-3].content)->data_type;
				backpatch((yyvsp[-3].content)->truelist,(yyvsp[-1].instr));
				(yyval.content)->truelist = (yyvsp[0].content)->truelist;
				(yyval.content)->falselist = merge((yyvsp[-3].content)->falselist,(yyvsp[0].content)->falselist);
			}
#line 1980 "y.tab.c"
    break;

  case 75: /* sub_expr: sub_expr LOGICAL_OR M sub_expr  */
#line 427 "parser.y"
                        {
				type_check((yyvsp[-3].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[-3].content)->data_type;
				backpatch((yyvsp[-3].content)->falselist,(yyvsp[-1].instr));
				(yyval.content)->truelist = merge((yyvsp[-3].content)->truelist,(yyvsp[0].content)->truelist);
				(yyval.content)->falselist = (yyvsp[0].content)->falselist;
			}
#line 1993 "y.tab.c"
    break;

  case 76: /* sub_expr: '!' sub_expr  */
#line 437 "parser.y"
                        {
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
				(yyval.content)->truelist = (yyvsp[0].content)->falselist;
				(yyval.content)->falselist = (yyvsp[0].content)->truelist;
			}
#line 2004 "y.tab.c"
    break;

  case 77: /* sub_expr: arithmetic_expr  */
#line 445 "parser.y"
                        {
				(yyval.content) = new content_t(); 
				(yyval.content)->data_type = (yyvsp[0].content)->data_type; 
				(yyval.content)->addr = (yyvsp[0].content)->addr;
			}
#line 2014 "y.tab.c"
    break;

  case 78: /* sub_expr: assignment_expr  */
#line 451 "parser.y"
                        {
				(yyval.content) = new content_t(); 
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
			}
#line 2023 "y.tab.c"
    break;

  case 79: /* sub_expr: unary_expr  */
#line 456 "parser.y"
                        {
				(yyval.content) = new content_t(); 
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
			}
#line 2032 "y.tab.c"
    break;

  case 80: /* assignment_expr: lhs assign arithmetic_expr  */
#line 464 "parser.y"
                        {
				type_check((yyvsp[-2].content)->entry->data_type,(yyvsp[0].content)->data_type,1);
		 		(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
		 		(yyval.content)->code = (yyvsp[-2].content)->entry->lexeme + *(yyvsp[-1].op) + (yyvsp[0].content)->addr;
				gencode((yyval.content)->code);
		 		rhs = 0;
			}
#line 2045 "y.tab.c"
    break;

  case 81: /* assignment_expr: lhs assign array_access  */
#line 474 "parser.y"
                        {
				type_check((yyvsp[-2].content)->entry->data_type,(yyvsp[0].content)->data_type,1);
	 			(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
	 			(yyval.content)->code = (yyvsp[-2].content)->entry->lexeme + *(yyvsp[-1].op) + (yyvsp[0].content)->code;
				gencode((yyval.content)->code);
	 			rhs = 0;
			}
#line 2058 "y.tab.c"
    break;

  case 82: /* assignment_expr: lhs assign function_call  */
#line 484 "parser.y"
                        {
				type_check((yyvsp[-2].content)->entry->data_type,(yyvsp[0].data_type),1); 
				(yyval.content) = new content_t(); 
				(yyval.content)->data_type = (yyvsp[0].data_type);
			}
#line 2068 "y.tab.c"
    break;

  case 83: /* assignment_expr: lhs assign unary_expr  */
#line 491 "parser.y"
                {
				type_check((yyvsp[-2].content)->entry->data_type,(yyvsp[0].content)->data_type,1);
			 	(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
			 	(yyval.content)->code = (yyvsp[-2].content)->entry->lexeme + *(yyvsp[-1].op) + (yyvsp[0].content)->code;
				gencode((yyval.content)->code);
			 	rhs = 0;
			}
#line 2081 "y.tab.c"
    break;

  case 84: /* assignment_expr: unary_expr assign unary_expr  */
#line 501 "parser.y"
                        {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,1);
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
			 	(yyval.content)->code = (yyvsp[-2].content)->code + *(yyvsp[-1].op) + (yyvsp[0].content)->code;
				gencode((yyval.content)->code);
				rhs = 0;
			}
#line 2094 "y.tab.c"
    break;

  case 85: /* unary_expr: identifier INCREMENT  */
#line 513 "parser.y"
                        {
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[-1].entry)->data_type;
				(yyval.content)->code = string((yyvsp[-1].entry)->lexeme) + string("++");
				gencode((yyval.content)->code);
			}
#line 2105 "y.tab.c"
    break;

  case 86: /* unary_expr: identifier DECREMENT  */
#line 521 "parser.y"
                        {
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[-1].entry)->data_type;
				(yyval.content)->code = string((yyvsp[-1].entry)->lexeme) + string("--");
				gencode((yyval.content)->code);
			}
#line 2116 "y.tab.c"
    break;

  case 87: /* unary_expr: DECREMENT identifier  */
#line 529 "parser.y"
                        {
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].entry)->data_type;
				(yyval.content)->code = string("--") + string((yyvsp[0].entry)->lexeme);
				gencode((yyval.content)->code);
			}
#line 2127 "y.tab.c"
    break;

  case 88: /* unary_expr: INCREMENT identifier  */
#line 537 "parser.y"
                        {
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].entry)->data_type;
				(yyval.content)->code = string("++") + string((yyvsp[0].entry)->lexeme);
				gencode((yyval.content)->code);
			}
#line 2138 "y.tab.c"
    break;

  case 89: /* lhs: identifier  */
#line 544 "parser.y"
                        {(yyval.content) = new content_t(); (yyval.content)->entry = (yyvsp[0].entry);}
#line 2144 "y.tab.c"
    break;

  case 90: /* lhs: array_access  */
#line 545 "parser.y"
                        {(yyval.content) = new content_t(); (yyval.content)->code = (yyvsp[0].content)->code;}
#line 2150 "y.tab.c"
    break;

  case 91: /* identifier: IDENTIFIER  */
#line 549 "parser.y"
                {
                    if(is_declaration && !rhs)
                    {
                      (yyvsp[0].entry) = insert(SYMBOL_TABLE,yytext,INT_MAX,current_dtype);
                      if((yyvsp[0].entry) == NULL) 
					  	yyerror("Redeclaration of variable");
                    }
                    else
                    {
                      (yyvsp[0].entry) = search_recursive(yytext);
                      if((yyvsp[0].entry) == NULL) 
					  	yyerror("Variable not declared");
                    }
                    
					(yyval.entry) = (yyvsp[0].entry);
                }
#line 2171 "y.tab.c"
    break;

  case 92: /* assign: '='  */
#line 567 "parser.y"
                                {rhs=1; (yyval.op) = new string(" = ");}
#line 2177 "y.tab.c"
    break;

  case 93: /* assign: ADD_ASSIGN  */
#line 568 "parser.y"
                        {rhs=1; (yyval.op) = new string(" += ");}
#line 2183 "y.tab.c"
    break;

  case 94: /* assign: SUB_ASSIGN  */
#line 569 "parser.y"
                        {rhs=1; (yyval.op) = new string(" -= ");}
#line 2189 "y.tab.c"
    break;

  case 95: /* assign: MUL_ASSIGN  */
#line 570 "parser.y"
                        {rhs=1; (yyval.op) = new string(" *= ");}
#line 2195 "y.tab.c"
    break;

  case 96: /* assign: DIV_ASSIGN  */
#line 571 "parser.y"
                        {rhs=1;	(yyval.op) = new string(" /= ");}
#line 2201 "y.tab.c"
    break;

  case 97: /* assign: MOD_ASSIGN  */
#line 572 "parser.y"
                        {rhs=1; (yyval.op) = new string(" %= ");}
#line 2207 "y.tab.c"
    break;

  case 98: /* arithmetic_expr: arithmetic_expr '+' arithmetic_expr  */
#line 576 "parser.y"
                                         {
						type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,0);
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[-2].content)->data_type;
						gencode_math((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" + "));
					 }
#line 2218 "y.tab.c"
    break;

  case 99: /* arithmetic_expr: arithmetic_expr '-' arithmetic_expr  */
#line 584 "parser.y"
                                         {
						type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,0);
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[-2].content)->data_type;
						gencode_math((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" - "));
					 }
#line 2229 "y.tab.c"
    break;

  case 100: /* arithmetic_expr: arithmetic_expr '*' arithmetic_expr  */
#line 592 "parser.y"
                                         {
						type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,0);
						(yyval.content) = new content_t();
		 				(yyval.content)->data_type = (yyvsp[-2].content)->data_type;
						gencode_math((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" * "));
					 }
#line 2240 "y.tab.c"
    break;

  case 101: /* arithmetic_expr: arithmetic_expr '/' arithmetic_expr  */
#line 600 "parser.y"
                                         {
						type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,0);
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[-2].content)->data_type;
						gencode_math((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" / "));
					 }
#line 2251 "y.tab.c"
    break;

  case 102: /* arithmetic_expr: arithmetic_expr '%' arithmetic_expr  */
#line 608 "parser.y"
                                         {
						type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,0);
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[-2].content)->data_type;
						gencode_math((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" % "));
				 	 }
#line 2262 "y.tab.c"
    break;

  case 103: /* arithmetic_expr: '(' arithmetic_expr ')'  */
#line 616 "parser.y"
                                         {
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[-1].content)->data_type;
						(yyval.content)->addr = (yyvsp[-1].content)->addr;
						(yyval.content)->code = (yyvsp[-1].content)->code;
					 }
#line 2273 "y.tab.c"
    break;

  case 104: /* arithmetic_expr: '-' arithmetic_expr  */
#line 624 "parser.y"
                                         {
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[0].content)->data_type;
						(yyval.content)->addr = "t" + to_string(temp_var_number);
						std::string expr = (yyval.content)->addr + " = " + "minus " + (yyvsp[0].content)->addr;
						(yyval.content)->code = (yyvsp[0].content)->code + expr;
						temp_var_number++;
				 	 }
#line 2286 "y.tab.c"
    break;

  case 105: /* arithmetic_expr: identifier  */
#line 634 "parser.y"
                                         {
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[0].entry)->data_type;
	 					(yyval.content)->addr = (yyvsp[0].entry)->lexeme;
			   		 }
#line 2296 "y.tab.c"
    break;

  case 106: /* arithmetic_expr: constant  */
#line 641 "parser.y"
                                         {
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[0].entry)->data_type;
						(yyval.content)->addr = to_string((yyvsp[0].entry)->value);
					 }
#line 2306 "y.tab.c"
    break;

  case 107: /* constant: DEC_CONSTANT  */
#line 648 "parser.y"
                                        {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 2312 "y.tab.c"
    break;

  case 108: /* constant: HEX_CONSTANT  */
#line 649 "parser.y"
                                        {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 2318 "y.tab.c"
    break;

  case 109: /* constant: CHAR_CONSTANT  */
#line 650 "parser.y"
                                                {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 2324 "y.tab.c"
    break;

  case 110: /* constant: FLOAT_CONSTANT  */
#line 651 "parser.y"
                                                {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 2330 "y.tab.c"
    break;

  case 111: /* array_access: identifier '[' array_index ']'  */
#line 655 "parser.y"
                                {
					if(is_declaration)
					{
						if((yyvsp[-1].entry)->value <= 0)
							yyerror("size of array is not positive");
						else if((yyvsp[-1].entry)->is_constant)
							(yyvsp[-3].entry)->array_dimension = (yyvsp[-1].entry)->value;
					}
					else if((yyvsp[-1].entry)->is_constant)
					{
						if((yyvsp[-1].entry)->value > (yyvsp[-3].entry)->array_dimension)
							yyerror("Array index out of bound");
						if((yyvsp[-1].entry)->value < 0)
							yyerror("Array index cannot be negative");
					}
					
					(yyval.content) = new content_t();
					(yyval.content)->data_type = (yyvsp[-3].entry)->data_type;
					
					if((yyvsp[-1].entry)->is_constant)
						(yyval.content)->code = string((yyvsp[-3].entry)->lexeme) + string("[") + to_string((yyvsp[-1].entry)->value) + string("]");
					else
						(yyval.content)->code = string((yyvsp[-3].entry)->lexeme) + string("[") + string((yyvsp[-1].entry)->lexeme) + string("]");
					(yyval.content)->entry = (yyvsp[-3].entry);
				}
#line 2360 "y.tab.c"
    break;

  case 112: /* array_index: constant  */
#line 681 "parser.y"
                                {(yyval.entry) = (yyvsp[0].entry);}
#line 2366 "y.tab.c"
    break;

  case 113: /* array_index: identifier  */
#line 682 "parser.y"
                                        {(yyval.entry) = (yyvsp[0].entry);}
#line 2372 "y.tab.c"
    break;

  case 114: /* function_call: identifier '(' parameter_list ')'  */
#line 686 "parser.y"
                                {
					(yyval.data_type) = (yyvsp[-3].entry)->data_type;
					check_parameter_list((yyvsp[-3].entry),param_list,p_idx);
					p_idx = 0;
					gencode(string("call ") + (yyvsp[-3].entry)->lexeme);
				}
#line 2383 "y.tab.c"
    break;

  case 115: /* function_call: identifier '(' ')'  */
#line 694 "parser.y"
                                {
					(yyval.data_type) = (yyvsp[-2].entry)->data_type;
				 	check_parameter_list((yyvsp[-2].entry),param_list,p_idx);
				 	p_idx = 0;
	 				gencode(string("call ") + (yyvsp[-2].entry)->lexeme);
				}
#line 2394 "y.tab.c"
    break;

  case 118: /* parameter: sub_expr  */
#line 708 "parser.y"
                                {
					param_list[p_idx++] = (yyvsp[0].content)->data_type;
					gencode(string("param ") + (yyvsp[0].content)->addr);
				}
#line 2403 "y.tab.c"
    break;

  case 119: /* parameter: STRING  */
#line 713 "parser.y"
                                {
					param_list[p_idx++] = STRING;
					gencode(string("param ") + (yyvsp[0].entry)->lexeme);
				}
#line 2412 "y.tab.c"
    break;

  case 120: /* M: %empty  */
#line 719 "parser.y"
                        {(yyval.instr) = nextinstr;}
#line 2418 "y.tab.c"
    break;

  case 121: /* N: %empty  */
#line 722 "parser.y"
                        {
				(yyval.content) = new content_t;
				(yyval.content)->nextlist = {nextinstr};
				gencode("goto _");
			}
#line 2428 "y.tab.c"
    break;


#line 2432 "y.tab.c"

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

#line 729 "parser.y"


void gencode(string x)
{
	std::string instruction;

	instruction = to_string(nextinstr) + string(": ") + x;
	ICG.push_back(instruction);
	nextinstr++;
}


void gencode_rel(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op)
{
	lhs->data_type = arg1->data_type;

	lhs->truelist = {nextinstr};
	lhs->falselist = {nextinstr + 1};

	std::string code;

	code = string("if ") + arg1->addr + op + arg2->addr + string(" goto _");
	gencode(code);

	code = string("goto _");
	gencode(code);
}

void gencode_math(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op)
{
	lhs->addr = "t" + to_string(temp_var_number);
	std::string expr = lhs->addr + string(" = ") + arg1->addr + op + arg2->addr;
	lhs->code = arg1->code + arg2->code + expr;

	temp_var_number++;

	gencode(expr);
}

void backpatch(vector<int>& v1, int number)
{
	for(int i = 0; i<v1.size(); i++)
	{
		string instruction = ICG[v1[i]];

		if(instruction.find("_") < instruction.size())
		{
			instruction.replace(instruction.find("_"),1,to_string(number));
			ICG[v1[i]] = instruction;
		}
	}
}

vector<int> merge(vector<int>& v1, vector<int>& v2)
{
	vector<int> concat;
	concat.reserve(v1.size() + v2.size());
	concat.insert(concat.end(), v1.begin(), v1.end());
	concat.insert(concat.end(), v2.begin(), v2.end());

	return concat;
}

void type_check(int left, int right, int flag)
{
	if(left != right)
	{
		switch(flag)
		{
			case 0: yyerror("Type mismatch in arithmetic expression"); break;
			case 1: yyerror("Type mismatch in assignment expression"); break;
			case 2: yyerror("Type mismatch in logical expression"); break;
		}
	}
}

void displayICG()
{
	ofstream outfile("ICG.code");

	for(int i=0; i<ICG.size();i++)
	outfile << ICG[i] <<endl;

	outfile << nextinstr << ": exit";

	outfile.close();
}

void printlist(vector<int> v){
	for(auto it:v)
		cout<<it<<" ";
	cout<<"Next: "<<nextinstr<<endl;
}

int main(int argc, char *argv[])
{
	 int i;
	 for(i=0; i<NUM_TABLES;i++)
	 {
	  symbol_table_list[i].symbol_table = NULL;
	  symbol_table_list[i].parent = -1;
	 }

	constant_table = create_table();
  symbol_table_list[0].symbol_table = create_table();
	yyin = fopen(argv[1], "r");

	if(!yyparse())
	{
		printf("\nPARSING COMPLETE\n\n\n");
	}
	else
	{
			printf("\nPARSING FAILED!\n\n\n");
	}

	displayICG();
/*
	printf("SYMBOL TABLES\n\n");
	display_all();

	printf("CONSTANT TABLE");
	display_constant_table(constant_table);*/

}

int yyerror(const char *msg)
{
	printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
	exit(0);
}
