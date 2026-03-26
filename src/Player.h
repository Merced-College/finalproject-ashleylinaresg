/* 
Author: Ashley Linares Garcia
Class: Player
Description: Manages the player stats, health, and inventory for the RPG
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Player {
private:
    string name;
    int health;
    vector<string> inventory;
    int score;

public:
    // Default constructor
    Player();

    // Constructor with player name and starting health
    Player(string name, int health);

    // Setters and getters
    void setName(const string& newName);
    string getName() const;
    int getHealth() const;
    int getScore() const;

    // Player actions
    void takeDamage(int damage);
    void heal(int amount);
    void addItem(const string& item);
    bool hasItem(const string& item) const;
    void showInventory() const;
    void addScore(int points);
};

#endif