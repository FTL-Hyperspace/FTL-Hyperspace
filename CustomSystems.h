#pragma once
#include "Global.h"

void ParseSystemsNode(rapidxml::xml_node<char>* node);

class CustomSystemManager
{
public:
    CustomSystemManager()
    {
        engineDodgeLevels.defaultLevels = {5,10,15,20,25,28,31,35};
    }

    static CustomSystemManager *GetInstance()
    {
        return &instance;
    }

    template<typename T> struct CustomSystemLevels
    {
        std::vector<std::pair<T,T>> systemLevels = std::vector<std::pair<T,T>>();
        std::pair<T,T> hackLevel = std::pair<T,T>();
        std::vector<T> defaultLevels = std::vector<T>();
    };

    CustomSystemLevels<int> engineDodgeLevels;
    CustomSystemLevels<float> engineChargeLevels;

    CustomSystemLevels<float> oxgyenLevels;

    void ParseSystemNode(rapidxml::xml_node<char>* node);

private:
    static CustomSystemManager instance;
};