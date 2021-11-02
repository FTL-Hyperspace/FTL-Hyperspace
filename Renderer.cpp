#include "Global.h"

#ifdef _WIN32
HOOK_METHOD(CApp, SetupWindow, () -> void)
{
    std::string argv = std::string(GetCommandLine());

    if (argv.find("-opengl") == std::string::npos)
    {
        useDirect3D = true;
    }

    super();
}
#endif
