#include "Global.h"


HOOK_METHOD_PRIORITY(OptionsScreen, OnRender, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> OptionsScreen::OnRender -> Begin (ControllerFunctionRewrites.cpp)\n")

    // code reverse engineered by Dino
    Point newLocation;
    std::string localizedText;
    int closeButtonX, closeButtonY;
    int baseX = position.x;
    int baseY = position.y;

    // set colortint when some stuff is open
    if (langChooser.bOpen || wipeProfileDialog.bOpen || restartRequiredDialog.bOpen) 
    {
        CSurface::GL_SetColorTint(COLOR_TINT);
    }

    // no custom controlls - idk what they mean, maybe has to do with ipad code
    if (!bCustomizeControls) 
    {
        // close button pos stuff
        Point buttonSize = closeButton.GetSize();
        closeButtonX = baseX + 692 - buttonSize.x;
        closeButtonY = baseY + 301;
        newLocation.x = closeButtonX;
        newLocation.y = closeButtonY;
        closeButton.SetLocation(newLocation);

        ChoiceBox::OnRender(); // render window
        
        // Render restart required window after enabling native fullscreen
        if ((G_->GetSettings()->currentFullscreen == 3) != (G_->GetSettings()->fullscreen == 3))
        {
            CSurface::GL_SetColor(COLOR_YELLOW);
            localizedText = G_->GetTextLibrary()->GetText("restart_required", G_->GetTextLibrary()->currentLanguage);
            freetype::easy_print(13, baseX + 145, baseY + 20, localizedText);
        }

        CSurface::GL_SetColor(COLOR_WHITE);
        
        // render volume texts
        localizedText = G_->GetTextLibrary()->GetText("sound_volume", G_->GetTextLibrary()->currentLanguage);
        freetype::easy_printCenter(13, baseX + 156, baseY + 344, localizedText);

        localizedText = G_->GetTextLibrary()->GetText("music_volume", G_->GetTextLibrary()->currentLanguage);
        freetype::easy_printCenter(13, baseX + 156, baseY + 394, localizedText);

        // render volume sliders
        soundVolume.OnRender();
        musicVolume.OnRender();

        if (showWipeButton) 
        {
            wipeProfileButton.OnRender();
        }
        // steam achievement stuff - can't include in build
        /*
        if (showSyncAchievements) 
        {
            syncAchievementsButton.OnRender();
        }
        */
    } 
    else 
    {
        newLocation.x = 1190 - closeButton.GetSize().x; // 1190 = 0x4a6 in decimal
        newLocation.y = 619; // 619 = 0x26b in decimal
        closeButton.SetLocation(newLocation);

        controls.OnRender(); // render keybind window
    }

    closeButton.OnRender(); // render close button

    // Render dialogs and adjust tints
    if (!langChooser.bOpen && !wipeProfileDialog.bOpen) 
    {
        if (!restartRequiredDialog.bOpen) 
        {
            return;
        }
        CSurface::GL_RemoveColorTint();
    }
    else
    {
        CSurface::GL_RemoveColorTint();
        if (wipeProfileDialog.bOpen)
        {
            wipeProfileDialog.OnRender();
        }
        if (langChooser.bOpen)
        {
            langChooser.OnRender();
        }
    }

    if (restartRequiredDialog.bOpen) 
    {
        restartRequiredDialog.OnRender();
    }
    // End of orig-code
}

HOOK_METHOD_PRIORITY(OptionsScreen, CheckSelection, 1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> OptionsScreen::CheckSelection -> Begin (ControllerFunctionRewrites.cpp)\n")

    // code reverse engineered by Dino
    int choice = GetPotentialChoice();

    if (-1 < choice) // Validate choice to prevent segfault
    {
        // Handle choice
        if (choice == choiceFullscreen) 
        {
            Settings::ToggleFullScreen();
        } 
        else if (choice == choiceVSync) 
        {
            Settings::ToggleVSync();
        } 
        else if (choice == choiceFrameLimit) 
        {
            G_->GetSettings()->frameLimit ^= 1;
        } 
        else if (choice == choiceLowend) 
        {
            G_->GetSettings()->lowend ^= 1;
        } 
        else if (choice == choiceColorblind) 
        {
            G_->GetSettings()->colorblind ^= 1;
        } 
        else if (choice == choiceLanguage) 
        {
            langChooser.bOpen = true;
            langChooser.iChoice = -1;
        } 
        else if (choice == choiceDialogKeys) 
        {
            G_->GetSettings()->dialogKeys = (G_->GetSettings()->dialogKeys + 1) % 3;
        } 
        else if (choice == choiceShowPaths) 
        {
            G_->GetSettings()->showPaths ^= 1;
        } 
        else if (choice == choiceAchievementPopups) 
        {
            G_->GetSettings()->achPopups ^= 1;
        } 
        else if (choice == choiceAutoPause) 
        {
            G_->GetSettings()->altPause ^= 1;
        } 
        else if (choice == choiceTouchAutoPause) 
        {
            G_->GetSettings()->touchAutoPause ^= 1;
        } 
        else if (choice == choiceControls) 
        {
            bCustomizeControls = true;
        }
        
        // Updates the states visually in the menu 
        if (choice != choiceControls) 
        {
            Open(showWipeButton);
        }
    }
    // End of orig-code
}

HOOK_METHOD_PRIORITY(OptionsScreen, Close, 1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> OptionsScreen::Close -> Begin (ControllerFunctionRewrites.cpp)\n")

    // code reverse engineered by Dino
    if (G_->GetSettings()->fullscreen != 1 || CSurface::IsFrameBufferSupported()) 
    {
        if (G_->GetSettings()->fullscreen == 3 && G_->GetSettings()->currentFullscreen != 3)
        {
            goto CloseWindow;
        }
    }
    else 
    {
        G_->GetSettings()->fullscreen = G_->GetSettings()->currentFullscreen;
    }

    G_->GetSettings()->currentFullscreen = G_->GetSettings()->fullscreen;

    CloseWindow:
    ChoiceBox::Close();
    // End of orig-code
}

HOOK_METHOD_PRIORITY(OptionsScreen, KeyDown, 9999, (SDLKey sym) -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> OptionsScreen::KeyDown -> Begin (ControllerFunctionRewrites.cpp)\n")

    // code reverse engineered by Dino

    /*
    Notes:
    0x1b corresponds to the escape key on your keyboard
    I improvised some code here because ghidra showed a mess
    Inlined some function calls that were literally just changing window visibility bools
    */

    if (!langChooser.bOpen && !wipeProfileDialog.bOpen) // Check if neither the language chooser nor the wipe profile dialog is open
    {
        // Check if the hotkey menu is open
        if (bCustomizeControls)
        {
            if (sym == 0x1b)
            {
                int selectedButton = controls.selectedButton;

                // Deselect button if one is selected
                if (selectedButton != -1)
                {
                    controls.buttons[controls.currentPage][selectedButton].state = 0;
                    controls.selectedButton = -1;
                    return true;
                }

                // Close the reset dialog if open
                if (controls.resetDialog.bOpen)
                {
                    controls.resetDialog.Close();
                    return true;
                }
            }
            else if (sym - 0x12fU < 2) // Unsure what this really does - probably an alternative for the escape key
            {
                auto &buttons = controls.buttons[controls.currentPage];
                for (auto &button : buttons)
                {
                    if (button.state == 2)
                    {
                        Settings::SetHotkey(button.value, sym);
                        button.state = 0;
                    }
                }
            }

            // Exit if the Escape key is pressed
            if (sym == 0x1b)
            {
                bCustomizeControls = false;
                return false;
            }

            return false;
        }
        else
        {
            // Close the current window if the Escape key is pressed
            if (sym == 0x1b)
            {
                bOpen = false;
            }
            else
            {
                // Handling they key further
                ChoiceBox::KeyDown(sym);
            }
            return false;
        }
    }
    else if (langChooser.bOpen && sym == 0x1b) // Close language chooser on Escape key input
    {
        langChooser.bOpen = false;
    }
    else if (wipeProfileDialog.bOpen) // Close profile dialog if open
    {
        wipeProfileDialog.bOpen = false;
    }

    return false;
    // End of orig-code
}
