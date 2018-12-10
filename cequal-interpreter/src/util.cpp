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

void notDefinedError(int line, std::string symbol){
    std::cerr << "Semantic error: Use of undefined symbol \'" << symbol  << "\' at line " << line << std::endl;
}

void invalidAttribution(int line, std::string symbol, std::string type){
    std::cerr << "Semantic error: Trying to assign an int value to a not int variable at line " << line << ". " << symbol << " have type of " << type << std::endl;
}

void invalidAritmeticAttribution(int line, std::string symbol, std::string type){
    std::cerr << "Semantic error: Trying to perfom a incremental assignment to a not int variable at line " << line << ". " << symbol << " have type of " << type << std::endl;
}

void invalidUseOfProc(int line, std::string symbol){
    std::cerr << "Semantic error: Invalid use of procedure as function " << symbol << " at line " << line << ". Procedures don't return value" << std::endl;
}

void expectedBoolExp(int line, std::string type){
    std::cerr << "Semantic error: Expected boolean expression in condition at line " << line << ". Got \'" << type << "\'" << std::endl;
}

void wrongParameter(int line, std::string expected, std::string got){
    std::cerr << "Semantic error: Invalid parameter. Expected " << expected << " variable, got " << got << " at line " << line << std::endl;
}

void invalidArrayUse(int line){
    std::cerr << "Semantic error: Must use array parameter as variable at line " << line << std::endl;
}

void parametersExpected(int line){
    std::cerr << "Semantic error: Expected parameters and got none at line " << line << std::endl;
}

void parametersNotExpected(int line){
    std::cerr << "Semantic error: Unexpected parameters at line " << line << std::endl;
}

void invalidUseOf(int line, std::string symbol){
    std::cerr << "Semantic error: Command " << symbol << " outside loop at line " << line << std::endl;
}

void returnInProcedure(int line){
    std::cerr << "Semantic error: Return command in procedure at line " << line << std::endl;
}

void invalidReturnType(int line){
    std::cerr << "Semantic error: Invalid return type at line " << line << std::endl;
}

void voidReturnInFunction(int line){
    std::cerr << "Semantic error: Void return in function at line " << line << std::endl;
}

void missingReturnInFunction(int line){
    std::cerr << "Semantic error: Missing return in funcion in line " << line << std::endl;
}

void variableTypeWrong(int line, std::string symbol){
    std::cerr << "Semantic error: Variable \'"<< symbol << "\' initialized with wrong type at line " <<line << std::endl;
}

void invalidTypeInExpression(int line){
    std::cerr << "Semantic error: Invalid type for arithmetic expression in line " << line << std::endl;
}

void invalidCompType(int line){
    std::cerr << "Semantic error: Invalid comparition in line " << line << std::endl;
}

void invalidIntComparition(int line){
    std::cerr << "Semantic error: This type of comparition at line " << line << " must be done with int type" << std::endl;
}

void invalidBoolComparition(int line){
    std::cerr << "Semantic error: This type of comparition at line " << line << " must be done with bool type" << std::endl;
}