#pragma GCC push_options
#pragma GCC optimize ("O1")
#include "PALMemoryProtection.h"
#include "CustomCrewManifest.h"

void CrewManifest::_HS_MouseUp(int mX, int mY)
{
    CustomCrewManifest::GetInstance()->MouseUp(mX, mY);
}

void SetupVTable(CrewManifest *_this)
{
    void** vtable = *(void***)_this;

    MEMPROT_SAVE_PROT(dwOldProtect);
    MEMPROT_PAGESIZE();
    MEMPROT_UNPROTECT(&vtable[0], sizeof(void*) * 17, dwOldProtect);

    vtable[11] = (void*)&CrewManifest::_HS_MouseUp;

    MEMPROT_REPROTECT(&vtable[0], sizeof(void*) * 17, dwOldProtect);
}

HOOK_METHOD_PRIORITY(CrewManifest, constructor, 500, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewManifest::constructor -> Begin (CrewManifestVTable.cpp)\n")
    super();

    SetupVTable(this);
}

#pragma GCC pop_options
