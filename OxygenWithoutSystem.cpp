#include "Global.h"
#include "CustomOptions.h"

/*
    This file contains the code to allow ships to have oxygen without an oxygen system installed.
    The game implements oxygen mechanics via the OxygenSystem class, which is instantiated at ShipManager::oxygenSystem.
    This was previously nullptr for all ShipManager instances that did not have an oxygen system installed, preventing oxygen mechanics from functioning properly.

    Implementation Details:

    All ShipManagers now have an OxygenSystem instance, regardless of whether an oxygen system is installed.


    All OxygenSystem methods are called either directly via ShipManager::oxygenSystem or by virtual dispatch from the ShipSystem base class.
    Direct calls are guarded by checks that ShipManager::systemKey[SYS_OXYGEN] != -1.
    These are bypassed by the added methods StartDummyOxygen and StopDummyOxygen, which change the value of systemKey[SYS_OXYGEN] to DUMMY_VALUE.
    DUMMY_VALUE is a negative value that is not -1.

    OxygenSystem method callers:
    ComputeAirLoss:
        Internal to other OxygenSystem methods
    EmptyOxygen:
        CrewMember * ShipManager::AddCrewMemberFromString(ShipManager* this, string* name, string* type, bool intruder, int roomId, bool init, bool male)
        CrewMember * ShipManager::AddCrewMemberFromBlueprint(ShipManager *this, CrewBlueprint* bp, int slot, bool init, int roomId, bool intruder)
    Functioning:
        Internal to other OxygenSystem methods, virtual dispatch
    GetOxygenLevel:
        float ShipManager::GetOxygenLevel(ShipManager* this, int roomId)
        void ShipManager::UpdateEnvironment(ShipManager* this)
        void ShipManager::UpdateCrewmembers(ShipManager* this)
        void ShipManager::ExportShip(ShipManager* this, int fd)
    GetRefillSpeed:
        UNKNOWN!
    ModifyRoomOxygen:
        void ShipManager::UpdateEnvironment(ShipManager* this)
    OnLoop:
        Virtual dispatch from ShipSystem::OnLoop
    OnRender:
        virtual dispatch from ShipSystem::OnRender (For system visuals, not necessary for dummy system)
    OxygenSystem:
        (Constructor, used in AddSystem and others)
    RedistributeOxygen:
        Internal to other OxygenSystem methods (OnLoop)
    RemoveRoom:
        UNKNOWN!
    Restart:
        (Likely virtual dispatch) from ShipSystem::Restart
    SetRoomOxygen:
        void ShipManager::ImportShip(ShipManager* this, int fd)
    UpdateAirlock:
        void ShipManager::UpdateEnvironment(ShipManager* this)
    UpdateBreach:
        void ShipManager::UpdateEnvironment(ShipManager* this)

OxygenSystem member variable access:
    ShipManager::GetOxygenPercentage
    ShipManager::GetOxygenLevels
Other:
    Inlined call to ShipManager::GetOxygenLevels within ShipManager::OnLoop has check for systemKey[SYS_OXYGEN] == -1




    To avoid bypassing systemKey checks for other methods, the systemKey value for SYS_OXYGEN is reset to -1 for the following methods

    ShipManager::GetSystemPower
    ShipManager::IsSystemHacked
    ShipManager::IsSystemHacked2
    ShipManager::ClearStatusSystem
    ShipManager::ClearStatusAll
    ShipManager::SetSystemPowerLimit
    ShipManager::SetSystemPowerLoss
    ShipManager::SetSystemDividePower
    ShipManager::GetSystemAvailablePower
    ShipManager::GetSystemDamage
    ShipManager::GetSystemHealth
    ShipManager::IncreaseSystemPower
    ShipManager::ForceIncreaseSystemPower
    ShipManager::ForceDecreaseSystemPower
    ShipManager::GetSystemRoom
    ShipManager::GetSystem
    ShipManager::SystemLocked
    ShipManager::SystemFunctions
    ShipManager::HasSystem (this one might need to be carefully handled as it might be used as a guard in some cases if not inlined)
    ShipManager::SystemRoom
    ShipManager::GetSystemPowerMax
    ShipManager::CanUpgrade
    ShipManager::UpgradeSystem


*/
/**
* @brief Determines if the dummy oxygen system should be used.
*
* This function checks the current value of the `oxygenWithoutSystem`
* option from the `CustomOptionsManager` instance. It returns a boolean
* indicating whether the dummy oxygen system is enabled.
*
* @return true if the dummy oxygen system should be used; false otherwise.
*/
static inline bool OxygenSettingEnabled()
{
    return CustomOptionsManager::GetInstance()->oxygenWithoutSystem.currentValue;
}
/**
* @brief A negative value that is not -1 meant to indicate that a system is not present but that some systemKey checks should be bypassed.
*/
const static int DUMMY_VALUE = -2;
/**
 * @brief Starts using the dummy oxygen system.
 * @return true if the dummy oxygen system was not being used; false otherwise.
*/

/**
 * @brief Sets whether the dummy oxygen system is being used or not.
 * @param useDummyOxygen A boolean indicating whether to use the dummy oxygen system.
 * @return The previous state of the dummy oxygen system, true if it was being used, false otherwise.
*/
bool ShipManager::SetDummyOxygen(bool useDummyOxygen)
{
    bool lastState = systemKey[SYS_OXYGEN] == DUMMY_VALUE;
    if (OxygenSettingEnabled() && systemKey[SYS_OXYGEN] < 0)
    {
        //Possibly move this elsewhere? Must be before all uses of oxygenSystem methods but after the number of rooms is known.
        //Or use a multi-step initialization process.
        if (oxygenSystem == nullptr && useDummyOxygen) InstallDummyOxygen();
        systemKey[SYS_OXYGEN] = useDummyOxygen ? DUMMY_VALUE : -1;
    }
    return lastState;
}
/**
* @brief Installs the dummy oxygen system.
*/
void ShipManager::InstallDummyOxygen()
{
    oxygenSystem = new OxygenSystem(ship.vRoomList.size(), -1, iShipId, 0);
    oxygenSystem->fTotalOxygen = 0.0f;
    for (auto& oxygenLevel : oxygenSystem->oxygenLevels)
    {
        oxygenLevel = 0.0f;
    };
}
/**
* @brief Removes the dummy oxygen system.
*/
void ShipManager::RemoveDummyOxygen()
{
    delete oxygenSystem;
    oxygenSystem = nullptr;
}
/**
 * @brief Indicates if the dummy oxygen system is installed.
 * @return true if the dummy oxygen system is installed; false otherwise.
*/
bool ShipManager::DummyOxygenInstalled()
{
    return oxygenSystem != nullptr && systemKey[SYS_OXYGEN] < 0;
}


//Remove dummy OxygenSystem when installing real system.
HOOK_METHOD(ShipManager, AddSystem, (int systemId) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::AddSystem -> Begin (OxygenWithoutSystem.cpp)\n")
    if (systemId == SYS_OXYGEN && DummyOxygenInstalled())
    {
        RemoveDummyOxygen();
    }
    return super(systemId);
}

//Bypass systemKey checks for all callers of OxygenSystem methods via ShipManager::oxygenSystem.
HOOK_METHOD(ShipManager, AddCrewMemberFromString, (const std::string& name, const std::string& race, bool intruder, int roomId, bool init, bool male) -> CrewMember*)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::AddCrewMemberFromString -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(true);
    CrewMember* ret = super(name, race, intruder, roomId, init, male);
    SetDummyOxygen(lastState);
    return ret;
}
HOOK_METHOD(ShipManager, AddCrewMemberFromBlueprint, (CrewBlueprint* bp, int slot, bool init, int roomId, bool intruder) -> CrewMember*)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::AddCrewMemberFromBlueprint -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(true);
    CrewMember* ret = super(bp, slot, init, roomId, intruder);
    SetDummyOxygen(lastState);
    return ret;
}
HOOK_METHOD(ShipManager, GetOxygenLevel, (int roomId) -> float)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetOxygenLevel -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(true);
    float ret = super(roomId);
    SetDummyOxygen(lastState);
    return ret;
}
HOOK_METHOD(ShipManager, UpdateEnvironment, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::UpdateEnvironment -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(true);
    super();
    SetDummyOxygen(lastState);
}
HOOK_METHOD(ShipManager, UpdateCrewMembers, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::UpdateCrewMembers -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(true);
    super();
    SetDummyOxygen(lastState);
}

HOOK_METHOD(ShipManager, ExportShip, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ExportShip -> Begin (OxygenWithoutSystem.cpp)\n")
    super(fd);
    if (DummyOxygenInstalled())
    {
        FileHelper::writeFloat(fd, oxygenSystem->max_oxygen);
        FileHelper::writeInt(fd, oxygenSystem->oxygenLevels.size());
        for (int i = 0; i < oxygenSystem->oxygenLevels.size(); ++i)
        {
            FileHelper::writeFloat(fd, oxygenSystem->oxygenLevels[i]);
        }
        FileHelper::writeFloat(fd, oxygenSystem->fTotalOxygen);
        FileHelper::writeInt(fd, oxygenSystem->bLeakingO2);
    }
}
HOOK_METHOD(ShipManager, ImportShip, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ImportShip -> Begin (OxygenWithoutSystem.cpp)\n")
    super(fd);
    if (DummyOxygenInstalled())
    {
        oxygenSystem->max_oxygen = FileHelper::readFloat(fd);
        int vectorSize = FileHelper::readInteger(fd);
        for (int i = 0; i < vectorSize; ++i)
        {
            int oxygenLevel = FileHelper::readFloat(fd);
            oxygenSystem->oxygenLevels[i] = oxygenLevel;
        }
        oxygenSystem->fTotalOxygen = FileHelper::readFloat(fd);
        oxygenSystem->bLeakingO2 = FileHelper::readInteger(fd);
    }
}
HOOK_METHOD(ShipManager, GetOxygenLevels, () -> std::vector<float>)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetOxygenLevels -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(true);
    std::vector<float> ret = super();
    SetDummyOxygen(lastState);
    return ret;
}
HOOK_METHOD(ShipManager, GetOxygenPercentage, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetOxygenPercentage -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(true);
    int ret = super();
    SetDummyOxygen(lastState);
    return ret;
}
//Call OnLoop method (Normally called via virtual dispatch) from ShipSystem* in vSystemList
HOOK_METHOD(ShipManager, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnLoop -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(true);
    super();
    if (OxygenSettingEnabled() && DummyOxygenInstalled()) oxygenSystem->OnLoop();
    SetDummyOxygen(lastState);
}

//Ensure systemKey checks are not bypassed for relevant methods.
HOOK_METHOD(ShipManager, GetSystemPower, (int systemId) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetSystemPower -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    auto ret = super(systemId);
    SetDummyOxygen(lastState);
    return ret;
}
HOOK_METHOD(ShipManager, IsSystemHacked, (int systemId) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::IsSystemHacked -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    auto ret = super(systemId);
    SetDummyOxygen(lastState);
    return ret;
}
HOOK_METHOD(ShipManager, IsSystemHacked2, (int systemId) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::IsSystemHacked2 -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    auto ret = super(systemId);
    SetDummyOxygen(lastState);
    return ret;
}
HOOK_METHOD(ShipManager, ClearStatusSystem, (int systemId) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ClearStatusSystem -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    super(systemId);
    SetDummyOxygen(lastState);
}
HOOK_METHOD(ShipManager, ClearStatusAll, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ClearStatusAll -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    super();
    SetDummyOxygen(lastState);
}
HOOK_METHOD(ShipManager, SetSystemPowerLimit, (int systemId, int limit) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::SetSystemPowerLimit -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    super(systemId, limit);
    SetDummyOxygen(lastState);
}
HOOK_METHOD(ShipManager, SetSystemPowerLoss, (int systemId, int powerLoss) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::SetSystemPowerLoss -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    super(systemId, powerLoss);
    SetDummyOxygen(lastState);
}
HOOK_METHOD(ShipManager, SetSystemDividePower, (int systemId, int amount) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::SetSystemDividePower -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    super(systemId, amount);
    SetDummyOxygen(lastState);
}
HOOK_METHOD(ShipManager, GetSystemAvailablePower, (int systemId) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetSystemAvailablePower -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    auto ret = super(systemId);
    SetDummyOxygen(lastState);
    return ret;
}
HOOK_METHOD(ShipManager, GetSystemDamage, (int systemId) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetSystemDamage -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    auto ret = super(systemId);
    SetDummyOxygen(lastState);
    return ret;
}
HOOK_METHOD(ShipManager, GetSystemHealth, (int systemId) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetSystemHealth -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    auto ret = super(systemId);
    SetDummyOxygen(lastState);
    return ret;
}
HOOK_METHOD(ShipManager, IncreaseSystemPower, (int systemId) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::IncreaseSystemPower -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    auto ret = super(systemId);
    SetDummyOxygen(lastState);
    return ret;
}
HOOK_METHOD(ShipManager, ForceIncreaseSystemPower, (int systemId) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ForceIncreaseSystemPower -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    auto ret = super(systemId);
    SetDummyOxygen(lastState);
    return ret;
}
HOOK_METHOD(ShipManager, ForceDecreaseSystemPower, (int systemId) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ForceDecreaseSystemPower -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    auto ret = super(systemId);
    SetDummyOxygen(lastState);
    return ret;
}
HOOK_METHOD(ShipManager, GetSystemRoom, (int systemId) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetSystemRoom -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    auto ret = super(systemId);
    SetDummyOxygen(lastState);
    return ret;
}
HOOK_METHOD(ShipManager, GetSystem, (int systemId) -> ShipSystem*)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetSystem -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    auto ret = super(systemId);
    SetDummyOxygen(lastState);
    return ret;
}
HOOK_METHOD(ShipManager, SystemLocked, (int systemId) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::SystemLocked -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    auto ret = super(systemId);
    SetDummyOxygen(lastState);
    return ret;
}
HOOK_METHOD(ShipManager, SystemFunctions, (int systemId) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::SystemFunctions -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    auto ret = super(systemId);
    SetDummyOxygen(lastState);
    return ret;
}
//Check that this isn't used as a guard in some cases, it should be inlined most of the time.
HOOK_METHOD(ShipManager, HasSystem, (int systemId) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::HasSystem -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    auto ret = super(systemId);
    SetDummyOxygen(lastState);
    return ret;
}
HOOK_METHOD(ShipManager, SystemRoom, (int systemId) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::SystemRoom -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    auto ret = super(systemId);
    SetDummyOxygen(lastState);
    return ret;
}
HOOK_METHOD(ShipManager, GetSystemPowerMax, (int systemId) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetSystemPowerMax -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    auto ret = super(systemId);
    SetDummyOxygen(lastState);
    return ret;
}
HOOK_METHOD(ShipManager, CanUpgrade, (int systemId, int amount) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::CanUpgrade -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    auto ret = super(systemId, amount);
    SetDummyOxygen(lastState);
    return ret;
}
HOOK_METHOD(ShipManager, UpgradeSystem, (int systemId, int amount) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::UpgradeSystem -> Begin (OxygenWithoutSystem.cpp)\n")
    bool lastState = SetDummyOxygen(false);
    super(systemId, amount);
    SetDummyOxygen(lastState);
}
