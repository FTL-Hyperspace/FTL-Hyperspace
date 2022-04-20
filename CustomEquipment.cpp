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


HOOK_METHOD_PRIORITY(Equipment, GetCargoHold, 9999, () -> std::vector<std::string>)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Equipment::GetCargoHold -> Begin (CustomEquipment.cpp)\n")
    // Rewrite to fix a vanilla item duplication bug.

    std::vector<std::string> ret = std::vector<std::string>();

    for (unsigned int i = this->cargoId; i<this->vEquipmentBoxes.size(); ++i)
    {
        if (!this->vEquipmentBoxes[i]->IsEmpty())
        {
            Blueprint *bp = this->vEquipmentBoxes[i]->GetBlueprint();
            ret.push_back(bp->name);
        }
    }

    return ret;
}

HOOK_METHOD_PRIORITY(Equipment, AddToCargo, 9999, (const std::string& name) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Equipment::AddToCargo -> Begin (CustomEquipment.cpp)\n")
    // Rewrite to fix deleting 0 power weapons/drones in cargo.

    WeaponBlueprint *weapon = G_->GetBlueprints()->GetWeaponBlueprint(name);
    if (weapon && weapon->type != -1)
    {
        AddWeapon(weapon,true,true);
        return;
    }

    DroneBlueprint *drone = G_->GetBlueprints()->GetDroneBlueprint(name);
    if (drone && drone->type != -1)
    {
        AddDrone(drone,true,true);
        return;
    }

    AugmentBlueprint *aug = G_->GetBlueprints()->GetAugmentBlueprint(name);
    if (aug && !aug->name.empty())
    {
        AddAugment(aug,true,true);
        return;
    }
}
