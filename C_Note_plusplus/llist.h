/*****************************************************
//
//  Name:        Wyatt Hoodes
//
//  Homework:    Project 2
//
//  Class:       ICS 212
//
//  Instructor:  Ravi Narayan
//
//  Date:        Nov 14, 2018
//
//  File:        llist.h
//
//  Description: The header file for the llist class
//
*****************************************************/

#ifndef LLIST_H
#define LLIST_H

#include <iostream>
#include "record.h"
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class llist
{
  private:
    record *start;
    char filename[16];
    int readfile();
    void writefile();
    record * reverse(record * );
    void cleanup();
    void copy(const llist&);

  public:
    llist();
    llist(char[]);
    llist(const llist&, string = "recordcopy.txt");
    ~llist();
    int addRecord (int, char [25],char [80]);
    int printRecord (int);
    llist& operator=(const llist&);
    friend ostream& operator<<(ostream&, llist&);
    int deleteRecord(int);
    void reverse();
};

#endif
