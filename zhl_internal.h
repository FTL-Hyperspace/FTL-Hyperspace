#pragma once

#include "zhl.h"

namespace ZHL
{

// Shared by zhl_definitions.cpp (definition loading) and zhl.cpp (hooks).
void Log(const char *format, ...);
const char *ConvertToUniqueName(char *dst, size_t size, const char *name, const char *type);

class Definition
{
public:
	static int Init();
	static const char *GetLastError();
	static Definition *Find(const char *name);

protected:
	static void Add(const char *name, Definition *def);
	// Registers an extra lookup key for a definition already passed to Add.
	static void AddAlias(const char *name, Definition *def);

public:
	virtual int Load() = 0;

};


//=================================================================================================

class FunctionDefinition : public Definition
{
private:
	// _name is the plain name plus the mangled signature, and is the key hooks
	// match on. _plainName is the bare "Class::function": what messages quote,
	// and what Install() checks to tell a wrong signature from a missing name.
	char _name[512];
	char _plainName[256];

	char _sig[512];
	const short *_argdata;
	int _nArgs;
	void **_outFunc;
	void *_address;

	unsigned int _flags;

private:
	void SetName(const char *name, const char *type);

public:
	FunctionDefinition(const char *name, const std::type_info &type, const char *sig, const short *argdata, int nArgs, unsigned int flags, void **outfunc);

	virtual int Load();

#ifdef __i386__
#ifdef _WIN32
	bool IsThiscall() const {return (_flags & 1) != 0;}
#else // TODO: Might be able to remove this if the lua parser never generates the flag 1 for Linux calls
    bool IsThiscall() const {return false;}
#endif // _WIN32
	bool NeedsCallerCleanup() const {return (_flags & 2) != 0;}
	bool IsVoid() const {return (_flags & 4) != 0;}
	bool IsLongLong() const {return (_flags & 8) != 0;}
	bool isMemPassedStructPointer() const { return (_flags & 16) != 0;}
#endif // __i386__
	bool forceDetourSize() const { return (_flags & 32) != 0; }
	bool IsNoHook() const { return (_flags & 64) != 0; }

	const short *GetArgData() const {return _argdata;}
	int GetArgCount() const {return _nArgs;}
	void *GetAddress() const {return _address;}
};

//=================================================================================================

class VariableDefinition : public Definition
{
private:
	void *_outVar;
	const char *_name;
	const char *_sig;
	const bool _useValue;
	const bool _useOffset;

public:
	VariableDefinition(const char *name, const char *sig, void *outvar, bool useValue = true, bool useOffset = false) :
        _name(name),
        _sig(sig),
        _outVar(outvar),
        _useValue(useValue),
        _useOffset(useOffset)
    {
        Add(_name, this);
    }

	virtual int Load();
};

//=================================================================================================

class NoOpDefinition : public Definition
{
private:
	const char *_name;
	const char *_sig;

public:
	NoOpDefinition(const char *name, const char *sig) :
        _name(name),
        _sig(sig)
    {
        Add(_name, this);
    }

	virtual int Load();
};

}
