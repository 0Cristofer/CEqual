/* Util informations and routines
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 18/10/2018
   Edited: 07/11/2018 */

#ifndef UTIL_HPP
#define UTIL_HPP

#include <cstdio>
#include <iostream>

#include "../classes/value/include/Value.hpp"
#include "../classes/value/include/Literal.hpp"
#include "../classes/symbol/include/Scope.hpp"

//#define STRARGS ("a:b:c:d:t:h")

extern int yylineno;
extern FILE *yyin;
extern Scope* actual_scope;

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
void notInitializedError(int line, std::string symbol);

#endif /* UTIL_HPP */
