/* Abstract Syntax Tree for command class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/11/2018
   Edited: 15/11/2018 */

#include <iostream>

#include "src/classes/ast/include/ASTListSpecVar.hpp"
#include "src/include/util.hpp"
#include "src/classes/value/include/LiteralBool.hpp"
#include "src/classes/ast/include/ASTCmdFor.hpp"

ASTCmdFor::ASTCmdFor(AST *init, AST *step, AST *cmd, AST* test, Scope *s) : AST(CMDFOR, s) {
    addChild(init);
    addChild(step);
    addChild(cmd);
    addChild(test);
}

Value *ASTCmdFor::inEval() {
    bool cont = true;
    Value *res;

    children[0]->eval();

    while (cont){
        res = children[3]->eval();

        if(!typeCheck(res, BOOL, line)){ // TODO error case
            semanticError(line);
            return nullptr;
        }

        cont = ((LiteralBool *)res)->val;

        if(!cont) break;

        children[2]->eval();
        children[1]->eval();
    }

    return nullptr;
}

void ASTCmdFor::printNode() {
    std::cout << "Node type: ASTCmdFor" << std::endl;
}
