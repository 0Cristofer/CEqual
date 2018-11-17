/* Abstract Syntax Tree block
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 17/11/2018 */

#ifndef ASTBLOCK_HPP_CEQUAL
#define ASTBLOCK_HPP_CEQUAL

#include "AST.hpp"
#include "../../symbol/include/Symbol.hpp"

class ASTBlock: public AST {
public:
    explicit ASTBlock();

    void printNode() override;

    std::vector<Symbol *>* add_symbols = nullptr;
protected:
    // Just iterate the children evaluating them
    Value *inEval() override;
};

#endif /* ASTBLOCK_HPP_CEQUAL */
