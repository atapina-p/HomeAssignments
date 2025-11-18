/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 3
*/

#ifndef AERIALBOT
#define AERIALBOT
#include <string>
#include <iostream>
#include "Transformer.h"

class AerialBot: public Transformer {
    public:
        AerialBot(std::string name, int health, int energy, bool isTransformed, PrimaryWeapon* weapon, int flightSpeed, int altitude);

        void evasiveManeuvers();
        void bombard();

        // Getters
        int getFlightSpeed();
        int getAltitude();
        // Setters
        void setFlightSpeed(int newFlightSpeed);
        void setAltitude(int newAltitude);
    private:
        int _flightSpeed;
        int _altitude;

};
#endif