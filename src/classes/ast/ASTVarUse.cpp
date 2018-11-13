/* Abstract Syntax Tree variable use
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 20/10/2018
   Edited: 07/11/2018 */

#include <iostream>

#include "include/ASTVarUse.hpp"
#include "../value/include/LiteralInt.hpp"
#include "../value/include/LiteralBool.hpp"
#include "../value/include/LiteralStr.hpp"
#include "../../include/util.hpp"

ASTVarUse::ASTVarUse(Symbol* s, AST* e, Scope* sc): AST(VARUSE, sc), sym(s){
    if(e) addChild(e);
}

Value* ASTVarUse::inEval(){
    int ind = 0;
    Value* v = nullptr, *e = nullptr;

    sym = scope->getSym(sym);

    if(sym->state == UNDEFINED){
        notInitializedError(line, *(sym->id));
        free(sym);
        return new LiteralInt(0);
    }

    if(!children.empty()){
        e = children[0]->eval();

        if(typeCheck(e, INT, line)){
            ind = ((LiteralInt*)e)->val;
            v = (*(sym->vals))[ind];
        }

    }
    else{
        v = sym->val;
    }


    //std::cout << "usou variável: " << *sym->id << ", com valor: " << ((LiteralInt*)(*sym->vals)[ind])->val << std::endl;
    switch (((Literal*)v)->type) {
        case INT:
            v = new LiteralInt(((LiteralInt*)v)->val);
            break;
        case BOOL:
            v = new LiteralBool(((LiteralBool*)v)->val);
            break;
        case STR:
            v = new LiteralStr(new std::string(*(((LiteralStr*)v)->val)));
            break;
    }

    return v;
}

void ASTVarUse::printNode(){
    std::cout << "Node type: ASTLiteral" << std::endl;
}
