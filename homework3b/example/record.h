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
//  FILE:        record.h
//
//  DESCRIPTION: This program will print out all the numbers from
//               0 to the number the user inputs and says whether
//               or not the number is a multiple of 4.
//   
//
****************************************************************/


/*****************************************************************
//
//  Structure name: record
//
//  DESCRIPTION:    This structure does
//                 
//               
//
//  Parameters:     argc (int) : The number of elements in argv
//                  argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : success
//                 
//
****************************************************************/

struct record
{
    int accountno;
    char name[30];
    char address[60];
    struct record* next;
};
