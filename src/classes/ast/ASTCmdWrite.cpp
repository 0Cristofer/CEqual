/* Abstract Syntax Tree command write
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 20/10/2018
   Edited: 07/11/2018 */

#include <iostream>
#include <src/classes/ast/include/ASTExpList.hpp>

#include "include/ASTCmdWrite.hpp"
#include "../value/include/LiteralInt.hpp"
#include "../value/include/LiteralBool.hpp"
#include "../value/include/LiteralStr.hpp"

ASTCmdWrite::ASTCmdWrite(AST* e, Scope* s): AST(CMDWRITE, s){
    if(e) addChild(e);
}

Value* ASTCmdWrite::inEval(){
    Value* v = nullptr;


    if(children[0]->a_type == EXPLIST){
        children[0]->eval();

        auto vals = ((ASTExpList*)children[0])->vals;

        for(Value* val : *vals){
            if (val != nullptr) {
                switch (((Literal *) val)->type) {
                    case INT:
                        std::cout << ((LiteralInt *) val)->val << std::endl;
                        break;
                    case BOOL:
                        std::cout << ((LiteralBool *) val)->val << std::endl;
                        break;
                    case STR:
                        std::cout << *(((LiteralStr *) val)->val) << std::endl;
                        break;
                }
            }
        }
    }
    else {
        v = children[0]->eval();

        if (v != nullptr) {
            switch (((Literal *) v)->type) {
                case INT:
                    std::cout << ((LiteralInt *) v)->val << std::endl;
                    break;
                case BOOL:
                    std::cout << ((LiteralBool *) v)->val << std::endl;
                    break;
                case STR:
                    std::cout << *(((LiteralStr *) v)->val) << std::endl;
                    break;
            }
        }
    }

    return nullptr;
}

void ASTCmdWrite::printNode(){
    std::cout << "Node type: ASTLiteral" << std::endl;
}
