/* Abstract Syntax Tree variable list specification
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 17/11/2018 */

#ifndef ASTLISTSPECVAR_HPP_CEQUAL
#define ASTLISTSPECVAR_HPP_CEQUAL

#include <vector>

#include "AST.hpp"
#include "../../symbol/include/Symbol.hpp"

class ASTListSpecVar: public AST{
public:
    explicit ASTListSpecVar(AST *r);

    // Reads all children and creates a vector with all the new variables (symbols)
    Value *inEval() override;
    void printNode() override;

    // The symbol vector to be read in the next phase
    std::vector<Symbol *> syms;
private:
};

#endif /* ASTLISTSPECVAR_HPP_CEQUAL */
