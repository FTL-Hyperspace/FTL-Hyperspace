#include "CustomReactor.h"
#include "CustomShipSelect.h"
#include "CustomShips.h"
#include "freetype.h"
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
    int reactorLevel = playerPowerMngr->currentPower.second;
    int tempLevel = tempUpgrade + reactorLevel;
    int displayReactorLevel = playerPowerMngr->currentPower.second;
    int displayTempUpgrade = tempUpgrade;
    int coloumn = floor(tempLevel / 5) + 1;
    int overCol = 0;

    bActive = reactorLevel < maxLevel;

    static GL_Color COLOR_GREEN(100.f/255, 255.f/255, 100.f/255, 1.f), COLOR_CB_WHITE(243.f/255, 255.f/255, 238.f/255, 1.f),
    dirtyWhite(235.f/255, 245.f/255, 229.f/255, 1.f), hoverColour(245.f/255, 238.f/255, 163.f/255, 1.f),
    emptyColour(255.f/255, 255.f/255, 100.f/255, 0.25f);
    GL_Color fullColour = G_->GetSettings()->colorblind ? COLOR_CB_WHITE : COLOR_GREEN;

    GL_Texture* reactorImageOff = G_->GetResources()->GetImageId("upgradeUI/equipment/equipment_reactor_off.png");
    GL_Texture* reactorImage = G_->GetResources()->GetImageId("upgradeUI/equipment/equipment_reactor_on.png");
    GL_Texture* reactorImageSel = G_->GetResources()->GetImageId("upgradeUI/equipment/equipment_reactor_select2.png");
    GL_Texture* activeImage = bActive ? (bHover ? reactorImageSel : reactorImage) : reactorImageOff;
    int baseX = position.x, baseY = position.y;

    G_->GetResources()->RenderImage(activeImage, baseX, baseY, 0, COLOR_WHITE, 1.f, false);

    //adjusting levels for rendering
    if(tempLevel >= 25){
        overCol = ceil((tempLevel - 25) / 5) + 1;
        if(tempLevel == maxLevel && (maxLevel % 5 == 0)) overCol--;
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

    //reactor upgrade boxes rendering
    GL_Color currentColour = (bActive && bHover) ? hoverColour : dirtyWhite;
    for(int col = 0; col < 5; col++){
        for(int row = 0; row < 5; row++){
            int currentBar = col * 5 + row + 1;
            GL_Color colour;
            if(currentBar <= displayReactorLevel) colour = fullColour;
            else if (currentBar <= displayTempLevel) colour = COLOR_YELLOW;
            else if((tempLevel > (maxLevel - 4)) && (currentBar > displayMaxLevel)) continue;
            else colour = emptyColour;
            CSurface::GL_DrawRect(baseX + 30 + col * 44, baseY + 74 - row * 13, 32, -8, colour);
        }

        int currentCost;
        if(reactorCosts[col + 1 + overCol] >= 0){
            currentCost = reactorCosts[col + 1 + overCol];
        } else {
            currentCost = reactorCosts[0] + (col + overCol) * increment;
        }

        //prices over the coloumns
        std::string price = std::to_string(currentCost);
        CSurface::GL_SetColor(currentColour);
        freetype::easy_printRightAlign(5, baseX + 47 + col * 44, baseY + 2, price);
    }

    //"# power bars" text
    std::string reactorText = G_->GetTextLibrary()->GetText("upgrade_reactor_power");
    boost::algorithm::replace_all(reactorText, "\\1", "");

    int powerBarsTextSize1 = (int)(freetype_hack::easy_measurePrintLines(0, 0, 0, 999, "88").x + 0.5);
    int powerBarsTextSize2 = (int)(freetype_hack::easy_measurePrintLines(52, 0, 0, 999, reactorText).x + 0.5);
    int powerBarsTextOffset = 103 - (powerBarsTextSize1 + powerBarsTextSize2) / 2;

    CSurface::GL_SetColor(currentColour);
    freetype::easy_printRightAlign(0, baseX + powerBarsTextOffset + powerBarsTextSize1, baseY + 93, std::to_string(tempLevel));
    freetype::easy_print(52, baseX + powerBarsTextOffset + powerBarsTextSize1, baseY + 89, reactorText);

    //current price
    int currentCost;
    if(reactorCosts[coloumn] >= 0){
        currentCost = reactorCosts[coloumn];
    } else {
        currentCost = reactorCosts[0] + (coloumn - 1) * increment;
    }
    std::string currentPrice = std::to_string(currentCost);
    CSurface::GL_SetColor(currentColour);
    if(!bActive) freetype::easy_printCenter(52, baseX + 238, baseY + 88, G_->GetTextLibrary()->GetText("upgrade_max"));
    else if(tempLevel == maxLevel) freetype::easy_print(52, baseX + 233, baseY + 88, "--");
    else if (currentCost >= 100) freetype::easy_printAutoShrink(0, baseX + 235, baseY + 93, 39, false, currentPrice);
    else freetype::easy_print(0, baseX + 235, baseY + 93, currentPrice);
}

HOOK_METHOD(ShipManager, CanUpgrade, (int systemId, int amount) -> int)
{
    if (systemId == 17)
    {
        auto customSel = CustomShipSelect::GetInstance();
        auto def = customSel->GetDefinition(myBlueprint.blueprintName);
        int maxLevel = def.maxReactorLevel;
        auto reactor = PowerManager::GetPowerManager(iShipId);
        return std::min(amount, maxLevel - reactor->currentPower.second);
    }
    return super(systemId, amount);
}
