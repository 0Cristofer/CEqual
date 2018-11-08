/* Abstract Syntax Tree variable list specification
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 07/11/2018 */

#include <iostream>

#include "include/ASTListSpecVar.hpp"
#include "include/ASTSpecVar.hpp"

ASTListSpecVar::ASTListSpecVar(AST* r, Scope* s): AST(LISTSPECVAR, s){
    if(r) addChild(r);
}

Value* ASTListSpecVar::inEval(){
    AST* a;
    Symbol* sym;

    for(auto it = children.rbegin(); it != children.rend(); ++it){
        a = *it;
        sym = ((ASTSpecVar*)a)->sym;

        sym->state = DEFINING;
        scope->addSym(sym);

        if(sym->type == SIM){
            sym->val = a->eval();
        }
        else{
            a->eval();
        }

        syms.push_back(sym);
    }

    return nullptr;
}

/*Value* ASTListSpecVar::inEval(){
    Symbol* sym;

    for(AST* a : children){
        sym = ((ASTSpecVar*)a)->sym;

        if(sym->type == SIM){
            sym->val = a->eval();
        }
        else{
            a->eval();
        }
        syms.push_back(sym);
    }

    return nullptr;
}*/

void ASTListSpecVar::printNode(){
    std::cout << "Node type: ASTSListSpecVar" << std::endl;
}
