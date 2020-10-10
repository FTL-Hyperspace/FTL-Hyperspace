#include "Global.h"

struct DroneAbilityDefinition
{
    enum class AIType
    {
        SYSTEMS,
        SYSTEMS_POWER,
        CREW_HEAL,
        ENEMIES
    };

    int delay = 0;
    AIType ai;
};

class AbilityDrone : public CrewDrone
{

public:

    DroneAbilityDefinition::AIType abilityAI = DroneAbilityDefinition::AIType::SYSTEMS;

    AbilityDrone(const std::string& type, const std::string& name, int shipId, const DroneBlueprint* blueprint, DroneAbilityDefinition ability);

    void CheckAbilityTimer();
    bool AbilityReady();
    int new_BlockRoom();
    void new_OnLoop();
private:
    int lastRoom = -1;
    TimerHelper abilityTimer;
    DroneAbilityDefinition ability;
};

class AbilityDroneAnimation : public CrewAnimation
{
public:
    Animation abilityAnimation;

    AbilityDroneAnimation(int shipId, const std::string& race, Pointf unk, bool hostile);

    bool new_OnRender(float scale, int selectedState, bool outlineOnly);
    void new_OnUpdate(bool isUsingAbility);
    void new_OnInit(const std::string& race, Pointf position, bool enemy);
};
