/* Abstract Syntax Tree block
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 07/11/2018 */

#include <iostream>

#include "include/ASTBlock.hpp"

ASTBlock::ASTBlock(Scope* s): AST(BLOCK), scope(s){

}

// TODO
Value* ASTBlock::inEval(){
    for(AST* child : children){
        child->eval();
    }
    free(scope);
    return nullptr;
}

void ASTBlock::printNode(){
    std::cout << "Node type: ASTBlock" << std::endl;
}
