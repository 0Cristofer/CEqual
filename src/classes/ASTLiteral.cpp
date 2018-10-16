/* Abstract Syntax Tree literal node definitions
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Date: 15/10/2018 */

#include <iostream>

#include "include/ASTLiteral.hpp"
#include "include/LiteralInt.hpp"

ASTLiteral::ASTLiteral(Literal* lit): AST(LITERAL), literal(lit){
}

int ASTLiteral::eval(){
  if(literal->type == INT){
    return ((LiteralInt*)literal)->val;
  }
}

void ASTLiteral::printNode(){
  std::cout << "Node type: ASTLiteral" << std::endl;
}
