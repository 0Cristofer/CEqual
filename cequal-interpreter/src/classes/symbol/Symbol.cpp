/* Symbol definitions
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 19/10/2018 */

#include "include/Symbol.hpp"
#include "../value/include/Literal.hpp"
#include "../value/include/LiteralInt.hpp"
#include "../value/include/LiteralBool.hpp"
#include "../value/include/LiteralStr.hpp"
#include "../../include/util.hpp"

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
        case PROC:
            break;
        case FUNC:
            break;
    }
}

Symbol *Symbol::duplicate() {
    Symbol* s;

    s = new Symbol(id, lineno);

    if(val){
        if (val->type == LITERALVAL) {
            switch (((Literal *) val)->type) {
                case INT:
                    s->val = new LiteralInt(((LiteralInt *) val)->val);
                    break;
                case BOOL:
                    s->val = new LiteralBool(((LiteralBool *) val)->val);
                    break;
                case STR:
                    s->val = val;
                    break;
                case VOID:
                    break;
            }
        }
        else{ // TODO error case
            semanticError(lineno);
        }
    }
    else {
        s->size = size;
        s->vals = vals;
    }

    s->type = type;

    return s;
}
