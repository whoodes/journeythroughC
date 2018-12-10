/*******************************************************************
//
//  NAME:        Wyatt Hoodes
//
//  HOMEWORK:    Homework 9
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        Nov 25, 2018
//
//  FILE:        Homework9.c
//
//  DESCRIPTION: The library to be linked with the java exec.
//
*******************************************************************/

#include "Homework9.h"

/**********************************************************************
//
//  Function name: Java_Homework9_isDivisible
//
//  Description:   The single function for the Homework9 library.
//
//  Paramters:     env (JNIEnv *) : unclear
//                 obj (jobject) : java object
//                 factor (jint) : factor to be tested for divisiblity
//                 num (jint) : number from user input
//
//  return values: : 1 : is divisible
//                   0 : indivisible
//
***********************************************************************/

JNIEXPORT jint JNICALL Java_Homework9_isDivisible (JNIEnv * env, jobject obj, jint factor, jint num)
{
    int result = 0;

    if(num % factor == 0)
    {
        result = 1;
    }

    return result;
}
