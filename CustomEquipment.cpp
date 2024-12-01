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


// displays transparent weapon/drone slots for not installed weapon/drone system

static GL_Texture* weaponBoxOffTexture = nullptr;
static GL_Texture* droneBoxOffTexture = nullptr;
static std::vector<GL_Primitive*> dummyWeaponSlots;
static std::vector<GL_Primitive*> dummyDroneSlots;

static bool g_hasWeapon;
static bool g_hasDrone;
static bool g_dummyEquBoxesRenderingCompleted;

static bool g_renderDummyEquBoxesUnderNoEquText = false;

HOOK_METHOD(Equipment, OnInit, (ShipManager *ship) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Equipment::OnInit -> Begin (CustomEquipment.cpp)\n")

    if (!CustomOptionsManager::GetInstance()->showDummyEquipmentSlots.currentValue) return super(ship);

    if (!weaponBoxOffTexture) weaponBoxOffTexture = G_->GetResources()->GetImageId("upgradeUI/Equipment/box_weapons_off.png");
    if (!droneBoxOffTexture) droneBoxOffTexture = G_->GetResources()->GetImageId("upgradeUI/Equipment/box_drones_off.png");

    for (auto primitive : dummyWeaponSlots)
    {
        CSurface::GL_DestroyPrimitive(primitive);
    }
    dummyWeaponSlots.clear();
    for (auto primitive : dummyDroneSlots)
    {
        CSurface::GL_DestroyPrimitive(primitive);
    }
    dummyDroneSlots.clear();

    if (!ship->HasSystem(3))
    {
        int max_slots = ship->myBlueprint.weaponSlots;
        int start_x = (4 - max_slots) * 58 + position.x + 64;
        for (int i = 0; i < max_slots; i++)
        {
            dummyWeaponSlots.push_back(CSurface::GL_CreateImagePrimitive(weaponBoxOffTexture, start_x + (i * 117), position.y + 70, weaponBoxOffTexture->width_, weaponBoxOffTexture->height_, 0.f, GL_Color(1.f, 1.f, 1.f, 0.2f)));
        }
    }
    if (!ship->HasSystem(4))
    {
        int max_slots = ship->myBlueprint.droneSlots;
        int start_x = (4 - max_slots) * 58 + position.x + 64;
        for (int i = 0; i < max_slots; i++)
        {
            dummyDroneSlots.push_back(CSurface::GL_CreateImagePrimitive(droneBoxOffTexture, start_x + (i * 117), position.y + 180, droneBoxOffTexture->width_, droneBoxOffTexture->height_, 0.f, GL_Color(1.f, 1.f, 1.f, 0.2f)));
        }
    }

    super(ship);
}

HOOK_METHOD(TextLibrary, GetText, (const std::string& name, const std::string& lang) -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> TextLibrary::GetText -> Begin (CustomEquipment.cpp)\n")

    if (g_renderDummyEquBoxesUnderNoEquText && name == "equipment_no_system" && !g_dummyEquBoxesRenderingCompleted)
    {
        GL_Color originalColor = CSurface::GL_GetColor();
        if (!g_hasWeapon)
        {
            for (auto primitive : dummyWeaponSlots)
            {
                CSurface::GL_RenderPrimitive(primitive);
            }
        }
        if (!g_hasDrone)
        {
            for (auto primitive : dummyDroneSlots)
            {
                CSurface::GL_RenderPrimitive(primitive);
            }
        }
        CSurface::GL_SetColor(originalColor);
        g_dummyEquBoxesRenderingCompleted = true; // prevent from calling twice; when both weapon and drone are not installed
    }
    return super(name, lang);
}

HOOK_METHOD(Equipment, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Equipment::OnRender -> Begin (CustomEquipment.cpp)\n")

    if (!CustomOptionsManager::GetInstance()->showDummyEquipmentSlots.currentValue || (shipManager->HasSystem(3) && shipManager->HasSystem(4))) return super();

    g_hasWeapon = shipManager->HasSystem(3);
    g_hasDrone = shipManager->HasSystem(4);
    g_dummyEquBoxesRenderingCompleted = false;
    g_renderDummyEquBoxesUnderNoEquText = true;
    super();
    g_renderDummyEquBoxesUnderNoEquText = false;
}
