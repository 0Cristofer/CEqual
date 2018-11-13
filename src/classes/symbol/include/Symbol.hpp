/* Symbol definitions
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 07/11/2018 */

#ifndef SYMBOL_HPP
#define SYMBOL_HPP

#include <string>
#include <vector>

#include "../../value/include/Value.hpp"

class AST;

enum SymState{
    UNDEFINED, DEFINING, DEFINED
};

enum SymType{
    SIM, ARRAY, PROC, FUNC
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
    Value* val = nullptr;
    AST* proc;
private:
};

// Implements the symbol pointer comparition for use in set
struct SymCmp{
    bool operator()(const Symbol* l, const Symbol* r) const;
};

#endif /* SYMBOL_HPP */
