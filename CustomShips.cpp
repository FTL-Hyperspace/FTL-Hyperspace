#include "CustomAugments.h"
#include "CustomShips.h"
#include "CustomShipSelect.h"
#include "EnemyShipIcons.h"

#include <boost/lexical_cast.hpp>

static bool importingShip = false;
bool revisitingShip = false;
bool bNoJump = false;

HOOK_METHOD(WorldManager, CreateShip, (ShipEvent* shipEvent, bool boss) -> CompleteShip*)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateShip -> Begin (CustomShips.cpp)\n")
    if (!boss && !shipEvent->actualBlueprint.blueprintName.empty()) revisitingShip = true;
    CompleteShip* ret = super(shipEvent, boss);
    revisitingShip = false;
    return ret;
}

bool g_enemyPreigniterFix = false;

void ShipManager_Extend::Initialize(bool restarting)
{
    CustomShipSelect *customSel = CustomShipSelect::GetInstance();

    isNewShip = customSel->IsCustomShip(orig->myBlueprint.blueprintName);

    CustomShipDefinition &def = customSel->GetDefinition(orig->myBlueprint.blueprintName);
    if (!importingShip)
    {
        for (auto &i : def.hiddenAugs)
        {
            G_->GetShipInfo(orig->iShipId)->augList["HIDDEN " + i.first] = i.second;
        }
        CustomAugmentManager::GetInstance()->UpdateAugments(orig->iShipId);
    }

    for (auto &i : def.roomDefs)
    {
        if (i.first < orig->ship.vRoomList.size())
        {
            Room *room = orig->ship.vRoomList[i.first];
            auto rex = RM_EX(room);

            for (auto &def2 : i.second->roomAnims)
            {
                rex->roomAnims.emplace_back(def2, room);
            }

            rex->sensorBlind = i.second->sensorBlind;
            rex->sysDamageResistChance = i.second->sysDamageResistChance;
            rex->ionDamageResistChance = i.second->ionDamageResistChance;
            rex->hullDamageResistChance = i.second->hullDamageResistChance;
        }
    }

    for (auto &i : def.shipIcons)
    {
        auto iconDef = ShipIconManager::instance->GetShipIconDefinition(i);
        if (iconDef)
        {
            ShipIcon* icon = new ShipIcon();

            icon->OnInit(iconDef->name, iconDef->tooltip, icons.size());
            icons.push_back(icon);
        }
    }

    if (!revisitingShip)
    {
        for (auto &i : def.crewList)
        {
            //species variable isn't used so it seems like the following code is dead and isList does nothing?
            auto species = i.species;

            if (i.isList)
            {
                std::vector<std::string> bpList = G_->GetBlueprints()->GetBlueprintList(i.species);

                if (!bpList.empty())
                {
                    species = bpList[rand() % bpList.size()];
                }
                else
                {
                    species = "human";
                }
            }

            orig->AddCrewMemberFromString(i.name, i.species, false, i.roomId, false, random32() % 2);

            orig->bAutomated = false;
        }
    }

    if (restarting)
    {
        if (def.startingScrap != -1)
        {
            orig->currentScrap = def.startingScrap;
        }
        if (def.startingFuel != -1)
        {
            orig->fuel_count = def.startingFuel;
        }
    }

    if (def.forceAutomated.enabled)
    {
        orig->bAutomated = def.forceAutomated.value;
    }
}

HOOK_METHOD(ShipManager, ResetScrapLevel, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ResetScrapLevel -> Begin (CustomShips.cpp)\n")
    super();
    auto customSel = CustomShipSelect::GetInstance();

    auto def = customSel->GetDefinition(myBlueprint.blueprintName);
    if (def.startingScrap != -1)
    {
        currentScrap = def.startingScrap;
    }
    if (def.startingFuel != -1)
    {
        fuel_count = def.startingFuel;
    }
}

HOOK_METHOD_PRIORITY(ShipManager, OnLoop, -1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::OnLoop -> Begin (CustomShips.cpp)\n")

    if (!importingShip) super();
}

HOOK_METHOD_PRIORITY(ShipManager, ImportShip, -1000, (int fileHelper) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::ImportShip -> Begin (CustomShips.cpp)\n")
    if (iShipId == 0)
    {
        G_->GetWorld()->playerShip = nullptr; // remove invalid reference
    }

    importingShip = true;
    super(fileHelper);
    importingShip = false;

    // Normally FTL calls OnLoop after importing the ship; here we want to block it and call it after the hooks instead
    if (bDestroyed)
    {
        std::vector<float> oxygenLevels;
        ship.OnLoop(oxygenLevels);
    }
    else
    {
        OnLoop();
    }
}

HOOK_METHOD(ShipManager, AddSystem, (int systemId) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::AddSystem -> Begin (CustomShips.cpp)\n")
    auto ret = super(systemId);

    // Fixes shield systems being created with damage when >10 bars
    if (systemId == SYS_SHIELDS && shieldSystem)
    {
        shieldSystem->healthState.first = shieldSystem->healthState.second;
    }

    // Fixes buying hacking at a store with a ship present
    else if (systemId == SYS_HACKING && hackingSystem)
    {
        if (current_target)
        {
            hackingSystem->drone.SetMovementTarget(&current_target->_targetable);
            G_->GetWorld()->space.drones.push_back(&hackingSystem->drone);
        }
    }

    return ret;
}


HOOK_METHOD_PRIORITY(ShipManager, OnInit, 100, (ShipBlueprint *bp, int shipLevel) -> int)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::OnInit -> Begin (CustomShips.cpp)\n")
    int ret = super(bp, shipLevel);

    SM_EX(this)->Initialize();

    return ret;
}

//AddInitialCrew adds all crew from ShipManager::myBlueprint::customCrew
//So the crew added by Hyperspace are temporarily removed from customCrew so crew aren't added twice on restart
HOOK_METHOD(ShipManager, Restart, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::Restart -> Begin (CustomShips.cpp)\n")

    int hyperspaceCrewCount = CustomShipSelect::GetInstance()->GetDefinition(myBlueprint.blueprintName).crewList.size();
    std::vector<CrewBlueprint>& customCrew = myBlueprint.customCrew;
    std::vector<CrewBlueprint> removedCrew(customCrew.end() - hyperspaceCrewCount, customCrew.end());
    super();
    customCrew.insert(customCrew.end(), removedCrew.begin(), removedCrew.end());
    SM_EX(this)->Initialize(true);
}

float CrewMemberFactory::GetCrewCapacityUsed()
{
    return CustomCrewManager::GetInstance()->crewCapacityUsed;
}

static CrewBlueprint *storeCrewBlue = nullptr;
HOOK_METHOD(ShipManager, IsCrewFull, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::IsCrewFull -> Begin (CustomShips.cpp)\n")
    if (iShipId == 1) return false; // no limit for enemy

    auto custom = CustomShipSelect::GetInstance();
    float crewCount = G_->GetCrewFactory()->GetCrewCapacityUsed();
    int crewLimit = custom->GetDefinition(myBlueprint.blueprintName).crewLimit;

    if (storeCrewBlue)
    {
        // If looking at a store blueprint, check if adding this crew would put the player over capacity
        CrewDefinition *crewDef = CustomCrewManager::GetInstance()->GetDefinition(storeCrewBlue->name);
        if (crewDef)
        {
            crewCount += StatBoostManager::GetInstance()->CalculateStatDummy(CrewStat::CREW_SLOTS, crewDef, 0, 0);
        }
        else
        {
            crewCount += 1.f;
        }
        return crewCount > crewLimit;
    }
    else
    {
        // Just check whether there is any capacity remaining, add an extra 0.001 to crewCount so if there's less than 0.001 slot then act as though it is full
        return crewCount + 0.001f >= crewLimit;
    }
}

HOOK_METHOD(CrewStoreBox, CanHold, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CrewStoreBox::CanHold -> Begin (CustomShips.cpp)\n")

    storeCrewBlue = &blueprint;
    bool ret = super();
    storeCrewBlue = nullptr;

    return ret;
}

HOOK_METHOD(CrewStoreBox, MouseMove, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewStoreBox::MouseMove -> Begin (CustomShips.cpp)\n")

    storeCrewBlue = &blueprint;
    super(mX, mY);
    storeCrewBlue = nullptr;
}

HOOK_METHOD(ShipManager, IsCrewOverFull, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::IsCrewOverFull -> Begin (CustomShips.cpp)\n")
    if (iShipId == 1) return false; // no limit for enemy

    auto custom = CustomShipSelect::GetInstance();
    float crewCount = G_->GetCrewFactory()->GetCrewCapacityUsed();
    int crewLimit = custom->GetDefinition(myBlueprint.blueprintName).crewLimit;

    if (crewLimit >= crewCount) return false;

    // Allow the upgrade/equipment screens to be opened without forcing the crew screen open
    CommandGui *commandGui = G_->GetWorld()->commandGui;
    return !(commandGui->upgradeScreen.bOpen || commandGui->equipScreen.bOpen);
}

HOOK_METHOD(Room, constructor, (int iShipId, int x, int y, int w, int h, int roomId) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Room::constructor -> Begin (CustomShips.cpp)\n")
    super(iShipId, x, y, w, h, roomId);

    CSurface::GL_DestroyPrimitive(o2LowPrimitive);

    char buf[128];

    sprintf(buf, "effects/low_o2_stripes_%dx%d.png", w, h);

    o2LowPrimitive = G_->GetResources()->CreateImagePrimitiveString(buf, rect.x, rect.y, 0, COLOR_WHITE, 0.5f, false);
}


HOOK_METHOD(ShipManager, CheckVision, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::CheckVision -> Begin (CustomShips.cpp)\n")
    return super();

    bool canSee = false;

    if (iShipId == 0)
    {
        int sensorRoom = systemKey[7];

        if (sensorRoom != -1)
        {
            ShipSystem *sensors = vSystemList[sensorRoom];
            canSee = sensors->GetEffectivePower() > 0 && !(sensors->iHackEffect > 1);
        }
    }
    else if (current_target != nullptr)
    {
        int sensorRoom = current_target->systemKey[7];

        if (sensorRoom != -1)
        {
            ShipSystem *sensors = current_target->vSystemList[sensorRoom];
            canSee = sensors->GetEffectivePower() > 1 && !(sensors->iHackEffect > 1);
        }
    }


    for (auto i : ship.vRoomList)
    {
        if (tempVision[i->iRoomId])
        {
            i->bBlackedOut = false;
            continue;
        }
        if (canSee)
        {
            i->bBlackedOut = false;
        }
        if (RM_EX(i)->sensorBlind)
        {
            i->bBlackedOut = true;
        }
    }

    if (iShipId == 1 && !canSee)
    {
        bool giveAch = true;

        for (int i = 0; i < ship.vRoomList.size(); i++)
        {
            if (ShipGraph::GetShipInfo(iShipId)->GetRoomBlackedOut(i))
            {
                giveAch = false;
                break;
            }
        }

        if (giveAch)
        {
            G_->GetAchievementTracker()->SetAchievement("ACH_SLUG_VISION", false, true);
        }
    }
}

void RoomAnim::OnUpdate()
{
    if (anim)
    {
        anim->Update();
    }
    for (Animation &tileAnim : tileAnims)
    {
        tileAnim.Update();
    }
    if (wallAnim)
    {
        wallAnim->Update();
    }
}

void RoomAnim::OnRender()
{
    if (anim)
    {
        anim->OnRender(1.f, COLOR_WHITE, false);
    }
    for (Animation &tileAnim : tileAnims)
    {
        tileAnim.OnRender(1.f, COLOR_WHITE, false);
    }
    if (wallAnim)
    {
        // bottom
        for (int xPos = 0; xPos < w; xPos++)
        {
            CSurface::GL_PushMatrix();

            CSurface::GL_Translate(pos.x + xPos * 35, pos.y + h*35 - 35);
            wallAnim->OnRender(1.f, COLOR_WHITE, false);

            CSurface::GL_PopMatrix();
        }

        // top
        for (int xPos = 0; xPos < w; xPos++)
        {
            CSurface::GL_PushMatrix();

            CSurface::GL_Translate(pos.x + xPos * 35 + 35, pos.y + 35.f);
            CSurface::GL_Rotate(180.f, 0.f, 0.f, 1.f);
            wallAnim->OnRender(1.f, COLOR_WHITE, false);

            CSurface::GL_PopMatrix();
        }

        // left
        for (int yPos = 0; yPos < h; yPos++)
        {
            CSurface::GL_PushMatrix();

            CSurface::GL_Translate(pos.x + 35, pos.y + yPos * 35.f);
            CSurface::GL_Rotate(90.f, 0.f, 0.f, 1.f);
            wallAnim->OnRender(1.f, COLOR_WHITE, false);

            CSurface::GL_PopMatrix();
        }

        // right
        for (int yPos = 0; yPos < h; yPos++)
        {
            CSurface::GL_PushMatrix();

            CSurface::GL_Translate(pos.x + w*35 - 35.f, pos.y + yPos * 35.f + 35.f);
            CSurface::GL_Rotate(-90.f, 0.f, 0.f, 1.f);
            wallAnim->OnRender(1.f, COLOR_WHITE, false);

            CSurface::GL_PopMatrix();
        }
    }
}

void RoomAnim::SaveState(int fd)
{
    FileHelper::writeInt(fd, renderLayer);
    FileHelper::writeFloat(fd, pos.x);
    FileHelper::writeFloat(fd, pos.y);
    FileHelper::writeInt(fd, w);
    FileHelper::writeInt(fd, h);

    FileHelper::writeInt(fd, anim.get() != nullptr);
    if (anim)
    {
        FileHelper::writeString(fd, anim->animName);
        anim->SaveState(fd);
    }

    FileHelper::writeInt(fd, tileAnims.size());
    for (Animation &tileAnim : tileAnims)
    {
        FileHelper::writeString(fd, tileAnim.animName);
        tileAnim.SaveState(fd);
    }

    FileHelper::writeInt(fd, wallAnim.get() != nullptr);
    if (wallAnim)
    {
        FileHelper::writeString(fd, wallAnim->animName);
        wallAnim->SaveState(fd);
    }
}

void RoomAnim::LoadState(int fd, Room *room)
{
    pos.x = room->rect.x;
    pos.y = room->rect.y;
    w = room->rect.w/35;
    h = room->rect.h/35;

    renderLayer = FileHelper::readInteger(fd);
    pos.x = FileHelper::readFloat(fd);
    pos.y = FileHelper::readFloat(fd);
    w = FileHelper::readInteger(fd);
    h = FileHelper::readInteger(fd);

    if (FileHelper::readInteger(fd))
    {
        anim.reset(new Animation(G_->GetAnimationControl()->GetAnimation(FileHelper::readString(fd))));
        anim->LoadState(fd);
    }

    int n = FileHelper::readInteger(fd);
    for (int i=0; i<n; ++i)
    {
        tileAnims.emplace_back(G_->GetAnimationControl()->GetAnimation(FileHelper::readString(fd)));
        tileAnims.back().LoadState(fd);
    }

    if (FileHelper::readInteger(fd))
    {
        wallAnim.reset(new Animation(G_->GetAnimationControl()->GetAnimation(FileHelper::readString(fd))));
        wallAnim->LoadState(fd);
    }
}

HOOK_METHOD(SoundControl, UpdateSoundLoop, (const std::string &loopId, float count) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SoundControl::UpdateSoundLoop -> Begin (CustomShips.cpp)\n")

    if (loopId == "hackLoop") return;

    if (loopId == "hackLoopHS")
    {
        super("hackLoop", count);
    }
    else
    {
        super(loopId, count);
    }
}

HOOK_METHOD(ShipManager, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnLoop -> Begin (CustomShips.cpp)\n")
    super();

    for (auto i : ship.vRoomList)
    {
        auto ex = RM_EX(i);

        for (auto& anim : ex->roomAnims)
        {
            anim.OnUpdate();
        }
        if (ex->erosion.anim)
        {
            ex->erosion.anim->OnUpdate();
        }
    }

    bool hackSoundLoop = false;
    if (hackingSystem)
    {
        hackSoundLoop = hackingSystem->SoundLoop();
    }
    if (!hackSoundLoop)
    {
        ShipManager* otherShip = G_->GetShipManager(iShipId == 1 ? 0 : 1);
        if (otherShip)
        {
            for (auto system : otherShip->vSystemList)
            {
                if (system->bUnderAttack && system->iHackEffect == 2)
                {
                    hackSoundLoop = true;
                    break;
                }
            }
        }
        if (!hackSoundLoop)
        {
            for (auto system : vSystemList)
            {
                if (system->bUnderAttack && system->iHackEffect == 2)
                {
                    hackSoundLoop = true;
                    break;
                }
            }
        }
    }
    G_->GetSoundControl()->UpdateSoundLoop("hackLoopHS", hackSoundLoop ? 1.f : 0.f);
}


HOOK_METHOD(ShipManager, OnRender, (bool showInterior, bool doorControlMode) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnRender -> Begin (CustomShips.cpp)\n")
    super(showInterior, doorControlMode);

    bool canSeeRooms = false;

    if (iShipId == 1)
    {
        bool hasCloakingSystem = systemKey[10] != -1;

        canSeeRooms = (_targetable.hostile && (!hasCloakingSystem || !cloakSystem->bTurnedOn)) || bContainsPlayerCrew;
    }
    else
    {
        canSeeRooms = bShowRoom;
    }

    canSeeRooms = canSeeRooms && !bDestroyed && !bJumping;

    for (auto room : ship.vRoomList)
    {
        auto ex = RM_EX(room);

        for (auto& i : ex->roomAnims)
        {
            if (i.renderLayer == 4 || (canSeeRooms && i.renderLayer == 3))
            {
                i.OnRender();
            }
        }
        for (auto& i : ex->statBoosts)
        {
            if (i.roomAnim)
            {
                if (i.roomAnim->renderLayer == 4 || (canSeeRooms && i.roomAnim->renderLayer == 3))
                {
                    i.roomAnim->OnRender();
                }
            }
        }
        if (ex->erosion.anim)
        {
            if (ex->erosion.anim->renderLayer == 4 || (canSeeRooms && ex->erosion.anim->renderLayer == 3))
            {
                ex->erosion.anim->OnRender();
            }
        }
    }
}

HOOK_METHOD(Ship, OnRenderSparks, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnRenderSparks -> Begin (CustomShips.cpp)\n")
    for (auto room : vRoomList)
    {
        auto ex = RM_EX(room);

        for (auto& i : ex->roomAnims)
        {
            if (i.renderLayer == 2)
            {
                i.OnRender();
            }
        }
        for (auto& i : ex->statBoosts)
        {
            if (i.roomAnim)
            {
                if (i.roomAnim->renderLayer == 2)
                {
                    i.roomAnim->OnRender();
                }
            }
        }
        if (ex->erosion.anim)
        {
            if (ex->erosion.anim->renderLayer == 2)
            {
                ex->erosion.anim->OnRender();
            }
        }
    }

    super();
}

HOOK_METHOD(Ship, OnRenderBreaches, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnRenderBreaches -> Begin (CustomShips.cpp)\n")
    for (auto room : vRoomList)
    {
        auto ex = RM_EX(room);

        if (room->bBlackedOut) continue;

        for (auto& i : ex->roomAnims)
        {
            if (i.renderLayer == 1)
            {
                i.OnRender();
            }
        }
        for (auto& i : ex->statBoosts)
        {
            if (i.roomAnim)
            {
                if (i.roomAnim->renderLayer == 1)
                {
                    i.roomAnim->OnRender();
                }
            }
        }
        if (ex->erosion.anim)
        {
            if (ex->erosion.anim->renderLayer == 1)
            {
                ex->erosion.anim->OnRender();
            }
        }
    }

    super();
}

HOOK_METHOD(Ship, OnRenderFloor, (bool experimental) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnRenderFloor -> Begin (CustomShips.cpp)\n")
    super(experimental);

    for (auto room : vRoomList)
    {
        auto ex = RM_EX(room);

        if (room->bBlackedOut) continue;

        for (auto& i : ex->roomAnims)
        {
            if (i.renderLayer == 0)
            {
                i.OnRender();
            }
        }
        for (auto& i : ex->statBoosts)
        {
            if (i.roomAnim)
            {
                if (i.roomAnim->renderLayer == 0)
                {
                    i.roomAnim->OnRender();
                }
            }
        }
        if (ex->erosion.anim)
        {
            if (ex->erosion.anim->renderLayer == 0)
            {
                ex->erosion.anim->OnRender();
            }
        }
    }
}


bool g_warningLightPositionFix = false;

void RelocateWarningLight(Room *room, int x, int y, int rotation)
{
    CSurface::GL_DestroyPrimitive(room->lightPrimitive);
    room->lightPrimitive = G_->GetResources()->CreateImagePrimitiveString("effects/light_base.png", x, y, rotation, COLOR_WHITE, 1.f, false);
    CSurface::GL_DestroyPrimitive(room->lightGlowPrimitive);
    room->lightGlowPrimitive = G_->GetResources()->CreateImagePrimitiveString("effects/light_glow.png", x, y, rotation, COLOR_WHITE, 1.f, false);
}

HOOK_METHOD(Ship, OnInit, (ShipBlueprint* bp) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnInit -> Begin (CustomShips.cpp)\n")
    super(bp);

    CSurface::GL_DestroyPrimitive(wallsPrimitive);

    std::vector<GL_Line> walls = std::vector<GL_Line>();

    // door length: 21
    std::vector<GL_Line> gaps = std::vector<GL_Line>();

    for (auto door : vDoorList)
    {
        if (door->bVertical)
        {
            gaps.push_back(GL_Line(door->x, door->y - door->height / 2, door->x, door->y + door->height / 2));
        }
        else
        {
            gaps.push_back(GL_Line(door->x - door->width / 2, door->y, door->x + door->width / 2, door->y));
        }
    }

    for (auto door : vOuterAirlocks)
    {
        if (door->bVertical)
        {
            gaps.push_back(GL_Line(door->x, door->y - door->height / 2, door->x, door->y + door->height / 2));
        }
        else
        {
            gaps.push_back(GL_Line(door->x - door->width / 2, door->y, door->x + door->width / 2, door->y));
        }
    }



    for (auto i : vRoomList)
    {

        for (int j = 0; j < (i->rect.w / 35); j++)
        {
            // top


            walls.push_back(GL_Line(i->rect.x + j * 35 - (j != 0), i->rect.y + 1, i->rect.x + 9 + j * 35, i->rect.y + 1));

            bool hasDoor = false;

            for (auto gap : gaps)
            {
                if (gap.start.x == i->rect.x + 9 + j * 35 && gap.start.y == i->rect.y)
                {
                    hasDoor = true;
                    break;
                }
            }

            if (!hasDoor)
            {
                walls.push_back(GL_Line(i->rect.x + 9 + j * 35, i->rect.y + 1, i->rect.x + 9 + j * 35 + 16, i->rect.y + 1));
            }


            walls.push_back(GL_Line(i->rect.x + j * 35 + 27 - 2, i->rect.y + 1, i->rect.x + 9 + j * 35 + 26, i->rect.y + 1));

            // bottom

            walls.push_back(GL_Line(i->rect.x + j * 35 - (j != 0), i->rect.y + i->rect.h - 1, i->rect.x + 9 + j * 35, i->rect.y + i->rect.h - 1));

            hasDoor = false;

            for (auto gap : gaps)
            {
                if (gap.start.x == i->rect.x + 9 + j * 35 && gap.start.y == i->rect.y + i->rect.h)
                {
                    hasDoor = true;
                    break;
                }
            }

            if (!hasDoor)
            {
                walls.push_back(GL_Line(i->rect.x + 9 + j * 35, i->rect.y + i->rect.h - 1, i->rect.x + 9 + j * 35 + 16, i->rect.y + i->rect.h - 1));
            }

            walls.push_back(GL_Line(i->rect.x + j * 35 + 27 - 2, i->rect.y + i->rect.h - 1, i->rect.x + 8 + j * 35 + 26, i->rect.y + i->rect.h - 1));
        }

        for (int j = 0; j < (i->rect.h / 35); j++)
        {
            walls.push_back(GL_Line(i->rect.x + 1, i->rect.y + j * 35 - (j != 0), i->rect.x + 1, i->rect.y + 9 + j * 35));

            bool hasDoor = false;

            for (auto gap : gaps)
            {
                if (gap.start.x == i->rect.x && gap.start.y == i->rect.y + 9 + j * 35)
                {
                    hasDoor = true;
                    break;
                }
            }

            if (!hasDoor)
            {
                walls.push_back(GL_Line(i->rect.x + 1, i->rect.y + 9 + j * 35, i->rect.x + 1, i->rect.y + 9 + j * 35 + 16));
            }


            walls.push_back(GL_Line(i->rect.x + 1, i->rect.y + j * 35 + 27 - 2, i->rect.x + 1, i->rect.y + 9 + j * 35 + 26));

            walls.push_back(GL_Line(i->rect.x + i->rect.w - 1, i->rect.y + j * 35 - (j != 0), i->rect.x + i->rect.w - 1, i->rect.y + 9 + j * 35));

            hasDoor = false;

            for (auto gap : gaps)
            {
                if (gap.start.x == i->rect.x + i->rect.w && gap.start.y == i->rect.y + 9 + j * 35)
                {
                    hasDoor = true;
                    break;
                }
            }

            if (!hasDoor)
            {
                walls.push_back(GL_Line(i->rect.x + i->rect.w - 1, i->rect.y + 9 + j * 35, i->rect.x + i->rect.w - 1, i->rect.y + 9 + j * 35 + 16));
            }


            walls.push_back(GL_Line(i->rect.x + i->rect.w - 1, i->rect.y + j * 35 + 27 - 2, i->rect.x + i->rect.w - 1, i->rect.y + 9 + j * 35 + 26));

        }
    }

    wallsPrimitive = CSurface::GL_CreateMultiLinePrimitive(walls, GL_Color(0.f, 0.f, 0.f, 1.f), 2.f);


    // warning light relocation
    if (!g_warningLightPositionFix) return;

    for (auto i : vRoomList)
    {
        int columns = i->rect.w / 35;
        int rows = i->rect.h / 35;

        if (columns % 2 == 0) // columns is even number -> set the light to the bottom center
        {
            RelocateWarningLight(i, i->rect.x + (columns / 2 - 1) * 35, i->rect.y + i->rect.h - 37, 0);
            continue;
        }
        else if (rows % 2 == 0) // rows is even number -> set the light to the left center
        {
            RelocateWarningLight(i, i->rect.x - 15, i->rect.y + (rows / 2 - 1) * 35 + 17, 90);
            continue;
        }

        // handle odd x odd shape

        int horizontal_center = columns / 2;
        int vertical_center = rows / 2;
        int candidate_diff_from_center = 9999;
        int candidate_dimention = -1; // 0: bottom, 1: top, 2: left, 3: right
        int candidate_index;

        // find the empty wall closest to the center
        for (int j = 0; j < columns && candidate_diff_from_center > 0; j++)
        {
            // bottom

            bool hasDoor = false;

            for (auto gap : gaps)
            {
                if (gap.start.x == i->rect.x + 9 + j * 35 && gap.start.y == i->rect.y + i->rect.h)
                {
                    hasDoor = true;
                    break;
                }
            }

            if (!hasDoor && abs(j - horizontal_center) < candidate_diff_from_center)
            {
                candidate_diff_from_center = abs(j - horizontal_center);
                candidate_dimention = 0;
                candidate_index = j;
                continue;
            }

            // top

            hasDoor = false;

            for (auto gap : gaps)
            {
                if (gap.start.x == i->rect.x + 9 + j * 35 && gap.start.y == i->rect.y)
                {
                    hasDoor = true;
                    break;
                }
            }

            if (!hasDoor && abs(j - horizontal_center) < candidate_diff_from_center)
            {
                candidate_diff_from_center = abs(j - horizontal_center);
                candidate_dimention = 1;
                candidate_index = j;
            }
        }

        for (int j = 0; j < rows && candidate_diff_from_center > 0; j++)
        {
            // left

            bool hasDoor = false;

            for (auto gap : gaps)
            {
                if (gap.start.x == i->rect.x && gap.start.y == i->rect.y + 9 + j * 35)
                {
                    hasDoor = true;
                    break;
                }
            }

            if (!hasDoor && abs(j - vertical_center) < candidate_diff_from_center)
            {
                candidate_diff_from_center = abs(j - vertical_center);
                candidate_dimention = 2;
                candidate_index = j;
                continue;
            }

            // right

            hasDoor = false;

            for (auto gap : gaps)
            {
                if (gap.start.x == i->rect.x + i->rect.w && gap.start.y == i->rect.y + 9 + j * 35)
                {
                    hasDoor = true;
                    break;
                }
            }

            if (!hasDoor && abs(j - vertical_center) < candidate_diff_from_center)
            {
                candidate_diff_from_center = abs(j - vertical_center);
                candidate_dimention = 3;
                candidate_index = j;
            }
        }

        switch (candidate_dimention)
        {
            case 0: // bottom
                RelocateWarningLight(i, i->rect.x + candidate_index * 35 - 17, i->rect.y + i->rect.h - 37, 0);
                continue;
            case 1: // top
                RelocateWarningLight(i, i->rect.x + candidate_index * 35 - 17, i->rect.y + 2, 180);
                continue;
            case 2: // left
                RelocateWarningLight(i, i->rect.x - 15, i->rect.y + candidate_index * 35, 90);
                continue;
            case 3: //right
                // note: the light image shrinks at the bottom by 1 pixel when rotating 270 degrees
                RelocateWarningLight(i, i->rect.x + i->rect.w - 54, i->rect.y + candidate_index * 35, 270);
                continue;
        }

        // handle the case where every wall has a door

        if (columns > 1)
        {
            RelocateWarningLight(i, i->rect.x + (horizontal_center - 1) * 35, i->rect.y + i->rect.h - 37, 0);
        }
        else if (rows > 1)
        {
            RelocateWarningLight(i, i->rect.x - 15, i->rect.y + (vertical_center - 1) * 35 + 17, 90);
        }
        else // where 1x1 room has 4 doors -> move the light to the bottom left corner
        {
            RelocateWarningLight(i, i->rect.x - 30, i->rect.y + i->rect.h - 37, 0);
        }
    }
}

HOOK_METHOD(CommandGui, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::OnLoop -> Begin (CustomShips.cpp)\n")
    super();
    auto custom = CustomShipSelect::GetInstance();

    if (shipComplete && shipComplete->shipManager->current_target && custom->GetDefinition(shipComplete->shipManager->current_target->myBlueprint.blueprintName).noJump)
    {
        ftlButton.bActive = false;
        ftlButton.bOutOfFuel = true;
        bNoJump = true;
    }
    else
    {
        bNoJump = false;
    }
}

HOOK_METHOD(FTLButton, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> FTLButton::OnRender -> Begin (CustomShips.cpp)\n")
    if (bNoJump)
    {
        float jump_timer = ship->jump_timer.first;
        ship->jump_timer.first = ship->jump_timer.second;
        super();
        ship->jump_timer.first = jump_timer;
        if (bHoverRaw)
        {
            G_->GetMouseControl()->SetTooltip(G_->GetTextLibrary()->GetText("tooltip_jump_noJump"));
        }
    }
    else
    {
        super();
    }
}

HOOK_METHOD(ShipManager, DamageSystem, (int roomId, Damage dmg) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::DamageSystem -> Begin (CustomShips.cpp)\n")

    auto ex = RM_EX(ship.vRoomList[roomId]);

    if (random32() % 100 < ex->sysDamageResistChance && (dmg.iSystemDamage > -dmg.iDamage))
    {
        dmg.iSystemDamage = -dmg.iDamage;
        auto msg = new DamageMessage(1.f, ship.GetRoomCenter(roomId), DamageMessage::MessageType::RESIST);
        msg->color.a = 1.f;
        damMessages.push_back(msg);
    }
    if (random32() % 100 < ex->ionDamageResistChance && dmg.iIonDamage > 0)
    {
        dmg.iIonDamage = 0;
        auto msg = new DamageMessage(1.f, ship.GetRoomCenter(roomId), DamageMessage::MessageType::RESIST);
        msg->color.r = 40.f / 255.f;
        msg->color.g = 210.f / 255.f;
        msg->color.b = 230.f / 255.f;
        msg->color.a = 1.f;
        damMessages.push_back(msg);
    }

    super(roomId, dmg);
}

HOOK_METHOD(ShipManager, DamageArea, (Pointf location, Damage dmg, bool forceHit) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::DamageArea -> Begin (CustomShips.cpp)\n")

    int roomId = ship.GetSelectedRoomId(location.x, location.y, true);
    bool resist = false;

    if (roomId > -1 && dmg.iDamage > 0 && random32() % 100 < RM_EX(ship.vRoomList[roomId])->hullDamageResistChance)
    {
        dmg.iSystemDamage += dmg.iDamage;
        dmg.iPersDamage += dmg.iDamage;
        dmg.iDamage = 0;
        resist = true;
    }

    bool ret = super(location, dmg, forceHit);

    if (resist && ret)
    {
        auto msg = new DamageMessage(1.f, ship.GetRoomCenter(roomId), DamageMessage::MessageType::RESIST);
        msg->color.a = 1.f;
        damMessages.push_back(msg);
    }
    
    return ret;
}

HOOK_METHOD(ShipManager, DamageBeam, (Pointf location1, Pointf location2, Damage dmg) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::DamageBeam -> Begin (CustomShips.cpp)\n")

    int room1 = ship.GetSelectedRoomId(location1.x, location1.y, true);
    int room2 = ship.GetSelectedRoomId(location2.x, location2.y, true);
    if (dmg.iDamage > 0 && room1 != room2 && (room1 > -1 || room2 > -1))
    {
        auto ex = room2 != -1 ? RM_EX(ship.vRoomList[room2]) : RM_EX(ship.vRoomList[room1]);
        if (random32() % 100 < ex->hullDamageResistChance)
        {
            dmg.iSystemDamage += dmg.iDamage;
            dmg.iPersDamage += dmg.iDamage;
            dmg.iDamage = 0;
            
            if (room1 > -1)
            {
                auto msg1 = new DamageMessage(1.f, ship.GetRoomCenter(room1), DamageMessage::MessageType::RESIST);
                msg1->color.a = 1.f;
                damMessages.push_back(msg1);
            }
            
        }
    }

    super(location1, location2, dmg);
}

HOOK_METHOD(ShipAI, SetStalemate, (bool stalemate) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipAI::SetStalemate -> Begin (CustomShips.cpp)\n")
    auto custom = CustomShipSelect::GetInstance();
    if (custom->GetDefinition(ship->myBlueprint.blueprintName).noFuelStalemate)
    {
        return super(!(target->GetSystem(6)->GetPowerCap() && target->GetSystem(1)->GetPowerCap()) && ship->CountCrew(true) == 0);
    }

    return super(stalemate);
}

HOOK_STATIC(ShipGenerator, CreateShip, (const std::string& name, int sector, ShipEvent& event) -> ShipManager*)
{
    LOG_HOOK("HOOK_STATIC -> ShipGenerator::CreateShip -> Begin (CustomShips.cpp)\n")
    auto ret = super(name, sector, event);

    auto bp = G_->GetBlueprints()->GetShipBlueprint(ret->myBlueprint.blueprintName, sector);

    int totalHealth = bp->health + sector - ((*Global::difficulty == 0) ? 1 : 0);

    auto custom = CustomShipSelect::GetInstance();
    auto def = custom->GetDefinition(bp->blueprintName);

    if (def.hpCap != -1)
    {
        if (totalHealth > def.hpCap)
        {
            totalHealth = def.hpCap;
        }
    }

    if (def.forceAutomated.enabled)
    {
        ret->bAutomated = def.forceAutomated.value;
    }

    ret->ship.hullIntegrity.second = totalHealth;
    ret->ship.hullIntegrity.first = totalHealth;

    return ret;
}

HOOK_METHOD(WorldManager, CreateShip, (ShipEvent* shipEvent, bool boss) -> CompleteShip*)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateShip -> Begin (CustomShips.cpp)\n")

    CompleteShip* ret = super(shipEvent, boss);
    if (ret == nullptr) return ret;

    ShipManager* shipManager = ret->shipManager;

    if (g_enemyPreigniterFix && shipManager->HasAugmentation("WEAPON_PREIGNITE") && shipManager->weaponSystem != nullptr)
    {
        for (ProjectileFactory* weapon : shipManager->weaponSystem->weapons)
        {
            shipManager->weaponSystem->IncreasePower(weapon->requiredPower, false);
        }
        for (ProjectileFactory* weapon : shipManager->weaponSystem->weapons)
        {
            weapon->ForceCoolup();
        }
    }

    if (shipManager->shieldSystem != nullptr && shipManager->shieldSystem->powerState.second > 10)
    {
        for (int i=shipManager->shieldSystem->powerState.second; i>0; i--)
        {
            if (!shipManager->shieldSystem->IncreasePower(1,false)) break;
        }
        shipManager->shieldSystem->InstantCharge();
    }

    return ret;
}

std::vector<std::pair<Animation, int8_t>> extraEngineAnim[2];

HOOK_METHOD(Ship, OnInit, (ShipBlueprint* bp) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnInit -> Begin (CustomShips.cpp)\n")
    super(bp);

    char *xmltext = G_->GetResources()->LoadFile("data/" + bp->layoutFile + ".xml");
    if (xmltext)
    {
        bool hasThrusters = false;
        bool syncThrusters = false;
        int nThrusters = 0;
        int nVanillaThrusters = 0;
        std::vector<std::string> thrusters;
        std::vector<Pointf> thrusterPos;
        std::vector<int8_t> thrusterRot;
        std::vector<bool> thrusterMirror;

        rapidxml::xml_document<> doc;
        doc.parse<0>(xmltext);

        rapidxml::xml_node<char> *node;
        rapidxml::xml_node<char> *ftlnode = doc.first_node("FTL");
        if (ftlnode)
        {
            node = ftlnode->first_node();
        }
        else
        {
            node = doc.first_node();
        }

        for ( ; node; node = node->next_sibling())
        {
            if (strcmp(node->name(), "thrusters") == 0)
            {
                hasThrusters = true;
                if (node->first_attribute("sync"))
                {
                    syncThrusters = EventsParser::ParseBoolean(node->first_attribute("sync")->value());
                }
                for (auto child = node->first_node(); child; child = child->next_sibling())
                {
                    if (strcmp(child->name(), "thruster") == 0)
                    {
                        Pointf pos = {0.f,0.f};
                        int8_t rot = 0;
                        bool mirror = false;
                        if (child->first_attribute("x"))
                        {
                            pos.x = boost::lexical_cast<float>(child->first_attribute("x")->value());
                        }
                        if (child->first_attribute("y"))
                        {
                            pos.y = boost::lexical_cast<float>(child->first_attribute("y")->value());
                        }
                        if (child->first_attribute("rotate"))
                        {
                            if (EventsParser::ParseBoolean(child->first_attribute("rotate")->value())) rot = 1;
                        }
                        if (child->first_attribute("irotate"))
                        {
                            if (EventsParser::ParseBoolean(child->first_attribute("irotate")->value())) rot = -1;
                        }
                        if (child->first_attribute("mirror"))
                        {
                            mirror = EventsParser::ParseBoolean(child->first_attribute("mirror")->value());
                        }

                        thrusters.push_back(child->value());
                        thrusterPos.push_back(pos);
                        thrusterRot.push_back(rot);
                        thrusterMirror.push_back(mirror);

                        nThrusters++;
                        if (!rot && nVanillaThrusters<2) nVanillaThrusters++;
                    }
                }
            }
        }

        doc.clear();

        extraEngineAnim[iShipId].clear();

        if (hasThrusters)
        {
            thrustersImage = nullptr;
            ShipGraph *graph = ShipGraph::GetShipInfo(iShipId);
            extraEngineAnim[iShipId].reserve(nThrusters-nVanillaThrusters);
            nVanillaThrusters = 0;
            int nExtraThrusters = 0;

            for (int i=0; i<nThrusters; ++i)
            {
                if (!thrusterRot[i] && nVanillaThrusters<2)
                {
                    if (!thrusters[i].empty()) engineAnim[nVanillaThrusters] = G_->GetAnimationControl()->GetAnimation(thrusters[i]);
                    engineAnim[nVanillaThrusters].position = {thrusterPos[i].x + shipImage.x + graph->shipBox.x, thrusterPos[i].y + shipImage.y + graph->shipBox.y};
                    engineAnim[nVanillaThrusters].tracker.SetLoop(true, 0.f);
                    if (syncThrusters)
                    {
                        engineAnim[nVanillaThrusters].Start(true);
                    }
                    else
                    {
                        engineAnim[nVanillaThrusters].RandomStart();
                    }
                    engineAnim[nVanillaThrusters].bAlwaysMirror = thrusterMirror[i];
                    nVanillaThrusters++;
                }
                else
                {
                    Pointf pos;
                    if (thrusterRot[i] == 1)
                    {
                        pos = {-(thrusterPos[i].y + shipImage.y + graph->shipBox.y), (thrusterPos[i].x + shipImage.x + graph->shipBox.x)};
                    }
                    else if (thrusterRot[i] == -1)
                    {
                        pos = {(thrusterPos[i].y + shipImage.y + graph->shipBox.y), -(thrusterPos[i].x + shipImage.x + graph->shipBox.x)};
                    }
                    else
                    {
                        pos = {thrusterPos[i].x + shipImage.x + graph->shipBox.x, thrusterPos[i].y + shipImage.y + graph->shipBox.y};
                    }
                    if (thrusters[i].empty())
                    {
                        if (thrusterRot[i] == 1)
                        {
                            pos.x -= 22;
                        }
                        else if (thrusterRot[i] == -1)
                        {
                            pos.y -= 70;
                        }
                        extraEngineAnim[iShipId].emplace_back(std::make_pair(Animation("effects/thrusters_on.png",4,0.5f,pos,88,70,0,-1),thrusterRot[i]));
                    }
                    else
                    {
                        Animation anim = G_->GetAnimationControl()->GetAnimation(thrusters[i]);
                        if (thrusterRot[i] == 1)
                        {
                            pos.x -= anim.info.frameWidth * anim.fScale;
                        }
                        else if (thrusterRot[i] == -1)
                        {
                            pos.y -= anim.info.frameHeight * anim.fScale;
                        }
                        anim.position = pos;
                        extraEngineAnim[iShipId].push_back({anim,thrusterRot[i]});
                    }
                    extraEngineAnim[iShipId][nExtraThrusters].first.tracker.SetLoop(true, 0.f);
                    if (syncThrusters)
                    {
                        extraEngineAnim[iShipId][nExtraThrusters].first.Start(true);
                    }
                    else
                    {
                        extraEngineAnim[iShipId][nExtraThrusters].first.RandomStart();
                    }
                    extraEngineAnim[iShipId][nExtraThrusters].first.bAlwaysMirror = thrusterMirror[i];
                    nExtraThrusters++;
                }
            }

            for (int i=nVanillaThrusters; i<2; ++i)
            {
                engineAnim[i] = G_->GetAnimationControl()->GetAnimation(""); // results in empty anim
            }

            //extraEngineAnim[iShipId].shrink_to_fit();

            if (nThrusters) bShowEngines = true;
        }

        delete [] xmltext;
    }
}

HOOK_METHOD(Ship, OnLoop, (std::vector<float> &oxygenLevels) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnLoop -> Begin (CustomShips.cpp)\n")
    super(oxygenLevels);

    for (std::pair<Animation,int8_t>& anim : extraEngineAnim[iShipId])
    {
        anim.first.Update();
    }
}

void Ship::RenderEngineAnimation(bool showEngines, float alpha)
{
    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShip, 0);
    lua_pushnumber(context->GetLua(), showEngines);
    lua_pushnumber(context->GetLua(), alpha);
    
    int idx = context->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::SHIP_ENGINES, 3);
    if (showEngines && idx >= 0)
    {
        if (engineAnim[0].animationStrip) engineAnim[0].OnRender(alpha, {1.f, 1.f, 1.f, 1.f}, false);
        if (engineAnim[1].animationStrip) engineAnim[1].OnRender(alpha, {1.f, 1.f, 1.f, 1.f}, false);
        for (std::pair<Animation,int8_t>& anim : extraEngineAnim[iShipId])
        {
            if (anim.second)
            {
                if (anim.second == -1)
                {
                    CSurface::GL_PushMatrix();
                    CSurface::GL_Rotate(+90.f, 0.f, 0.f, 1.f);
                    anim.first.OnRender(alpha, {1.f, 1.f, 1.f, 1.f}, false);
                    CSurface::GL_PopMatrix();
                }
                else
                {
                    CSurface::GL_PushMatrix();
                    CSurface::GL_Rotate(-90.f, 0.f, 0.f, 1.f);
                    anim.first.OnRender(alpha, {1.f, 1.f, 1.f, 1.f}, false);
                    CSurface::GL_PopMatrix();
                }
            }
            else
            {
                anim.first.OnRender(alpha, {1.f, 1.f, 1.f, 1.f}, false);
            }
        }
    }
    context->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SHIP_ENGINES, std::abs(idx), 3);

    lua_pop(context->GetLua(), 3);
}

HOOK_METHOD_PRIORITY(Ship, OnRenderBase, 9999, (bool engines) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Ship::OnRenderBase -> Begin (CustomShips.cpp)\n")

    ShipGraph *shipGraph = ShipGraph::GetShipInfo(iShipId);
    float xPos = (float)(shipGraph->shipBox).x;
    float yPos = (float)(shipGraph->shipBox).y;

    // Calculate cloak alpha for each sprite
    float alphaCloak = 0.f;
    float alphaOther = 1.f;
    float alphaHull = 1.f;
    if (cloakingTracker.running)
    {
        alphaCloak = cloakingTracker.Progress(-1.f);
        alphaOther = (1.f - alphaCloak) * 0.5f + 0.5f;
        alphaHull = bCloaked ? alphaOther * 0.75f : (1.f - alphaCloak) * 0.625f + 0.375f;
    }
    else if (bCloaked)
    {
        alphaCloak = 1.f;
        alphaOther = 0.5f;
        alphaHull = 0.375f;
    }
    
    // Lua callback init
    auto context = Global::GetInstance()->getLuaContext();
    
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShip, 0);
    lua_pushnumber(context->GetLua(), alphaCloak);
    
    int idx = context->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::SHIP_HULL, 2);

    if (idx >= 0)
    {
        // Render hull
        CSurface::GL_Translate(xPos, yPos, 0.0);
        CSurface::GL_RenderPrimitiveWithAlpha(shipImagePrimitive, alphaHull);

        // Render cloak
        if (alphaCloak > 0.f)
        {
            if (!shipImageCloak.tex && !cloakImageName.empty())
            {
                ResourceControl *resources = G_->GetResources();
                GL_Texture *image = resources->GetImageId(cloakImageName);
                shipImageCloak.tex = image;
                shipImageCloak.w = image ? image->width_ : 1;
                shipImageCloak.h = image ? image->height_ : 1;
                cloakPrimitive = resources->CreateImagePrimitive(image, shipImageCloak.x, shipImageCloak.y, 0, COLOR_WHITE, 1.f, false);
            }
            CSurface::GL_RenderPrimitiveWithAlpha(cloakPrimitive, alphaCloak);
        }
        CSurface::GL_Translate(-xPos, -yPos, 0.0);

        // Render thruster animations
        RenderEngineAnimation(engines && bShowEngines, alphaOther);
    }

    // Lua callback close
    context->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SHIP_HULL, std::abs(idx), 2);
    lua_pop(context->GetLua(), 2);

    // Render floor
    if (iShipId == 0)
    {
        CSurface::GL_Translate(xPos, yPos, 0.0);
        CSurface::GL_RenderPrimitiveWithAlpha(floorPrimitive, alphaOther);
        CSurface::GL_Translate(-xPos, -yPos, 0.0);
    }
}

HOOK_METHOD_PRIORITY(Ship, OnRenderJump, 9999, (float progress) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Ship::OnRenderJump -> Begin (CustomShips.cpp)\n")

    ShipGraph *shipGraph = ShipGraph::GetShipInfo(iShipId);
    float sparkProgress = progress/0.75;
    float sparkScale = 0.0;
    float sparkX = 0.0;
    float sparkY = 0.0;

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(shipGraph->shipBox.x, shipGraph->shipBox.y, 0.0);

    // Do artillery gib fix for boss while jumping
    ShipManager *shipManager;
    bool doArtyGibFix =
        iShipId == 1 &&
        (shipManager = G_->GetShipManager(iShipId)) &&
        !shipManager->artillerySystems.empty() &&
        !explosion.pieces.empty() &&
        (g_artilleryGibMountFix || CustomShipSelect::GetInstance()->GetDefinition(shipManager->myBlueprint.blueprintName).artilleryGibMountFix) &&
        G_->GetWorld()->commandGui->combatControl.currentTarget == (CompleteShip*)G_->GetWorld()->bossShip &&
        (G_->GetWorld()->bossShip->currentStage == 1 || G_->GetWorld()->bossShip->currentStage == 2);
    if (doArtyGibFix)
    {
        Pointf gibPos = explosion.position[explosion.pieces.size() - 1];
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(shipImage.x - gibPos.x, shipImage.y - gibPos.y, 0.0);
        CSurface::GL_SetColorTint(GL_Color(255.f, 255.f, 255.f, 1.f - progress));
        for (ArtillerySystem *artillery : shipManager->artillerySystems)
        {
            // Only render artillery mounted to the final gib, which should
            // be the one rendered in this function as shipImagePrimitive
            if (artillery && artillery->projectileFactory->mount.gib == explosion.pieces.size())
            {
                artillery->projectileFactory->OnRender(1.f, shipManager->iCustomizeMode == 2);
            }
        }
        CSurface::GL_RemoveColorTint();
        CSurface::GL_PopMatrix();
    }

    // Render hull image
    shipImagePrimitive->textureAntialias = iShipId == 0;
    CSurface::GL_RenderPrimitiveWithAlpha(shipImagePrimitive, 1.0 - progress);
    shipImagePrimitive->textureAntialias = false;

    CSurface::GL_PopMatrix();

    // Calculate values
    if (sparkProgress < 1.0)
    {
        if (0.0 < sparkProgress)
        {
            if (sparkProgress < 0.5)
            {
                sparkScale = sparkProgress*600.0 + sparkProgress*600.0 + 64.0;
                sparkX = sparkScale*0.5;
            }
            else
            {
                sparkX = (sparkProgress - 0.5)*600.0;
                sparkScale = 600.0 - (sparkX + sparkX);
                sparkX = sparkScale*0.5;
            }
        }
    }
    else
    {
        sparkProgress = 1.0;
    }
    if (iShipId == 0)
    {
        sparkY = (float)(shipGraph->shipBox.h/2) - sparkX;
        sparkX = -sparkScale*0.5 + (float)shipGraph->shipBox.w*sparkProgress;
    }
    else
    {
        sparkY = (float)shipGraph->shipBox.h;
        sparkY = (sparkY - sparkX) - sparkY*sparkProgress;
        sparkX = (float)(shipGraph->shipBox.w/2) - sparkX;
    }

    // Render thrusters
    RenderEngineAnimation(bShowEngines, 1.f - sparkProgress);

    // Render jump spark
    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(shipGraph->shipBox.x + sparkX, shipGraph->shipBox.y + sparkY, 0.0);
    CSurface::GL_Scale(sparkScale*0.015625, sparkScale*0.015625, 0.0);
    CSurface::GL_BlitPixelImage(jumpGlare, 0.0, 0.0, 64.0, 64.0, 0.0, COLOR_WHITE, false);
    CSurface::GL_PopMatrix();
}

// save and load rooms

HOOK_METHOD(ShipManager, ExportShip, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ExportShip -> Begin (CustomShips.cpp)\n")
    super(fd);

    for (Room *room : ship.vRoomList)
    {
        Room_Extend *ex = RM_EX(room);

        FileHelper::writeInt(fd, ex->statBoosts.size());
        for (RoomStatBoost &statBoost : ex->statBoosts)
        {
            statBoost.statBoost.Save(fd);
        }

        FileHelper::writeFloat(fd, ex->erosion.timer);
        FileHelper::writeFloat(fd, ex->erosion.speed);
        FileHelper::writeFloat(fd, ex->erosion.systemRepairMultiplier);

        FileHelper::writeInt(fd, ex->erosion.anim != nullptr);
        if (ex->erosion.anim)
        {
            ex->erosion.anim->SaveState(fd);
        }
    }
}

HOOK_METHOD(ShipManager, ImportShip, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ImportShip -> Begin (CustomShips.cpp)\n")
    super(fd);

    int n;

    for (Room *room : ship.vRoomList)
    {
        Room_Extend *ex = RM_EX(room);

        n = FileHelper::readInteger(fd);
        for (int i=0; i<n; ++i)
        {
            ex->statBoosts.emplace_back(StatBoost::LoadStatBoost(fd), room);

            // set room
            if (iShipId == 1)
            {
                ex->statBoosts.back().statBoost.sourceRoomIds.second.push_back(room->iRoomId);
            }
            else
            {
                ex->statBoosts.back().statBoost.sourceRoomIds.first.push_back(room->iRoomId);
            }
        }

        //erosion
        ex->erosion.timer = FileHelper::readFloat(fd);
        ex->erosion.speed = FileHelper::readFloat(fd);
        ex->erosion.systemRepairMultiplier = FileHelper::readFloat(fd);
        if (FileHelper::readInteger(fd))
        {
            ex->erosion.anim = new RoomAnim();
            ex->erosion.anim->LoadState(fd, room);
        }
    }
}

bool g_artilleryGibMountFix = false;
bool g_hideHullDuringExplosion = false;

HOOK_METHOD(ExplosionAnimation, OnRender, (Globals::Rect *shipRect, ImageDesc shipImage, GL_Primitive *shipImagePrimitive) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ExplosionAnimation::OnRender -> Begin (CustomShips.cpp)\n")

    if (!running) return;

    // Setup
    LoadGibs();
    int gib = pieces.size() - 1;
    ShipManager *currentShip = G_->GetShipManager(shipObj.iShipId);
    CustomShipDefinition &shipDef = CustomShipSelect::GetInstance()->GetDefinition(currentShip->myBlueprint.blueprintName);

    // Progress animation
    // Skip the final gib if doing the partial explosion for
    // the final boss so it can reduce opacity as it jumps out
    if (gib > -1 && Progress(-1.f) > 0.75 && bJumpOut) --gib;

    if (gib > -1)
    {
        // Check if artillery weapons should be rendered
        bool doArtyGibFix =
            currentShip &&
            !currentShip->artillerySystems.empty() &&
            (g_artilleryGibMountFix || shipDef.artilleryGibMountFix);

        // Iterate through all gibs
        for (; gib >= 0; --gib)
        {
            float rectW = shipRect->w/2;
            float rectH = shipRect->h/2;
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(position[gib].x, position[gib].y, 0.f);
            CSurface::GL_Translate(rectW, rectH, 0.f);
            CSurface::GL_Rotate(rotation[gib], 0.f, 0.f, 1.f);
            CSurface::GL_Translate(-rectW, -rectH, 0.f);
            CSurface::GL_Translate(shipRect->x + pos.x, shipRect->y + pos.y, 0.f);

            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(-startingPosition[gib].x, -startingPosition[gib].y, 0.f);

            // Render the weapons mounted to the gib
            for (WeaponAnimation* weaponAnim : weaponAnims)
            {
                if (weaponAnim && weaponAnim->mount.gib == gib + 1)
                {
                    weaponAnim->OnRender(1.f);
                }
            }

            // Render the artillery mounted to the gib
            if (doArtyGibFix)
            {
                for (ArtillerySystem *artillery : currentShip->artillerySystems)
                {
                    if (artillery && artillery->projectileFactory->mount.gib == gib + 1)
                    {
                        artillery->projectileFactory->weaponVisual.OnRender(1.f);
                    }
                }
            }

            CSurface::GL_PopMatrix();

            // Render the gib itself
            G_->GetResources()->RenderImage(pieces[gib], 0, 0, 0, COLOR_WHITE, 1.f, false);
            CSurface::GL_PopMatrix();
        }
    }

    // Render the ship hull while the gibs aren't moving
    // For some reason using the shipImagePrimitive arg passed into this function
    // doesn't work, so just get it directly from the Ship struct
    if (!bFinalBoom && currentShip && currentShip->ship.shipImagePrimitive && !(g_hideHullDuringExplosion || shipDef.hideHullDuringExplosion)) {
        CSurface::GL_Translate(shipRect->x, shipRect->y, 0.f);
        CSurface::GL_RenderPrimitive(currentShip->ship.shipImagePrimitive);
        CSurface::GL_Translate(-shipRect->x, -shipRect->y, 0.f);
    }

    // Render the large explosion animations present before the gibs break apart
    if (current_time < 3.f)
    {
        for (Animation explosion : explosions)
        {
            explosion.OnRender(1.f, COLOR_WHITE, false);
        }
    }
}
