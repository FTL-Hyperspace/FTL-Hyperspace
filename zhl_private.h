#pragma once
#include "zhl.h"

//=================================================================================================

#define FUNCTIONHOOK_MAXSIZE 128

class FunctionHook_private
{
private:
	// _name carries the signature the hook declared, so it resolves one specific
	// overload. _plainName is the bare name: what errors quote, and what
	// Install() checks to tell a wrong signature from a missing name.
	char _name[512];
	char _plainName[256];


	void **_outInternalSuper;

	unsigned char _internalHook[FUNCTIONHOOK_MAXSIZE];
	unsigned char _internalSuper[FUNCTIONHOOK_MAXSIZE];
	unsigned int _hSize;
	unsigned int _sSize;
	int _priority;

	void *_detour;

public:
	static int Init();
	static const char *GetLastError();
	void *_hook;

private:
	static void Add(FunctionHook_private *hook);
	void SetName(const char *name, const char *type);
	int Install();

public:
	FunctionHook_private(const char *name, const std::type_info &type, void *hook, void **outInternalSuper, int priority);
	~FunctionHook_private();
};
