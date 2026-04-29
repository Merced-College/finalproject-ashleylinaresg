/*
Author: Ashley G.
Course: CPSC-25-12703

File: GameMap.cpp

Description:
This file reads rooms.csv and builds the castle map.
Each line in the file becomes one room.
*/

#include "GameMap.h"
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

/*
Algorithm: CSV File Reading
Purpose:
Reads each line of the CSV file and creates rooms.

Time Complexity:
O(n), where n is the number of rooms.
*/

bool GameMap::loadRooms(string fileName, LinkedList& rooms)
{
    ifstream file(fileName);

    // If the file does not open, return false
    if (!file.is_open())
    {
        return false;
    }

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string name;
        string description;
        string actionsText;
        string item;

        getline(ss, name, ',');
        getline(ss, description, ',');
        getline(ss, actionsText, ',');
        getline(ss, item);

        vector<string> actions;
        stringstream actionStream(actionsText);
        string action;

        // Split actions using semicolons
        while (getline(actionStream, action, ';'))
        {
            actions.push_back(action);
        }

        Room newRoom(name, description, actions, item);
        rooms.addRoom(newRoom);
    }

    file.close();
    return true;
}