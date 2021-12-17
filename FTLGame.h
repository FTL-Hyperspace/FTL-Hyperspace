#pragma once

#ifdef _WIN32
    #include "FTLGameWin32.h"
#elif defined(__linux__)
    #ifdef __i386__
        #include "FTLGameELF32.h"
    #elif defined(__amd64__)
        #error "Currently unsupported architecture AMD64"
    #else
        #error "Unsupported architecture"
    #endif
#else
    #error "Unsupported OS"
#endif

#ifdef DEBUG
    #define LOG_HOOK(message) printf(message);
#else
    #define LOG_HOOK(message)
#endif // DEBUG
