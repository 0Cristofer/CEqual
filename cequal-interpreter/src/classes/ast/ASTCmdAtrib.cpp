/* Abstract Syntax Tree atribution command class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/11/2018
   Edited: 17/11/2018 */

#include <iostream>

#include "include/ASTVarUse.hpp"
#include "include/ASTCmdAtrib.hpp"
#include "../value/include/LiteralInt.hpp"
#include "../../include/util.hpp"

ASTCmdAtrib::ASTCmdAtrib(AST* use, AST* exp, ATRT t) : AST(CMDATRIB), attype(t) {
    addChild(use);
    addChild(exp);
}

Value *ASTCmdAtrib::inEval() {
    int ind;
    Value *var, *ex;
    Symbol *sm;

    var = children[0]->eval();
    ex = children[1]->eval(); //expression

    if(ex == nullptr) return nullptr;

    if((((Literal*)var)->type != INT) && (attype != ATR)){ // TODO error case
        invalidAritmeticAttribution(line, *(((ASTVarUse *) children[0])->sym->id) , "SEM NOME DE TIPO (por enquanto :3 )");
        return nullptr;
    }

    if(((Literal*)var)->type == ((Literal*)ex)->type){
        if(r_error) return nullptr;

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
        invalidAttribution(line, *(((ASTVarUse *) children[0])->sym->id), ((Literal*)var)->name, ((Literal*)ex)->name);
        return nullptr;
    }

    return nullptr;
}

void ASTCmdAtrib::printNode() {
    std::cout << "Node type: ASTCmdAtrib" << std::endl;
}

