/*
Author: Brenda Romero
Course: CPSC-25-12703

File: InventoryManager.cpp

Description:
This file controls inventory actions like adding items,
showing items, searching, and sorting.
*/

#include "InventoryManager.h"
#include <iostream>

using namespace std;

// Adds a new item to inventory
void InventoryManager::addItem(string item)
{
    items.push_back(item);
}

// Removes an item if found
void InventoryManager::removeItem(string item)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i] == item)
        {
            items.erase(items.begin() + i);
            return;
        }
    }
}

/*
Algorithm: Linear Search
Purpose:
Checks if an item exists in inventory.

Time Complexity:
O(n)
*/
bool InventoryManager::hasItem(string item) const
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i] == item)
        {
            return true;
        }
    }

    return false;
}

// Shows every item in inventory
void InventoryManager::showInventory() const
{
    cout << "\n===== INVENTORY =====\n";

    if (items.empty())
    {
        cout << "Inventory is empty.\n";
        return;
    }

    for (int i = 0; i < items.size(); i++)
    {
        cout << i + 1 << ". " << items[i] << endl;
    }
}

/*
Algorithm: Selection Sort
Purpose:
Sorts inventory items alphabetically.

Time Complexity:
O(n^2)
*/
void InventoryManager::sortInventory()
{
    for (int i = 0; i < items.size() - 1; i++)
    {
        int smallestIndex = i;

        for (int j = i + 1; j < items.size(); j++)
        {
            if (items[j] < items[smallestIndex])
            {
                smallestIndex = j;
            }
        }

        string temp = items[i];
        items[i] = items[smallestIndex];
        items[smallestIndex] = temp;
    }
}

// Returns all inventory items
vector<string> InventoryManager::getItems() const
{
    return items;
}

// Replaces inventory with loaded items
void InventoryManager::setItems(vector<string> newItems)
{
    items = newItems;
}