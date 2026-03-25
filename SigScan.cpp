#include "SigScan.h"
#include <string>
#include "hde.h"
#include "TokenScanner.h"
#include "SymbolTable.h"

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
#else
    #error "Unsupported OS"
#endif

unsigned char *SigScan::s_pBase = 0;
size_t SigScan::s_iBaseLen = 0;
unsigned char *SigScan::s_pLastStartAddress = 0;
unsigned char *SigScan::s_pLastAddress = 0;
//std::list<SigScan::Match> SigScan::s_lastMatches;

//=====================================================================

SigScan::SigScan(const char *sig) noexcept :
	m_iLength(0),
	m_sig(nullptr),
	m_mask(nullptr),
	m_matches(),
	m_bNoReturnSeek(false),
	m_bStartFromLastAddress(false),
	m_bUseSymbolLookup(false),
	m_bHasFallback(false),
	m_bAlwaysFallback(false),
	m_bSymbolLookupSuccess(false),
	m_symbolLookupType(SLType::BY_NAME),
	m_symbolName{"", 0},
	m_pAddress(nullptr),
	m_dist(0)
{
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
			m_sig = nullptr;
			m_mask = nullptr;
			return;
		}
	}

	StringView sigView{sig};
	const char* realSig = sigView.begin();
	const char* sigEnd = sigView.end();

	Scanner::SkipSpace(realSig);
	for(; *realSig;) {
		static constexpr std::initializer_list<StringView> tokenList = {
			{"@@", 2}, {"@", 1}, {"##", 2}, {"#", 1}, {"++", 2}, {"+", 1}};
		const size_t lookupType = Scanner::ConsumeAnyOf(realSig, tokenList);
		if(lookupType == tokenList.size()) {
			m_bUseSymbolLookup = false;
			break;
		}
		Scanner::SkipSpace(realSig);
		StringView symbolNameView{"", 0};
		if(Scanner::MatchTrimmedEndsWith(realSig, sigEnd, {"||", 2}, symbolNameView)) {
			if(symbolNameView.empty()) {
				m_bUseSymbolLookup = false;
				break;
			}
			m_bHasFallback = true;
			m_bAlwaysFallback = false;
			m_symbolName = symbolNameView;
			m_symbolLookupType = static_cast<SLType>(lookupType);
			m_bUseSymbolLookup = true;
			break;
		}
		if(Scanner::MatchTrimmedUntil<true>(realSig, sigEnd, {"->", 2}, symbolNameView)) {
			if(symbolNameView.empty()) {
				m_bUseSymbolLookup = false;
				break;
			}
			m_bHasFallback = true;
			m_bAlwaysFallback = true;
			m_symbolName = symbolNameView;
			m_symbolLookupType = static_cast<SLType>(lookupType);
			m_bUseSymbolLookup = true;
			break;
		}
		if(symbolNameView.empty()) {
			m_bUseSymbolLookup = false;
			break;
		}
		m_bHasFallback = false;
		m_bAlwaysFallback = false;
		m_symbolName = symbolNameView;
		m_symbolLookupType = static_cast<SLType>(lookupType);
		m_bUseSymbolLookup = true;
		break;
	}
	Scanner::SkipSpace(realSig);

	int len = 0;
	for(const char *p = realSig; *p; ++p)
	{
		char c = *p;
		len += ((c>='a' && c<='f') || (c>='A' && c<='F') || (c>='0' && c<='9') || c=='?');
	}

	m_iLength = len / 2;
	if(m_iLength == 0) {
		m_sig = nullptr;
		m_mask = nullptr;
		for (const char *p = realSig; *p; ++p) {
			if (*p == '.') {
				m_bStartFromLastAddress = true;
				continue;
			}
			if (*p == '!') {
				m_bNoReturnSeek = true;
				continue;
			}
		}
		return;
	}

	try {
		m_sig = new unsigned char[m_iLength];
		m_mask = new unsigned char[m_iLength];
	} catch(const std::bad_alloc&) {
		m_sig = nullptr;
		m_mask = nullptr;
		m_iLength = 0;
		return;
	}

	unsigned char *ps = m_sig;
	unsigned char *pm = m_mask;

	short matchStart = -1;
	short i = 0;

	for(const char *p = realSig; *p; ++p)
	{
		int c = static_cast<unsigned char>(*p);
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
		if(c == ')')
		{
			m_matches.emplace_back(matchStart, i - matchStart);
			matchStart = -1;
			continue;
		}

		if(c >= '0' && c <= '9') c -= '0';
		else if(c >= 'a' && c <= 'f') c -= ('a' - 10);
		else if(c >= 'A' && c <= 'F') c -= ('A' - 10);
		else c = -1;

		++p;

		int d = static_cast<unsigned char>(*p);
		if(!d) break;
		if(d >= '0' && d <= '9') d -= '0';
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

SigScan::~SigScan() noexcept
{
	// 'if' statement is unnecessary; deleting null pointer has no effect 
	delete[] m_sig;
	delete[] m_mask;
}

bool SigScan::Scan(Callback callback)
{
	const unsigned char *usig = m_sig;

	if(!m_bUseSymbolLookup && m_iLength == 0)
	{
		m_pAddress = s_pLastStartAddress;
		return true;
	}

	unsigned char *pStart = s_pBase;
	unsigned char *pEnd = s_pBase + s_iBaseLen - m_iLength;

	if(m_bUseSymbolLookup) { // New logic for symbol lookup
		decltype(GetSymbolByName("")) opt_symbol{boost::none};
		switch (m_symbolLookupType) {
			case SLType::BY_NAME:
				opt_symbol = GetSymbolByName(m_symbolName);
				break;
			case SLType::BY_DEMANGLED:
				opt_symbol = GetSymbolByDemangledName(m_symbolName);
				break;
			case SLType::BY_NAME_REGEX:
				opt_symbol = GetSymbolByNameRegex(m_symbolName);
				break;
			case SLType::BY_DEMANGLED_REGEX:
				opt_symbol = GetSymbolByDemangledNameRegex(m_symbolName);
				break;
			case SLType::BY_NAME_SIMPLE:
				opt_symbol = GetSymbolByNameSimple(m_symbolName);
				break;
			case SLType::BY_DEMANGLED_SIMPLE:
				opt_symbol = GetSymbolByDemangledNameSimple(m_symbolName);
				break;
		}
		if(opt_symbol.has_value()) {
			const Symbol& symbol = opt_symbol.value();
			unsigned char *pSymbol = Symbol::IsOffset() ? s_pBase + symbol.address : reinterpret_cast<unsigned char*>(symbol.address);
			m_bSymbolLookupSuccess = true;
			if(!(m_bHasFallback && m_bAlwaysFallback)) {
				// Symbol found and no fallback or not always fallback, just use symbol address
				m_pAddress = pSymbol;
				return true;
			}
			// Start scanning from symbol address if m_bHasFallback && m_bAlwaysFallback
			pStart = pSymbol;
			if(symbol.size == static_cast<std::size_t>(-1)) {
				// Size unknown, just scan to end of module
				pEnd = s_pBase + s_iBaseLen - 1;
			} else {
				pEnd = pStart + symbol.size;
			}
		} else {
			m_bSymbolLookupSuccess = false;
			if(!m_bHasFallback) {
				// Symbol not found and no fallback sig, fail the scan
				s_pLastAddress = s_pBase;
				return false;
			}
			// Symbol not found, use fallback sig
			if(m_bStartFromLastAddress) {
				pStart = s_pLastAddress;
			}
		}
	} else if(m_bStartFromLastAddress) {
		pStart = s_pLastAddress;
	}

	for( ; pStart <= pEnd ; ++pStart)
	{
		const unsigned char *p = pStart;
		const unsigned char *s = usig;
		const unsigned char *m = m_mask;
		size_t i = 0;

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
				T_HDE s{};
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

			for(auto& match : m_matches)
				match.address = m_pAddress + match.begin;

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

	s_pBase = reinterpret_cast<unsigned char*>(hModule);
	auto *dos = reinterpret_cast<IMAGE_DOS_HEADER*>(s_pBase);
	auto *pe = reinterpret_cast<IMAGE_NT_HEADERS*>(s_pBase + dos->e_lfanew);

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
#endif

