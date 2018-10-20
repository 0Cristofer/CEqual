/* Util informations and routines
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 18/10/2018
   Edited: 18/10/2018 */

#include "include/util.hpp"
#include "classes/ast/include/AST.hpp"

bool typeCheck(Value* v, LiteralType t){
  bool res;

  if(!v) return true;

  switch (v->type) {
    case LITERAL:
      res = ((Literal*)v)->type == t;
      if(!res) typeError();
      break;

    default:
      std::cout << "Not implemented" << std::endl;
      break;
  }

  return res;
}

void semanticError(){
  std::cerr << "Semantic error at line " << yylineno << std::endl;
}

void typeError(){
  std::cerr << "Semantic error: type error at line " << yylineno << std::endl;
}

void arraySizeMismatchError(){
  std::cerr << "Semantic error: array initialization with more elements than specified at line " << yylineno << std::endl;
}
