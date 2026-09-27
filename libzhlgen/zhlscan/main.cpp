// zhlscan: resolve ZHL signatures against a game binary on disk.
//
// Reads the binary's code section (LIEF), loads a libftlgame-<platform>
// definitions module (one platform's generated FTLGame*.cpp linked with the
// game's own definition loading) and runs it over the section, writing the
// same zhl.log the game writes. Addresses in the log are host pointers into
// the loaded buffer; compare_zhl_nm.py derives the slide.
//
// Usage: zhlscan <libftlgame-PLATFORM.so> <game binary> <zhl.log>

#include "CodeSection.h"
#include "DefinitionsModule.h"

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <dlfcn.h>
#endif

namespace {

constexpr int EXIT_USAGE = 2;
constexpr int ARGUMENT_COUNT = 4;
constexpr size_t ERROR_SIZE = 1024;

zhlscan_run_t LoadModule(const char* path, std::string& error)
{
#ifdef _WIN32
    HMODULE module = LoadLibraryA(path);
    if (!module)
    {
        error = "cannot load module";
        return nullptr;
    }
    zhlscan_run_t run = reinterpret_cast<zhlscan_run_t>(GetProcAddress(module, ZHLSCAN_RUN_SYMBOL));
#else
    void* module = dlopen(path, RTLD_NOW | RTLD_LOCAL);
    if (!module)
    {
        error = dlerror();
        return nullptr;
    }
    zhlscan_run_t run = reinterpret_cast<zhlscan_run_t>(dlsym(module, ZHLSCAN_RUN_SYMBOL));
#endif
    if (!run)
    {
        error = "module does not export " ZHLSCAN_RUN_SYMBOL;
    }
    return run;
}

} // namespace

int main(int argc, char** argv)
{
    if (argc != ARGUMENT_COUNT)
    {
        fprintf(stderr, "Usage: %s <libftlgame-PLATFORM.so> <game binary> <zhl.log>\n", argv[0]);
        return EXIT_USAGE;
    }
    const char* modulePath = argv[1];
    const char* binaryPath = argv[2];
    const char* logPath = argv[3];

    std::string error;
    zhlscan_run_t run = LoadModule(modulePath, error);
    if (!run)
    {
        fprintf(stderr, "%s: %s\n", modulePath, error.c_str());
        return EXIT_FAILURE;
    }

    std::vector<unsigned char> code;
    if (!ReadCodeSection(binaryPath, code, error))
    {
        fprintf(stderr, "%s: %s\n", binaryPath, error.c_str());
        return EXIT_FAILURE;
    }

    char runError[ERROR_SIZE];
    if (!run(code.data(), code.size(), logPath, runError, sizeof(runError)))
    {
        fprintf(stderr, "%s\n", runError);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
