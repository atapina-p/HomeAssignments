#include "Transformer.h"
#include "AerialBot.h"

AerialBot::AerialBot(std::string name, int health, int energy, bool isTransformed, 
    PrimaryWeapon weapon, int flightSpeed, int altitude):
    Transformer(name, health, energy, isTransformed, weapon),
    _flightSpeed(flightSpeed),
    _altitude(altitude){};


void AerialBot::evasiveManeuvers(){
    _flightSpeed += 10;
    std::cout << "Now flight speed is " << _flightSpeed << std::endl;
}

void AerialBot::bombard(){
    std::cout << "Booom!" << std::endl;
}


// Getters
int AerialBot::getFlightSpeed(){
    return _flightSpeed;
}
int AerialBot::getAltitude(){
    return _altitude;
}


// Setters
void AerialBot::setFlightSpeed(int newFlightSpeed){
    _flightSpeed = newFlightSpeed;
}
void AerialBot::setAltitude(int newAltitude){
    _altitude = newAltitude;
}

