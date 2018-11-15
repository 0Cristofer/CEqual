//
// Created by cristofer on 15/11/18.
//

#ifndef CEQUAL_ASTCMDREAD_HPP
#define CEQUAL_ASTCMDREAD_HPP

#include "AST.hpp"
#include "../../symbol/include/Symbol.hpp"

#include <src/classes/value/include/Value.hpp>

class ASTCmdRead: public AST {
public:
    ASTCmdRead(AST *e, Scope *sc);

    Value* inEval() override;
    void printNode() override;

private:
};

#endif //CEQUAL_ASTCMDREAD_HPP
