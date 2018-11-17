/* Leaf node for integer literal
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 15/10/2018 */

#ifndef LITERALINT_HPP_CEQUAL
#define LITERALINT_HPP_CEQUAL

#include "Literal.hpp"

class LiteralInt: public Literal{
public:
    // Stores the integer value of the node
    explicit LiteralInt(int v);

    int val;
};

#endif /* LITERALINT_HPP_CEQUAL */
