#if defined(__linux__)
#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_gamecontroller.h>

class ControllerManager
{
public:
    // Constructor & Destructor
    ControllerManager();
    ~ControllerManager();

    bool Init();
    void Update();
    void ReadControllerButtonEvent(SDL_GameController* controller, uint8_t button, uint8_t state); // State: 0 = button down - 1 button up
    void ReadControllerAxisEvent(SDL_GameController* controller, uint8_t axis, int16_t value);
    void InputHandler(); // Not yet implemented
    void Shutdown();

    static const char* SDL_ID;

private:
    SDL_GameController* controller;
    SDL_Joystick* joystick;
    int8_t inputDevice;
    bool leftTriggerPressed;
    bool rightTriggerPressed;
    std::vector<SDL_GameController*> controllers;
    std::vector<SDL_Joystick*> joysticks;
};
#endif // defined
