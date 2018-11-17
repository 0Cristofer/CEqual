/* Abstract Syntax Tree expression list class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 12/11/2018
   Edited: 17/11/2018 */

#ifndef ASTEXPLIST_HPP_CEQUAL
#define ASTEXPLIST_HPP_CEQUAL

#include "AST.hpp"

class ASTExpList: public AST {
public:
    explicit ASTExpList(AST *a);

    void printNode() override;

    std::vector<Value *> *vals;
protected:
    // Exaluate the expressions and save its return values
    Value *inEval() override;
};


#endif /* ASTEXPLIST_HPP_CEQUAL */
