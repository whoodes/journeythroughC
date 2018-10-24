/*********************************************************
//
//  NAME:        Wyatt Hoodes
//
//  HOMEWORK:    3B
//
//  CLASS:       212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        Sept 19, 2018
//
//  FILE:        dataFxns.h
//
//  DESCRIPTION: Header file for the database functions.
//
**********************************************************/

#include "record.h"

int addRecord (struct record **, int, char [],char []);
int printRecord (struct record *, int);
void printAllRecords(struct record *);
int deleteRecord(struct record **, int);
void getaddress (char [], int);
int readfile (struct record **, char []);
int writefile (struct record *, char []);

