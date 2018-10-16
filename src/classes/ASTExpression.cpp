/* Abstract Syntax Tree expression node definitions
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Date: 15/10/2018 */

#include <iostream>

#include "include/ASTExpression.hpp"
#include "include/ASTLiteral.hpp"
#include "include/LiteralInt.hpp"
#include "../cequal.tab.h"

ASTExpression::ASTExpression(Operand op, AST* l, AST* r): AST(EXPRESSION), operand(op){
  addChildren(l);
  addChildren(r);
}

int ASTExpression::eval(){
  int res, lval, rval;

  std::cout << "Evaluating..." << std::endl;
  //printNode();
  switch (operand) {
    case PLUS:
      lval = children[0]->eval();
      rval = children[1]->eval();
      res = lval + rval;
      std::cout << "Calculating: " << lval << " + " << rval << " = " << res << std::endl;
      break;
    case MINUS:
      lval = children[0]->eval();
      rval = children[1]->eval();
      res = lval - rval;
      std::cout << "Calculating: " << lval << " - " << rval << " = " << res << std::endl;
      break;
    case MUL:
      lval = children[0]->eval();
      rval = children[1]->eval();
      res = lval * rval;
      std::cout << "Calculating: " << lval << " * " << rval << " = " << res << std::endl;
      break;
    case DIV:
      lval = children[0]->eval();
      rval = children[1]->eval();
      res = lval / rval;
      std::cout << "Calculating: " << lval << " / " << rval << " = " << res << std::endl;
      break;
    case MOD:
      lval = children[0]->eval();
      rval = children[1]->eval();
      res = lval % rval;
      std::cout << "Calculating: " << lval << " \% " << rval << " = " << res << std::endl;
      break;
    case U_MINUS:
      lval = children[0]->eval();
      res = -lval;
      std::cout << "Calculating: " << "-" << lval << " = " << res << std::endl;
      break;
  }

  return res;
}

void ASTExpression::printNode(){
  std::cout << "Node type: ASTExpression" << std::endl;

  std::cout << "\tHas: " << children.size() << " children, wich are:" << std::endl;

  for(AST* ast : children){
    std::cout << "\t";
    ast->printNode();
  }

  std::cout << "------------------" << std::endl;
}
