/* Symbol definitions
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 19/10/2018 */

#include "include/Symbol.hpp"

Symbol::Symbol(std::string* sym, int n): id(sym), lineno(n), state(UNDEFINED){

}

bool SymCmp::operator()(const Symbol* l, const Symbol* r) const{
    return (*(l->id)) < (*(r->id));
}

Symbol::~Symbol(){
    free(id);

    switch (type) {
        case SIM:
            if(val) free(val);
            break;
        case ARRAY:
            if(vals){
                for(Value* v : *vals){
                    free(v);
                }
                free(vals);
            }
            break;
    }
}
