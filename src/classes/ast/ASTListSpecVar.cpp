/* Abstract Syntax Tree variable list specification
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 19/10/2018 */

#include <iostream>

#include "include/ASTListSpecVar.hpp"
#include "include/ASTSpecVar.hpp"

ASTListSpecVar::ASTListSpecVar(AST* r): AST(LISTSPECVAR){
  if(r) addChild(r);
}

Value* ASTListSpecVar::inEval(){
  Symbol* sym;

  for(AST* a : children){
    sym = ((ASTSpecVar*)a)->sym;

    if(sym->type == SIM){
      sym->val = a->eval();
    }
    else{
      a->eval();
    }
    syms.push_back(sym);
  }

  return NULL;
}

void ASTListSpecVar::printNode(){
  std::cout << "Node type: ASTSListSpecVar" << std::endl;
}
