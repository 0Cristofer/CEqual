/* Abstract Syntax Tree parameter specification specification
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 12/11/2018
   Edited: 17/11/2018 */

#include <iostream>

#include "include/ASTParamSpec.hpp"
#include "../value/include/LiteralInt.hpp"
#include "../value/include/LiteralBool.hpp"
#include "../value/include/LiteralStr.hpp"

ASTParamSpec::ASTParamSpec(Symbol* sym) : AST(PARAMSPEC) {
    addSymbol(sym);
}

void ASTParamSpec::addSymbol(Symbol *sym) {
    syms.push_back(sym);
}

Value *ASTParamSpec::inEval() {
    for(Symbol *s: syms) {
        switch (type) {
            case INT:
                if(s->type == SIM) s->val = new LiteralInt(0);
                else{
                    s->size = 1;
                    s->vals = new std::vector<Value *> ();
                    s->vals->push_back(new LiteralInt(0));
                }
                break;
            case BOOL:
                if(s->type == SIM) s->val = new LiteralBool(false);
                else{
                    s->size = 1;
                    s->vals = new std::vector<Value *> ();
                    s->vals->push_back(new LiteralBool(false));
                }
                break;
            case STR:
                if(s->type == SIM) s->val = new LiteralStr(new std::string());
                else{
                    s->size = 1;
                    s->vals = new std::vector<Value *> ();
                    s->vals->push_back(new LiteralStr(new std::string()));
                }
                break;

            case VOID:break;
        }
    }

    return nullptr;
}

void ASTParamSpec::printNode() {
    std::cout << "Node type: ASTParamSpec" << std::endl;
}
