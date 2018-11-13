/* Abstract Syntax Tree abstract class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 07/11/2018 */

#ifndef CEQUAL_ASTCALLPROC_HPP
#define CEQUAL_ASTCALLPROC_HPP

#include "AST.hpp"

class ASTCallProc: public AST {
public:
    ASTCallProc(Scope *s, Symbol *sm, AST *a, SymType t);

    Symbol* sym;
    SymType s_t;
protected:
    Value *inEval() override;
};


#endif /* CEQUAL_ASTCALLPROC_HPP */
