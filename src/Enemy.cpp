/*
Author: Ashley Linares Garcia
Class: Enemy
*/
#include "Enemy.h"

// Default enemy values
Enemy::Enemy() : name("Unknown Enemy"), health(0), damage(0), defeated(false) {}

// Custom constructor
Enemy::Enemy(string name, int health, int damage)
    : name(name), health(health), damage(damage), defeated(false) {}

// Return the enemy's name
string Enemy::getName() const {
    return name;
}

// Return the enemy's current health
int Enemy::getHealth() const {
    return health;
}

// Return the amount of damage the enemy can do
int Enemy::getDamage() const {
    return damage;
}

// Check if the enemy has been defeated
bool Enemy::isDefeated() const {
    return defeated;
}

// Reduce the enemy's health by a given amount
void Enemy::takeDamage(int amount) {
    health -= amount;

    // Prevent health from going below 0
    if (health < 0) {
        health = 0;
    }

    // If health reaches 0, mark enemy as defeated
    if (health == 0) {
        defeated = true;
    }
}

// Return how much damage the enemy does when attacking
int Enemy::attack() const {
    return damage;
}

// Manually change defeated status if needed
void Enemy::setDefeated(bool status) {
    defeated = status;
}