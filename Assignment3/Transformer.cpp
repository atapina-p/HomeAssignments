/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 3
*/

#include "Transformer.h"
#include "PrimaryWeapon.h"
#include "SparkCore.h"


Transformer::Transformer(std::string name, int health, int energy, bool isTransformed, PrimaryWeapon* weapon): 
    _name(name),
    _health(health),
    _energy(energy),
    _isTransformed(isTransformed),
    _weapon(weapon),
    _robotSpark("undefined"){};

Transformer::Transformer(std::string name, int health, int energy, bool isTransformed): 
    _name(name),
    _health(health),
    _energy(energy),
    _isTransformed(isTransformed),
    _weapon(new PrimaryWeapon(30)),
    _robotSpark("undefined"){};

Transformer::Transformer(std::string name, int health, int energy): 
    _name(name),
    _health(health),
    _energy(energy),
    _isTransformed(false),
    _weapon(new PrimaryWeapon(30)),
    _robotSpark("undefined"){};

Transformer::Transformer(std::string name, int health): 
    _name(name),
    _health(health),
    _energy(100),
    _isTransformed(false),
    _weapon(new PrimaryWeapon(30)),
    _robotSpark("undefined"){};

Transformer::Transformer(std::string name): 
    _name(name),
    _health(50),
    _energy(100),
    _isTransformed(false),
    _weapon(new PrimaryWeapon(30)),
    _robotSpark("undefined"){};
Transformer::~Transformer(){};


std::ostream& operator<<(std::ostream& os, Transformer& transformer)
{
    os<<"Transformer " << transformer.getName() << "\n"
    << "Health: " << transformer.getHealth() << "\n"
    << "Energy: " << transformer.getEnergy() << "\n"
    << "Transform status: " << transformer.getIsTransformed() << "\n"
    << "Weapon: " << transformer.getWeaponInfo()->getDamageInfo() << "\n"
    << "Spark core: " << transformer.getStatusSpark() << "\n";
    return os;
}

void Transformer::fire(){
    std::cout << "method 'fire' from Transformer\n";
}

void Transformer::scream(){
    std::cout << "method 'scream' from Transformer\n";
}

void Transformer::speak(){
    std::cout << "method 'speak' from Transformer\n";
}

//methods
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
PrimaryWeapon* Transformer::getWeaponInfo(){
    return _weapon;
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
void Transformer::setWeapon(PrimaryWeapon* weapon){
    _weapon = weapon;
}
void Transformer::setStatusSpark(std::string newSpark){
    _robotSpark.changeStatus(newSpark);
}
