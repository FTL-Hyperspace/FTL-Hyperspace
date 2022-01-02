#pragma once
#include <string>
#include <vector>
#include <map>
#include "rapidxml.hpp"
#include "StatBoost.h"
#include "EnemyShipIcons.h"

struct AugmentSuperShield
{
    int value = 0;
    int add = 0;
    bool customRender = false;
    bool present = false;
    std::string shieldTexture[2] = {"", ""};
    GL_Color shieldColor = GL_Color(0.392156862f,1.f,0.392156862f,1.f);
};

struct AugmentCrystalShard
{
    std::string weapon = "";
    float chance = 0.f;
    int stacking = 0;
};

struct AugmentFunction
{
    float value;
    bool preferHigher = true;
    bool useForReqs = true;
    bool warning = true;
    int sys = -1;
    bool modifyChoiceTextScrap = false;

    bool Functional(int iShipId);
};

struct AugmentDefinition
{
    std::string name;
    std::unordered_map<std::string, AugmentFunction> functions = std::unordered_map<std::string, AugmentFunction>();
    AugmentSuperShield superShield;
    std::vector<AugmentCrystalShard> crystalShard;
    bool locked = false;
    std::vector<StatBoostDefinition*> statBoosts = std::vector<StatBoostDefinition*>();

    std::string icon;
    int iconShipId = -1;
};


class CustomAugmentManager
{
public:
    CustomAugmentManager()
    {

    }

    void ParseCustomAugmentNode(rapidxml::xml_node<char>* node);

    std::unordered_map<std::string, AugmentFunction*>* GetPotentialAugments(const std::string& name, bool req=false);

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
    std::unordered_map<std::string, int>* GetShipAugments(int iShipId);
    std::vector<ShipIcon*>& GetAugIconList(int iShipId)
    {
        return augIconList[iShipId];
    }

    void UpdateAugments(int iShipId);

    static int GetSuperShieldValue(int shipId);

    static CustomAugmentManager* GetInstance()
    {
        return &instance;
    }

private:
    std::map<std::string, AugmentDefinition*> augDefs;
    std::unordered_map<std::string, std::unordered_map<std::string, AugmentFunction*>> augDefsByFunction;
    std::unordered_map<std::string, std::unordered_map<std::string, AugmentFunction*>> augDefsByReq;
    static CustomAugmentManager instance;
    std::unordered_map<std::string, int> augListWithHidden[2];
    std::vector<std::string> augListNoHidden[2];
    std::vector<ShipIcon*> augIconList[2];
};

int HasAugmentationById(const std::string& name, int iShipId);
