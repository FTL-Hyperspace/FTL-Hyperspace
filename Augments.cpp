#include "Global.h"
#include "math.h"

HOOK_METHOD(ShipObject, HasAugmentation, (std::string& augment) -> bool)
{
    ShipInfo *player = G_->GetShipInfo();
    auto augList = player->augList;

    if (augList.count(augment) > 0)
    {
        return augList.at(augment) > 0;
    }



    return false;
}

/*
HOOK_METHOD(CrewMember, UpdateHealth, () -> void)
{
    if (this->iShipId == 1 && this->intruder)
    {
        std::string augment("NANOBOT_DEFENSE_SYSTEM");

        if (G_->GetWorld()->playerShip && G_->GetWorld()->playerShip->shipManager->HasAugmentation(augment))
        {
            float augSpeed = G_->GetWorld()->playerShip->shipManager->GetAugmentationValue(augment) / 100.f;
            float speed = G_->GetCFPS()->GetSpeedFactor() * -augSpeed;
            this->DirectModifyHealth(speed);
        }
    }
    super();
}

*/
