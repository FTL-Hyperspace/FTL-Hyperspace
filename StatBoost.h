#pragma once
#include "Global.h"

struct ActivatedPowerDefinition;

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
    DEFAULT_SKILL_LEVEL,
    POWER_RECHARGE_MULTIPLIER,
    HACK_DOORS
};

static const std::array<std::string, 43> crewStats =
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
    "defaultSkillLevel",
    "powerRechargeMultiplier",
    "hackDoors"
};

struct StatBoostDefinition
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
        ALL,
        CURRENT_ALLIES,
        CURRENT_ENEMIES
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
    float amount;
    bool value;
    bool isBool = false;
    int priority = -1;
    float duration = -1;

    std::string boostAnim = "";

    bool affectsSelf;

    std::vector<std::string> whiteList = std::vector<std::string>();
    std::vector<std::string> blackList = std::vector<std::string>();
    std::vector<std::string> systemRoomReqs = std::vector<std::string>();
    std::vector<std::string> systemList = std::vector<std::string>();

    std::vector<StatBoostDefinition> providedStatBoosts = std::vector<StatBoostDefinition>();

    ActivatedPowerDefinition* powerChange;
    Damage* deathEffectChange;
    bool explosionShipFriendlyFire;

    std::vector<float> powerScaling = std::vector<float>();
    std::vector<int> systemPowerScaling;

    std::vector<ExtraCondition> extraConditions = std::vector<ExtraCondition>();
    bool extraConditionsReq;
    SystemRoomTarget systemRoomTarget;
    bool systemRoomReq;
    BoostSource boostSource;
    BoostType boostType;
    ShipTarget shipTarget;
    CrewTarget crewTarget;
    DroneTarget droneTarget = DroneTarget::ALL;

    static uint64_t nextId;

    int realBoostId = -1;
    int stackId = 0;
    int maxStacks = 2147483647;

    void GiveId()
    {
        nextId++;
        realBoostId = nextId;
    }
};

struct StatBoost
{
    StatBoostDefinition def;

    int iStacks = 1;

    CrewMember* crewSource;
    TimerHelper timerHelper;

    std::pair<std::vector<int>,std::vector<int>> sourceRoomIds = std::pair<std::vector<int>,std::vector<int>>();

    int sourceShipId;

    StatBoost(StatBoostDefinition definition) : def{definition}
    {
    }
};

class StatBoostManager
{
public:
    std::unordered_map<CrewStat, std::vector<StatBoost>> statBoosts;
    std::vector<StatBoost> animBoosts;

    StatBoostManager()
    {

    }

    static StatBoostManager *GetInstance()
    {
        return &instance;
    }

    StatBoostDefinition ParseStatBoostNode(rapidxml::xml_node<char>* node, StatBoostDefinition::BoostSource boostSource);
    void CreateTimedAugmentBoost(StatBoost statBoost, CrewMember* crew);
    void OnLoop(WorldManager* world);
private:
    static StatBoostManager instance;
    ShipManager* playerShip;
    ShipManager* enemyShip;
    std::vector<CrewMember*> checkingCrewList;

    int nextStackId = 0;
    std::unordered_map<std::string, int> stackIdMap;

    int GiveStackId()
    {
        return ++nextStackId;
    }

    int GiveStackId(std::string stringId)
    {
        auto it = stackIdMap.find(stringId);
        if (it != stackIdMap.end()) return it->second;
        stackIdMap[stringId] = ++nextStackId;
        return nextStackId;
    }

    void CreateAugmentBoost(StatBoostDefinition& def, int shipId, int nStacks);
    void CreateCrewBoost(StatBoostDefinition& def, CrewMember* otherCrew, int nStacks);
    void CreateCrewBoost(StatBoost statBoost, CrewMember* otherCrew);
    void CreateRecursiveBoosts(StatBoost& statBoost, int nStacks);
};

void CreateAugmentBoost(StatBoostDefinition& def, ShipManager* playerShip, ShipManager* enemyShip, int nStacks);
