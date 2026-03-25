#include "Global.h"
#include "Systems.h"
#include "CustomOptions.h"

static bool HackFix()
{
    return CustomOptionsManager::GetInstance()->teleporterHackFix.currentValue;
}

enum TeleportCommands
{
    TELE_NONE = 0,
    TELE_LEAVE = 1,
    TELE_ARRIVE = 2
};
static const int ALL_ROOMS = -2;

HOOK_METHOD_PRIORITY(ShipAI, GetTeleportCommand, 9999, () -> std::pair<int, int>)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipAI::GetTeleportCommand -> Begin (TeleporterBugFixes.cpp)\n")
    static const std::pair<int, int> NULL_COMMAND {TELE_NONE, -1};
    if (target != nullptr && ship != nullptr && ship->HasSystem(SYS_TELEPORTER))
    {
        TeleportSystem* teleSys = ship->teleportSystem;
        bool sysHacked = teleSys->iHackEffect >= 2 && teleSys->bUnderAttack;

        //Cloaking only blocks teleportation if the teleporter is not hacked when fix is enabled
        if((&target->_targetable)->IsCloaked() && !(sysHacked && HackFix())) return NULL_COMMAND;

        if (playerShip && !sysHacked) return NULL_COMMAND;
        //Hyperspace neutral ship bugfix
        if (!ship->_targetable.hostile && iTeleportRequest != -1) return NULL_COMMAND;

        if (iTeleportRequest > 0 && crewAI.ReadyForTeleport() && teleSys->CanSend())
        {
            iTeleportRequest -= teleSys->iPreparedCrew;
            if (iTeleportRequest < 1)
            {
                iTimesTeleported++;
                iTeleportRequest = 0;
            }
            return std::pair<int, int>(TELE_LEAVE, -1);
        }

        if (!(&ship->_targetable)->GetIsDying() && iTeleportRequest < 0 && (teleSys->CanReceive(true) || (ship->iShipId != 0 && !ship->_targetable.hostile)))
        {
            iTeleportRequest = 0;
            return std::pair<int, int>(TELE_ARRIVE, sysHacked && HackFix() ? ALL_ROOMS : iTeleportTarget);
        }
    }
    return NULL_COMMAND;
}


HOOK_METHOD_PRIORITY(ShipAI, SetEvacRequest, 9999, (int val) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipAI::SetEvacRequest -> Begin (TeleporterBugFixes.cpp)\n")
    //Vanilla code does not account for energy shield bypass when attempting to recall crew
    bool shouldUseBypass = CustomOptionsManager::GetInstance()->energyBypassTeleportRecall.currentValue && ship->HasAugmentation("ZOLTAN_BYPASS");
    if (target != nullptr && (&target->_targetable)->GetShieldPower().super.first > 0 && !shouldUseBypass) return;
    if (val != -1 && !destroyed && 0.0 <= escapeTimer)
    {
        iTeleportTarget = val;
        iTeleportRequest = -1;
    }
}

std::vector<CrewMember*> TeleportCrewShip(ShipManager *ship, int roomId, bool intruders, int maximum=-1)
{
    std::vector<CrewMember*> leavingCrewList = std::vector<CrewMember*>();

    int teleCounter = 0;

    for (auto i : ship->vCrewList)
    {
        if (roomId != i->iRoomId && roomId != ALL_ROOMS)
        {
            continue;
        }

        if (i->GetIntruder() == intruders && i->CanTeleport() && (!CM_EX(i)->customTele.teleporting || i->crewAnim->anims[0][6].tracker.reverse))
        {
            i->StartTeleport();
            leavingCrewList.push_back(i);

            teleCounter++;

            if (teleCounter >= maximum && maximum != -1) return leavingCrewList;
        }
    }

    return leavingCrewList;
}


HOOK_METHOD_PRIORITY(CompleteShip, InitiateTeleport, 9999, (int targetRoom, int command) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CompleteShip::InitiateTeleport -> Begin (TeleporterBugFixes.cpp)\n")
    if (!arrivingParty.empty() || !leavingParty.empty() || command == TELE_NONE ||
        enemyShip == nullptr || enemyShip->shipManager == nullptr || enemyShip->shipManager->bJumping ||
        shipManager == nullptr || shipManager->bJumping)
    {
        return;
    }

    int actualRoom = targetRoom;

    if (targetRoom == -1)
    {
        actualRoom = random32() % ShipGraph::GetShipInfo(enemyShip->shipManager->iShipId)->RoomCount();
    }

    teleTargetRoom = actualRoom;

    int teleSysRoom = shipManager->GetSystemRoom(SYS_TELEPORTER);

    if (command == TELE_LEAVE)
    {
        int freeSlots = 0;

        for (auto i : ShipGraph::GetShipInfo(enemyShip->shipManager->iShipId)->rooms)
        {
            freeSlots += i->GetEmptySlots(true);
        }

        if (freeSlots > 0)
        {
            leavingParty = TeleportCrewShip(shipManager, teleSysRoom, false, freeSlots);
        }
    }
    if (command == TELE_ARRIVE)
    {
        int arrivingSlots = ShipGraph::GetShipInfo(enemyShip->shipManager->iShipId)->GetNumSlots(teleSysRoom);
        if (targetRoom != ALL_ROOMS) arrivingSlots = std::max(arrivingSlots, 4);
        arrivingParty = TeleportCrewShip(enemyShip->shipManager, teleTargetRoom, true, arrivingSlots);
    }

    if (!leavingParty.empty() || !arrivingParty.empty())
    {
        shipManager->teleportSystem->InitiateTeleport();
        G_->GetSoundControl()->PlaySoundMix("teleport", -1.f, false);

        if (shipManager->HasEquipment("TELEPORT_HEAL"))
        {
            float value = shipManager->GetAugmentationValue("TELEPORT_HEAL");

            for (auto i : leavingParty)
            {
                i->DirectModifyHealth(value * i->health.second);
            }
            for (auto i : arrivingParty)
            {
                i->DirectModifyHealth(value * i->health.second);
            }
        }
    }
}

/*
HOOK_METHOD(ShipManager, TeleportCrew, (int roomId, bool intruders) -> std::vector<CrewMember*>)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::TeleportCrew -> Begin (InfiniteTeleport.cpp)\n")
    std::vector<CrewMember*> leavingCrewList = std::vector<CrewMember*>();

    int counter = 0;

    for (auto i : this->vCrewList)
    {
        if (roomId != i->iRoomId)
        {
            continue;
        }

        if (i->GetIntruder() == intruders && i->CanTeleport())
        {
            i->StartTeleport();
            leavingCrewList.push_back(i);

            counter++;

            if (counter >= 4)
            {
                return leavingCrewList;
            }
        }
    }
}
*/
