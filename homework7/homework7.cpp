/*****************************************************************
//
//  NAME:        Alexander Moshir
//
//  HOMEWORK:    7
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        Novemeber 5, 2022
//
//  FILE:        homework7.cpp
//
//  DESCRIPTION:
//   The seventh homework for ICS 212. Takes an int input
//   from the user and outputs from 0 up until that number
//   and identifies if each number is a multiple of 5, but in C++.
//
****************************************************************/

#include <iostream>
#include <cstdio>
#include <limits>
using namespace std;

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
    cout << "The seventh homework for ICS 212. Takes an int input \nfrom the user and outputs from 0 up until that number \nand identifies if each number is a multiple of 5, but in C++." << endl;
    

    cout << "Enter maximum number to show: ";
    cin >> input;
    while(input <= 0)
    {
        cout << "That wasn't a valid number, please try again: " << endl;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin >> input;
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
    cout << "Number\t";
    cout << "Multiple of 4?" << endl;
    for (i = 0; i <= input; ++i)
    {
        cout << i;
        if (is_multiple4(i))
            cout << "\tYes" << endl;
        else
            cout << "\tNo" << endl;
    }

    return 0;
}
