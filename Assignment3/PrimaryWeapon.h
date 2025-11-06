#ifndef PRIMARYWEAPON
#define PRIMARYWEAPON
#include <string>

class PrimaryWeapon {
    public:
        PrimaryWeapon(int damage);
        // Getters
        int getDamageInfo();
        // Setters
        void changeDamage(int newDamage);
        
    private:
        int _damage;
};


#endif
