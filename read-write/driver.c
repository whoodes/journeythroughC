/****************************************************************
// 
//  NAME:           Wyatt Hoodes
//
//  HOMEWORK:       5
//
//  CLASS:          ICS 212
//
//  INSTRUCTOR:     Ravi Narayan
//
//  DATE:           Oct 03, 2018
//
//  FILE:           driver.c
//
//  DESCRIPTION:    The test driver for the IO functions located
//                  in the iofunctions.c file.
//
*****************************************************************/

#include "iofunctions.h"
#include <stdlib.h>
#include <stdio.h>

/**************************************************************
//
//  Function name:  main
//
//  DESCRIPTION:    The main function housing the test driver.
//
//  Parameters:     No paramters needed for this instance.
//
//  Return values:  0 : success
//
**************************************************************/

int main()
{
    struct record bankone[5];
    int numcustomers;
    int result;
    int i;

    char writeFilename[50] = "new-records.txt";
    char readFilename[50] = "./records.txt";

    /****************************************
    * Test block for the readfile function. *
    *****************************************/ 

    result = readfile(bankone, &numcustomers, readFilename); 
        
    if (result == 0)
    {
        printf("\nThe file was successfully read from %s", readFilename);
        printf("\nNumber of customers read from the file: %d", numcustomers);
        printf("\n");
        printf("The following are the current values now stored in the account array: \n");
        
        for (i = 0; i < numcustomers; i++)
        {
            printf("account no: %d", bankone[i].accountno);
            printf("\n");
            printf("name: %s", bankone[i].name);
            printf("\n");
            printf("address: %s", bankone[i].address);
            printf("\n\n");
        }
    }
    else
    {
        printf("There was an error when attempting to read from the file %s", readFilename);
        printf("\n");
    } 
    
    /*****************************************
    * Test block for the writefile function. *
    ******************************************/

    result = writefile(bankone, numcustomers, writeFilename); 
    
    if (result == 0)
    {
        printf("The file was successfully written as %s", writeFilename);
        printf("\n");
    }
    else
    {
        printf("There was an error when writing the file");
        printf("\n");
    }
 
    printf("\n");

    return 0;
}

