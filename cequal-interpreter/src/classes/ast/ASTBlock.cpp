/* Abstract Syntax Tree block
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 17/11/2018 */

#include <iostream>

#include "include/ASTBlock.hpp"
#include "../symbol/include/Scope.hpp"
#include "../value/include/StopType.hpp"
#include "../../include/util.hpp"

ASTBlock::ASTBlock(): AST(BLOCK) {

}

Value *ASTBlock::inEval() {
    Value *v;
    Scope *prev;

    prev = actual_scope; // Every block creates a new scope and in the end we take the previous back
    actual_scope = new Scope(actual_scope);

    if(add_symbols){ // If there are symbols to add to this block (procedure parameters)
        for(Symbol *s : *add_symbols){
            s = s->duplicate();
            s->state = DEFINED;
            actual_scope->addSym(s);
        }
    }

    // Children must be evaluated in inverse order because of the botton-up read
    for(auto it = children.rbegin(); it != children.rend(); ++it){
        v = (*it)->eval();

        if(v){
            if(v->type == STOPTYPE){
                actual_scope = prev;
                return v;
            }
        }
    }

    actual_scope = prev;
    v = new StopType(END);

    return v;
}

void ASTBlock::printNode(){
    std::cout << "Node type: ASTBlock" << std::endl;
}
