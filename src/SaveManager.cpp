/*
Author: Brenda Romero and Ashley G.
Course: CPSC-25-12703

File: SaveManager.cpp

Description:
This file saves and loads player progress using save.txt.
*/

#include "SaveManager.h"
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Saves player data into a file
void SaveManager::saveGame(const Player& player, const InventoryManager& inventory)
{
    ofstream file("save.txt");

    file << player.getName() << endl;
    file << player.getHealth() << endl;
    file << player.getScore() << endl;

    vector<string> items = inventory.getItems();

    for (int i = 0; i < items.size(); i++)
    {
        file << items[i];

        if (i < items.size() - 1)
        {
            file << ",";
        }
    }

    file << endl;
    file.close();
}

/*
Algorithm: File Parsing
Purpose:
Loads saved data and rebuilds the player.

Time Complexity:
O(n)
*/
bool SaveManager::loadGame(Player& player, InventoryManager& inventory)
{
    ifstream file("save.txt");

    if (!file.is_open())
    {
        return false;
    }

    string name;
    string healthText;
    string scoreText;
    string inventoryLine;

    getline(file, name);
    getline(file, healthText);
    getline(file, scoreText);
    getline(file, inventoryLine);

    player.setName(name);
    player.setHealth(stoi(healthText));
    player.setScore(stoi(scoreText));

    vector<string> loadedItems;
    stringstream ss(inventoryLine);
    string item;

    while (getline(ss, item, ','))
    {
        if (!item.empty())
        {
            loadedItems.push_back(item);
        }
    }

    inventory.setItems(loadedItems);

    file.close();
    return true;
}