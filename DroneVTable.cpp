#pragma GCC push_options
#pragma GCC optimize ("O1")
#include "CustomDrones.h"
#include "CustomCrew.h"
#include <algorithm>

static bool __attribute__((fastcall)) CrewDrone_GetControllable(CrewDrone *_this)
{
    bool req = _this->iShipId == 0 && !_this->IsDead() && !_this->bMindControlled && _this->Functional();
    if (!req)
    {
        return false;
    }

    CustomCrewManager *custom = CustomCrewManager::GetInstance();

    if (_this->_drone.blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto ex = CM_EX(_this);
        auto def = custom->GetDefinition("boarder_ion");
        bool ret = false;
        ex->CalculateStat(CrewStat::CONTROLLABLE, def, &ret);
        return ret && req;
    }

    if (custom->IsRace(_this->species))
    {
        auto ex = CM_EX(_this);
        auto def = custom->GetDefinition(_this->species);
        bool ret = false;
        ex->CalculateStat(CrewStat::CONTROLLABLE, def, &ret);
        return ret && req;
    }

    return false;
}

static bool __attribute__((fastcall)) CrewDrone_CanFight(CrewDrone *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();

    if (_this->_drone.blueprint->name == "BOARDER_ION") {
        if (custom->IsRace("boarder_ion"))
        {
            auto ex = CM_EX(_this);
            auto def = custom->GetDefinition("boarder_ion");
            bool ret = false;
            ex->CalculateStat(CrewStat::CAN_FIGHT, def, &ret);
            return ret;
        }
        return false;
    }

    if (custom->IsRace(_this->species))
    {
        auto ex = CM_EX(_this);
        auto def = custom->GetDefinition(_this->species);
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_FIGHT, def, &ret);
        return ret;
    }

    if (_this->_drone.blueprint->typeName == "BOARDER")
    {
        return true;
    }
    else if (_this->_drone.blueprint->typeName == "BOARDER_ION")
    {
        return false;
    }
    else if (_this->_drone.blueprint->typeName == "REPAIR")
    {
        return false;
    }
    else if (_this->_drone.blueprint->typeName == "BATTLE")
    {
        return true;
    }
}

static bool __attribute__((fastcall)) CrewDrone_CanRepair(CrewDrone *_this)
{
    bool req = _this->_drone.powered;
    if (!req)
    {
        return false;
    }

    CustomCrewManager *custom = CustomCrewManager::GetInstance();

//    if (_this->GetShipObject()->HasAugmentation("ALL_DRONE_CREW_REPAIR"))
//    {
//        return (bool)_this->GetShipObject()->GetAugmentationValue("ALL_DRONE_CREW_REPAIR");
//    }
    if (_this->_drone.blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto ex = CM_EX(_this);
        auto def = custom->GetDefinition("boarder_ion");
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_REPAIR, def, &ret);
        return ret && req;
    }

    if (custom->IsRace(_this->species))
    {
        auto ex = CM_EX(_this);
        auto def = custom->GetDefinition(_this->species);
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_REPAIR, def, &ret);
        return ret && req;
    }

    if (_this->_drone.blueprint->typeName == "BOARDER")
    {
        return false;
    }
    else if (_this->_drone.blueprint->typeName == "BOARDER_ION")
    {
        return false;
    }
    else if (_this->_drone.blueprint->typeName == "REPAIR")
    {
        return req;
    }
    else if (_this->_drone.blueprint->typeName == "BATTLE")
    {
        return false;
    }
}

static bool __attribute__((fastcall)) CrewDrone_CanSabotage(CrewDrone *_this)
{
    bool req = _this->intruder;
    if (!req)
    {
        return false;
    }
    CustomCrewManager *custom = CustomCrewManager::GetInstance();

//    if (_this->GetShipObject()->HasAugmentation("ALL_DRONE_CREW_SABOTAGE"))
//    {
//        return (bool)_this->GetShipObject()->GetAugmentationValue("ALL_DRONE_CREW_SABOTAGE");
//    }
    if (_this->_drone.blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto ex = CM_EX(_this);
        auto def = custom->GetDefinition("boarder_ion");
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_SABOTAGE, def, &ret);
        return ret && req;
    }

    if (custom->IsRace(_this->species))
    {
        auto ex = CM_EX(_this);
        auto def = custom->GetDefinition(_this->species);
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_SABOTAGE, def, &ret);
        return ret && req;
    }

    if (_this->_drone.blueprint->typeName == "BOARDER")
    {
        return true;
    }
    else if (_this->_drone.blueprint->typeName == "BOARDER_ION")
    {
        return true;
    }
    else if (_this->_drone.blueprint->typeName == "REPAIR")
    {
        return false;
    }
    else if (_this->_drone.blueprint->typeName == "BATTLE")
    {
        return false;
    }
}

static bool __attribute__((fastcall)) CrewDrone_CanMan(CrewDrone *_this)
{
    bool req = !_this->intruder && _this->fStunTime == 0.f && _this->crewAnim->status != 3;
    if (!req)
    {
        return false;
    }

    CustomCrewManager *custom = CustomCrewManager::GetInstance();

//    if (_this->GetShipObject()->HasAugmentation("ALL_DRONE_CREW_MAN"))
//    {
//        return (bool)_this->GetShipObject()->GetAugmentationValue("ALL_DRONE_CREW_MAN");
//    }
    if (_this->_drone.blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto ex = CM_EX(_this);
        auto def = custom->GetDefinition("boarder_ion");
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_MAN, def, &ret);
        return ret && req;
    }

    if (custom->IsRace(_this->species))
    {
        auto ex = CM_EX(_this);
        auto def = custom->GetDefinition(_this->species);
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_MAN, def, &ret);
        return ret && req;
    }

    return false;
}

static bool __attribute__((fastcall)) CrewDrone_CanSuffocate(CrewDrone *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();

//    if (_this->GetShipObject()->HasAugmentation("ALL_DRONE_CREW_SUFFOCATE"))
//    {
//        return (bool)_this->GetShipObject()->GetAugmentationValue("ALL_DRONE_CREW_SUFFOCATE");
//    }
    if (_this->_drone.blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto ex = CM_EX(_this);
        auto def = custom->GetDefinition("boarder_ion");
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_SUFFOCATE, def, &ret);
        return ret;
    }

    if (custom->IsRace(_this->species))
    {
        auto ex = CM_EX(_this);
        auto def = custom->GetDefinition(_this->species);
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_SUFFOCATE, def, &ret);
        return ret;
    }

    return false;
}

static bool __attribute__((fastcall)) CrewDrone_CanBurn(CrewDrone *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();

//    if (_this->GetShipObject()->HasAugmentation("ALL_DRONE_CREW_BURN"))
//    {
//        return (bool)_this->GetShipObject()->GetAugmentationValue("ALL_DRONE_CREW_BURN");
//    }
    if (_this->_drone.blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto ex = CM_EX(_this);
        auto def = custom->GetDefinition("boarder_ion");
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_BURN, def, &ret);
        return ret;
    }

    if (custom->IsRace(_this->species))
    {
        auto ex = CM_EX(_this);
        auto def = custom->GetDefinition(_this->species);
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_BURN, def, &ret);
        return ret;
    }

    return false;
}

static float __attribute__((fastcall)) CrewDrone_GetMoveSpeedMultiplier(CrewDrone *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (_this->_drone.blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto def = custom->GetDefinition("boarder_ion");
        return CM_EX(_this)->CalculateStat(CrewStat::MOVE_SPEED_MULTIPLIER, def);
    }
    if (custom->IsRace(_this->species))
    {
        auto def = custom->GetDefinition(_this->species);
        return CM_EX(_this)->CalculateStat(CrewStat::MOVE_SPEED_MULTIPLIER, def);
    }

    return 0.5f;
}

static float __attribute__((fastcall)) CrewDrone_GetRepairSpeed(CrewDrone *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (_this->_drone.blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto def = custom->GetDefinition("boarder_ion");
        return CM_EX(_this)->CalculateStat(CrewStat::REPAIR_SPEED_MULTIPLIER, def);
    }
    if (custom->IsRace(_this->species))
    {
        auto def = custom->GetDefinition(_this->species);
        return CM_EX(_this)->CalculateStat(CrewStat::REPAIR_SPEED_MULTIPLIER, def);
    }

    return 2.f;
}

static int __attribute__((fastcall)) CrewDrone_GetMaxHealth(CrewDrone *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (_this->_drone.blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto def = custom->GetDefinition("boarder_ion");
        return CM_EX(_this)->CalculateStat(CrewStat::MAX_HEALTH, def);
    }
    if (custom->IsRace(_this->species))
    {
        auto def = custom->GetDefinition(_this->species);
        return CM_EX(_this)->CalculateStat(CrewStat::MAX_HEALTH, def);
    }

    if (_this->_drone.blueprint->typeName == "BOARDER")
    {
        return _this->_drone.blueprint->name == "BOARDER_ION" ? 125 : 150;
    }
    else if (_this->_drone.blueprint->typeName == "BOARDER_ION")
    {
        return 125;
    }
    else if (_this->_drone.blueprint->typeName == "REPAIR")
    {
        return 25;
    }
    else if (_this->_drone.blueprint->typeName == "BATTLE")
    {
        return 150;
    }
}

static float __attribute__((fastcall)) CrewDrone_GetDamageMultiplier(CrewDrone *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (_this->_drone.blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto def = custom->GetDefinition("boarder_ion");
        return CM_EX(_this)->CalculateStat(CrewStat::DAMAGE_MULTIPLIER, def);
    }
    if (custom->IsRace(_this->species))
    {
        auto def = custom->GetDefinition(_this->species);
        return CM_EX(_this)->CalculateStat(CrewStat::DAMAGE_MULTIPLIER, def);
    }

    if (_this->_drone.blueprint->typeName == "BOARDER")
    {
        return 1.2f;
    }
    else if (_this->_drone.blueprint->typeName == "BOARDER_ION")
    {
        return 1.f;
    }
    else if (_this->_drone.blueprint->typeName == "REPAIR")
    {
        return 1.f;
    }
    else if (_this->_drone.blueprint->typeName == "BATTLE")
    {
        return 1.2f;
    }
}

static bool __attribute__((fastcall)) CrewDrone_ProvidesPower(CrewDrone *_this)
{
    bool req = _this->_drone.powered;
    if (!req)
    {
        return false;
    }

    CustomCrewManager *custom = CustomCrewManager::GetInstance();

    if (_this->_drone.blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        return custom->GetDefinition("boarder_ion")->providesPower && req;
    }
    if (custom->IsRace(_this->species))
    {
        return custom->GetDefinition(_this->species)->providesPower && req;
    }

    return false;
}

static float __attribute__((fastcall)) CrewDrone_GetFireRepairMultiplier(CrewDrone *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (_this->_drone.blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto def = custom->GetDefinition("boarder_ion");
        return CM_EX(_this)->CalculateStat(CrewStat::FIRE_REPAIR_MULTIPLIER, def);
    }
    if (custom->IsRace(_this->species))
    {
        auto def = custom->GetDefinition(_this->species);
        return CM_EX(_this)->CalculateStat(CrewStat::FIRE_REPAIR_MULTIPLIER, def);
    }

    return 1.2f;
}

static bool __attribute__((fastcall)) CrewDrone_IsTelepathic(CrewDrone *_this)
{
    bool req = _this->_drone.powered;
    if (!req)
    {
        return false;
    }

    CustomCrewManager *custom = CustomCrewManager::GetInstance();

//    if (_this->GetShipObject()->HasAugmentation("ALL_DRONE_CREW_TELEPATHIC"))
//    {
//        return (bool)_this->GetShipObject()->GetAugmentationValue("ALL_DRONE_CREW_TELEPATHIC");
//    }
    if (_this->_drone.blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto ex = CM_EX(_this);
        auto def = custom->GetDefinition("boarder_ion");
        bool ret = (ex->temporaryPowerActive && ex->GetPowerDef()->tempPower.isTelepathic.enabled) ? ex->GetPowerDef()->tempPower.isTelepathic.value : def->isTelepathic;
        ex->CalculateStat(CrewStat::IS_TELEPATHIC, def, &ret);
        return ret && req;
    }

    if (custom->IsRace(_this->species))
    {
        auto ex = CM_EX(_this);
        auto def = custom->GetDefinition(_this->species);
        bool ret = (ex->temporaryPowerActive && ex->GetPowerDef()->tempPower.isTelepathic.enabled) ? ex->GetPowerDef()->tempPower.isTelepathic.value : def->isTelepathic;
        ex->CalculateStat(CrewStat::IS_TELEPATHIC, def, &ret);
        return ret && req;
    }

    return false;
}

static float __attribute__((fastcall)) CrewDrone_GetSuffocationModifier(CrewDrone *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (_this->_drone.blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto def = custom->GetDefinition("boarder_ion");
        return CM_EX(_this)->CalculateStat(CrewStat::SUFFOCATION_MODIFIER, def);
    }
    if (custom->IsRace(_this->species))
    {
        auto def = custom->GetDefinition(_this->species);
        return CM_EX(_this)->CalculateStat(CrewStat::SUFFOCATION_MODIFIER, def);
    }

    return 0.f;
}

static bool __attribute__((fastcall)) CrewDrone_IsAnaerobic(CrewDrone *_this)
{
    bool req = _this->_drone.powered;
    if (!req)
    {
        return false;
    }

    CustomCrewManager *custom = CustomCrewManager::GetInstance();

//    if (_this->GetShipObject()->HasAugmentation("ALL_DRONE_CREW_ANAEROBIC"))
//    {
//        return (bool)_this->GetShipObject()->GetAugmentationValue("ALL_DRONE_CREW_ANAEROBIC");
//    }
    if (_this->_drone.blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto ex = CM_EX(_this);
        auto def = custom->GetDefinition("boarder_ion");
        bool ret = false;
        ex->CalculateStat(CrewStat::IS_ANAEROBIC, def, &ret);
        return ret && req;
    }

    if (custom->IsRace(_this->species))
    {
        auto ex = CM_EX(_this);
        auto def = custom->GetDefinition(_this->species);
        bool ret = false;
        ex->CalculateStat(CrewStat::IS_ANAEROBIC, def, &ret);
        return ret && req;
    }

    return false;
}

static int __attribute__((fastcall)) CrewDrone_BlockRoom(CrewDrone *_this)
{
    if (CM_EX(_this)->isAbilityDrone)
        return ((AbilityDrone*)_this)->new_BlockRoom();
    else if (CM_EX(_this)->isIonDrone)
        return ((IonDrone*)_this)->lastRoom;

    return -1;
}

void SetupVTable(CrewDrone *crew)
{
    void** vtable = *(void***)crew;

    DWORD dwOldProtect, dwBkup;
    VirtualProtect(&vtable[0], sizeof(void*) * 57, PAGE_EXECUTE_READWRITE, &dwOldProtect);
    vtable[23] = (void*)&CrewDrone_GetControllable;
    vtable[25] = (void*)&CrewDrone_CanFight;
    vtable[26] = (void*)&CrewDrone_CanRepair;
    vtable[27] = (void*)&CrewDrone_CanSabotage;
    vtable[28] = (void*)&CrewDrone_CanMan;
    vtable[31] = (void*)&CrewDrone_CanSuffocate;
    vtable[32] = (void*)&CrewDrone_CanBurn;
    vtable[33] = (void*)&CrewDrone_GetMaxHealth;
    vtable[40] = (void*)&CrewDrone_GetMoveSpeedMultiplier;
    vtable[41] = (void*)&CrewDrone_GetRepairSpeed;
    vtable[42] = (void*)&CrewDrone_GetDamageMultiplier;
    vtable[43] = (void*)&CrewDrone_ProvidesPower;
    vtable[45] = (void*)&CrewDrone_GetFireRepairMultiplier;
    vtable[46] = (void*)&CrewDrone_IsTelepathic;
    vtable[52] = (void*)&CrewDrone_GetSuffocationModifier;
    vtable[53] = (void*)&CrewDrone_BlockRoom;
    vtable[55] = (void*)&CrewDrone_IsAnaerobic;
    VirtualProtect(&vtable[0], sizeof(void*) * 57, dwOldProtect, &dwBkup);
}

HOOK_METHOD(CrewMemberFactory, CreateRepairDrone, (int shipId, DroneBlueprint* bp) -> RepairDrone*)
{
    RepairDrone* drone = super(shipId, bp);

    SetupVTable(drone);

    return drone;
}



HOOK_METHOD(CrewMemberFactory, CreateBattleDrone, (int shipId, DroneBlueprint* bp) -> BattleDrone*)
{
    BattleDrone* drone = super(shipId, bp);

    SetupVTable(drone);

    return drone;
}

HOOK_METHOD_PRIORITY(CrewMemberFactory, CreateBoarderDrone, -900, (int shipId, DroneBlueprint* bp) -> BoarderDrone*)
{
    BoarderDrone* drone = super(shipId, bp);

    SetupVTable(drone);

    return drone;
}

#pragma GCC pop_options
