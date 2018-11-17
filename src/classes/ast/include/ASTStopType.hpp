/* Abstract Syntax Tree stop types class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 16/11/2018
   Edited: 17/11/2018 */

#ifndef ASTSTOPTYPE_HPP_CEQUAL
#define ASTSTOPTYPE_HPP_CEQUAL

#include "AST.hpp"
#include "../../value/include/StopType.hpp"

class ASTStopType: public AST {
public:
    ASTStopType(SType stop, AST* exp);

    void printNode() override;

    SType stype;
protected:
    Value *inEval() override;
};


#endif /* ASTSTOPTYPE_HPP_CEQUAL */
