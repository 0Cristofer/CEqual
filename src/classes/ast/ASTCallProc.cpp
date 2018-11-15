/* Abstract Syntax Tree procedure call class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 12/11/2018
   Edited: 12/11/2018 */

#include <src/include/util.hpp>
#include "src/classes/ast/include/ASTDecSub.hpp"
#include "src/classes/ast/include/ASTCallProc.hpp"

ASTCallProc::ASTCallProc(Symbol *sm, AST *a, SymType t, Scope *s) : AST(CALLPROC, s), sym(sm), s_t(t) {
    if(a) addChild(a);
}

Value *ASTCallProc::inEval() {
    Value* res = nullptr;

    sym = scope->getSym(sym);

    if(sym->state == UNDEFINED) semanticError(line); // TODO error case

    if(s_t == FUNC) {
        if(sym->type == FUNC) { // Just call as a function if the procedure is a function
            res = ((ASTDecSub*)sym->proc)->call(children[0]);
        }
        else {
            semanticError(line);
        }
    }
    else if(s_t == PROC) {
        ((ASTDecSub*)sym->proc)->call(children[0]);
    }

    return res;
}

void ASTCallProc::printNode() {
    std::cout << "Node type: ASTCallProc" << std::endl;
}
