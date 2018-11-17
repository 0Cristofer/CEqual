/* Abstract Syntax Tree atribution command class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/11/2018
   Edited: 17/11/2018 */

#ifndef ASTCMDATRIB_HPP_CEQUAL
#define ASTCMDATRIB_HPP_CEQUAL

#include "AST.hpp"

enum ATRT {
    ATR, ATP, ATM, ATMUL, ATDIV, ATMOD
};

class ASTCmdAtrib: public AST {
public:
    ASTCmdAtrib(AST *use, AST *exp, ATRT t);

    void printNode() override;

protected:
    ATRT attype;

    Value *inEval() override;
};


#endif /* ASTCMDATRIB_HPP_CEQUAL */
