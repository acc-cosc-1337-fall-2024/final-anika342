#include "die.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() 
{
	Die die1, die2;

	Shooter shooter;

	Roll* roll = shooter.throw_dice(die1, die2);
	int rolled_value = roll->roll_value();

	ComeOutPhase come_out_phase;

	while (true)
	{
		RollOutcome outcome = come_out_phase.get_outcome(roll);
		std::cout << "Rolled value: " << rolled_value << std::endl;

		if (outcome == RollOutcome::natural || outcome == RollOutcome::craps)
		{
			std::cout << "Roll again!" << std::endl;
			roll = shooter.throw_dice(die1, die2);
			rolled_value = roll->roll_value();
		}
		else
		{
			break;
		}
	}

	std::cout << "Start of point phase" << std::endl;
	std::cout << "Roll until rolled value or 7 is rolled." << std::endl;

	int point = rolled_value;
	roll = shooter.throw_dice(die1, die2);
	rolled_value = roll->roll_value();

	PointPhase point_phase(point);

	while (true)
	{
		RollOutcome outcome = point_phase.get_outcome(roll);
		std::cout << "Rolled value: " << rolled_value << std::endl;

		if (outcome == RollOutcome::seven_out || outcome == RollOutcome::nopoint)
		{
			std::cout << "Roll again!" << std::endl;
			roll = shooter.throw_dice(die1, die2);
			rolled_value = roll->roll_value();
		}
		else
		{
			break;
		}
	}

	std::cout << "End of point phase" << std::endl;

	shooter.display_rolled_values();
	
	return 0;
}