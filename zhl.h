#pragma once

#ifdef _WIN32
    #define FUNC_NAKED __declspec(naked)
    #ifdef LIBZHL_EXPORTS
        #define LIBZHL_API __declspec(dllexport)
    #else
        #define LIBZHL_API __declspec(dllimport)
    #endif
#elif defined(__linux__)
    // Linux exports all symbols, we don't need to be specific like in Windows.
    // If we want to optimize this library in the future we'd need to change things around to an EXPORTED & NON_EXPORTED definition and set the __attribute___((visibility( thing to explicitly hide some exports on *NIX systems
    // SEE: https://gcc.gnu.org/wiki/Visibility
    #define LIBZHL_API
    #if __GNUC__ < 8
        #error "GCC version too old, must be at least version 8 to support naked functions"
    #endif
    #define FUNC_NAKED __attribute__((naked))
#else
    #error "Unsupported OS"
#endif

#include <stdlib.h>
#include <typeinfo>
#include <cstdio>

//=================================================================================================

namespace ZHL
{
	void Init();
	void SetLogPath(const char *logPath);
}

class FunctionHook
{
private:
	static void Add(const char *name, const std::type_info &type, void *hook, void **outInternalSuper, int priority);

public:
	template <class T> FunctionHook(const char *name, const std::type_info &type, T hook, void **outInternalSuper, int priority)
	{
		Add(name, type, *(void**)&hook, outInternalSuper, priority);
	}
};

//=================================================================================================

#define _DEFINE_METHOD_HOOK1(_id, _classname, _name, _priority, _type) \
	namespace { namespace Hook_##_id { \
		static void *internalSuper = NULL; \
		struct wrapper : public _classname { \
			auto hook _type ; \
			auto super _type ; \
		}; \
		static FunctionHook hookObj = FunctionHook(#_classname "::" #_name, typeid(auto (_classname::*) _type), &wrapper::hook, &internalSuper, _priority); \
	} } \
	auto FUNC_NAKED Hook_##_id :: wrapper::super _type {__asm__ ("jmp %0" :: "m"(internalSuper)); } \
	auto Hook_##_id ::wrapper::hook _type

#define _DEFINE_METHOD_HOOK0(_id, _classname, _name, _priority, _type) _DEFINE_METHOD_HOOK1(_id, _classname, _name, _priority, _type)

#define HOOK_METHOD(_classname, _name, _type) _DEFINE_METHOD_HOOK0(__LINE__, _classname, _name, 0, _type)
#define HOOK_METHOD_PRIORITY(_classname, _name, _priority, _type) _DEFINE_METHOD_HOOK0(__LINE__, _classname, _name, _priority, _type)

//=================================================================================================

#define _DEFINE_STATIC_HOOK1(_id, _classname, _name, _priority, _type) \
	namespace { namespace Hook_##_id { \
		static void *internalSuper = NULL; \
		struct wrapper : public _classname { \
			static auto __stdcall hook _type ; \
			static auto __stdcall super _type ; \
		}; \
		static FunctionHook hookObj(#_classname "::" #_name, typeid(auto (*) _type), &wrapper::hook, &internalSuper, _priority); \
	} } \
	auto FUNC_NAKED Hook_##_id :: wrapper::super _type {__asm__ ("jmp %0" :: "m"(internalSuper)); } \
	auto Hook_##_id ::wrapper::hook _type

#define _DEFINE_STATIC_HOOK0(_id, _classname, _name, _priority, _type) _DEFINE_STATIC_HOOK1(_id, _classname, _name, _priority, _type)

#define HOOK_STATIC(_classname, _name, _type) _DEFINE_STATIC_HOOK0(__LINE__, _classname, _name, 0, _type)
#define HOOK_STATIC_PRIORITY(_classname, _name, _priority, _type) _DEFINE_STATIC_HOOK0(__LINE__, _classname, _name, _priority, _type)

//=================================================================================================

#define _DEFINE_GLOBAL_HOOK1(_id, _name, _priority, _type) \
	namespace { namespace Hook_##_id { \
		static void *internalSuper = NULL; \
		static auto __stdcall hook _type ; \
		static auto __stdcall super _type ; \
		\
		static FunctionHook hookObj(#_name, typeid(auto (*) _type), &hook, &internalSuper, _priority); \
	} } \
	auto FUNC_NAKED __stdcall Hook_##_id ::super _type {__asm__ ("jmp %0" :: "m"(internalSuper)); } \
	auto __stdcall Hook_##_id ::hook _type

#define _DEFINE_GLOBAL_HOOK0(_id, _name, _priority, _type) _DEFINE_GLOBAL_HOOK1(_id, _name, _priority, _type)

#define HOOK_GLOBAL(_name, _type) _DEFINE_GLOBAL_HOOK0(__LINE__, _name, 0, _type)
#define HOOK_GLOBAL_PRIORITY(_name, _priority, _type) _DEFINE_GLOBAL_HOOK0(__LINE__, _name, _priority, _type)
