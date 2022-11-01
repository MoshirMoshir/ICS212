/*****************************************************************
//
//  NAME:        Alexander Moshir
//
//  HOMEWORK:    Project 1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 29, 2022
//
//  FILE:        user_interface.c
//
//  DESCRIPTION: The user_interface from homework 3b.
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
//  DESCRIPTION:   A database of records with a UI to edit the database.     
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
    void getaddress(char inputAddress[], int size);
    int quit = 0;
    char input[10];
    

    readfile(&start, "database_data");
    if (argc == 2 && strcmp(argv[1], "debug") == 0)
    {
        debugmode = 1;
    }
    else if (argc > 1)
    {
        printf("\nerror: unknown argc\n");
        quit = 1;
    }
    printf("--------------------------------------------------\n");
    printf("Record Database Interface\n");
    printf("\n   Welcome to the RDI, with this program, you can \n"
           "create a database of records that hold a Name, \n"
           "Account Number, and Address.\n");
    printf("--------------------------------------------------\n");

    if(debugmode == 1)
    {
        printf("debug: Menu UI Interface Successful");
    }

    printf("\nPlease type an option:\n");

    while (quit == 0)
    {
        
        printf("add      : adds a new record to the database\n"
               "printall : prints all the records in the database\n"
               "find     : finds a record in the database\n"
               "delete   : deletes a record in the database\n"
               "quit     : quits the program\n");

        fgets(input, 10, stdin);
        

        if (strncmp(input, "q", 1) == 0)
        {
            if (strlen(input) > 5)
            {
                printf("\nerror: invalid input\n");
                if(debugmode == 1)
                {
                    printf("debug: Quit Failed");
                }
            }
            else
            {
                writefile(start, "database_data");
                quit = 1;
                if(debugmode == 1)
                {
                    printf("debug: Quit Successful");
                }
            }
        }
        else if (strncmp(input, "a", 1) == 0)
        {
            if (strlen(input) > 4)
            {
                printf("\nerror: invalid input\n");
                if(debugmode == 1)
                {
                    printf("debug: Add Failed");
                }
            }
            else
            {
                char userName[30];
                char userAddress[60];
                int accountno;
                int success = 0;
                printf("\nInput a name:\n");
                fgets(userName, 30, stdin);
                printf("\nInput an address:\n");
                getaddress(userAddress, 60);
                printf("Input an account number:\n");
                do
                {
                    fgets(input, 10, stdin);
                    accountno = atoi(input);
                    if (accountno <= 0)
                    {
                        printf("\nerror: invalid input\n");
                        printf("The account number must be a positive number\n");
                        if(debugmode == 1)
                        {
                            printf("debug: Negative Number Attempted to be Inputted");
                        }
                    }
                    else
                    {
                        success++;
                        if(debugmode == 1)
                        {
                            printf("debug: Add Successful");
                        }
                    }
                
                
                }
                while (success == 0);

                addRecord(&start, accountno, userName, userAddress);
                printf("\nThe account was added succesfully\n");
            }
        }
        else if (strncmp(input, "p", 1) == 0)
        {
            if (strlen(input) > 9)
            {
                printf("\nerror: invalid input\n");
                if(debugmode == 1)
                {
                    printf("debug: Printall failed");
                }
            }
            else
            {
                printAllRecords(start);
                if(debugmode == 1)
                {
                    printf("debug: Printall Successful");
                }
            }
        }
        else if (strncmp(input, "f", 1) == 0)
        {

            if (strlen(input) > 5)
            {
                printf("\nerror: invalid input\n");   
                if(debugmode == 1)
                {
                    printf("debug: Find Failed");
                }               
            }
            else
            {
                int accountno;
                int success = 0;
                printf("\nType an account number to find:\n");
                do
                {
                    fgets(input, 10, stdin);
                    accountno = atoi(input);
                    if (accountno <= 0)
                    {
                        printf("\nerror: invalid input\n");
                        printf("The account number must be a positive number\n");
                        if(debugmode == 1)
                        {
                            printf("debug: Negative Number Attempted to be Inputted");
                        }
                    }
                    else
                    {
                        success++;
                    }
                }
                while (success == 0);

                findRecord(start, accountno);
                if(debugmode == 1)
                {
                    printf("debug: Find Succesful");
                }
            }
        }
        else if (strncmp(input, "d", 1) == 0)
        {

            if (strlen(input) > 7)
            {
                printf("\nerror: invalid input\n");
                if(debugmode == 1)
                {
                    printf("debug: Delete Failed");
                }
            }
            else 
            {
                int accountno;
                int success = 0;
                printf("\nType an account number to delete\n");
                do
                {
                    fgets(input, 10, stdin);
                    accountno = atoi(input);
                    if (accountno <= 0)
                    {
                        printf("\nerror: invalid input\n");
                        printf("The account number must be a positive number\n");
                        if(debugmode == 1)
                        {
                            printf("debug: Negative Number Attempted to be Inputted");
                        }
                    }
                    else
                    {
                        printf("account %d was deleted", accountno);
                        success++;
                    }


                }
                while (success == 0);

                deleteRecord(&start, accountno);
                if(debugmode == 1)
                {
                    printf("debug: Deleted Succesful");
                }
            }

        }
        else
        {
            printf("\nerror: option does not exist\n");
            if(debugmode == 1)
            {
                printf("debug: Input did not match any options");
            }
        }
        if (quit != 1)
        {
            printf("\nChoose another option:\n");
            if(debugmode == 1)
            {
                printf("debug: Quit parameters not met, relaunching menu");
            }
        }

    }
    
    printf("\nExiting the program...\n");
    return 0;

}

/*****************************************************************
//
//  Function name: getaddress
//
//  DESCRIPTION:   A database of records with a UI to edit the database.     
//
//  Parameters:    char Address[] : address to be inputted
//                 int size : size of address
//                                  
****************************************************************/

void getaddress(char Address[], int size)
{
    int i = 0;
    char input;
    char enterIn;

    while (i < size)
    {
        input = getchar();
        if (input == '\n' && enterIn == '\n')
        {
            i = size;
        }
        else
        {
            Address[i] = input;
            enterIn = input;
            i++;
        }
    }

    if(debugmode == 1)
    {
        printf("debug: getaddress Function executed");
    }


}