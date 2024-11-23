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

//Planned feature
//allow xml control for heal per jump (hp and hp%)
////hook CloneSystem::GetJumpHealth and ShipManager::CloneHealing
//allow xml control for health when cloned
//allow xml control for skill loss when cloned
////hook CrewMember::Clone
//allow xml control for clone death speed
////hook CloneSystem::GetDeathProgress
//allow xml control for clone speed
////hook CloneSystem::GetProgress or loop
//allow those value to be affected by augments
//TBD if we can allow for multiple clones at the same time

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
        int count;
    };
    static void ParseSystemNode(rapidxml::xml_node<char>* node);
    static CloneLevel& GetLevel(CloneSystem* system, bool passive);
    
    static CloneLevel& GetLevel(int power);
private:
    static CloneLevel defaultLevel;
    static std::vector<CloneLevel> levels;
};
