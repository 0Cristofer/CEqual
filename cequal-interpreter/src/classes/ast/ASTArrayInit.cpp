/* Abstract Syntax Tree array initialization
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 17/11/2018 */

#include <iostream>

#include "include/ASTArrayInit.hpp"
#include "../value/include/Literal.hpp"
#include "../symbol/include/Symbol.hpp"
#include "../../include/util.hpp"

ASTArrayInit::ASTArrayInit(AST *l): AST(ARRAYINIT) {
    if(l) addChild(l);
}

Value *ASTArrayInit::inEval() {
    int i;
    Value *v, *prev = nullptr;

    vals = new std::vector<Value *>(children.size());

    // Since this is a array, we initialize a vector to hold it's elements
    // and evaluate the children to populate it. Ps.: the values are inverted because of the botton-up read
    for(i = static_cast<int>(children.size()); i > 0; i--){
        v = children[(i-1)]->eval();

        if(prev){
            if(typeCheck(v, ((Literal *) prev)->type, line)){
                (*vals)[(children.size()-i)] = v;
                prev = v;
            }
            else{
                free(vals);
                break;
            }
        }
        else{
            prev = v;
            (*vals)[(children.size()-i)] = v;
        }
    }

    return nullptr;
}

void ASTArrayInit::printNode(){
    std::cout << "Node type: ASTArrayInit" << std::endl;
}
