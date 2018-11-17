/* Abstract Syntax Tree while command class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/11/2018
   Edited: 17/11/2018 */

#include <iostream>

#include "include/ASTCmdWhile.hpp"
#include "../value/include/LiteralBool.hpp"
#include "../value/include/StopType.hpp"
#include "../../include/util.hpp"

ASTCmdWhile::ASTCmdWhile(AST *t, AST *e) : AST(CMDWHILE) {
    addChild(t);
    addChild(e);
}

Value *ASTCmdWhile::inEval() {
    bool cont;
    Value *res = nullptr;

    while(true){
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
