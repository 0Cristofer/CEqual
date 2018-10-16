/* Leaf node for integers definitons
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Date: 15/10/2018 */

#include <iostream>

#include "include/LiteralInt.hpp"

LiteralInt::LiteralInt(int v): Literal(INT), val(v){
  type = INT;
}
