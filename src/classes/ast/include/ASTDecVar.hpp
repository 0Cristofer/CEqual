/* Abstract Syntax Tree variable declarations
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 19/10/2018 */

#ifndef ASTDECVAR_HPP
#define ASTDECVAR_HPP

#include "AST.hpp"
#include "../../value/include/Literal.hpp"

class ASTDecVar: public AST{
public:
    ASTDecVar(AST* list, LiteralType t);

    // Implementation of the pure virtual.
    Value* inEval() override;
    void printNode() override;

    LiteralType s_type; // The type of the new variable
private:
};

#endif /* ASTDECVAR_HPP */
