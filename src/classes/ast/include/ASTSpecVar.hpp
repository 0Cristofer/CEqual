/* Abstract Syntax Tree variable specification leaf node
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 19/10/2018 */

#ifndef ASTSPECVAR_HPP_CEQUAL
#define ASTSPECVAR_HPP_CEQUAL

#include "AST.hpp"
#include "../../symbol/include/Symbol.hpp"

// Variable types, simple or array
enum SpecType{
    SIMVAR, ARRAYVAR
};

class ASTSpecVar: public AST{
public:
    // Sets up the literal value stored by this node (if any) and the specification type
    ASTSpecVar(Symbol* s, SpecType t);

    // Last phase of variable declaration. Updates the symbol tabe and sets up its data
    Value* inEval() override;
    void printNode() override;

    // The symbol held by this node
    Symbol* sym;
    // The type of the variable
    SpecType type;
private:
};

#endif /* ASTSPECVAR_HPP_CEQUAL */
