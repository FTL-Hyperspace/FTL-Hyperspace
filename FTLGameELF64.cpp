#include "FTLGameELF64.h"
#include "zhl_internal.h"

#ifdef _WIN32
    #define FUNC_NAKED __declspec(naked)
#elif defined(__linux__)
    #if __clang__
    #elif __GNUC__ < 8
        #error "GCC version too old, must be at least version 8"
    #endif
    #define FUNC_NAKED __attribute__((naked))
#endif

using namespace ZHL;

namespace _func0
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("AchievementTracker::LoadAchievementDescriptions", typeid(void (AchievementTracker::*)()), "4157be????????41564989fe4155415455534881ece8020100", argdata, 1, 6, &func);
}

FUNC_NAKED void AchievementTracker::LoadAchievementDescriptions()
{
	__asm__
	(
		"pushl %rbp\n\t"
		"movl %rsp, %rbp\n\t"
		"subl $8, %rsp\n\t"
		"pushl %rbx\n\t"
		"pushl %rbp\n\t"
		"pushl %r12\n\t"
		"pushl %r13\n\t"
		"pushl %r14\n\t"
		"pushl %r15\n\t"
	);
	__asm__("call *%0\n\t" :: "m"(_func0::func));
	__asm__
	(
		"popl %r15\n\t"
		"popl %r14\n\t"
		"popl %r13\n\t"
		"popl %r12\n\t"
		"popl %rbp\n\t"
		"popl %rbx\n\t"
		"movl %rbp, %rsp\n\t"
		"popl %rbp\n\t"
		"ret\n\t"
	);
}

namespace _func1
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("AchievementTracker::GetShipAchievements", typeid(std::vector<CAchievement*> (AchievementTracker::*)(const std::string &)), "4157b90200000041564989d631d241554989fd", argdata, 3, 18, &func);
}

FUNC_NAKED std::vector<CAchievement*> AchievementTracker::GetShipAchievements(const std::string &ship)
{
	__asm__
	(
		"pushl %rbp\n\t"
		"movl %rsp, %rbp\n\t"
		"subl $8, %rsp\n\t"
		"pushl %rbx\n\t"
		"pushl %rbp\n\t"
		"pushl %r12\n\t"
		"pushl %r13\n\t"
		"pushl %r14\n\t"
		"pushl %r15\n\t"
	);
	__asm__("call *%0\n\t" :: "m"(_func1::func));
	__asm__
	(
		"popl %r15\n\t"
		"popl %r14\n\t"
		"popl %r13\n\t"
		"popl %r12\n\t"
		"popl %rbp\n\t"
		"popl %rbx\n\t"
		"movl %rbp, %rsp\n\t"
		"popl %rbp\n\t"
		"ret\n\t"
	);
}

namespace _func2
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("AchievementTracker::SetAchievement", typeid(void (AchievementTracker::*)(const std::string &, bool , bool )), "415741564531f6415541545531ed534889fb4883ec68", argdata, 4, 6, &func);
}

FUNC_NAKED void AchievementTracker::SetAchievement(const std::string &achievement, bool noPopup, bool sendToServer)
{
	__asm__
	(
		"pushl %rbp\n\t"
		"movl %rsp, %rbp\n\t"
		"subl $8, %rsp\n\t"
		"pushl %rbx\n\t"
		"pushl %rbp\n\t"
		"pushl %r12\n\t"
		"pushl %r13\n\t"
		"pushl %r14\n\t"
		"pushl %r15\n\t"
	);
	__asm__("call *%0\n\t" :: "m"(_func2::func));
	__asm__
	(
		"popl %r15\n\t"
		"popl %r14\n\t"
		"popl %r13\n\t"
		"popl %r12\n\t"
		"popl %rbp\n\t"
		"popl %rbx\n\t"
		"movl %rbp, %rsp\n\t"
		"popl %rbp\n\t"
		"ret\n\t"
	);
}

namespace _func3
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("AchievementTracker::UnlockShip", typeid(void (AchievementTracker::*)(int , int )), "83fa0274434863f6488b4f184863d2", argdata, 3, 6, &func);
}

FUNC_NAKED void AchievementTracker::UnlockShip(int shipId, int shipType)
{
	__asm__
	(
		"pushl %rbp\n\t"
		"movl %rsp, %rbp\n\t"
		"subl $8, %rsp\n\t"
		"pushl %rbx\n\t"
		"pushl %rbp\n\t"
		"pushl %r12\n\t"
		"pushl %r13\n\t"
		"pushl %r14\n\t"
		"pushl %r15\n\t"
	);
	__asm__("call *%0\n\t" :: "m"(_func3::func));
	__asm__
	(
		"popl %r15\n\t"
		"popl %r14\n\t"
		"popl %r13\n\t"
		"popl %r12\n\t"
		"popl %rbp\n\t"
		"popl %rbx\n\t"
		"movl %rbp, %rsp\n\t"
		"popl %rbp\n\t"
		"ret\n\t"
	);
}

namespace _func4
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("AchievementTracker::SetSectorEight", typeid(void (AchievementTracker::*)()), "4157be????????415641554154554889fd534883ec68488d542430", argdata, 1, 6, &func);
}

FUNC_NAKED void AchievementTracker::SetSectorEight()
{
	__asm__
	(
		"pushl %rbp\n\t"
		"movl %rsp, %rbp\n\t"
		"subl $8, %rsp\n\t"
		"pushl %rbx\n\t"
		"pushl %rbp\n\t"
		"pushl %r12\n\t"
		"pushl %r13\n\t"
		"pushl %r14\n\t"
		"pushl %r15\n\t"
	);
	__asm__("call *%0\n\t" :: "m"(_func4::func));
	__asm__
	(
		"popl %r15\n\t"
		"popl %r14\n\t"
		"popl %r13\n\t"
		"popl %r12\n\t"
		"popl %rbp\n\t"
		"popl %rbx\n\t"
		"movl %rbp, %rsp\n\t"
		"popl %rbp\n\t"
		"ret\n\t"
	);
}

namespace _func5
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("AchievementTracker::GetShipMarker", typeid(int (AchievementTracker::*)(const std::string &, const std::string &)), "4157415641554989f541544989d455534883ec28488b3a", argdata, 3, 2, &func);
}

FUNC_NAKED int AchievementTracker::GetShipMarker(const std::string &baseName, const std::string &thisName)
{
	__asm__
	(
		"pushl %rbp\n\t"
		"movl %rsp, %rbp\n\t"
		"subl $8, %rsp\n\t"
		"pushl %rbx\n\t"
		"pushl %rbp\n\t"
		"pushl %r12\n\t"
		"pushl %r13\n\t"
		"pushl %r14\n\t"
		"pushl %r15\n\t"
	);
	__asm__("call *%0\n\t" :: "m"(_func5::func));
	__asm__
	(
		"popl %r15\n\t"
		"popl %r14\n\t"
		"popl %r13\n\t"
		"popl %r12\n\t"
		"popl %rbp\n\t"
		"popl %rbx\n\t"
		"movl %rbp, %rsp\n\t"
		"popl %rbp\n\t"
		"ret\n\t"
	);
}

namespace _func6
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("AchievementTracker::SetFlag", typeid(void (AchievementTracker::*)(const std::string &)), "4157488d4f50488d4748415641554154554889fd4889c7534889cb4883ec38", argdata, 2, 6, &func);
}

FUNC_NAKED void AchievementTracker::SetFlag(const std::string &flagName)
{
	__asm__
	(
		"pushl %rbp\n\t"
		"movl %rsp, %rbp\n\t"
		"subl $8, %rsp\n\t"
		"pushl %rbx\n\t"
		"pushl %rbp\n\t"
		"pushl %r12\n\t"
		"pushl %r13\n\t"
		"pushl %r14\n\t"
		"pushl %r15\n\t"
	);
	__asm__("call *%0\n\t" :: "m"(_func6::func));
	__asm__
	(
		"popl %r15\n\t"
		"popl %r14\n\t"
		"popl %r13\n\t"
		"popl %r12\n\t"
		"popl %rbp\n\t"
		"popl %rbx\n\t"
		"movl %rbp, %rsp\n\t"
		"popl %rbp\n\t"
		"ret\n\t"
	);
}

namespace _func7
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("AchievementTracker::DO_NOT_HOOK_1", typeid(void (AchievementTracker::*)()), "4157488d47484989f7415641554154554889fd4889c7534883ec38", argdata, 0, 4, &func);
}

FUNC_NAKED void AchievementTracker::DO_NOT_HOOK_1()
{
	__asm__
	(
		"pushl %rbp\n\t"
		"movl %rsp, %rbp\n\t"
		"subl $8, %rsp\n\t"
		"pushl %rbx\n\t"
		"pushl %rbp\n\t"
		"pushl %r12\n\t"
		"pushl %r13\n\t"
		"pushl %r14\n\t"
		"pushl %r15\n\t"
	);
	__asm__("call *%0\n\t" :: "m"(_func7::func));
	__asm__
	(
		"popl %r15\n\t"
		"popl %r14\n\t"
		"popl %r13\n\t"
		"popl %r12\n\t"
		"popl %rbp\n\t"
		"popl %rbx\n\t"
		"movl %rbp, %rsp\n\t"
		"popl %rbp\n\t"
		"ret\n\t"
	);
}

namespace _func8
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("AchievementTracker::GetFlag", typeid(bool (AchievementTracker::*)(const std::string &)), ".4157488d47484989f7415641554154554889fd4889c7534883ec38", argdata, 2, 2, &func);
}

FUNC_NAKED bool AchievementTracker::GetFlag(const std::string &flagName)
{
	__asm__
	(
		"pushl %rbp\n\t"
		"movl %rsp, %rbp\n\t"
		"subl $8, %rsp\n\t"
		"pushl %rbx\n\t"
		"pushl %rbp\n\t"
		"pushl %r12\n\t"
		"pushl %r13\n\t"
		"pushl %r14\n\t"
		"pushl %r15\n\t"
	);
	__asm__("call *%0\n\t" :: "m"(_func8::func));
	__asm__
	(
		"popl %r15\n\t"
		"popl %r14\n\t"
		"popl %r13\n\t"
		"popl %r12\n\t"
		"popl %rbp\n\t"
		"popl %rbx\n\t"
		"movl %rbp, %rsp\n\t"
		"popl %rbp\n\t"
		"ret\n\t"
	);
}

namespace _func9
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("AchievementTracker::SaveProfile", typeid(void (AchievementTracker::*)(int )), "41564989fe415541544189f45553488b7f30", argdata, 2, 6, &func);
}

FUNC_NAKED void AchievementTracker::SaveProfile(int file)
{
	__asm__
	(
		"pushl %rbp\n\t"
		"movl %rsp, %rbp\n\t"
		"subl $8, %rsp\n\t"
		"pushl %rbx\n\t"
		"pushl %rbp\n\t"
		"pushl %r12\n\t"
		"pushl %r13\n\t"
		"pushl %r14\n\t"
		"pushl %r15\n\t"
	);
	__asm__("call *%0\n\t" :: "m"(_func9::func));
	__asm__
	(
		"popl %r15\n\t"
		"popl %r14\n\t"
		"popl %r13\n\t"
		"popl %r12\n\t"
		"popl %rbp\n\t"
		"popl %rbx\n\t"
		"movl %rbp, %rsp\n\t"
		"popl %rbp\n\t"
		"ret\n\t"
	);
}

namespace _func10
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("AchievementTracker::LoadProfile", typeid(void (AchievementTracker::*)(int , int )), "41574989ff89f741564189d6415541544131e45589f5534883ec48", argdata, 3, 6, &func);
}

FUNC_NAKED void AchievementTracker::LoadProfile(int file, int version)
{
	__asm__
	(
		"pushl %rbp\n\t"
		"movl %rsp, %rbp\n\t"
		"subl $8, %rsp\n\t"
		"pushl %rbx\n\t"
		"pushl %rbp\n\t"
		"pushl %r12\n\t"
		"pushl %r13\n\t"
		"pushl %r14\n\t"
		"pushl %r15\n\t"
	);
	__asm__("call *%0\n\t" :: "m"(_func10::func));
	__asm__
	(
		"popl %r15\n\t"
		"popl %r14\n\t"
		"popl %r13\n\t"
		"popl %r12\n\t"
		"popl %rbp\n\t"
		"popl %rbx\n\t"
		"movl %rbp, %rsp\n\t"
		"popl %rbp\n\t"
		"ret\n\t"
	);
}

namespace _func11
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("AchievementTracker::SetVictoryAchievement", typeid(void (AchievementTracker::*)()), "554889fd53488d9fc00000004883ec38", argdata, 1, 6, &func);
}

FUNC_NAKED void AchievementTracker::SetVictoryAchievement()
{
	__asm__
	(
		"pushl %rbp\n\t"
		"movl %rsp, %rbp\n\t"
		"subl $8, %rsp\n\t"
		"pushl %rbx\n\t"
		"pushl %rbp\n\t"
		"pushl %r12\n\t"
		"pushl %r13\n\t"
		"pushl %r14\n\t"
		"pushl %r15\n\t"
	);
	__asm__("call *%0\n\t" :: "m"(_func11::func));
	__asm__
	(
		"popl %r15\n\t"
		"popl %r14\n\t"
		"popl %r13\n\t"
		"popl %r12\n\t"
		"popl %rbp\n\t"
		"popl %rbx\n\t"
		"movl %rbp, %rsp\n\t"
		"popl %rbp\n\t"
		"ret\n\t"
	);
}

namespace _func12
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("AchievementTracker::OnLanguageChange", typeid(void (AchievementTracker::*)()), "415741564989fe4155415455534881ecb8000000488b7738", argdata, 1, 6, &func);
}

FUNC_NAKED void AchievementTracker::OnLanguageChange()
{
	__asm__
	(
		"pushl %rbp\n\t"
		"movl %rsp, %rbp\n\t"
		"subl $8, %rsp\n\t"
		"pushl %rbx\n\t"
		"pushl %rbp\n\t"
		"pushl %r12\n\t"
		"pushl %r13\n\t"
		"pushl %r14\n\t"
		"pushl %r15\n\t"
	);
	__asm__("call *%0\n\t" :: "m"(_func12::func));
	__asm__
	(
		"popl %r15\n\t"
		"popl %r14\n\t"
		"popl %r13\n\t"
		"popl %r12\n\t"
		"popl %rbp\n\t"
		"popl %rbx\n\t"
		"movl %rbp, %rsp\n\t"
		"popl %rbp\n\t"
		"ret\n\t"
	);
}

namespace _func13
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("AchievementTracker::SetTooltip", typeid(void (AchievementTracker::*)(CAchievement *)), "41574156415541544989f455534881ec48010000", argdata, 2, 6, &func);
}

FUNC_NAKED void AchievementTracker::SetTooltip(CAchievement *ach)
{
	__asm__
	(
		"pushl %rbp\n\t"
		"movl %rsp, %rbp\n\t"
		"subl $8, %rsp\n\t"
		"pushl %rbx\n\t"
		"pushl %rbp\n\t"
		"pushl %r12\n\t"
		"pushl %r13\n\t"
		"pushl %r14\n\t"
		"pushl %r15\n\t"
	);
	__asm__("call *%0\n\t" :: "m"(_func13::func));
	__asm__
	(
		"popl %r15\n\t"
		"popl %r14\n\t"
		"popl %r13\n\t"
		"popl %r12\n\t"
		"popl %rbp\n\t"
		"popl %rbx\n\t"
		"movl %rbp, %rsp\n\t"
		"popl %rbp\n\t"
		"ret\n\t"
	);
}

namespace _func14
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("AchievementTracker::ResetFlags", typeid(void (AchievementTracker::*)()), "53488b77584889fb488d7f48", argdata, 1, 6, &func);
}

FUNC_NAKED void AchievementTracker::ResetFlags()
{
	__asm__
	(
		"pushl %rbp\n\t"
		"movl %rsp, %rbp\n\t"
		"subl $8, %rsp\n\t"
		"pushl %rbx\n\t"
		"pushl %rbp\n\t"
		"pushl %r12\n\t"
		"pushl %r13\n\t"
		"pushl %r14\n\t"
		"pushl %r15\n\t"
	);
	__asm__("call *%0\n\t" :: "m"(_func14::func));
	__asm__
	(
		"popl %r15\n\t"
		"popl %r14\n\t"
		"popl %r13\n\t"
		"popl %r12\n\t"
		"popl %rbp\n\t"
		"popl %rbx\n\t"
		"movl %rbp, %rsp\n\t"
		"popl %rbp\n\t"
		"ret\n\t"
	);
}

AchievementTracker *Global_AchievementTracker_Tracker;

namespace _var15
{
	static VariableDefinition varObj("Global_AchievementTracker_Tracker", "!488d742420bf(???????\?)e8????????488b5424208b44240c", &Global_AchievementTracker_Tracker);
}

