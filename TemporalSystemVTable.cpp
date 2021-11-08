#include "Global.h"

#pragma GCC push_options
#pragma GCC optimize ("O1")
#include "TemporalSystem.h"

const int g_temporalVTableSize = 45;
static void* g_temporalVTable[g_temporalVTableSize];

static void __attribute__((fastcall)) TemporalSystem_Jump(ShipSystem *_this)
{
    _this->ShipSystem::StopHacking();
    SYS_EX(_this)->temporalSystem->StopTimeDilation();
    _this->LockSystem(0);
}


static void __attribute__((fastcall)) TemporalSystem_OnLoop(ShipSystem *_this)
{
    _this->ShipSystem::OnLoop();
    SYS_EX(_this)->temporalSystem->OnLoop();
}

static void __attribute__((fastcall)) TemporalSystem_ShipDestroyed(ShipSystem *_this)
{
    SYS_EX(_this)->temporalSystem->StopTimeDilation();
}

void SetupVTable_TemporalSystem(ShipSystem* sys)
{
    void** vtable = *(void***)sys;

    DWORD dwOldProtect, dwBkup;
    VirtualProtect(&vtable[0], sizeof(void*) * g_temporalVTableSize, PAGE_EXECUTE_READWRITE, &dwOldProtect);

    for (int i = 0; i < g_temporalVTableSize; i++)
    {
        g_temporalVTable[i] = vtable[i];
    }

    VirtualProtect(&vtable[0], sizeof(void*) * g_temporalVTableSize, dwOldProtect, &dwBkup);

    g_temporalVTable[35] = (void*)&TemporalSystem_Jump;
    g_temporalVTable[39] = (void*)&TemporalSystem_OnLoop;
    g_temporalVTable[44] = (void*)&TemporalSystem_ShipDestroyed;

    *((void**)sys)= &g_temporalVTable;
}

HOOK_METHOD(ShipSystem, constructor, (int systemId, int roomId, int shipId, int startingPower) -> void)
{
	super(systemId, roomId, shipId, startingPower);

	if (systemId == 20)
    {
        SYS_EX(this)->temporalSystem = new TemporalSystem_Wrapper(this);
        SetupVTable_TemporalSystem(this);
    }
}

#pragma GCC pop_options
