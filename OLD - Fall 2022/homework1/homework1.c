/*****************************************************************
//
//  NAME:        Alexander Moshir
//
//  HOMEWORK:    1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 3, 2022
//
//  FILE:        homework1.c
//
//  DESCRIPTION: Outputs the same output as helloworld.java
//
//
****************************************************************/


#include <stdio.h>


/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Reproduces the function in helloworld.java
//
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : success
//
//
****************************************************************/

int main(int argc, char* argv[])
{
    int num;
    int i;
    
    for (i = 0; i < 6; ++i)
    {
        if (i < 2)
            printf("Hello\n");
        else if (i < 4)
            printf("World\n");
        else
            printf("!!!\n");
    }

    num = 0;
    while (num < 3)
    {
        printf("While loop!\n");
        ++num;
    }

    num = 0;
    do
    {
        printf("Do-while loop!\n");
        ++num;
    }
    while (num < 3);
    
    return 0;
}
