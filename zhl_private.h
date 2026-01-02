#pragma once
#include "zhl.h"

//=================================================================================================

#define FUNCTIONHOOK_MAXSIZE 128

class FunctionHook_private
{
private:
	char _name[256];


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
	static bool Add(FunctionHook_private *hook) noexcept;
	void SetName(const char *name, const char *type) noexcept;
	int Install();

public:
	FunctionHook_private(const char *name, const std::type_info &type, void *hook, void **outInternalSuper, int priority) noexcept;
	~FunctionHook_private();
};
