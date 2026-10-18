#ifndef PALMEMORYPROTECTION_H_INCLUDED
#define PALMEMORYPROTECTION_H_INCLUDED

#ifdef __aarch64__
// Memory is made writable, then given its old protection back (with an instruction
// cache flush for code), never left writable and executable at once.
#include "zhl/Arm64Detour.h"
#define MEMPROT_SAVE_PROT(NAME) int NAME = 0
#define MEMPROT_UNPROTECT(ADDRESS, SIZE, OLDPROT) Arm64Detour::Unprotect((void*)(ADDRESS), (SIZE), &(OLDPROT))
#define MEMPROT_REPROTECT(ADDRESS, SIZE, OLDPROT) Arm64Detour::Reprotect((void*)(ADDRESS), (SIZE), (OLDPROT))
#else
#include "detours.h"

#define MEMPROT_SAVE_PROT(NAME) MOLOGIE_DETOURS_MEMORY_WINDOWS_INIT((NAME))
#define MEMPROT_UNPROTECT(ADDRESS, SIZE, OLDPROT) MOLOGIE_DETOURS_MEMORY_UNPROTECT((ADDRESS), (SIZE), (OLDPROT))
#define MEMPROT_REPROTECT(ADDRESS, SIZE, OLDPROT) MOLOGIE_DETOURS_MEMORY_REPROTECT((ADDRESS), (SIZE), (OLDPROT))
#endif

#if defined(_WIN32) || defined(__aarch64__)
    #define MEMPROT_PAGESIZE()
#else
    #include <unistd.h>
    #define MEMPROT_PAGESIZE() size_t pageSize_ = sysconf(_SC_PAGESIZE)
#endif

#endif // PALMEMORYPROTECTION_H_INCLUDED
