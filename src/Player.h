/*
Author: Brenda Romero and Ashley G.
Course: CPSC-25-12703

File: Player.h
*/
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player {
private:
    std::string name;
    int health;
    int score;
    int x, y; // To track position on the GameMap
    std::vector<std::string> inventory;

public:
    // Constructor
    Player(std::string playerName = "Hero", int startingHealth = 100);

    // Getters and Setters
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    void setHealth(int h) { health = h; }

    // Game Actions
    void move(int dx, int dy);
    void takeDamage(int damage);
    void addItem(std::string item);
    void showStatus();

    // Check if player is still alive
    bool isAlive() const { return health > 0; }
};

#endif