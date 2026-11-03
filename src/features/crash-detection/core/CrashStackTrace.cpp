#include "CrashStackTrace.h"
#include "HSVersion.h"
#include "features/system-info/SystemInfo.h"

#include <csignal>
#include <cstdarg>
#include <cstdint>
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

    // Most frames written by the normal trace
    const int MAX_STACK_FRAMES = 64;

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
        void* frames[MAX_STACK_FRAMES];
#ifdef _WIN32
        int count = CaptureStackBackTrace(0, MAX_STACK_FRAMES, frames, nullptr);
#else
        int count = backtrace(frames, MAX_STACK_FRAMES);
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

#ifdef _WIN32
    // Longest call instruction we look for before a return address
    const int MAX_CALL_LENGTH = 7;

    // Most frames written by the stack scan
    const int MAX_CUSTOM_STACK_FRAMES = 128;

    bool IsExecutable(DWORD protection)
    {
        return protection & (PAGE_EXECUTE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY);
    }

    // Real length of an FF call, from the byte after it (and the SIB byte when there is one)
    int IndirectCallLength(const unsigned char* instruction)
    {
        int mod = instruction[1] >> 6;
        int rm = instruction[1] & 7;

        // call register, e.g. call eax
        if (mod == 3) return 2;

        int length = 2;
        // SIB byte follows
        if (rm == 4) length += 1;
        // 1 byte offset
        if (mod == 1) length += 1;
        // 4 byte offset
        if (mod == 2) length += 4;
        // 4 byte address, e.g. call [address]
        if (mod == 0 && rm == 5) length += 4;
        // SIB with a 4 byte address instead of a base register
        if (mod == 0 && rm == 4 && (instruction[2] & 7) == 5) length += 4;
        return length;
    }

    // True for the address right after a call instruction
    bool IsCallAt(const unsigned char* instruction, int length)
    {
        // 0xE8 = call opcode, length 5 = opcode + 4 byte target
        if (length == 5 && instruction[0] == 0xE8) return true;

        // 0xFF + next byte's middle bits 010 (& 0x38 == 0x10) = call through a register or pointer, length 2 to 7
        return instruction[0] == 0xFF && (instruction[1] & 0x38) == 0x10 && IndirectCallLength(instruction) == length;
    }

    // True when this stack value is a return address
    bool IsReturnAddress(uintptr_t address)
    {
        
        MEMORY_BASIC_INFORMATION memory;
        // VirtualQuery fails means address the app can't access
        if (!VirtualQuery((void*)address, &memory, sizeof(memory))) return false;

        // not MEM_COMMIT is unused memory, not MEM_IMAGE is heap or stack
        if (memory.State != MEM_COMMIT || memory.Type != MEM_IMAGE) return false;

        // not code
        if (!IsExecutable(memory.Protect)) return false;

        // can't read the call before less than MAX_CALL_LENGTH bytes from the region start
        if (address - MAX_CALL_LENGTH < (uintptr_t)memory.BaseAddress) return false;

        const unsigned char* code = (const unsigned char*)address;
        for (int length = 2; length <= MAX_CALL_LENGTH; ++length)
        {
            if (IsCallAt(code - length, length)) return true;
        }

        // code, but no call before it = unrelated value
        return false;
    }

    // 32-bit FTL and msvcrt have no frame pointers which is why we need this besides WriteStack()
    // Reads the stack from here up to its start, and writes every value a call left there, as module + offset.
    void WriteCustomStackScan()
    {
        uintptr_t* top = (uintptr_t*)((NT_TIB*)NtCurrentTeb())->StackBase;
        uintptr_t marker = 0;
        int found = 0;

        Write("\nCustom stack scan:\n");
        for (uintptr_t* slot = &marker; slot < top && found < MAX_CUSTOM_STACK_FRAMES; ++slot)
        {
            if (!IsReturnAddress(*slot)) continue;
            char label[8];
            snprintf(label, sizeof(label), "#%02d", found++);
            WriteFrame(label, (void*)*slot);
        }
    }
#endif

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
#ifdef _WIN32
        WriteCustomStackScan();
#endif
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
    #elif defined(__i386__)
        return (void*)((ucontext_t*)context)->uc_mcontext.gregs[REG_EIP];
    #else
        return (void*)((ucontext_t*)context)->uc_mcontext.gregs[REG_RIP];
    #endif
    }

    void OnCrashSignal(int sig, siginfo_t*, void* context)
    {
        // backtrace() loses the crashing function at the signal frame, the context still has it
        WriteSignal(sig, CrashAddress(context));

    #ifdef __APPLE__
        // Not passed on to FTL's handler as on macOS it is empty which causes a segfault that loops forever.
        // The OS still handles the crash as usual.
        signal(sig, SIG_DFL);
    #elif defined(__linux__)
        // FTL's Linux handler writes its own crash.<date>.txt, then exits
        for (int i = 0; i < signalCount; ++i)
        {
            if (crashSignals[i] == sig) sigaction(sig, &previousActions[i], nullptr);
        }
    #endif
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
    WriteCustomStackScan();
    close(crashFile);
#endif
}
