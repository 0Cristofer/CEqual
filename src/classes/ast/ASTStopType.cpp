/* Abstract Syntax Tree stop types class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 16/11/2018
   Edited: 17/11/2018 */

#include <iostream>

#include "include/ASTStopType.hpp"

ASTStopType::ASTStopType(SType stop, AST* exp) : AST(CMDSTOP), stype(stop) {
    if(exp) addChild(exp);
}

Value *ASTStopType::inEval() {
    auto *stop = new StopType(stype);

    if(stype == RETURN){
        if(!children.empty()){
            stop->val = children[0]->eval();
        }
    }

    return stop;
}

void ASTStopType::printNode() {
    std::cout << "Node type: ASTStopType" << std::endl;
}
