/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 3
*/

#ifndef WARRIOR
#define WARRIOR
#include <string>
#include <iostream>
#include "Transformer.h"

class Warrior: public Transformer {
    public:
        Warrior(std::string name, int health, int energy, bool isTransformed, PrimaryWeapon* weapon, int armor, int rage);

        friend std::ostream& operator<<(std::ostream& os, Warrior& warrior);

        void furiousStrike();

        // Getters
        int getArmor();
        int getRage();
        // Setters
        void setArmor(int newArmor);
        void setRage(int newRage);
    private:
        int _armor;
        int _rage;
};
#endif