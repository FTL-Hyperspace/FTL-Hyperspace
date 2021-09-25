#include "CustomAugments.h"
#include "CustomShips.h"
#include "CustomShipSelect.h"
#include "EnemyShipIcons.h"

#include <boost/lexical_cast.hpp>

static bool importingShip = false;
bool revisitingShip = false;

HOOK_METHOD(WorldManager, CreateShip, (ShipEvent* shipEvent, bool boss) -> CompleteShip*)
{
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
    hasCustomDef = customSel->HasCustomDef(orig->myBlueprint.blueprintName);

    if (hasCustomDef)
    {
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
                auto rex = RM_EX(orig->ship.vRoomList[i.first]);

                for (auto def : i.second->roomAnims)
                {
                    Animation *anim = G_->GetAnimationControl()->GetAnimation(def.animName);
                    RoomAnim roomAnim = RoomAnim();

                    roomAnim.anim = anim;
                    roomAnim.renderLayer = def.renderLayer;

                    anim->Start(true);
                    anim->tracker.SetLoop(true, 0.f);

                    rex->roomAnims.push_back(roomAnim);

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
                    auto bpList = std::vector<std::string>();
                    BlueprintManager::GetBlueprintList(bpList, G_->GetBlueprints(), i.species);

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
}

HOOK_METHOD(ShipManager, ResetScrapLevel, () -> void)
{
    super();
    auto customSel = CustomShipSelect::GetInstance();
    if (customSel->HasCustomDef(myBlueprint.blueprintName))
    {

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

}

HOOK_METHOD(ShipManager, ImportShip, (int fileHelper) -> void)
{
    if (iShipId == 0)
    {
        G_->GetWorld()->playerShip = nullptr; // remove invalid reference
    }

    importingShip = true;
    super(fileHelper);
    importingShip = false;
}

HOOK_METHOD(ShipManager, AddSystem, (int systemId) -> int)
{
    auto ret = super(systemId);

    if (systemId == 0 && shieldSystem)
    {
        shieldSystem->healthState.first = shieldSystem->healthState.second;
    }

    return ret;
}


HOOK_METHOD_PRIORITY(ShipManager, OnInit, 100, (ShipBlueprint *bp, int shipLevel) -> int)
{
    int ret = super(bp, shipLevel);

    SM_EX(this)->Initialize();

    return ret;
}

HOOK_METHOD(ShipManager, Restart, () -> void)
{
    super();

    SM_EX(this)->Initialize(true);
}


HOOK_METHOD(ShipManager, IsCrewFull, () -> bool)
{
    if (iShipId == 1) return false;

    auto custom = CustomShipSelect::GetInstance();
    int crewCount = G_->GetCrewFactory()->GetCrewCount(iShipId);
    int crewLimit = custom->GetDefaultDefinition().crewLimit;

    if (custom->HasCustomDef(myBlueprint.blueprintName))
    {
        crewLimit = custom->GetDefinition(myBlueprint.blueprintName).crewLimit;
    }

    if (crewLimit > crewCount)
    {
        return false;
    }

    return true;
}

HOOK_METHOD(ShipManager, IsCrewOverFull, () -> bool)
{
    if (iShipId == 1) return false;

    auto custom = CustomShipSelect::GetInstance();
    int crewCount = G_->GetCrewFactory()->GetCrewCount(iShipId);
    int crewLimit = custom->GetDefaultDefinition().crewLimit;

    if (custom->HasCustomDef(myBlueprint.blueprintName))
    {
        crewLimit = custom->GetDefinition(myBlueprint.blueprintName).crewLimit;
    }

    return crewLimit < crewCount;
}

HOOK_METHOD(Room, constructor, (int iShipId, int x, int y, int w, int h, int roomId) -> void)
{
    super(iShipId, x, y, w, h, roomId);

    CSurface::GL_DestroyPrimitive(o2LowPrimitive);

    char buf[128];

    sprintf(buf, "effects/low_o2_stripes_%dx%d.png", w, h);

    o2LowPrimitive = G_->GetResources()->CreateImagePrimitiveString(buf, rect.x, rect.y, 0, COLOR_WHITE, 0.5f, false);
}


HOOK_METHOD(ShipManager, CheckVision, () -> void)
{
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

HOOK_METHOD(ShipManager, OnLoop, () -> void)
{
    super();

    for (auto i : ship.vRoomList)
    {
        auto ex = RM_EX(i);

        for (auto anim : ex->roomAnims)
        {
            anim.anim->Update();
        }
    }
}


HOOK_METHOD(ShipManager, OnRender, (bool showInterior, bool doorControlMode) -> void)
{
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
        for (auto i : RM_EX(room)->roomAnims)
        {
            if (i.renderLayer == 4 || (canSeeRooms && i.renderLayer == 3))
            {
                CSurface::GL_PushMatrix();
                CSurface::GL_Translate(room->rect.x, room->rect.y);
                i.anim->OnRender(1.f, COLOR_WHITE, false);
                CSurface::GL_PopMatrix();
            }
        }
    }
}

HOOK_METHOD(Ship, OnRenderSparks, () -> void)
{
    for (auto room : vRoomList)
    {
        for (auto i : RM_EX(room)->roomAnims)
        {
            if (i.renderLayer == 2)
            {
                CSurface::GL_PushMatrix();
                CSurface::GL_Translate(room->rect.x, room->rect.y);
                i.anim->OnRender(1.f, COLOR_WHITE, false);
                CSurface::GL_PopMatrix();
            }
        }
    }

    super();
}

HOOK_METHOD(Ship, OnRenderBreaches, () -> void)
{
    for (auto room : vRoomList)
    {
        if (room->bBlackedOut) continue;

        for (auto i : RM_EX(room)->roomAnims)
        {
            if (i.renderLayer == 1)
            {
                CSurface::GL_PushMatrix();
                CSurface::GL_Translate(room->rect.x, room->rect.y);
                i.anim->OnRender(1.f, COLOR_WHITE, false);
                CSurface::GL_PopMatrix();
            }
        }
    }

    super();
}

HOOK_METHOD(Ship, OnRenderFloor, (bool experimental) -> void)
{
    super(experimental);

    for (auto room : vRoomList)
    {
        if (room->bBlackedOut) continue;

        for (auto i : RM_EX(room)->roomAnims)
        {
            if (i.renderLayer == 0)
            {
                CSurface::GL_PushMatrix();
                CSurface::GL_Translate(room->rect.x, room->rect.y);
                i.anim->OnRender(1.f, COLOR_WHITE, false);
                CSurface::GL_PopMatrix();
            }
        }
    }
}


HOOK_METHOD(Ship, OnInit, (ShipBlueprint& bp) -> void)
{
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
    super();
    auto custom = CustomShipSelect::GetInstance();

    if (shipComplete && shipComplete->shipManager->current_target && custom->HasCustomDef(shipComplete->shipManager->current_target->myBlueprint.blueprintName) && custom->GetDefinition(shipComplete->shipManager->current_target->myBlueprint.blueprintName).noJump)
    {
        ftlButton.bActive = false;
    }
}

HOOK_METHOD(ShipManager, DamageSystem, (int roomId, DamageParameter dmgParam) -> void)
{
    Damage* dmg = (Damage*)&dmgParam;

    auto ex = RM_EX(ship.vRoomList[roomId]);

    if (random32() % 100 < ex->sysDamageResistChance && (dmg->iSystemDamage > -dmg->iDamage))
    {
        dmg->iSystemDamage = -dmg->iDamage;
        auto msg = new DamageMessage(1.f, ship.GetRoomCenter(roomId), DamageMessage::MessageType::RESIST);
        msg->color.a = 1.f;
        damMessages.push_back(msg);
    }
    if (random32() % 100 < ex->ionDamageResistChance && dmg->iIonDamage > 0)
    {
        dmg->iIonDamage = 0;
        auto msg = new DamageMessage(1.f, ship.GetRoomCenter(roomId), DamageMessage::MessageType::RESIST);
        msg->color.r = 40.f / 255.f;
        msg->color.g = 210.f / 255.f;
        msg->color.b = 230.f / 255.f;
        msg->color.a = 1.f;
        damMessages.push_back(msg);
    }

    super(roomId, dmgParam);
}

HOOK_METHOD(ShipAI, SetStalemate, (bool stalemate) -> void)
{
    auto custom = CustomShipSelect::GetInstance();
    if (custom->HasCustomDef(ship->myBlueprint.blueprintName) && custom->GetDefinition(ship->myBlueprint.blueprintName).noFuelStalemate)
    {
        return super(!(target->GetSystem(6)->GetPowerCap() && target->GetSystem(1)->GetPowerCap()) && ship->CountCrew(true) == 0);
    }

    return super(stalemate);
}

HOOK_STATIC(ShipGenerator, CreateShip, (const std::string& name, int sector, ShipEvent& event) -> ShipManager*)
{
    auto ret = super(name, sector, event);

    auto bp = G_->GetBlueprints()->GetShipBlueprint(ret->myBlueprint.blueprintName, sector);

    int totalHealth = bp->health + sector - ((*Global::difficulty == 0) ? 1 : 0);

    auto custom = CustomShipSelect::GetInstance();
    if (custom->HasCustomDef(bp->blueprintName))
    {
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
    }
    else if (totalHealth > 20)
    {
        totalHealth = 20;
    }

    ret->ship.hullIntegrity.second = totalHealth;
    ret->ship.hullIntegrity.first = totalHealth;

    return ret;
}

HOOK_METHOD(WorldManager, CreateShip, (ShipEvent* shipEvent, bool boss) -> CompleteShip*)
{

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

static std::vector<std::pair<Animation,bool>> extraEngineAnim[2];

HOOK_METHOD(Ship, OnInit, (ShipBlueprint& bp) -> void)
{
    super(bp);

    char *xmltext = G_->GetResources()->LoadFile("data/" + bp.imgFile + ".xml");
    if (xmltext)
    {
        bool hasThrusters = false;
        int nThrusters = 0;
        int nVanillaThrusters = 0;
        std::vector<std::string> thrusters;
        std::vector<Pointf> thrusterPos;
        std::vector<bool> thrusterRot;

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
                for (auto child = node->first_node(); child; child = child->next_sibling())
                {
                    if (strcmp(child->name(), "thruster") == 0)
                    {
                        Pointf pos = {0.f,0.f};
                        bool rot = false;
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
                            rot = EventsParser::ParseBoolean(child->first_attribute("rotate")->value());
                        }

                        thrusters.push_back(child->value());
                        thrusterPos.push_back(pos);
                        thrusterRot.push_back(rot);

                        nThrusters++;
                        if (!rot && nVanillaThrusters<2) nVanillaThrusters++;
                    }
                }
            }
        }

        doc.clear();

        if (hasThrusters)
        {
            thrustersImage = nullptr;
            ShipGraph *graph = ShipGraph::GetShipInfo(iShipId);
            extraEngineAnim[iShipId].clear();
            extraEngineAnim[iShipId].reserve(nThrusters-nVanillaThrusters);
            nVanillaThrusters = 0;
            int nExtraThrusters = 0;

            for (int i=0; i<nThrusters; ++i)
            {
                if (!thrusterRot[i] && nVanillaThrusters<2)
                {
                    if (!thrusters[i].empty()) AnimationControl::GetAnimation(engineAnim[nVanillaThrusters], G_->GetAnimationControl(), thrusters[i]);
                    engineAnim[nVanillaThrusters].position = {thrusterPos[i].x + shipImage.x + graph->shipBox.x, thrusterPos[i].y + shipImage.y + graph->shipBox.y};
                    engineAnim[nVanillaThrusters].tracker.SetLoop(true, 0.f);
                    engineAnim[nVanillaThrusters].RandomStart();
                    nVanillaThrusters++;
                }
                else
                {
                    Pointf pos;
                    if (thrusterRot[i])
                    {
                        pos = {-(thrusterPos[i].y + shipImage.y + graph->shipBox.y), (thrusterPos[i].x + shipImage.x + graph->shipBox.x)};
                    }
                    else
                    {
                        pos = {thrusterPos[i].x + shipImage.x + graph->shipBox.x, thrusterPos[i].y + shipImage.y + graph->shipBox.y};
                    }
                    if (thrusters[i].empty())
                    {
                        if (thrusterRot[i]) pos.x -= 22;
                        extraEngineAnim[iShipId].emplace_back(std::make_pair(Animation("effects/thrusters_on.png",4,0.5f,pos,88,70,0,-1),thrusterRot[i]));
                    }
                    else
                    {
                        Animation anim;
                        AnimationControl::GetAnimation(anim, G_->GetAnimationControl(), thrusters[i]);
                        if (thrusterRot[i]) pos.x -= anim.info.frameWidth * anim.fScale;
                        anim.position = pos;
                        extraEngineAnim[iShipId].push_back({anim,thrusterRot[i]});
                    }
                    extraEngineAnim[iShipId][nExtraThrusters].first.tracker.SetLoop(true, 0.f);
                    extraEngineAnim[iShipId][nExtraThrusters].first.RandomStart();
                    nExtraThrusters++;
                }
            }

            for (int i=nVanillaThrusters; i<2; ++i)
            {
                AnimationControl::GetAnimation(engineAnim[i], G_->GetAnimationControl(), ""); // results in empty anim
            }

            //extraEngineAnim[iShipId].shrink_to_fit();

            if (nThrusters) bShowEngines = true;
        }
    }
}

HOOK_METHOD(Ship, OnLoop, (std::vector<float> &oxygenLevels) -> void)
{
    super(oxygenLevels);

    for (std::pair<Animation,bool>& anim : extraEngineAnim[iShipId])
    {
        anim.first.Update();
    }
}

HOOK_METHOD(Ship, OnRenderBase, (bool engines) -> void)
{
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
        for (std::pair<Animation,bool>& anim : extraEngineAnim[iShipId])
        {
            if (anim.second)
            {
                CSurface::GL_PushMatrix();
                CSurface::GL_Rotate(-90.f, 0.f, 0.f, 1.f);
                anim.first.OnRender(alpha, {1.f, 1.f, 1.f, 1.f}, false);
                CSurface::GL_PopMatrix();
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
    bool customEngines = bShowEngines && thrustersImage == nullptr;
    if (customEngines) bShowEngines = false;
    super(progress);
    if (customEngines) bShowEngines = true;

    if (customEngines)
    {
        float alpha = 1.f - std::min(progress * 0.75f, 1.f);

        if (engineAnim[0].animationStrip) engineAnim[0].OnRender(alpha, {1.f, 1.f, 1.f, 1.f}, false);
        if (engineAnim[1].animationStrip) engineAnim[1].OnRender(alpha, {1.f, 1.f, 1.f, 1.f}, false);
        for (std::pair<Animation,bool>& anim : extraEngineAnim[iShipId])
        {
            if (anim.second)
            {
                CSurface::GL_PushMatrix();
                CSurface::GL_Rotate(-90.f, 0.f, 0.f, 1.f);
                anim.first.OnRender(alpha, {1.f, 1.f, 1.f, 1.f}, false);
                CSurface::GL_PopMatrix();
            }
            else
            {
                anim.first.OnRender(alpha, {1.f, 1.f, 1.f, 1.f}, false);
            }
        }
    }
}
