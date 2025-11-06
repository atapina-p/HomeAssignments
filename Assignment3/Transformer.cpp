#include "Transformer.h"
#include "PrimaryWeapon.h"
#include "SparkCore.h"


Transformer::Transformer(std::string name, int health, int energy, bool isTransformed, PrimaryWeapon weapon): 
    _name(name),
    _health(health),
    _energy(energy),
    _isTransformed(isTransformed),
    _weapon(weapon),
    _robotSpark("undefined"){};

Transformer::~Transformer(){};


void Transformer::fight(){
    if (_energy >= 10) _energy -= 10;
}
void Transformer::transform(){
    if (_isTransformed) _isTransformed = false;
    else _isTransformed = true;
}


// getters
std::string Transformer::getName(){
    return _name;
}
int Transformer::getHealth(){
    return _health;
}
int Transformer::getEnergy(){
    return _energy;
}
bool Transformer::getIsTransformed(){
    return _isTransformed;
}
int Transformer::getWeaponInfo(){
    return _weapon.getDamageInfo();
}
std::string Transformer::getStatusSpark(){
    return _robotSpark.getStatus();
}


// setters
void Transformer::setName(const std::string newName){
    _name = newName;
}
void Transformer::setHealth(int newHealth){
    _health = newHealth;
}
void Transformer::setEnergy(int newEnergy){
    _energy = newEnergy;
}
void Transformer::setIsTransformed(bool newTransformed){
    _isTransformed = newTransformed;
}
void Transformer::setWeapon(int weaponDamage){
    _weapon.changeDamage(weaponDamage);
}
void Transformer::setStatusSpark(std::string newSpark){
    _robotSpark.changeStatus(newSpark);
}
