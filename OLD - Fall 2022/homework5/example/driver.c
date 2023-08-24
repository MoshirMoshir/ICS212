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
//  FILE:        driver.c
//
//  DESCRIPTION: This program will test iofunctions
//               
//              
//           
//   
//
****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pokemon.h"
#include "iofunctions.h"

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   This is takes user input and uses that data to write
//                 and read data to a file
//                 
//                 
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

int main (int argc, char* argv[])
{
    struct pokemon pokemonbank[5];
    int numpokemons;
    char file[30];
    char str[30];
    char suffix[2];
    int i = 0;
    printf("\nEnter a number of pokemon to add(max=4): ");
    numpokemons = atoi(fgets(str, 30, stdin));
    while (numpokemons > 4 || numpokemons < 1)
    {
        printf("\nEnter positive number less than 5: ");
        numpokemons = atoi(fgets(str, 30, stdin));
    }
    while (i < numpokemons)
    {
        if (i == 0)
        {
            strcpy(suffix, "st");    
        }
        else if (i == 1)
        {
            strcpy(suffix, "nd");   
        }
        else if (i == 2)
        {
            strcpy(suffix, "rd");   
        }
        else
        {
            strcpy(suffix, "th");    
        }

        printf("\nEnter level of %d%s pokemon: ", i + 1, suffix);
        fgets(str, 30, stdin);
        while ((pokemonbank[i].level = atoi(str)) <= 0)
        {
            printf("\nEnter positive number!");
            fgets(str, 30, stdin);
        }
        printf("\nEnter name of %d%s pokemon: ", i + 1, suffix);
        scanf("%s", pokemonbank[i].name);
        getchar();
        i++;
    }
    printf("\nEnter file to access: ");
    scanf("%s", file);
    getchar();

    printf("Writing to %s\n", file);
    writefile(pokemonbank, numpokemons, file);
    printf("Reading from %s\n", file);
    readfile(pokemonbank, &numpokemons, file);

    return 0;

}
