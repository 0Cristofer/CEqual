/* Abstract Syntax Tree array declaration list
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 07/11/2018
   Edited: 07/11/2018 */

#ifndef ASTLISTDEC_HPP_CEQUAL
#define ASTLISTDEC_HPP_CEQUAL


#include "AST.hpp"

class ASTListDec: public AST {
public:
    explicit ASTListDec(AST *child, Scope *s);

    void printNode() override;

protected:
    // Just evaluate the children
    Value *inEval() override;
};


#endif /* ASTLISTDEC_HPP_CEQUAL */
