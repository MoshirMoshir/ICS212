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
    int number;

    number = user_interface();
    print_table(number);
    



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
    int intInput = 0;
    printf("The second homework for ICS 212. Takes an int input \nfrom the user and outputs from 0 up until that number \nand identifies if each number is a multiple of 5.\n");
    
    do
    {
        printf("Enter a maximum number to show: ");
        scanf("%d", &intInput);
    } 
    while (!(intInput > 0));
    {
        printf("That wasn't a valid number! Please try again: ");
        scanf("%d", &intInput);
    }

    return intInput;
}

/*****************************************************************
//
//  Function name: is_multiple4
//
//  DESCRIPTION:   A template function
//                 This function does not do anything.
//                 Please describe your function correctly.
//
//  Parameters:    int input
//
//  Return values:  1 : input is a multiple of 4
                    0 : input is not a multiple of 4
//
****************************************************************/

int is_multiple4(int input)
{
    if ( input % 4 == 0)
    {
        return 1;
    }
    else
        return 0;
}

/*****************************************************************
//
//  Function name: print_table
//
//  DESCRIPTION:   A template function
//                 This function does not do anything.
//                 Please describe your function correctly.
//
//  Parameters:    int input
//
//  Return values:  0 : success
//
****************************************************************/

int print_table(int input)
{
    int i;
	printf("%*s\t", 3, "Number");
	printf("%*s\n", 3, "Multiple of 4?");
    for (i = 0; i < input; ++i)
    {
        printf("%*s\t", 3, "%d", i);
        if (is_multiple4(i))
            printf("%*s\n", 3, "Yes");
        else
            printf("%*s\n", 3, "No");
    }

}
