#include "SdlTest.h"

#ifdef HS_TEST_SDL
/**
 * Reports which SDL3 subsystems come up inside the Hyperspace binary, drawn over the game.
 *
 */

#include "Global.h"

#include <SDL3/SDL.h>

#include <string>
#include <vector>

static std::string g_report;
static SDL_Gamepad *g_pad = nullptr;
static SDL_AudioStream *g_beep = nullptr;

static bool InitSubsystem(const char *name, SDL_InitFlags flag)
{
    bool ok = SDL_InitSubSystem(flag);
    g_report += std::string(name) + (ok ? ": ok" : std::string(": FAILED - ") + SDL_GetError()) + "\n";
    return ok;
}

static void PlayBeep()
{
    std::vector<float> tone(4800);
    for (size_t i = 0; i < tone.size(); ++i)
        tone[i] = 0.2f * SDL_sinf(2.0f * SDL_PI_F * 440.0f * i / 48000.0f);

    SDL_PutAudioStreamData(g_beep, tone.data(), (int)(tone.size() * sizeof(float)));
}

void SdlTest::Init()
{
    if (InitSubsystem("Audio", SDL_INIT_AUDIO))
    {
        g_report += std::string("Audio driver: ") + SDL_GetCurrentAudioDriver() + "\n";

        int deviceCount = 0;
        SDL_AudioDeviceID *devices = SDL_GetAudioPlaybackDevices(&deviceCount);
        g_report += "Audio devices: " + std::to_string(deviceCount) + "\n";
        SDL_free(devices);

        SDL_AudioSpec spec = { SDL_AUDIO_F32, 1, 48000 };
        g_beep = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &spec, nullptr, nullptr);
        if (g_beep) SDL_ResumeAudioStreamDevice(g_beep);
    }

    if (InitSubsystem("Gamepad", SDL_INIT_GAMEPAD))
    {
        int padCount = 0;
        SDL_JoystickID *padIds = SDL_GetGamepads(&padCount);
        if (padCount > 0) g_pad = SDL_OpenGamepad(padIds[0]);
        SDL_free(padIds);

        g_report += std::string("Gamepad: ") + (g_pad ? SDL_GetGamepadName(g_pad) : "none connected") + "\n";
    }

    g_report += "Press the X (A) button on the gamepad to hear a beep\n";
}

void SdlTest::Render()
{
    // FTL owns the event loop, so nothing refreshes gamepad state for us
    SDL_UpdateGamepads();

    std::string live = "Gamepad state: ";
    if (g_pad)
    {
        live += "LX " + std::to_string(SDL_GetGamepadAxis(g_pad, SDL_GAMEPAD_AXIS_LEFTX))
              + "  LY " + std::to_string(SDL_GetGamepadAxis(g_pad, SDL_GAMEPAD_AXIS_LEFTY));

        static bool wasDown = false;
        bool isDown = SDL_GetGamepadButton(g_pad, SDL_GAMEPAD_BUTTON_SOUTH);
        if (isDown && !wasDown && g_beep) PlayBeep();
        wasDown = isDown;
    }
    else
    {
        live += "no gamepad";
    }

    CSurface::GL_SetColor(GL_Color(0.4f, 1.0f, 0.6f, 1.0f));

    float y = 40.0f;
    size_t start = 0;
    while (start < g_report.size())
    {
        size_t end = g_report.find('\n', start);
        freetype::easy_print(10, 40.0f, y, g_report.substr(start, end - start));
        y += 18.0f;
        start = end + 1;
    }
    freetype::easy_print(10, 40.0f, y + 18.0f, live);

    CSurface::GL_SetColor(GL_Color(1.0f, 1.0f, 1.0f, 1.0f));
}

#endif // HS_TEST_SDL
