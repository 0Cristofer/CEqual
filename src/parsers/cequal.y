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
  #include "src/classes/value/include/LiteralStr.hpp"

  bool declaring = false;
  Scope* actual_scope;
  AST* main_proc;
  AST* first;
%}

%union{
  AST* ast;
  Literal* literal;
  Symbol* sym;
  LiteralType l_type;
  std::string* sym_name;
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
%type <ast> expression literal callFunc
%type <ast> listDec dec decVar listSpecVar specVar
%type <ast> specVarSim specVarSimInit specVarArr specVarArrInit arrInit
%type <ast> block varUse cmds cmd simCmd
%type <ast> paramSpec paramDef paramList decProc decFunc decSub expList
%type <ast> cmdWrite
%type <l_type> type

%start program

%%

/* Rules for CEqual syntax parser */

/* Start rules */

program:
  listDec {first = $1;}
;

listDec:
  dec {$$ = new ASTListDec($1, actual_scope);}
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
  T_RES_VAR listSpecVar T_SYM_COL type T_SYM_SMC {$$ = new ASTDecVar($2, $4, actual_scope);}
;

listSpecVar:
  specVar {$$ = new ASTListSpecVar($1, actual_scope);}
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
  id {$$ = new ASTSpecVar($1, SIMVAR, actual_scope);}
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
                                      $$ = new ASTSpecVar($1, ARRAYVAR, actual_scope);
                                   }
;

specVarArrInit:
  specVarArr T_SYM_ATR T_SYM_OBC arrInit T_SYM_CBC {
                                                      $$ = $1;
                                                      $1->addChild($4);
                                                   }
;

arrInit:
  literal {$$ = new ASTArrayInit($1, actual_scope);}
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

// Starting a new function, should start a new scope
startfunc:
  T_RES_DEF id T_SYM_OP {
                          $$ = $2;
                          actual_scope->addSym($2);
                          actual_scope = new Scope(actual_scope);
                          declaring = true;
                        }
;

decProc:
  startfunc paramList T_SYM_CP block {
                                        $$ = new ASTDecSub(actual_scope, $2, $4, INT);
                                        $1->type = PROC;
                                        $1->proc = $$;
                                     }
;

decFunc:
  startfunc paramList T_SYM_CP T_SYM_COL type block {
                                                      $$ = new ASTDecSub(actual_scope, $2, $6, $5);
                                                      $1->type = FUNC;
                                                      $1->proc = $$;

                                                      if($1->id->compare("main") == 0) main_proc = $$;
                                                    }
;

paramList:
            {$$ = nullptr;}
  |paramDef {$$ = new ASTParamList($1, actual_scope);}
  |paramDef T_SYM_SMC paramList {
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
  param {$$ = new ASTParamSpec($1, actual_scope);}
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
  T_LIT_INT    {$$ = new ASTLiteral(yylval.literal, actual_scope);}
  |T_LIT_STR   {$$ = new ASTLiteral(yylval.literal, actual_scope);}
  |T_LIT_TRUE  {$$ = new ASTLiteral(yylval.literal, actual_scope);}
  |T_LIT_FALSE {$$ = new ASTLiteral(yylval.literal, actual_scope);}
;

type:
  T_RES_INT   {$$ = INT;}
  |T_RES_BOOL {$$ = BOOL;}
  |T_RES_STR  {$$ = STR;}
;

// Starting a new block, so we need to verify if it is a function block.
// If it is a function block, the scope is already initialized, otherwise start a new one
startblock:
  T_SYM_OBC {
              if(!declaring){
                actual_scope = new Scope(actual_scope);
              }
              else{
                declaring = false;
              }
            }
;

// When the block ends, its scope is finalized and the actual scope is the previus one
block:
  startblock listDec cmds T_SYM_CBC {
                                      $$ = new ASTBlock(actual_scope);
                                      actual_scope = actual_scope->prev;
                                      $$->addChild($3);
                                      $$->addChild($2);
                                    }
  |startblock cmds T_SYM_CBC {
                                $$ = new ASTBlock(actual_scope);
                                actual_scope = actual_scope->prev;
                                $$->addChild($2);
                             }
;

varUse:
  id {$$ = new ASTVarUse($1, NULL, actual_scope);}
  |id T_SYM_OBK expression T_SYM_CBK {$$ = new ASTVarUse($1, $3, actual_scope);}
;

// Creates a AST for each expression.
expression:
  expression T_SYM_INTR expression T_SYM_COL expression {$$ = new ASTExpression(TERN, NOOPERAND, $3, $5, $1, actual_scope);}
  |expression T_SYM_OR expression    {$$ = new ASTExpression(LOGIC, OR, $1, $3, NULL, actual_scope);}
  |expression T_SYM_AND expression   {$$ = new ASTExpression(LOGIC, AND, $1, $3, NULL, actual_scope);}
  |expression T_SYM_EQL expression   {$$ = new ASTExpression(COMP, EQL, $1, $3, NULL, actual_scope);}
  |expression T_SYM_DIF expression   {$$ = new ASTExpression(COMP, DIF, $1, $3, NULL, actual_scope);}
  |expression T_SYM_GRT expression   {$$ = new ASTExpression(COMP, GRT, $1, $3, NULL, actual_scope);}
  |expression T_SYM_GRE expression   {$$ = new ASTExpression(COMP, GRE, $1, $3, NULL, actual_scope);}
  |expression T_SYM_LES expression   {$$ = new ASTExpression(COMP, LES, $1, $3, NULL, actual_scope);}
  |expression T_SYM_LEQ expression   {$$ = new ASTExpression(COMP, LEQ, $1, $3, NULL, actual_scope);}
  |expression T_SYM_PLS expression   {$$ = new ASTExpression(ARITM, PLUS, $1, $3, NULL, actual_scope);}
  |expression T_SYM_MIN expression   {$$ = new ASTExpression(ARITM, MINUS, $1, $3, NULL, actual_scope);}
  |expression T_SYM_MUL expression   {$$ = new ASTExpression(ARITM, MUL, $1, $3, NULL, actual_scope);}
  |expression T_SYM_DIV expression   {$$ = new ASTExpression(ARITM, DIV, $1, $3, NULL, actual_scope);}
  |expression T_SYM_MOD expression   {$$ = new ASTExpression(ARITM, MOD, $1, $3, NULL, actual_scope);}
  |T_SYM_NOT expression              {$$ = new ASTExpression(LOGIC, NOT, $2, NULL, NULL, actual_scope);}
  |T_SYM_MIN expression %prec UMINUS {$$ = new ASTExpression(ARITM, U_MINUS, $2, NULL, NULL, actual_scope);}
  |T_SYM_OP expression T_SYM_CP      {$$ = $2;}
  |literal                           {$$ = $1;}
  |varUse                            {$$ = $1;}
  |callFunc
;

/* A chamada de função deve procurar na tabela de símbolos o id da função.
   Para chamar, utilizar a função call() do nó guardado na símbolo passando
   a lista de expressões.
*/
callFunc:
  id T_SYM_OP expList T_SYM_CP {$$ = new ASTCallProc(actual_scope, $1, $3, FUNC);}
;

expList:
    {$$ = nullptr;}
  |expression {$$ = new ASTExpList($1, actual_scope);}
  |expression T_SYM_CMA expList {
                                  $$ = $3;
                                  $3->addChild($1);
                                }
;

/* Commands */

cmds:
    {$$ = new ASTCmds(actual_scope);}
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
  /*cmdAtrib
  |cmdIf
  |cmdWhile
  |cmdFor
  |cmdStop
  |cmdSkip
  |cmdReturn
  |cmdCallProc
  |cmdRead*/
  cmdWrite {$$ = $1;}
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
  T_RES_WRITE expList T_SYM_SMC {$$ = new ASTCmdWrite($2, actual_scope);}
  |T_RES_WRITE varUse T_SYM_SMC {$$ = new ASTCmdWrite($2, actual_scope);}
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
  ((ASTDecSub*)main_proc)->call(nullptr);

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
