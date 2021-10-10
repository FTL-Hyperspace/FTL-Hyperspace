#pragma GCC push_options
#pragma GCC optimize ("O1")

#include "CustomEquipment.h"

static bool __attribute__((fastcall)) EquipmentBox_CanHoldAugment(EquipmentBox *_this)
{
    //return _this != G_->GetWorld()->commandGui->equipScreen.overcapacityBox;
    return g_cargoAugments;
}

void SetupVTable(EquipmentBox *equip)
{
    void** vtable = *(void***)equip;

    DWORD dwOldProtect, dwBkup;
    VirtualProtect(&vtable[0], sizeof(void*) * 21, PAGE_EXECUTE_READWRITE, &dwOldProtect);

    vtable[15] = (void*)&EquipmentBox_CanHoldAugment;
    //vtable[17] = (void*)&EquipmentBox_GetType;

    VirtualProtect(&vtable[0], sizeof(void*) * 21, dwOldProtect, &dwBkup);
}

HOOK_METHOD_PRIORITY(EquipmentBox, constructor, 500, (Point pos, int slot) -> void)
{
    super(pos, slot);
    SetupVTable(this);
}

#pragma GCC pop_options
