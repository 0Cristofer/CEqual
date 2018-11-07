/* Abstract Syntax Tree variable use
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 07/11/2018 */

#ifndef ASTVARUSE_HPP_CEQUAL
#define ASTVARUSE_HPP_CEQUAL

#include "AST.hpp"
#include "../../symbol/include/Symbol.hpp"

class ASTVarUse: public AST{
public:
    // Gets the symbol referenced by the ID and the value to access (if it is an array)
    ASTVarUse(Symbol* s, AST* e, Scope* sc);

    // Reads the value stored in this symbol, if it exists
    Value* inEval() override;
    void printNode() override;

    // The referenced symbol
    Symbol* sym;
private:
};

#endif /* ASTVARUSE_HPP_CEQUAL */
