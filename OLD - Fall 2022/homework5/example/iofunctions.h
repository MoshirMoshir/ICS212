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
//  FILE:        iofunctions.h
//
//  DESCRIPTION: This is a header file for the prototypes of the
//               read and write files.
//               
//               
//   
//
****************************************************************/


/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:    This is a prototype for the writefile function
//                 
//               
//
//  Parameters:     pokearray[](struct pokemon) : array to write from
//                  num(int) : Amount of pokemon to write
//                  filename[](char) : File to write to
//                  
//                                  
//
//  Return values:  0 : success
//                  -1 : failure
//                 
//
****************************************************************/


int writefile(struct pokemon[], int, char[]);


/*****************************************************************
//  Function name: readfile
//
//  DESCRIPTION:    This is a prototype for the readfile function
//
//
//
//  Parameters:     pokearray[](struct pokemon) : array to put all read items
//                  num(int) : The amount of pokemon it has stored in the array
//                  filename[](char) : file to read from
//
// 
//  
//  Return values:  0 : success
//                  -1 : failure
//  
//  
****************************************************************/


int readfile(struct pokemon[], int*, char[]);




