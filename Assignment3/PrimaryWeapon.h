/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 3
*/

#ifndef PRIMARYWEAPON
#define PRIMARYWEAPON
#include <string>

class PrimaryWeapon {
    public:
        PrimaryWeapon(int damage);
        ~PrimaryWeapon();
        // Getters
        int getDamageInfo();
        // Setters
        void changeDamage(int newDamage);
        
    private:
        int _damage;
};


#endif
