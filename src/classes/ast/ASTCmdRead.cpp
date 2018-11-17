/* Abstract Syntax Tree read command class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/11/2018
   Edited: 17/11/2018 */

#include <iostream>

#include "include/ASTVarUse.hpp"
#include "include/ASTCmdRead.hpp"
#include "../value/include/LiteralInt.hpp"
#include "../value/include/LiteralStr.hpp"
#include "../value/include/LiteralBool.hpp"

ASTCmdRead::ASTCmdRead(AST *e): AST(CMDREAD){
    if(e) addChild(e);
}

Value *ASTCmdRead::inEval() {
    int i, ind;
    bool b;
    std::string s;
    Symbol *sm;

    children[0]->eval();

    sm = ((ASTVarUse *) children[0])->sym;
    ind = ((ASTVarUse *) children[0])->ind;

    if(sm->type == SIM) {
        switch (((Literal *) (sm->val))->type) {
            case INT:
                std::cin >> i;
                ((LiteralInt *) (sm->val))->val = i;
                break;
            case STR:
                std::cin >> s;
                ((LiteralStr *) (sm->val))->val = new std::string(s);
                break;
            case BOOL:
                std::cin >> s;
                b = s == "true";
                ((LiteralBool *) (sm->val))->val = b;
                break;
            case VOID:
                break;
        }
    }
    else{
        switch (((Literal *) (*(sm->vals))[0])->type) {
            case INT:
                std::cin >> i;
                ((LiteralInt *) (*(sm->vals))[ind])->val = i;
                break;
            case STR:
                std::cin >> s;
                ((LiteralStr *) (*(sm->vals))[ind])->val = new std::string(s);
                break;
            case BOOL:
                std::cin >> s;
                b = s == "true";
                ((LiteralBool *) (*(sm->vals))[ind])->val = b;
                break;
            case VOID:
                break;
        }
    }

    return nullptr;
}

void ASTCmdRead::printNode(){
    std::cout << "Node type: ASTCmdRead" << std::endl;
}

