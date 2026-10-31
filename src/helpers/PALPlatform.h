#pragma once

#if defined(__APPLE__)
    #define HS_APPLE_GAME 1
#elif defined(__ANDROID__)
    #define HS_ANDROID 1
    #define HS_APPLE_GAME 1
#endif
