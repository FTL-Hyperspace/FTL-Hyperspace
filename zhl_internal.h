#pragma once

#include "zhl.h"
#include <cstring>

namespace ZHL
{

class Definition
{
public:
	static int Init();
	static const char *GetLastError();
	static Definition *Find(const char *name);

protected:
	static bool Add(const char *name, Definition *def) noexcept;

public:
	virtual int Load() = 0;

};


//=================================================================================================

class FunctionDefinition : public Definition
{
private:
	char _name[256]{};

	char _sig[512]{};
	const short *_argdata;
	int _nArgs;
	void **_outFunc;
	void *_address{};

	unsigned int _flags;

	void SetName(const char *name, const char *type) noexcept;

public:
	FunctionDefinition(const char *name, const std::type_info &type, const char* sig, const short *argdata, int nArgs, unsigned int flags, void **outfunc) noexcept :
		_argdata(argdata),
		_nArgs(nArgs),
		_outFunc(outfunc),
		_flags(flags)
	{
    	SetName(name, type.name());
		std::strncpy(_name, name, sizeof(_name) - 1);
    	std::strncpy(_sig, sig, sizeof(_sig) - 1);
    	if(!Add(_name, this)) {
			// error
		}
	}

	int Load() override;

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
	VariableDefinition(const char *name, const char *sig, void *outvar, bool useValue = true, bool useOffset = false) noexcept :
        _outVar(outvar),
        _name(name),
        _sig(sig),
        _useValue(useValue),
        _useOffset(useOffset)
    {
        if(!Add(_name, this)) {
			// error
		}
    }

	int Load() override;
};

//=================================================================================================

class NoOpDefinition : public Definition
{
private:
	const char *_name;
	const char *_sig;

public:
	NoOpDefinition(const char *name, const char *sig) noexcept :
        _name(name),
        _sig(sig)
    {
        if(!Add(_name, this)) {
			// error
		}
    }

	int Load() override;
};

}
