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
//  DATE:        September 3, 2023
//
//  FILE:        homework1.c
//
//  DESCRIPTION:
//   The first homework, a transpose of helloworld.java to C
//
****************************************************************/

#include <stdio.h>

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   A transpose of hellowworld.java, prints out a variety of "helloworlds"
//                 
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : success
//
****************************************************************/

int main(int argc, char* argv[])
{
    int num = 0;
    int i = 0;

    for (i = 0; i < 5; i = i + 1)
    {
        if (i < 2)
            printf("Hello\n");
        else if (i < 4)
            printf("World\n");
        else
            printf("!!!\n");
    }

    while (num < 4)
    {
        printf("While loop!\n");
        num = num + 1;
    }

    num = 0;
    do
    {
        printf("Do-while loop!\n");
        num = num + 1;
    } 
    while (num < 4);

    return 0;
}

