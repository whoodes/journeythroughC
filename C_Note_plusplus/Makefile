userinterface : userinterface.cpp llist.cpp llist.h record.h uiFunctions.h
	g++ -ansi -pedantic-errors -Wall -c userinterface.cpp
	g++ -ansi -pedantic-errors -Wall -c llist.cpp
	g++ -ansi -pedantic-errors -Wall -c uiFunctions.cpp
	g++ -o userinterface userinterface.o llist.o uiFunctions.o

clean : 
	rm *.o *.txt userinterface

dClean : 
	rm *.o *.txt userinterfaceDEBUG

debug : userinterface.cpp llist.cpp llist.h record.h uiFunctions.h
	g++ -D DEBUG -ansi -pedantic-errors -Wall -c userinterface.cpp
	g++ -D DEBUG -ansi -pedantic-errors -Wall -c llist.cpp
	g++ -D DEBUG -ansi -pedantic-errors -Wall -c uiFunctions.cpp
	g++ -D DEBUG -o userinterfaceDEBUG userinterface.o llist.o uiFunctions.o
