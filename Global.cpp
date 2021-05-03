#include "Global.h"
#include "Resources.h"
#include <chrono>

Global *Global::instance = new Global();

ResourceControl* Global::__resourceControl = nullptr;
CApp* Global::__cApp = nullptr;
ShipInfo** Global::__enemyShipInfo = nullptr;
CFPS* Global::__cFPS = nullptr;
BlueprintManager *Global::__blueprints = nullptr;
SoundControl *Global::__soundControl = nullptr;
MouseControl *Global::__mouseControl = nullptr;
TextLibrary *Global::__textLibrary = nullptr;
CrewMemberFactory *Global::__crewFactory = nullptr;
TutorialManager *Global::__tutorialManager = nullptr;
EventGenerator *Global::__eventGenerator = nullptr;
EventsParser *Global::__eventsParser = nullptr;
EventSystem *Global::__eventSystem = nullptr;
AnimationControl *Global::__animations = nullptr;
AchievementTracker *Global::__achievementTracker = nullptr;
ScoreKeeper *Global::__scoreKeeper = nullptr;

bool *Global::showBeaconPath = nullptr;
unsigned int Global::currentSeed = 0;
int64_t *Global::randomState = nullptr;
std::mt19937 Global::seededRng;
bool *Global::showWelcome = nullptr;
bool *Global::dlcEnabled = nullptr;
int *Global::difficulty = nullptr;
bool Global::forceDlc = false;
bool Global::isCustomSeed = false;
unsigned int Global::sectorMapSeed = -1;
FILE *Global::logFile = nullptr;
bool *Global::firstTimeShips = nullptr;

void hs_log_file(const char *str...)
{
    va_list va;
    va_start(va, str);

    FILE* log = G_->logFile;
    if (log != nullptr)
    {
        vfprintf(log, str, va);
        fflush(G_->logFile);
    }
    va_end(va);
}

HOOK_METHOD(CApp, OnInit, () -> int)
{
    G_->Initialize(this);
    return super();
}

ShipManager* Global::GetShipManager(int iShipId)
{
    ShipManager *playerShip = NULL;

    if (G_->GetWorld()->playerShip)
    {
        playerShip = G_->GetWorld()->playerShip->shipManager;
    }
    else
    {
        playerShip = G_->GetCApp()->menu.shipBuilder.currentShip;
    }

    if (iShipId == 1 && playerShip)
    {
        return playerShip->current_target;
    }
    else
    {
        return playerShip;
    }
}

void Global::Initialize(CApp *cApp)
{
    printf("Initializing Hyperspace...\n");
    __baseAddress = (DWORD)GetModuleHandle(NULL);


    __resourceControl = (ResourceControl*)(__baseAddress + __resourcesOffset);
    __cApp = cApp;
    __cFPS = (CFPS*)(__baseAddress + __cFPSOffset);
    __enemyShipInfo = (ShipInfo**)(__baseAddress + __shipInfoOffset);
    __blueprints = (BlueprintManager*)(__baseAddress + __blueprintOffset);
    __soundControl = (SoundControl*)(__baseAddress + __soundOffset);
    __mouseControl = (MouseControl*)(__baseAddress + __mouseOffset);
    __textLibrary = (TextLibrary*)(__baseAddress + __textOffset);
    __crewFactory = (CrewMemberFactory*)(__baseAddress + __crewFactoryOffset);
    __tutorialManager = (TutorialManager*)(__baseAddress + __tutorialOffset);
    __eventGenerator = (EventGenerator*)(__baseAddress + __eventGenOffset);
    __eventsParser = (EventsParser*)(__baseAddress + __eventsParseOffset);
    __eventSystem = (EventSystem*)(__baseAddress + __eventSystem);
    __animations = (AnimationControl*)(__baseAddress + __animationsOffset);
    __achievementTracker = (AchievementTracker*)(__baseAddress + __achievementOffset);
    __scoreKeeper = (ScoreKeeper*)(__baseAddress + __scoreKeeperOffset);
    seededRng = std::mt19937(std::chrono::system_clock::now().time_since_epoch().count());
    currentSeed = 0;

    showWelcome = (bool*)((__baseAddress + __showWelcomeOffset));
    showBeaconPath = (bool*)((__baseAddress + __beaconPathOffset));
    dlcEnabled = (bool*)((__baseAddress + __dlcEnabledOffset));
    difficulty = (int*)((__baseAddress + __difficultyOffset));
    firstTimeShips = (bool*)((__baseAddress + __firstTimeShipsOffset));
    *firstTimeShips = false;
    //fragment_shader_source_callback = (ShaderSourceCallback**)((__baseAddress + __fragmentCallbackOffset));
    logFile = fopen("FTL_HS.log", "w");



    SetWindowTextA((HWND)GetModuleHandle(NULL), "FTL: Hyperspace");
    printf("Hyperspace initialized\n");
}
