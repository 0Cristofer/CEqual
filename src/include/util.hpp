/* Util informations and routines
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 18/10/2018
   Edited: 18/10/2018 */

#ifndef UTIL_H
#define UTIL_H

#include <cstdio>
#include <iostream>

#include "../classes/include/Value.hpp"
#include "../classes/include/Literal.hpp"

//#define STRARGS ("a:b:c:d:t:h")

extern int yylineno;
extern FILE *yyin;

// Lexical parser function
extern int yylex();
// Syntax parser function
extern int yyparse();
// Syntax parser error function
void yyerror(std::string s);
// Checks if a value is of given type
bool typeCheck(Value* v, LiteralType t);
// Prints to standart error output a semantic error
void semanticError();
// Prints to standart error output a type error
void typeError();

#endif /* UTIL_H */
