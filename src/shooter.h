//

#ifndef SHOOTER_H
#define SHOOTER_H

#include "roll.h"
#include <memory>
#include <vector>

class Shooter {
public:
    Shooter()   {}
    //Roll* () throw_dice; //two die parameter references 
    Roll* throw_dice(Die& die1, Die& die2);
    void display_rolled_values();
    ~Shooter();

private:
    std::vector<Roll*> rolls;

};


#endif
