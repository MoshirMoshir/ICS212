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
//  FILE:        Dragonpult.cpp
//
//  DESCRIPTION:
//   child class of Pokemon for Dragonpult
//
****************************************************************/
#include "Dragapult.h"

/*****************************************************************
//
//  Function name: Dragapult()
//
//  DESCRIPTION:   Creates an instance of Dragapult, Constructor       
//
****************************************************************/
Dragapult::Dragapult() : Pokemon() {
    type = "Dragon, Ghost";
    weight = 50.0f;
    std::cout << "Dragapult Constructor\n";
}

/*****************************************************************
//
//  Function name: ~Dragapult()
//
//  DESCRIPTION:   Removes an instance of Dragapult, Destructor
//
****************************************************************/
Dragapult::~Dragapult() {
    std::cout << "Dragapult Destructor\n";
}

/*****************************************************************
//
//  Function name: printData()
//
//  DESCRIPTION:   Prints Dragapult's data
//
****************************************************************/
void Dragapult::printData() {
    std::cout << "Dragapult - Type: " << type << ", Weight: " << weight << " kg\n";
}
