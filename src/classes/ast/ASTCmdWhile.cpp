/* Abstract Syntax Tree while command class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/11/2018
   Edited: 15/11/2018 */

#include <iostream>
#include <src/classes/value/include/LiteralBool.hpp>

#include "src/include/util.hpp"
#include "src/classes/ast/include/ASTCmdWhile.hpp"

ASTCmdWhile::ASTCmdWhile(AST *t, AST *e, Scope *s) : AST(CMDWHILE, s) {
    addChild(t);
    addChild(e);
}

Value *ASTCmdWhile::inEval() {
    bool cont = true;
    Value* res;

    while(cont){
        res = children[1]->eval();

        if(!typeCheck(res, BOOL, line)){ // TODO error case
            semanticError(line);
            return nullptr;
        }

        cont = ((LiteralBool *)res)->val;

        if(!cont) break;

        children[0]->eval();
    }

    return nullptr;
}

void ASTCmdWhile::printNode() {
    std::cout << "Node type: ASTCmdWhile" << std::endl;
}
