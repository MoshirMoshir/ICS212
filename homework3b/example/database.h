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
//  FILE:        database.h
//
//  DESCRIPTION: This program will print out all the numbers from
//               0 to the number the user inputs and says whether
//               or not the number is a multiple of 4.
//   
//
****************************************************************/
#include "record.h"
/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   This is where all the functions that print gets
//                 called.
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

void addRecord(struct record **, int, char [ ],char [ ]);

void printAllRecords(struct record *);

int findRecord(struct record *, int);

int deleteRecord(struct record **, int);
