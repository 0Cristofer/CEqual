/* Abstract Syntax Tree command write
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 20/10/2018
   Edited: 15/11/2018 */

#include <iostream>
#include <src/classes/ast/include/ASTExpList.hpp>

#include "include/ASTCmdWrite.hpp"
#include "../value/include/LiteralInt.hpp"
#include "../value/include/LiteralBool.hpp"
#include "../value/include/LiteralStr.hpp"

ASTCmdWrite::ASTCmdWrite(AST *e, Scope *s): AST(CMDWRITE, s) {
    if(e) addChild(e);
}

Value *ASTCmdWrite::inEval() {
    children[0]->eval();

    auto vals = ((ASTExpList*)children[0])->vals;

    for(Value *val : *vals) {
        if (val != nullptr) {
            switch (((Literal *) val)->type) {
                case INT:
                    std::cout << ((LiteralInt *) val)->val;
                    break;
                case BOOL:
                    if(((LiteralBool *) val)->val){
                        std::cout << "true";
                    } else {
                        std::cout << "false";
                    }
                    break;
                case STR:
                    std::cout << *(((LiteralStr *) val)->val);
                    break;
            }
        }
    }

    return nullptr;
}

void ASTCmdWrite::printNode(){
    std::cout << "Node type: ASTCmdWrite" << std::endl;
}
