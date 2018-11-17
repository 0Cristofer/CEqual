/* Abstract Syntax Tree subprogram declaration class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 12/11/2018
   Edited: 16/11/2018 */

#include <iostream>

#include "src/classes/value/include/StopType.hpp"
#include "src/include/util.hpp"
#include "src/classes/ast/include/ASTDecSub.hpp"
#include "src/classes/ast/include/ASTParamList.hpp"
#include "src/classes/ast/include/ASTVarUse.hpp"
#include "src/classes/ast/include/ASTDecSub.hpp"

ASTDecSub::ASTDecSub(AST *param, AST *block, LiteralType t, Scope *s) : AST(DECSUB, s), type(t) {
    addChild(param);
    addChild(block);
}

Value *ASTDecSub::inEval() {
    if(children[0]) {
        children[0]->eval();
        params = ((ASTParamList *)children[0])->params;
        syms = ((ASTParamList *)children[0])->syms;
    }

    return nullptr;
}

Value *ASTDecSub::call(AST *a) {
    Value *v = nullptr;
    bool ok = true; // Used for parameter - argument verification

    if(params) { // If there is parameteres
        if(!a) { // And none is passed
            ok = false;
        }
        else {
            ok = params->size() == a->children.size();
            auto p = params->begin();
            auto s = syms->begin();

            if (ok){
                for (AST *child: a->children) {
                    v = child->eval();

                    if ((*p)->second == ARRAY) { // If the parameter is an array we need to verify if the argument is too and set up de data
                        if (child->a_type == VARUSE) {

                            ok = ((ASTVarUse *) (child))->sym->type == ARRAY;

                            if (!ok){
                                // TODO error case
                                break;
                            }

                            ok = ok && (((Literal *) (*(((ASTVarUse *) child)->sym->vals))[0])->type ==
                                        (*p)->first);
                            if (!ok) {
                                // TODO error case
                                break;
                            }

                            (*s)->vals = (((ASTVarUse *) child)->sym->vals);
                            (*s)->size = ((ASTVarUse *) child)->sym->size;
                        }
                        else {
                            // TODO error case
                            ok = false;
                            break;
                        }
                    }
                    else { // Else, verify the type and if it is a string, pass by reference
                        ok = ((Literal *) v)->type == (*p)->first;

                        if (!ok){
                            // TODO error case
                            break;
                        }

                        if((*p)->first == STR){
                            (*s)->val = ((ASTVarUse *) child)->sym->val;
                        }
                        else{
                            (*s)->val = v;
                        }

                    }

                    p++;
                    s++;
                }
            }
        }
    }

    if(ok){ // Arguments verified, can evaluate this procedure's block
        v = children[1]->eval();


        if(v->type == STOPTYPE){
            switch (((StopType *)v)->stype){
                case STOP:
                case SKIP:
                    semanticError(line);
                    break;
                case RETURN:
                    if(((StopType *)v)->val){
                        if(type == VOID){
                            semanticError(line); // TODO error case
                        }
                        else{
                            if(typeCheck(((StopType *)v)->val, type, line)){
                                v = ((StopType *)v)->val;
                            }
                            else{
                                semanticError(line); // TODO error case

                            }
                        }
                    }
                    else{
                        if(type != VOID){
                            semanticError(line); // TODO error case
                        }
                    }

                    break;
                case END:
                    if(type != VOID){
                        semanticError(line); // TODO error case
                    }

                    break;
            }
        }
        else{ // TODO error case
            semanticError(line);
        }
    }
    else{
        semanticError(line);
    }

    return v;
}

void ASTDecSub::printNode() {
    std::cout << "Node type: ASTDecSub" << std::endl;
}
