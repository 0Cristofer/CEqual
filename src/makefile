LANG_DEFS = langdefs/
FILE_NAME = cequal
EXEC_NAME = cequal
CLASSES = classes/AST.cpp classes/ASTLiteral.cpp classes/ASTExpression.cpp classes/Literal.cpp classes/LiteralInt.cpp
CC = g++
CLIBS =

all: exec
	rm *.yy.*
	rm *.tab.*
	rm *.output

exec: yacc lex
	$(CC) lex.yy.c $(FILE_NAME).tab.c $(CLASSES) $(CLIBS) -o $(EXEC_NAME)

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
