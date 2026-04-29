/*
Author: Ashley Linares Garcia
Class: Enemy 
Description: Manages enemy stats, damage, and status for the RPG
*/
#ifndef ENEMY_H
#define ENEMY_H

#include <string>
using namespace std;
class Enemy
{
private:
    string name;
    int health;
    int damage;
    bool defeated;

public:
    // Default constructor
    Enemy();

    // Constructor that creates an enemy with a name, health, and damage
    Enemy(string name, int health, int damage);

    // Getters for enemy information
    string getName() const;
    int getHealth() const;
    int getDamage() const;
    bool isDefeated() const;

    // Battle functions
    void takeDamage(int amount);
    int attack() const;
};

#endif