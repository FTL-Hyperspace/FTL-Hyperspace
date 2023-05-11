#include "Global.h"

#include "CustomEquipment.h"
#include "CustomAugments.h"

bool g_cargoAugments = false;

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

// CARGO AUGMENTS

HOOK_METHOD(EquipmentBox, RenderLabels, (bool unk) -> void)
{
    if (IsCargoBox() && IsAugment() && !unk)
    {
        TextString title = item.augment->desc.shortTitle.data.empty() ? item.augment->desc.title : item.augment->desc.shortTitle;
        freetype::easy_printCenter(6, location.x + 60, location.y + 58, title.GetText());
    }
    else
    {
        super(unk);
    }
}

HOOK_METHOD_PRIORITY(EquipmentBox, RenderIcon, 1000, () -> void)
{
    if (IsCargoBox() && IsAugment())
    {
        Equipment& equipment = G_->GetWorld()->commandGui->equipScreen;

        if (equipment.bDragging && this == equipment.vEquipmentBoxes[equipment.draggingEquipBox])
        {
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(-location.x, -location.y, 0.0);

            GL_Texture* augTex = G_->GetResources()->GetImageId("upgradeUI/Equipment/box_augment_on.png");
            CSurface::GL_BlitImage(augTex, location.x, location.y, augTex->width_, augTex->height_, 0.0, GL_Color(1.0,1.0,1.0,1.0), false);

            TextString title = item.augment->desc.title;
            freetype::easy_printCenter(13, location.x + 117, location.y + 14, title.GetText());

            CSurface::GL_PopMatrix();
        }
        else
        {
            auto custom = CustomAugmentManager::GetInstance();
            if (custom->IsAugment(item.augment->name))
            {
                auto def = custom->GetAugmentDefinition(item.augment->name);
                if (def != nullptr && !def->icon.empty())
                {
                    auto iconDef = ShipIconManager::instance->GetShipIconDefinition(def->icon);
                    if (iconDef != nullptr)
                    {
                        GL_Texture* augIcon = G_->GetResources()->GetImageId("combatUI/icons/" + iconDef->name + ".png");
                        CSurface::GL_BlitImage(augIcon, -0.5*augIcon->width_, -0.5*augIcon->height_ + 3.0, augIcon->width_, augIcon->height_, 0.0, GL_Color(1.0,1.0,1.0,1.0), false);
                    }
                }
            }
        }
    }
    else
    {
        super();
    }
}



/*
HOOK_METHOD(EquipmentBox, GetType, (bool unk) -> int)
{
    int ret = super(unk);
    if (ret == 4 && !unk && item.augment != nullptr)
    {
        return 4;
    }
    return ret;
}
*/

HOOK_METHOD_PRIORITY(Equipment, OnLoop, 500, () -> void)
{
    super();

    if (g_cargoAugments && bDragging)
    {
        EquipmentBox *draggingBox = vEquipmentBoxes[draggingEquipBox];
        if (draggingBox->IsAugment())
        {
            for (auto i : vEquipmentBoxes)
            {
                if (draggingBox->CanSwap(i))
                {
                    i->bBlocked = false;
                    i->overlayColor = GL_Color(100.f, 255.f, 100.f, 1.f);
                }
                else
                {
                    i->bBlocked = true;
                    i->overlayColor = GL_Color(255.f, 50.f, 50.f, 1.f);
                }
            }

            std::unordered_map<std::string, int> *augList = CustomAugmentManager::GetInstance()->GetShipAugments(shipManager->iShipId);

            if (draggingBox->IsCargoBox() || draggingBox == overAugBox)
            {
                if (!draggingBox->item.augment->stacking)
                {
                    int augCount = 0;
                    if (augList->count(draggingBox->item.augment->name))
                    {
                        augCount = augList->at(draggingBox->item.augment->name);
                    }

                    if (augCount > 0)
                    {
                        for (auto i : vEquipmentBoxes)
                        {
                            if (i->CanHoldAugment() && !i->IsCargoBox() && i != overAugBox)
                            {
                                i->bBlocked = true;
                                i->overlayColor = GL_Color(255.f, 50.f, 50.f, 1.f);
                            }
                        }
                    }
                }
            }
            else
            {
                for (auto i : vEquipmentBoxes)
                {
                    if (i->IsAugment() && (i->IsCargoBox() || i == overAugBox) && !i->item.augment->stacking)
                    {
                        int augCount = 0;
                        if (augList->count(i->item.augment->name))
                        {
                            augCount = augList->at(i->item.augment->name);
                        }

                        if (augCount > 0)
                        {
                            i->bBlocked = true;
                            i->overlayColor = GL_Color(255.f, 50.f, 50.f, 1.f);
                        }
                    }
                }
            }
        }
        else
        {
            overAugBox->bBlocked = true;
            overAugBox->overlayColor = GL_Color(255.f, 50.f, 50.f, 1.f);
        }
    }
}

HOOK_METHOD_PRIORITY(Equipment, AddAugment, 1000, (AugmentBlueprint *bp, bool unk1, bool unk2) -> void)
{
    if (!g_cargoAugments) return super(bp, unk1, unk2);

    if (!bp->name.empty())
    {
        bool success = !unk2 && shipManager->AddAugmentation(bp->name);
        if (!success)
        {
            EquipmentBoxItem item = EquipmentBoxItem();
            item.augment = bp;

            for (unsigned int i = cargoId; i<vEquipmentBoxes.size(); ++i)
            {
                if (vEquipmentBoxes[i]->IsEmpty())
                {
                    vEquipmentBoxes[i]->AddItem(item);
                    if (vEquipmentBoxes[i] == overcapacityBox)
                    {
                        if (!unk2) Open();
                        bOverCapacity = true;
                    }
                    else if (vEquipmentBoxes[i] == overAugBox)
                    {
                        if (!unk2) Open();
                        bOverAugCapacity = true;
                    }
                    else
                    {
                        for (auto box : vEquipmentBoxes)
                        {
                            box->weaponSys = shipManager->weaponSystem;
                            box->droneSys = shipManager->droneSystem;
                            box->CheckContents();
                        }
                    }
                    break;
                }
            }
        }
        else
        {
            for (auto box : vEquipmentBoxes)
            {
                box->weaponSys = shipManager->weaponSystem;
                box->droneSys = shipManager->droneSystem;
                box->CheckContents();
            }
        }
    }
}
