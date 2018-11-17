/* Abstract Syntax Tree block
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 16/11/2018 */

#include <iostream>

#include "include/ASTBlock.hpp"
#include "../value/include/StopType.hpp"

ASTBlock::ASTBlock(Scope *s): AST(BLOCK, s) {

}

Value *ASTBlock::inEval() {
    Value* v;

    // Children must be evaluated in inverse order because of the botton-up read
    for(auto it = children.rbegin(); it != children.rend(); ++it){
        v = (*it)->eval();

        if(v){
            if(v->type == STOPTYPE){
                return v;
            }
        }
    }

    v = new StopType(END);

    return v;
}

void ASTBlock::printNode(){
    std::cout << "Node type: ASTBlock" << std::endl;
}
