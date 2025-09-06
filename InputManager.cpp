#include "InputManager.h"

void InputManager::StartInputSwitching(InputMethod requestingInput)
{
    int8_t& switchSource = *(reinterpret_cast<int8_t*>(&this->inputSwitch.running) + 0x1);
    if (!this->inputSwitch.Running() || switchSource != requestingInput)
    {
        this->inputSwitch = TimerHelper();
        this->inputSwitch.Start(0.51f);
        switchSource = requestingInput;
    }
    else if (this->inputSwitch.Running())
    {
        if (this->inputSwitch.currTime < 0.51f && switchSource == requestingInput)
        {
            this->inputSwitch.Stop();
            this->currentInputDevice = requestingInput;

            this->ReconstructMatrix(G_->GetCApp(), requestingInput);
        }
    }
}

void InputManager::ReconstructMatrix(CApp* cApp, InputMethod desiredInput)
{
    // Reconstruct the SysBoxes and wires as touch version if in-game
    if (!cApp->menu.bOpen && !cApp->menu.shipBuilder.bOpen) cApp->gui->sysControl.CreateSystemBoxes();

    // Reconstruct Starmap images to match touch versions
    StarMap& starMap = cApp->world->starMap;
    if (desiredInput == TOUCHSCREEN)
    {
        starMap.explored = Touch_explored;
        starMap.unexplored = Touch_unexplored;
        starMap.danger = Touch_danger;
        starMap.warning = Touch_warning;
        starMap.yellow_warning = Touch_yellow_warning;
        starMap.warning_shadow = Touch_warning_shadow;
        starMap.warning_circle = Touch_warning_circle;
        starMap.dottedLine = Touch_dottedLine;
    }
    else // PC and debug graphics (aswell as controller for now)
    {
        starMap.explored = PC_explored;
        starMap.unexplored = PC_unexplored;
        starMap.danger = PC_danger;
        starMap.warning = PC_warning;
        starMap.yellow_warning = PC_yellow_warning;
        starMap.warning_shadow = PC_warning_shadow;
        starMap.warning_circle = PC_warning_circle;
        starMap.dottedLine = PC_dottedLine;
    }
}


// --------------------------------------- //
// Allow, block & manage CApp input events //
// --------------------------------------- //

HOOK_METHOD(CApp, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnLoop -> Begin (TouchScreen.cpp)\n")

    InputManager* inputManager = InputManager::GetInstance();
    if (inputManager->inputSwitch.running)
    {
        if (inputManager->inputSwitch.currTime > 0.51f)
        {
            inputManager->inputSwitch.Stop();
            inputManager->inputSwitch.currTime = 0.f;
        }
        else
        {
            inputManager->inputSwitch.Update();
        }
    }

    super();
}

HOOK_METHOD_PRIORITY(CApp, OnTouchDown, 9999, (int id, int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnTouchDown -> Begin (TouchScreen.cpp)\n")

    InputManager* inputManager = InputManager::GetInstance();
    if (inputManager->currentInputDevice == InputManager::DEBUG) goto DebugSkip;
    if (inputManager->currentInputDevice != InputManager::TOUCHSCREEN)
    {
        inputManager->StartInputSwitching(InputManager::TOUCHSCREEN);
        return;
    }
    /**
    Top-level touch handling function.

    In the vanilla code this function was empty on the pc version
    so that touch inputs don't registered and can't be handled.
    This code of mine reconnects the top-level to individual low-level
    touch handling functions to enable touch on PC.
    */
DebugSkip:
    if (this->langChooser.bOpen)
    {
        this->langChooser.OnTouch(TOUCH_DOWN, id, x, y, x, y);
        return;
    }
    if (!this->menu.bOpen)
    {
        this->gui->OnTouch(TOUCH_DOWN, id, x, y, x, y);
        return;
    }
    this->menu.OnTouch(TOUCH_DOWN, id, x, y, x, y);
}

HOOK_METHOD_PRIORITY(CApp, OnTouchUp, 9999, (int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnTouchUp -> Begin (TouchScreen.cpp)\n")

    InputManager* inputManager = InputManager::GetInstance();
    if (inputManager->currentInputDevice == InputManager::DEBUG) goto DebugSkip;
    if (inputManager->currentInputDevice != InputManager::TOUCHSCREEN) return;
    /**
    Top-level touch handling function.

    In the vanilla code this function was empty on the pc version
    so that touch inputs don't registered and can't be handled.
    This code of mine reconnects the top-level to individual low-level
    touch handling functions to enable touch on PC.
    */
DebugSkip:
    if (this->langChooser.bOpen)
    {
        this->langChooser.OnTouch(TOUCH_UP, id, x, y, initialX, initialY);
        return;
    }
    if (!this->menu.bOpen)
    {
        this->gui->OnTouch(TOUCH_UP, id, x, y, initialX, initialY);
        return;
    }
    this->menu.OnTouch(TOUCH_UP, id, x, y, initialX, initialY);
}

HOOK_METHOD_PRIORITY(CApp, OnTouchMove, 9999, (int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnTouchMove -> Begin (TouchScreen.cpp)\n")

    InputManager* inputManager = InputManager::GetInstance();
    if (inputManager->currentInputDevice == InputManager::DEBUG) goto DebugSkip;
    if (inputManager->currentInputDevice != InputManager::TOUCHSCREEN) return;
    /**
    Top-level touch handling function.

    In the vanilla code this function was empty on the pc version
    so that touch inputs don't registered and can't be handled.
    This code of mine reconnects the top-level to individual low-level
    touch handling functions to enable touch on PC.
    */
DebugSkip:
    if (this->langChooser.bOpen)
    {
        this->langChooser.OnTouch(TOUCH_MOVE, id, x, y, initialX, initialY);
        return;
    }
    if (!this->menu.bOpen)
    {
        this->gui->OnTouch(TOUCH_MOVE, id, x, y, initialX, initialY);
        return;
    }
    this->menu.OnTouch(TOUCH_MOVE, id, x, y, initialX, initialY);
}

HOOK_METHOD_PRIORITY(CApp, OnTouchCancel, 9999, (int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnTouchCancel -> Begin (TouchScreen.cpp)\n")

    InputManager* inputManager = InputManager::GetInstance();
    if (inputManager->currentInputDevice == InputManager::DEBUG) goto DebugSkip;
    if (inputManager->currentInputDevice != InputManager::TOUCHSCREEN) return;
    /**
    Top-level touch handling function.

    In the vanilla code this function was empty on the pc version
    so that touch inputs don't registered and can't be handled.
    This code of mine reconnects the top-level to individual low-level
    touch handling functions to enable touch on PC.
    */
DebugSkip:
    if (this->langChooser.bOpen)
    {
        this->langChooser.OnTouch(TOUCH_CANCEL, id, x, y, initialX, initialY);
        return;
    }
    if (!this->menu.bOpen)
    {
        this->gui->OnTouch(TOUCH_CANCEL, id, x, y, initialX, initialY);
        return;
    }
    this->menu.OnTouch(TOUCH_CANCEL, id, x, y, initialX, initialY);
}

// Mouse/Keyboard input stuff
HOOK_METHOD_PRIORITY(CApp, OnLButtonDown, 9999, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnLButtonDown -> Begin (TouchScreen.cpp)\n")

    InputManager* inputManager = InputManager::GetInstance();
    if (inputManager->currentInputDevice == InputManager::DEBUG) goto DebugSkip;
    if (inputManager->currentInputDevice != InputManager::KEYBOARD)
    {
        inputManager->StartInputSwitching(InputManager::KEYBOARD);
        return;
    }
DebugSkip:
    // Rewrote super to avoid jumping back to original function
    int localX = static_cast<int>(static_cast<float>((mX - this->x_bar) * this->mouseModifier_x)) - this->modifier_x;
    int localY = static_cast<int>(static_cast<float>((mY - this->y_bar) * this->mouseModifier_y)) - this->modifier_y;
    if (this->langChooser.bOpen)
    {
        this->langChooser.MouseClick(localX, localY);
        return;
    }
    if (this->menu.bOpen)
    {
        this->menu.MouseClick(localX, localY);
        return;
    }
    this->gui->LButtonDown(localX, localY, this->shift_held);
}

HOOK_METHOD_PRIORITY(CApp, OnRButtonDown, 9999, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnRButtonDown -> Begin (TouchScreen.cpp)\n")

    InputManager* inputManager = InputManager::GetInstance();
    if (inputManager->currentInputDevice == InputManager::DEBUG) goto DebugSkip;
    if (inputManager->currentInputDevice != InputManager::KEYBOARD)
    {
        inputManager->StartInputSwitching(InputManager::KEYBOARD);
        return;
    }
DebugSkip:
    // Rewrote super to avoid jumping back to original function
    int localX = static_cast<int>(static_cast<float>((mX - this->x_bar) * this->mouseModifier_x)) - this->modifier_x;
    int localY = static_cast<int>(static_cast<float>((mY - this->y_bar) * this->mouseModifier_y)) - this->modifier_y;
    if (!this->langChooser.bOpen)
    {
        if (this->menu.bOpen)
        {
            this->menu.MouseRClick(localX, localY);
            return;
        }
        this->gui->RButtonDown(localX, localY, this->shift_held);
    }
}

HOOK_METHOD_PRIORITY(CApp, OnMButtonDown, 9999, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnMButtonDown -> Begin (TouchScreen.cpp)\n")

    InputManager* inputManager = InputManager::GetInstance();
    if (inputManager->currentInputDevice == InputManager::DEBUG) goto DebugSkip;
    if (inputManager->currentInputDevice != InputManager::KEYBOARD)
    {
        inputManager->StartInputSwitching(InputManager::KEYBOARD);
        return;
    }
DebugSkip:
    // Rewrote super to avoid jumping back to original function
    if (!this->langChooser.bOpen && !this->menu.bOpen)
    {
        this->gui->SpaceBar();
    }
}

HOOK_METHOD_PRIORITY(CApp, OnLButtonUp, 9999, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnLButtonUp -> Begin (TouchScreen.cpp)\n")

    InputManager* inputManager = InputManager::GetInstance();
    if (inputManager->currentInputDevice == InputManager::DEBUG) goto DebugSkip;
    if (inputManager->currentInputDevice != InputManager::KEYBOARD) return;
DebugSkip:
    // Rewrote super to avoid jumping back to original function
    int localX = static_cast<int>(static_cast<float>((mX - this->x_bar) * this->mouseModifier_x)) - this->modifier_x;
    int localY = static_cast<int>(static_cast<float>((mY - this->y_bar) * this->mouseModifier_y)) - this->modifier_y;
    if (!this->langChooser.bOpen)
    {
        if (this->menu.bOpen)
        {
            this->menu.MouseUp(localX, localY);
            return;
        }
        this->gui->LButtonUp(localX, localY, this->shift_held);
    }
}

HOOK_METHOD_PRIORITY(CApp, OnRButtonUp, 9999, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnRButtonUp -> Begin (TouchScreen.cpp)\n")

    InputManager* inputManager = InputManager::GetInstance();
    if (inputManager->currentInputDevice == InputManager::DEBUG) goto DebugSkip;
    if (inputManager->currentInputDevice != InputManager::KEYBOARD) return;
DebugSkip:
    // Rewrote super to avoid jumping back to original function
    int localX = static_cast<int>(static_cast<float>((mX - this->x_bar) * this->mouseModifier_x)) - this->modifier_x;
    int localY = static_cast<int>(static_cast<float>((mY - this->y_bar) * this->mouseModifier_y)) - this->modifier_y;
    if (!this->langChooser.bOpen && !this->menu.bOpen)
    {
        this->gui->RButtonUp(localX, localY, this->shift_held);
    }
}

HOOK_METHOD_PRIORITY(CApp, OnMouseMove, 9999, (int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnMouseMove -> Begin (TouchScreen.cpp)\n")

    InputManager* inputManager = InputManager::GetInstance();
    if (inputManager->currentInputDevice == InputManager::DEBUG) goto DebugSkip;
    if (inputManager->currentInputDevice != InputManager::KEYBOARD) return;
DebugSkip:
    // Rewrote super to avoid jumping back to original function
    int localX = static_cast<int>(static_cast<float>((mX - this->x_bar) * this->mouseModifier_x)) - this->modifier_x;
    int localY = static_cast<int>(static_cast<float>((mY - this->y_bar) * this->mouseModifier_y)) - this->modifier_y;
    G_->GetMouseControl()->SetPosition(localX, localY);
    if (this->langChooser.bOpen)
    {
        this->langChooser.MouseMove(localX, localY);
    }
}

HOOK_METHOD_PRIORITY(CApp, OnKeyDown, 9999, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnKeyDown -> Begin (TouchScreen.cpp)\n")

    InputManager* inputManager = InputManager::GetInstance();
    /*
    // TODO: Add keyboard setting
    if (*inputManager->AlwaysAllowKeyboard() == true) goto DebugSkip;
    */
    goto DebugSkip;
    if (inputManager->currentInputDevice == InputManager::DEBUG) goto DebugSkip;
    if (inputManager->currentInputDevice != InputManager::KEYBOARD) return;
DebugSkip:
    super(key);
}

HOOK_METHOD_PRIORITY(CApp, OnKeyUp, 9999, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnKeyUp -> Begin (TouchScreen.cpp)\n")

    InputManager* inputManager = InputManager::GetInstance();
    /*
    // TODO: Add keyboard setting
    if (*inputManager->AlwaysAllowKeyboard() == true) goto DebugSkip;
    */
    goto DebugSkip;
    if (inputManager->currentInputDevice == InputManager::DEBUG) goto DebugSkip;
    if (inputManager->currentInputDevice != InputManager::KEYBOARD) return;
DebugSkip:
    super(key);
}
