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
//  FILE:        record.h
//
//  DESCRIPTION: struct record for bank database.
//
**********************************************************/

struct record
{
    int                accountno;
    char               name[25];
    char               address[80];
    struct record*     next;
};
