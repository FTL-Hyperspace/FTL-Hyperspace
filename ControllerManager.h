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
    void HandleControllerButtonEvent(SDL_GameController* controller, uint8_t button);
    void HandleControllerAxisEvent(SDL_GameController* controller, uint8_t axis, int16_t value);
    void HandleJoystickEvent(SDL_Joystick* joystick, SDL_Event& event);
    void InputTranformer(); // Not yet implemented
    void Shutdown();

    static const char* SDL_ID;

private:
    SDL_GameController* controller;
    SDL_Joystick* joystick;
    int inputDevice;
    std::vector<SDL_GameController*> controllers;
    std::vector<SDL_Joystick*> joysticks;
};
#endif // defined
