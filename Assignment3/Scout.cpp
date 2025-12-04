/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 3
*/

#include "Transformer.h"
#include "Scout.h"

//Constructor
Scout::Scout(std::string name, int health, int energy, bool isTransformed, 
    PrimaryWeapon* weapon, int speed, int cloakLevel, int scanRange):
    Transformer(name, health, energy, isTransformed, weapon), _speed(speed), _cloakLevel(cloakLevel), _scanRange(scanRange){};

Scout::Scout(std::string name, int health, int energy, bool isTransformed, 
    PrimaryWeapon* weapon, int speed, int cloakLevel):
    Transformer(name, health, energy, isTransformed, weapon), _speed(speed), _cloakLevel(cloakLevel), _scanRange(30){};

Scout::Scout(std::string name, int health, int energy, bool isTransformed, 
    PrimaryWeapon* weapon, int speed):
    Transformer(name, health, energy, isTransformed, weapon), _speed(speed), _cloakLevel(5), _scanRange(30){};

Scout::Scout(std::string name, int health, int energy, bool isTransformed, 
    PrimaryWeapon* weapon):
    Transformer(name, health, energy, isTransformed, weapon), _speed(85), _cloakLevel(5), _scanRange(30){};

Scout::Scout(std::string name, int health, int energy, bool isTransformed):
    Transformer(name, health, energy, isTransformed), _speed(85), _cloakLevel(5), _scanRange(30){};

Scout::Scout(std::string name, int health, int energy):
    Transformer(name, health, energy), _speed(85), _cloakLevel(5), _scanRange(30){};

Scout::Scout(std::string name, int health):
    Transformer(name, health), _speed(85), _cloakLevel(5), _scanRange(30){};

Scout::Scout(std::string name):
    Transformer(name), _speed(85), _cloakLevel(5), _scanRange(30){};

std::ostream& operator<<(std::ostream& os, Scout& scout)
{
    os << "Scout " << scout.getName() << "\n"
    << "Health: " << scout.getHealth() << "\n"
    << "Energy: " << scout.getEnergy() << "\n"
    << "Transform status: " << scout.getIsTransformed() << "\n"
    << "Weapon: " << scout.getWeaponInfo()->getDamageInfo() << "\n"
    << "Spark core: " << scout.getStatusSpark() << "\n"
    << "Speed: " << scout.getSpeed() << "\n"
    << "Cloak level: " << scout.getCloakLevel() << "\n"
    << "Scan range: " << scout.getScanRange() << "\n";
    return os;
}


bool Scout::fire(){
    std::cout << "method 'fire' from Scout\n";
    return true;
}
bool Scout::speak(){
    std::cout << "method 'speak' from Scout\n";
    return true;
}
bool Scout::scream(){
    std::cout << "method 'scream' from Scout\n";
    return true;
}


void Scout::cloak(){
    if (getEnergy() > 0) std::cout << getName() << " disguised for " << _cloakLevel << " level\n";
    else std::cout << getName() << " is exhausted, didn't disguise\n";
}

void Scout::scanArea(){
    std::cout << "Scaned " << abs(3*_scanRange*_scanRange) << " miles\n";
}

// Getters
int Scout::getSpeed(){
    return _speed;
}
int Scout::getCloakLevel(){
    return _cloakLevel;
}
int Scout::getScanRange(){
    return _scanRange;
}

// Setters
void Scout::setSpeed(int newSpeed){
    _speed = newSpeed;
}
void Scout::setCloakLevel(int newCloakLevel){
    _cloakLevel = newCloakLevel;
}
void Scout::setScanRange(int newScanRange){
    _scanRange = newScanRange;
}

