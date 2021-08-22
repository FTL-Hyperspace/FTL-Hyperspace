#include "RenderReactorBar.h"

HOOK_METHOD(SystemControl, RenderPowerBar, () -> void)
{
    PowerManager *playerPowerManager = PowerManager::GetPowerManager(0);
    int availablePower = playerPowerManager->GetAvailablePower();
    int reactorLevel = playerPowerManager->GetMaxPower();
    int powerBarCount = availablePower + playerPowerManager->batteryPower.second - playerPowerManager->batteryPower.first;
    int maxPower = playerPowerManager->currentPower.second + playerPowerManager->batteryPower.second;
    int unusedPower = powerBarCount - (maxPower - (reactorLevel + playerPowerManager->batteryPower.second));
    int displayLevel = (reactorLevel > 29) ? 27 : 29;

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
    int sysID, numWeaponSlots = this->shipManager->myBlueprint.weaponSlots;
    GL_Primitive* droneSysWireImage;
    WarningMessage* powerWarning = this->notEnoughPower;
    int powerCounter;
    PowerBars* powerBars;
    bool colourBlindOn = false;
    GL_Color COLOR_GREEN(100.f/255, 255.f/255, 100.f/255, 1.f), COLOR_CB_WHITE(243.f/255, 255.f/255, 238.f/255, 1), borderColour(230.f/255, 110.f/255, 30.f/255, 1.f), blueColour(40.f/255, 210.f/255, 230.f/255, 1.f);
    GL_Color powerBarColour = COLOR_GREEN;


    if(G_->GetEventSystem()->PollEvent(11))
    {
        printf("Successful event poll\n");
        this->flashBatteryPower.Start(0);
        this->flashTracker.Start(0);
    }
    else
    {
        printf("No event poll\n");
    }

    this->flashBatteryPower.Update();
    this->flashTracker.Update();
    if(this->flashBatteryPower.done) this->flashBatteryPower.Stop(false);

    //reactor wires rendering
    int wiresMaskY = (maxPower > displayLevel) ? (-9 * displayLevel + 1) : (-9 * maxPower + 1);
    CSurface::GL_SetStencilMode(STENCIL_SET, 1, 1);
    CSurface::GL_Translate(0, wiresMaskY, 0);
    CSurface::GL_RenderPrimitive(this->wiresMask);
    //printf("wiresMask: %i\n", wiresMaskY);

    int wiresImageY = (maxPower > displayLevel) ? (9 * displayLevel - 1) : (9 * maxPower - 1);
    CSurface::GL_Translate(0, wiresImageY, 0);
    CSurface::GL_SetStencilMode(STENCIL_USE, 0, 1);
    CSurface::GL_RenderPrimitiveWithAlpha(this->wiresImage, greyOpacity);
    //printf("wiresImage: %i\n", wiresImageY);

    if(unusedPower)
    {
        //int translateAmount = (unusedPower > 29) ? (unusedPower - 29) : unusedPower;
        int unusedMaskY = (unusedPower > displayLevel) ? (-9 * displayLevel) : (-9 * unusedPower);
        CSurface::GL_SetStencilMode(STENCIL_SET, 1, 1);
        CSurface::GL_Translate(0, (-9 * unusedPower), 0);
        CSurface::GL_RenderPrimitive(this->wiresMask);
        //printf("unusedMask: %i\n", unusedMaskY);

        int unusedImageY = (unusedPower > displayLevel) ? (9 * displayLevel) : (9 * unusedPower);
        CSurface::GL_Translate(0, (9 * unusedPower), 0);
        CSurface::GL_SetStencilMode(STENCIL_USE, 0, 1);
        CSurface::GL_RenderPrimitive(this->wiresImage);
        //printf("unusedImage: %i\n\n", unusedImageY);
    }
    else
    {
        //printf("\n");
    }

    CSurface::GL_SetStencilMode(STENCIL_IGNORE, 0, 0);


    //system wires rendering
    if(this->sysBoxes.size() > 7)
    {
        while(1)
        {
            currentSys = this->sysBoxes[startsAtTwo - 1]->pSystem;

            if(currentSys->GetNeedsPower())
            {
                currentSysBox = this->sysBoxes[startsAtTwo - 2];
                sysBoxLocX = currentSysBox->location.x;
                sysBoxLocY = currentSysBox->location.y;
                CSurface::GL_Translate(sysBoxLocX, sysBoxLocY, 0);

                if(currentSysBox->HasButton())
                {
                    currentSys = this->sysBoxes[startsAtTwo]->pSystem;
                    if(this->sysBoxes.size() <= startsAtTwo || currentSys->GetNeedsPower())
                    {
                        CSurface::GL_RenderPrimitiveWithAlpha(this->button, greyOpacity);
                        if(unusedPower) CSurface::GL_RenderPrimitive(this->button);
                    }
                    else
                    {
                        CSurface::GL_RenderPrimitiveWithAlpha(this->button_cap, greyOpacity);
                        if(unusedPower) CSurface::GL_RenderPrimitive(this->button_cap);
                    }
                }//hasButton if end
                else
                {
                    currentSys = this->sysBoxes[startsAtTwo - 2]->pSystem;
                    sysID = currentSys->GetId();

                    if(sysID == 3)
                    {
                        if(numWeaponSlots == 2)
                        {
                            droneSysWireImage = this->drone2;
                        }
                        else if(numWeaponSlots == 3)
                        {
                            droneSysWireImage = this->drone3;
                        }
                        else
                        {
                            droneSysWireImage = this->drone;
                        }

                        CSurface::GL_RenderPrimitiveWithAlpha(droneSysWireImage, greyOpacity);
                        if(unusedPower) CSurface::GL_RenderPrimitive(droneSysWireImage);
                    }//sysID if end
                    else
                    {
                        currentSys = this->sysBoxes[startsAtTwo]->pSystem;
                        if(this->sysBoxes.size() <= startsAtTwo || currentSys->GetNeedsPower())
                        {
                            CSurface::GL_RenderPrimitiveWithAlpha(this->noButton, greyOpacity);
                            if(unusedPower) CSurface::GL_RenderPrimitive(this->noButton);
                        }
                        else
                        {
                            CSurface::GL_RenderPrimitiveWithAlpha(this->noButton_cap, greyOpacity);
                            if(unusedPower) CSurface::GL_RenderPrimitive(this->noButton_cap);
                        }
                    }//sysID else end
                }//hasButton else end
                CSurface::GL_Translate(-sysBoxLocX, -sysBoxLocY, 0);
            }//needsPower if end
            startsAtTwo++;
            if(this->sysBoxes.size() <= startsAtTwo) break;
        }//while(1) end
    }//sysBoxes.size > 7 end

    //reactor bars rendering
    if(!powerWarning->tracker.done)
    {
        bPowerWarningRunning = powerWarning->tracker.running;
        if(powerWarning->tracker.running && powerWarning->flash) {
            bPowerWarningRunning = powerWarning->flashTracker.Progress(-1) < 0.5;
        }
    }

    sysPowerLocX = this->systemPowerPosition.x;
    sysPowerLocY = this->systemPowerPosition.y;
    powerBars = SystemControl::GetPowerBars(28, 7, 2, false);

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(sysPowerLocX, sysPowerLocY, 0);

    if(maxPower > 0)
    {
        powerCounter = 0;
        while(1)
        {
            while(1)
            {
                if(powerCounter < batteryEffPower)
                {
                    powerBarColour = COLOR_GREEN;
                    //if(colourBlindOn) powerBarColour = COLOR_CB_WHITE; //placeholder for when the colourblind setting is hooked
                    if(this->flashBatteryPower.running) {
                        if((this->flashTracker.Progress(-1) > 0.5) && !colourBlindOn)
                            powerBarColour = COLOR_WHITE;
                    }

                    CSurface::GL_RenderPrimitiveWithColor(powerBars->tiny[powerCounter], powerBarColour);
                    CSurface::GL_RenderPrimitiveWithColor(powerBars->empty[powerCounter], borderColour);
                    powerCounter++;
                    if(maxPower == powerCounter)
                    {
                        sysPowerH = 9 * maxPower;
                        goto doubleWhileEnd;
                    } else if(powerCounter == displayLevel) {
                        sysPowerH = 9 * displayLevel;
                        goto doubleWhileEnd;
                    }
                    continue;
                }//if(powerCounter < batteryEffPower)

                if(powerCounter < std::min((reactorLevel + playerPowerManager->batteryPower.second), displayLevel)) break;
                CSurface::GL_RenderPrimitiveWithColor(powerBars->damaged[powerCounter], blueColour);
                powerCounter++;
                if(maxPower == powerCounter) {
                    sysPowerH = 9 * maxPower;
                    goto doubleWhileEnd;
                } else if(powerCounter == displayLevel) {
                    sysPowerH = 9 * displayLevel;
                    goto doubleWhileEnd;
                }
            }//inner while(1) end

            //if(maxPower == powerCounter) break;
            if(unusedPower > powerCounter)
            {
                if(bPowerWarningRunning)
                {
                    CSurface::GL_RenderPrimitive(powerBars->normal[powerCounter]);
                } else {
                    powerBarColour = COLOR_GREEN;
                    //if(colourBlindOn) powerBarColour = COLOR_CB_WHITE; //placeholder for when the colourblind setting is hooked
                    CSurface::GL_RenderPrimitiveWithColor(powerBars->normal[powerCounter], powerBarColour);
                }
                powerCounter++;
                if(maxPower == powerCounter)
                {
                    sysPowerH = 9 * maxPower;
                    goto doubleWhileEnd;
                } else if(powerCounter == displayLevel) {
                    sysPowerH = 9 * displayLevel;
                    goto doubleWhileEnd;
                }
                continue;
            }//if(unusedPower > powerCounter) end

            CSurface::GL_RenderPrimitive(powerBars->empty[powerCounter]);
            powerCounter++;
            if(maxPower == powerCounter)
            {
                sysPowerH = 9 * maxPower;
                goto doubleWhileEnd;
            } else if(powerCounter == displayLevel) {
                sysPowerH = 9 * displayLevel;
                goto doubleWhileEnd;
            }
        }//outer while(1) end
    }//if(maxPower > 0) end

doubleWhileEnd:
    CSurface::GL_PopMatrix();
    this->SystemPower.h = sysPowerH;
    this->SystemPower.w = 28;
    this->SystemPower.x = 12 - this->position.x;
    this->SystemPower.y = this->systemPowerPosition.y - sysPowerH + 10;

    ///*
    if(reactorLevel > 29) {
        std::stringstream reactorStream;
        if(unusedPower > 27) {
            CSurface::GL_SetColor(COLOR_GREEN);
            int overflow = unusedPower - 27;
            reactorStream << "+ " << overflow;
            freetype::easy_printCenter(62, 26, 48, reactorStream.str());
        } else {
            CSurface::GL_SetColor(COLOR_WHITE);
            reactorStream << "+";
            freetype::easy_printCenter(62, 26, 48, reactorStream.str());
        }
    }
    //*/

    if(!powerWarning->tracker.done)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(this->SystemPower.y - 74, 0);
        this->notEnoughPower->OnRender();
        CSurface::GL_PopMatrix();
    }
}//hook end
