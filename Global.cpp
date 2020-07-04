#include "Global.h"
#include "Resources.h"
#include <chrono>

Global *Global::instance = new Global();

ResourceControl* Global::__resourceControl = NULL;
CApp* Global::__cApp = NULL;
ShipInfo** Global::__enemyShipInfo = NULL;
CFPS* Global::__cFPS = NULL;
BlueprintManager *Global::__blueprints = NULL;
SoundControl *Global::__soundControl = NULL;
MouseControl *Global::__mouseControl = NULL;
TextLibrary *Global::__textLibrary = NULL;
CrewMemberFactory *Global::__crewFactory = NULL;
TutorialManager *Global::__tutorialManager = NULL;
EventGenerator *Global::__eventGenerator = NULL;
EventsParser *Global::__eventsParser = NULL;
EventSystem *Global::__eventSystem = NULL;
AnimationControl *Global::__animations = NULL;

bool *Global::showBeaconPath = NULL;
unsigned int Global::currentSeed = 0;
int64_t *Global::randomState = NULL;
std::mt19937 Global::seededRng;
bool *Global::__rng = NULL;
bool *Global::showWelcome = NULL;
bool *Global::dlcEnabled = NULL;
int *Global::difficulty = NULL;
bool Global::forceDlc = false;
bool Global::isCustomSeed = false;
unsigned int Global::sectorMapSeed = -1;


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
    seededRng = std::mt19937(std::chrono::system_clock::now().time_since_epoch().count());
    currentSeed = 0;

    showWelcome = (bool*)((__baseAddress + __showWelcomeOffset));
    showBeaconPath = (bool*)((__baseAddress + __beaconPathOffset));
    dlcEnabled = (bool*)((__baseAddress + __dlcEnabledOffset));
    __rng = (bool*)((__baseAddress + __rngOffset));
    difficulty = (int*)((__baseAddress + __difficultyOffset));



    SetWindowTextA((HWND)GetModuleHandle(NULL), "FTL: Hyperspace");
    printf("Hyperspace initialized\n");
}
