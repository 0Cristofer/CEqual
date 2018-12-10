#include <utility>

/* Abstract leaf node for literal definitions
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 15/10/2018 */

#include "include/Literal.hpp"

std::string LITER[3] = {
        "int",
        "bool"
        "string"
};

Literal::Literal(LiteralType t, std::string name): Value(LITERALVAL), type(t), name(std::move(name)){

}
