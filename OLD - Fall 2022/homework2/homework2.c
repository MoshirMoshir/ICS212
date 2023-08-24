/*****************************************************************
//
//  NAME:        Alexander Moshir
//
//  HOMEWORK:    2
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
int user_interface();
int is_multiple4(int input);
int print_table(int input);


/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Calls for a user input and prints out a table      
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
    int number;

    number = user_interface();
    print_table(number);
    

    return 0;

}

/*****************************************************************
//
//  Function name: user_interface
//
//  DESCRIPTION:   Prints out description and
//                 gets user input. Rejects characters and
//                 negative numbers but accepts floats at
//                 it's lowest whole number
//
//  Return values:  input : user input int > 0
//
****************************************************************/

int user_interface()
{
    int input = 0;
    printf("The second homework for ICS 212. Takes an int input \nfrom the user and outputs from 0 up until that number \nand identifies if each number is a multiple of 5.\n");
    

    printf("Enter maximum number to show: ");
    while(scanf("%d",&input) != 1 || input <= 0)
    {
        printf("That wasn't a valid number, please try again: ");
        while(getchar() != '\n');
    }

    return input;
}

/*****************************************************************
//
//  Function name: is_multiple4
//
//  DESCRIPTION:   determines if int input is a
//                 multiple of 4
//
//  Parameters:    int input
//
//  Return values:  1 : input is a multiple of 4
//                  0 : input is not a multiple of 4
//
****************************************************************/

int is_multiple4(int input)
{
    int result;
    if ( input % 4 == 0)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

/*****************************************************************
//
//  Function name: print_table
//
//  DESCRIPTION:   prints a table of all whole numbers
//                 from 0 up to number (user input) and
//                 if they are multiples of 4.
//
//  Parameters:    int input
//
//  Return values:  0 : success
//
****************************************************************/

int print_table(int input)
{
    int i;
    printf("%3s\t", "Number");
    printf("%3s\n", "Multiple of 4?");
    for (i = 0; i <= input; ++i)
    {
        printf("%6d\t", i);
        if (is_multiple4(i))
            printf("%3s\n", "Yes");
        else
            printf("%2s\n", "No");
    }

    return 0;
}
