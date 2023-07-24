#include "CustomBoss.h"
#include "CustomWeapons.h"
#include <boost/lexical_cast.hpp>
#include <math.h>

CustomBoss* CustomBoss::instance = new CustomBoss();

std::string droneSurgeOverride = "";
std::string barrageOverride = "";

void CustomBoss::ParseBossNode(rapidxml::xml_node<char> *node)
{
    for (int i = 0; i < 3; i++)
    {
        droneSurgeDef[i] = std::vector<DroneCount>();
    }

    try
    {
        for (auto bossNode = node->first_node(); bossNode; bossNode = bossNode->next_sibling())
        {
            std::string nodeName = bossNode->name();

            if (nodeName == "crew")
            {
                for (auto crewNode = bossNode->first_node(); crewNode; crewNode = crewNode->next_sibling())
                {
                    int roomId = 0;

                    if (crewNode->first_attribute("room"))
                    {
                        roomId = boost::lexical_cast<int>(crewNode->first_attribute("room")->value());
                    }

                    auto crewDef = std::pair<std::string, int>(crewNode->name(), roomId);

                    initialCrewList.push_back(crewDef);
                }
            }

            if (nodeName == "surgeDrones")
            {
                if (bossNode->first_attribute("name"))
                {
                    auto def = new std::array<std::vector<DroneCount>,3>();
                    ParseBossDroneNode(bossNode, def);
                    droneSurgeDefs[bossNode->first_attribute("name")->value()] = def;
                }
                else
                {
                    customSurgeDrones = true;

                    ParseBossDroneNode(bossNode, &droneSurgeDef);
                }
            }

            if (nodeName == "surgeBarrage")
            {
                if (bossNode->first_attribute("name"))
                {
                    auto def = new std::array<std::vector<BarrageCount>,3>();
                    ParseBossBarrageNode(bossNode, def);
                    barrageDefs[bossNode->first_attribute("name")->value()] = def;
                }
                else
                {
                    customBarrage = true;

                    ParseBossBarrageNode(bossNode, &barrageDef);
                }
            }
        }
    }
    catch (rapidxml::parse_error& e)
    {
        ErrorMessage(std::string("Error parsing <boss> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (std::exception &e)
    {
        ErrorMessage(std::string("Error parsing <boss> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (const char* e)
    {
        ErrorMessage(std::string("Error parsing <boss> in hyperspace.xml\n") + std::string(e));
    }
    catch (...)
    {
        ErrorMessage("Error parsing <boss> in hyperspace.xml\n");
    }
}

void CustomBoss::ParseBossDroneNode(rapidxml::xml_node<char> *node, std::array<std::vector<DroneCount>,3> *def)
{
    for (auto droneNode = node->first_node(); droneNode; droneNode = droneNode->next_sibling())
    {
        if (droneNode->first_attribute("difficulty"))
        {
            int difficulty = boost::lexical_cast<int>(droneNode->first_attribute("difficulty")->value());

            if (difficulty > 2) continue;

            DroneCount droneCount = DroneCount();

            droneCount.drone = droneNode->first_attribute("name")->value();
            droneCount.number = boost::lexical_cast<int>(droneNode->first_attribute("count")->value());

            (*def)[difficulty].push_back(droneCount);
        }
        else
        {
            for (int difficulty=0; difficulty<3; ++difficulty)
            {
                DroneCount droneCount = DroneCount();

                droneCount.drone = droneNode->first_attribute("name")->value();
                droneCount.number = boost::lexical_cast<int>(droneNode->first_attribute("count")->value());

                (*def)[difficulty].push_back(droneCount);
            }
        }
    }
}

void CustomBoss::ParseBossBarrageNode(rapidxml::xml_node<char> *node, std::array<std::vector<BarrageCount>,3> *def)
{
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        if (child->first_attribute("difficulty"))
        {
            int difficulty = boost::lexical_cast<int>(child->first_attribute("difficulty")->value());

            if (difficulty > 2) continue;

            BarrageCount barrageCount = BarrageCount();

            barrageCount.weapon = child->first_attribute("name")->value();
            barrageCount.number = boost::lexical_cast<int>(child->first_attribute("count")->value());

            (*def)[difficulty].push_back(barrageCount);
        }
        else
        {
            for (int difficulty=0; difficulty<3; ++difficulty)
            {
                BarrageCount barrageCount = BarrageCount();

                barrageCount.weapon = child->first_attribute("name")->value();
                barrageCount.number = boost::lexical_cast<int>(child->first_attribute("count")->value());

                (*def)[difficulty].push_back(barrageCount);
            }
        }
    }
}

static bool isStartingStage = false;
static bool spawnBossCrew = false;
static BossShip* bossShipStartingStage;

HOOK_METHOD(BossShip, StartStage, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> BossShip::StartStage -> Begin (CustomBoss.cpp)\n")
    isStartingStage = true;
    spawnBossCrew = true;
    bossShipStartingStage = this;

    super();

    isStartingStage = false;

    /*
    if (currentStage == 1)
    {
        for (int i = 0; i < CustomBoss::instance->initialCrewList.size(); i++)
        {
            shipManager->AddCrewMemberFromString("", CustomBoss::instance->initialCrewList[i].first, false, CustomBoss::instance->initialCrewList[i].second, false, random32() % 2);
        }
    }
    else
    {
        int roomCount = ShipGraph::GetShipInfo(iShipId)->RoomCount();
        for (auto i : CustomBoss::instance->currentCrewCounts)
        {
            if (i.second < roomCount)
            {
                shipManager->AddCrewMemberFromString("", i.first, false, i.second, false, random32() % 2);
            }
        }
    }
    */
}

HOOK_METHOD(BossShip, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> BossShip::OnLoop -> Begin (CustomBoss.cpp)\n")
    super();


    if (!shipManager->bJumping && !shipManager->bDestroyed)
    {
        CustomBoss::instance->currentCrewCounts.clear();

        for (auto i : shipManager->vCrewList)
        {
            if (!i->bDead && !i->IsDrone() && iShipId == i->iShipId)
            {
                auto crewDef = std::pair<std::string, int>(i->species, i->iRoomId);
                CustomBoss::instance->currentCrewCounts.push_back(crewDef);
            }
        }
    }

}

HOOK_METHOD_PRIORITY(ShipManager, AddCrewMemberFromString, -100, (const std::string& name, const std::string& race, bool intruder, int roomId, bool init, bool male) -> CrewMember*)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::AddCrewMemberFromString -> Begin (CustomBoss.cpp)\n")
    if (isStartingStage)
    {
        if (spawnBossCrew)
        {
            spawnBossCrew = false;
            if (bossShipStartingStage->currentStage == 1)
            {
                for (int i = 0; i < CustomBoss::instance->initialCrewList.size(); i++)
                {
                    super("", CustomBoss::instance->initialCrewList[i].first, false, CustomBoss::instance->initialCrewList[i].second, false, random32() % 2);
                }
            }
            else
            {
                int roomCount = ShipGraph::GetShipInfo(bossShipStartingStage->iShipId)->RoomCount();
                for (auto i : CustomBoss::instance->currentCrewCounts)
                {
                    if (i.second < roomCount)
                    {
                        super("", i.first, false, i.second, false, random32() % 2);
                    }
                }
            }
        }
        return nullptr;
    }
    return super(name, race, intruder, roomId, init, male);
}

HOOK_METHOD(BossShip, SaveBoss, (int fh) -> void)
{
    LOG_HOOK("HOOK_METHOD -> BossShip::SaveBoss -> Begin (CustomBoss.cpp)\n")
    FileHelper::writeInt(fh, CustomBoss::instance->currentCrewCounts.size());
    for (auto i : CustomBoss::instance->currentCrewCounts)
    {
        FileHelper::writeString(fh, i.first);
        FileHelper::writeInt(fh, i.second);
    }

    super(fh);
}

HOOK_METHOD(BossShip, LoadBoss, (int fh) -> void)
{
    LOG_HOOK("HOOK_METHOD -> BossShip::LoadBoss -> Begin (CustomBoss.cpp)\n")
    int crewCountsSize = FileHelper::readInteger(fh);

    for (int i = 0; i < crewCountsSize; i++)
    {
        auto crewDef = std::pair<std::string, int>();
        crewDef.first = FileHelper::readString(fh);
        crewDef.second = FileHelper::readInteger(fh);
    }

    super(fh);
}


HOOK_METHOD(ShipManager, PrepareSuperDrones, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::PrepareSuperDrones -> Begin (CustomBoss.cpp)\n")
    std::array<std::vector<DroneCount>,3> *def = nullptr;
    if (CustomBoss::instance->customSurgeDrones) def = &(CustomBoss::instance->droneSurgeDef);
    if (!droneSurgeOverride.empty())
    {
        auto it = CustomBoss::instance->droneSurgeDefs.find(droneSurgeOverride);
        if (it != CustomBoss::instance->droneSurgeDefs.end())
        {
            def = it->second;
        }
        droneSurgeOverride = "";
    }
    if (def == nullptr) return super();

    std::vector<DroneCount> droneCount = (*def)[*G_->difficulty];

    for (auto i : droneCount)
    {
        auto bp = G_->GetBlueprints()->GetDroneBlueprint(i.drone);
        for (int j = 0; j < i.number; j++)
        {
            auto drone = new CombatDrone(iShipId, Globals::GetNextSpaceId(), bp);
            superDrones.push_back(drone);

            drone->powerRequired = 0;
            drone->lifespan = 2;
            drone->SetMovementTarget(&current_target->_targetable);
            drone->SetWeaponTarget(&current_target->_targetable);
            drone->powered = true;
            drone->SetDeployed(true);
            drone->bDead = false;


            droneTrash.push_back(drone);
            newDroneArrivals.push_back(drone);
        }
    }
}

HOOK_METHOD(ShipManager, PrepareSuperBarrage, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::PrepareSuperBarrage -> Begin (CustomBoss.cpp)\n")
    std::array<std::vector<BarrageCount>,3> *def = nullptr;
    if (CustomBoss::instance->customBarrage) def = &(CustomBoss::instance->barrageDef);
    if (!barrageOverride.empty())
    {
        auto it = CustomBoss::instance->barrageDefs.find(barrageOverride);
        if (it != CustomBoss::instance->barrageDefs.end())
        {
            def = it->second;
        }
        barrageOverride = "";
    }
    if (def == nullptr) return super();

    ShipGraph* graph = ShipGraph::GetShipInfo(iShipId);
    Pointf pos = {(float)graph->center.x, (float)graph->center.y};

    if (current_target == nullptr) return;
    int targetId = current_target->iShipId;

    SoundControl* soundControl = G_->GetSoundControl();

    std::vector<BarrageCount> barrageCount = (*def)[*G_->difficulty];

    std::vector<Pointf> bombTargets = std::vector<Pointf>();
    unsigned int bombTargetIdx = 0;

    for (auto i : barrageCount)
    {
        WeaponBlueprint *bp = G_->GetBlueprints()->GetWeaponBlueprint(i.weapon);
        if (bp == nullptr) continue;

        for (int j = 0; j < i.number; j++)
        {
            switch (bp->type)
            {
            case 0:
                {
                    Pointf targetPos = current_target->GetRandomRoomCenter();
                    float heading = random32()%360;

                    LaserBlast *projectile = new LaserBlast(pos,iShipId,targetId,targetPos);
                    projectile->heading = heading;
                    projectile->OnInit();
                    projectile->Initialize(*bp);

                    superBarrage.push_back(projectile);
                }
                break;
            case 1:
                {
                    Pointf targetPos = current_target->GetRandomRoomCenter();
                    float heading = random32()%360;

                    Missile *projectile = new Missile(pos,iShipId,targetId,targetPos,heading);
                    projectile->Initialize(*bp);

                    superBarrage.push_back(projectile);
                }
                break;
            case 2:
                {
                    Pointf targetPos = current_target->GetRandomRoomCenter();
                    Pointf finalPos;

                    if (bp->length > 1) // real beam
                    {
                        do
                        {
                            finalPos = current_target->GetRandomRoomCenter();
                        }
                        while (finalPos.x == targetPos.x && finalPos.y == targetPos.y);
                    }
                    else // pinpoint beam
                    {
                        int roomNumber = G_->GetShipManager(targetId)->ship.GetSelectedRoomId(targetPos.x, targetPos.y, true);
                        if (roomNumber != -1)
                        {
                            ShipGraph *shipInfo = ShipGraph::GetShipInfo(targetId);
                            int numSlots = shipInfo->GetNumSlots(roomNumber);
                            int randomSlot = random32() % numSlots;
                            Point gridPos = shipInfo->GetSlotWorldPosition(randomSlot, roomNumber);
                            Point grid = ShipGraph::TranslateToGrid(gridPos.x, gridPos.y);

                            targetPos.x = (grid.x * 35.f + 17.0f);
                            targetPos.y = (grid.y * 35.f + 17.5f);
                            finalPos.x=targetPos.x+1.0f;
                            finalPos.y=targetPos.y;
                        }
                        else // fallback
                        {
                            do
                            {
                                finalPos = current_target->GetRandomRoomCenter();
                            }
                            while (finalPos.x == targetPos.x && finalPos.y == targetPos.y);
                        }
                    }
                    float heading = random32()%360;

                    BeamWeapon *projectile = new BeamWeapon(pos,iShipId,targetId,targetPos,finalPos,bp->length,&current_target->_targetable);
                    projectile->heading = heading;
                    projectile->entryAngle = random32()%360;

                    float theta = heading * 0.01745329f;
                    projectile->sub_end.x = pos.x + 2000.f*cos(theta);
                    projectile->sub_end.y = pos.y + 2000.f*sin(theta);

                    projectile->Initialize(*bp);

                    superBarrage.push_back(projectile);
                }
                break;
            case 3:
                {
                    if (bombTargetIdx >= bombTargets.size())
                    {
                        bombTargets.clear();
                        int numRooms = ShipGraph::GetShipInfo(targetId)->RoomCount();
                        bombTargets.reserve(numRooms);
                        for (int k=0; k<numRooms; ++k) bombTargets.push_back(current_target->GetRoomCenter(k));

                        std::random_shuffle(bombTargets.begin(), bombTargets.end(), [](int i){return random32()%i;});
                        bombTargetIdx = 0;
                    }

                    BombProjectile *projectile = new BombProjectile(pos,iShipId,targetId,bombTargets[bombTargetIdx++]);
                    projectile->superShieldBypass = HasEquipment("ZOLTAN_BYPASS");
                    projectile->Initialize(*bp);
                    projectile->flight_animation.tracker.loop = false;

                    superBarrage.push_back(projectile);
                }
                break;
            case 4:
                {
                    Pointf targetPos = current_target->GetRandomRoomCenter();
                    float heading = random32()%360;
                    float entryAngle = random32()%360;

                    for (auto &k : bp->miniProjectiles)
                    {
                        float r = sqrt(random32()/2147483648.f) * bp->radius;
                        float theta = random32()%360 * 0.01745329f;
                        Pointf ppos = {static_cast<float>(targetPos.x + r*cos(theta)), static_cast<float>(targetPos.y + r*sin(theta))};
                        LaserBlast *projectile = new LaserBlast(pos,iShipId,targetId,ppos);
                        projectile->heading = heading;
                        projectile->OnInit();
                        projectile->entryAngle = entryAngle;
                        projectile->Initialize(*bp);

                        projectile->flight_animation = G_->GetAnimationControl()->GetAnimation(k.image);

                        if (k.fake)
                        {
                            projectile->damage.iDamage = 0;
                            projectile->damage.iShieldPiercing = 0;
                            projectile->damage.fireChance = 0;
                            projectile->damage.breachChance = 0;
                            projectile->damage.stunChance = 0;
                            projectile->damage.iIonDamage = 0;
                            projectile->damage.iSystemDamage = 0;
                            projectile->damage.iPersDamage = 0;
                            projectile->damage.bHullBuster = false;
                            projectile->damage.ownerId = -1;
                            projectile->damage.selfId = -1;
                            projectile->damage.bLockdown = false;
                            projectile->damage.crystalShard = false;
                            projectile->damage.bFriendlyFire = true;
                            projectile->damage.iStun = 0;
                            projectile->death_animation.fScale = 0.25;
                        }
                        else
                        {
                            projectile->bBroadcastTarget = iShipId == 0;
                        }

                        CustomWeaponManager::ProcessMiniProjectile(projectile, bp);

                        superBarrage.push_back(projectile);
                    }

                }
                break;
            }
            if (!bp->effects.launchSounds.empty())
            {
                soundControl->PlaySoundMix(bp->effects.launchSounds[random32()%bp->effects.launchSounds.size()], -1.f, false);
            }
        }
    }
}

HOOK_METHOD(BossShip, GetEvent, () -> LocationEvent*)
{
    LOG_HOOK("HOOK_METHOD -> BossShip::GetEvent -> Begin (CustomBoss.cpp)\n")
    LocationEvent *ret = super();

    ret->statusEffects.clear();

    return ret;
}

static bool blockSystemBoxRender = false;


HOOK_METHOD(SystemBox, OnRender, (bool ignoreStatus) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SystemBox::OnRender -> Begin (CustomBoss.cpp)\n")
    if (blockSystemBoxRender)
    {
        return;
    }

    super(ignoreStatus);
}


HOOK_METHOD(CombatControl, RenderTarget, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::RenderTarget -> Begin (CustomBoss.cpp)\n")
    if (currentTarget->IsBoss())
    {
        blockSystemBoxRender = true;
    }

    super();

    blockSystemBoxRender = false;

    if (currentTarget->IsBoss())
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(position.x, position.y);
        CSurface::GL_PushMatrix();
        //CSurface::GL_Translate(targetPosition.x, targetPosition.y);

        if (shipManager->DoSensorsProvide(3))
        {
            for (auto i : sysBoxes)
            {
                i->bShowPower = true;
            }
        }
        else
        {
            for (auto i : sysBoxes)
            {
                i->bShowPower = false;
            }
        }

        for (auto i : sysBoxes)
        {
            i->OnRender(true);
        }

        CSurface::GL_PopMatrix();
        CSurface::GL_PopMatrix();
    }
}
