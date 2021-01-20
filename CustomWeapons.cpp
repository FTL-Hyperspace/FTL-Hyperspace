#include "CustomWeapons.h"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

CustomWeaponManager *CustomWeaponManager::instance = new CustomWeaponManager();

HOOK_STATIC(BlueprintManager, ProcessWeaponBlueprint, (WeaponBlueprint* bp, BlueprintManager *bpM, rapidxml::xml_node<char>* node) -> WeaponBlueprint*)
{
    super(bp, bpM, node);

    auto weaponDef = CustomWeaponDefinition();
    weaponDef.name = node->first_attribute("name")->value();

    for (auto child = node->first_node(); child = child->next_sibling(); child)
    {
        std::string name = child->name();
        std::string val = child->value();

        if (name == "freeMissileChance")
        {
            weaponDef.freeMissileChance = boost::lexical_cast<int>(val);

        }
        if (name == "descriptionOverride")
        {
            weaponDef.descriptionOverride = val;
        }
    }

    CustomWeaponManager::instance->AddWeaponDefinition(weaponDef);

    return bp;
}

HOOK_METHOD(ShipManager, OnRender, (bool showInterior, bool doorControlMode) -> void)
{
    if (bJumping)
    {
        auto time = jumpAnimation.current_time;
        if (time >= 1.0)
        {
            CSurface::GL_SetColorTint(255.f, 255.f, 255.f, 1.f - ((time - 1.f) * 2.f));
            RenderWeapons();
            CSurface::GL_RemoveColorTint();
        }
        else
        {
            RenderWeapons();
        }
    }
    super(showInterior, doorControlMode);

}

static bool artillery = false;

HOOK_METHOD(ProjectileFactory, NumTargetsRequired, () -> int)
{
    int ret = super();

    if (artillery)
    {
        int rooms = ShipGraph::GetShipInfo(!iShipId)->rooms.size();
        if (ret > rooms)
        {
            return rooms;
        }
    }

    return ret;
}

HOOK_METHOD(ArtillerySystem, OnLoop, () -> void)
{
    artillery = true;
    super();
    artillery = false;
}

HOOK_METHOD(ProjectileFactory, SpendMissiles, () -> int)
{
    if (iSpendMissile > 0)
    {
        int randomNum = random32() % 100;

        if (randomNum < CustomWeaponManager::instance->GetWeaponDefinition(blueprint->name)->freeMissileChance)
        {
            iSpendMissile = 0;
        }
    }

    return super();
}

// Weapon Types:
// 0: LASER
// 1: MISSILES
// 2: BEAM
// 3: BOMB
// 4: BURST

HOOK_STATIC(WeaponBlueprint, GetDescription, (std::string* strRef, WeaponBlueprint *bp, bool tooltip) -> void)
{
    if (tooltip) return super(strRef, bp, tooltip);
    super(strRef, bp, tooltip);

    auto tLib = G_->GetTextLibrary();
    std::string descText = "";
    std::string currentText = "";

    auto weaponDef = CustomWeaponManager::instance->GetWeaponDefinition(bp->name);

    if (!weaponDef->descriptionOverride.empty())
    {
        std::string newDesc = weaponDef->descriptionOverride;

        strRef->assign(boost::algorithm::replace_all_copy(newDesc, "\\n", "\n"));
        return;
    }



    descText += bp->desc.description.GetText() + "\n\n";

    currentText = tLib->GetText("required_power");
    descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->power)) + "\n";

    currentText = tLib->GetText("charge_time");

    std::stringstream cooldownString;
    cooldownString << bp->cooldown;


    descText += boost::algorithm::replace_all_copy(currentText, "\\1", cooldownString.str()) + "\n";

    if (bp->boostPower.count > 1)
    {
        std::string boostType = "";

        if (bp->boostPower.type == 2)
        {
            boostType += tLib->GetText("boost_power_damage") + "\n";

            int dmg = bp->damage.iIonDamage;
            if (dmg <= 0)
            {
                dmg = bp->damage.iDamage;
            }

            std::stringstream damageCapString;
            damageCapString << (bp->boostPower.count * bp->boostPower.amount + dmg);

            currentText = tLib->GetText("damage_cap");
            boostType += boost::algorithm::replace_all_copy(currentText, "\\1", damageCapString.str()) + "\n";
        }
        else
        {
            boostType += tLib->GetText("boost_power_speed") + "\n";

            currentText = tLib->GetText("speed_cap");

            std::stringstream speedCapString;
            speedCapString << bp->cooldown - (bp->boostPower.count * bp->boostPower.amount);

            boostType += boost::algorithm::replace_all_copy(currentText, "\\1", speedCapString.str()) + "\n";
        }

        descText += boostType;
    }

    if (bp->missiles > 0)
    {
        descText += tLib->GetText("requires_missiles") + "\n";
    }

    if ((bp->type == 0 || bp->type == 1) && bp->shots > 0)
    {
        currentText = tLib->GetText("shots");
        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->shots)) + "\n";
    }

    if (bp->type == 4)
    {
        currentText = tLib->GetText("shots");
        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->miniCount)) + "\n";
    }

    if (bp->chargeLevels > 1)
    {
        currentText = tLib->GetText("charge");
        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->chargeLevels)) + "\n";
    }

    if (bp->type == 2)
    {
        currentText = tLib->GetText("damage_room");
        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iDamage)) + "\n";
    }
    else
    {
        currentText = tLib->GetText("damage_shot");
        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iDamage)) + "\n";
    }

    if (bp->damage.iShieldPiercing > 0)
    {
        currentText = tLib->GetText("shield_piercing");
        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iShieldPiercing)) + "\n";
    }

    if (bp->damage.fireChance > 0)
    {
        currentText = tLib->GetText("fire_chance");
        boost::algorithm::replace_all(currentText, "\\1", std::to_string(bp->damage.fireChance * 10));

        std::string level = tLib->GetText("chance_low");
        if (bp->damage.fireChance >= 7)
        {
            level = tLib->GetText("chance_high");
        }
        else if (bp->damage.fireChance >= 4)
        {
            level = tLib->GetText("chance_med");
        }

        boost::algorithm::replace_all(currentText, "\\2", level);

        descText += currentText + "\n";

    }
    if (bp->damage.breachChance > 0)
    {
        currentText = tLib->GetText("breach_chance");
        boost::algorithm::replace_all(currentText, "\\1", std::to_string(bp->damage.breachChance * 10));
        boost::algorithm::replace_all(currentText, "\\2", std::to_string(bp->damage.breachChance * 10 - bp->damage.fireChance * bp->damage.breachChance));

        std::string level = tLib->GetText("chance_low");
        if (bp->damage.breachChance >= 7)
        {
            level = tLib->GetText("chance_high");
        }
        else if (bp->damage.breachChance >= 4)
        {
            level = tLib->GetText("chance_med");
        }

        boost::algorithm::replace_all(currentText, "\\3", level);

        descText += currentText + "\n";
    }
    if (bp->damage.stunChance > 0 && Settings::GetDlcEnabled())
    {
        currentText = tLib->GetText("stun_chance");
        boost::algorithm::replace_all(currentText, "\\1", std::to_string(bp->damage.stunChance * 10));

        std::string level = tLib->GetText("chance_low");
        if (bp->damage.stunChance >= 7)
        {
            level = tLib->GetText("chance_high");
        }
        else if (bp->damage.stunChance >= 4)
        {
            level = tLib->GetText("chance_med");
        }

        boost::algorithm::replace_all(currentText, "\\2", level);

        descText += currentText + "\n";
    }

    if (bp->damage.iIonDamage > 0)
    {
        currentText = tLib->GetText("ion_damage");
        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iIonDamage)) + "\n";
    }
    if (bp->damage.iStun > 0)
    {
        currentText = tLib->GetText("stun_damage");
        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iStun)) + "\n";
    }
    if (bp->damage.iPersDamage > 0)
    {
        currentText = tLib->GetText("personnel_damage");
        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iPersDamage * 15)) + "\n";
    }
    if (bp->damage.iSystemDamage > 0)
    {
        currentText = tLib->GetText("system_damage");
        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iSystemDamage)) + "\n";
    }
    if (bp->damage.bHullBuster)
    {
        descText += tLib->GetText("double_damage") + "\n";
    }
    if (weaponDef->freeMissileChance > 0)
    {
        currentText = tLib->GetText("free_missile_chance");
        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(weaponDef->freeMissileChance)) + "\n";
    }

    strRef->assign(descText);
}
