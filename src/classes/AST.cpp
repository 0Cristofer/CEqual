/* Abstract Syntax Tree abstract class definitions.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Date: 15/10/2018 */

#include <iostream>

#include "include/AST.hpp"

AST::AST(ASTType t): type(t){

}

void AST::addChildren(AST* ast){
  children.push_back(ast);
}
