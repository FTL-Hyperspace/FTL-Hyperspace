#include "Global.h"
#include "ASMHooks.h"

HOOK_METHOD(CrewMember, GetNewGoal, () -> void)
{
    //printf("%d\n", CM_EX(this)->_canPhaseThroughDoors);
    if (this->last_door && CM_EX(this)->canPhaseThroughDoors)
    {
        this->last_door = 0;
    }

    super();
}


HOOK_ASM_PATH(GhostPhaseDoors, 0x0007219A, 0x6, (CrewMember *member) -> bool, 0x000721D0)
{
    return CM_EX(member)->canPhaseThroughDoors;
}

DEFINE_ASM(GhostPhaseDoors)
{
    __asm__
    (
        "push eax;"
        "push ecx;"
        "push edx;"
        "push ebx;"
        "call %0;"
        "pop ebx;"
        "pop edx;"
        "pop ecx;"

        "test al, al;"
        "jz GhostPhaseDoors;"

        "pop eax;"
        "jmp %2;"


     "GhostPhaseDoors:;"
        "pop eax;"
        "mov eax, [ebx+0x1DC];"
        "test eax, eax;"
        "jmp %1;" :: "m"(HOOK_TO), "m"(JMP_TO), "m"(JMP_TO2)
    );
}

HOOK_ASM_PATH(GhostOpenDoors, 0x00072389, 0x5, (CrewMember *member) -> bool, 0x00072393)
{
    return CM_EX(member)->canPhaseThroughDoors;
}

DEFINE_ASM(GhostOpenDoors)
{
    __asm__(
        "push eax;"
        "push ecx;"
        "push edx;"
        "push ebx;"
        "call %0;"
        "pop ebx;"
        "pop edx;"
        "pop ecx;"
        "test al, al;"
        "jz GhostOpenDoors;"

        "pop eax;"
        "jmp %2;"


    "GhostOpenDoors:;"
        "pop eax;"
        "mov [ebx+0x64], edi;"
        "mov ecx, edi;"
        "jmp %1;" :: "m"(HOOK_TO), "m"(JMP_TO), "m"(JMP_TO2)
    );

}

