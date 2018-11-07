/* Abstract Syntax Tree literal node definitions
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 07/11/2018 */

#include <iostream>

#include "include/ASTSpecVar.hpp"
#include "include/ASTArrayInit.hpp"
#include "../../include/util.hpp"

ASTSpecVar::ASTSpecVar(Symbol* s, SpecType t, Scope* sc): AST(SPECVAR, sc), sym(s), type(t){

}

Value* ASTSpecVar::inEval(){
    Value* res = nullptr;
    std::vector<Value*>* v;

    if(type == SIMVAR){
        if(!children.empty()){
            res = children[0]->eval();
        }

        sym->type = SIM;
    }
    else{
        if(!children.empty()){
            children[0]->eval();
            v = ((ASTArrayInit*)children[0])->vals;

            if(v->size() > sym->size){
                arraySizeMismatchError(line);
            }
            else{
                if(sym->vals){
                    for(Value* oldv : *(sym->vals)){
                        free(oldv);
                    }

                    free(sym->vals);
                }

                sym->vals = v;

                if(v->size() < sym->size){
                    v->resize(static_cast<unsigned long>(sym->size));
                }
            }
        }

        sym->type = ARRAY;
    }

    return res;
}

void ASTSpecVar::printNode(){
    std::cout << "Node type: ASTSpecVar" << std::endl;
}
