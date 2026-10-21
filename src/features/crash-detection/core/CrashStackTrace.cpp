#include "CrashStackTrace.h"
#include "HSVersion.h"
#include "features/system-info/SystemInfo.h"

#include <csignal>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fcntl.h>

#ifdef _WIN32
    #include <windows.h>
    #include <io.h>
#else
    #include <dlfcn.h>
    #include <execinfo.h>
    #include <unistd.h>
    #ifndef __APPLE__
        #include <ucontext.h>
    #endif
#endif

namespace
{
#ifdef _WIN32
    const int crashSignals[] = { SIGABRT };
    const int openFlags = O_WRONLY | O_CREAT | O_TRUNC | O_BINARY;
#else
    const int crashSignals[] = { SIGSEGV, SIGABRT, SIGBUS, SIGILL, SIGFPE, SIGTRAP };
    const int openFlags = O_WRONLY | O_CREAT | O_TRUNC;
#endif
    const int signalCount = sizeof(crashSignals) / sizeof(crashSignals[0]);

    // Filled at install, the crash handler must not allocate
    char header[1024];
    int crashFile = -1;

    void Write(const char* format, ...)
    {
        char line[512];
        va_list args;
        va_start(args, format);
        int length = vsnprintf(line, sizeof(line), format, args);
        va_end(args);
        if (length > 0) write(crashFile, line, length < (int)sizeof(line) ? length : sizeof(line) - 1);
    }

    const char* BaseName(const char* path)
    {
        const char* name = path;
        for (const char* c = path; *c; ++c)
        {
            if (*c == '/' || *c == '\\') name = c + 1;
        }
        return name;
    }

    void WriteFrame(const char* label, void* address)
    {
#ifdef _WIN32
        HMODULE module = nullptr;
        char path[MAX_PATH];
        if (GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCSTR)address, &module)
            && GetModuleFileNameA(module, path, MAX_PATH))
        {
            Write("%s %s + 0x%lx\n", label, BaseName(path), (unsigned long)((char*)address - (char*)module));
            return;
        }
#else
        Dl_info info;
        if (dladdr(address, &info) && info.dli_fname)
        {
            Write("%s %s + 0x%lx\n", label, BaseName(info.dli_fname), (unsigned long)((char*)address - (char*)info.dli_fbase));
            return;
        }
#endif
        Write("%s %p\n", label, address);
    }

    void* ModuleOf(void* address)
    {
#ifdef _WIN32
        HMODULE module = nullptr;
        GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCSTR)address, &module);
        return module;
#else
        Dl_info info;
        return dladdr(address, &info) ? info.dli_fbase : nullptr;
#endif
    }

    void WriteStack()
    {
        void* frames[64];
#ifdef _WIN32
        int count = CaptureStackBackTrace(0, 64, frames, nullptr);
#else
        int count = backtrace(frames, 64);
#endif

        // Skip the crash handler itself, then the signal trampoline and its empty frame
        void* ownModule = ModuleOf((void*)&WriteStack);
        int first = 0;
        while (first < count && ModuleOf(frames[first]) == ownModule) ++first;
#ifndef _WIN32
        ++first;
        while (first < count && frames[first] == nullptr) ++first;
#endif

        for (int i = first; i < count; ++i)
        {
            char label[8];
            snprintf(label, sizeof(label), "#%02d", i - first);
            WriteFrame(label, frames[i]);
        }
    }

    void WriteHeader(const char* crash)
    {
        char now[32] = "unknown time";
        time_t seconds = time(nullptr);
        struct tm utc;
#ifdef _WIN32
        if (gmtime_s(&utc, &seconds) == 0)
#else
        if (gmtime_r(&seconds, &utc))
#endif
            strftime(now, sizeof(now), "%Y-%m-%d %H:%M:%S UTC", &utc);

        Write("%s%s at %s\n\n", header, crash, now);
    }

    void WriteSignal(int sig, void* crashAddress)
    {
        crashFile = open("FTL_HS_crash.log", openFlags, 0644);
        if (crashFile < 0) return;

        char crash[32];
        snprintf(crash, sizeof(crash), "Signal %d", sig);
        WriteHeader(crash);
        if (crashAddress) WriteFrame("Crashed at", crashAddress);
        WriteStack();
        close(crashFile);
    }

#ifdef _WIN32
    void (*previousHandlers[signalCount])(int);

    void OnCrashSignal(int sig)
    {
        WriteSignal(sig, nullptr);

        // Pass the crash on, so FTL and the OS still handle it
        for (int i = 0; i < signalCount; ++i)
        {
            if (crashSignals[i] == sig) signal(sig, previousHandlers[i]);
        }
        raise(sig);
    }
#else
    struct sigaction previousActions[signalCount];

    void* CrashAddress(void* context)
    {
    #ifdef __APPLE__
        return (void*)((ucontext_t*)context)->uc_mcontext->__ss.__rip;
    #else
        return (void*)((ucontext_t*)context)->uc_mcontext.gregs[REG_RIP];
    #endif
    }

    void OnCrashSignal(int sig, siginfo_t*, void* context)
    {
        // backtrace() loses the crashing function at the signal frame, the context still has it
        WriteSignal(sig, CrashAddress(context));

        // Pass the crash on, so FTL and the OS still handle it
        for (int i = 0; i < signalCount; ++i)
        {
            if (crashSignals[i] == sig) sigaction(sig, &previousActions[i], nullptr);
        }
        raise(sig);
    }
#endif
}

void CrashStackTrace::Install()
{
    snprintf(header, sizeof(header), "Hyperspace: v%s Compiled: %s %s\n%s",
             HS_Version.toIdentifierString().c_str(), __DATE__, __TIME__, SystemInfo::Describe().c_str());

#ifdef _WIN32
    for (int i = 0; i < signalCount; ++i)
    {
        previousHandlers[i] = signal(crashSignals[i], OnCrashSignal);
    }
#else
    // The first backtrace loads libgcc, which is not safe inside a signal handler
    void* warmup;
    backtrace(&warmup, 1);

    struct sigaction action = {};
    action.sa_sigaction = OnCrashSignal;
    action.sa_flags = SA_SIGINFO;
    sigemptyset(&action.sa_mask);
    for (int i = 0; i < signalCount; ++i)
    {
        sigaction(crashSignals[i], &action, &previousActions[i]);
    }
#endif
}

void CrashStackTrace::WriteException(void* exceptionPointers)
{
#ifdef _WIN32
    EXCEPTION_RECORD* record = ((EXCEPTION_POINTERS*)exceptionPointers)->ExceptionRecord;

    crashFile = open("FTL_HS_crash.log", openFlags, 0644);
    if (crashFile < 0) return;

    char crash[32];
    snprintf(crash, sizeof(crash), "Exception 0x%08lx", record->ExceptionCode);
    WriteHeader(crash);
    WriteFrame("Crashed at", record->ExceptionAddress);
    WriteStack();
    close(crashFile);
#endif
}
