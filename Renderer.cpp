#include "Global.h"

#ifdef _WIN32

#ifndef GL_VENDOR
#define GL_VENDOR 0x1F00
#endif

typedef char* (*glGetString_ptr)(uint32_t glenum);

HOOK_METHOD(CApp, SetupWindow, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::SetupWindow -> Begin (Renderer.cpp)\n")
    std::string argv = std::string(GetCommandLine());

    // TODO: Should we detect legacy `-opengl` command and tell people it's meaningless now or just ignore silently?
    if (argv.find("--force-d3d") != std::string::npos)
    {
        hs_log_file("GPU Renderer: Direct3D Mode (Forced)\n");
        // TODO: Log to HS/FTL Log that Direct3D was forced
        useDirect3D = true;
    }
    else if (argv.find("--force-opengl") != std::string::npos)
    {
        hs_log_file("GPU Renderer: OpenGL Mode (Forced)\n");
        // TODO: Log to HS/FTL Log that OpenGL was forced
        useDirect3D = false;
    }
    else
    {
        // TODO: Log to HS/FTL Log that autodetect was used and what the output of autodetect was
        // GPU Autodetect & choose OpenGL/Direct3D automatically based on GPU vendor
        HMODULE opengl32dll = GetModuleHandleA("opengl32.dll");
        glGetString_ptr glGetString = reinterpret_cast<glGetString_ptr>(GetProcAddress(opengl32dll, "glGetString"));
        char *gpuVendor = glGetString(GL_VENDOR);
        hs_log_file("GPU Renderer: (AutoSelect) (Vendor: %s)\n", gpuVendor);

        // TODO: Check values from GPU Renderer, see if `Nvidia` reports `Nvidia`
    }

    super();
}
#endif
