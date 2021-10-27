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
SettingValues *Global::__settingValues = nullptr;

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
std::pair<Point, Point> *Global::droneWeaponPosition = nullptr;
GL_Color *Global::superShieldColor = nullptr;
//GL_Color Global::defaultSuperShieldColor = GL_Color(255.0, 255.0, 255.0, 1.0);

void *Global::__vtableLaserBlast = nullptr;

unsigned int Global::questSeed = 0;
std::vector<unsigned int> Global::delayedQuestSeeds = std::vector<unsigned int>();
int Global::delayedQuestIndex = 0;
std::vector<unsigned int> Global::lastDelayedQuestSeeds = std::vector<unsigned int>();

std::vector<std::vector<GL_Color*>> Global::colorPointers = std::vector<std::vector<GL_Color*>>();
std::vector<std::vector<DWORD>> Global::colorOffsets
{
    { 0x004C84E0 }, // detailsBarOn
    { 0x004C84F0 }, // detailsBarOff
};


unsigned int Global::bossFleetSeed = 0;

bool loadingGame = false;

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
    G_->SetCApp(this);
    return super();
}

ShipManager* Global::GetShipManager(int iShipId)
{
    if (G_->GetCApp()->menu.shipBuilder.bOpen)
    {
        return iShipId == 1 ? nullptr : G_->GetCApp()->menu.shipBuilder.currentShip;
    }

    CompleteShip *playerShip = G_->GetWorld()->playerShip;

    if (playerShip)
    {
        if (iShipId == 1) return playerShip->enemyShip ? playerShip->enemyShip->shipManager : nullptr;
        return playerShip->shipManager;
    }
    return nullptr;
}

void Global::SetCApp(CApp *cApp)
{
    __cApp = cApp;
}

void Global::Initialize()
{
    printf("Initializing Hyperspace...\n");
    __baseAddress = (DWORD)GetModuleHandle(NULL);


    __resourceControl = (ResourceControl*)(__baseAddress + __resourcesOffset);
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
    __eventSystem = (EventSystem*)(__baseAddress + __eventSystemOffset);
    __animations = (AnimationControl*)(__baseAddress + __animationsOffset);
    __achievementTracker = (AchievementTracker*)(__baseAddress + __achievementOffset);
    __scoreKeeper = (ScoreKeeper*)(__baseAddress + __scoreKeeperOffset);
    __settingValues = (SettingValues*)(__baseAddress + __settingValuesOffset);
    seededRng = std::mt19937(std::chrono::system_clock::now().time_since_epoch().count());
    currentSeed = 0;

    showWelcome = (bool*)((__baseAddress + __showWelcomeOffset));
    showBeaconPath = (bool*)((__baseAddress + __beaconPathOffset));
    dlcEnabled = (bool*)((__baseAddress + __dlcEnabledOffset));
    difficulty = (int*)((__baseAddress + __difficultyOffset));
    firstTimeShips = (bool*)((__baseAddress + __firstTimeShipsOffset));
    *firstTimeShips = false;
    droneWeaponPosition = (std::pair<Point, Point>*)((__baseAddress + __droneWeaponPosOffset));
    //fragment_shader_source_callback = (ShaderSourceCallback**)((__baseAddress + __fragmentCallbackOffset));
    superShieldColor = (GL_Color*)((__baseAddress + __superShieldColorOffset));
    //defaultSuperShieldColor = *superShieldColor;
    //*superShieldColor = GL_Color(1084.0, 0.0, 310.0, 1.0);

    __vtableLaserBlast = (void*)(__baseAddress + __vtableLaserBlastOffset);

    for (auto vec : colorOffsets)
    {
        std::vector<GL_Color*> newVec = std::vector<GL_Color*>();

        for (auto offset : vec)
        {
            newVec.push_back((GL_Color*)(__baseAddress + offset));
        }

        colorPointers.push_back(newVec);
    }

    logFile = fopen("FTL_HS.log", "w");



    SetWindowTextA((HWND)GetModuleHandle(NULL), "FTL: Hyperspace");
    printf("Hyperspace initialized\n");
}

HOOK_METHOD(WorldManager, LoadGame, (const std::string file) -> void)
{
    loadingGame = true;
    super(file);
    loadingGame = false;
}
