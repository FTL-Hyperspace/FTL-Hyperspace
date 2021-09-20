#include "CustomSystems.h"
#include "TemporalSystem.h"
#include "CustomShipSelect.h"

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
        }
    }
}





HOOK_STATIC(ShipSystem, NameToSystemId, (std::string& name) -> int)
{
    if (name == "temporal")
    {
        return 20;
    }

    return super(name);
}

HOOK_STATIC(ShipSystem, SystemIdToName, (std::string& strRef, int systemId) -> std::string&)
{
    super(strRef, systemId);
    if (systemId == 20)
    {
        strRef.assign("temporal");
    }

    return strRef;
}



HOOK_METHOD(ShipSystem, constructor, (int systemId, int roomId, int shipId, int startingPower) -> void)
{
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

    auto realBp = G_->GetBlueprints()->GetShipBlueprint(myBlueprint.blueprintName, -1);

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

HOOK_METHOD(SystemControl, CreateSystemBoxes, () -> void)
{
    (*Global::droneWeaponPosition).first = Point(0, 0);
    (*Global::droneWeaponPosition).second = Point(0, 0);

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
        (*Global::droneWeaponPosition).second = Point(position.x + xPos + 36, position.y + 269);
        auto box = new WeaponSystemBox(Point(xPos + 36, 269), shipManager->GetSystem(3), &combatControl->weapControl);

        sysBoxes.push_back(box);

        if (shipManager->myBlueprint.weaponSlots >= 4)
        {
            xPos += 436;
        }
        else if (shipManager->myBlueprint.weaponSlots == 3)
        {
            xPos += 339;
        }
        else
        {
            xPos += 242;
        }
    }
    if (shipManager->HasSystem(4))
    {
        (*Global::droneWeaponPosition).first = Point(position.x + xPos + 36, position.y + 269);
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
    int sysLimit = custom->GetDefaultDefinition().systemLimit;

    if (custom->HasCustomDef(myBlueprint.blueprintName))
    {
        sysLimit = custom->GetDefinition(myBlueprint.blueprintName).systemLimit;
    }

    return count < sysLimit;
}

HOOK_METHOD(ShipManager, CanFitSubsystem, (int systemId) -> bool)
{
    int count = 0;

    for (auto i : vSystemList)
    {
        if (!i->bNeedsPower)
        {
            count++;
        }
    }

    auto custom = CustomShipSelect::GetInstance();
    int sysLimit = custom->GetDefaultDefinition().subsystemLimit;

    if (custom->HasCustomDef(myBlueprint.blueprintName))
    {
        sysLimit = custom->GetDefinition(myBlueprint.blueprintName).subsystemLimit;
    }

    return count < sysLimit;
}

/*
HOOK_METHOD(ShipManager, RenderChargeBars, () -> void)
{

}
*/

/*
HOOK_METHOD(ShipSystem, SetPowerLoss, (int powerLoss) -> int)
{
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
HOOK_STATIC(ShipSystem, GetLevelDescription, (void* unk, std::string& retStr, int systemId, int level, bool tooltip) -> void)
{
    super(unk, retStr, systemId, level, tooltip);

    std::string name = "";
    SystemIdToName(name, systemId);
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
        retStr.assign(tLib->GetText(name));
    }
    else
    {
        name += "_" + std::to_string(level);
        retStr.assign(tLib->GetText(name));
    }
}
*/

HOOK_METHOD(ShipSystem, GetEffectivePower, () -> int)
{
    int boostPower = 0;

    if (iActiveManned > 0 && bBoostable && healthState.first == healthState.second)
    {
        boostPower = bLevelBoostable;
    }

    return boostPower + iBatteryPower + powerState.first + iBonusPower;
}

/*
HOOK_METHOD(ShipSystem, RenderPowerBoxes, (int x, int y, int width, int height, int gap, int heightMod, bool flash) -> void)
{
    super(x, y, width, height, gap, heightMod, flash);

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate((x + (64 - width)) / 2.f, (y + 10 - gap));

    if (powerState.second > 0)
    {

    }
}
*/
