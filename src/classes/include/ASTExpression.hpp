/* Abstract Syntax Tree expression node
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 18/10/2018 */

#ifndef ASTEXPRESSION_HPP
#define ASTEXPRESSION_HPP

#include "AST.hpp"
#include "Literal.hpp"
#include "LiteralInt.hpp"
#include "LiteralBool.hpp"

// Possible expression operands
enum Operand{
  PLUS, MINUS, MUL, DIV, MOD, U_MINUS, // Aritmetic operands
  EQL, DIF, GRT, GRE, LES, LEQ, // Comparition operands
  OR, AND, NOT // Logic operands
};

// Possible expression types
enum ExpType{
  ARITM, COMP, LOGIC
};

class ASTExpression: public AST{
public:
  // Creates a expression node with its type, operand em children
  ASTExpression(ExpType t, Operand op, AST* l, AST* r, AST* test);

  // Implementation of the pure virtual. Evaluates the expression, verifing its operands and returning a generic value
  Value* inEval();
  void printNode();
private:
  // Evaluates a integer expression
  LiteralInt* intEval(int l, int r);
  // Evaluates a comparition expression
  LiteralBool* compEval(int l, int r);
  // Evaluates a logic expression
  LiteralBool* logicEval(bool l, bool r);

  ExpType type;
  Operand operand;
};

#endif /* ASTEXPRESSION_HPP */
