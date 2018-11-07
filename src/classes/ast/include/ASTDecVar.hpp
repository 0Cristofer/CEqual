/* Abstract Syntax Tree variable declarations
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 19/10/2018 */

#ifndef ASTDECVAR_HPP_CEQUAL
#define ASTDECVAR_HPP_CEQUAL

#include "AST.hpp"
#include "../../value/include/Literal.hpp"

class ASTDecVar: public AST{
public:
    ASTDecVar(AST* list, LiteralType t);

    // May have more than one child, the id and the variable initialization. Adds the id to the current scope
    Value* inEval() override;
    void printNode() override;

    LiteralType s_type; // The type of the new variable
private:
};

#endif /* ASTDECVAR_HPP_CEQUAL */
