/* Abstract Syntax Tree expression list class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 12/11/2018
   Edited: 17/11/2018 */

#include <iostream>

#include "include/ASTExpList.hpp"

ASTExpList::ASTExpList(AST* a) : AST(EXPLIST) {
    addChild(a);
}

Value *ASTExpList::inEval() {
    vals = new std::vector<Value *>();

    for(auto it = children.rbegin(); it != children.rend(); ++it){
        vals->push_back((*it)->eval());
    }

    return nullptr;
}

void ASTExpList::printNode() {
    std::cout << "Node type: ASTExpList" << std::endl;
}
