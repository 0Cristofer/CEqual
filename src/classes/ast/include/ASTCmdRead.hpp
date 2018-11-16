/* Abstract Syntax Tree read command class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/11/2018
   Edited: 15/11/2018 */

#ifndef ASTCMDREAD_HPP_CEQUAL
#define ASTCMDREAD_HPP_CEQUAL

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

#endif /* ASTCMDREAD_HPP_CEQUAL */
