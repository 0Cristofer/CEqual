/* Abstract Syntax Tree for command class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/11/2018
   Edited: 17/11/2018 */

#include <iostream>

#include "include/ASTListSpecVar.hpp"
#include "include/ASTCmdFor.hpp"
#include "../value/include/StopType.hpp"
#include "../value/include/LiteralBool.hpp"
#include "../../include/util.hpp"

ASTCmdFor::ASTCmdFor(AST *init, AST *step, AST *cmd, AST* test) : AST(CMDFOR) {
    addChild(init);
    addChild(step);
    addChild(cmd);
    addChild(test);
}

Value *ASTCmdFor::inEval() {
    bool cont = true;
    Value *res = nullptr;

    children[0]->eval();

    while (cont){
        res = children[3]->eval();

        if(!typeCheck(res, BOOL, line)){
            expectedBoolExp(line, "Sem nome de tipo ainda mano!"); // TODO error case
            return nullptr;
        }

        cont = ((LiteralBool *)res)->val;

        if(!cont) break;

        res = children[2]->eval();

        if(res){
            if(res->type == STOPTYPE){
                if((((StopType *)res)->stype == STOP) || (((StopType *)res)->stype == RETURN)){
                    break;
                }
            }
        }

        children[1]->eval();
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

void ASTCmdFor::printNode() {
    std::cout << "Node type: ASTCmdFor" << std::endl;
}
