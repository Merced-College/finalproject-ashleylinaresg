/*
Author: Brenda Romero
Course: CPSC-25-12703

File: Player.cpp

Description:
This file defines the functions from the Player class.
The Player class keeps track of the player's name, health,
and score while they move through the castle.
*/

#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

// Creates a player with a custom name and health
Player::Player(string name, int health)
{
    this->name = name;
    this->health = health;
    this->score = 0; // Added this-> to be consistent
}

// Updates the player's name
void Player::setName(string name)
{
    this->name = name;
}

// Updates health and makes sure it does not go below 0
void Player::setHealth(int health)
{
    this->health = health;

    if (this->health < 0)
    {
        this->health = 0;
    }
}

// Updates score and makes sure it does not go below 0
void Player::setScore(int score)
{
    this->score = score;

    if (this->score < 0)
    {
        this->score = 0;
    }
}

// Returns the player's name
string Player::getName() const
{
    return name;
}

// Returns the player's current health
int Player::getHealth() const
{
    return health;
}

// Returns the player's current score
int Player::getScore() const
{
    return score;
}

// Subtracts health when the player takes damage
void Player::takeDamage(int damage)
{
    health -= damage;

    if (health < 0)
    {
        health = 0;
    }
}

// Adds health back to the player
void Player::heal(int amount)
{
    health += amount;

    // Keeps the player's health from going over 100
    if (health > 100)
    {
        health = 100;
    }
}

// Adds points to the player's score
void Player::addScore(int points)
{
    score += points;
}