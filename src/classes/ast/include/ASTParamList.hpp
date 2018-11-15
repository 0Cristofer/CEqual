/* Abstract Syntax Tree variable list specification
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 12/11/2018
   Edited: 12/11/2018 */

#ifndef ASTPARAMLIST_HPP_CEQUAL
#define ASTPARAMLIST_HPP_CEQUAL

#include "AST.hpp"

class ASTParamList : public AST{
public:
    ASTParamList(AST *ast, Scope *s);

    void printNode() override;

    std::vector<std::pair<LiteralType, SymType> *> *params;
    std::vector<Symbol *> *syms;
protected:
    // Sets up the parameter list, by adding them to the symbol table and saving them to the next node
    Value *inEval() override;
};


#endif /* ASTPARAMLIST_HPP_CEQUAL */
