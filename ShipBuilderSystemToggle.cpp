#include "ShipBuilderSystemToggle.h"

static ShipManager* g_realShip = nullptr;
static ShipManager* g_allSystemsShip = nullptr;
static TextButton g_showSystemsButton;

HOOK_METHOD(ShipBuilder, constructor, () -> void)
{
    super();

    g_showSystemsButton = TextButton();
    g_showSystemsButton.bActive = true;
    g_showSystemsButton.SetLocation(Point(300,300));
}

HOOK_METHOD(ShipBuilder, Open, () -> void)
{
    super();

    g_realShip = currentShip;
}

HOOK_METHOD(ShipBuilder, SwitchShip, (int shipType, int shipVariant) -> void)
{
    super(shipType, shipVariant);

    if (currentShip)
    {
        g_realShip = currentShip;
        if (g_allSystemsShip)
        {
            delete g_allSystemsShip;
            g_allSystemsShip = nullptr;
        }
    }
}

HOOK_METHOD(ShipBuilder, OnLoop, () -> void)
{
    if (g_showSystemsButton.bActive)
    {
        if (!g_allSystemsShip)
        {
//            g_allSystemsShip = new ShipManager(0);
//            g_allSystemsShip->OnInit(&(currentShip->myBlueprint), -1);
//            for (int i = 0; i < 30; ++i)
//            {
//                g_allSystemsShip->AddSystem(i);
//            }
        }
        currentShip = g_allSystemsShip;
    }
    else
    {
        currentShip = g_realShip;
    }

    super();
}

HOOK_METHOD(ShipBuilder, OnRender, () -> void)
{
    super();
    g_showSystemsButton.OnRender();
}
