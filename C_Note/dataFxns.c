/**************************************************
// NAME:         Wyatt Hoodes
//
// HOMEWORK:     Project 1
//
// CLASS:        ICS 212
//
// INSTRUCTOR:   Ravi Narayan
//
// DATE:         Oct 17, 2018
//
// FILE:         dataFxns.c
//
// DESCRIPTION:  A file containing the functions
//     for use in the banking database.
//     Included: addRecord
//               printRecord
//               printAllRecords
//               deleteRecord
//               fileExists
//               readfile
//               writefile
//
**************************************************/

#include "record.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern int debugmode;

int fileExists(const char *);
int addRecord(struct record **, int, char [], char []);
int printRecord (struct record *, int);
void printAllRecords(struct record *);
int deleteRecord(struct record **, int);
int readfile(struct record **, char []);
int writefile(struct record *, char []);

/***************************************************************
//
//  Function name:  fileExists
// 
//  DESCRIPTION:    A function to test whether a file exists
//                  for use in the readfile function.
// 
//  Parameters:     filename (char *) : contains the filename
// 
//  Return values:  0 : does not exist
//                  1 : does exist
//
****************************************************************/

int fileExists(const char *filename)
{
    FILE *file;
 
    int status = 0;

    if (debugmode == 1)
    {
        printf("\n***Debugmode***\n");
        printf("--------------------------------------------------------\n");
        printf("fileExists call. filename: %s", filename);
        printf("\n--------------------------------------------------------\n");
    }
 
    if ( (file = fopen(filename, "r")) && (fgetc(file) != EOF) )
    {
        fclose(file);
        status = 1;
    }
    
    return status;
}

/*********************************************
//
//  Function name: readFile
//
//  DESCRIPTION:  A function to read data from a .txt file
//                 to the record linkedlist data structure.
//
//  Parameters:    start (struct record **) : A pointer to the start pointer of the linkedlist
//                 filename (char []) : The file name to read from.
//
//  Return values: 0 : success
//                -1 : error
//
***********************************************/

int readfile(struct record **start, char filename[])
{
    FILE *filePointer;
    int status;
    int checker;
    int account;

    char accountArr[100] = "";
    char temp[80] = "";
    char address[80] = "";
    char name[25] = ""; 
     
    status = -1;

    if (debugmode == 1)
    {
        printf("\n***Debugmode***\n");
        printf("--------------------------------------------------------\n");
        printf("readFile call. filename: %s", filename);
        printf("\n--------------------------------------------------------\n");
    }

    if (fileExists(filename) == 1)
    { 
        status = 0;
        filePointer = fopen(filename, "r");

        while (checker != EOF)
        {  
            fgets(accountArr, 100, filePointer);
            account = atoi(accountArr); 
 
            fgets(name, 25, filePointer);
            name[strlen(name) - 1] = '\0';

            while (temp[0] != '#')
            {
                fgets(temp, 80, filePointer);
                strcat(address, temp);
            }
 
            address[strlen(address) - 3] = '\0';
            status = addRecord(start, account, name, address);

            strcpy(temp, "");
            strcpy(address, "");
            strcpy(name, "");

            checker = fgetc(filePointer);
        }

        fclose(filePointer);            
    }
    
    return status;
}

/***********************************************
//
//  Function name: writeFile
//
//  DESCRIPTION:   A function to write linkedlist records to
//                 a .txt file.   
//
//  Parameters:    start (struct record *) : The start of the linked list. 
//                 filename (char []) : The filename to write to.
//             
//  Return values: 0 : success
//                -1 : error
//
************************************************/

int writefile(struct record *start, char filename[])
{
    FILE *filePointer;
    struct record *temp;
    int status;
    int count;
 
    if (debugmode == 1)
    {
        printf("\n***Debugmode***\n");
        printf("--------------------------------------------------------\n");
        printf("writeFile call. filename: %s", filename);
        printf("\n--------------------------------------------------------\n");
    }
    
    count = 0;
    temp = start;
    filePointer = fopen(filename, "w");
    
    if (filePointer == NULL) 
    {
        status = -1;
    }
    else
    {
        status = 0;
        while (temp != NULL)
        {

            /******************************************************************
             * Some hackery to deal with the file checker in the readfile fxn *
             ******************************************************************/
 
            if (count > 0)
            {
                fprintf(filePointer, "%d", 0);
            }

            fprintf(filePointer, "%d", temp->accountno);

            fprintf(filePointer, "%c", '\n');

            fprintf(filePointer, "%s", temp->name);
            fprintf(filePointer, "%c", '\n');

            fprintf(filePointer, "%s", temp->address);
            fprintf(filePointer, "%c", '\n');
            fprintf(filePointer, "%c", '#'); 
            fprintf(filePointer, "%c", '\n');
 
            count++;
            temp = temp->next;
        }
    
        fclose(filePointer);
    }
    
    return status;
}

/************************************************************************
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
//  Return values  0 : success 
//                -1 : error
// 
************************************************************************/

int addRecord (struct record **start, int account, char name[], char address[])
{
  
    struct record *temp;
    struct record *current;
    struct record *successor;
    int status;

    status = -1;
    temp = (struct record*)malloc(sizeof(struct record));

    temp->accountno = account;
    strcpy(temp->name, name);
    strcpy(temp->address, address);

    if (debugmode == 1)
    {
        printf("\n***Debugmode***\n");
        printf("--------------------------------------------------------\n");
        printf("addRecord call. account: %d, name: %s, \naddress: %s", account, name, address);
        printf("\n--------------------------------------------------------\n");
    }

    if (*start == NULL || (*start)->accountno > account)
    {
        temp->next = *start;
        *start = temp;
        status = 0;
    }
    else
    {
        current = *start;
        successor = current->next;
       
        while (successor != NULL && successor->accountno < account)
        {
            current = successor;
            successor = successor->next;    
        }

        current->next = temp;
        temp->next = successor;
        status = 0;
    }

    return status;
}

/**************************************************************
//
//  Function name: printRecord
//
//  DESCRIPTION:   A function to print a record.
//
//  Parameters:    start (struct record *) : N/A
//                 account (int) : contains the account number.
//
//  Return Values  0 : success
//                -1 : error
//
**************************************************************/

int printRecord (struct record *start, int account)
{
    struct record *temp;
    int status;

    temp = start;
    status = -1;

    if (debugmode == 1)
    {
        printf("\n***Debugmode***\n");
        printf("--------------------------------------------------------\n");
        printf("printRecord call. account: %d", account);
        printf("\n--------------------------------------------------------\n");

    }

    while (temp != NULL && temp->accountno == account)
    {
        if (status == -1)
        {
            status = 0;
        }

        printf("Account: %d", temp->accountno);
        printf("\nName: %s", temp->name);
        printf("\nAddress: %s", temp->address);
        printf("\n\n");
        temp = temp->next;        
    }

    if (status == -1)
    {
        while (temp != NULL)
        {
            while (temp != NULL && temp->accountno != account)
            {
                temp = temp->next;
            }

            if (temp != NULL)
            {
                if (status == -1)
                {
                    status = 0;
                }

                printf("Account: %d", temp->accountno);
                printf("\nName: %s", temp->name);
                printf("\nAddress: %s", temp->address);
                printf("\n\n");
                temp = temp->next;
            }            
        }       
    }

    return status;
}

/****************************************************
//
//  Function Name: printAllRecords
//
//  DESCRIPTION:   Print all the records in the
//                 database.
//
//  Parameters:    start (struct record *) : N/A
//  
//  Return values: void
// 
*****************************************************/

void printAllRecords(struct record *start)
{
    struct record *temp = start;

    if (debugmode == 1)
    {
        printf("\n***Debugmode***\n");
        printf("--------------------------------------------------------\n");
        printf("printAllRecords call.");
        printf("\n--------------------------------------------------------\n");
    }

    if (temp != NULL)
    {
        while (temp != NULL)
        {
            printf("\n");
            printf("Account: %d", temp->accountno);
            printf("\nName: %s", temp->name);
            printf("\nAddress: %s", temp->address);
            printf("\n");      
            temp = temp->next;
        }
    }
    else
    {
        printf("\nThere don't appear to be any records in the system.\n");
    }
}

/***************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   Delete a record from the database.
//
//  Parameters:    start (struct record *) : N/A
//                 account (int) : contains the account number
//
//  Return values: 0 : success
//                -1 : error
//
***************************************************************/

int deleteRecord(struct record **start, int account)
{
    struct record *temp;
    struct record *previous;
    int status;

    temp = *start;
    status = -1;

    if (debugmode == 1)
    {
        printf("\n***Debugmode***\n");
        printf("--------------------------------------------------------\n");
        printf("deleteRecord call. account: %d", account);
        printf("\n--------------------------------------------------------\n");
    }

    while (temp != NULL && temp->accountno == account)
    {
        if (status == -1)
        {
            status = 0;
        }

        *start = temp->next;
        free(temp);
        temp = *start;        
    }

    if (status == -1)
    {
        while (temp != NULL)
        {
            while (temp != NULL && temp->accountno != account)
            {
                previous = temp;
                temp = temp->next;
            }

            if (temp != NULL)
            {
                if (status == -1)
                {
                    status = 0;
                }

                previous->next = temp->next;
                free(temp);
                temp = previous->next;
            }            
        }       
    }

    return status;
}
