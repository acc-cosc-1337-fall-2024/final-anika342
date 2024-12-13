//
#include "die.h"
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>

int Die::roll() {
    srand(time(0));
    return (rand() % 6) + 1;
}

