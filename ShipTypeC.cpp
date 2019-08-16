#include "Global.h"
#include "ASMHooks.h"

/*
HOOK_METHOD(ShipBuilder, CheckTypes, () -> void*)
{
    auto ret = super();


    if (this->currentShipId >= 8)
    {

        auto aPos = Point(32, 248);
        auto bPos = Point(77, 248);
        auto cPos = Point(122, 248);

        this->typeA.SetLocation(aPos);
        this->typeB.SetLocation(bPos);
        this->typeC.SetLocation(cPos);
        this->typeC.SetActive(true);
    }

    return ret;
}

HOOK_METHOD(ScoreKeeper, GetShipUnlocked, (int shipId, int shipVariant) -> bool)
{
    if (shipId >= 8 && shipVariant == 2) return true;
    return super(shipId, shipVariant);
}


HOOK_ASM(CAchievementTypeC, 0x0002A0F8, 0xD, () -> void)
{}

float cAchievementOffset = 1.f;

DEFINE_ASM(CAchievementTypeC)
{

    __asm__(
            "movss xmm0, ds : %1;"
            "mov eax, 3;"
            "jmp %0;" :: "m"(JMP_TO), "m"(cAchievementOffset)
            );
}

HOOK_ASM(ShipButtonConstructorTypeC, 0x00112946, 0x6, () -> void)
{}

DEFINE_ASM(ShipButtonConstructorTypeC)
{
    __asm__(
            "sub eax, 256;"
            "cmp eax, 1;"
            "jmp %0;" :: "m"(JMP_TO)

            );
}

HOOK_ASM(ShipSelectMouseMoveTypeC, 0x0011472D, 0x6, () -> void)
{}

DEFINE_ASM(ShipSelectMouseMoveTypeC)
{
    __asm__(
            "sub eax, 256;"
            "cmp eax, 1;"
            "jmp %0;" :: "m"(JMP_TO)

            );
}
*/
