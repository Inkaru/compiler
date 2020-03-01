parser: lex.yy.c binary.tab.o main.cc
	g++ -g -oint binary.tab.o lex.yy.c node.cpp environment.cpp main.cc -std=c++11
binary.tab.o: binary.tab.cc
	g++ -g -c binary.tab.cc -std=c++11
binary.tab.cc: binary.yy
	bison binary.yy -Wall
lex.yy.c: binary.ll binary.tab.cc
	flex binary.ll
clean: 
	rm -f binary.tab.* lex.yy.c* parser