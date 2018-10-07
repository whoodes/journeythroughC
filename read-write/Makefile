driver : iofunctions.o driver.o
	gcc -o driver iofunctions.o driver.o

driver.o : driver.c iofunctions.h
	gcc -ansi -pedantic-errors -Wall -c driver.c

iofunctions.o : iofunctions.c record.h
	gcc -ansi -pedantic-errors -Wall -c iofunctions.c
