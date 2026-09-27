#include "Global.h"

void TimerHelper::Start(float goal) // float overload
{
    running = true;
    currTime = 0.0;
    if (goal != -1.0)
    {
        currGoal = goal;
    }
    else if (maxTime != minTime)
    {
        currGoal = (minTime + random32() % (maxTime - minTime)) / 1000.0;
    }
    else
    {
        currGoal = maxTime / 1000.0;
    }
}
