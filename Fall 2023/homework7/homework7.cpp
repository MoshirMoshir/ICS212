/*****************************************************************
//
//  NAME:        Alexander Moshir
//
//  HOMEWORK:    homework 7
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        9 Novemeber 2023
//
//  FILE:        homework7.cpp
//
//  DESCRIPTION: Generates a table up to user inputted number
//               and labels them even or odd, transcribed from C to C++
//
****************************************************************/

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;
int user_interface();
void is_even(int, int&);
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
//  Return values:  0 : success           
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
//  Return values:  in : number inputted by user
//
****************************************************************/

int user_interface()
{
    int in = 0;
    cout << "This program will generate a table of numbers up to the number you enter and label them even or odd.\n" << endl;
    cout << "Enter maximum number to show: ";
    cin >> in;
    while(in <= 0)
    {
        cout << "Invalid input. Please enter a positive number: " << endl;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin >> in;
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
//                 int& address : address of check value
//
****************************************************************/

void is_even(int num, int& address)
{
    int* out = &address;

    if (num % 2 == 0)
    {
        *out = 1;
    }
    else
    {
        *out = 0;
    }
}

/*****************************************************************
//
//  Function name: print_table();
//
//  DESCRIPTION:   generates table of numbers up to parameter
//
//  Parameters:    int end : number to end table at
//
****************************************************************/

void print_table(int end)
{
    int i = 0;
    int compare;
    cout << "Number\tEven or Odd?\n" << endl;
    for (i = 0; i <= end; ++i)
    {
        cout << i;
        is_even(i, compare);
        if (compare == 1)
        {
            cout << "\tEven" << endl;
        }
        else
        {
            cout << "\tOdd" << endl;
        }
    }
}
