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



int main()
{
    PrimaryWeapon weapon(25);
    Transformer t("Optimus", 100, 100, false, &weapon);
    AerialBot bot("Optimus", 100, 100, false, &weapon, 12, 35);
    Scout sc("Optimus", 100, 100, false, &weapon, 12, 35, 10);
    Warrior warrior("Optimus", 100, 100, false, &weapon, 12, 35);
    std::cout << warrior;
}