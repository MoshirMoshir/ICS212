/*****************************************************************
//
//  NAME:        Alexander Moshir
//
//  HOMEWORK:    homework9
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        December 02, 2023
//
//  FILE:        main.cpp
//
//  DESCRIPTION:
//   Runs the main program for homework9
//   runs a pokedex and prints out the data for three pokemon
//
****************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include "Pikachu.h"
#include "Gardevoir.h"
#include "Dragapult.h"

/*****************************************************************
//
//  Function name: checkPokedex()
//
//  DESCRIPTION:   Prints the pokemon in Pokedex      
//
//  Parameters:    pokemon (Pokemon*) : Pokemon in pokedex        
//
****************************************************************/
void checkPokedex(Pokemon* pokemon) {
    pokemon->printData();
}

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Creates the child classes of Pokemon and prints the Pokedex     
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : success           
//
****************************************************************/
int main(int argc, char* argv[]) {
    Pokemon* pikachu = new Pikachu();
    Pokemon* gardevoir = new Gardevoir();
    Pokemon* dragapult = new Dragapult();

    std::string pikachuNickname = "Pika";
    std::string gardevoirNickname = "Trap";
    std::string dragapultNickname = "Lizard";

    std::vector<std::string> nicknames;
    nicknames.push_back(pikachuNickname);
    nicknames.push_back(gardevoirNickname);
    nicknames.push_back(dragapultNickname);

    std::map<std::string, Pokemon*> pokedex;

    pokedex[pikachuNickname] = pikachu;
    pokedex[gardevoirNickname] = gardevoir;
    pokedex[dragapultNickname] = dragapult;

    std::cout << "Checking Pokedex:\n";
    std::vector<std::string>::iterator nicknameIt = nicknames.begin();
    for (; nicknameIt != nicknames.end(); ++nicknameIt) {
        std::cout << "Nickname: " << *nicknameIt << "\n";
        checkPokedex(pokedex[*nicknameIt]);
        std::cout << "----------------------\n";
    }

    delete pikachu;
    delete gardevoir;
    delete dragapult;

    return 0;
}
