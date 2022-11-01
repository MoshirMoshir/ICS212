/*****************************************************************
//
//  NAME:        Micah Schoefield
//
//  HOMEWORK:    2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 24, 2022
//
//  FILE:        user_interface.c
//
//  DESCRIPTION: This program is a user interface for a bank
//               and will allow a banker to alter a database.
//              
//           
//   
//
****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "database.h"


int debugmode = 0;

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   This is the main part of the user_interface.
//                 This will take user input and process that data.
//                 
//               
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : success
//                 
//
****************************************************************/

int main (int argc, char* argv[])
{
    struct record * start = NULL;
    char userInput[10];
    int i = 0;
    int willQuit = 0;
    void getaddress(char inputAddress[], int size);
    readfile(&start, "Bankrecords");
    if (argc == 2 && strcmp(argv[1], "debug") == 0)
    {
        debugmode = 1;
    } 
    else if (argc > 1)
    {
        printf("\nError: Incorrect argument, exiting program.\n");
        willQuit++;
        i++;
    }
    if (willQuit == 0)
    {
        printf("\nWelcome user\n");
        printf("Please choose one of the following options\n");
    }
    while (i <1)
    {
        int j = 0;
        printf("add: This adds a new record in the database\n");
        printf("printall: This prints all record in the databse\n");
        printf("find: This finds record(s) with a specified amount\n");
        printf("delete: This deletes an existing record from the database\n");
        printf("quit: quits program\n");

        do
        {
            fgets(userInput, 10, stdin);
            
            if (strncmp(userInput, "q", 1) == 0)
            {
                if (strlen(userInput) > 5)
                {
                    printf("error : Invalid option chosen!\n");
                    j++;
                }
                else
                {
                    writefile(start, "Bankrecords");
                    j++;
                    i++;
                }
            }

            else if (strncmp(userInput, "a", 1) == 0)
            {
                if (strlen(userInput) > 4)
                {
                    printf("error : Invalid option chosen!\n");
                    j++;
                }
                else
                {
                    char userName[30];
                    char userAddress[60];
                    int accountno;
                    int correct = 0;
                    printf("You are adding a record, enter a name\n");
                    fgets(userName, 30, stdin);
                    printf("Enter an address (Press enter, or return, twice to finish)\n");
                    getaddress(userAddress, 60);
                    printf("Enter an account number\n");
                    do
                    {
                        fgets(userInput, 10, stdin);
                        accountno = atoi(userInput);
                        if (accountno <= 0)
                        {
                            printf("error : invalid input!\n");
                            printf("Please enter a POSITIVE integer\n");
                        }
                        else
                        {
                            correct++;
                        }
                    
                    
                    }
                    while (correct < 1);
                    j++;
                    addRecord(&start, accountno, userName, userAddress);
                }
            }
            else if (strncmp(userInput, "p", 1) == 0)
            {
                if (strlen(userInput) > 9)
                {
                    printf("error : Invalid option chosen!\n");
                    j++;
                }
                else
                {
                    printAllRecords(start);
                    j++;
                }
            }
            else if (strncmp(userInput, "f", 1) == 0)
            {

                if (strlen(userInput) > 5)
                {
                    printf("error : Invalid option chosen!\n");
                    j++;                  
                }
                else
                {
                    int accountno;
                    int correct = 0;
                    printf("Enter account number of account to find\n");
                    do
                    {
                        fgets(userInput, 10, stdin);
                        accountno = atoi(userInput);
                        if (accountno <= 0)
                        {
                            printf("error : invalid input!\n");
                            printf("Please enter a POSITIVE integer\n");
                        }
                        else
                        {
                            correct++;
                        }
                    }
                    while (correct < 1);
                    j++;
                    findRecord(start, accountno);
                }
            }
            else if (strncmp(userInput, "d", 1) == 0)
            {

                if (strlen(userInput) > 7)
                {
                    printf("error : Invalid option chosen!\n");
                    j++;
                }
                else 
                {
                    int accountno;
                    int correct = 0;
                    printf("Enter account number of account to delete\n");
                    do
                    {
                        fgets(userInput, 10, stdin);
                        accountno = atoi(userInput);
                        if (accountno <= 0)
                        {
                            printf("error : invalid input!\n");
                            printf("Please enter a POSITIVE integer\n");
                        }
                        else
                        {
                            correct++;
                        }


                    }
                    while (correct < 1);
                    j++;
                    deleteRecord(&start, accountno);
                }

            }
            else
            {
                printf("Invalid input!\n");
            }
            if (i != 1)
            {
                printf("\nChoose another option\n");
            }
        }
        while(j < 1);
        
    }
    printf("\nThank You. Good Bye.\n");
    return 0;
}



/*****************************************************************
//  Function name: getaddress
//
//  DESCRIPTION:   This function collects the address from the
//                 in whatever format the user wants.
//                 
//
//
//  Parameters:    inputAddress[] : The address array to be changed.
//                 size : The size of the array
//                                 
//
//  Return values:  void
//
***************************************************************/

void getaddress (char inputAddress[], int size)
{
    int i = 0;
    char input;
    char lastInput;
    char end = '\n';
    if (debugmode == 1)
    {
        printf("\nGet address function has started. inputAddress[]: ");
        printf(inputAddress);
        printf("\nsize: %d\n", size);
    }
    while (i < size)
    {
        input = getchar();
        if (input == end && lastInput == end)
        {
            i = size;
        }
        else 
        {
            inputAddress[i] = input;
            lastInput = input;
            i++;
        }
    }






}
