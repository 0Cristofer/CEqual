/* CEqual syntactic definition file
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Date: 09/18/2018 */

%{
  #include <stdio.h>

  void yyerror(char* s);
  int yylex();

  extern int yylineno;
%}

%name cequal_parser

/* Reserved words */

%token T_RES_VAR T_RES_BOOL T_RES_STR T_RES_INT
%token T_RES_IF T_RES_ELSE
%token T_RES_FOR T_RES_WHILE T_RES_SKIP T_RES_STOP
%token T_RES_DEF T_RES_RETURN
%token T_RES_READ T_RES_WRITE

/* Symbols */

/* '(' and ')' */
%token T_SYM_OP T_SYM_CP
/* '[' and ']' */
%token T_SYM_OBK T_SYM_CBK
/* '{' and '}' */
%token T_SYM_OBC T_SYM_CBC
/* Attributions (=, +=, -=, *=, /=, %=) */
%token T_SYM_ATR T_SYM_ATP T_SYM_ATM T_SYM_ATMUL T_SYM_ATDIV T_SYM_ATMOD
/* Operators (+, -, *, /, %, ==, !=, >, >=, <, <=, ||, &&, !)*/
%token T_SYM_PLS T_SYM_MIN T_SYM_MUL T_SYM_DIV T_SYM_MOD T_SYM_EQL T_SYM_DIF
%token T_SYM_HIG T_SYM_HEQ T_SYM_LES T_SYM_LEQ T_SYM_OR T_SYM_AND T_SYM_NOT
/* Separators (;, ,, ?, :)*/
%token T_SYM_SMC T_SYM_CMA T_SYM_INTR T_SYM_COL

/* IDs */
%token T_ID

/* Literals */
%token T_LIT_INT T_LIT_STR T_LIT_TRUE T_LIT_FALSE

%token T_EOL T_EOF

%start program

%%

/* Rules for CEqual syntax parser */

/* Start rules */

program:
  listDec
;

listDec:
  dec
  |listDec dec
;

dec:
  decVar
  |decSub
;

/* Variable declaration rules */

decVar:
  T_RES_VAR listVarSpecs T_SYM_COL type T_SYM_SMC
;

listVarSpecs:
  specVar
  |specVar T_SYM_CMA listVarSpecs
;

specVar:
  specVarSim
  |specVarSimInit
  |specVarArr
  |specVarArrInit
;

specVarSim:
  id
;

specVarSimInit:
  specVarSim T_SYM_ATR literal
;

specVarArr:
  id T_SYM_OBK T_LIT_INT T_SYM_CBK
;

specVarArrInit:
  specVarArr T_SYM_ATR T_SYM_OBC arrInit T_SYM_CBC
;

arrInit:
  T_LIT_INT
  |T_LIT_INT T_SYM_CMA arrInit
;

/* Routine declaration rules */

decSub:
  T_ID
;

/* Basic rules */

id:
  T_ID
;

literal:
  T_LIT_INT
  |T_LIT_STR
  |T_LIT_TRUE
  |T_LIT_FALSE
;

type:
  T_RES_INT
  |T_RES_BOOL
  |T_RES_STR
;

%%

int main(int argc, char** argv){
  yyparse();

  return 0;
}

void yyerror(char* s){
  fprintf(stderr, "Error: %s at line %d\n", s, yylineno);
}
