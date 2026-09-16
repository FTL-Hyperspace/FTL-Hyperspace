// Minimal stand-in for <windows.h> so FTLGameWin32.cpp compiles on non-Windows
// hosts for the offline scanner. Only the names the generated code mentions;
// none of it is executed.
#pragma once

typedef long long __int64;
typedef unsigned long DWORD;
typedef void* HANDLE;
typedef void* HMODULE;

inline HMODULE GetModuleHandle(const char*) { return nullptr; }
