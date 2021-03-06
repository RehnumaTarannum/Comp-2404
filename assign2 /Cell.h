/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Brig.cc
 *   Purpose:   Assignment 2 , Comp 2404
 *   Author:    Rehnuma Tarannum, Abdul Bin Asif Niazi
 *   Date:      Feb 24 2015
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "PArray.h"

class Cell 
{
  public:
    Cell(int=MAX_CELL_SPACE);
    bool    fits(Pirate*);
    PArray& getPirates();
    int     getSpace();
    void    reduceSpace(int);
    void    increaseSpace(int);
  private:
    static int  nextId;
    int         cellNumber;
    int         spaceRemaining;
    PArray      pirates;
};

#endif

