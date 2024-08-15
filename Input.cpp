#include "Global.h"
#include "CustomCommandGui.h"
#include "CustomCrewManifest.h"
#include "ShipZoom.h"
#include "ScrollingChoiceBox.h"

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
    if (inputEvent->type == InputEventType::INPUT_EVENT_JOYSTICK)
    {
        JoystickInputEvent *jEvent = (JoystickInputEvent*)(&inputEvent->event);

        if (jEvent->index != 0 || jEvent->index != 1)
        {
            hs_log_file("JOYSTICK EVENT:\n Device: %d - Index: %d - x-pos: %d - y-pos: %d \n", 
                        jEvent->device, jEvent->index, jEvent->x, jEvent->y);
        }
    }

    switch (inputEvent->detail)
    {
    case INPUT_JOYSTICK_CONNECTED:
        hs_log_file("\nController Connected \n");
        break;
    case INPUT_JOYSTICK_DISCONNECTED:
        hs_log_file("\nController Disconnected \n");
        break;
    case INPUT_JOYSTICK_BUTTON_DOWN:
        hs_log_file("\nController Button Pressed \n");
        break;
    case INPUT_JOYSTICK_BUTTON_UP:
        hs_log_file("\nController Button Released \n");
        break;
    case INPUT_JOYSTICK_DPAD_CHANGE:
        hs_log_file("\nController DPAD Interacted \n");
        break;
    case INPUT_JOYSTICK_STICK_CHANGE:
        hs_log_file("\nController Joystick Interacted \n");
        break;
    default:
        hs_log_file("\nNon-Controller Event: %d\n", inputEvent->detail);
        break;
    }

    super(inputEvent);
}

/*
struct InputEvent
{
  InputEventType type;
  InputEventDetail detail;
  double timestamp;
  InputEventUnion event;
};
*/