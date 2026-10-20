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
static_assert(offsetof(StarMap, currentLoc) == 0x70, "StarMap::currentLoc");
static_assert(offsetof(StarMap, hoverLoc) == 0x80, "StarMap::hoverLoc, the beacon tapped last");
static_assert(offsetof(StarMap, waitButton) == 0x1d0, "StarMap::waitButton, drawn in place of jumpButton");
static_assert(offsetof(StarMap, jumpButton) == 0x438, "StarMap::jumpButton");
static_assert(offsetof(StarMap, bossLevel) == 0xab8, "StarMap::bossLevel");
static_assert(offsetof(StarMap, bEnemyShip) == 0xae0, "StarMap::bEnemyShip");
static_assert(offsetof(InputBox, textBox) == 0x20, "InputBox::textBox, drawn by the iPad's InputBox::OnRender");
