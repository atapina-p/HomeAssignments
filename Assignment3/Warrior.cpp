/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 3
*/

#include "Transformer.h"
#include "Warrior.h"

Warrior::Warrior(std::string name, int health, int energy, bool isTransformed, 
    PrimaryWeapon* weapon, int armor, int rage):
    Transformer(name, health, energy, isTransformed, weapon),
    _armor(armor),
    _rage(rage){};


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

