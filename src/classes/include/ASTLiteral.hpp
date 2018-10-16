/* Abstract Syntax Tree literal node
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Date: 15/10/2018 */

#ifndef ASTLITERAL_HPP
#define ASTLITERAL_HPP

#include "AST.hpp"
#include "Literal.hpp"

class ASTLiteral: public AST{
public:
  ASTLiteral(Literal* lit);

  int eval();
  void printNode();
private:
  Literal* literal;
};

#endif /* ASTLITERAL_HPP */
