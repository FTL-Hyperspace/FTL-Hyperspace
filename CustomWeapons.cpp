#include "CustomWeapons.h"
#include "CustomOptions.h"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <iomanip>

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
        if (name == "hideEventTooltip")
        {
            weaponDef.hideEventTooltip = EventsParser::ParseBoolean(val);
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

HOOK_STATIC(WeaponBox, GenerateTooltip, (std::string &retStr, WeaponBox *_this) -> void)
{
    super(retStr, _this);

    auto tLib = G_->GetTextLibrary();
    std::string descText = "";
    std::string currentText = "";
    auto bp = _this->pWeapon->blueprint;

    auto weaponDef = CustomWeaponManager::instance->GetWeaponDefinition(bp->name);

    if (CustomOptionsManager::GetInstance()->redesignedWeaponTooltips.currentValue == true)
    {
        if (bp->power > 0)
        {
            currentText = tLib->GetText("required_power");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->power)) + "\n";
        }
        else if (bp->power == 0)
        {
            if (bp->cooldown >= 0)
            {
                currentText = tLib->GetText("requires_no_power");
                descText += currentText + "\n";
            }
            else
            {
                currentText = tLib->GetText("cannot_fire");
                descText += currentText + "\n";
            }
        }
        else
        {
            currentText = tLib->GetText("provides_bonus_power");
            descText += currentText + ": " + std::to_string(bp->power * -1) + "\n";
        }

        if (bp->cooldown >= 0)
        {
            currentText = tLib->GetText("charge_time");

            std::stringstream cooldownString;
            cooldownString << bp->cooldown;

            descText += boost::algorithm::replace_all_copy(currentText, "\\1", cooldownString.str()) + "\n";
        }
        else
        {
            if (bp->power != 0)
            {
                currentText = tLib->GetText("cannot_fire");
                descText += currentText + "\n";
            }
        }

        if (bp->cooldown >= 0)
        {
            if (bp->missiles > 0)
            {
                currentText = tLib->GetText("ammo_consumption");
                descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->missiles)) + "\n";
            }

            if (weaponDef->freeMissileChance > 0)
            {
                currentText = tLib->GetText("free_missile_chance");
                descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(weaponDef->freeMissileChance)) + "\n";
            }

            if (bp->boostPower.count > 0)
            {
                std::string boostType = "";

                if (bp->boostPower.type == 2)
                {
                    if (bp->boostPower.amount > 0)
                    {
                        currentText = tLib->GetText("redesigned_boost_power_damage_positive");
                        std::stringstream stream;
                        stream << std::setprecision(2) << bp->boostPower.amount;
                        boostType += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str()) + "\n";

                        int dmg = bp->damage.iIonDamage;
                        if (dmg <= 0)
                        {
                            dmg = bp->damage.iDamage;
                        }

                        std::stringstream damageCapString;
                        damageCapString << (bp->boostPower.count * bp->boostPower.amount + dmg);

                        currentText = tLib->GetText("redesigned_damage_cap");
                        currentText = boost::algorithm::replace_all_copy(currentText, "\\1", damageCapString.str());
                        stream.str("");
                        stream.clear();
                        stream << std::setprecision(2) << bp->boostPower.count;
                        boostType += boost::algorithm::replace_all_copy(currentText, "\\2", stream.str()) + "\n";
                    }
                    else
                    {
                        currentText = tLib->GetText("redesigned_boost_power_damage_negative");
                        std::stringstream stream;
                        stream << std::setprecision(2) << bp->boostPower.amount;
                        boostType += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str()) + "\n";

                        int dmg = bp->damage.iIonDamage;
                        if (dmg <= 0)
                        {
                            dmg = bp->damage.iDamage;
                        }

                        std::stringstream damageCapString;
                        damageCapString << (bp->boostPower.count * bp->boostPower.amount + dmg);

                        currentText = tLib->GetText("redesigned_damage_cap");
                        currentText = boost::algorithm::replace_all_copy(currentText, "\\1", damageCapString.str());
                        stream.str("");
                        stream.clear();
                        stream << std::setprecision(2) << bp->boostPower.count;
                        boostType += boost::algorithm::replace_all_copy(currentText, "\\2", stream.str()) + "\n";
                    }
                }
                else
                {
                    if (bp->boostPower.amount > 0)
                    {
                        currentText = tLib->GetText("redesigned_boost_power_speed_positive");
                        std::stringstream stream;
                        stream << std::setprecision(4) << bp->boostPower.amount;
                        boostType += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str()) + "\n";

                        std::stringstream speedCapString;
                        speedCapString << bp->cooldown - (bp->boostPower.count * bp->boostPower.amount);

                        currentText = tLib->GetText("redesigned_speed_cap");
                        currentText = boost::algorithm::replace_all_copy(currentText, "\\1", speedCapString.str());
                        stream.str("");
                        stream.clear();
                        stream << std::setprecision(4) << bp->boostPower.count;
                        boostType += boost::algorithm::replace_all_copy(currentText, "\\2", stream.str()) + "\n";
                    }
                    else
                    {
                        currentText = tLib->GetText("redesigned_boost_power_speed_negative");
                        std::stringstream stream;
                        stream << std::setprecision(4) << bp->boostPower.amount;
                        boostType += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str()) + "\n";

                        std::stringstream speedCapString;
                        speedCapString << bp->cooldown - (bp->boostPower.count * bp->boostPower.amount);

                        currentText = tLib->GetText("redesigned_speed_cap");
                        currentText = boost::algorithm::replace_all_copy(currentText, "\\1", speedCapString.str());
                        stream.str("");
                        stream.clear();
                        stream << std::setprecision(4) << bp->boostPower.count;
                        boostType += boost::algorithm::replace_all_copy(currentText, "\\2", stream.str()) + "\n";
                    }
                }

                descText += boostType;
            }

            // space
            boost::trim_right(descText);
            descText += "\n\n";

            if(bp->radius > 0)
            {
                currentText = tLib->GetText("shot_radius");
                descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->radius)) + "\n";
            }

            if (bp->type == 0 || bp->type == 1 || bp->type == 3 || bp->type == 4)
            {
                if (bp->type == 0 || bp->type == 1 || (bp->shots == 1 && bp->type != 4))
                {
                    currentText = tLib->GetText("shots");
                    descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->shots)) + "\n";
                }
                else if (bp->type == 3)
                {
                    currentText = tLib->GetText("bomb_shots");
                    descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->shots)) + "\n";
                }
                else
                {
                    currentText = tLib->GetText("shots");
                    descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->miniCount * bp->shots)) + "\n";
                }
            }

            if (bp->chargeLevels > 1)
            {
                currentText = tLib->GetText("charge");
                descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->chargeLevels)) + "\n";
            }

            if (bp->type == 2)
            {
                currentText = tLib->GetText("beam_length");
                descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->length)) + "\n";

                currentText = tLib->GetText("swipe_speed");
                if (bp->speed != 0)
                {
                    std::stringstream stream;
                    stream << std::fixed <<std::setprecision(0) << bp->speed;
                    descText += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str()) + "\n";
                }
                else
                {
                    descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(5)) + "\n";
                }
            }

            // space
            boost::trim_right(descText);
            descText += "\n\n";

//            if (bp->drone_targetable != 0)
//            {
//                descText += tLib->GetText("weapon_not_drone_targetable") + "\n";
//            }
//            else
//            {
//                descText += tLib->GetText("weapon_drone_targetable") + "\n";
//            }

            if (bp->damage.bHullBuster)
            {
                descText += tLib->GetText("redesigned_double_damage") + "\n";
            }

//            if (bp->damage.iPersDamage == 0 && bp->damage.iSystemDamage == 0)
//            {
//                if (bp->damage.iDamage != 0)
//                {
//                    if (bp->type == 2)
//                    {
//                        currentText = tLib->GetText("redesigned_damage_room");
//                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iDamage)) + "\n";
//                    }
//                    else
//                    {
//                        currentText = tLib->GetText("redesigned_damage_shot");
//                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iDamage)) + "\n";
//                    }
//                }
//            }
//            else
//            {
//                if (bp->type == 2)
//                {
                    if (bp->damage.iDamage > 0)
                    {
                        currentText = tLib->GetText("hull_damage");
                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iDamage)) + "\n";
                    }
                    else if (bp->damage.iDamage < 0)
                    {
                        currentText = tLib->GetText("hull_damage_negative");
                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iDamage * -1)) + "\n";
                    }

                    if (bp->damage.iDamage >= 0)
                    {
                        if (bp->damage.iSystemDamage + bp->damage.iDamage > 0)
                        {
                            currentText = tLib->GetText("system_damage");
                            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iSystemDamage + bp->damage.iDamage)) + "\n";
                        }
                        else if (bp->damage.iSystemDamage + bp->damage.iDamage < 0)
                        {
                            currentText = tLib->GetText("system_damage_negative");
                            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string((bp->damage.iSystemDamage + bp->damage.iDamage) * -1)) + "\n";
                        }
                        if (bp->damage.iPersDamage + bp->damage.iDamage > 0)
                        {
                            currentText = tLib->GetText("personnel_damage");
                            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string((bp->damage.iDamage + bp->damage.iPersDamage) * 15)) + "\n";
                        }
                        else if (bp->damage.iPersDamage + bp->damage.iDamage < 0)
                        {
                            currentText = tLib->GetText("personnel_damage_negative");
                            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(((bp->damage.iDamage + bp->damage.iPersDamage) * -1) * 15)) + "\n";
                        }

                    }
                    else
                    {
                        if (bp->damage.iSystemDamage > 0)
                        {
                            currentText = tLib->GetText("system_damage");
                            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iSystemDamage)) + "\n";
                        }
                        else if (bp->damage.iSystemDamage < 0)
                        {
                            currentText = tLib->GetText("system_damage_negative");
                            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string((bp->damage.iSystemDamage) * -1)) + "\n";
                        }
                        if (bp->damage.iPersDamage > 0)
                        {
                            currentText = tLib->GetText("personnel_damage");
                            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string((bp->damage.iPersDamage) * 15)) + "\n";
                        }
                        else if (bp->damage.iPersDamage < 0)
                        {
                            currentText = tLib->GetText("personnel_damage_negative");
                            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(((bp->damage.iPersDamage) * -1) * 15)) + "\n";
                        }
                    }
//                }
//                else
//                {
//                    if (bp->damage.iDamage != 0)
//                    {
//                        currentText = tLib->GetText("hull_damage");
//                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iDamage)) + "\n";
//                    }
//                    if (bp->damage.iSystemDamage + bp->damage.iDamage != 0)
//                    {
//                        currentText = tLib->GetText("system_damage");
//                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iSystemDamage + bp->damage.iDamage)) + "\n";
//                    }
//                    if (bp->damage.iPersDamage + bp->damage.iDamage != 0)
//                    {
//                        currentText = tLib->GetText("personnel_damage");
//                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string((bp->damage.iDamage + bp->damage.iPersDamage) * 15)) + "\n";
//                    }
//                }
//            }

            if (bp->damage.iIonDamage != 0)
            {
                currentText = tLib->GetText("ion_damage");
                descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iIonDamage)) + "\n";
            }

            if (bp->damage.iShieldPiercing != 0)
            {
                currentText = tLib->GetText("shield_piercing");
                if (bp->type != 2)
                {
                    descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iShieldPiercing)) + "\n";
                }
                else if (bp->damage.iDamage == 0 && bp->damage.iShieldPiercing - 1 > 0)
                {
                    descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iShieldPiercing - 1)) + "\n";
                }
            }

            // space
            boost::trim_right(descText);
            descText += "\n\n";


            if (bp->damage.bLockdown)
            {
                currentText = tLib->GetText("weapon_lockdown");
                descText += currentText + "\n";
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
                    level = tLib->GetText("chance_medium");
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
                    level = tLib->GetText("chance_medium");
                }

                boost::algorithm::replace_all(currentText, "\\3", level);

                descText += currentText + "\n";
            }
            if (bp->damage.iStun > 0 && Settings::GetDlcEnabled())
            {
                currentText = tLib->GetText("stun_chance");
                boost::algorithm::replace_all(currentText, "\\1", std::to_string(100));
                descText += currentText + " (" + std::to_string(bp->damage.iStun) + " " + tLib->GetText("stun_length") + ")\n";
            }
            else if (bp->damage.stunChance > 0 && Settings::GetDlcEnabled())
            {
                currentText = tLib->GetText("stun_chance");
                boost::algorithm::replace_all(currentText, "\\1", std::to_string(bp->damage.stunChance * 10));
                currentText += " (3 " + tLib->GetText("stun_length") + ")";

                std::string level = tLib->GetText("chance_low") + " (3 " + tLib->GetText("stun_length");
                if (bp->damage.stunChance >= 7)
                {
                    level = tLib->GetText("chance_high") + " (3 " + tLib->GetText("stun_length");
                }
                else if (bp->damage.stunChance >= 4)
                {
                    level = tLib->GetText("chance_medium") + " (3 " + tLib->GetText("stun_length");
                }

                boost::algorithm::replace_all(currentText, "\\2", level);

                descText += currentText + "\n";
            }
        }
        boost::trim_right(descText);
        retStr.assign(descText);
    }
}

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
    else if (CustomOptionsManager::GetInstance()->redesignedWeaponTooltips.currentValue == true)
    {
        descText += bp->desc.description.GetText() + "\n\n";
        descText += tLib->GetText("description_stats") + "\n";

        if (bp->power > 0)
        {
            currentText = tLib->GetText("required_power");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->power)) + "\n";
        }
        else if (bp->power == 0)
        {
            if (bp->cooldown >= 0)
            {
                currentText = tLib->GetText("requires_no_power");
                descText += currentText + "\n";
            }
            else
            {
                currentText = tLib->GetText("cannot_fire");
                descText += currentText + "\n";
            }
        }
        else
        {
            currentText = tLib->GetText("provides_bonus_power");
            descText += currentText + ": " + std::to_string(bp->power * -1) + "\n";
        }

        if (bp->cooldown >= 0)
        {
            currentText = tLib->GetText("charge_time");

            std::stringstream cooldownString;
            cooldownString << bp->cooldown;

            descText += boost::algorithm::replace_all_copy(currentText, "\\1", cooldownString.str()) + "\n";
        }
        else
        {
            if (bp->power != 0)
            {
                currentText = tLib->GetText("cannot_fire");
                descText += currentText + "\n";
            }
        }

        if (bp->cooldown >= 0)
        {
            if (bp->missiles > 0)
            {
                currentText = tLib->GetText("ammo_consumption");
                descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->missiles)) + "\n";
            }

            if (weaponDef->freeMissileChance > 0)
            {
                currentText = tLib->GetText("free_missile_chance");
                descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(weaponDef->freeMissileChance)) + "\n";
            }

            if (bp->boostPower.count > 0)
            {
                std::string boostType = "";

                if (bp->boostPower.type == 2)
                {
                    if (bp->boostPower.amount > 0)
                    {
                        currentText = tLib->GetText("redesigned_boost_power_damage_positive");
                        std::stringstream stream;
                        stream << std::setprecision(2) << bp->boostPower.amount;
                        boostType += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str()) + "\n";

                        int dmg = bp->damage.iIonDamage;
                        if (dmg <= 0)
                        {
                            dmg = bp->damage.iDamage;
                        }

                        std::stringstream damageCapString;
                        damageCapString << (bp->boostPower.count * bp->boostPower.amount + dmg);

                        currentText = tLib->GetText("redesigned_damage_cap");
                        currentText = boost::algorithm::replace_all_copy(currentText, "\\1", damageCapString.str());
                        stream.str("");
                        stream.clear();
                        stream << std::setprecision(2) << bp->boostPower.count;
                        boostType += boost::algorithm::replace_all_copy(currentText, "\\2", stream.str()) + "\n";
                    }
                    else
                    {
                        currentText = tLib->GetText("redesigned_boost_power_damage_negative");
                        std::stringstream stream;
                        stream << std::setprecision(2) << bp->boostPower.amount;
                        boostType += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str()) + "\n";

                        int dmg = bp->damage.iIonDamage;
                        if (dmg <= 0)
                        {
                            dmg = bp->damage.iDamage;
                        }

                        std::stringstream damageCapString;
                        damageCapString << (bp->boostPower.count * bp->boostPower.amount + dmg);

                        currentText = tLib->GetText("redesigned_damage_cap");
                        currentText = boost::algorithm::replace_all_copy(currentText, "\\1", damageCapString.str());
                        stream.str("");
                        stream.clear();
                        stream << std::setprecision(2) << bp->boostPower.count;
                        boostType += boost::algorithm::replace_all_copy(currentText, "\\2", stream.str()) + "\n";
                    }
                }
                else
                {
                    if (bp->boostPower.amount > 0)
                    {
                        currentText = tLib->GetText("redesigned_boost_power_speed_positive");
                        std::stringstream stream;
                        stream << std::setprecision(4) << bp->boostPower.amount;
                        boostType += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str()) + "\n";

                        std::stringstream speedCapString;
                        speedCapString << bp->cooldown - (bp->boostPower.count * bp->boostPower.amount);

                        currentText = tLib->GetText("redesigned_speed_cap");
                        currentText = boost::algorithm::replace_all_copy(currentText, "\\1", speedCapString.str());
                        stream.str("");
                        stream.clear();
                        stream << std::setprecision(4) << bp->boostPower.count;
                        boostType += boost::algorithm::replace_all_copy(currentText, "\\2", stream.str()) + "\n";
                    }
                    else
                    {
                        currentText = tLib->GetText("redesigned_boost_power_speed_negative");
                        std::stringstream stream;
                        stream << std::setprecision(4) << bp->boostPower.amount;
                        boostType += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str()) + "\n";

                        std::stringstream speedCapString;
                        speedCapString << bp->cooldown - (bp->boostPower.count * bp->boostPower.amount);

                        currentText = tLib->GetText("redesigned_speed_cap");
                        currentText = boost::algorithm::replace_all_copy(currentText, "\\1", speedCapString.str());
                        stream.str("");
                        stream.clear();
                        stream << std::setprecision(4) << bp->boostPower.count;
                        boostType += boost::algorithm::replace_all_copy(currentText, "\\2", stream.str()) + "\n";
                    }
                }

                descText += boostType;
            }

            // space
            boost::trim_right(descText);
            descText += "\n\n";

            if(bp->radius > 0)
            {
                currentText = tLib->GetText("shot_radius");
                descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->radius)) + "\n";
            }

            if (bp->type == 0 || bp->type == 1 || bp->type == 3 || bp->type == 4)
            {
                if (bp->type == 0 || bp->type == 1 || (bp->shots == 1 && bp->type != 4))
                {
                    currentText = tLib->GetText("shots");
                    descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->shots)) + "\n";
                }
                else if (bp->type == 3)
                {
                    currentText = tLib->GetText("bomb_shots");
                    descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->shots)) + "\n";
                }
                else
                {
                    currentText = tLib->GetText("shots");
                    descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->miniCount * bp->shots)) + "\n";
                }
            }

            if (bp->chargeLevels > 1)
            {
                currentText = tLib->GetText("charge");
                descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->chargeLevels)) + "\n";
            }

            if (bp->type == 2)
            {
                currentText = tLib->GetText("beam_length");
                descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->length)) + "\n";

                currentText = tLib->GetText("swipe_speed");
                if (bp->speed != 0)
                {
                    std::stringstream stream;
                    stream << std::fixed <<std::setprecision(0) << bp->speed;
                    descText += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str()) + "\n";
                }
                else
                {
                    descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(5)) + "\n";
                }
            }

            // space
            boost::trim_right(descText);
            descText += "\n\n";

//            if (bp->drone_targetable != 0)
//            {
//                descText += tLib->GetText("weapon_not_drone_targetable") + "\n";
//            }
//            else
//            {
//                descText += tLib->GetText("weapon_drone_targetable") + "\n";
//            }

            if (bp->damage.bHullBuster)
            {
                descText += tLib->GetText("redesigned_double_damage") + "\n";
            }

//            if (bp->damage.iPersDamage == 0 && bp->damage.iSystemDamage == 0)
//            {
//                if (bp->damage.iDamage != 0)
//                {
//                    if (bp->type == 2)
//                    {
//                        currentText = tLib->GetText("redesigned_damage_room");
//                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iDamage)) + "\n";
//                    }
//                    else
//                    {
//                        currentText = tLib->GetText("redesigned_damage_shot");
//                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iDamage)) + "\n";
//                    }
//                }
//            }
//            else
//            {
                    if (bp->damage.iDamage > 0)
                    {
                        currentText = tLib->GetText("hull_damage");
                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iDamage)) + "\n";
                    }
                    else if (bp->damage.iDamage < 0)
                    {
                        currentText = tLib->GetText("hull_damage_negative");
                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iDamage * -1)) + "\n";
                    }

                    if (bp->damage.iDamage >= 0)
                    {
                        if (bp->damage.iSystemDamage + bp->damage.iDamage > 0)
                        {
                            currentText = tLib->GetText("system_damage");
                            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iSystemDamage + bp->damage.iDamage)) + "\n";
                        }
                        else if (bp->damage.iSystemDamage + bp->damage.iDamage < 0)
                        {
                            currentText = tLib->GetText("system_damage_negative");
                            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string((bp->damage.iSystemDamage + bp->damage.iDamage) * -1)) + "\n";
                        }
                        if (bp->damage.iPersDamage + bp->damage.iDamage > 0)
                        {
                            currentText = tLib->GetText("personnel_damage");
                            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string((bp->damage.iDamage + bp->damage.iPersDamage) * 15)) + "\n";
                        }
                        else if (bp->damage.iPersDamage + bp->damage.iDamage < 0)
                        {
                            currentText = tLib->GetText("personnel_damage_negative");
                            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(((bp->damage.iDamage + bp->damage.iPersDamage) * -1) * 15)) + "\n";
                        }

                    }
                    else
                    {
                        if (bp->damage.iSystemDamage > 0)
                        {
                            currentText = tLib->GetText("system_damage");
                            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iSystemDamage)) + "\n";
                        }
                        else if (bp->damage.iSystemDamage < 0)
                        {
                            currentText = tLib->GetText("system_damage_negative");
                            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string((bp->damage.iSystemDamage) * -1)) + "\n";
                        }
                        if (bp->damage.iPersDamage > 0)
                        {
                            currentText = tLib->GetText("personnel_damage");
                            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string((bp->damage.iPersDamage) * 15)) + "\n";
                        }
                        else if (bp->damage.iPersDamage < 0)
                        {
                            currentText = tLib->GetText("personnel_damage_negative");
                            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(((bp->damage.iPersDamage) * -1) * 15)) + "\n";
                        }
                    }
//            }

            if (bp->damage.iIonDamage != 0)
            {
                currentText = tLib->GetText("ion_damage");
                descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iIonDamage)) + "\n";
            }

            if (bp->damage.iShieldPiercing != 0)
            {
                currentText = tLib->GetText("shield_piercing");
                if (bp->type != 2 || bp->damage.iDamage > 0)
                {
                    descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iShieldPiercing)) + "\n";
                }
                else if (bp->damage.iDamage == 0 && bp->damage.iShieldPiercing - 1 > 0)
                {
                    descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iShieldPiercing - 1)) + "\n";
                }
                else
                {
                    descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iShieldPiercing + bp->damage.iDamage - 1)) + "\n";
                }
            }

            // space
            boost::trim_right(descText);
            descText += "\n\n";


            if (bp->damage.bLockdown)
            {
                currentText = tLib->GetText("weapon_lockdown");
                descText += currentText + "\n";
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
                    level = tLib->GetText("chance_medium");
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
                    level = tLib->GetText("chance_medium");
                }

                boost::algorithm::replace_all(currentText, "\\3", level);

                descText += currentText + "\n";
            }
            if (bp->damage.iStun > 0 && Settings::GetDlcEnabled())
            {
                currentText = tLib->GetText("stun_chance");
                boost::algorithm::replace_all(currentText, "\\1", std::to_string(100));
                descText += currentText + " (" + std::to_string(bp->damage.iStun) + " " + tLib->GetText("stun_length") + ")\n";
            }
            else if (bp->damage.stunChance > 0 && Settings::GetDlcEnabled())
            {
                currentText = tLib->GetText("stun_chance");
                boost::algorithm::replace_all(currentText, "\\1", std::to_string(bp->damage.stunChance * 10));
                currentText += " (3 " + tLib->GetText("stun_length") + ")";

                std::string level = tLib->GetText("chance_low") + " (3 " + tLib->GetText("stun_length");
                if (bp->damage.stunChance >= 7)
                {
                    level = tLib->GetText("chance_high") + " (3 " + tLib->GetText("stun_length");
                }
                else if (bp->damage.stunChance >= 4)
                {
                    level = tLib->GetText("chance_medium") + " (3 " + tLib->GetText("stun_length");
                }

                boost::algorithm::replace_all(currentText, "\\2", level);

                descText += currentText + "\n";
            }
        }
        boost::trim_right(descText);
        descText += "\n\n";
        currentText = tLib->GetText("scrap_value");
        currentText = boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->desc.cost));
        descText += boost::algorithm::replace_all_copy(currentText, "\\2", std::to_string(bp->desc.cost / 2)) + "\n";
    }
    else
    {
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

        if (bp->damage.iShieldPiercing != 0)
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
                level = tLib->GetText("chance_medium");
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
                level = tLib->GetText("chance_medium");
            }

            boost::algorithm::replace_all(currentText, "\\3", level);

            descText += currentText + "\n";
        }

        if (bp->damage.iIonDamage != 0)
        {
            currentText = tLib->GetText("ion_damage");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iIonDamage)) + "\n";
        }
        if (bp->damage.iStun > 0 && Settings::GetDlcEnabled())
        {
            currentText = tLib->GetText("stun_damage");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iStun)) + "\n";
        }
        else if (bp->damage.stunChance > 0 && Settings::GetDlcEnabled())
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
                level = tLib->GetText("chance_medium");
            }

            boost::algorithm::replace_all(currentText, "\\2", level);

            descText += currentText + "\n";
        }
        if (bp->damage.iPersDamage != 0)
        {
            currentText = tLib->GetText("personnel_damage");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iPersDamage * 15)) + "\n";
        }
        if (bp->damage.iSystemDamage != 0)
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
    }

    strRef->assign(descText);
}

static Button* smallAutoFireButton;

HOOK_METHOD(WeaponControl, constructor, () -> void)
{
    super();

    smallAutoFireButton = new Button();
    smallAutoFireButton->OnInit("button_small_autofireOn", 0, 0);
    smallAutoFireButton->hitbox.w = 28;
    smallAutoFireButton->hitbox.h = 28;
}

HOOK_METHOD(WeaponControl, LinkShip, (ShipManager *ship) -> void)
{
    super(ship);

    if(autoFiring){
        smallAutoFireButton->SetImageBase("button_small_autofireOn");
        smallAutoFireButton->bRenderOff = true;
    }
    else {
        smallAutoFireButton->SetImageBase("button_small_autofireOff");
        smallAutoFireButton->bRenderOff = true;
    }
}

HOOK_METHOD(WeaponControl, OnRender, () -> void)
{
    super();

    if (this->shipManager->myBlueprint.weaponSlots <= 2 && this->shipManager->myBlueprint.weaponSlots > 0 && this->shipManager->HasSystem(3))
    {
        smallAutoFireButton->hitbox.x = this->location.x + 184;
        smallAutoFireButton->hitbox.y = this->location.y + 61;

        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(this->location.x + 184, this->location.y + 61, 0.0);
        smallAutoFireButton->OnRender();
        CSurface::GL_PopMatrix();
    }
}

HOOK_METHOD(WeaponControl, MouseMove, (int x, int y) -> void)
{
    super(x, y);

    if (this->shipManager->myBlueprint.weaponSlots <= 2 && this->shipManager->myBlueprint.weaponSlots > 0 && this->shipManager->HasSystem(3) && !Dragging())
    {
        smallAutoFireButton->MouseMove(x, y, false);
        if(smallAutoFireButton->bHover){
            smallAutoFireButton->bRenderOff = false;
            smallAutoFireButton->bRenderSelected = true;

            std::string replaceWith;
            std::string tooltip = G_->GetTextLibrary()->GetText("tooltip_autofire");

            Settings::GetHotkeyName(replaceWith, "autofire");
            boost::algorithm::replace_all(tooltip, "\\1", replaceWith);

            Settings::GetHotkeyName(replaceWith, "force_autofire");
            boost::algorithm::replace_all(tooltip, "\\2", replaceWith);

            G_->GetMouseControl()->bForceTooltip = true;
            G_->GetMouseControl()->SetTooltip(tooltip);
        }
        else {
            smallAutoFireButton->bRenderOff = true;
            smallAutoFireButton->bRenderSelected = false;

        }

    }
}

HOOK_METHOD(WeaponControl, LButton, (int x, int y, bool holdingShift) -> bool)
{
    bool ret = super(x, y, holdingShift);

    if (this->shipManager->myBlueprint.weaponSlots <= 2 && this->shipManager->myBlueprint.weaponSlots > 0 && this->shipManager->HasSystem(3))
    {
        if (smallAutoFireButton->bActive && smallAutoFireButton->bHover)
        {
            SetAutofiring(!autoFiring, false);
            if (autoFiring) {
                smallAutoFireButton->SetImageBase("button_small_autofireOn");
                smallAutoFireButton->bRenderSelected = false;
                smallAutoFireButton->bRenderOff = true;
            }
            else {
                smallAutoFireButton->SetImageBase("button_small_autofireOff");
                smallAutoFireButton->bRenderSelected = false;
                smallAutoFireButton->bRenderOff = true;
            }
            return autoFiring;
        }
    }

    return ret;
}

HOOK_METHOD(WeaponControl, KeyDown, (SDLKey key) -> bool)
{
    bool ret = super(key);

    if (this->shipManager->myBlueprint.weaponSlots <= 2 && this->shipManager->myBlueprint.weaponSlots > 0 && this->shipManager->HasSystem(3))
    {
        if (key == Settings::GetHotkey("autofire"))
        {
            if (smallAutoFireButton->bActive)
            {
                SetAutofiring(!autoFiring, false);
                if (autoFiring)
                {
                    smallAutoFireButton->SetImageBase("button_small_autofireOn");
                    smallAutoFireButton->bRenderSelected = false;
                    smallAutoFireButton->bRenderOff = true;
                }
                else
                {
                    smallAutoFireButton->SetImageBase("button_small_autofireOff");
                    smallAutoFireButton->bRenderSelected = false;
                    smallAutoFireButton->bRenderOff = true;
                }
                return autoFiring;
            }
        }
    }

    return ret;
}
