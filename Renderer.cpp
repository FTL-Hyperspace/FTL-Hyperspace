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

#include <shlwapi.h>
#include <GL/gl.h>

bool checkIfUnderWINE();

HOOK_METHOD(CApp, SetupWindow, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::SetupWindow -> Begin (Renderer.cpp)\n")
    std::string argv = std::string(GetCommandLine());

    bool isUnderWINE = checkIfUnderWINE();

    if (argv.find("-opengl") != std::string::npos)
    {
        hs_log_file("Warning command line argument `-opengl` is no longer supported!\nIf you are encountering issues with the auto-detection please report it to the Hyperspace team on Discord or on Github.\n");
        ErrorMessage("Startup argument `-opengl` is no longer supported! (We now auto-detect your GPU configuration)\nPlease remove `-opengl` or I'll just keep complaining\n\nIf this is your first install of Hyperspace don't try random things and see the install guide at https://ftl-hyperspace.github.io/FTL-Hyperspace/\n");
    }

    if (argv.find("--force-d3d") != std::string::npos)
    {
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
        // Window dimensions
        const int WIDTH = 800;
        const int HEIGHT = 600;

        // Create a window on Windows
        HWND hwnd;
        HDC hdc;
        HGLRC hglrc;

        // Create the window
        WNDCLASSW wc = { 0 };
        wc.lpfnWndProc = DefWindowProc;
        wc.hInstance = GetModuleHandle(NULL);
        wc.lpszClassName = L"OpenGLWindow";
        RegisterClassW(&wc);

        // Create an invisible window because we left out `WS_VISIBLE` flag
        hwnd = CreateWindowW(wc.lpszClassName, L"FTL: Hyperspace - Graphics Detection", WS_OVERLAPPEDWINDOW, 0, 0, WIDTH, HEIGHT, NULL, NULL, wc.hInstance, NULL);

        // Get the device context
        hdc = GetDC(hwnd);

        // Set the pixel format
        PIXELFORMATDESCRIPTOR pfd = { 0 };
        pfd.nSize = sizeof(pfd);
        pfd.nVersion = 1;
        pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 24;
        pfd.cDepthBits = 16;
        pfd.iLayerType = PFD_MAIN_PLANE;

        int pixelFormat = ChoosePixelFormat(hdc, &pfd);
        SetPixelFormat(hdc, pixelFormat, &pfd);

        hs_log_file("Create OpenGL context for Hyperspace graphics auto-detection\n");
        // Create the OpenGL context
        hglrc = wglCreateContext(hdc);
        wglMakeCurrent(hdc, hglrc);

        /* // Set up OpenGL */
        /* glClearColor(0.2f, 0.3f, 0.4f, 1.0f); */
        /* glViewport(0, 0, WIDTH, HEIGHT); */

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

        // Clean up on Windows
        wglMakeCurrent(NULL, NULL);
        wglDeleteContext(hglrc);
        ReleaseDC(hwnd, hdc);
        DestroyWindow(hwnd);
    }

    super();
}

bool checkIfUnderWINE()
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
