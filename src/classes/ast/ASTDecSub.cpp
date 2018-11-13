/* Abstract Syntax Tree abstract class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 12/11/2018
   Edited: 12/11/2018 */

#include <iostream>
#include "src/classes/ast/include/ASTDecSub.hpp"
#include "src/classes/ast/include/ASTParamList.hpp"
#include "src/classes/ast/include/ASTVarUse.hpp"

#include "src/classes/ast/include/ASTDecSub.hpp"

ASTDecSub::ASTDecSub(Scope *s, AST *param, AST *block, LiteralType t) : AST(DECSUB, s), type(t) {
    addChild(param);
    addChild(block);
}

Value *ASTDecSub::inEval() {

    if(children[0]){
        children[0]->eval();
        params = ((ASTParamList*)children[0])->params;
        syms = ((ASTParamList*)children[0])->syms;
    }

    return nullptr;
}

Value * ASTDecSub::call(AST *a) {
    Value* v;
    bool ok = true;

    if(params) {
        ok = params->size() == a->children.size();
        auto p = params->begin();
        auto s = syms->begin();

        if (!ok) return nullptr; // caso de erro

        for (AST *child: a->children) {
            v = child->eval();

            if ((*p)->second == ARRAY) {

                if (child->a_type == VARUSE) {

                    ok = ((ASTVarUse *) (child))->sym->type == ARRAY;
                    if (!ok) break; // caso de erro

                    ok = ok && (((Literal *) (*(((ASTVarUse *) child)->sym->vals))[0])->type ==
                                (*p)->first); // essa linha é bonita
                    if (!ok) break; // caso de erro

                    (*s)->vals = (((ASTVarUse *) child)->sym->vals);
                    (*s)->size = ((ASTVarUse *) child)->sym->size;
                } else break; // caso de erro
            } else {
                ok = ((Literal *) v)->type == (*p)->first;

                (*s)->val = v;
            }

            p++;
            s++;
        }
    }

    if(ok){ // Arguments verified, can evaluate this procedure's block
        for(AST* ast: children[1]->children){
            ast->eval(); //TODO encontrar o return para pegar o valor
        }
    }

    return nullptr;
}
