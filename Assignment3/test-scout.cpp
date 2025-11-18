/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 3
*/

#include "gtest/gtest.h"
#include "Scout.h"
#include "PrimaryWeapon.h"

// Constructor
TEST(ScoutTest, ConstructorTest) {
    PrimaryWeapon weapon(25);
    Scout scout("Optimus", 100, 100, false, &weapon, 50, 10, 7);
    EXPECT_EQ(scout.getSpeed(), 50);
    EXPECT_EQ(scout.getCloakLevel(), 10);
    EXPECT_EQ(scout.getScanRange(), 7);
}

// Setters and getters
TEST(ScoutTest, SetGetSpeed) {
    PrimaryWeapon weapon(25);
    Scout scout("Optimus", 100, 100, false, &weapon, 50, 10, 7);
    scout.setSpeed(64);
    EXPECT_EQ(scout.getSpeed(), 64);
}
TEST(ScoutTest, SetGetCloakLevel) {
    PrimaryWeapon weapon(25);
    Scout scout("Optimus", 100, 100, false, &weapon, 50, 10, 7);
    scout.setCloakLevel(16);
    EXPECT_EQ(scout.getCloakLevel(), 16);
}
TEST(ScoutTest, SetGetScanRange) {
    PrimaryWeapon weapon(25);
    Scout scout("Optimus", 100, 100, false, &weapon, 50, 10, 7);
    scout.setScanRange(16);
    EXPECT_EQ(scout.getScanRange(), 16);
}

// Methods
TEST(ScoutTest, CloakMethodTest_1) {
    PrimaryWeapon weapon(25);
    Scout scout("Optimus", 100, 100, false, &weapon, 50, 10, 7);
    std::ostringstream buffer; 
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(buffer.rdbuf());
    scout.cloak();
    std::cout.rdbuf(oldCoutBuffer);
    EXPECT_EQ(buffer.str(), "Optimus disguised for 10 level\n");
}
TEST(ScoutTest, CloakMethodTest_2) {
    PrimaryWeapon weapon(25);
    Scout scout("Optimus", 100, 0, false, &weapon, 50, 10, 7);
    std::ostringstream buffer; 
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(buffer.rdbuf());
    scout.cloak();
    std::cout.rdbuf(oldCoutBuffer);
    EXPECT_EQ(buffer.str(), "Optimus is exhausted, didn't disguise\n");
} 

TEST(ScoutTest, ScanMethodTest) {
    PrimaryWeapon weapon(25);
    Scout scout("Optimus", 100, 100, false, &weapon, 50, 10, 7);
    std::ostringstream buffer; 
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(buffer.rdbuf());
    scout.scanArea();
    std::cout.rdbuf(oldCoutBuffer);
    EXPECT_EQ(buffer.str(), "Scaned 147 miles\n");
}

