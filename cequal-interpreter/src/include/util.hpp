/* Util informations and routines
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 18/10/2018
   Edited: 07/11/2018 */

#ifndef UTIL_HPP_CEQUAL
#define UTIL_HPP_CEQUAL

#include <cstdio>
#include <iostream>

#include "../classes/value/include/Value.hpp"
#include "../classes/value/include/Literal.hpp"
#include "../classes/symbol/include/Scope.hpp"

//#define STRARGS ("a:b:c:d:t:h")

extern int yylineno;
extern FILE *yyin;
extern Scope* actual_scope;
extern AST* main_proc;
extern AST* first;
extern bool r_error;

// Lexical parser function
int yylex();
// Syntax parser function
int yyparse();
// Syntax parser error function
void yyerror(std::string s);
// Checks if a value is of given type
bool typeCheck(Value *v, LiteralType t, int line);
// Prints to standart error output a semantic error
void semanticError(int line);
// Prints to standart error output a type error
void typeError(int line);
// Prints to standart error output a array size mismatch error
void arraySizeMismatchError(int line);
// Prints to standart error output a not initizlized error
void notDefinedError(int line, std::string symbol);
// Prints to standart error output an invalid atribution
void invalidAttribution(int line, std::string symbol, std::string type1, std::string type2);
// wooho sathurday night fun
void invalidAritmeticAttribution(int line, std::string symbol, std::string type);
// So much fun
void invalidUseOfProc(int line, std::string symbol);
// Tão me ameaçando
void expectedBoolExp(int line, std::string type);
// não quero
void wrongParameter(int line, std::string expected, std::string got);
// Sunday shitshow
void invalidArrayUse(int line);
// Takamine
void parametersExpected(int line);
// Tá chegando o carvão
void parametersNotExpected(int line);
// O carvão não chegou
void invalidUseOf(int line, std::string symbol);
// O carvão chegou
void returnInProcedure(int line);
// Rosh feito, narga montado, virando o carvão
void invalidReturnType(int line);
// Arguile aceso
void voidReturnInFunction(int line);
// Minha vez no arguile
void missingReturnInFunction(int line);
// Passei a vez
void variableTypeWrong(int line, std::string symbol);
// Bruno foi dormir
void invalidTypeInExpression(int line);
// Eu to quase indo tambem
void invalidCompType(int line);
// Força ta acabando
void invalidIntComparition(int line);
// Esse nem deu graça
void invalidBoolComparition(int line);

void incorrectNumberArguments(int line, int parm, int args);
#endif /* UTIL_HPP_CEQUAL */
