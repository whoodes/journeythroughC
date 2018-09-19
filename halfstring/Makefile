#
# Name:         Wyatt Hoodes
#
# Class:        ICS 212
#
# Instructor:   Ravi Narayan
#
# Description:  Makefile for homework2b Exercise 1
#

driver : driver.o halfstring.o
	gcc -o driver driver.o halfstring.o

driver.o : driver.c halfstring.h
	gcc -ansi -pedantic-errors -Wall -c driver.c 

halfstring.o : halfstring.c
	gcc -ansi -pedantic-errors -Wall -c halfstring.c
