#include "Global.h"
#include "ASMHooks.h"
#include "CustomCrew.h"
#include "ShipUnlocks.h"

// Plays airlock sound when crew have been "dismissed"

HOOK_METHOD(CrewEquipBox, RemoveItem, () -> int)
{
    int ret = super();
    G_->GetSoundControl()->PlaySoundMix("airLoss", -1.f, false);
    return ret;
}



// Doesn't do anything, but I usually use this to test random stuff by changing what the numpad buttons do

static int testVal = 0;

HOOK_METHOD(CApp, OnKeyDown, (SDLKey key) -> void)
{
    if (key == SDLKey::SDLK_LEFTBRACKET) testVal -= 1;
    if (key == SDLKey::SDLK_RIGHTBRACKET) testVal += 1;

    if (key == SDLKey::SDLK_KP_MINUS)
    {
        testVal--;
    }
    if (key == SDLKey::SDLK_KP_PLUS)
    {
        testVal++;
    }

    super(key);
}



// Don't display low O2 warning if ship does not have an oxygen system

static bool displayWarning = true;

HOOK_METHOD(ShipStatus, RenderEvadeOxygen, (bool unk) -> void)
{
    if (!ship->HasSystem(ShipSystem::NameToSystemId("oxygen")) && ship->GetOxygenPercentage() <= 24)
    {
        displayWarning = false;
        oxygenMessage->flash = false;
    }

    super(unk);

    displayWarning = true;
    oxygenMessage->flash = true;
}

HOOK_METHOD(WarningMessage, OnRender, () -> void)
{
    if (displayWarning)
    {
        super();
    }
}
