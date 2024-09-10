#include "Global.h"

HOOK_METHOD_PRIORITY(OptionsScreen, constructor, 1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> OptionsScreen::constructor -> Begin (ControllerFunctionRewrites.cpp)\n")

    super();
}

HOOK_METHOD(OptionsScreen, OnLanguageChange, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> OptionsScreen::OnLanguageChange -> Begin (ControllerFunctionRewrites.cpp)\n")

    super();

    OnInit(); // Reconstruct buttons with new language
}

HOOK_METHOD_PRIORITY(OptionsScreen, OnInit, 1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> OptionsScreen::OnInit -> Begin (ControllerFunctionRewrites.cpp)\n")

    // code reverse engineered by Dino

    // Set sound volume
    float soundVolume = G_->GetSoundControl()->GetSoundVolume();
    float musicVolume = G_->GetSoundControl()->GetMusicVolume();
    this->soundVolume.marker.x = static_cast<int>(this->soundVolume.minMax.first + soundVolume * (this->soundVolume.minMax.second - this->soundVolume.minMax.first));
    this->musicVolume.marker.x = static_cast<int>(this->musicVolume.minMax.first + musicVolume * (this->musicVolume.minMax.second - this->musicVolume.minMax.first));

    // Holder variables
    TextString empty = TextString();
    TextString label = TextString();

    // Static link to text library
    TextLibrary *textLibrary = G_->GetTextLibrary();

    // Initialize controls
    controls.OnInit();

    // Initialize restart required dialog
    restartRequiredDialog.bOpen = false;
    restartRequiredDialog.selectedChoice = -1;

    // Initialize language chooser
    langChooser.bOpen = false;
    langChooser.OnInit();

    // Initialize close button
    label.data = textLibrary->GetText("button_close", textLibrary->currentLanguage);
    closeButton.OnInit(Point(30, 148), Point(103, 32), 4, &label, 63);
    closeButton.SetBaseImage("storeUI/store_close_base.png", Point(-23, -7), 103);
    closeButton.SetAutoWidth(true, false, 3, 0);

    // Initialize wipe profile button
    label.data = textLibrary->GetText("button_delete_profile", textLibrary->currentLanguage);
    wipeProfileButton.OnInit(Point(251, 474), Point(131, 60), 8, &label, 63);
    wipeProfileButton.lineHeight = (textLibrary->currentLanguage == "ja") ? 28 : 26;
    wipeProfileButton.textYOffset = -2;
    wipeProfileButton.SetBaseImage("optionsUI/button_deleteprofile_base.png", Point(-15, -15), 131);
    wipeProfileButton.SetAutoWidth(true, true, 4, 0);

    // Initialize the "Sync Achievements" button - (removed steam feature)
    #ifdef STEAM_1_6_13_BUILD
    label.data = textLibrary->GetText("button_sync_achievements", textLibrary->currentLanguage);
    Steam1613OptionsScreenStructAdditions steam;
    steam.syncAchievementsButton.OnInit(Point(-46, 186), Point(131, 60), 8, &label, 63);
    steam.syncAchievementsButton.lineHeight = (G_->GetTextLibrary()->currentLanguage == "ja") ? 28 : 26;
    steam.syncAchievementsButton.textYOffset = -2;
    steam.syncAchievementsButton.SetBaseImage("optionsUI/button_deleteprofile_base.png", Point(-15, -15), 131);
    steam.syncAchievementsButton.SetAutoWidth(true, true, 4, 0);
    #endif

    // Configure confirm wipe profile dialog
    label.data = textLibrary->GetText("confirm_wipe_profile", textLibrary->currentLanguage);
    empty.data = "";
    wipeProfileDialog.Close();
    wipeProfileDialog.SetText(label, 240, true, empty, empty);
    // End of orig-code
}

HOOK_METHOD_PRIORITY(OptionsScreen, OnLoop, 1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> OptionsScreen::OnLoop -> Begin (ControllerFunctionRewrites.cpp)\n")

    // code reverse engineered by Dino

    /*
    // Handle steam achievement sync button visibility
    #ifdef STEAM_1_6_13_BUILD
    Steam1613OptionsScreenStructAdditions steam;
    steam.showSyncAchievements = G_->GetAchievementTracker()->IsReadyToSync();
    #endif
    */

    // Handle sound/music volume 
    float soundVolumeRatio = static_cast<float>(this->soundVolume.marker.x - this->soundVolume.minMax.first) / static_cast<float>(this->soundVolume.minMax.second - this->soundVolume.minMax.first);
    G_->GetSoundControl()->SetSoundVolume(soundVolumeRatio);
    float musicVolumeRatio = static_cast<float>(this->musicVolume.marker.x - this->musicVolume.minMax.first) / static_cast<float>(this->musicVolume.minMax.second - this->musicVolume.minMax.first);
    G_->GetSoundControl()->SetMusicVolume(musicVolumeRatio);

    // Handle Hotkey Menu stuff
    std::vector<ControlButton> &hotkeyButtons = controls.buttons[controls.currentPage];
    for (ControlButton &button : hotkeyButtons)
    {
        SDLKey currentHotkey = Settings::GetHotkey(button.value);

        std::string hotkeyDisplay = (currentHotkey == 0) ? "----" : Settings::GetHotkeyName(button.value);
        button.key = hotkeyDisplay;
    }

    // Update option screen if fullscreen changed 
    if (!bCustomizeControls && lastFullScreen != G_->GetSettings()->fullscreen)
    {
        Open(showWipeButton);
    }

    // Handle language menu stuff
    if (langChooser.bOpen)
    {
        langChooser.OnLoop();

        if (!langChooser.bOpen)
        {
            Open(showWipeButton);
        }
    }

    // Handle restart required window
    if (restartRequiredDialog.bOpen)
    {
        int8_t choice = restartRequiredDialog.GetChoice();

        if (choice != -1)
        {
            bOpen = false;
            return;
        }
    }
    // End of orig-code
}

HOOK_METHOD_PRIORITY(OptionsScreen, OnRender, 1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> OptionsScreen::OnRender -> Begin (ControllerFunctionRewrites.cpp)\n")

    // code reverse engineered by Dino
    
    // Satic link to text library
    TextLibrary *textLibrary = G_->GetTextLibrary();

    // Internal Vars
    Point newLocation;
    std::string localizedText;
    int16_t closeButtonX, closeButtonY;
    int16_t baseX = position.x;
    int16_t baseY = position.y;

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
            localizedText = textLibrary->GetText("restart_required", textLibrary->currentLanguage);
            freetype::easy_print(13, baseX + 145, baseY + 20, localizedText);
        }

        CSurface::GL_SetColor(COLOR_WHITE);
        
        // render volume texts
        localizedText = textLibrary->GetText("sound_volume", textLibrary->currentLanguage);
        freetype::easy_printCenter(13, baseX + 156, baseY + 344, localizedText);

        localizedText = textLibrary->GetText("music_volume", textLibrary->currentLanguage);
        freetype::easy_printCenter(13, baseX + 156, baseY + 394, localizedText);

        // render volume sliders
        soundVolume.OnRender();
        musicVolume.OnRender();

        // wipe profile
        if (showWipeButton)
        {
            wipeProfileButton.OnRender();
        }

        // Steam achievement sync
        /*
        #ifdef STEAM_1_6_13_BUILD
        Steam1613OptionsScreenStructAdditions steam;
        if (steam.showSyncAchievements) 
        {
            steam.syncAchievementsButton.OnRender();
        }
        #endif
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

    SettingValues *settings = G_->GetSettings();

    int8_t choice = GetPotentialChoice();

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
            settings->frameLimit ^= 1;
        } 
        else if (choice == choiceLowend) 
        {
            settings->lowend ^= 1;
        } 
        else if (choice == choiceColorblind) 
        {
            settings->colorblind ^= 1;
        } 
        else if (choice == choiceLanguage) 
        {
            langChooser.bOpen = true;
            langChooser.iChoice = -1;
        } 
        else if (choice == choiceDialogKeys) 
        {
            settings->dialogKeys = (settings->dialogKeys + 1) % 3;
        } 
        else if (choice == choiceShowPaths) 
        {
            settings->showPaths ^= 1;
        } 
        else if (choice == choiceAchievementPopups) 
        {
            settings->achPopups ^= 1;
        } 
        else if (choice == choiceAutoPause) 
        {
            settings->altPause ^= 1;
        } 
        else if (choice == choiceTouchAutoPause) 
        {
            settings->touchAutoPause ^= 1;
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

HOOK_METHOD_PRIORITY(OptionsScreen, Open, 1000, (bool mainMenu) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> OptionsScreen::Open -> Begin (ControllerFunctionRewrites.cpp)\n")

    // code reverse engineered by Dino

    /*
    Notes:
    - Heavily changed the way strings are constructed for the option
      screen window by creating lambdas and writing a new function for
      the text library class to optimize the code and shorten it't length.
    - Original code sets the OptionsScreen::CheckSelection identifier
      vars several times which I did not do here either (optimisation).
    - I <3 optimisation!
    */

    // Static links
    SettingValues *settings = G_->GetSettings();
    TextLibrary *textLibrary = G_->GetTextLibrary();
    std::string currentLanguage = textLibrary->currentLanguage;
    /*
    #ifdef STEAM_1_6_13_BUILD
        Steam1613OptionsScreenStructAdditions steam;
    #endif
    */

    // Set some very relevant class values
    showWipeButton = mainMenu;
    bCustomizeControls = false;
    lastFullScreen = settings->fullscreen;
    /*
    #ifdef STEAM_1_6_13_BUILD
        steam.showSyncAchievements = G_->GetAchievementTracker()->IsReadyToSync();
    #endif
    */

    // Set identifier for OptionsScreen::CheckSelection
    choiceTouchAutoPause = -1;

    // Holder Variables:
    std::string optionText;
    std::string optionStatus;
    std::string formattedText;
    std::vector<ChoiceText> firstColumn;
    std::vector<ChoiceText> secondColumn;

    // String constructor Lambdas
    std::function<std::string(bool)> getOnOffText = [&](bool condition) -> std::string
    {
        return textLibrary->GetText(condition ? "on" : "off");
    };

    std::function<std::string(bool)> getDisabledEnabledText = [&](bool condition) -> std::string
    {
        return textLibrary->GetText(condition ? "disabled" : "enabled");
    };

    std::function<std::string(const std::string&, const std::string&)> insertFormattedText = [&](const std::string& key, const std::string& status) -> std::string
    {
        return textLibrary->InsertText(textLibrary->GetText(key), status);
    };

    // Construct fullscreen option
    choiceFullscreen = 0;
    optionStatus = textLibrary->GetText("fullscreen_" + std::to_string(settings->fullscreen));
    formattedText = insertFormattedText("fullscreen", optionStatus);
    firstColumn.emplace_back(0, formattedText, ResourceEvent());

    // Construct VSync option
    choiceVSync = 1;
    formattedText = insertFormattedText("v_sync", getOnOffText(settings->vsync));
    firstColumn.emplace_back(0, formattedText, ResourceEvent());

    // Construct frame-limit option
    choiceFrameLimit = 2;
    formattedText = insertFormattedText("frame_limit", getOnOffText(settings->frameLimit));
    firstColumn.emplace_back(0, formattedText, ResourceEvent());

    // Construct dynamic-background option
    choiceLowend = 3;
    formattedText = insertFormattedText("dynamic_back", getOnOffText(!settings->lowend));
    firstColumn.emplace_back(0, formattedText, ResourceEvent());

    // Construct colorblind option
    choiceColorblind = 4;
    formattedText = insertFormattedText("colorblind", getDisabledEnabledText(!settings->colorblind));
    firstColumn.emplace_back(0, formattedText, ResourceEvent());

    // Construct language option
    choiceLanguage = 5;
    optionText = textLibrary->GetText("change_language");
    firstColumn.emplace_back(0, optionText, ResourceEvent());

    //               //
    // SECOND COLUMN //
    //               //

    // Construct event-choice-input-delay option
    choiceDialogKeys = 6;
    switch (settings->dialogKeys)
    {
        case 0:
            optionStatus = textLibrary->GetText("event_choice_disable_hotkeys");
            break;
        case 1:
            optionStatus = textLibrary->GetText("event_choice_brief_delay");
            break;
        case 2:
            optionStatus = textLibrary->GetText("event_choice_no_delay");
            break;
    }
    formattedText = insertFormattedText("event_choice", optionStatus);
    secondColumn.emplace_back(0, formattedText, ResourceEvent());

    // Construct show-map-paths option
    choiceShowPaths = 7;
    formattedText = insertFormattedText("show_paths", getDisabledEnabledText(!settings->showPaths));
    secondColumn.emplace_back(0, formattedText, ResourceEvent());

    // Construct achievement-popup option
    choiceAchievementPopups = 8;
    formattedText = insertFormattedText("achievement_popup", getDisabledEnabledText(!settings->achPopups));
    secondColumn.emplace_back(0, formattedText, ResourceEvent());

    // Construct window-focus-auto-pause option
    if (settings->fullscreen == 0)
    {
        choiceAutoPause = 9;
        choiceControls = 10;
        formattedText = insertFormattedText("window_focus", getOnOffText(settings->altPause));
        secondColumn.emplace_back(0, formattedText, ResourceEvent());
    }
    else
    {
        choiceControls = 9;
    }

    // Construct keybind-menu option
    optionText = textLibrary->GetText("configure_controls");
    secondColumn.emplace_back(0, optionText, ResourceEvent());

    // Initialize option screen
    std::string empty = "";
    ChoiceBox::SetChoices(&empty, &firstColumn, &secondColumn);

    // Vector clea-up
    firstColumn.clear();
    secondColumn.clear();

    // Update sound volume based on current settings
    if (!bOpen)
    {
        float soundVolume = G_->GetSoundControl()->GetSoundVolume();
        float musicVolume = G_->GetSoundControl()->GetMusicVolume();
        this->soundVolume.marker.x = static_cast<int>(this->soundVolume.minMax.first + soundVolume * (this->soundVolume.minMax.second - this->soundVolume.minMax.first));
        this->musicVolume.marker.x = static_cast<int>(this->musicVolume.minMax.first + musicVolume * (this->musicVolume.minMax.second - this->musicVolume.minMax.first));
    }

    bOpen = true; // This basically opens the options window
    // End of orig-code
}

HOOK_METHOD_PRIORITY(OptionsScreen, Close, 1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> OptionsScreen::Close -> Begin (ControllerFunctionRewrites.cpp)\n")

    // code reverse engineered by Dino
    SettingValues *settings = G_->GetSettings();
    if (settings->fullscreen != 1 || CSurface::IsFrameBufferSupported()) 
    {
        if (settings->fullscreen == 3 && settings->currentFullscreen != 3)
        {
            goto CloseWindow;
        }
    }
    else 
    {
        settings->fullscreen = settings->currentFullscreen;
    }

    settings->currentFullscreen = settings->fullscreen;

    CloseWindow:
    ChoiceBox::Close();
    // End of orig-code
}

HOOK_METHOD_PRIORITY(OptionsScreen, MouseMove, 1000, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> OptionsScreen::MouseMove -> Begin (ControllerFunctionRewrites.cpp)\n")

    // code reverse engineered by Dino
    if (!langChooser.bOpen)
    {
        if (wipeProfileDialog.bOpen)
        {
            // Handles wipe profile confirm window hover stuff
            wipeProfileDialog.MouseMove(x, y);
            return;
        }

        if (!restartRequiredDialog.bOpen)
        {
            closeButton.MouseMove(x, y, false);
            
            if (!bCustomizeControls)
            {
                
                if (showWipeButton)
                {
                    // Handles the hovering of the wipe profile button
                    wipeProfileButton.MouseMove(x, y, false);
                }

                /*
                #ifdef STEAM_1_6_13_BUILD
                Steam1613OptionsScreenStructAdditions steam;
                if (steam.showSyncAchievements) 
                {
                    steam.syncAchievementsButton.MouseMove(x, y, false);
                }
                #endif
                */

                // Tells the game where the cursor is so it knows which texts to highlight
                ChoiceBox::MouseMove(x, y);

                /*
                Unused Vanilla code - Reports back if a resolution mode is supported when hovering it (kinda broken)
                if (choiceBoxes.size() > 0 && choiceBoxes[0].x <= x && x <= choiceBoxes[0].x + choiceBoxes[0].w && choiceBoxes[0].y <= y && y <= choiceBoxes[0].y + choiceBoxes[0].h) 
                {
                    if (!G_->GetSettings()->manualResolution)
                    {
                        std::string tooltipID = (G_->GetSettings()->fullscreen == 1 || !CSurface::IsFrameBufferSupported()) ? "stretch_not_supported" : "manual_override";
                        std::string tooltip = G_->GetTextLibrary()->GetText(tooltipID, G_->GetTextLibrary()->currentLanguage);
                        G_->GetMouseControl()->SetTooltip(tooltip);
                        G_->GetMouseControl()->InstantTooltip();
                    }
                }
                */

                // Handles the sound volume slider stuff
                if (!soundVolume.holding)
                {
                    // Checks if the slider is hovered
                    bool isHovering =  x > soundVolume.marker.x && x < soundVolume.marker.x + soundVolume.marker.w && y > soundVolume.marker.y && y < soundVolume.marker.y + soundVolume.marker.h;
                    soundVolume.hovering = isHovering;
                }
                else
                {
                    // Handles the movement of the slider
                    int16_t newMarkerX = (x - soundVolume.mouseStart.x) + soundVolume.rectStart.x;

                    if (newMarkerX < soundVolume.minMax.first)
                    {
                        newMarkerX = soundVolume.minMax.first;
                    }
                    else if (newMarkerX > soundVolume.minMax.second)
                    {
                        newMarkerX = soundVolume.minMax.second;
                    }

                    soundVolume.marker.x = newMarkerX;
                }

                // Handles the music volume slider stuff
                if (!musicVolume.holding)
                {
                    // Checks if the slider is hovered
                    bool isHovering = x > musicVolume.marker.x && x < musicVolume.marker.x + musicVolume.marker.w && y > musicVolume.marker.y && y < musicVolume.marker.y + musicVolume.marker.h;
                    musicVolume.hovering = isHovering;
                }
                else
                {
                    // Handles the movement of the slider
                    int16_t newMarkerX = (x - musicVolume.mouseStart.x) + musicVolume.rectStart.x;

                    if (newMarkerX < musicVolume.minMax.first)
                    {
                        newMarkerX = musicVolume.minMax.first;
                    }
                    else if (newMarkerX > musicVolume.minMax.second)
                    {
                        newMarkerX = musicVolume.minMax.second;
                    }

                    musicVolume.marker.x = newMarkerX;
                }

            }
            else
            {
                // Tells the game what is hovered in the controls menu
                controls.MouseMove(x, y);
            }
        }
        else
        {
            // Tells the game what is hovered in the restart required box
            restartRequiredDialog.MouseMove(x, y);
        }
    }
    else
    {
        // Handles the hovering of the language buttons in the lang menu
        std::vector<TextButton*> locButtons = langChooser.buttons;
        for (uint8_t buttonIndex = 0; buttonIndex < locButtons.size(); ++buttonIndex) 
        {
            locButtons[buttonIndex]->MouseMove(x, y, false);
        }
    }
    // End of orig-code
}

HOOK_METHOD_PRIORITY(OptionsScreen, MouseClick, 1000, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> OptionsScreen::MouseClick -> Begin (ControllerFunctionRewrites.cpp)\n")

    // code reverse engineered by Dino
    if (!langChooser.bOpen) 
    {
        if (!wipeProfileDialog.bOpen) 
        {
            // Restart required window logic
            if (restartRequiredDialog.bOpen) 
            {
                restartRequiredDialog.MouseClick(x, y);
                return;
            }

            // Close button handling 
            if (!closeButton.bActive || !closeButton.bHover) 
            {
                if (!bCustomizeControls) 
                {
                    // Handle various buttons and the sound sliders
                    if (wipeProfileButton.bActive && wipeProfileButton.bHover && showWipeButton) 
                    {
                        wipeProfileDialog.Open();
                    }
                    
                    // Handle Steam achievement sync button
                    /*
                    #ifdef STEAM_1_6_13_BUILD
                    Steam1613OptionsScreenStructAdditions steam;
                    if (steam.syncAchievementsButton.bActive && steam.syncAchievementsButton.bHover && steam.showSyncAchievements) 
                    {
                        G_->GetAchievementTracker()->SyncAchievements();
                    }
                    #endif
                    */

                    // Volume slider handling
                    soundVolume.MouseClick(x, y);
                    musicVolume.MouseClick(x, y);
                    CheckSelection();
                    return;
                }
                else
                {
                    controls.MouseClick(x, y); // Handle customize controls logic
                }
            }
            else if (!bCustomizeControls) 
            {
                // Restart required dialog window and close click handled here
                if (G_->GetSettings()->currentFullscreen != 3 && G_->GetSettings()->fullscreen == 3)
                {
                    std::vector<ChoiceText> choices1;
                    std::vector<ChoiceText> choices2;
                    std::string restartDialogText = G_->GetTextLibrary()->GetText("restart_required_dialog", G_->GetTextLibrary()->currentLanguage);
                    restartRequiredDialog.SetChoices(&restartDialogText, &choices1, &choices2);
                    restartRequiredDialog.bOpen = true;
                }
                else
                {
                    Close();
                }
            }
            else 
            {
                // Handle option button clicks
                int8_t selectedButton = controls.selectedButton;
                if (selectedButton != -1) 
                {
                    controls.buttons[controls.currentPage][selectedButton].state = 0;
                    controls.selectedButton = -1;
                }
                bCustomizeControls = false;
            }
        }
        else 
        {
            // Handle wipe profile confirm window click
            wipeProfileDialog.MouseClick(x, y);
            if (!wipeProfileDialog.bOpen && wipeProfileDialog.result)
            {
                G_->GetScoreKeeper()->WipeProfile(true);
            }
        }
    }
    else 
    {
        // Handle language chooser button clicks
        std::vector<TextButton*> locButtons = langChooser.buttons;
        for (uint8_t buttonIndex = 0; buttonIndex < locButtons.size(); ++buttonIndex) 
        {
            if (locButtons[buttonIndex]->bActive && locButtons[buttonIndex]->bHover)
            {
                langChooser.iChoice = buttonIndex;
                break;
            }
        }
    }
    // End of orig-code
}

HOOK_METHOD_PRIORITY(OptionsScreen, KeyDown, 1000, (SDLKey sym) -> bool)
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
                int16_t selectedButton = controls.selectedButton;

                // Deselect the hotkey and set it to its previous key
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
            else if (sym != 0x1b) // Bind the the pressed key to the selected hotkey if wasn't the escape key
            {
                std::vector<ControlButton> &hotkeyButtons = controls.buttons[controls.currentPage];
                for (ControlButton &button : hotkeyButtons)
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

/*  
// Not hooking these for now because they seem to be unused in the code
HOOK_METHOD_PRIORITY(OptionsScreen, destructor1, 1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> OptionsScreen::destructor1 -> Begin (ControllerFunctionRewrites.cpp)\n")

    super();
}

HOOK_METHOD_PRIORITY(OptionsScreen, destructor2, 1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> OptionsScreen::destructor2 -> Begin (ControllerFunctionRewrites.cpp)\n")

    super();
} 
*/
