/* Abstract Syntax Tree block
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 19/10/2018 */

#ifndef ASTBLOCK_HPP
#define ASTBLOCK_HPP

#include "AST.hpp"
#include "../../symbol/include/Scope.hpp"

class ASTBlock: public AST{
public:
  // Sets up scope stored by this node
  ASTBlock(Scope* s);

  // Implementation of the pure virtual.
  Value* inEval();
  void printNode();

  // The scope of this block
  Scope* scope;
private:
};

#endif /* ASTBLOCK_HPP */