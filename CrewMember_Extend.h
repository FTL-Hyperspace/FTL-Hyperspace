#pragma once
#include "CrewSpawn.h"
#include "FTLGame.h"
#include "StatBoost.h"
#include "Constants.h"
#include "CustomCrewCommon.h"
#include "EnumClassHash.h"
#include "ToggleValue.h"
#include <array>
#include <memory>

struct CrewDefinition;
struct ActivatedPowerDefinition;
struct PowerResourceDefinition;
struct ActivatedPowerRequirements;

enum class CrewStat : unsigned int;
struct StatBoost;
struct StatBoostDefinition;

enum PowerReadyState : unsigned int
{
    POWER_NOT_READY_COOLDOWN,
    POWER_READY,
    POWER_NOT_READY_ACTIVATED,
    POWER_NOT_READY_ENEMY_SHIP,
    POWER_NOT_READY_PLAYER_SHIP,
    POWER_NOT_READY_ENEMY_IN_ROOM,
    POWER_NOT_READY_FRIENDLY_IN_ROOM,
    POWER_NOT_READY_WHITELIST,
    POWER_NOT_READY_ENEMY_WHITELIST,
    POWER_NOT_READY_FRIENDLY_WHITELIST,
    POWER_NOT_READY_ENEMY_BLACKLIST,
    POWER_NOT_READY_FRIENDLY_BLACKLIST,
    POWER_NOT_READY_SYSTEM_IN_ROOM,
    POWER_NOT_READY_HAS_CLONEBAY,
    POWER_NOT_READY_AI_DISABLED,
    POWER_NOT_READY_OUT_OF_COMBAT,
    POWER_NOT_READY_IN_COMBAT,
    POWER_NOT_READY_SYSTEM,
    POWER_NOT_READY_SYSTEM_FUNCTIONAL,
    POWER_NOT_READY_MIN_HEALTH,
    POWER_NOT_READY_MAX_HEALTH,
    POWER_NOT_READY_SYSTEM_DAMAGED,
    POWER_NOT_READY_CHARGES,
    POWER_NOT_READY_SILENCED,
    POWER_NOT_READY_EXTRACONDITION_OR,
    POWER_NOT_READY_EXTRACONDITION_TRUE = 16384,
    POWER_NOT_READY_EXTRACONDITION_FALSE = 32768,
    POWER_NOT_READY_CUSTOM = 65536,
};

extern unsigned int nextPowerReadyState;
unsigned int GetNextPowerReadyState(unsigned int amount);

extern const std::array<std::string, numStats> powerReadyStateExtraTextTrue;

extern const std::array<std::string, numStats> powerReadyStateExtraTextFalse;

struct ActivatedPower;

struct ActivatedPowerResource
{
public:
    PowerResourceDefinition *def;
    CrewMember *crew;
    CrewMember_Extend *crew_ex;

    // enabled
    bool enabled = true;
    bool lastEnabled;

    // definition modifiers that should be saved
    float modifiedPowerCharges = -1.f;

    // definition modifiers that don't need to be saved
    float modifiedChargesPerJump = 0.f;
    float modifiedPowerCooldown;

    std::pair<float, float> powerCooldown = std::pair<float, float>();
    std::pair<int, int> powerCharges = std::pair<int, int>();

    std::vector<ActivatedPower*> tempLinkedPowers; // linked powers, temporary used for UI construction
    void GetLinkedPowers();

    // constructors with definitions and crew
    ActivatedPowerResource(PowerResourceDefinition *_def) : def{_def} {}
    ActivatedPowerResource(PowerResourceDefinition *_def, CrewMember *_crew, CrewMember_Extend *_ex) : def{_def}, crew{_crew}, crew_ex{_ex} {}
    ActivatedPowerResource(PowerResourceDefinition *_def, CrewMember *_crew);
    ActivatedPowerResource(PowerResourceDefinition *_def, CrewMember_Extend *_ex);

    // methods
    PowerReadyState PowerReq(const ActivatedPowerRequirements *req);
    void OnUpdate();
    void EnablePower();
    void DisablePower();
    void EnableInit();
    int GetCrewBoxResourceWidth(int mode);

    void SaveState(int fd);
    void LoadState(int fd);
};

struct ActivatedPower
{
public:
    ActivatedPowerDefinition *def;
    CrewMember *crew;
    CrewMember_Extend *crew_ex;

    // enabled
    bool enabled = true;
    bool enabledInit = false;
    bool tempEnabled;

    // definition modifiers that should be saved
    float modifiedPowerCharges = -1.f;

    // definition modifiers that don't need to be saved
    float modifiedChargesPerJump = 0.f;
    bool activateWhenReady = false;
    float modifiedPowerCooldown;

    std::pair<float, float> powerCooldown = std::pair<float, float>();
    std::pair<float, float> temporaryPowerDuration = std::pair<float, float>();
    std::pair<int, int> powerCharges = std::pair<int, int>();

    std::vector<ActivatedPowerResource*> powerResources;
    void LinkPowerResources(); // links/adds power resources on the crew and sets enabled flag
    void EnablePowerResources(); // simply sets enabled flag on existing resources

    int powerRoom = -1;
    int powerShip = -1;

    bool powerActivated = false;
    bool temporaryPowerActive = false;
    bool powerDone = true;
    bool temporaryPowerDone = true;

    std::unique_ptr<Animation> effectAnim = nullptr;
    std::unique_ptr<Animation> tempEffectAnim = nullptr;
    std::unique_ptr<Animation> effectFinishAnim = nullptr;
    std::vector<Animation> extraAnims;
    GL_Texture* tempEffectStrip = nullptr;

    Pointf effectPos;
    Pointf effectWorldPos;

    // constructors with definitions and crew
    ActivatedPower(ActivatedPowerDefinition *_def) : def{_def} {}
    ActivatedPower(ActivatedPowerDefinition *_def, CrewMember *_crew, CrewMember_Extend *_ex) : def{_def}, crew{_crew}, crew_ex{_ex} {}
    ActivatedPower(ActivatedPowerDefinition *_def, CrewMember *_crew);
    ActivatedPower(ActivatedPowerDefinition *_def, CrewMember_Extend *_ex);

    // methods
    template <class T> static PowerReadyState PowerReqStatic(const T *power, const ActivatedPowerRequirements *req); // ugly
    PowerReadyState PowerReq(const ActivatedPowerRequirements *req);
    PowerReadyState PowerReady();
    Damage GetPowerDamage();
    void ActivateTemporaryPower();
    void TemporaryPowerFinished();
    void PrepareAnimation();
    void PrepareTemporaryAnimation();
    void PreparePower();
    void ActivatePower();
    void CancelPower(bool clearAnim);
    void OnUpdate();
    void ChangePowerDef(ActivatedPowerDefinition *newDef);
    void EnablePower();
    void DisablePower();
    void EnableInit();
    int GetCrewBoxResourceWidth(int mode);

    void SaveState(int fd);
    void LoadState(int fd);
};

struct CrewAnimation_Extend
{
public:
    CrewAnimation *orig;
    CrewMember *crew;
    std::unordered_map<uint64_t, Animation*> boostAnim = std::unordered_map<uint64_t, Animation*>();

    std::string crewAnimationType = "human";
    bool isMantisAnimation = false;
    bool isIonDrone = false;
    bool isAbilityDrone = false;
    TimerHelper ionTimer;

    ToggleValue<bool> canPunch;

    void OnInit(const std::string& name, Pointf position, bool enemy);

    ~CrewAnimation_Extend();
};

struct CrewMember_Extend
{
public:
    CrewMember *orig;
    int selfId = -1;
    bool canPhaseThroughDoors = false;
    bool isHealing = false;
    TimerHelper* passiveHealTimer = nullptr;
    TimerHelper* deathTimer = nullptr;
    int lastRoom = -1;
    int lastShipId = -1;
    bool exploded = false;
    bool triggerExplosion = false;

    std::vector<ActivatedPower*> crewPowers;
    bool hasSpecialPower = false;
    bool tempAddedPowerResource;
    std::vector<ActivatedPowerResource*> powerResources;
    std::unordered_map<unsigned int,ActivatedPowerResource*> powerResourceMap;

    std::vector<ActivatedPowerDefinition*> powerChange;
    void CalculatePowerDef();

    ExplosionDefinition deathEffectChange;
    bool hasDeathExplosion;

    bool isIonDrone = false;
    bool isAbilityDrone = false;

    bool noSlot = false;
    bool noClone = false;

    float prevStun = 0.f; // for use in stun resistance checking
    bool prevCanMove = true;

    std::vector<StatBoost> outgoingStatBoosts = std::vector<StatBoost>(); // list of stat boosts passive + temporary ability effects
//    std::vector<StatBoost> outgoingAbilityStatBoosts = std::vector<StatBoost>();
//    std::vector<StatBoost> tempOutgoingStatBoosts = std::vector<StatBoost>();
//    std::vector<StatBoost> outgoingTimedStatBoosts = std::vector<StatBoost>();
//    std::vector<StatBoost> outgoingTimedAbilityStatBoosts = std::vector<StatBoost>();
    std::unordered_map<CrewStat, std::vector<StatBoost>, EnumClassHash> timedStatBoosts = std::unordered_map<CrewStat, std::vector<StatBoost>, EnumClassHash>();
//    std::vector<StatBoost> personalStatBoosts;

    float extraMedbay = 0.f;

    std::string originalColorRace = ""; // for color layers
    std::string originalRace = "";
    std::string transformRace = "";

    struct CustomTeleport
    {
        bool teleporting = false;
        int shipId = -1;
        int roomId;
        int slotId;
    };

    CustomTeleport customTele;

    void InitiateTeleport(int shipId, int roomId=-1, int slotId=-1);
    bool CanTeleportMove(bool toOtherShip);

    void Initialize(CrewBlueprint& bp, int shipId, bool enemy, CrewAnimation *animation, bool isTransform = false);
    bool TransformRace(const std::string& newRace);
    static void TransformColors(CrewBlueprint& bp, CrewBlueprint *newBlueprint);

    ActivatedPower *GetFirstCrewPower()
    {
        for (ActivatedPower *power : crewPowers)
        {
            if (power->enabled) return power;
        }
        return nullptr;
    }

    void ClearCrewPowers()
    {
        for (ActivatedPower *power : crewPowers)
        {
            delete power;
        }
        crewPowers.clear();
        for (ActivatedPowerResource *resource : powerResources)
        {
            delete resource;
        }
        powerResources.clear();
        powerResourceMap.clear();
    }

    CrewMember_Extend()
    {
        selfId = Globals::GetNextSpaceId();
    }

    ~CrewMember_Extend()
    {
        delete passiveHealTimer;
        delete deathTimer;

        for (ActivatedPower *power : crewPowers)
        {
            delete power;
        }
        for (ActivatedPowerResource *resource : powerResources)
        {
            delete resource;
        }
    }

    void UpdateAbilityStatBoosts(CrewDefinition *def);
    void UpdateAbilityStatBoosts();

    std::pair<float,int> statCache[numCachedStats] = {};

    bool BoostCheck(StatBoost& statBoost, int checkRoomId=-1);
    bool CheckExtraCondition(CrewExtraCondition condition);
    int CalculateMaxHealth(const CrewDefinition* def);
    float CalculateStat(CrewStat stat, const CrewDefinition* def, bool* boolValue=nullptr);
    int CalculateDangerRating(float health, int roomId);

    std::string GetRace();
    CrewDefinition *GetDefinition();

    float CalculateStat(CrewStat stat, bool* boolValue=nullptr)
    {
        return CalculateStat(stat, GetDefinition(), boolValue);
    }

    bool IsInvulnerable();

    bool IsController(bool ai);
};

CrewMember_Extend* Get_CrewMember_Extend(const CrewMember* c);
CrewAnimation_Extend* Get_CrewAnimation_Extend(CrewAnimation *c);

#define CM_EX Get_CrewMember_Extend
#define CMA_EX Get_CrewAnimation_Extend
