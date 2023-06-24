#include "Global.h"

#ifdef _WIN32

/* # This should cause Nvidia Optimus & AMD PowerXpress to choose the dedicated GPU instead of the internal GPU on laptops */
/* #ifdef __cplusplus */
/* extern "C" { */
/* #endif */

/*     __declspec(dllexport) DWORD NvOptimusEnablement = 1; */
/*     __declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1; */

/* #ifdef __cplusplus */
/* } */
/* #endif */

#include <GL/glut.h>
#include <shlwapi.h>

bool checkIfUnderWINE(void);
void renderHyperspaceTestDisplay();

HOOK_METHOD(CApp, SetupWindow, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::SetupWindow -> Begin (Renderer.cpp)\n")
    std::string argv = std::string(GetCommandLine());

    bool isUnderWINE = checkIfUnderWINE();

    /* if (argv.find("--skip-gpu-check") == std::string::npos) */
    /* { */
    /*     // do GPU check */
    /* } */

    // TODO: Should we detect legacy `-opengl` command and tell people it's meaningless now or just ignore silently?
    if (argv.find("--force-d3d") != std::string::npos)
    {
        // TODO: Rework so that we check the GPU first (even on WINE) and always print out GPU info, then WINE info, and then finally decide to either follow it or use forced setting. Maybe add a `--skip-gpu-check` `--skip-wine-check` just in case it causes problems?
        hs_log_file("GPU Renderer: Direct3D Mode (Forced)\n");
        useDirect3D = true;
    }
    else if (argv.find("--force-opengl") != std::string::npos)
    {
        hs_log_file("GPU Renderer: OpenGL Mode (Forced)\n");
        useDirect3D = false;
    }
    else if (isUnderWINE)
    {
        hs_log_file("ATTENTION! Running under WINE/Proton, we default to OpenGL under WINE, you may need to force Direct3D usage with `--force-d3d` if you're trying to use DXVK or WINED3D for compatibility on your system depending on how you are attempting to run under WINE/Proton\n");
        useDirect3D = false;
        hs_log_file("GPU Renderer: OpenGL Mode (WINE/Proton)\n");
    }
    else
    {
        hs_log_file("Opening GLUT to determine GPU\n");
        glutInit(&__argc, __argv);
        /* glutInitWindowPosition(-1, -1); // Might be optional since -1, -1 is the defaults? */
        /* glutInitWindowSize(800, 600); // Might be optional? */
        glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
        int window = glutCreateWindow("OpenGL GPU Checking Window");
        glutDisplayFunc(renderHyperspaceTestDisplay);
        glutMainLoop();
        glutHideWindow();
        const char* gpuVendor = (const char*) glGetString(GL_VENDOR);
        const GLubyte* gpuRenderer = glGetString(GL_RENDERER);
        if (StrStrIA(gpuVendor, "nvidia") != NULL)
        {
            useDirect3D = true;
        }
        else
        {
            useDirect3D = false;
        }
        hs_log_file("GPU Renderer: %s (AutoSelect) (Vendor: %s, Renderer: %s)\n", useDirect3D ? "Direct3D" : "OpenGL", gpuVendor, gpuRenderer);
        glutDestroyWindow(window); // Doesn't seem to work, still figuring out how to close the window after it's opened
    }

    super();
}

void renderHyperspaceTestDisplay()
{
    glClearColor(1.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

bool checkIfUnderWINE(void)
{
    typedef void (CDECL *pwine_get_host_version_ptr)(const char **sysname, const char **release);
    typedef const char* (CDECL *pwine_get_version_ptr)(void);

    HMODULE hntdll = GetModuleHandle("ntdll.dll");
    if(!hntdll)
    {
        hs_log_file("Not running on NT, cannot detect WINE\n");
        return false;
    }

    pwine_get_version_ptr pwine_get_version = reinterpret_cast<pwine_get_version_ptr>(GetProcAddress(hntdll, "wine_get_version"));
    pwine_get_host_version_ptr pwine_get_host_version = reinterpret_cast<pwine_get_host_version_ptr>(GetProcAddress(hntdll, "wine_get_host_version"));

    if(pwine_get_version)
    {
        const char* sysname;
        const char* version;
        pwine_get_host_version(&sysname, &version);
        hs_log_file("Running on Wine/Proton version %s, on platform: '%s' '%s'\n", pwine_get_version(), sysname, version);

        return true;
    }
    else
    {
        hs_log_file("Running on Microsoft Windows (not WINE/Proton)\n");
        return false;
    }
}
#endif
