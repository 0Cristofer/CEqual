/* CEqual syntactic definition file
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 9/9/2018
   Edited: 18/10/2018 */

%{
  #include <iostream>

  #include "src/include/util.hpp"
  #include "src/classes/ast/include/ASTLiteral.hpp"
  #include "src/classes/ast/include/ASTExpression.hpp"
  #include "src/classes/ast/include/ASTSpecVar.hpp"
  #include "src/classes/ast/include/ASTListSpecVar.hpp"
  #include "src/classes/ast/include/ASTArrayInit.hpp"
  #include "src/classes/ast/include/ASTDecVar.hpp"
  #include "src/classes/ast/include/ASTBlock.hpp"
  #include "src/classes/ast/include/ASTVarUse.hpp"
  #include "src/classes/ast/include/ASTCmdWrite.hpp"
  #include "src/classes/ast/include/ASTCmds.hpp"
  #include "src/classes/ast/include/ASTListDec.hpp"
  #include "src/classes/ast/include/ASTParamSpec.hpp"
  #include "src/classes/ast/include/ASTParamList.hpp"
  #include "src/classes/ast/include/ASTDecSub.hpp"
  #include "src/classes/ast/include/ASTExpList.hpp"
  #include "src/classes/ast/include/ASTCallProc.hpp"
  #include "src/classes/ast/include/ASTCmdAtrib.hpp"
  #include "src/classes/ast/include/ASTCmdRead.hpp"
  #include "src/classes/ast/include/ASTCmdIf.hpp"
  #include "src/classes/ast/include/ASTCmdWhile.hpp"
  #include "src/classes/ast/include/ASTCmdFor.hpp"
  #include "src/classes/ast/include/ASTStopType.hpp"
  #include "src/classes/value/include/LiteralStr.hpp"

  bool declaring = false;
  Scope* actual_scope;
  AST* main_proc = nullptr;
  AST* first;
%}

%union{
  AST* ast;
  Literal* literal;
  Symbol* sym;
  LiteralType l_type;
  std::string* sym_name;
  ATRT t;
}

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
%token <op> T_SYM_PLS T_SYM_MIN T_SYM_MUL T_SYM_DIV T_SYM_MOD T_SYM_EQL T_SYM_DIF
%token <op> T_SYM_GRT T_SYM_GRE T_SYM_LES T_SYM_LEQ T_SYM_OR T_SYM_AND T_SYM_NOT
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

%type <sym> id param startfunc
%type <ast> expression literal callFunc expressionSequence paramSequence
%type <ast> listDec dec decVar listSpecVar specVar startBlock
%type <ast> specVarSim specVarSimInit specVarArr specVarArrInit arrInit
%type <ast> block varUse cmds cmd simCmd cmdCallProc cmdAtrib atrib
%type <ast> paramSpec paramDef paramList decProc decFunc decSub expList
%type <ast> cmdWrite cmdRead cmdIf cmdWhile cmdFor cmdSkip cmdStop cmdReturn
%type <t> atrbSym
%type <l_type> type

%start program

%%

/* Rules for CEqual syntax parser */

/* Start rules */

program:
  listDec {first = $1;}
;

listDec:
  dec {$$ = new ASTListDec($1);}
  |dec listDec{
                $2->addChild($1);
                $$ = $2;
              }
;

dec:
  decVar {$$ = $1;}
  |decSub {$$ = $1;}
;

/* Variable declaration rules. TODO: String specifics */

decVar:
  T_RES_VAR listSpecVar T_SYM_COL type T_SYM_SMC {$$ = new ASTDecVar($2, $4);}
;

listSpecVar:
  specVar {$$ = new ASTListSpecVar($1);}
  |specVar T_SYM_CMA listSpecVar {
                                    $3->addChild($1);
                                    $$ = $3;
                                  }
;

specVar:
  specVarSim      {$$ = $1;}
  |specVarSimInit {$$ = $1;}
  |specVarArr     {$$ = $1;}
  |specVarArrInit {$$ = $1;}
;

specVarSim:
  id {$$ = new ASTSpecVar($1, SIMVAR);}
;

specVarSimInit:
  specVarSim T_SYM_ATR expression {
                                    $$ = $1;
                                    $1->addChild($3);
                                  }
;

specVarArr:
  id T_SYM_OBK T_LIT_INT T_SYM_CBK {
                                      $1->size = ((LiteralInt*)yylval.literal)->val;
                                      free(yylval.literal);
                                      $$ = new ASTSpecVar($1, ARRAYVAR);
                                   }
;

specVarArrInit:
  specVarArr T_SYM_ATR T_SYM_OBC arrInit T_SYM_CBC {
                                                      $$ = $1;
                                                      $1->addChild($4);
                                                   }
;

arrInit:
  literal {$$ = new ASTArrayInit($1);}
  |literal T_SYM_CMA arrInit {
                                $3->addChild($1);
                                $$ = $3;
                             }
;

/* Routine declaration rules */

decSub:
  decProc {$$ = $1;}
  |decFunc {$$ = $1;}
;

/*
  Mudar a instanciação do escopo para dentro da avaliação do bloco. O bloco
  será responsável por instânciar e destruir o escopo dele toda vez que for
  avaliado. O escopo é instânciado no inicio da avaliação e destruído no final.
  A chamada de função deve ser responsável por "desempilhar" o escopo atual, já
  que o fluxo será alterado para um novo escopo, que será instânciado pelo bloco
  do procedimento.
*/

// Starting a new function, should start a new scope
startfunc:
  T_RES_DEF id T_SYM_OP {
                          $$ = $2;
                          actual_scope->addSym($2);
                          declaring = true;
                        }
;

decProc:
  startfunc paramList T_SYM_CP block {
                                        $$ = new ASTDecSub($2, $4, VOID);
                                        $1->state = DEFINED;
                                        $1->type = PROC;
                                        $1->proc = $$;
                                     }
;

decFunc:
  startfunc paramList T_SYM_CP T_SYM_COL type block {
                                                      $$ = new ASTDecSub($2, $6, $5);
                                                      $1->state = DEFINED;
                                                      $1->type = FUNC;
                                                      $1->proc = $$;

                                                      if($1->id->compare("main") == 0) main_proc = $$;
                                                    }
;

paramList:
    {$$ = nullptr;}
  |paramSequence {$$ = $1;}
;

paramSequence:
    paramDef {$$ = new ASTParamList($1);}
    |paramDef T_SYM_SMC paramSequence {
                                        $$ = $3;
                                        $3->addChild($1);
                                      }
;

paramDef:
  paramSpec T_SYM_COL type {
                                ((ASTParamSpec*)$1)->type = $3;
                                $$ = $1;
                           }
;

paramSpec:
  param {$$ = new ASTParamSpec($1);}
  |param T_SYM_CMA paramSpec {
                                $$ = $3;
                                ((ASTParamSpec*)$3)->addSymbol($1);
                             }
;

param:
  id {
      $1->type = SIM;
      $$ = $1;
     }
  |id T_SYM_OBK T_SYM_CBK {
                            $1->type = ARRAY;
                            $$ = $1;
                          }
;

/* Basic rules */

// Found a identifier, so we need to make a new symbol and add to the actual scope symbol table
id:
  T_ID {
          $$ = new Symbol(yylval.sym_name, yylineno);
        }
;

literal:
  T_LIT_INT    {$$ = new ASTLiteral(yylval.literal);}
  |T_LIT_STR   {$$ = new ASTLiteral(yylval.literal);}
  |T_LIT_TRUE  {$$ = new ASTLiteral(yylval.literal);}
  |T_LIT_FALSE {$$ = new ASTLiteral(yylval.literal);}
;

type:
  T_RES_INT   {$$ = INT;}
  |T_RES_BOOL {$$ = BOOL;}
  |T_RES_STR  {$$ = STR;}
;

// When the block ends, its scope is finalized and the actual scope is the previus one
startBlock:
  T_SYM_OBC {$$ = new ASTBlock();}
;

block:
  startBlock listDec cmds T_SYM_CBC {
                                      $$ = $1;
                                      $$->addChild($3);
                                      $$->addChild($2);
                                    }
  |startBlock cmds T_SYM_CBC {
                                $$ = $1;
                                $$->addChild($2);
                             }
;

varUse:
  id {$$ = new ASTVarUse($1, NULL);}
  |id T_SYM_OBK expression T_SYM_CBK {$$ = new ASTVarUse($1, $3);}
;

// Creates a AST for each expression.
expression:
  expression T_SYM_INTR expression T_SYM_COL expression {$$ = new ASTExpression(TERN, NOOPERAND, $3, $5, $1);}
  |expression T_SYM_OR expression    {$$ = new ASTExpression(LOGIC, OR, $1, $3, NULL);}
  |expression T_SYM_AND expression   {$$ = new ASTExpression(LOGIC, AND, $1, $3, NULL);}
  |expression T_SYM_EQL expression   {$$ = new ASTExpression(COMP, EQL, $1, $3, NULL);}
  |expression T_SYM_DIF expression   {$$ = new ASTExpression(COMP, DIF, $1, $3, NULL);}
  |expression T_SYM_GRT expression   {$$ = new ASTExpression(COMP, GRT, $1, $3, NULL);}
  |expression T_SYM_GRE expression   {$$ = new ASTExpression(COMP, GRE, $1, $3, NULL);}
  |expression T_SYM_LES expression   {$$ = new ASTExpression(COMP, LES, $1, $3, NULL);}
  |expression T_SYM_LEQ expression   {$$ = new ASTExpression(COMP, LEQ, $1, $3, NULL);}
  |expression T_SYM_PLS expression   {$$ = new ASTExpression(ARITM, PLUS, $1, $3, NULL);}
  |expression T_SYM_MIN expression   {$$ = new ASTExpression(ARITM, MINUS, $1, $3, NULL);}
  |expression T_SYM_MUL expression   {$$ = new ASTExpression(ARITM, MUL, $1, $3, NULL);}
  |expression T_SYM_DIV expression   {$$ = new ASTExpression(ARITM, DIV, $1, $3, NULL);}
  |expression T_SYM_MOD expression   {$$ = new ASTExpression(ARITM, MOD, $1, $3, NULL);}
  |T_SYM_NOT expression              {$$ = new ASTExpression(LOGIC, NOT, $2, NULL, NULL);}
  |T_SYM_MIN expression %prec UMINUS {$$ = new ASTExpression(ARITM, U_MINUS, $2, NULL, NULL);}
  |T_SYM_OP expression T_SYM_CP      {$$ = $2;}
  |literal                           {$$ = $1;}
  |varUse                            {$$ = $1;}
  |callFunc                          {$$ = $1;}
;

callFunc:
  id T_SYM_OP expList T_SYM_CP {$$ = new ASTCallProc($1, $3, FUNC);}
;

expList:
    {$$ = nullptr;}
  |expressionSequence {$$ = $1;}
;

expressionSequence:
    expression {$$ = new ASTExpList($1);}
    |expression T_SYM_CMA expressionSequence {
                                                $$ = $3;
                                                $3->addChild($1);
                                             }
;

/* Commands */

cmds:
    {$$ = new ASTCmds();}
  |cmd cmds {
              $2->addChild($1);
              $$ = $2;
            }
;

cmd:
  simCmd {$$ = $1;}
  |block {$$ = $1;}
;

simCmd:
  cmdAtrib     {$$ = $1;}
  |cmdIf       {$$ = $1;}
  |cmdWhile    {$$ = $1;}
  |cmdFor      {$$ = $1;}
  |cmdStop     {$$ = $1;}
  |cmdSkip     {$$ = $1;}
  |cmdReturn   {$$ = $1;}
  |cmdCallProc {$$ = $1;}
  |cmdRead     {$$ = $1;}
  |cmdWrite    {$$ = $1;}
;

cmdAtrib:
  atrib T_SYM_SMC {$$ = $1;}
;

atrib:
  varUse atrbSym expression {$$ = new ASTCmdAtrib($1, $3, $2);}
;

atrbSym:
  T_SYM_ATR    {$$ = ATR;}
  |T_SYM_ATP   {$$ = ATP;}
  |T_SYM_ATM   {$$ = ATM;}
  |T_SYM_ATMUL {$$ = ATMUL;}
  |T_SYM_ATDIV {$$ = ATDIV;}
  |T_SYM_ATMOD {$$ = ATMOD;}
;

cmdIf:
  T_RES_IF T_SYM_OP expression T_SYM_CP cmd %prec LOWER_THEN_ELSE {$$ = new ASTCmdIf($5, nullptr, $3);}
  |T_RES_IF T_SYM_OP expression T_SYM_CP cmd T_RES_ELSE cmd {$$ = new ASTCmdIf($5, $7, $3);}
;

cmdWhile:
  T_RES_WHILE T_SYM_OP expression T_SYM_CP cmd {$$ = new ASTCmdWhile($5, $3);}
;

cmdFor:
  T_RES_FOR T_SYM_OP atrib T_SYM_SMC expression T_SYM_SMC atrib T_SYM_CP cmd {$$ = new ASTCmdFor($3, $7, $9, $5);}
;

cmdStop:
  T_RES_STOP T_SYM_SMC {$$ = new ASTStopType(STOP, nullptr);}
;

cmdSkip:
  T_RES_SKIP T_SYM_SMC {$$ = new ASTStopType(SKIP, nullptr);}
;

cmdReturn:
  T_RES_RETURN T_SYM_SMC {$$ = new ASTStopType(RETURN, nullptr);}
  |T_RES_RETURN expression T_SYM_SMC {$$ = new ASTStopType(RETURN, $2);}
;

cmdCallProc:
  id T_SYM_OP expList T_SYM_CP T_SYM_SMC {$$ = new ASTCallProc($1, $3, PROC);}
;

cmdRead:
  T_RES_READ varUse T_SYM_SMC {$$ = new ASTCmdRead($2);}
;

cmdWrite:
  T_RES_WRITE expList T_SYM_SMC {$$ = new ASTCmdWrite($2);}
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

  actual_scope = new Scope(NULL);

  yyparse();

  first->eval();

  if(main_proc == nullptr){
    std::cerr << "No main function, aborting." << std::endl;
    return 0;
  }

  ((ASTDecSub*)main_proc)->call(nullptr, false);

  free(actual_scope);

  return 0;
}

void yyerror(std::string s){
  std::cerr << "Syntax error at line " << yylineno << ". Message: " << s << std::endl;
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
