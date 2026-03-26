/*
Author: Ashley Linares Garcia
Class: Enemy 
Description: Manages enemy stats, damage, and rewards for the RPG
*/
#ifndef ENEMY_H
#define ENEMY_H

#include <string>
using namespace std;

class Enemy {
private:
    string name;
    int health;
    int damage;
    bool defeated;
    string reward;

public:
    // Default constructor
    Enemy();

    // Constructor with enemy name, health, and damage
    Enemy(string name, int health, int damage);

    // Getters
    string getName() const;
    int getHealth() const;
    int getDamage() const;
    bool isDefeated() const;
    string getReward() const;

    // Enemy actions
    void takeDamage(int amount);
    int attack() const;
    void setDefeated(bool status);
};

#endif