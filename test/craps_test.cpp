#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify die roll return a value from 1 to 6") {
	//REQUIRE(Die::roll()==(1||2||3||4||5||6));
	Die die;

	for (int i=0; i<10; ++i)
	{
		//int roll_value = die.roll();
		REQUIRE (die.roll() == (1||2||3||4||5||6));
		//REQUIRE ((roll_value >1) && (roll_value<7));
	}
}

TEST_CASE ("Verify die rolls return a value from 2 to 12") {
	Die die1;
	Die die2;
	Roll roll(die1, die2);

	for (int i=0; i<10; ++i)
	{
		roll.roll_dice();
		//int roll_value = roll.roll_value();

		REQUIRE(roll.roll_value() == (2||3||4||5||6||7||8||9||10||11||12));
		//REQUIRE(roll.roll_value() == (1));

	}
}