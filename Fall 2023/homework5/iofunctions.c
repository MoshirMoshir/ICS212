/*****************************************************************
//
//  NAME:        Alexander Moshir
//
//  HOMEWORK:    5
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 7, 2023
//
//  FILE:        iofunctions.c
//
//  DESCRIPTION: Contains the functions writefile and readfile
//               
****************************************************************/

#include <stdio.h>
#include "pokemon.h"
#include "iofunctions.h"

/*****************************************************************
//
//  Function name:  writefile
//
//  DESCRIPTION:    This function writes from a input array to a file
//                 
//  Parameters:     struct pokemon pokearray[ ] : input array
//                  int num : amount of pokemon in array
//                  char filename[ ] : file to write to                         
//
//  Return values:  0 : success
//                 -1 : failure
//                 
****************************************************************/


int writefile(struct pokemon pokearray[ ], int num, char filename[ ])
{
    FILE * write = fopen(filename, "w");
    int success = -1;
    int i = 0;

    if (write != NULL)
    {
        for (i = 0; i < num; i++)
        {
            fprintf(write, "%d\n", pokearray[i].level);
            fprintf(write, "%s\n", pokearray[i].name);
        }
        fclose(write);
        success = 0;
    }
    else
    {
        printf("Error: File not found\n");
    }

    return success;
}


/*****************************************************************
//  Function name: readfile
//
//  DESCRIPTION:    This function reads from the file to the array
//
//
//
//  Parameters:     struct pokemon pokearray[ ] : array to read
//                  int* num : pointer to amount of pokemon in array
//                  char filename[ ] : file to read 
// 
//  Return values:  0 : success
//                 -1 : failure
//  
****************************************************************/


int readfile(struct pokemon pokearray[ ], int* num, char filename[ ])
{
    FILE * read = fopen(filename, "r");
    int success = -1;
    int i = 0;
    int length = *num;
  
    if (read != NULL)
    {
        *num = 0;
        while (!feof(read) && i < length)
        {
            fscanf(read, "%d", &pokearray[i].level);
            printf("%d\n", pokearray[i].level);
            fscanf(read, "%s", pokearray[i].name);
            printf("%s\n", pokearray[i].name); 
            i++;   
        }
        *num = i;
        fclose(read);
        success = 0;
    }
    else
    {
        printf("Error: File not found\n");
    }
    
    return success;
}






