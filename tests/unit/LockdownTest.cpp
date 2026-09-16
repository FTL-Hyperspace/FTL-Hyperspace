#include "../utils/TestUtils.h"
#include "../../Global.h"
#include "../../CustomCrew.h"
#include "../../CustomLockdowns.h"

/**
 * Test: Crystal Crew Lockdown
 *
 * Spawns a crystal crew member, charges its ability and fires it,
 * PreparePower -> ActivatePower -> DamageArea -> Ship::LockdownRoom.
 *
 * Also checks the field offsets the lockdown code depends on, by driving vanilla
 * functions and reading the fields back through Hyperspace's struct definitions.
 * A mislocated field fails here instead of silently reading heap garbage in game.
 */

static const int LOCKDOWN_ATTEMPTS = 5;

static CrewMember* g_crew = nullptr;
static ActivatedPower* g_power = nullptr;
static int g_roomId = -1;
static size_t g_shardsBefore = 0;

static Ship* getShipHull()
{
    ShipManager* manager = GameAccess::State::getPlayerShip();
    return manager ? &manager->ship : nullptr;
}

// Crew spawn with an empty cooldown, so top it up rather than waiting out the charge
static void chargeAbility(ActivatedPower* power)
{
    power->powerCooldown.first = power->powerCooldown.second;
    if (power->powerCharges.second >= 0)
    {
        power->powerCharges.first = std::max(1, power->powerCharges.second);
    }
    for (ActivatedPowerResource* resource : power->powerResources)
    {
        resource->powerCooldown.first = resource->powerCooldown.second;
        if (resource->powerCharges.second >= 0)
        {
            resource->powerCharges.first = std::max(1, resource->powerCharges.second);
        }
    }
}

static void LockdownTest(TestFramework::Test& test, TestFramework::TestStages& stages)
{
    test.section("Crystal Crew Lockdown Test");

    stages.addStage("Verify lockdown field offsets", [&test]() {
        Ship* ship = getShipHull();
        test.requireNotNull(ship, "Player ship exists");
        test.requireTrue(!ship->vDoorList.empty(), "Ship has doors");

        for (Door* door : ship->vDoorList)
        {
            bool before = door->lockedDown.running;

            door->SetLockdown(true);
            test.requireTrue(door->lockedDown.running,
                "Door " + std::to_string(door->iDoorId) + ": SetLockdown(true) visible through lockedDown.running");
            door->SetLockdown(false);
            test.requireFalse(door->lockedDown.running,
                "Door " + std::to_string(door->iDoorId) + ": SetLockdown(false) visible through lockedDown.running");

            door->lockedDown.running = before;
        }
    }, 0);

    for (int attempt = 0; attempt < LOCKDOWN_ATTEMPTS; ++attempt)
    {
        const std::string label = "Attempt " + std::to_string(attempt + 1);

        stages.addStage("Spawn crystal crew (" + label + ")", [&test, attempt]() {
            ShipManager* manager = GameAccess::State::getPlayerShip();
            Ship* ship = getShipHull();
            test.requireNotNull(ship, "Player ship exists");

            g_roomId = ship->vRoomList[attempt % ship->vRoomList.size()]->iRoomId;
            g_crew = manager->AddCrewMemberFromString(
                "Lockdown Tester", "crystal", false, g_roomId, true, true);

            test.requireNotNull(g_crew, "Crystal crew member was created");
            test.assertTrue(g_crew->iRoomId == g_roomId,
                "Crew spawned in room " + std::to_string(g_roomId) +
                " (is in " + std::to_string(g_crew->iRoomId) + ")");

            g_power = CM_EX(g_crew)->GetFirstCrewPower();
            test.requireNotNull(g_power, "Crystal crew has an activated power");
        }, 5);

        stages.addStage("Charge and fire ability (" + label + ")", [&test, label]() {
            Ship* ship = getShipHull();
            test.requireNotNull(ship, "Player ship exists");
            test.requireNotNull(g_power, "Ability is available");

            chargeAbility(g_power);
            test.requireTrue(g_power->PowerReady() == PowerReadyState::POWER_READY,
                label + ": ability is charged and ready (state " +
                std::to_string((int)g_power->PowerReady()) + ")");

            g_shardsBefore = ship->lockdowns.size();
            g_power->PreparePower();
        }, 60);

        stages.addStage("Verify lockdown (" + label + ")", [&test, label]() {
            Ship* ship = getShipHull();
            test.requireNotNull(ship, "Player ship exists");

            int connecting = 0;
            int locked = 0;
            for (Door* door : ship->vDoorList)
            {
                if (!door->ConnectsRooms(g_roomId, -1)) continue;
                ++connecting;
                if (door->lockedDown.running) ++locked;
            }

            test.log("Room " + std::to_string(g_roomId) + ": " +
                     std::to_string(ship->lockdowns.size() - g_shardsBefore) + " shards spawned, " +
                     std::to_string(locked) + "/" + std::to_string(connecting) + " doors locked");

            test.assertTrue(ship->lockdowns.size() > g_shardsBefore,
                label + ": ability spawned lockdown shards");

            // bDone is ours to write and the game's to read, so a wrong offset for it
            // silently reads uninitialized padding instead of the real flag
            if (!ship->lockdowns.empty())
            {
                LockdownShard& shard = ship->lockdowns.front();
                bool original = shard.bDone;

                shard.bDone = true;
                test.assertTrue(shard.Done(),
                    label + ": bDone=true is visible through the game's Done()");
                shard.bDone = false;
                test.assertFalse(shard.Done(),
                    label + ": bDone=false is visible through the game's Done()");

                shard.bDone = original;
            }
            test.assertTrue(connecting > 0, label + ": room has doors to lock");
            test.assertTrue(locked == connecting,
                label + ": every connecting door is locked down (" +
                std::to_string(locked) + "/" + std::to_string(connecting) + ")");
        }, 10);
    }
}

// Auto-register
static TestFramework::TestRegistrar _lockdownTest("Lockdown", LockdownTest, "SavedGame",
    TestFramework::ScenarioParams().setString("saveName", "hull-28-scrap-18"));
