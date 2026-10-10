#pragma once
#include "Global.h"

void ParseSystemsNode(rapidxml::xml_node<char>* node);
class CustomMindSystem
{
public:
    struct MindLevel
    {
        float damageBoost;
        float healthBoost;
        float duration;
        int lock;
        int count;
    };
    static void ParseSystemNode(rapidxml::xml_node<char>* node);
    static MindLevel& GetLevel(MindSystem* system);

private:
    static MindLevel defaultLevel;
    static std::vector<MindLevel> levels;
};

class CustomCloneSystem
{
public:
    struct CloneLevel
    {
        int jumpHP;
        int jumpHPPercent;
        int cloneHPPercent;
        int skillLossPercent;
        float cloneSpeed;
        float deathSpeed;
        int count; // Number of clones, unused for now, still here with the xml implementation for a later use
    };
    static void ParseSystemNode(rapidxml::xml_node<char>* node);
    static CloneLevel& GetLevel(CloneSystem* system, bool passive);

    static CloneLevel& GetLevel(int power);
private:
    static CloneLevel defaultLevel;
    static std::vector<CloneLevel> levels;
};

class CustomUserSystems
{
public:
    static void ParseSystemNode(rapidxml::xml_node<char>* node);
    static int NameToSystemId(const std::string& systemName);
    static std::string SystemIdToName(int systemId);
    static int GetLastSystemId();
    static bool IsCustomSubSystem(int systemId);
    static bool AnyCustomSubSystems();
private:
    static void AddSystemName(const std::string& systemName);
    static std::vector<std::string> systemNames;
    static std::unordered_map<std::string, int> systemIds; //For quicker NameToSystemId;
    static std::unordered_set<std::string> subSystems;
};
class SystemExclusivityManager
{
public:
    bool AreSystemsExclusive(int sysId_1, int sysId_2);
    void ParseExclusivityNode(rapidxml::xml_node<char>* node);
    static SystemExclusivityManager* GetGlobalManager();
private:
    int currentExclusivityIndex = 0;
    std::unordered_map<int, int> exclusivityGroups; // systemId, group
};

struct SystemPosition
{
    int position;
    bool staticallyPositioned;
    int staticOffset;
};
class SystemPositionManager
{
public:
    static void ParsePositionsNode(rapidxml::xml_node<char>* node);
    static const SystemPosition* GetSystemPosition(int systemId);
    static int subSystemOffset;
private:
    static std::unordered_map<int, SystemPosition> systemPositions;
    static const SystemPosition defaultPosition;
};

extern float leakModifiers[2]; // [0] = player, [1] = enemy
