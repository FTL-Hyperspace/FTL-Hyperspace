#if defined(__linux__)
#include "Global.h"

namespace DINO  
{
    #include "ControllerManager.h"

    const char* ControllerManager::SDL_ID = "[SDL2]: ";

    // Constructor
    ControllerManager::ControllerManager() : controller(nullptr), joystick(nullptr), inputDevice(-1)
    {
    }

    // Destructor
    ControllerManager::~ControllerManager()
    {
        Shutdown();
    }

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
        "Nintendo Switch Joy-Con (L)"
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
            if (event.type == SDL_CONTROLLERBUTTONDOWN || event.type == SDL_CONTROLLERAXISMOTION)
            {
                SDL_JoystickID joystickID = event.cbutton.which;
                int controllerIndex = -1;

                for (int i = 0; i < controllers.size(); ++i)
                {
                    if (SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(controllers[i])) == joystickID)
                    {
                        controllerIndex = i;
                        break;
                    }
                }

                if (controllerIndex != -1)
                {
                    SDL_GameController* controller = controllers[controllerIndex];
                    if (event.type == SDL_CONTROLLERBUTTONDOWN)
                    {
                        HandleControllerButtonEvent(controller, event.cbutton.button);
                    }
                    else if (event.type == SDL_CONTROLLERAXISMOTION)
                    {
                        HandleControllerAxisEvent(controller, event.caxis.axis, event.caxis.value);
                    }
                }
            }
            else if (event.type == SDL_JOYBUTTONDOWN || event.type == SDL_JOYAXISMOTION || event.type == SDL_JOYHATMOTION)
            {
                int joystickIndex = event.jbutton.which;
                if (joystickIndex < joysticks.size())
                {
                    HandleJoystickEvent(joysticks[joystickIndex], event);
                }
            }
        }
    }

    // Handle controller buttons
    void ControllerManager::HandleControllerButtonEvent(SDL_GameController* controller, uint8_t button)
    {
        const char* buttonName = "Unknown";
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
        hs_log_file("%sController *%s* button pressed: %s\n", SDL_ID, SDL_GameControllerName(controller), buttonName);
    }

    // Handle controller stick & triggers (Tend to be axes on many models)
    void ControllerManager::HandleControllerAxisEvent(SDL_GameController* controller, uint8_t axis, int16_t value)
    {
        // Skip output if within deadzone
        if (value > -10000 && value < 10000) return;

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
            case SDL_CONTROLLER_AXIS_TRIGGERLEFT:
                if (value == 32767 || value == -32768) 
                {
                    // hs_log_file("%sLeft Trigger Axis: %d\n", SDL_ID, value);
                    hs_log_file("%sController *%s* button pressed: %s\n", SDL_ID, SDL_GameControllerName(controller), "Left Trigger");
                }
                break;
            case SDL_CONTROLLER_AXIS_TRIGGERRIGHT:
                if (value == 32767 || value == -32768) 
                {
                    // hs_log_file("%sRight Trigger Axis: %d\n", SDL_ID, value);
                    hs_log_file("%sController *%s* button pressed: %s\n", SDL_ID, SDL_GameControllerName(controller), "Right Trigger");
                }
                break;
            default:
                hs_log_file("%sController *%s* Unknown Axis: %d\n", SDL_ID, SDL_GameControllerName(controller), axis);
                break;
        }
    }

    // Handle all joystick stuff at once
    void ControllerManager::HandleJoystickEvent(SDL_Joystick* joystick, SDL_Event& event)
    {
        // Treat Button inputs
        if (event.type == SDL_JOYBUTTONDOWN)
        {
            hs_log_file("%sJoystick *%s* button pressed: %d\n", SDL_ID, SDL_JoystickName(joystick), event.jbutton.button);
        }
        // Treat Axis inputs
        else if (event.type == SDL_JOYAXISMOTION)
        {
            // Skip output if within deadzone
            if (event.jaxis.value > -10000 && event.jaxis.value < 10000) return;

            hs_log_file("%sJoystick *%s* axis %d moved to %d\n", SDL_ID, SDL_JoystickName(joystick), event.jaxis.axis, event.jaxis.value);
        }
        // Treat Hat inputs (usually D-Pads on controllers)
        else if (event.type == SDL_JOYHATMOTION)
        {
            hs_log_file("%sJoystick *%s* Hat %d moved to position %d\n", SDL_ID, SDL_JoystickName(joystick), event.jhat.hat, event.jhat.value);
        }
    }

    void ControllerManager::InputTranformer()
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
