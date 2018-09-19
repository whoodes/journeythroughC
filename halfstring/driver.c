/********************************************
********************************
//
//  Name:          Wyatt Hoodes
//  
//  HOMEWORK:      2b
//
//  CLASS:         ICS 212
//
//  INSTRUCTOR:    Ravi Narayan
//
//  DATE:          Sept 11, 2018
//
//  FILE:          driver.c
//
//  DESCRIPTION:   A driver testing the halfstring
//      function with user input.
//
***********************************
*******************************************/\

#include "halfstring.h"
#include <stdio.h>

/*******************************************
******************************
//  
//  Function name: main
//
//  DESCRIPTION:   A main driver for testing the
//      halfstring function.  A welcome message is
//      printed prompting user input.  By calling
//      the halfstring function, the input string
//      and the half string are printed to screen.
//
//  Parameters:    none
//
//  Return values: 0 : success
//
*******************************
**********************************************/

int main(int argc, char **argv)
{ 
    char string[200] = "";
    char newString[200] = "";
    char *result = ""; 
    
    printf("\nHello, please enter a string: ");
    fgets(string, 200, stdin);

    result = halfstring(string, newString);
    
    printf("\nString / Halfstring: %s", result);
    printf("\n");

    return 0;
}
