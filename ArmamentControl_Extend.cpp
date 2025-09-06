#include "ArmamentControl_Extend.h"
#include "Global.h"

HOOK_METHOD_PRIORITY(ArmamentControl, constructor, 900, (int systemId) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ArmamentControl::constructor -> Begin (ArmamentControl_Extend.cpp)\n")

    super(systemId);

    ArmamentControl_Extend* ex = new ArmamentControl_Extend();

    uintptr_t dEx = (uintptr_t)ex;


#ifdef __amd64__
    reinterpret_cast<uint8_t*>(this)[0xC] = (dEx >> 56) & 0xFF;
    reinterpret_cast<uint8_t*>(this)[0xD] = (dEx >> 48) & 0xFF;
    reinterpret_cast<uint8_t*>(this)[0xE] = (dEx >> 40) & 0xFF;
    reinterpret_cast<uint8_t*>(this)[0xF] = (dEx >> 32) & 0xFF;
    reinterpret_cast<uint8_t*>(this)[0xCC] = (dEx >> 24) & 0xFF;
    reinterpret_cast<uint8_t*>(this)[0xCD] = (dEx >> 16) & 0xFF;
    reinterpret_cast<uint8_t*>(this)[0xCE] = (dEx >> 8) & 0xFF;
    reinterpret_cast<uint8_t*>(this)[0xCF] = dEx & 0xFF;
#else // __amd64__
    reinterpret_cast<uint8_t*>(this)[0x5D] = (dEx >> 24) & 0xFF;
    reinterpret_cast<uint8_t*>(this)[0x5E] = (dEx >> 16) & 0xFF;
    reinterpret_cast<uint8_t*>(this)[0x5F] = (dEx >> 8) & 0xFF;
    reinterpret_cast<uint8_t*>(this)[0x79] = dEx & 0xFF;
#endif

    ex->orig = this;
    ex->touchWeaponBoxTop = G_->GetResources()->CreateImagePrimitiveString("ipad/systemUI/weapbox_box_top.png", 0, -42, 0, COLOR_WHITE, 1.f, false);
    ex->touchWeaponBoxMid = G_->GetResources()->CreateImagePrimitiveString("ipad/systemUI/weapbox_box_mid.png", 0, -35, 0, COLOR_WHITE, 1.f, false);
    ex->touchWeaponBoxBottom = G_->GetResources()->CreateImagePrimitiveString("ipad/systemUI/weapbox_box_bottom.png", 0, 0, 0, COLOR_WHITE, 1.f, false);
    ex->touchWeaponBoxSingle = G_->GetResources()->CreateImagePrimitiveString("ipad/systemUI/weapbox_box_single.png", 0, 0, 0, COLOR_WHITE, 1.f, false);
}

HOOK_METHOD_PRIORITY(ArmamentControl, destructor, 900, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ArmamentControl::destructor -> Begin (ArmamentControl_Extend.cpp)\n")
    delete AC_EX(this);
    super();
}

ArmamentControl_Extend* Get_ArmamentControl_Extend(ArmamentControl* c)
{
    uintptr_t dEx = 0;

#ifdef __amd64__
    dEx |= static_cast<uintptr_t>(reinterpret_cast<uint8_t*>(c)[0xC]) << 56;
    dEx |= static_cast<uintptr_t>(reinterpret_cast<uint8_t*>(c)[0xD]) << 48;
    dEx |= static_cast<uintptr_t>(reinterpret_cast<uint8_t*>(c)[0xE]) << 40;
    dEx |= static_cast<uintptr_t>(reinterpret_cast<uint8_t*>(c)[0xF]) << 32;
    dEx |= static_cast<uintptr_t>(reinterpret_cast<uint8_t*>(c)[0xCC]) << 24;
    dEx |= static_cast<uintptr_t>(reinterpret_cast<uint8_t*>(c)[0xCD]) << 16;
    dEx |= static_cast<uintptr_t>(reinterpret_cast<uint8_t*>(c)[0xCE]) << 8;
    dEx |= static_cast<uintptr_t>(reinterpret_cast<uint8_t*>(c)[0xCF]);
#else // __amd64__
    dEx |= static_cast<uintptr_t>(reinterpret_cast<uint8_t*>(c)[0x5D]) << 24;
    dEx |= static_cast<uintptr_t>(reinterpret_cast<uint8_t*>(c)[0x5E]) << 16;
    dEx |= static_cast<uintptr_t>(reinterpret_cast<uint8_t*>(c)[0x5F]) << 8;
    dEx |= static_cast<uintptr_t>(reinterpret_cast<uint8_t*>(c)[0x79]);
#endif

    return reinterpret_cast<ArmamentControl_Extend*>(dEx);
}