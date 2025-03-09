#include "Global.h"
#include "CustomCommandGui.h"
#include "CustomCrewManifest.h"
#include "ShipZoom.h"
#include "ScrollingChoiceBox.h"
#include "RedesignedTooltips.h"
#include "SystemBox_Extend.h"

static void OnScrollWheel(float direction)
{
    CApp *cApp = G_->GetCApp();

    if (!cApp->langChooser.bOpen)
    {
        if (!cApp->menu.bOpen)
        {
            if (ScrollingTooltip::OnScrollWheel(direction))
            {

            }
            else if (ScrollingChoiceBox::OnScrollWheel(direction))
            {

            }
            else if (cApp->gui->crewScreen.bOpen)
            {
                CustomCrewManifest::GetInstance()->OnScrollWheel(direction);
            }
            else if (cApp->gui->sysControl.OnScrollWheel(direction))
            {
                
            }
            else
            {
                CustomCommandGui::GetInstance()->OnScrollWheel(direction);
            }
        }
    }
}

bool SystemControl::OnScrollWheel(float direction)
{
    for (SystemBox* systemBox : sysBoxes)
    {
        SB_EX(systemBox)->OnScrollWheel(direction);
        /*
        TODO: Find better condition for system hovering for systems with complex UI
        if (systemBox->mouseHover)
        {
            SB_EX(systemBox)->OnScrollWheel(direction);
            return true;
        }
        */       
    }
    return false;
}
void SystemControl::RButtonUp(int mX, int mY, bool shiftHeld)
{
    for (SystemBox* systemBox : sysBoxes)
    {   
        SB_EX(systemBox)->RButtonUp(mX, mY, shiftHeld);    
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

HOOK_METHOD(CApp, OnRButtonUp, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnRButtonUp -> Begin (Input.cpp)\n")
    if (!langChooser.bOpen && !menu.bOpen)
    {
        Point pos = Point((int)((x - x_bar)*mouseModifier_x) - modifier_x, (int)((y - y_bar)*mouseModifier_y) - modifier_y);
        gui->sysControl.RButtonUp(pos.x, pos.y, shift_held);
    }
    super(x, y);
}