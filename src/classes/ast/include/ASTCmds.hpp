/* Abstract Syntax Tree command list
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 07/11/2018
   Edited: 07/11/2018 */

#ifndef CEQUAL_ASTCMDS_HPP
#define CEQUAL_ASTCMDS_HPP


#include "AST.hpp"

class ASTCmds: public AST {
public:
    explicit ASTCmds(Scope* s);

    void printNode() override;

protected:
    Value *inEval() override;
};


#endif //CEQUAL_ASTCMDS_HPP
