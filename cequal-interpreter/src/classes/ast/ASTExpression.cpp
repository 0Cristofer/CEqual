/* Abstract Syntax Tree expression node definitions
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 15/10/2018
   Edited: 17/11/2018 */

#include <iostream>

#include "include/ASTExpression.hpp"
#include "include/ASTLiteral.hpp"
#include "../value/include/LiteralStr.hpp"
#include "../../include/util.hpp"

// Adds the operands nodes if they exist
ASTExpression::ASTExpression(ExpType t, Operand op, AST *l, AST *r, AST *test):
        AST(EXPRESSION), type(t), operand(op){
    if(l) addChild(l);
    if(r) addChild(r);
    if(test) addChild(test);
}

// Verify the operation type and calls the correct function if the operands types are correct
Value* ASTExpression::inEval(){
    Value *lval = nullptr, *rval = nullptr, *testval = nullptr, *res = nullptr;

    switch (type) {
        case ARITM:
            lval = children[0]->eval();
            if(operand != U_MINUS) rval = children[1]->eval(); // Only evaluate right child if it is not a unary minus operation

            if(typeCheck(lval, INT, line) && typeCheck(rval, INT, line)){ // Check for the type
                res = intEval(((LiteralInt *)lval)->val, rval ? ((LiteralInt *)rval)->val : 0); // Perform action
            }
            else{ // TODO error case
                res = new LiteralInt(0); // If types are wrong, return 0
            }

            break;

        case COMP:
            lval = children[0]->eval();
            rval = children[1]->eval();

            if((operand == EQL) || (operand == DIF)) {
                if (typeCheck(lval, ((Literal *) rval)->type, line)) {
                    switch (((Literal *) rval)->type) {
                        case INT:
                            res = intCompEval(((LiteralInt *) lval)->val, ((LiteralInt *) rval)->val);
                            break;
                        case BOOL:
                            res = boolCompEval(((LiteralBool *) lval)->val, ((LiteralBool *) rval)->val);
                            break;
                        case STR:
                            res = strCompEval(((LiteralStr *) lval)->val, ((LiteralStr *) rval)->val);
                            break;
                        case VOID:
                            break;
                    }
                }
                else { // TODO error case
                    res = new LiteralBool(false);
                }
            }
            else{
                if (typeCheck(lval, INT, line) && typeCheck(rval, INT, line)) {
                    res = intCompEval(((LiteralInt *) lval)->val, ((LiteralInt *) rval)->val);
                }
                else { // TODO error case
                    res = new LiteralBool(false);
                }
            }

            break;

        case LOGIC:
            lval = children[0]->eval();
            if(operand != NOT) rval = children[1]->eval();

            if(typeCheck(lval, BOOL, line) && typeCheck(rval, BOOL, line)){
                res = logicEval(((LiteralBool *)lval)->val, rval ? ((LiteralBool *)rval)->val : false);
            }
            else{ // TODO error case
                res = new LiteralBool(false);
            }

            break;

        case TERN:
            testval = children[2]->eval();

            if(typeCheck(testval, BOOL, line)){
                if(((LiteralBool *)testval)->val){
                    res = children[0]->eval(); // 0 = left operand
                }
                else{
                    res = children[1]->eval(); // 1 = right operand
                }
            }
            else{ // TODO error case
                res = new LiteralInt(0);
            }
    }

    return res;
}

// Evaluates a integer expression by performing the correct aritmetic action based on the operator
LiteralInt *ASTExpression::intEval(int l, int r){
    int res;

    switch (operand) {
        case PLUS:
            res = l + r;
            break;

        case MINUS:
            res = l - r;
            break;

        case MUL:
            res = l * r;
            break;

        case DIV:
            res = l / r;
            break;

        case MOD:
            res = l % r;
            break;

        case U_MINUS:
            res = -l;
            break;

        default:
            res = 0;
            break;
    }

    return new LiteralInt(res);
}

// Evaluates a comparition expression by performing the correct comparition action based on the operator
LiteralBool *ASTExpression::intCompEval(int l, int r){
    bool res;

    switch (operand) {
        case EQL:
            res = l == r;
            break;

        case DIF:
            res = l != r;
            break;

        case GRT:
            res = l > r;
            break;

        case GRE:
            res = l >= r;
            break;

        case LES:
            res = l < r;
            break;

        case LEQ:
            res = l <= r;
            break;

        default:
            res = false;
    }

    return new LiteralBool(res);
}

// Evaluates a comparition expression by performing the correct comparition action based on the operator
LiteralBool *ASTExpression::strCompEval(std::string* l, std::string* r){
    bool res;

    switch (operand) {
        case EQL:
            res = *l == *r;
            break;

        case DIF:
            res = *l != *r;
            break;
        default:
            res = false;
    }

    return new LiteralBool(res);
}

// Evaluates a comparition expression by performing the correct comparition action based on the operator
LiteralBool *ASTExpression::boolCompEval(bool l, bool r){
    bool res;

    switch (operand) {
        case EQL:
            res = l == r;
            break;

        case DIF:
            res = l != r;
            break;

        default:
            res = false;
    }

    return new LiteralBool(res);
}

// Evaluates a logic expression by performing the correct logic action based on the operator
LiteralBool *ASTExpression::logicEval(bool l, bool r){
    bool res;

    switch (operand) {
        case AND:
            res = l && r;
            break;

        case OR:
            res = l || r;
            break;

        case NOT:
            res = !l;
            break;

        default:
            res = false;
            break;
    }

    return new LiteralBool(res);
}

void ASTExpression::printNode(){
    std::cout << "Node type: ASTExpression" << std::endl;
}
