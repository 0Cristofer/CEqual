/* Abstract Syntax Tree expression node
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Date: 15/10/2018 */

#ifndef ASTEXPRESSION_HPP
#define ASTEXPRESSION_HPP

#include "AST.hpp"
#include "Literal.hpp"

enum Operand{
  PLUS, MINUS, MUL, DIV, MOD, U_MINUS
};

class ASTExpression: public AST{
public:
  ASTExpression(Operand op, AST* l, AST* r);

  int eval();
  void printNode();
private:
  Operand operand;
};

#endif /* ASTEXPRESSION_HPP */
