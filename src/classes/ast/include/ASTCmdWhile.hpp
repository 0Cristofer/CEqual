/* Abstract Syntax Tree while command class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/11/2018
   Edited: 17/11/2018 */

#ifndef ASTCMDWHILE_HPP_CEQUAL
#define ASTCMDWHILE_HPP_CEQUAL

#include "AST.hpp"

class ASTCmdWhile: public AST {
public:
    // Constructs the node by recieving the true and test nodes
    ASTCmdWhile(AST *t, AST *e);

    void printNode() override;

protected:
    // Keeps testing the "test" node and while it is true, evaluate the command child
    Value *inEval() override;
};


#endif /* ASTCMDWHILE_HPP_CEQUAL */
