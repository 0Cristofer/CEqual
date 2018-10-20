/* Abstract Syntax Tree variable list specification
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 19/10/2018 */

#ifndef ASTLISTSPECVAR_HPP
#define ASTLISTSPECVAR_HPP

#include <vector>

#include "AST.hpp"
#include "../../symbol/include/Symbol.hpp"

class ASTListSpecVar: public AST{
public:
  ASTListSpecVar(AST* r);

  // Implementation of the pure virtual.
  Value* inEval();
  void printNode();

  std::vector<Symbol*> syms;
private:
};

#endif /* ASTLISTSPECVAR_HPP */
