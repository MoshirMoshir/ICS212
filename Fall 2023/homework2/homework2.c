/*****************************************************************
//
//  NAME:        Alexander Moshir
//
//  HOMEWORK:    homework 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        9 September 2023
//
//  FILE:        homework2.c
//
//  DESCRIPTION: Generates a table up to user inputted number
//               and labels them even or odd.
//
****************************************************************/

#include <stdio.h>
int user_interface();
int is_even(int);
void print_table(int);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Generates a table up to user inputted number
//                 and labels them even or odd.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : Success
//
****************************************************************/

int main(int argc, char* argv[])
{
    int max = user_interface();

    print_table(max);

    return 0;
}

/*****************************************************************
//
//  Function name: user_interface();
//
//  DESCRIPTION:   prints instructions and takes user input
//
//  Parameters:    none
//
//  Return values:  in : number inputted by user
//
****************************************************************/

int user_interface()
{
    int in = 0;
    char temp[999];

    printf("This program will generate a table of numbers up to the number you enter and label them even or odd.\n");
    printf("Enter maximum number to show: ");
    scanf("%d", &in);
    while(in <= 0)
    {
        printf("Invalid input. Please enter a positive number: ");
        fgets(temp, 999, stdin);
        scanf("%d", &in);
        
    }

    return in;
}

/*****************************************************************
//
//  Function name: is_even();
//
//  DESCRIPTION:   checks if parameter is even
//
//  Parameters:    int num : number to check
//
//  Return values:  1 : even
//                  0 : odd
//
****************************************************************/

int is_even(int num)
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

/*****************************************************************
//
//  Function name: print_table();
//
//  DESCRIPTION:   generates table of numbers up to parameter
//
//  Parameters:    int end : number to end table at
//
//  Return values:  0 : Success
//
****************************************************************/

void print_table(int end)
{
    int i = 0;
    printf("Number\tEven or Odd?\n");
    for(i = 0; i <= end; i++)
    {
        if(is_even(i) == 1)
        {
            printf("%6d\tEven\n", i);
        }
        else
        {
            printf("%6d\tOdd\n", i);
        }
    }
}