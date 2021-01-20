#include "Global.h"
#include "freetype.h"

HOOK_METHOD(InfoBox, SetBlueprintWeapon, (const WeaponBlueprint* bp, int status, bool hasWeaponSystem, int yShift) -> void)
{
    if (hasWeaponSystem && status == 1)
    {
        return super(bp, 2, hasWeaponSystem, yShift);
    }

    super(bp, 2, hasWeaponSystem, yShift);
}


HOOK_METHOD(InfoBox, SetBlueprintWeapon, (const WeaponBlueprint* bp, int status, bool hasWeaponSystem, int yShift) -> void)
{
    super(bp, status, hasWeaponSystem, yShift);

    Pointf titleSize = freetype_hack::easy_measurePrintLines(16, 0, 0, descBoxSize.x, desc.title.GetText());
    Pointf descSize = freetype_hack::easy_measurePrintLines(10, 0, 0, descBoxSize.x, desc.description.GetText());

    Pointf boxSize = titleSize + descSize + Pointf(0, 28.f);
    boxSize.y = std::max(boxSize.y, 252.f);

    delete primaryBox;
    primaryBox = new WindowFrame(7, 7, 323, boxSize.y);


    descBoxSize.y = boxSize.y + 14.f;
}

HOOK_METHOD(InfoBox, SetBlueprintDrone, (const DroneBlueprint* bp, int status, bool hasDroneSystem, int yShift) -> void)
{
    if (hasDroneSystem && status == 1)
    {
        return super(bp, 2, hasDroneSystem, yShift);
    }

    super(bp, 2, hasDroneSystem, yShift);
}

HOOK_METHOD(InfoBox, SetBlueprintDrone, (const DroneBlueprint* bp, int status, bool hasDroneSystem, int yShift) -> void)
{
    super(bp, status, hasDroneSystem, yShift);

    Pointf titleSize = freetype_hack::easy_measurePrintLines(16, 0, 0, descBoxSize.x, desc.title.GetText());
    Pointf descSize = freetype_hack::easy_measurePrintLines(10, 0, 0, descBoxSize.x, desc.description.GetText());

    Pointf boxSize = titleSize + descSize + Pointf(0, 28.f);
    boxSize.y = std::max(boxSize.y, 162.f);

    delete primaryBox;
    primaryBox = new WindowFrame(7, 7, 323, boxSize.y);

    descBoxSize.y = boxSize.y + 14.f;
}
