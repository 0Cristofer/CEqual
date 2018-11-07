/* Scope class for symbol management
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 19/10/2018 */

#include <iostream>
#include <src/classes/symbol/include/Scope.hpp>


#include "include/Scope.hpp"

Scope::Scope(Scope* p): prev(p){

}

Symbol* Scope::addSym(Symbol* s){
    auto ins = sym_tab.insert(s);

    if(!ins.second){
        free(s);
        //std::cout << "New symbol, id: " << *(s->id) << " at: " << s->lineno << std::endl;
    }

    return *ins.first;
}

Scope::~Scope(){
    for(Symbol* s : sym_tab){
        free(s);
    }
}

Symbol *Scope::getSym(Symbol *s) {
    auto sm = sym_tab.find(s);
    Symbol* a_sym;

    if (sm != sym_tab.end()){
        free(s);
        return *sm;
    }

    a_sym = s;
    s = prev->getSym(a_sym);

    return s;
}
