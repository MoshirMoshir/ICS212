/*****************************************************************
//
//  NAME:        Micah Schoefield
//
//  HOMEWORK:    5
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 8, 2022
//
//  FILE:        iofunctions.c
//
//  DESCRIPTION: This is a file of the definitions of the writefile
//               and readfile functions.
//               
//               
//               
//   
//
****************************************************************/
#include <stdio.h>
#include "pokemon.h"
#include "iofunctions.h"
/*****************************************************************
//
//  Function name:  writefile
//
//  DESCRIPTION:    This function writes from the array to the file
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


int writefile(struct pokemon pokearray[], int num, char filename[ ])
{
    FILE * write = fopen(filename, "w");
    int returnval = 0;
    int i = 0;

    if (write != NULL)
    {
        while(i < num)
        {
            fprintf(write, "%d\n", pokearray[i].level);
            fprintf(write, "%s\n", pokearray[i].name);
            i++;
        }
        fclose(write);
    }
    else
    {
        printf("Could not open %s\n", filename);
        returnval = -1;
    }

    return returnval;
}


/*****************************************************************
//  Function name: readfile
//
//  DESCRIPTION:    This function reads from the file to the array
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


int readfile(struct pokemon pokearray[], int* num, char filename[ ])
{
    FILE * read = fopen(filename, "r");
    int returnval = 0;
    int i = 0;
    int len = *num;
  
    if (read != NULL)
    {
        *num = 0;
        while ( !feof(read) && i < len)
        {
            fscanf(read, "%d", &pokearray[i].level);
            printf("%d\n", pokearray[i].level);
            fscanf(read, "%s", pokearray[i].name);
            printf("%s\n", pokearray[i].name); 
            i++;   
        }
        *num = i;
        fclose(read);
    }
    else
    {
        printf("Could not open %s\n", filename);
        returnval = -1;
    }
    
    return returnval;
    
}






