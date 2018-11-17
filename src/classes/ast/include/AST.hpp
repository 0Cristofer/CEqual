/* Abstract Syntax Tree abstract class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 17/11/2018 */

#ifndef AST_HPP_CEQUAL
#define AST_HPP_CEQUAL

#include <vector>

#include "../../value/include/Value.hpp"

// Possible AST types
enum ASTType {
    LITERAL, EXPRESSION, BLOCK, SPECVAR, LISTSPECVAR, ARRAYINIT, DECVAR, VARUSE, CMDWRITE, LISTDEC, CMDS,
    PARAMSPEC, PARAMLIST, DECSUB, EXPLIST, CALLPROC, CMDATRIB, CMDREAD, CMDIF, CMDWHILE, CMDFOR, CMDSTOP
};

class AST {
public:
    // Sets up the type of this node
    explicit AST(ASTType t);

    // Adds a child to this node
    void addChild(AST *ast);
    // Evaluates the node, calling inEval() and returning a generic value
    Value *eval();

    // Pure virtual. Should print node information
    virtual void printNode() = 0;

    // Actual node tipe
    ASTType a_type;
    std::vector<AST *> children;

protected:
    // Pure virtual. Should make the actual evaluation of the node and its children
    virtual Value *inEval() = 0;

    int line = 0;
};

#endif /* AST_HPP_CEQUAL */
