/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 3
*/

#include "gtest/gtest.h"

#include "Transformer.h"
#include "PrimaryWeapon.h"
#include "SparkCore.h"



// SparkCore class test
TEST(SparkCoreTest, ConstructorGetStatusSpark) {
    PrimaryWeapon weapon(25);
    Transformer transformer("Optimus", 100, 100, false, weapon);
    EXPECT_EQ(transformer.getStatusSpark(), "undefined");
}
TEST(SparkCoreTest, SetGetStatusSpark) {
    PrimaryWeapon weapon(25);
    Transformer transformer("Optimus", 100, 100, false, weapon);
    transformer.setStatusSpark("Damaged");
    EXPECT_EQ(transformer.getStatusSpark(), "Damaged");
}

//Transformer class tests
TEST(TransformerTest, ConstructorGetName) {
    PrimaryWeapon weapon(25);
    Transformer transformer("Optimus", 100, 100, false, weapon);
    EXPECT_EQ(transformer.getName(), "Optimus");
}
TEST(TransformerTest, SetGetName) {
    PrimaryWeapon weapon(25);
    Transformer transformer("Optimus", 100, 100, false, weapon);
    transformer.setName("Vector");
    EXPECT_EQ(transformer.getName(), "Vector");
}

TEST(TransformerTest, ConstructorGetHealth) {
    PrimaryWeapon weapon(25);
    Transformer transformer("Optimus", 37, 250, false, weapon);
    EXPECT_EQ(transformer.getHealth(), 37);
}
TEST(TransformerTest, SetGetHealth) {
    PrimaryWeapon weapon(25);
    Transformer transformer("Optimus", 37, 250, false, weapon);
    transformer.setHealth(24);
    EXPECT_EQ(transformer.getHealth(), 24);
}

TEST(TransformerTest, ConstructorGetEnergy) {
    PrimaryWeapon weapon(25);
    Transformer transformer("Optimus", 50, 230, false, weapon);
    EXPECT_EQ(transformer.getEnergy(), 230);
}
TEST(TransformerTest, SetGetEnergy) {
    PrimaryWeapon weapon(25);
    Transformer transformer("Optimus", 50, 230, false, weapon);
    transformer.setEnergy(200);
    EXPECT_EQ(transformer.getEnergy(), 200);
}

TEST(TransformerTest, ConstructorGetIsTransformed) {
    PrimaryWeapon weapon(25);
    Transformer transformer("Optimus", 50, 230, false, weapon);
    EXPECT_FALSE(transformer.getIsTransformed());
}
TEST(TransformerTest, SetGetIsTransformed) {
    PrimaryWeapon weapon(25);
    Transformer transformer("Optimus", 50, 230, false, weapon);
    transformer.setIsTransformed(true);
    EXPECT_TRUE(transformer.getIsTransformed());
}

TEST(TransformerTest, TransformMethod_1) {
    PrimaryWeapon weapon(25);
    Transformer transformer("Optimus", 50, 230, false, weapon);
    transformer.transform();
    EXPECT_TRUE(transformer.getIsTransformed());
}
TEST(TransformerTest, TransformMethod_2) {
    PrimaryWeapon weapon(25);
    Transformer transformer("Optimus", 50, 230, true, weapon);
    transformer.transform();
    EXPECT_FALSE(transformer.getIsTransformed());
}

TEST(TransformerTest, FightMethod_1) {
    PrimaryWeapon weapon(25);
    Transformer transformer("Optimus", 50, 230, false, weapon);
    transformer.fight();
    EXPECT_EQ(transformer.getEnergy(), 220);
}
TEST(TransformerTest, FightMethod_2) {
    PrimaryWeapon weapon(25);
    Transformer transformer("Optimus", 50, 5, true, weapon);
    transformer.fight();
    EXPECT_EQ(transformer.getEnergy(), 5);
}

// Primary Weapon tests
TEST(WeaponTest, ConstructorGetWeapon) {
    PrimaryWeapon weapon(25);
    Transformer transformer("Optimus", 50, 230, false, weapon);
    EXPECT_EQ(transformer.getWeaponInfo(), 25);
}
TEST(TransformerTest, SetGetWeapon) {
    PrimaryWeapon weapon(25);
    Transformer transformer("Optimus", 50, 230, false, weapon);
    transformer.setWeapon(37);
    EXPECT_EQ(transformer.getWeaponInfo(), 37);
}

