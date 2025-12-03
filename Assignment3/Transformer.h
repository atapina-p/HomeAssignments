/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 3
*/

#ifndef TRANSFORMER
#define TRANSFORMER
#include <iostream>
#include <string>
#include "PrimaryWeapon.h"
#include "SparkCore.h"


class Transformer {

    friend class AerialBot;
    friend class Scout;
    friend class Warrior;

    public:
        Transformer(std::string name);
        Transformer(std::string name, int health);
        Transformer(std::string name, int health, int energy);
        Transformer(std::string name, int health, int energy, bool isTransformed);
        Transformer(std::string name, int health, int energy, bool isTransformed, PrimaryWeapon* weapon);
        virtual ~Transformer();

        friend std::ostream& operator<<(std::ostream& os, Transformer& transformer); 

        //virtual methods
        virtual void fire(); //a purely virtual method
        virtual void scream();
        virtual void speak();
        
        //methods
        void transform();
        void fight();

        // Getters
        std::string getName();
        int getHealth();
        int getEnergy();
        bool getIsTransformed();
        PrimaryWeapon* getWeaponInfo();
        std::string getStatusSpark();


        // Setters
        void setName(const std::string newName);
        void setHealth(int newHealth);
        void setEnergy(int newEnergy);
        void setIsTransformed(bool newTransformed);
        void setWeapon(PrimaryWeapon* weapon);
        void setStatusSpark(std::string newSpark);
        
    private:
        std::string _name;
        int _health;
        int _energy;
        bool _isTransformed;
        PrimaryWeapon* _weapon; // association
        SparkCore _robotSpark; // composition
};


#endif
