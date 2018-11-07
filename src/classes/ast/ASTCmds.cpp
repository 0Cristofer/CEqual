/* Abstract Syntax Tree command list
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 07/11/2018
   Edited: 07/1/2018 */

#include <iostream>
#include "src/classes/ast/include/ASTCmds.hpp"

ASTCmds::ASTCmds() : AST(CMDS) {
}

Value *ASTCmds::inEval() {
    for(AST* a : children){
        a->eval();
    }

    return nullptr;
}

void ASTCmds::printNode() {
    std::cout << "Node type: ASTCmds" << std::endl;

}
