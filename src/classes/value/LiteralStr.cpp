/* Leaf node for string definitons
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 19/10/2018 */

#include "include/LiteralStr.hpp"

LiteralStr::LiteralStr(std::string* s): Literal(STR){
    s->erase(0, 1);
    s->erase(s->size()-1, 1);

    val = s;
}

LiteralStr::~LiteralStr(){
    free(val);
}
