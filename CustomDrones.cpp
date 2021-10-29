#include "CustomDrones.h"
#include "CustomCrew.h"
#include "CustomWeapons.h"
#include <boost/lexical_cast.hpp>

CustomDroneManager CustomDroneManager::_instance = CustomDroneManager();

void CustomDroneManager::ParseDroneNode(rapidxml::xml_node<char> *node)
{
    try
    {
        for (auto droneNode = node->first_node(); droneNode; droneNode = droneNode->next_sibling())
        {
            if (strcmp(droneNode->name(), "drone") == 0)
            {
                CustomDroneDefinition* def = new CustomDroneDefinition();

                def->name = droneNode->first_attribute("name")->value();

                for (auto child = droneNode->first_node(); child; child = child->next_sibling())
                {
                    std::string name = child->name();
                    std::string val = child->value();

                    if (name == "crewBlueprint")
                    {
                        def->crewBlueprint = val;
                    }
                    if (name == "tooltipName")
                    {
                        def->tooltipName = val;
                    }
                    if (name == "ability")
                    {
                        def->hasAbility = true;

                        DroneAbilityDefinition::AIType ai;
                        if (child->first_attribute("ai"))
                        {
                            std::string aiString = child->first_attribute("ai")->value();

                            if (aiString == "systems")
                            {
                                ai = DroneAbilityDefinition::AIType::SYSTEMS;
                            }
                            if (aiString == "systems_power")
                            {
                                ai = DroneAbilityDefinition::AIType::SYSTEMS_POWER;
                            }
                            if (aiString == "heal")
                            {
                                ai = DroneAbilityDefinition::AIType::CREW_HEAL;
                            }
                            if (aiString == "enemies")
                            {
                                ai = DroneAbilityDefinition::AIType::ENEMIES;
                            }
                        }

                        def->ability.ai = ai;
                    }
                }

                droneDefs.push_back(def);
            }
        }
    }
    catch (std::exception)
    {
        MessageBoxA(GetDesktopWindow(), "Error parsing <drones> in hyperspace.xml", "Error", MB_ICONERROR | MB_SETFOREGROUND);
    }
}



//====================================================

HOOK_METHOD(CrewMemberFactory, CreateBoarderDrone, (int shipId, DroneBlueprint *bp) -> BoarderDrone*)
{
    CustomDroneDefinition *customDrone = CustomDroneManager::GetInstance()->GetDefinition(bp->name);

    if (customDrone)
    {
        if (customDrone->hasAbility)
        {
            AbilityDrone* drone = new AbilityDrone(customDrone->crewBlueprint, customDrone->tooltipName, shipId, bp, customDrone->ability);

            crewMembers.push_back(drone);

            return (BoarderDrone*)drone;
        }
    }

    return super(shipId, bp);
}

HOOK_METHOD(DroneBlueprint, RenderIcon, (float scale) -> void)
{
    CustomDroneDefinition *customDrone = CustomDroneManager::GetInstance()->GetDefinition(name);
    if ((type == 2 || type == 3 || type == 4) && customDrone)
    {
        CSurface::GL_PushMatrix();
        auto walkDown = G_->GetAnimationControl()->GetAnimation(customDrone->crewBlueprint + "_walk_down");
        auto base = G_->GetResources()->GetImageId("people/" + customDrone->crewBlueprint + "_base.png");
        auto layer = G_->GetResources()->GetImageId("people/" + customDrone->crewBlueprint + "_layer1.png");

        CSurface::GL_Translate(std::floor(std::floor((-scale * walkDown->info.frameWidth)) / 2.f) + 1, std::floor(std::floor((-scale * walkDown->info.frameHeight)) / 2.f) + 1);

        walkDown->SetCurrentFrame(0);
        walkDown->SetAnimationId(base);
        walkDown->OnRender(1.f, COLOR_WHITE, false);
        walkDown->SetAnimationId(layer);
        walkDown->OnRender(1.f, GL_Color(128.f / 255.f, 255.f / 255.f, 141.f / 255.f, 1.f), false);

        delete walkDown;

        CSurface::GL_PopMatrix();
        return;
    }

    super(scale);
}

HOOK_METHOD(CrewAnimation, OnInit, (const std::string& name, Pointf position, bool enemy) -> void)
{
    super(name, position, enemy);

    CustomDroneDefinition *customDrone = CustomDroneManager::GetInstance()->GetDefinitionByRace(race);
    if (customDrone)
    {
        bDrone = true;
    }
}

HOOK_METHOD(CrewDrone, constructor, (const std::string& droneType, const std::string& name, int shipId, const DroneBlueprint* blueprint, CrewAnimation *anim) -> void)
{
    CustomDroneDefinition *customDrone = CustomDroneManager::GetInstance()->GetDefinition(blueprint->name);

    if (customDrone)
    {
        super(customDrone->crewBlueprint, customDrone->tooltipName.empty() ? name : customDrone->tooltipName, shipId, blueprint, nullptr);

        if (!customDrone->tooltipName.empty())
        {
            TextString textName = TextString();

            textName.data = customDrone->tooltipName;
            textName.isLiteral = true;

            SetName(textName, true);
        }
    }
    else
    {
        super(droneType, name, shipId, blueprint, anim);
    }
}

static bool blockControllableAI;

HOOK_METHOD(ShipManager, CommandCrewMoveRoom, (CrewMember* crew, int room) -> bool)
{
    if (blockControllableAI)
    {
        auto custom = CustomCrewManager::GetInstance();
        if (crew->GetControllable() || (!crew->intruder && custom->IsRace(crew->species) && custom->GetDefinition(crew->species)->droneAI.hasCustomAI)) return false;
    }

    return super(crew, room);
}

HOOK_METHOD(CrewMember, SetTask, (CrewTask task) -> void)
{
    if (blockControllableAI)
    {
        auto custom = CustomCrewManager::GetInstance();
        if (GetControllable() || (!intruder && custom->IsRace(species) && custom->GetDefinition(species)->droneAI.hasCustomAI)) return;
    }

    super(task);
}

HOOK_METHOD(CrewAI, UpdateDrones, () -> void)
{
    blockControllableAI = true;
    super();
    blockControllableAI = false;

    bool hasDrone = false;

    for (auto i : crewList)
    {
        if (i->IsDrone() && !i->intruder)
        {
            hasDrone = true;
            break;
        }
    }

    if (!hasDrone) return;

    CustomCrewManager *custom = CustomCrewManager::GetInstance();

    for (auto crew : crewList)
    {
        if (crew->IsDrone() && !crew->intruder && custom->IsRace(crew->species))
        {
            auto def = custom->GetDefinition(crew->species);
            if (def->droneAI.hasCustomAI && !crew->GetControllable() && !crew->IsDead() && crew->Functional() && crew->crewAnim->status != 3)
            {
                std::vector<CrewTask> taskList(desiredTaskList);
                taskList.insert(taskList.end(), bonusTaskList.begin(), bonusTaskList.end());

                if (taskList.empty())
                {
                    AssignCrewmembers();
                    return;
                }

                if (crew->CanFight())
                {
                    if (def->droneAI.fightAI)
                    {
                        CrewTask closestTask;
                        float closestDist = FLT_MAX;
                        int newTaskId = 4;

                        for (auto task : taskList)
                        {
                            if (task.taskId == 7)
                            {
                                if (!ship->ship.FullRoom(task.room, false))
                                {
                                    float dist = ship->GetRoomCenter(task.room).RelativeDistance(Pointf(crew->x, crew->y));

                                    if (dist < closestDist)
                                    {
                                        closestDist = dist;
                                        closestTask = task;
                                        newTaskId = task.taskId;
                                    }
                                }
                            }
                        }

                        if (newTaskId != 4)
                        {
                            if (!ship->ship.RoomLocked(closestTask.room))
                            {
                                if (ship->CommandCrewMoveRoom(crew, closestTask.room))
                                {
                                    crew->SetTask(closestTask);
                                }
                            }
                        }
                    }
                }
                if (!crew->IsBusy() && crew->CanRepair())
                {
                    if (def->droneAI.repairAI)
                    {
                        crew->ClearTask();

                        for (auto task : taskList)
                        {
                            if (task.taskId <= 3 && task.taskId > 0)
                            {
                                if (PrioritizeTask(task, -1) < PrioritizeTask(crew->task, -1))
                                {
                                    if (!ship->ship.RoomLocked(task.room) && (ship->CommandCrewMoveRoom(crew, task.room) || task.room == crew->currentSlot.roomId))
                                    {
                                        crew->SetTask(task);
                                    }
                                }
                            }
                        }
                    }
                }

                if (!crew->IsBusy() && crew->CanMan())
                {
                    if (def->droneAI.manAI)
                    {
                        for (auto task : taskList)
                        {
                            if (task.taskId == 0 && task.system != 5 && task.system != 2 && task.system != 6)
                            {
                                if (PrioritizeTask(task, -1) < PrioritizeTask(crew->task, -1))
                                {
                                    if (!ship->ship.RoomLocked(task.room) && (ship->CommandCrewMoveRoom(crew, task.room) || task.room == crew->currentSlot.roomId))
                                    {
                                        crew->SetTask(task);
                                    }
                                }
                            }
                        }
                    }
                }

                if (!crew->IsBusy() && crew->task.taskId != 0)
                {
                    bool idle = true;

                    if (def->droneAI.batteryAI)
                    {
                        if (def->providesPower || def->bonusPower > 0)
                        {
                            idle = false;

                            int maxPowerDiff = 0;
                            int targetRoom = -1;

                            for (auto i : ship->vSystemList)
                            {
                                int powerDiff = i->powerState.second - i->powerState.first;

                                if (i->iSystemType == 3)
                                {
                                    int maxPower = 0;
                                    for (auto wep : ship->GetWeaponList())
                                    {
                                        maxPower += wep->requiredPower;
                                    }

                                    powerDiff = maxPower - i->powerState.first;
                                }

                                if (powerDiff > maxPowerDiff && powerDiff > 0 && !ShipSystem::IsSubsystem(i->iSystemType) && i->iSystemType != 4 && i->iSystemType != 5)
                                {
                                    maxPowerDiff = powerDiff;
                                    targetRoom = i->roomId;
                                    if (targetRoom != -1 && !ship->ship.RoomLocked(targetRoom) && (ship->CommandCrewMoveRoom(crew, targetRoom) || targetRoom == crew->currentSlot.roomId))
                                    {
                                        CrewTask task = CrewTask();
                                        task.room = targetRoom;
                                        task.taskId = 4;
                                        task.system = -1;

                                        crew->SetTask(task);
                                    }
                                    else
                                    {
                                        targetRoom = -1;
                                    }
                                }
                            }

                            if (targetRoom == -1)
                            {
                                int priorityList[7] = { 3, 0, 13, 1, 11, 10, 15 };

                                for (auto i : priorityList)
                                {
                                    if (i == 3)
                                    {
                                        int maxPower = 0;
                                        for (auto wep : ship->GetWeaponList())
                                        {
                                            maxPower += wep->requiredPower;
                                        }
                                        if (maxPower == 0) continue;
                                    }

                                    targetRoom = ship->GetSystemRoom(i);
                                    if (targetRoom != -1 && !ship->ship.RoomLocked(targetRoom) && (ship->CommandCrewMoveRoom(crew, targetRoom) || targetRoom == crew->currentSlot.roomId))
                                    {
                                        CrewTask task = CrewTask();
                                        task.room = targetRoom;
                                        task.taskId = 4;
                                        task.system = -1;

                                        crew->SetTask(task);

                                        break;
                                    }
                                    else
                                    {
                                        targetRoom = -1;
                                    }
                                }
                            }

                            if (targetRoom == -1)
                            {
                                idle = true;
                            }
                        }
                    }

                    if (idle)
                    {
                        if (def->droneAI.returnToDroneRoom)
                        {
                            int droneRoom = ship->GetSystemRoom(4);
                            if (!ship->ship.RoomLocked(droneRoom))
                            {
                                if (ship->CommandCrewMoveRoom(crew, droneRoom) || droneRoom == crew->currentSlot.roomId)
                                {
                                    CrewTask task = CrewTask();
                                    task.room = droneRoom;
                                    task.taskId = 4;
                                    task.system = -1;

                                    crew->SetTask(task);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

HOOK_METHOD(ShipManager, CreateSpaceDrone, (const DroneBlueprint *bp) -> SpaceDrone*)
{
    if (bp->type == 4)
    {
        for (auto i: myBlueprint.systemInfo)
        {
            if (i.second.systemId == SYS_DRONES)
            {
                return super(bp);
            }
        }

        BoarderPodDrone *ret = new BoarderPodDrone(iShipId, Globals::GetNextSpaceId(), *bp);
        ret->powerRequired = bp->power;
        spaceDrones.push_back(ret);
        droneTrash.push_back(ret);
        newDroneArrivals.push_back(ret);
        return ret;
    }

    return super(bp);
}

HOOK_METHOD(ShipManager, CreateSpaceDrone, (const DroneBlueprint *bp) -> SpaceDrone*)
{
    SpaceDrone* ret = super(bp);

    if (ret)
    {
        if (current_target)
        {
            if (ret->type == 1)
            {
                // combat

                ((CombatDrone*)ret)->SetMovementTarget(&current_target->_targetable);
                ((CombatDrone*)ret)->SetWeaponTarget(&current_target->_targetable);

            }
            else if (ret->type == 4)
            {
                // boarder

                BoarderPodDrone *drone = ((BoarderPodDrone*)ret);

                drone->SetMovementTarget(&current_target->_targetable);

                if (drone->boarderDrone)
                {
                    drone->boarderDrone->SetCurrentShip(current_target->iShipId);
                    drone->boarderDrone->ship = &current_target->ship;
                    drone->boarderDrone->SetRoom(-1);
                    current_target->vCrewList.push_back(drone->boarderDrone);
                    drone->boarderDrone->EmptySlot();
                }
            }
        }
    }

    return ret;
}


static std::vector<Projectile*> spaceDroneQueuedProjectiles = std::vector<Projectile*>();
HOOK_METHOD(SpaceDrone, GetNextProjectile, () -> Projectile*)
{
    Projectile* ret;
    if (weaponBlueprint->type == 4) // flak
    {
        if (spaceDroneQueuedProjectiles.empty())
        {
            ret = super();
            if (ret)
            {
                Pointf lastTargetLocation = ret->target;

                float radius = CustomWeaponManager::instance->GetWeaponDefinition(weaponBlueprint->name)->angularRadius;
                if (radius == -1.f)
                {
                    radius = weaponBlueprint->radius;
                }
                else
                {
                    radius = radius * sqrt(lastTargetLocation.RelativeDistance(ret->position)) * 0.01745329f;
                }

                delete ret;

                for (auto &k : weaponBlueprint->miniProjectiles)
                {
                    float r = sqrt(random32()/2147483648.f) * radius;
                    float theta = random32()%360 * 0.01745329f;
                    Pointf ppos = {lastTargetLocation.x + r*cos(theta), lastTargetLocation.y + r*sin(theta)};
                    LaserBlast *projectile = new LaserBlast(currentLocation,currentSpace,currentSpace,ppos);
                    projectile->heading = -1.0;
                    projectile->OnInit();
                    projectile->Initialize(*weaponBlueprint);
                    projectile->ownerId = iShipId;

                    Animation *anim = G_->GetAnimationControl()->GetAnimation(k.image);
                    projectile->flight_animation = *anim;
                    delete anim;

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
                        projectile->damage.ownerId = iShipId;
                        projectile->bBroadcastTarget = type == 1 && iShipId == 0;
                    }

                    spaceDroneQueuedProjectiles.push_back(projectile);
                }
            }
        }
        if (!spaceDroneQueuedProjectiles.empty())
        {
            ret = spaceDroneQueuedProjectiles.back();
            spaceDroneQueuedProjectiles.pop_back();
            return ret;
        }
        return nullptr;
    }

    ret = super();
    if (ret && weaponBlueprint->type == 3) // bomb
    {
        ret->flight_animation.tracker.loop = false;
    }
    return ret;
}

HOOK_METHOD(DroneSystem, OnLoop, () -> void)
{
    if (!loadingGame)
    {
        for (Drone* _drone : drones)
        {
            if (_drone->type == 4) // check that this is a boarding drone
            {
                BoarderPodDrone* drone = (BoarderPodDrone*) _drone;
                if (drone->movementTarget == nullptr && drone->deployed)
                {
                    if (!drone->bDead && (!drone->bDeliveredDrone || !drone->boarderDrone->bDead))
                    {
                        if (_shipObj.HasAugmentation("BOARDER_RECOVERY"))
                        {
                            drone_count += 1;
                            drone->SetDeployed(false);
                        }
                    }
                }
            }
        }
    }
    super();
}


HOOK_METHOD(CrewDrone, OnLoop, () -> void)
{
    if (CustomCrewManager::GetInstance()->IsRace(species) && CustomCrewManager::GetInstance()->GetDefinition(species)->droneMoveFromManningSlot)
    {
        SetFrozen(_drone.deployed && !_drone.powered);

        ShipGraph *shipGraph = ShipGraph::GetShipInfo(currentShipId);

        if (currentSlot.slotId != -1 && iRoomId != -1 && !intruder)
        {
            if (_drone.deployed && !_drone.powered && shipGraph->rooms[iRoomId]->primarySlot == currentSlot.slotId)
            {
                bFrozenLocation = false;
            }

            if (!bFrozenLocation)
            {
                int closestSlot = -1;
                int closestRoom = -1;
                int closestDist = INT_MAX;

                Room *currentRoom = shipGraph->rooms[iRoomId];

                if (currentRoom->primarySlot != currentSlot.slotId)
                {
                    bFrozenLocation = true;
                    return super();
                }

                for (auto room : shipGraph->rooms)
                {
                    std::vector<int> emptySlots = std::vector<int>();

                    for (int slot = 0; slot < room->slots[intruder].size(); slot++)
                    {
                        if (slot != room->primarySlot && room->slots[intruder][slot] == false)
                        {
                            emptySlots.push_back(slot);
                        }
                    }

                    for (auto slot : emptySlots)
                    {
                        int dist = shipGraph->GetSlotWorldPosition(room->iRoomId, slot).RelativeDistance(currentSlot.worldLocation);

                        if (dist < closestDist)
                        {
                            closestSlot = slot;
                            closestRoom = room->iRoomId;
                            closestDist = dist;
                        }
                    }
                }



                bFrozenLocation = true;

                if (closestRoom != -1)
                {
                    MoveToRoom(closestRoom, closestSlot, intruder);
                }

            }
        }
    }

    super();
}

HOOK_METHOD(BoarderPodDrone, constructor, (int _iShipId, int _selfId, const DroneBlueprint& _bp) -> void)
{
    super(_iShipId, _selfId, _bp);

    CustomDroneManager* customDrone = CustomDroneManager::GetInstance();

    if (customDrone->GetDefinition(_bp.name))
    {
        std::string race = customDrone->GetDefinition(_bp.name)->crewBlueprint;

        baseSheet = G_->GetResources()->GetImageId("people/" + race + "_base.png");
        colorSheet = G_->GetResources()->GetImageId("people/" + race + "_layer1.png");
        droneImage = *G_->GetAnimationControl()->GetAnimation(race + "_fly");
    }
}


HOOK_METHOD(CrewDrone, OnLoop, () -> void)
{
    super();

    if (CM_EX(this)->isAbilityDrone)
    {
        ((AbilityDrone*)this)->new_OnLoop();
    }
}

HOOK_METHOD(CrewAnimation, OnRender, (float scale, int selectedState, bool outlineOnly) -> void)
{
    if (CMA_EX(this)->isAbilityDrone)
    {
        if (((AbilityDroneAnimation*)this)->new_OnRender(scale, selectedState, outlineOnly)) return;
    }

    super(scale, selectedState, outlineOnly);

}


HOOK_METHOD(CrewAnimation, OnInit, (const std::string& _race, Pointf position, bool enemy) -> void)
{
    super(_race, position, enemy);

    CustomDroneDefinition *customDrone = CustomDroneManager::GetInstance()->GetDefinitionByRace(_race);

    if (customDrone && customDrone->hasAbility)
    {
        ((AbilityDroneAnimation*)this)->new_OnInit(_race, position, enemy);
    }
}

