#include <stdio.h>
#include "database.h"
extern int debugmode;

void addRecord (struct record **r, int a, char b[], char c[]) 
{
    if (debugmode == 1)
    {
        printf("\naddRecord(%d, %d, %s, %s)\n", r, a, b, c);
    }
}

void printAllRecords(struct record *r) 
{
    if (debugmode == 1)
    {
        printf("\nprintAllRecords(%d)\n", r);
    }
}

int findRecord (struct record *r, int a) 
{
    if (debugmode == 1)
    {
        printf("\nfindRecord(%d, %d)\n", r, a);
    }
}

int deleteRecord(struct record **r, int a) 
{
    if (debugmode == 1)
    {
        printf("\ndeleteRecord(%d, %d)\n", r, a);
    }
}