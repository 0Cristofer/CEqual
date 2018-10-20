/* Abstract Syntax Tree variable use
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 18/10/2018 */

#ifndef ASTVARUSE_HPP
#define ASTVARUSE_HPP

#include "AST.hpp"
#include "../../symbol/include/Symbol.hpp"

class ASTVarUse: public AST{
public:
  // Sets up the literal value stored by this node
  ASTVarUse(Symbol* s, AST* e);

  // Implementation of the pure virtual. Evaluates the literal by returning a literal value
  Value* inEval();
  void printNode();

  Symbol* sym;
private:
};

#endif /* ASTVARUSE_HPP */
