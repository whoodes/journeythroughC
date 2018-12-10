# Makefile for Homework9
# Created at: Nov 25, 2018
# Created by: Wyatt Hoodes

Homework9 : Homework9.java Homework9.c
	javac Homework9.java
	javah Homework9
	gcc -ansi -pedantic-errors -Wall -shared -o libHomework9.so Homework9.c -fPIC -I/usr/java/jdk1.8.0_131/include -I/usr/java/jdk1.8.0_131/include/linux

