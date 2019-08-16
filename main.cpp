#include "main.h"
#include <stdio.h>
#include <Windows.h>
#include "FTLGame.h"
#include "Global.h"

extern "C" BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {

        case DLL_PROCESS_ATTACH:
            {
            // attach to process
            // return FALSE to fail DLL load
#ifdef DEBUG
            AllocConsole();
            freopen("conin$", "r", stdin);
            freopen("conout$", "w", stdout);
            freopen("conout$", "w", stderr);
            printf("Hyperspace.dll is loaded\n");
#endif

            G_->Initialize();
            ZHL::SetLogPath("zhl.log");
            ZHL::Init();




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
