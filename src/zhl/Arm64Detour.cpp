#if defined(__aarch64__)

#include "Arm64Detour.h"
#ifdef __ANDROID__
    #include "android/MachO.h"
#endif

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <mutex>
#include <vector>
#include <algorithm>

#ifndef MAP_FIXED_NOREPLACE
    #define MAP_FIXED_NOREPLACE 0x100000
#endif

namespace
{
    // ---- memory ---------------------------------------------------------------------

    uintptr_t g_gameStart = 0;
    size_t g_gameSize = 0;

    void FlushCode(void *p, size_t n)
    {
        __builtin___clear_cache((char *)p, (char *)p + n);
    }

    size_t PageSize()
    {
        static size_t s = (size_t)sysconf(_SC_PAGESIZE);
        return s;
    }

    // Executable memory near the game, so a 4-byte B (+-128MB) reaches it from any game
    // function. Veneers and trampolines are carved from it sequentially.
    struct Pool
    {
        uint8_t *base = nullptr;
        size_t size = 0, used = 0;
    };

    Pool g_pool;
    std::mutex g_lock;

    bool NearEnough(uintptr_t from, uintptr_t to)
    {
        intptr_t d = (intptr_t)to - (intptr_t)from;
        return d > -(intptr_t)(120u << 20) && d < (intptr_t)(120u << 20);
    }

    // The pool has to be in reach of every function that may be hooked: the whole game
    // when we know where it is, otherwise the first function hooked.
    bool PoolInReach(uintptr_t pool, size_t size, uintptr_t lo, uintptr_t hi)
    {
        return NearEnough(lo, pool) && NearEnough(lo, pool + size) && NearEnough(hi, pool) && NearEnough(hi, pool + size);
    }

    bool TakePool(Pool &pool, void *p, size_t size)
    {
        mprotect(p, size, PROT_READ | PROT_EXEC);
        pool.base = (uint8_t *)p;
        pool.size = size;
        pool.used = 0;
        return true;
    }

    // The free gaps in reach, from /proc/self/maps: on a busy device the space next to the
    // game soon fills up with thread stacks, allocator regions and graphics buffers, and
    // fixed steps can miss the gaps between them. The one nearest the game wins.
    bool MakePoolInGap(Pool &pool, uintptr_t lo, uintptr_t hi, size_t size)
    {
        FILE *f = fopen("/proc/self/maps", "r");
        if (!f) return false;
        std::vector<std::pair<uintptr_t, uintptr_t>> used;
        char line[512];
        while (fgets(line, sizeof(line), f))
        {
            unsigned long a, b;
            if (sscanf(line, "%lx-%lx", &a, &b) == 2) used.emplace_back(a, b);
        }
        fclose(f);
        std::sort(used.begin(), used.end());

        const uintptr_t align = 1u << 16;
        const uintptr_t reach = 120u << 20;
        uintptr_t windowLo = hi > reach ? hi - reach + 1 : 0;
        uintptr_t windowHi = lo + reach - 1;
        std::vector<uintptr_t> candidates;
        uintptr_t prevEnd = 0;
        for (size_t i = 0; i <= used.size(); i++)
        {
            uintptr_t gapLo = std::max(prevEnd, windowLo);
            uintptr_t gapHi = std::min(i < used.size() ? used[i].first : ~(uintptr_t)0, windowHi);
            if (i < used.size()) prevEnd = std::max(prevEnd, used[i].second);
            gapLo = (gapLo + align - 1) & ~(align - 1);
            if (gapHi <= gapLo || gapHi - gapLo < size) continue;
            // The end of the gap nearest the game
            uintptr_t at = gapLo >= hi ? gapLo : ((gapHi - size) & ~(align - 1));
            if (at >= gapLo) candidates.push_back(at);
        }
        uintptr_t mid = lo + (hi - lo) / 2;
        std::sort(candidates.begin(), candidates.end(), [mid](uintptr_t x, uintptr_t y)
        {
            uintptr_t dx = x > mid ? x - mid : mid - x, dy = y > mid ? y - mid : mid - y;
            return dx < dy;
        });
        for (uintptr_t want : candidates)
        {
            void *p = mmap((void *)want, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED_NOREPLACE, -1, 0);
            if (p == MAP_FAILED) continue;
            if (!PoolInReach((uintptr_t)p, size, lo, hi))
            {
                munmap(p, size);
                continue;
            }
            return TakePool(pool, p, size);
        }
        return false;
    }

    bool MakePoolNear(Pool &pool, uintptr_t lo, uintptr_t hi, size_t size)
    {
        if (MakePoolInGap(pool, lo, hi, size)) return true;

        const uintptr_t align = 1u << 16;
        // Without the memory map: right after the game first, then just before it, then
        // further out
        for (uintptr_t step = 0; step < (64u << 20); step += (1u << 20))
        {
            for (int dir = 0; dir < 2; dir++)
            {
                uintptr_t want = dir == 0 ? ((hi + align - 1) & ~(align - 1)) + step
                                          : (lo & ~(align - 1)) - size - step;
                // NOREPLACE fails rather than map over something; kernels too old to know
                // it treat the address as a hint, which the range check below covers
                void *p = mmap((void *)want, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED_NOREPLACE, -1, 0);
                if (p == MAP_FAILED) continue;
                if (!PoolInReach((uintptr_t)p, size, lo, hi))
                {
                    munmap(p, size);
                    continue;
                }
                return TakePool(pool, p, size);
            }
        }
        return false;
    }

    bool MakePool(uintptr_t near)
    {
        uintptr_t lo = g_gameStart ? g_gameStart : near;
        uintptr_t hi = g_gameStart ? g_gameStart + g_gameSize : near;
        // ~1500 hooks need well under 200KB; take less when that's all there is
        for (size_t size : {(size_t)1u << 20, (size_t)512u << 10, (size_t)256u << 10})
        {
            if (MakePoolNear(g_pool, lo, hi, size)) return true;
        }
        return false;
    }

    bool SetProt(void *addr, size_t size, int prot)
    {
        uintptr_t start = (uintptr_t)addr & ~(uintptr_t)(PageSize() - 1);
        uintptr_t end = ((uintptr_t)addr + size + PageSize() - 1) & ~(uintptr_t)(PageSize() - 1);
        return mprotect((void *)start, end - start, prot) == 0;
    }

    // Protection of memory that is neither the game's nor the pool's, from /proc/self/maps
    int MapsProtection(uintptr_t a)
    {
        FILE *f = fopen("/proc/self/maps", "r");
        if (!f) return PROT_READ;
        char line[512];
        int prot = PROT_READ;
        while (fgets(line, sizeof(line), f))
        {
            unsigned long lo, hi;
            char perms[5];
            if (sscanf(line, "%lx-%lx %4s", &lo, &hi, perms) != 3) continue;
            if (a < lo || a >= hi) continue;
            prot = (perms[0] == 'r' ? PROT_READ : 0) | (perms[1] == 'w' ? PROT_WRITE : 0) | (perms[2] == 'x' ? PROT_EXEC : 0);
            break;
        }
        fclose(f);
        return prot;
    }

    int CurrentProt(void *addr)
    {
        uintptr_t a = (uintptr_t)addr;
        if (g_pool.base && a >= (uintptr_t)g_pool.base && a < (uintptr_t)g_pool.base + g_pool.size)
            return PROT_READ | PROT_EXEC;
#ifdef __ANDROID__
        // The port gives each game segment the protection its load command asks for
        if (g_gameStart && a >= g_gameStart && a < g_gameStart + g_gameSize)
        {
            int vm = MachO::SegmentProtection((const void *)g_gameStart, a - g_gameStart);
            if (vm >= 0)
            {
                return (vm & MachO::VM_PROT_READ ? PROT_READ : 0) | (vm & MachO::VM_PROT_WRITE ? PROT_WRITE : 0) |
                       (vm & MachO::VM_PROT_EXECUTE ? PROT_EXEC : 0);
            }
        }
#endif
        return MapsProtection(a);
    }

    // Executable pages stay executable while they're written: another thread (audio)
    // may be running code on the same page.
    bool WriteCode(void *dst, const void *src, size_t n, int prot)
    {
        if (!SetProt(dst, n, prot | PROT_READ | PROT_WRITE)) return false;
        memcpy(dst, src, n);
        bool ok = SetProt(dst, n, prot);
        FlushCode(dst, n);
        return ok;
    }

    bool WriteCode(void *dst, const void *src, size_t n)
    {
        return WriteCode(dst, src, n, CurrentProt(dst));
    }

    // ---- code generation --------------------------------------------------------------

    struct Emitter
    {
        uint32_t buf[64];
        int n = 0;
        uint64_t lits[16];
        int nlits = 0;
        int litFixups[16];

        void Emit(uint32_t ins) { buf[n++] = ins; }

        // LDR Xt, =value (literal placed after the code; fixed up in Finish)
        void LoadLiteral(int reg, uint64_t value)
        {
            litFixups[nlits] = n;
            lits[nlits++] = value;
            Emit(0x58000000u | (uint32_t)reg);
        }

        void JumpAbs(uint64_t to)
        {
            LoadLiteral(16, to);
            Emit(0xd61f0200u);  // br x16
        }

        // Code, then 8-byte aligned literals (`out` must be 8-byte aligned)
        size_t Size() const
        {
            return (((size_t)n * 4 + 7) & ~(size_t)7) + (size_t)nlits * 8;
        }

        size_t Finish(uint8_t *out)
        {
            size_t code = (size_t)n * 4;
            size_t litOff = (code + 7) & ~(size_t)7;
            for (int i = 0; i < nlits; i++)
            {
                int at = litFixups[i];
                int64_t delta = (int64_t)(litOff + (size_t)i * 8) - (int64_t)at * 4;
                buf[at] |= (uint32_t)(((delta >> 2) & 0x7ffff) << 5);
            }
            memcpy(out, buf, code);
            if (litOff > code) memcpy(out + code, "\x1f\x20\x03\xd5", 4);  // nop padding
            memcpy(out + litOff, lits, (size_t)nlits * 8);
            return litOff + (size_t)nlits * 8;
        }
    };

    int64_t SignExtend(uint64_t v, int bits)
    {
        uint64_t m = 1ull << (bits - 1);
        return (int64_t)((v ^ m) - m);
    }

    // Rewrite one instruction taken from `pc` so it runs correctly from anywhere.
    bool Relocate(Emitter &e, uint32_t ins, uint64_t pc, char *error, size_t errorSize)
    {
        if ((ins & 0x7c000000u) == 0x14000000u)  // B / BL
        {
            uint64_t to = pc + (uint64_t)(SignExtend(ins & 0x3ffffff, 26) * 4);
            if (ins & 0x80000000u)  // BL: call, then continue with the next instruction
            {
                e.LoadLiteral(16, to);
                e.Emit(0xd63f0200u);  // blr x16
            }
            else
            {
                e.JumpAbs(to);
            }
            return true;
        }
        bool cond = (ins & 0xff000010u) == 0x54000000u;   // B.cond
        bool cbz = (ins & 0x7e000000u) == 0x34000000u;    // CBZ / CBNZ
        bool tbz = (ins & 0x7e000000u) == 0x36000000u;    // TBZ / TBNZ
        if (cond || cbz || tbz)
        {
            uint64_t to = tbz ? pc + (uint64_t)(SignExtend((ins >> 5) & 0x3fff, 14) * 4)
                              : pc + (uint64_t)(SignExtend((ins >> 5) & 0x7ffff, 19) * 4);
            // <branch> taken ; b not_taken ; taken: ldr x16, =to ; br x16 ; not_taken:
            uint32_t keep = tbz ? (ins & ~(0x3fffu << 5)) | (2u << 5) : (ins & ~(0x7ffffu << 5)) | (2u << 5);
            e.Emit(keep);
            e.Emit(0x14000003u);  // b +12 (over ldr/br below)
            e.LoadLiteral(16, to);
            e.Emit(0xd61f0200u);
            return true;
        }
        if ((ins & 0x1f000000u) == 0x10000000u)  // ADR / ADRP
        {
            int rd = ins & 0x1f;
            uint64_t imm = ((ins >> 29) & 3) | (((uint64_t)(ins >> 5) & 0x7ffff) << 2);
            uint64_t value;
            if (ins & 0x80000000u)
                value = (pc & ~0xfffull) + (uint64_t)(SignExtend(imm, 21) << 12);
            else
                value = pc + (uint64_t)SignExtend(imm, 21);
            e.LoadLiteral(rd, value);
            return true;
        }
        if ((ins & 0x3b000000u) == 0x18000000u)  // LDR (literal): W/X/S/D/Q, LDRSW, PRFM
        {
            uint64_t addr = pc + (uint64_t)(SignExtend((ins >> 5) & 0x7ffff, 19) * 4);
            int rt = ins & 0x1f;
            uint32_t opc = ins >> 30;
            bool simd = (ins >> 26) & 1;
            e.LoadLiteral(17, addr);
            if (!simd)
            {
                if (opc == 0) e.Emit(0xb9400000u | (17u << 5) | (uint32_t)rt);       // ldr wt, [x17]
                else if (opc == 1) e.Emit(0xf9400000u | (17u << 5) | (uint32_t)rt);  // ldr xt, [x17]
                else if (opc == 2) e.Emit(0xb9800000u | (17u << 5) | (uint32_t)rt);  // ldrsw xt, [x17]
                else e.Emit(0xd503201fu);                                            // prfm -> nop
            }
            else
            {
                if (opc == 0) e.Emit(0xbd400000u | (17u << 5) | (uint32_t)rt);       // ldr st, [x17]
                else if (opc == 1) e.Emit(0xfd400000u | (17u << 5) | (uint32_t)rt);  // ldr dt, [x17]
                else if (opc == 2) e.Emit(0x3dc00000u | (17u << 5) | (uint32_t)rt);  // ldr qt, [x17]
                else
                {
                    snprintf(error, errorSize, "unsupported literal load %08x", ins);
                    return false;
                }
            }
            return true;
        }
        e.Emit(ins);  // not PC-relative
        return true;
    }

    uint8_t *PoolAlloc(size_t n, Pool &pool = g_pool)
    {
        n = (n + 15) & ~(size_t)15;
        if (pool.used + n > pool.size) return nullptr;
        uint8_t *p = pool.base + pool.used;
        pool.used += n;
        return p;
    }

    uint8_t *PoolWrite(Emitter &e, Pool &pool = g_pool)
    {
        alignas(8) uint8_t tmp[sizeof(e.buf) + sizeof(e.lits) + 8];
        uint8_t *p = PoolAlloc(e.Size(), pool);
        if (!p) return nullptr;
        size_t n = e.Finish(tmp);
        return WriteCode(p, tmp, n) ? p : nullptr;
    }

    uint32_t BranchTo(uintptr_t from, uintptr_t to)
    {
        return 0x14000000u | (uint32_t)((((int64_t)to - (int64_t)from) >> 2) & 0x3ffffff);
    }
}

namespace Arm64Detour
{
    void SetGameRange(uintptr_t start, size_t size)
    {
        g_gameStart = start;
        g_gameSize = size;
    }

    size_t PoolUsed(size_t *capacity)
    {
        std::lock_guard<std::mutex> lock(g_lock);
        if (capacity) *capacity = g_pool.size;
        return g_pool.used;
    }

    void *Hook(void *target, void *hook, int flags, char *error, size_t errorSize)
    {
        std::lock_guard<std::mutex> lock(g_lock);
        uintptr_t t = (uintptr_t)target;
        if (!g_pool.base && !MakePool(t))
        {
            snprintf(error, errorSize, "no memory for hook trampolines near the game");
            return nullptr;
        }
        if (!NearEnough(t, (uintptr_t)g_pool.base) || !NearEnough(t, (uintptr_t)g_pool.base + g_pool.size))
        {
            snprintf(error, errorSize, "function is out of branch range of the trampolines");
            return nullptr;
        }

        uint32_t first;
        memcpy(&first, target, 4);

        // Trampoline: the displaced instruction, relocated, then back to target + 4.
        Emitter tr;
        if (!Relocate(tr, first, t, error, errorSize)) return nullptr;
        tr.JumpAbs(t + 4);

        // Veneer: an absolute jump to the hook, or (KeepThis) a call to it that gives
        // the caller its x0 back
        Emitter ve;
        if (flags & KeepThis)
        {
            ve.Emit(0xa9be7bfdu);  // stp x29, x30, [sp, #-32]!
            ve.Emit(0x910003fdu);  // mov x29, sp
            ve.Emit(0xf9000be0u);  // str x0, [sp, #16]
            ve.LoadLiteral(16, (uint64_t)(uintptr_t)hook);
            ve.Emit(0xd63f0200u);  // blr x16
            ve.Emit(0xf9400be0u);  // ldr x0, [sp, #16]
            ve.Emit(0xa8c27bfdu);  // ldp x29, x30, [sp], #32
            ve.Emit(0xd65f03c0u);  // ret
        }
        else
        {
            ve.JumpAbs((uint64_t)(uintptr_t)hook);
        }

        uint8_t *tramp = PoolWrite(tr);
        uint8_t *veneer = tramp ? PoolWrite(ve) : nullptr;
        if (!tramp || !veneer)
        {
            snprintf(error, errorSize, "out of hook trampoline space, or it can't be written");
            return nullptr;
        }
        int64_t d = ((int64_t)(uintptr_t)veneer - (int64_t)t) >> 2;
        uint32_t b = 0x14000000u | (uint32_t)(d & 0x3ffffff);
        if (!WriteCode(target, &b, 4))
        {
            snprintf(error, errorSize, "could not make game code writable");
            return nullptr;
        }
        return tramp;
    }

    void *MakeTrap(const char *name, void (*handler)(const char *name))
    {
        std::lock_guard<std::mutex> lock(g_lock);
        if (!g_pool.base && !MakePool(g_gameStart)) return nullptr;
        Emitter e;
        e.LoadLiteral(0, (uint64_t)(uintptr_t)name);
        e.JumpAbs((uint64_t)(uintptr_t)handler);
        return PoolWrite(e);
    }

    int ReplaceUntranslatable(void *start, size_t size, char *error, size_t errorSize)
    {
        std::lock_guard<std::mutex> lock(g_lock);
        static Pool own;
        uintptr_t lo = (uintptr_t)start, hi = lo + size;
        if (!own.base && !MakePoolNear(own, lo, hi, 1u << 16))
        {
            snprintf(error, errorSize, "no memory near the code to rewrite");
            return -1;
        }
        int count = 0;
        for (uintptr_t a = lo; a + 4 <= hi; a += 4)
        {
            uint32_t ins;
            memcpy(&ins, (void *)a, 4);
            // FCVTZS / FCVTZU (vector, integer), scalar: Sd, Sn or Dd, Dn
            if ((ins & 0xdfbffc00u) != 0x5ea1b800u) continue;
            bool isUnsigned = (ins >> 29) & 1, isDouble = (ins >> 22) & 1;
            uint32_t rn = (ins >> 5) & 31, rd = ins & 31;
            Emitter e;
            e.Emit(0xd10043ffu);  // sub sp, sp, #16
            e.Emit(0xf90003f0u);  // str x16, [sp]
            // fcvtz{s,u} w16, sN / x16, dN
            e.Emit((isDouble ? 0x9e780000u : 0x1e380000u) | (isUnsigned ? 0x10000u : 0) | (rn << 5) | 16u);
            e.Emit((isDouble ? 0x9e670000u : 0x1e270000u) | (16u << 5) | rd);  // fmov sD, w16 / dD, x16
            e.Emit(0xf94003f0u);  // ldr x16, [sp]
            e.Emit(0x910043ffu);  // add sp, sp, #16
            uint8_t *stub = PoolAlloc(e.Size() + 4, own);
            if (!stub)
            {
                snprintf(error, errorSize, "out of space for rewritten instructions");
                return -1;
            }
            e.Emit(BranchTo((uintptr_t)stub + (uintptr_t)e.n * 4, a + 4));  // back after it
            alignas(8) uint8_t tmp[sizeof(e.buf) + 8];
            size_t n = e.Finish(tmp);
            uint32_t b = BranchTo(a, (uintptr_t)stub);
            // Both are read+execute; /proc/self/maps can't say so under a translator, which
            // maps ARM code for itself to read, not to run
            if (!WriteCode(stub, tmp, n, PROT_READ | PROT_EXEC) || !WriteCode((void *)a, &b, 4, PROT_READ | PROT_EXEC))
            {
                snprintf(error, errorSize, "could not write code");
                return -1;
            }
            count++;
        }
        return count;
    }

    bool Unprotect(void *address, size_t size, int *oldProt)
    {
        *oldProt = CurrentProt(address);
        return SetProt(address, size, *oldProt | PROT_READ | PROT_WRITE);
    }

    bool Reprotect(void *address, size_t size, int oldProt)
    {
        bool ok = SetProt(address, size, oldProt);
        if (oldProt & PROT_EXEC) FlushCode(address, size);
        return ok;
    }
}

#endif // __aarch64__
