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
//  FILE:        driver.c
//
//  DESCRIPTION: This program tests read and write functions in iofunctions
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
//  DESCRIPTION:   Tests possible data to writefile and readfile          
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : success
//                 
****************************************************************/

int main (int argc, char* argv[])
{
    struct pokemon pokearray[5];
    int num;
    
    char file[30] = "test.txt";
    int i = 0;
    
    /* Test 1 */
    printf("Test 1: Write and Read 2 pokemon to file\n");
    num = 2;

    printf("Pokemon 1: Magikarp, Level 1\n");
    pokearray[0].level = 1;
    strcpy(pokearray[0].name, "Magikarp");
    
    printf("Pokemon 2: Ralts, Level 99\n");
    pokearray[1].level = 99;
    strcpy(pokearray[1].name, "Ralts");

    printf("Writing to %s\n", file);
    writefile(pokearray, num, file);

    printf("Reading from %s\n", file);
    readfile(pokearray, &num, file);

    /* Test 2 */
    printf("\nTest 2: Write and Read 4 pokemon to file (should overwrite Test 1\n");
    num = 4;

    printf("Pokemon 1: Gardevior, Level 100\n");
    pokearray[0].level = 100;
    strcpy(pokearray[0].name, "Gardevior");

    printf("Pokemon 2: Magikarp, Level 99\n");
    pokearray[1].level = 99;
    strcpy(pokearray[1].name, "Magikarp");

    printf("Pokemon 3: Pichu, Level 5\n");
    pokearray[2].level = 5;
    strcpy(pokearray[2].name, "Pichu");

    printf("Pokemon 4: Pikachu, Level 50\n");
    pokearray[3].level = 50;
    strcpy(pokearray[3].name, "Pikachu");

    printf("Writing to %s\n", file);
    writefile(pokearray, num, file);

    printf("Reading from %s\n", file);
    readfile(pokearray, &num, file);

        /* Test 3 */
    printf("Test 3: Repeat Test 1 (should overwrite Test 2)\n");
    num = 2;

    printf("Pokemon 1: Magikarp, Level 1\n");
    pokearray[0].level = 1;
    strcpy(pokearray[0].name, "Magikarp");
    
    printf("Pokemon 2: Ralts, Level 99\n");
    pokearray[1].level = 99;
    strcpy(pokearray[1].name, "Ralts");

    printf("Writing to %s\n", file);
    writefile(pokearray, num, file);

    printf("Reading from %s\n", file);
    readfile(pokearray, &num, file);

    return 0;

}
