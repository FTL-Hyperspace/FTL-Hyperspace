#include "CustomReactor.h"

HOOK_METHOD(ReactorButton, OnClick, ()-> void)
{

    PowerManager* playerPowerMngr = PowerManager::GetPowerManager(0);
    ShipManager* shipMngr = this->ship;
    EventSystem* eventSys = G_->GetEventSystem();
    int currentScrap = shipMngr->currentScrap;
    int availablePower = playerPowerMngr->GetAvailablePower();
    int reactorLevel = playerPowerMngr->GetMaxPower();
    int tempUpg = this->tempUpgrade;
    int tempLevel = tempUpg + reactorLevel;
    int reactorCost;


    if(tempLevel <= 24 && this->bActive && this->bHover)
    {
        reactorCost = -30;
        if(tempLevel > 4) reactorCost =  -5 * (tempLevel / 5) + 15;
        if(currentScrap >= reactorCost){
            shipMngr->ModifyScrapCount(reactorCost, false);
            G_->GetSoundControl()->PlaySoundMix("bp_upgrade_1", -1.f, false);

        } else {
            eventSys->AddEvent(6);
        }
    }
}
