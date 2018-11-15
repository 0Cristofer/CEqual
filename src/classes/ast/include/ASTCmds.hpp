/* Abstract Syntax Tree command list
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 07/11/2018
   Edited: 07/11/2018 */

#ifndef ASTCMDS_HPP_CEQUAL
#define ASTCMDS_HPP_CEQUAL


#include "AST.hpp"

class ASTCmds: public AST {
public:
    explicit ASTCmds(Scope *s);

    void printNode() override;

protected:
    // Just iterate the children
    Value *inEval() override;
};


#endif /* ASTCMDS_HPP_CEQUAL */
