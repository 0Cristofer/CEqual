/* Abstract Syntax Tree array initialization
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 19/10/2018 */

#ifndef ASTARRAYINIT_HPP
#define ASTARRAYINIT_HPP

#include <vector>

#include "AST.hpp"
#include "../../value/include/Value.hpp"

class ASTArrayInit: public AST{
public:
    explicit ASTArrayInit(AST* l);

    // Implementation of the pure virtual.
    Value* inEval() override;
    void printNode() override;

    std::vector<Value*>* vals;
private:
};

#endif /* ASTARRAYINIT_HPP */
