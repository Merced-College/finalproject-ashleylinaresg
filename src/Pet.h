/*
Author: Ashley Linares Garcia
Class: Pet
Description: Represents a companion that provides passive bonuses to the player
*/

#ifndef PET_H
#define PET_H

#include <string>

class Pet {
private:
    std::string name;
    std::string type; // e.g., "Healing", "Attack", "Defense"
    int bonusValue;

public:
    // Constructor
    Pet(std::string name, std::string type, int bonusValue);

    // Getters
    std::string getName() const;
    std::string getType() const;
    int getBonusValue() const;

    // Logic
    void displayPetStats() const;
};

#endif