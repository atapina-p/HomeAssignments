#include "PrimaryWeapon.h"

PrimaryWeapon::PrimaryWeapon(int damage): _damage(damage){};


void PrimaryWeapon::changeDamage(int newDamage){
    _damage = abs(newDamage);
}


int PrimaryWeapon::getDamageInfo(){
    return _damage;
}


