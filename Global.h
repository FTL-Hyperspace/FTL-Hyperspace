#pragma once
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

#include "zhl.h"
#include "FTLGame.h"

#include "Systems.h"

#include "CrewMember_Extend.h"
#include "ShipManager_Extend.h"

class Global
{
public:
    static Global *GetInstance() { return instance; }

    void InitializeResources(ResourceControl *resources);
    bool AreResourcesInitialized() { return __resourcesInitialized; }
    void Initialize(CApp *cApp);


    ResourceControl *GetResources() { return __resourceControl; }
    CApp *GetCApp() { return __cApp; }
    ShipInfo *GetShipInfo(bool enemy=false) { return enemy ? *__enemyShipInfo : (ShipInfo*)((unsigned char*)*(__enemyShipInfo) + sizeof(ShipInfo)); }
    WorldManager *GetWorld() { return GetCApp()->world; };
    CFPS *GetCFPS() { return __cFPS; }
    BlueprintManager *GetBlueprints() { return __blueprints; }
    SoundControl *GetSoundControl() { return __soundControl; }
    DWORD GetBaseAddress() { return __baseAddress; }

private:
    bool __resourcesInitialized;
    static Global* instance;




    const DWORD __resourcesOffset = 0x004CB680;
    const DWORD __shipInfoOffset =  0x004C6F80;
    const DWORD __cFPSOffset =      0x004CB600;
    const DWORD __blueprintOffset = 0x004CBD60;
    const DWORD __soundOffset =     0x004CB820;

    DWORD __baseAddress = 0;

    static ResourceControl *__resourceControl;
    static CApp *__cApp;
    static ShipInfo **__enemyShipInfo;
    static CFPS *__cFPS;
    static BlueprintManager *__blueprints;
    static SoundControl *__soundControl;
};


#define G_ (Global::GetInstance())
