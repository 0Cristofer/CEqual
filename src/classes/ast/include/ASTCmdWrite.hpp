/* Abstract Syntax Tree command write
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 18/10/2018 */

#ifndef ASTCMDWRITE_HPP
#define ASTCMDWRITE_HPP

#include "AST.hpp"

class ASTCmdWrite: public AST{
public:
  ASTCmdWrite(AST* e);

  Value* inEval();
  void printNode();

private:
};

#endif /* ASTCMDWRITE_HPP */
