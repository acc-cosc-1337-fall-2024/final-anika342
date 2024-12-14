#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"

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

TEST_CASE ("Verify shooter returns a roll and that roll has 2-12") {
	Die die1;
	Die die2;
	Shooter shooter;

	for (int i=0; i<10; ++i)
	{
		Roll* roll = shooter.throw_dice(die1,die2);
		//int roll_value = roll.roll_value();

		REQUIRE(roll->roll_value() == (2||3||4||5||6||7||8||9||10||11||12));
		//REQUIRE(roll.roll_value() == (1));

		delete roll;

	}

}

TEST_CASE ("ComeOutPhase outcome TEST") {
	Die die1;
	Die die2;
	Roll roll(die1, die2);
	ComeOutPhase comeOutPhase;

	roll.roll_dice();
	int roll_value = roll.roll_value();
	if (roll_value == 7 || roll_value == 11)
	{
		REQUIRE(comeOutPhase.get_outcome(&roll) == RollOutcome::natural);
	}

	roll.roll_dice();
	roll_value = roll.roll_value();
	if (roll_value == 2 || roll_value == 3 || roll_value == 12)
	{
		REQUIRE(comeOutPhase.get_outcome(&roll) == RollOutcome::craps);
	}

	roll.roll_dice();
	roll_value = roll.roll_value();
	if (roll_value != 7 && roll_value != 11 && roll_value != 2 && roll_value != 3 && roll_value != 12)
	{
		REQUIRE(comeOutPhase.get_outcome(&roll) == RollOutcome::point);
	}

}

TEST_CASE ("PointPhase outcome TEST") {
	Die die1;
	Die die2;
	Roll roll(die1, die2);

	roll.roll_dice();
	int point_value = roll.roll_value();
	PointPhase pointPhase(point_value);

	roll.roll_dice();
	if (roll.roll_value() == point_value)
	{
		REQUIRE(pointPhase.get_outcome(&roll) == RollOutcome::point);
	}

	roll.roll_dice();
	if (roll.roll_value() == 7)
	{
		REQUIRE(pointPhase.get_outcome(&roll) == RollOutcome::seven_out);
	}

	roll.roll_dice();
	if (roll.roll_value() != point_value && roll.roll_value() != 7)
	{
		REQUIRE(pointPhase.get_outcome(&roll) == RollOutcome::nopoint);
	}

}