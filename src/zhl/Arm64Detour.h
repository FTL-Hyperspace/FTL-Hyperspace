#pragma once
// Function hooking for arm64 (FTL for iPad, run by the Android port).
//
// The hooked function's first instruction is replaced by a 4-byte branch to a small
// veneer (an absolute jump to the hook) placed within +-128MB of the game. That one
// displaced instruction is rewritten into a trampoline, followed by a jump back, which
// is what "calling the original" runs. Patching only one instruction means even
// one-instruction functions (common for small virtual overrides in the iPad build) can
// be hooked, and hooking an already hooked function chains, because the displaced
// branch is relocated like any other PC-relative instruction.

#include <stddef.h>
#include <stdint.h>

namespace Arm64Detour
{
    // Where the game is mapped (from its Mach-O header on): veneers are placed next to
    // it, and its segments say what protection to restore after writing to it.
    void SetGameRange(uintptr_t start, size_t size);

    // How much of the memory for veneers and trampolines is in use (and its size)
    size_t PoolUsed(size_t *capacity);

    enum
    {
        // The game is built for Apple's arm64 ABI, where constructors and destructors
        // return `this`, and callers use that return value. Hyperspace's hooks on them
        // return void, so the veneer calls the hook and returns the original x0.
        // Only for functions that take no arguments on the stack.
        KeepThis = 1,
    };

    // Redirect `target` to `hook`. Returns a callable that runs the original function,
    // or nullptr with a reason in `error`.
    void *Hook(void *target, void *hook, int flags, char *error, size_t errorSize);

    // A function that calls handler(name): stands in for game functions that aren't known
    // on this build
    void *MakeTrap(const char *name, void (*handler)(const char *name));

    // Some ARM translators (redroid's libndk_translation) can't run FCVTZS/FCVTZU into a
    // SIMD register, which clang emits for float -> int -> float. This sends each one in
    // the range to a few equivalent instructions that go through x16 instead. Returns how
    // many it changed, or -1 with a reason in `error`.
    int ReplaceUntranslatable(void *start, size_t size, char *error, size_t errorSize);

    // Make memory writable for a moment (code or data) and restore it afterwards,
    // flushing the instruction cache when the range is executable.
    bool Unprotect(void *address, size_t size, int *oldProt);
    bool Reprotect(void *address, size_t size, int oldProt);
}
