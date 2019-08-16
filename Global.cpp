#include "Global.h"
#include "Resources.h"

Global *Global::instance = new Global();

ResourceControl* Global::__resourceControl = NULL;
CApp** Global::__cApp = NULL;
ShipInfo** Global::__enemyShipInfo = NULL;
CFPS* Global::__cFPS = NULL;
BlueprintManager *Global::__blueprints = NULL;
SoundControl *Global::__soundControl = NULL;

void Global::Initialize()
{
    printf("Initializing Hyperspace...\n");
    __baseAddress = (DWORD)GetModuleHandle(NULL);


    __resourceControl = (ResourceControl*)(__baseAddress + __resourcesOffset);
    __cApp = (CApp**)(__baseAddress + __cAppOffset);
    __cFPS = (CFPS*)(__baseAddress + __cFPSOffset);
    __enemyShipInfo = (ShipInfo**)(__baseAddress + __shipInfoOffset);
    __blueprints = (BlueprintManager*)(__baseAddress + __blueprintOffset);
    __soundControl = (SoundControl*)(__baseAddress + __soundOffset);
}
