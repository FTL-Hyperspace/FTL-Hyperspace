#include "Global.h"
#include "ASMHooks.h"
/*
HOOK_ASM(CreateChoiceBox, 0x001F1282, 6, (WorldManager *world, int equipLevel, const char* equipment) -> int)
{
    std::string equipStr(equipment);
    if (equipLevel == 0) {
        Equipment equip = world->commandGui->equipScreen;
        auto boxes = equip.vEquipmentBoxes;

        auto blueprintList = std::vector<std::string>();
        BlueprintManager::GetBlueprintList(blueprintList, G_->GetBlueprints(), equipStr);

        for (auto const& box: boxes)
        {
            CALL_VIRTUAL_RETURN(EquipmentBox, IsCargoBox, char, box, isCargo)();


            if (isCargo)
            {
                Blueprint* cargoItem = box->GetBlueprint();
                if (cargoItem)
                {
                    if (blueprintList.size() > 0)
                    {
                        for (auto const& x: blueprintList)
                        {
                            if (cargoItem->name == x) return 1;
                        }
                    }
                    else
                    {
                        if (cargoItem->name == equipStr) return 1;
                    }
                }
            }
        }
    }

    return equipLevel;
}

DEFINE_ASM(CreateChoiceBox)
{
    __asm__
    (
        "cmp edx, [ebp-0x334];"

        "push edx;"
        "push ebx;"
        "mov ebx, [esp+0x100+2*4];"
        "push ecx;"
        "mov ecx, [esp+0x30+3*4];"
        "push ebx;"
        "push eax;"
        "push ecx;"
        "call %0;"
        "pop ecx;"
        "mov edx, eax;"
        "pop eax;"
        "mov eax, edx;"
        "pop ebx;"
        "pop ecx;"
        "pop ebx;"

        "pop edx;"

        "jmp %1\n\t" :: "m"(HOOK_TO), "m"(JMP_TO)
    );
}
*/




ASMHook::ASMHook(BYTE* offset, int bytes, ASM_HOOK(*funcTo)(), BYTE* pathOffset) : _funcTo(funcTo), _size(bytes)
{
    DWORD baseAddress = (DWORD)GetModuleHandle(NULL);
    BYTE* jmpAddress = baseAddress + offset;

    JMP(jmpAddress, (DWORD)funcTo, bytes);

    _address = jmpAddress + bytes;

    if (pathOffset > 0)
    {
        _address2 = baseAddress + pathOffset;
    }
}

void JMP(BYTE *pAddress, DWORD dwJumpTo, DWORD dwLen)
{
    DWORD dwOldProtect, dwBkup, dwRelAddr;
    VirtualProtect(pAddress, dwLen, PAGE_EXECUTE_READWRITE, &dwOldProtect);
    dwRelAddr = (DWORD)(dwJumpTo - (DWORD)pAddress) - 5;
    *pAddress = 0xE9;
    *((DWORD *)(pAddress + 0x1)) = dwRelAddr;
    for (DWORD x = 0x5; x < dwLen; x++)
        *(pAddress + x) = 0x90;
    VirtualProtect(pAddress, dwLen, dwOldProtect, &dwBkup);
}

void NOP(DWORD instruction, DWORD dwLen)
{
    DWORD dwOldProtect, dwRelAddr;
    BYTE nop = 0x90;
    BYTE* addr = (BYTE*)instruction;
    VirtualProtect(addr, dwLen, PAGE_EXECUTE_READWRITE, &dwOldProtect);
    for (int i = 0; i < dwLen; i++)
    {
        *(addr + i) = 0x90;
    }
    VirtualProtect(addr, dwLen, dwOldProtect, NULL);
}

void WriteByte(BYTE *pAddress, BYTE val)
{
    DWORD dwOldProtect;
    VirtualProtect(pAddress, 1, PAGE_EXECUTE_READWRITE, &dwOldProtect);
    *(pAddress) = val;
    VirtualProtect(pAddress, 1, dwOldProtect, NULL);
}
