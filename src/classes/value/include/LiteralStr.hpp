/* Leaf node for string literal
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 19/10/2018 */

#ifndef LITERALSTR_HPP_CEQUAL
#define LITERALSTR_HPP_CEQUAL

#include <string>

#include "Literal.hpp"

class LiteralStr: public Literal{
public:
    // Stores the boolean value of the node
    explicit LiteralStr(std::string *s);
    ~LiteralStr();

    std::string* val;
};

#endif /* LITERALSTR_HPP_CEQUAL */
