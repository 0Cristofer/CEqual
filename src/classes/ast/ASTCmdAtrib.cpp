/* Abstract Syntax Tree atribution command class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/11/2018
   Edited: 15/11/2018 */

#include <iostream>
#include <src/classes/ast/include/ASTVarUse.hpp>
#include <src/include/util.hpp>
#include <src/classes/value/include/LiteralInt.hpp>
#include "src/classes/ast/include/ASTCmdAtrib.hpp"

ASTCmdAtrib::ASTCmdAtrib(AST* use, AST* exp, ATRT t, Scope *s) : AST(CMDATRIB, s), attype(t) {
    addChild(use);
    addChild(exp);
}

Value *ASTCmdAtrib::inEval() {
    int ind;
    Value *var, *ex;
    Symbol *sm;

    var = children[0]->eval();
    ex = children[1]->eval();

    if((((Literal*)var)->type != INT) && (attype != ATR)){ // TODO error case
        semanticError(line);
        return nullptr;
    }

    if(((Literal*)var)->type == ((Literal*)ex)->type){
        sm = ((ASTVarUse *) children[0])->sym;

        if(((ASTVarUse *) children[0])->sym->type == ARRAY){
            ind = ((ASTVarUse *) children[0])->ind;
            switch (attype) {
                case ATR:
                    (*(sm->vals))[ind] = ex;
                    break;
                case ATP:
                    (*(sm->vals))[ind] = new LiteralInt(((LiteralInt *)var)->val + ((LiteralInt *)ex)->val);
                    break;
                case ATM:
                    (*(sm->vals))[ind] = new LiteralInt(((LiteralInt *)var)->val - ((LiteralInt *)ex)->val);
                    break;
                case ATMUL:
                    (*(sm->vals))[ind] = new LiteralInt(((LiteralInt *)var)->val * ((LiteralInt *)ex)->val);
                    break;
                case ATDIV:
                    (*(sm->vals))[ind] = new LiteralInt(((LiteralInt *)var)->val / ((LiteralInt *)ex)->val);
                    break;
                case ATMOD:
                    (*(sm->vals))[ind] = new LiteralInt(((LiteralInt *)var)->val % ((LiteralInt *)ex)->val);
                    break;
            }
        }
        else {
            switch (attype) {
                case ATR:
                    sm->val = ex;
                    break;
                case ATP:
                    sm->val = new LiteralInt(((LiteralInt *)var)->val + ((LiteralInt *)ex)->val);
                    break;
                case ATM:
                    sm->val = new LiteralInt(((LiteralInt *)var)->val - ((LiteralInt *)ex)->val);
                    break;
                case ATMUL:
                    sm->val = new LiteralInt(((LiteralInt *)var)->val * ((LiteralInt *)ex)->val);
                    break;
                case ATDIV:
                    sm->val = new LiteralInt(((LiteralInt *)var)->val / ((LiteralInt *)ex)->val);
                    break;
                case ATMOD:
                    sm->val = new LiteralInt(((LiteralInt *)var)->val % ((LiteralInt *)ex)->val);
                    break;
            }
        }
    }
    else{ // TODO error case
        semanticError(line);
    }

    return nullptr;
}

void ASTCmdAtrib::printNode() {
    std::cout << "Node type: ASTCmdAtrib" << std::endl;
}

