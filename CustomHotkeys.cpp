#include "CustomHotkeys.h"

static std::vector<CustomHotkey> customHotkeys =
{
    {"weapon1", SDLKey::SDLK_1, 1, 8},
    {"weapon2", SDLKey::SDLK_2, 1, 9},
    {"weapon3", SDLKey::SDLK_3, 1, 10},
    {"weapon4", SDLKey::SDLK_4, 1, 11},
    {"drone4", SDLKey::SDLK_8, 1, 15},
    {"drone5", SDLKey::SDLK_9, 1, 16},
    {"drone6", SDLKey::SDLK_0, 1, 17},
    {"console", SDLKey::SDLK_BACKSLASH, 0, 21},
    {"speed", SDLKey::SDLK_BACKQUOTE, 0, 22},
    {"info", SDLKey::SDLK_RALT, 0, 11},
    {"temporal", SDLKey::SDLK_SEMICOLON, 2, 11},
    {"un_temporal", SDLKey::SDLK_UNKNOWN, 2, -1},
    {"temporal_speed", SDLKey::SDLK_PERIOD, 1, 8},
    {"temporal_slow", SDLKey::SDLK_COMMA, 1, 9},
    {"aim_artillery1", SDLKey::SDLK_UNKNOWN, 3, 8},
    {"aim_artillery2", SDLKey::SDLK_UNKNOWN, 3, 9},
    {"aim_artillery3", SDLKey::SDLK_UNKNOWN, 3, -1},
    {"aim_artillery4", SDLKey::SDLK_UNKNOWN, 3, -1}
};

HOOK_METHOD(ControlsScreen, OnInit, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ControlsScreen::OnInit -> Begin (CustomHotkeys.cpp)\n")
    for (int i = 0; i < 4; i++)
    {
        buttons[i].clear();
    }

    super();

    Point origin = Point(480, 130);
    int btnsPerColumn = 10;
    for (int page = 0; page < 3; page++)
    {
        if (page == 0)
        {
            btnsPerColumn = 12;
        }
        else if (page == 1)
        {
            btnsPerColumn = 10;
        }
        else if (page == 2)
        {
            btnsPerColumn = 12;
        }

        for (int i = 0; i < buttons[page].size(); i++)
        {
            auto& button = buttons[page][i];

            button.rect.x = origin.x + ((i >= btnsPerColumn) ? 440 : 0);
            button.rect.y = origin.y + (40 * (i >= btnsPerColumn ? i - btnsPerColumn : i));
        }
    }

    // Ugly fix for the rightclick button hotkey, might look for a better approach in the future
    #ifdef __APPLE__
    this->buttons[0][24].rect.x += 44;
    this->buttons[0][24].rect.y += 13;
    /*
    // A more Dynamic approach (keep this to track the button if its index ever changes in the future)
    for (size_t i = 0; i < this->buttons[0].size(); ++i)
    {
        ControlButton& button = this->buttons[0][i];
        if (button.value == "rightclick")
        {
            std::cout << "Button index: " << i << std::endl;
            button.rect.w += 100;
            break;
        }
    }
    */
    #endif
}

/*
// Fully working rewrite, couldn't achieve my goal with it though. Commented out therefore 
HOOK_METHOD_PRIORITY(ControlsScreen, OnRender, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ControlsScreen::OnRender -> Begin (CustomHotkeys.cpp)\n")

    if (this->resetDialog.bOpen)
    {
        CSurface::GL_SetColorTint(COLOR_TINT);
    }

    GL_Texture* ImageId = G_->GetResources()->GetImageId("box_options_configure_tab.png");
    float size_x;
    float size_y;
    float width;
    if (ImageId)
    {
        // Begin: inline int height(GL_Texture* this)
        // Begin: inline int width(GL_Texture* this)
        size_y = (float)ImageId->height_;
        width = (float)ImageId->width_;
    }
    else
    {
        size_y = 1.0;
        width = 1.0;
    }

    std::string tabText = G_->GetTextLibrary()->GetText("configure_controls_tab");
    size_x = roundf(freetype::easy_measurePrintLines(63,0.0,0.0,999, tabText).x);
    this->customBox->WindowFrame::Draw(128);

    CSurface::GL_BlitImagePartial(ImageId, 123.0f, 70.0f, 39.0f, size_y, 0.0f, 39.0f / width, 0.0f, 1.0f, 1.0f, COLOR_WHITE, false);
    CSurface::GL_BlitImagePartial(ImageId, 162.0f, 70.0f, (float)((int)size_x - 16), size_y, 39.0f / width, 40.0f / width, 0.0f, 1.0f, 1.0f, COLOR_WHITE, false);
    CSurface::GL_BlitImagePartial(ImageId, (float)((int)size_x + 146), 70.0f, 51.0f, size_y, 40.0f / width, 91.0f / width, 0.0f, 1.0f, 1.0f, COLOR_WHITE, false);

    CSurface::GL_SetColor(COLOR_BUTTON_TEXT);
    freetype::easy_print(63, 154.0f, 81.0f, tabText);

    CSurface::GL_SetColor(COLOR_WHITE);
    for (ControlButton hotkeyField : this->buttons[this->currentPage])
    {
        hotkeyField.OnRender();
    }
    this->defaultButton.TextButton::OnRender();

    Button* currentButton = this->pageButtons;
    uint8_t buttonToRender = 1;
    do
    {
        currentButton->Button::OnRender();
        
        int buttonX = currentButton->position.x;
        int buttonY = currentButton->position.y;
        CSurface::GL_SetColor(COLOR_BUTTON_TEXT);
        freetype::easy_printCenter(62, (float)(buttonX + 37), (float)(buttonY + 7), std::to_string(buttonToRender));
        
        currentButton++;
        buttonToRender++;
    } while(buttonToRender != 5);

    CSurface::GL_SetColor(COLOR_WHITE);
    {
        if (1 < this->currentPage)
        {
            freetype::easy_print(12, 467.0f, 625.0f, G_->GetTextLibrary()->GetText("power_note"));
        }
    }

    if (this->resetDialog.bOpen)
    {
        CSurface::GL_RemoveColorTint();
        this->resetDialog.ConfirmWindow::OnRender();
    }
}
*/

HOOK_STATIC(Settings, ResetHotkeys, () -> void)
{
    LOG_HOOK("HOOK_STATIC -> Settings::ResetHotkeys -> Begin (CustomHotkeys.cpp)\n")
    super();

    SettingValues* settings = G_->GetSettings();

    for (auto i : customHotkeys)
    {
        HotkeyDesc hk = HotkeyDesc();
        hk.name = i.hotkeyName;
        hk.key = i.defaultValue;

        for (auto it = settings->hotkeys[i.page].begin(); it != settings->hotkeys[i.page].end(); ++it)
        {
            if (it->name == i.hotkeyName)
            {
                hk = *it;
                settings->hotkeys[i.page].erase(it);
                break;
            }
        }

        if (i.index == -1)
        {
            settings->hotkeys[i.page].push_back(hk);
        }
        else
        {
            settings->hotkeys[i.page].insert(settings->hotkeys[i.page].begin() + i.index, hk);
        }
    }
}

// TO BE REMOVED FOR 2.0
// A mistake made a version ago forced this backward compatibility fix in order to not break text_misc.xml data that should have just been updated with the new ID instead
// beware that the prefix "hotkey_artillery" will always break the power artillery hotkey
HOOK_METHOD(TextLibrary, GetText, (const std::string &name, const std::string &lang) -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> TextLibrary::GetText -> Begin (CustomHotkeys.cpp)\n")

    std::string ret = super(name, lang);
    if (ret.find("Could not find:") != std::string::npos && (name == "hotkey_aim_artillery1" || name == "hotkey_aim_artillery2" || name == "hotkey_aim_artillery3" || name == "hotkey_aim_artillery4"))
        ret = super("hotkey_artillery" + name.substr(20), lang);
    return ret;
}
