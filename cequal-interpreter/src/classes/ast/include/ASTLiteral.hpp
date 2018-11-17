/* Abstract Syntax Tree literal node
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 17/11/2018 */

#ifndef ASTLITERAL_HPP_CEQUAL
#define ASTLITERAL_HPP_CEQUAL

#include "AST.hpp"
#include "../../value/include/Literal.hpp"

class ASTLiteral: public AST{
public:
    // Sets up the literal value stored by this node
    explicit ASTLiteral(Literal *lit);

    // Evaluates the literal by returning a literal value
    Value* inEval() override;
    void printNode() override;
private:
    Literal *literal;
};

#endif /* ASTLITERAL_HPP_CEQUAL */
