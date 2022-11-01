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
//  DATE:        September 10, 2022
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
//  Parameters:    account (struct record **) : The address of the
//                                              account
//                 no (int) : The account number.
//                 name (name*) : The name of the account holder
//                 address (char*) : The address of the account holder
//                                  
//
//  Return values:  void
//                 
//
****************************************************************/

void addRecord(struct record ** account, int no, char name[], char address[])
{
    if (debugmode == 1)
    {
        printf("\naddRecord\n");
        printf("no: %d\n", no);
        printf("name[]: %s\n", name);
        printf("address[]: %s\n", address);
    }
}

/*****************************************************************
//  Function name: printAllRecord
//
//  DESCRIPTION:   This prints all records in the database.
//  
// 
//  
//  Parameters:    accounts (struct record *) : The address of the
//                                              account array.
//                                             
//
//  Return values:  void
//
//
****************************************************************/


void printAllRecords(struct record * accounts)
{
    if (debugmode == 1)
    {
        printf("\nprintAllRecords\n");
    }
}

/*****************************************************************
//  Function name: findRecord
//
//  DESCRIPTION:   This finds a record in the database.
// 
//  
//  
//  Parameters:    accounts (struct record *) : The address of the
//                                              account array
//                 no (int) : The account number.
//
//
//  Return values:  0 : success
//  
//  
****************************************************************/


int findRecord(struct record * accounts, int no)
{
    if (debugmode == 1)
    {
        printf("\nfindRecord\n");
        printf("no: %d\n", no);
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
//  Parameters:    account (struct record **) : The address of the
//                                              account
//                 no (int) : The account number.
//                 
//
//  
//  Return values:  0 : success
//  
//  
****************************************************************/


int deleteRecord(struct record ** account, int no)
{
    if (debugmode == 1)
    {
        printf("\ndeleteRecord\n");
        printf("no: %d\n", no);
    }
    return 0;

}
