// Entry point for the Android port of FTL for iPad (see HyperspaceHost.h). On PC,
// Hyperspace starts from a library constructor; here the port calls hs_android_init
// once the game is mapped, so it can pass where the game is.

#include "android/HyperspaceHost.h"
#include "Global.h"
#include "SigScan.h"
#include "Arm64Detour.h"
#include "zhl_internal.h"
#include "zhl_private.h"

#include <android/log.h>
#include <dlfcn.h>
#include <elf.h>
#include <link.h>
#include <sys/system_properties.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <unistd.h>

static hs_host_info g_host;
static std::string g_logDir;
static std::string g_zhlLogPath;
static std::string g_lastError;

static void HostLog(int level, const char *fmt, ...)
{
    char msg[1024];
    va_list va;
    va_start(va, fmt);
    vsnprintf(msg, sizeof(msg), fmt, va);
    va_end(va);
    if (g_host.log)
        g_host.log(level, msg);
    else
        __android_log_write(level >= 2 ? ANDROID_LOG_ERROR : level == 1 ? ANDROID_LOG_WARN : ANDROID_LOG_INFO, "Hyperspace", msg);
}

void PAL_AndroidShowError(const char *title, const char *message)
{
    HostLog(2, "Hyperspace: %s: %s", title, message);
    g_lastError = std::string(title) + ": " + message;
}

std::string HS_LogPath(const char *name)
{
    if (g_logDir.empty()) return name;
    return g_logDir + "/" + name;
}

// Who called: Hyperspace functions by name, game code by its address in the binary
static void LogCallers()
{
    uintptr_t *fp = (uintptr_t *)__builtin_frame_address(0);
    uintptr_t game = (uintptr_t)g_host.mach_header;
    for (int i = 0; i < 16 && fp; i++)
    {
        uintptr_t ret = fp[1];
        if (!ret) break;
        Dl_info di = {};
        if (game && ret >= game && ret < game + g_host.image_size)
            HostLog(2, "  from FTL %#lx", (unsigned long)(ret - g_host.slide));
        else if (!dladdr((void *)ret, &di) || !di.dli_fname)
            HostLog(2, "  from %#lx", (unsigned long)ret);
        else if (di.dli_sname)
            HostLog(2, "  from %s+%#lx", di.dli_sname, (unsigned long)(ret - (uintptr_t)di.dli_saddr));
        else
            HostLog(2, "  from %s+%#lx", strrchr(di.dli_fname, '/') ? strrchr(di.dli_fname, '/') + 1 : di.dli_fname,
                    (unsigned long)(ret - (uintptr_t)di.dli_fbase));
        uintptr_t *next = (uintptr_t *)fp[0];
        if (next <= fp) break;
        fp = next;
    }
}

// Stands in for game functions the definitions don't have an address for yet ("@0"):
// says which one was called, and from where, then stops the game.
static void MissingFunctionCalled(const char *name)
{
    HostLog(2, "Hyperspace: called %s, which isn't found in the iPad game yet", name);
    ZHL::Log("Called %s, which isn't found in the iPad game yet\n", name);
    LogCallers();
    abort();
}

static void *MakeMissingStub(const char *name)
{
    return Arm64Detour::MakeTrap(name, MissingFunctionCalled);
}

// The port's libunwind build looks up the game's unwind info through this, so
// exceptions and backtraces can pass through game frames.
extern "C" int __ftl_find_macho_unwind(uintptr_t pc, uintptr_t *mh, uintptr_t *textLen, uintptr_t *cu, size_t *cuLen,
                                       uintptr_t *eh, size_t *ehLen)
{
    if (!g_host.find_macho_unwind) return 0;
    return g_host.find_macho_unwind(pc, mh, textLen, cu, cuLen, eh, ehLen);
}

// On x86 devices and emulators that run ARM apps through a translator (a native bridge),
// rewrite the few instructions in our own code it can't run. ARM devices skip this.
// Only .text is scanned (found from the library file's section headers): the executable
// segment also holds read-only data, which must not be touched.
static bool OwnTextSection(uintptr_t *start, size_t *size)
{
    Dl_info self;
    if (!dladdr((void *)&OwnTextSection, &self) || !self.dli_fname) return false;
    FILE *f = fopen(self.dli_fname, "rb");
    if (!f) return false;
    bool found = false;
    ElfW(Ehdr) eh;
    std::vector<ElfW(Shdr)> sh;
    std::vector<char> names;
    if (fread(&eh, sizeof(eh), 1, f) == 1 && eh.e_shentsize == sizeof(ElfW(Shdr)) && eh.e_shstrndx < eh.e_shnum)
    {
        sh.resize(eh.e_shnum);
        if (fseek(f, (long)eh.e_shoff, SEEK_SET) == 0 && fread(sh.data(), sizeof(ElfW(Shdr)), sh.size(), f) == sh.size())
        {
            const ElfW(Shdr) &strs = sh[eh.e_shstrndx];
            names.resize(strs.sh_size + 1);
            if (fseek(f, (long)strs.sh_offset, SEEK_SET) == 0 && fread(names.data(), 1, strs.sh_size, f) == strs.sh_size)
            {
                for (const ElfW(Shdr) &s : sh)
                {
                    if (s.sh_name < strs.sh_size && strcmp(&names[s.sh_name], ".text") == 0)
                    {
                        *start = (uintptr_t)self.dli_fbase + s.sh_addr;
                        *size = s.sh_size;
                        found = true;
                    }
                }
            }
        }
    }
    fclose(f);
    return found;
}

static void AdjustForTranslator()
{
    char bridge[PROP_VALUE_MAX] = "";
    __system_property_get("ro.dalvik.vm.native.bridge", bridge);
    if (!bridge[0] || strcmp(bridge, "0") == 0) return;
    uintptr_t text;
    size_t size;
    char error[128] = "";
    int n = OwnTextSection(&text, &size) ? Arm64Detour::ReplaceUntranslatable((void *)text, size, error, sizeof(error)) : -1;
    if (n < 0)
        HostLog(1, "Hyperspace: running through %s, but can't adjust its code for it: %s", bridge,
                error[0] ? error : "no .text section found");
    else
        HostLog(0, "Hyperspace: running through %s; adjusted %d instructions it can't run", bridge, n);
}

extern "C" __attribute__((visibility("default"))) int hs_android_init(const hs_host_info *info, char *error, size_t errorSize)
{
    if (!info || info->version != HS_HOST_VERSION || info->size < sizeof(hs_host_info))
    {
        snprintf(error, errorSize, "This Hyperspace build doesn't match the app (interface %u, expected %u).",
                 info ? info->version : 0u, (unsigned)HS_HOST_VERSION);
        return 1;
    }
    g_host = *info;
    g_logDir = info->log_dir ? info->log_dir : "";

    // Files Hyperspace keeps in the game folder on PC (settings_hs.ini)
    if (info->data_dir && chdir(info->data_dir) != 0)
        HostLog(1, "Hyperspace: can't use %s as the working directory", info->data_dir);

    std::rename(HS_LogPath("zhl.log").c_str(), HS_LogPath("zhl.log.bak").c_str());
    std::rename(HS_LogPath("FTL_HS.log").c_str(), HS_LogPath("FTL_HS.log.bak").c_str());
    g_zhlLogPath = HS_LogPath("zhl.log");
    ZHL::SetLogPath(g_zhlLogPath.c_str());

    SigScan::SetGameImage(info->mach_header, info->slide);
    if (!SigScan::IsKnownGame())
    {
        snprintf(error, errorSize, "This copy of FTL for iPad isn't the 1.6.21 build Hyperspace is made for.");
        HostLog(2, "Hyperspace: %s", error);
        return 1;
    }
    AdjustForTranslator();
    Arm64Detour::SetGameRange((uintptr_t)info->mach_header, info->image_size);
    ZHL::SetMissingFunctionStub(MakeMissingStub);

    if (!ZHL::Init())
    {
        snprintf(error, errorSize, "%s", g_lastError.empty() ? "Hyperspace failed to start (see zhl.log)." : g_lastError.c_str());
        return 1;
    }
    size_t poolSize = 0, poolUsed = Arm64Detour::PoolUsed(&poolSize);
    HostLog(0, "Hyperspace: hooks installed (%zuK of %zuK for trampolines)", poolUsed >> 10, poolSize >> 10);

    G_->Initialize();
    HostLog(0, "Hyperspace: initialized");
    return 0;
}
