lex.yy.c: ansic.lex
	flex ansic.lex
y.tab.c: ansic.yacc
	bison -yd ansic.yacc
compilador: y.tab.c lex.yy.c	
	gcc -lfl y.tab.c lex.yy.c -o compilador
clean:
	rm -f lex.yy.c y.tab.c y.tab.h ansic.tab.cacc
