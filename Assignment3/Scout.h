/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 3
*/

#ifndef SCOUT
#define SCOUT
#include <string>
#include <iostream>
#include "Transformer.h"

class Scout: public Transformer {
    public:
        Scout(std::string name, int health, int energy, bool isTransformed, PrimaryWeapon* weapon, int speed, int cloakLevel, int scanRange);
        Scout(std::string name, int health, int energy, bool isTransformed, PrimaryWeapon* weapon, int speed, int cloakLevel);
        Scout(std::string name, int health, int energy, bool isTransformed, PrimaryWeapon* weapon, int speed);
        Scout(std::string name, int health, int energy, bool isTransformed, PrimaryWeapon* weapon);
        Scout(std::string name, int health, int energy, bool isTransformed);
        Scout(std::string name, int health, int energy);
        Scout(std::string name, int health);
        Scout(std::string name);
        
        friend std::ostream& operator<<(std::ostream& os, Scout& scout);

        bool fire() override;
        bool scream() override;
        bool speak() override;

        //methods
        void cloak();
        void scanArea();

        // Getters
        int getSpeed();
        int getCloakLevel();
        int getScanRange();
        // Setters
        void setSpeed(int newSpeed);
        void setCloakLevel(int newCloakLevel);
        void setScanRange(int newScanRange);
    private:
        int _speed;
        int _cloakLevel;
        int _scanRange;
};
#endif