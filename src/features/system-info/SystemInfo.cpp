#include "SystemInfo.h"
#include "Global.h"
#include "HSVersion.h"

#include <fstream>
#include <string>

#ifdef _WIN32
    #include <windows.h>
    #include <GL/gl.h>
#elif __APPLE__
    #include <sys/sysctl.h>
    #include <OpenGL/gl.h>
#else
    #include <sys/utsname.h>
    #include <GL/gl.h>
#endif

namespace SystemInfo
{

static std::string FtlVersion()
{
#ifdef _WIN32
    return "1.6.9";
#elif defined(STEAM_1_6_13_BUILD)
    return "1.6.13 (Steam)";
#else
    return "1.6.12";
#endif
}

#ifdef _WIN32

static std::string OperatingSystem()
{
    // GetVersionEx reports Windows 8 to programs without a manifest, RtlGetVersion does not
    typedef LONG (WINAPI *RtlGetVersionFn)(OSVERSIONINFOW*);
    HMODULE ntdll = GetModuleHandleA("ntdll.dll");
    auto rtlGetVersion = (RtlGetVersionFn)GetProcAddress(ntdll, "RtlGetVersion");

    OSVERSIONINFOW info = {};
    info.dwOSVersionInfoSize = sizeof(info);
    std::string os = "Windows";
    if (rtlGetVersion && rtlGetVersion(&info) == 0)
    {
        os += " " + std::to_string(info.dwMajorVersion) + "." + std::to_string(info.dwMinorVersion) + " build " + std::to_string(info.dwBuildNumber);
    }

    typedef const char* (*WineGetVersionFn)();
    auto wineGetVersion = (WineGetVersionFn)GetProcAddress(ntdll, "wine_get_version");
    if (wineGetVersion) os += std::string(" under Wine ") + wineGetVersion();

    return os;
}

#elif __APPLE__

static std::string Sysctl(const char* name)
{
    char value[256] = {};
    size_t size = sizeof(value);
    if (sysctlbyname(name, value, &size, nullptr, 0) != 0) return "unknown";
    return value;
}

static std::string OperatingSystem()
{
    std::string os = "macOS " + Sysctl("kern.osproductversion") + " (" + Sysctl("kern.osversion") + "), " + Sysctl("hw.model");

    int translated = 0;
    size_t size = sizeof(translated);
    if (sysctlbyname("sysctl.proc_translated", &translated, &size, nullptr, 0) == 0 && translated == 1)
        os += ", Rosetta";

    return os;
}

#else

static std::string OperatingSystem()
{
    std::string os = "Linux";

    std::ifstream release("/etc/os-release");
    for (std::string line; std::getline(release, line);)
    {
        if (line.compare(0, 12, "PRETTY_NAME=") == 0)
        {
            os = line.substr(12);
            if (os.size() >= 2 && os.front() == '"') os = os.substr(1, os.size() - 2);
        }
    }

    utsname name;
    if (uname(&name) == 0) os += std::string(", kernel ") + name.release + " " + name.machine;

    return os;
}

#endif

static std::string Renderer()
{
    // Empty without an OpenGL context, e.g. FTL running on Direct3D
    const char* renderer = (const char*)glGetString(GL_RENDERER);
    const char* version = (const char*)glGetString(GL_VERSION);
    if (!renderer || !version) return "not OpenGL";
    return std::string(renderer) + ", OpenGL " + version;
}

static std::string BuildType()
{
#ifdef DEBUG
    return "Debug";
#else
    return "Release";
#endif
}

std::string Describe()
{
    return "Build: " + BuildType() + "\n"
        + "Branch: " + (branchName.empty() ? std::string("unknown") : branchName) + "\n"
        + "FTL: " + FtlVersion() + "\n"
        + "System: " + OperatingSystem() + "\n"
        + "Renderer: " + Renderer() + "\n";
}

void Log()
{
    hs_log_file("%s", Describe().c_str());
}

}
