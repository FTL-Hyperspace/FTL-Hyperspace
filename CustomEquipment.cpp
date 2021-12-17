#include "Global.h"

HOOK_METHOD(InfoBox, SetBlueprintWeapon, (const WeaponBlueprint* bp, int status, bool hasWeaponSystem, int yShift) -> void)
{
    LOG_HOOK("HOOK_METHOD -> InfoBox::SetBlueprintWeapon -> Begin (CustomEquipment.cpp)\n")
    if (hasWeaponSystem && status == 1)
    {
        return super(bp, 2, hasWeaponSystem, yShift);
    }

    super(bp, 2, hasWeaponSystem, yShift);
}


HOOK_METHOD(InfoBox, SetBlueprintWeapon, (const WeaponBlueprint* bp, int status, bool hasWeaponSystem, int yShift) -> void)
{
    LOG_HOOK("HOOK_METHOD -> InfoBox::SetBlueprintWeapon -> Begin (CustomEquipment.cpp)\n")
    super(bp, status, hasWeaponSystem, yShift);

    Pointf titleSize = freetype::easy_measurePrintLines(16, 0, 0, descBoxSize.x, desc.title.GetText());
    Pointf descSize = freetype::easy_measurePrintLines(10, 0, 0, descBoxSize.x, desc.description.GetText());

    Pointf boxSize = titleSize + descSize + Pointf(0, 28.f);
    boxSize.y = std::max(boxSize.y, 252.f);

    delete primaryBox;
    primaryBox = new WindowFrame(7, 7, 323, boxSize.y);


    descBoxSize.y = boxSize.y + 14.f;
}
