/* Abstract Syntax Tree command write
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 20/10/2018
   Edited: 15/11/2018 */

#ifndef ASTCMDWRITE_HPP_CEQUAL
#define ASTCMDWRITE_HPP_CEQUAL

#include "AST.hpp"

class ASTCmdWrite: public AST{
public:
    explicit ASTCmdWrite(AST* e, Scope* s);

    Value* inEval() override;
    void printNode() override;

private:
};

#endif /* ASTCMDWRITE_HPP_CEQUAL */
