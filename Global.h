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

    void *GetVTable_LaserBlast() { return VTable_LaserBlast; }

    uint32_t GetBaseAddress() { return __baseAddress; }

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
    static GL_Color* superShieldColor;
    static GL_Color defaultSuperShieldColor;

    static unsigned int questSeed;
    static std::vector<unsigned int> delayedQuestSeeds;
    static int delayedQuestIndex;
    static std::vector<unsigned int> lastDelayedQuestSeeds;

    static unsigned int bossFleetSeed;

    static std::vector<std::vector<GL_Color*>> colorPointers;

    static ShaderSourceCallback** fragment_shader_source_callback;

    //LuaState* lua;

private:
    bool __resourcesInitialized;
    static Global* instance;


    // TODO: Find these offsets in the Windows EXE file and replace this hardcoded crap with either Linux hardcoded crap (and make 4 different versions) or with sigscanner variable stuff?
    // Note in Windows these are + 0x400000 because the DOS image starts at 40,00,00h
    // Note it looks like we might be able to match these with ZHL SigScanner if we match references to the variables.
    // It's pretty easy to hardcode the addresses directly but we'd also end up with more versions of the library to deal with GOG vs Steam binary versions that have different offsets
    // Also SigScanner might be preferred in case these are not loaded into the ELF LOAD with READ EXECUTE segment and might be in another segment that is not contigous in memory from where our base pointer to the LOAD RE segment is.
    // These addresses might all be off by 0804edd0 and it might need to be subtracted.
    const uint32_t __resourcesOffset =        /*0x084a32e0*/ 0x0849d220 /*- 0x08048000*/; // 0x084a32e0 (offset) on 1.16.13.steam.x86 binary, 0x0849d220 (offset) on 1.6.12.gog.x86 binary "_ZN15ResourceControl15GlobalResourcesE ResourceControl::GlobalResources"
    const uint32_t __shipInfoOffset =         /*0x0849c680*/ 0x084965c0 /*- 0x08048000*/; // 0x0849c680 _ZN10ShipObject12shipInfoListE ShipObject::shipInfoList
    const uint32_t __cFPSOffset =             /*0x084a21c0*/ 0x0849c100 /*- 0x08048000*/; // 0x084a21c0 _ZN4CFPS10FPSControlE CFPS::FPSControl
    const uint32_t __blueprintOffset =        /*0x084a4d40*/ 0x0849ec80 /*- 0x08048000*/; // 0x084a4d40 _ZN16BlueprintManager10BlueprintsE BlueprintManager::Blueprints
    const uint32_t __soundOffset =            /*0x084a43e0*/ 0x0849e320 /*- 0x08048000*/; // 0x084a43e0 _ZN12SoundControl6SoundsE SoundControl::Sounds
    const uint32_t __mouseOffset =            /*0x0849f140*/ 0x08499080 /*- 0x08048000*/; // 0x0849f140 _ZN12MouseControl5MouseE MouseControl::Mouse
    const uint32_t __textOffset =             /*0x084a2d80*/ 0x0849ccc0 /*- 0x08048000*/; // 0x084a2d80 _ZN7Globals7LibraryE Globals::Library
    const uint32_t __rngOffset =              /*0x084a2d60*/ 0x0849cca0 /*- 0x08048000*/; // 0x084a2d60 _ZN7Globals3RNGE Globals::RNG
    const uint32_t __crewFactoryOffset =      /*0x0849b7e0*/ 0x08495720 /*- 0x08048000*/; // 0x0849b7e0 _ZN17CrewMemberFactory7FactoryE CrewMemberFactory::Factory
    const uint32_t __tutorialOffset =         /*0x0849af00*/ 0x08494e40 /*- 0x08048000*/; // 0x0849af00 _ZN15TutorialManager8TutorialE TutorialManager::Tutorial
    const uint32_t __eventGenOffset =         /*0x084a5350*/ 0x0849f2a0 /*- 0x08048000*/; // 0x084a5350 _ZN14EventGenerator9GeneratorE EventGenerator::Generator
    const uint32_t __eventsParseOffset =      /*0x084a5660*/ 0x0849f5a0 /*- 0x08048000*/; // 0x084a5660 _ZN12EventsParser6ParserE EventsParser::Parser
    const uint32_t __beaconPathOffset =       /*0x084a37a2*/ 0x0849d6e2 /*- 0x08048000*/; // 0x084a37a2 showPaths in _ZN8Settings8settingsE Settings::settings which is at 0x084a3760, probably better to match the struct? // WHY is this defined, can just use __settingValuesOffset & struct to get the value
    const uint32_t __eventSystemOffset =      /*0x084a2a30*/ 0x0849c970 /*- 0x08048000*/; // 0x084a2a30 _ZN11EventSystem12EventManagerE EventSystem::EventManager
    const uint32_t __randomStateOffset =      /*0x08497730*/ 0x08491720 /*- 0x08048000*/; // 0x08497730 _sil_random_state, note the value is a uint64_t in the Linux dissassembly but seen as two separate 32 bit values in Windows, looks like some code uses __sil_random_state+4 so some are reading the upper 32-bits
    const uint32_t __showWelcomeOffset =      /*0x084a3795*/ 0x0849d6d5 /*- 0x08048000*/; // 0x084a3795 // Probably in Settings::settings // WHY is this defined, can just use __settingValuesOffset & struct to get the value
    const uint32_t __dlcEnabledOffset =       /*0x084a37d9*/ 0x0849d719 /*- 0x08048000*/; // 0x084a37d9 // in Settings::settings // WHY is this defined, can just use __settingValuesOffset & struct to get the value
    const uint32_t __animationsOffset =       /*0x084a14a0*/ 0x0849b3e0 /*- 0x08048000*/; // 0x084a14a0 _ZN16AnimationControl10AnimationsE AnimationControl::Animations
    const uint32_t __difficultyOffset =       /*0x084a3774*/ 0x0849d6b4 /*- 0x08048000*/; // 0x084a3774 // Probably in Settings::settings
    const uint32_t __fragmentCallbackOffset = /*0x084b6e40*/ 0x084b0d00 /*- 0x08048000*/; // 0x084b6e40 fragment_shader_source_callback
    const uint32_t __achievementOffset =      /*0x08498880*/ 0x084927c0 /*- 0x08048000*/; // 0x08498880 _ZN18AchievementTracker7TrackerE AchievementTracker::Tracker
    const uint32_t __scoreKeeperOffset =      /*0x08499a60*/ 0x084939a0 /*- 0x08048000*/; // 0x08499a60 _ZN11ScoreKeeper6KeeperE ScoreKeeper::Keeper
    const uint32_t __firstTimeShipsOffset =   /*0x084a37dc*/ 0x0849d71c /*- 0x08048000*/; // 0x084a37dc // Probably in Settings::settings  // WHY is this defined, can just use __settingValuesOffset & struct to get the value
    const uint32_t __settingValuesOffset =    /*0x084a3760*/ 0x0849d6a0 /*- 0x08048000*/; // 0x084a3760  // Settings::settings // WHY is this defined, can just use __settingValuesOffset & struct to get the value
    const uint32_t __droneWeaponPosOffset =   /*0x084a0780*/ 0x0849a6c0 /*- 0x08048000*/; // 0x084a0780 _ZN13SystemControl14drone_positionE SystemControl::drone_position

    const uint32_t __superShieldColorOffset = /*0x084a7080*/ 0x084a0fc0 /*- 0x08048000*/; // 0x084a7080 _ZL11COLOR_GREEN COLOR_GREEN (referenced in _ZN7Shields10RenderBaseEff Shields::RenderBase, it is referenced at 0x082a33b4)

    static std::vector<std::vector<uint32_t>> colorOffsets;

    uint32_t __baseAddress = 0;

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

    const int __version = 8;


};

void hs_log_file(const char *str...);

#define G_ (Global::GetInstance())
