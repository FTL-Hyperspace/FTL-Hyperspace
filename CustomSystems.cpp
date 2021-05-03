#include "CustomSystems.h"
#include "OverclockerSystem.h"

//(working) test system

HOOK_STATIC(ShipSystem, NameToSystemId, (std::string& name) -> int)
{
    if (name == "overclocker")
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
        strRef.assign("overclocker");
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

    for (auto i : myBlueprint.systems)
    {
        AddSystem(i);
    }
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

    std::vector<int> systemOrder = { 0, 1, 2, 3, 4, 5, 9, 10, 11, 12, 13, 14, 15, 20 };
    //std::vector<int> systemOrder = { 0, 1, 2, 3, 4, 5, 9, 10, 11, 12, 13, 14, 15 };

    for (auto sysId : systemOrder)
    {
        auto sys = shipManager->GetSystem(sysId);
        if (!sys || !sys->bNeedsPower) continue;

        switch (sysId)
        {
        case 14:
            {
                auto box = new MindBox(Point(xPos + 36, 269), shipManager->mindSystem);
                sysBoxes.push_back(box);
                xPos += 54;
                break;
            }
        case 13:
            {
                auto box = new CloneBox(Point(xPos + 36, 269), shipManager->cloneSystem);
                sysBoxes.push_back(box);
                xPos += 36;
                break;
            }
        case 15:
            {
                auto box = new HackBox(Point(xPos + 36, 269), shipManager->hackingSystem, shipManager);
                sysBoxes.push_back(box);
                xPos += 54;
                break;
            }
        case 9:
            {
                auto box = new TeleportBox(Point(xPos + 36, 269), shipManager->teleportSystem);
                sysBoxes.push_back(box);
                xPos += 54;
                break;
            }
        case 10:
            {
                auto box = new CloakingBox(Point(xPos + 36, 269), shipManager->cloakSystem);
                sysBoxes.push_back(box);
                xPos += 54;
                break;
            }
        case 11:
            {
                if (shipManager->artillerySystems.size() > 0)
                {
                    auto artillerySys = shipManager->artillerySystems[0];
                    auto box = new ArtilleryBox(Point(xPos + 36, 269), artillerySys);
                    sysBoxes.push_back(box);
                    xPos += 36;
                }
            }
            break;
        case 3:
            break;
        case 4:
            break;

        // Custom systems
        case 20:
            {
                auto box = new OverclockerBox(Point(xPos + 36, 269), sys, shipManager);
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

    int subXPos = subSystemPosition.x - 36;
    int subYPos = subSystemPosition.y;

    for (int i = 0; i < 4; i++)
    {
        int sysId = subSystemOrder[i];

        auto sys = shipManager->GetSystem(sysId);
        switch (sysId)
        {
        case 8:
            if (sys)
            {
                auto box = new DoorBox(Point(subXPos + 36, subYPos), sys, shipManager);
                sysBoxes.push_back(box);
                subXPos += sub_spacing + 36;
            }
            subXPos += 15;
            break;
        case 12:
            if (sys)
            {
                auto box = new BatteryBox(Point(subXPos + 36, subYPos), shipManager->batterySystem);
                sysBoxes.push_back(box);
                subXPos += sub_spacing + 36;
            }
            subXPos += 18;
            break;
        default:
            if (sys)
            {
                auto box = new SystemBox(Point(subXPos + 36, subYPos), sys, true);
                sysBoxes.push_back(box);
            }
            subXPos += sub_spacing + 36;
            break;
        }
    }
}

/*
HOOK_METHOD(ShipManager, AddSystem, (int sysId) -> ShipSystem*)
{
    if (sysId == 100)
    {
        auto sys = new TestSystem(100, 1, iShipId, 0);
        addedSystem = true;
        printf("%d\n", systemKey.size());
        return sys;
    }

    return super(sysId);
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
HOOK_STATIC(ShipSystem, GetLevelDescription, (void* unk, std::string &retStr, int systemId, int level, bool tooltip) -> void)
{
    super(unk, retStr, systemId, level, tooltip);

    std::string name = "";
    SystemIdToName(name, systemId);
    auto tLib = G_->GetTextLibrary();
    name += "_" + std::to_string(level + 1);
    if (tooltip)
    {
        name += "_" + std::to_string(level) + "_tooltip";
        retStr.assign(tLib->GetText(name));
    }
    else
    {
        retStr.assign(tLib->GetText(name));
    }
}
*/
