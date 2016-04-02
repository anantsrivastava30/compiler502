yacc -d grammer.y
lex scanner.l
cc lex.yy.c y.tab.c -o quack
