#include "gtest/gtest.h"

#include "Transformer.h"
#include "PrimaryWeapon.h"
#include "SparkCore.h"



// SparkCore class test
TEST(SparkCoreTest, ConstructorAndGetStatusSpark) {
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

