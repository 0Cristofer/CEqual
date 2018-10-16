/* Abstract leaf node for literal
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Date: 15/10/2018 */

#ifndef LITERAL_HPP
#define LITERAL_HPP

enum LiteralType{
  INT, BOOL, STR
};

class Literal{
public:
  Literal(LiteralType t);

  LiteralType type;
};

#endif /* LITERAL_HPP */
