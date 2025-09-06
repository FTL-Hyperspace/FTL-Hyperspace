#include "Global.h"

struct InputManager
{
    enum InputMethod : int8_t
    {
        KEYBOARD = 0x0,
        TOUCHSCREEN = 0x1,
        CONTROLLER = 0x2,
        DEBUG = 0x4,
    };


    static InputManager* GetInstance()
    {
        static InputManager instance;
        return &instance;
    }

    bool* AlwaysAllowKeyboard()
    {
        // Saving the bool in padding space to save memory bandwidth
        return (reinterpret_cast<bool*>(&this->inputSwitch.running) + 0x2);
    }

    void StartInputSwitching(InputMethod requestingInput);
    void ReconstructMatrix(CApp* cApp, InputMethod desiredInput);

    TimerHelper inputSwitch;
    InputMethod currentInputDevice;
};



// Starmap primitive swap pointers
// PC
extern GL_Primitive* PC_explored;
extern GL_Primitive* PC_unexplored;
extern GL_Primitive* PC_danger;
extern GL_Primitive* PC_warning;
extern GL_Primitive* PC_yellow_warning;
extern GL_Primitive* PC_warning_shadow;
extern GL_Primitive* PC_warning_circle;
extern GL_Texture* PC_dottedLine;
// Touch
extern GL_Primitive* Touch_explored;
extern GL_Primitive* Touch_unexplored;
extern GL_Primitive* Touch_danger;
extern GL_Primitive* Touch_warning;
extern GL_Primitive* Touch_yellow_warning;
extern GL_Primitive* Touch_warning_shadow;
extern GL_Primitive* Touch_warning_circle;
extern GL_Texture* Touch_dottedLine;
