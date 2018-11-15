/* Abstract Syntax Tree procedure call class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 12/11/2018
   Edited: 12/11/2018 */

#ifndef ASTCALLPROC_HPP_CEQUAL
#define ASTCALLPROC_HPP_CEQUAL

#include "AST.hpp"

class ASTCallProc: public AST {
public:
    // Creates a precedure call command, recieving the symbol representing the procedure,
    // the arguments and the type of call (funcion or procedure)
    ASTCallProc(Symbol *sm, AST *a, SymType t, Scope *s);

    void printNode() override;

    Symbol *sym;
    SymType s_t;

protected:
    // Verify the type of the call and call the procedure passing the arguments (first child of this node)
    Value *inEval() override;
};


#endif /* ASTCALLPROC_HPP_CEQUAL */
