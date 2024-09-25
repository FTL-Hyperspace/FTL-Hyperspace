#include "Global.h"
#include "CustomOptions.h"

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

struct EquipmentInfo
{
    static bool has_weapon;
    static bool has_drone;
    static int weapon_max_slots;
    static int drone_max_slots;
    static int pos_x;
    static int pos_y;
    static bool dummyEquBoxesRenderingCompleted;
};

bool EquipmentInfo::has_weapon = false;
bool EquipmentInfo::has_drone = false;
int EquipmentInfo::weapon_max_slots = 0;
int EquipmentInfo::drone_max_slots = 0;
int EquipmentInfo::pos_x = 0;
int EquipmentInfo::pos_y = 0;
bool EquipmentInfo::dummyEquBoxesRenderingCompleted = true;

static bool g_renderDummyEquBoxesUnderNoEquText = false;

HOOK_METHOD(TextLibrary, GetText, (const std::string& name, const std::string& lang) -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> TextLibrary::GetText -> Begin (Misc.cpp)\n")

    if (g_renderDummyEquBoxesUnderNoEquText && name == "equipment_no_system" && !EquipmentInfo::dummyEquBoxesRenderingCompleted)
    {
        GL_Color originalColor = CSurface::GL_GetColor();
        if (!EquipmentInfo::has_weapon)
        {
            int max_slots = EquipmentInfo::weapon_max_slots;
            int start_x = (4 - max_slots) * 58 + EquipmentInfo::pos_x + 64;
            GL_Texture *weaponBoxOffTexture = G_->GetResources()->GetImageId("upgradeUI/Equipment/box_weapons_off.png");
            for (int i = 0; i < max_slots; i++)
            {
                GL_Primitive *weaponBoxOffPrimitive = CSurface::GL_CreateImagePrimitive(weaponBoxOffTexture, start_x + (i * 117), EquipmentInfo::pos_y + 70, weaponBoxOffTexture->width_, weaponBoxOffTexture->height_, 0.f, GL_Color(1.f, 1.f, 1.f, 0.2f));
                CSurface::GL_RenderPrimitive(weaponBoxOffPrimitive);
            }
        }

        if (!EquipmentInfo::has_drone)
        {
            int max_slots = EquipmentInfo::drone_max_slots;
            int start_x = (4 - max_slots) * 58 + EquipmentInfo::pos_x + 64;
            GL_Texture *droneBoxOffTexture = G_->GetResources()->GetImageId("upgradeUI/Equipment/box_drones_off.png");
            for (int i = 0; i < max_slots; i++)
            {
                GL_Primitive *droneBoxOffPrimitive = CSurface::GL_CreateImagePrimitive(droneBoxOffTexture, start_x + (i * 117), EquipmentInfo::pos_y + 180, droneBoxOffTexture->width_, droneBoxOffTexture->height_, 0.f, GL_Color(1.f, 1.f, 1.f, 0.2f));
                CSurface::GL_RenderPrimitive(droneBoxOffPrimitive);
            }
        }
        
        CSurface::GL_SetColor(originalColor);
        EquipmentInfo::dummyEquBoxesRenderingCompleted = true;
    }
    return super(name, lang);
}

HOOK_METHOD(Equipment, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Equipment::OnRender -> Begin (Misc.cpp)\n")

    if (!CustomOptionsManager::GetInstance()->showDummyEquipmentSlots.currentValue || (shipManager->HasSystem(3) && shipManager->HasSystem(4)))
    {
        super();
        return;
    }

    EquipmentInfo::has_weapon = shipManager->HasSystem(3);
    EquipmentInfo::has_drone = shipManager->HasSystem(4);
    EquipmentInfo::weapon_max_slots = shipManager->myBlueprint.weaponSlots;
    EquipmentInfo::drone_max_slots = shipManager->myBlueprint.droneSlots;
    EquipmentInfo::pos_x = position.x;
    EquipmentInfo::pos_y = position.y;
    EquipmentInfo::dummyEquBoxesRenderingCompleted = false;

    g_renderDummyEquBoxesUnderNoEquText = true;
    super();
    g_renderDummyEquBoxesUnderNoEquText = false;
}