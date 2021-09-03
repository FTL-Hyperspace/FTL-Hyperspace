#include "CustomReactor.h"
#include "CustomShipSelect.h"
#include "CustomShips.h"
#include <cmath>


HOOK_METHOD(ReactorButton, OnClick, ()-> void)
{
    auto customSel = CustomShipSelect::GetInstance();
    auto def = customSel->GetDefinition(ship->myBlueprint.blueprintName);
    std::vector<int> reactorCosts = def.reactorPrices;
    int increment = def.reactorPriceIncrement;
    int maxLevel = def.maxReactorLevel;

    PowerManager* playerPowerMngr = PowerManager::GetPowerManager(0);
    EventSystem* eventSys = G_->GetEventSystem();
    int currentScrap = ship->currentScrap;
    int reactorLevel = playerPowerMngr->GetMaxPower();
    int tempUpg = this->tempUpgrade;
    int tempLevel = tempUpg + reactorLevel;
    int coloumn = floor(tempLevel / 5) + 1;

    if(tempLevel < maxLevel && this->bHover){

        int currentCost;
        if(reactorCosts[coloumn] >= 0){
            currentCost = reactorCosts[coloumn];
        } else {
            currentCost = reactorCosts[0] + (coloumn - 1) * increment;
        }

        if(currentScrap >= currentCost){
            ship->ModifyScrapCount(-currentCost, false);
            G_->GetSoundControl()->PlaySoundMix("upgradeSystem", -1.f, false);
            this->tempUpgrade++;
        } else {
            eventSys->AddEvent(6);
        }
    }
}

HOOK_METHOD(ReactorButton, OnRightClick, ()->void)
{
    auto customSel = CustomShipSelect::GetInstance();
    auto def = customSel->GetDefinition(ship->myBlueprint.blueprintName);
    std::vector<int> reactorCosts = def.reactorPrices;
    int increment = def.reactorPriceIncrement;
    int maxLevel = def.maxReactorLevel;

    PowerManager* playerPowerMngr = PowerManager::GetPowerManager(0);
    EventSystem* eventSys = G_->GetEventSystem();
    int currentScrap = ship->currentScrap;
    int reactorLevel = playerPowerMngr->GetMaxPower();
    int tempUpg = this->tempUpgrade;
    int tempLevel = tempUpg + reactorLevel;
    int coloumn = floor((tempLevel - 1) / 5) + 1;

    if(tempUpgrade > 0 && this->bHover){

        int currentCost;
        if(reactorCosts[coloumn] >= 0){
            currentCost = reactorCosts[coloumn];
        } else {
            currentCost = reactorCosts[0] + (coloumn - 1) * increment;
        }

        ship->ModifyScrapCount(currentCost, false);
        this->tempUpgrade--;
        G_->GetSoundControl()->PlaySoundMix("downgradeSystem", -1.f, false);
    }
}

/*
HOOK_METHOD(ReactorButton, OnRender, ()->void)
{
    auto customSel = CustomShipSelect::GetInstance();
    auto def = customSel->GetDefinition(ship->myBlueprint.blueprintName);
    std::vector<int> reactorCosts = def.reactorPrices;
    int increment = def.reactorPriceIncrement;
    int maxLevel = def.maxReactorLevel;

    PowerManager* playerPowerMngr = PowerManager::GetPowerManager(0);
    EventSystem* eventSys = G_->GetEventSystem();
    int currentScrap = ship->currentScrap;
    int reactorLevel = playerPowerMngr->GetMaxPower();
    int tempUpg = this->tempUpgrade;
    int tempLevel = tempUpg + reactorLevel;
    int coloumn = floor(tempLevel / 5) + 1;

}
*/

