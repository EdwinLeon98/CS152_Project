ld: parser

parser: y.tab.c lex.yy.c 
		gcc -o parser y.tab.c lex.yy.c -lfl

lex.yy.c:862054277-862132870.lex
		flex 862054277-862132870.lex

y.tab.c:mini_l.y
		bison -v -d --file-prefix=y mini_l.y
