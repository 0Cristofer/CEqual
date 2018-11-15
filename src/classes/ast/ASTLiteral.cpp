/* Abstract Syntax Tree literal node definitions
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 07/11/2018 */

#include <iostream>

#include "include/ASTLiteral.hpp"
#include "../value/include/LiteralInt.hpp"

ASTLiteral::ASTLiteral(Literal *lit, Scope *s): AST(LITERAL, s), literal(lit){

}

Value *ASTLiteral::inEval(){
    return literal;
}

void ASTLiteral::printNode(){
    std::cout << "Node type: ASTLiteral" << std::endl;
}
