#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include <string>
#include <vector>

using namespace std;

/*
Author: Brenda Romero
Course: CPSC-25-12703

Class: InventoryManager

Description:
This class controls the player's inventory.
It stores items and can add, remove, search,
display, and sort them.
*/

class InventoryManager
{
private:
    vector<string> items;

public:
    void addItem(string item);
    void removeItem(string item);
    bool hasItem(string item) const;
    void showInventory() const;
    void sortInventory();

    vector<string> getItems() const;
    void setItems(vector<string> newItems);
};

#endif