#include "Pet.h"
#include <iostream>

using namespace std;

// Constructor
Pet::Pet(string name, string type, int bonusValue) 
    : name(name), type(type), bonusValue(bonusValue) {}

string Pet::getName() const { return name; }
string Pet::getType() const { return type; }
int Pet::getBonusValue() const { return bonusValue; }

void Pet::displayPetStats() const {
    cout << "Pet: " << name << " | Type: " << type 
         << " | Bonus: +" << bonusValue << endl;
}