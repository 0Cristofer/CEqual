/* Abstract Syntax Tree abstract class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 12/11/2018
   Edited: 12/11/2018 */

#ifndef CEQUAL_ASTDECSUB_HPP
#define CEQUAL_ASTDECSUB_HPP

#include "AST.hpp"

class ASTDecSub: public AST {
public:
    ASTDecSub(Scope *s, AST *param, AST *block, LiteralType t);

    Value * call(AST *a);

    LiteralType type;
    std::vector<std::pair<LiteralType, SymType>*>* params = nullptr;
    std::vector<Symbol*>* syms;

protected:
    Value *inEval() override;
};


#endif /* CEQUAL_ASTDECSUB_HPP */
