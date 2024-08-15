#if defined(__linux__)
#include <SDL2/SDL.h>
#include <SDL2/SDL_gamecontroller.h>
#endif

#include "Global.h"
#include "CustomCommandGui.h"
#include "CustomCrewManifest.h"
#include "ShipZoom.h"
#include "ScrollingChoiceBox.h"

static void OnScrollWheel(float direction)
{
    CApp *cApp = G_->GetCApp();

    if (!cApp->langChooser.bOpen)%
    {
        if (!cApp->menu.bOpen)
        {
            if (ScrollingChoiceBox::OnScrollWheel(direction))
            {

            }
            else if (cApp->gui->crewScreen.bOpen)
            {
                CustomCrewManifest::GetInstance()->OnScrollWheel(direction);
            }
            else
            {
                CustomCommandGui::GetInstance()->OnScrollWheel(direction);
            }
        }
    }
}

HOOK_METHOD(CEvent, OnEvent, (const InputEvent* inputEvent) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CEvent::OnEvent -> Begin (Input.cpp)\n")

    if (inputEvent->type == InputEventType::INPUT_EVENT_MOUSE)
    {
        MouseInputEvent *mEvent = (MouseInputEvent*)(&inputEvent->event);

        if (mEvent->scroll != 0.f)
        {
            OnScrollWheel(mEvent->scroll);
        }
    }
    super(inputEvent);
}

HOOK_GLOBAL(input_update, () -> void)
{
    LOG_HOOK("HOOK_GLOBAL -> input_update -> Begin (Input.cpp)\n");
    hs_log_file("Generischer Ausgabetest\n");

    // Initialize first available GameController (Index 0)
    SDL_GameController* controller = nullptr;
    if (SDL_IsGameController(0))
    {
        controller = SDL_GameControllerOpen(0);
        if (controller)
        {
            hs_log_file("GameController connected\n");

            // Check if a button is pressed
            if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A))
            {
                hs_log_file("Button A is pressed\n");
            }

            SDL_GameControllerClose(controller);
        }
        else
        {
            hs_log_file("GameController could not be initialized: %s\n", SDL_GetError());
        }
    }
    else
    {
        hs_log_file("No GameController connected\n");
    }

    super();
}

HOOK_METHOD(CApp, OnExecute, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnExecute -> Begin (Input.cpp)\n");

    if (SDL_Init(SDL_INIT_GAMECONTROLLER) != 0)
    {
        hs_log_file("SDL could not initialize: %s\n", SDL_GetError());
        return;
    }

    super();
}
