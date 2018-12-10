/* Abstract leaf node for literal
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 16/10/2018 */

#ifndef LITERAL_HPP_CEQUAL
#define LITERAL_HPP_CEQUAL

#include <string>
#include "Value.hpp"

// Possble literal types
enum LiteralType {
    INT, BOOL, STR, VOID
};

class Literal: public Value {
public:
    explicit Literal(LiteralType t, std::string name);

    LiteralType type;
    std::string name;
};

#endif /* LITERAL_HPP_CEQUAL */
