/* Abstract Syntax Tree literal node
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 18/10/2018 */

#ifndef ASTLITERAL_HPP
#define ASTLITERAL_HPP

#include "AST.hpp"
#include "../../value/include/Literal.hpp"

class ASTLiteral: public AST{
public:
  // Sets up the literal value stored by this node
  ASTLiteral(Literal* lit);

  // Implementation of the pure virtual. Evaluates the literal by returning a literal value
  Value* inEval();
  void printNode();
private:
  Literal* literal;
};

#endif /* ASTLITERAL_HPP */
