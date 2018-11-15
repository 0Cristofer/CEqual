/* Abstract Syntax Tree variable list specification
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 12/11/2018
   Edited: 12/11/2018 */

#include <iostream>

#include "src/classes/ast/include/ASTParamSpec.hpp"
#include "src/classes/ast/include/ASTParamList.hpp"

ASTParamList::ASTParamList(AST *ast, Scope *s) : AST(PARAMLIST, s) {
    addChild(ast);
}

Value *ASTParamList::inEval() {
    params = new std::vector<std::pair<LiteralType, SymType> *>();
    syms = new std::vector<Symbol *>();

    for(AST *ast: children){
        ast->eval();

        for(Symbol *s: ((ASTParamSpec *)ast)->syms) {
            if(s->type == SIM) {
                params->push_back(new std::pair<LiteralType, SymType>(((Literal *)(s->val))->type, SIM));
            }
            else{
                params->push_back(new std::pair<LiteralType, SymType>(((Literal *)((*(s->vals))[0]))->type, ARRAY));
            }

            s->state = DEFINED;
            scope->addSym(s);
            syms->push_back(s);
        }
    }

    return nullptr;
}

void ASTParamList::printNode(){
    std::cout << "Node type: ASTParamList" << std::endl;
}

