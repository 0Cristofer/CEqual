/* Abstract Syntax Tree if command class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/11/2018
   Edited: 17/11/2018 */

#include "include/ASTCmdIf.hpp"
#include "../value/include/StopType.hpp"
#include "../value/include/LiteralBool.hpp"
#include "../../include/util.hpp"

ASTCmdIf::ASTCmdIf(AST *t, AST *f, AST *e) : AST(CMDIF) {
    addChild(t);
    addChild(f);
    addChild(e);
}

Value *ASTCmdIf::inEval() {
    Value* res;

    res = children[2]->eval();

    if(!typeCheck(res, BOOL, children[0]->line)){
        expectedBoolExp(children[0]->line, ((Literal*)res)->name);
        return nullptr;
    }

    if(((LiteralBool *)res)->val){
        res = children[0]->eval();
    }
    else if(r_error || (!((LiteralBool *)res)->val)){
        if(children[1]){
            res = children[1]->eval();
        }
    }

    if(res){
        if(res->type == STOPTYPE){
            if(((StopType *)res)->stype == END){
                res = nullptr;
            }
        }
    }

    return res;
}

void ASTCmdIf::printNode() {
    std::cout << "Node type: ASTCmdIf" << std::endl;
}
