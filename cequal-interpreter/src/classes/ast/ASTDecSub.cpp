/* Abstract Syntax Tree subprogram declaration class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 12/11/2018
   Edited: 17/11/2018 */

#include <iostream>

#include "include/ASTDecSub.hpp"
#include "include/ASTBlock.hpp"
#include "include/ASTParamList.hpp"
#include "include/ASTVarUse.hpp"
#include "../value/include/StopType.hpp"
#include "../../include/util.hpp"

ASTDecSub::ASTDecSub(AST *param, AST *block, LiteralType t) : AST(DECSUB), type(t) {
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

Value *ASTDecSub::call(AST *a, bool unstack) {
    Value *v = nullptr;
    Scope *prev = nullptr;
    bool ok = true; // Used for parameter - argument verification

    if(params) { // If there is parameteres
        if(!a) { // And none is passed
            parametersExpected(line);
            ok = false;
        }
        else {
            ok = params->size() == a->children.size();
            auto p = params->begin();
            auto s = syms->begin();

            if (ok){
                for (AST *child: a->children) {
                    v = child->eval();

                    if ((*p)->second == ARRAY) { // If the parameter is an array we need to verify if the argument is too and set up the data
                        if (child->a_type == VARUSE) {

                            ok = ((ASTVarUse *) (child))->sym->type == ARRAY;

                            if (!ok){
                                wrongParameter(line, "array", "single");
                                break;
                            }

                            ok = ok && (((Literal *) (*(((ASTVarUse *) child)->sym->vals))[0])->type ==
                                        (*p)->first);
                            if (!ok) {
                                wrongParameter(line, "EXPECTED", "GOT"); // TODO error case
                                break;
                            }

                            (*s)->vals = (((ASTVarUse *) child)->sym->vals);
                            (*s)->size = ((ASTVarUse *) child)->sym->size;
                        }
                        else {
                            invalidArrayUse(line);
                            ok = false;
                            break;
                        }
                    }
                    else { // Else, verify the type and if it is a string, pass by reference
                        ok = ((Literal *) v)->type == (*p)->first;

                        if (!ok){
                            wrongParameter(line, "EXPECTED", "GOT"); // TODO error case
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
    else{ // If there is no parameters and arguments were passed
        if(a) {
            ok = false;
            parametersNotExpected(line);
        }
    }

    if(ok){ // Arguments verified, can evaluate this procedure's block
        if(unstack){
            prev = actual_scope; // Since we are calling a procedure, we need to "unstack" the actual scope
            actual_scope = actual_scope->prev;
        }

        ((ASTBlock *) children[1])->add_symbols = syms;
        v = children[1]->eval();


        if(v->type == STOPTYPE){
            switch (((StopType *)v)->stype){
                case STOP:
                    invalidUseOf(children[1]->line, "STOP");
                    break;
                case SKIP:
                    invalidUseOf(children[1]->line, "SKIP");
                    break;
                case RETURN:
                    if(((StopType *)v)->val){
                        if(type == VOID){
                            returnInProcedure(children[1]->line);
                        }
                        else{
                            if(typeCheck(((StopType *)v)->val, type, line)){
                                v = ((StopType *)v)->val;
                            }
                            else{
                                invalidReturnType(line);
                            }
                        }
                    }
                    else{
                        if(type != VOID){
                            voidReturnInFunction(line);
                        }
                    }

                    break;
                case END:
                    if(type != VOID){
                        missingReturnInFunction(line);
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

    if(unstack) actual_scope = prev;

    return v;
}

void ASTDecSub::printNode() {
    std::cout << "Node type: ASTDecSub" << std::endl;
}
