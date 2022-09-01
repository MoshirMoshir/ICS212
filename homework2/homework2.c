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
//  DATE:        September 10, 2022
//
//  FILE:        homework2.c
//
//  DESCRIPTION:
//   The second homework for ICS 212. Takes an int input
//   from the user and outputs from 0 up until that number
//   and identifies if each number is a multiple of 5.
//
****************************************************************/

#include <stdio.h>

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Don't forget to describe what your main
//                 function does.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : some meaning
//                 -1 : some meaning
//
****************************************************************/

int main(int argc, char* argv[])
{
    printf("The second homework for ICS 212. Takes an int input 
          \nfrom the user and outputs from 0 up until that number 
          \nand identifies if each number is a multiple of 5.");

    int intInput;
    printf("Enter a maximum number to show: ");
    scanf("%d", &intInput);
    
    print("Number    Multiple of 5?");
    for (i = 0; i <= intInput; ++i)
    {
        printf(i);

        if (i % 5 == 0);
            print("    Yes\n");   
        else
            print("    No\n");
    }


}

/*****************************************************************
//
//  Function name: user_interface
//
//  DESCRIPTION:   A template function
//                 This function does not do anything.
//                 Please describe your function correctly.
//
//  Parameters:    
//
//  Return values:  0 : success
//
****************************************************************/

int user_interface()
{
    ...
}
