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

int is_even(int);

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