/* Symbol definitions
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 07/11/2018 */

#ifndef SYMBOL_HPP_CEQUAL
#define SYMBOL_HPP_CEQUAL

#include <string>
#include <vector>

#include "../../value/include/Value.hpp"

class AST;

enum SymState {
    UNDEFINED, DEFINING, DEFINED
};

enum SymType {
    SIM, ARRAY, PROC, FUNC
};

class Symbol {
public:
    Symbol(std::string *sym, int n);
    // Duplicates a symbol, by duplicating its members and the value (if it is a simple symbol)
    Symbol* duplicate();
    ~Symbol();

    int lineno; // Line of the declaration
    int size; // Number of elements (if it is an array)
    std::string *id; // String (name) of this symbol
    std::vector<Value *> *vals = nullptr; // Vector with the values (if it is an array)
    SymState state;
    SymType type;
    Value *val = nullptr; // Value of this symbol (if it is a simpĺe var)
    AST *proc; // Pointer to the DecSub node (if it as procedure symbol)
};

// Implements the symbol pointer comparition for use in set
struct SymCmp{
    bool operator()(const Symbol* l, const Symbol* r) const;
};

#endif /* SYMBOL_HPP_CEQUAL */
