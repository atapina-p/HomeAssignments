/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 3
*/

#include "Transformer.h"
#include "Warrior.h"

Warrior::Warrior(std::string name, int health, int energy, bool isTransformed, 
    PrimaryWeapon* weapon, int armor, int rage):
    Transformer(name, health, energy, isTransformed, weapon), _armor(armor), _rage(rage){};

Warrior::Warrior(std::string name, int health, int energy, bool isTransformed, 
    PrimaryWeapon* weapon, int armor):
    Transformer(name, health, energy, isTransformed, weapon), _armor(armor), _rage(5){};

Warrior::Warrior(std::string name, int health, int energy, bool isTransformed, 
    PrimaryWeapon* weapon):
    Transformer(name, health, energy, isTransformed, weapon), _armor(80), _rage(5){};

Warrior::Warrior(std::string name, int health, int energy, bool isTransformed):
    Transformer(name, health, energy, isTransformed), _armor(80), _rage(5){};

Warrior::Warrior(std::string name, int health, int energy):
    Transformer(name, health, energy), _armor(80), _rage(5){};

Warrior::Warrior(std::string name, int health):
    Transformer(name, health), _armor(80), _rage(5){};

Warrior::Warrior(std::string name):
    Transformer(name), _armor(80), _rage(5){};

std::ostream& operator<<(std::ostream& os, Warrior& warrior)
{
    os << "Warrior " << warrior.getName() << "\n"
    << "Health: " << warrior.getHealth() << "\n"
    << "Energy: " << warrior.getEnergy() << "\n"
    << "Transform status: " << warrior.getIsTransformed() << "\n"
    << "Weapon: " << warrior.getWeaponInfo()->getDamageInfo() << "\n"
    << "Spark core: " << warrior.getStatusSpark() << "\n"
    << "Armor: " << warrior.getArmor() << "\n"
    << "Rage: " << warrior.getRage() << "\n";
    return os; 
}


void Warrior::fire(){
    std::cout << "method 'fire' from Warrior\n";
}
void Warrior::speak(){
    std::cout << "method 'speak' from Warrior\n";
}
void Warrior::scream(){
    std::cout << "method 'scream' from Warrior\n";
}

//methods
void Warrior::furiousStrike(){
    std::cout << _rage*getEnergy() << "\n";
}


// Getters
int Warrior::getArmor(){
    return _armor;
}
int Warrior::getRage(){
    return _rage;
}


// Setters
void Warrior::setArmor(int newArmor){
    _armor = newArmor;
}
void Warrior::setRage(int newRage){
    _rage = newRage;
}

