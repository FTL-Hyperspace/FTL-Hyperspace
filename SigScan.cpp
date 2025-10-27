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
	#include <mach-o/dyld.h>
	#include <mach/vm_page_size.h>
	#include <sys/mman.h>

	#ifdef __amd64__
		#define PTR_PRINT_F "0x%016" PRIxPTR
	#else
		#error "Processor architecture not supported. Only amd64!"
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
            
            // get segment size
            printf("SEG SIZE: 0x%016" PRIx64 "\n", t_phdr.p_memsz);
            segmentLength = t_phdr.p_memsz;

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

void SigScan::Init()
{
	for (uint32_t i = 0; i < _dyld_image_count(); i++)
	{
		const struct mach_header_64* header = (const struct mach_header_64*)_dyld_get_image_header(i);
		if (!header || header->magic != MH_MAGIC_64) continue;

		if (header->filetype != MH_EXECUTE) continue; // Filter out main executable

		uintptr_t slide = _dyld_get_image_vmaddr_slide(i);
		const uint8_t* ptr = (const uint8_t*)(header + 1);

		for (uint32_t j = 0; j < header->ncmds; j++)
		{
			const struct load_command *lc = (const struct load_command *)ptr;

			if (lc->cmd == LC_SEGMENT_64)
			{
				const struct segment_command_64 *seg = (const struct segment_command_64 *)lc;

				if (strcmp(seg->segname, "__TEXT") == 0)
				{
					const struct section_64 *sect = (const struct section_64 *)(seg + 1);
					for (uint32_t k = 0; k < seg->nsects; k++)
					{
						if (strcmp(sect->sectname, "__text") == 0)
						{
							uintptr_t codeSectStart = slide + sect->addr;

							s_pBase = reinterpret_cast<unsigned char*>(codeSectStart);
							s_iBaseLen = sect->size;
							s_pLastAddress = s_pBase;

							// pre-unprotect
							/*
							uintptr_t page_start = codeSectStart & ~(vm_page_size - 1);
							uintptr_t page_end = (codeSectStart + s_iBaseLen + vm_page_size - 1) & ~(vm_page_size - 1);
							size_t page_len = page_end - page_start;
						
							printf("[INFO] Adjusting permissions for page: 0x%lx (size: 0x%lx)\n", (unsigned long)page_start, (unsigned long)page_len);
						
							if (mprotect((void*)page_start, page_len, PROT_READ | PROT_WRITE | PROT_EXEC) != 0)
							{
								return perror("[ERROR] mprotect failed");
							}
							*/

							printf("ASLR slide amount: 0x%lx\n", slide);
							printf("__TEXT.__text start address: %lx\n", codeSectStart);
							printf("__TEXT.__text length: 0x%lx\n", s_iBaseLen);
							return;
						}
						sect++;
					}
				}
			}
			ptr += lc->cmdsize;
		}
	}
	fprintf(stderr, "[ERROR] Something went wrong while initializing the SigScanner!\n");
	return;
}

#endif

