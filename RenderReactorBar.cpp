#include "RenderReactorBar.h"
#include "SystemBox_Extend.h"

static GL_Primitive *droneN = nullptr;
static int droneN_n = -1;

static GL_Texture* customWire = nullptr;
static GL_Primitive* customWire_connector = nullptr;
static GL_Primitive* customWire_connector_cap = nullptr;


const Point CUSTOM_WIRE_UI_OFFSET(31, 31);;


HOOK_METHOD(SystemControl, RenderPowerBar, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> SystemControl::RenderPowerBar -> Begin (RenderReactorBar.cpp)\n")
    PowerManager *playerPowerManager = PowerManager::GetPowerManager(0);
    int availablePower = playerPowerManager->GetAvailablePower();
    int reactorLevel = playerPowerManager->GetMaxPower();
    int powerBarCount = availablePower + playerPowerManager->batteryPower.second - playerPowerManager->batteryPower.first;
    int maxPower = playerPowerManager->currentPower.second + playerPowerManager->batteryPower.second;
    int unusedPower = powerBarCount - (maxPower - (reactorLevel + playerPowerManager->batteryPower.second));
    int displayLevel = (maxPower > 29) ? 27 : 29;

    float greyOpacity = 0.5;
    int batteryEffPower = playerPowerManager->batteryPower.second - playerPowerManager->batteryPower.first;

    int currentFirst = playerPowerManager->currentPower.first;
    int currentSecond = playerPowerManager->currentPower.second;

    SystemBox* currentSysBox;
    int startsAtTwo = 2;
    bool sysNeedsPower, bPowerWarningRunning = 0;
    ShipSystem* currentSys;
    int sysBoxLocX, sysBoxLocY;
    int sysPowerLocX, sysPowerLocY, sysPowerH = 0;
    int sysID, numWeaponSlots = shipManager->myBlueprint.weaponSlots;
    GL_Primitive* droneSysWireImage;
    int powerCounter;
    PowerBars* powerBars;
    bool colourBlindOn = G_->GetSettings()->colorblind;
    static GL_Color COLOR_GREEN(100.f/255, 255.f/255, 100.f/255, 1.f), COLOR_CB_WHITE(243.f/255, 255.f/255, 238.f/255, 1),
    borderColour(230.f/255, 110.f/255, 30.f/255, 1.f), blueColour(40.f/255, 210.f/255, 230.f/255, 1.f);
    GL_Color powerBarColourOn = colourBlindOn ? COLOR_CB_WHITE : COLOR_GREEN;
    GL_Color powerBarColour = powerBarColourOn;

    //TODO: Move to constructor or initialization function later
    if (!customWire)
    {
        customWire = G_->GetResources()->GetImageId("wireUI/wire_custom.png");
    }
    if (!customWire_connector)
    {
        const char* path = "wireUI/wire_custom_connector.png";
        int x = 0;
        int y = 0;
        int rotation = 0;
        GL_Color color(1.f, 1.f, 1.f, 1.f);
        float alpha = 1.f;
        bool mirror = false;
        customWire_connector = G_->GetResources()->CreateImagePrimitiveString(path, CUSTOM_WIRE_UI_OFFSET.x, CUSTOM_WIRE_UI_OFFSET.y, rotation, color, alpha, mirror);
    }
    if (!customWire_connector_cap)
    {
        const char* path = "wireUI/wire_custom_connector_cap.png";
        int x = 0;
        int y = 0;
        int rotation = 0;
        GL_Color color(1.f, 1.f, 1.f, 1.f);
        float alpha = 1.f;
        bool mirror = false;
        customWire_connector_cap = G_->GetResources()->CreateImagePrimitiveString(path, CUSTOM_WIRE_UI_OFFSET.x, CUSTOM_WIRE_UI_OFFSET.y, rotation, color, alpha, mirror);
    }

    if(G_->GetEventSystem()->PollEvent(11)){
        flashBatteryPower.Start(0);
        flashTracker.Start(0);
    }

    flashBatteryPower.Update();
    flashTracker.Update();
    if(flashBatteryPower.done) flashBatteryPower.Stop(false);

    //reactor wires rendering
    int wiresMaskY = (maxPower > displayLevel) ? (-9 * displayLevel + 1) : (-9 * maxPower + 1);
    CSurface::GL_SetStencilMode(STENCIL_SET, 1, 1);
    CSurface::GL_Translate(0, wiresMaskY, 0);
    CSurface::GL_RenderPrimitive(wiresMask);
    if (maxPower < 4) // fix vanilla bug with mask not covering wires properly at low power
    {
        CSurface::GL_Translate(0, -36, 0);
        CSurface::GL_RenderPrimitive(wiresMask);
        CSurface::GL_Translate(0, 36, 0);
    }
    if (maxPower < 1) // less ugly at 0 reactor
    {
        CSurface::GL_Translate(0, 36, 0);
        CSurface::GL_RenderPrimitive(wiresMask);
        CSurface::GL_Translate(0, -36, 0);
    }

    int wiresImageY = (maxPower > displayLevel) ? (9 * displayLevel - 1) : (9 * maxPower - 1);
    CSurface::GL_Translate(0, wiresImageY, 0);
    CSurface::GL_SetStencilMode(STENCIL_USE, 0, 1);
    CSurface::GL_RenderPrimitiveWithAlpha(wiresImage, greyOpacity);

    if(unusedPower){
        int unusedMaskY = (unusedPower > displayLevel) ? (-9 * displayLevel) : (-9 * unusedPower);
        CSurface::GL_SetStencilMode(STENCIL_SET, 1, 1);
        CSurface::GL_Translate(0, (-9 * unusedPower), 0);
        CSurface::GL_RenderPrimitive(wiresMask);

        int unusedImageY = (unusedPower > displayLevel) ? (9 * displayLevel) : (9 * unusedPower);
        CSurface::GL_Translate(0, (9 * unusedPower), 0);
        CSurface::GL_SetStencilMode(STENCIL_USE, 0, 1);
        CSurface::GL_RenderPrimitive(wiresImage);
    }

    CSurface::GL_SetStencilMode(STENCIL_IGNORE, 0, 0);


    //system wires rendering
    if(sysBoxes.size() > 7)
    {
        while(1)
        {
            currentSys = sysBoxes[startsAtTwo - 1]->pSystem;

            if(currentSys->GetNeedsPower()) {
                currentSysBox = sysBoxes[startsAtTwo - 2];
                sysBoxLocX = currentSysBox->location.x;
                sysBoxLocY = currentSysBox->location.y;
                CSurface::GL_Translate(sysBoxLocX, sysBoxLocY, 0);

                //generic wires 
                if (currentSysBox->pSystem->iSystemType >= SYS_CUSTOM_FIRST) //Use custom offset for custom systems
                {
                    currentSys = sysBoxes[startsAtTwo]->pSystem;
                    //Determine which connector primitive to use
                    GL_Primitive* connectorToUse = nullptr;
                    if(sysBoxes.size() <= startsAtTwo || currentSys->GetNeedsPower()) { 
                        //If not last system
                        connectorToUse = customWire_connector;
                    } else {
                        //Last system
                        connectorToUse = customWire_connector_cap;
                    }
                    //Render dynamically sized wire wire
                    float width = SB_EX(currentSysBox)->xOffset - connectorToUse->texture->width_;
                    width = std::max(0.f, width);
                    float alpha = unusedPower ? 1.f : greyOpacity;
                    GL_Color color(1.f, 1.f, 1.f, alpha);
                    CSurface::GL_BlitImage(customWire, CUSTOM_WIRE_UI_OFFSET.x, CUSTOM_WIRE_UI_OFFSET.y, width, customWire->height_, 0, color, false);
                    //Render connector
                    CSurface::GL_Translate(width, 0);
                    CSurface::GL_RenderPrimitiveWithAlpha(connectorToUse, alpha);
                    CSurface::GL_Translate(-width, 0);
                }

                else if(currentSysBox->HasButton()) {
                    currentSys = sysBoxes[startsAtTwo]->pSystem;
                    if(sysBoxes.size() <= startsAtTwo || currentSys->GetNeedsPower()) {
                        CSurface::GL_RenderPrimitiveWithAlpha(button, greyOpacity);
                        if(unusedPower) CSurface::GL_RenderPrimitive(button);
                    } else {
                        CSurface::GL_RenderPrimitiveWithAlpha(button_cap, greyOpacity);
                        if(unusedPower) CSurface::GL_RenderPrimitive(button_cap);
                    }
                } else {
                    currentSys = sysBoxes[startsAtTwo - 2]->pSystem;
                    sysID = currentSys->GetId();

                    //drone system wires
                    if(sysID == 3) {
                        if(numWeaponSlots == 2) droneSysWireImage = drone2;
                        else if(numWeaponSlots == 3) droneSysWireImage = drone3;
                        else if(numWeaponSlots == 4) droneSysWireImage = drone;
                        else
                        {
                            if (numWeaponSlots != droneN_n)
                            {
                                CSurface::GL_DestroyPrimitive(droneN);
                                droneN = G_->GetResources()->CreateImagePrimitiveString("wireUI/wire_456_" + std::to_string(shipManager->myBlueprint.weaponSlots) + "weapon_cap.png", 31, 31, 0, GL_Color(1.f, 1.f, 1.f, 1.f), 1.f, false);
                                droneN_n = numWeaponSlots;
                            }
                            droneSysWireImage = droneN;
                        }

                        CSurface::GL_RenderPrimitiveWithAlpha(droneSysWireImage, greyOpacity);
                        if(unusedPower) CSurface::GL_RenderPrimitive(droneSysWireImage);
                    } else {
                        currentSys = sysBoxes[startsAtTwo]->pSystem;
                        if(sysBoxes.size() <= startsAtTwo || currentSys->GetNeedsPower()) {
                            CSurface::GL_RenderPrimitiveWithAlpha(noButton, greyOpacity);
                            if(unusedPower) CSurface::GL_RenderPrimitive(noButton);
                        } else {
                            CSurface::GL_RenderPrimitiveWithAlpha(noButton_cap, greyOpacity);
                            if(unusedPower) CSurface::GL_RenderPrimitive(noButton_cap);
                        }
                    }
                }//hasButton else end
                CSurface::GL_Translate(-sysBoxLocX, -sysBoxLocY, 0);
            }//needsPower if end
            startsAtTwo++;
            if(sysBoxes.size() <= startsAtTwo) break;
        }//while(1) end
    }//sysBoxes.size > 7 end

    //reactor bars rendering
    if(!notEnoughPower->tracker.done) {
        bPowerWarningRunning = notEnoughPower->tracker.running;
        if(notEnoughPower->tracker.running && notEnoughPower->flash) bPowerWarningRunning = notEnoughPower->flashTracker.Progress(-1) < 0.5;
    }

    powerBars = SystemControl::GetPowerBars(28, 7, 2, false);
    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(systemPowerPosition.x, systemPowerPosition.y, 0);

    if(maxPower > 0) {
        powerCounter = 0;
        [&]{
            while(1) {
                while(1) {
                    //battery bar boxes
                    if(powerCounter < batteryEffPower){
                        powerBarColour = powerBarColourOn;
                        if(flashBatteryPower.running && flashTracker.Progress(-1) > 0.5 && !colourBlindOn) {
                            powerBarColour = COLOR_WHITE;
                        }

                        CSurface::GL_RenderPrimitiveWithColor(powerBars->tiny[powerCounter], powerBarColour);
                        CSurface::GL_RenderPrimitiveWithColor(powerBars->empty[powerCounter], borderColour);
                        powerCounter++;
                        if(maxPower == powerCounter){
                            sysPowerH = 9 * maxPower;
                            return;
                        } else if(powerCounter == displayLevel) {
                            sysPowerH = 9 * displayLevel;
                            return;
                        }
                        continue;
                    }

                    //blue bar boxes (nebula)
                    if(powerCounter < std::min((reactorLevel + playerPowerManager->batteryPower.second), displayLevel)) break;
                    CSurface::GL_RenderPrimitiveWithColor(powerBars->damaged[powerCounter], blueColour);
                    powerCounter++;
                    if(maxPower == powerCounter) {
                        sysPowerH = 9 * maxPower;
                        return;
                    } else if(powerCounter == displayLevel) {
                        sysPowerH = 9 * displayLevel;
                        return;
                    }
                }//inner while(1) end

                //power bar boxes
                if(unusedPower > powerCounter) {
                    if(bPowerWarningRunning) {
                        CSurface::GL_RenderPrimitive(powerBars->normal[powerCounter]);
                    } else {
                        powerBarColour = powerBarColourOn;
                        CSurface::GL_RenderPrimitiveWithColor(powerBars->normal[powerCounter], powerBarColour);
                    }
                    powerCounter++;
                    if(maxPower == powerCounter) {
                        sysPowerH = 9 * maxPower;
                        return;
                    } else if(powerCounter == displayLevel) {
                        sysPowerH = 9 * displayLevel;
                        return;
                    }
                    continue;
                }

                //empty bar boxes
                CSurface::GL_RenderPrimitive(powerBars->empty[powerCounter]);
                powerCounter++;
                if(maxPower == powerCounter) {
                    sysPowerH = 9 * maxPower;
                    return;
                } else if(powerCounter == displayLevel) {
                    sysPowerH = 9 * displayLevel;
                    return;
                }
            }//outer while(1) end
        }();
    }//if(maxPower > 0) end

    CSurface::GL_PopMatrix();

    if(maxPower > 29){
        std::stringstream reactorStream;
        if(unusedPower > 27) {
            CSurface::GL_SetColor(COLOR_GREEN);
            int overflow = unusedPower - 27;
            reactorStream << "+" << overflow;
            freetype::easy_printCenter(62, 26, 48, reactorStream.str());
        } else {
            CSurface::GL_SetColor(COLOR_WHITE);
            reactorStream << "+";
            freetype::easy_printCenter(62, 26, 48, reactorStream.str());
        }
    }

    if(!notEnoughPower->tracker.done && notEnoughPower->tracker.running){
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(74, 66);
        notEnoughPower->OnRender();
        CSurface::GL_PopMatrix();
    }
}//hook end
