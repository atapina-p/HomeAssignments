/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 3
*/

#include "PrimaryWeapon.h"

PrimaryWeapon::PrimaryWeapon(int damage): _damage(damage){};

PrimaryWeapon::~PrimaryWeapon(){};


void PrimaryWeapon::changeDamage(int newDamage){
    _damage = abs(newDamage);
}


int PrimaryWeapon::getDamageInfo(){
    return _damage;
}


