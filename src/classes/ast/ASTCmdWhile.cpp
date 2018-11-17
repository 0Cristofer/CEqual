/* Abstract Syntax Tree while command class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/11/2018
   Edited: 16/11/2018 */

#include <iostream>

#include "src/classes/value/include/LiteralBool.hpp"
#include "src/classes/value/include/StopType.hpp"
#include "src/include/util.hpp"
#include "src/classes/ast/include/ASTCmdWhile.hpp"

ASTCmdWhile::ASTCmdWhile(AST *t, AST *e, Scope *s) : AST(CMDWHILE, s) {
    addChild(t);
    addChild(e);
}

Value *ASTCmdWhile::inEval() {
    bool cont = true;
    Value *res = nullptr;

    while(cont){
        res = children[1]->eval();

        if(!typeCheck(res, BOOL, line)){ // TODO error case
            semanticError(line);
            return nullptr;
        }

        cont = ((LiteralBool *)res)->val;

        if(!cont) break;

        res = children[0]->eval();

        if(res){
            if(res->type == STOPTYPE){
                if((((StopType *)res)->stype == STOP) || (((StopType *)res)->stype == RETURN)){
                    break;
                }
            }
        }
    }

    if(res){
        if(res->type == STOPTYPE){
            if((((StopType *)res)->stype == STOP) || (((StopType *)res)->stype == SKIP)){
                res = nullptr;
            }
        }
    }

    return res;
}

void ASTCmdWhile::printNode() {
    std::cout << "Node type: ASTCmdWhile" << std::endl;
}
