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

ASTVarUse::ASTVarUse(Symbol *s, AST *e): AST(VARUSE), sym(s){
    if(e) addChild(e);
}

Value *ASTVarUse::inEval(){
    Value *v = nullptr, *e = nullptr;

    sym = actual_scope->getSym(sym);

    if(sym->state == UNDEFINED){
        notDefinedError(line, *(sym->id));
        free(sym);
        sym = nullptr;
        return nullptr;
    }

    if(!children.empty()){
        e = children[0]->eval();

        if(typeCheck(e, INT, line)){
            ind = ((LiteralInt *)e)->val;
            v = (*(sym->vals))[ind];
        }
        else{
            // TODO error case
            return nullptr;
        }

    }
    else{
        if(sym->type == ARRAY){ // If it is an array an no position is specified, just pass the first element
            v = *(*(sym->vals)).begin();
        }
        else{
            v = sym->val;
        }
    }

    switch (((Literal*)v)->type) {
        case INT:
            v = new LiteralInt(((LiteralInt *)v)->val);
            break;
        case BOOL:
            v = new LiteralBool(((LiteralBool *)v)->val);
            break;
        case STR:
            v = new LiteralStr(new std::string(*(((LiteralStr *)v)->val)));
            break;
        case VOID:
            std::cerr << "Not Implemented" << std::endl;
            break;
    }

    return v;
}

void ASTVarUse::printNode(){
    std::cout << "Node type: ASTLiteral" << std::endl;
}
