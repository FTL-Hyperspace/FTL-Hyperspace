#include "InputManager.h"
#include "CustomOptions.h"
#include "SystemBox_Extend.h"
#include "ArmamentControl_Extend.h"
#include "MoreInfoButton.h"
#include "PauseButton.h"
#include <boost/algorithm/string/replace.hpp>

PauseButton* pauseButton;
GL_Primitive* pauseImageTouch;
HOOK_METHOD(CommandGui, OnInit, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::OnInit -> Begin (TouchScreen.cpp)\n")

    super();

    if (!pauseButton) pauseButton = new PauseButton("ipad/pause_large_base.png", "ipad/pause_large_top.png");
    GL_Texture* tempImage = G_->GetResources()->GetImageId("ipad/pause.png");
    if (!pauseImageTouch) pauseImageTouch = G_->GetResources()->CreateImagePrimitive(tempImage, 640 - tempImage->width_ / 2, 558-63 - tempImage->height_ / 2, 0, COLOR_WHITE, 1.f, false);

}

HOOK_METHOD(CommandGui, OnLanguageChange, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::OnLanguageChange -> Begin (TouchScreen.cpp)\n")

    super();

    if (pauseButton) pauseButton->OnLanguageChange();
    if (pauseImageTouch) delete pauseImageTouch;
    GL_Texture* tempImage = G_->GetResources()->GetImageId("ipad/pause.png");
    pauseImageTouch = G_->GetResources()->CreateImagePrimitive(tempImage, 640 - tempImage->width_ / 2, 558-63 - tempImage->height_ / 2, 0, COLOR_WHITE, 1.f, false);
}

void CommandGui::OnTouch(TouchAction action, int id, int x, int y, int initialX, int initialY)
{
    // Do some touch action cleanup
    bool wasActiveTouchNull = false;
    if (action == TOUCH_DOWN)
    {
        if (this->activeTouch != 0 && CEvent::IsTouchActive(this->activeTouch))
        {
            this->extraTouches.push_back(id);
            return;
        }
        this->extraTouches.clear();
        wasActiveTouchNull = false;
        this->activeTouchIsButton = false;
        this->activeTouchIsCrewBox = false;
        this->activeTouchIsShip = false;
        this->activeTouch = id;
    }
    else 
    {
        if (this->activeTouch != id)
        {
            if (action == TOUCH_MOVE)
            {
                return;
            }
            // Erase invalid touch action
            size_t extraTouchesAmount = this->extraTouches.size();
            if (extraTouchesAmount == 0)
            {
                return;
            }
            size_t loopIndex = 0;
            do {
                if (this->extraTouches[loopIndex] == id)
                {
                    this->extraTouches.erase(this->extraTouches.begin() + loopIndex);
                    break;
                }
                loopIndex += 1;
            } while (loopIndex < extraTouchesAmount);
            return;
        }
        if (action != TOUCH_MOVE)
        {
            this->extraTouches.clear();
            this->activeTouch = 0;
        }
        wasActiveTouchNull = this->activeTouchIsNull;
    }

    this->activeTouchIsNull = false;

    // I honestly have no idea what the error dialog even is
    if (this->writeErrorDialog.bOpen)
    {
        this->writeErrorDialog.OnTouch(action, id, x, y, initialX, initialY);
        return;
    }

    // This probably is the crew dismiss thing
    if (this->leaveCrewDialog.bOpen)
    {
        this->leaveCrewDialog.OnTouch(action, id, x, y, initialX, initialY);
        if (this->leaveCrewDialog.bOpen || !this->leaveCrewDialog.result)
        {
            return;
        }
        this->starMap->Open();
        return;
    }

    // Return if tutorial touch stuff is happening
    if (!this->menuBox.bOpen && G_->GetTutorialManager()->OnTouch(action, id, x, y, initialX, initialY))
    {
        return;
    }

    // Handle touch for all sorts of windows that derived from FocusWindow
    for (FocusWindow* window : this->focusWindows)
    {
        if (window && window->bOpen)
        {
            // VTable call because structs are messed up (also means I wont have to hook the individual functions!)
            void** vtable = *(void***)window;
            const int ON_TOUCH_INDEX = 13;
            using OnTouchFunction = void(*)(FocusWindow*, TouchAction, int, int, int, int, int);
            OnTouchFunction onTouchFunc = (OnTouchFunction)vtable[ON_TOUCH_INDEX];
            onTouchFunc(window, action, id, x, y, initialX, initialY);
            return;
        }
    }

    // Cancel handling if the player is jumping
    if (this->shipComplete->shipManager->bJumping)
    {
        this->activeTouch = 0;
        return;
    }

    // Handle individual buttons
    if (action == TOUCH_DOWN || this->activeTouchIsButton || wasActiveTouchNull)
    {
        this->activeTouchIsButton = this->ftlButton.OnTouch(action, id, x, y, initialX, initialY);
        this->activeTouchIsButton = this->activeTouchIsButton || this->upgradeButton.OnTouch(action, id, x, y, initialX, initialY);
        this->activeTouchIsButton = this->activeTouchIsButton || (this->storeButton.bActive ? this->storeButton.OnTouch(action, id, x, y, initialX, initialY) : false);
        this->activeTouchIsButton = this->activeTouchIsButton || this->optionsButton.OnTouch(action, id, x, y, initialX, initialY);
        this->activeTouchIsButton = this->activeTouchIsButton || this->crewControl.OnTouchButtons(action, id, x, y, initialX, initialY);
    }

    // Determine if touch is inside a room
    bool touchingNearShip = false;
    Point worldCoords = this->GetWorldCoordinates(Point(x, y), false);
    if (!this->sysControl.IsPointInTappedSystem(Point(x, y)))
    {
        const std::vector<Room*>& rooms = this->shipComplete->shipManager->ship.GetRoomListConst();
        Globals::Rect room;
        for (Room* roomPtr : rooms)
        {
            room = roomPtr->GetRect();
            room.y -= 40;
            room.x -= 40;
            room.w += 80;
            room.h += 80;

            if (room.Contains(worldCoords.x, worldCoords.y))
            {
                touchingNearShip = true;
                break;
            }
        }
    }

    // Determine if touching crew or ship
    bool isTouchInCrewBox = (action == TOUCH_DOWN || wasActiveTouchNull) ? this->crewControl.IsPointInCrewBoxes(x, y) : this->activeTouchIsCrewBox;
    this->activeTouchIsCrewBox = isTouchInCrewBox;
    this->activeTouchIsShip = touchingNearShip;
    if (isTouchInCrewBox && !this->activeTouchIsShip && touchingNearShip)
    {
        this->activeTouchIsShip = true;
        this->activeTouchIsCrewBox = false;
    }


    // Call individual handlers depending on what is being touched
    if (!this->activeTouchIsButton && !this->activeTouchIsShip)
    {
        if (!this->combatControl.OnTouch(action, id, x, y, initialX, initialY) && !this->activeTouchIsCrewBox)
        {
            // this->combatControl.ClearSelectedCrew(); // Moved
            this->combatControl.SetSelectedSelfRoom(-1);
            this->shipStatus.OnTouch(action, id, x, y, initialX, initialY);
            this->sysControl.OnTouch(action, id, x, y, initialX, initialY);
            this->spaceStatus.OnTouch(action, id, x, y, initialX, initialY);
            if (!this->sysControl.IsAnySystemTapped())
            {
                this->activeTouchIsNull = true;
            }
        }
        else if (wasActiveTouchNull && action != TOUCH_DOWN)
        {
            this->crewControl.OnTouch(TOUCH_DOWN, id, x, y, worldCoords.x, worldCoords.y, initialX, initialY, true);
        }
        this->crewControl.OnTouch(action, id, x, y, worldCoords.x, worldCoords.y, initialX, initialY, true);
    }
    else if (this->activeTouchIsShip)
    {
        bool allowCrewSelection = !this->combatControl.WeaponsArmed();
        if (!allowCrewSelection && !this->sysControl.IsSystemTapped(SYS_DOORS))
        {
            if (!this->combatControl.OnTouch(action, id, x, y, initialX, initialY))
            {
                if (wasActiveTouchNull && action != TOUCH_DOWN)
                {
                    this->crewControl.OnTouch(TOUCH_DOWN, id, x, y, worldCoords.x, worldCoords.y, initialX, initialY, true);
                }
                this->crewControl.OnTouch(action, id, x, y, worldCoords.x, worldCoords.y, initialX, initialY, true);
            }
        }
        else
        {
            this->crewControl.OnTouch(action, id, x, y, worldCoords.x, worldCoords.y, initialX, initialY, allowCrewSelection);
        }
    }

    // Allow door control if the door system was tapped
    this->crewControl.doorControlMode = this->sysControl.IsSystemTapped(SYS_DOORS);
    
    // Open upgrade/storage menu
    if (this->upgradeButton.bActivated && !this->shipScreens.bOpen && this->upgradeButton.hitbox.Contains(x, y))
    {
        this->sysControl.CloseAll();
        this->shipScreens.Open();
        this->upgradeButton.bActivated = false;
        return;
    }

    // Open store menu
    if (this->storeButton.bActivated && this->storeButton.hitbox.Contains(x, y))
    {
        this->sysControl.CloseAll();
        if (this->storeScreens.GetWindow(0))
        {
            this->storeScreens.Open();
            this->storeButton.bActivated = false;
            return;
        }
    }

    // Open options menu
    if (this->optionsButton.bActivated && !this->menuBox.bOpen && this->optionsButton.hitbox.Contains(x, y))
    {
        this->sysControl.CloseAll();
        this->menuBox.Open();
        this->optionsButton.bActivated = false;
        return;
    }

    // Open starMap
    if (this->ftlButton.bActivated && this->ftlButton.hitbox.Contains(x, y) && this->shipComplete->shipManager->jump_timer.first >= this->shipComplete->shipManager->jump_timer.second)
    {
        this->sysControl.CloseAll();
        if (this->enemyShip && this->enemyShip->shipManager->CountPlayerCrew() > 0)
        {
            this->leaveCrewDialog.Open();
            return;
        }
        this->starMap->Open();
    }

    // CUSTOM: Handle pause button
    if (pauseButton->OnTouch(action, id, x, y, initialX, initialY))
    {
        // inline: this->SetPaused(!this->bPaused, false);
        this->bPaused = !this->bPaused;
        *TutorialManager_Tutorial_bGamePaused = this->bPaused;
        this->bAutoPaused = false;
        return;
    }
}


///                                                                                  ///
/// Those two hooks fix hovering animations, dragging, selecting and far more things ///
///  The function mess up global position values which are essential for some logic  ///
///                                                                                  ///
HOOK_METHOD_PRIORITY(MainMenu, MouseMove, -1000, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> MainMenu::MouseMove -> Begin (TouchScreen.cpp)\n")
    InputManager* inputManager = InputManager::GetInstance();
    if (inputManager->currentInputDevice == InputManager::KEYBOARD || inputManager->currentInputDevice == InputManager::DEBUG)
    {
        super(mX, mY);
    }
}
HOOK_METHOD_PRIORITY(CommandGui, MouseMove, -1000, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CommandGui::MouseMove -> Begin (TouchScreen.cpp)\n")
    InputManager* inputManager = InputManager::GetInstance();
    if (inputManager->currentInputDevice == InputManager::KEYBOARD || inputManager->currentInputDevice == InputManager::DEBUG)
    {
        super(mX, mY);
    }
}

// Redefined because that value was only required for that function
static bool RenderStatic_fullFocus = false;
HOOK_METHOD_PRIORITY(CommandGui, RenderStatic, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CommandGui::RenderStatic -> Begin (TouchScreen.cpp)\n")
    
    InputManager* inputManager = InputManager::GetInstance();
    
    // Apply a color tint if full focus is active
    if (RenderStatic_fullFocus)
    {
        CSurface::GL_SetColorTint(GL_Color(0.15f, 0.15f, 0.15f, 1.f));
    }

    // Set some in-game states
    int hullIntegrityCurrent = this->shipComplete->shipManager->ship.hullIntegrity.first;
    int hullIntegrityMax = this->shipComplete->shipManager->ship.hullIntegrity.second;
    this->space->gamePaused = this->bPaused;
    this->space->shipHealth = static_cast<float>(hullIntegrityCurrent) / static_cast<float>(hullIntegrityMax);

    // Limit jump animation progress to 1.f
    float jumpAnimProgress = this->shipComplete->shipManager->jumpAnimation.Progress(-1.f);
    jumpAnimProgress += jumpAnimProgress;
    if (jumpAnimProgress > 0.5f)
    {
        jumpAnimProgress = 1.f;
    }
    else
    {
        jumpAnimProgress += jumpAnimProgress;
    }

    // Get ship information and calculate positions
    ShipGraph* shipGraph = ShipGraph::GetShipInfo(0);
    int16_t shipImageWidth = this->shipComplete->shipManager->ship.shipImage.w;
    int16_t shipImageHeight = this->shipComplete->shipManager->ship.shipImage.h;
    int16_t shipImageX = this->shipComplete->shipManager->ship.shipImage.x;
    int16_t shipImageY = this->shipComplete->shipManager->ship.shipImage.y;

    // Calculate ship image position
    Point shipCenter = Point((this->shipPosition.x + shipImageX + shipGraph->shipBox.x) + shipImageWidth / 2, (this->shipPosition.y + shipImageY + shipGraph->shipBox.y) + shipImageHeight / 2);

    // Render background
    this->space->OnRenderBackground();

    // Render foreground with scaling
    float scaleFactor = 1.f - jumpAnimProgress * 0.05f;
    if (scaleFactor == 1.f)
    {
        this->space->OnRenderForeground();
    }
    else
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(shipCenter.x, shipCenter.y);
        CSurface::GL_Scale(scaleFactor, scaleFactor);
        CSurface::GL_Translate(-shipCenter.x, -shipCenter.y);
        this->space->OnRenderForeground();
        CSurface::GL_PopMatrix();
    }

    // Render asteroids with scaling
    scaleFactor = 1.f - jumpAnimProgress * 0.3f;
    if (scaleFactor == 1.f)
    {
        this->space->OnRenderAsteroids(3, 1.f);
    }
    else
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(shipCenter.x, shipCenter.y);
        CSurface::GL_Scale(scaleFactor, scaleFactor);
        CSurface::GL_Translate(-shipCenter.x, -shipCenter.y);
        this->space->OnRenderAsteroids(3, 1.f);
        CSurface::GL_PopMatrix();
    }

    // Render player ship
    this->RenderPlayerShip(shipCenter, 1.f - jumpAnimProgress * 0.75f);

    // Render asteroids with additional scaling
    if (jumpAnimProgress > 0.f)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(shipCenter.x, shipCenter.y);
        CSurface::GL_Scale(scaleFactor, scaleFactor);
        CSurface::GL_Translate(-shipCenter.x, -shipCenter.y);
        this->space->OnRenderAsteroids(1, jumpAnimProgress);
        CSurface::GL_PopMatrix();
    }


    // Render UI elements if the UI is not hidden
    if (!this->bHideUI)
    {
        // Update screen shake effect
        Pointf shakeEffect = this->UpdateShake();

        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(shakeEffect.x, shakeEffect.y);

        // Render buttons and warnings
        this->ftlButton.OnRender();
        this->upgradeButton.OnRender();
        this->upgradeWarning.OnRender();

        if (this->storeButton.bActive)
        {
            this->storeButton.OnRender();
        }

        this->optionsButton.OnRender();

        // Touchscreen pause button
        if (inputManager->currentInputDevice == InputManager::TOUCHSCREEN)
        {
            pauseButton->OnRender((this->bPaused || this->bAutoPaused || this->menu_pause || this->event_pause || this->touch_pause));
        }

        // Render combat control if the ship is not destroyed
        if (!this->shipComplete->shipManager->bJumping)
        {
            this->combatControl.OnRenderCombat();
        }

        // Render crew and system controls
        this->crewControl.OnRender();
        bool isSystemTapped = this->sysControl.IsAnySystemTapped();
        if (isSystemTapped)
        {
            GL_Color tintColor = CSurface::GetColorTint();
            tintColor.r = tintColor.r * 0.75f;
            tintColor.g = tintColor.g * 0.75f;
            tintColor.b = tintColor.b * 0.75f;
            CSurface::GL_SetColorTint(tintColor);
            CSurface::GL_EnableBlend();
        }
        
        // Adjusted the render order for touch
        if (inputManager->currentInputDevice != InputManager::TOUCHSCREEN)
            {
            this->sysControl.OnRender(false);
            this->combatControl.OnRenderInterface(false);
        }
        else
        {
            this->combatControl.OnRenderInterface(false);
            this->sysControl.OnRender(false);
        }
        
        if (isSystemTapped)
        {
            CSurface::GL_RemoveColorTint();
        }

        // Render pause menu and status
        if (!this->touch_pause || this->touchPauseReason == TOUCH_PAUSE_DOORS)
        {
            this->RenderPause();
            this->spaceStatus.OnRender();
            // Adjusted the render order for touch
            if (inputManager->currentInputDevice != InputManager::TOUCHSCREEN)
            {
                this->sysControl.OnRender(true);
                this->combatControl.OnRenderInterface(true);
            }
            else
            {
                this->sysControl.OnRender(true);
            }
            CSurface::GL_PopMatrix();
        }
        else
        {
            this->spaceStatus.OnRender();
            // Adjusted the render order for touch
            if (inputManager->currentInputDevice != InputManager::TOUCHSCREEN)
            {
                this->sysControl.OnRender(true);
                this->combatControl.OnRenderInterface(true);
            }
            else
            {
                this->sysControl.OnRender(true);
            }
            CSurface::GL_PopMatrix();
            this->RenderPause();
        }

        // Remove color tint if no special windows are open
        if (!this->gameOverScreen.bOpen && !this->menuBox.bOpen && !this->leaveCrewDialog.bOpen && !this->optionsBox.bOpen)
        {
            CSurface::GL_RemoveColorTint();
        }

        // Render ship status and flare effects
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(shakeEffect.x, shakeEffect.y);
        this->shipStatus.OnRender();

        float flashOpacity = this->space->GetFlashOpacity();
        if (flashOpacity > 0.f)
        {
            GL_Color flareColor;
            if (!this->space->pulsarLevel)
            {
                flareColor.r = 248.f / 255;
                flareColor.g = 142.5f / 255;
                flareColor.b = 33.f / 255;
            }
            else
            {
                // Color value of COLOR_BLUE_ION
                flareColor.r = 133.f / 255;
                flareColor.g = 231.f / 255;
                flareColor.b = 237.f / 255;
            }
            flareColor.a = flashOpacity;

            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(-360.f, -640.f);
            CSurface::GL_Scale(4.f, 4.f);
            CSurface::GL_RenderPrimitiveWithColor(this->flareImage, flareColor);
            CSurface::GL_PopMatrix();
        }

        CSurface::GL_PopMatrix();
        CSurface::GL_RemoveColorTint();

        // Render focusWindow-based objects
        RenderStatic_fullFocus = false;
        if (!this->focusWindows.empty()) // Check if the vector is not empty
        {
            MouseControl* mouse = G_->GetMouseControl();
            for (FocusWindow* iFocusWindow : this->focusWindows) // Range-based for loop
            {
                if (this->shipComplete->shipManager->bJumping)
                {
                    break; // Abort rendering if the ship is jumping
                }

                if (iFocusWindow && iFocusWindow->bOpen) // Check if the window is valid and open
                {
                    mouse->ResetArmed(); // Reset the mouse state
                    RenderStatic_fullFocus = iFocusWindow->bFullFocus; // Update focus state

                    // Manually accessing the vtable because the structs are messed up (Hooray!)
                    void** vtable = *(void***)iFocusWindow; // Pointer into the vtable
                    const int ON_RENDER_INDEX = 8; // Index of the OnRender method in the vtable
                    using OnRenderFunction = void(*)(FocusWindow*); // Typedef for the function
                    OnRenderFunction onRenderFunc = (OnRenderFunction)vtable[ON_RENDER_INDEX]; // Pull the function out of the vtable
                    onRenderFunc(iFocusWindow); // Call vtable-specific OnRender

                    // iFocusWindow->OnRender(); // Not possible because structs are messed up and virtual functions can't be used

                    break; // Exit the loop after rendering the first valid window
                }
            }
        }

        // Render the confirmation window for leaving the crew
        if (this->leaveCrewDialog.bOpen)
        {
            RenderStatic_fullFocus = true;
            this->leaveCrewDialog.OnRender();
        }

        // Render the tutorial if no special windows are open
        if (!this->choiceBox.bOpen && !this->shipComplete->shipManager->bJumping && !this->menuBox.bOpen && !this->optionsBox.bOpen && !this->gameOverScreen.bOpen)
        {
            G_->GetTutorialManager()->OnRender();
        }

        // Render the error dialog
        if (this->writeErrorDialog.bOpen)
        {
            RenderStatic_fullFocus = true;
            this->writeErrorDialog.OnRender();
        }
    }
}

// Redefined because that value was only required for that function
static float RenderPause_dx = 1.f;
void CommandGui::RenderPause()
{
    // Check if the game is paused via different methods (keyboard, menu, touch)
    if (!this->bPaused && !this->menu_pause && !this->touch_pause)
    {
        return; // If not paused, exit the function
    }

    InputManager* inputManager = InputManager::GetInstance();

    // Set the default pause message
    std::string pauseMessage;
    
    // Check if a keyboard is present
    if ((inputManager->currentInputDevice != InputManager::TOUCHSCREEN) && (inputManager->currentInputDevice != InputManager::CONTROLLER))
    {
        // Retrieve the localized "paused" text and the hotkey for pausing
        pauseMessage = "Pause";
        std::string pausedText = G_->GetTextLibrary()->GetText("paused_text", G_->GetTextLibrary()->currentLanguage);
        std::string hotkey = Settings::GetHotkeyName("pause");

        // Replace the placeholder "\\1" in the text with the actual hotkey
        boost::replace_all(pausedText, "\\1", hotkey);
        pauseMessage = pausedText; // Update the pause message with the modified text
    }
    /*
    if (CEvent::IsKeyboardPresent())
    {
        // Retrieve the localized "paused" text and the hotkey for pausing
        pauseMessage = "Pause";
        std::string pausedText = G_->GetTextLibrary()->GetText("paused_text", G_->GetTextLibrary()->currentLanguage);
        std::string hotkey = Settings::GetHotkeyName("pause");

        // Replace the placeholder "\\1" in the text with the actual hotkey
        boost::replace_all(pausedText, "\\1", hotkey);
        pauseMessage = pausedText; // Update the pause message with the modified text
    }
    */

    // Initialize variables for rendering
    float animationFactor = (this->pause_animation * 0.3f) / this->pause_anim_time + 0.6f;

    // Handle touch pause rendering
    GL_Primitive* pauseReasonPrimitive = nullptr;
    if (this->touch_pause)
    {
        switch (this->touchPauseReason)
        {
            case TOUCH_PAUSE_CREW_SELECT:
                pauseReasonPrimitive = this->pauseCrewImage;
                break;
            case TOUCH_PAUSE_CREW_MOVE:
                pauseReasonPrimitive = this->pauseRoomImage;
                break;
            case TOUCH_PAUSE_DOORS:
                pauseReasonPrimitive = this->pauseDoorsImage;
                break;
            case TOUCH_PAUSE_HACKING:
                pauseReasonPrimitive = this->pauseHackingImage;
                break;
            case TOUCH_PAUSE_MIND:
                pauseReasonPrimitive = this->pauseMindImage;
                break;
            case TOUCH_PAUSE_TARGETING:
                if (this->combatControl.weapControl.armedWeapon || this->combatControl.weapControl.armedWeapon->blueprint->type != 2)
                {
                    pauseReasonPrimitive = this->pauseTargetImage;
                }
                else
                {
                    pauseReasonPrimitive = this->pauseTargetBeamImage;
                }
                break;
            case TOUCH_PAUSE_TELEPORT_ARRIVE:
                pauseReasonPrimitive = this->pauseTeleportArriveImage;
                break;
            case TOUCH_PAUSE_TELEPORT_LEAVE:
                pauseReasonPrimitive = this->pauseTeleportLeaveImage;
                break;
            case TOUCH_PAUSE_TEMPORAL:
            case TOUCH_PAUSE_OVERCLOCKER:
            default:
                pauseReasonPrimitive = this->pauseHackingImage; // Placeholder image for now
        }
    }

    GL_Color touchFlashColor = GL_Color(animationFactor, animationFactor, animationFactor, 1.0f);

    // Render pause images based on the pause state
    if (this->bPaused || this->menu_pause)
    {
        if (inputManager->currentInputDevice == InputManager::TOUCHSCREEN)
        {
            if (!this->bAutoPaused)
            {
                CSurface::GL_RenderPrimitiveWithColor(pauseImageTouch, touchFlashColor);
            }
            else
            {
                CSurface::GL_Translate(0.f, -63.f);
                CSurface::GL_RenderPrimitiveWithColor(this->pauseImageAuto, touchFlashColor);
                CSurface::GL_Translate(0.f, 63.f);
            }
        }
        else
        {
            float alpha = 1.0f;
            if (!this->pauseImage2)
            {
                alpha = animationFactor;
            }

            if (!this->bAutoPaused)
            {
                CSurface::GL_RenderPrimitiveWithAlpha(this->pauseImage, alpha);
                if (this->pauseImage2)
                {
                    CSurface::GL_RenderPrimitiveWithAlpha(this->pauseImage2, this->pause_animation / this->pause_anim_time);
                }
            }
            else
            {
                CSurface::GL_RenderPrimitiveWithAlpha(this->pauseImageAuto, alpha);
            }
        }
    }

    // Render the selected primitive with color
    if (pauseReasonPrimitive)
    {
        CSurface::GL_RenderPrimitiveWithColor(pauseReasonPrimitive, touchFlashColor);
    }

    // Render pause text if it's valid + if input device matches
    if ((pauseMessage.length() > 0) && (inputManager->currentInputDevice != InputManager::TOUCHSCREEN) && (inputManager->currentInputDevice != InputManager::CONTROLLER))
    {
        GL_Color textColor = GL_Color(1.f, 1.f, 1.f, animationFactor);
        CSurface::GL_SetColor(textColor);
        freetype::easy_printNewlinesCentered(5, this->pauseTextLoc.x, this->pauseTextLoc.y, 0x500, pauseMessage);
        CSurface::GL_SetColor(COLOR_WHITE);
    }


    // Update pause animation
    float delta = RenderPause_dx * 0.0625f;
    float speedFactor = G_->GetCFPS()->GetSpeedFactor();
    this->pause_animation += speedFactor * delta;
    // Handle animation bounds
    if (this->pause_animation > this->pause_anim_time)
    {
        RenderPause_dx = -1.f;
        this->pause_animation = 2.f * this->pause_anim_time - this->pause_animation;
    }
    else if (this->pause_animation < 0.f)
    {
        RenderPause_dx = 1.f;
        this->pause_animation = -this->pause_animation;
    }
}

HOOK_METHOD_PRIORITY(CrewControl, ClearSelectedCrew, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewControl::ClearSelectedCrew -> Begin (TouchScreen.cpp)\n")
    
    for (CrewMember* crew : this->selectedCrew)
    {
        crew->selectionState = 0;
    }
    this->selectedCrew.clear();
    
    for (CrewMember* crew : this->potentialSelectedCrew)
    {
        crew->selectionState = 0;
    }
    this->potentialSelectedCrew.clear();
    
    this->selectedCrewBox = -1;
}

///                                                            ///
/// Reimplemented (scratch) to fix some behavior bugs and also ///
///  to allow for tile-based movement and moving crew drones   ///
///                                                            ///
HOOK_METHOD_PRIORITY(CrewControl, OnTouch, 9999, (TouchAction action, int id, int x, int y, int wX, int wY, int initialX, int initialY, bool allowCrewSelection) -> void)
{
    uint uVar8;
    uint uVar16;
    int local_6c;
    ShipManager *ownShip;
    ShipManager *targetShip;
    ShipManager* targetedShip;
    

    Globals::Rect rect;
    std::vector<CrewMember*> pvVar6;

        
    ShipManager* touchedShip;
    int16_t roomId;
    if (action == TOUCH_DOWN)
    {
        if (this->activeTouch != 0 && CEvent::IsTouchActive(this->activeTouch)) return;
        this->activeTouch = id;
    }
    else
    {
        if (this->activeTouch != id) return;
    }

    this->currentMouse = Point(x, y);
    this->worldCurrentMouse = Point(wX, wY);




    /*
    if (action == TOUCH_DOWN)
    {
        if ((this->activeTouch != 0) && CEvent::IsTouchActive(this->activeTouch)) return;
        this->activeTouch = id;
    }
    else
    {
        if (this->activeTouch != id) return;
        
        if (action != TOUCH_MOVE)
        {
            this->activeTouch = 0;
            if (action == TOUCH_CANCEL)
            {
                this->selectingCrew = false;
                this->selectedRoom = -1;
                return;
            }
        }
    }
    */

    if (this->doorControlMode && this->shipManager->DoorsFunction())
    {
        if (action == TOUCH_DOWN)
        {
            this->doorControlOpenSet = false;
        }

        Door* door = this->shipManager->ship.GetSelectedDoor(wX, wY, 2.f);
        if (door && (!door->lockedDown.running || door->iHacked == 0))
        {
            if (!this->doorControlOpenSet)
            {
                this->doorControlOpen = !door->bOpen && !door->forcedOpen.running;
                this->doorControlOpenSet = true;
            }

            if (this->doorControlOpen)
            {
                door->Open();
            }
            else
            {
                door->Close();
            }
        }

        return;
    }

    const std::vector<Room*>& rooms = this->shipManager->ship.GetRoomListConst();
    size_t index = 0;
    size_t size = rooms.size();
    if (size != 0)
    {
        do {
            Globals::Rect room = rooms[index]->GetRect();
            room.x -= 40;
            room.y -= 40;
            room.w += 80;
            room.h += 80;

            if (room.Contains(wX, wY))
            {
                this->selectingCrew = true;
            }

            index += 1;
        } while (index < size);
    }

    if (this->selectingCrew && this->selectedCrew.empty())
    {
        // Code for selecting the crew to be moved //

        /*
        if (!this->selectingCrewOnPlayerShip)
        {
            CrewMember* crewMember = this->combatControl->GetSelectedCrew(x, y);
        }
        else
        {
            CrewMember* crewMember = this->shipManager->GetSelectedCrewPoint(wX,wY,false);
        }
        */
        CrewMember* crew = this->shipManager->GetSelectedCrewPoint(wX,wY,false);
        
        if (crew && crew->GetControllable())
        {
            bool isTeleporting = crew->crewAnim->status == 6;
            bool isAnimationReversed = crew->crewAnim->anims[0][6].tracker.reverse;

            if (!isTeleporting || !isAnimationReversed)
            {
                std::vector<CrewMember*>& potentialCrew = this->potentialSelectedCrew;
                bool isAlreadyInList = std::find(potentialCrew.begin(), potentialCrew.end(), crew) != potentialCrew.end();

                if (!isAlreadyInList)
                {
                    crew->SetSelectedState(2);
                    potentialCrew.emplace_back(crew);
                }
            }
        }
    }
    else
    {
        if (!pauseButton->hitbox.Contains(x, y))
        {
            if (this->selectedCrew.empty() || this->selectingCrewOnPlayerShip)
            {
                this->selectedRoom = this->shipManager->GetSelectedRoom(wX, wY, true);
                this->selectedPlayerShip = true;

                if (this->selectedRoom == -1) goto TouchingEnemyShip1;
                
                if (action != TOUCH_UP)
                {
                    this->combatControl->SetSelectedSelfRoom(this->selectedRoom);
                }
            TouchingOwnShip1:
                touchedShip = this->shipManager;
            }
            else
            {
                this->selectedRoom = -1;
                this->selectedPlayerShip = true;

            TouchingEnemyShip1:
                this->combatControl->SetSelectedSelfRoom(-1);

                bool selectedOwn = this->selectingCrewOnPlayerShip;
                if (this->selectedCrew.empty() || !selectedOwn)
                {
                    this->selectedRoom = this->combatControl->SelectRoom(x, y);
                    selectedOwn = this->selectedRoom == -1; // -1 on an enemy ship probably means it's from the player or something like that
                }
                else
                {
                    this->selectedRoom = -1;
                }
                this->selectedPlayerShip = selectedOwn;

                if (selectedOwn) goto TouchingOwnShip1;

                touchedShip = this->combatControl->GetCurrentTarget();
            }

            this->shipManager->SetSelectedRoom(-1);

            if ((action == TOUCH_DOWN || action == TOUCH_MOVE) && (this->combatControl->WeaponsArmed() || !this->selectedCrew.empty()) && (!this->combatControl->WeaponsArmed() || !this->selectedPlayerShip || this->combatControl->CanTargetSelf()))
            {
                touchedShip->SetSelectedRoom(this->selectedRoom);
            }

            if (action == TOUCH_UP && touchedShip && this->selectedRoom != -1)
            {
                if (CustomOptionsManager::GetInstance()->alternateCrewMovement.currentValue)
                {
                    Room* room = touchedShip->ship.vRoomList.at(selectedRoom);
                    int tile = ((wX - room->rect.x) / 35 + (room->rect.w / 35) * ((wY - room->rect.y) / 35) );
                    if (tile < 0 || tile >= (room->rect.w / 35)*(room->rect.h / 35))
                    {
                        goto MoveNormally;
                    }

                    // Find the crewmember currently in this slot
                    bool occupiedSlot = room->slots[touchedShip->iShipId][tile];
                    CrewMember *swapCrew = nullptr;
                    if (occupiedSlot)
                    {
                        for (CrewMember *crew : touchedShip->vCrewList)
                        {
                            if (crew->currentSlot.roomId == selectedRoom && crew->currentSlot.slotId == tile && crew->intruder == touchedShip->iShipId)
                            {
                                swapCrew = crew;
                                break;
                            }
                        }
                    }

                    bool roomIsFull = room->Full(touchedShip->iShipId);
                    bool tileAvailable = !occupiedSlot;
                    if (swapCrew != nullptr) tileAvailable = swapCrew->GetControllable() && swapCrew->Functional() && (swapCrew->fStunTime <= 0.f || !swapCrew->AtFinalGoal()) && swapCrew->crewAnim->status != 3;

                    // Check that slot is either empty or has a crew that can swap
                    if (tileAvailable)
                    {
                        for (CrewMember *crew : selectedCrew)
                        {
                            if (touchedShip->iShipId == crew->currentShipId && crew->GetControllable() && crew->Functional() && (crew->fStunTime <= 0.f || !crew->AtFinalGoal()) && crew->crewAnim->status != 3)
                            {
                                if (swapCrew == nullptr)
                                {
                                    // Destination slot is empty
                                    bool moved = crew->MoveToRoom(selectedRoom, tile, true);
                                    if (!moved) goto MoveNormally;
                                }
                                else if (swapCrew != crew)
                                {
                                    if (crew->currentSlot.roomId == selectedRoom)
                                    {
                                        // Destination slot is occupied but the selected crewmember is in the same room to swap places
                                        int oldTile = crew->currentSlot.slotId;
                                        swapCrew->EmptySlot();
                                        bool moved = crew->MoveToRoom(selectedRoom, tile, true);
                                        swapCrew->MoveToRoom(selectedRoom, oldTile, true);
                                        if (!moved) goto MoveNormally;
                                    }
                                    else if (!roomIsFull)
                                    {
                                        // Destination slot is occupied but there's another empty slot
                                        bool moved = swapCrew->MoveToRoom(selectedRoom, -1, true);
                                        if (moved) moved = crew->MoveToRoom(selectedRoom, tile, true);
                                        if (!moved) goto MoveNormally;
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                MoveNormally:
                    for (CrewMember* crew : this->selectedCrew)
                    {
                        touchedShip->CommandCrewMoveRoom(crew, this->selectedRoom);
                    }
                }
                
                this->selectedRoom = -1;
                this->selectedCrewBox = -1;
                this->ClearSelectedCrew();
            }
        }
    }
    hs_log_file("Touched room: %d on %s\n", this->selectedRoom, (touchedShip == this->shipManager) ? "Player ship" : "Enemy ship");



    if (action == TOUCH_DOWN && !this->selectingCrew)
    {
        if (!pauseButton->hitbox.Contains(x, y))
        {
            this->ClearSelectedCrew();
        }
        return;
    }

    if (action == TOUCH_UP || action == TOUCH_CANCEL)
    {
        this->selectingCrew = false;
        if (!potentialSelectedCrew.empty())
        {
            for (CrewMember* crew : potentialSelectedCrew)
            {
                crew->SetSelectedState(1);
            }
            this->selectedCrew = potentialSelectedCrew;
            potentialSelectedCrew.clear();
        }
    }


    return;














    if (this->selectedCrew.empty() || this->selectingCrewOnPlayerShip)
    {
        this->selectedRoom = this->shipManager->GetSelectedRoom(wX, wY, true);
        this->selectedPlayerShip = true;

        if (this->selectedRoom == -1) goto TouchingEnemyShip;
        
        if (action != TOUCH_UP)
        {
            this->combatControl->SetSelectedSelfRoom(this->selectedRoom);
        }
    TouchingOwnShip:
        ownShip = this->shipManager;
        targetShip = ownShip;
    }
    else
    {
        this->selectedRoom = -1;
        this->selectedPlayerShip = true;

    TouchingEnemyShip:
        this->combatControl->SetSelectedSelfRoom(-1);

        bool selectedOwn = this->selectingCrewOnPlayerShip;
        if (this->selectedCrew.empty() || !selectedOwn)
        {
            this->selectedRoom = this->combatControl->SelectRoom(x, y);
            selectedOwn = this->selectedRoom == -1; // -1 on an enemy ship probably means it's from the player or something like that
        }
        else
        {
            this->selectedRoom = -1;
        }
        this->selectedPlayerShip = selectedOwn;

        if (selectedOwn) goto TouchingOwnShip;

        targetShip = this->combatControl->GetCurrentTarget();
        ownShip = this->shipManager;
    }

    ownShip->SetSelectedRoom(-1);
    
    if (((action - TOUCH_DOWN < 2) && (this->combatControl->WeaponsArmed() || !this->selectedCrew.empty())) && (!this->combatControl->WeaponsArmed() || !this->selectedPlayerShip || this->combatControl->CanTargetSelf()))
    {
        targetShip->SetSelectedRoom(this->selectedRoom);
    }
    if (!allowCrewSelection) return;

    if (!this->selectedCrew.empty())
    {
        if (action != TOUCH_UP) return;

        size_t size = this->selectedCrew.size();
        if ((this->selectedRoom != -1) && (size != 0))
        {
            size_t index = 0;
            do {
                if (this->selectedCrew[index]->currentShipId == targetShip->iShipId)
                {
                    targetShip->CommandCrewMoveRoom(this->selectedCrew[index],this->selectedRoom);
                }
                index += 1;
            } while (index < size);
        }
        this->selectedRoom = -1;
        this->selectedCrew.clear();
        this->selectedCrewBox = -1;
        return;
    }
    this->selectedCrewBox = -1;

    // if (action != TOUCH_DOWN) goto LAB_0050d334;
    
    // this->potentialSelectedCrew.clear();
    this->selectingCrew = true;
    this->selectingCrewStartTime = time_now();

    //rect = this->shipManager->GetShape();

    targetedShip = this->combatControl->GetCurrentTarget();
    if (targetedShip == nullptr || (wX <= rect.x + rect.w + 40))
    {
        targetedShip = this->shipManager;
        this->selectingCrewOnPlayerShip = true;
    }
    else
    {
        this->selectingCrewOnPlayerShip = false;
    }
    
    uVar16 = 0;
    pvVar6 = targetedShip->GetCrewList();
    local_6c = 0;
    
    if (pvVar6.size() == 0)
    {
    LAB_0050d5e8:
        if (!this->selectingCrewOnPlayerShip)
        {
        LAB_0050d5f2:
            ftl_log("No friendly crew on selected ship, cancelling crew selection\n");
            this->selectingCrew = false;
            this->activeTouch = 0;
            return;
        }

        if (this->crewBoxes[0]->GetBottomRight().x + 40 < x) goto LAB_0050d5f2;
        if (this->crewBoxes[0]->GetTopLeft().y - 40 > y)  goto LAB_0050d5f2;
        if (this->crewBoxes[this->crewBoxes.size() - 1]->GetBottomRight().y + 40 < y) goto LAB_0050d5f2;

        this->selectingCrewOnPlayerShip = false;
    }
    else
    {
        size_t index;
        do {
            CrewMember* crewMember = pvVar6[index];
            if ((crewMember->GetIntruder() == !this->selectingCrewOnPlayerShip) && !crewMember->IsDead() && !crewMember->IsDrone())
            {
                uVar8 = 1;
                if (crewMember->crewAnim->status == 6)
                {
                    uVar8 = crewMember->crewAnim->anims[0][6].tracker.reverse ? 1 : 0;
                }
            }
            else
            {
                // Begin: inline bool TeleportLeaving(CrewMember * this) Begin: inline bool TeleportLeaving(CrewAnimation * this) 
                uVar8 = 0;
            }
            local_6c = local_6c + uVar8;
            index += 1;
        } while (index < pvVar6.size());

        if (local_6c == 0) goto LAB_0050d5e8;
    }


    LAB_0050d334:
    if (this->crewBoxes.size() != 0)
    {
        size_t index = 0;
        do {
            CrewMember* crewMember = this->crewBoxes[index]->GetSelected(x, y);
            if (crewMember != nullptr)
            {
                this->selectedCrewBox = index;
                this->selectingCrewOnPlayerShip = !crewMember->GetIntruder();
                
                this->potentialSelectedCrew.clear();
                this->SelectPotentialCrew(crewMember, false);
            }

            index += 1;
        } while (index < this->crewBoxes.size());
    }

    if (this->selectingCrewOnPlayerShip == false)
    {
        CrewMember* crewMember = this->combatControl->GetSelectedCrew(x, y);
        this->SelectPotentialCrew(crewMember, false);
    }
    else
    {
        CrewMember* crewMember = this->shipManager->GetSelectedCrewPoint(wX,wY,false);
        this->SelectPotentialCrew(crewMember, false);
    }

    if (action > 2) // UP or CANCEL
    {
        this->selectingCrew = false;
        this->selectedCrew = this->potentialSelectedCrew;
        this->potentialSelectedCrew.clear();
    }
    return;
}

HOOK_METHOD_PRIORITY(CrewMember, OnRender, 9999, (bool outlineOnly) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::OnRender -> Begin (TouchScreen.cpp)\n")

    if (!this->bDead)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(0.f, this->PositionShift());

        this->crewAnim->OnRender(this->scale, this->selectionState, outlineOnly);
        
        CSurface::GL_PopMatrix();
    }
}

HOOK_METHOD_PRIORITY(CrewAnimation, OnRender, 9999, (float scale, int selectedState, bool outlineOnly) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewAnimation::OnRender -> Begin (TouchScreen.cpp)\n")

    float scaleFactor = scale;
    float red;
    float green;
    float blue;
    float alpha;
    float outlineRed = 1.f;
    float outlineGreen = 1.f;
    float outlineBlue = 1.f;
    

    bool settingColorblind = G_->GetSettings()->colorblind;
    if ((this->iShipId != 0) && (this->colorblind != settingColorblind))
    {
        this->colorblind = settingColorblind;
    }
    
    if (this->status == 3)
    {
        if (outlineOnly)
        {
            return;
        }
    SetStandardColor:
        red = 1.f;
        green = 1.f;
        blue = 1.f;
        goto StartRendering;
    }
    if (outlineOnly)
    {
        // COLOR_RED
        red = 255.f / 255;
        green = 50.f / 255;
        blue = 50.f / 255;
        outlineRed = red;
        outlineGreen = green;
        outlineBlue = blue;
        goto StartRendering;
    }
    if (!this->bPlayer)
    {
        if (this->colorblind)
        {
            // COLOR_CB_BLUE
            red = 1.0;
            outlineRed = 255.f / 255;
            outlineGreen = 255.f / 255;
            outlineBlue = 50.f / 255;
            goto HandleStunnedState;
        }
        // COLOR_RED
        outlineRed = 255.f / 255;
        outlineGreen = 50.f / 255;
        outlineBlue = 50.f / 255;
        if (!this->bStunned) goto SetStandardColor;
    }
    else
    {
        if (selectedState == 1)
        {
            // COLOR_GREEN
            red = 0.5f;
            outlineRed = 100.f / 255;
            outlineGreen = 255.f / 255;
            outlineBlue = 100.f / 255;
        }
        else if (selectedState == 2)
        {
            // COLOR_GREEN
            red = 1.f;
            outlineRed = 100.f / 255;
            outlineGreen = 255.f / 255;
            outlineBlue = 100.f / 255;
        }
        else if (selectedState == 3)
        {
            // COLOR_GREEN
            red = 0.5f;
            outlineRed = 100.f / 255;
            outlineGreen = 255.f / 255;
            outlineBlue = 100.f / 255;
        }
        else if (selectedState == 4)
        {
            // COLOR_GREEN
            red = 1.f;
            outlineRed = 100.f / 255;
            outlineGreen = 255.f / 255;
            outlineBlue = 100.f / 255;
        }
        else if (selectedState == 0)
        {
            // COLOR_YELLOW
            red = 1.f;
            outlineRed = 255.f / 255;
            outlineGreen = 255.f / 255;
            outlineBlue = 50.f / 255;
        }
        else
        {
            red = 1.f;
        }
    HandleStunnedState:
        if (!this->bStunned)
        {
            blue = red;
            green = 1.f;
            goto StartRendering;
        }
    }
    // COLOR_GRAY
    blue = 125.f / 255;
    green = 125.f / 255;
    red = 125.f / 255;
    StartRendering:
    
    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(this->lastPosition.x - 17.f,this->lastPosition.y - 17.f);

    // REWRITE IMPROVEMENT: Use pointer leading to the correct animation inside the vector to prevent reaching for it multiple times throughout the code
    Animation* anim = &this->anims[this->direction][this->status];

    if ((this->forcedAnimation != -1) && (this->forcedDirection != -1))
    {
        this->direction = this->forcedDirection;
        this->status = this->forcedAnimation; // Possibly incorrect
        anim->tracker.SetLoop(true, 0.f);
    }
    if (this->status == 7)
    {
        if (this->GetFiringFrame() != -1)
        {
            anim->SetCurrentFrame(this->status);
        }
    }
    if (!outlineOnly && (this->status == 4))
    {
        this->smokeEmitter.OnRender();
    }
    alpha = 1.f;
    if (this->bGhost)
    {
        alpha = 0.5f;
    }
    if (this->status == 6)
    {
        CSurface::GL_Translate(0.f,-8.f);
        alpha = (1.f - anim->tracker.Progress(-1.f)) * alpha;
    }

    if (outlineOnly && (alpha = 0.75f, this->colorblind))
    {
        alpha = 1.f;
    }
    
    InputManager* inputManager = InputManager::GetInstance();
    CrewControl* crewControl = &G_->GetCApp()->gui->crewControl;
    if ((selectedState == 1 || (crewControl->selectedCrew.empty() && crewControl->selectingCrew)) && inputManager->currentInputDevice == InputManager::TOUCHSCREEN)
    {
        CSurface::GL_Translate(-roundf(static_cast<float>(anim->info.frameWidth) / 2 - 1.f), -roundf(static_cast<float>(anim->info.frameHeight) / 2 - 1.f));
        CSurface::GL_Scale(2.f, 2.f);
    }
    
    if (!this->bDrone)
    {
        if ((selectedState == 1) && inputManager->currentInputDevice != InputManager::TOUCHSCREEN)
        {
            scaleFactor = scale * 1.125f;
        }
        if ((this->status != 3) && (!outlineOnly))
        {
            CSurface::GL_PushMatrix();
            if (scaleFactor != 1.f)
            {
                anim->fScale = 1.f;
                float scaleOffset = (1.f - scaleFactor) * 0.5f;
                CSurface::GL_Translate(anim->info.frameWidth * scaleOffset, anim->info.frameHeight * scaleOffset);
            }
            anim->fScale = scaleFactor;
            anim->SetAnimationId(this->colorStrip);
            // Render outline:
            anim->OnRender(alpha, GL_Color(outlineRed, outlineGreen, outlineBlue, 1.f), false);
            anim->fScale = 1.f;
            CSurface::GL_PopMatrix();
        }
    }

    if ((this->CustomDeath() && !this->bDrone) || (this->status != 3))
    {
        anim->SetAnimationId(this->baseStrip);
        // Render base (main layer)
        anim->OnRender(alpha, GL_Color(red, green, blue, 1.f), false);

        if (!outlineOnly && !this->layerStrips.empty())
        {
            size_t layerStripIndex = 0;
            do {
                anim->SetAnimationId(this->layerStrips[layerStripIndex]);

                GL_Color* layerColor = &this->layerColors[layerStripIndex];
                GL_Color renderColor(red * layerColor->r, green * layerColor->g, blue * layerColor->b, layerColor->a);

                anim->OnRender(alpha, renderColor, false);
                layerStripIndex++;
            } while (layerStripIndex < this->layerStrips.size());
        }
    }
    else
    {
        if (this->CustomDeath() != false)
        {
            anim->position = Pointf(17.f - (anim->info.frameWidth * anim->fScale) / 2, 17.f - (anim->info.frameHeight * anim->fScale) / 2);
        }
        anim->OnRender(alpha, COLOR_WHITE, false);
    }
    CSurface::GL_PopMatrix();
    return;
}





HOOK_METHOD_PRIORITY(Button, OnRender, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> GenericButton::OnRender -> Begin (TouchScreen.cpp)\n")
    /* DWARF original prototype: void OnRender(Button * this) */
    
    if (this->primitives[0] == nullptr)
    {
        for (int i = 0; i < 3; i++)
        {
            this->primitives[i] = CSurface::GL_CreatePixelImagePrimitive(this->images[i], static_cast<float>(this->position.x), static_cast<float>(this->position.y), static_cast<float>(this->imageSize.x), static_cast<float>(this->imageSize.y), 0.f, COLOR_WHITE, this->bMirror);
        }
    }

    int renderState = 0;
    if (!this->bRenderOff && !this->bRenderSelected && this->bActive && !this->bSelected)
    {
        renderState = 2 - (int)(!this->bHover);
    }
    
    CSurface::GL_RenderPrimitive(this->primitives[renderState]);

    if (this->bFlashing && this->bActive && !this->bHover)
    {
        CSurface::GL_RenderPrimitiveWithAlpha(this->primitives[2], this->flashing.GetAlphaLevel(false) * 0.75f);
    }
}

HOOK_METHOD_PRIORITY(GenericButton, OnTouch, 9999, (TouchAction action, int id, int x, int y, int initialX, int initialY) -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> GenericButton::OnTouch -> Begin (TouchScreen.cpp)\n")

    this->bActivated = false;

    if (!this->allowAnyTouch)
    {
        if (action != TOUCH_DOWN)
        {
            if (this->activeTouch != id) return false;
            goto HandleMoveOrUp;
        }

        if (this->activeTouch != 0 && CEvent::IsTouchActive(this->activeTouch)) return false;

        if (this->hitbox.Contains(x, y))
        {
            this->activeTouch = id;
            this->bHover = true;
            goto HandleTouchLogic;
        }
    }
    else
    {
    HandleMoveOrUp:
        if (action == TOUCH_MOVE)
        {
            this->bHover = this->hitbox.Contains(x, y);
        }
        else
        {
            if (action == TOUCH_UP || action == TOUCH_CANCEL)
            {
                bool isWithinHitbox = this->hitbox.Contains(x, y);
                this->bActivated = (this->bActive && isWithinHitbox);

                this->bHover = false;
                this->activeTouch = 0;
                goto HandleTouchLogic;
            }

            if (action == TOUCH_DOWN)
            {
                if (this->hitbox.Contains(x, y))
                {
                    this->activeTouch = id;
                    this->bHover = true;
                    goto HandleTouchLogic;
                }
            }
        }
    }

HandleTouchLogic:
    if (this->touchSelectable)
    {
        if (action == TOUCH_UP && this->bActivated)
        {
            if (!this->bSelected)
            {
                this->bActivated = false;
                this->bSelected = true;
            }
        }
        else
        {
            if (!this->Hovering())
            {
                this->bSelected = false;
            }
        }
    }
    
    if (this->activeTouch == 0 && !this->bHover)
    {
        return this->bActivated;
    }
    return true;

    /*
    this->bActivated = false;

    if (!this->allowAnyTouch)
    {
        if (action != TOUCH_DOWN)
        {
            if (this->activeTouch != id) return false;
        }
        else
        {
            if (this->activeTouch != 0 && CEvent::IsTouchActive(activeTouch)) return false;
            if (this->hitbox.Contains(x, y))
            {
                this->activeTouch = id;
                this->bHover = true;
            }
        }
    } 
    else
    {
        switch (action)
        {
            case TOUCH_MOVE:
                bHover = hitbox.Contains(x, y);
                break;
            case TOUCH_UP:
                bActivated = bActive && hitbox.Contains(x, y);
            case TOUCH_CANCEL:
                bHover = false;
                activeTouch = 0;
                break;
            case TOUCH_DOWN:
                if (hitbox.Contains(x, y))
                {
                    activeTouch = id;
                    bHover = true;
                }
                break;
        }
    }

    if (this->touchSelectable)
    {
        if (action == TOUCH_UP && this->bActivated)
        {
            if (!this->bSelected)
            {
                this->bActivated = false;
                this->bSelected = true;
            }
        }
        else if (!this->Hovering())
        {
            this->bSelected = false;
        }
    }

    return (this->activeTouch != 0) || this->bHover || this->bActivated;
    */
}





HOOK_METHOD_PRIORITY(CombatControl, OnRenderInterface, 9999, (bool front) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CombatControl::OnRenderInterface -> Begin (TouchScreen.cpp)\n")

    this->weapControl.WeaponControl::OnRender(front);
    this->droneControl.DroneControl::OnRender(front);
    if (front)
    {
        this->weapControl.ArmamentControl::RenderLabels();
        this->droneControl.ArmamentControl::RenderLabels();
        this->weapControl.WeaponControl::RenderWarnings();
        this->droneControl.DroneControl::RenderWarnings();
        this->weapControl.ArmamentControl::RenderDragging();
        this->droneControl.ArmamentControl::RenderDragging();
    }
}

HOOK_METHOD_PRIORITY(SystemControl, OnRender, 9999, (bool front) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SystemControl::OnRender -> Begin (TouchScreen.cpp)\n")

    // Init GL matrix
    CSurface::GL_PushMatrix();
    // Translate to the position of this system control
    CSurface::GL_Translate(this->position.x, this->position.y);

    if (InputManager::GetInstance()->currentInputDevice == InputManager::TOUCHSCREEN)
    {
        // Render the power bar
        if (!front) RenderPowerBar();

        for (SystemBox* box : this->sysBoxes)
        {
            if (box->tapped == front)
            {
                box->OnRender(false);
            }
        }
    }
    else
    {
        if (!front)
        {
            // Render the power bar
            RenderPowerBar();
            // Render the subsystem box
            CSurface::GL_RenderPrimitive(this->sub_box);

            // Fetch data for subSys box UI
            std::string label = G_->GetTextLibrary()->GetText("subsystems_label", G_->GetTextLibrary()->currentLanguage);
            GL_Color color =
            {
                (::COLOR_BUTTON_TEXT.r) * 1.6f,
                (::COLOR_BUTTON_TEXT.g) * 1.6f,
                (::COLOR_BUTTON_TEXT.b) * 1.6f,
                1.f
            };

            // Render the subSys UI
            CSurface::GL_SetColor(color);
            freetype::easy_printCenter(62, this->subSystemPosition.x + (this->sub_spacing * 3 / 2) + 87.f, this->subSystemPosition.y + 47.f, label);
        }

        for (SystemBox* box : this->sysBoxes)
        {
            if (box->tapped == front)
            {
                box->OnRender(false);
            }
        }
    }

    // Kill the current GL matrix
    CSurface::GL_PopMatrix();
}

static bool initExtraPrimitive = false;
static GL_Primitive* timerCircleMaxOcta = nullptr;
static GL_Primitive* timerCircleMaxRing = nullptr;
static GL_Primitive* touchTimerCircleMaxOcta = nullptr;
static GL_Primitive* touchTimerCircleMaxRing = nullptr;

HOOK_METHOD(SystemBox, constructor, (Point pos, ShipSystem *sys, bool playerUI) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SystemBox::constructor -> Begin (TouchScreen.cpp)\n")
    super(pos, sys, playerUI);

    SystemBox_Extend* ex = SB_EX(this);
    int8_t sysId = this->pSystem->GetId();
    bool isSubsystem = ShipSystem::IsSubsystem(sysId);

    // Touch cooldown num-box
    for (uint8_t i = 1; i <= 9; i++)
    {
        ex->touchTimerCircle[i] = G_->GetResources()->CreateImagePrimitiveString((std::string("ipad/icons/locking/s_") + (isSubsystem ? "octa" : "ring") + "_" + std::to_string(i) + "_base.png"), 0, 0, 0, COLOR_WHITE, 1.f, false);
    }
    // Touch cooldown timer
    ex->touchTimerLines = G_->GetResources()->CreateImagePrimitiveString((std::string("ipad/icons/locking/s_") + (isSubsystem ? "octa" : "ring") + "_timer.png"), 0, 0, 0, COLOR_WHITE, 1.f, false);

    if (sysId == SYS_WEAPONS || sysId == SYS_DRONES)
    {
        ex->tappedBoxBottom = G_->GetResources()->CreateImagePrimitiveString(("ipad/systemUI/sysbox_bottom.png"), -2, 48, 0, COLOR_WHITE, 1.f, false);
        ex->tappedBoxMiddle = G_->GetResources()->CreateImagePrimitiveString(("ipad/systemUI/sysbox_1px.png"), -2, 0, 0, COLOR_WHITE, 1.f, false);
        ex->tappedBoxSeparator = G_->GetResources()->CreateImagePrimitiveString(("ipad/systemUI/sysbox_separator.png"), -2, -12, 0, COLOR_WHITE, 1.f, false);
        ex->tappedBoxTop = G_->GetResources()->CreateImagePrimitiveString(("ipad/systemUI/sysbox_top.png"), -2, -17, 0, COLOR_WHITE, 1.f, false);
    }
    else
    {
        ex->tappedBoxBottom = G_->GetResources()->CreateImagePrimitiveString(("ipad/systemUI/sysbox2_bottom.png"), -13, 48, 0, COLOR_WHITE, 1.f, false);
        ex->tappedBoxMiddle = G_->GetResources()->CreateImagePrimitiveString(("ipad/systemUI/sysbox2_1px.png"), -13, 0, 0, COLOR_WHITE, 1.f, false);
        ex->tappedBoxSeparator = G_->GetResources()->CreateImagePrimitiveString(("ipad/systemUI/sysbox2_separator.png"), -13, -12, 0, COLOR_WHITE, 1.f, false);
        ex->tappedBoxTop = G_->GetResources()->CreateImagePrimitiveString(("ipad/systemUI/sysbox2_top.png"), -13, -17, 0, COLOR_WHITE, 1.f, false);
    }

    if (!initExtraPrimitive)
    {
        // Custom texture for cooldown greater than 9
        // Normal variants
        timerCircleMaxOcta = G_->GetResources()->CreateImagePrimitiveString("icons/locking/s_octa_9+_base.png", 0, 0, 0, COLOR_WHITE, 1.f, false);
        timerCircleMaxRing = G_->GetResources()->CreateImagePrimitiveString("icons/locking/s_ring_9+_base.png", 0, 0, 0, COLOR_WHITE, 1.f, false);
        // Touchscreen variants
        touchTimerCircleMaxOcta = G_->GetResources()->CreateImagePrimitiveString("ipad/icons/locking/s_octa_9+_base.png", 0, 0, 0, COLOR_WHITE, 1.f, false);
        touchTimerCircleMaxRing = G_->GetResources()->CreateImagePrimitiveString("ipad/icons/locking/s_ring_9+_base.png", 0, 0, 0, COLOR_WHITE, 1.f, false);
        initExtraPrimitive = true;
    }
}

void SystemBox_Extend::RenderTouchSystemSymbol()
{
    bool colorblind = G_->GetSettings()->colorblind;
    ShipSystem* system = this->orig->pSystem;
    GL_Color color = GL_Color(1.f, 0.f, 180.f/255, 1.f);

    if ((system->iLockCount == -1 || system->iLockCount >= 1 || system->iHackEffect >= 2) && system->flashTracker.AnimationTracker::GetAlphaLevel(false) > 0.5) // System ability in use
    {
        color = GL_Color(133.f/255, 253.f/255, 245.f/255, 1.f);
    }
    else
    {
        if (system->healthState.first < 1) // System destroyed
        {
            if (this->orig->tapped)
            {
                color = GL_Color(253.f/255, 181.f/255, 177.f/255, 1.f);
            }
            else
            {
                color = GL_Color(227.f/255, 75.f/255, 62.f/255, 1.f);
            }
        }
        else if (system->healthState.second - system->healthState.first < 1) // System undamaged
        {
            if (system->GetEffectivePower() == 0) // System unpowered
            {
                if (colorblind)
                {
                    color = GL_Color(150.f/255, 154.f/255, 155.f/255, 1.f);
                }
                else
                {
                    if (this->orig->tapped)
                    {
                        color = GL_Color(226.f/255, 226.f/255, 226.f/255, 1.f);
                    }
                    else
                    {
                        color = GL_Color(211.f/255, 211.f/255, 211.f/255, 1.f);
                    }
                }
            }
            else // System Powered
            {
                if (colorblind)
                {
                    color = GL_Color(253.f/255, 255.f/255, 238.f/255, 1.f);
                }
                else
                {
                    if (this->orig->tapped)
                    {
                        color = GL_Color(137.f/255, 253.f/255, 133.f/255, 1.f);
                    }
                    else
                    {
                        color = GL_Color(81.f/255, 245.f/255, 77.f/255, 1.f);
                    }
                }
            }
        }
        else // System damaged
        {
            if (colorblind)
            {
                color = GL_Color(254.f/255, 192.f/255, 119.f/255, 1.f);
            }
            else
            {
                if (this->orig->tapped)
                {
                    color = GL_Color(253.f/255, 207.f/255, 177.f/255, 1.f);
                }
                else
                {
                    color = GL_Color(253.f/255, 144.f/255, 65.f/255, 1.f);
                }
            }
        }
    }
    CSurface::GL_EnableBlend();
    CSurface::GL_SetColor(color);
    if (this->orig->tapped)
    {
        int8_t sysId = system->GetId();
        if (sysId == SYS_WEAPONS || sysId == SYS_DRONES)
        {
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(1.f, -26.f);
            CSurface::GL_Scale(2.f, 2.f);

            CSurface::GL_RenderPrimitiveWithColor(this->scaledPcSystemIcon, color);
            CSurface::GL_RenderPrimitiveWithColor(this->scaledPcSystemIcon, color);

            CSurface::GL_PopMatrix();
        }
        else
        {
            CSurface::GL_RenderPrimitiveWithColor(this->touchSystemIcon, color);
            CSurface::GL_RenderPrimitiveWithColor(this->touchSystemIcon, color);
        }
    }
    else
    {
        CSurface::GL_RenderPrimitiveWithColor(this->touchSystemIcon, color);
    }
}

HOOK_METHOD_PRIORITY(ShipSystem, RenderSystemSymbol, 9999, (bool forPowerUI, int forceColor) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipSystem::RenderSystemSymbol -> Begin (TouchScreen.cpp)\n")
    
    uint8_t systemSymbol = 0;

    if (forceColor < 0)
    {
        if ((this->iLockCount == -1 || this->iLockCount >= 1 || this->iHackEffect >= 2) && this->flashTracker.AnimationTracker::GetAlphaLevel(false) > 0.5) // System ability in use
        {
            systemSymbol = 16;
        }
        else
        {
            if (this->healthState.first < 1) // System destroyed
            {
                systemSymbol = 12;
            }
            else if (this->healthState.second - this->healthState.first < 1) // System undamaged
            {
                systemSymbol = (this->GetEffectivePower() == 0) ? 4 : 0; // System unpowered or powered
            }
            else // System damaged
            {
                systemSymbol = 8;
            }
        }
    }
    else // forced colors are used in the hangar or upgrade menu
    {
        if (forceColor == 0)
        {
            CSurface::GL_RenderPrimitive(this->iconPrimitives[0]);
            return;
        }
        if (forceColor == 1)
        {
            CSurface::GL_RenderPrimitive(this->iconPrimitives[2]);
            return;
        }
    }

    // Add colorblind adjustment if needed
    if (G_->GetSettings()->colorblind)
    {
        systemSymbol += 1;
    }

    // Coloring for touch scaled icon:
    if (forceColor == 99)
    {
        systemSymbol += 2;
        CSurface::GL_RenderPrimitive(this->iconPrimitives[systemSymbol]);
        return;
    }

    // Render the secondary symbol twice if selected
    if (this->selectedState != 0)
    {
        systemSymbol += 2;
        CSurface::GL_RenderPrimitive(this->iconPrimitives[systemSymbol]);
    }
    CSurface::GL_RenderPrimitive(this->iconPrimitives[systemSymbol]);

    /*
    After some testing I was able to figure out what each index was:

    iconPrimitives[0] = green1
    iconPrimitives[1] = colorblind green1 (white)
    iconPrimitives[2] = green2
    iconPrimitives[3] = colorblind green2 (white)
    iconPrimitives[4] = grey1
    iconPrimitives[5] = colorblind grey1
    iconPrimitives[6] = grey2
    iconPrimitives[7] = colorblind grey2
    iconPrimitives[8] = orange1
    iconPrimitives[9] = colorblind orange1
    iconPrimitives[10] = orange2
    iconPrimitives[11] = colorblind orange2
    iconPrimitives[12] = red1
    iconPrimitives[13] = colorblind red1
    iconPrimitives[14] = red2
    iconPrimitives[15] = colorblind red2
    iconPrimitives[16] = blue1
    iconPrimitives[17] = colorblind blue1 
    iconPrimitives[18] = blue1
    iconPrimitives[19] = colorblind blue1
    */
}



HOOK_METHOD_PRIORITY(ShipStatus, OnRender, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipStatus::OnRender -> Begin (TouchScreen.cpp)\n")

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(this->location.x, this->location.y);
    this->RenderHealth(true);
    this->RenderShields(false);
    this->RenderEvadeOxygen(false);
    this->RenderResources(false);
    this->RenderEvadeOxygen(true);
    this->RenderResources(true);
    this->hullMessage->OnRender();
    if (!this->bBossFight)
    {
        if (!this->bEnemyShip)
        {
            CSurface::GL_Translate(static_cast<float>(this->noShipShift.x), static_cast<float>(this->noShipShift.y));
        }
    }
    else
    {
        CSurface::GL_Translate(-120.f,0.f);
    }
    CSurface::GL_Translate(0.f,static_cast<float>(this->intruderShift.y));
    CSurface::GL_Translate(static_cast<float>(this->intruderPos.x), static_cast<float>(this->intruderPos.x));
    this->boardingMessage->OnRender();
    CSurface::GL_PopMatrix();
}

HOOK_METHOD_PRIORITY(ShipStatus, RenderHealth, 9999, (bool renderText) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipStatus::RenderHealth -> Begin (TouchScreen.cpp)\n")

    GL_Primitive* renderHullBox = this->hullBox;
    GL_Texture* renderHullLabel = this->hullLabel;

    // Check for red damage blinking
    if (!this->hullMessage->tracker.done && this->hullMessage->tracker.running && (!this->hullMessage->flash || this->hullMessage->flashTracker.Progress(-1.0) <= 0.5f))
    {
        renderHullBox = this->hullBox_Red;
        renderHullLabel = this->hullLabel_Red;
    }
    // Render the primitive
    CSurface::GL_RenderPrimitive(renderHullBox);

    // Render hull label
    std::string hullText = G_->GetTextLibrary()->GetText("status_hull", G_->GetTextLibrary()->currentLanguage);
    Pointf textSize = freetype::easy_measurePrintLines(62, 0.f, 0.f, 999, hullText);

    float textWidth = roundf(textSize.x);
    float textureWidth = 1.f;
    float textureHeight = 1.f;
    float scaleFactor = 16.f;

    // Check for primitive
    if (renderHullLabel == nullptr)
    {
        textureWidth = 1.f;
        scaleFactor = 16.f;
    }
    else
    {
        textureWidth = static_cast<float>(renderHullLabel->width_);
        textureHeight = static_cast<float>(renderHullLabel->height_);
        scaleFactor = 16.f / textureWidth;
    }

    // Modify the box under the "HULL" text based on the text size of the current language
    CSurface::GL_BlitImagePartial(renderHullLabel, 0.f, 0.f, 16.f, textureHeight, 0.f, scaleFactor, 0.f, 1.f, 1.f, COLOR_WHITE, false);
    CSurface::GL_BlitImagePartial(renderHullLabel, 16.f, 0.f, textWidth - 15.f, textureHeight, scaleFactor, 17.f / textureWidth, 0.f, 1.f, 1.f, COLOR_WHITE, false);
    CSurface::GL_BlitImagePartial(renderHullLabel, textWidth + 1.f, 0.f, 34.f, textureHeight, 17.f / textureWidth, 51.f / textureWidth, 0.f, 1.f, 1.f, COLOR_WHITE, false);
    CSurface::GL_BlitImagePartial(renderHullLabel, textWidth + 35.f, 0.f, 121.f - (textWidth + 35.f), textureHeight, 51.f / textureWidth, 52.f / textureWidth, 0.f, 1.f, 1.f, COLOR_WHITE, false);

    // Render health mask
    int currentHealth = this->ship->ship.hullIntegrity.first;
    int maxHealth = this->ship->ship.hullIntegrity.second;

    if (currentHealth != this->lastHealth || !this->healthMask)
    {
        this->lastHealth = currentHealth;

        float healthRatio = static_cast<float>(currentHealth) / static_cast<float>(maxHealth);

        float red, green, blue;
        if (healthRatio > 0.65f)
        {
            red = 120.f;
            green = 255.f;
            blue = 120.f;
        }
        else if (healthRatio > 0.32f)
        {
            red = 255.f;
            green = 230.f;
            blue = 92.f;
        }
        else
        {
            red = 255.f;
            green = 92.f;
            blue = 92.f;
        }

        CSurface::GL_DestroyPrimitive(this->healthMask);

        GL_Color healthColor = GL_Color(red / 255, green / 255, blue / 255, 1.f);

        this->healthMask = CSurface::GL_CreateImagePartialPrimitive(this->healthMaskTexture, 11.f, 0.f, healthRatio * 360.f, 65.f, 0.f, healthRatio, 0.f, 1.f, 1.f, healthColor, false);
    }
    CSurface::GL_RenderPrimitive(this->healthMask);

    if (renderText)
    {
        CSurface::GL_SetColor(GL_Color(::COLOR_BUTTON_TEXT.r / 255, ::COLOR_BUTTON_TEXT.g / 255, ::COLOR_BUTTON_TEXT.b / 255, 1.f));
        freetype::easy_print(62, 9.f, 9.f, hullText);
    }
}



// TODO: REMOVE THIS - JUST TEMPORRARY UNTIL MOUSE INPUT CAN BE SUPRESSED
HOOK_METHOD(SystemBox, MouseMove, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SystemBox::MouseMove -> Begin (TouchScreen.cpp)\n")

    super(mX, mY);

    // Little patch to check if the system box was touch-tapped and thus selected. Without, it will instantly get unselected because of the mouse code
    if (this->tapped) (this->pSystem->selectedState = 1);
}



//
// Reverse engineered original touch handling code for SysBoxes because it was laid out for the PC GUI.
//

// Base class input handling method:

HOOK_METHOD_PRIORITY(SystemBox, OnTouch, 9999, (TouchAction action, int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SystemBox::OnTouch -> Begin (TouchScreen.cpp)\n")

    uint8_t tappedState;

    if (action == TOUCH_DOWN)
    {
        // If there's already an active touch and it's still active, return early
        if (this->activeTouch != 0 && G_->GetCApp()->IsTouchActive(this->activeTouch)) return;
        
        this->activeTouch = id;
        this->touchInitialOffset = Point(0, 0);
    }
    else
    {
        // If the touch ID doesn't match the active touch, return early
        if (this->activeTouch != id) return;

        // If the action is not TOUCH_MOVE, reset the active touch
        if (action != TOUCH_MOVE) this->activeTouch = 0;
    }

    int16_t hitBoxX = this->hitBox.x;
    int16_t hitBoxY = this->hitBox.y;
    int16_t hitBoxWidth = this->hitBox.w;
    int16_t hitBoxHeight = this->hitBox.h;

    // Handle non-player UI
    if (!this->bPlayerUI)
    {
        bool isHovering = false;
        if (action < 3 && hitBoxX < x && x < hitBoxX + hitBoxWidth && hitBoxY < y)
        {
            isHovering = y < hitBoxY + hitBoxHeight;
        }
        this->mouseHover = isHovering;
        return;
    }

    // Adjust initial touch position based on offset
    int adjustedInitialY = this->touchInitialOffset.y + initialY;
    int adjustedInitialX = this->touchInitialOffset.x + initialX;

    // Handle touch tooltip
    if (this->touchTooltip != nullptr)
    {
        if (this->touchTooltip->OnTouch((this->tapped ? action : TOUCH_CANCEL), id, x, y, adjustedInitialX, adjustedInitialY)) return;
    }

    // Improved original code with a switch case because it's more performant which input handling benefits from
    switch (action)
    {
        case TOUCH_MOVE:
        {
            if (!this->tapped)
            {
                // Check if the touch is within the hitbox
                if (x <= hitBoxX || x >= hitBoxX + hitBoxWidth || y <= hitBoxY || y >= hitBoxY + hitBoxHeight) return;

                this->tapped = true;
                this->touchInitialOffset = Point(x - adjustedInitialX, y - adjustedInitialY);
            }

            // Handle touch tooltip positioning
            if (this->touchTooltip != nullptr)
            {
                if ((!this->pSystem->bNeedsPower && x < this->touchTooltip->position.x) || (this->pSystem->bNeedsPower && this->touchTooltip->position.x < x))
                {
                    int deltaX = x - adjustedInitialX;
                    int deltaY = y - adjustedInitialY;
                    if (std::abs(deltaY) < std::abs(deltaX))
                    {
                        this->touchTooltip->TakeTouch(id, x, y, adjustedInitialX, adjustedInitialY);
                        return;
                    }
                }
            }

            // Handle power dragging
            if (this->pSystem->bNeedsPower || this->pSystem->iSystemType == SYS_WEAPONS || this->pSystem->iSystemType == SYS_DRONES)
            {
                double currentTime = *Global_CEvent_lastEventTime;
                if (!this->draggingPower)
                {
                    int deltaY = y - adjustedInitialY;
                    if (std::abs(deltaY) > 9)
                    {
                        this->draggingPower = true;
                        this->dragInitialPower = this->pSystem->GetEffectivePower();
                        this->lastDragSpeed = 0.f;
                        this->lastDragY = y;
                        this->lastDragTime = currentTime - 1.f;
                    }
                }
                else
                {
                    // The actual power dragging stuff over like swiping the bars and such
                    int lastY = this->lastDragY;
                    this->lastDragY = y;
                    double deltaTime = currentTime - this->lastDragTime;
                    this->lastDragTime = currentTime;
                    this->lastDragSpeed = static_cast<float>((y - lastY) / deltaTime);

                    int deltaY = y - adjustedInitialY;
                    if (std::abs(deltaY) % 16 - 2 < 4) // Turned to 16 pixels instead of the original 8 so it behaves like on the iPad
                    {
                        int powerChange = (deltaY / 16); // Also adjusted for 16 px
                        if (deltaY < 0) powerChange = (deltaY / 16); // Also adjusted for 16 px
                        int newPower = this->dragInitialPower - powerChange;
                        newPower = std::max(0, std::min(newPower, this->pSystem->GetMaxPower()));
                        this->AdjustPowerTo(newPower);
                        tappedState = (this->tapped ? 1 : 0);
                        goto SetSelectedState;
                    }
                }
            }
        }
        break;
        case TOUCH_DOWN:
        {
            // Make the box tapped when the touch tap happens inside the given hitbox
            if (hitBoxX < x && x < hitBoxX + hitBoxWidth && hitBoxY < y && y < hitBoxY + hitBoxHeight)
            {
                if (!this->tapped)
                {
                    this->tapped = true;
                    tappedState = 1;
                }
                else
                {
                    this->draggingPower = true;
                    this->dragInitialPower = this->pSystem->GetEffectivePower();
                    this->lastDragSpeed = 0.f;
                    this->lastDragY = y;
                    this->lastDragTime = *Global_CEvent_lastEventTime - 1.f;
                    tappedState = (this->tapped ? 1 : 0);
                }
            }
            else
            {
                // false the tapped state and close the tap box when a touch tap happens anywhere
                tappedState = 0;
                if (this->tapped)
                {
                    this->activeTouch = 0;
                    if (this->lockedOpen) return;
                    this->CloseTapBox();
                    return;
                }
            }
            goto SetSelectedState;
        }
        break;
        case TOUCH_UP:
        {
            // Also has to do with power dragging in some way, but I am not certain what it actually does
            if (this->draggingPower)
            {
                if (std::abs(this->lastDragSpeed) >= 1200.f)
                {
                    if (this->lastDragSpeed <= 0.f)
                    {
                        this->AdjustPowerTo(this->pSystem->GetMaxPower());
                    }
                    else
                    {
                        this->AdjustPowerTo(0);
                    }
                }
                if (!this->lockedOpen)
                {
                    this->CloseTapBox();
                    tappedState = (this->tapped ? 1 : 0);
                    goto SetSelectedState;
                }
            }
        }
        break;
        case TOUCH_CANCEL:
        {
            // Cancel the touch action - honestly I have no idea when this happens or if it can even happen
            this->CancelTouch();
        }
        break;
    }

    tappedState = (this->tapped ? 1 : 0);
    SetSelectedState:
    // Set the system as selected if it is tapped - Rendering depends on that state (e.g. power bar glow)
    this->pSystem->selectedState = tappedState;
}

// Derived input handler methods:

HOOK_METHOD_PRIORITY(BatteryBox, OnTouch, 9999, (TouchAction action, int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> BatteryBox::OnTouch -> Begin (TouchScreen.cpp)\n")

    this->SystemBox::OnTouch(action, id, x, y, initialX, initialY);
}

HOOK_METHOD_PRIORITY(CloakingBox, OnTouch, 9999, (TouchAction action, int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CloakingBox::OnTouch -> Begin (TouchScreen.cpp)\n")

    this->SystemBox::OnTouch(action, id, x, y, initialX, initialY);
}

HOOK_METHOD_PRIORITY(DoorBox, OnTouch, 9999, (TouchAction action, int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> DoorBox::OnTouch -> Begin (TouchScreen.cpp)\n")

    this->SystemBox::OnTouch(action, id, x, y, initialX, initialY);
}

HOOK_METHOD_PRIORITY(HackBox, OnTouch, 9999, (TouchAction action, int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> HackBox::OnTouch -> Begin (TouchScreen.cpp)\n")

    this->SystemBox::OnTouch(action, id, x, y, initialX, initialY); // HackBox didn't originally call the touch handler for some reason
}

HOOK_METHOD_PRIORITY(MindBox, OnTouch, 9999, (TouchAction action, int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> MindBox::OnTouch -> Begin (TouchScreen.cpp)\n")

    this->SystemBox::OnTouch(action, id, x, y, initialX, initialY);
}

HOOK_METHOD_PRIORITY(TeleportBox, OnTouch, 9999, (TouchAction action, int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> TeleportBox::OnTouch -> Begin (TouchScreen.cpp)\n")

    this->SystemBox::OnTouch(action, id, x, y, initialX, initialY);
}

HOOK_METHOD_PRIORITY(WeaponSystemBox, OnTouch, 9999, (TouchAction action, int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WeaponSystemBox::OnTouch -> Begin (TouchScreen.cpp)\n")

    this->SystemBox::OnTouch(action, id, x, y, initialX, initialY);
}

// Base class render method:

HOOK_METHOD_PRIORITY(SystemBox, OnRender, 9999, (bool ignoreStatus) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SystemBox::OnRender -> Begin (TouchScreen.cpp)\n");
    
    // Rewritten to fix the rendering of a broken primitive when ion was greater than 9
    // Refactored by Dino because it was a mess and unreadable
    // Modified by Dino to add touch screen rendering (Code is no longer original reversed code, but better)

    SystemBox_Extend* ex = SB_EX(this);
    GL_Primitive* prim = nullptr;
    InputManager* inputManager = InputManager::GetInstance();
    int8_t sysId = this->pSystem->GetId();
    bool renderSysIcon = false;
    this->tapButtonOffsetY = 0;
    this->cooldownOffsetY = 0;

    if (!this->HasButton() && !(sysId == SYS_WEAPONS) && !(sysId == SYS_DRONES))
    {
        if (this->tapped)
        {
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(static_cast<float>(this->location.x), static_cast<float>(this->location.y));
            CSurface::GL_RenderPrimitive(ex->tappedBoxBottom);
            CSurface::GL_Translate(0.f, 48.f);
            float boxHeight = static_cast<float>(this->hitBox.h) - 1.f;
            CSurface::GL_PushMatrix();
            CSurface::GL_Scale(1.f, -boxHeight);
            CSurface::GL_RenderPrimitive(ex->tappedBoxMiddle);
            CSurface::GL_PopMatrix();
            CSurface::GL_Translate(0.f, -boxHeight);
            CSurface::GL_RenderPrimitive(ex->tappedBoxTop);
            CSurface::GL_PopMatrix();
        }
    }

    bool showPower = this->bShowPower;
    if (!showPower && this->pSystem->iHackEffect > 0)
    {
        showPower = this->pSystem->bUnderAttack;
    }
    this->bShowPower = showPower;

    if (this->pSystem->iLockCount < 1)
    {
        renderSysIcon = true;

        if (this->bShowPower)
        {
            if (!G_->GetSettings()->colorblind)
            {
                this->topPower = 0;
            }
            else
            {
                prim = (this->pSystem->healthState.first == 0) ? this->brokenIcon : (this->pSystem->GetLocked() ? this->lockIcon : nullptr);
                if (prim) CSurface::GL_RenderPrimitive(prim);

                this->topPower = 12;
            }
        }
    }

    if (this->powerAlpha < 1.f)
    {
        CSurface::GL_SetColorTint(CSurface::GetColorTint());
    }

    if ((this->pSystem->_shipObj.iShipId == 0) && (!G_->GetCApp()->menu.shipBuilder.bOpen) && (inputManager->currentInputDevice == InputManager::TOUCHSCREEN))
    {
        if (!this->bSimplePower)
        {
            this->topPower = this->pSystem->RenderPowerBoxes(this->location.x - 2, this->location.y - 12, 30, 12, 4, 0, false);
        }
        else
        {
            this->topPower = ShipSystem::RenderPowerBoxesPlain(this->location.x - 2, this->location.y - 12, 30, 12, 4, this->pSystem->powerState.second, 0, this->pSystem->powerState.second);
        }
    }
    else
    {
        if (!this->bSimplePower)
        {
            this->topPower = this->pSystem->RenderPowerBoxes(location.x, location.y, 16, 6, 2, this->GetHeightModifier(), false);
        }
        else
        {
            this->topPower = ShipSystem::RenderPowerBoxesPlain(location.x, location.y, 16, 6, 2, this->pSystem->powerState.second, 0, this->pSystem->powerState.second);
        }
    }

    if (this->powerAlpha < 1.f && this->powerAlpha != 1.f)
    {
        CSurface::GL_RemoveColorTint();
    }

    if (!warning.tracker.done && warning.tracker.running)
    {
        int warningY = location.y + (this->pSystem->bOnFire ? -53 : -33) + (sysId == 0 ? -78 : 0);
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(static_cast<float>(location.x), static_cast<float>(warningY));
        warning.OnRender();
        CSurface::GL_PopMatrix();
    }

    this->hitBox.x = this->location.x + 24;
    this->hitBox.y = this->topPower + 16;
    this->hitBox.w = 15;
    this->hitBox.h = this->location.y - this->topPower + 15;

    // Touch patch
    if (inputManager->currentInputDevice == InputManager::TOUCHSCREEN)
    {
        this->hitBox.x = this->hitBox.x - 13;
        this->hitBox.y = this->hitBox.y;
        this->hitBox.w = this->hitBox.w + 23;
        this->hitBox.h = this->hitBox.h + 18;
    }

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(static_cast<float>(this->location.x), static_cast<float>(this->location.y));

    if (inputManager->currentInputDevice == InputManager::TOUCHSCREEN)
    {
        if (renderSysIcon)
        {
            CSurface::GL_DestroyPrimitive(this->timerStencil);
            this->timerStencil = nullptr;
            this->lastTimerStencilCount = -1;

            if (!this->bSimplePower)
            {
                if (this->pSystem->_shipObj.iShipId == 0)
                {
                    ex->RenderTouchSystemSymbol();
                }
                else
                {
                    this->pSystem->RenderSystemSymbol(this->bPlayerUI, -1);
                }
            }
            else
            {
                this->pSystem->RenderSystemSymbol(false, 0);
            }
        }
        else
        {
            if (!(this->pSystem->_shipObj.iShipId == 0)) goto defaultIonRendering;

            // Fix for ion greater than 9 rendering invalid primitive
            int lockCount = this->pSystem->iLockCount;
            TimerHelper timer = this->pSystem->GetLockTimer();
            int stencilCount = static_cast<int>(12.f - (timer.currTime / timer.currGoal) * 12.f) + 1;

            CSurface::GL_RenderPrimitive(lockCount <= 9 ? ex->touchTimerCircle[lockCount] : (ShipSystem::IsSubsystem(sysId) ? touchTimerCircleMaxOcta : touchTimerCircleMaxRing));

            if (stencilCount != this->lastTimerStencilCount)
            {
                this->lastTimerStencilCount = stencilCount;
                CSurface::GL_DestroyPrimitive(ex->touchTimerStencil);
                ex->touchTimerStencil = CSurface::GL_CreatePiePartialPrimitive(0, 0, 22.f, -85.f, static_cast<float>(stencilCount * 30 - 85), 22.f, COLOR_WHITE);
            }

            CSurface::GL_SetStencilMode(STENCIL_SET, 1, 1);
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(29.f, 29.f);
            CSurface::GL_RenderPrimitive(ex->touchTimerStencil);
            CSurface::GL_PopMatrix();
            CSurface::GL_SetStencilMode(STENCIL_USE, 1, 1);
            CSurface::GL_RenderPrimitive(ex->touchTimerLines);
            CSurface::GL_SetStencilMode(STENCIL_IGNORE, 0, 0);
        }
    }
    else
    {
        if (renderSysIcon)
        {
            CSurface::GL_DestroyPrimitive(this->timerStencil);
            this->timerStencil = nullptr;
            this->lastTimerStencilCount = -1;

            if (!this->bSimplePower)
            {
                this->pSystem->RenderSystemSymbol(this->bPlayerUI, -1);
            }
            else
            {
                this->pSystem->RenderSystemSymbol(false, 0);
            }
        }
        else
        {
            defaultIonRendering:
            // Fix for ion greater than 9 rendering invalid primitive
            int lockCount = this->pSystem->iLockCount;
            TimerHelper timer = this->pSystem->GetLockTimer();
            int stencilCount = static_cast<int>(12.f - (timer.currTime / timer.currGoal) * 12.f) + 1;

            CSurface::GL_RenderPrimitive(lockCount <= 9 ? this->timerCircle[lockCount] : (ShipSystem::IsSubsystem(sysId) ? timerCircleMaxOcta : timerCircleMaxRing));

            if (stencilCount != this->lastTimerStencilCount)
            {
                this->lastTimerStencilCount = stencilCount;
                CSurface::GL_DestroyPrimitive(this->timerStencil);
                this->timerStencil = CSurface::GL_CreatePiePartialPrimitive(0, 0, 17.f, -85.f, static_cast<float>(stencilCount * 30 - 85), 17.f, COLOR_WHITE);
            }

            CSurface::GL_SetStencilMode(STENCIL_SET, 1, 1);
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(32.f, 32.f);
            CSurface::GL_RenderPrimitive(this->timerStencil);
            CSurface::GL_PopMatrix();
            CSurface::GL_SetStencilMode(STENCIL_USE, 1, 1);
            CSurface::GL_RenderPrimitive(this->timerLines);
            CSurface::GL_SetStencilMode(STENCIL_IGNORE, 0, 0);
        }
    }

    CSurface::GL_PopMatrix();

    // Render purple hack icon above power bars
    if (0 < this->pSystem->iHackEffect && this->pSystem->bUnderAttack && !this->bShowPower)
    {
        CSurface::GL_Translate(0.f, 0.f);
        CSurface::GL_RenderPrimitive(this->hackIcon);
        CSurface::GL_Translate(0.f, 0.f);
    }
}

// Derived methods:

HOOK_METHOD_PRIORITY(ArtilleryBox, OnRender, 9999, (bool ignoreStatus) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ArtilleryBox::OnRender -> Begin (TouchScreen.cpp)\n")

    this->SystemBox::OnRender(ignoreStatus);
}

HOOK_METHOD_PRIORITY(BatteryBox, OnRender, 9999, (bool ignoreStatus) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> BatteryBox::OnRender -> Begin (TouchScreen.cpp)\n")

    SystemBox* sysbox = this;
    SystemBox_Extend* ex = SB_EX(sysbox);

    if (this->tapped)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(static_cast<float>(this->location.x), static_cast<float>(this->location.y));
        CSurface::GL_RenderPrimitive(ex->tappedBoxBottom);
        CSurface::GL_Translate(0.f, 48.f);
        float boxHeight = static_cast<float>(this->hitBox.h) - 1.f;
        CSurface::GL_PushMatrix();
        CSurface::GL_Scale(1.f, -boxHeight);
        CSurface::GL_RenderPrimitive(ex->tappedBoxMiddle);
        CSurface::GL_PopMatrix();
        CSurface::GL_Translate(0.f, -boxHeight);
        CSurface::GL_RenderPrimitive(ex->tappedBoxSeparator);
        CSurface::GL_PopMatrix();
    }
    this->SystemBox::OnRender(ignoreStatus);
}

HOOK_METHOD_PRIORITY(CloakingBox, OnRender, 9999, (bool ignoreStatus) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CloakingBox::OnRender -> Begin (TouchScreen.cpp)\n")

    SystemBox* sysbox = this;
    SystemBox_Extend* ex = SB_EX(sysbox);

    if (this->tapped)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(static_cast<float>(this->location.x), static_cast<float>(this->location.y));
        CSurface::GL_RenderPrimitive(ex->tappedBoxBottom);
        CSurface::GL_Translate(0.f, 48.f);
        float boxHeight = static_cast<float>(this->hitBox.h) - 1.f;
        CSurface::GL_PushMatrix();
        CSurface::GL_Scale(1.f, -boxHeight);
        CSurface::GL_RenderPrimitive(ex->tappedBoxMiddle);
        CSurface::GL_PopMatrix();
        CSurface::GL_Translate(0.f, -boxHeight);
        CSurface::GL_RenderPrimitive(ex->tappedBoxSeparator);
        CSurface::GL_PopMatrix();
    }
    this->SystemBox::OnRender(ignoreStatus);
}

HOOK_METHOD_PRIORITY(DoorBox, OnRender, 9999, (bool ignoreStatus) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> DoorBox::OnRender -> Begin (TouchScreen.cpp)\n")

    SystemBox* sysbox = this;
    SystemBox_Extend* ex = SB_EX(sysbox);

    if (this->tapped)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(static_cast<float>(this->location.x), static_cast<float>(this->location.y));
        CSurface::GL_RenderPrimitive(ex->tappedBoxBottom);
        CSurface::GL_Translate(0.f, 48.f);
        float boxHeight = static_cast<float>(this->hitBox.h) - 1.f;
        CSurface::GL_PushMatrix();
        CSurface::GL_Scale(1.f, -boxHeight);
        CSurface::GL_RenderPrimitive(ex->tappedBoxMiddle);
        CSurface::GL_PopMatrix();
        CSurface::GL_Translate(0.f, -boxHeight);
        CSurface::GL_RenderPrimitive(ex->tappedBoxSeparator);
        CSurface::GL_PopMatrix();
    }
    this->SystemBox::OnRender(ignoreStatus);
}

HOOK_METHOD_PRIORITY(HackBox, OnRender, 9999, (bool ignoreStatus) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> HackBox::OnRender -> Begin (TouchScreen.cpp)\n")

    SystemBox* sysbox = this;
    SystemBox_Extend* ex = SB_EX(sysbox);

    if (this->tapped)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(static_cast<float>(this->location.x), static_cast<float>(this->location.y));
        CSurface::GL_RenderPrimitive(ex->tappedBoxBottom);
        CSurface::GL_Translate(0.f, 48.f);
        float boxHeight = static_cast<float>(this->hitBox.h) - 1.f;
        CSurface::GL_PushMatrix();
        CSurface::GL_Scale(1.f, -boxHeight);
        CSurface::GL_RenderPrimitive(ex->tappedBoxMiddle);
        CSurface::GL_PopMatrix();
        CSurface::GL_Translate(0.f, -boxHeight);
        CSurface::GL_RenderPrimitive(ex->tappedBoxSeparator);
        CSurface::GL_PopMatrix();
    }
    this->SystemBox::OnRender(ignoreStatus);
}

HOOK_METHOD_PRIORITY(MindBox, OnRender, 9999, (bool ignoreStatus) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> MindBox::OnRender -> Begin (TouchScreen.cpp)\n")

    SystemBox* sysbox = this;
    SystemBox_Extend* ex = SB_EX(sysbox);

    if (this->tapped)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(static_cast<float>(this->location.x), static_cast<float>(this->location.y));
        CSurface::GL_RenderPrimitive(ex->tappedBoxBottom);
        CSurface::GL_Translate(0.f, 48.f);
        float boxHeight = static_cast<float>(this->hitBox.h) - 1.f;
        CSurface::GL_PushMatrix();
        CSurface::GL_Scale(1.f, -boxHeight);
        CSurface::GL_RenderPrimitive(ex->tappedBoxMiddle);
        CSurface::GL_PopMatrix();
        CSurface::GL_Translate(0.f, -boxHeight);
        CSurface::GL_RenderPrimitive(ex->tappedBoxSeparator);
        CSurface::GL_PopMatrix();
    }
    this->SystemBox::OnRender(ignoreStatus);
}

HOOK_METHOD_PRIORITY(TeleportBox, OnRender, 9999, (bool ignoreStatus) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> TeleportBox::OnRender -> Begin (TouchScreen.cpp)\n")

    SystemBox* sysbox = this;
    SystemBox_Extend* ex = SB_EX(sysbox);

    if (this->tapped)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(static_cast<float>(this->location.x), static_cast<float>(this->location.y));
        CSurface::GL_RenderPrimitive(ex->tappedBoxBottom);
        CSurface::GL_Translate(0.f, 48.f);
        float boxHeight = static_cast<float>(this->hitBox.h) - 1.f;
        CSurface::GL_PushMatrix();
        CSurface::GL_Scale(1.f, -boxHeight);
        CSurface::GL_RenderPrimitive(ex->tappedBoxMiddle);
        CSurface::GL_PopMatrix();
        CSurface::GL_Translate(0.f, -boxHeight);
        CSurface::GL_RenderPrimitive(ex->tappedBoxSeparator);
        CSurface::GL_PopMatrix();
    }
    this->SystemBox::OnRender(ignoreStatus);
}

HOOK_METHOD_PRIORITY(WeaponSystemBox, OnRender, 9999, (bool ignoreStatus) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WeaponSystemBox::OnRender -> Begin (TouchScreen.cpp)\n")

    SystemBox* sysbox = this;
    SystemBox_Extend* ex = SB_EX(sysbox);

    if (this->tapped)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(static_cast<float>(this->location.x), static_cast<float>(this->location.y));
        CSurface::GL_RenderPrimitive(ex->tappedBoxBottom);
        CSurface::GL_Translate(0.f, 48.f);
        float boxHeight = static_cast<float>(this->hitBox.h) - 1.f;
        CSurface::GL_PushMatrix();
        CSurface::GL_Scale(1.f, -boxHeight);
        CSurface::GL_RenderPrimitive(ex->tappedBoxMiddle);
        CSurface::GL_PopMatrix();
        CSurface::GL_Translate(0.f, -boxHeight);
        CSurface::GL_RenderPrimitive(ex->tappedBoxSeparator);
        CSurface::GL_PopMatrix();
    }
    else
    {
        if (this->pSystem->GetId() == SYS_DRONES)
        {
            reinterpret_cast<DroneControl*>(this->weapControl)->OnRender(false);
        }
        else
        {
            weapControl->OnRender(false);
        }
    }
    this->SystemBox::OnRender(ignoreStatus);
}



// Fully reimplement those methods from scratch because they were designed for the PC UI (and also so broken that they caused crashes lol)

HOOK_METHOD_PRIORITY(ArmamentBox, OnTouch, 9999, (TouchAction action, int id, int x, int y, int initialX, int initialY) -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ArmamentBox::OnTouch -> Begin (TouchScreen.cpp)\n")

    return false;
}

HOOK_METHOD_PRIORITY(ArmamentControl, OnTouch, 9999, (TouchAction action, int id, int x, int y, int initialX, int initialY) -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ArmamentControl::OnTouch -> Begin (TouchScreen.cpp)\n")

    return false;
}

HOOK_METHOD_PRIORITY(DroneControl, OnTouch, 9999, (TouchAction action, int id, int x, int y, int initialX, int initialY) -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> DroneControl::OnTouch -> Begin (TouchScreen.cpp)\n")

    return false;
}

HOOK_METHOD_PRIORITY(WeaponControl, OnTouch, 9999, (TouchAction action, int id, int x, int y, int initialX, int initialY) -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WeaponControl::OnTouch -> Begin (TouchScreen.cpp)\n")

    return false;
}



// Custom code for touch GUI

HOOK_METHOD_PRIORITY(ArmamentBox, OnRender, 9999, (bool dragging, bool flashPowerBox) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ArmamentBox::OnRender -> Begin (TouchScreen.cpp)\n")

    if (InputManager::GetInstance()->currentInputDevice == InputManager::TOUCHSCREEN)
    {

    }
    else
    {
        super(dragging, flashPowerBox);
    }
}

HOOK_METHOD_PRIORITY(ArmamentControl, OnRender, 9999, (bool front) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ArmamentControl::OnRender -> Begin (TouchScreen.cpp)\n")

    if (InputManager::GetInstance()->currentInputDevice == InputManager::TOUCHSCREEN)
    {

    }
    else
    {
        super(front);
    }
}

HOOK_METHOD_PRIORITY(ArmamentControl, RenderLabels, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ArmamentControl::RenderLabels -> Begin (TouchScreen.cpp)\n")

    if (InputManager::GetInstance()->currentInputDevice == InputManager::TOUCHSCREEN)
    {

    }
    else
    {
        super();
    }
}

HOOK_METHOD_PRIORITY(ArmamentControl, RenderDragging, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ArmamentControl::RenderDragging -> Begin (TouchScreen.cpp)\n")

    if (InputManager::GetInstance()->currentInputDevice == InputManager::TOUCHSCREEN)
    {

    }
    else
    {
        super();
    }
}

HOOK_METHOD_PRIORITY(WeaponControl, OnRender, 9999, (bool front) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WeaponControl::OnRender -> Begin (TouchScreen.cpp)\n")

    if (InputManager::GetInstance()->currentInputDevice == InputManager::TOUCHSCREEN)
    {
        if (this->shipManager->HasSystem(SYS_WEAPONS))
        {
            ArmamentControl_Extend* ex = AC_EX(this);

            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(static_cast<float>(this->location.x) + 13.f, static_cast<float>(this->location.y) + 3.f);
            
            switch (this->shipManager->myBlueprint.weaponSlots) 
            {
                case 1:
                    CSurface::GL_RenderPrimitive(ex->touchWeaponBoxSingle);
                case 0:
                    // Prevents rendering when there are no slots (idk why you'd have that)
                    break;
                default:
                {
                    CSurface::GL_RenderPrimitive(ex->touchWeaponBoxBottom);
                    for (int slots = 0; slots < this->shipManager->myBlueprint.weaponSlots - 2; slots++)
                    {
                        CSurface::GL_RenderPrimitive(ex->touchWeaponBoxMid);
                        CSurface::GL_Translate(0.f, -35.f);
                    }
                    CSurface::GL_RenderPrimitive(ex->touchWeaponBoxTop);
                }
                break;
            }

            CSurface::GL_PopMatrix();
        }
    }
    else
    {
        super(front);
    }
}

HOOK_METHOD_PRIORITY(WeaponControl, RenderWarnings, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WeaponControl::RenderWarnings -> Begin (TouchScreen.cpp)\n")

    if (InputManager::GetInstance()->currentInputDevice == InputManager::TOUCHSCREEN)
    {
        return;
    }
    else
    {
        super();
    }
}

HOOK_METHOD_PRIORITY(DroneControl, OnRender, 9999, (bool front) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> DroneControl::OnRender -> Begin (TouchScreen.cpp)\n")

    if (InputManager::GetInstance()->currentInputDevice == InputManager::TOUCHSCREEN)
    {
        if (this->shipManager->HasSystem(SYS_DRONES))
        {
            ArmamentControl_Extend* ex = AC_EX(this);

            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(static_cast<float>(this->location.x) + 13.f, static_cast<float>(this->location.y) + 3.f);
            
            switch (this->shipManager->myBlueprint.droneSlots) 
            {
                case 1:
                    CSurface::GL_RenderPrimitive(ex->touchWeaponBoxSingle);
                case 0:
                    // Prevents rendering when there are no slots (idk why you'd have that)
                    break;
                default:
                {
                    CSurface::GL_RenderPrimitive(ex->touchWeaponBoxBottom);
                    for (int slots = 0; slots < this->shipManager->myBlueprint.droneSlots - 2; slots++)
                    {
                        CSurface::GL_RenderPrimitive(ex->touchWeaponBoxMid);
                        CSurface::GL_Translate(0.f, -35.f);
                    }
                    CSurface::GL_RenderPrimitive(ex->touchWeaponBoxTop);
                }
                break;
            }

            CSurface::GL_PopMatrix();
        }
    }
    else
    {
        super(front);
    }
}

HOOK_METHOD_PRIORITY(DroneControl, RenderWarnings, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> DroneControl::RenderWarnings -> Begin (TouchScreen.cpp)\n")

    if (InputManager::GetInstance()->currentInputDevice == InputManager::TOUCHSCREEN)
    {

    }
    else
    {
        super();
    }
}


// Starmap primitive swap pointers
// PC
GL_Primitive* PC_explored;
GL_Primitive* PC_unexplored;
GL_Primitive* PC_danger;
GL_Primitive* PC_warning;
GL_Primitive* PC_yellow_warning;
GL_Primitive* PC_warning_shadow;
GL_Primitive* PC_warning_circle;
GL_Texture* PC_dottedLine;
// Touch
GL_Primitive* Touch_explored;
GL_Primitive* Touch_unexplored;
GL_Primitive* Touch_danger;
GL_Primitive* Touch_warning;
GL_Primitive* Touch_yellow_warning;
GL_Primitive* Touch_warning_shadow;
GL_Primitive* Touch_warning_circle;
GL_Texture* Touch_dottedLine;

HOOK_METHOD_PRIORITY(StarMap, constructor, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> StarMap::OnRender -> Begin (TouchScreen.cpp)\n")

    super();

    // Back up the primitive pointers and create some for touch so that they can be swapped later
    if (!Touch_explored)
    {
        PC_explored = this->explored;
        PC_unexplored = this->unexplored;
        PC_danger = this->danger;
        PC_warning = this->warning;
        PC_yellow_warning = this->yellow_warning;
        PC_warning_shadow = this->warning_shadow;
        PC_warning_circle = this->warning_circle;
        PC_dottedLine = this->dottedLine;

        Touch_explored = G_->GetResources()->CreateImagePrimitiveString("ipad/map/map_icon_diamond_blue.png", -19, -19, 0, COLOR_WHITE, 1.f, false);
        Touch_unexplored = G_->GetResources()->CreateImagePrimitiveString("ipad/map/map_icon_diamond_yellow.png", -19, -19, 0, COLOR_WHITE, 1.f, false);
        Touch_danger = G_->GetResources()->CreateImagePrimitiveString("ipad/map/map_icon_warning.png", -24, -24, 0, COLOR_WHITE, 1.f, false);
        Touch_warning = G_->GetResources()->CreateImagePrimitiveString("ipad/map/map_icon_triangle_red.png", -24, -26, 0, COLOR_WHITE, 1.f, false);
        Touch_yellow_warning = G_->GetResources()->CreateImagePrimitiveString("ipad/map/map_icon_triangle_yellow.png", -24, -26, 0, COLOR_WHITE, 1.f, false);
        Touch_warning_shadow = G_->GetResources()->CreateImagePrimitiveString("ipad/map/map_icon_triangle_shadow.png", -24, -26, 0, COLOR_WHITE, 1.f, false);
        Touch_warning_circle = G_->GetResources()->CreateImagePrimitiveString("ipad/map/map_icon_hazard.png", -33, -33, 0, COLOR_WHITE, 1.f, false);
        Touch_dottedLine = G_->GetResources()->GetImageId("ipad/map/dotted_line.png");
    }
}

HOOK_METHOD_PRIORITY(StarMap, OnRender, -100, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> StarMap::OnRender -> Begin (TouchScreen.cpp)\n")

    if (InputManager::GetInstance()->currentInputDevice == InputManager::TOUCHSCREEN)
    {
        Location* origPotentialLoc = this->potentialLoc;
        if (this->potentialLoc == nullptr)
        {
            if (this->hoverLoc == nullptr)
            {
                this->hoverLoc = this->currentLoc; // Prevents crash when switching inputs whilst the StarMap window is open
                this->potentialLoc = this->currentLoc;
            }
            else
            {
                this->potentialLoc = this->hoverLoc;
            }
        }

        super();

        this->potentialLoc = origPotentialLoc;

        if (!this->bChoosingNewSector)
        {
            std::string beaconText = this->GetLocationText(this->hoverLoc == nullptr ? this->currentLoc : this->hoverLoc);

            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(340.f, 83.f);

            Pointf textPixelDimensions = freetype::easy_measurePrintLines(7, 0.f, 0.f, 1000, beaconText);
            float xTextShift = 740.f - textPixelDimensions.x;
            float yTextShift =  roundf((502.f - (textPixelDimensions.y / 2)) + 0.7f);
            
            G_->GetResources()->RenderImage(this->mapInsetTextRight, 740, 467, 0, COLOR_WHITE, 1.f, false);
            CSurface::GL_BlitPixelImage(this->mapInsetTextMiddle, xTextShift, 470.f, textPixelDimensions.x, 60.f, 0.f, COLOR_WHITE, false);
            if (this->potentialLoc != nullptr)
            {
                this->RenderLeftInsetButton(xTextShift, 470.f, false);
            }
            else
            {
                G_->GetResources()->RenderImage(this->mapInsetTextLeft, static_cast<int>(xTextShift) - 21, 470, 0, COLOR_WHITE, 1.f, false);
            }

            freetype::easy_printAutoNewlines(7, xTextShift, yTextShift, 10000, beaconText);
            CSurface::GL_PopMatrix();
        }
    }
    else
    {
        super();
    }
}

HOOK_METHOD_PRIORITY(StarMap, OnTouch, 9999, (TouchAction action, int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> StarMap::OnRender -> Begin (TouchScreen.cpp)\n")

    // If the tutorial hasn't been generated and the player isn't choosing a new sector, handle the FocusWindow stuff
    if (!this->bTutorialGenerated && !this->bChoosingNewSector)
    {
        this->FocusWindow::OnTouch(action, id, x, y, initialX, initialY);
    }

    // If the waiting animation is running, return early
    if (this->waiting.running)
    {
        return;
    }

    // If the map is not open, reset potential location and return
    if (!this->bOpen)
    {
        this->potentialLoc = nullptr;
        return;
    }

    // Handle touch events when choosing a new sector
    if (this->bChoosingNewSector)
    {
        // Handle touch events for the jump and close sector buttons
        this->jumpButton.GenericButton::OnTouch(action, id, x, y, initialX, initialY);
        this->closeSectorButton.GenericButton::OnTouch(action, id, x, y, initialX, initialY);

        // Calculate the touch position relative to the sector map offset
        Point touchPoint = Point(x - this->sectorMapOffset.x, y - this->sectorMapOffset.y);

        // Check if any sector is touched
        if (this->sectors.size() != 0)
        {
            int8_t touchedSector = -1;
            int8_t touchPixelRange = 30;

            // Find the closest sector to the touch point
            for (size_t index = 0; index < this->sectors.size(); ++index)
            {
                int16_t touchDistance = this->sectors[index]->location.Distance(touchPoint);
                if (touchDistance < touchPixelRange)
                {
                    touchedSector = index;
                    touchPixelRange = touchDistance;
                }
            }

            // If a sector is touched, update the potential sector choice and the map
            if (touchedSector != -1)
            {
                this->potentialSectorChoice = touchedSector;
                Sector* potentialSector = this->sectors[touchedSector];
                Sector* selectedNeighbor = nullptr;

                // Check if the touched sector is a neighbor of the current sector
                for (Sector* neighbor : this->currentSector->neighbors)
                {
                    if (neighbor == potentialSector)
                    {
                        selectedNeighbor = neighbor;
                    }
                    neighbor->visited = (neighbor == potentialSector);
                }

                // Update the sector map with the selected neighbor
                this->UpdateSectorMap(selectedNeighbor);
            }
        }

        // If neither the jump button nor the close sector button was pressed, return
        if (!this->jumpButton.bActivated)
        {
            if (!this->closeSectorButton.bActivated)
            {
                return;
            }

            // If the close button was pressed, stop choosing a new sector and activate the end button
            this->bChoosingNewSector = false;
            this->endButton.GenericButton::SetActive(true);
            return;
        }

        // If the jump button is activated, set the final sector choice and return
        this->finalSectorChoice = this->potentialSectorChoice;
        return;
    }

    // Calculate the touch position relative to the map position
    int buttonX = x - this->position.x;
    int buttonY = y - this->position.y;
    int buttonInitialX = initialX - this->position.x;
    int buttonInitialY = initialY - this->position.y;

    // Check if any button is touched
    // HYPERSPACE FIX: Rearranged the call order to prioritize the jump button
    bool anyButtonTouched =
        this->jumpButton.GenericButton::OnTouch(action, id, buttonX, buttonY, buttonInitialX, buttonInitialY) ||
        this->waitButton.GenericButton::OnTouch(action, id, buttonX, buttonY, buttonInitialX, buttonInitialY) ||
        this->distressButton.GenericButton::OnTouch(action, id, buttonX, buttonY, buttonInitialX, buttonInitialY) ||
        this->endButton.GenericButton::OnTouch(action, id, buttonX, buttonY, buttonInitialX, buttonInitialY) ||
        this->closeButton.GenericButton::OnTouch(action, id, buttonX, buttonY, buttonInitialX, buttonInitialY);

    // If no button is touched and there is no fuel shortage, handle map touch events
    if (!anyButtonTouched && !this->outOfFuel)
    {
        // Calculate the touch position relative to the map translation
        Point touchPoint(buttonX - static_cast<int>(this->translation.x), buttonY - static_cast<int>(this->translation.y));

        // Convert the touch position to grid coordinates
        Point grid = this->PointToGrid(static_cast<float>(touchPoint.x), static_cast<float>(touchPoint.y));

        // Find the grid cell in the locations grid
        auto gridIt = this->locations_grid.find(grid);
        if (gridIt != this->locations_grid.end())
        {
            Location* closestLocation = nullptr;
            float minDistance = 1000.0f;

            // Find the closest location to the touch point
            for (Location* location : gridIt->second)
            {
                float distance = location->loc.RelativeDistance(Pointf(touchPoint.x, touchPoint.y));
                if (distance < minDistance)
                {
                    closestLocation = location;
                    minDistance = distance;
                }
            }

            if (closestLocation != nullptr)
            {
                // Handle the closest location
                this->hoverLoc = closestLocation;
                this->potentialLoc = nullptr;

                // Clear the temporary path
                this->temp_path.clear();

                // Select the beacon if the location has already beed visited and the player has the basic FTL_JUMPER augment
                // HYPERSPACE FIX: add extra case to allow for any beacon if the player has the the FTL_JUMPER_GOOD augment
                if ((closestLocation->visited && shipManager->HasAugmentation("FTL_JUMPER")) || shipManager->HasAugmentation("FTL_JUMPER_GOOD"))
                {
                    if (this->hoverLoc != this->currentLoc)
                    {
                        this->targetBoxTimer.Start(0.f);
                        this->potentialLoc = this->hoverLoc;
                        goto HandleButtonPresses;
                    }
                }

                // If the location is connected to the current location, calculate the path
                if (!this->currentLoc->connectedLocations.empty())
                {
                    for (Location* connectedLocation : this->currentLoc->connectedLocations)
                    {
                        if (this->hoverLoc == connectedLocation)
                        {
                            this->targetBoxTimer.Start(0.f);
                            this->potentialLoc = this->hoverLoc;

                            // Calculate the path using Dijkstra's algorithm
                            this->Dijkstra(this->currentLoc, this->hoverLoc, false);

                            // Update the temporary path
                            this->temp_path = std::vector<Location*>(this->temp_path);

                            // Clear the temporary path if it's not empty
                            if (!this->temp_path.empty())
                            {
                                this->temp_path.clear();
                            }

                            goto HandleButtonPresses;
                        }
                    }
                }
            }
        }
    }
HandleButtonPresses:
    // Handle the individual buttons being pressed
    if (!this->distressButton.bActivated)
    {
        if (!this->waitButton.bActivated)
        {
            if (!this->endButton.bActivated)
            {
                if (!this->jumpButton.bActivated)
                {
                    if (this->closeButton.bActivated)
                    {
                        // Close the StarMap window if the close button was pressed
                        this->FocusWindow::Close();
                    }
                }
                else
                {
                    // Prepare to jump if the jump button was pressed
                    this->readyToTravel = true;
                    this->FocusWindow::Close();
                }
            }
            else
            {
                if (!this->bSecretSector)
                {
                    // Open sector map when the "Next Sector" button was pressed
                    this->bChoosingNewSector = true;
                }
                else 
                {
                    // SECRET/CRYSTAL SECTOR LOGIC

                    // If not at the final sector increase the world level 
                    if (this->worldLevel != 7)
                    {
                        this->AdvanceWorldLevel();
                    }

                    // Gather all sectors at the current world level
                    std::vector<Sector*> eligibleSectors;
                    for (Sector* sector : this->sectors)
                    {
                        if (sector->level == this->worldLevel)
                        {
                            eligibleSectors.push_back(sector);
                        }
                    }

                    // If there are eligible sectors, choose a random one
                    if (!eligibleSectors.empty())
                    {
                        // inlined RandomNumberGenerator::Get() with (*Globals_RNG ? rand() : random32())
                        int randomIndex = (*Globals_RNG ? rand() : random32()) % eligibleSectors.size();
                        Sector* newSector = eligibleSectors[randomIndex];
                        this->currentSector = newSector;
                        newSector->visited = true;

                        // Update the sector map and prepare to jump
                        this->UpdateSectorMap(nullptr);
                        this->readyToTravel = true;
                        this->potentialLoc = &this->dummyNewSector;

                        this->FocusWindow::Close();
                    }

                    this->bSecretSector = false;
                }

                this->endButton.GenericButton::SetActive(false);
            }
        }
        else
        {
            // Start the waiting animation if the wait button was pressed
            this->waiting.Start(0.f);
            this->dangerWaitStart = this->dangerZone.x;

            // Deactivate the wait and distress buttons
            this->waitButton.GenericButton::SetActive(false);
            this->distressButton.GenericButton::SetActive(false);
        }
    }
    else
    {
        // Toggle the distress button state and update the label
        bool newState = !this->distressButton.state;
        this->distressButton.state = newState;

        this->distressButton.label = this->distressButton.labels[newState];
        this->distressButton.label.isLiteral = this->distressButton.labels[newState].isLiteral;

        // Start or stop the distress animation based on the new state
        if (this->distressButton.state == false)
        {
            this->distressAnim.Stop(false);
        }
        else
        {
            this->distressAnim.Start(0.f);
        }
    }

    return;
}
