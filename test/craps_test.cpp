#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"

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