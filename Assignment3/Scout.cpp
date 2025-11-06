#include "Transformer.h"
#include "Scout.h"

Scout::Scout(std::string name, int health, int energy, bool isTransformed, 
    PrimaryWeapon weapon, int speed, int cloakLevel, int scanRange):
    Transformer(name, health, energy, isTransformed, weapon),
    _speed(speed),
    _cloakLevel(cloakLevel),
    _scanRange(scanRange){};


void Scout::cloak(){
    if (getEnergy() > 0) std::cout << getName() << " disguised for " << _cloakLevel << " level" << std::endl;
    else std::cout << getName() << " is exhausted, didn't disguise" << std::endl;
}

void Scout::scanArea(){
    std::cout << "Scaned " << 3.14*_scanRange*_scanRange << " miles" << std::endl;
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

