#include "Global.h"


HOOK_METHOD(CrewMember, UpdateHealth, () -> void)
{

    if (this->currentShipId == 0 && this->intruder && !this->bMindControlled)
    {
        if (G_->GetWorld()->playerShip && G_->GetWorld()->playerShip->shipManager->HasAugmentation("NANOBOT_DEFENSE_SYSTEM"))
        {
            float augSpeed = G_->GetWorld()->playerShip->shipManager->GetAugmentationValue("NANOBOT_DEFENSE_SYSTEM") / 500.f;
            float speed = G_->GetCFPS()->GetSpeedFactor() * -augSpeed;
            this->DirectModifyHealth(speed);
        }
    }
    super();
}
