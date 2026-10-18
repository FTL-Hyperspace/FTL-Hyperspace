#pragma once
// Reading the game's load commands in memory. The Android NDK has no <mach-o/loader.h>,
// so the few structures needed are declared here (64-bit only, as the game is arm64).

#include <stdint.h>
#include <string.h>

namespace MachO
{
    struct Header { uint32_t magic, cputype, cpusubtype, filetype, ncmds, sizeofcmds, flags, reserved; };
    struct LoadCommand { uint32_t cmd, cmdsize; };
    struct Segment
    {
        uint32_t cmd, cmdsize;
        char segname[16];
        uint64_t vmaddr, vmsize, fileoff, filesize;
        int32_t maxprot, initprot;
        uint32_t nsects, flags;
    };
    struct Section
    {
        char sectname[16], segname[16];
        uint64_t addr, size;
        uint32_t offset, align, reloff, nreloc, flags, reserved1, reserved2, reserved3;
    };

    const uint32_t MH_MAGIC_64 = 0xfeedfacf;
    const uint32_t LC_SEGMENT_64 = 0x19;
    const uint32_t LC_UUID = 0x1b;
    const int32_t VM_PROT_READ = 1, VM_PROT_WRITE = 2, VM_PROT_EXECUTE = 4;

    // Calls fn(command) for each load command until it returns true.
    template <typename F> bool ForEachCommand(const void *mh, F fn)
    {
        const Header *h = (const Header *)mh;
        if (!h || h->magic != MH_MAGIC_64) return false;
        const uint8_t *p = (const uint8_t *)(h + 1);
        for (uint32_t i = 0; i < h->ncmds; i++)
        {
            const LoadCommand *lc = (const LoadCommand *)p;
            if (fn(lc)) return true;
            p += lc->cmdsize;
        }
        return false;
    }

    inline bool GetUUID(const void *mh, uint8_t uuid[16])
    {
        return ForEachCommand(mh, [&](const LoadCommand *lc) -> bool {
            if (lc->cmd != LC_UUID) return false;
            memcpy(uuid, (const uint8_t *)lc + 8, 16);
            return true;
        });
    }

    // Link-time address and size of a section
    inline bool FindSection(const void *mh, const char *seg, const char *sect, uint64_t *addr, uint64_t *size)
    {
        return ForEachCommand(mh, [&](const LoadCommand *lc) -> bool {
            if (lc->cmd != LC_SEGMENT_64) return false;
            const Segment *s = (const Segment *)lc;
            if (strncmp(s->segname, seg, 16) != 0) return false;
            const Section *sc = (const Section *)(s + 1);
            for (uint32_t i = 0; i < s->nsects; i++, sc++)
            {
                if (strncmp(sc->sectname, sect, 16) == 0)
                {
                    *addr = sc->addr;
                    *size = sc->size;
                    return true;
                }
            }
            return false;
        });
    }

    // Initial protection (VM_PROT_*) of the segment holding `offset` (bytes from the
    // mapped header, which starts __TEXT), or -1
    inline int SegmentProtection(const void *mh, uint64_t offset)
    {
        uint64_t text = 0;
        ForEachCommand(mh, [&](const LoadCommand *lc) -> bool {
            if (lc->cmd != LC_SEGMENT_64) return false;
            const Segment *s = (const Segment *)lc;
            if (s->fileoff != 0 || s->filesize == 0) return false;
            text = s->vmaddr;
            return true;
        });
        uint64_t addr = text + offset;
        int prot = -1;
        ForEachCommand(mh, [&](const LoadCommand *lc) -> bool {
            if (lc->cmd != LC_SEGMENT_64) return false;
            const Segment *s = (const Segment *)lc;
            if (s->filesize == 0 && s->fileoff == 0 && s->vmsize > 0 && s->initprot == 0) return false;  // __PAGEZERO
            if (addr < s->vmaddr || addr >= s->vmaddr + s->vmsize) return false;
            prot = s->initprot;
            return true;
        });
        return prot;
    }
}
