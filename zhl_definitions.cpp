// ZHL definition loading: resolves every FunctionDefinition / VariableDefinition /
// NoOpDefinition registered by the generated FTLGame*.cpp against the code
// section SigScan was initialised with. Contains no hook or platform code so it
// can also be linked into the offline signature scanner (libzhlgen/zhlscan).

#include "zhl_internal.h"
#include "SigScan.h"
#include <unordered_map>
#include <string>
#include <cstdarg>
#include <cstring>
#include <inttypes.h>

#ifdef ZHL_OFFLINE_SCAN
    // The scanned code lives in a writable buffer; no page protection to lift.
    #define MEMPROT_SAVE_PROT(NAME)
    #define MEMPROT_PAGESIZE()
    #define MEMPROT_UNPROTECT(ADDRESS, SIZE, OLDPROT)
    #define MEMPROT_REPROTECT(ADDRESS, SIZE, OLDPROT)
#else
    #include "PALMemoryProtection.h"
#endif

#if UINTPTR_MAX == 0xffffffff
    #define PTR_PRINT_F "0x%08" PRIxPTR
#else
    #define PTR_PRINT_F "0x%016" PRIxPTR
#endif

using namespace ZHL;

static const char *g_logPath = NULL;
static FILE *g_hookLog = NULL;

void ZHL::SetLogPath(const char *logPath)
{
	g_logPath = logPath;
	if(g_hookLog)
	{
		fclose(g_hookLog);
		g_hookLog = NULL;
	}
}

//#define HOOK_LOG
void ZHL::Log(const char *format, ...)
{
	if(!g_logPath) return;
	if(!g_hookLog) g_hookLog = std::fopen(g_logPath, "w");
	if(!g_hookLog) return;



	va_list va;
	va_start(va, format);
	vfprintf(g_hookLog, format, va);
	fflush(g_hookLog);
	va_end(va);
}

// Builds the key a definition is registered under and a hook looks up: the plain
// name followed by the mangled signature, so overloads stay apart. Reads type in
// place; the 128-byte copy this used to make cut the signature at 127 characters,
// which would give two signatures differing only past the cut the same key.
const char *ZHL::ConvertToUniqueName(char *dst, size_t Size, const char *name, const char *type)
{
	const char *p = type;
	if (p[0] == '.')
	{
		++p;
		if (p[0] == 'P' && p[1] == '8')
		{
			p += 2;
			while (p[0] && (p[0] != '@' || p[1] != '@'))
			{
				++p;
			}
		}
	}

	// Safely concatenate (truncate if needed)
	int written = snprintf(dst, Size, "%s%s", name, p);
	if (written < 0 || (size_t)written >= Size)
	{
		dst[Size - 1] = '\0'; // Ensure null-termination
		// Two signatures that only differ past the cut would now share a key.
		Log("Warning: unique name for %s truncated to %zu bytes\n", name, Size - 1);
	}
	return dst;
}


//================================================================================
// Definition

static std::vector<Definition*> &Defs()
{
	static std::vector<Definition*> defs;
	return defs;
}

static std::unordered_map<std::string, Definition*> &DefsByName()
{
	static std::unordered_map<std::string, Definition*> defsByName;
	return defsByName;
}

static char g_defLastError[1024] = {0};

const char *Definition::GetLastError() {return g_defLastError;}

void FunctionDefinition::SetName(const char *name, const char *type)
{
	ConvertToUniqueName(_name, sizeof(_name), name, type);
}

int Definition::Init()
{
	SigScan::Init();

	for(auto it = Defs().begin() ; it != Defs().end() ; ++it)
	{
		if(!(*it)->Load()) return 0;
	}
	return 1;
}

Definition *Definition::Find(const char *name)
{
	auto it = DefsByName().find(name);
	if(it != DefsByName().end())
		return (*it).second;
	else
		return NULL;
}

void Definition::Add(const char *name, Definition *def)
{
	Defs().push_back(def);
	AddAlias(name, def);
}

void Definition::AddAlias(const char *name, Definition *def)
{
	// insert() keeps the incumbent, so when several definitions share a key the
	// first one registered stays reachable and the rest are shadowed.
	DefsByName().insert(std::pair<std::string, Definition*>(name, def));
}



//================================================================================
// VariableDefinition


int VariableDefinition::Load()
{
	SigScan sig(_sig);
	if(!sig.Scan())
	{
		snprintf(g_defLastError, 1024, "Failed to find value for variable %s, address could not be found", _name);
		return 0;
	}

	if(sig.GetMatchCount() == 0)
	{
		snprintf(g_defLastError, 1024, "Failed to find address for variable %s, no capture in input signature", _name);
		return 0;
	}

	const SigScan::Match &m = sig.GetMatch();
	if(_useOffset)
    {
        /* Instruction Pointer relative addressing
         * Determine real address of variable match
         * RIP + var = real addr
         * During execution (E|R)IP would be at the next instruction so instead we add the length of the match
         * NOTE: This means it is only possible to match a variable with offset computation that is at the END of the instruction bytes
         * i.e., operands that can take two memory addresses, only the second memory address (end of the bytes of the instruction) can be matched.
         */
        uintptr_t valueVar = 0;
        memcpy(&valueVar, m.address, m.length);
        uintptr_t realAddr = (uintptr_t) m.address;
        realAddr += m.length;
        realAddr += valueVar;
        *(void**)_outVar = (void*) realAddr;
    }
	else if(_useValue)
        memcpy(_outVar, m.address, m.length);
    else
        *(void**)_outVar = (void*)m.address;

	Log("Found value for %s: " PTR_PRINT_F ", scan " PTR_PRINT_F ", dist %d\n",
		_name, *((uintptr_t*) _outVar), (uintptr_t)sig.GetAddress(), sig.GetDistance());

	return 1;
}

//================================================================================
// NoOpDefinition


int NoOpDefinition::Load()
{
	SigScan sig(_sig);
	if(!sig.Scan())
	{
		snprintf(g_defLastError, 1024, "Failed to find match for no-op region %s, address could not be found", _name);
		return 0;
	}

	if(sig.GetMatchCount() == 0)
	{
		snprintf(g_defLastError, 1024, "Failed to find match for no-op region %s, no capture in input signature", _name);
		return 0;
	}

	const SigScan::Match &m = sig.GetMatch();
	
	uintptr_t ptrToCode = (uintptr_t) m.address;
    const size_t noopingSize = sizeof(uint8_t) * m.length;
    MEMPROT_SAVE_PROT(dwOldProtect);
    MEMPROT_PAGESIZE();
    MEMPROT_UNPROTECT(ptrToCode, noopingSize, dwOldProtect);
    for(unsigned int i = 0; i < m.length; i++)
    {
        *(uint8_t*)(ptrToCode++) = 0x90;
    }
    MEMPROT_REPROTECT(ptrToCode, noopingSize, dwOldProtect);

	Log("Found address for %s: " PTR_PRINT_F ", wrote NOP's for %d bytes, dist %d\n", _name, (uintptr_t) m.address, m.length, sig.GetDistance());

	return 1;
}

//================================================================================
// FunctionDefinition

FunctionDefinition::FunctionDefinition(const char *name, const std::type_info &type, const char* sig, const short *argdata, int nArgs, unsigned int flags, void **outfunc)
{
    _argdata = argdata;
    _nArgs = nArgs;
    _flags = flags;
    _outFunc = outfunc;



    SetName(name, type.name());
    snprintf(_plainName, sizeof(_plainName), "%s", name);
    strcpy(_sig, sig);

    // Registered under both keys: the signature-qualified one that hooks match
    // on, and the plain name, which Install() consults only to tell a wrong
    // signature apart from a name that does not exist at all.
    Add(_plainName, this);
    AddAlias(_name, this);

}

int FunctionDefinition::Load()
{
	SigScan sig = SigScan(_sig);

	if(!sig.Scan())
	{
	#ifdef _WIN32
		if (strncmp(_plainName, "AchievementTracker::", 20) == 0)
		{
			snprintf(g_defLastError, 1024, "Failed to find address for function %s\n\nFTL has most likely not been downgraded. If you got FTL from Steam, please run downgrade.bat in your FTL folder and then run FTLGame.exe again. If you obtained FTL elsewhere, please read the Hyperspace instructions for downgrading FTL.", _plainName);
			return 0;
		}
	#endif // _WIN32
		snprintf(g_defLastError, 1024, "Failed to find address for function %s", _plainName);
		return 0;
	}

	_address = sig.GetAddress<void*>();
	*_outFunc = _address;
	Log("Found address for %s: " PTR_PRINT_F ", dist %d\n", _plainName, (uintptr_t)_address, sig.GetDistance());

	return 1;
}

