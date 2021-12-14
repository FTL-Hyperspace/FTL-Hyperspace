#include "Global.h"
#include "Resources.h"
#include <chrono>

Global *Global::instance = new Global();

CApp* Global::__cApp = nullptr;

bool *Global::showBeaconPath = nullptr;
unsigned int Global::currentSeed = 0;
std::mt19937 Global::seededRng;
bool *Global::showWelcome = nullptr;
bool *Global::dlcEnabled = nullptr;
int *Global::difficulty = nullptr;
bool Global::forceDlc = false;
bool Global::isCustomSeed = false;
unsigned int Global::sectorMapSeed = -1;
FILE *Global::logFile = nullptr;
bool *Global::firstTimeShips = nullptr;
Point *Global::dronePosition = nullptr;
Point *Global::weaponPosition = nullptr;
GL_Color *Global::superShieldColor = nullptr;
GL_Color Global::defaultSuperShieldColor = GL_Color(255.0, 255.0, 255.0, 1.0);

unsigned int Global::questSeed = 0;
std::vector<unsigned int> Global::delayedQuestSeeds = std::vector<unsigned int>();
int Global::delayedQuestIndex = 0;
std::vector<unsigned int> Global::lastDelayedQuestSeeds = std::vector<unsigned int>();

std::vector<std::vector<GL_Color*>> Global::colorPointers = std::vector<std::vector<GL_Color*>>();

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
    __baseAddress = (uintptr_t)GetBaseAddress();


    seededRng = std::mt19937(std::chrono::system_clock::now().time_since_epoch().count());
    currentSeed = 0;

    showWelcome = &Global_Settings_Settings->bShowChangelog;
    showBeaconPath = &Global_Settings_Settings->showPaths;
    dlcEnabled = &Global_Settings_Settings->bDlcEnabled;
    difficulty = &Global_Settings_Settings->difficulty;
    firstTimeShips = (bool*) (void*) &Global_Settings_Settings->openedList; // Note this address is an int, not a bool
    *firstTimeShips = false;
    dronePosition = Global_SystemControl_drone_position;
    weaponPosition = Global_SystemControl_weapon_position;
    superShieldColor = &Global_COLOR_GREEN;
    defaultSuperShieldColor = *superShieldColor;
    *superShieldColor = GL_Color(1084.0, 0.0, 310.0, 1.0);
    
    {
        std::vector<GL_Color*> colorVec = std::vector<GL_Color*>();
        colorVec.push_back(&Global_InfoBox_detailsBarOn);
        colorPointers.push_back(colorVec);
    }
    {
        std::vector<GL_Color*> colorVec = std::vector<GL_Color*>();
        colorVec.push_back(&Global_InfoBox_detailsBarOff);
        colorPointers.push_back(colorVec);
    }

    logFile = fopen("FTL_HS.log", "w");


#ifdef _WIN32
    // TODO: Find out how to set the Window text on Linux
    SetWindowTextA((HWND)GetModuleHandle(NULL), "FTL: Hyperspace");
#endif
    printf("Hyperspace initialized\n");
}

HOOK_METHOD(WorldManager, LoadGame, (const std::string file) -> void)
{
    loadingGame = true;
    super(file);
    loadingGame = false;
}
