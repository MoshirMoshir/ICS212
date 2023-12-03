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
//  FILE:        llist.h
//
//  DESCRIPTION:
//   reference file for functions in llist.cpp
//
****************************************************************/
#include "record.h"
class llist
{
    private:
        record *    start;
        char        filename[20];
        void        cleanup();

    public:
        llist();
        llist(char[]);
        ~llist();
        int         readfile(char[]);
        int         writefile(char[]);
        int addRecord(int, char [ ],char [ ]);
        int findRecord(int);
        void printAllRecords();
        int deleteRecord(int);
};