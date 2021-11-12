#pragma once

#include "zhl.h"

namespace ZHL
{

class Definition
{
public:
	static int Init();
	static const char *GetLastError();
	static Definition *Find(const char *name);

protected:
	static void Add(const char *name, Definition *def);

public:
	virtual int Load() = 0;

};


//=================================================================================================

class FunctionDefinition : public Definition
{
private:
	char _shortName[128];
	char _name[256];

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

#ifdef _WIN32
	bool IsThiscall() const {return (_flags & 1) != 0;}
#else
    bool IsThiscall() const {return false;}
#endif // _WIN32
	bool NeedsCallerCleanup() const {return (_flags & 2) != 0;}
	bool IsVoid() const {return (_flags & 4) != 0;}
	bool IsLongLong() const {return (_flags & 8) != 0;}

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

public:
	VariableDefinition(const char *name, const char *sig, void *outvar) :
        _name(name),
        _sig(sig),
        _outVar(outvar)
    {
        Add(_name, this);
    }

	virtual int Load();
};

}
