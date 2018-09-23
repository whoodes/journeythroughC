#
#  NAME:        Wyatt Hoodes
# 
#  HOMEWORK:    3b
#
#  CLASS:       ICS 212
#
#  INSTRUCTOR:  Ravi Narayan
#
#  DATE:        Sept 19, 2018
#
#  FILE:        Makefile
#
#  DESCRIPTION: A Makefile for homework3b.
#

userInterface : userInterface.o dataFxns.o
	gcc -o userInterface userInterface.o dataFxns.o

userInterface.o : userInterface.c dataFxns.h 
	gcc -ansi -pedantic-errors -Wall -c userInterface.c

dataFxns.o : dataFxns.c record.h
	gcc -ansi -pedantic-errors -Wall -c dataFxns.c

