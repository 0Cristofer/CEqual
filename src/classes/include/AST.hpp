/* Abstract Syntax Tree abstract class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Date: 15/10/2018 */

#ifndef AST_HPP
#define AST_HPP

#include <vector>

enum ASTType{
 LITERAL, EXPRESSION
};

class AST{
public:
  AST(ASTType t);

  void addChildren(AST* ast);
  virtual void printNode() = 0;
  virtual int eval() = 0;

  ASTType type;
protected:
  std::vector<AST*> children;
};

#endif /* AST_HPP */
