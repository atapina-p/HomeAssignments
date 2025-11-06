#ifndef TRANSFORMER
#define TRANSFORMER
#include <iostream>
#include <string>
#include "PrimaryWeapon.h"
#include "SparkCore.h"


class Transformer {
    public:
        Transformer(std::string name, int health, int energy, bool isTransformed, PrimaryWeapon weapon);
        ~Transformer();
        
        void transform();
        void fight();


        // Getters
        std::string getName();
        int getHealth();
        int getEnergy();
        bool getIsTransformed();
        int getWeaponInfo();
        std::string getStatusSpark();


        // Setters
        void setName(const std::string newName);
        void setHealth(int newHealth);
        void setEnergy(int newEnergy);
        void setIsTransformed(bool newTransformed);
        void setWeapon(int weaponDamage);
        void setStatusSpark(std::string newSpark);
        
    private:
        std::string _name;
        int _health;
        int _energy;
        bool _isTransformed;
        PrimaryWeapon _weapon; // association
        SparkCore _robotSpark; // composition
};


#endif
