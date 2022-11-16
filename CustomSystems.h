#pragma once
#include "Global.h"


void ParseSystemsNode(rapidxml::xml_node<char>* node);

class CustomSystemManager
{
public:
    CustomSystemManager()
    {
        engineDodgeLevels.defaultLevels = {5,10,15,20,25,28,31,35}; //used for default values in the description and tooltips.
    }

    static CustomSystemManager *GetInstance()
    {
        return &instance;
    }

    template<typename T> struct CustomSystemLevels
    {
        std::vector<std::pair<T,T>> systemLevels = std::vector<std::pair<T,T>>();
        std::pair<T,T> hackLevels = std::pair<T,T>();
        std::vector<T> defaultLevels = std::vector<T>();
    };

    CustomSystemLevels<int> engineDodgeLevels;
    CustomSystemLevels<float> engineChargeLevels;

    CustomSystemLevels<float> oxygenLevels;

    void ParseSystemNode(rapidxml::xml_node<char>* node);

    template<typename T> 
    void ParseLevelValues(rapidxml::xml_node<char>* node, std::pair<T,T> &levelPair);

private:
    static CustomSystemManager instance;
};