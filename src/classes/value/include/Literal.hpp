/* Abstract leaf node for literal
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 15/10/2018 */

#ifndef LITERAL_HPP
#define LITERAL_HPP

#include "Value.hpp"

// Possble literal types
enum LiteralType{
  INT, BOOL, STR
};

class Literal: public Value{
public:
  Literal(LiteralType t);

  LiteralType type;
};

#endif /* LITERAL_HPP */
