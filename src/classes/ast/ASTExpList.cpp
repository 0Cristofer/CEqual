/* Abstract Syntax Tree abstract class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 07/11/2018 */

#include "src/classes/ast/include/ASTExpList.hpp"

ASTExpList::ASTExpList(AST* a, Scope *s) : AST(EXPLIST, s) {
    addChild(a);
}

Value *ASTExpList::inEval() {
    vals = new std::vector<Value*>();

    for(AST* a: children){
        vals->push_back(a->eval());
    }

    return nullptr;
}
