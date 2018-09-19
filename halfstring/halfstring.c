/*******************************************
*******************************
//  NAME:         Wyatt Hoodes
//
//  HOMEWORK:     2b
//
//  CLASS:        ICS 212
//
//  INSTRUCTOR:   Ravi Narayan
//
//  DATE:         Sept 11, 2018
//
//  FILE:         halfstring.c
//
//  DESCRIPTION:  This file contains the 
//      halfstring function.
//
***************************
********************************************/

/************************************************************
***********************************
//
//  Function name: halfstring
//
//  DESCRIPTION:   Takes two char arrays an 
//                 original, and one to be modfied.
//                 The result is one string with the
//                 original and modfied concatenated.
//
//  Parameters:    original (const char *) : the original string
//                 modified (char *)       : the modified string
//
//  Return values: char * : The resulting string containing the
//                            original and modified strings.
//      
***********************************
****************************************************************/

char* halfstring (const char *original, char *modified)
{
    int strlen = 0;
    int j = 0;
    int k = 0;
    
    while (original[strlen] != '\0')
    {
        modified[strlen] = original[strlen];
        strlen++;
    }

    j = strlen;
    modified[strlen - 1] = '\t';

    while (k < strlen)
    {
        modified[j] = original[k];
        k = k + 2;
        j++;
    }

    return modified; 
}
       
