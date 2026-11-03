#pragma once

// Writes FTL_HS_crash.log with the crashing stack as module + offset, resolved later with the .symbols files
namespace CrashStackTrace
{
    // Right after FTL installs its own handlers
    void Install();
    void WriteException(void* exceptionPointers);
}
