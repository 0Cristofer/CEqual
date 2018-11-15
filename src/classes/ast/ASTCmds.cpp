/* Abstract Syntax Tree command list
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 07/11/2018
   Edited: 07/11/2018 */

#include <iostream>

#include "src/classes/ast/include/ASTCmds.hpp"

ASTCmds::ASTCmds(Scope *s) : AST(CMDS, s) {
}

Value *ASTCmds::inEval() {
    for(auto it = children.rbegin(); it != children.rend(); ++it){
        (*it)->eval();
    }

    return nullptr;
}

void ASTCmds::printNode() {
    std::cout << "Node type: ASTCmds" << std::endl;
}
