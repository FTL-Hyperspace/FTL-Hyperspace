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
			// rdi has this
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
	static FunctionDefinition funcObj("AchievementTracker::GetShipAchievements", typeid(std::vector<CAchievement*> (AchievementTracker::*)(const std::string &)), "4157b90200000041564989d631d241554989fd", argdata, 3, 2, &func);
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
			// rdi has implicit_output
			// rsi has this
			// rdx has ship
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
			// rdi has this
			// rsi has achievement
			// rdx has noPopup
			// rcx has sendToServer
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
			// rdi has this
			// rsi has shipId
			// rdx has shipType
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
			// rdi has this
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
			// rdi has this
			// rsi has baseName
			// rdx has thisName
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
			// rdi has this
			// rsi has flagName
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
			// rdi has this
			// rsi has flagName
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
			// rdi has this
			// rsi has file
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
			// rdi has this
			// rsi has file
			// rdx has version
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
			// rdi has this
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
			// rdi has this
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
			// rdi has this
			// rsi has ach
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
			// rdi has this
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

namespace _func16
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x10a, 0x101, 0x108, 0x109, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Animation::constructor", typeid(void (Animation::*)(const std::string &, int , float , Pointf , int , int , int , int )), "41574989f7be????????", argdata, 9, 6, &func);
}

FUNC_NAKED void Animation::constructor(const std::string &_image, int _length, float _time, Pointf _position, int _imageWidth, int _imageHeight, int _stripStartX, int _numFrames)
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
		"pushl 16(%rbp)\n\t"		// _numFrames
		"pushl 8(%rbp)\n\t"		// _stripStartX
			// rdi has this
			// rsi has _image
			// rdx has _length
			// xmm0 has _time
			// rcx has _position
			// r8 has _imageWidth
			// r9 has _imageHeight
	);
	__asm__("call *%0\n\t" :: "m"(_func16::func));
	__asm__
	(
		"addl $16, %rsp\n\t"
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

namespace _func17
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x2ff, 0x106};
	static FunctionDefinition funcObj("Animation::OnRender", typeid(void (Animation::*)(float , GL_Color , bool )), "4156415541544189f455534889fb4883ec30", argdata, 4, 6, &func);
}

FUNC_NAKED void Animation::OnRender(float opacity, GL_Color color, bool mirror)
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
		"pushl 16(%rbp)\n\t"		// color
		"pushl 8(%rbp)\n\t"		// color
			// rdi has this
			// xmm0 has opacity
			// rsi has mirror
	);
	__asm__("call *%0\n\t" :: "m"(_func17::func));
	__asm__
	(
		"addl $16, %rsp\n\t"
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

namespace _func18
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Animation::Update", typeid(void (Animation::*)()), "41564155415455534889fb4883ec30807f3c00", argdata, 1, 6, &func);
}

FUNC_NAKED void Animation::Update()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func18::func));
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

namespace _func19
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Animation::SetCurrentFrame", typeid(void (Animation::*)(int )), "8b4708897424fc8d50ff", argdata, 2, 6, &func);
}

FUNC_NAKED void Animation::SetCurrentFrame(int frame)
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
			// rdi has this
			// rsi has frame
	);
	__asm__("call *%0\n\t" :: "m"(_func19::func));
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

namespace _func20
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Animation::Start", typeid(void (Animation::*)(bool )), "534889fb4883ec104084f60f85", argdata, 2, 6, &func);
}

FUNC_NAKED void Animation::Start(bool reset)
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
			// rdi has this
			// rsi has reset
	);
	__asm__("call *%0\n\t" :: "m"(_func20::func));
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

namespace _func21
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("Animation::AddSoundQueue", typeid(void (Animation::*)(int , const std::string &)), "85f6784e488b4f78", argdata, 3, 6, &func);
}

FUNC_NAKED void Animation::AddSoundQueue(int frame, const std::string &sound)
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
			// rdi has this
			// rsi has frame
			// rdx has sound
	);
	__asm__("call *%0\n\t" :: "m"(_func21::func));
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

namespace _func22
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Animation::SetAnimationId", typeid(void (Animation::*)(GL_Texture *)), "48393774354889f0", argdata, 2, 6, &func);
}

FUNC_NAKED void Animation::SetAnimationId(GL_Texture *tex)
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
			// rdi has this
			// rsi has tex
	);
	__asm__("call *%0\n\t" :: "m"(_func22::func));
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

namespace _func23
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Animation::destructor", typeid(void (Animation::*)()), "4157415641554989fd415455534883ec18488b8798000000", argdata, 1, 6, &func);
}

FUNC_NAKED void Animation::destructor()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func23::func));
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

namespace _func24
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Animation::StartReverse", typeid(void (Animation::*)(bool )), "534889fb4883ec104084f67573", argdata, 2, 6, &func);
}

FUNC_NAKED void Animation::StartReverse(bool reset)
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
			// rdi has this
			// rsi has reset
	);
	__asm__("call *%0\n\t" :: "m"(_func24::func));
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

namespace _func25
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("Animation::SetProgress", typeid(void (Animation::*)(float )), "f30f105730807f3c00", argdata, 2, 6, &func);
}

FUNC_NAKED void Animation::SetProgress(float progress)
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
			// rdi has this
			// xmm0 has progress
	);
	__asm__("call *%0\n\t" :: "m"(_func25::func));
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

namespace _func26
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Animation::RandomStart", typeid(int (Animation::*)()), "803d????????00534889fb7543", argdata, 1, 2, &func);
}

FUNC_NAKED int Animation::RandomStart()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func26::func));
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

namespace _func27
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("AnimationControl::GetAnimation", typeid(Animation (AnimationControl::*)(const std::string &)), "415741564155415455534883ec6848897c2408", argdata, 3, 2, &func);
}

FUNC_NAKED Animation AnimationControl::GetAnimation(const std::string &animName)
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
			// rdi has implicit_output
			// rsi has this
			// rdx has animName
	);
	__asm__("call *%0\n\t" :: "m"(_func27::func));
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

AnimationControl *Global_AnimationControl_Animations;

namespace _var28
{
	static VariableDefinition varObj("Global_AnimationControl_Animations", "!488d542460488d7c2470be(???????\?)e8????????488b442470", &Global_AnimationControl_Animations);
}

namespace _func29
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("AnimationTracker::Update", typeid(void (AnimationTracker::*)()), "53807f14004889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void AnimationTracker::Update()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func29::func));
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

namespace _func30
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x10a};
	static FunctionDefinition funcObj("AnimationTracker::SetLoop", typeid(void (AnimationTracker::*)(bool , float )), "4088770c", argdata, 3, 6, &func);
}

FUNC_NAKED void AnimationTracker::SetLoop(bool loop, float loopDelay)
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
			// rdi has this
			// rsi has loop
			// xmm0 has loopDelay
	);
	__asm__("call *%0\n\t" :: "m"(_func30::func));
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

namespace _func31
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("AnimationTracker::Stop", typeid(void (AnimationTracker::*)(bool )), "4084f6c6471400", argdata, 2, 6, &func);
}

FUNC_NAKED void AnimationTracker::Stop(bool resetTime)
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
			// rdi has this
			// rsi has resetTime
	);
	__asm__("call *%0\n\t" :: "m"(_func31::func));
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

namespace _func32
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("AnimationTracker::Start", typeid(void (AnimationTracker::*)(float )), "c6471600c6471401f30f114710", argdata, 2, 6, &func);
}

FUNC_NAKED void AnimationTracker::Start(float time)
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
			// rdi has this
			// xmm0 has time
	);
	__asm__("call *%0\n\t" :: "m"(_func32::func));
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

namespace _func33
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("AnimationTracker::StartReverse", typeid(void (AnimationTracker::*)(float )), "0f57c9c6471600", argdata, 2, 6, &func);
}

FUNC_NAKED void AnimationTracker::StartReverse(float time)
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
			// rdi has this
			// xmm0 has time
	);
	__asm__("call *%0\n\t" :: "m"(_func33::func));
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

namespace _func34
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("AnimationTracker::Progress", typeid(float (AnimationTracker::*)(float )), "807f14000f57c9", argdata, 2, 2, &func);
}

FUNC_NAKED float AnimationTracker::Progress(float speed)
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
			// rdi has this
			// xmm0 has speed
	);
	__asm__("call *%0\n\t" :: "m"(_func34::func));
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

namespace _func35
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("AnimationTracker::SetProgress", typeid(void (AnimationTracker::*)(float )), "f30f594708", argdata, 2, 6, &func);
}

FUNC_NAKED void AnimationTracker::SetProgress(float time)
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
			// rdi has this
			// xmm0 has time
	);
	__asm__("call *%0\n\t" :: "m"(_func35::func));
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

namespace _func36
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("AnimationTracker::GetAlphaLevel", typeid(float (AnimationTracker::*)(bool )), "f30f100d????????f30f1015????????f30f594f08", argdata, 2, 2, &func);
}

FUNC_NAKED float AnimationTracker::GetAlphaLevel(bool reverse)
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
			// rdi has this
			// rsi has reverse
	);
	__asm__("call *%0\n\t" :: "m"(_func36::func));
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

namespace _func37
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ArmamentControl::Dragging", typeid(bool (ArmamentControl::*)()), "5383bfb0000000ff", argdata, 1, 2, &func);
}

FUNC_NAKED bool ArmamentControl::Dragging()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func37::func));
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

namespace _func38
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ArmamentControl::SetPosition", typeid(void (ArmamentControl::*)(Point )), "55534889fb4883ec08397738", argdata, 2, 6, &func);
}

FUNC_NAKED void ArmamentControl::SetPosition(Point loc)
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
			// rdi has this
			// rsi has loc
	);
	__asm__("call *%0\n\t" :: "m"(_func38::func));
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

namespace _func39
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ArmamentControl::KeyDown", typeid(bool (ArmamentControl::*)(SDLKey )), "415431c94989fc5589f553", argdata, 2, 2, &func);
}

FUNC_NAKED bool ArmamentControl::KeyDown(SDLKey key)
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
			// rdi has this
			// rsi has key
	);
	__asm__("call *%0\n\t" :: "m"(_func39::func));
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

namespace _func40
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ArtilleryBox::constructor", typeid(void (ArtilleryBox::*)(Point , ArtillerySystem *)), "55b9010000004889d5534889fb4883ec08", argdata, 3, 6, &func);
}

FUNC_NAKED void ArtilleryBox::constructor(Point pos, ArtillerySystem *sys)
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
			// rdi has this
			// rsi has pos
			// rdx has sys
	);
	__asm__("call *%0\n\t" :: "m"(_func40::func));
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

namespace _func41
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ArtilleryBox::OnRender", typeid(void (ArtilleryBox::*)(bool )), "4154400fb6f655534889fb4883ec70", argdata, 2, 6, &func);
}

FUNC_NAKED void ArtilleryBox::OnRender(bool ignoreStatus)
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
			// rdi has this
			// rsi has ignoreStatus
	);
	__asm__("call *%0\n\t" :: "m"(_func41::func));
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

namespace _func42
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ArtillerySystem::OnLoop", typeid(void (ArtillerySystem::*)()), "415455534889fb4883ec70e8????????4889df", argdata, 1, 6, &func);
}

FUNC_NAKED void ArtillerySystem::OnLoop()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func42::func));
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

namespace _func43
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("AsteroidGenerator::constructor", typeid(void (AsteroidGenerator::*)()), "415741564155415455534889fbbf40000000", argdata, 1, 6, &func);
}

FUNC_NAKED void AsteroidGenerator::constructor()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func43::func));
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

namespace _func44
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("AsteroidGenerator::Initialize", typeid(float (AsteroidGenerator::*)(int , int , bool )), ".89d0538997b4000000", argdata, 4, 2, &func);
}

FUNC_NAKED float AsteroidGenerator::Initialize(int numberOfShips, int shieldCount, bool defense)
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
			// rdi has this
			// rsi has numberOfShips
			// rdx has shieldCount
			// rcx has defense
	);
	__asm__("call *%0\n\t" :: "m"(_func44::func));
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

namespace _func45
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("AsteroidGenerator::SetNumShips", typeid(void (AsteroidGenerator::*)(int )), ".89b798000000", argdata, 2, 6, &func);
}

FUNC_NAKED void AsteroidGenerator::SetNumShips(int ships)
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
			// rdi has this
			// rsi has ships
	);
	__asm__("call *%0\n\t" :: "m"(_func45::func));
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

namespace _func46
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("AsteroidGenerator::GetNextAsteroid", typeid(Projectile *(AsteroidGenerator::*)()), ".415741564155415455534889fb4881ec38030000", argdata, 1, 2, &func);
}

FUNC_NAKED Projectile *AsteroidGenerator::GetNextAsteroid()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func46::func));
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

namespace _func47
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("AsteroidGenerator::OnLoop", typeid(void (AsteroidGenerator::*)()), ".415741564155415455534889fb4883ec18", argdata, 1, 6, &func);
}

FUNC_NAKED void AsteroidGenerator::OnLoop()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func47::func));
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

namespace _func48
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("AsteroidGenerator::GetNextState", typeid(void (AsteroidGenerator::*)()), ".538b879c000000", argdata, 1, 6, &func);
}

FUNC_NAKED void AsteroidGenerator::GetNextState()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func48::func));
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

namespace _func49
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("AsteroidGenerator::UpdateState", typeid(void (AsteroidGenerator::*)()), ".534889fbbf????????e8????????", argdata, 1, 6, &func);
}

FUNC_NAKED void AsteroidGenerator::UpdateState()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func49::func));
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

namespace _func50
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("AsteroidGenerator::SaveAsteroids", typeid(bool (AsteroidGenerator::*)(void *)), ".554889fd5389f34883ec08", argdata, 2, 2, &func);
}

FUNC_NAKED bool AsteroidGenerator::SaveAsteroids(void *file)
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
			// rdi has this
			// rsi has file
	);
	__asm__("call *%0\n\t" :: "m"(_func50::func));
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

namespace _func51
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("AsteroidGenerator::LoadAsteroids", typeid(void (AsteroidGenerator::*)(void *)), ".5589f5534889fb89f74883ec08", argdata, 2, 6, &func);
}

FUNC_NAKED void AsteroidGenerator::LoadAsteroids(void *file)
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
			// rdi has this
			// rsi has file
	);
	__asm__("call *%0\n\t" :: "m"(_func51::func));
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

namespace _func52
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("AugmentEquipBox::RenderIcon", typeid(void (AugmentEquipBox::*)()), "534889fbe8????????8b435c8b5358", argdata, 1, 6, &func);
}

FUNC_NAKED void AugmentEquipBox::RenderIcon()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func52::func));
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

namespace _func53
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("AugmentEquipBox::CheckContents", typeid(void (AugmentEquipBox::*)()), "41544989fc55534883ec40488bb7a8000000", argdata, 1, 6, &func);
}

FUNC_NAKED void AugmentEquipBox::CheckContents()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func53::func));
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

namespace _func54
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("AugmentEquipBox::RemoveItem", typeid(void (AugmentEquipBox::*)()), "534889fb4883ec204883bfa800000000743d", argdata, 1, 6, &func);
}

FUNC_NAKED void AugmentEquipBox::RemoveItem()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func54::func));
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

namespace _func55
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("AugmentStoreBox::constructor", typeid(void (AugmentStoreBox::*)(ShipManager *, const AugmentBlueprint *)), "41544989f4be????????554889d5534889fb", argdata, 3, 6, &func);
}

FUNC_NAKED void AugmentStoreBox::constructor(ShipManager *ship, const AugmentBlueprint *bp)
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
			// rdi has this
			// rsi has ship
			// rdx has bp
	);
	__asm__("call *%0\n\t" :: "m"(_func55::func));
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

namespace _func56
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("BatteryBox::constructor", typeid(void (BatteryBox::*)(Point , BatterySystem *)), "5531c94889d5534889fb4883ec58", argdata, 3, 6, &func);
}

FUNC_NAKED void BatteryBox::constructor(Point pos, BatterySystem *sys)
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
			// rdi has this
			// rsi has pos
			// rdx has sys
	);
	__asm__("call *%0\n\t" :: "m"(_func56::func));
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

namespace _func57
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x109, 0x1ff, 0x1ff, 0x10a};
	static FunctionDefinition funcObj("BeamWeapon::constructor", typeid(void (BeamWeapon::*)(Pointf , int , int , Pointf , Pointf , int , Targetable *, float )), "41564189ce41554154554c89c5534889fb4883ec10", argdata, 9, 6, &func);
}

FUNC_NAKED void BeamWeapon::constructor(Pointf _position, int _ownerId, int _targetId, Pointf _target, Pointf _target2, int _length, Targetable *_targetable, float heading)
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
		"pushl 16(%rbp)\n\t"		// _targetable
		"pushl 8(%rbp)\n\t"		// _length
			// rdi has this
			// rsi has _position
			// rdx has _ownerId
			// rcx has _targetId
			// r8 has _target
			// r9 has _target2
			// xmm0 has heading
	);
	__asm__("call *%0\n\t" :: "m"(_func57::func));
	__asm__
	(
		"addl $16, %rsp\n\t"
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

namespace _func58
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("BeamWeapon::CollisionCheck", typeid(void (BeamWeapon::*)(Collideable *)), ".4157415641554989fd415455534881ecb8010000", argdata, 2, 6, &func);
}

FUNC_NAKED void BeamWeapon::CollisionCheck(Collideable *other)
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
			// rdi has this
			// rsi has other
	);
	__asm__("call *%0\n\t" :: "m"(_func58::func));
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

namespace _func59
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Blueprint::destructor", typeid(void (Blueprint::*)()), "534889fb4883ec10488b476848c707????????488d78e84881ff????????756f", argdata, 1, 6, &func);
}

FUNC_NAKED void Blueprint::destructor()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func59::func));
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

namespace _func60
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Blueprint::GetNameShort", typeid(std::string (Blueprint::*)()), "53807e2800", argdata, 2, 2, &func);
}

FUNC_NAKED std::string Blueprint::GetNameShort()
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
			// rdi has implicit_output
			// rsi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func60::func));
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

namespace _func61
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("BlueprintManager::GetBlueprintList", typeid(std::vector<std::string> (BlueprintManager::*)(const std::string &)), "4157415641554989f54d8dbde8010000", argdata, 3, 2, &func);
}

FUNC_NAKED std::vector<std::string> BlueprintManager::GetBlueprintList(const std::string &name)
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
			// rdi has implicit_output
			// rsi has this
			// rdx has name
	);
	__asm__("call *%0\n\t" :: "m"(_func61::func));
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

namespace _func62
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("BlueprintManager::GetShipBlueprint", typeid(ShipBlueprint *(BlueprintManager::*)(const std::string &, int )), "415641554989f541544989fc5589d5534883ec60", argdata, 3, 2, &func);
}

FUNC_NAKED ShipBlueprint *BlueprintManager::GetShipBlueprint(const std::string &name, int sector)
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
			// rdi has this
			// rsi has name
			// rdx has sector
	);
	__asm__("call *%0\n\t" :: "m"(_func62::func));
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

namespace _func63
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("BlueprintManager::GetWeaponBlueprint", typeid(WeaponBlueprint *(BlueprintManager::*)(const std::string &)), "41554154554889f5be????????534889fb4c8da3e80100004883ec28", argdata, 2, 2, &func);
}

FUNC_NAKED WeaponBlueprint *BlueprintManager::GetWeaponBlueprint(const std::string &name)
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
			// rdi has this
			// rsi has name
	);
	__asm__("call *%0\n\t" :: "m"(_func63::func));
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

namespace _func64
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("BlueprintManager::GetDroneBlueprint", typeid(DroneBlueprint *(BlueprintManager::*)(const std::string &)), ".41554154554889f5be????????534889fb4c8da3e80100004883ec28", argdata, 2, 2, &func);
}

FUNC_NAKED DroneBlueprint *BlueprintManager::GetDroneBlueprint(const std::string &name)
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
			// rdi has this
			// rsi has name
	);
	__asm__("call *%0\n\t" :: "m"(_func64::func));
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

namespace _func65
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("BlueprintManager::GetAugmentBlueprint", typeid(AugmentBlueprint *(BlueprintManager::*)(const std::string &)), ".41554154554889f5be????????534889fb4c8da3e80100004883ec28", argdata, 2, 2, &func);
}

FUNC_NAKED AugmentBlueprint *BlueprintManager::GetAugmentBlueprint(const std::string &name)
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
			// rdi has this
			// rsi has name
	);
	__asm__("call *%0\n\t" :: "m"(_func65::func));
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

namespace _func66
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("BlueprintManager::GetAugmentValue", typeid(float (BlueprintManager::*)(const std::string &)), ".4157488d8798000000", argdata, 2, 2, &func);
}

FUNC_NAKED float BlueprintManager::GetAugmentValue(const std::string &name)
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
			// rdi has this
			// rsi has name
	);
	__asm__("call *%0\n\t" :: "m"(_func66::func));
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

namespace _func67
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("BlueprintManager::GetItemBlueprint", typeid(ItemBlueprint *(BlueprintManager::*)(const std::string &)), "4157488d8f90010000", argdata, 2, 2, &func);
}

FUNC_NAKED ItemBlueprint *BlueprintManager::GetItemBlueprint(const std::string &name)
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
			// rdi has this
			// rsi has name
	);
	__asm__("call *%0\n\t" :: "m"(_func67::func));
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

namespace _func68
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("BlueprintManager::ProcessWeaponBlueprint", typeid(WeaponBlueprint (BlueprintManager::*)(rapidxml::xml_node<char> *)), "41574156415541544989f4554889d5534889fb4881ecb8000000", argdata, 3, 2, &func);
}

FUNC_NAKED WeaponBlueprint BlueprintManager::ProcessWeaponBlueprint(rapidxml::xml_node<char> *node)
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
			// rdi has implicit_output
			// rsi has this
			// rdx has node
	);
	__asm__("call *%0\n\t" :: "m"(_func68::func));
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

namespace _func69
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("BlueprintManager::ProcessDescription", typeid(Description (BlueprintManager::*)(rapidxml::xml_node<char> *)), "4157be????????415641554154554889fd4c8d6d10", argdata, 3, 2, &func);
}

FUNC_NAKED Description BlueprintManager::ProcessDescription(rapidxml::xml_node<char> *node)
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
			// rdi has implicit_output
			// rsi has this
			// rdx has node
	);
	__asm__("call *%0\n\t" :: "m"(_func69::func));
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

namespace _func70
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("BlueprintManager::ProcessEffectsBlueprint", typeid(EffectsBlueprint (BlueprintManager::*)(rapidxml::xml_node<char> *)), "4157415641554989f5be", argdata, 3, 2, &func);
}

FUNC_NAKED EffectsBlueprint BlueprintManager::ProcessEffectsBlueprint(rapidxml::xml_node<char> *node)
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
			// rdi has implicit_output
			// rsi has this
			// rdx has node
	);
	__asm__("call *%0\n\t" :: "m"(_func70::func));
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

namespace _func71
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("BlueprintManager::GetCrewBlueprint", typeid(CrewBlueprint (BlueprintManager::*)(const std::string &)), "41574156415541544989f44d8dac24c8000000", argdata, 3, 2, &func);
}

FUNC_NAKED CrewBlueprint BlueprintManager::GetCrewBlueprint(const std::string &name)
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
			// rdi has implicit_output
			// rsi has this
			// rdx has name
	);
	__asm__("call *%0\n\t" :: "m"(_func71::func));
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

namespace _func72
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("BlueprintManager::GetRandomAugment", typeid(std::vector<AugmentBlueprint*> (BlueprintManager::*)(int , bool )), "488d869800000053", argdata, 4, 2, &func);
}

FUNC_NAKED std::vector<AugmentBlueprint*> BlueprintManager::GetRandomAugment(int count, bool demo_lock)
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
			// rdi has implicit_output
			// rsi has this
			// rdx has count
			// rcx has demo_lock
	);
	__asm__("call *%0\n\t" :: "m"(_func72::func));
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

namespace _func73
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("BlueprintManager::GetSystemBlueprint", typeid(SystemBlueprint *(BlueprintManager::*)(const std::string &)), "4157488d8fc0010000", argdata, 2, 2, &func);
}

FUNC_NAKED SystemBlueprint *BlueprintManager::GetSystemBlueprint(const std::string &name)
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
			// rdi has this
			// rsi has name
	);
	__asm__("call *%0\n\t" :: "m"(_func73::func));
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

namespace _func74
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("BlueprintManager::GetUnusedCrewName", typeid(std::string (BlueprintManager::*)(bool *)), "415741564155415455534883ec5848c707", argdata, 3, 2, &func);
}

FUNC_NAKED std::string BlueprintManager::GetUnusedCrewName(bool *isMale_ret)
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
			// rdi has implicit_output
			// rsi has this
			// rdx has isMale_ret
	);
	__asm__("call *%0\n\t" :: "m"(_func74::func));
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

namespace _func75
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("BlueprintManager::GetCrewName", typeid(std::string (BlueprintManager::*)(bool *)), "415741564c8db6f800000041554989d541544989fc55534889f3", argdata, 3, 2, &func);
}

FUNC_NAKED std::string BlueprintManager::GetCrewName(bool *isMale_ret)
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
			// rdi has implicit_output
			// rsi has this
			// rdx has isMale_ret
	);
	__asm__("call *%0\n\t" :: "m"(_func75::func));
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

namespace _func76
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("BlueprintManager::GetRandomWeapon", typeid(std::vector<WeaponBlueprint*> (BlueprintManager::*)(int , bool )), "488d463853440fb6c1", argdata, 4, 2, &func);
}

FUNC_NAKED std::vector<WeaponBlueprint*> BlueprintManager::GetRandomWeapon(int count, bool demo_lock)
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
			// rdi has implicit_output
			// rsi has this
			// rdx has count
			// rcx has demo_lock
	);
	__asm__("call *%0\n\t" :: "m"(_func76::func));
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

namespace _func77
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("BlueprintManager::GetRandomDrone", typeid(std::vector<DroneBlueprint*> (BlueprintManager::*)(int , bool )), "488d466853440fb6c1", argdata, 4, 2, &func);
}

FUNC_NAKED std::vector<DroneBlueprint*> BlueprintManager::GetRandomDrone(int count, bool demo_lock)
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
			// rdi has implicit_output
			// rsi has this
			// rdx has count
			// rcx has demo_lock
	);
	__asm__("call *%0\n\t" :: "m"(_func77::func));
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

namespace _func78
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("BlueprintManager::ProcessShipBlueprint", typeid(ShipBlueprint (BlueprintManager::*)(rapidxml::xml_node<char> *)), "415741564989d641554989f5415455534889fb4881ecc8000000", argdata, 3, 2, &func);
}

FUNC_NAKED ShipBlueprint BlueprintManager::ProcessShipBlueprint(rapidxml::xml_node<char> *node)
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
			// rdi has implicit_output
			// rsi has this
			// rdx has node
	);
	__asm__("call *%0\n\t" :: "m"(_func78::func));
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

namespace _func79
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("BlueprintManager::ProcessDroneBlueprint", typeid(DroneBlueprint (BlueprintManager::*)(rapidxml::xml_node<char> *)), "415741564989f641554989d54154554889fd534881ec98000000", argdata, 3, 2, &func);
}

FUNC_NAKED DroneBlueprint BlueprintManager::ProcessDroneBlueprint(rapidxml::xml_node<char> *node)
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
			// rdi has implicit_output
			// rsi has this
			// rdx has node
	);
	__asm__("call *%0\n\t" :: "m"(_func79::func));
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

BlueprintManager *Global_BlueprintManager_Blueprints;

namespace _var80
{
	static VariableDefinition varObj("Global_BlueprintManager_Blueprints", "!488d742410baffffffffbf(???????\?)4c8d742430", &Global_BlueprintManager_Blueprints);
}

namespace _func81
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("BoarderPodDrone::constructor", typeid(void (BoarderPodDrone::*)(int , int , const DroneBlueprint &)), "41574989ff415641554989cd415455498dafa8030000", argdata, 4, 6, &func);
}

FUNC_NAKED void BoarderPodDrone::constructor(int _iShipId, int _selfId, const DroneBlueprint &_bp)
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
			// rdi has this
			// rsi has _iShipId
			// rdx has _selfId
			// rcx has _bp
	);
	__asm__("call *%0\n\t" :: "m"(_func81::func));
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

namespace _func82
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("BoarderPodDrone::SetMovementTarget", typeid(void (BoarderPodDrone::*)(Targetable &)), "534889fb4883ec104885f6", argdata, 2, 6, &func);
}

FUNC_NAKED void BoarderPodDrone::SetMovementTarget(Targetable &target)
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
			// rdi has this
			// rsi has target
	);
	__asm__("call *%0\n\t" :: "m"(_func82::func));
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

namespace _func83
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("BoarderPodDrone::CanBeDeployed", typeid(bool (BoarderPodDrone::*)()), ".534889fb488bbf58010000", argdata, 1, 2, &func);
}

FUNC_NAKED bool BoarderPodDrone::CanBeDeployed()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func83::func));
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

namespace _func84
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("BoarderPodDrone::SetDeployed", typeid(void (BoarderPodDrone::*)(bool )), "5589f5534889fb4883ec08807f1800742f", argdata, 2, 6, &func);
}

FUNC_NAKED void BoarderPodDrone::SetDeployed(bool _deployed)
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
			// rdi has this
			// rsi has _deployed
	);
	__asm__("call *%0\n\t" :: "m"(_func84::func));
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

namespace _func85
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("BombProjectile::constructor", typeid(void (BombProjectile::*)(Pointf , int , int , Pointf )), "41574989ff41564155415455534881ece8000000", argdata, 5, 6, &func);
}

FUNC_NAKED void BombProjectile::constructor(Pointf _position, int _ownerId, int _targetId, Pointf _target)
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
			// rdi has this
			// rsi has _position
			// rdx has _ownerId
			// rcx has _targetId
			// r8 has _target
	);
	__asm__("call *%0\n\t" :: "m"(_func85::func));
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

namespace _func86
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("BombProjectile::CollisionCheck", typeid(void (BombProjectile::*)(Collideable *)), "41554154554889f5534889fb4889f74883ec78", argdata, 2, 6, &func);
}

FUNC_NAKED void BombProjectile::CollisionCheck(Collideable *other)
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
			// rdi has this
			// rsi has other
	);
	__asm__("call *%0\n\t" :: "m"(_func86::func));
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

namespace _func87
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("BossShip::Restart", typeid(void (BossShip::*)()), "c7871402000000000000c7874c02000001000000", argdata, 1, 6, &func);
}

FUNC_NAKED void BossShip::Restart()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func87::func));
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

namespace _func88
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("BossShip::IncomingFire", typeid(bool (BossShip::*)()), ".f30f108724020000", argdata, 1, 2, &func);
}

FUNC_NAKED bool BossShip::IncomingFire()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func88::func));
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

namespace _func89
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("BossShip::constructor", typeid(void (BossShip::*)(SpaceManager *)), ".53b9010000004889fb31d24883c330", argdata, 2, 6, &func);
}

FUNC_NAKED void BossShip::constructor(SpaceManager *space)
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
			// rdi has this
			// rsi has space
	);
	__asm__("call *%0\n\t" :: "m"(_func89::func));
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

namespace _func90
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("BossShip::ClearLocation", typeid(void (BossShip::*)()), ".534889fb488b7f104885ff740e", argdata, 1, 6, &func);
}

FUNC_NAKED void BossShip::ClearLocation()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func90::func));
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

namespace _func91
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("BossShip::Defeated", typeid(bool (BossShip::*)()), ".31c083bf1402000003", argdata, 1, 2, &func);
}

FUNC_NAKED bool BossShip::Defeated()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func91::func));
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

namespace _func92
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("BossShip::GetSubEvent", typeid(LocationEvent *(BossShip::*)()), ".415455534889fb4883ec30", argdata, 1, 2, &func);
}

FUNC_NAKED LocationEvent *BossShip::GetSubEvent()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func92::func));
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

namespace _func93
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("BossShip::StartStage", typeid(void (BossShip::*)()), ".415741564155415455534889fb488d7f304881ecd8010000", argdata, 1, 6, &func);
}

FUNC_NAKED void BossShip::StartStage()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func93::func));
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

namespace _func94
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("BossShip::SaveBoss", typeid(void (BossShip::*)(int )), ".41544189f4554889fd538bb714020000", argdata, 2, 6, &func);
}

FUNC_NAKED void BossShip::SaveBoss(int file)
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
			// rdi has this
			// rsi has file
	);
	__asm__("call *%0\n\t" :: "m"(_func94::func));
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

namespace _func95
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("BossShip::GetEvent", typeid(LocationEvent *(BossShip::*)()), ".4883ec48488db74c020000", argdata, 1, 2, &func);
}

FUNC_NAKED LocationEvent *BossShip::GetEvent()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func95::func));
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

namespace _func96
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("BossShip::LoadBoss", typeid(void (BossShip::*)(int )), ".4156415541544189f455534889fb89f74883ec10", argdata, 2, 6, &func);
}

FUNC_NAKED void BossShip::LoadBoss(int file)
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
			// rdi has this
			// rsi has file
	);
	__asm__("call *%0\n\t" :: "m"(_func96::func));
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

namespace _func97
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("BossShip::OnLoop", typeid(void (BossShip::*)()), ".4155415455534889fb4883ec28c687d401000001", argdata, 1, 6, &func);
}

FUNC_NAKED void BossShip::OnLoop()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func97::func));
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

namespace _func98
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Button::SetLocation", typeid(void (Button::*)(const Point )), "8b57084889f08b4f0c48c1f82039f2", argdata, 2, 6, &func);
}

FUNC_NAKED void Button::SetLocation(const Point pos)
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
			// rdi has this
			// rsi has pos
	);
	__asm__("call *%0\n\t" :: "m"(_func98::func));
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

namespace _func99
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("Button::OnInit", typeid(void (Button::*)(const std::string &, Point )), "41544989f4554889d5534889fb4883ec20488d7c2410", argdata, 3, 6, &func);
}

FUNC_NAKED void Button::OnInit(const std::string &img, Point pos)
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
			// rdi has this
			// rsi has img
			// rdx has pos
	);
	__asm__("call *%0\n\t" :: "m"(_func99::func));
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

namespace _func100
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Button::constructor", typeid(void (Button::*)()), "55534889fb488d7f08488d6b284883ec18", argdata, 1, 6, &func);
}

FUNC_NAKED void Button::constructor()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func100::func));
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

namespace _func101
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Button::OnRender", typeid(void (Button::*)()), "415455534889fb4883ec2048837f6800", argdata, 1, 6, &func);
}

FUNC_NAKED void Button::OnRender()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func101::func));
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

namespace _func102
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Button::SetInactiveImage", typeid(void (Button::*)(GL_Texture *)), "483977507412488b07", argdata, 2, 6, &func);
}

FUNC_NAKED void Button::SetInactiveImage(GL_Texture *texture)
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
			// rdi has this
			// rsi has texture
	);
	__asm__("call *%0\n\t" :: "m"(_func102::func));
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

namespace _func103
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Button::SetActiveImage", typeid(void (Button::*)(GL_Texture *)), "483977587412488b07", argdata, 2, 6, &func);
}

FUNC_NAKED void Button::SetActiveImage(GL_Texture *texture)
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
			// rdi has this
			// rsi has texture
	);
	__asm__("call *%0\n\t" :: "m"(_func103::func));
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

namespace _func104
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Button::SetImageBase", typeid(void (Button::*)(const std::string &)), "554889f5534889fb4883ec28488d7c2410", argdata, 2, 6, &func);
}

FUNC_NAKED void Button::SetImageBase(const std::string &imageBase)
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
			// rdi has this
			// rsi has imageBase
	);
	__asm__("call *%0\n\t" :: "m"(_func104::func));
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

namespace _func105
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CAchievement::OnRender", typeid(void (CAchievement::*)(Point , int , bool )), "415741564189ce415541544989f45589d5534889fb4883ec78", argdata, 4, 6, &func);
}

FUNC_NAKED void CAchievement::OnRender(Point pos, int selected, bool showNew)
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
			// rdi has this
			// rsi has pos
			// rdx has selected
			// rcx has showNew
	);
	__asm__("call *%0\n\t" :: "m"(_func105::func));
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

namespace _func106
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CAchievement::constructor", typeid(void (CAchievement::*)()), "53be????????4889fb4883ec20", argdata, 1, 6, &func);
}

FUNC_NAKED void CAchievement::constructor()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func106::func));
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

namespace _func107
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CEvent::OnEvent", typeid(void (CEvent::*)(const InputEvent *)), "415741564155415455534889f34883ec288b4604", argdata, 2, 6, &func);
}

FUNC_NAKED void CEvent::OnEvent(const InputEvent *event)
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
			// rdi has this
			// rsi has event
	);
	__asm__("call *%0\n\t" :: "m"(_func107::func));
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

namespace _func108
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CFPS::GetSpeedFactor", typeid(float (CFPS::*)()), "f30f104718c3", argdata, 1, 2, &func);
}

FUNC_NAKED float CFPS::GetSpeedFactor()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func108::func));
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

namespace _func109
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CFPS::OnLoop", typeid(void (CFPS::*)()), "534889fb4883ec10f20f1015", argdata, 1, 6, &func);
}

FUNC_NAKED void CFPS::OnLoop()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func109::func));
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

CFPS *Global_CFPS_FPSControl;

namespace _var110
{
	static VariableDefinition varObj("Global_CFPS_FPSControl", "!0f28d90f28d0bf(???????\?)f30fc2d1050f54da0f55d00f28ca0f56cb", &Global_CFPS_FPSControl);
}

namespace _func111
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CachedImage::destructor", typeid(void (CachedImage::*)()), "534889fb4883ec10488b471048c707????????488d78e84881ff????????750e", argdata, 1, 6, &func);
}

FUNC_NAKED void CachedImage::destructor()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func111::func));
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

namespace _func112
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CachedImage::SetImagePath", typeid(void (CachedImage::*)(const std::string &)), "55534889fbbf????????4883ec08e8????????483b4318", argdata, 2, 6, &func);
}

FUNC_NAKED void CachedImage::SetImagePath(const std::string &imagePath)
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
			// rdi has this
			// rsi has imagePath
	);
	__asm__("call *%0\n\t" :: "m"(_func112::func));
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

namespace _func113
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CachedImage::SetPosition", typeid(void (CachedImage::*)(int , int )), ".41544189d45589f553397720", argdata, 3, 6, &func);
}

FUNC_NAKED void CachedImage::SetPosition(int x, int y)
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
			// rdi has this
			// rsi has x
			// rdx has y
	);
	__asm__("call *%0\n\t" :: "m"(_func113::func));
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

namespace _func114
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CachedImage::constructor1", typeid(void (CachedImage::*)(const std::string &, int , int )), "41544189cc5589d5534889fb48c7470800000000", argdata, 4, 6, &func);
}

FUNC_NAKED void CachedImage::constructor1(const std::string &path, int x, int y)
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
			// rdi has this
			// rsi has path
			// rdx has x
			// rcx has y
	);
	__asm__("call *%0\n\t" :: "m"(_func114::func));
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

namespace _func115
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CachedImage::constructor_copy", typeid(void (CachedImage::*)(const CachedImage &)), "554889f5488d7610534889fb488d7f104883ec0848c747f800000000", argdata, 2, 6, &func);
}

FUNC_NAKED void CachedImage::constructor_copy(const CachedImage &other)
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
			// rdi has this
			// rsi has other
	);
	__asm__("call *%0\n\t" :: "m"(_func115::func));
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

namespace _func116
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("CachedImage::SetRotation", typeid(void (CachedImage::*)(float )), "534889fb4883ec100f2e4740", argdata, 2, 6, &func);
}

FUNC_NAKED void CachedImage::SetRotation(float _rotation)
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
			// rdi has this
			// xmm0 has _rotation
	);
	__asm__("call *%0\n\t" :: "m"(_func116::func));
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

namespace _func117
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CachedImage::SetMirrored", typeid(void (CachedImage::*)(bool )), ".5589f5534889fb4883ec0840387744", argdata, 2, 6, &func);
}

FUNC_NAKED void CachedImage::SetMirrored(bool _mirrored)
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
			// rdi has this
			// rsi has _mirrored
	);
	__asm__("call *%0\n\t" :: "m"(_func117::func));
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

namespace _func118
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CachedImage::CreatePrimitive", typeid(void (CachedImage::*)()), "415455534889fb4883ec50488b6f184885ed", argdata, 1, 6, &func);
}

FUNC_NAKED void CachedImage::CreatePrimitive()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func118::func));
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

namespace _func119
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CachedPrimitive::OnRender", typeid(void (CachedPrimitive::*)(const GL_Color &)), "534889fb4883ec20488b7f084885ff", argdata, 2, 6, &func);
}

FUNC_NAKED void CachedPrimitive::OnRender(const GL_Color &color)
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
			// rdi has this
			// rsi has color
	);
	__asm__("call *%0\n\t" :: "m"(_func119::func));
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

namespace _func120
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CachedPrimitive::destructor", typeid(void (CachedPrimitive::*)()), "48c707????????488b7f08e9", argdata, 1, 6, &func);
}

FUNC_NAKED void CachedPrimitive::destructor()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func120::func));
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

namespace _func121
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ChoiceBox::OnRender", typeid(void (ChoiceBox::*)()), "41574989ff41564155415455534881ec68020000", argdata, 1, 6, &func);
}

FUNC_NAKED void ChoiceBox::OnRender()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func121::func));
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

namespace _func122
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ChoiceBox::MouseMove", typeid(void (ChoiceBox::*)(int , int )), "41554189d541544989fcbf", argdata, 3, 6, &func);
}

FUNC_NAKED void ChoiceBox::MouseMove(int x, int y)
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
			// rdi has this
			// rsi has x
			// rdx has y
	);
	__asm__("call *%0\n\t" :: "m"(_func122::func));
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

namespace _func123
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CloakingBox::constructor", typeid(void (CloakingBox::*)(Point , CloakingSystem *)), "415431c9554889d5534889fb4883ec50", argdata, 3, 6, &func);
}

FUNC_NAKED void CloakingBox::constructor(Point pos, CloakingSystem *sys)
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
			// rdi has this
			// rsi has pos
			// rdx has sys
	);
	__asm__("call *%0\n\t" :: "m"(_func123::func));
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

namespace _func124
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CloakingSystem::OnLoop", typeid(void (CloakingSystem::*)()), "55534889fb4883ec08e8????????488dbb68020000", argdata, 1, 6, &func);
}

FUNC_NAKED void CloakingSystem::OnLoop()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func124::func));
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

namespace _func125
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CloakingSystem::FiredWeapon", typeid(void (CloakingSystem::*)()), "534889fbbe????????4883ec30488d54241e", argdata, 1, 6, &func);
}

FUNC_NAKED void CloakingSystem::FiredWeapon()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func125::func));
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

namespace _func126
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CloneBox::constructor", typeid(void (CloneBox::*)(Point , CloneSystem *)), "415731c94156415541544531e4554889d5534889fb4881ec08020000", argdata, 3, 6, &func);
}

FUNC_NAKED void CloneBox::constructor(Point pos, CloneSystem *sys)
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
			// rdi has this
			// rsi has pos
			// rdx has sys
	);
	__asm__("call *%0\n\t" :: "m"(_func126::func));
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

namespace _func127
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CloneSystem::OnLoop", typeid(void (CloneSystem::*)()), "415741564155415455534889fb4881ec88010000", argdata, 1, 6, &func);
}

FUNC_NAKED void CloneSystem::OnLoop()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func127::func));
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

namespace _func128
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CombatAI::UpdateMindControl", typeid(void (CombatAI::*)(bool )), "41554154554889fd534883ec48488b4760488b58604885db", argdata, 2, 6, &func);
}

FUNC_NAKED void CombatAI::UpdateMindControl(bool unk)
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
			// rdi has this
			// rsi has unk
	);
	__asm__("call *%0\n\t" :: "m"(_func128::func));
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

namespace _func129
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CombatAI::OnLoop", typeid(void (CombatAI::*)()), "4154554889fd53e8????????488b7d60", argdata, 1, 6, &func);
}

FUNC_NAKED void CombatAI::OnLoop()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func129::func));
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

namespace _func130
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CombatDrone::constructor", typeid(void (CombatDrone::*)(int , int , const DroneBlueprint *)), "41554154554889cd4c8da5a0000000534889fb4883ec38", argdata, 4, 6, &func);
}

FUNC_NAKED void CombatDrone::constructor(int iShipId, int selfId, const DroneBlueprint *bp)
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
			// rdi has this
			// rsi has iShipId
			// rdx has selfId
			// rcx has bp
	);
	__asm__("call *%0\n\t" :: "m"(_func130::func));
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

namespace _func131
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CombatDrone::SetWeaponTarget", typeid(void (CombatDrone::*)(Targetable &)), "554889f5534889fb4883ec084885f6743f", argdata, 2, 6, &func);
}

FUNC_NAKED void CombatDrone::SetWeaponTarget(Targetable &target)
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
			// rdi has this
			// rsi has target
	);
	__asm__("call *%0\n\t" :: "m"(_func131::func));
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

namespace _func132
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ControlButton::OnRender", typeid(void (ControlButton::*)()), "415455534889fb4883ec608b4730", argdata, 1, 6, &func);
}

FUNC_NAKED void ControlButton::OnRender()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func132::func));
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

namespace _func133
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ControlsScreen::OnInit", typeid(void (ControlsScreen::*)()), "41574156415541544989fc55534881ece80000004883bf3006000000", argdata, 1, 6, &func);
}

FUNC_NAKED void ControlsScreen::OnInit()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func133::func));
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

namespace _func134
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ControlsScreen::OnLoop", typeid(void (ControlsScreen::*)()), "41564155415449bcb76ddbb66ddbb66d554889fd534883ec4048638728060000", argdata, 1, 6, &func);
}

FUNC_NAKED void ControlsScreen::OnLoop()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func134::func));
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

namespace _func135
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ControlsScreen::OnRender", typeid(void (ControlsScreen::*)()), "415741564155415455534889fb4881ec1802000080bf7001000000", argdata, 1, 6, &func);
}

FUNC_NAKED void ControlsScreen::OnRender()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func135::func));
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

namespace _func136
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CooldownSystemBox::constructor", typeid(void (CooldownSystemBox::*)(Point , ShipSystem *, bool )), "4157415641554989fd41545589cdb901000000534889f34881ece8010000", argdata, 4, 6, &func);
}

FUNC_NAKED void CooldownSystemBox::constructor(Point pos, ShipSystem *sys, bool roundDown)
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
			// rdi has this
			// rsi has pos
			// rdx has sys
			// rcx has roundDown
	);
	__asm__("call *%0\n\t" :: "m"(_func136::func));
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

namespace _func137
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CooldownSystemBox::OnRender", typeid(void (CooldownSystemBox::*)(bool )), "4154400fb6f655534889fb4883ec50", argdata, 2, 6, &func);
}

FUNC_NAKED void CooldownSystemBox::OnRender(bool ignoreStatus)
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
			// rdi has this
			// rsi has ignoreStatus
	);
	__asm__("call *%0\n\t" :: "m"(_func137::func));
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

namespace _func138
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CreditScreen::OnRender", typeid(void (CreditScreen::*)()), "415641554154554889fd534883ec60", argdata, 1, 6, &func);
}

FUNC_NAKED void CreditScreen::OnRender()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func138::func));
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

namespace _func139
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CreditScreen::constructor", typeid(void (CreditScreen::*)()), "48c74708????????48c74710????????c747180000000048c7472800000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CreditScreen::constructor()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func139::func));
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

namespace _func140
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CreditScreen::Start", typeid(void (CreditScreen::*)(const std::string &, const std::vector<std::string> &)), "4157415641554154554889d5534889fb4881ecd8010000", argdata, 3, 6, &func);
}

FUNC_NAKED void CreditScreen::Start(const std::string &shipName, const std::vector<std::string> &crewNames)
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
			// rdi has this
			// rsi has shipName
			// rdx has crewNames
	);
	__asm__("call *%0\n\t" :: "m"(_func140::func));
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

namespace _func141
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CreditScreen::Done", typeid(bool (CreditScreen::*)()), "488b4730482b472848baabaaaaaaaaaaaaaa", argdata, 1, 2, &func);
}

FUNC_NAKED bool CreditScreen::Done()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func141::func));
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

namespace _func142
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewCustomizeBox::CheckContents", typeid(void (CrewCustomizeBox::*)()), "534889fb4883ec2080bf6807000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewCustomizeBox::CheckContents()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func142::func));
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

namespace _func143
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewStoreBox::Purchase", typeid(void (CrewStoreBox::*)()), "415741564531f641554989fd4154555331db4881ec18010000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewStoreBox::Purchase()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func143::func));
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

namespace _func144
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CrewStoreBox::constructor", typeid(void (CrewStoreBox::*)(ShipManager *, int , const std::string &)), "41574989ff415641554154554889f5", argdata, 4, 6, &func);
}

FUNC_NAKED void CrewStoreBox::constructor(ShipManager *ship, int worldLevel, const std::string &type)
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
			// rdi has this
			// rsi has ship
			// rdx has worldLevel
			// rcx has type
	);
	__asm__("call *%0\n\t" :: "m"(_func144::func));
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

namespace _func145
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x106, 0x102};
	static FunctionDefinition funcObj("DamageMessage::constructor", typeid(void (DamageMessage::*)(float , Pointf , DamageMessage::MessageType )), "534889fb4883ec5085f648c707", argdata, 4, 6, &func);
}

FUNC_NAKED void DamageMessage::constructor(float length, Pointf pos, DamageMessage::MessageType type)
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
			// rdi has this
			// xmm0 has length
			// rsi has pos
			// rdx has type
	);
	__asm__("call *%0\n\t" :: "m"(_func145::func));
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

namespace _func146
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("DamageMessage::constructor2", typeid(void (DamageMessage::*)(float , int , Pointf , bool )), "415741564155415455534889fb4881ec3803000084d2", argdata, 5, 6, &func);
}

FUNC_NAKED void DamageMessage::constructor2(float length, int amount, Pointf pos, bool unk)
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
			// rdi has this
			// xmm0 has length
			// rsi has amount
			// rdx has pos
			// rcx has unk
	);
	__asm__("call *%0\n\t" :: "m"(_func146::func));
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

namespace _func147
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("DefenseDrone::ValidTargetObject", typeid(bool (DefenseDrone::*)(Targetable &)), "4885f60f84b7000000", argdata, 2, 2, &func);
}

FUNC_NAKED bool DefenseDrone::ValidTargetObject(Targetable &target)
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
			// rdi has this
			// rsi has target
	);
	__asm__("call *%0\n\t" :: "m"(_func147::func));
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

namespace _func148
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("DefenseDrone::PickTarget", typeid(void (DefenseDrone::*)()), "55534889fb4883ec4880bf5d02000000", argdata, 1, 6, &func);
}

FUNC_NAKED void DefenseDrone::PickTarget()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func148::func));
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

namespace _func149
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("DefenseDrone::SetWeaponTarget", typeid(void (DefenseDrone::*)(Targetable &)), "4154554889fd53488b074889f3", argdata, 2, 6, &func);
}

FUNC_NAKED void DefenseDrone::SetWeaponTarget(Targetable &target)
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
			// rdi has this
			// rsi has target
	);
	__asm__("call *%0\n\t" :: "m"(_func149::func));
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

namespace _func150
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("DefenseDrone::GetTooltip", typeid(std::string (DefenseDrone::*)()), "554889f5be????????534889fb4883ec38488d542420", argdata, 2, 2, &func);
}

FUNC_NAKED std::string DefenseDrone::GetTooltip()
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
			// rdi has implicit_output
			// rsi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func150::func));
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

namespace _func151
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Door::FakeClose", typeid(void (Door::*)()), "55534889fb4883ec080fb64724c6472c00", argdata, 1, 6, &func);
}

FUNC_NAKED void Door::FakeClose()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func151::func));
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

namespace _func152
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Door::IsSealed", typeid(bool (Door::*)(int )), "8b8f4c0200008b570885c9", argdata, 2, 2, &func);
}

FUNC_NAKED bool Door::IsSealed(int shipId)
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
			// rdi has this
			// rsi has shipId
	);
	__asm__("call *%0\n\t" :: "m"(_func152::func));
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

namespace _func153
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Door::FakeOpen", typeid(void (Door::*)()), "55534889fb4883ec0883bfb400000004c6472c01", argdata, 1, 6, &func);
}

FUNC_NAKED void Door::FakeOpen()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func153::func));
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

namespace _func154
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Door::OnLoop", typeid(void (Door::*)()), "55534889fb4883ec188b874c02000085c0", argdata, 1, 6, &func);
}

FUNC_NAKED void Door::OnLoop()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func154::func));
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

namespace _func155
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("DoorBox::constructor", typeid(void (DoorBox::*)(Point , ShipSystem *, ShipManager *)), "41554989cdb901000000415455534889fb488dab700200004c8da3000300004883ec48", argdata, 4, 6, &func);
}

FUNC_NAKED void DoorBox::constructor(Point pos, ShipSystem *sys, ShipManager *ship)
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
			// rdi has this
			// rsi has pos
			// rdx has sys
			// rcx has ship
	);
	__asm__("call *%0\n\t" :: "m"(_func155::func));
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

namespace _func156
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("DroneBlueprint::RenderIcon", typeid(void (DroneBlueprint::*)(float )), "4156415541544989fc55534881ec20010000", argdata, 2, 6, &func);
}

FUNC_NAKED void DroneBlueprint::RenderIcon(float scale)
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
			// rdi has this
			// xmm0 has scale
	);
	__asm__("call *%0\n\t" :: "m"(_func156::func));
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

namespace _func157
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("DroneStoreBox::constructor", typeid(void (DroneStoreBox::*)(ShipManager *, Equipment *, const DroneBlueprint *)), "41554989d541544989f4be", argdata, 4, 6, &func);
}

FUNC_NAKED void DroneStoreBox::constructor(ShipManager *ship, Equipment *equip, const DroneBlueprint *bp)
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
			// rdi has this
			// rsi has ship
			// rdx has equip
			// rcx has bp
	);
	__asm__("call *%0\n\t" :: "m"(_func157::func));
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

namespace _func158
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("DroneSystem::RemoveDrone", typeid(void (DroneSystem::*)(int )), "31c085f60f888e00000041545553488b8f48020000", argdata, 2, 6, &func);
}

FUNC_NAKED void DroneSystem::RemoveDrone(int slot)
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
			// rdi has this
			// rsi has slot
	);
	__asm__("call *%0\n\t" :: "m"(_func158::func));
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

namespace _func159
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("DroneSystem::UpdateBonusPower", typeid(void (DroneSystem::*)()), "415741564531f6415541545531ed534889fb4883ec18488b9748020000", argdata, 1, 6, &func);
}

FUNC_NAKED void DroneSystem::UpdateBonusPower()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func159::func));
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

namespace _func160
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("DroneSystem::OnLoop", typeid(void (DroneSystem::*)()), ".41574989ff41564155415455534883ec38", argdata, 1, 6, &func);
}

FUNC_NAKED void DroneSystem::OnLoop()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func160::func));
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

namespace _func161
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("DroneSystem::SetBonusPower", typeid(void (DroneSystem::*)(int , int )), ".5589f5534889fb4883ec08", argdata, 3, 6, &func);
}

FUNC_NAKED void DroneSystem::SetBonusPower(int amount, int permanentPower)
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
			// rdi has this
			// rsi has amount
			// rdx has permanentPower
	);
	__asm__("call *%0\n\t" :: "m"(_func161::func));
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

namespace _func162
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("DroneSystem::DePowerDrone", typeid(bool (DroneSystem::*)(Drone *, bool )), "415484d24989f4554889fd53", argdata, 3, 2, &func);
}

FUNC_NAKED bool DroneSystem::DePowerDrone(Drone *drone, bool unk)
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
			// rdi has this
			// rsi has drone
			// rdx has unk
	);
	__asm__("call *%0\n\t" :: "m"(_func162::func));
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

namespace _func163
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("DropBox::OnRender", typeid(void (DropBox::*)()), "415741564155415455534889fb4883ec78e8", argdata, 1, 6, &func);
}

FUNC_NAKED void DropBox::OnRender()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func163::func));
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

namespace _func164
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("DropBox::GetHeight", typeid(int (DropBox::*)()), "488b57104889d04885c0", argdata, 1, 2, &func);
}

FUNC_NAKED int DropBox::GetHeight()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func164::func));
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

namespace _func165
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("EnergyAlien::OnLoop", typeid(void (EnergyAlien::*)()), "534889fbe8????????488b83c000000083786003", argdata, 1, 6, &func);
}

FUNC_NAKED void EnergyAlien::OnLoop()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func165::func));
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

namespace _func166
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("EnergyAlien::GetRoomDamage", typeid(Damage (EnergyAlien::*)()), "80be41070000004889f8", argdata, 2, 2, &func);
}

FUNC_NAKED Damage EnergyAlien::GetRoomDamage()
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
			// rdi has implicit_output
			// rsi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func166::func));
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

namespace _func167
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("EventSystem::AddEvent", typeid(void (EventSystem::*)(int )), "85f6781a488b5718488b4720", argdata, 2, 6, &func);
}

FUNC_NAKED void EventSystem::AddEvent(int id)
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
			// rdi has this
			// rsi has id
	);
	__asm__("call *%0\n\t" :: "m"(_func167::func));
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

namespace _func168
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("EventSystem::PollEvent", typeid(bool (EventSystem::*)(int )), "85f6781c488b0f488b5708", argdata, 2, 2, &func);
}

FUNC_NAKED bool EventSystem::PollEvent(int id)
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
			// rdi has this
			// rsi has id
	);
	__asm__("call *%0\n\t" :: "m"(_func168::func));
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

EventSystem *Global_EventSystem_EventManager;

namespace _var169
{
	static VariableDefinition varObj("Global_EventSystem_EventManager", "!488b7b088b348a3bb7700600007e62be06000000bf(???????\?)", &Global_EventSystem_EventManager);
}

namespace _func170
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("ExplosionAnimation::OnInit", typeid(void (ExplosionAnimation::*)(rapidxml::xml_node<char> *, const std::string &, Point )), "415741564989fe4155415455534889f34881ec380200008b7f28", argdata, 4, 6, &func);
}

FUNC_NAKED void ExplosionAnimation::OnInit(rapidxml::xml_node<char> *node, const std::string &name, Point glowOffset)
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
			// rdi has this
			// rsi has node
			// rdx has name
			// rcx has glowOffset
	);
	__asm__("call *%0\n\t" :: "m"(_func170::func));
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

namespace _func171
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("FTLButton::OnRender", typeid(void (FTLButton::*)()), "4157be0100000041564155415455534889fb4881ecf8000000488bbf10010000", argdata, 1, 6, &func);
}

FUNC_NAKED void FTLButton::OnRender()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func171::func));
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

namespace _func172
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Fire::OnLoop", typeid(void (Fire::*)()), "55534889fb4883ec0880bfd801000000", argdata, 1, 6, &func);
}

FUNC_NAKED void Fire::OnLoop()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func172::func));
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

namespace _func173
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Fire::UpdateDeathTimer", typeid(void (Fire::*)(int )), ".5589f5534889fb4883ec18488b07ff505084c0", argdata, 2, 6, &func);
}

FUNC_NAKED void Fire::UpdateDeathTimer(int connectedFires)
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
			// rdi has this
			// rsi has connectedFires
	);
	__asm__("call *%0\n\t" :: "m"(_func173::func));
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

namespace _func174
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Fire::UpdateStartTimer", typeid(void (Fire::*)(int )), ".5589f5534889fb4883ec18488b07ff505084c0", argdata, 2, 6, &func);
}

FUNC_NAKED void Fire::UpdateStartTimer(int doorLevel)
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
			// rdi has this
			// rsi has doorLevel
	);
	__asm__("call *%0\n\t" :: "m"(_func174::func));
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

namespace _func175
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("FocusWindow::MouseClick", typeid(void (FocusWindow::*)(int , int )), "807f1400750af3c3", argdata, 3, 6, &func);
}

FUNC_NAKED void FocusWindow::MouseClick(int x, int y)
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
			// rdi has this
			// rsi has x
			// rdx has y
	);
	__asm__("call *%0\n\t" :: "m"(_func175::func));
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

namespace _func176
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("GameOver::OpenText", typeid(void (GameOver::*)(const std::string &)), "415741564155415455534889fb488d7f704881ecf8000000", argdata, 2, 6, &func);
}

FUNC_NAKED void GameOver::OpenText(const std::string &text)
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
			// rdi has this
			// rsi has text
	);
	__asm__("call *%0\n\t" :: "m"(_func176::func));
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

namespace _func177
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("GameOver::OnRender", typeid(void (GameOver::*)()), "415741564155415455534889fb4881ec1802000080bfd800000000", argdata, 1, 6, &func);
}

FUNC_NAKED void GameOver::OnRender()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func177::func));
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

namespace _func178
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("GameOver::OnLoop", typeid(void (GameOver::*)()), "4154554889fdbf????????534883ec40", argdata, 1, 6, &func);
}

FUNC_NAKED void GameOver::OnLoop()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func178::func));
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

namespace _func179
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x10a};
	static FunctionDefinition funcObj("Globals::AimAhead", typeid(float (*)(Pointf , Pointf , float )), "4883ec18f30f59d2660fd60424488b1424", argdata, 3, 2, &func);
}

FUNC_NAKED float Globals::AimAhead(Pointf delta, Pointf vr, float muzzleV)
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
			// rdi has delta
			// rsi has vr
			// xmm0 has muzzleV
	);
	__asm__("call *%0\n\t" :: "m"(_func179::func));
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

namespace _func180
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Globals::GetNextSpaceId", typeid(int (*)()), "8b15????????b865000000", argdata, 0, 0, &func);
}

FUNC_NAKED int Globals::GetNextSpaceId()
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
	__asm__("call *%0\n\t" :: "m"(_func180::func));
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

TextLibrary *Global_Globals_Library;

namespace _var181
{
	static VariableDefinition varObj("Global_Globals_Library", "!4189e8488d4c2460ba010000004c89e7be(???????\?)", &Global_Globals_Library);
}

namespace _func182
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("HackBox::constructor", typeid(void (HackBox::*)(Point , HackingSystem *, ShipManager *)), "41554989cd31c94154554889d5534889fb4c8da3180300004883ec68", argdata, 4, 6, &func);
}

FUNC_NAKED void HackBox::constructor(Point pos, HackingSystem *sys, ShipManager *ship)
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
			// rdi has this
			// rsi has pos
			// rdx has sys
			// rcx has ship
	);
	__asm__("call *%0\n\t" :: "m"(_func182::func));
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

namespace _func183
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("HackingDrone::OnLoop", typeid(void (HackingDrone::*)()), "55bd05000000534889fb4883ec48", argdata, 1, 6, &func);
}

FUNC_NAKED void HackingDrone::OnLoop()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func183::func));
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

namespace _func184
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("HackingDrone::SetMovementTarget", typeid(void (HackingDrone::*)(Targetable &)), "554889f5534889fb4883ec184885f60f84b3000000", argdata, 2, 6, &func);
}

FUNC_NAKED void HackingDrone::SetMovementTarget(Targetable &target)
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
			// rdi has this
			// rsi has target
	);
	__asm__("call *%0\n\t" :: "m"(_func184::func));
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

namespace _func185
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("HackingSystem::BlowHackingDrone", typeid(void (HackingSystem::*)()), "80bf60020000007507f3c3", argdata, 1, 6, &func);
}

FUNC_NAKED void HackingSystem::BlowHackingDrone()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func185::func));
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

namespace _func186
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("HackingSystem::OnLoop", typeid(void (HackingSystem::*)()), "55534889fb4883ec38e8????????80bb7002000000", argdata, 1, 6, &func);
}

FUNC_NAKED void HackingSystem::OnLoop()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func186::func));
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

namespace _func187
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("InputBox::TextEvent", typeid(void (InputBox::*)(CEvent::TextEvent )), "4155415455534889fb4883ec1883fe01", argdata, 2, 6, &func);
}

FUNC_NAKED void InputBox::TextEvent(CEvent::TextEvent event)
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
			// rdi has this
			// rsi has event
	);
	__asm__("call *%0\n\t" :: "m"(_func187::func));
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

namespace _func188
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("InputBox::StartInput", typeid(void (InputBox::*)()), "534889fb488d7f3831d2", argdata, 1, 6, &func);
}

FUNC_NAKED void InputBox::StartInput()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func188::func));
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

namespace _func189
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("IonDrone::GetRoomDamage", typeid(Damage (IonDrone::*)()), "554889f5534889fb4883ec08c70700000000", argdata, 2, 2, &func);
}

FUNC_NAKED Damage IonDrone::GetRoomDamage()
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
			// rdi has implicit_output
			// rsi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func189::func));
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

namespace _func190
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ItemStoreBox::constructor", typeid(void (ItemStoreBox::*)(ShipManager *, const std::string &)), "41544989f4554889d5534889fb4883ec20488b02", argdata, 3, 6, &func);
}

FUNC_NAKED void ItemStoreBox::constructor(ShipManager *ship, const std::string &resourceName)
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
			// rdi has this
			// rsi has ship
			// rdx has resourceName
	);
	__asm__("call *%0\n\t" :: "m"(_func190::func));
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

namespace _func191
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("LaserBlast::OnUpdate", typeid(void (LaserBlast::*)()), "534889fb4883ec1080bfc400000000745f", argdata, 1, 6, &func);
}

FUNC_NAKED void LaserBlast::OnUpdate()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func191::func));
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

namespace _func192
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("LaserBlast::OnInit", typeid(void (LaserBlast::*)()), "538b477c4889fb394778c7474001000000", argdata, 1, 6, &func);
}

FUNC_NAKED void LaserBlast::OnInit()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func192::func));
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

void **VTable_LaserBlast;

namespace _var193
{
	static VariableDefinition varObj("VTable_LaserBlast", "!b8b7600bb64589e84c89e741f7ed4489e849c70424(???????\?)c1f81f49c7442408(???????\?)", &VTable_LaserBlast);
}

void **VTable_Targetable_LaserBlast;

namespace _var194
{
	static VariableDefinition varObj("VTable_Targetable_LaserBlast", "", &VTable_Targetable_LaserBlast);
}

namespace _func195
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("LocationEvent::ClearEvent", typeid(void (LocationEvent::*)(bool )), "4157415641554154554889fd534883ec3883bfc404000001", argdata, 2, 6, &func);
}

FUNC_NAKED void LocationEvent::ClearEvent(bool force)
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
			// rdi has this
			// rsi has force
	);
	__asm__("call *%0\n\t" :: "m"(_func195::func));
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

namespace _func196
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("LocationEvent::constructor", typeid(void (LocationEvent::*)()), "53be????????4889fb4883ec10488d54240fe8????????488d7b18", argdata, 1, 6, &func);
}

FUNC_NAKED void LocationEvent::constructor()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func196::func));
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

namespace _func197
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("LockdownShard::Update", typeid(void (LockdownShard::*)()), "534889fbbf????????e8????????f30f5905????????f30f5883d8000000", argdata, 1, 6, &func);
}

FUNC_NAKED void LockdownShard::Update()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func197::func));
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

namespace _func198
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("MenuScreen::OnRender", typeid(void (MenuScreen::*)()), "41564155415455534889fb4881eca000000080bf0803000000", argdata, 1, 6, &func);
}

FUNC_NAKED void MenuScreen::OnRender()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func198::func));
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

namespace _func199
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("MenuScreen::constructor", typeid(void (MenuScreen::*)()), "41564155415455534889fb488d6b784881ece0000000", argdata, 1, 6, &func);
}

FUNC_NAKED void MenuScreen::constructor()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func199::func));
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

namespace _func200
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("MindBox::constructor", typeid(void (MindBox::*)(Point , MindSystem *)), "415431c9554889d5534889fb4883ec60", argdata, 3, 6, &func);
}

FUNC_NAKED void MindBox::constructor(Point pos, MindSystem *sys)
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
			// rdi has this
			// rsi has pos
			// rdx has sys
	);
	__asm__("call *%0\n\t" :: "m"(_func200::func));
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

namespace _func201
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("MindSystem::SetArmed", typeid(void (MindSystem::*)(int )), "83fe01534889fb740f", argdata, 2, 6, &func);
}

FUNC_NAKED void MindSystem::SetArmed(int armed)
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
			// rdi has this
			// rsi has armed
	);
	__asm__("call *%0\n\t" :: "m"(_func201::func));
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

namespace _func202
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("MindSystem::InitiateMindControl", typeid(void (MindSystem::*)()), "415741564155415455534889fb4883ec48488bb780020000", argdata, 1, 6, &func);
}

FUNC_NAKED void MindSystem::InitiateMindControl()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func202::func));
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

namespace _func203
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("MindSystem::OnLoop", typeid(void (MindSystem::*)()), "415455534889fb4883ec20e8????????488b8380020000", argdata, 1, 6, &func);
}

FUNC_NAKED void MindSystem::OnLoop()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func203::func));
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

namespace _func204
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x10a};
	static FunctionDefinition funcObj("Missile::constructor", typeid(void (Missile::*)(Pointf , int , int , Pointf , float )), "41574989ff4156415541545589f55389d34881ecf8000000f30f11542404", argdata, 6, 6, &func);
}

FUNC_NAKED void Missile::constructor(Pointf _position, int _ownerId, int _targetId, Pointf _target, float _heading)
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
			// rdi has this
			// rsi has _position
			// rdx has _ownerId
			// rcx has _targetId
			// r8 has _target
			// xmm0 has _heading
	);
	__asm__("call *%0\n\t" :: "m"(_func204::func));
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

namespace _func205
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("OptionsScreen::OnInit", typeid(void (OptionsScreen::*)()), "4155415455534889fbbf????????488dabe00800004883ec68", argdata, 1, 6, &func);
}

FUNC_NAKED void OptionsScreen::OnInit()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func205::func));
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

namespace _func206
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("OptionsScreen::OnLoop", typeid(void (OptionsScreen::*)()), "41574156415549bdb76ddbb66ddbb66d4154554889fd", argdata, 1, 6, &func);
}

FUNC_NAKED void OptionsScreen::OnLoop()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func206::func));
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

namespace _func207
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("PDSFire::CollisionCheck", typeid(void (PDSFire::*)(Collideable *)), "554889f5534889fb4889f74883ec58488b06", argdata, 2, 6, &func);
}

FUNC_NAKED void PDSFire::CollisionCheck(Collideable *other)
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
			// rdi has this
			// rsi has other
	);
	__asm__("call *%0\n\t" :: "m"(_func207::func));
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

namespace _func208
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Point::RelativeDistance", typeid(int (Point::*)(Point )), "8b178b470429f248c1fe2029f00fafd20fafc001d0", argdata, 2, 2, &func);
}

FUNC_NAKED int Point::RelativeDistance(Point other)
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
			// rdi has this
			// rsi has other
	);
	__asm__("call *%0\n\t" :: "m"(_func208::func));
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

namespace _func209
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Point::Distance", typeid(int (Point::*)(Point )), ".8b178b470429f248c1fe2029f00fafd20fafc001d0", argdata, 2, 2, &func);
}

FUNC_NAKED int Point::Distance(Point other)
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
			// rdi has this
			// rsi has other
	);
	__asm__("call *%0\n\t" :: "m"(_func209::func));
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

namespace _func210
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b};
	static FunctionDefinition funcObj("Pointf::constructor", typeid(void (Pointf::*)(float , float )), "f30f1107f30f114f04c3", argdata, 3, 6, &func);
}

FUNC_NAKED void Pointf::constructor(float x, float y)
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
			// rdi has this
			// xmm0 has x
			// xmm1 has y
	);
	__asm__("call *%0\n\t" :: "m"(_func210::func));
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

namespace _func211
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Pointf::RelativeDistance", typeid(float (Pointf::*)(Pointf )), "660fd64424f0488b4424f0f30f1007", argdata, 2, 2, &func);
}

FUNC_NAKED float Pointf::RelativeDistance(Pointf other)
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
			// rdi has this
			// rsi has other
	);
	__asm__("call *%0\n\t" :: "m"(_func211::func));
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

namespace _func212
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Pointf::Normalize", typeid(Pointf (Pointf::*)()), "4883ec28f30f100ff30f104704", argdata, 1, 2, &func);
}

FUNC_NAKED Pointf Pointf::Normalize()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func212::func));
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

namespace _func213
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("PowerManager::GetPowerManager", typeid(PowerManager *(*)(int )), "5389fb4883ec30488b05????????488b0d????????4889c2", argdata, 1, 2, &func);
}

FUNC_NAKED PowerManager *PowerManager::GetPowerManager(int iShipId)
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
			// rdi has iShipId
	);
	__asm__("call *%0\n\t" :: "m"(_func213::func));
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

namespace _func214
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ReactorButton::Accept", typeid(void (ReactorButton::*)()), "55534889fb4883ec288b878c000000", argdata, 1, 6, &func);
}

FUNC_NAKED void ReactorButton::Accept()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func214::func));
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

namespace _func215
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ReactorButton::OnClick", typeid(void (ReactorButton::*)()), "55534889fb4883ec28488bbf90000000", argdata, 1, 6, &func);
}

FUNC_NAKED void ReactorButton::OnClick()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func215::func));
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

namespace _func216
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ReactorButton::OnRightClick", typeid(void (ReactorButton::*)()), "534889fb4883ec208b878c000000", argdata, 1, 6, &func);
}

FUNC_NAKED void ReactorButton::OnRightClick()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func216::func));
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

namespace _func217
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ReactorButton::OnRender", typeid(void (ReactorButton::*)()), "415741564155415455534889fb4881ec3805000048897c2440", argdata, 1, 6, &func);
}

FUNC_NAKED void ReactorButton::OnRender()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func217::func));
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

namespace _func218
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("RepairStoreBox::constructor", typeid(void (RepairStoreBox::*)(ShipManager *, bool , int )), "4157415641554189cd41544989f4", argdata, 4, 6, &func);
}

FUNC_NAKED void RepairStoreBox::constructor(ShipManager *ship, bool repairAll, int price)
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
			// rdi has this
			// rsi has ship
			// rdx has repairAll
			// rcx has price
	);
	__asm__("call *%0\n\t" :: "m"(_func218::func));
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

namespace _func219
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipAI::constructor", typeid(void (ShipAI::*)(bool )), "5589f5534889fb488d7f104883ec0848c747f800000000", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipAI::constructor(bool unk)
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
			// rdi has this
			// rsi has unk
	);
	__asm__("call *%0\n\t" :: "m"(_func219::func));
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

namespace _func220
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipAI::SetStalemate", typeid(void (ShipAI::*)(bool )), ".4084f6740980bf9801000000", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipAI::SetStalemate(bool stalemate)
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
			// rdi has this
			// rsi has stalemate
	);
	__asm__("call *%0\n\t" :: "m"(_func220::func));
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

namespace _func221
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipAI::OnLoop", typeid(void (ShipAI::*)(bool )), ".41545589f5534889fb4883ec304084f6488b07", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipAI::OnLoop(bool hostile)
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
			// rdi has this
			// rsi has hostile
	);
	__asm__("call *%0\n\t" :: "m"(_func221::func));
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

namespace _func222
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipAI::GetTeleportCommand", typeid(std::pair<int, int> (ShipAI::*)()), "5348837f08004889fb", argdata, 1, 2, &func);
}

FUNC_NAKED std::pair<int, int> ShipAI::GetTeleportCommand()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func222::func));
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

namespace _func223
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipBlueprint::destructor", typeid(void (ShipBlueprint::*)()), "4154554889fd534883ec10488b874002000048c707", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipBlueprint::destructor()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func223::func));
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

namespace _func224
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipEvent::constructor", typeid(void (ShipEvent::*)(const ShipEvent &)), "415641554989f5488d760841544989fc488d7f08", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipEvent::constructor(const ShipEvent &event)
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
			// rdi has this
			// rsi has event
	);
	__asm__("call *%0\n\t" :: "m"(_func224::func));
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

namespace _func225
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipInfo::AddAugmentation", typeid(char (ShipInfo::*)(const std::string &)), "415731c041564155415455534889fb4883ec48837f6002", argdata, 2, 2, &func);
}

FUNC_NAKED char ShipInfo::AddAugmentation(const std::string &augment)
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
			// rdi has this
			// rsi has augment
	);
	__asm__("call *%0\n\t" :: "m"(_func225::func));
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

namespace _func226
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipInfo::HasAugmentation", typeid(bool (ShipInfo::*)(const std::string &)), "4157488d47084989f7415641554989fd4154554889c5534883ec28", argdata, 2, 2, &func);
}

FUNC_NAKED bool ShipInfo::HasAugmentation(const std::string &augment)
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
			// rdi has this
			// rsi has augment
	);
	__asm__("call *%0\n\t" :: "m"(_func226::func));
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

namespace _func227
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipInfo::GetAugmentationValue", typeid(float (ShipInfo::*)(const std::string &)), ".4157415641554989fd415455534883ec48488d7c2430", argdata, 2, 2, &func);
}

FUNC_NAKED float ShipInfo::GetAugmentationValue(const std::string &augment)
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
			// rdi has this
			// rsi has augment
	);
	__asm__("call *%0\n\t" :: "m"(_func227::func));
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

namespace _func228
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipStatus::RenderHealth", typeid(void (ShipStatus::*)(bool )), "4155415455534881ec880000004084f6", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipStatus::RenderHealth(bool unk)
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
			// rdi has this
			// rsi has unk
	);
	__asm__("call *%0\n\t" :: "m"(_func228::func));
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

namespace _func229
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x10a};
	static FunctionDefinition funcObj("ShipStatus::OnInit", typeid(void (ShipStatus::*)(Point , float )), "415741564155415455534889fb4881ece8010000f30f114708", argdata, 3, 6, &func);
}

FUNC_NAKED void ShipStatus::OnInit(Point unk, float unk2)
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
			// rdi has this
			// rsi has unk
			// xmm0 has unk2
	);
	__asm__("call *%0\n\t" :: "m"(_func229::func));
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

namespace _func230
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipStatus::RenderEvadeOxygen", typeid(void (ShipStatus::*)(bool )), "415741564155415455534889fb4881ec580300004084f6", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipStatus::RenderEvadeOxygen(bool unk)
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
			// rdi has this
			// rsi has unk
	);
	__asm__("call *%0\n\t" :: "m"(_func230::func));
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

namespace _func231
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipStatus::OnRender", typeid(void (ShipStatus::*)()), "4155415455534889fb4881ec88000000e8????????f30f2a03", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipStatus::OnRender()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func231::func));
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

namespace _func232
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipStatus::RenderShields", typeid(void (ShipStatus::*)(bool )), "41574156415541544989fc55534883ec18488b7f10", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipStatus::RenderShields(bool renderText)
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
			// rdi has this
			// rsi has renderText
	);
	__asm__("call *%0\n\t" :: "m"(_func232::func));
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

namespace _func233
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("StatusEffect::GetNebulaEffect", typeid(StatusEffect (*)()), "4883ec08803d????????007433660f6f05????????48b8020000000700000048ba0000000002000000", argdata, 0, 10, &func);
}

FUNC_NAKED StatusEffect StatusEffect::GetNebulaEffect()
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
	__asm__("call *%0\n\t" :: "m"(_func233::func));
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

namespace _func234
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("SystemCustomBox::constructor", typeid(void (SystemCustomBox::*)(Point , ShipSystem *, ShipManager *)), "41544989cc31c9554889f5534889fb4883ec40", argdata, 4, 6, &func);
}

FUNC_NAKED void SystemCustomBox::constructor(Point pos, ShipSystem *sys, ShipManager *ship)
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
			// rdi has this
			// rsi has pos
			// rdx has sys
			// rcx has ship
	);
	__asm__("call *%0\n\t" :: "m"(_func234::func));
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

namespace _func235
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TabbedWindow::Close", typeid(void (TabbedWindow::*)()), "538b57684889fb488b4738", argdata, 1, 6, &func);
}

FUNC_NAKED void TabbedWindow::Close()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func235::func));
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

namespace _func236
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("TeleportBox::constructor", typeid(void (TeleportBox::*)(Point , TeleportSystem *)), "4155b9010000004989d5415455534889fb4c8da370020000488dab000300004883ec58", argdata, 3, 6, &func);
}

FUNC_NAKED void TeleportBox::constructor(Point pos, TeleportSystem *sys)
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
			// rdi has this
			// rsi has pos
			// rdx has sys
	);
	__asm__("call *%0\n\t" :: "m"(_func236::func));
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

namespace _func237
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TextButton::ResetPrimitives", typeid(void (TextButton::*)()), "554889fd5331db4883ec08488b7c1d50", argdata, 1, 6, &func);
}

FUNC_NAKED void TextButton::ResetPrimitives()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func237::func));
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

namespace _func238
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TextButton::GetIdealButtonWidth", typeid(int (TextButton::*)()), "55534889fb4883ec3880bfe800000000", argdata, 1, 2, &func);
}

FUNC_NAKED int TextButton::GetIdealButtonWidth()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func238::func));
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

namespace _func239
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x109};
	static FunctionDefinition funcObj("TextButton::OnInit", typeid(void (TextButton::*)(Point , Point , int , TextString *, int )), "415741564d89c641554989d541544989f44c89c6554489cd534889fb488dbfe0000000", argdata, 6, 6, &func);
}

FUNC_NAKED void TextButton::OnInit(Point pos, Point size, int cornerInset, TextString *buttonLabel, int font)
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
			// rdi has this
			// rsi has pos
			// rdx has size
			// rcx has cornerInset
			// r8 has buttonLabel
			// r9 has font
	);
	__asm__("call *%0\n\t" :: "m"(_func239::func));
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

namespace _func240
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TextButton::OnRender", typeid(void (TextButton::*)()), "4157415641554989fd415455534883ec5880bfd000000000", argdata, 1, 6, &func);
}

FUNC_NAKED void TextButton::OnRender()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func240::func));
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

namespace _func241
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TextButton::destructor", typeid(void (TextButton::*)()), "534889fb4883ec1048c707????????488b7f50", argdata, 1, 6, &func);
}

FUNC_NAKED void TextButton::destructor()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func241::func));
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

namespace _func242
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TextButton::GetSize", typeid(Point (TextButton::*)()), "4155415455534889fb4883ec1880bfd000000000751a", argdata, 1, 2, &func);
}

FUNC_NAKED Point TextButton::GetSize()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func242::func));
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

namespace _func243
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("TextButton::OnInitRect", typeid(void (TextButton::*)(Globals::Rect &, int , TextString &, int )), "41574156415541544989cc554889f5534889fb4883ec488954240c", argdata, 5, 6, &func);
}

FUNC_NAKED void TextButton::OnInitRect(Globals::Rect &rect, int cornerInset, TextString &buttonLabel, int font)
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
			// rdi has this
			// rsi has rect
			// rdx has cornerInset
			// rcx has buttonLabel
			// r8 has font
	);
	__asm__("call *%0\n\t" :: "m"(_func243::func));
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

namespace _func244
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("TextButton::SetBaseImage", typeid(void (TextButton::*)(const std::string &, Point , int )), "4154488b065553488378e800", argdata, 4, 6, &func);
}

FUNC_NAKED void TextButton::SetBaseImage(const std::string &name, Point pos, int autoWidthMin)
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
			// rdi has this
			// rsi has name
			// rdx has pos
			// rcx has autoWidthMin
	);
	__asm__("call *%0\n\t" :: "m"(_func244::func));
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

namespace _func245
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("TextButton::SetAutoWidth", typeid(void (TextButton::*)(bool , bool , int , int )), "4585c04088b7d0000000", argdata, 5, 6, &func);
}

FUNC_NAKED void TextButton::SetAutoWidth(bool autoWidth, bool autoRightAlign, int margin, int min)
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
			// rdi has this
			// rsi has autoWidth
			// rdx has autoRightAlign
			// rcx has margin
			// r8 has min
	);
	__asm__("call *%0\n\t" :: "m"(_func245::func));
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

namespace _func246
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TextButton::constructor", typeid(void (TextButton::*)()), "55534889fb488d7f08488d6b284883ec28", argdata, 1, 6, &func);
}

FUNC_NAKED void TextButton::constructor()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func246::func));
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

namespace _func247
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x2ff};
	static FunctionDefinition funcObj("TextButton::SetInactiveColor", typeid(void (TextButton::*)(GL_Color )), ".!80bf8000000000660fd64c24f0", argdata, 2, 6, &func);
}

FUNC_NAKED void TextButton::SetInactiveColor(GL_Color color)
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
		"pushl 16(%rbp)\n\t"		// color
		"pushl 8(%rbp)\n\t"		// color
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func247::func));
	__asm__
	(
		"addl $16, %rsp\n\t"
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

namespace _func248
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x2ff};
	static FunctionDefinition funcObj("TextButton::SetActiveColor", typeid(void (TextButton::*)(GL_Color )), ".!80bf8000000000660fd64c24f0", argdata, 2, 6, &func);
}

FUNC_NAKED void TextButton::SetActiveColor(GL_Color color)
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
		"pushl 16(%rbp)\n\t"		// color
		"pushl 8(%rbp)\n\t"		// color
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func248::func));
	__asm__
	(
		"addl $16, %rsp\n\t"
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

namespace _func249
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x2ff};
	static FunctionDefinition funcObj("TextButton::SetSelectedColor", typeid(void (TextButton::*)(GL_Color )), ".!80bf8000000000660fd64c24f0", argdata, 2, 6, &func);
}

FUNC_NAKED void TextButton::SetSelectedColor(GL_Color color)
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
		"pushl 16(%rbp)\n\t"		// color
		"pushl 8(%rbp)\n\t"		// color
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func249::func));
	__asm__
	(
		"addl $16, %rsp\n\t"
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

namespace _func250
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x2ff};
	static FunctionDefinition funcObj("TextButton::SetTextColor", typeid(void (TextButton::*)(GL_Color )), ".80bf8000000000660fd64c24f8", argdata, 2, 6, &func);
}

FUNC_NAKED void TextButton::SetTextColor(GL_Color color)
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
		"pushl 16(%rbp)\n\t"		// color
		"pushl 8(%rbp)\n\t"		// color
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func250::func));
	__asm__
	(
		"addl $16, %rsp\n\t"
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

namespace _func251
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TextButton::InitPrimitives", typeid(void (TextButton::*)()), "415741564989fe4155415455534881ecb800000080bf8000000000", argdata, 1, 6, &func);
}

FUNC_NAKED void TextButton::InitPrimitives()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func251::func));
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

namespace _func252
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("TextLibrary::GetText", typeid(std::string (TextLibrary::*)(const std::string &, const std::string &)), "41574156415541544989fc5553488d5e384883ec48", argdata, 4, 2, &func);
}

FUNC_NAKED std::string TextLibrary::GetText(const std::string &name, const std::string &lang)
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
			// rdi has implicit_output
			// rsi has this
			// rdx has name
			// rcx has lang
	);
	__asm__("call *%0\n\t" :: "m"(_func252::func));
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

namespace _func253
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("TextString::GetText", typeid(std::string (TextString::*)()), "53807e08004889fb", argdata, 2, 2, &func);
}

FUNC_NAKED std::string TextString::GetText()
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
			// rdi has implicit_output
			// rsi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func253::func));
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

namespace _func254
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("UnlockArrow::constructor", typeid(void (UnlockArrow::*)(Point , int , int )), "554889f5534889fb4883ec28803d????????00", argdata, 4, 6, &func);
}

FUNC_NAKED void UnlockArrow::constructor(Point pos, int unk1, int unk2)
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
			// rdi has this
			// rsi has pos
			// rdx has unk1
			// rcx has unk2
	);
	__asm__("call *%0\n\t" :: "m"(_func254::func));
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

namespace _func255
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("UnlockArrow::MouseMove", typeid(bool (UnlockArrow::*)(int , int )), ".837f0403", argdata, 3, 2, &func);
}

FUNC_NAKED bool UnlockArrow::MouseMove(int x, int y)
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
			// rdi has this
			// rsi has x
			// rdx has y
	);
	__asm__("call *%0\n\t" :: "m"(_func255::func));
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

namespace _func256
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("UnlockArrow::OnRender", typeid(void (UnlockArrow::*)()), ".534889fb4883ec308b0785c0", argdata, 1, 6, &func);
}

FUNC_NAKED void UnlockArrow::OnRender()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func256::func));
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

namespace _func257
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WeaponAnimation::StartFire", typeid(bool (WeaponAnimation::*)()), "530fb687c10000004889fb84c0", argdata, 1, 2, &func);
}

FUNC_NAKED bool WeaponAnimation::StartFire()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func257::func));
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

namespace _func258
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("WeaponAnimation::SetFireTime", typeid(void (WeaponAnimation::*)(float )), "8b470889c22b97c8000000", argdata, 2, 6, &func);
}

FUNC_NAKED void WeaponAnimation::SetFireTime(float time)
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
			// rdi has this
			// xmm0 has time
	);
	__asm__("call *%0\n\t" :: "m"(_func258::func));
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

namespace _func259
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WeaponAnimation::Update", typeid(void (WeaponAnimation::*)()), "415455534889fb4883ec1080bfc100000000", argdata, 1, 6, &func);
}

FUNC_NAKED void WeaponAnimation::Update()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func259::func));
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

namespace _func260
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("WeaponBox::RenderBox", typeid(void (WeaponBox::*)(bool , bool )), "41570fb6d2400fb6f641564155415455534889fb4881ec68030000", argdata, 3, 6, &func);
}

FUNC_NAKED void WeaponBox::RenderBox(bool dragging, bool flashPowerBox)
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
			// rdi has this
			// rsi has dragging
			// rdx has flashPowerBox
	);
	__asm__("call *%0\n\t" :: "m"(_func260::func));
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

namespace _func261
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x107};
	static FunctionDefinition funcObj("WeaponBox::GenerateTooltip", typeid(std::string (WeaponBox::*)()), "554889f5534889fb4889f74883ec38488b06", argdata, 2, 2, &func);
}

FUNC_NAKED std::string WeaponBox::GenerateTooltip()
{
	__asm__
	(
		"pushl %rbp\n\t"
		"movl %rsp, %rbp\n\t"
		"pushl %rbx\n\t"
		"pushl %rbp\n\t"
		"pushl %r12\n\t"
		"pushl %r13\n\t"
		"pushl %r14\n\t"
		"pushl %r15\n\t"
		"pushl 8(%rbp)\n\t"		// implicit_output
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func261::func));
	__asm__
	(
		"addl $8, %rsp\n\t"
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

namespace _func262
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("WeaponStoreBox::__DO_NOT_HOOK", typeid(void (*)()), "41554989d541544989f4be", argdata, 0, 4, &func);
}

FUNC_NAKED void WeaponStoreBox::__DO_NOT_HOOK()
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
	__asm__("call *%0\n\t" :: "m"(_func262::func));
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

namespace _func263
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("WeaponStoreBox::constructor", typeid(void (WeaponStoreBox::*)(ShipManager *, Equipment *, const WeaponBlueprint *)), ".41554989d541544989f4be", argdata, 4, 6, &func);
}

FUNC_NAKED void WeaponStoreBox::constructor(ShipManager *ship, Equipment *equip, const WeaponBlueprint *weaponBp)
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
			// rdi has this
			// rsi has ship
			// rdx has equip
			// rcx has weaponBp
	);
	__asm__("call *%0\n\t" :: "m"(_func263::func));
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

namespace _func264
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WeaponSystem::RemoveWeapon", typeid(void (WeaponSystem::*)(int )), "31c085f60f88d800000041564155415455534889fb4883ec20", argdata, 2, 6, &func);
}

FUNC_NAKED void WeaponSystem::RemoveWeapon(int slot)
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
			// rdi has this
			// rsi has slot
	);
	__asm__("call *%0\n\t" :: "m"(_func264::func));
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

namespace _func265
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("WeaponSystem::SetBonusPower", typeid(void (WeaponSystem::*)(int , int )), ".5589f5534889fb4883ec08e8????????39e8", argdata, 3, 6, &func);
}

FUNC_NAKED void WeaponSystem::SetBonusPower(int amount, int permanentPower)
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
			// rdi has this
			// rsi has amount
			// rdx has permanentPower
	);
	__asm__("call *%0\n\t" :: "m"(_func265::func));
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

namespace _func266
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WeaponSystem::OnLoop", typeid(void (WeaponSystem::*)()), ".415741564155415455534889fb4883ec38e8????????488b9350020000", argdata, 1, 6, &func);
}

FUNC_NAKED void WeaponSystem::OnLoop()
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
			// rdi has this
	);
	__asm__("call *%0\n\t" :: "m"(_func266::func));
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

namespace _func267
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("WeaponSystemBox::constructor", typeid(void (WeaponSystemBox::*)(Point , ShipSystem *, WeaponControl *)), "554889cdb901000000534889fb4883ec08e8????????488dbb70020000", argdata, 4, 6, &func);
}

FUNC_NAKED void WeaponSystemBox::constructor(Point pos, ShipSystem *sys, WeaponControl *weapCtrl)
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
			// rdi has this
			// rsi has pos
			// rdx has sys
			// rcx has weapCtrl
	);
	__asm__("call *%0\n\t" :: "m"(_func267::func));
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

