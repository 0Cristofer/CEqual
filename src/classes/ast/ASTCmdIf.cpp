/* Abstract Syntax Tree if command class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/11/2018
   Edited: 15/11/2018 */

#include <src/include/util.hpp>

#include "src/classes/value/include/LiteralBool.hpp"
#include "src/classes/ast/include/ASTCmdIf.hpp"

ASTCmdIf::ASTCmdIf(AST *t, AST *f, AST *e, Scope *s) : AST(CMDIF, s) {
    addChild(t);
    addChild(f);
    addChild(e);
}

Value *ASTCmdIf::inEval() {
    Value* res;

    res = children[2]->eval();

    if(!typeCheck(res, BOOL, line)){ // TODO error case
        semanticError(line);
        return nullptr;
    }

    if(((LiteralBool *)res)->val){
        children[0]->eval();
    }
    else{
        if(children[1]){
            children[1]->eval();
        }
    }

    return nullptr;
}

void ASTCmdIf::printNode() {
    std::cout << "Node type: ASTCmdIf" << std::endl;
}
