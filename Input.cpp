#include "Global.h"
#include "CustomCommandGui.h"

static void OnScrollWheel(float direction)
{
    CApp *cApp = G_->GetCApp();

    if (!cApp->langChooser.bOpen)
    {
        if (!cApp->menu.bOpen)
        {
            CustomCommandGui::GetInstance()->OnScrollWheel(direction);
        }
    }
}

HOOK_METHOD(CEvent, OnEvent, (const InputEvent* inputEvent) -> void)
{
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
