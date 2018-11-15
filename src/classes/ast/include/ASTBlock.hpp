/* Abstract Syntax Tree block
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 07/11/2018 */

#ifndef ASTBLOCK_HPP_CEQUAL
#define ASTBLOCK_HPP_CEQUAL

#include "AST.hpp"
#include "../../symbol/include/Scope.hpp"

class ASTBlock: public AST {
public:
    explicit ASTBlock(Scope *s);

    void printNode() override;

protected:
    // Just iterate the children evaluating them
    Value *inEval() override;
};

#endif /* ASTBLOCK_HPP_CEQUAL */
