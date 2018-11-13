/* Abstract Syntax Tree abstract class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 07/11/2018 */

#include "src/classes/ast/include/ASTDecSub.hpp"
#include "src/classes/ast/include/ASTCallProc.hpp"

ASTCallProc::ASTCallProc(Scope *s, Symbol *sm, AST *a, SymType t) : AST(CALLPROC, s), sym(sm), s_t(t) {
    addChild(a);
}

Value *ASTCallProc::inEval() {
    Value* res = nullptr;

    sym = scope->getSym(sym);

    if(sym->state == UNDEFINED) return res; // caso de erro

    if((s_t == FUNC) && (sym->type == FUNC)){
        res = ((ASTDecSub*)sym->proc)->call(children[0]);
    }
    else if(s_t == PROC){
        ((ASTDecSub*)sym->proc)->call(children[0]);
    }

    return res;
}
