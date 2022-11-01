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
//  DATE:        September 29, 2022
//
//  FILE:        database.c
//
//  DESCRIPTION: This program is the database for the bank.
//               
//               
//   
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
//  DESCRIPTION:   This adds a record to the database.
//                 
//               
//
//  Parameters:    start (struct record **) : The address of start
//                                             
//                 no (int) : The account number.
//                 name (name*) : The name of the account holder
//                 address (char*) : The address of the account holder
//                                  
//
//  Return values:  void
//                 
//
****************************************************************/

void addRecord(struct record ** start, int no, char uname[], char uaddress[])
{
    struct record* temp;
    int i;
    if (debugmode == 1)
    {
        printf("\naddRecord\n");
        printf("no: %d\n", no);
        printf("uname[]: %s\n", uname);
        printf("uaddress[]: %s\n", uaddress);
    }
    temp = (struct record*)malloc(sizeof(struct record));
    if (temp == NULL)
    {
        if (debugmode == 1)
        {
            printf("malloc returned a NULL pointer. Could not allocate space.\n");
        }
    }
    else
    {
        strcpy(temp->name, uname);
        strcpy(temp->address, uaddress);
        temp->accountno = no;
        temp->next = NULL;
        if (*start != NULL)
        {
            struct record* prev;
            prev = *start;
            i = 0;
            if (debugmode == 1)
            {
                printf("start is not NULL\n");
            }
            if (temp->accountno >= prev->accountno)
            {
                if (debugmode == 1)
                {
                    printf("\nInserting\n");
                }
                temp->next = prev;
                *start = temp;
            }
            else
            {
                if (prev->next == NULL)
                {
                    if (debugmode == 1)
                    {
                        printf("\nLess than start but right after start.\n");
                    }
                    temp->next = prev->next;
                    prev->next = temp;
                }
                else
                {
                    while (i < 1)
                    {
                        if (temp->accountno >= prev->next->accountno)
                        {
                            if (debugmode == 1)
                            {
                                printf("\nFurther in the list\n");
                            }
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
            if (debugmode == 1)
            {
                printf("start is NULL.\n");
            }
            temp->next = NULL;
            *start = temp;
        }
        printf("\nName is %s\n", temp->name); 
        printf("Address is %s\n", temp->address);
        printf("Account number is %d\n", temp->accountno);
        if (debugmode == 1)
        {
            printf("Next address is %p\n", (void*)temp->next);
        }
    }
    
}

/*****************************************************************
//  Function name: printAllRecord
//
//  DESCRIPTION:   This prints all records in the database.
//  
// 
//  
//  Parameters:    start (struct record *) : The address of the
//                                           start of the list
//                                             
//
//  Return values:  void
//
//
****************************************************************/


void printAllRecords(struct record * start)
{
    if (debugmode == 1)
    {
        printf("\nprintAllRecords\n");
    }
    if (start == NULL || start->accountno == 0)
    {
        printf("\nNo Record Found\n");
    }
    else
    {
        while (start != NULL && start->accountno != 0)
        {
            printf("\n%s\n", start->name);
            printf("%d\n", start->accountno);
            printf("%s\n", start->address);
            start = start->next;
        }
    }
}

/*****************************************************************
//  Function name: findRecord
//
//  DESCRIPTION:   This finds a record in the database.
// 
//  
//  
//  Parameters:    start (struct record *) : The address of the
//                                           start of the list
//                 no (int) : The account number.
//
//
//  Return values:  1 : success
//                 -1 : failure
//  
//  
****************************************************************/


int findRecord(struct record * start, int no)
{
    int returnval = -1;
    if (debugmode == 1)
    {
        printf("\nfindRecord\n");
        printf("no: %d\n", no);
    }

    if (start == NULL)
    {
        printf("\nstart is NULL!\n");
    }

    while (start != NULL)
    {
        if (start->accountno == no)
        {
            printf("\nName: %s\n", start->name);
            printf("Account number: %d\n", start->accountno);
            printf("Address: %s\n", start->address);
            if (returnval == -1)
            {
                returnval = 1;
            }
        }
        start = start->next;
    }

    if (returnval == -1)
    {
        printf("\nCould not find record\n");
    }
    return 0;

}

/*****************************************************************
//  Function name: deleteRecord
//  
//  DESCRIPTION:   This deletes a record in the database.
//  
//  
//  
//  Parameters:    start (struct record **) : The address of the
//                                            start of the list
//                 no (int) : The account number.
//                 
//
//  
//  Return values:  1 : success
//                 -1 : failure
//  
//  
****************************************************************/


int deleteRecord(struct record ** start, int no)
{
    struct record* temp;
    struct record* tempnext;
    int returnval = -1;
    if(debugmode == 1)
    {
        printf("Starting Delete");
    }
    temp = *start;
    if (temp == NULL)
    {
        printf("No records found");
    }
    else if (temp->accountno == no)
    {
        if (debugmode == 1)
        {
            printf("\nStart to be deleted\n");
        }
        while (temp->next != NULL && temp->next->accountno == no)
        {    
            tempnext = temp->next->next;
            free(temp->next);
            temp->next = tempnext;
            
        }
        free(*start);
        temp = NULL;
        *start = NULL;
        returnval = 1;
    }
    else if (temp->next != NULL && temp->next->accountno == no)
    {
        if (debugmode == 1) 
        {
            printf("\nDeleting from middle/end\n");
        }   
        while (temp->next != NULL && temp->next->accountno == no)
        {
            tempnext = temp->next->next;
            free(temp->next);
            temp->next = tempnext;

        }
        returnval = 1;
    }
    else
    {
        printf("\nCould not find record\n");
    }
    temp = NULL;
    tempnext = NULL;
    return returnval;

    

}



/*****************************************************************
//  Function name: writefile
//
//  DESCRIPTION:   This writes to a file
//
//
//
//  Parameters:    start (struct record *) : The address of the
//                                           start of the list
//                 file (char[]) : File to write to.
//
//
//
//  Return values:  0 : success
//                 -1 : failure
//
//
****************************************************************/

int writefile(struct record* start, char file[])
{
    FILE * write = fopen(file, "w");
    int returnval = 0;
    if (debugmode == 1)
    {
        printf("\nStarting writefile\n");
        printf("Opening File: %s\n", file);
    }
    returnval = 0;
    if (write != NULL)
    {
        if (start == NULL)
        {
            printf("No Record Found");
        }
        else
        {
            while (start != NULL)
            {
                fprintf(write, "%d", start->accountno);
                fprintf(write, "\n%s", start->name);
                fprintf(write, "\n%s", start->address);
                start = start->next;
            }
        }
        fclose(write);
    }
    else
    {
        printf("\nCould not open file\n");
        returnval = -1;
    }
    return returnval;

}

/*****************************************************************
//  Function name: readfile
//
//  DESCRIPTION:   This reads to a file
//
//
//
//  Parameters:    start (struct record **) : The address of the
//                                            start of the list
//                 file (char[]) : Name of file to read.
//
//
//
//  Return values:  0 : success
//                  -1 : failure
//
//
****************************************************************/

int readfile(struct record ** start, char file[])
{
    FILE * read = fopen(file, "r");
    struct record* temp;
    struct record* prevtemp;
    int returnval = 0;
    int toaddint;
    char toaddname[30];
    char toaddc;
    int prevc = 0;
    int endloop = 0;
    int i = 0;

    if (read != NULL)
    {
        temp = (struct record*)malloc(sizeof(struct record));
        if (temp != NULL && !feof(read))
        {
            fscanf(read, "%i", &toaddint);
            temp->accountno = toaddint;
            fgets(toaddname, 30, read);
            strcpy(temp->name, toaddname);
            temp->next = NULL;
            while (endloop == 0 && !feof(read))
            {
                if ((toaddc = fgetc(read)) == '\n' && prevc == '\n')
                {
                    endloop++;
                }
                else
                {
                    if (toaddc != EOF)
                    {
                        temp->address[i] = toaddc;
                        i++;
                    }

                }
            }
            *start = temp;
            prevtemp = *start;
        }
        
        while (temp != NULL && !feof(read))
        {
            i = 0;
            temp = (struct record*)malloc(sizeof(struct record));
            fscanf(read, "%i", &toaddint);
            temp->accountno = toaddint;
            fgets(toaddname, 30, read);
            strcpy(temp->name, toaddname);
            temp->next = prevtemp->next;
            while (endloop == 0 && !feof(read))
            {
                if ((toaddc = fgetc(read)) == '\n' && prevc == '\n')
                {
                    endloop++;
                }
                else
                {
                    if (toaddc != EOF)
                    {
                        temp->address[i] = toaddc;
                        i++;
                    }
                }
            }
            
            prevtemp->next = temp;
            prevtemp = temp;
        }
        
        fclose(read);
    }
    else
    {
        printf("\nCould not open file\n");
        returnval = -1;
    }
    return returnval;
}




/*****************************************************************
//  Function name: cleanup
//
//  DESCRIPTION:   Cleans up the heap memory.
//
//
//
//  Parameters:    start (struct record **) : Address of the start
//                                            of the linked list.
//                                              
//                 
//
//
//
//  Return values:  void
//
//
****************************************************************/

void cleanup(struct record** start)
{
    struct record* temp;
    struct record* tempnext;
    temp = *start;
    while (temp != NULL)
    {
        tempnext = temp->next;
        free(temp);
        temp = tempnext;
    }
    *start = NULL;
        
}



