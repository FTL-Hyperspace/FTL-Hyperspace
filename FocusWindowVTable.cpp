#pragma once

#include "Global.h"
#include "PALMemoryProtection.h"

static bool VTableInitialized = false;
FocusWindow::FocusWindow()
{
    // need to remap Hyperspace's vtable to FTL's vtable so that derived classes can call FocusWindow methods
    if (!VTableInitialized)
    {
        VTableInitialized = true;
        const unsigned int vTableSize = 17;

        // hyperspace vtable
        void** vtable = *(void***)this;

        MEMPROT_SAVE_PROT(dwOldProtect);
        MEMPROT_PAGESIZE();
        MEMPROT_UNPROTECT(&vtable[0], sizeof(void*) * vTableSize, dwOldProtect);

        // set all the vtable entries to the FTL methods from the sigscanned FTL vtable
        for (unsigned int i=0; i<vTableSize; ++i)
        {
            vtable[i] = VTable_FocusWindow[i];
        }

        MEMPROT_REPROTECT(&vtable[0], sizeof(void*) * 57, dwOldProtect);
    }

    // call the FTL constructor
    this->constructor();
}
