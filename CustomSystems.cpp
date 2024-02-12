#include "CustomSystems.h"
#include "TemporalSystem.h"
#include "CustomShipSelect.h"
#include "CustomShips.h"

#include <cmath>

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

static bool initRenderPowerBoxes = false;

static GL_Color COLOR_TRUE_WHITE = {1.f, 1.f, 1.f, 1.f};
static GL_Color COLOR_GREEN = {100.f/255.f, 255.f/255.f, 100.f/255.f, 1.f};
static GL_Color COLOR_CB_WHITE = {243.f/255.f, 255.f/255.f, 238.f/255.f, 1.f};
static GL_Color COLOR_BLUE_ION = {133.f/255.f, 231.f/255.f, 237.f/255.f, 1.f};
static GL_Color COLOR_PURPLE_HACKING = {207.f/255.f, 70.f/255.f, 253.f/255.f, 1.f};
static GL_Color COLOR_BLUE_ION_OUTLINE = {40.f/255.f, 210.f/255.f, 230.f/255.f, 1.f};
static GL_Color COLOR_RED = {255.f/255.f, 50.f/255.f, 50.f/255.f, 1.f};
static GL_Color COLOR_CB_RED = {227.f/255.f, 65.f/255.f, 63.f/255.f, 1.f};
static GL_Color COLOR_BATTERY_OUTLINE = {230.f/255.f, 110.f/255.f, 30.f/255.f, 1.f};
static GL_Color COLOR_YELLOW_BONUSPOWER = {255.f/255.f, 250.f/255.f, 90.f/255.f, 1.f};
static GL_Color COLOR_REPAIR = {255.f/255.f, 255.f/255.f, 50.f/255.f, 1.f};

static GL_Primitive *ErosionTimerPrimitive;
static std::array<GL_Primitive*,10> ErosionIconPrimitive;
static GL_Primitive *ErosionTimerStencil = nullptr;
int lastErosionTimerStencilCount = -1;

HOOK_METHOD(ShipSystem, constructor, (int systemId, int roomId, int shipId, int startingPower) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::constructor -> Begin (CustomSystems.cpp)\n")

    if (!initRenderPowerBoxes)
    {
        ErosionTimerPrimitive = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/ring_timer.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);
        ErosionIconPrimitive[0] = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/base_1.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);
        ErosionIconPrimitive[1] = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/base_2.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);
        ErosionIconPrimitive[2] = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/base_3.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);
        ErosionIconPrimitive[3] = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/base_4.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);
        ErosionIconPrimitive[4] = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/base_5.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);
        ErosionIconPrimitive[5] = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/base_6.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);
        ErosionIconPrimitive[6] = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/base_7.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);
        ErosionIconPrimitive[7] = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/base_8.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);
        ErosionIconPrimitive[8] = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/base_9.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);
        ErosionIconPrimitive[9] = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/base_9p.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);

        initRenderPowerBoxes = true;
    }

    super(systemId, roomId, shipId, startingPower);
}

HOOK_METHOD(ShipSystem, RenderPowerBoxes, (int x, int y, int width, int height, int gap, int heightMod, bool flash) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::RenderPowerBoxes -> Begin (CustomSystems.cpp)\n")

    //return super(x, y, width, height, gap, heightMod, flash);

    SystemControl::PowerBars *powerBars = SystemControl::GetPowerBars(width, height, gap, iSystemType == 0);

    float repairFraction = fRepairOverTime / 100.f;
    float damageFraction = fDamageOverTime / 100.f;

    float x_00 = x + (64 - width) / 2;
    float y_00 = y + 10 - gap;
    float y_01 = y_00;

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(x_00, y_00, 0.f);

    float spacing = height + gap;

    int healthPower = powerState.second + healthState.first - healthState.second;
    int maxPower = GetMaxPower();

    float erosionHealth = 1.0e30;
    int erosionTimer1 = 0;
    int erosionTimer2 = 0;

    if (roomId > -1)
    {
        ShipManager *shipManager = G_->GetShipManager(_shipObj.iShipId);
        if (shipManager && roomId < shipManager->ship.vRoomList.size())
        {
            Room *room = shipManager->ship.vRoomList[roomId];
            Room_Extend *room_ex = RM_EX(room);
            if (room_ex->erosion.timer > 0.f)
            {
                erosionHealth = healthPower + repairFraction - damageFraction - (room_ex->erosion.timer * room_ex->erosion.speed * 0.16f);

                float fErosionTimer = room_ex->erosion.timer/5.f;
                float fErosionTimer1 = ceil(fErosionTimer);
                erosionTimer1 = fErosionTimer1;
                erosionTimer2 = ceil((fErosionTimer-fErosionTimer1)*12.f)+12;
            }
        }
    }

    if (selectedState != 0 && iHackEffect < 2)
    {
        CSurface::GL_PushMatrix();
        for (int i=0; i<powerState.second; ++i)
        {
            if (i >= healthPower)
            {
                CSurface::GL_RenderPrimitive(*ShipSystem__glowRed);
            }
            else if (i >= maxPower)
            {
                CSurface::GL_RenderPrimitive(*ShipSystem__glowBlue);
            }
            else
            {
                CSurface::GL_RenderPrimitive(*ShipSystem__glowWhite);
                CSurface::GL_RenderPrimitive(*ShipSystem__glowWhite);
            }
            if (iSystemType == 0 && i+1<powerState.second && (i&1) != 0) // shields power bar gap
            {
                CSurface::GL_Translate(0.f, -gap*2, 0.f);
            }
            CSurface::GL_Translate(0.f, -spacing, 0.f);
        }
        CSurface::GL_PopMatrix();
    }

    for (int i=0; i<powerState.second; ++i)
    {
        if (flash) // flashing
        {
            CSurface::GL_RenderPrimitive(powerBars->normal[i]);
        }
        else if (i < powerState.first) // powered
        {
            GL_Color powerColor = COLOR_GREEN;
            if (G_->GetSettings()->colorblind) powerColor = COLOR_CB_WHITE;
            if (iHackEffect > 1)
            {
                powerColor = COLOR_PURPLE_HACKING;
            }
            else if (iLockCount == -1)
            {
                powerColor = COLOR_TRUE_WHITE;
            }
            else if (iLockCount > 0)
            {
                powerColor = COLOR_BLUE_ION;
            }
            CSurface::GL_RenderPrimitiveWithColor(powerBars->normal[i], powerColor);
        }
        else if (i < powerState.first + iBatteryPower)
        {
            GL_Color powerColor = COLOR_GREEN;
            if (G_->GetSettings()->colorblind) powerColor = COLOR_CB_WHITE;
            CSurface::GL_RenderPrimitiveWithColor(powerBars->tiny[i], powerColor);
            CSurface::GL_RenderPrimitiveWithColor(powerBars->empty[i], COLOR_BATTERY_OUTLINE);
        }
        else if (i < powerState.first + iBatteryPower + iBonusPower)
        {
            CSurface::GL_RenderPrimitiveWithColor(powerBars->normal[i], COLOR_YELLOW_BONUSPOWER);
        }
        else if (i >= healthPower)
        {
            GL_Color powerColor = COLOR_RED;
            if (G_->GetSettings()->colorblind) powerColor = COLOR_CB_RED;
            CSurface::GL_RenderPrimitiveWithColor(powerBars->damaged[i], powerColor);
            if (repairFraction > 0.f && i == healthPower)
            {
                CSurface::GL_DrawRect(width * (1.f-repairFraction), y_01-y_00, width * repairFraction, height, COLOR_REPAIR);
                if (erosionHealth < i+1)
                {
                    float erosionFraction = std::min(1.f, i+1-erosionHealth);
                    CSurface::GL_DrawRect(width * (1.f-repairFraction), y_01-y_00+height-2, width * (repairFraction - 1.f + erosionFraction), 2, COLOR_RED);
                }
            }
        }
        else if (i >= maxPower)
        {
            CSurface::GL_RenderPrimitiveWithColor(powerBars->damaged[i], COLOR_BLUE_ION_OUTLINE);
        }
        else
        {
            CSurface::GL_RenderPrimitive(powerBars->empty[i]);
        }

        if (i < healthPower)
        {
            if (erosionHealth < i+1)
            {
                float erosionFraction = std::min(1.f, i+1-erosionHealth);
                CSurface::GL_DrawRect(0, y_01-y_00+height-2, width * erosionFraction, 2, COLOR_RED);
            }
            if (damageFraction > 0.f && i == healthPower-1)
            {
                Globals::Rect newDamageRect;
                newDamageRect.x = 0;
                newDamageRect.y = y_01 - y_00;
                newDamageRect.w = width * damageFraction;
                newDamageRect.h = height;
                if (newDamageRect.x != partialDamageRect.x || newDamageRect.y != partialDamageRect.y || newDamageRect.w != partialDamageRect.w || newDamageRect.h != partialDamageRect.h)
                {
                    CSurface::GL_DestroyPrimitive(partialDamageRect.primitive);
                    partialDamageRect.primitive = nullptr;
                    partialDamageRect.x = newDamageRect.x;
                    partialDamageRect.y = newDamageRect.y;
                    partialDamageRect.w = newDamageRect.w;
                    partialDamageRect.h = newDamageRect.h;
                }
                partialDamageRect.OnRender(COLOR_RED);
            }
        }

        if (iSystemType == 0 && i+1<powerState.second && (i&1) != 0) // shields power bar gap
        {
            y_01 -= gap*2;
        }
        y_01 -= spacing;
    }

    y_01 += spacing;
    y_00 += height;

    CSurface::GL_Translate(0.f, height, 0.f);
    CSurface::GL_Translate(x-x_00, y_01-y_00, 0.f);

    if (bBoostable && !BlockedBoosted(!bLevelBoostable)) // can be manned
    {
        GL_Primitive *manningPrimitive;
        if (bLevelBoostable) // subsystems that can be boosted
        {
            if (iActiveManned >= 1 && bBoostable && healthState.first == healthState.second)
            {
                manningPrimitive = *ShipSystem__manningBarOn;
            }
            else if (BlockedBoosted(true))
            {
                manningPrimitive = *ShipSystem__manningBarIon;
            }
            else
            {
                manningPrimitive = *ShipSystem__manningBarOff;
            }
            CSurface::GL_RenderPrimitive(manningPrimitive);
        }
        else
        {
            if (iActiveManned < 1 || !bBoostable || healthState.first != healthState.second)
            {
                spacing = 16;
                manningPrimitive = *ShipSystem__manningOutline;
            }
            else if (iActiveManned == 1)
            {
                spacing = 16;
                manningPrimitive = *ShipSystem__manningWhite;
            }
            else if (iActiveManned == 2)
            {
                spacing = 24;
                manningPrimitive = *ShipSystem__manningGreen;
            }
            else if (iActiveManned == 3)
            {
                spacing = 24;
                manningPrimitive = *ShipSystem__manningYellow;
            }
            CSurface::GL_RenderPrimitive(manningPrimitive);
        }
        y_01 -= spacing;
        CSurface::GL_Translate(0.f, -spacing, 0.f);
    }

    if (heightMod > 0)
    {
        y_01 -= heightMod;
        CSurface::GL_Translate(0.f, -heightMod, 0.f);
    }

    GL_Primitive *lockPrimitive = nullptr;
    GL_Color lockColor;
    if (iHackEffect >= 2 && bUnderAttack)
    {
        lockPrimitive = *ShipSystem__lockHack;
        lockColor = COLOR_PURPLE_HACKING;
    }
    else if (iLockCount == -1)
    {
        lockPrimitive = *ShipSystem__lockWhite;
        lockColor = COLOR_TRUE_WHITE;
    }
    else if (iLockCount > 0)
    {
        lockPrimitive = *ShipSystem__lockBlue;
        lockColor = COLOR_BLUE_ION;
    }
    else if (iHackEffect >= 2)
    {
        lockPrimitive = *ShipSystem__lockBlue;
        lockColor = COLOR_BLUE_ION;
    }

    if (lockPrimitive)
    {
        float ionBoxGap = ((int)(gap/2))+2;

        Globals::Rect newOutline = {int((x_00-ionBoxGap)-x), int(heightMod - ionBoxGap), int(width + 2*ionBoxGap), int((y_00 + ionBoxGap) - (heightMod - ionBoxGap + y_01))};
        if (newOutline.x != lockOutline.x || newOutline.y != lockOutline.y || newOutline.w != lockOutline.w || newOutline.h != lockOutline.h)
        {
            CSurface::GL_DestroyPrimitive(lockOutline.primitive);
            lockOutline.primitive = nullptr;
            lockOutline.x = newOutline.x;
            lockOutline.y = newOutline.y;
            lockOutline.w = newOutline.w;
            lockOutline.h = newOutline.h;
            lockOutline.thickness = 2;
        }

        lockOutline.OnRender(lockColor);
        CSurface::GL_Translate(0.f, -ionBoxGap, 0.f);
        y_01 -= ionBoxGap;

        if (lockPrimitive != *ShipSystem__lockHack)
        {
            CSurface::GL_RenderPrimitive(lockPrimitive);
            CSurface::GL_Translate(0.f, -21.f, 0.f);
            y_01 -= 21.f;
        }
    }

    if (bUnderAttack && iHackEffect > 0)
    {
        CSurface::GL_RenderPrimitive(*ShipSystem__lockHack);
        CSurface::GL_Translate(0.f, -22.f, 0.f);
        y_01 -= 22.f;
    }

    if (erosionTimer1 > 0)
    {
        CSurface::GL_RenderPrimitive(ErosionIconPrimitive[std::min(erosionTimer1-1,9)]);

        if (erosionTimer2 != lastErosionTimerStencilCount)
        {
            lastErosionTimerStencilCount = erosionTimer2;
            CSurface::GL_DestroyPrimitive(ErosionTimerStencil);
            ErosionTimerStencil = CSurface::GL_CreatePiePartialPrimitive(32, -14, 17.f, -85.f, erosionTimer2*30-85, 17.f, COLOR_TRUE_WHITE);
        }

        CSurface::GL_SetStencilMode(STENCIL_SET,1,1);
        CSurface::GL_RenderPrimitive(ErosionTimerStencil);
        CSurface::GL_SetStencilMode(STENCIL_USE,1,1);
        CSurface::GL_RenderPrimitive(ErosionTimerPrimitive);
        CSurface::GL_SetStencilMode(STENCIL_IGNORE,0,0);

        CSurface::GL_Translate(0.f, -28.f, 0.f);
        y_01 -= 28.f;
    }

    if (bOccupied && fDamageOverTime != 0.f && !CompletelyDestroyed())
    {
        CSurface::GL_RenderPrimitive(*ShipSystem__sabotageImage);
        CSurface::GL_Translate(0.f, -24.f, 0.f);
        y_01 -= 24.f;
    }

    if (bOnFire)
    {
        CSurface::GL_RenderPrimitive(*ShipSystem__fireImage);
        CSurface::GL_Translate(0.f, -22.f, 0.f);
        y_01 -= 22.f;
    }

    CSurface::GL_PopMatrix();

    return y_01 - 20.f;
}
