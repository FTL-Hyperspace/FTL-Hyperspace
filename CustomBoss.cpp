#include "CustomBoss.h"
#include <boost/lexical_cast.hpp>

CustomBoss* CustomBoss::instance = new CustomBoss();


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
                customSurgeDrones = true;

                for (auto droneNode = bossNode->first_node(); droneNode; droneNode = droneNode->next_sibling())
                {
                    if (droneNode->first_attribute("difficulty"))
                    {
                        int difficulty = boost::lexical_cast<int>(droneNode->first_attribute("difficulty")->value());

                        if (difficulty > 2) continue;

                        DroneCount droneCount = DroneCount();

                        droneCount.drone = droneNode->first_attribute("name")->value();
                        droneCount.number = boost::lexical_cast<int>(droneNode->first_attribute("count")->value());

                        droneSurgeDef[difficulty].push_back(droneCount);
                    }
                }
            }
        }
    }
    catch (std::exception)
    {
        MessageBoxA(GetDesktopWindow(), "Error parsing <boss> in hyperspace.xml", "Error", MB_ICONERROR | MB_SETFOREGROUND);
    }
}



static bool isStartingStage = false;
static bool spawnBossCrew = false;
static BossShip* bossShipStartingStage;

HOOK_METHOD(BossShip, StartStage, () -> void)
{
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
    int crewCountsSize = FileHelper::readInteger(fh);

    for (int i = 0; i < crewCountsSize; i++)
    {
        auto crewDef = std::pair<std::string, int>();
        crewDef.first = std::string();
        FileHelper::readString(crewDef.first, fh);
        crewDef.second = FileHelper::readInteger(fh);
    }

    super(fh);
}


HOOK_METHOD(ShipManager, PrepareSuperDrones, () -> void)
{
    if (!CustomBoss::instance->customSurgeDrones) return;

    if (superDrones.size() == 0)
    {
        std::vector<DroneCount> droneCount = CustomBoss::instance->droneSurgeDef[*G_->difficulty];

        for (auto i : droneCount)
        {
            auto bp = G_->GetBlueprints()->GetDroneBlueprint(i.drone);
            for (int j = 0; j < i.number; j++)
            {
                auto drone = new CombatDrone(iShipId, Globals::GetNextSpaceId(), bp);
                superDrones.push_back(drone);

                drone->powerRequired = 0;
                drone->lifespan = 2;


                droneTrash.push_back(drone);
                newDroneArrivals.push_back(drone);
            }
        }
    }

    for (auto i : superDrones)
    {
        CombatDrone *drone = (CombatDrone*)i;

        drone->SetMovementTarget(&current_target->_targetable);
        drone->SetWeaponTarget(&current_target->_targetable);
        drone->lifespan = 2;
        drone->powered = true;
        drone->SetDeployed(true);
        drone->bDead = false;
    }
}

HOOK_METHOD(BossShip, GetEvent, () -> LocationEvent*)
{
    LocationEvent *ret = super();

    ret->statusEffects.clear();

    return ret;
}

static bool blockSystemBoxRender = false;


HOOK_METHOD(SystemBox, OnRender, (bool ignoreStatus) -> void)
{
    if (blockSystemBoxRender)
    {
        return;
    }

    super(ignoreStatus);
}


HOOK_METHOD(CombatControl, RenderTarget, () -> void)
{
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
