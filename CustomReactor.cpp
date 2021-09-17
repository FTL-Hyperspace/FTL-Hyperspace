#include "CustomReactor.h"
#include "CustomShipSelect.h"
#include "CustomShips.h"
#include <cmath>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>


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
    int tempLevel = tempUpgrade + reactorLevel;
    int coloumn = floor(tempLevel / 5) + 1;

    if(tempLevel < maxLevel && bHover){

        int currentCost;
        if(reactorCosts[coloumn] >= 0){
            currentCost = reactorCosts[coloumn];
        } else {
            currentCost = reactorCosts[0] + (coloumn - 1) * increment;
        }

        if(currentScrap >= currentCost){
            ship->ModifyScrapCount(-currentCost, false);
            G_->GetSoundControl()->PlaySoundMix("upgradeSystem", -1.f, false);
            tempUpgrade++;
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

    PowerManager* playerPowerMngr = PowerManager::GetPowerManager(0);
    EventSystem* eventSys = G_->GetEventSystem();
    int currentScrap = ship->currentScrap;
    int reactorLevel = playerPowerMngr->GetMaxPower();
    int tempLevel = tempUpgrade + reactorLevel;
    int coloumn = floor((tempLevel - 1) / 5) + 1;

    if(tempUpgrade > 0 && bHover){

        int currentCost;
        if(reactorCosts[coloumn] >= 0){
            currentCost = reactorCosts[coloumn];
        } else {
            currentCost = reactorCosts[0] + (coloumn - 1) * increment;
        }

        ship->ModifyScrapCount(currentCost, false);
        tempUpgrade--;
        G_->GetSoundControl()->PlaySoundMix("downgradeSystem", -1.f, false);
    }
}

HOOK_METHOD(ReactorButton, OnRender, ()->void)
{
    auto def = CustomShipSelect::GetInstance()->GetDefinition(ship->myBlueprint.blueprintName);
    std::vector<int> reactorCosts = def.reactorPrices;
    int increment = def.reactorPriceIncrement;
    int maxLevel = def.maxReactorLevel;

    PowerManager* playerPowerMngr = PowerManager::GetPowerManager(0);
    int currentScrap = ship->currentScrap;
    int reactorLevel = playerPowerMngr->GetMaxPower();
    int tempLevel = tempUpgrade + reactorLevel;
    int displayReactorLevel = playerPowerMngr->GetMaxPower();
    int displayTempUpgrade = tempUpgrade;
    int coloumn = floor(tempLevel / 5) + 1;
    int overCol = 0;
    GL_Color COLOR_GREEN(100.f/255, 255.f/255, 100.f/255, 1.f), dirtyWhite(235.f/255, 245.f/255, 229.f/255, 1.f), hoverColour(245.f/255, 238.f/255, 163.f/255, 1.f),
    emptyColour(105.f/255, 98.f/255, 56.f/255, 1.f), blankColour(54.f/255, 45.f/255, 45.f/255, 1.f), blankHoverColour(122.f/255, 100.f/255, 100.f/255, 1.f);
    GL_Texture* reactorImage = G_->GetResources()->GetImageId("upgradeUI/equipment/equipment_reactor_on.png");
    GL_Texture* reactorImageSel = G_->GetResources()->GetImageId("upgradeUI/equipment/equipment_reactor_select2.png");
    GL_Texture* activeImage = bHover ? reactorImageSel : reactorImage;
    G_->GetResources()->RenderImage(activeImage, 610, 412, 0, COLOR_WHITE, 1.f, false);

    if(tempLevel > 25){
        overCol = ceil((tempLevel - 25) / 5) + 1;
        if(tempLevel == maxLevel) overCol--;
        if(displayReactorLevel < (overCol * 5)){
            displayTempUpgrade = displayTempUpgrade - (overCol * 5 - displayReactorLevel);
            displayReactorLevel = 0;
        } else {
            displayReactorLevel -= (overCol * 5);
        }
    }

    int displayTempLevel = displayTempUpgrade + displayReactorLevel;
    int displayMaxLevel = maxLevel;
    while(displayMaxLevel > 25){
        displayMaxLevel -= 5;
    }

    GL_Color currentColour = bHover ? hoverColour : dirtyWhite;
    for(int col = 0; col < 5; col++){
        for(int row = 0; row < 5; row++){
            int currentBar = col * 5 + row + 1;
            GL_Color colour;
            if(bHover) blankColour = blankHoverColour;
            if(currentBar <= displayReactorLevel) colour = COLOR_GREEN;
            else if (currentBar <= displayTempLevel) colour = COLOR_YELLOW;
            else if((tempLevel > (maxLevel - 4)) && (currentBar > displayMaxLevel)) colour = blankColour;
            else colour = emptyColour;
            CSurface::GL_DrawRect(640 + col * 44, 486 - row * 13, 32, -8, colour);
        }

        int currentCost;
        if(reactorCosts[col + 1 + overCol] >= 0){
            currentCost = reactorCosts[col + 1 + overCol];
        } else {
            currentCost = reactorCosts[0] + (col + overCol) * increment;
        }

        std::string price = boost::lexical_cast<std::string>(currentCost);
        CSurface::GL_SetColor(currentColour);
        freetype::easy_printRightAlign(5, 657 + col * 44, 414, price);
    }

    std::string reactorText = G_->GetTextLibrary()->GetText("upgrade_reactor_power");
    boost::algorithm::replace_all(reactorText, "\\1", boost::lexical_cast<std::string>(tempLevel));
    CSurface::GL_SetColor(currentColour);
    freetype::easy_printRightAlign(14, 791, 494, reactorText);

    int currentCost;
    if(reactorCosts[coloumn] >= 0){
        currentCost = reactorCosts[coloumn];
    } else {
        currentCost = reactorCosts[0] + (coloumn - 1) * increment;
    }
    std::string currentPrice = boost::lexical_cast<std::string>(currentCost);
    CSurface::GL_SetColor(currentColour);
    if(tempLevel == maxLevel) freetype::easy_print(14, 845, 496, "--");
    else if (currentCost >= 100) freetype::easy_printAutoShrink(14, 840, 494, 39, false, currentPrice);
    else freetype::easy_print(14, 845, 494, currentPrice);
}
