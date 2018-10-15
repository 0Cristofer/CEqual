/* CEqual syntax definition file
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Date: 09/18/2018 */

%option noyywrap nodefault

%{
  #include <iostream>

  #include "cequal.tab.h"

  int yylineno = 1;

  void lexicalError(char *s);
%}

%%

"var"    {return T_RES_VAR;}
"bool"   {return T_RES_BOOL;}
"string" {return T_RES_STR;}
"int"    {return T_RES_INT;}

"if"     {return T_RES_IF;}
"else"   {return T_RES_ELSE;}

"for"    {return T_RES_FOR;}
"while"  {return T_RES_WHILE;}
"skip"   {return T_RES_SKIP;}
"stop"   {return T_RES_STOP;}

"def"    {return T_RES_DEF;}
"return" {return T_RES_RETURN;}

"read"   {return T_RES_READ;}
"write"  {return T_RES_WRITE;}

"("      {return T_SYM_OP;}
")"      {return T_SYM_CP;}
"["      {return T_SYM_OBK;}
"]"      {return T_SYM_CBK;}
"{"      {return T_SYM_OBC;}
"}"      {return T_SYM_CBC;}

"="      {return T_SYM_ATR;}
"+="     {return T_SYM_ATP;}
"-="     {return T_SYM_ATM;}
"*="     {return T_SYM_ATMUL;}
"/="     {return T_SYM_ATDIV;}
"%="     {return T_SYM_ATMOD;}

"+"      {return T_SYM_PLS;}
"-"      {return T_SYM_MIN;}
"*"      {return T_SYM_MUL;}
"/"      {return T_SYM_DIV;}
"%"      {return T_SYM_MOD;}
"=="     {return T_SYM_EQL;}
"!="     {return T_SYM_DIF;}
">"      {return T_SYM_GRT;}
">="     {return T_SYM_GRE;}
"<"      {return T_SYM_LES;}
"<="     {return T_SYM_LEQ;}
"||"     {return T_SYM_OR;}
"&&"     {return T_SYM_AND;}
"!"      {return T_SYM_NOT;}

";"      {return T_SYM_SMC;}
","      {return T_SYM_CMA;}
"?"      {return T_SYM_INTR;}
":"      {return T_SYM_COL;}

[0-9]+            {yylval = atoi(yytext);
                   return T_LIT_INT;}
\"(\\.|[^"\\])*\" {return T_LIT_STR;}
"true"            {return T_LIT_TRUE;}
"false"           {return T_LIT_FALSE;}

([a-zA-Z]|_)([a-zA-Z]|_|[0-9])* {return T_ID;}

"\n" {yylineno = yylineno + 1;}
[ \t]
"//".*

. {lexicalError(yytext);}

%%

void lexicalError(char *s){
  std::cerr << "Lexical error: unrecognized character " << s << " at line " << yylineno << std::endl;
}
