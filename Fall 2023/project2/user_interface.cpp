/*****************************************************************
//
//  NAME:        Alexander Moshir
//
//  HOMEWORK:    Project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 27, 2023
//
//  FILE:        user_interface.cpp
//
//  DESCRIPTION: The user_interface from homework 3b converted to C++.
//   
****************************************************************/

#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include "llist.h"

int debugmode = 0;
int getAccountNo();
void getaddress(char [], int);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Runs the user interface of the database       
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
    llist mylist;

    if (argc == 2 && strcmp(argv[1], "debug") == 0)
    {
        debugmode = 1;
        std::cout << "\nStarting in debug mode...\n";
    } 
    else if (argc > 1)
    {
        std::cout << "\nError: Incorrect argument\n\nterminating...\n";
        return 1;
    }

    std::cout << "\nWelcome to the Bank Database!\n";
    
    do
    {
        std::cout << "\nPlease type one of the following options\n";
        std::cout << "  add      : This adds a new record in the database\n";
        std::cout << "  printall : This prints all record in the database\n";
        std::cout << "  find     : This finds record(s) with a specified amount\n";
        std::cout << "  delete   : This deletes an existing record from the database\n";
        std::cout << "  quit     : quits program\n";

        std::string user_input;
        std::getline(std::cin, user_input);

        if (user_input.substr(0, 3) == "add" && user_input.length() <= 4 && user_input.length() >= 2)
        {
            char name[50];
            char address[80];
            int account_no = getAccountNo();

            std::cout << "\nPlease enter a name:\n";
            std::cin.getline(name, 50);
            getaddress(address, 80);

            mylist.addRecord(account_no, name, address);
        }
        else if (user_input.substr(0, 8) == "printall" && user_input.length() <= 9)
        {
            mylist.printAllRecords();
        }
        else if (user_input.substr(0, 4) == "find" && user_input.length() <= 5)
        {
            mylist.findRecord(getAccountNo());
        }
        else if (user_input.substr(0, 6) == "delete" && user_input.length() <= 7)
        {
            mylist.deleteRecord(getAccountNo());
        }
        else if (user_input.substr(0, 4) == "quit" && user_input.length() <= 5)
        {
            std::cout << "\nThank you for using the Bank Database!\n\nGoodbye...\n";
            mylist.writefile("database.txt");
            break;
        }
        else
        {
            std::cout << "\nError: Invalid input\n";
        }
    } while (true);

    return 0;
}

/*****************************************************************
//
//  Function name: getAccountNo()
//
//  DESCRIPTION:   Asks for the user's account number,
//                 continues to ask until input is valid
//
//  Parameters:    
//
//  Return values:  account_no : The user's account number           
//
****************************************************************/

int getAccountNo()
{
    int account_no = 0;
    int valid = 0;
    std::string user_input;

    do
    {
        std::cout << "\nPlease enter an account number:\n";
        std::getline(std::cin, user_input);

        std::istringstream iss(user_input);
        if (iss >> account_no && account_no > 0 && iss.eof())
        {
            valid = 1;
        }
        else
        { 
            std::cout << "\nError: Invalid input\n";
        }
    } while (valid == 0);

    return account_no;
}

/*****************************************************************
//
//  Function name: getaddress()
//
//  DESCRIPTION:   Asks for the user's address,
//                 continues to ask until input is valid
//
//  Parameters:    char [] : The address array to be changed.
//                 int : The size of the array
//
//  Return values:        
//
****************************************************************/

void getaddress(char address[], int size)
{
    std::cout << "\nPlease enter an address:\n";
    std::cin.getline(address, size);
}
