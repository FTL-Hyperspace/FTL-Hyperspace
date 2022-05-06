#include "Global.h"
#include "Resources.h"
#include <chrono>

#if defined(__linux__)
#include <SDL2/SDL_messagebox.h>
#endif // defined

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

int Global::questSeed = 0;

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

void ftl_log(const char *str...)
{
    va_list va;
    va_start(va, str);

    if (ftl_log_logfile != nullptr) // todo: open file if it's nullptr
    {
        vfprintf(ftl_log_logfile, str, va);
        fflush(ftl_log_logfile);
    }
    va_end(va);
}

void ErrorMessage(const std::string &msg)
{
    ErrorMessage(msg.c_str());
}

void ErrorMessage(const char *msg)
{
    #ifdef _WIN32
        MessageBoxA(NULL, msg, "Error", MB_ICONERROR);
    #elif defined(__linux__)
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", msg, NULL);
        fprintf(stderr, msg);
    #endif
}


HOOK_METHOD(CApp, OnInit, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnInit -> Begin (Global.cpp)\n")
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

    {
        std::vector<GL_Color*> colorVec = std::vector<GL_Color*>();
        colorVec.push_back(Global_InfoBox_detailsBarOn);
        colorPointers.push_back(colorVec);
    }
    {
        std::vector<GL_Color*> colorVec = std::vector<GL_Color*>();
        colorVec.push_back(Global_InfoBox_detailsBarOff);
        colorPointers.push_back(colorVec);
    }

    logFile = fopen("FTL_HS.log", "w");
    
    printf("Starting Lua\n");
    m_luaScript = new LuaScriptInit();
    printf("Lua Inited\n");


#ifdef _WIN32
    // TODO: Find out how to set the Window text on Linux
    SetWindowTextA((HWND)GetModuleHandle(NULL), "FTL: Hyperspace");
#endif
    printf("Hyperspace initialized\n");
}

HOOK_METHOD(WorldManager, LoadGame, (const std::string file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::LoadGame -> Begin (Global.cpp)\n")
    loadingGame = true;
    super(file);
    loadingGame = false;
}
