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
// DESCRIPTION:  A file containing the main function
//     and a few other input functions for use in 
//     the banking database.
//     Included: getAddress
//               getName 
//               getAccount
//               funcReport
//               printOptions 
//
****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataFxns.h"

int debugmode = 0;

/************************************************************************
//
//  Function name: getAddress
//
//  DESCRIPTION:   A function to get the address data for adding a record.
//
//  Parameters:    input (char []) : Char array to hold the address
//                 length (int) : length of the aforementioned char array.
//
//  Return values: void
//
************************************************************************/

void getAddress(char input[], int length)
{
    char temp[500] = "";
    char *pHash;

    if (debugmode == 1)
    {
        printf("\n***Debugmode***\n");
        printf("--------------------------------------------------------\n");
        printf("getAddress call: Character array param: %s, \ninteger length param: %d", input, length);
        printf("\n--------------------------------------------------------\n\n");
    }

    printf("Please enter the street, city, state and zipcode. \nFollowed by a # sign on a new line.\n");
    printf("Address: ");

    while (temp[0] != '#')
    {
        fgets(temp, length, stdin);
        strcat(input, temp);
    }
    
    /*  End string at newline preceding '#' symbol  */
   
    pHash = strrchr(input, '#');
    *(pHash - 1) = '\0'; 
}

/**********************************************************************
//
//  Function name: getName
//
//  DESCRIPTION:   A function to get the name for adding a record.
//
//  Parameters:    input (char []) : Char array to hold the name
//                 length (int) : the length of the aforementioned array
//
//  return value:  void
//
***********************************************************************/

void getName(char input[], int length)
{
    char *pCR;

    if (debugmode == 1)
    {
        printf("\n***Debugmode***\n");
        printf("--------------------------------------------------------\n");
        printf("getName call: Character array param: %s, \ninteger length param: %d", input, length);
        printf("\n--------------------------------------------------------\n\n");
    }

    printf("Please enter the name for the account: ");
    fgets(input, length, stdin);
    
    pCR = strrchr(input, '\n');
    *pCR = '\0';
}

/**********************************************************************
//
//  Function name: getAccount
//  
//  DESCRIPTION:   A function to get the account number for a new record.
//
//  Parameters:    input (char []) : char array to hold the account
//                 length (int) : the length of the aforementioned array
//
//  Return values: account (int) : The input as an integer.
//
************************************************************************/

long getAccount(char input[], int length)
{
    long account;
    char *pCR;

    if (debugmode == 1)
    {
        printf("\n***Debugmode***\n");
        printf("--------------------------------------------------------\n");
        printf("getAccount call: character array param: %s, \nlong length param: %d", input, length);
        printf("\n--------------------------------------------------------\n\n");
    }        
  
    printf("Please enter the account number: ");
    fgets(input, length, stdin);
    
    pCR = strrchr(input, '\n');
    *pCR = '\0';

    account = strtol(input, &pCR, 10);
    return account;
}
    
/*****************************************************
//
//  Function name: printOptions
//
//  DESCRIPTION:   A function to print the options
//
//  Parameters:    none
//
//  Return values: void
//
********************************************************/

void printOptions()
{
    if (debugmode == 1 )
    {
        printf("\n\n***Debugmode***\n");
        printf("--------------------------------------------------------\n");
        printf("printOptions call");
        printf("\n--------------------------------------------------------\n");

    }

    printf("\n1. Add a record to the database.\n");
    printf("2. Print a single record from the database.\n");
    printf("3. Print all records in the database.\n");
    printf("4. Delete a record from the database.\n");
    printf("5. Display options.\n");
    printf("0. Exit\n");
    printf("\nChoice: ");
}

/*************************************************************************
//
//  Function name: funcReport
//
//  DESCRIPTIONL   Displays the appropriate output based off 
//      return from called function.
//
//  Parameters:    stat (int) : Contains the status from the function call.
//                 choice (char) : Contains the current user input choice.
//
//  Return values: void
//
***************************************************************************/

void funcReport(int stat, char choice)
{
    if (debugmode == 1)
    { 
        printf("\n***Debugmode***\n");
        printf("--------------------------------------------------------\n");
        printf("funcReport call: integer stat param: %d, \ncharacter choice param: %c", stat, choice);
        printf("\n--------------------------------------------------------\n");

    }

    if (stat == 0)
    {
        if (choice == '1')
        {
            printf("\nThe record was successfully added!\n"); 
        }
        else if (choice == '4')
        {
            printf("\nThe record was successfully deleted!\n");
        }
      
    }
    else
    {
        if (choice == '2' || choice == '4')
        {
            printf("\nNo such record was found!\n");
        }
    }
}

/******************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   The main function to run the banking program.
//
//  Parameters:    argc (int) : Number of command line args
//                 argv (char **) : The address of the char pointer (?)
//
//  Return Values : 0 : success
//
*******************************************************************/

int main(int argc, char **argv)
{
    char optionInput[100] = "";
    char debugger[10] = "debug";
    char strAddress[500] = "";
    char strAccount[500] = "";
    char strName[500] = "";
    int validExecute;
    int optionLen;
    int inputSize;
    int functionStatus;
    long accountNum;

    struct record *start = NULL;
    inputSize = 500;
    validExecute = 1;
    optionInput[0] = '9'; 
    
    /************************************
     *  Begin validExecute test  block  *
     ************************************/

    if (argc > 2)
    {
        printf("\nuserInterface: In function main: error: exceeded maximum number of arguments\n");
        validExecute = 0;
    }
    else if (argc == 2 && strcmp(debugger, argv[1]) != 0)
    {
        printf("\nuserInterface: In function main: error: second command exists only as 'debug'\n");
        validExecute = 0;
    }
    else if (argc == 2)
    {
        printf("\n***Entering debugmode***\n");
        debugmode = 1;
    }
    
    /*********************************
     *  End validExecute test block  *
     *********************************/

    if (validExecute == 1)
    {
        functionStatus = readfile(&start, "records.txt");
       
        printf("\n\nWelcome to Banking Made Mo Bettah'.  Here, there are\n");
        printf("a number of great features to choose from.\n");
        printf("Please make a choice corresponding to the number from the selection below...\n\n");
       
        /***************************
         *  Begin Menu loop block  *
         ***************************/

        while (optionInput[0] != '0')
        {
            printOptions();
            fgets(optionInput, 100, stdin);
            optionLen = strlen(optionInput);

            while (optionInput[0] < '0' || optionInput[0] > '5' || optionLen > 2)
            {
                printf("Please enter a number corresponding to the list...\n");
                printf("Choice: ");
                fgets(optionInput, 100, stdin);
                optionLen = strlen(optionInput);
            }

            /********************
             * 1 = add a record *
             ********************/

            if (optionInput[0] == '1')
            {
                accountNum = getAccount(strAccount, inputSize);

                if (accountNum == 0L)
                {
                    printf("\nAn account number is required.\n");
                }
                else 
                {
                    getName(strName, inputSize);
                    getAddress(strAddress, inputSize);
                    
                    if (strlen(strName) <= 25 && strlen(strName) > 2 && 
                        strlen(strAddress) <= 80 && strlen(strAddress) > 5)
                    {
                        functionStatus = addRecord(&start, accountNum, strName, strAddress);
                        funcReport(functionStatus, optionInput[0]);
                    }
                    else
                    {
                        printf("\nAn error occurred when attempting to add the previous record\n");
                        printf("\nPlease be sure that...\n");
                        printf("\nThe length of the name is greater than 2 characters and does\n");
                        printf("not exceed 25 characters.  The length of the address is greater");
                        printf("\nthan five characters and does not exceed 80 characters. \nPlease try again.\n");
                    }  
                  
                    strcpy(strAddress, "");
                }
            }

            /**********************
             * 2 = print a record *
             **********************/
            
            else if (optionInput[0] == '2')
            {
                if (start != NULL)
                {
                    accountNum = getAccount(strAccount, inputSize);

                    if (accountNum == 0L)
                    {
                        printf("\nAn account number is required.\n");
                    }
                    else
                    {
                        functionStatus = printRecord(start, accountNum);
                        funcReport(functionStatus, optionInput[0]);
                    }
                }
                else
                {
                    printf("\nThere are no records! Go add some customers!\n");
                } 
            }

            /*************************
             * 3 = print all records *
             *************************/

            else if (optionInput[0] == '3')
            {
                printAllRecords(start);
            }

            /***********************
             * 4 = delete a record *
             ***********************/

            else if (optionInput[0] == '4')
            {
                if (start != NULL)
                {
                    accountNum = getAccount(strAccount, inputSize);
              
                    if (accountNum == 0L)
                    {
                        printf("\nAn account number is required.\n");
                    }
                    else
                    {
                        functionStatus = deleteRecord(&start, accountNum);
                        funcReport(functionStatus, optionInput[0]);
                    }
                }
                else
                {
                    printf("\nThere are no records! What happens when a bank goes bankrupt?\n");
                } 
            }

            /*********************
             * 5 = print options *
             *********************/

            else if (optionInput[0] == '5')
            {
                printOptions();
            }
        }
     
        /*************************
         *  End Menu loop block  *
         *************************/

        functionStatus = writefile(start, "records.txt");
        if (functionStatus == 0)
        {
            printf("\n\nRecords were successfully written to: records.txt\n\n");
        }
        else
        {
            printf("\n\nThere was an error when attempting to write records to: records.txt\n\n");
        }
    }

    return 0;
}

