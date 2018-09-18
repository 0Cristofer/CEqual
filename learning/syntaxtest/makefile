FILE_NAME = syntax
EXEC_NAME = syntax
CC = gcc
CLIBS = -lfl
CFLAGS =

all: yacc lex
	$(CC) $(FILE_NAME).tab.c lex.yy.c $(CLIBS) -o $(EXEC_NAME)

lexc: lex
	$(CC) *.yy.c $(CLIBS) -o $(EXEC_NAME)

lex: $(FILE_NAME).l
	flex $(FILE_NAME).l

yacc: $(FILE_NAME).y
	bison -d $(FILE_NAME).y

clean: cleanflex cleanyacc cleanexec

cleanlex: *.yy.c
	rm *.yy.c

cleanyacc: *.tab.*
	rm *.tab.*

cleanexec:
	rm $(EXEC_NAME)
