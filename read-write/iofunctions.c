/*****************************************************************************
//
//  NAME:         Wyatt Hoodes
//
//  HOMEWORK:     5
//
//  CLASS:        ICS 212
//
//  INSTRUCTOR:   Ravi Narayan
//
//  DATE:         Oct 3, 2018
//
//  FILE:         iofunctions.c
//
//  DESCRIPTION:  A file containing the readfile and writefile function for
//      reading and writing to files.  Also included is a fileExists function
//      for checking whether a file exists.
//      Included: fileExists
//                readfile
//                writefile
//      
*******************************************************************************/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "record.h"

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
  
    if ( (file = fopen(filename, "r")) && (fgetc(file) != EOF) )
    {
        fclose(file);
        status = 1;
    }
    
    return status;
}

/*******************************************************************************************
//
//  Function name:  readfile
//
//  DESCRIPTION:    A function to read bank records from
//                  .txt file to a struct record account array.
//                  Note: Each record in the text file must be separated by newline.
//
//  Parameters:     accarray (struct record []) : contains the address of the account array
//                  pnumcust (int *) : contains the address for the numcustomers int 
//                  filename (char []) : contains the filename to read from
//
//  Return value:   0 : success
//                  1 : failed to read
//
*********************************************************************************************/

int readfile(struct record accarray[], int* pnumcust, char filename[])
{
    FILE *filePointer;
    char *pCR;
    int recordCount;
    int status;
    int checker;

    char address[80] = "";
    char name[25] = ""; 
    char wasteBin[100] = "";
      
    recordCount = 0;
    status = 1;

    if (fileExists(filename) == 1)
    { 
        status = 0;
        filePointer = fopen(filename, "r");

        while (checker != EOF)
        {
            fscanf(filePointer, "%d", &accarray[recordCount].accountno);
            fgets(wasteBin, 100, filePointer);
 
            fgets(name, 25, filePointer);
            strcpy(accarray[recordCount].name, name);                                  
            pCR = strrchr(accarray[recordCount].name, '\n');
            *pCR = '\0';          
      
            fgets(address, 80, filePointer);
            strcpy(accarray[recordCount].address, address);             
            pCR = strrchr(accarray[recordCount].address, '\n');
            *pCR = '\0';          

            recordCount++;
            checker = fgetc(filePointer);
        }

        fclose(filePointer);            
    }
    
    *pnumcust = recordCount;
    return status;   
}

/**************************************************************************************
//
//  Function name:  writefile
//
//  DESCRIPTION:    A function to write data from a struct record to a .txt file.
//
//  Parameters:     accarray (struct record []) : contains the array of struct records
//                  numcust (int) : contains the number of customers
//                  filename (char []) : contains the filename to be written to
//
//  Return values:  0 : Success
//                  1 : Failed to write
//
***************************************************************************************/

int writefile(struct record accarray[], int numcust, char filename[])
{
    FILE *filePointer;
    int status;
    int i;

    filePointer = fopen(filename, "w");
    
    if (filePointer == NULL) 
    {
        status = 1;
    }
    else
    {
        status = 0;
        for (i = 0; i < numcust; i++)
        {
            fprintf(filePointer, "%d", accarray[i].accountno);
            fprintf(filePointer, "%c", '\n');

            fprintf(filePointer, "%s", accarray[i].name);
            fprintf(filePointer, "%c", '\n');

            fprintf(filePointer, "%s", accarray[i].address);
            fprintf(filePointer, "%c", '\n');

            fprintf(filePointer, "%c", '\n');
        }
    
        fclose(filePointer);
    }
    
    return status;
}

