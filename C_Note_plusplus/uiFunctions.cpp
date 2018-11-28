/********************************************************
//
//  NAME:        Wyatt Hoodes
//
//  HOMEWORK:    Project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        Nov 18, 2018
//
//  FILE:        uiFunctions.cpp
//
//  DESCRIPTION: The ui functions to be utilized in the
//               main function of the banking program.
//
********************************************************/

#include "llist.h"
#include <cstdlib>
#include <cstring>

/**************************************************************************
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
**************************************************************************/

void getAddress(char input[], int length)
{
    char temp[500] = "";
    char CR[2] = "\n";
    char *pHash;

    #ifdef DEBUG
        cout << "\n***Debugmode***\n";
        cout << "--------------------------------------------------------\n";
        cout << "getAddress call: Character array param: " << input << "\ninteger length param: " << length;
        cout << "\n--------------------------------------------------------\n\n";
    #endif

    cout << "Please enter the street, city, state and zipcode. \nEnter a '#' on a newline to finish.\n\n";
    cout << "Address: ";

    while (temp[0] != '#')
    {
        cin.getline(temp, length);
        strcat(input, temp);
        strcat(input, CR);
    }

    /*  End string at newline preceding '#' symbol  */

    pHash = strrchr(input, '#');
    *(pHash - 1) = '\0';
}

/***********************************************************************
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
    #ifdef DEBUG
        cout << "\n***Debugmode***\n";
        cout << "--------------------------------------------------------\n";
        cout << "getName call: Character array param: " << input << "\ninteger length param: " << length;
        cout << "\n--------------------------------------------------------\n\n";
    #endif

    cout << "Please enter the name for the account: ";

    cin.getline(input, length);

}

/***********************************************************************
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
***********************************************************************/

long getAccount(char input[], int length)
{
    long account;

    #ifdef DEBUG
        cout << "\n***Debugmode***\n";
        cout << "--------------------------------------------------------\n";
        cout << "getAccount call: character array param: " << input << "\nlong length param: %d" << length;
        cout << "\n--------------------------------------------------------\n\n";
    #endif

    cout << "Please enter the account number: ";
    cin.getline(input, length);

    account = atoi(input);
    return account;
}

/***************************************************
//
//  Function name: printOptions
//
//  DESCRIPTION:   A function to print the options
//
//  Parameters:    none
//
//  Return values: void
//
***************************************************/

void printOptions()
{
    #ifdef DEBUG
        cout << "\n\n***Debugmode***\n";
        cout << "--------------------------------------------------------\n";
        cout << "printOptions call";
        cout << "\n--------------------------------------------------------\n";
    #endif

    cout << "\n1. Add a record to the database.\n";
    cout << "2. Print a single record from the database.\n";
    cout << "3. Print all records in the database.\n";
    cout << "4. Delete a record from the database.\n";
    cout << "5. Reverse records list ordering.\n";
    cout << "6. Display options.\n";
    cout << "0. Exit\n";
    cout << "\nChoice: ";
}

/**************************************************************************
//
//  Function name: funcReport
//
//  DESCRIPTION:   Displays the appropriate output based off
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
    #ifdef DEBUG
        cout << "\n***Debugmode***\n";
        cout << "--------------------------------------------------------\n";
        cout << "funcReport call: integer stat param: " << stat << "\ncharacter choice param: " << choice;
        cout << "\n--------------------------------------------------------\n";
    #endif

    if (stat == 0)
    {
        if (choice == '1')
        {
            cout << "\nThe record was successfully added!\n";
        }
        else if (choice == '4')
        {
            cout << "\nThe record was successfully deleted!\n";
        }

    }
    else
    {
        if (choice == '2' || choice == '4')
        {
            cout << "\nNo such record was found!\n";
        }
    }
}

/********************************************************************************
//
//  Function name:  menu
//
//  DESCRIPTION:    The function that handles the main ui
//                  for the banking program.
//
//  Parameters:     llist& (linkedList) : the linked list object for use
//                                        as the data structure for the program.
//
//  Return value:   void
//
********************************************************************************/

void menu(llist &linkedList)
{
    char optionInput[100] = "";
    char strAddress[500] = "";
    char strAccount[500] = "";
    char strName[500] = "";
    int optionLen;
    int inputSize;
    int functionStatus;
    long accountNum;

    inputSize = 500;
    optionInput[0] = '9';

    #ifdef DEBUG
        cout << "\n***Entering Debugmode***\n";
    #endif

    cout << "\n\nWelcome to Banking Made Mo Bettah' v1.1!  Here, there are\n";
    cout << "a number of great features to choose from.\n";
    cout << "Please make a choice corresponding to a number from the selection below...\n\n";

    while (optionInput[0] != '0')
    {
        printOptions();
        cin.getline(optionInput, 100);
        optionLen = strlen(optionInput);

        while (optionInput[0] < '0' || optionInput[0] > '6' || optionLen > 1)
        {
            cout << "Please enter a number corresponding to the list...\n";
            cout << "Choice: ";
            cin.getline(optionInput, 100);
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
                cout << "\nAn account number is required.\n";
            }
            else
            {
                getName(strName, inputSize);
                getAddress(strAddress, inputSize);

                if (strlen(strName) <= 25 && strlen(strName) > 2 &&
                    strlen(strAddress) <= 80 && strlen(strAddress) > 5)
                {
                    functionStatus = linkedList.addRecord(accountNum, strName, strAddress);
                    funcReport(functionStatus, optionInput[0]);
                }
                else
                {
                    cout << "\nAn error occurred when attempting to add the previous record\n";
                    cout << "\nPlease be sure that...\n";
                    cout << "\nThe length of the name is greater than 2 characters and does\n";
                    cout << "not exceed 25 characters.  The length of the address is greater";
                    cout << "\nthan five characters and does not exceed 80 characters. \nPlease try again.\n";
                }

                strcpy(strAddress, "");
            }
        }

        /**********************
         * 2 = print a record *
         **********************/

        else if (optionInput[0] == '2')
        {
            accountNum = getAccount(strAccount, inputSize);

            if (accountNum == 0L)
            {
                cout << "\nAn account number is required.\n";
            }
            else
            {
                functionStatus = linkedList.printRecord(accountNum);
                funcReport(functionStatus, optionInput[0]);
            }
        }

        /*************************
         * 3 = print all records *
         *************************/

        else if (optionInput[0] == '3')
        {
            cout << linkedList;
        }

        /***********************
         * 4 = delete a record *
         ***********************/

        else if (optionInput[0] == '4')
        {
            accountNum = getAccount(strAccount, inputSize);

            if (accountNum == 0L)
            {
                cout << "\nAn account number is required.\n";
            }
            else
            {
                functionStatus = linkedList.deleteRecord(accountNum);
                funcReport(functionStatus, optionInput[0]);
            }
        }

        /*********************
         * 5 = reverse list *
         *********************/

        else if (optionInput[0] == '5')
        {
            linkedList.reverse();
        }

        /*********************
         * 6 = print options *
         *********************/

        else if (optionInput[0] == '6')
        {
            printOptions();
        }
    }
}
