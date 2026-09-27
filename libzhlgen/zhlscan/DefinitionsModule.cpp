#include "DefinitionsModule.h"

#include "SigScan.h"
#include "zhl_internal.h"

#include <cstring>

extern "C" ZHLSCAN_EXPORT int zhlscan_run(unsigned char* code, size_t length, const char* logPath,
                                         char* error, size_t errorSize)
{
    SigScan::InitFromBuffer(code, length);
    ZHL::SetLogPath(logPath);

    if (ZHL::Definition::Init())
    {
        return 1;
    }
    strncpy(error, ZHL::Definition::GetLastError(), errorSize - 1);
    error[errorSize - 1] = '\0';
    return 0;
}
