#include "OxygenSystem.h"

HOOK_METHOD_PRIORITY(OxygenSystem, GetRefillSpeed, 9999, () -> float)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> OxygenSystem::GetRefillSpeed -> Begin (OxygenSystem.cpp)\n")

    // Begin: inline int GetHackLevel(ShipSystem * this)
    if (this->bUnderAttack && 1 < this->iHackEffect)
    {
        return G_->GetCFPS()->GetSpeedFactor() * -0.375f;
    }
    if (!this->OxygenSystem::Functioning())
    {
        return G_->GetCFPS()->GetSpeedFactor() * -0.075f;
    }
    return ((this->ShipSystem::GetEffectivePower() + -1) * 3.f + 1.f) * 0.075f * G_->GetCFPS()->GetSpeedFactor();
}

HOOK_METHOD_PRIORITY(OxygenSystem, OnLoop, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> OxygenSystem::OnLoop -> Begin (OxygenSystem.cpp)\n")

    this->ShipSystem::OnLoop();

    float refillAmount = this->OxygenSystem::GetRefillSpeed();

    // If there are no oxygen levels, skip processing (prevents division by zero)
    if (!this->oxygenLevels.empty())
    {
        // Add the refill amount to every room's oxygen level
        for (float& level : this->oxygenLevels)
        {
            level += refillAmount;
        }

        // Clamp each level to [0, 100] and sum them
        float totalOxygen = 0.f;
        for (float& level : this->oxygenLevels)
        {
            if (level < 0.f)
            {
                level = 0.f;
            }
            else if (level > 100.0f)
            {
                level = 100.0f;
            }
            totalOxygen += level;
        }

        // Compute total oxygen as a fraction of the maximum possible (size * 100)
        this->fTotalOxygen = totalOxygen / (this->oxygenLevels.size() * 100);
    }

    // Balance adjacent rooms
    this->RedistributeOxygen();

    // Update the air leak sound only for the players ship
    if (this->_shipObj.iShipId == 0)
    {
        G_->GetSoundControl()->UpdateSoundLoop("airLeak", static_cast<float>(this->bLeakingO2));
    }
    this->bLeakingO2 = false;
}
