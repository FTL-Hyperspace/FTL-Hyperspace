#if defined(__linux__)
#include "Global.h"

namespace DINO  
{
    #include "ControllerManager.h"

    const char* ControllerManager::SDL_ID = "[SDL2]: ";

    // Constructor
    ControllerManager::ControllerManager() : controller(nullptr), joystick(nullptr), inputDevice(-1), leftTriggerPressed(false), rightTriggerPressed(false)
    {
    }

    // Destructor
    ControllerManager::~ControllerManager()
    {
        Shutdown();
    }

    // SDL Controller/Joystick Initialisation
    bool ControllerManager::Init()
    {
        hs_log_file("%sStarting controller/joystick initialization\n", SDL_ID);
        if (SDL_Init(SDL_INIT_GAMECONTROLLER | SDL_INIT_JOYSTICK) != 0)
        {
            hs_log_file("%sSDL could not initialize: %s\n", SDL_ID, SDL_GetError());
            return false;
        }

        bool forceJoystick = false;

        int numJoysticks = SDL_NumJoysticks();

        std::vector<std::string> forceAsJoystickList = 
        {
        "Nintendo Switch Joy-Con (R)",
        "Nintendo Switch Joy-Con (L)",
        "Google Stadia Controller"
        };

        for (int i = 0; i < numJoysticks; ++i)
        {
            // If forceJoystick is true, or if the device is not a GameController, treat it as a joystick
            if (forceJoystick || !SDL_IsGameController(i))
            {
                JoystickInit: // goto jump
                SDL_Joystick* joystick = SDL_JoystickOpen(i);
                if (joystick)
                {
                    hs_log_file("%sJoystick connected: %s\n", SDL_ID, SDL_JoystickName(joystick));
                    joysticks.push_back(joystick);
                }
                else
                {
                    hs_log_file("%sFailed to open Joystick %d: %s\n", SDL_ID, i, SDL_GetError());
                }
                continue;  // Move to the next device
            }

            // Try to open as GameController
            SDL_GameController* gameController = SDL_GameControllerOpen(i);
            std::string cName = SDL_GameControllerName(gameController);

            // Check if controller is banned
            if (std::find(forceAsJoystickList.begin(), forceAsJoystickList.end(), cName) != forceAsJoystickList.end())
            {
                forceJoystick = true;
                goto JoystickInit;
            }

            if (gameController)
            {
                hs_log_file("%sFound a valid GameController: %s\n", SDL_ID, SDL_GameControllerName(gameController));
                controllers.push_back(gameController);
            }
            else
            {
                hs_log_file("%sFailed to open GameController %d: %s\n", SDL_ID, i, SDL_GetError());
            }
        }

        if (controllers.empty() && joysticks.empty())
        {
            hs_log_file("%sNo controllers or joysticks found\n", SDL_ID);
            SDL_Quit();
            return false;
        }

        return true;
    }

    // Update controller or joystick input
    void ControllerManager::Update()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            SDL_JoystickID joystickID;
            int8_t controllerIndex = -1;
            uint8_t controllerButtonState = 0;
            uint8_t joystickButtonState = 0;
            uint8_t joystickIndex = 0;

            // Determine device index
            if (event.type == SDL_CONTROLLERBUTTONDOWN || event.type == SDL_CONTROLLERBUTTONUP || event.type == SDL_CONTROLLERAXISMOTION)
            {
                joystickID = event.cbutton.which;
                for (int i = 0; i < controllers.size(); ++i)
                {
                    if (SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(controllers[i])) == joystickID)
                    {
                        controllerIndex = i;
                        break;
                    }
                }
            }

            // Treat all kind of controller/joystick inputs
            switch (event.type)
            {
            case SDL_CONTROLLERBUTTONUP:
                controllerButtonState = 1;
            case SDL_CONTROLLERBUTTONDOWN:
                if (controllerIndex != -1)
                {
                    SDL_GameController* controller = controllers[controllerIndex];
                    ReadControllerButtonEvent(controller, event.cbutton.button, controllerButtonState);
                }
                break;
            case SDL_CONTROLLERAXISMOTION:
                if (controllerIndex != -1)
                {
                    SDL_GameController* controller = controllers[controllerIndex];
                    ReadControllerAxisEvent(controller, event.caxis.axis, event.caxis.value);
                }
                break;
            case SDL_JOYBUTTONUP:
                joystickButtonState = 1;
            case SDL_JOYBUTTONDOWN:
                joystickIndex = event.jbutton.which;
                if (joystickIndex < joysticks.size())
                {
                    SDL_Joystick* joystick = joysticks[joystickIndex];
                    const char* jName = SDL_JoystickName(joystick);
                    const char* state = (joystickButtonState == 0) ? "pressed" : "released";
                    uint16_t button = event.jbutton.button;
                    hs_log_file("%sJoystick *%s* button %s: %d\n", SDL_ID, jName, state, button);
                }
                break;
            case SDL_JOYAXISMOTION:
                joystickIndex = event.jaxis.which;
                if (joystickIndex < joysticks.size())
                {
                    SDL_Joystick* joystick = joysticks[joystickIndex];
                    const char* jName = SDL_JoystickName(joystick);
                    uint8_t jAxisIndex = event.jaxis.axis;
                    uint16_t jAxisVal = event.jaxis.value;
                    if (event.jaxis.value > -10000 && event.jaxis.value < 10000) break; // Skip if within deadzone
                    hs_log_file("%sJoystick *%s* axis %d moved to %d\n", SDL_ID, jName, jAxisIndex, jAxisVal);
                }
                break;
            case SDL_JOYHATMOTION:
                joystickIndex = event.jhat.which;
                if (joystickIndex < joysticks.size())
                {
                    SDL_Joystick* joystick = joysticks[joystickIndex];
                    const char* jName = SDL_JoystickName(joystick);
                    uint8_t jHatIndex = event.jhat.hat;
                    uint16_t jHatVal = event.jhat.value;
                    hs_log_file("%sJoystick *%s* Hat %d moved to position %d\n", SDL_ID, SDL_JoystickName(joystick), jHatIndex, jHatVal);
                }
                break;
            }
        }
    }

    // Read controller buttons
    void ControllerManager::ReadControllerButtonEvent(SDL_GameController* controller, uint8_t button, uint8_t state)
    {
        const char* buttonName = "Unknown";
        const char* buttonAction = (state == 1) ? "released" : "pressed";
        switch (button)
        {
            case SDL_CONTROLLER_BUTTON_A: buttonName = "A"; break;
            case SDL_CONTROLLER_BUTTON_B: buttonName = "B"; break;
            case SDL_CONTROLLER_BUTTON_X: buttonName = "X"; break;
            case SDL_CONTROLLER_BUTTON_Y: buttonName = "Y"; break;
            case SDL_CONTROLLER_BUTTON_BACK: buttonName = "Back"; break;
            case SDL_CONTROLLER_BUTTON_GUIDE: buttonName = "Guide"; break;
            case SDL_CONTROLLER_BUTTON_START: buttonName = "Start"; break;
            case SDL_CONTROLLER_BUTTON_LEFTSTICK: buttonName = "Left Stick"; break;
            case SDL_CONTROLLER_BUTTON_RIGHTSTICK: buttonName = "Right Stick"; break;
            case SDL_CONTROLLER_BUTTON_LEFTSHOULDER: buttonName = "Left Shoulder"; break;
            case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER: buttonName = "Right Shoulder"; break;
            case SDL_CONTROLLER_BUTTON_DPAD_UP: buttonName = "D-Pad Up"; break;
            case SDL_CONTROLLER_BUTTON_DPAD_DOWN: buttonName = "D-Pad Down"; break;
            case SDL_CONTROLLER_BUTTON_DPAD_LEFT: buttonName = "D-Pad Left"; break;
            case SDL_CONTROLLER_BUTTON_DPAD_RIGHT: buttonName = "D-Pad Right"; break;
        }
        hs_log_file("%sController *%s* button %s: %s\n", SDL_ID, SDL_GameControllerName(controller), buttonAction, buttonName);
    }

    // Read controller stick & triggers (Triggers are axis inputs on GamePads)
    void ControllerManager::ReadControllerAxisEvent(SDL_GameController* controller, uint8_t axis, int16_t value)
    {
        // Skip output if within deadzone (except for triggers)
        if ((axis != SDL_CONTROLLER_AXIS_TRIGGERLEFT && axis != SDL_CONTROLLER_AXIS_TRIGGERRIGHT) && (value > -10000 && value < 10000)) return;

        switch (axis)
        {
            case SDL_CONTROLLER_AXIS_LEFTX:
                hs_log_file("%sController *%s* Left Stick X Axis: %d\n", SDL_ID, SDL_GameControllerName(controller), value);
                break;
            case SDL_CONTROLLER_AXIS_LEFTY:
                hs_log_file("%sController *%s* Left Stick Y Axis: %d\n", SDL_ID, SDL_GameControllerName(controller), value);
                break;
            case SDL_CONTROLLER_AXIS_RIGHTX:
                hs_log_file("%sController *%s* Right Stick X Axis: %d\n", SDL_ID, SDL_GameControllerName(controller), value);
                break;
            case SDL_CONTROLLER_AXIS_RIGHTY:
                hs_log_file("%sController *%s* Right Stick Y Axis: %d\n", SDL_ID, SDL_GameControllerName(controller), value);
                break;
            case SDL_CONTROLLER_AXIS_TRIGGERLEFT: // Faking triggers as button because it makes them easier to work with
                if (value > 25000 && !leftTriggerPressed) // Button Down
                {
                    leftTriggerPressed = true;
                    hs_log_file("%sController *%s* button pressed: %s\n", SDL_ID, SDL_GameControllerName(controller), "Left Trigger");
                }
                else if (value < 10000 && leftTriggerPressed) // Button Up
                {
                    leftTriggerPressed = false;
                    hs_log_file("%sController *%s* button released: %s\n", SDL_ID, SDL_GameControllerName(controller), "Left Trigger");
                }
                break;
            case SDL_CONTROLLER_AXIS_TRIGGERRIGHT: // Faking triggers as button because it makes them easier to work with
                if (value > 25000 && !rightTriggerPressed) // Button Down
                {
                    rightTriggerPressed = true;
                    hs_log_file("%sController *%s* button pressed: %s\n", SDL_ID, SDL_GameControllerName(controller), "Right Trigger");
                }
                else if (value < 10000 && rightTriggerPressed) // Button Up
                {
                    rightTriggerPressed = false;
                    hs_log_file("%sController *%s* button released: %s\n", SDL_ID, SDL_GameControllerName(controller), "Right Trigger");
                }
                break;
            default:
                hs_log_file("%sController *%s* Unknown Axis: %d\n", SDL_ID, SDL_GameControllerName(controller), axis);
                break;
        }
    }

    // 
    void ControllerManager::InputHandler()
    {

    }

    // Close and clean up all controllers and joysticks
    void ControllerManager::Shutdown()
    {
        for (auto* controller : controllers)
        {
            hs_log_file("%sGameController *%s* closed\n", SDL_ID, SDL_GameControllerName(controller));
            SDL_GameControllerClose(controller);
        }
        controllers.clear();

        for (auto* joystick : joysticks)
        {
            hs_log_file("%sJoystick *%s* closed\n", SDL_ID, SDL_JoystickName(joystick));
            SDL_JoystickClose(joystick);
        }
        joysticks.clear();

        SDL_Quit();
    }
}
#endif
