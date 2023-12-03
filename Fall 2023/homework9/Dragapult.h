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
//  FILE:        Dragapult.h
//
//  DESCRIPTION:
//   header for Dragapult.cpp
//
****************************************************************/
#ifndef DRAGAPULT_H
#define DRAGAPULT_H

#include "Pokemon.h"

class Dragapult : public Pokemon {
public:
    Dragapult();
    virtual ~Dragapult();
    virtual void printData();
};

#endif // Dragapult_H
