/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 3
*/

#include "Transformer.h"
#include "Warrior.h"

Warrior::Warrior(std::string name, int health, int energy, bool isTransformed, 
    PrimaryWeapon weapon, int armor, int rage):
    Transformer(name, health, energy, isTransformed, weapon),
    _armor(armor),
    _rage(rage){};


void Warrior::furiousStrike(){
    std::cout << _rage*getEnergy() << std::endl;
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

