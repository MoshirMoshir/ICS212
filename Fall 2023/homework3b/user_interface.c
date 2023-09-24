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
    int running = 1;
    char user_input[20];

    /* Checks for debug mode */
    if (argc == 2 && strcmp(argv[1], "debug") == 0)
    {
        debugmode = 1;
        printf("\nStarting in debug mode...\n");
    } 
    else if (argc > 1)
    {
        printf("\nError: Incorrect argument\n\nterminating...\n");
        running = 0;
    }

    /* Runs the user interface */
    if (running)
    {
        printf("\nWelcome to the Bank Database!\n");
        do
        {
            printf("\nPlease type one of the following options\n");
            printf("  add      : This adds a new record in the database\n");
            printf("  printall : This prints all record in the database\n");
            printf("  find     : This finds record(s) with a specified amount\n");
            printf("  delete   : This deletes an existing record from the database\n");
            printf("  quit     : quits program\n");

            fgets(user_input, 20, stdin);
            if (strncmp(user_input, "add", strlen(user_input) - 1) == 0 && strlen(user_input) <= 4)
            {
                char name[50];
                char address[80];
                int account_no = getAccountNo();

                printf("\nPlease enter a name: ");
                fgets(name, 50, stdin);
                getaddress(address, 80);
                addRecord(&start, account_no, name, address);
            }
            else if (strncmp(user_input, "printall", strlen(user_input) - 1) == 0 && strlen(user_input) <= 9)
            {
                printAllRecords(start);
            }
            else if (strncmp(user_input, "find", strlen(user_input) - 1) == 0 && strlen(user_input) <= 5)
            {
                findRecord(start, getAccountNo());
            }
            else if (strncmp(user_input, "delete", strlen(user_input) - 1) == 0 && strlen(user_input) <= 7)
            {
                deleteRecord(&start, getAccountNo());
            }
            else if (strncmp(user_input, "quit", strlen(user_input) - 1) == 0 && strlen(user_input) <= 5)
            {
                printf("\nThank you for using the Bank Database!\n\nGoodbye...\n");
                running = 0;
            }
            else
            {
                printf("\nError: Invalid input\n");
            }
        } while (running == 1);
    }
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
            valid = 1;
        }
        else
        {
            printf("\nError: Invalid input\n");
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
    int running = 1;
    char user_input[80];
    char input;
    char temp = '\0';

    if (debugmode == 1)
    {
        printf("\ngetaddress(%s, %d)\n", address, size);
    }

    printf("\nPlease enter an address: ");
    do
    {
        
        input = getchar();
        if (input == '\n' && temp == '\n')
        {
            running = 0;
        }
        else
        {
            strncat(user_input, &input, 1);
            temp = input;
        }
        

    } while (running == 1);
    strcpy(address, user_input);
}
