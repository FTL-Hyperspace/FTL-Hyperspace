#pragma once
#include "Global.h"

struct WeaponAttribute
{
    enum class MathType
    {
        SET,
        FLAT,
        MULT
    };

    std::string attribute;
    float amount;
};

struct WeaponModifier
{
    std::string name;
    std::vector<std::string> targets;
    std::string titleSuffix;
    std::string descriptionSuffix;

    std::vector<WeaponAttribute> attributes;
};

struct CustomWeaponDefinition
{
    std::string name;

    int freeMissileChance;
    std::string descriptionOverride;
    bool hideEventTooltip = false;
    bool simultaneousFire = false;
    float fireTime = 0.f;
    float angularRadius = -1.f;

    CustomDamage customDamage;
};

class CustomWeaponManager
{
public:
    static CustomWeaponManager* instance;
    static CustomWeaponDefinition* currentWeapon;

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
