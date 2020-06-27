#ifndef CM_EX
#include "FTLGame.h"

enum PowerReadyState
{
    POWER_NOT_READY_COOLDOWN,
    POWER_READY,
    POWER_NOT_READY_ENEMY_SHIP,
    POWER_NOT_READY_PLAYER_SHIP,
    POWER_NOT_READY_ENEMY_IN_ROOM,
    POWER_NOT_READY_FRIENDLY_IN_ROOM,
    POWER_NOT_READY_SYSTEM_IN_ROOM,
    POWER_NOT_READY_ACTIVATED
};

struct CrewAnimation_Extend
{
public:
    CrewAnimation *orig;
    Animation* effectAnim = NULL;
    Animation* tempEffectAnim = NULL;

    void OnInit(const std::string& name, Pointf position, bool enemy);
};

struct CrewMember_Extend
{
public:
    CrewMember *orig;
    bool canPhaseThroughDoors = false;
    bool isHealing = false;
    TimerHelper* passiveHealTimer;
    int lastRoom = -1;
    int lastShipId = -1;
    bool exploded = false;
    bool triggerExplosion = false;

    bool hasSpecialPower = false;
    bool hasTemporaryPower = false;

    std::pair<float, float> powerCooldown = std::pair<float, float>();
    std::pair<float, float> temporaryPowerDuration = std::pair<float, float>();

    bool powerActivated = false;
    bool temporaryPowerActive = false;
    bool hasEffectAnim = false;
    bool hasTempEffectAnim = false;

    void ActivatePower();
    void TemporaryPowerFinished();
    PowerReadyState PowerReady();


};

CrewMember_Extend* Get_CrewMember_Extend(CrewMember* c);
CrewAnimation_Extend* Get_CrewAnimation_Extend(CrewAnimation *c);

#define CM_EX Get_CrewMember_Extend
#define CMA_EX Get_CrewAnimation_Extend
#endif
