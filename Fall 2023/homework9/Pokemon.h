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
//  FILE:        Pokemon.h
//
//  DESCRIPTION:
//   header for Pokemon.cpp
//
****************************************************************/
#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

class Pokemon {
protected:
    std::string type;
    float weight;

public:
    Pokemon();
    virtual ~Pokemon();
    virtual void printData();
};

#endif // POKEMON_H
