
/*****************************************************************
//
//  NAME:        Alexander Moshir
//
//  HOMEWORK:    Project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 27, 2023
//
//  FILE:        record.h
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