/* CEqual syntax definition file
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Date: 09/18/2018 */

%{
  #include <stdio.h>

  void lexicalError(char *s);
  int yyval;
  int lineno = 1;
%}

%%
"var" {printf("res_var");}
"bool" {printf("type_bool");}
"string" {printf("type_string");}
"int" {printf("type_int");}

"true" {printf("lit_true");}
"false" {printf("lit_false");}

"if" {printf("res_if");}
"else" {printf("res_else");}

"for" {printf("res_for");}
"while" {printf("res_while");}
"skip" {printf("res_skip");}
"stop" {printf("res_stop");}

"def" {printf("res_def");}
"return" {printf("res_return");}

"read" {printf("res_read");}
"write" {printf("res_write");}

"+"|"-"|"=="|">"|">="|"<"|"<=" {printf("relop: %s ", yytext);}
"="|"("|")"|"["|"]"|"{"|"}"|","|":"|"?"|"&&" {printf(" symb: %s ", yytext);}
";" {printf(" EOC");}

([a-zA-Z]|_)([a-zA-Z]|_|[0-9])* {printf("id: %s ", yytext);}
[0-9]+ {yyval = atoi(yytext); printf("lit_val: '%d' ", yyval);}
\"(\\.|[^"\\])*\" {printf("lit_str: %s ", yytext);}

"\n" {printf("%s", yytext); lineno = lineno + 1;}
[ \t] {printf("%s", yytext);}
"//".* {printf("Comment: %s", yytext);}

. {lexicalError(yytext);}
%%

int main(int argc, char** argv){
  yylex();
  return 0;
}

void lexicalError(char *s){
  fprintf(stderr, "Lexical Error: unrecognized character %s at line %d\n", s, lineno);
}
