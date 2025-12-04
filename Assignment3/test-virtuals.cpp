/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 3
*/

#include "gtest/gtest.h"
#include "Scout.h"
#include "Warrior.h"
#include "AerialBot.h"
#include "Transformer.h"
#include "PrimaryWeapon.h"
#include <vector>


TEST(Virtuals, VectorVirtualMethods){
    PrimaryWeapon weapon(25);
    std::vector<Transformer*> v;
    for (int i=0; i<3; i++) v.push_back(new AerialBot("AerBot", i*100, 100, false, &weapon, 240, i*3));
    for (int i=0; i<3; i++) v.push_back(new Scout("Sc", i*50, 100, false, &weapon, 24, i*5, 10));
    for (int i=0; i<3; i++) v.push_back(new Warrior("Wa", i*75, 100, false, &weapon, 35, i*2));

    for(auto t: v)
    {
        ASSERT_TRUE(t->fire());
        ASSERT_TRUE(t->scream());
        ASSERT_TRUE(t->speak());
    }

    for (auto t: v) delete t;
}