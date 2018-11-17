/* Abstract Syntax Tree command list
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 07/11/2018
   Edited: 17/11/2018 */

#include <iostream>

#include "include/ASTCmds.hpp"

ASTCmds::ASTCmds() : AST(CMDS) {
}

Value *ASTCmds::inEval() {
    Value* v = nullptr;

    for(auto it = children.rbegin(); it != children.rend(); ++it){
        v = (*it)->eval();

        if(v){
            if(v->type == STOPTYPE){
                return v;
            }
        }
    }

    return v;
}

void ASTCmds::printNode() {
    std::cout << "Node type: ASTCmds" << std::endl;
}
