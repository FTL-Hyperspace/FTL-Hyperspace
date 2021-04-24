#include "CustomHotkeys.h"

static std::vector<CustomHotkey> customHotkeys =
{
    {"console", SDLKey::SDLK_l, 1},
    {"speed", SDLKey::SDLK_BACKQUOTE, 1},
    {"info", SDLKey::SDLK_LALT, 1}
};






HOOK_STATIC(Settings, ResetHotkeys, () -> void)
{
    super();

    SettingValues* settings = G_->GetSettings();

    for (auto i : customHotkeys)
    {
        HotkeyDesc hk = HotkeyDesc();
        hk.name = i.hotkeyName;
        hk.key = i.defaultValue;

        settings->hotkeys[i.page].push_back(hk);
    }
}
