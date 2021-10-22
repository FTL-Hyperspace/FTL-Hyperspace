#include "main.h"
#include <stdio.h>
#include "FTLGame.h"
#include "Global.h"

extern "C" BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {

        case DLL_PROCESS_ATTACH:
            {
#ifdef DEBUG
            AllocConsole();
            freopen("conin$", "r", stdin);
            freopen("conout$", "w", stdout);
            freopen("conout$", "w", stderr);
            printf("Hyperspace.dll is loaded\n");
#endif



            ZHL::SetLogPath("zhl.log");
            ZHL::Init();

            G_->Initialize();




            break;
            }
        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }

    return TRUE; // succesful
}
