LANG_DEFS = src/parsers/
FILE_NAME = cequal
EXEC_NAME = cequal
CLASSES = src/classes/*.cpp
ETC = src/*.cpp
CC = g++
CLIBS =

all: exec
	rm *.yy.*
	rm *.tab.*
	rm *.output

exec: yacc lex
	$(CC) lex.yy.c $(FILE_NAME).tab.c $(CLASSES) $(ETC) $(CLIBS) -o $(EXEC_NAME)

lex: $(LANG_DEFS)$(FILE_NAME).l
	flex $(LANG_DEFS)$(FILE_NAME).l

yacc: $(LANG_DEFS)$(FILE_NAME).y
	bison --verbose -d $(LANG_DEFS)$(FILE_NAME).y

clean: cleanlex cleanyacc cleanexec

cleanlex: *.yy.*
	rm *.yy.*

cleanyacc: *.tab.* *.output
	rm *.tab.*
	rm *.output

cleanexec:
	rm $(EXEC_NAME)
