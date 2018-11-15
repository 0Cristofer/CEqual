/* Abstract Syntax Tree block
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 07/11/2018 */

#include <iostream>

#include "include/ASTBlock.hpp"

ASTBlock::ASTBlock(Scope *s): AST(BLOCK, s) {

}

Value *ASTBlock::inEval() {
    // Children must be evaluated in inverse order because of the botton-up read
    for(auto it = children.rbegin(); it != children.rend(); ++it){
        (*it)->eval();
    }

    return nullptr;
}

void ASTBlock::printNode(){
    std::cout << "Node type: ASTBlock" << std::endl;
}
