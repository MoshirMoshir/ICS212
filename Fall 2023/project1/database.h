
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
//   reference file for functions in database.c
//
****************************************************************/
#include "record.h"
void addRecord(struct record **, int, char [ ], char [ ]);
void printAllRecords(struct record *);
int findRecord(struct record *, int);
int deleteRecord(struct record **, int);
int writefile(struct record *, char [ ]);
int readfile(struct record **, char [ ]);
void cleanup(struct record **);