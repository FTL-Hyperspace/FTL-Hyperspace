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