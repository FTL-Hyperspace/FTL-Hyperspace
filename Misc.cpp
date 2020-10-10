#include "Global.h"
#include "ASMHooks.h"
#include "CustomCrew.h"

HOOK_METHOD(CrewEquipBox, RemoveItem, () -> int)
{
    int ret = super();
    G_->GetSoundControl()->PlaySoundMix("airLoss", -1.f, false);
    return ret;
}

static int testVal = 0;

HOOK_METHOD(CApp, OnKeyDown, (SDLKey key) -> void)
{
    if (key == SDLKey::SDLK_LEFTBRACKET) testVal -= 1;
    if (key == SDLKey::SDLK_RIGHTBRACKET) testVal += 1;

    if (key == SDLKey::SDLK_KP_MINUS)
    {
    }
    if (key == SDLKey::SDLK_KP_PLUS)
    {
        std::string species = CustomCrewManager::GetInstance()->GetBlueprintNames()[testVal % CustomCrewManager::GetInstance()->GetBlueprintNames().size()];

        for (auto i : G_->GetWorld()->playerShip->shipManager->vCrewList)
        {
        }

        testVal++;
    }

    super(key);
}

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
