#include "Global.h"
#include "PALMemoryProtection.h"

#pragma GCC push_options
#pragma GCC optimize ("O1")
#include "TemporalSystem.h"

const int g_temporalVTableSize = 45;
static void* g_temporalVTable[g_temporalVTableSize];

void TemporalSystem::_HS_Jump()
{
    this->ShipSystem::StopHacking();
    SYS_EX(this)->temporalSystem->StopTimeDilation();
    this->LockSystem(0);
}


void TemporalSystem::_HS_OnLoop()
{
    this->ShipSystem::OnLoop();
    SYS_EX(this)->temporalSystem->OnLoop();
}

void TemporalSystem::_HS_ShipDestroyed()
{
    SYS_EX(this)->temporalSystem->StopTimeDilation();
}

void SetupVTable_TemporalSystem(ShipSystem* sys)
{
    void** vtable = *(void***)sys;

    MEMPROT_SAVE_PROT(dwOldProtect);
    MEMPROT_PAGESIZE();
    MEMPROT_UNPROTECT(&vtable[0], sizeof(void*) * g_temporalVTableSize, dwOldProtect);

    for (int i = 0; i < g_temporalVTableSize; i++)
    {
        g_temporalVTable[i] = vtable[i];
    }

    MEMPROT_REPROTECT(&vtable[0], sizeof(void*) * g_temporalVTableSize, dwOldProtect);

    g_temporalVTable[35] = (void*)&TemporalSystem::_HS_Jump;
    g_temporalVTable[39] = (void*)&TemporalSystem::_HS_OnLoop;
    g_temporalVTable[44] = (void*)&TemporalSystem::_HS_ShipDestroyed;

    *((void**)sys)= &g_temporalVTable;
}

HOOK_METHOD(ShipSystem, constructor, (int systemId, int roomId, int shipId, int startingPower) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::constructor -> Begin (TemporalSystemVTable.cpp)\n")
	super(systemId, roomId, shipId, startingPower);

	if (systemId == 20)
    {
        SYS_EX(this)->temporalSystem = new TemporalSystem_Wrapper(this);
        SetupVTable_TemporalSystem(this);
    }
}

#pragma GCC pop_options
