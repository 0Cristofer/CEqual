/* Abstract Syntax Tree command write
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 20/10/2018
   Edited: 20/10/2018 */

#include <iostream>

#include "include/ASTCmdWrite.hpp"
#include "../value/include/LiteralInt.hpp"
#include "../value/include/LiteralBool.hpp"
#include "../value/include/LiteralStr.hpp"

ASTCmdWrite::ASTCmdWrite(AST* e): AST(CMDWRITE){
  if(e) addChild(e);
}

Value* ASTCmdWrite::inEval(){
  Value* v;

  v = children[0]->eval();

  switch (((Literal*)v)->type) {
    case INT:
      std::cout << ((LiteralInt*)v)->val << std::endl;
    case BOOL:
      std::cout << ((LiteralBool*)v)->val << std::endl;
    case STR:
      std::cout << *(((LiteralStr*)v)->val) << std::endl;
  }

  return NULL;
}

void ASTCmdWrite::printNode(){
  std::cout << "Node type: ASTLiteral" << std::endl;
}
