main:
	bison -d calculator.y
	flex calculator.l
	gcc -o calculator calculator.tab.c lex.yy.c -lfl