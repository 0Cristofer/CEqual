/* Abstract Syntax Tree variable list specification
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 12/11/2018
   Edited: 17/11/2018 */

#ifndef ASTPARAMLIST_HPP_CEQUAL
#define ASTPARAMLIST_HPP_CEQUAL

#include "AST.hpp"
#include "../../value/include/Literal.hpp"
#include "../../symbol/include/Symbol.hpp"

class ASTParamList : public AST{
public:
    explicit ASTParamList(AST *ast);

    void printNode() override;

    std::vector<std::pair<LiteralType, SymType> *> *params = nullptr;
    std::vector<Symbol *> *syms = nullptr;
protected:
    // Sets up the parameter list, by adding them to the symbol table and saving them to the next node
    Value *inEval() override;
};


#endif /* ASTPARAMLIST_HPP_CEQUAL */
