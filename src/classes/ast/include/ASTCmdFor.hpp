/* Abstract Syntax Tree for command class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/11/2018
   Edited: 15/11/2018 */

#ifndef ASTCMDFOR_HPP_CEQUAL
#define ASTCMDFOR_HPP_CEQUAL


#include "AST.hpp"

class ASTCmdFor: public AST {
public:
    // Constructs the node by recieving the initialization, step, command and test nodes
    ASTCmdFor(AST *init, AST *step, AST *cmd, AST* test, Scope *s);

    void printNode() override;

protected:
    // Calls the initialization then evaluate the test. While the test is true, runs the command them the step
    Value *inEval() override;
};


#endif /* ASTCMDFOR_HPP_CEQUAL */
