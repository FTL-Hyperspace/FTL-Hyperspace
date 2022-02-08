#pragma once

#include "palWindowsGeneric.h"
#include <random>

#include "zhl.h"
#include "FTLGame.h"

#include "Systems.h"
#include "Colors.h"


#include "CrewMember_Extend.h"
#include "ShipManager_Extend.h"
#include "System_Extend.h"
#include "Blueprint_Extend.h"
#include "Room_Extend.h"

//#include "LuaState.h"

extern bool loadingGame;

class Global
{
public:
    static Global *GetInstance() { return instance; }

    void PreInitializeResources(ResourceControl *resources);
    void InitializeResources(ResourceControl *resources);
    bool AreResourcesInitialized() { return __resourcesInitialized; }
    void Initialize();
    void SetCApp(CApp *cApp);

    ShipManager *GetShipManager(int iShipId);


    ResourceControl *GetResources() { return Global_ResourceControl_GlobalResources; }
    CApp *GetCApp() { return __cApp; }
    ShipInfo *GetShipInfo(bool enemy=false) { return enemy ? *Global_ShipObject_ShipInfoList : (ShipInfo*)((unsigned char*)*(Global_ShipObject_ShipInfoList) + sizeof(ShipInfo)); }
    WorldManager *GetWorld() { return GetCApp()->world; };
    CFPS *GetCFPS() { return Global_CFPS_FPSControl; }
    BlueprintManager *GetBlueprints() { return Global_BlueprintManager_Blueprints; }
    SoundControl *GetSoundControl() { return Global_SoundControl_Sounds; }
    MouseControl *GetMouseControl() { return Global_MouseControl_Mouse; }
    TextLibrary *GetTextLibrary() { return Global_Globals_Library; }
    CrewMemberFactory *GetCrewFactory() { return Global_CrewMemberFactory_Factory; }
    TutorialManager *GetTutorialManager() { return Global_TutorialManager_Tutorial; }
    EventGenerator *GetEventGenerator() { return Global_EventGenerator_Generator; }
    EventsParser *GetEventsParser() { return Global_EventsParser_Parser; }
    EventSystem *GetEventSystem() { return Global_EventSystem_EventManager; }
    AnimationControl *GetAnimationControl() { return Global_AnimationControl_Animations; }
    AchievementTracker *GetAchievementTracker() { return Global_AchievementTracker_Tracker; }
    ScoreKeeper *GetScoreKeeper() { return Global_ScoreKeeper_Keeper; }
    SettingValues *GetSettings() { return Global_Settings_Settings; }
    int GetVersion() { return __version; }

    void *GetVTable_LaserBlast() { return VTable_LaserBlast; }

    uint32_t GetBaseAddress() { return __baseAddress; }

    static bool* showBeaconPath;
    static unsigned int currentSeed;
    static bool isCustomSeed;
    static unsigned int sectorMapSeed;
    static std::mt19937 seededRng;
    static bool* showWelcome;
    static bool* dlcEnabled;
    static int* difficulty;
    static bool forceDlc;
    static FILE* logFile;
    static bool* firstTimeShips;
    static Point* dronePosition;
    static Point* weaponPosition;
    static GL_Color* superShieldColor;
    static GL_Color defaultSuperShieldColor;

    static unsigned int questSeed;
    static std::vector<unsigned int> delayedQuestSeeds;
    static int delayedQuestIndex;
    static std::vector<unsigned int> lastDelayedQuestSeeds;

    static unsigned int bossFleetSeed;

    static std::vector<std::vector<GL_Color*>> colorPointers;

    //LuaState* lua;

private:
    bool __resourcesInitialized;
    static Global* instance;

    uint32_t __baseAddress = 0;

    static CApp *__cApp;

    const int __version = 91;


};

void hs_log_file(const char *str...);

#define G_ (Global::GetInstance())
