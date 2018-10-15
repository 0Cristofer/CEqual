/* CEqual syntactic definition file
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Date: 09/18/2018 */

%{
  #include <iostream>

  //#define STRARGS ("a:b:c:d:t:h")

  extern int yylex();
  extern int yyparse();
  extern FILE *yyin;
  extern int yylineno;

  void yyerror(std::string s);
%}

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
%token T_SYM_GRT T_SYM_GRE T_SYM_LES T_SYM_LEQ T_SYM_OR T_SYM_AND T_SYM_NOT
/* Separators (;, ,, ?, :)*/
%token T_SYM_SMC T_SYM_CMA T_SYM_INTR T_SYM_COL

/* IDs */
%token T_ID

/* Literals */
%token T_LIT_INT T_LIT_STR T_LIT_TRUE T_LIT_FALSE

%nonassoc LOWER_THEN_ELSE
%nonassoc T_RES_ELSE

%right T_SYM_INTR T_SYM_COL
%left T_SYM_OR
%left T_SYM_AND
%left T_SYM_EQL T_SYM_DIF
%left T_SYM_LES T_SYM_LEQ T_SYM_GRT T_SYM_GRE
%right T_SYM_ATR T_SYM_ATP T_SYM_ATM T_SYM_ATMUL T_SYM_ATDIV T_SYM_ATMOD
%left T_SYM_PLS T_SYM_MIN
%left T_SYM_MUL T_SYM_DIV T_SYM_MOD
%right T_SYM_NOT
%right UMINUS

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

/* Variable declaration rules. TODO: String specifics */

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
  specVarSim T_SYM_ATR expression
;

specVarArr:
  id T_SYM_OBK T_LIT_INT T_SYM_CBK
;

specVarArrInit:
  specVarArr T_SYM_ATR T_SYM_OBC arrInit T_SYM_CBC
;

arrInit:
  literal
  |literal T_SYM_CMA arrInit
;

/* Routine declaration rules */

decSub:
  decProc
  |decFunc
;

decProc:
  T_RES_DEF id T_SYM_OP paramList T_SYM_CP block
;

decFunc:
  T_RES_DEF id T_SYM_OP paramList T_SYM_CP T_SYM_COL type block
;

paramList:

  |paramDef
  |paramDef T_SYM_SMC paramList
;

paramDef:
  paramSpec T_SYM_COL type
;

paramSpec:
  param
  |param T_SYM_CMA paramSpec
;

param:
  id
  |id T_SYM_OBK T_SYM_CBK
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

block:
  T_SYM_OBC blockdec T_SYM_CBC
;

blockdec:
  listDec cmds
  |cmds
;

varUse:
  id
  |id T_SYM_OBK expression T_SYM_CBK
;

expression:
  expression T_SYM_INTR expression T_SYM_COL expression
  |expression T_SYM_PLS expression
  |expression T_SYM_MIN expression
  |expression T_SYM_MUL expression
  |expression T_SYM_DIV expression
  |expression T_SYM_MOD expression
  |expression T_SYM_EQL expression
  |expression T_SYM_DIF expression
  |expression T_SYM_GRT expression
  |expression T_SYM_GRE expression
  |expression T_SYM_LES expression
  |expression T_SYM_LEQ expression
  |expression T_SYM_OR expression
  |expression T_SYM_AND expression
  |T_SYM_OP expression T_SYM_CP
  |T_SYM_NOT expression
  |T_SYM_MIN expression %prec UMINUS
  |literal
  |varUse
  |callFunc
;

callFunc:
  id T_SYM_OP expList T_SYM_CP

expList:

  |expression
  |expression T_SYM_CMA expList
;

/* Commands */

cmds:

  |cmds cmd
;

cmd:
  simCmd
  |block
;

simCmd:
  cmdAtrib
  |cmdIf
  |cmdWhile
  |cmdFor
  |cmdStop
  |cmdSkip
  |cmdReturn
  |cmdCallProc
  |cmdRead
  |cmdWrite
;

cmdAtrib:
  atrib T_SYM_SMC
;

atrib:
  varUse atrbSym expression
;

atrbSym:
  T_SYM_ATR
  |T_SYM_ATP
  |T_SYM_ATM
  |T_SYM_ATMUL
  |T_SYM_ATDIV
  |T_SYM_ATMOD
;

cmdIf:
  T_RES_IF T_SYM_OP expression T_SYM_CP cmd %prec LOWER_THEN_ELSE
  |T_RES_IF T_SYM_OP expression T_SYM_CP cmd T_RES_ELSE cmd
;

cmdWhile:
  T_RES_WHILE T_SYM_OP expression T_SYM_CP cmd
;


cmdFor:
  T_RES_FOR T_SYM_OP atrib T_SYM_SMC expression T_SYM_SMC atrib T_SYM_CP cmd
;

cmdStop:
  T_RES_STOP T_SYM_SMC
;

cmdSkip:
  T_RES_SKIP T_SYM_SMC
;

cmdReturn:
  T_RES_RETURN T_SYM_SMC
  |T_RES_RETURN expression T_SYM_SMC
;

cmdCallProc:
  id T_SYM_OP expList T_SYM_CP T_SYM_SMC
;

cmdRead:
  T_RES_READ varUse T_SYM_SMC
;

cmdWrite:
  T_RES_WRITE expList T_SYM_SMC
;

%%

int main(int argc, char** argv){

  if(argc != 2){
    std::cerr << "Invalid arguments, use: \'cequal input_file.ce\'" << std::endl;

    return 1;
  }
  else{
    yyin = fopen(argv[1], "r");

    if(!yyin){
      std::cerr << "Can't open \'" << argv[1] << "\' input file" << std::endl;

      return 1;
    }
  }

  yyparse();

  return 0;
}

void yyerror(std::string s){
  std::cerr << "Error: " << s << " at line " << yylineno << std::endl;
}

/*//Lê os argumentos com optarg
void readArgs(int argc, char** argv, args_t* args){
  extern char* optarg;
  char op;

  while((op = getopt(argc, argv, STRARGS)) != -1){
	   switch(op){
      case 'a':
        args->la = atoi(optarg);
        break;
      case 'b':
        args->ca = atoi(optarg);
        break;
      case 'c':
        args->lb = atoi(optarg);
        break;
      case 'd':
        args->cb = atoi(optarg);
        break;
      case 't':
        args->nt = atoi(optarg);
        break;
      case 'h':
        printf(HELP);
        break;
      default:
        printf("Wrong argument, showing help\n");
        printf(HELP);
        break;
     }
   }
}
*/
