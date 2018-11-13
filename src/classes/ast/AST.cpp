/* Abstract Syntax Tree abstract class definitions.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 07/11/2018 */

#include <cstdlib>
#include <src/classes/ast/include/AST.hpp>

#include "src/include/util.hpp"

#include "include/AST.hpp"

AST::AST(ASTType t, Scope* s): a_type(t), scope(s){
    line = yylineno;
}

void AST::addChild(AST* ast){
    children.push_back(ast);
}

Value* AST::eval(){
    Value* res = this->inEval(); // Calls the main evaluation of the node

    for(AST* ast : children){
        if(!ast) continue;
        if((scope->prev == nullptr) && (ast->a_type == DECVAR)) free(ast); // Only free this child if it is a
                                                                           // variable declaration in the global scope
    }

    return res;
}

void AST::printNode() {

}
