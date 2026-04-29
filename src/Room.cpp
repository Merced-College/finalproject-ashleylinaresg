/*
Author: Brenda Romero and Ashley G.
Course: CPSC-25-12703

File: Room.cpp

Description:
This file defines the functions from the Room class.
Rooms are loaded from rooms.csv and used as the places the player explores.
*/

#include "Room.h"

// Default room in case no room information is given
Room::Room()
{
    name = "Unknown";
    description = "No description.";
    item = "Nothing";
}

// Creates a room with a name, description, actions, and item
Room::Room(string name, string description, vector<string> actions, string item)
{
    this->name = name;
    this->description = description;
    this->actions = actions;
    this->item = item;
}

// Returns the room name
string Room::getName() const
{
    return name;
}

// Returns the room description
string Room::getDescription() const
{
    return description;
}

// Returns the list of actions for the room
vector<string> Room::getActions() const
{
    return actions;
}

// Returns the item found in the room
string Room::getItem() const
{
    return item;
}

// Makes a clean text version of the room information
string Room::toString() const
{
    string text = "Room: " + name + "\n";
    text += "Description: " + description + "\n";
    text += "Actions:\n";

    for (int i = 0; i < actions.size(); i++)
    {
        text += "- " + actions[i] + "\n";
    }

    text += "Item: " + item + "\n";

    return text;
}