/* Abstract Syntax Tree array declaration list
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 07/11/2018
   Edited: 07/11/2018 */

#include <iostream>

#include "src/classes/ast/include/ASTListDec.hpp"

ASTListDec::ASTListDec(AST* child) : AST(LISTDEC) {
    children.push_back(child);
}

Value *ASTListDec::inEval() {
    for(AST* a : children){
        a->eval();
    }

    return nullptr;
}

void ASTListDec::printNode() {
    std::cout << "Node type: ASTListDec" << std::endl;
}
