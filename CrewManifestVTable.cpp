#pragma GCC push_options
#pragma GCC optimize ("O1")
#include "Global.h"
#include "CustomCrewManifest.h"

static void __attribute__((fastcall)) CrewManifest_MouseUp(CrewManifest *_this, int _edx, int mX, int mY)
{
    CustomCrewManifest::GetInstance()->MouseUp(mX, mY);
}

void SetupVTable(CrewManifest *_this)
{
    void** vtable = *(void***)_this;

    DWORD dwOldProtect, dwBkup;
    VirtualProtect(&vtable[0], sizeof(void*) * 17, PAGE_EXECUTE_READWRITE, &dwOldProtect);

    vtable[11] = (void*)&CrewManifest_MouseUp;

    VirtualProtect(&vtable[0], sizeof(void*) * 17, dwOldProtect, &dwBkup);
}

HOOK_METHOD_PRIORITY(CrewManifest, constructor, 500, () -> void)
{
    super();

    SetupVTable(this);
}

#pragma GCC pop_options
