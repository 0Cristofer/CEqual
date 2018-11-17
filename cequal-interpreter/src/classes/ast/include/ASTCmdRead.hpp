/* Abstract Syntax Tree read command class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/11/2018
   Edited: 17/11/2018 */

#ifndef ASTCMDREAD_HPP_CEQUAL
#define ASTCMDREAD_HPP_CEQUAL

#include "AST.hpp"

class ASTCmdRead: public AST {
public:
    explicit ASTCmdRead(AST *e);

    Value* inEval() override;
    void printNode() override;

private:
};

#endif /* ASTCMDREAD_HPP_CEQUAL */
