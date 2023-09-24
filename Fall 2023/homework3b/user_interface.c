/*****************************************************************
//
//  NAME:        Alexander Moshir
//
//  HOMEWORK:    3b
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 23, 2023
//
//  FILE:        homework3b.c
//
//  DESCRIPTION:
//   A banking database program that allows the user to
//   add, print, delete, and find addresses in the database
//
****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "database.h"
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
    struct record * start = NULL;
    bool running = true;
    char user_input[10];

    // Checks for debug mode
    if (argc == 2 && strcmp(argv[1], "debug") == 0)
    {
        debugmode = 1;
        printf("\nStarting in debug mode...\n");
    } 
    else if (argc > 1)
    {
        printf("\nError: Incorrect argument, terminating...\n");
        running = false;
    }

    // Runs the user interface
    printf("\nWelcome to the Bank Database!\n");
    do
    {
        printf("\nPlease choose one of the following options by typing the option\n");
        printf("add: This adds a new record in the database\n");
        printf("printall: This prints all record in the databse\n");
        printf("find: This finds record(s) with a specified amount\n");
        printf("delete: This deletes an existing record from the database\n");
        printf("quit: quits program\n");

        fgets(user_input, 20, stdin);
        if (strncmp(user_input, "add", 3) == 0)
        {
            char name[50];
            char address[80];
            int account_no = getAccountNo();

            printf("\nPlease enter a name: ");
            fgets(name, 50, stdin);
            getaddress(address, 80);
            addRecord(&start, account_no, name, address);
        }
        else if (strncmp(user_input, "printall", 8) == 0)
        {
            printAllRecords(start);
        }
        else if (strncmp(user_input, "find", 4) == 0)
        {
            findRecord(start, getAccountNo());
        }
        else if (strncmp(user_input, "delete", 6) == 0)
        {
            deleteRecord(&start, getAccountNo());
        }
        else if (strncmp(user_input, "quit", 4) == 0)
        {
            printf("\nThank you for using the Bank Database\nGoodbye\n");
            running = false;
        }
        else
        {
            printf("\nError: Invalid input\n");
        }
    } while (running);
    
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
    bool valid = false;
    char user_input[10];

    if (debugmode == 1)
    {
        printf("\ngetAccountNo()\n");
    }

    do
    {
        printf("\nPlease enter an account number: ");
        fgets(user_input, 10, stdin);
        if (sscanf(user_input, "%d", &account_no) == 1 && account_no > 0)
        {
            valid = true;
        }
        else
        {
            printf("\nError: Invalid input\n");
        }
    } while (!valid);

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
//  Return values:  void        
//
****************************************************************/

void getaddress(char address[], int size)
{
    bool running = true;
    char user_input[80];
    char input;
    char temp = '\0';

    if (debugmode == 1)
    {
        printf("\ngetaddress(%s, %d)\n", address, size);
    }

    do
    {
        printf("\nPlease enter an address: ");
        input = getchar();
        if (input == '\n' && temp == '\n')
        {
            running = false;
        }
        else
        {
            strncat(user_input, &input, 1);
            temp = input;
        }
        

    } while (running);
    strcpy(address, user_input);
}
