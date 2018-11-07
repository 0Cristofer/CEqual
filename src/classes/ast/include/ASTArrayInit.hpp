/* Abstract Syntax Tree array initialization node
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 07/11/2018 */

#ifndef ASTARRAYINIT_HPP_CEQUAL
#define ASTARRAYINIT_HPP_CEQUAL

#include <vector>

#include "AST.hpp"
#include "../../value/include/Value.hpp"

class ASTArrayInit: public AST{
public:
    // A array initialization gets only the first child, the others are added after
    explicit ASTArrayInit(AST* l, Scope* s);

    // Evaluate the node by reading all literal values and checking if they are of the same type. In the end, the values are stored in vector vals
    Value* inEval() override;
    void printNode() override;

    // The values read
    std::vector<Value*>* vals;
private:
};

#endif /* ASTARRAYINIT_HPP_CEQUAL */
