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
//  FILE:        Gardevoir.cpp
//
//  DESCRIPTION:
//   child class of Pokemon for Gardevoir
//
****************************************************************/
#include "Gardevoir.h"

/*****************************************************************
//
//  Function name: Gardevoir()
//
//  DESCRIPTION:   Creates an instance of Gardevoir, Constructor       
//
****************************************************************/
Gardevoir::Gardevoir() : Pokemon() {
    type = "Psychic, Fairy";
    weight = 48.4f;
    std::cout << "Gardevoir Constructor\n";
}

/*****************************************************************
//
//  Function name: ~Gardevoir()
//
//  DESCRIPTION:   Removes an instance of Gardevoir, Destructor
//
****************************************************************/
Gardevoir::~Gardevoir() {
    std::cout << "Gardevoir Destructor\n";
}

/*****************************************************************
//
//  Function name: printData()
//
//  DESCRIPTION:   Prints Gardevoir's data
//
****************************************************************/
void Gardevoir::printData() {
    std::cout << "Gardevoir - Type: " << type << ", Weight: " << weight << " kg\n";
}
