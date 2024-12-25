#include "SigScan.h"
#include <string>
#include "hde.h"

#ifdef _WIN32
    #include <windows.h>
#elif defined(__linux__)
    #include <stdio.h>
    #include <link.h>
    #include <stdlib.h>
    #include <inttypes.h>
    
    #ifdef __i386__
        #define PTR_PRINT_F "0x%08" PRIxPTR
    #elif defined(__amd64__)
        #define PTR_PRINT_F "0x%016" PRIxPTR
    #else
        #error "Unknown processor architecture not supported."
    #endif // Architecture
#elif defined(__APPLE__)
    #include <stdio.h>
    #include <stdlib.h>
    #include <inttypes.h>
    #include <mach-o/dyld.h>
	#include <mach-o/loader.h>
	#include <mach/mach.h>
	

	#ifdef __amd64__
		#define PTR_PRINT_F "0x%016" PRIxPTR
	#else
		#error "Specified processor architecture not supported for darwin. Only amd64!"
	#endif // Architecture
#else
    #error "Unsupported OS"
#endif

unsigned char *SigScan::s_pBase = 0;
size_t SigScan::s_iBaseLen = 0;
unsigned char *SigScan::s_pLastStartAddress = 0;
unsigned char *SigScan::s_pLastAddress = 0;
//std::list<SigScan::Match> SigScan::s_lastMatches;

//=====================================================================

SigScan::SigScan(const char *sig) : m_pAddress(0)
{
	m_bStartFromLastAddress = false;
	m_bNoReturnSeek = false;
	m_dist = 0;
	// Default signature if nothing was specified
	if(!sig || !sig[0])
	{
		if(s_lastMatches().empty())
		{
			// Look for the first function after the last scanned function
			// TODO: This sig will need a tweak for AMD64 variants
			sig = ".558bec";
		}
		else
		{
			// Get remaining matches from the last scan
			s_lastMatches().pop_front();
			m_matches = s_lastMatches();
			m_iLength = 0;
			m_sig = NULL;
			m_mask = NULL;
			return;
		}
	}

	int len = 0;
	for(const char *p = sig ; *p ; ++p)
	{
		char c = *p;
		len += ((c>='a' && c<='f') || (c>='A' && c<='F') || (c>='0' && c<='9') || c=='?');
	}

	m_iLength = len / 2;
	m_sig = new unsigned char[m_iLength];
	m_mask = new unsigned char[m_iLength];

	unsigned char *ps = m_sig;
	unsigned char *pm = m_mask;

	bool b = false;

	short matchStart = -1;
	int i = 0;

	for(const char *p = sig ; *p ; ++p)
	{
		int c = *p;
		if(c == '.')
		{
			m_bStartFromLastAddress = true;
			continue;
		}

		if(c == '!')
		{
			m_bNoReturnSeek = true;
			continue;
		}

		if(c == '(')
		{
			matchStart = i;
			continue;
		}
		else if(c == ')')
		{
			m_matches.push_back(Match(matchStart, i - matchStart));

			matchStart = -1;
			continue;
		}

		if(c >= '0' && c <= '9') c -= '0';
		else if(c >= 'a' && c <= 'f') c -= ('a' - 10);
		else if(c >= 'A' && c <= 'F') c -= ('A' - 10);
		else c = -1;

		++p;

		int d = *p;
		if(!d) break;
		else if(d >= '0' && d <= '9') d -= '0';
		else if(d >= 'a' && d <= 'f') d -= ('a' - 10);
		else if(d >= 'A' && d <= 'F') d -= ('A' - 10);
		else d = -1;

		if(c >= 0 && d >= 0)
		{
			*(ps++) = (c << 4) | d;
			*(pm++) = 1;
		}
		else
		{
			*(ps++) = 0;
			*(pm++) = 0;
		}
		++i;
	}

}

//=====================================================================

SigScan::~SigScan()
{
	if(m_sig)
		delete[] m_sig;
	if(m_mask)
		delete[] m_mask;
}

bool SigScan::Scan(Callback callback)
{
	const unsigned char *usig = m_sig;

	if(!m_iLength)
	{
		m_pAddress = s_pLastStartAddress;
		return true;
	}

	short itn = 0;

	unsigned char *pStart = s_pBase;
	unsigned char *pEnd = s_pBase + s_iBaseLen - m_iLength;

	if(m_bStartFromLastAddress)
		pStart = (unsigned char*)s_pLastAddress;

	for( ; pStart <= pEnd ; ++pStart)
	{
		const unsigned char *p = pStart;
		const unsigned char *s = usig;
		const unsigned char *m = m_mask;
		size_t i;

		for(i=0 ; i<m_iLength ; ++i, ++p, ++s, ++m)
			if(*m && *s != *p) break;

		if(i == m_iLength)
		{
			if(m_bStartFromLastAddress)
				m_dist = pStart-s_pLastAddress;
			else
				m_dist = pStart-s_pBase;

			m_pAddress = pStart;

			// Find out where the function ends
			s_pLastStartAddress = pStart;

			s_pLastAddress = pStart;

			if(m_bNoReturnSeek)
			{
				s_pLastAddress = pStart + m_iLength;
			}
			else
			{
				T_HDE s = {0};
				int n = 0;

				do
				{
					n = HDE_DISASM(s_pLastAddress, &s);
					s_pLastAddress += n;
				} while(n && s.opcode != 0xc2 && s.opcode != 0xc3);

				if(!n)
				{
					// failed to find ret instruction for whatever reason
					s_pLastAddress = pStart + m_iLength;
				}
			}

			for(auto it = m_matches.begin() ; it != m_matches.end() ; ++it)
				it->address = m_pAddress + it->begin;

			s_lastMatches() = m_matches;

			if(callback) callback(this);
			return true;
		}
	}

	s_pLastAddress = s_pBase;
	return false;
}

//=====================================================================
#ifdef _WIN32
void SigScan::Init()
{
	HMODULE hModule = GetModuleHandle(NULL);

	s_pBase = (unsigned char*)hModule;
	IMAGE_DOS_HEADER *dos = (IMAGE_DOS_HEADER*)s_pBase;
	IMAGE_NT_HEADERS *pe = (IMAGE_NT_HEADERS*)(s_pBase + dos->e_lfanew);

	if(pe->Signature != IMAGE_NT_SIGNATURE)
	{
		s_pBase = 0;
		return;
	}

	s_iBaseLen = pe->OptionalHeader.SizeOfImage;
	s_pLastAddress = s_pBase;
}
#elif defined(__linux__)
size_t segmentLength = 0;
uintptr_t programBaseAddress = 0;

static int callback(struct dl_phdr_info *info, size_t size, void *data) {
    static int once = 0;
    
    if(once) return 0;
    once = 1;
    
    printf("ELF Relocation addr: " PTR_PRINT_F "\n", (uintptr_t) info->dlpi_addr);
    
    for(int j = 0; j < info->dlpi_phnum; j++) {
        ElfW(Phdr) t_phdr = info->dlpi_phdr[j];
        if(t_phdr.p_type == PT_LOAD && t_phdr.p_flags & 0x11 /* executable & read I think */) {

            printf("ELF Loaded at " PTR_PRINT_F ", " PTR_PRINT_F "\n", (uintptr_t) (info->dlpi_addr + t_phdr.p_vaddr), (uintptr_t) t_phdr.p_vaddr);

            programBaseAddress = (uintptr_t) (info->dlpi_addr + t_phdr.p_vaddr);
            
            size_t seg_size = 0;
            // get segment size
            while(seg_size < t_phdr.p_filesz) {
                printf("SEG SIZE: 0x%016x\n", t_phdr.p_align);
                seg_size += t_phdr.p_align; // TODO: Dump these individual seg sizes to see if any are correct, maybe we're scanning too far?
            }
            segmentLength = seg_size; // TODO: This segment size might be wrong on 64-bit, it seems to compute a length too long?

            break;
        }
    }
    
    return 0;
}

void SigScan::Init()
{
    dl_iterate_phdr(callback, NULL);

    s_pBase = (unsigned char *) programBaseAddress;
    s_iBaseLen = segmentLength;
	s_pLastAddress = s_pBase;
}

#elif defined(__APPLE__)

/*
void SigScan::Init()
{
    // Get the number of loaded images
    int imageCount = _dyld_image_count();

    // Loop through all loaded images to find the main executable
    for (int i = 0; i < imageCount; i++)
	{
        const struct mach_header *header = _dyld_get_image_header(i);
        intptr_t slide = _dyld_get_image_vmaddr_slide(i);

        // Check if this is the main executable
        if (header->filetype == MH_EXECUTE)
		{
            const struct segment_command_64 *segCmd = nullptr;

            // Traverse load commands
            const char *cmds = (const char *)header + sizeof(struct mach_header_64);
            for (int j = 0; j < header->ncmds; j++)
			{
                const struct load_command *loadCmd = (const struct load_command *)cmds;

                // Check for the __TEXT segment (contains executable code)
                if (loadCmd->cmd == LC_SEGMENT_64)
				{
                    segCmd = (const struct segment_command_64 *)loadCmd;

                    if (strcmp(segCmd->segname, "__TEXT") == 0)
					{
                        s_pBase = (unsigned char *)(segCmd->vmaddr + slide); // Base address
                        s_iBaseLen = segCmd->vmsize; // Size of the segment
                        s_pLastAddress = s_pBase;

                        return;
                    }
                }

                cmds += loadCmd->cmdsize;
            }
        }
    }
}
*/

#include <iostream>

void SigScan::Init() {
    int imageCount = _dyld_image_count();
    std::cout << "Number of loaded images: " << imageCount << std::endl;

    for (int i = 0; i < imageCount; i++) {
        const struct mach_header *header = _dyld_get_image_header(i);
        intptr_t slide = _dyld_get_image_vmaddr_slide(i);

        if (header->filetype == MH_EXECUTE) {
            std::cout << "Found main executable image at index " << i << std::endl;
            std::cout << "Slide: 0x" << std::hex << slide << std::endl;

            const struct segment_command_64 *segCmd = nullptr;
            const char *cmds = (const char *)header + sizeof(struct mach_header_64);

            for (int j = 0; j < header->ncmds; j++) {
                const struct load_command *loadCmd = (const struct load_command *)cmds;

                if (loadCmd->cmd == LC_SEGMENT_64) {
                    segCmd = (const struct segment_command_64 *)loadCmd;

                    if (strcmp(segCmd->segname, "__TEXT") == 0) {
                        s_pBase = (unsigned char *)(segCmd->vmaddr + slide);
                        s_iBaseLen = segCmd->vmsize;
                        s_pLastAddress = s_pBase;

                        std::cout << "Found __TEXT segment:" << std::endl;
                        std::cout << "Base Address: 0x" << std::hex << (uintptr_t)s_pBase << std::endl;
                        std::cout << "Segment Length: 0x" << std::hex << s_iBaseLen << std::endl;

                        return;
                    }
                }

                cmds += loadCmd->cmdsize;
            }
        }
    }

    s_pBase = nullptr;
    s_iBaseLen = 0;
    std::cerr << "Failed to find __TEXT segment in main executable." << std::endl;
}

#endif

