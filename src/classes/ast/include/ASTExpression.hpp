/* Abstract Syntax Tree expression node
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 17/11/2018 */

#ifndef ASTEXPRESSION_HPP_CEQUAL
#define ASTEXPRESSION_HPP_CEQUAL

#include <string>

#include "AST.hpp"
#include "../../value/include/Literal.hpp"
#include "../../value/include/LiteralInt.hpp"
#include "../../value/include/LiteralBool.hpp"

// Possible expression operands
enum Operand {
    PLUS, MINUS, MUL, DIV, MOD, U_MINUS, // Aritmetic operands
    EQL, DIF, GRT, GRE, LES, LEQ, // Comparition operands
    OR, AND, NOT, // Logic operands
    NOOPERAND // For ternary
};

// Possible expression types
enum ExpType {
    ARITM, COMP, LOGIC, TERN
};

class ASTExpression: public AST {
public:
    // Creates a expression node with its type, operand em children
    ASTExpression(ExpType t, Operand op, AST *l, AST *r, AST *test);

    //Evaluates the expression, verifing its operands and returning a generic value
    Value* inEval() override;
    void printNode() override;

private:
    // Evaluates a integer expression
    LiteralInt *intEval(int l, int r);
    // Evaluates a comparition expression
    LiteralBool *intCompEval(int l, int r);
    LiteralBool *strCompEval(std::string* l, std::string* r);
    LiteralBool *boolCompEval(bool l, bool r);
    // Evaluates a logic expression
    LiteralBool *logicEval(bool l, bool r);

    ExpType type;
    Operand operand;
};

#endif /* ASTEXPRESSION_HPP_CEQUAL */
