/* Abstract Syntax Tree array declaration list
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 07/11/2018
   Edited: 07/11/2018 */

#ifndef CEQUAL_ASTLISTDEC_HPP
#define CEQUAL_ASTLISTDEC_HPP


#include "AST.hpp"

class ASTListDec: public AST {
public:
    explicit ASTListDec(AST* child, Scope* s);

    void printNode() override;

protected:
    Value *inEval() override;
};


#endif //CEQUAL_ASTLISTDEC_HPP
