#pragma once
#include <string>
#include <vector>
#include <map>
#include "rapidxml.hpp"
#include "StatBoost.h"

struct AugmentSuperShield
{
    int value = 0;
    int add = 0;
    bool customRender = false;
    std::string shieldTexture[2] = {"", ""};
    GL_Color shieldColor = GL_Color(0.392156862f,1.f,0.392156862f,1.f);
};

struct AugmentFunction
{
    float value;
    bool preferHigher = true;
    bool useForReqs = true;
    bool warning = true;
};

struct AugmentDefinition
{
    std::string name;
    std::map<std::string, AugmentFunction> functions = std::map<std::string, AugmentFunction>();
    AugmentSuperShield superShield;
    bool locked = false;
    std::vector<StatBoostDefinition> statBoosts = std::vector<StatBoostDefinition>();
};


class CustomAugmentManager
{
public:
    CustomAugmentManager()
    {

    }

    void ParseCustomAugmentNode(rapidxml::xml_node<char>* node);

    std::map<std::string, AugmentFunction> GetPotentialAugments(const std::string& name, bool req=false);

    AugmentDefinition* GetAugmentDefinition(const std::string& name)
    {
        return augDefs[name];
    }

    bool IsAugment(const std::string& name)
    {
        return augDefs.find(name) != augDefs.end();
    }

    bool superShieldCustomRender[2] = {false, false};
    std::string superShieldTexture[2] = {"", ""};
    GL_Color superShieldColor[2] = {GL_Color(0.f,0.f,0.f,0.f), GL_Color(0.f,0.f,0.f,0.f)};

    static std::map<std::string, int> CheckHiddenAugments(const std::map<std::string, int>& augList);
    static std::vector<std::string> RemoveHiddenAugments(const std::vector<std::string>& augList);

    static int GetSuperShieldValue(int shipId);

    static CustomAugmentManager* GetInstance()
    {
        return &instance;
    }

private:
    std::map<std::string, AugmentDefinition*> augDefs;
    static CustomAugmentManager instance;

};

