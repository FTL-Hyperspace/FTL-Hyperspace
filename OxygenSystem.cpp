#include "OxygenSystem.h"

HOOK_METHOD_PRIORITY(OxygenSystem, GetRefillSpeed, 9999, () -> float)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> OxygenSystem::GetRefillSpeed -> Begin (OxygenSystem.cpp)\n")

    const float speed = G_->GetCFPS()->GetSpeedFactor();

    if (bUnderAttack && iHackEffect > 1)
    {
        return speed * -0.375F;
    }
    if (!Functioning())
    {
        return speed * -0.075F;
    }

    const int power = GetEffectivePower();
    const int multiplier = (power == 1) ? 1 : (power - 1) * 3;
    return multiplier * 0.075F * speed;
}

HOOK_METHOD_PRIORITY(OxygenSystem, OnLoop, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> OxygenSystem::OnLoop -> Begin (OxygenSystem.cpp)\n")

    ShipSystem::OnLoop();
    const float refillAmount = GetRefillSpeed();
    float total = 0.0F;
    for (float& oxygen : oxygenLevels)
    {
        oxygen += refillAmount; // Add refillAmount of oxygen to each room

        // Clamp oxygen level to [0,100]
        if(oxygen < 0.0F)
        {
            oxygen = 0.0F;
        } else if(oxygen > 100.0F)
        {
            oxygen = 100.0F;
        }

        total += oxygen;
    }

    // Total oxygen as a fraction of the maximum possible (size * 100)
    fTotalOxygen = total / (oxygenLevels.size() * 100.0F);

    // Balance adjacent rooms
    RedistributeOxygen();

    // Update the air leak sound only for the players ship
    if (_shipObj.iShipId == 0)
    {
        G_->GetSoundControl()->UpdateSoundLoop("airLeak", bLeakingO2 ? 1.0F : 0.0F);
    }
    bLeakingO2 = false;
}

void OxygenSystem::RedistributeOxygen()
{
    std::vector<bool> visited(oxygenLevels.size(), false);
    for (std::size_t room = 0; room < oxygenLevels.size(); ++room)
    {
        if (visited[room])
        {
            continue;
        }
        ShipGraph* const graph = ShipGraph::GetShipInfo(_shipObj.iShipId);
        const std::vector<std::int32_t> depths = graph->ConnectivityDFS(static_cast<std::int32_t>(room));
        if (depths.empty())
        {
            continue;
        }

        float total = 0.0F;
        std::int32_t connected = 0;
        for (std::size_t i = 0; i < depths.size(); ++i)
        {
            if (depths[i] != -1)
            {
                visited[i] = true;
                total += oxygenLevels[i];
                ++connected;
            }
        }
        const float desired = total / static_cast<float>(connected);
        for (std::size_t i = 0; i < depths.size(); ++i)
        {
            if (depths[i] != -1)
            {
                const float current = oxygenLevels[i];
                const float speed = G_->GetCFPS()->GetSpeedFactor();
                oxygenLevels[i] = current - speed * -0.005F * (desired - current);
            }
        }
    }
}
