/* Abstract Syntax Tree variable list specification
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 12/11/2018
   Edited: 12/11/2018 */

#ifndef CEQUAL_ASTPARAMLIST_HPP
#define CEQUAL_ASTPARAMLIST_HPP


#include "AST.hpp"

class ASTParamList : public AST{
public:
    ASTParamList(AST* ast, Scope *s);

protected:
    Value *inEval() override;
};


#endif //CEQUAL_ASTPARAMLIST_HPP
