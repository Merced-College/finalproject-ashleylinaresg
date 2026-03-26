/* 
Author: Ashley Linares Garcia
Class: Player
*/
#include <iostream>
#include "Player.h"
using namespace std;

// Default player starts with a basic name, 100 health, and 0 score
Player::Player() : name("Player"), health(100), score(0) {}

// Custom constructor
Player::Player(string name, int health) : name(name), health(health), score(0) {}

// Change the player's name
void Player::setName(const string& newName) {
    name = newName;
}

// Return the player's name
string Player::getName() const {
    return name;
}

// Return the player's current health
int Player::getHealth() const {
    return health;
}

// Return the player's current score
int Player::getScore() const {
    return score;
}

// Subtract damage from the player's health
void Player::takeDamage(int damage) {
    health -= damage;

    // Prevent health from going below 0
    if (health < 0) {
        health = 0;
    }
}

// Heal the player by a certain amount
void Player::heal(int amount) {
    health += amount;
    if (health > 100) { //assuming max health is 100
        health =100;
    }
}

// Add an item to the player's inventory
void Player::addItem(const string& item) {
    inventory.push_back(item);
}

// Check if the player already has an item
bool Player::hasItem(const string& item) const {
    for (const auto& currentItem : inventory) {
        if (currentItem == item) {
            return true;
        }
    }
    return false;
}

// Show all items currently in the inventory
void Player::showInventory() const {
    cout << "\nInventory:\n";

    if (inventory.empty()) {
        cout << "Your inventory is empty.\n";
        return;
    }

    for (const auto& item : inventory) {
        cout << "- " << item << endl;
    }
}

// Add points to the player's score
void Player::addScore(int points) {
    score += points;
}