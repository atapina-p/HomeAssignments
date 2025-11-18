/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 3
*/

#include "gtest/gtest.h"
#include "AerialBot.h"
#include "PrimaryWeapon.h"

// Constructor
TEST(AerialBotTest, ConstructorTest) {
    PrimaryWeapon weapon(25);
    AerialBot bot("Optimus", 100, 100, false, &weapon, 240, 12);
    EXPECT_EQ(bot.getFlightSpeed(), 240);
    EXPECT_EQ(bot.getAltitude(), 12);
}


//Setters and getters
TEST(AerialBotTest, SetGetFlightSpeed) {
    PrimaryWeapon weapon(25);
    AerialBot bot("Optimus", 100, 100, false, &weapon, 240, 12);
    bot.setFlightSpeed(225);
    EXPECT_EQ(bot.getFlightSpeed(), 225);
}
TEST(AerialBotTest, SetGetAltitude) {
    PrimaryWeapon weapon(25);
    AerialBot bot("Optimus", 100, 100, false, &weapon, 240, 12);
    bot.setAltitude(9);
    EXPECT_EQ(bot.getAltitude(), 9);
}

// Methods
TEST(AerialBotTest, ManeuverTest) {
    PrimaryWeapon weapon(25);
    AerialBot bot("Optimus", 100, 100, false, &weapon, 240, 12);
    std::ostringstream buffer; 
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(buffer.rdbuf());
    bot.evasiveManeuvers();
    std::cout.rdbuf(oldCoutBuffer);
    EXPECT_EQ(buffer.str(), "Now flight speed is 250\n");
    EXPECT_EQ(bot.getFlightSpeed(), 250);
}



