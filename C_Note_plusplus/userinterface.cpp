/****************************************************
// NAME:         Wyatt Hoodes
//
// HOMEWORK:     3b
//
// CLASS:        ICS 212
//
// INSTRUCTOR:   Ravi Narayan
//
// DATE:         Sept 19, 2018
//
// FILE:         userInteface.c
//
// DESCRIPTION:  The file containing the main function
//               for Banking Made Mo Betteh'!
//
*****************************************************/

#include <cstring>
#include "llist.h"
#include "uiFunctions.h"

/***********************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   The main function to run the banking program.
//
//  Parameters:    argc (int) : Number of command line args
//                 argv (char **) : The array of args
//
//  Return Values : 0 : success
//
************************************************************************/

int main(int argc, char **argv)
{
    llist linkedList;
    menu(linkedList);
    return 0;
}
