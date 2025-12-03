/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 3
*/

#include "Transformer.h"
#include "AerialBot.h"

AerialBot::AerialBot(std::string name, int health, int energy, bool isTransformed, 
    PrimaryWeapon* weapon, int flightSpeed, int altitude):
    Transformer(name, health, energy, isTransformed, weapon),
    _flightSpeed(flightSpeed),
    _altitude(altitude){};


std::ostream& operator<<(std::ostream& os, AerialBot& bot)
{
    os << "Aerial bot " << bot.getName() << "\n"
    << "Health: " << bot.getHealth() << "\n"
    << "Energy: " << bot.getEnergy() << "\n"
    << "Transform status: " << bot.getIsTransformed() << "\n"
    << "Weapon: " << bot.getWeaponInfo()->getDamageInfo() << "\n"
    << "Spark core: " << bot.getStatusSpark() << "\n"
    << "Flight speed: " << bot.getFlightSpeed() << "\n"
    << "Altitude: " << bot.getAltitude() << "\n";
    return os;
}

void AerialBot::evasiveManeuvers(){
    _flightSpeed += 10;
    std::cout << "Now flight speed is " << _flightSpeed << "\n";
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

