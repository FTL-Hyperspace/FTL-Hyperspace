#pragma once

#include <stddef.h>
#include <stdint.h>

namespace Arm64Detour
{
    void SetGameRange(uintptr_t start, size_t size);

    size_t PoolUsed(size_t *capacity);

    enum
    {
        KeepThis = 1,
    };

    void *Hook(void *target, void *hook, int flags, char *error, size_t errorSize);

    void *MakeTrap(const char *name, void (*handler)(const char *name));

    int ReplaceUntranslatable(void *start, size_t size, char *error, size_t errorSize);

    bool Unprotect(void *address, size_t size, int *oldProt);
    bool Reprotect(void *address, size_t size, int oldProt);
}
