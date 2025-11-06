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
    PrimaryWeapon bomb(1000);
    AerialBot robot("Vector", 100, 100, false, bomb, 20, 10);
    robot.evasiveManeuvers();
    robot.bombard();
}