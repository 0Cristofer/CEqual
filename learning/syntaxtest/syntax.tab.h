#ifndef YY_cequal_parser_h_included
#define YY_cequal_parser_h_included
/*#define YY_USE_CLASS 
*/
#line 1 "/usr/share/bison++/bison.h"
/* before anything */
#ifdef c_plusplus
 #ifndef __cplusplus
  #define __cplusplus
 #endif
#endif


 #line 8 "/usr/share/bison++/bison.h"

#line 21 "/usr/share/bison++/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_cequal_parser_COMPATIBILITY
 #ifndef YY_USE_CLASS
  #define  YY_cequal_parser_COMPATIBILITY 1
 #else
  #define  YY_cequal_parser_COMPATIBILITY 0
 #endif
#endif

#if YY_cequal_parser_COMPATIBILITY != 0
/* backward compatibility */
 #ifdef YYLTYPE
  #ifndef YY_cequal_parser_LTYPE
   #define YY_cequal_parser_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
  #endif
 #endif
/*#ifdef YYSTYPE*/
  #ifndef YY_cequal_parser_STYPE
   #define YY_cequal_parser_STYPE YYSTYPE
  /* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
   /* use %define STYPE */
  #endif
/*#endif*/
 #ifdef YYDEBUG
  #ifndef YY_cequal_parser_DEBUG
   #define  YY_cequal_parser_DEBUG YYDEBUG
   /* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
   /* use %define DEBUG */
  #endif
 #endif 
 /* use goto to be compatible */
 #ifndef YY_cequal_parser_USE_GOTO
  #define YY_cequal_parser_USE_GOTO 1
 #endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_cequal_parser_USE_GOTO
 #define YY_cequal_parser_USE_GOTO 0
#endif

#ifndef YY_cequal_parser_PURE

 #line 65 "/usr/share/bison++/bison.h"

#line 65 "/usr/share/bison++/bison.h"
/* YY_cequal_parser_PURE */
#endif


 #line 68 "/usr/share/bison++/bison.h"
#ifndef YY_USE_CLASS
# ifndef YYSTYPE
#  define YYSTYPE int
#  define YYSTYPE_IS_TRIVIAL 1
# endif
#endif

#line 68 "/usr/share/bison++/bison.h"
/* prefix */

#ifndef YY_cequal_parser_DEBUG

 #line 71 "/usr/share/bison++/bison.h"

#line 71 "/usr/share/bison++/bison.h"
/* YY_cequal_parser_DEBUG */
#endif

#ifndef YY_cequal_parser_LSP_NEEDED

 #line 75 "/usr/share/bison++/bison.h"

#line 75 "/usr/share/bison++/bison.h"
 /* YY_cequal_parser_LSP_NEEDED*/
#endif

/* DEFAULT LTYPE*/
#ifdef YY_cequal_parser_LSP_NEEDED
 #ifndef YY_cequal_parser_LTYPE
  #ifndef BISON_YYLTYPE_ISDECLARED
   #define BISON_YYLTYPE_ISDECLARED
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;
  #endif

  #define YY_cequal_parser_LTYPE yyltype
 #endif
#endif

/* DEFAULT STYPE*/
#ifndef YY_cequal_parser_STYPE
 #define YY_cequal_parser_STYPE int
#endif

/* DEFAULT MISCELANEOUS */
#ifndef YY_cequal_parser_PARSE
 #define YY_cequal_parser_PARSE yyparse
#endif

#ifndef YY_cequal_parser_LEX
 #define YY_cequal_parser_LEX yylex
#endif

#ifndef YY_cequal_parser_LVAL
 #define YY_cequal_parser_LVAL yylval
#endif

#ifndef YY_cequal_parser_LLOC
 #define YY_cequal_parser_LLOC yylloc
#endif

#ifndef YY_cequal_parser_CHAR
 #define YY_cequal_parser_CHAR yychar
#endif

#ifndef YY_cequal_parser_NERRS
 #define YY_cequal_parser_NERRS yynerrs
#endif

#ifndef YY_cequal_parser_DEBUG_FLAG
 #define YY_cequal_parser_DEBUG_FLAG yydebug
#endif

#ifndef YY_cequal_parser_ERROR
 #define YY_cequal_parser_ERROR yyerror
#endif

#ifndef YY_cequal_parser_PARSE_PARAM
 #ifndef __STDC__
  #ifndef __cplusplus
   #ifndef YY_USE_CLASS
    #define YY_cequal_parser_PARSE_PARAM
    #ifndef YY_cequal_parser_PARSE_PARAM_DEF
     #define YY_cequal_parser_PARSE_PARAM_DEF
    #endif
   #endif
  #endif
 #endif
 #ifndef YY_cequal_parser_PARSE_PARAM
  #define YY_cequal_parser_PARSE_PARAM void
 #endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

 #ifndef YY_cequal_parser_PURE
  #ifndef yylval
   extern YY_cequal_parser_STYPE YY_cequal_parser_LVAL;
  #else
   #if yylval != YY_cequal_parser_LVAL
    extern YY_cequal_parser_STYPE YY_cequal_parser_LVAL;
   #else
    #warning "Namespace conflict, disabling some functionality (bison++ only)"
   #endif
  #endif
 #endif


 #line 169 "/usr/share/bison++/bison.h"
#define	T_RES_VAR	258
#define	T_RES_BOOL	259
#define	T_RES_STR	260
#define	T_RES_INT	261
#define	T_RES_IF	262
#define	T_RES_ELSE	263
#define	T_RES_FOR	264
#define	T_RES_WHILE	265
#define	T_RES_SKIP	266
#define	T_RES_STOP	267
#define	T_RES_DEF	268
#define	T_RES_RETURN	269
#define	T_RES_READ	270
#define	T_RES_WRITE	271
#define	T_SYM_OP	272
#define	T_SYM_CP	273
#define	T_SYM_OBK	274
#define	T_SYM_CBK	275
#define	T_SYM_OBC	276
#define	T_SYM_CBC	277
#define	T_SYM_ATR	278
#define	T_SYM_ATP	279
#define	T_SYM_ATM	280
#define	T_SYM_ATMUL	281
#define	T_SYM_ATDIV	282
#define	T_SYM_ATMOD	283
#define	T_SYM_PLS	284
#define	T_SYM_MIN	285
#define	T_SYM_MUL	286
#define	T_SYM_DIV	287
#define	T_SYM_MOD	288
#define	T_SYM_EQL	289
#define	T_SYM_DIF	290
#define	T_SYM_HIG	291
#define	T_SYM_HEQ	292
#define	T_SYM_LES	293
#define	T_SYM_LEQ	294
#define	T_SYM_OR	295
#define	T_SYM_AND	296
#define	T_SYM_NOT	297
#define	T_SYM_SMC	298
#define	T_SYM_CMA	299
#define	T_SYM_INTR	300
#define	T_SYM_COL	301
#define	T_ID	302
#define	T_LIT_INT	303
#define	T_LIT_STR	304
#define	T_LIT_TRUE	305
#define	T_LIT_FALSE	306
#define	LOWER_THEN_ELSE	307
#define	UMINUS	308


#line 169 "/usr/share/bison++/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
 #ifndef YY_cequal_parser_CLASS
  #define YY_cequal_parser_CLASS cequal_parser
 #endif

 #ifndef YY_cequal_parser_INHERIT
  #define YY_cequal_parser_INHERIT
 #endif

 #ifndef YY_cequal_parser_MEMBERS
  #define YY_cequal_parser_MEMBERS 
 #endif

 #ifndef YY_cequal_parser_LEX_BODY
  #define YY_cequal_parser_LEX_BODY  
 #endif

 #ifndef YY_cequal_parser_ERROR_BODY
  #define YY_cequal_parser_ERROR_BODY  
 #endif

 #ifndef YY_cequal_parser_CONSTRUCTOR_PARAM
  #define YY_cequal_parser_CONSTRUCTOR_PARAM
 #endif
 /* choose between enum and const */
 #ifndef YY_cequal_parser_USE_CONST_TOKEN
  #define YY_cequal_parser_USE_CONST_TOKEN 0
  /* yes enum is more compatible with flex,  */
  /* so by default we use it */ 
 #endif
 #if YY_cequal_parser_USE_CONST_TOKEN != 0
  #ifndef YY_cequal_parser_ENUM_TOKEN
   #define YY_cequal_parser_ENUM_TOKEN yy_cequal_parser_enum_token
  #endif
 #endif

class YY_cequal_parser_CLASS YY_cequal_parser_INHERIT
{
public: 
 #if YY_cequal_parser_USE_CONST_TOKEN != 0
  /* static const int token ... */
  
 #line 212 "/usr/share/bison++/bison.h"
static const int T_RES_VAR;
static const int T_RES_BOOL;
static const int T_RES_STR;
static const int T_RES_INT;
static const int T_RES_IF;
static const int T_RES_ELSE;
static const int T_RES_FOR;
static const int T_RES_WHILE;
static const int T_RES_SKIP;
static const int T_RES_STOP;
static const int T_RES_DEF;
static const int T_RES_RETURN;
static const int T_RES_READ;
static const int T_RES_WRITE;
static const int T_SYM_OP;
static const int T_SYM_CP;
static const int T_SYM_OBK;
static const int T_SYM_CBK;
static const int T_SYM_OBC;
static const int T_SYM_CBC;
static const int T_SYM_ATR;
static const int T_SYM_ATP;
static const int T_SYM_ATM;
static const int T_SYM_ATMUL;
static const int T_SYM_ATDIV;
static const int T_SYM_ATMOD;
static const int T_SYM_PLS;
static const int T_SYM_MIN;
static const int T_SYM_MUL;
static const int T_SYM_DIV;
static const int T_SYM_MOD;
static const int T_SYM_EQL;
static const int T_SYM_DIF;
static const int T_SYM_HIG;
static const int T_SYM_HEQ;
static const int T_SYM_LES;
static const int T_SYM_LEQ;
static const int T_SYM_OR;
static const int T_SYM_AND;
static const int T_SYM_NOT;
static const int T_SYM_SMC;
static const int T_SYM_CMA;
static const int T_SYM_INTR;
static const int T_SYM_COL;
static const int T_ID;
static const int T_LIT_INT;
static const int T_LIT_STR;
static const int T_LIT_TRUE;
static const int T_LIT_FALSE;
static const int LOWER_THEN_ELSE;
static const int UMINUS;


#line 212 "/usr/share/bison++/bison.h"
 /* decl const */
 #else
  enum YY_cequal_parser_ENUM_TOKEN { YY_cequal_parser_NULL_TOKEN=0
  
 #line 215 "/usr/share/bison++/bison.h"
	,T_RES_VAR=258
	,T_RES_BOOL=259
	,T_RES_STR=260
	,T_RES_INT=261
	,T_RES_IF=262
	,T_RES_ELSE=263
	,T_RES_FOR=264
	,T_RES_WHILE=265
	,T_RES_SKIP=266
	,T_RES_STOP=267
	,T_RES_DEF=268
	,T_RES_RETURN=269
	,T_RES_READ=270
	,T_RES_WRITE=271
	,T_SYM_OP=272
	,T_SYM_CP=273
	,T_SYM_OBK=274
	,T_SYM_CBK=275
	,T_SYM_OBC=276
	,T_SYM_CBC=277
	,T_SYM_ATR=278
	,T_SYM_ATP=279
	,T_SYM_ATM=280
	,T_SYM_ATMUL=281
	,T_SYM_ATDIV=282
	,T_SYM_ATMOD=283
	,T_SYM_PLS=284
	,T_SYM_MIN=285
	,T_SYM_MUL=286
	,T_SYM_DIV=287
	,T_SYM_MOD=288
	,T_SYM_EQL=289
	,T_SYM_DIF=290
	,T_SYM_HIG=291
	,T_SYM_HEQ=292
	,T_SYM_LES=293
	,T_SYM_LEQ=294
	,T_SYM_OR=295
	,T_SYM_AND=296
	,T_SYM_NOT=297
	,T_SYM_SMC=298
	,T_SYM_CMA=299
	,T_SYM_INTR=300
	,T_SYM_COL=301
	,T_ID=302
	,T_LIT_INT=303
	,T_LIT_STR=304
	,T_LIT_TRUE=305
	,T_LIT_FALSE=306
	,LOWER_THEN_ELSE=307
	,UMINUS=308


#line 215 "/usr/share/bison++/bison.h"
 /* enum token */
     }; /* end of enum declaration */
 #endif
public:
 int YY_cequal_parser_PARSE(YY_cequal_parser_PARSE_PARAM);
 virtual void YY_cequal_parser_ERROR(char *msg) YY_cequal_parser_ERROR_BODY;
 #ifdef YY_cequal_parser_PURE
  #ifdef YY_cequal_parser_LSP_NEEDED
   virtual int  YY_cequal_parser_LEX(YY_cequal_parser_STYPE *YY_cequal_parser_LVAL,YY_cequal_parser_LTYPE *YY_cequal_parser_LLOC) YY_cequal_parser_LEX_BODY;
  #else
   virtual int  YY_cequal_parser_LEX(YY_cequal_parser_STYPE *YY_cequal_parser_LVAL) YY_cequal_parser_LEX_BODY;
  #endif
 #else
  virtual int YY_cequal_parser_LEX() YY_cequal_parser_LEX_BODY;
  YY_cequal_parser_STYPE YY_cequal_parser_LVAL;
  #ifdef YY_cequal_parser_LSP_NEEDED
   YY_cequal_parser_LTYPE YY_cequal_parser_LLOC;
  #endif
  int YY_cequal_parser_NERRS;
  int YY_cequal_parser_CHAR;
 #endif
 #if YY_cequal_parser_DEBUG != 0
  public:
   int YY_cequal_parser_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
 #endif
public:
 YY_cequal_parser_CLASS(YY_cequal_parser_CONSTRUCTOR_PARAM);
public:
 YY_cequal_parser_MEMBERS 
};
/* other declare folow */
#endif


#if YY_cequal_parser_COMPATIBILITY != 0
 /* backward compatibility */
 /* Removed due to bison problems
 /#ifndef YYSTYPE
 / #define YYSTYPE YY_cequal_parser_STYPE
 /#endif*/

 #ifndef YYLTYPE
  #define YYLTYPE YY_cequal_parser_LTYPE
 #endif
 #ifndef YYDEBUG
  #ifdef YY_cequal_parser_DEBUG 
   #define YYDEBUG YY_cequal_parser_DEBUG
  #endif
 #endif

#endif
/* END */

 #line 267 "/usr/share/bison++/bison.h"
#endif
