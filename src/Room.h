#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
using namespace std;

/*
Author: Brenda Romero and Ashley G.
Course: CPSC-25-12703

Class: Room

Description:
This class stores information for each room in the castle.
Each room has a name, description, list of actions, and an item.
*/

class Room
{
private:
    string name;
    string description;
    vector<string> actions;
    string item;

public:
    // Default constructor
    Room();

    // Constructor that lets us create a room from the CSV file
    Room(string name, string description, vector<string> actions, string item);

    // Getters for room information
    string getName() const;
    string getDescription() const;
    vector<string> getActions() const;
    string getItem() const;

    // Turns room information into readable text
    string toString() const;
};

#endif