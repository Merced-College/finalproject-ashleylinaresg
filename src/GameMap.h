#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <string>
#include "LinkedList.h"

using namespace std;

/*
Author: Ashley G.
Course: CPSC-25-12703

Class: GameMap

Description:
This class loads room data from the CSV file
and places the rooms into the linked list.
*/

class GameMap
{
public:
    bool loadRooms(string fileName, LinkedList& rooms);
};

#endif