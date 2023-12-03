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
//  FILE:        Pokemon.cpp
//
//  DESCRIPTION:
//   Parent class for Pokemons
//
****************************************************************/
#include "Pokemon.h"

/*****************************************************************
//
//  Function name: Pokemon()
//
//  DESCRIPTION:   Parent class for pokemon constructors      
//
****************************************************************/
Pokemon::Pokemon() {
    std::cout << "Pokemon Constructor\n";
}

/*****************************************************************
//
//  Function name: ~Pokemon()
//
//  DESCRIPTION:   Parent class for pokemon destructors
//
****************************************************************/
Pokemon::~Pokemon() {
    std::cout << "Pokemon Destructor\n";
}
