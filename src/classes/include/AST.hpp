/* Abstract Syntax Tree abstract class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 18/10/2018 */

#ifndef AST_HPP
#define AST_HPP

#include <vector>
#include "Value.hpp"
#include "Literal.hpp"

// Possible AST types
enum ASTType{
 LITERAL, EXPRESSION
};

class AST{
public:
  AST(ASTType t);

  // Adds a child to this node
  void addChild(AST* ast);
  // Evaluates the node, freeing its children and returning a generic value
  Value* eval();

  // Pure virtual. Should print node information
  virtual void printNode() = 0;

  ASTType type;
protected:
  // Pure virtual. Should make the actual evaluation of the node and its children
  virtual Value* inEval() = 0;

  std::vector<AST*> children;
};

#endif /* AST_HPP */
