/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 3
*/

#include "gtest/gtest.h"
#include "Warrior.h"
#include "PrimaryWeapon.h"

// Constructor
TEST(WarriorTest, ConstructorTest) {
    PrimaryWeapon weapon(25);
    Warrior warrior("Optimus", 100, 100, false, &weapon, 10, 6);
    EXPECT_EQ(warrior.getArmor(), 10);
    EXPECT_EQ(warrior.getRage(), 6);
}

// Setters and getters
TEST(WarriorTest, SetGetArmor) {
    PrimaryWeapon weapon(25);
    Warrior warrior("Optimus", 100, 100, false, &weapon, 10, 6);
    warrior.setArmor(37);
    EXPECT_EQ(warrior.getArmor(), 37);
}
TEST(WarriorTest, SetGetRage) {
    PrimaryWeapon weapon(25);
    Warrior warrior("Optimus", 100, 100, false, &weapon, 10, 6);
    warrior.setRage(4);
    EXPECT_EQ(warrior.getRage(), 4);
}


// Methods
TEST(WarriorTest, StrikeTest) {
    PrimaryWeapon weapon(25);
    Warrior warrior("Optimus", 100, 100, false, &weapon, 10, 6);
    std::ostringstream buffer; 
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(buffer.rdbuf());
    warrior.furiousStrike();
    std::cout.rdbuf(oldCoutBuffer);
    EXPECT_EQ(buffer.str(), "600\n");
}

