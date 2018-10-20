/* Symbol definitions
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 19/10/2018 */

#ifndef SYMBOL_HPP
#define SYMBOL_HPP

#include <string>
#include <vector>

#include "../../value/include/Value.hpp"

enum SymState{
  UNDEFINED, DEFINED
};

enum SymType{
  SIM, ARRAY
};

class Symbol{
public:
  Symbol(std::string* sym, int n);
  ~Symbol();

  int lineno;
  int size;
  std::string* id;
  std::vector<Value*>* vals;
  SymState state;
  SymType type;
  Value* val = NULL;
private:
};

// Implements the symbol pointer comparition for use in set
struct SymCmp{
  bool operator()(const Symbol* l, const Symbol* r) const;
};

#endif /* SYMBOL_HPP */
