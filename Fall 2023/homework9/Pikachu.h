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
//  FILE:        Pikachu.h
//
//  DESCRIPTION:
//   header for Pikachu.cpp
//
****************************************************************/
#ifndef PIKACHU_H
#define PIKACHU_H

#include "Pokemon.h"

class Pikachu : public Pokemon {
public:
    Pikachu();
    virtual ~Pikachu();
    virtual void printData();
};

#endif // PIKACHU_H
