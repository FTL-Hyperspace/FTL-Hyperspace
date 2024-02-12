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
    TextString descriptionOverride;
    TextString advancedDescriptionOverride;
    TextString tooltipOverride;
    TextString advancedTooltipOverride;
    bool hideEventTooltip = false;
    bool invisibleBeam = false;
    bool simultaneousFire = false;
    float fireTime = 0.f;
    float angularRadius = -1.f;

    std::string iconReplace;
    float iconScale = 1.f;

    CustomDamageDefinition *customDamage;

    std::unordered_map<std::string, std::string> miniProjectileOverride;
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

    static void ProcessMiniProjectile(Projectile *proj, const WeaponBlueprint *bp, int boostLevel = 0);

private:
};
