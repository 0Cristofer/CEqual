/* Scope class for symbol management
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 07/11/2018 */

#include <iostream>

#include "include/Scope.hpp"

Scope::Scope(Scope* p): prev(p){

}

Symbol* Scope::addSym(Symbol* s){
    auto ins = sym_tab.insert(s);

    return *ins.first;
}

Scope::~Scope(){
    for(Symbol* s : sym_tab){
        free(s);
    }
}

Symbol *Scope::getSym(Symbol *s) {
    auto sm = sym_tab.find(s);
    Symbol* a_sym = nullptr;

    if (sm != sym_tab.end()){
        return *sm;
    }


    a_sym = s;
    if(prev != nullptr) s = prev->getSym(a_sym);

    return s;
}

void Scope::removeSym(Symbol *s) {
    auto sm = sym_tab.find(s);
    Symbol* a_sym = nullptr;

    if (sm != sym_tab.end()){
        sym_tab.erase(sm);
    }

    a_sym = s;
    if(prev != nullptr) prev->removeSym(a_sym);
}
