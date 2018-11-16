/* Abstract Syntax Tree if command class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/11/2018
   Edited: 15/11/2018 */

#ifndef ASTCMDIF_HPP_CEQUAL
#define ASTCMDIF_HPP_CEQUAL


#include "AST.hpp"

class ASTCmdIf: public AST {
public:
    // Constructs the node by recieving the true, false and test nodes
    ASTCmdIf(AST *t, AST *f, AST *e, Scope *s);

    void printNode() override;

protected:
    // Evaluate the test and if it is true, evaluate the "true" child, else, if there is another node, evaluate it
    Value *inEval() override;
};


#endif /* ASTCMDIF_HPP_CEQUAL */
