#include "throttle.h"

throttle::throttle()
{
    top_position = 6;
    position = 0;
}

throttle::~throttle()
{
}

throttle::throttle(int initial_top_position)
{
    top_position = initial_top_position;
    position = 0;
}


void throttle::shift(int amount) 
{
    position += amount;
    if(position < 0)
        position = 0;
    else if(position > top_position)
        position = top_position;
    else
        ; // do nothing!
}


void throttle::shut_off()
{
    position = 0;
}


// accessors
double throttle::flow() const 
{
    return (double)position/top_position;
}

bool throttle::is_on() const
{
    return position > 0;
}