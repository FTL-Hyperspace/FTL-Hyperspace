// Fields the Android code relies on, where FTL for iPad 1.6.21's own code has them (the
// offsets its functions use). The layouts are in ios_arm64/FTLGameStripped.h; a failure
// here means a field moved there.
#include "Global.h"
#include <cstddef>

#pragma clang diagnostic ignored "-Winvalid-offsetof"

static_assert(offsetof(CombatControl, droneControl) == 0x4b0, "CombatControl::droneControl, passed to the drones box");
static_assert(offsetof(Equipment, ipadButton) == 0x4c0, "Equipment::ipadButton, the SELL button");
static_assert(offsetof(ShipSystem, iLockCount) == 0x24c, "ShipSystem::iLockCount, read by GetLockCount");
static_assert(offsetof(MouseControl, tooltipTitle) == 0x150, "MouseControl::tooltipTitle");
static_assert(offsetof(MouseControl, staticTooltip) == 0x188, "MouseControl::staticTooltip");
static_assert(offsetof(Upgrades, ipadButton) == 0x370, "Upgrades::ipadButton, the UPGRADE button");
static_assert(offsetof(Upgrades, ipadValues) == 0x480, "Upgrades::ipadValues, the selected box, price and info box width");
