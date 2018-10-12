FILE_NAME = cequal
EXEC_NAME = cequal
CC = g++
CLIBS =

all: yacc lex
	$(CC) lex.yy.c $(FILE_NAME).tab.c $(CLIBS) -o $(EXEC_NAME)

lex: $(FILE_NAME).l
	flex $(FILE_NAME).l

yacc: $(FILE_NAME).y
	bison --verbose -d $(FILE_NAME).y

clean: cleanlex cleanyacc cleanexec

cleanlex: *.yy.*
	rm *.yy.*

cleanyacc: *.tab.* *.output
	rm *.tab.*
	rm *.output

cleanexec:
	rm $(EXEC_NAME)
