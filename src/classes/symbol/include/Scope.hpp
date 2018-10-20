/* Scope class for symbol management
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 19/10/2018 */

#ifndef SCOPE_HPP
#define SCOPE_HPP

#include <set>

#include "Symbol.hpp"

class Scope{
public:
  // Create a new scope having the reference to the previous one
  Scope(Scope *p);
  ~Scope();

  // Adds a symbol to this scope's table
  Symbol* addSym(Symbol* s);

  Scope* prev;
private:
  std::set<Symbol*, SymCmp> sym_tab;
};

#endif /* SCOPE_HPP */