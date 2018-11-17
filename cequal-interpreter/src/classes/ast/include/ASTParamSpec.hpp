/* Abstract Syntax Tree parameter specification specification
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 12/11/2018
   Edited: 17/11/2018 */

#ifndef ASTPARAMSPEC_HPP_CEQUAL
#define ASTPARAMSPEC_HPP_CEQUAL

#include "AST.hpp"
#include "../../symbol/include/Symbol.hpp"
#include "../../value/include/Literal.hpp"

class ASTParamSpec : public AST{
public:
    // Each parameter specification refers to one type
    explicit ASTParamSpec(Symbol *sym);

    void addSymbol(Symbol *sym);

    void printNode() override;

    LiteralType type = INT;
    std::vector<Symbol *> syms; // All symbols of this type

protected:
    // Evaluate all symbols, initializing them with it type
    Value *inEval() override;
};


#endif /* ASTPARAMSPEC_HPP_CEQUAL */
