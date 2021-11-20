#include "AbilityDrone.h"

AbilityDrone::AbilityDrone(const std::string& _type, const std::string& _name, int _shipId, const DroneBlueprint* _bp, DroneAbilityDefinition _ability) : ability(_ability)
{
    this->constructor(_type, _name, _shipId, _bp, new AbilityDroneAnimation(_shipId, _type, Pointf(0, 0), _shipId == 0));
    abilityTimer = TimerHelper(false);
    CM_EX(this)->isAbilityDrone = true;
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


bool AbilityDroneAnimation::new_OnRender(float scale, int selectedState, bool outlineOnly)
{

}

void AbilityDroneAnimation::new_OnUpdate(bool isUsingAbility)
{
    if (isUsingAbility)
    {
        status = 10;
    }
}

void AbilityDrone::new_OnLoop()
{
    ((AbilityDroneAnimation*)&(crewAnim))->new_OnUpdate(true);
}

void AbilityDroneAnimation::new_OnInit(const std::string& race, Pointf position, bool enemy)
{
    for (int i = 0; i < 4; i++)
    {
        anims[i].push_back(G_->GetAnimationControl()->GetAnimation(race + "_ability"));
    }
}


AbilityDroneAnimation::AbilityDroneAnimation(int shipId, const std::string& race, Pointf pos, bool hostile) : CrewAnimation()
{
    this->constructor(shipId, race, pos, hostile);
    CMA_EX(this)->isAbilityDrone = true;
}
