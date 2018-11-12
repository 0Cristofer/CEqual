/* Abstract Syntax Tree variable list specification
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 12/11/2018
   Edited: 12/11/2018 */

#ifndef CEQUAL_ASTPARAMSPEC_HPP
#define CEQUAL_ASTPARAMSPEC_HPP


#include "AST.hpp"

class ASTParamSpec : public AST{
public:
    ASTParamSpec(Symbol* sym, Scope *s);

    void addSymbol(Symbol* sym);

    LiteralType type;

protected:
    Value *inEval() override;

public:

    std::vector<Symbol*> syms;
};


#endif /* CEQUAL_ASTPARAMSPEC_HPP */
