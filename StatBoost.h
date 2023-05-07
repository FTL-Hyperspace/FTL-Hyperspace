#pragma once
#include "Global.h"
#include "Constants.h"
#include "CustomCrew.h"
#include "CustomCrewCommon.h"
#include "EnumClassHash.h"
#include <unordered_set>

struct CrewDefinition;
struct ActivatedPowerDefinition;
struct PowerResourceDefinition;
class CrewMember_Extend;
struct RoomAnimDef;

enum class CrewExtraCondition : unsigned int;

enum class CrewStat : unsigned int
{
    MAX_HEALTH = 0,
    STUN_MULTIPLIER,
    MOVE_SPEED_MULTIPLIER,
    REPAIR_SPEED_MULTIPLIER,
    DAMAGE_MULTIPLIER,
    RANGED_DAMAGE_MULTIPLIER,
    DOOR_DAMAGE_MULTIPLIER,
    FIRE_REPAIR_MULTIPLIER,
    SUFFOCATION_MODIFIER,
    FIRE_DAMAGE_MULTIPLIER,
    OXYGEN_CHANGE_SPEED,
    DAMAGE_TAKEN_MULTIPLIER,
    CLONE_SPEED_MULTIPLIER,
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
    ESSENTIAL,
    CAN_FIGHT,
    CAN_REPAIR,
    CAN_SABOTAGE,
    CAN_MAN,
    CAN_TELEPORT,
    CAN_SUFFOCATE,
    CONTROLLABLE,
    CAN_BURN,
    IS_TELEPATHIC,
    RESISTS_MIND_CONTROL,
    IS_ANAEROBIC,
    CAN_PHASE_THROUGH_DOORS,
    DETECTS_LIFEFORMS,
    CLONE_LOSE_SKILLS,
    POWER_DRAIN_FRIENDLY,
    DEFAULT_SKILL_LEVEL,
    POWER_RECHARGE_MULTIPLIER,
    HACK_DOORS,
    NO_CLONE,
    NO_SLOT,
    NO_AI,
    VALID_TARGET,
    CAN_MOVE,
    TELEPORT_MOVE,
    TELEPORT_MOVE_OTHER_SHIP,
    SILENCED,
    LOW_HEALTH_THRESHOLD,
    // non-cached stats
    CREW_SLOTS, // this doesn't need to be cached since the crew slots are totalled once per frame
    ACTIVATE_WHEN_READY,
    STAT_BOOST,
    DEATH_EFFECT,
    POWER_EFFECT,
    POWER_MAX_CHARGES,
    POWER_CHARGES_PER_JUMP,
    POWER_COOLDOWN,
    TRANSFORM_RACE
};

extern const std::array<std::string, numStats> crewStats;

struct StatBoostDefinition
{
    enum class BoostType
    {
        MULT,
        FLAT,
        ADD=FLAT,
        SET,
        FLIP,
        SET_VALUE,
        MIN,
        MAX,
        REPLACE_GROUP,
        REPLACE_POWER,
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
        CREW_TARGET,
        TARGETS_ME,
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
        CURRENT_ENEMIES,
        ORIGINAL_ALLIES,
        ORIGINAL_ENEMIES
    };

    enum class DroneTarget
    {
        DRONES,
        CREW,
        ALL
    };

    CrewStat stat;
    float amount;
    bool value;
    std::string stringValue = "";
    bool isBool = false;
    int priority = -1;
    float duration = -1;
    bool jumpClear = false;

    std::string boostAnim = "";
    RoomAnimDef *roomAnim = nullptr;

    bool affectsSelf = false;

    std::vector<std::string> whiteList = std::vector<std::string>();
    std::vector<std::string> blackList = std::vector<std::string>();
    std::vector<std::string> systemRoomReqs = std::vector<std::string>();
    std::vector<std::string> systemList = std::vector<std::string>();

    std::vector<StatBoostDefinition*> providedStatBoosts = std::vector<StatBoostDefinition*>();

    ActivatedPowerDefinition *powerChange = nullptr;
    std::unordered_set<ActivatedPowerDefinition*> powerWhitelist;
    std::unordered_set<ActivatedPowerDefinition*> powerBlacklist;
    std::unordered_set<PowerResourceDefinition*> powerResourceWhitelist;
    std::unordered_set<PowerResourceDefinition*> powerResourceBlacklist;
    std::unordered_set<unsigned int> powerGroupWhitelist;
    std::unordered_set<unsigned int> powerGroupBlacklist;
    bool hasPowerList;
    ExplosionDefinition* deathEffectChange;

    std::vector<float> powerScaling = std::vector<float>();
    float powerScalingNoSys = 1.0;
    float powerScalingHackedSys = 1.0;
    std::vector<int> systemPowerScaling;

    std::vector<std::pair<CrewExtraCondition,bool>> extraConditions = std::vector<std::pair<CrewExtraCondition,bool>>();
    std::vector<std::pair<CrewExtraCondition,bool>> extraOrConditions = std::vector<std::pair<CrewExtraCondition,bool>>();
    bool extraConditionsReq;
    SystemRoomTarget systemRoomTarget;
    bool systemRoomReq;
    bool isRoomBased;
    BoostSource boostSource;
    BoostType boostType;
    ShipTarget shipTarget;
    CrewTarget crewTarget;
    DroneTarget droneTarget = DroneTarget::ALL;
    bool functionalTarget = false;
    std::pair<float,float> healthReq = {-1.f, -1.f};
    std::pair<float,float> healthFractionReq = {-1.f, -1.f};
    std::pair<float,float> oxygenReq = {-1.f, -1.f};
    std::pair<int,int> fireCount = {-1, -1};

    float dangerRating = -1.f;

    int realBoostId = -1;
    int stackId = 0;
    int maxStacks = 2147483647;

    static std::vector<StatBoostDefinition*> statBoostDefs;
    static std::unordered_map<std::string,StatBoostDefinition*> savedStatBoostDefs;

    void GiveId()
    {
        realBoostId = statBoostDefs.size();
        statBoostDefs.push_back(this);
    }

    bool TestRoomStatBoostSystem(ShipManager *ship, int room);

    bool IsTargetPower(ActivatedPowerDefinition *power);
    bool IsTargetPower(PowerResourceDefinition *power);
};

struct StatBoost
{
    StatBoostDefinition* def;

    int iStacks = 1;

    CrewMember* crewSource;
    int crewSourceId;
    TimerHelper timerHelper;

    void FindCrewSource();

    std::pair<std::vector<int>,std::vector<int>> sourceRoomIds = std::pair<std::vector<int>,std::vector<int>>();

    int sourceShipId;

    void Save(int fd);
    static StatBoost LoadStatBoost(int fd);

    StatBoost(StatBoostDefinition& definition) : def{&definition}
    {
    }

    StatBoost(StatBoostDefinition* definition) : def{definition}
    {
    }
};

class StatBoostManager
{
public:
    static unsigned int statCacheFrame;

    std::unordered_map<CrewStat, std::vector<StatBoost>, EnumClassHash> statBoosts;
    std::vector<StatBoost> animBoosts;
    std::vector<StatBoost> dangerBoosts;

    StatBoostManager()
    {

    }

    static StatBoostManager *GetInstance()
    {
        return &instance;
    }

    void Clear()
    {
        statBoosts.clear();
        animBoosts.clear();
        dangerBoosts.clear();
    }

    StatBoostDefinition* ParseStatBoostNode(rapidxml::xml_node<char>* node, StatBoostDefinition::BoostSource boostSource, bool isRoomBased);
    void CreateTimedAugmentBoost(StatBoost statBoost, CrewMember* crew);
    void OnLoop(WorldManager* world);

    float CalculateStatDummy(CrewStat stat, CrewDefinition *def, int ownerId, int shipId = -1, int roomId = -1);
    void CreateDummyCrew();
private:
    static StatBoostManager instance;
    ShipManager* playerShip;
    ShipManager* enemyShip;
    std::vector<CrewMember*> checkingCrewList;
    std::unordered_map<CrewMember*,std::unordered_map<int,int>> recursiveStackCount;

    int nextStackId = 0;
    std::unordered_map<std::string, int> stackIdMap;

    CrewMember *dummyCrew = nullptr;

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

    void CreateAugmentBoost(StatBoostDefinition* def, int shipId, int nStacks);
    void CreateCrewBoost(StatBoostDefinition* def, CrewMember* otherCrew, CrewMember_Extend* ex, int nStacks);
    void CreateCrewBoost(StatBoost statBoost, CrewMember* otherCrew);
    void CreateRecursiveBoosts(StatBoost& statBoost, int nStacks, bool noCheck = false);
    void AddRoomStatBoosts(ShipManager *ship);
};
