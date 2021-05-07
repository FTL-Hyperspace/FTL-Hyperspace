#pragma once
#include "FTLGame.h"
#include <array>

struct CrewDefinition;
struct ActivatedPowerDefinition;

enum PowerReadyState
{
    POWER_NOT_READY_COOLDOWN,
    POWER_READY,
    POWER_NOT_READY_ACTIVATED,
    POWER_NOT_READY_ENEMY_SHIP,
    POWER_NOT_READY_PLAYER_SHIP,
    POWER_NOT_READY_ENEMY_IN_ROOM,
    POWER_NOT_READY_FRIENDLY_IN_ROOM,
    POWER_NOT_READY_SYSTEM_IN_ROOM,
    POWER_NOT_READY_HAS_CLONEBAY,
    POWER_NOT_READY_AI_DISABLED,
    POWER_NOT_READY_OUT_OF_COMBAT,
    POWER_NOT_READY_IN_COMBAT,
    POWER_NOT_READY_MIN_HEALTH,
    POWER_NOT_READY_MAX_HEALTH,
    POWER_NOT_READY_SYSTEM_DAMAGED,
    POWER_NOT_READY_TELEPORTING
};

enum class CrewStat
{
    MAX_HEALTH = 0,
    STUN_MULTIPLIER,
    MOVE_SPEED_MULTIPLIER,
    REPAIR_SPEED_MULTIPLIER,
    DAMAGE_MULTIPLIER,
    RANGED_DAMAGE_MULTIPLIER,
    FIRE_REPAIR_MULTIPLIER,
    SUFFOCATION_MODIFIER,
    FIRE_DAMAGE_MULTIPLIER,
    OXYGEN_CHANGE_SPEED,
    DAMAGE_TAKEN_MULTIPLIER,
    PASSIVE_HEAL_AMOUNT,
    TRUE_PASSIVE_HEAL_AMOUNT,
    TRUE_HEAL_AMOUNT,
    PASSIVE_HEAL_DELAY,
    ACTIVE_HEAL_AMOUNT,
    SABOTAGE_SPEED_MULTIPLIER,
    ALL_DAMAGE_TAKEN_MULTIPLIER,
    HEAL_SPEED_MULTIPLIER,
    HEAL_CREW_AMOUNT,
    DAMAGE_ENEMIES_AMOUNT,
    BONUS_POWER,
    POWER_DRAIN,
    CAN_FIGHT,
    CAN_REPAIR,
    CAN_SABOTAGE,
    CAN_MAN,
    CAN_SUFFOCATE,
    CONTROLLABLE,
    CAN_BURN,
    IS_TELEPATHIC,
    IS_ANAEROBIC,
    CAN_PHASE_THROUGH_DOORS,
    DETECTS_LIFEFORMS,
    CLONE_LOSE_SKILLS,
    POWER_DRAIN_FRIENDLY,
    STAT_BOOST,
    DEATH_EFFECT,
    POWER_EFFECT,
    ACTIVATE_WHEN_READY,
    DEFAULT_SKILL_LEVEL
};

static const std::array<std::string, 41> crewStats =
{
    "maxHealth",
    "stunMultiplier",
    "moveSpeedMultiplier",
    "repairSpeed",
    "damageMultiplier",
    "rangedDamageMultiplier",
    "fireRepairMultiplier",
    "suffocationModifier",
    "fireDamageMultiplier",
    "oxygenChangeSpeed",
    "damageTakenMultiplier",
    "passiveHealAmount",
    "truePassiveHealAmount",
    "trueHealAmount",
    "passiveHealDelay",
    "healAmount",
    "sabotageSpeedMultiplier",
    "allDamageTakenMultiplier",
    "healSpeed",
    "healCrewAmount",
    "damageEnemiesAmount",
    "bonusPower",
    "powerDrain",
    "canFight",
    "canRepair",
    "canSabotage",
    "canMan",
    "canSuffocate",
    "controllable",
    "canBurn",
    "isTelepathic",
    "isAnaerobic",
    "canPhaseThroughDoors",
    "detectsLifeforms",
    "cloneLoseSkills",
    "powerDrainFriendly",
    "statBoost",
    "deathEffect",
    "powerEffect",
    "activateWhenReady",
    "defaultSkillLevel"
};

struct StatBoost
{
    enum class BoostType
    {
        MULT,
        FLAT,
        SET,
        FLIP,
        SET_VALUE
    };

    enum class BoostSource
    {
        CREW,
        AUGMENT
    };

    enum class ShipTarget
    {
        PLAYER_SHIP,
        ENEMY_SHIP,
        CURRENT_ALL,
        CURRENT_ROOM,
        OTHER_ALL,
        ORIGINAL_SHIP,
        ORIGINAL_OTHER_SHIP,
        ALL
    };

    enum class SystemRoomTarget
    {
        ALL,
        NONE
    };

    enum class CrewTarget
    {
        ALLIES,
        ENEMIES,
        SELF,
        ALL
    };

    enum class DroneTarget
    {
        DRONES,
        CREW,
        ALL
    };

    enum class ExtraCondition
    {
        BURNING,
        SUFFOCATING,
        MIND_CONTROLLED,
        STUNNED,
        REPAIRING,
        FIGHTING,
        SHOOTING,
        MOVING,
        IDLE,
        MANNING,
        FIREFIGHTING,
        DYING,
        TELEPORTING_OR_CLONING

    };

    CrewStat stat;
    CrewMember* crewSource;
    float amount;
    bool value;
    bool isBool = false;
    int priority = -1;
    float duration = -1;
    TimerHelper* timerHelper;

    std::string boostAnim = "";

    bool affectsSelf;

    std::vector<std::string> whiteList = std::vector<std::string>();
    std::vector<std::string> blackList = std::vector<std::string>();
    std::pair<std::vector<int>,std::vector<int>> sourceRoomIds = std::pair<std::vector<int>,std::vector<int>>();
    std::vector<std::string> systemRoomReqs = std::vector<std::string>();
    std::vector<std::string> systemList = std::vector<std::string>();

    std::vector<StatBoost> providedStatBoosts = std::vector<StatBoost>();

    ActivatedPowerDefinition* powerChange;
    Damage* deathEffectChange;
    bool explosionShipFriendlyFire;

    std::vector<float> powerScaling = std::vector<float>();
    std::vector<int> systemPowerScaling;

    std::vector<ExtraCondition> extraConditions = std::vector<ExtraCondition>();
    bool extraConditionsReq;
    SystemRoomTarget systemRoomTarget;
    bool systemRoomReq;
    BoostType boostType;
    BoostSource boostSource;
    ShipTarget shipTarget;
    CrewTarget crewTarget;
    DroneTarget droneTarget = DroneTarget::ALL;

    int sourceShipId;

    static uint64_t nextId;

    bool isDefinition = false;
    int realBoostId = -1;


    void GiveId()
    {
        nextId++;
        realBoostId = nextId;
    }

    ~StatBoost()
    {
        delete timerHelper;
    }
};

struct CrewAnimation_Extend
{
public:
    CrewAnimation *orig;
    Animation* effectAnim = nullptr;
    Animation* tempEffectAnim = nullptr;
    Animation* effectFinishAnim = nullptr;
    std::unordered_map<uint64_t, Animation*> boostAnim = std::unordered_map<uint64_t, Animation*>();
    GL_Texture* tempEffectStrip = nullptr;

    bool isMantisAnimation = false;
    bool isIonDrone = false;

    Pointf effectPos;
    Pointf effectWorldPos;
    bool powerDone = true;

    bool temporaryPowerActive;
    bool isAbilityDrone = false;

    void OnInit(const std::string& name, Pointf position, bool enemy);

    ~CrewAnimation_Extend();
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

    int powerRoom;
    int powerShip;

    bool powerActivated = false;
    bool temporaryPowerActive = false;

    void ActivatePower();
    void PreparePower();
    void ActivateTemporaryPower();
    void TemporaryPowerFinished();
    Damage* GetPowerDamage();
    PowerReadyState PowerReady();

    ActivatedPowerDefinition* powerChange;
    Damage deathEffectChange;
    bool explosionShipFriendlyFire;
    bool hasDeathExplosion;

    bool isIonDrone = false;
    bool isAbilityDrone = false;

    float prevStun = 0.f; // for use in stun resistance checking

    std::vector<StatBoost> outgoingStatBoosts = std::vector<StatBoost>();
    std::vector<StatBoost> outgoingAbilityStatBoosts = std::vector<StatBoost>();
    std::vector<StatBoost> tempOutgoingStatBoosts = std::vector<StatBoost>();
//    std::vector<StatBoost> outgoingTimedStatBoosts = std::vector<StatBoost>();
//    std::vector<StatBoost> outgoingTimedAbilityStatBoosts = std::vector<StatBoost>();
    std::unordered_map<CrewStat, std::vector<StatBoost>> timedStatBoosts = std::unordered_map<CrewStat, std::vector<StatBoost>>();
//    std::vector<StatBoost> personalStatBoosts;

    float extraMedbay = 0.f;

    void Initialize(CrewBlueprint& bp, int shipId, bool enemy, CrewAnimation *animation);


    ~CrewMember_Extend()
    {
        delete passiveHealTimer;
    }

    bool BoostCheck(const StatBoost& statBoost);
    float CalculateStat(CrewStat stat, const CrewDefinition& def, bool* boolValue=nullptr);
};

CrewMember_Extend* Get_CrewMember_Extend(CrewMember* c);
CrewAnimation_Extend* Get_CrewAnimation_Extend(CrewAnimation *c);

#define CM_EX Get_CrewMember_Extend
#define CMA_EX Get_CrewAnimation_Extend
