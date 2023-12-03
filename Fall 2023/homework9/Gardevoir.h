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
//  FILE:        Gardevoir.h
//
//  DESCRIPTION:
//   header for Gardevoir.cpp
//
****************************************************************/
#ifndef GARDEVOIR_H
#define GARDEVOIR_H

#include "Pokemon.h"

class Gardevoir : public Pokemon {
public:
    Gardevoir();
    virtual ~Gardevoir() override;
    virtual void printData() override;
};

#endif // GARDEVOIR_H
