#pragma once
// HS_ANDROID: FTL for iPad running on Android, loaded by the Android port (Android also
// defines __linux__, so check HS_ANDROID first wherever Linux is meant).
//
// HS_APPLE_GAME: the game binary was built by Apple's clang with libc++, which is true
// of both the Mac game and the iPad one. Use it where the game build matters rather
// than the system Hyperspace runs on (functions the compiler inlined or cloned, vtable
// symbols and so on).

#if defined(__APPLE__)
    #define HS_APPLE_GAME 1
#elif defined(__ANDROID__)
    #define HS_ANDROID 1
    #define HS_APPLE_GAME 1
#endif
