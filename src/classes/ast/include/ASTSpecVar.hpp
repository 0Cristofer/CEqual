/* Abstract Syntax Tree variable specification leaf node
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 19/10/2018 */

#ifndef ASTSPECVAR_HPP
#define ASTSPECVAR_HPP

#include "AST.hpp"
#include "../../symbol/include/Symbol.hpp"

enum SpecType{
    SIMVAR, ARRAYVAR
};

class ASTSpecVar: public AST{
public:
    // Sets up the literal value stored by this node and the specification type
    ASTSpecVar(Symbol* s, SpecType t);

    // Implementation of the pure virtual.
    Value* inEval() override;
    void printNode() override;

    Symbol* sym;
    SpecType type;
private:
};

#endif /* ASTSPECVAR_HPP */
