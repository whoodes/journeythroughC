/***********************************
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
// FILE:         dataFxns.c
//
// DESCRIPTION:  A file containing the functions
//     for use in the banking database.
//     Included: addRecord
//               printRecord
//               printAllRecords
//               deleteRecord
//
************************************/

#include "record.h"
#include <stdio.h>
#include <string.h>

extern int debugmode;


/**************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   A function to add a record
//                 to the database.
//
//  Parameters:    start (struct record **) : N/A
//                 account (int) : contains the account number
//                 name (char *) : contains the name for the record
//                 address (char *) : contains the address for the record
//
//  Return values  1 : success 
//      Note: this function has not been implemented.
//
****************************************/

int addRecord (struct record **start, int account, char *name, char *address)
{
    if (debugmode == 1)
    {
        printf("\n***Debugmode***\n");
        printf("--------------------\n");
        printf("addRecord call. account: %d, name: %s, address: %s", account, name, address);
        printf("\n--------------------\n");
        printf("***Debugmode***\n\n");
    }

    return 1;
}

/***************************************
//
//  Function name: printRecord
//
//  DESCRIPTION:   A function to print a record.
//
//  Parameters:    start (struct record *) : N/A
//                 account (int) : contains the account number.
//
//  Return Values  1 : success
//      Note: This function has not been implemented.
//
****************************************/

int printRecord (struct record *start, int account)
{
    if (debugmode == 1)
    {
        printf("\n***Debugmode***\n");
        printf("--------------------\n");
        printf("printRecord call. account: %d", account);
        printf("\n----------------------\n");
        printf("\n***Debugmode***\n\n");
    }   
    
    return 1;
}

/***************************************
//
//  Function Name: printAllRecords
//
//  DESCRIPTION:   Print all the records in the
//      database.
//
//  Parameters:    start (struct record *) : N/A
//  
//  Return values: 1 : success
//      Note: This function has not been implemented.
//
****************************************/

void printAllRecords(struct record *start)
{
    if (debugmode == 1)
    {
        printf("\n***Debugmode***\n");
        printf("--------------------\n");
        printf("printAllRecords call.");
        printf("\n--------------------");
        printf("\n***Debugmode***\n\n");
    }
}

/************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   Delete a record from the database.
//
//  Parameters:    start (struct record *) : N/A
//                 account (int) : contains the account number
//
//  Return values: 1 : success
//      Note: This function has not been implemented.
//
*************************************/

int deleteRecord(struct record **start, int account)
{
    if (debugmode == 1)
    {
        printf("\n***Debugmode***\n");
        printf("--------------------\n");
        printf("deleteRecord call. account: %d", account);
        printf("\n--------------------\n");
        printf("\n***Debugmode***\n");
    }

    return 1;
}
