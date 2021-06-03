#pragma once
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
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
#include <random>

//#include "LuaState.h"


class Global
{
public:
    static Global *GetInstance() { return instance; }

    void InitializeResources(ResourceControl *resources);
    bool AreResourcesInitialized() { return __resourcesInitialized; }
    void Initialize();
    void SetCApp(CApp *cApp);

    ShipManager *GetShipManager(int iShipId);


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
    EventGenerator *GetEventGenerator() { return __eventGenerator; }
    EventsParser *GetEventsParser() { return __eventsParser; }
    EventSystem *GetEventSystem() { return __eventSystem; }
    AnimationControl *GetAnimationControl() { return __animations; }
    AchievementTracker *GetAchievementTracker() { return __achievementTracker; }
    ScoreKeeper *GetScoreKeeper() { return __scoreKeeper; }
    SettingValues *GetSettings() { return __settingValues; }
    int GetVersion() { return __version; }

    DWORD GetBaseAddress() { return __baseAddress; }

    static bool* showBeaconPath;
    static unsigned int currentSeed;
    static bool isCustomSeed;
    static unsigned int sectorMapSeed;
    static int64_t* randomState;
    static std::mt19937 seededRng;
    static bool* showWelcome;
    static bool* dlcEnabled;
    static int* difficulty;
    static bool forceDlc;
    static FILE* logFile;
    static bool* firstTimeShips;
    static std::pair<Point, Point>* droneWeaponPosition;

    static unsigned int questSeed;
    static std::vector<unsigned int> delayedQuestSeeds;
    static int delayedQuestIndex;
    static std::vector<unsigned int> lastDelayedQuestSeeds;

    static unsigned int bossFleetSeed;

    //static ShaderSourceCallback** fragment_shader_source_callback;

    //LuaState* lua;

private:
    bool __resourcesInitialized;
    static Global* instance;



    const DWORD __resourcesOffset =        0x004CB680;
    const DWORD __shipInfoOffset =         0x004C6F80;
    const DWORD __cFPSOffset =             0x004CB600;
    const DWORD __blueprintOffset =        0x004CBD60;
    const DWORD __soundOffset =            0x004CB820;
    const DWORD __mouseOffset =            0x004C76C0;
    const DWORD __textOffset =             0x004CB7C0;
    const DWORD __rngOffset =              0x004CB7A0;
    const DWORD __crewFactoryOffset =      0x004C6E40;
    const DWORD __tutorialOffset =         0x004C5340;
    const DWORD __eventGenOffset =         0x004CB920;
    const DWORD __eventsParseOffset =      0x004CBB60;
    const DWORD __beaconPathOffset =       0x004C8CF6;
    const DWORD __eventSystemOffset =      0x004CB640;
    const DWORD __randomStateOffset =      0x00428110;
    const DWORD __showWelcomeOffset =      0x004C8CE9;
    const DWORD __dlcEnabledOffset =       0x004C8D2D;
    const DWORD __animationsOffset =       0x004CB0A0;
    const DWORD __difficultyOffset =       0x004C8CB4;
    const DWORD __fragmentCallbackOffset = 0x004DC53C;
    const DWORD __achievementOffset =      0x004C5780;
    const DWORD __scoreKeeperOffset =      0x004C5980;
    const DWORD __firstTimeShipsOffset =   0x004C8D30;
    const DWORD __settingValuesOffset =    0x004C8CA0;
    const DWORD __droneWeaponPosOffset =   0x004C7400;

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
    static EventGenerator *__eventGenerator;
    static EventsParser *__eventsParser;
    static EventSystem *__eventSystem;
    static AnimationControl *__animations;
    static AchievementTracker *__achievementTracker;
    static ScoreKeeper *__scoreKeeper;
    static SettingValues *__settingValues;

    const int __version = 71;


};

void hs_log_file(const char *str...);

#define G_ (Global::GetInstance())
