/* Abstract Syntax Tree variable list specification
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 12/11/2018
   Edited: 12/11/2018 */

#include "src/classes/ast/include/ASTParamSpec.hpp"
#include "src/classes/value/include/LiteralInt.hpp"
#include "src/classes/value/include/LiteralBool.hpp"
#include "src/classes/value/include/LiteralStr.hpp"

#include "src/classes/ast/include/ASTParamSpec.hpp"

ASTParamSpec::ASTParamSpec(Symbol* sym, Scope *s) : AST(PARAMSPEC, s) {
    this->addSymbol(sym);
}

void ASTParamSpec::addSymbol(Symbol *sym) {
    syms.push_back(sym);
}

Value *ASTParamSpec::inEval() {
    for(Symbol* s: syms) {
        switch (type) {
            case INT:
                if(s->type == SIM) s->val = new LiteralInt(0);
                else{
                    s->size = 1;
                    s->vals = new std::vector<Value*> ();
                    s->vals->push_back(new LiteralInt(0));
                }
                break;
            case BOOL:
                if(s->type == SIM) s->val = new LiteralBool(false);
                else{
                    s->size = 1;
                    s->vals = new std::vector<Value*> ();
                    s->vals->push_back(new LiteralBool(false));
                }
                break;
            case STR:
                if(s->type == SIM) s->val = new LiteralStr(new std::string());
                else{
                    s->size = 1;
                    s->vals = new std::vector<Value*> ();
                    s->vals->push_back(new LiteralStr(new std::string()));
                }
                break;
        }
        return nullptr;
    }
}
