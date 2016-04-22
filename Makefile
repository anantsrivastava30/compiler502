all:flash
flash.tab.c flash.tab.h: flash.y
	bison -dv flash.y
lex.yy.c: flash.lex flash.tab.h
	flex flash.lex
flash: flash.tab.c lex.yy.c
	gcc -c flash.tab.c lex.yy.c
all: lex.yy.c flash.tab.c CG.h ST.h
	gcc -o flash flash.tab.o lex.yy.o -lm
	
clean: 
	rm flash.tab.c lex.yy.c flash.tab.h lex.yy.o flash.output flash.tab.o
