/* Abstract Syntax Tree block
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 19/10/2018 */

#ifndef ASTBLOCK_HPP_CEQUAL
#define ASTBLOCK_HPP_CEQUAL

#include "AST.hpp"
#include "../../symbol/include/Scope.hpp"

class ASTBlock: public AST{
public:
    // Sets up scope stored by this node
    explicit ASTBlock(Scope* s);

    Value* inEval() override;
    void printNode() override;

    // The scope of this block
    Scope* scope;
private:
};

#endif /* ASTBLOCK_HPP_CEQUAL */
