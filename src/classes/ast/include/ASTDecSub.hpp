/* Abstract Syntax Tree subprogram declaration class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 12/11/2018
   Edited: 17/11/2018 */

#ifndef CEQUAL_ASTDECSUB_HPP
#define CEQUAL_ASTDECSUB_HPP

#include "AST.hpp"
#include "../../value/include/Literal.hpp"
#include "../../symbol/include/Symbol.hpp"

class ASTDecSub: public AST {
public:
    // Creates a new node by getting the parameters node, the block of this subprogram and its return type (default: INT)
    ASTDecSub(AST *param, AST *block, LiteralType t);


    // Calls this function, recieving its arguments and verifing them. Only unstack the scope if needed
    Value *call(AST *a, bool unstack);

    void printNode() override;

    LiteralType type;
    std::vector<std::pair<LiteralType, SymType> *> *params = nullptr; // Used for argument verification <type, var type (simple or array)>
    std::vector<Symbol *> *syms = nullptr; // The symbols refering the arguments

protected:
    // Evaluates the arguments node, setting up the params var
    Value *inEval() override;
};


#endif /* CEQUAL_ASTDECSUB_HPP */
