#include "RenderReactorBar.h"
#include "SystemBox_Extend.h"
#include "InputManager.h"

static GL_Primitive *droneN = nullptr;
static int droneN_n = -1;

static GL_Texture* customWire = nullptr;
static GL_Primitive* customWire_connector = nullptr;
static GL_Primitive* customWire_connector_cap = nullptr;


const Point CUSTOM_WIRE_UI_OFFSET(31, 31);;

bool initTouchWires = false;
static GL_Primitive* touchWireReactor = nullptr;
static GL_Primitive* touchWireLeft = nullptr;
static GL_Primitive* touchWireRight = nullptr;
static GL_Primitive* touchWireNormal = nullptr;
static GL_Primitive* touchWireWeapons = nullptr;
static GL_Primitive* touchWireSubSysRight = nullptr;
static GL_Primitive* touchWireSubSysLeft = nullptr;
static GL_Primitive* touchWireSubSysNormal = nullptr;

HOOK_METHOD(SystemControl, OnInit, (Point position) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SystemControl::OnInit -> Begin (RenderReactorBar.cpp)\n")

    super(position);

    if (!initTouchWires)
    {
        touchWireReactor = G_->GetResources()->CreateImagePrimitiveString("ipad/wireUI/wire_left.png", 22, 306, 0, COLOR_WHITE, 1.f, false);
        touchWireLeft = G_->GetResources()->CreateImagePrimitiveString("ipad/wireUI/wire_left2.png", 69, 308, 0, COLOR_WHITE, 1.f, false);
        touchWireRight = G_->GetResources()->CreateImagePrimitiveString("ipad/wireUI/wire_right.png", 30, 47, 0, COLOR_WHITE, 1.f, false);
        touchWireNormal = G_->GetResources()->CreateImagePrimitiveString("ipad/wireUI/wire_56.png", 30, 47, 0, COLOR_WHITE, 1.f, false);
        touchWireWeapons = G_->GetResources()->CreateImagePrimitiveString("ipad/wireUI/wire_94.png", 30, 47, 0, COLOR_WHITE, 1.f, false);
        touchWireSubSysRight = G_->GetResources()->CreateImagePrimitiveString("ipad/wireUI/wire_left2.png", 30, 47, 0, COLOR_WHITE, 1.f, true);
        touchWireSubSysLeft = G_->GetResources()->CreateImagePrimitiveString("ipad/wireUI/wire_right.png", 24, 47, 0, COLOR_WHITE, 1.f, true);
        touchWireSubSysNormal = G_->GetResources()->CreateImagePrimitiveString("ipad/wireUI/wire_56.png", 30, 47, 0, COLOR_WHITE, 1.f, true);


        initTouchWires = true;
    }


    if (!customWire)
    {
        customWire = G_->GetResources()->GetImageId("wireUI/wire_custom.png");
    }
    if (!customWire_connector)
    {
        customWire_connector = G_->GetResources()->CreateImagePrimitiveString("wireUI/wire_custom_connector.png", CUSTOM_WIRE_UI_OFFSET.x, CUSTOM_WIRE_UI_OFFSET.y, 0, COLOR_WHITE, 1.f, false);
    }
    if (!customWire_connector_cap)
    {
        customWire_connector_cap = G_->GetResources()->CreateImagePrimitiveString("wireUI/wire_custom_connector_cap.png", CUSTOM_WIRE_UI_OFFSET.x, CUSTOM_WIRE_UI_OFFSET.y, 0, COLOR_WHITE, 1.f, false);
    }
}

HOOK_METHOD_PRIORITY(SystemControl, RenderPowerBar, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SystemControl::RenderPowerBar -> Begin (RenderReactorBar.cpp)\n")

    // Rewritten for wire rendering fixes and touch support

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


    if (G_->GetEventSystem()->PollEvent(11))
    {
        flashBatteryPower.Start(0);
        flashTracker.Start(0);
    }

    flashBatteryPower.Update();
    flashTracker.Update();
    if(flashBatteryPower.done) flashBatteryPower.Stop(false);


    // Wire rendering specific to current input mode
    if (InputManager::GetInstance()->currentInputDevice == InputManager::TOUCHSCREEN)
    {
        // Reactor wires rendering
        if (maxPower < 1) // Draw left edge variant from subsystems if reactor has no power bars (looks nicer I think)
        {
            CSurface::GL_RenderPrimitiveWithAlpha(touchWireLeft, greyOpacity);
        }
        else
        {
            if (unusedPower)
            {
                CSurface::GL_RenderPrimitive(touchWireReactor);
            }
            else
            {
                CSurface::GL_RenderPrimitiveWithAlpha(touchWireReactor, greyOpacity);
            }
        }


        uint8_t installedSubsystems = 0;
        for (SystemBox* box : this->sysBoxes)
        {
            std::string name = box->pSystem->name;
            if (name == "battery" || name == "doors" || name == "sensors" || name == "pilot")
            {
                if (this->shipManager->HasSystem(box->pSystem->GetId()))
                {
                    installedSubsystems++;
                }
            }
        }

        // System wires rendering
        uint8_t index = 0;
        for (SystemBox* box : this->sysBoxes)
        {
            index++;
            currentSys = box->pSystem;
            int currentSysId = box->pSystem->GetId();
            CSurface::GL_Translate(box->location.x, box->location.y);
            if (currentSysId == 3 || currentSysId == 4)
            {
                if (unusedPower)
                {
                    CSurface::GL_RenderPrimitive(touchWireWeapons);
                }
                else
                {
                    CSurface::GL_RenderPrimitiveWithAlpha(touchWireWeapons, greyOpacity);
                }
            }
            else
            {
                if (index == (sysBoxes.size() - installedSubsystems) + 1)
                {
                    CSurface::GL_RenderPrimitive(touchWireSubSysRight);
                }
                else if (index > (sysBoxes.size() - installedSubsystems) + 1 && index < sysBoxes.size())
                {
                    CSurface::GL_RenderPrimitive(touchWireSubSysNormal);
                }
                else if (index == sysBoxes.size())
                {
                    CSurface::GL_RenderPrimitive(touchWireSubSysLeft);
                }
                else if (index == (sysBoxes.size() - installedSubsystems))
                {
                    // Don't render if next system is a subsystem
                }
                else if (index == (sysBoxes.size() - installedSubsystems) - 1)
                {
                    if (unusedPower)
                    {
                        CSurface::GL_RenderPrimitive(touchWireRight);
                    }
                    else
                    {
                        CSurface::GL_RenderPrimitiveWithAlpha(touchWireRight, greyOpacity);
                    }
                }
                else
                {
                    if (unusedPower)
                    {
                        CSurface::GL_RenderPrimitive(touchWireNormal);
                    }
                    else
                    {
                        CSurface::GL_RenderPrimitiveWithAlpha(touchWireNormal, greyOpacity);
                    }
                }
            }
            CSurface::GL_Translate(-box->location.x, -box->location.y);
        }
    }
    else // Render PC version
    {
        // Reactor wires rendering
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

        if (unusedPower)
        {
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


        // System wires rendering
        if (sysBoxes.size() > 7)
        {
            while (1)
            {
                currentSys = sysBoxes[startsAtTwo - 1]->pSystem;

                if (currentSys->GetNeedsPower())
                {
                    currentSysBox = sysBoxes[startsAtTwo - 2];
                    sysBoxLocX = currentSysBox->location.x;
                    sysBoxLocY = currentSysBox->location.y;
                    CSurface::GL_Translate(sysBoxLocX, sysBoxLocY);

                    if (!true) // TODO: Change to touch check
                    {
                        int currentSysId = sysBoxes[startsAtTwo - 2]->pSystem->GetId();
                        if (currentSysId == 3 || currentSysId == 4)
                        {
                            if (unusedPower)
                            {
                                CSurface::GL_RenderPrimitive(touchWireWeapons);
                            }
                            else
                            {
                                CSurface::GL_RenderPrimitiveWithAlpha(touchWireWeapons, greyOpacity);
                            }
                        }
                        else
                        {
                            if (startsAtTwo < sysBoxes.size() - 4)
                            {
                                if (unusedPower)
                                {
                                    CSurface::GL_RenderPrimitive(touchWireNormal);
                                }
                                else
                                {
                                    CSurface::GL_RenderPrimitiveWithAlpha(touchWireNormal, greyOpacity);
                                }
                            }
                            else
                            {
                                if (unusedPower)
                                {
                                    CSurface::GL_RenderPrimitive(touchWireRight);
                                }
                                else
                                {
                                    CSurface::GL_RenderPrimitiveWithAlpha(touchWireRight, greyOpacity);
                                }
                            }
                        }
                    }
                    else
                    {
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

                        else if (currentSysBox->HasButton())
                        {
                            currentSys = sysBoxes[startsAtTwo]->pSystem;
                            if (sysBoxes.size() <= startsAtTwo || currentSys->GetNeedsPower())
                            {
                                CSurface::GL_RenderPrimitiveWithAlpha(button, greyOpacity);
                                if (unusedPower) CSurface::GL_RenderPrimitive(button);
                            }
                            else
                            {
                                CSurface::GL_RenderPrimitiveWithAlpha(button_cap, greyOpacity);
                                if (unusedPower) CSurface::GL_RenderPrimitive(button_cap);
                            }
                        }
                        else
                        {
                            currentSys = sysBoxes[startsAtTwo - 2]->pSystem;
                            sysID = currentSys->GetId();

                            // drone system wires
                            if (sysID == 3)
                            {
                                if (numWeaponSlots == 2) droneSysWireImage = drone2;
                                else if (numWeaponSlots == 3) droneSysWireImage = drone3;
                                else if (numWeaponSlots == 4) droneSysWireImage = drone;
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
                                if (unusedPower) CSurface::GL_RenderPrimitive(droneSysWireImage);
                            }
                            else
                            {
                                currentSys = sysBoxes[startsAtTwo]->pSystem;
                                if (sysBoxes.size() <= startsAtTwo || currentSys->GetNeedsPower())
                                {
                                    CSurface::GL_RenderPrimitiveWithAlpha(noButton, greyOpacity);
                                    if (unusedPower) CSurface::GL_RenderPrimitive(noButton);
                                }
                                else
                                {
                                    CSurface::GL_RenderPrimitiveWithAlpha(noButton_cap, greyOpacity);
                                    if (unusedPower) CSurface::GL_RenderPrimitive(noButton_cap);
                                }
                            }
                        } // hasButton else end
                    }
                    CSurface::GL_Translate(-sysBoxLocX, -sysBoxLocY, 0);
                } // needsPower if end
                startsAtTwo++;
                if (sysBoxes.size() <= startsAtTwo) break;
            } // while(1) end
        } // sysBoxes.size > 7 end
    }

    // reactor bars rendering
    if (!notEnoughPower->tracker.done)
    {
        bPowerWarningRunning = notEnoughPower->tracker.running;
        if (notEnoughPower->tracker.running && notEnoughPower->flash) bPowerWarningRunning = notEnoughPower->flashTracker.Progress(-1) < 0.5;
    }

    powerBars = SystemControl::GetPowerBars(28, 7, 2, false);
    CSurface::GL_PushMatrix();
    if (InputManager::GetInstance()->currentInputDevice == InputManager::TOUCHSCREEN)
    {
        CSurface::GL_Translate(systemPowerPosition.x + 4.f, systemPowerPosition.y - 5.f);
    }
    else
    {
        CSurface::GL_Translate(systemPowerPosition.x, systemPowerPosition.y);
    }

    if(maxPower > 0)
    {
        powerCounter = 0;
        [&]{
            while(1)
            {
                while(1)
                {
                    // battery bar boxes
                    if (powerCounter < batteryEffPower)
                    {
                        powerBarColour = powerBarColourOn;
                        if (flashBatteryPower.running && flashTracker.Progress(-1) > 0.5 && !colourBlindOn)
                        {
                            powerBarColour = COLOR_WHITE;
                        }

                        CSurface::GL_RenderPrimitiveWithColor(powerBars->tiny[powerCounter], powerBarColour);
                        CSurface::GL_RenderPrimitiveWithColor(powerBars->empty[powerCounter], borderColour);
                        powerCounter++;
                        if (maxPower == powerCounter)
                        {
                            sysPowerH = 9 * maxPower;
                            return;
                        }
                        else if (powerCounter == displayLevel)
                        {
                            sysPowerH = 9 * displayLevel;
                            return;
                        }
                        continue;
                    }

                    // blue bar boxes (nebula)
                    if (powerCounter < std::min((reactorLevel + playerPowerManager->batteryPower.second), displayLevel)) break;
                    CSurface::GL_RenderPrimitiveWithColor(powerBars->damaged[powerCounter], blueColour);
                    powerCounter++;
                    if (maxPower == powerCounter)
                    {
                        sysPowerH = 9 * maxPower;
                        return;
                    } 
                    else if (powerCounter == displayLevel)
                    {
                        sysPowerH = 9 * displayLevel;
                        return;
                    }
                } // inner while(1) end

                // power bar boxes
                if (unusedPower > powerCounter)
                {
                    if (bPowerWarningRunning)
                    {
                        CSurface::GL_RenderPrimitive(powerBars->normal[powerCounter]);
                    }
                    else
                    {
                        powerBarColour = powerBarColourOn;
                        CSurface::GL_RenderPrimitiveWithColor(powerBars->normal[powerCounter], powerBarColour);
                    }
                    powerCounter++;
                    if (maxPower == powerCounter)
                    {
                        sysPowerH = 9 * maxPower;
                        return;
                    }
                    else if (powerCounter == displayLevel)
                    {
                        sysPowerH = 9 * displayLevel;
                        return;
                    }
                    continue;
                }

                //empty bar boxes
                CSurface::GL_RenderPrimitive(powerBars->empty[powerCounter]);
                powerCounter++;
                if (maxPower == powerCounter)
                {
                    sysPowerH = 9 * maxPower;
                    return;
                }
                else if (powerCounter == displayLevel)
                {
                    sysPowerH = 9 * displayLevel;
                    return;
                }
            } // outer while(1) end
        }();
    } // if(maxPower > 0) end

    CSurface::GL_PopMatrix();

    if (maxPower > 29)
    {
        std::stringstream reactorStream;
        if (unusedPower > 27)
        {
            CSurface::GL_SetColor(COLOR_GREEN);
            int overflow = unusedPower - 27;
            reactorStream << "+" << overflow;
            freetype::easy_printCenter(62, 26, 48, reactorStream.str());
        }
        else
        {
            CSurface::GL_SetColor(COLOR_WHITE);
            reactorStream << "+";
            freetype::easy_printCenter(62, 26, 48, reactorStream.str());
        }
    }

    if(!notEnoughPower->tracker.done && notEnoughPower->tracker.running)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(74, 66);
        notEnoughPower->OnRender();
        CSurface::GL_PopMatrix();
    }
} // hook end
