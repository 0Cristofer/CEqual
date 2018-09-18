/* CEqual syntactic definition file
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Date: 09/18/2018 */

%{
  #include <stdio.h>

  void yyerror(char* s);
  int yylex();
%}

%name cequal_parser

/* Reserved words */

%token T_RES_VAR T_RES_BOOL T_RES_STR T_RES_INT
%token T_RES_TRUE T_RES_FALSE
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
/* ''' and '"' */
%token T_SYM_QS T_SYM_QD
/* Attributions (=, +=, -=, *=, /=, %=) */
%token T_SYM_AT T_SYM_ATP T_SYM_ATM T_SYM_ATMUL T_SYM_ATDIV T_SYM_ATMOD
/* Operators (+, -, *, /, %, ==, !=, >, >=, <, <=, ||, &&, !)*/
%token T_SYM_PLS T_SYM_MIN T_SYM_MUL T_SYM_DIV T_SYM_MOD T_SYM_EQL T_SYM_DIF
%token T_SYM_HIG T_SYM_HEQ T_SYM_LES T_SYM_LEQ T_SYM_OR T_SYM_AND T_SYM_NOT
/* Separators (;, ,, ?, :)*/
%token T_SYM_SMC T_SYM_CMA T_SYM_INTR T_SYM_COL

/* Etc. */

%token T_ID
/* Literals */
%token T_LIT_INT T_LIT_STR
%token T_EOL

%%

program: {printf("%d\n", $$)};

%%

int main(int argc, char** argv){
  yyparse();
  return 0;
}

void yyerror(char* s){
  fprintf(stderr, "Error: %s\n", s);
}
