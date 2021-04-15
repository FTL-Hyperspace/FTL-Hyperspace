#pragma once
#include "Global.h"

struct CustomWeaponDefinition
{
    std::string name;

    int freeMissileChance;
    std::string descriptionOverride;
    bool hideEventTooltip = false;
};

class CustomWeaponManager
{
public:
    static CustomWeaponManager* instance;

    void AddWeaponDefinition(CustomWeaponDefinition& weaponDef)
    {
        weaponDefs[weaponDef.name] = weaponDef;
    }

    CustomWeaponDefinition* GetWeaponDefinition(const std::string& bpName)
    {
        if (weaponDefs.find(bpName) != weaponDefs.end())
        {
            return &weaponDefs[bpName];
        }

        return nullptr;
    }
    std::unordered_map<std::string, CustomWeaponDefinition> weaponDefs;

private:
};
