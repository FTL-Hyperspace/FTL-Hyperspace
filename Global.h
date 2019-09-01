#pragma once
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

#include "zhl.h"
#include "FTLGame.h"

#include "Systems.h"
#include "Colors.h"


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
    MouseControl *GetMouseControl() { return __mouseControl; }
    TextLibrary *GetTextLibrary() { return __textLibrary; }
    CrewMemberFactory *GetCrewFactory() { return __crewFactory; }
    TutorialManager *GetTutorialManager() { return __tutorialManager; }

    bool GetRNG() { return *__rng; }

    DWORD GetBaseAddress() { return __baseAddress; }

private:
    bool __resourcesInitialized;
    static Global* instance;




    const DWORD __resourcesOffset =   0x004CB680;
    const DWORD __shipInfoOffset =    0x004C6F80;
    const DWORD __cFPSOffset =        0x004CB600;
    const DWORD __blueprintOffset =   0x004CBD60;
    const DWORD __soundOffset =       0x004CB820;
    const DWORD __mouseOffset =       0x004C76C0;
    const DWORD __textOffset =        0x004CB7C0;
    const DWORD __rngOffset =         0x004CB7A0;
    const DWORD __crewFactoryOffset = 0x004C6E40;
    const DWORD __tutorialOffset =    0x004C5340;

    DWORD __baseAddress = 0;

    static ResourceControl *__resourceControl;
    static CApp *__cApp;
    static ShipInfo **__enemyShipInfo;
    static CFPS *__cFPS;
    static BlueprintManager *__blueprints;
    static SoundControl *__soundControl;
    static MouseControl *__mouseControl;
    static TextLibrary *__textLibrary;
    static CrewMemberFactory *__crewFactory;
    static TutorialManager *__tutorialManager;

    static bool* __rng;
};


#define G_ (Global::GetInstance())
