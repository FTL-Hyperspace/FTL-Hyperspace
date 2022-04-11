#pragma once
#include "CustomCrewCommon.h"
#include "Global.h"
#include "ToggleValue.h"
#include "CrewSpawn.h"
#include "CustomDamage.h"
#include <unordered_map>

extern CrewMember *currentCrewLoop;

enum TransformColorMode
{
    KEEP_COLORS,
    KEEP_INDICES
};

enum class CrewExtraCondition : unsigned int
{
    BURNING = 0,
    SUFFOCATING,
    MIND_CONTROLLED,
    STUNNED,
    REPAIRING,
    REPAIRING_SYSTEM,
    REPAIRING_BREACH,
    FIGHTING,
    SABOTAGING,
    SHOOTING,
    MOVING,
    IDLE,
    MANNING,
    FIREFIGHTING,
    DYING,
    TELEPORTING
};

extern TransformColorMode g_transformColorMode;
extern bool g_resistsMindControlStat;

extern int requiresFullControl;
extern bool isTelepathicMindControl;

extern bool shipFriendlyFire;
extern bool blockDamageArea;

struct StatBoostDefinition;
struct StatBoost;

struct Skill
{
    int requirement;
    float levels[4];
};

struct SkillsDefinition
{
    SkillsDefinition()
    {
        skills["piloting"] = Skill();

        skills["piloting"].requirement = 15;
        skills["piloting"].levels[0] = 0.f;
        skills["piloting"].levels[1] = 5.f;
        skills["piloting"].levels[2] = 7.f;
        skills["piloting"].levels[3] = 10.f;

        skills["engines"] = Skill();

        skills["engines"].requirement = 15;
        skills["engines"].levels[0] = 0.f;
        skills["engines"].levels[1] = 5.f;
        skills["engines"].levels[2] = 7.f;
        skills["engines"].levels[3] = 10.f;

        skills["shields"] = Skill();

        skills["shields"].requirement = 55;
        skills["shields"].levels[0] = 1.f;
        skills["shields"].levels[1] = 1.1f;
        skills["shields"].levels[2] = 1.25f;
        skills["shields"].levels[3] = 1.3f;

        skills["weapons"] = Skill();

        skills["weapons"].requirement = 65;
        skills["weapons"].levels[0] = 0.f;
        skills["weapons"].levels[1] = 0.9f;
        skills["weapons"].levels[2] = 0.85f;
        skills["weapons"].levels[3] = 0.8f;

        skills["repair"] = Skill();

        skills["repair"].requirement = 18;
        skills["repair"].levels[0] = 1.0f;
        skills["repair"].levels[1] = 1.0f;
        skills["repair"].levels[2] = 1.1f;
        skills["repair"].levels[3] = 1.2f;

        skills["combat"] = Skill();

        skills["combat"].requirement = 8;
        skills["combat"].levels[0] = 1.0f;
        skills["combat"].levels[1] = 1.0f;
        skills["combat"].levels[2] = 1.1f;
        skills["combat"].levels[3] = 1.2f;

    }

    std::map<std::string, Skill> skills = std::map<std::string, Skill>();
};

struct DroneAI
{
    bool hasCustomAI = false;
    bool fightAI = false;
    bool repairAI = false;
    bool manAI = false;
    bool batteryAI = false;
    bool returnToDroneRoom = false;
};

struct TemporaryPowerDefinition
{
    float duration;

    std::string effectAnim;
    std::string effectFinishAnim;
    std::string animSheet;
    bool baseVisible = true;
    bool soundsEnemy = true;
    std::vector<std::string> sounds;

    ToggleValue<int> maxHealth;
    ToggleValue<float> stunMultiplier;
    ToggleValue<float> moveSpeedMultiplier;
    ToggleValue<float> damageMultiplier;
    ToggleValue<float> rangedDamageMultiplier;
    ToggleValue<float> doorDamageMultiplier;
    ToggleValue<float> repairSpeed;
    ToggleValue<float> fireRepairMultiplier;
    ToggleValue<bool> controllable;
    ToggleValue<bool> canFight;
    ToggleValue<bool> canRepair;
    ToggleValue<bool> canSabotage;
    ToggleValue<bool> canMan;
    ToggleValue<bool> canTeleport;
    ToggleValue<bool> canSuffocate;
    ToggleValue<bool> canBurn;
    ToggleValue<float> oxygenChangeSpeed;
    ToggleValue<bool> canPhaseThroughDoors;
    ToggleValue<float> fireDamageMultiplier;
    ToggleValue<bool> isTelepathic;
    ToggleValue<bool> resistsMindControl;
    ToggleValue<bool> isAnaerobic;
    ToggleValue<bool> detectsLifeforms;
    ToggleValue<float> damageTakenMultiplier;
    ToggleValue<float> passiveHealAmount;
    ToggleValue<float> truePassiveHealAmount;
    ToggleValue<float> healAmount;
    ToggleValue<float> trueHealAmount;
    ToggleValue<int> passiveHealDelay;
    ToggleValue<float> sabotageSpeedMultiplier;
    ToggleValue<float> allDamageTakenMultiplier;
    ToggleValue<float> healSpeed;
    ToggleValue<float> suffocationModifier;
    ToggleValue<float> healCrewAmount;
    ToggleValue<int> powerDrain;
    ToggleValue<bool> powerDrainFriendly;
    ToggleValue<int> bonusPower;
    ToggleValue<float> damageEnemiesAmount;
    ToggleValue<bool> hackDoors;
    ToggleValue<float> powerRechargeMultiplier;
    ToggleValue<bool> noClone;
    ToggleValue<bool> noAI;
    ToggleValue<bool> validTarget;

    std::vector<StatBoostDefinition*> statBoosts;

    bool invulnerable;
    int animFrame = -1;

    GL_Color cooldownColor;
};

struct ActivatedPowerRequirements
{
    bool playerShip = false;
    bool enemyShip = false;
    bool checkRoomCrew = false;
    bool enemyInRoom = false;
    bool friendlyInRoom = false;
    std::vector<std::string> whiteList;
    std::vector<std::string> friendlyWhiteList;
    std::vector<std::string> friendlyBlackList;
    std::vector<std::string> enemyWhiteList;
    std::vector<std::string> enemyBlackList;
    bool systemInRoom = false;
    bool systemDamaged = false;
    bool hasClonebay = false;
    bool aiDisabled = false;
    bool outOfCombat = false;
    bool inCombat = false;
    int requiredSystem = -1;
    bool requiredSystemFunctional = false;
    ToggleValue<int> minHealth;
    ToggleValue<int> maxHealth;
    std::vector<std::pair<CrewExtraCondition,bool>> extraConditions = std::vector<std::pair<CrewExtraCondition,bool>>();
    std::vector<std::pair<CrewExtraCondition,bool>> extraOrConditions = std::vector<std::pair<CrewExtraCondition,bool>>();
    TextString extraOrConditionsTooltip;
};

struct ActivatedPowerDefinition
{
    ActivatedPowerDefinition()
    {
        damage = Damage();
        damage.iDamage = 0;
        damage.iShieldPiercing = 0;
        damage.fireChance = 0;
        damage.breachChance = 0;
        damage.stunChance = 0;
        damage.iIonDamage = 0;
        damage.iSystemDamage = 0;
        damage.iPersDamage = 0;
        damage.bHullBuster = false;
        damage.ownerId = -1;
        damage.selfId = -1;
        damage.bLockdown = false;
        damage.crystalShard = false;
        damage.bFriendlyFire = false;
        damage.iStun = 0;
        sounds = std::vector<std::string>();
        buttonLabel = TextString();
        cooldownColor = GL_Color(133.f / 255.f, 231.f / 255.f, 237.f / 255.f, 1.f);
        tempPower = TemporaryPowerDefinition();
        tempPower.cooldownColor = GL_Color(1.f, 1.f, 1.f, 1.f);
        playerReq = ActivatedPowerRequirements();
        enemyReq = ActivatedPowerRequirements();
    }

    enum JUMP_COOLDOWN
    {
        JUMP_COOLDOWN_FULL,
        JUMP_COOLDOWN_RESET,
        JUMP_COOLDOWN_CONTINUE
    };

    static std::vector<ActivatedPowerDefinition> powerDefs;

    void AssignIndex()
    {
        this->index = powerDefs.size();
        powerDefs.push_back(*this);
    }

    unsigned int index = 0;

    Damage damage;
    float cooldown = 50.f;
    float shipFriendlyFire = false;
    bool hasSpecialPower = false;
    bool hasTemporaryPower = false;
    int jumpCooldown = JUMP_COOLDOWN_FULL;

    int powerCharges = -1;
    int initialCharges = 2147483647;
    int chargesPerJump = 1073741823;


    std::vector<std::string> sounds;
    bool soundsEnemy = true;


    TextString buttonLabel;
    GL_Color cooldownColor;

    TextString tooltip;
    std::string effectAnim;

    ActivatedPowerRequirements playerReq;
    ActivatedPowerRequirements enemyReq;

    ActivatedPowerRequirements *chargeReq = nullptr;

    bool win = false;
    float crewHealth = 0.f;
    float enemyHealth = 0.f;
    float selfHealth = 0.f;
    int animFrame = -1;
    bool followCrew = false;

    bool activateWhenReady = false;
    bool activateReadyEnemies = false;
    std::string transformRace = "";

    std::vector<CrewSpawn*> crewSpawns;

    std::vector<StatBoostDefinition*> statBoosts;

    std::array<std::string,2> event = {"",""};

    TemporaryPowerDefinition tempPower;
};

struct CrewDefinition
{
    std::string race;
    std::vector<std::string> deathSounds;
    std::vector<std::string> deathSoundsFemale;
    std::vector<std::string> shootingSounds;
    std::vector<std::string> repairSounds;
    int repairSoundFrame = -1;

    bool canFight = true;
    bool canRepair = true;
    bool canSabotage = true;
    bool canMan = true;
    bool canTeleport = true;
    bool canSuffocate = true;
    bool controllable = true;
    bool selectable = false;
    bool canBurn = true;
    int maxHealth = 100;
    float stunMultiplier = 1.f;
    float moveSpeedMultiplier = 1.f;
    float repairSpeed = 1.f;
    float damageMultiplier = 1.f;
    float rangedDamageMultiplier = 1.f;
    float doorDamageMultiplier = 1.f;
    bool providesPower = false;
    int bonusPower = 0;
    float fireRepairMultiplier = 1.2f;
    float suffocationModifier = 1.f;
    bool isTelepathic = false;
    bool resistsMindControl = false;
    bool isAnaerobic = false;
    float fireDamageMultiplier = 1.f;
    bool canPhaseThroughDoors = false;
    float oxygenChangeSpeed = 0.f;
    float damageTakenMultiplier = 1.f;
    float passiveHealAmount = 0.f;
    float truePassiveHealAmount = 0.f;
    float healAmount = 0.f;
    float trueHealAmount = 0.f;
    int passiveHealDelay = 0;
    bool detectsLifeforms = false;
    bool hasCustomDeathAnimation = false;
    bool hasDeathExplosion = false;
    std::string animBase = "human";
    std::string animSheet[2] = {"",""};
    float sabotageSpeedMultiplier = 1.f;
    float allDamageTakenMultiplier = 1.f;
    int defaultSkillLevel = 0;
    float healSpeed = 1.f;
    bool cloneLoseSkills = true;
    float healCrewAmount = 0.f;
    DroneAI droneAI;
    bool droneMoveFromManningSlot;
    int powerDrain = 0;
    bool powerDrainFriendly = false;
    float damageEnemiesAmount = 0.f;
    bool hackDoors = false;
    float powerRechargeMultiplier = 1.f;
    bool noSlot = false;
    bool noClone = false;
    bool noAI = false;
    bool validTarget = true;
    bool canPunch = true;
    float essential = 0.f;

    std::pair<int,int> shootTimer = {-1, -1};
    std::pair<int,int> punchTimer = {-1, -1};

    ExplosionDefinition explosionDef;

    //ActivatedPowerDefinition powerDef;
    unsigned int powerDefIdx = 0;
    ActivatedPowerDefinition* GetPowerDef() const
    {
        return &ActivatedPowerDefinition::powerDefs[powerDefIdx];
    }

    std::vector<StatBoostDefinition*> passiveStatBoosts;

    std::vector<std::string> nameRace;
    std::vector<std::string> transformName;
    bool changeIfSame = true;


    SkillsDefinition skillsDef;
};

class CustomCrewManager
{
public:
    CustomCrewManager()
    {
        ActivatedPowerDefinition powerDef;
        powerDef.AssignIndex();
    }



    void AddCrewDefinition(CrewDefinition crew);
    void ParseDeathEffect(rapidxml::xml_node<char>* stat, ExplosionDefinition* explosionDef);
    void ParseAbilityEffect(rapidxml::xml_node<char>* stat, ActivatedPowerDefinition* powerDef);
    void ParsePowerRequirementsNode(rapidxml::xml_node<char> *node, ActivatedPowerRequirements *def);
    void ParseExtraConditionsNode(rapidxml::xml_node<char> *node, std::vector<std::pair<CrewExtraCondition,bool>> &extraConditions);
    void ParseCrewNode(rapidxml::xml_node<char> *node);
    CrewMember* CreateCrewMember(CrewBlueprint* bp, int shipId, bool intruder);
    bool IsRace(const std::string& race);
    void SetupVTable(CrewMember *crew);
    void SwapVTable(void** vtable, int index, void* swapTo);

    CrewDefinition* GetDefinition(const std::string& name)
    {
        return &(this->blueprintNames[name]);
    }

    CrewDefinition* GetDroneRaceDefinition(CrewDrone *drone);

    std::vector<std::string> GetBlueprintNames()
    {
        std::vector<std::string> ret = std::vector<std::string>();

        for (auto i : blueprintNames)
        {
            ret.push_back(i.first);
        }

        return ret;
    }

    static CustomCrewManager *GetInstance()
    {
        return &instance;
    }

private:
    static CustomCrewManager instance;

    std::unordered_map<std::string, CrewDefinition> blueprintNames;
};
