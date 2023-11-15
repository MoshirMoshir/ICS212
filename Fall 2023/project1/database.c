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
//  DATE:        October 27, 2023
//
//  FILE:        database.c
//
//  DESCRIPTION:
//   The first project for ICS 212 consists of database.c, database.h,
//   user_interface.c, record.h, Makefile, testplan.xlsx, summary.txt,
//   proof.txt, and successput.txt
//
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"
extern int debugmode;

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   Adds a record to the database list     
//
//  Parameters:    struct record **start : address of the first record address in database
//                 int uaccountno : account number to be added
//                 char uname[] : account name to be added
//                 char uaddress[] : account address to be added
//
****************************************************************/

void addRecord(struct record **start, int uaccountno, char uname[], char uaddress[])
{
    struct record *temp;
    int i;

    if(debugmode == 1)
    {
        printf("\naddRecord(%p, %d, %s, %s)\n", &start, uaccountno, uname, uaddress);
    }

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

}

/*****************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   Prints all records in database    
//
//  Parameters:    struct record *start : first record in database          
//
****************************************************************/

void printAllRecords(struct record *start)
{
    if(debugmode == 1)
    {
        printf("\nprintAllRecords(%p)\n", start);
    }

    if (start == NULL || start->accountno == 0)
    {
        printf("\ndatabase is empty\n\n");
    }
    else
    {
        
        while (start != NULL && start->accountno != 0)
        {
            printf("Name      : %s\n", start->name);
            printf("AccountNo : %d\n", start->accountno);
            printf("Address   : %s\n", start->address);

            start = start->next;
        }
    }

}

/*****************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   Finds a record in the database    
//
//  Parameters:    struct record *start : first record in database
//                 int uaccountno : account number to be found
//
//  Return values:  0 : success    
//                 -1 : failure       
//
****************************************************************/

int findRecord(struct record *start, int uaccountno)
{
    int success = -1;

    if(debugmode == 1)
    {
        printf("\nfindRecord(%p, %d)\n", start, uaccountno);
    }

    if (start == NULL)
    {
        printf("\ndatabase is empty\n\n");
    }
    else
    {
        while (start != NULL)
        {
            if (start->accountno == uaccountno)
            {
                printf("Name      : %s\n", start->name);
                printf("AccountNo : %d\n", start->accountno);
                printf("Address   : %s\n", start->address);
                success = 0;
            }

            start = start->next;
        }
    }
    if (success == -1)
    {
        printf("\naccount does not exist\n");
    }

    return success;
}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   deletes a record from the database     
//
//  Parameters:    struct record **start : address of address of the first record
//                 int uaccountno : account number to be deleted
//
//  Return values:  0 : success
//                 -1 : failure           
//
****************************************************************/

int deleteRecord(struct record **start, int uaccountno)
{
    int success = -1;
    struct record *temp;
    struct record *tempnext;
    
    if(debugmode == 1)
    {
        printf("\ndeleteRecord(%p, %d)\n", &start, uaccountno);
    }

    temp = *start;
    if (temp == NULL)
    {
        printf("\ndatabase is empty\n");
    }
    else
    {
        if (temp->accountno == uaccountno)
        {
            *start = temp->next;
            free(temp);
            success = 0;
        }
        else
        {
            while (temp->next != NULL && temp->next->accountno != uaccountno)
            {
                temp = temp->next;
            }

            if (temp->next->accountno == uaccountno)
            {
                tempnext = temp->next;
                temp->next = tempnext->next;
                free(tempnext);
                success = 0;
            }
            else
            {
                printf("\naccount does not exist\n");
            }
        }
    }
        
    return success;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   writes the database to a file    
//
//  Parameters:    struct record *start : first record in database
//                 char filename[ ] : file to write to
//
//  Return values:  0 : success  
//                 -1 : failure         
//
****************************************************************/

int writefile(struct record *start, char filename[ ])
{
    int success = -1;
    FILE *write = fopen(filename, "w");
    
    if(debugmode == 1)
    {
        printf("\nwritefile(%p, %s)\n", start, filename);
    }

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
        success = 0;
    }
    else
    {
        printf("\nError: Unable to write a file\n");
    }

    return success;
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   reads a file to fill database  
//
//  Parameters:    struct record **start : address of address of first record
//                 char filename[ ] : file to read
//
//  Return values:  0 : success 
//                 -1 : failure          
//
****************************************************************/

int readfile(struct record **start, char filename[ ])
{
    int success = -1;
    struct record *temp;
    int uaccountno;
    char uname[30];
    char uaddress[50];
    char input;
    char prevInput;
    int running = 0;
    int i;

    FILE *read = fopen(filename, "r");

    if(debugmode == 1)
    {
        printf("\nreadfile(%p, %s)\n", &start, filename);
    }

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
        }
        while (temp != NULL && !feof(read))
        {
            temp = temp->next;
            temp = (struct record*)malloc(sizeof(struct record));
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
        }
        fclose(read);
        success = 0;
    }
    else
    {
        printf("\nFile not found, creating new file...\n");
        writefile(NULL, "database.txt");
    }

    return success;
}

/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   cleans up memory     
//
//  Parameters:    struct record **start : address of address of first record         
//
****************************************************************/

void cleanup(struct record **start)
{
    struct record *temp;
    struct record *tempnext;

    if(debugmode == 1)
    {
        printf("\ncleanup(%p)\n", &start);
    }

    temp = *start;
    while (temp != NULL)
    {
        tempnext = temp->next;
        free(temp);
        temp = tempnext;
    }
    *start = NULL;

}