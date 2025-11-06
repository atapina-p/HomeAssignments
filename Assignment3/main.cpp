/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 3
*/

#include "Scout.h"
#include "Warrior.h"
#include "AerialBot.h"
#include "Transformer.h"
#include "PrimaryWeapon.h"



int main(){
    PrimaryWeapon weapon(25);
    Scout scout("Optimus", 100, 100, false, weapon, 50, 10, 7);
    scout.scanArea();
}