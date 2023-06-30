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
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
/* #include <GL/glew.h> */

bool checkIfUnderWINE();
/* void renderHyperspaceTestDisplay(); */
/* void renderCloseTimer(int window); */

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
        hs_log_file("Opening SFML to determine GPU\n");
        sf::RenderWindow window(sf::VideoMode(800, 600, "Hyperspace GPU Checking Window");
        window.setFramerateLimit(60);

        // Initialize GLEW
        glewExperimental = GL_TRUE;
        glewInit();

        // Get the GPU vendor name and use it to determine if we should use D3D or not
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

        // Run the main loop
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }

            // Clear the window
            window.clear();

            // Draw text on the window
            sf::Font font;
            if (font.loadFromFile("arial.ttf")) // Replace with your desired font file
            {
                sf::Text text("Hello World", font, 24);
                text.setPosition(10.f, 10.f);
                window.draw(text);
            }

            // Display the window contents
            window.display();
        }
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
