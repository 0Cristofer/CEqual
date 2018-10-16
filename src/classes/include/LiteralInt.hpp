/* Leaf node for integers
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Date: 15/10/2018 */

#ifndef LITERALINT_HPP
#define LITERALINT_HPP

#include "Literal.hpp"

class LiteralInt: public Literal{
public:
  LiteralInt(int v);

  int val;
};

#endif /* LITERALINT_HPP */
