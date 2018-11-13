/* Abstract Syntax Tree abstract class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 07/11/2018 */

#ifndef CEQUAL_ASTEXPLIST_HPP
#define CEQUAL_ASTEXPLIST_HPP

#include "AST.hpp"

class ASTExpList: public AST {
public:
    ASTExpList(AST* a, Scope *s);

    std::vector<Value*>* vals;
protected:
    Value *inEval() override;
};


#endif /* CEQUAL_ASTEXPLIST_HPP */
