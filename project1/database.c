


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
//  FILE:        database.c
//
//  DESCRIPTION:
//   The first project for ICS 212 consists of database.c, database.h,
//   user_interface.c, record.h, Makefile, testplan.xlsx, summary.txt,
//   proof.txt, and output.txt
//
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

extern int debugmode;


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

void addRecord(struct record **start, int uaccountno, char uname[], char uaddress[])
{
    struct record *temp;
    int i;

    temp = (struct record*)malloc(sizeof(struct record));

    strcpy(temp->name, uname);
    strcpy(temp->address, uaddress);
    temp->accountno = uaccountno;
    temp->next = NULL;
    if (*start != NULL)
    {
        struct record *prev;
        prev = *start;
        i = 0;
        if (temp->accountno >= prev->accountno)
        {
            temp->next = prev;
            *start = temp;
        }
        else
        {
            if (prev->next == NULL)
            {
                temp->next = prev->next;
                prev->next = temp;
            }
            else
            {
                while (i < 1)
                {
                    if (temp->accountno >= prev->next->accountno)
                    {
                        temp->next = prev->next;
                        prev->next = temp;
                        i++;
                    }
                    else
                    {
                        prev = prev->next;
                    }
                }
            }
        }
    }
    else
    {
        temp->next = NULL;
        *start = temp;
    }

    if(debugmode == 1)
    {
        printf("debug: addRecord Function executed");
    }
}

void printAllRecords(struct record *start)
{
    if (start == NULL || start->accountno == 0)
    {
        printf("--------------------------------------------------\n");
        printf("\ndatabase is empty\n\n");
        printf("--------------------------------------------------\n");
    }
    else
    {
        
        while (start != NULL && start->accountno != 0)
        {
            printf("--------------------------------------------------\n");
            printf("Name      : %s\n", start->name);
            printf("AccountNo : %d\n", start->accountno);
            printf("Address   : %s\n", start->address);

            start = start->next;
        }
        printf("--------------------------------------------------\n");
    }

    if(debugmode == 1)
    {
        printf("debug: printAllRecords Function executed");
    }
}

int findRecord(struct record *start, int uaccountno)
{
    int out = -1;

    if (start == NULL)
    {
        printf("--------------------------------------------------\n");
        printf("\ndatabase is empty\n\n");
        printf("--------------------------------------------------\n");
    }
    else
    {
        while (start != NULL)
        {
            if (start->accountno == uaccountno)
            {
                printf("--------------------------------------------------\n");
                printf("Name      : %s\n", start->name);
                printf("AccountNo : %d\n", start->accountno);
                printf("Address   : %s\n", start->address);
                printf("--------------------------------------------------\n");
                out = 0;
            }

            start = start->next;
        }
    }
    if (out == -1)
    {
        printf("\naccount does not exist\n");
    }

    if(debugmode == 1)
    {
        printf("debug: findRecord Function executed");
    }

    return out;
}

int deleteRecord(struct record **start, int uaccountno)
{
    int out = -1;
    struct record *temp;
    struct record *tempnext;
    temp = *start;
    if (temp == NULL)
    {
        printf("\ndatabase is empty\n");
    }
    else if (temp->accountno == uaccountno)
    {
        while (temp->next != NULL && temp->next->accountno == uaccountno)
        {    
            tempnext = temp->next->next;
            free(temp->next);
            temp->next = tempnext;
            
        }
        free(*start);
        temp = NULL;
        *start = NULL;
        out = 0;
    }
    else if (temp->next != NULL && temp->next->accountno == uaccountno)
    { 
        while (temp->next != NULL && temp->next->accountno == uaccountno)
        {
            tempnext = temp->next->next;
            free(temp->next);
            temp->next = tempnext;

        }
        out = 0;
    }
    else
    {
        printf("\naccount does not exist\n");
    }

    temp = NULL;
    tempnext = NULL;

    if(debugmode == 1)
    {
        printf("debug: deleteRecord Function executed");
    }

    return out;
}

int writefile(struct record *start, char file[])
{
    int out = -1;
    FILE *write = fopen(file, "w");
    if (write != NULL)
    {
        if (start == NULL)
        {
            printf("\ndatabase is empty\n");
        }
        else
        {
            while (start != NULL)
            {
                fprintf(write, "%d", start->accountno);
                fprintf(write, "%s", start->name);
                fprintf(write, "%s\n", start->address);
    
                start = start->next;
            }
        }
        fclose(write);
        out = 0;
    }
    else
    {
        printf("\nerror: unable to write a file\n");
    }

    if(debugmode == 1)
    {
        printf("debug: writefile Function executed");
    }

    return out;
}

int readfile(struct record **start, char file[])
{
    int out = -1;
    struct record *temp;
    struct record *prevTemp;
    int uaccountno;
    char uname[30];
    char uaddress[60];
    char input;
    char prevInput;
    int running = 0;
    int i;

    FILE *read = fopen(file, "r");

    if (read != NULL)
    {
        temp = (struct record *)malloc(sizeof(struct record));
        if (temp != NULL && !feof(read))
        {
            fscanf(read, "%i", &uaccountno);
            temp->accountno = uaccountno;
            fgets(uname, 30, read);
            strcpy(temp->name, uname);
            i = 0;
            while (running == 0 && !feof(read))
            {  
                if ((input = fgetc(read)) == '\n' && prevInput == '\n')
                {
                    running++;
                }
                else
                {
                    if (input != EOF)
                    {
                        uaddress[i] = input;
                        prevInput = input;
                        i++;
                    }
                }
            }
            strcpy(temp->address, uaddress);
            *start = temp;
            prevTemp = temp;
            temp = prevTemp->next;
        }
        while (prevTemp != NULL && !feof(read))
        {
            temp = (struct record*)malloc(sizeof(struct record));
            fscanf(read, "%i", &uaccountno);
            temp->accountno = uaccountno;
            fgets(uname, 30, read);
            strcpy(temp->name, uname);
            i = 0;
            temp->next = prevTemp->next;
            while (running == 0 && !feof(read))
            {  
                if ((input = fgetc(read)) == '\n' && prevInput == '\n')
                {
                    running++;
                }
                else
                {
                    if (input != EOF)
                    {
                        uaddress[i] = input;
                        prevInput = input;
                        i++;
                    }
                }
            }
            strcpy(temp->address, uaddress);
            prevTemp->next = temp;
            prevTemp = temp;
            temp = prevTemp->next;
        }
        fclose(read);
        out = 0;
    }
    else
    {
        printf("\ndatabase_data not found, creating new file...\n");
        writefile(NULL, "database_data");
    }

    if(debugmode == 1)
    {
        printf("debug: readfile Function executed");
    }

    return out;
}

void cleanup(struct record **start)
{
    struct record *temp;
    struct record *tempnext;
    temp = *start;
    while (temp != NULL)
    {
        tempnext = temp->next;
        free(temp);
        temp = tempnext;
    }
    *start = NULL;

    if(debugmode == 1)
    {
        printf("debug: cleanup Function executed");
    }
}