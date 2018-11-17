/* Leaf node for boolean literal
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 18/10/2018
   Edited: 18/10/2018 */

#ifndef LITERALBOOL_HPP_CEQUAL
#define LITERALBOOL_HPP_CEQUAL

#include "Literal.hpp"

class LiteralBool: public Literal{
public:
    // Stores the boolean value of the node
    explicit LiteralBool(bool b);

    bool val;
};

#endif /* LITERALBOOL_HPP_CEQUAL */
