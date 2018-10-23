/* Abstract Syntax Tree abstract class definitions.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 18/10/2018 */

#include <cstdlib>

#include "include/AST.hpp"

AST::AST(ASTType t): a_type(t){

}

void AST::addChild(AST* ast){
    children.push_back(ast);
}

Value* AST::eval(){
    Value* res = this->inEval(); // Calls the main evaluation of the node

    for(AST* ast : children){
        free(ast);
    }

    return res;
}
