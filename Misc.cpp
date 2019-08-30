#include "Global.h"
#include "ASMHooks.h"

HOOK_METHOD(CrewEquipBox, RemoveItem, () -> int)
{
    int ret = super();
    std::string soundName("airLoss");
    G_->GetSoundControl()->PlaySoundMix(soundName, -1.f, false);
    return ret;
}

static int testVal = 0;

HOOK_METHOD(CApp, OnKeyDown, (SDLKey key) -> void)
{
    if (key == SDLKey::SDLK_LEFTBRACKET) testVal -= 1;
    if (key == SDLKey::SDLK_RIGHTBRACKET) testVal += 1;

    if (key == SDLKey::SDLK_KP_PLUS)
    {
        std::vector<std::string> vec = std::vector<std::string>();
        CrewMemberFactory::GetCrewNames(vec, G_->GetCrewFactory());

        for (auto const &name: vec)
        {
            printf("%s\n", name.c_str());
        }
    }

    super(key);
}

typedef std::pair<std::string, bool> std_pair_std_string_bool;
