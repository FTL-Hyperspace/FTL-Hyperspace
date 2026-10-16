#pragma once
// A fatal error the player should see. SDL message boxes on the desktop builds; on
// Android the port shows it (see src/android/AndroidHost.cpp).

#include <stdio.h>

#if defined(__ANDROID__)
    void PAL_AndroidShowError(const char *title, const char *message);
    inline void PAL_ShowError(const char *title, const char *message)
    {
        PAL_AndroidShowError(title, message);
    }
#else
    #include <SDL3/SDL_messagebox.h>
    inline void PAL_ShowError(const char *title, const char *message)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, title, message, NULL);
    }
#endif
