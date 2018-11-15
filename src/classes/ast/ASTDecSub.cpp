/* Abstract Syntax Tree subprogram declaration class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 12/11/2018
   Edited: 12/11/2018 */

#include <iostream>
#include <src/include/util.hpp>

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
    Value *v;
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

                    if ((*p)->second == ARRAY) { // If the parameter is an array we need to verify if the parameter is too and set up de data
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
                    else { // Else, just verify the type
                        ok = ((Literal *) v)->type == (*p)->first;

                        if (!ok){
                            // TODO error case
                            break;
                        }

                        (*s)->val = v;
                    }

                    p++;
                    s++;
                }
            }
        }
    }

    if(ok){ // Arguments verified, can evaluate this procedure's block
        children[1]->eval();
        //TODO read the return
    }
    else{
        semanticError(line);
    }

    return nullptr;
}

void ASTDecSub::printNode() {
    std::cout << "Node type: ASTDecSub" << std::endl;
}
