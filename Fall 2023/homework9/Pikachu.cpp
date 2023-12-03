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
//  FILE:        Pikachu.cpp
//
//  DESCRIPTION:
//   child class of Pokemon for Pikachu
//
****************************************************************/
#include "Pikachu.h"

/*****************************************************************
//
//  Function name: Pikachu()
//
//  DESCRIPTION:   Creates an instance of Pikachu, Constructor       
//
****************************************************************/
Pikachu::Pikachu() : Pokemon() {
    type = "Electric";
    weight = 6.0f;
    std::cout << "Pikachu Constructor\n";
}

/*****************************************************************
//
//  Function name: ~Pikachu()
//
//  DESCRIPTION:   Removes an instance of Pikachu, Destructor
//
****************************************************************/
Pikachu::~Pikachu() {
    std::cout << "Pikachu Destructor\n";
}

/*****************************************************************
//
//  Function name: printData()
//
//  DESCRIPTION:   Prints Pikachu's data
//
****************************************************************/
void Pikachu::printData() {
    std::cout << "Pikachu - Type: " << type << ", Weight: " << weight << " kg\n";
}
