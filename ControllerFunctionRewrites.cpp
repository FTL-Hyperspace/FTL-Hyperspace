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
