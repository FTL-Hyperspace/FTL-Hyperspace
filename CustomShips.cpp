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
    auto customSel = CustomShipSelect::GetInstance();

    isNewShip = customSel->IsCustomShip(orig->myBlueprint.blueprintName);

    auto def = customSel->GetDefinition(orig->myBlueprint.blueprintName);
    if (!importingShip)
    {
        for (auto i : def.hiddenAugs)
        {
            G_->GetShipInfo(orig->iShipId)->augList["HIDDEN " + i.first] = i.second;
        }
        CustomAugmentManager::GetInstance()->UpdateAugments(orig->iShipId);
    }

    for (auto i : def.roomDefs)
    {
        if (i.first < orig->ship.vRoomList.size())
        {
            Room *room = orig->ship.vRoomList[i.first];
            auto rex = RM_EX(room);

            for (auto &def : i.second->roomAnims)
            {
                rex->roomAnims.emplace_back(def, room);
            }

            rex->sensorBlind = i.second->sensorBlind;
            rex->sysDamageResistChance = i.second->sysDamageResistChance;
            rex->ionDamageResistChance = i.second->ionDamageResistChance;
        }
    }

    for (auto i : def.shipIcons)
    {
        auto iconDef = ShipIconManager::instance->GetShipIconDefinition(i);
        if (iconDef)
        {
            ShipIcon* icon = new ShipIcon();

            icon->OnInit(iconDef->name, iconDef->tooltip, icons.size());
            icons.push_back(icon);
        }
    }

    if (!restarting && !revisitingShip)
    {
        for (auto i : def.crewList)
        {
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

HOOK_METHOD(ShipManager, Restart, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::Restart -> Begin (CustomShips.cpp)\n")
    super();

    SM_EX(this)->Initialize(true);
}


HOOK_METHOD(ShipManager, IsCrewFull, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::IsCrewFull -> Begin (CustomShips.cpp)\n")
    if (iShipId == 1) return false;

    auto custom = CustomShipSelect::GetInstance();
    int crewCount = G_->GetCrewFactory()->GetCrewCount(iShipId);
    int crewLimit = custom->GetDefinition(myBlueprint.blueprintName).crewLimit;

    if (crewLimit > crewCount)
    {
        return false;
    }

    return true;
}

HOOK_METHOD(ShipManager, IsCrewOverFull, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::IsCrewOverFull -> Begin (CustomShips.cpp)\n")
    if (iShipId == 1) return false;

    auto custom = CustomShipSelect::GetInstance();
    int crewCount = G_->GetCrewFactory()->GetCrewCount(iShipId);
    int crewLimit = custom->GetDefinition(myBlueprint.blueprintName).crewLimit;

    if (crewLimit >= crewCount) return false;

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
        anim->SaveState(fd);
    }

    FileHelper::writeInt(fd, tileAnims.size());
    for (Animation &tileAnim : tileAnims)
    {
        tileAnim.SaveState(fd);
    }

    FileHelper::writeInt(fd, wallAnim.get() != nullptr);
    if (wallAnim)
    {
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
        anim.reset(new Animation);
        anim->LoadState(fd);
    }

    int n = FileHelper::readInteger(fd);
    for (int i=0; i<n; ++i)
    {
        tileAnims.emplace_back();
        Animation &tileAnim = tileAnims.back();
        tileAnim.LoadState(fd);
    }

    if (FileHelper::readInteger(fd))
    {
        wallAnim.reset(new Animation);
        wallAnim->LoadState(fd);
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

static std::vector<std::pair<Animation,int8_t>> extraEngineAnim[2];

HOOK_METHOD(Ship, OnInit, (ShipBlueprint* bp) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnInit -> Begin (CustomShips.cpp)\n")
    super(bp);

    char *xmltext = G_->GetResources()->LoadFile("data/" + bp->imgFile + ".xml");
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

HOOK_METHOD(Ship, OnRenderBase, (bool engines) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnRenderBase -> Begin (CustomShips.cpp)\n")
    super(false);

    if (engines && bShowEngines)
    {
        float alpha = 1.f;
        if (bCloaked)
        {
            alpha = 0.5f;
            if (cloakingTracker.running)
            {
                alpha = 1.f - 0.5f * cloakingTracker.Progress(-1.f);
            }
        }
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
}

HOOK_METHOD(Ship, OnRenderJump, (float progress) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnRenderJump -> Begin (CustomShips.cpp)\n")
    bool customEngines = bShowEngines && thrustersImage == nullptr;
    if (customEngines) bShowEngines = false;
    super(progress);
    if (customEngines) bShowEngines = true;

    if (customEngines)
    {
        float alpha = 1.f - std::min(progress / 0.75f, 1.f);

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
