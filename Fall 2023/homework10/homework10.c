/*****************************************************************
//
//  NAME:        Alexander Moshir
//
//  HOMEWORK:    homework 10
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        9 December 2023
//
//  FILE:        homework10.c
//
//  DESCRIPTION: Determines if a number is even
//
****************************************************************/

#include "homework10.h"

/*****************************************************************
//
//  Function name: Java_homework10_is_1even
//
//  DESCRIPTION:   checks if parameter is even
//
//  Parameters:    JNIEnv *env : JNI environment
//                 jclass  : class
//                 jint    : number to check
//
//  Return values:  1 : even
//                  0 : odd
//
****************************************************************/

JNIEXPORT jint JNICALL Java_homework10_is_1even(JNIEnv *env, jclass class, jint num)
{
   int out;

    if(num % 2 == 0)
    {
        out = 1;
    }
    else
    {
        out = 0;
    }

    return out;
}
