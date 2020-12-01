#include "Global.h"

HOOK_STATIC(BlueprintManager, ProcessWeaponBlueprint, (WeaponBlueprint* bp, BlueprintManager *bpM, rapidxml::xml_node<char>* node) -> WeaponBlueprint*)
{
    super(bp, bpM, node);

    auto ex = BP_EX(bp)->weapon;

    for (auto child = node->first_node(); child = child->next_sibling(); child)
    {
        std::string name = child->name();
        std::string val = child->value();

        if (name == "rainbow")
        {

        }
    }

    return bp;
}

HOOK_METHOD(ShipManager, OnRender, (bool showInterior, bool doorControlMode) -> void)
{
    if (bJumping)
    {
        auto time = jumpAnimation.current_time;
        if (time >= 1.0)
        {
            CSurface::GL_SetColorTint(255.f, 255.f, 255.f, 1.f - ((time - 1.f) * 2.f));
            RenderWeapons();
            CSurface::GL_RemoveColorTint();
        }
        else
        {
            RenderWeapons();
        }
    }
    super(showInterior, doorControlMode);

}

static bool artillery = false;

HOOK_METHOD(ProjectileFactory, NumTargetsRequired, () -> int)
{
    int ret = super();

    if (artillery)
    {
        int rooms = ShipGraph::GetShipInfo(!iShipId)->rooms.size();
        if (ret > rooms)
        {
            return rooms;
        }
    }

    return ret;
}

HOOK_METHOD(ArtillerySystem, OnLoop, () -> void)
{
    artillery = true;
    super();
    artillery = false;
}
