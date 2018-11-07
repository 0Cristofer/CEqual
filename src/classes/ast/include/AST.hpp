/* Abstract Syntax Tree abstract class.
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 19/10/2018 */

#ifndef AST_HPP_CEQUAL
#define AST_HPP_CEQUAL

#include <vector>

#include "../../value/include/Value.hpp"
#include "../../value/include/Literal.hpp"

// Possible AST types
enum ASTType{
    LITERAL, EXPRESSION, BLOCK, SPECVAR, LISTSPECVAR, ARRAYINIT, DECVAR, VARUSE, CMDWRITE, LISTDEC, CMDS
};

class AST{
public:
    explicit AST(ASTType t);

    // Adds a child to this node
    void addChild(AST* ast);
    // Evaluates the node, freeing its children and returning a generic value
    Value* eval();

    // Pure virtual. Should print node information
    virtual void printNode() = 0;

    // Actual node tipe
    ASTType a_type;
protected:
    // Pure virtual. Should make the actual evaluation of the node and its children
    virtual Value* inEval() = 0;

    std::vector<AST*> children;
};

#endif /* AST_HPP_CEQUAL */
