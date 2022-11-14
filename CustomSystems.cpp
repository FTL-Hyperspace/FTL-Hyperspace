#include "CustomSystems.h"
#include "TemporalSystem.h"
#include "CustomShipSelect.h"
#include "CustomShips.h"
#include "CustomWeapons.h"
#include "Systems.h"
#include "CustomOptions.h"

#include <boost/lexical_cast.hpp>

CustomSystemManager CustomSystemManager::instance = CustomSystemManager();

template<typename T> void CustomSystemManager::ParseLevelValues(rapidxml::xml_node<char>* node, std::pair<T,T> &levelPair)
{
    if (node->first_attribute("amount"))
    {
        levelPair.first=boost::lexical_cast<T>(node->first_attribute("amount")->value());
        levelPair.second=boost::lexical_cast<T>(node->first_attribute("amount")->value());
    }
    if (node->first_attribute("player"))
    {
        levelPair.first=boost::lexical_cast<T>(node->first_attribute("player")->value());
    }
    if (node->first_attribute("enemy"))
    {
        levelPair.second=boost::lexical_cast<T>(node->first_attribute("enemy")->value());
    }
}


void CustomSystemManager::ParseSystemNode(rapidxml::xml_node<char>* node)
{
    std::string sysName = node->first_attribute("id")->value();

    if (sysName == "engines")
    {
        for (auto immediateChild = node->first_node(); immediateChild; immediateChild = immediateChild->next_sibling())
        {
            if (strcmp(immediateChild->name(),"levels") == 0)
            {
                for (auto levelNode = immediateChild->first_node(); levelNode; levelNode = levelNode->next_sibling())
                {
                    std::pair<int,int> evasionPair{-2147483648,-2147483648};
                    std::pair<float,float> chargePair{-2147483648.f,-2147483648.f};
                    for (auto child = levelNode->first_node(); child; child = child->next_sibling())
                    {
                        std::string nodeName = child->name();
                    
                        if (nodeName == "evasionBoost")
                        {
                            ParseLevelValues<int>(child, evasionPair);
                        }

                        if (nodeName == "jumpCharge")
                        {
                            ParseLevelValues<float>(child, chargePair);   
                        }
                    }
                    engineDodgeLevels.systemLevels.push_back(evasionPair);
                    engineChargeLevels.systemLevels.push_back(chargePair);
                }
            }

            if (strcmp(immediateChild->name(),"hackEffects") == 0)
            {
                engineDodgeLevels.hackLevels = {0,0};
                engineChargeLevels.hackLevels = {0.f,0.f};
                for (auto child = immediateChild->first_node(); child; child = child->next_sibling())
                {
                    std::string nodeName = child->name();
                    if (nodeName == "evasionBoost")
                    {
                        ParseLevelValues<int>(child, engineDodgeLevels.hackLevels);
                    }

                    if (nodeName == "jumpCharge")
                    {
                        ParseLevelValues<float>(child, engineChargeLevels.hackLevels);   
                    }
                }  
            }  
        }     
    }

    if (sysName == "oxygen")
    {
        for (auto immediateChild = node->first_node(); immediateChild; immediateChild = immediateChild->next_sibling())
        {
            if (strcmp(immediateChild->name(),"levels") == 0)
            {
                for (auto levelNode = immediateChild->first_node(); levelNode; levelNode = levelNode->next_sibling())
                {
                    std::pair<float,float> fillPair{-2147483648.f,-2147483648.f};
                    for (auto child = levelNode->first_node(); child; child = child->next_sibling())
                    {
                        std::string nodeName = child->name();
                        if (nodeName == "fillRate")
                        {
                            ParseLevelValues<float>(child, fillPair);   
                        }
                    }
                    oxygenLevels.systemLevels.push_back(fillPair);
                }
            }

            if (strcmp(immediateChild->name(),"hackEffects") == 0)
            {
                oxygenLevels.hackLevels = {0.f,0.f};
                for (auto child = immediateChild->first_node(); child; child = child->next_sibling())
                {
                    std::string nodeName = child->name();
                    if (nodeName == "fillRate")
                    {
                        ParseLevelValues<float>(child, oxygenLevels.hackLevels);   
                    }
                }  
            }  
        }     
    }
}


void ParseSystemsNode(rapidxml::xml_node<char>* node)
{
    
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string name = child->name();
        std::string val = child->value();

        if (name == "system" && child->first_attribute("id"))
        {
            std::string sysName = child->first_attribute("id")->value();

            if (sysName == "temporal")
            {
                TemporalSystemParser::ParseSystemNode(child);
            }

            CustomSystemManager::GetInstance()->ParseSystemNode(child);
        }
    }
}


HOOK_METHOD(EngineSystem, GetDodgeFactor, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> EngineSystem::GetDodgeFactor -> Begin (CustomSystems.cpp)\n")
    int effectivePower = this->GetEffectivePower();
    if (effectivePower == 0) {return 0;}
    else
    {
        auto levelVector = CustomSystemManager::GetInstance()->engineDodgeLevels.systemLevels;
         //TODO: Make sure it defaults properly if none of this information is declared.
        int overrideLevel  = (this->_shipObj.iShipId == 0) ? levelVector[effectivePower-1].first : levelVector[effectivePower-1].second;
        if (overrideLevel == -2147483648 || (effectivePower > levelVector.size())) {return super();} //when a <level> node doesn't have a defined evasionBoost, it will default to -2147483648 for both the player and enemy
        else
        {
            int manLevel = this->iActiveManned; 
            if ((manLevel < 1) || (this->bBoostable == false))
            {
                manLevel = 0;
            }
            else if (this->healthState.first != this->healthState.second)
            {
                manLevel = 0;
            }

            
            float skill = getSkillBonus(1, manLevel);
            return int(skill) + overrideLevel;
        }    
    }
}

HOOK_METHOD(EngineSystem, GetEngineSpeed, () -> float)
{
    LOG_HOOK("HOOK_METHOD -> EngineSystem::GetEngineSpeed -> Begin (CustomSystems.cpp)\n")
    /*
    int manLevel = this->iActiveManned;
    float manBoost = 1.f;

    if ((manLevel > 0) && (this->bBoostable) && (this->healthState.second == this->healthState.first))
    {
        if (manLevel == 1)
        {
            manBoost = 1.1f;
        }
        else if (manLevel == 2)
        {
            manBoost = 1.17f;
        }
        else if (manLevel == 3)
        {
            manBoost = 1.25f;
        }
    }

    float additionalBoost = this->bBoostFTL ? 3.0f : 1.0f;
    float augBoost = this->_shipObj.GetAugmentationValue("FTL_BOOSTER");
    
    int powerLevel = this->GetEffectivePower();

    
    float speedFactor = G_->GetCFPS()->GetSpeedFactor();
    
    float jumpSpeed = manBoost * (augBoost + 1.0f) * ((float)(powerLevel - 1) * 0.35f + 1.25f) * 0.0625f * speedFactor;
    
    float ret = super();

    printf("Real value: %f Calculated value: %f \n",ret,jumpSpeed); //just testing to see if it works as it should
    return ret;
    */
    float originalCharge = super();
    int effectivePower = this->GetEffectivePower();

    float originalMult = 1.f + ((effectivePower - 1.f) * 0.25f);
    float baseCharge = originalCharge / originalMult;

    auto levelVector = CustomSystemManager::GetInstance()->engineChargeLevels.systemLevels;
    float overrideLevel  = (this->_shipObj.iShipId == 0) ? levelVector[effectivePower-1].first : levelVector[effectivePower-1].second;
    
    if (overrideLevel == -2147483648 || (effectivePower > levelVector.size()) || effectivePower == 0) {return originalCharge;} //when a <level> node doesn't have a defined evasionBoost, it will default to -2147483648 for both the player and enemy
    else
    {
        return (baseCharge * overrideLevel);
    }    

}





HOOK_STATIC(ShipSystem, NameToSystemId, (std::string& name) -> int)
{
    LOG_HOOK("HOOK_STATIC -> ShipSystem::NameToSystemId -> Begin (CustomSystems.cpp)\n")
    if (name == "temporal")
    {
        return 20;
    }

    return super(name);
}

HOOK_STATIC(ShipSystem, SystemIdToName, (int systemId) -> std::string)
{
    LOG_HOOK("HOOK_STATIC -> ShipSystem::SystemIdToName -> Begin (CustomSystems.cpp)\n")
    std::string ret = super(systemId);
    if (systemId == 20)
    {
        ret.assign("temporal");
    }

    return ret;
}



HOOK_METHOD_PRIORITY(WorldManager, ModifyResources, 1000, (LocationEvent *event) -> LocationEvent*)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WorldManager::ModifyResources -> Begin (CustomSystems.cpp)\n")

    LocationEvent *ret = super(event);

    if (event->stuff.upgradeAmount > 0)
    {
        if (event->stuff.upgradeId == 16) // upgrade everything
        {
            playerShip->shipManager->UpgradeSystem(SYS_TEMPORAL, event->stuff.upgradeAmount);
        }
        else if (event->stuff.upgradeId >= 20) // new IDs
        {
            playerShip->shipManager->UpgradeSystem(event->stuff.upgradeId, event->stuff.upgradeAmount);
        }
    }

    return ret;
}



HOOK_METHOD(ShipSystem, constructor, (int systemId, int roomId, int shipId, int startingPower) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::constructor -> Begin (CustomSystems.cpp)\n")
    super(systemId, roomId, shipId, startingPower);

    if (systemId == 20)
    {
        bNeedsPower = true;
        bBoostable = false;
        bNeedsManned = false;
        bLevelBoostable = false;
    }
}

HOOK_METHOD(ShipManager, CreateSystems, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::CreateSystems -> Begin (CustomSystems.cpp)\n")
    if (myBlueprint.systemInfo.find(0) != myBlueprint.systemInfo.end())
    {
        auto shieldInfo = myBlueprint.systemInfo[0];


        auto sys = new Shields(shieldInfo.location[0], iShipId, 0, myBlueprint.shieldFile);
        shieldSystem = sys;
        sys->SetBaseEllipse(ship.GetBaseEllipse());
    }
    else
    {
        shieldSystem = nullptr;
    }

    systemKey.clear();
    for (int i = 0; i < 21; i++)
    {
        systemKey.push_back(-1);
    }

    ShipBlueprint *realBp = nullptr;
    if (!revisitingShip) realBp = G_->GetBlueprints()->GetShipBlueprint(myBlueprint.blueprintName, -1);

    int ret = 0;

    if (realBp)
    {
        for (auto i : realBp->systems)
        {
            ret += AddSystem(i);
        }
    }
    else
    {
        for (auto i : myBlueprint.systems)
        {
            ret += AddSystem(i);
        }
    }
    return ret;
}

HOOK_METHOD(ShipManager, SaveToBlueprint, (bool unk) -> ShipBlueprint)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::SaveToBlueprint -> Begin (CustomSystems.cpp)\n")
    ShipBlueprint ret = super(unk);
    if (this->systemKey[SYS_ARTILLERY] != -1) // Fix for saving multiple artillery blueprint
    {
        int numArtillery = this->artillerySystems.size();
        for (auto i : ret.systems)
        {
            if (i == SYS_ARTILLERY)
            {
                numArtillery--;
            }
        }
        if (numArtillery > 0)
        {
            for (int i=0; i<numArtillery; ++i)
            {
                ret.systems.push_back(SYS_ARTILLERY);
            }
            if (unk)
            {
                this->myBlueprint.systems = ret.systems;
            }
            return ret;
        }
    }
    return ret;
}

HOOK_METHOD(SystemControl, CreateSystemBoxes, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> SystemControl::CreateSystemBoxes -> Begin (CustomSystems.cpp)\n")
    *Global::weaponPosition = Point(0, 0);
    *Global::dronePosition = Point(0, 0);

    for (auto i : sysBoxes)
    {
        delete i;
    }

    sysBoxes.clear();

    SystemPower.x = 0;
    SystemPower.y = 0;

    int xPos = 22;

    std::vector<int> systemOrder = { 0, 1, 5, 13, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 14, 15, 20 };

    for (auto sysId : systemOrder)
    {
        auto sys = shipManager->GetSystem(sysId);
        if (!sys || !sys->bNeedsPower) continue;

        switch (sysId)
        {
        case SYS_MIND:
            {
                auto box = new MindBox(Point(xPos + 36, 269), shipManager->mindSystem);
                sysBoxes.push_back(box);
                xPos += 54;
                break;
            }
        case SYS_CLONEBAY:
            {
                auto box = new CloneBox(Point(xPos + 36, 269), shipManager->cloneSystem);
                sysBoxes.push_back(box);
                xPos += 36;
                break;
            }
        case SYS_HACKING:
            {
                auto box = new HackBox(Point(xPos + 36, 269), shipManager->hackingSystem, shipManager);
                sysBoxes.push_back(box);
                xPos += 54;
                break;
            }
        case SYS_TELEPORTER:
            {
                auto box = new TeleportBox(Point(xPos + 36, 269), shipManager->teleportSystem);
                sysBoxes.push_back(box);
                xPos += 54;
                break;
            }
        case SYS_CLOAKING:
            {
                auto box = new CloakingBox(Point(xPos + 36, 269), shipManager->cloakSystem);
                sysBoxes.push_back(box);
                xPos += 54;
                break;
            }
        case SYS_ARTILLERY:
            {
                for (auto i : shipManager->artillerySystems)
                {
                    auto box = new ArtilleryBox(Point(xPos + 36, 269), i);
                    sysBoxes.push_back(box);
                    xPos += 36;
                }

                /*
                if (shipManager->artillerySystems.size() > 0)
                {
                    auto artillerySys = shipManager->artillerySystems[0];
                    auto box = new ArtilleryBox(Point(xPos + 36, 269), artillerySys);
                    sysBoxes.push_back(box);
                    xPos += 36;
                }
                */
            }
            break;
        case SYS_WEAPONS:
            break;
        case SYS_DRONES:
            break;

        // Custom systems
        case SYS_TEMPORAL:
            {
                auto box = new TemporalBox(Point(xPos + 36, 269), sys, shipManager);
                sysBoxes.push_back(box);
                xPos += 54;
                break;
            }
        default:
            auto box = new SystemBox(Point(xPos + 36, 269), sys, true);
            sysBoxes.push_back(box);
            xPos += 36;
        }
    }


    if (shipManager->HasSystem(3))
    {
        *Global::weaponPosition = Point(position.x + xPos + 36, position.y + 269);
        auto box = new WeaponSystemBox(Point(xPos + 36, 269), shipManager->GetSystem(3), &combatControl->weapControl);

        sysBoxes.push_back(box);

        xPos += 48 + 97 * shipManager->myBlueprint.weaponSlots;
    }
    if (shipManager->HasSystem(4))
    {
        *Global::dronePosition = Point(position.x + xPos + 36, position.y + 269);
        auto box = new SystemBox(Point(xPos + 36, 269), shipManager->GetSystem(4), true);

        sysBoxes.push_back(box);
    }

    int subSystemOrder[4] = { 6, 7, 8, 12 };

    int subXPos = subSystemPosition.x;
    int subYPos = subSystemPosition.y;

    for (int i = 0; i < 4; i++)
    {
        int sysId = subSystemOrder[i];

        auto sys = shipManager->GetSystem(sysId);
        switch (sysId)
        {
        case SYS_DOORS:
            if (sys)
            {
                auto box = new DoorBox(Point(subXPos, subYPos), sys, shipManager);
                sysBoxes.push_back(box);
            }

            subXPos += 15;
            break;
        case SYS_BATTERY:
            if (sys)
            {
                auto box = new BatteryBox(Point(subXPos, subYPos), shipManager->batterySystem);
                sysBoxes.push_back(box);
            }
            subXPos += 18;
            break;
        default:
            if (sys)
            {
                auto box = new SystemBox(Point(subXPos, subYPos), sys, true);
                sysBoxes.push_back(box);
            }
            break;
        }
        subXPos += sub_spacing + 36;
    }
}


HOOK_METHOD(ShipBuilder, CreateSystemBoxes, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::CreateSystemBoxes -> Begin (CustomSystems.cpp)\n")
    for (auto i : sysBoxes)
    {
        delete i;
    }

    sysBoxes.clear();

    int xPos = 360;

    std::vector<int> systemIds = { 0, 1, 2, 3, 4, 5, 9, 10, 11, 13, 14, 15, 20, 6, 7, 8, 12 };

    for (auto i : systemIds)
    {
        if (i == SYS_ARTILLERY)
        {
            for (auto sys : currentShip->artillerySystems)
            {
                auto box = new SystemCustomBox(Point(xPos, 425), sys, currentShip);

                sysBoxes.push_back(box);

                box->bShowPower = true;
                box->bSimplePower = true;

                xPos += 38;
            }
        }
        else
        {
            if (currentShip->HasSystem(i))
            {
                auto sys = currentShip->GetSystem(i);
                auto box = new SystemCustomBox(Point(xPos, 425), sys, currentShip);

                sysBoxes.push_back(box);

                box->bShowPower = true;
                box->bSimplePower = true;

                xPos += 38;
            }
        }
    }
}


HOOK_METHOD(CombatControl, KeyDown, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::KeyDown -> Begin (CustomSystems.cpp)\n")
    bool isWeaponKey = weapControl.KeyDown(key);
    if (isWeaponKey || droneControl.KeyDown(key))
    {
        if (shipManager->HasSystem(SYS_MIND))
        {
            shipManager->mindSystem->SetArmed(0);
        }
        if (shipManager->HasSystem(SYS_HACKING))
        {
            shipManager->hackingSystem->bArmed = false;
        }
        if (shipManager->HasSystem(SYS_TEMPORAL))
        {
            auto temporalSys = SYS_EX(shipManager->GetSystem(SYS_TEMPORAL))->temporalSystem;

            temporalSys->SetArmed(TemporalArmState::TEMPORAL_ARM_NONE);
        }

        shipManager->ship.SetSelectedRoom(-1);
        if (currentTarget)
        {
            currentTarget->shipManager->ship.SetSelectedRoom(-1);
        }
    }
    if (isWeaponKey)
    {
        aimingPoints.clear();
    }
}

HOOK_METHOD(ShipManager, CanFitSystem, (int systemId) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::CanFitSystem -> Begin (CustomSystems.cpp)\n")
    if (systemId == SYS_MEDBAY)
    {
        if (systemKey[SYS_CLONEBAY] != -1)
        {
            return true;
        }
    }
    else if (systemId == SYS_CLONEBAY)
    {
        if (systemKey[SYS_MEDBAY] != -1)
        {
            return true;
        }
    }

    int count = 0;

    for (auto i : vSystemList)
    {
        if (i->bNeedsPower)
        {
            count++;
        }
    }

    auto custom = CustomShipSelect::GetInstance();
    int sysLimit = custom->GetDefinition(myBlueprint.blueprintName).systemLimit;

    return count < sysLimit;
}

HOOK_METHOD(ShipManager, CanFitSubsystem, (int systemId) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::CanFitSubsystem -> Begin (CustomSystems.cpp)\n")
    int count = 0;

    for (auto i : vSystemList)
    {
        if (!i->bNeedsPower)
        {
            count++;
        }
    }

    auto custom = CustomShipSelect::GetInstance();
    int sysLimit = custom->GetDefinition(myBlueprint.blueprintName).subsystemLimit;

    return count < sysLimit;
}

/*
HOOK_METHOD(ShipManager, RenderChargeBars, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::RenderChargeBars -> Begin (CustomSystems.cpp)\n")

}
*/

/*
HOOK_METHOD(ShipSystem, SetPowerLoss, (int powerLoss) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::SetPowerLoss -> Begin (CustomSystems.cpp)\n")
    auto ex = SYS_EX(this);
    iTempPowerLoss = powerLoss + ex->additionalPowerLoss;

    int maxPower = powerState.second;
    int oldMaxHealth = healthState.second;

    if (healthState.first <= healthState.second)
    {
        oldMaxHealth = healthState.first;
    }

    if (oldMaxHealth < 0)
    {
        oldMaxHealth = 0;
    }

    int currentHealth = healthState.second;
    healthState.first = oldMaxHealth;
    int newBonusPower = maxPower - (currentHealth - oldMaxHealth) - powerLoss;

    int powerCap = 0;
    if (iTempPowerCap <= 7)
    {
        if (iTempPowerCap >= 0)
        {
            powerCap = iTempPowerCap;
        }
    }
    else
    {
        if (maxPower >= 0)
        {
            powerCap = maxPower;
        }
    }

    if (iBonusPower <= newBonusPower)
    {
        newBonusPower = iBonusPower;
    }
    if (newBonusPower > powerCap)
    {
        newBonusPower = powerCap;
    }
    iBonusPower = newBonusPower;

    CheckMaxPower();

    if (iSystemType - 3 > 1)
    {
        return CheckForRepower();
    }

    return iSystemType - 3;
}
*/

/*
HOOK_STATIC(ShipSystem, GetLevelDescription, (int systemId, int level, bool tooltip) -> std::string)
{
    LOG_HOOK("HOOK_STATIC -> ShipSystem::GetLevelDescription -> Begin (CustomSystems.cpp)\n")
    std::string ret = super(systemId, level, tooltip);

    std::string name = SystemIdToName(systemId);
    auto tLib = G_->GetTextLibrary();
    if (tooltip)
    {
        bool hacked = false; // figure out method
        if (hacked)
        {
            name += "_tooltip_hacked";
        }
        else
        {
            name += "_" + std::to_string(level) + "_tooltip";
        }
        ret.assign(tLib->GetText(name));
    }
    else
    {
        name += "_" + std::to_string(level);
        ret.assign(tLib->GetText(name));
    }
    return ret;
}
*/

HOOK_METHOD(ShipSystem, GetEffectivePower, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::GetEffectivePower -> Begin (CustomSystems.cpp)\n")
    int boostPower = 0;

    if (iActiveManned > 0 && bBoostable && healthState.first == healthState.second)
    {
        boostPower = bLevelBoostable;
    }

    return boostPower + iBatteryPower + powerState.first + iBonusPower;
}
HOOK_METHOD(ShipManager, GetDodgeFactor, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetDodgeFactor -> Begin (CustomSystems.cpp)\n");
    int ret = super();

    auto options = CustomOptionsManager::GetInstance();

    if (options->sensorsAccuracyBonus.currentValue)
    {
        if (current_target != nullptr)
        {
            if (options->sensorsAccuracyFirstLevelBonus.currentValue)
            {
                ret -= options->sensorsAccuracyBonus.currentValue * current_target->GetSystemPower(SystemId::SYS_SENSORS);
            }
            else
            {
                ret -= options->sensorsAccuracyBonus.currentValue * (-1 + std::max(1, current_target->GetSystemPower(SystemId::SYS_SENSORS)));
            }
        }
    }

    return ret;
}

void modifyWeaponCooldown(ProjectileFactory* pFactory)
{
    float value = 0.f;
    auto weapon = CustomWeaponManager::instance->GetWeaponDefinition(pFactory->blueprint->name);
    bool hacked = false;
    bool enemyCloaked = false;

    if (G_->GetShipManager(pFactory->iShipId) != nullptr && G_->GetShipManager(pFactory->iShipId)->current_target != nullptr && G_->GetShipManager(pFactory->iShipId)->current_target->cloakSystem != nullptr && G_->GetShipManager(pFactory->iShipId)->current_target->cloakSystem->bTurnedOn) // if the target exists and the target is cloaking
    {
        enemyCloaked = true;
        value += pFactory->GetAugmentationValue("ENEMY_CLOAKING_CHARGE_RATE_INCREASE") - pFactory->GetAugmentationValue("ENEMY_CLOAKING_CHARGE_RATE_DECREASE") + weapon->enemyCloakingChargeRateChange;
    }
    if (G_->GetShipManager(pFactory->iShipId) != nullptr && G_->GetShipManager(pFactory->iShipId)->cloakSystem != nullptr && G_->GetShipManager(pFactory->iShipId)->cloakSystem->bTurnedOn)
    {
        value += pFactory->GetAugmentationValue("SELF_CLOAKING_CHARGE_RATE_INCREASE") - pFactory->GetAugmentationValue("SELF_CLOAKING_CHARGE_RATE_DECREASE") + weapon->selfCloakingChargeRateChange;
    }
    if (CustomOptionsManager::GetInstance()->enemyCloakingChargeRateChange.currentValue)
    {
        value += CustomOptionsManager::GetInstance()->enemyCloakingChargeRateChange.currentAmount;
    }
    if (pFactory->iHackLevel >= 2) // if hacked
    {
        hacked = true;
        value += pFactory->GetAugmentationValue("ENEMY_HACKING_CHARGE_RATE_INCREASE") - pFactory->GetAugmentationValue("ENEMY_HACKING_CHARGE_RATE_DECREASE") + weapon->enemyHackingChargeRateChange;
    }
    if (G_->GetShipManager(pFactory->iShipId) != nullptr && G_->GetShipManager(pFactory->iShipId)->hackingSystem != nullptr && G_->GetShipManager(pFactory->iShipId)->hackingSystem->currentSystem != nullptr && G_->GetShipManager(pFactory->iShipId)->hackingSystem->currentSystem->iHackEffect >= 2)
    {
        value += pFactory->GetAugmentationValue("SELF_HACKING_CHARGE_RATE_INCREASE") - pFactory->GetAugmentationValue("SELF_HACKING_CHARGE_RATE_DECREASE") + weapon->selfHackingChargeRateChange;
    }
    if (CustomOptionsManager::GetInstance()->enemyHackingChargeRateChange.currentValue)
    {
        value += CustomOptionsManager::GetInstance()->enemyHackingChargeRateChange.currentAmount;
    }

    pFactory->cooldown.first += G_->GetCFPS()->GetSpeedFactor() * 0.0625 * value * (1 + pFactory->GetAugmentationValue("AUTO_COOLDOWN")); // change rate of weapon charge while cloaking

    if ((value < -1 || hacked && value < 1 || enemyCloaked && value < 0) && pFactory->blueprint->chargeLevels <= pFactory->chargeLevel)
    {
        pFactory->chargeLevel -= 1;
    }
    else if ((value < -1 || hacked && value < 1 || enemyCloaked && value < 0) && pFactory->cooldown.first < 0)
    {
        if (pFactory->chargeLevel > 0)
        {
            pFactory->chargeLevel -= 1;
            pFactory->cooldown.first += pFactory->cooldown.second;
        }
        else
        {
            pFactory->cooldown.first = 0;
        }
    }
    else if (pFactory->cooldown.first > pFactory->cooldown.second)
    {
        if (pFactory->chargeLevel < pFactory->blueprint->chargeLevels)
        {
            pFactory->chargeLevel += 1;
            if (pFactory->chargeLevel == pFactory->blueprint->chargeLevels)
            {
                pFactory->cooldown.first = pFactory->cooldown.second;
            }
            else
            {
                pFactory->cooldown.first -= pFactory->cooldown.second;
            }
        }
        else
        {
            pFactory->cooldown.first = pFactory->cooldown.second;
        }
    }
}

HOOK_METHOD(ProjectileFactory, Update, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::Update -> Begin (CustomSystems.cpp)\n");

    modifyWeaponCooldown(this);

    super();
}

// HOOK_METHOD(MindSystem, ReleaseCrew, () -> void)
// {
//     hs_log_file("Did we do it?");

//     super();
// }

// HOOK_METHOD(ArtillerySystem, OnLoop, () -> void)
// {
//     LOG_HOOK("HOOK_METHOD -> ArtillerySystem::OnLoop -> Begin (CustomSystems.cpp)\n");

//     modifyWeaponCooldown(this->projectileFactory);

//     super();
// }

/*
HOOK_METHOD(ShipSystem, RenderPowerBoxes, (int x, int y, int width, int height, int gap, int heightMod, bool flash) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::RenderPowerBoxes -> Begin (CustomSystems.cpp)\n")
    super(x, y, width, height, gap, heightMod, flash);

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate((x + (64 - width)) / 2.f, (y + 10 - gap));

    if (powerState.second > 0)
    {

    }
}
*/
