/* Abstract Syntax Tree variable list specification
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 07/11/2018 */

#include <iostream>
#include <src/classes/value/include/LiteralBool.hpp>
#include <src/classes/value/include/LiteralStr.hpp>

#include "include/ASTDecVar.hpp"
#include "include/ASTListSpecVar.hpp"
#include "../value/include/LiteralInt.hpp"
#include "../../include/util.hpp"

ASTDecVar::ASTDecVar(AST *list, LiteralType t, Scope *s): AST(DECVAR, s), s_type(t) {
    addChild(list);
}

Value *ASTDecVar::inEval() {
    ASTListSpecVar *list;

    children[0]->eval();
    list = (ASTListSpecVar *)children[0];

    for(Symbol* s : list->syms) {
        s->state = UNDEFINED;

        if(s->type == SIM) {
            if(s->val) {
                if(typeCheck((Literal *) s->val, s_type, line)) {
                    s->state = DEFINED;
                }
                else{ // TODO error case
                    semanticError(line);
                }
            }
            else {
                switch (s_type) {
                    case INT:
                        s->val = new LiteralInt(0);
                        break;
                    case BOOL:
                        s->val = new LiteralBool(false);
                        break;
                    case STR:
                        s->val = new LiteralStr(new std::string(" "));
                        break;
                }

                s->state = DEFINED;
            }
        }
        else {
            if(s->vals) {
                if(typeCheck((*(s->vals))[0], s_type, line)) {
                    s->state = DEFINED;
                }
                else{ // TODO error case
                    semanticError(line);
                }
            }
            else {
                s->vals = new std::vector<Value *>();

                switch (s_type) {
                    case INT:
                        for(int i = 0; i < s->size; i++){
                            s->vals->push_back(new LiteralInt(0));
                        }
                        break;
                    case BOOL:
                        for(int i = 0; i < s->size; i++) {
                            s->vals->push_back(new LiteralBool(false));
                        }
                        break;
                    case STR:
                        for(int i = 0; i < s->size; i++) {
                            s->vals->push_back(new LiteralStr(new std::string(" ")));
                        }
                        break;
                }

                s->state = DEFINED;
            }
        }


    }

    return nullptr;
}

void ASTDecVar::printNode() {
    std::cout << "Node type: ASTDecVar" << std::endl;
}
