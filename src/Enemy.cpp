/*
Author: Ashley G.
Course: CPSC-25-12703

File: Enemy.cpp

Description:
This file defines the functions from the Enemy class.
Enemies are used in the battle system and can attack the player.
*/

#include "Enemy.h"

// Default enemy starts with simple values
Enemy::Enemy()
{
    name = "Unknown Enemy";
    health = 0;
    damage = 0;
    defeated = false;
}

// Creates an enemy with custom stats
Enemy::Enemy(string name, int health, int damage)
{
    this->name = name;
    this->health = health;
    this->damage = damage;
    defeated = false;
}

// Returns the enemy's name
string Enemy::getName() const
{
    return name;
}

// Returns the enemy's current health
int Enemy::getHealth() const
{
    return health;
}

// Returns how much damage the enemy does
int Enemy::getDamage() const
{
    return damage;
}

// Tells us if the enemy has already been defeated
bool Enemy::isDefeated() const
{
    return defeated;
}

// Lowers enemy health when the player attacks
void Enemy::takeDamage(int amount)
{
    health -= amount;

    // If health reaches 0, the enemy is defeated
    if (health <= 0)
    {
        health = 0;
        defeated = true;
    }
}

// Returns the enemy damage amount
int Enemy::attack() const
{
    return damage;
}