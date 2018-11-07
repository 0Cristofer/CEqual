/* Abstract Syntax Tree variable list specification
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 07/11/2018 */

#include <iostream>

#include "include/ASTDecVar.hpp"
#include "include/ASTListSpecVar.hpp"
#include "../value/include/LiteralInt.hpp"
#include "../../include/util.hpp"

ASTDecVar::ASTDecVar(AST* list, LiteralType t, Scope* s): AST(DECVAR, s), s_type(t){
    addChild(list);
}

Value* ASTDecVar::inEval(){
    ASTListSpecVar* list;
    children[0]->eval();
    list = (ASTListSpecVar*)children[0];

    for(Symbol* s : list->syms){
        if(s->type == SIM){
            if(s->val){
                if(typeCheck((Literal *) s->val, s_type, line)){
                    s->state = DEFINED;
                    scope->addSym(s);
                }
            }
            else{
                s->state = DEFINED;
                scope->addSym(s);
            }
        }
        else{
            if(s->vals){
                if(typeCheck((*(s->vals))[0], s_type, line)){
                    s->state = DEFINED;
                    scope->addSym(s);
                }
            }
            else{
                s->vals = new std::vector<Value*>();
                s->state = DEFINED;
                scope->addSym(s);
            }
        }
    }

    return nullptr;
}

void ASTDecVar::printNode(){
    std::cout << "Node type: ASTDecVar" << std::endl;
}
