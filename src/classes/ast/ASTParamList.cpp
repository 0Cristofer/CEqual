/* Abstract Syntax Tree variable list specification
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 12/11/2018
   Edited: 12/11/2018 */

#include <src/classes/ast/include/ASTParamSpec.hpp>
#include "src/classes/ast/include/ASTParamList.hpp"

ASTParamList::ASTParamList(AST *ast, Scope *s) : AST(PARAMLIST, s) {
    this->addChild(ast);
}

Value *ASTParamList::inEval() {

    for(AST* ast: children){ /* itera sobre os filhos de ParamList que sao ListDefs*/
        for(Symbol* s: ((ASTParamSpec*)ast)->syms){ /* itera sobre os símbolos de ListDefs*/
            s->state = DEFINED;
            scope->addSym(s);  /* Insere na tabela de Símbolos*/
        }
    }
}

