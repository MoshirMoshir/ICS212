
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
//   reference file for the struct record
//
****************************************************************/
struct record
{
    int                accountno;
    char               name[30];
    char               address[50];
    struct record*     next;
};