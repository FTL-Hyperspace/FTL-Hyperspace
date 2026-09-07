#pragma once

// Entry point exported by every libftlgame-<platform> module. Each module is
// one platform's generated FTLGame*.cpp linked with the game's own definition
// loading (zhl_definitions.cpp, SigScan, HDE) under ZHL_OFFLINE_SCAN; loading
// it registers the definitions exactly as loading Hyperspace does.

#include <stddef.h>

#ifdef _WIN32
    #define ZHLSCAN_EXPORT __declspec(dllexport)
#else
    #define ZHLSCAN_EXPORT __attribute__((visibility("default")))
#endif

#define ZHLSCAN_RUN_SYMBOL "zhlscan_run"

extern "C" {

// Resolves every definition against `code` (the binary's code section as the
// OS loader maps it; NOP regions are patched in place), writing the game's
// zhl.log to logPath. Returns 1 on
// success; on failure returns 0 with the game's error message in `error`.
typedef int (*zhlscan_run_t)(unsigned char* code, size_t length, const char* logPath,
                             char* error, size_t errorSize);

}
