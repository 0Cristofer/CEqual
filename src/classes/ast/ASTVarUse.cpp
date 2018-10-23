/* Abstract Syntax Tree variable use
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 20/10/2018
   Edited: 20/10/2018 */

#include <iostream>

#include "include/ASTVarUse.hpp"
#include "../value/include/LiteralInt.hpp"
#include "../value/include/LiteralBool.hpp"
#include "../value/include/LiteralStr.hpp"
#include "../../include/util.hpp"

ASTVarUse::ASTVarUse(Symbol* s, AST* e): AST(VARUSE), sym(s){
    if(e) addChild(e);
}

Value* ASTVarUse::inEval(){
    Value* v = nullptr, *e;

    if(!children.empty()){
        e = children[0]->eval();

        if(typeCheck(e, INT)){
            v = (*(sym->vals))[((LiteralInt*)e)->val];
        }

    }
    else{
        v = sym->val;
    }

    switch (((Literal*)(sym->val))->type) {
        case INT:
            v = new LiteralInt(((LiteralInt*)(sym->val))->val);
            break;
        case BOOL:
            v = new LiteralBool(((LiteralBool*)(sym->val))->val);
            break;
        case STR:
            v = new LiteralStr(new std::string(*(((LiteralStr*)(sym->val))->val)));
            break;
    }

    return v;
}

void ASTVarUse::printNode(){
    std::cout << "Node type: ASTLiteral" << std::endl;
}
