#include "Global.h"
#include "CustomCommandGui.h"
#include "CustomCrewManifest.h"
#include "ShipZoom.h"
#include "ScrollingChoiceBox.h"
namespace DINO 
{
    #include "ControllerManager.h"
}

static void OnScrollWheel(float direction)
{
    CApp *cApp = G_->GetCApp();

    if (!cApp->langChooser.bOpen)
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

// Global variable for ControllerManager
DINO::ControllerManager controllerManager;

HOOK_METHOD(CApp, OnExecute, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnExecute -> Begin (Input.cpp)\n")

    // Initialise the controller
    if (controllerManager.Init())
    {
        hs_log_file("%sInitialized controller interface succesfull!\n", controllerManager.SDL_ID);
    }

    super();
}

HOOK_GLOBAL(input_update, () -> void)
{
    LOG_HOOK("HOOK_GLOBAL -> input_update -> Begin (Input.cpp)\n")

    // Handle Inputs from controller
    controllerManager.Update();

    super();
}

HOOK_METHOD(CApp, OnExit, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnExit -> Begin (Input.cpp)\n")

    // Close controller interface
    controllerManager.Shutdown();

    super();
}
