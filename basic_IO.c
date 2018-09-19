/******************************************
***********************
//
//  NAME:        Wyatt Hoodes
// 
//  HOMEWORK:    1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        Aug 30, 2018
//
//  FILE:        homework1.c
//
//  DESCRIPTION:
//    This file contains four functions,
//    including main, for acquiring an
//    integer from user input and then 
//    displaying the factors back to the
//    user. 
//    Functions include:
//      -getInput
//      -isDivisible
//      -printResult
//      -main
//
************************
******************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int isDivisible(int, int);

/*****************************************
**************************
//
//  Function Name:  getInput
//
//  DESCRIPTION:    Validates that the user input
//                  is an integer by checking 
//                  the ASCII value of each element in
//                  the char array 
//                  
//  Parameters:     none
//
//  Return value:   num (int) : contains the user input
//                              as an integer
//
**************************
****************************************/

int getInput()
{
    char str[20] = "";
    int true = 1;
    int false = 0;
    int valid = false;
    int i;
    int num;
    int count = 0;
    
    while (valid == false)
    {
        /*******************************************
        //  The initial pass for input, assume true
        //  until proven false
        ********************************************/

        printf("Please enter an integer: ");
        fgets(str, 20, stdin);
        valid = true;
        count = strlen(str) - 1;

        /*****************************************
        //  Loop invariant: If some element, i,
        //  in the char array has an ASCII value
        //  less than 49 or greater than 57, then
        //  the array contains a non-integer
        ******************************************/

        for (i = 0; i < count; i++)
        {
            if(str[i] < '0' || str[i] > '9')
            {
                valid = false;
            }
        }

        if (str[0] == '0' || str[0] == '\n')
        {
            valid = false;
        }

        /**************************************
        //  Testing for specific error messages
        ***************************************/

        if (valid == false)
        {       
            if(str[0] <= '0')
            {
                printf("Error: Please enter a positive number.\n");
            }
            else
            {
                str[count] = '\0';
                printf("Error: |%s| is not a number, human.", str);
                printf("\n");
            }
        }
    }

    num = atoi(str);
    return num;
}

/*********************************************************
**********************************
//
//  Function name:  isDivisible
//  
//  DESCRIPTION:    A function to test whether or not a
//                  number is divisble by a given
//                  factor.
//
//  Paramters:      factor (int) : contains the factor 
//                                 representing the divisor
//                  num (int)    : contains the number 
//                                 representing the dividend
//                       
//  Return values:  0 : not divisible
//                  1 : is divisible
//
*********************************
********************************************************/

int isDivisible(int factor, int num)
{
    if (num % factor == 0)
    {
        return 1;
    }

    return 0;
}

/********************************************
*********************************
//
//  Function name:  printResult
//
//  DESCRIPTION:    Prints the welcome message and
//                  calls the getInput function.
//                  Prints the result by calling the
//                  isDivisible function.
//
//  Parameters:     None
//
//  Return Value:   void
//
*********************************
**********************************************/

void printResult()
{
    int i;
    int num;
    int factor;
    int index = 1;

    printf("\n");
    printf("Welcome my friend, this program will print all factors\n");
    printf("for any integer you wish, but it must be positve and non-zero.\n");
    printf("Note: I do not care about uniqueness!\n");
    printf("\n");

    num = getInput();

    printf("    index    factor\n");

    /****************************************
    //  Loop Invariant: Beginning with the
    //  number itself, check divisibilty,
    //  decrement i. This prints the factors
    //  in ascending order from the top, down.
    ******************************************/

    for (i = num; i > 0; i--)
    {
        if (isDivisible(i, num) == 1)
        {
            factor = num / i;
            printf("%9d", index);
            printf("%10d", factor);
            printf("\n");
            index++;
        }
    }
}


/******************************************
***************************
//
//  Function name:  main
//
//  Description:    The main function to execute
//                  the homework1 program
//
//  Parameters:     argc (int)     : Not entirely clear
//
//                  argv (pointer) : Not entirely clear
//
//  Return values:  0 : success
//
***************************
******************************************/

int main(int argc, char* argv[])
{
    printResult();
    return 0;
}

