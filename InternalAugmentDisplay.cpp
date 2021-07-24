#include "InternalAugmentDisplay.h"
#include "CustomAugments.h"

static const int g_internalAugmentVTableSize = 16;
static void* g_internalAugmentVTable[g_internalAugmentVTableSize];

InternalAugmentWindow* InternalAugmentWindow::instance = nullptr;


static void __attribute__((fastcall)) InternalAugmentWindow_Open(InternalAugmentWindow *_this)
{
    _this->bOpen = true;


}

void SetupVTable(InternalAugmentWindow* window)
{
    void** vtable = *(void***)window;

    DWORD dwOldProtect, dwBkup;
    VirtualProtect(&vtable[0], sizeof(void*) * g_internalAugmentVTableSize, PAGE_EXECUTE_READWRITE, &dwOldProtect);

    for (int i = 0; i < g_internalAugmentVTableSize; i++)
    {
        g_internalAugmentVTable[i] = vtable[i];
    }

    VirtualProtect(&vtable[0], sizeof(void*) * g_internalAugmentVTableSize, dwOldProtect, &dwBkup);



    *((void**)window)= &g_internalAugmentVTable;
}

HOOK_METHOD(CommandGui, constructor, () -> void)
{
    super();

    InternalAugmentWindow::instance = new InternalAugmentWindow();
    SetupVTable(InternalAugmentWindow::GetInstance());
}

HOOK_METHOD(CommandGui, LinkShip, (CompleteShip *ship) -> void)
{
    super(ship);

    // if there are any internal augments
    Button* internalButton = new Button();
    Globals::Rect imgRect{264, -7, 109, 48};
    Globals::Rect hitboxRect{197, 0, 103, 38};

    internalButton->OnInitRect("upgradeUI/Equipment/tabButtons/upgrades_equipment", imgRect, hitboxRect, false);

    shipScreens.AddWindow("internals", internalButton, InternalAugmentWindow::GetInstance());
}

static std::string g_lastResource = "";

HOOK_METHOD(ResourceControl, GetImageId, (const std::string& name) -> GL_Texture*)
{
    if (name == "nullResource.png")
    {
        printf("%s\n", g_lastResource.c_str());
    }
    else
    {
        g_lastResource = name;
    }

    return super(name);
}
