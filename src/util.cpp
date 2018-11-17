/* Util informations and routines
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 18/10/2018
   Edited: 07/11/2018 */

#include "include/util.hpp"
#include "classes/ast/include/AST.hpp"

bool typeCheck(Value *v, LiteralType t, int line){
    bool res = false;

    if(!v) return true;

    switch (v->type) {
        case LITERALVAL:
            res = ((Literal *)v)->type == t;
            if(!res) typeError(line);
            break;

        default:
            std::cerr << "Not implemented" << std::endl;
            break;
    }

    return res;
}

void semanticError(int line){
    std::cerr << "Semantic error at line " << line << std::endl;
}

void typeError(int line){
    std::cerr << "Semantic error: type error at line " << line << std::endl;
}

void arraySizeMismatchError(int line){
    std::cerr << "Semantic error: array initialization with more elements than specified at line " << line << std::endl;
}

void notInitializedError(int line, std::string symbol){
    std::cerr << "Semantic error: symbol \'" << symbol  << "\' not defined at: " << line << std::endl;
}
