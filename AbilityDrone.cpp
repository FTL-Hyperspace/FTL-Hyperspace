#include "AbilityDrone.h"

AbilityDrone::AbilityDrone(const std::string& _type, const std::string& _name, int _shipId, const DroneBlueprint* _bp, DroneAbilityDefinition _ability) : ability(_ability)
{
    this->constructor(_type, _name, _shipId, _bp, new AbilityDroneAnimation(_shipId, _type, Pointf(0, 0), _shipId == 0));
    abilityTimer = TimerHelper(false);
}

void AbilityDrone::CheckAbilityTimer()
{

}

bool AbilityDrone::AbilityReady()
{
    return abilityTimer.Done();
}

int AbilityDrone::new_BlockRoom()
{
    if (abilityAI == DroneAbilityDefinition::AIType::SYSTEMS)
    {
        return lastRoom;
    }

    return -1;
}

void AbilityDrone::new_OnLoop()
{

}

void AbilityDroneAnimation::new_OnRender(float scale, int selectedState, bool outlineOnly)
{
}

void AbilityDroneAnimation::new_OnUpdate(bool isUsingAbility)
{

}

void AbilityDroneAnimation::new_OnInit(const std::string& race, Pointf position, bool enemy)
{

}


AbilityDroneAnimation::AbilityDroneAnimation(int shipId, const std::string& race, Pointf pos, bool hostile) : CrewAnimation()
{
    this->constructor(shipId, race, pos, hostile);
}

HOOK_METHOD(CrewDrone, OnLoop, () -> void)
{
    super();

    if (CM_EX(this)->isAbilityDrone)
    {
        ((AbilityDrone*)this)->new_OnLoop();
    }
}
/*
HOOK_METHOD(CrewAnimation, OnRender, (float scale, int selectedState, bool outlineOnly) -> void)
{
    super(scale, selectedState, outlineOnly);

    if (CMA_EX(this)->isAbilityDrone)
    {
        ((AbilityDroneAnimation*)this)->new_OnRender(scale, selectedState, outlineOnly);
    }
}


HOOK_METHOD(CrewAnimation, OnInit, (const std::string& _race, Pointf position, bool enemy) -> void)
{
    super(_race, position, enemy);

    if (CMA_EX(this)->isAbilityDrone)
    {
        ((AbilityDroneAnimation*)this)->new_OnInit(_race, position, enemy);
    }
}
*/
