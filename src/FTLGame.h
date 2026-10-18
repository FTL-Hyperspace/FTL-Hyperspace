#pragma once
#include "helpers/PALPlatform.h"  // HS_ANDROID, HS_APPLE_GAME

#ifdef _WIN32
    #include "FTLGameWin32.h"
#elif defined(__ANDROID__)
    #include "FTLGameiOSARM64.h"  // FTL for iPad 1.6.21, run by the Android port
#elif defined(__linux__)
    #ifdef __i386__
        #include "FTLGameELF32.h"
    #elif defined(__amd64__)
        #include "FTLGameELF64.h"
    #else
        #error "Unsupported architecture"
    #endif
#elif defined(__APPLE__)
    #include "FTLGameMacOSAMD64.h"
#else
    #error "Unsupported OS"
#endif

#ifdef TRACE
    #define LOG_HOOK(message) printf(message);
#else
    #define LOG_HOOK(message)
#endif // DEBUG
