#include "Global.h"

#ifdef _WIN32
HOOK_METHOD(CApp, SetupWindow, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::SetupWindow -> Begin (Renderer.cpp)\n")
    std::string argv = std::string(GetCommandLine());

    if (argv.find("-opengl") == std::string::npos)
    {
        useDirect3D = true;
    }

    super();
}
#endif
