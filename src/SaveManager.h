#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include "Player.h"
#include "InventoryManager.h"

/*
Author: Brenda Romero and Ashley G.
Course: CPSC-25-12703

Class: SaveManager

Description:
This class handles saving and loading game progress.
*/

class SaveManager
{
public:
    void saveGame(const Player& player, const InventoryManager& inventory);
    bool loadGame(Player& player, InventoryManager& inventory);
};

#endif