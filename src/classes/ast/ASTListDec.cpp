/* Abstract Syntax Tree array declaration list
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 07/11/2018
   Edited: 16/11/2018 */

#include <iostream>

#include "src/classes/ast/include/ASTListDec.hpp"

ASTListDec::ASTListDec(AST *child, Scope *s) : AST(LISTDEC, s) {
    children.push_back(child);
}

Value *ASTListDec::inEval() {
    Value* v = nullptr;

    for(auto it = children.rbegin(); it != children.rend(); ++it){
        v = (*it)->eval();
    }

    return v;
}

void ASTListDec::printNode() {
    std::cout << "Node type: ASTListDec" << std::endl;
}
