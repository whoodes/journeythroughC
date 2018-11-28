/**************************************************
//
//  NAME:        Wyatt Hoodes
//
//  HOMEWORK:    Project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        Nov 14, 2018
//
//  FILE:        record.h
//
//  DESCRIPTION: Header file for the struct record
//               data type.
//
**************************************************/

#ifndef RECORD_H
#define RECORD_H

struct record
{
    int                accountno;
    char               name[25];
    char               address[80];
    struct record*     next;
};

#endif
