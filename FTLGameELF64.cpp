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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func0::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has ship
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1::func)
		 : "rdi", "rsi", "rdx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has achievement
			// rdx has noPopup
			// rcx has sendToServer
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func2::func)
		 : "rdi", "rsi", "rdx", "rcx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shipId
			// rdx has shipType
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func3::func)
		 : "rdi", "rsi", "rdx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func4::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has baseName
			// rdx has thisName
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func5::func)
		 : "rdi", "rsi", "rdx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has flagName
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func6::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func7::func)
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has flagName
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func8::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has file
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func9::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has file
			// rdx has version
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func10::func)
		 : "rdi", "rsi", "rdx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func11::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func12::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ach
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func13::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func14::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// _numFrames
		"pushq 8(%%rbp)\n\t"		// _stripStartX
			// rdi has this
			// rsi has _image
			// rdx has _length
			// xmm0 has _time
			// rcx has _position
			// r8 has _imageWidth
			// r9 has _imageHeight
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func16::func)
		 : "rdi", "rsi", "rdx", "xmm0", "rcx", "r8", "r9"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has this
			// xmm0 has opacity
			// rsi has mirror
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func17::func)
		 : "rdi", "xmm0", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func18::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has frame
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func19::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has reset
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func20::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has frame
			// rdx has sound
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func21::func)
		 : "rdi", "rsi", "rdx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has tex
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func22::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func23::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has reset
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func24::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has progress
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func25::func)
		 : "rdi", "xmm0"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func26::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has animName
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func27::func)
		 : "rdi", "rsi", "rdx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func29::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has loop
			// xmm0 has loopDelay
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func30::func)
		 : "rdi", "rsi", "xmm0"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has resetTime
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func31::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has time
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func32::func)
		 : "rdi", "xmm0"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has time
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func33::func)
		 : "rdi", "xmm0"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has speed
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func34::func)
		 : "rdi", "xmm0"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has time
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func35::func)
		 : "rdi", "xmm0"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has reverse
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func36::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func37::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has loc
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func38::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has key
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func39::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
			// rdx has sys
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func40::func)
		 : "rdi", "rsi", "rdx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ignoreStatus
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func41::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func42::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func43::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has numberOfShips
			// rdx has shieldCount
			// rcx has defense
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func44::func)
		 : "rdi", "rsi", "rdx", "rcx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ships
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func45::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func46::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func47::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func48::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func49::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has file
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func50::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has file
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func51::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func52::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func53::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func54::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ship
			// rdx has bp
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func55::func)
		 : "rdi", "rsi", "rdx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
			// rdx has sys
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func56::func)
		 : "rdi", "rsi", "rdx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// _targetable
		"pushq 8(%%rbp)\n\t"		// _length
			// rdi has this
			// rsi has _position
			// rdx has _ownerId
			// rcx has _targetId
			// r8 has _target
			// r9 has _target2
			// xmm0 has heading
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func57::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "r9", "xmm0"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has other
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func58::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func59::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func60::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has name
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func61::func)
		 : "rdi", "rsi", "rdx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has name
			// rdx has sector
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func62::func)
		 : "rdi", "rsi", "rdx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has name
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func63::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has name
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func64::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has name
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func65::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has name
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func66::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has name
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func67::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has node
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func68::func)
		 : "rdi", "rsi", "rdx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has node
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func69::func)
		 : "rdi", "rsi", "rdx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has node
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func70::func)
		 : "rdi", "rsi", "rdx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has name
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func71::func)
		 : "rdi", "rsi", "rdx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has count
			// rcx has demo_lock
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func72::func)
		 : "rdi", "rsi", "rdx", "rcx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has name
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func73::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has isMale_ret
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func74::func)
		 : "rdi", "rsi", "rdx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has isMale_ret
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func75::func)
		 : "rdi", "rsi", "rdx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has count
			// rcx has demo_lock
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func76::func)
		 : "rdi", "rsi", "rdx", "rcx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has count
			// rcx has demo_lock
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func77::func)
		 : "rdi", "rsi", "rdx", "rcx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has node
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func78::func)
		 : "rdi", "rsi", "rdx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has node
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func79::func)
		 : "rdi", "rsi", "rdx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has _iShipId
			// rdx has _selfId
			// rcx has _bp
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func81::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func82
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("BoarderPodDrone::SetMovementTarget", typeid(void (BoarderPodDrone::*)(Targetable *)), "534889fb4883ec104885f6", argdata, 2, 6, &func);
}

FUNC_NAKED void BoarderPodDrone::SetMovementTarget(Targetable *target)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has target
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func82::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func83::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has _deployed
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func84::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has _position
			// rdx has _ownerId
			// rcx has _targetId
			// r8 has _target
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func85::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has other
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func86::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func87::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func88::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has space
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func89::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func90::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func91::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func92::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func93::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has file
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func94::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func95::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has file
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func96::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func97::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func98::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has img
			// rdx has pos
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func99::func)
		 : "rdi", "rsi", "rdx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func100::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func101::func)
		 : "rdi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has texture
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func102::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has texture
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func103::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has imageBase
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func104::func)
		 : "rdi", "rsi"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
			// rdx has selected
			// rcx has showNew
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func105::func)
		 : "rdi", "rsi", "rdx", "rcx"
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
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func106::func)
		 : "rdi"
	);
}

namespace _func107
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CApp::OnRequestExit", typeid(void (CApp::*)()), "534889fb488b7f104885ff7428", argdata, 1, 6, &func);
}

FUNC_NAKED void CApp::OnRequestExit()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func107::func)
		 : "rdi"
	);
}

namespace _func108
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CApp::OnExit", typeid(void (CApp::*)()), ".534889fbe8", argdata, 1, 6, &func);
}

FUNC_NAKED void CApp::OnExit()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func108::func)
		 : "rdi"
	);
}

namespace _func109
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CApp::OnMButtonDown", typeid(void (CApp::*)(int , int )), ".80bff037000000", argdata, 3, 6, &func);
}

FUNC_NAKED void CApp::OnMButtonDown(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func109::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func110
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CApp::OnTextInput", typeid(void (CApp::*)(int )), ".80bff037000000", argdata, 2, 6, &func);
}

FUNC_NAKED void CApp::OnTextInput(int ch)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ch
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func110::func)
		 : "rdi", "rsi"
	);
}

namespace _func111
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CApp::OnTextEvent", typeid(void (CApp::*)(CEvent::TextEvent )), ".80bff037000000", argdata, 2, 6, &func);
}

FUNC_NAKED void CApp::OnTextEvent(CEvent::TextEvent textEvent)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has textEvent
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func111::func)
		 : "rdi", "rsi"
	);
}

namespace _func112
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CApp::OnInputFocus", typeid(void (CApp::*)()), ".5380bf3b38000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CApp::OnInputFocus()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func112::func)
		 : "rdi"
	);
}

namespace _func113
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CApp::OnInputBlur", typeid(void (CApp::*)()), ".534889fbc6873b38000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CApp::OnInputBlur()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func113::func)
		 : "rdi"
	);
}

namespace _func114
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CApp::OnRButtonUp", typeid(void (CApp::*)(int , int )), ".534889fb4883ec102bb75c380000", argdata, 3, 6, &func);
}

FUNC_NAKED void CApp::OnRButtonUp(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func114::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func115
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CApp::OnRButtonDown", typeid(void (CApp::*)(int , int )), ".534889fb4883ec102bb75c380000", argdata, 3, 6, &func);
}

FUNC_NAKED void CApp::OnRButtonDown(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func115::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func116
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CApp::OnLButtonUp", typeid(void (CApp::*)(int , int )), ".534889fb4883ec102bb75c380000", argdata, 3, 6, &func);
}

FUNC_NAKED void CApp::OnLButtonUp(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func116::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func117
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CApp::OnLButtonDown", typeid(void (CApp::*)(int , int )), ".534889fb4883ec102bb75c380000", argdata, 3, 6, &func);
}

FUNC_NAKED void CApp::OnLButtonDown(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func117::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func118
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x109, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnMouseMove", typeid(void (CApp::*)(int , int , int , int , bool , bool , bool )), ".415455534889fb4883ec102bb75c380000", argdata, 8, 6, &func);
}

FUNC_NAKED void CApp::OnMouseMove(int x, int y, int xdiff, int ydiff, bool holdingLMB, bool holdingRMB, bool holdingMMB)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// holdingMMB
		"pushq 8(%%rbp)\n\t"		// holdingRMB
			// rdi has this
			// rsi has x
			// rdx has y
			// rcx has xdiff
			// r8 has ydiff
			// r9 has holdingLMB
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func118::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "r9"
	);
}

namespace _func119
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CApp::OnKeyUp", typeid(void (CApp::*)(SDLKey )), ".555389f34883ec3885f6", argdata, 2, 6, &func);
}

FUNC_NAKED void CApp::OnKeyUp(SDLKey key)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has key
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func119::func)
		 : "rdi", "rsi"
	);
}

namespace _func120
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CApp::OnLanguageChange", typeid(void (CApp::*)()), ".55be????????534889fb4883ec38", argdata, 1, 6, &func);
}

FUNC_NAKED void CApp::OnLanguageChange()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func120::func)
		 : "rdi"
	);
}

namespace _func121
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CApp::OnKeyDown", typeid(void (CApp::*)(SDLKey )), ".555389f34883ec4885f6", argdata, 2, 6, &func);
}

FUNC_NAKED void CApp::OnKeyDown(SDLKey key)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has key
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func121::func)
		 : "rdi", "rsi"
	);
}

namespace _func122
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CApp::constructor", typeid(void (CApp::*)()), ".534889fbe8????????488d7b20", argdata, 1, 6, &func);
}

FUNC_NAKED void CApp::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func122::func)
		 : "rdi"
	);
}

namespace _func123
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CApp::ParseArgs", typeid(void (CApp::*)(int , const char **)), ".f3c366666666662e0f1f840000000000", argdata, 3, 6, &func);
}

FUNC_NAKED void CApp::ParseArgs(int argc, const char **argv)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has argc
			// rdx has argv
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func123::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func124
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CApp::OnLoop", typeid(void (CApp::*)()), ".55534889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void CApp::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func124::func)
		 : "rdi"
	);
}

namespace _func125
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CApp::SetupWindow", typeid(int (CApp::*)()), ".53be0100000031c04889fb", argdata, 1, 2, &func);
}

FUNC_NAKED int CApp::SetupWindow()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func125::func)
		 : "rdi"
	);
}

namespace _func126
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CApp::OnCleanup", typeid(void (CApp::*)()), ".55534889fb4883ec08488b7f18", argdata, 1, 6, &func);
}

FUNC_NAKED void CApp::OnCleanup()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func126::func)
		 : "rdi"
	);
}

namespace _func127
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CApp::GenInputEvents", typeid(void (CApp::*)()), ".55534889fb4883ec08", argdata, 1, 6, &func);
}

FUNC_NAKED void CApp::GenInputEvents()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func127::func)
		 : "rdi"
	);
}

namespace _func128
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CApp::OnSuspend", typeid(void (CApp::*)()), ".534889fbe8????????488b7b10", argdata, 1, 6, &func);
}

FUNC_NAKED void CApp::OnSuspend()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func128::func)
		 : "rdi"
	);
}

namespace _func129
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CApp::OnResume", typeid(void (CApp::*)()), ".5380bff037000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CApp::OnResume()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func129::func)
		 : "rdi"
	);
}

namespace _func130
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CApp::TranslateMouse", typeid(Point (CApp::*)(int , int )), ".4883ec182bb75c3800002b9760380000", argdata, 3, 2, &func);
}

FUNC_NAKED Point CApp::TranslateMouse(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func130::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func131
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CApp::UpdateFullScreen", typeid(void (CApp::*)()), ".803d????????007407c3", argdata, 1, 6, &func);
}

FUNC_NAKED void CApp::UpdateFullScreen()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func131::func)
		 : "rdi"
	);
}

namespace _func132
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CApp::UpdateWindowSettings", typeid(void (CApp::*)()), ".80bf5838000000c7873038000000000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CApp::UpdateWindowSettings()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func132::func)
		 : "rdi"
	);
}

namespace _func133
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CApp::OnRender", typeid(void (CApp::*)()), ".534889fb4883ec30", argdata, 1, 6, &func);
}

FUNC_NAKED void CApp::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func133::func)
		 : "rdi"
	);
}

namespace _func134
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CApp::OnInit", typeid(int (CApp::*)()), ".534889fb31ff4883ec40", argdata, 1, 2, &func);
}

FUNC_NAKED int CApp::OnInit()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func134::func)
		 : "rdi"
	);
}

namespace _func135
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CApp::OnExecute", typeid(int (CApp::*)()), ".415731f641564155415455534889fb", argdata, 1, 2, &func);
}

FUNC_NAKED int CApp::OnExecute()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func135::func)
		 : "rdi"
	);
}

namespace _func136
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CEvent::OnEvent", typeid(void (CEvent::*)(const InputEvent *)), "415741564155415455534889f34883ec288b4604", argdata, 2, 6, &func);
}

FUNC_NAKED void CEvent::OnEvent(const InputEvent *event)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has event
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func136::func)
		 : "rdi", "rsi"
	);
}

namespace _func137
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CFPS::GetSpeedFactor", typeid(float (CFPS::*)()), "f30f104718c3", argdata, 1, 2, &func);
}

FUNC_NAKED float CFPS::GetSpeedFactor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func137::func)
		 : "rdi"
	);
}

namespace _func138
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CFPS::OnLoop", typeid(void (CFPS::*)()), "534889fb4883ec10f20f1015", argdata, 1, 6, &func);
}

FUNC_NAKED void CFPS::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func138::func)
		 : "rdi"
	);
}

CFPS *Global_CFPS_FPSControl;

namespace _var139
{
	static VariableDefinition varObj("Global_CFPS_FPSControl", "!0f28d90f28d0bf(???????\?)f30fc2d1050f54da0f55d00f28ca0f56cb", &Global_CFPS_FPSControl);
}

namespace _func140
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_ClearAll", typeid(void (*)()), "!.0f57db31ff", argdata, 0, 6, &func);
}

FUNC_NAKED void CSurface::GL_ClearAll()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func140::func)
	);
}

namespace _func141
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_ClearColor", typeid(void (*)()), "!.0f57db0f28d30f28cb0f28c3", argdata, 0, 6, &func);
}

FUNC_NAKED void CSurface::GL_ClearColor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func141::func)
	);
}

namespace _func142
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CSurface::SetViewPort", typeid(int (*)(int , int , int , int )), ".4883ec08e8????????b801000000", argdata, 4, 2, &func);
}

FUNC_NAKED int CSurface::SetViewPort(int left, int bottom, int h, int w)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has left
			// rsi has bottom
			// rdx has h
			// rcx has w
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func142::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func143
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PopScissor", typeid(void (*)()), "!.488b0d????????488b15", argdata, 0, 6, &func);
}

FUNC_NAKED void CSurface::GL_PopScissor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func143::func)
	);
}

namespace _func144
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CSurface::GL_SetStencilMode", typeid(void (*)(GL_StencilMode , int , int )), ".4883ec1883ff01", argdata, 3, 6, &func);
}

FUNC_NAKED void CSurface::GL_SetStencilMode(GL_StencilMode stencilMode, int ref, int mask)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has stencilMode
			// rsi has ref
			// rdx has mask
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func144::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func145
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PopStencilMode", typeid(void (*)()), ".488b0d????????488b15", argdata, 0, 6, &func);
}

FUNC_NAKED void CSurface::GL_PopStencilMode()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func145::func)
	);
}

namespace _func146
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_LoadIdentity", typeid(int (*)()), "!.0f57d2bf????????0f57c9", argdata, 0, 2, &func);
}

FUNC_NAKED int CSurface::GL_LoadIdentity()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func146::func)
	);
}

namespace _func147
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PushMatrix", typeid(int (*)()), ".8b15????????83fa0f", argdata, 0, 2, &func);
}

FUNC_NAKED int CSurface::GL_PushMatrix()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func147::func)
	);
}

namespace _func148
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PopMatrix", typeid(int (*)()), ".8b15????????85d20f84", argdata, 0, 2, &func);
}

FUNC_NAKED int CSurface::GL_PopMatrix()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func148::func)
	);
}

namespace _func149
{
	static void *func = 0;
	static short argdata[] = {0x10a, 0x10b, 0x10c, 0x10d};
	static FunctionDefinition funcObj("CSurface::GL_Rotate", typeid(void (*)(float , float , float , float )), ".0f57e44881ecf80000000f2ec4", argdata, 4, 6, &func);
}

FUNC_NAKED void CSurface::GL_Rotate(float angle, float x, float y, float z)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// xmm0 has angle
			// xmm1 has x
			// xmm2 has y
			// xmm3 has z
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func149::func)
		 : "xmm0", "xmm1", "xmm2", "xmm3"
	);
}

namespace _func150
{
	static void *func = 0;
	static short argdata[] = {0x10a, 0x10b, 0x10c};
	static FunctionDefinition funcObj("CSurface::GL_Scale", typeid(void (*)(float , float , float )), ".f30f101d????????b8000000000f2ec30f9bc20f45d084d2", argdata, 3, 6, &func);
}

FUNC_NAKED void CSurface::GL_Scale(float x, float y, float z)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// xmm0 has x
			// xmm1 has y
			// xmm2 has z
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func150::func)
		 : "xmm0", "xmm1", "xmm2"
	);
}

namespace _func151
{
	static void *func = 0;
	static short argdata[] = {0x10a, 0x10b, 0x10c};
	static FunctionDefinition funcObj("CSurface::GL_Translate", typeid(bool (*)(float , float , float )), ".0f57dbb8000000000f2ec30f9bc20f45d084d2", argdata, 3, 2, &func);
}

FUNC_NAKED bool CSurface::GL_Translate(float x, float y, float z)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// xmm0 has x
			// xmm1 has y
			// xmm2 has z
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func151::func)
		 : "xmm0", "xmm1", "xmm2"
	);
}

namespace _func152
{
	static void *func = 0;
	static short argdata[] = {0x2ff};
	static FunctionDefinition funcObj("CSurface::GL_SetColor", typeid(int (*)(GL_Color )), ".4883ec28660fd6442408488b442408660fd64c2408488b542408", argdata, 1, 2, &func);
}

FUNC_NAKED int CSurface::GL_SetColor(GL_Color color)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func152::func)
	);
}

namespace _func153
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_GetColor", typeid(GL_Color (*)()), ".488b05????????f30f7e05", argdata, 0, 10, &func);
}

FUNC_NAKED GL_Color CSurface::GL_GetColor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func153::func)
	);
}

namespace _func154
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_RemoveColorTint", typeid(void (*)()), ".488b05????????483b05", argdata, 0, 6, &func);
}

FUNC_NAKED void CSurface::GL_RemoveColorTint()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func154::func)
	);
}

namespace _func155
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GetColorTint", typeid(GL_Color (*)()), ".488b15????????488b05", argdata, 0, 10, &func);
}

FUNC_NAKED GL_Color CSurface::GetColorTint()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func155::func)
	);
}

namespace _func156
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_EnableBlend", typeid(bool (*)()), "!.ba04000000be03000000bf01000000", argdata, 0, 2, &func);
}

FUNC_NAKED bool CSurface::GL_EnableBlend()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func156::func)
	);
}

namespace _func157
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_DisableBlend", typeid(bool (*)()), "!.31d2be01000000bf01000000", argdata, 0, 2, &func);
}

FUNC_NAKED bool CSurface::GL_DisableBlend()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func157::func)
	);
}

namespace _func158
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CSurface::GL_ForceAntialias", typeid(void (*)(bool )), "!.40883d????????c3", argdata, 1, 6, &func);
}

FUNC_NAKED void CSurface::GL_ForceAntialias(bool on)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has on
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func158::func)
		 : "rdi"
	);
}

namespace _func159
{
	static void *func = 0;
	static short argdata[] = {0x10a, 0x10b, 0x10c, 0x10d, 0x10e, 0x2ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawLine", typeid(bool (*)(float , float , float , float , float , GL_Color )), ".4881eca8000000440f28c8660fd62c24", argdata, 6, 2, &func);
}

FUNC_NAKED bool CSurface::GL_DrawLine(float x1, float y1, float x2, float y2, float lineWidth, GL_Color color)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// xmm0 has x1
			// xmm1 has y1
			// xmm2 has x2
			// xmm3 has y2
			// xmm4 has lineWidth
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func159::func)
		 : "xmm0", "xmm1", "xmm2", "xmm3", "xmm4"
	);
}

namespace _func160
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x2ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawTriangle", typeid(bool (*)(Point , Point , Point , GL_Color )), ".4883ec78660fd6442408488b4c2408", argdata, 4, 2, &func);
}

FUNC_NAKED bool CSurface::GL_DrawTriangle(Point vertex1, Point vertex2, Point vertex3, GL_Color color)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has vertex1
			// rsi has vertex2
			// rdx has vertex3
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func160::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func161
{
	static void *func = 0;
	static short argdata[] = {0x10a, 0x10b, 0x10c, 0x10d, 0x2ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawRect", typeid(bool (*)(float , float , float , float , GL_Color )), ".4881ec88000000660fd6642408488b542408", argdata, 5, 2, &func);
}

FUNC_NAKED bool CSurface::GL_DrawRect(float x1, float y1, float x2, float y2, GL_Color color)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// xmm0 has x1
			// xmm1 has y1
			// xmm2 has x2
			// xmm3 has y2
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func161::func)
		 : "xmm0", "xmm1", "xmm2", "xmm3"
	);
}

namespace _func162
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x2ff, 0x10c};
	static FunctionDefinition funcObj("CSurface::GL_DrawRectOutline", typeid(bool (*)(int , int , int , int , GL_Color , float )), ".4881eca8010000660fd64424084c8b442408660fd64c2408", argdata, 6, 2, &func);
}

FUNC_NAKED bool CSurface::GL_DrawRectOutline(int x1, int y1, int x2, int y2, GL_Color color, float lineWidth)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has x1
			// rsi has y1
			// rdx has x2
			// rcx has y2
			// xmm2 has lineWidth
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func162::func)
		 : "rdi", "rsi", "rdx", "rcx", "xmm2"
	);
}

namespace _func163
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b, 0x10c, 0x10d, 0x10e, 0x2ff, 0x106};
	static FunctionDefinition funcObj("CSurface::GL_BlitImage", typeid(bool (*)(GL_Texture *, float , float , float , float , float , GL_Color , bool )), ".554889fd534883ec68660fd66c2410", argdata, 8, 2, &func);
}

FUNC_NAKED bool CSurface::GL_BlitImage(GL_Texture *tex, float x, float y, float x2, float y2, float rotation, GL_Color color, bool mirror)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has tex
			// xmm0 has x
			// xmm1 has y
			// xmm2 has x2
			// xmm3 has y2
			// xmm4 has rotation
			// rsi has mirror
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func163::func)
		 : "rdi", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "rsi"
	);
}

namespace _func164
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b, 0x10c, 0x10d, 0x10e, 0x2ff, 0x106};
	static FunctionDefinition funcObj("CSurface::GL_BlitPixelImage", typeid(bool (*)(GL_Texture *, float , float , float , float , float , GL_Color , bool )), ".4154554889fd534883ec60", argdata, 8, 2, &func);
}

FUNC_NAKED bool CSurface::GL_BlitPixelImage(GL_Texture *tex, float x, float y, float x2, float y2, float rotation, GL_Color color, bool mirror)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has tex
			// xmm0 has x
			// xmm1 has y
			// xmm2 has x2
			// xmm3 has y2
			// xmm4 has rotation
			// rsi has mirror
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func164::func)
		 : "rdi", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "rsi"
	);
}

namespace _func165
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b, 0x10c, 0x10d, 0x10e, 0x10f, 0x110, 0x111, 0x1ff, 0x2ff, 0x106};
	static FunctionDefinition funcObj("CSurface::GL_BlitImagePartial", typeid(bool (*)(GL_Texture *, float , float , float , float , float , float , float , float , float , GL_Color , bool )), ".415455534889fb4883ec604084f6f30f11442408", argdata, 12, 2, &func);
}

FUNC_NAKED bool CSurface::GL_BlitImagePartial(GL_Texture *tex, float x, float y, float size_x, float size_y, float start_x, float end_x, float start_y, float end_y, float alpha, GL_Color color, bool mirror)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"subq $8, %%rsp\n\t"
		"pushq 24(%%rbp)\n\t"		// color
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// alpha
			// rdi has tex
			// xmm0 has x
			// xmm1 has y
			// xmm2 has size_x
			// xmm3 has size_y
			// xmm4 has start_x
			// xmm5 has end_x
			// xmm6 has start_y
			// xmm7 has end_y
			// rsi has mirror
		"call *%0\n\t"
		"addq $24, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func165::func)
		 : "rdi", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "rsi"
	);
}

namespace _func166
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b, 0x106, 0x102, 0x10c, 0x2ff, 0x101};
	static FunctionDefinition funcObj("CSurface::GL_BlitPixelImageWide", typeid(bool (*)(GL_Texture *, float , float , int , int , float , GL_Color , bool )), ".41574889f841564989fe41554189d54154555389f34881ec88000000", argdata, 8, 2, &func);
}

FUNC_NAKED bool CSurface::GL_BlitPixelImageWide(GL_Texture *tex, float x, float y, int x2, int y2, float opacity, GL_Color color, bool mirror)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has tex
			// xmm0 has x
			// xmm1 has y
			// rsi has x2
			// rdx has y2
			// xmm2 has opacity
			// rcx has mirror
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func166::func)
		 : "rdi", "xmm0", "xmm1", "rsi", "rdx", "xmm2", "rcx"
	);
}

namespace _func167
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CSurface::GL_BlitMultiImage", typeid(void (*)(GL_Texture *, const std::vector<GL_TexVertex> &, bool )), ".415641554189d541544989f455534889fb4883ec20", argdata, 3, 6, &func);
}

FUNC_NAKED void CSurface::GL_BlitMultiImage(GL_Texture *tex, const std::vector<GL_TexVertex> &texVertices, bool antialias)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has tex
			// rsi has texVertices
			// rdx has antialias
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func167::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func168
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CSurface::GL_BlitMultiColorImage", typeid(void (*)(GL_Texture *, const std::vector<GL_ColorTexVertex> &, bool )), ".4156415541544189d4554889f5534889fb4883ec20", argdata, 3, 6, &func);
}

FUNC_NAKED void CSurface::GL_BlitMultiColorImage(GL_Texture *tex, const std::vector<GL_ColorTexVertex> &texVertices, bool antialias)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has tex
			// rsi has texVertices
			// rdx has antialias
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func168::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func169
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CSurface::GL_RenderPrimitive", typeid(void (*)(GL_Primitive *)), ".534889fb4883ec104885ff", argdata, 1, 6, &func);
}

FUNC_NAKED void CSurface::GL_RenderPrimitive(GL_Primitive *primitive)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has primitive
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func169::func)
		 : "rdi"
	);
}

namespace _func170
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("CSurface::GL_RenderPrimitiveWithAlpha", typeid(void (*)(GL_Primitive *, float )), ".534889fb4883ec104885ff", argdata, 2, 6, &func);
}

FUNC_NAKED void CSurface::GL_RenderPrimitiveWithAlpha(GL_Primitive *primitive, float alpha)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has primitive
			// xmm0 has alpha
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func170::func)
		 : "rdi", "xmm0"
	);
}

namespace _func171
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x2ff};
	static FunctionDefinition funcObj("CSurface::GL_RenderPrimitiveWithColor", typeid(void (*)(GL_Primitive *, GL_Color )), ".534889fb4883ec20660fd6442408", argdata, 2, 6, &func);
}

FUNC_NAKED void CSurface::GL_RenderPrimitiveWithColor(GL_Primitive *primitive, GL_Color color)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has primitive
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func171::func)
		 : "rdi"
	);
}

namespace _func172
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CSurface::GL_DestroyPrimitive", typeid(void (*)(GL_Primitive *)), ".4885ff534889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void CSurface::GL_DestroyPrimitive(GL_Primitive *primitive)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has primitive
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func172::func)
		 : "rdi"
	);
}

namespace _func173
{
	static void *func = 0;
	static short argdata[] = {0x10a, 0x10b, 0x10c, 0x10d, 0x2ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateRectPrimitive", typeid(GL_Primitive *(*)(float , float , float , float , GL_Color )), ".53f30f58d0bf30000000f30f58d94883ec40", argdata, 5, 2, &func);
}

FUNC_NAKED GL_Primitive *CSurface::GL_CreateRectPrimitive(float x, float y, float w, float h, GL_Color color)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// xmm0 has x
			// xmm1 has y
			// xmm2 has w
			// xmm3 has h
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func173::func)
		 : "xmm0", "xmm1", "xmm2", "xmm3"
	);
}

namespace _func174
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x2ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateMultiRectPrimitive", typeid(GL_Primitive *(*)(std::vector<Globals::Rect> &, GL_Color )), ".415648be000000000000c01f4989fe4155415455534883ec20", argdata, 2, 2, &func);
}

FUNC_NAKED GL_Primitive *CSurface::GL_CreateMultiRectPrimitive(std::vector<Globals::Rect> &vec, GL_Color color)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has vec
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func174::func)
		 : "rdi"
	);
}

namespace _func175
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x2ff, 0x10c};
	static FunctionDefinition funcObj("CSurface::GL_CreateRectOutlinePrimitive", typeid(GL_Primitive *(*)(int , int , int , int , GL_Color , float )), ".53f30f2adff30f2ae6bf300000004881eca0000000", argdata, 6, 2, &func);
}

FUNC_NAKED GL_Primitive *CSurface::GL_CreateRectOutlinePrimitive(int x, int y, int w, int h, GL_Color color, float lineWidth)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has x
			// rsi has y
			// rdx has w
			// rcx has h
			// xmm2 has lineWidth
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func175::func)
		 : "rdi", "rsi", "rdx", "rcx", "xmm2"
	);
}

namespace _func176
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x2ff, 0x10c};
	static FunctionDefinition funcObj("CSurface::GL_CreateMultiLinePrimitive", typeid(GL_Primitive *(*)(std::vector<GL_Line> &, GL_Color , float )), ".4157415641554989fd415455534883ec484c8b6708", argdata, 3, 2, &func);
}

FUNC_NAKED GL_Primitive *CSurface::GL_CreateMultiLinePrimitive(std::vector<GL_Line> &vec, GL_Color color, float thickness)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has vec
			// xmm2 has thickness
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func176::func)
		 : "rdi", "xmm2"
	);
}

namespace _func177
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x2ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateMultiImagePrimitive", typeid(GL_Primitive *(*)(GL_Texture *, std::vector<GL_TexVertex> *, GL_Color )), ".415541544989f455534883ec48", argdata, 3, 2, &func);
}

FUNC_NAKED GL_Primitive *CSurface::GL_CreateMultiImagePrimitive(GL_Texture *tex, std::vector<GL_TexVertex> *vec, GL_Color color)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has tex
			// rsi has vec
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func177::func)
		 : "rdi", "rsi"
	);
}

namespace _func178
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PushStencilMode", typeid(void (*)()), ".488b05????????483b05", argdata, 0, 6, &func);
}

FUNC_NAKED void CSurface::GL_PushStencilMode()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func178::func)
	);
}

namespace _func179
{
	static void *func = 0;
	static short argdata[] = {0x2ff};
	static FunctionDefinition funcObj("CSurface::GL_SetColorTint", typeid(void (*)(GL_Color )), ".4883ec18488b0d", argdata, 1, 6, &func);
}

FUNC_NAKED void CSurface::GL_SetColorTint(GL_Color color)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func179::func)
	);
}

namespace _func180
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b, 0x10c, 0x10d, 0x10e, 0x2ff, 0x106};
	static FunctionDefinition funcObj("CSurface::GL_CreatePixelImagePrimitive", typeid(GL_Primitive *(*)(GL_Texture *, float , float , float , float , float , GL_Color , bool )), ".41550f28f84989fd415455534883ec58", argdata, 8, 2, &func);
}

FUNC_NAKED GL_Primitive *CSurface::GL_CreatePixelImagePrimitive(GL_Texture *tex, float x, float y, float size_x, float size_y, float rotate, GL_Color color, bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has tex
			// xmm0 has x
			// xmm1 has y
			// xmm2 has size_x
			// xmm3 has size_y
			// xmm4 has rotate
			// rsi has unk
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func180::func)
		 : "rdi", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "rsi"
	);
}

namespace _func181
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b, 0x10c, 0x10d, 0x10e, 0x10f, 0x110, 0x111};
	static FunctionDefinition funcObj("CSurface::AddTexVertices", typeid(void (*)(std::vector<GL_TexVertex> *, float , float , float , float , float , float , float , float )), ".554889fd534883ec28488b07488b5f08", argdata, 9, 6, &func);
}

FUNC_NAKED void CSurface::AddTexVertices(std::vector<GL_TexVertex> *vec, float x1, float y1, float u1, float v1, float x2, float y2, float u2, float v2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has vec
			// xmm0 has x1
			// xmm1 has y1
			// xmm2 has u1
			// xmm3 has v1
			// xmm4 has x2
			// xmm5 has y2
			// xmm6 has u2
			// xmm7 has v2
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func181::func)
		 : "rdi", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7"
	);
}

namespace _func182
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b, 0x10c, 0x10d, 0x10e, 0x2ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateImagePrimitive", typeid(GL_Primitive *(*)(GL_Texture *, float , float , float , float , float , GL_Color )), ".550f28f84889fd534883ec58", argdata, 7, 2, &func);
}

FUNC_NAKED GL_Primitive *CSurface::GL_CreateImagePrimitive(GL_Texture *tex, float x, float y, float size_x, float size_y, float rotate, GL_Color color)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has tex
			// xmm0 has x
			// xmm1 has y
			// xmm2 has size_x
			// xmm3 has size_y
			// xmm4 has rotate
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func182::func)
		 : "rdi", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4"
	);
}

namespace _func183
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x10a, 0x10b, 0x102, 0x101, 0x2ff, 0x10e};
	static FunctionDefinition funcObj("CSurface::GL_DrawShield", typeid(bool (*)(int , int , float , float , int , int , GL_Color , float )), ".41550f28f041540f28fe4189cc55f30f5cfc89d5534883ec68", argdata, 8, 2, &func);
}

FUNC_NAKED bool CSurface::GL_DrawShield(int x, int y, float a1, float b1, int angle1, int angle2, GL_Color color, float thickness)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has x
			// rsi has y
			// xmm0 has a1
			// xmm1 has b1
			// rdx has angle1
			// rcx has angle2
			// xmm4 has thickness
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func183::func)
		 : "rdi", "rsi", "xmm0", "xmm1", "rdx", "rcx", "xmm4"
	);
}

namespace _func184
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::FinishFrame", typeid(void (*)()), "!488b35????????488b3d????????e9", argdata, 0, 6, &func);
}

FUNC_NAKED void CSurface::FinishFrame()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func184::func)
	);
}

namespace _func185
{
	static void *func = 0;
	static short argdata[] = {0x10a, 0x10b, 0x10c, 0x10d, 0x10e, 0x10f};
	static FunctionDefinition funcObj("CSurface::GL_OrthoProjection", typeid(int (*)(float , float , float , float , float , float )), "440f28c94883ec48", argdata, 6, 2, &func);
}

FUNC_NAKED int CSurface::GL_OrthoProjection(float mx1, float mx2, float mx3, float mx4, float mx5, float mx6)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// xmm0 has mx1
			// xmm1 has mx2
			// xmm2 has mx3
			// xmm3 has mx4
			// xmm4 has mx5
			// xmm5 has mx6
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func185::func)
		 : "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5"
	);
}

namespace _func186
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CachedImage::destructor", typeid(void (CachedImage::*)()), "534889fb4883ec10488b471048c707????????488d78e84881ff????????750e", argdata, 1, 6, &func);
}

FUNC_NAKED void CachedImage::destructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func186::func)
		 : "rdi"
	);
}

namespace _func187
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CachedImage::SetImagePath", typeid(void (CachedImage::*)(const std::string &)), "55534889fbbf????????4883ec08e8????????483b4318", argdata, 2, 6, &func);
}

FUNC_NAKED void CachedImage::SetImagePath(const std::string &imagePath)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has imagePath
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func187::func)
		 : "rdi", "rsi"
	);
}

namespace _func188
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CachedImage::SetPosition", typeid(void (CachedImage::*)(int , int )), ".41544189d45589f553397720", argdata, 3, 6, &func);
}

FUNC_NAKED void CachedImage::SetPosition(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func188::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func189
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CachedImage::constructor1", typeid(void (CachedImage::*)(const std::string &, int , int )), "41544189cc5589d5534889fb48c7470800000000", argdata, 4, 6, &func);
}

FUNC_NAKED void CachedImage::constructor1(const std::string &path, int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has path
			// rdx has x
			// rcx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func189::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func190
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CachedImage::constructor_copy", typeid(void (CachedImage::*)(const CachedImage &)), "554889f5488d7610534889fb488d7f104883ec0848c747f800000000", argdata, 2, 6, &func);
}

FUNC_NAKED void CachedImage::constructor_copy(const CachedImage &other)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has other
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func190::func)
		 : "rdi", "rsi"
	);
}

namespace _func191
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("CachedImage::SetRotation", typeid(void (CachedImage::*)(float )), "534889fb4883ec100f2e4740", argdata, 2, 6, &func);
}

FUNC_NAKED void CachedImage::SetRotation(float _rotation)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has _rotation
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func191::func)
		 : "rdi", "xmm0"
	);
}

namespace _func192
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CachedImage::SetMirrored", typeid(void (CachedImage::*)(bool )), ".5589f5534889fb4883ec0840387744", argdata, 2, 6, &func);
}

FUNC_NAKED void CachedImage::SetMirrored(bool _mirrored)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has _mirrored
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func192::func)
		 : "rdi", "rsi"
	);
}

namespace _func193
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CachedImage::CreatePrimitive", typeid(void (CachedImage::*)()), "415455534889fb4883ec50488b6f184885ed", argdata, 1, 6, &func);
}

FUNC_NAKED void CachedImage::CreatePrimitive()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func193::func)
		 : "rdi"
	);
}

namespace _func194
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CachedPrimitive::OnRender", typeid(void (CachedPrimitive::*)(const GL_Color &)), "534889fb4883ec20488b7f084885ff", argdata, 2, 6, &func);
}

FUNC_NAKED void CachedPrimitive::OnRender(const GL_Color &color)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has color
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func194::func)
		 : "rdi", "rsi"
	);
}

namespace _func195
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CachedPrimitive::destructor", typeid(void (CachedPrimitive::*)()), "48c707????????488b7f08e9", argdata, 1, 6, &func);
}

FUNC_NAKED void CachedPrimitive::destructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func195::func)
		 : "rdi"
	);
}

namespace _func196
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ChoiceBox::OnRender", typeid(void (ChoiceBox::*)()), "41574989ff41564155415455534881ec68020000", argdata, 1, 6, &func);
}

FUNC_NAKED void ChoiceBox::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func196::func)
		 : "rdi"
	);
}

namespace _func197
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ChoiceBox::MouseMove", typeid(void (ChoiceBox::*)(int , int )), "41554189d541544989fcbf", argdata, 3, 6, &func);
}

FUNC_NAKED void ChoiceBox::MouseMove(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func197::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func198
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CloakingBox::constructor", typeid(void (CloakingBox::*)(Point , CloakingSystem *)), "415431c9554889d5534889fb4883ec50", argdata, 3, 6, &func);
}

FUNC_NAKED void CloakingBox::constructor(Point pos, CloakingSystem *sys)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
			// rdx has sys
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func198::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func199
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CloakingSystem::OnLoop", typeid(void (CloakingSystem::*)()), "55534889fb4883ec08e8????????488dbb68020000", argdata, 1, 6, &func);
}

FUNC_NAKED void CloakingSystem::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func199::func)
		 : "rdi"
	);
}

namespace _func200
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CloakingSystem::FiredWeapon", typeid(void (CloakingSystem::*)()), "534889fbbe????????4883ec30488d54241e", argdata, 1, 6, &func);
}

FUNC_NAKED void CloakingSystem::FiredWeapon()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func200::func)
		 : "rdi"
	);
}

namespace _func201
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CloneBox::constructor", typeid(void (CloneBox::*)(Point , CloneSystem *)), "415731c94156415541544531e4554889d5534889fb4881ec08020000", argdata, 3, 6, &func);
}

FUNC_NAKED void CloneBox::constructor(Point pos, CloneSystem *sys)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
			// rdx has sys
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func201::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func202
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CloneSystem::OnLoop", typeid(void (CloneSystem::*)()), "415741564155415455534889fb4881ec88010000", argdata, 1, 6, &func);
}

FUNC_NAKED void CloneSystem::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func202::func)
		 : "rdi"
	);
}

namespace _func203
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CombatAI::UpdateMindControl", typeid(void (CombatAI::*)(bool )), "41554154554889fd534883ec48488b4760488b58604885db", argdata, 2, 6, &func);
}

FUNC_NAKED void CombatAI::UpdateMindControl(bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func203::func)
		 : "rdi", "rsi"
	);
}

namespace _func204
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CombatAI::OnLoop", typeid(void (CombatAI::*)()), "4154554889fd53e8????????488b7d60", argdata, 1, 6, &func);
}

FUNC_NAKED void CombatAI::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func204::func)
		 : "rdi"
	);
}

namespace _func205
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CombatControl::RenderTarget", typeid(void (CombatControl::*)()), "415741564989fe4155415455534881ec68020000488b87f8000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CombatControl::RenderTarget()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func205::func)
		 : "rdi"
	);
}

namespace _func206
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CombatControl::GetCurrentTarget", typeid(ShipManager *(CombatControl::*)()), "488b87c00700004885c0740c488b4010c3", argdata, 1, 2, &func);
}

FUNC_NAKED ShipManager *CombatControl::GetCurrentTarget()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func206::func)
		 : "rdi"
	);
}

namespace _func207
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CombatControl::CurrentTargetIsBoss", typeid(char (CombatControl::*)()), ".488bbfc00700004885ff", argdata, 1, 2, &func);
}

FUNC_NAKED char CombatControl::CurrentTargetIsBoss()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func207::func)
		 : "rdi"
	);
}

namespace _func208
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CombatControl::CanTargetSelf", typeid(char (CombatControl::*)()), "4154554889fd534883ec30488b87f80000004885c0", argdata, 1, 2, &func);
}

FUNC_NAKED char CombatControl::CanTargetSelf()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func208::func)
		 : "rdi"
	);
}

namespace _func209
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CombatControl::OnRenderCombat", typeid(void (CombatControl::*)()), "534889fb4883ec3080bfb80e000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CombatControl::OnRenderCombat()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func209::func)
		 : "rdi"
	);
}

namespace _func210
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CombatControl::AddEnemyShip", typeid(void (CombatControl::*)(CompleteShip *)), "4155415455534889fb4883ec284883bfc007000000", argdata, 2, 6, &func);
}

FUNC_NAKED void CombatControl::AddEnemyShip(CompleteShip *ship)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ship
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func210::func)
		 : "rdi", "rsi"
	);
}

namespace _func211
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CombatControl::UpdateAiming", typeid(void (CombatControl::*)()), "415455534889fb4883ec1083bfdc070000ff", argdata, 1, 6, &func);
}

FUNC_NAKED void CombatControl::UpdateAiming()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func211::func)
		 : "rdi"
	);
}

namespace _func212
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CombatControl::UpdateTarget", typeid(bool (CombatControl::*)()), "41564155415455534889fb4881eca0000000f30f1087e00e0000", argdata, 1, 2, &func);
}

FUNC_NAKED bool CombatControl::UpdateTarget()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func212::func)
		 : "rdi"
	);
}

namespace _func213
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x2ff, 0x106};
	static FunctionDefinition funcObj("CombatControl::DrawHostileBox", typeid(void (CombatControl::*)(GL_Color , int )), "415731d24156415541545589f531f6534889fb4883ec38488d7c2420", argdata, 3, 6, &func);
}

FUNC_NAKED void CombatControl::DrawHostileBox(GL_Color color, int stencilBit)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has this
			// rsi has stencilBit
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func213::func)
		 : "rdi", "rsi"
	);
}

namespace _func214
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CombatControl::OnInit", typeid(void (CombatControl::*)(Point )), "55534889fb4883ec184883bf7011000000", argdata, 2, 6, &func);
}

FUNC_NAKED void CombatControl::OnInit(Point pos)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func214::func)
		 : "rdi", "rsi"
	);
}

namespace _func215
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CombatControl::OnLoop", typeid(void (CombatControl::*)()), "415431c95531ed534889fb4883ec10488b9790070000", argdata, 1, 6, &func);
}

FUNC_NAKED void CombatControl::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func215::func)
		 : "rdi"
	);
}

namespace _func216
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CombatControl::SetMouseCursor", typeid(void (CombatControl::*)()), "534883bff8000000004889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void CombatControl::SetMouseCursor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func216::func)
		 : "rdi"
	);
}

namespace _func217
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CombatControl::DisarmAll", typeid(void (CombatControl::*)()), "534883bfc0070000004889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void CombatControl::DisarmAll()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func217::func)
		 : "rdi"
	);
}

namespace _func218
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CombatControl::SelectTarget", typeid(bool (CombatControl::*)()), "4157be0900000041564155415455534889fb4883ec58488b7f08", argdata, 1, 2, &func);
}

FUNC_NAKED bool CombatControl::SelectTarget()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func218::func)
		 : "rdi"
	);
}

namespace _func219
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CombatControl::MouseRClick", typeid(bool (CombatControl::*)(int , int )), "415541544189d45589f5534889fb4883ec08", argdata, 3, 2, &func);
}

FUNC_NAKED bool CombatControl::MouseRClick(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func219::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func220
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CombatControl::WeaponsArmed", typeid(bool (CombatControl::*)()), "534889fb488b7f08be09000000e8????????84c0751a", argdata, 1, 2, &func);
}

FUNC_NAKED bool CombatControl::WeaponsArmed()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func220::func)
		 : "rdi"
	);
}

namespace _func221
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CombatControl::KeyDown", typeid(void (CombatControl::*)(SDLKey )), "5589f5534889fb488d7f204883ec08", argdata, 2, 6, &func);
}

FUNC_NAKED void CombatControl::KeyDown(SDLKey key)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has key
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func221::func)
		 : "rdi", "rsi"
	);
}

namespace _func222
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CombatControl::DisarmTeleporter", typeid(void (CombatControl::*)()), "55be0900000031ed534889fb4883ec08488b7f08", argdata, 1, 6, &func);
}

FUNC_NAKED void CombatControl::DisarmTeleporter()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func222::func)
		 : "rdi"
	);
}

namespace _func223
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CombatControl::constructor", typeid(void (CombatControl::*)()), "415741564155415455534889fb488d7f104c8da3a8090000", argdata, 1, 6, &func);
}

FUNC_NAKED void CombatControl::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func223::func)
		 : "rdi"
	);
}

namespace _func224
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CombatControl::RenderSelfAiming", typeid(void (CombatControl::*)()), "534889fb488d7f204883ec20e8", argdata, 1, 6, &func);
}

FUNC_NAKED void CombatControl::RenderSelfAiming()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func224::func)
		 : "rdi"
	);
}

namespace _func225
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x2ff};
	static FunctionDefinition funcObj("CombatControl::RenderShipStatus", typeid(void (CombatControl::*)(Pointf , GL_Color )), "41574156415541544989fc55534881ecb8000000660fd60424", argdata, 3, 6, &func);
}

FUNC_NAKED void CombatControl::RenderShipStatus(Pointf pos, GL_Color color)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has this
			// rsi has pos
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func225::func)
		 : "rdi", "rsi"
	);
}

namespace _func226
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CombatControl::GetCrewTooltip", typeid(std::string (CombatControl::*)(int , int )), "534889fb4883ec10488b86c00700004885c0", argdata, 4, 2, &func);
}

FUNC_NAKED std::string CombatControl::GetCrewTooltip(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has x
			// rcx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func226::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func227
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CombatControl::Clear", typeid(void (CombatControl::*)()), "554889fd534883ec0848c787c007000000000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CombatControl::Clear()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func227::func)
		 : "rdi"
	);
}

namespace _func228
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CombatControl::MouseMove", typeid(bool (CombatControl::*)(int , int )), "f30f2ac641554189f541544189d455534889fb4883ec08", argdata, 3, 2, &func);
}

FUNC_NAKED bool CombatControl::MouseMove(int mX, int mY)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mX
			// rdx has mY
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func228::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func229
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CombatControl::MouseClick", typeid(void (CombatControl::*)(int , int , bool )), "415431c94189d45589f553c687e80e0000014889fb", argdata, 4, 6, &func);
}

FUNC_NAKED void CombatControl::MouseClick(int mX, int mY, bool shift)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mX
			// rdx has mY
			// rcx has shift
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func229::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func230
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CombatDrone::constructor", typeid(void (CombatDrone::*)(int , int , const DroneBlueprint *)), "41554154554889cd4c8da5a0000000534889fb4883ec38", argdata, 4, 6, &func);
}

FUNC_NAKED void CombatDrone::constructor(int iShipId, int selfId, const DroneBlueprint *bp)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has iShipId
			// rdx has selfId
			// rcx has bp
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func230::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func231
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CombatDrone::SetWeaponTarget", typeid(void (CombatDrone::*)(Targetable *)), "554889f5534889fb4883ec084885f6743f", argdata, 2, 6, &func);
}

FUNC_NAKED void CombatDrone::SetWeaponTarget(Targetable *target)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has target
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func231::func)
		 : "rdi", "rsi"
	);
}

namespace _func232
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CommandGui::Victory", typeid(void (CommandGui::*)()), "4157415641554989fd415455534883ec78488b8770190000", argdata, 1, 6, &func);
}

FUNC_NAKED void CommandGui::Victory()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func232::func)
		 : "rdi"
	);
}

namespace _func233
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CommandGui::CheckGameover", typeid(void (CommandGui::*)()), ".415455534889fb4883ec50", argdata, 1, 6, &func);
}

FUNC_NAKED void CommandGui::CheckGameover()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func233::func)
		 : "rdi"
	);
}

namespace _func234
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CommandGui::IsGameOver", typeid(bool (CommandGui::*)()), ".803d????????00756753", argdata, 1, 2, &func);
}

FUNC_NAKED bool CommandGui::IsGameOver()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func234::func)
		 : "rdi"
	);
}

namespace _func235
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CommandGui::OnInit", typeid(void (CommandGui::*)()), ".415455488daf90040000534889fb4889ef4881eca0000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CommandGui::OnInit()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func235::func)
		 : "rdi"
	);
}

namespace _func236
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CommandGui::AddEnemyShip", typeid(void (CommandGui::*)(CompleteShip *)), ".4154554889f5534889fb488dbf880500004883ec30", argdata, 2, 6, &func);
}

FUNC_NAKED void CommandGui::AddEnemyShip(CompleteShip *ship)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ship
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func236::func)
		 : "rdi", "rsi"
	);
}

namespace _func237
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CommandGui::GetWorldCoordinates", typeid(Point (CommandGui::*)(Point , bool )), ".41544189d4554889fd534889f34883ec204889e7", argdata, 3, 2, &func);
}

FUNC_NAKED Point CommandGui::GetWorldCoordinates(Point point, bool fromTarget)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has point
			// rdx has fromTarget
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func237::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func238
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x10a};
	static FunctionDefinition funcObj("CommandGui::RenderPlayerShip", typeid(void (CommandGui::*)(Point &, float )), ".415431d2554889f531f6534889fb4883ec30", argdata, 3, 6, &func);
}

FUNC_NAKED void CommandGui::RenderPlayerShip(Point &shipCenter, float jumpScale)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shipCenter
			// xmm0 has jumpScale
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func238::func)
		 : "rdi", "rsi", "xmm0"
	);
}

namespace _func239
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("CommandGui::NewLocation", typeid(void (CommandGui::*)(const std::string &, std::vector<ChoiceText> *, ResourceEvent &, bool )), ".415741564155415455534889d34881ec58020000", argdata, 5, 6, &func);
}

FUNC_NAKED void CommandGui::NewLocation(const std::string &mainText, std::vector<ChoiceText> *choices, ResourceEvent &resources, bool testingEvents)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mainText
			// rdx has choices
			// rcx has resources
			// r8 has testingEvents
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func239::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func240
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CommandGui::RunCommand", typeid(void (CommandGui::*)(std::string &)), ".4157415641554989fd41544989f45531ed5331db4883ec58488b06", argdata, 2, 6, &func);
}

FUNC_NAKED void CommandGui::RunCommand(std::string &command)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has command
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func240::func)
		 : "rdi", "rsi"
	);
}

namespace _func241
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CommandGui::CreateNewStore", typeid(Store *(CommandGui::*)(int )), ".41554189f5415455534889fbbf580600004c8da3003c0000", argdata, 2, 2, &func);
}

FUNC_NAKED Store *CommandGui::CreateNewStore(int sectorNumber)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has sectorNumber
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func241::func)
		 : "rdi", "rsi"
	);
}

namespace _func242
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CommandGui::KeyDown", typeid(void (CommandGui::*)(SDLKey , bool )), ".415541545589f5534889fb4883ec3880bf8045000000", argdata, 3, 6, &func);
}

FUNC_NAKED void CommandGui::KeyDown(SDLKey key, bool shiftHeld)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has key
			// rdx has shiftHeld
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func242::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func243
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CommandGui::RenderStatic", typeid(void (CommandGui::*)()), ".41564155415455534889fb4883ec40", argdata, 1, 6, &func);
}

FUNC_NAKED void CommandGui::RenderStatic()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func243::func)
		 : "rdi"
	);
}

namespace _func244
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CommandGui::LButtonDown", typeid(void (CommandGui::*)(int , int , bool )), ".415541544189d45589f5534889fb4883ec2880bf8045000000", argdata, 4, 6, &func);
}

FUNC_NAKED void CommandGui::LButtonDown(int mX, int mY, bool shiftHeld)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mX
			// rdx has mY
			// rcx has shiftHeld
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func244::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func245
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CommandGui::MouseMove", typeid(void (CommandGui::*)(int , int )), ".41544189d45589f5534889fb4883ec5080bf8045000000", argdata, 3, 6, &func);
}

FUNC_NAKED void CommandGui::MouseMove(int mX, int mY)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mX
			// rdx has mY
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func245::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func246
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CommandGui::OnLoop", typeid(void (CommandGui::*)()), ".41564155415455534889fb4883ec2080bf8045000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CommandGui::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func246::func)
		 : "rdi"
	);
}

namespace _func247
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CommandGui::constructor", typeid(void (CommandGui::*)()), ".41574156415541545548c7c5ffffffff534889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void CommandGui::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func247::func)
		 : "rdi"
	);
}

namespace _func248
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CompleteShip::PauseLoop", typeid(void (CompleteShip::*)()), "!488b7f10e9????????90660f1f44000053", argdata, 1, 6, &func);
}

FUNC_NAKED void CompleteShip::PauseLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func248::func)
		 : "rdi"
	);
}

namespace _func249
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CompleteShip::Restart", typeid(void (CompleteShip::*)()), ".534889fb488b7f10", argdata, 1, 6, &func);
}

FUNC_NAKED void CompleteShip::Restart()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func249::func)
		 : "rdi"
	);
}

namespace _func250
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CompleteShip::constructor", typeid(void (CompleteShip::*)(SpaceManager *, bool , int )), ".534889fb48897718", argdata, 4, 6, &func);
}

FUNC_NAKED void CompleteShip::constructor(SpaceManager *space, bool unk, int unk2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has space
			// rdx has unk
			// rcx has unk2
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func250::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func251
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CompleteShip::SetShip", typeid(void (CompleteShip::*)(ShipManager *)), ".8b96ac08000048897710", argdata, 2, 6, &func);
}

FUNC_NAKED void CompleteShip::SetShip(ShipManager *ship)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ship
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func251::func)
		 : "rdi", "rsi"
	);
}

namespace _func252
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CompleteShip::OnInit", typeid(void (CompleteShip::*)(const ShipBlueprint *, int )), ".41554189d541544989f455534889fbbf580a0000", argdata, 3, 6, &func);
}

FUNC_NAKED void CompleteShip::OnInit(const ShipBlueprint *blueprint, int unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has blueprint
			// rdx has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func252::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func253
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CompleteShip::AddBoarders", typeid(void (CompleteShip::*)(int , const std::string &, bool )), ".415741564189ce415541544189f4be02000000554889fd534881ec88000000", argdata, 4, 6, &func);
}

FUNC_NAKED void CompleteShip::AddBoarders(int amount, const std::string &race, bool unk2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has amount
			// rdx has race
			// rcx has unk2
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func253::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func254
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember", typeid(CrewMember *(CompleteShip::*)(const CrewBlueprint *, bool )), ".415741564989f6415541544189d455488dae88000000534881ec38010000", argdata, 3, 2, &func);
}

FUNC_NAKED CrewMember *CompleteShip::AddCrewMember(const CrewBlueprint *blueprint, bool hostile)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has blueprint
			// rdx has hostile
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func254::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func255
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember1", typeid(CrewMember *(CompleteShip::*)(const std::string &, const std::string &, bool )), ".41574889f04989ff415641554189cd415455534889d34883ec58", argdata, 4, 2, &func);
}

FUNC_NAKED CrewMember *CompleteShip::AddCrewMember1(const std::string &race, const std::string &name, bool hostile)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has race
			// rdx has name
			// rcx has hostile
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func255::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func256
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CompleteShip::AddDrone", typeid(Drone *(CompleteShip::*)(const DroneBlueprint *, int )), "!.488b7f10e9????????90660f1f4400004154", argdata, 3, 2, &func);
}

FUNC_NAKED Drone *CompleteShip::AddDrone(const DroneBlueprint *blueprint, int unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has blueprint
			// rdx has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func256::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func257
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember2", typeid(CrewMember *(CompleteShip::*)(CrewMember *, int )), ".41544885f655534889f3", argdata, 3, 2, &func);
}

FUNC_NAKED CrewMember *CompleteShip::AddCrewMember2(CrewMember *member, int unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has member
			// rdx has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func257::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func258
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CompleteShip::SaveState", typeid(void (CompleteShip::*)(int )), "!.89f08bb71002000089c7", argdata, 2, 6, &func);
}

FUNC_NAKED void CompleteShip::SaveState(int unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func258::func)
		 : "rdi", "rsi"
	);
}

namespace _func259
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CompleteShip::LoadState", typeid(void (CompleteShip::*)(int )), ".534889fb89f74883ec20", argdata, 2, 6, &func);
}

FUNC_NAKED void CompleteShip::LoadState(int unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func259::func)
		 : "rdi", "rsi"
	);
}

namespace _func260
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CompleteShip::InitiateTeleport", typeid(void (CompleteShip::*)(int , int )), ".415455534889fb4883ec40488b87e0010000", argdata, 3, 6, &func);
}

FUNC_NAKED void CompleteShip::InitiateTeleport(int targetRoom, int command)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has targetRoom
			// rdx has command
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func260::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func261
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CompleteShip::OnLoop", typeid(void (CompleteShip::*)()), ".4157415641554989fd415455498d6d305331db4883ec18488b7f10", argdata, 1, 6, &func);
}

FUNC_NAKED void CompleteShip::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func261::func)
		 : "rdi"
	);
}

namespace _func262
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CompleteShip::GetTeleportingParty", typeid(std::vector<CrewMember*> (CompleteShip::*)()), ".4154554889f553488b86000200004889fb", argdata, 2, 2, &func);
}

FUNC_NAKED std::vector<CrewMember*> CompleteShip::GetTeleportingParty()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func262::func)
		 : "rdi", "rsi"
	);
}

namespace _func263
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CompleteShip::KillRandomCrew", typeid(void (CompleteShip::*)()), "!.488b7f10e9????????90660f1f440000488b7f10", argdata, 1, 6, &func);
}

FUNC_NAKED void CompleteShip::KillRandomCrew()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func263::func)
		 : "rdi"
	);
}

namespace _func264
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CompleteShip::CountCrew", typeid(int (CompleteShip::*)(bool )), "!.488b7f10400fb6f6", argdata, 2, 2, &func);
}

FUNC_NAKED int CompleteShip::CountCrew(bool boarders)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has boarders
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func264::func)
		 : "rdi", "rsi"
	);
}

namespace _func265
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CompleteShip::Jump", typeid(void (CompleteShip::*)()), ".488b87e0010000488987e8010000", argdata, 1, 6, &func);
}

FUNC_NAKED void CompleteShip::Jump()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func265::func)
		 : "rdi"
	);
}

namespace _func266
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CompleteShip::SetEnemyShip", typeid(void (CompleteShip::*)(CompleteShip *)), "!.4885f648897720", argdata, 2, 6, &func);
}

FUNC_NAKED void CompleteShip::SetEnemyShip(CompleteShip *other)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has other
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func266::func)
		 : "rdi", "rsi"
	);
}

namespace _func267
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CompleteShip::DeadCrew", typeid(bool (CompleteShip::*)()), ".55534889fb4883ec080fb67728", argdata, 1, 2, &func);
}

FUNC_NAKED bool CompleteShip::DeadCrew()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func267::func)
		 : "rdi"
	);
}

namespace _func268
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CompleteShip::TeleportCrew", typeid(std::vector<CrewMember*> (CompleteShip::*)(int , bool )), ".53488b76104889fb0fb6c9", argdata, 4, 2, &func);
}

FUNC_NAKED std::vector<CrewMember*> CompleteShip::TeleportCrew(int roomId, bool intruders)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has roomId
			// rcx has intruders
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func268::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func269
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CompleteShip::OnRender", typeid(void (CompleteShip::*)()), "!.534889fb8b7708488b7f18ba02000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CompleteShip::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func269::func)
		 : "rdi"
	);
}

namespace _func270
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CompleteShip::OnRenderSpace", typeid(void (CompleteShip::*)()), "!.488b7f18f30f1005????????be03000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CompleteShip::OnRenderSpace()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func270::func)
		 : "rdi"
	);
}

namespace _func271
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CompleteShip::OnRenderShip", typeid(void (CompleteShip::*)(bool , bool )), "!.41544189d4ba020000005589f5534889fb8b7708488b7f18", argdata, 3, 6, &func);
}

FUNC_NAKED void CompleteShip::OnRenderShip(bool unk1, bool unk2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk1
			// rdx has unk2
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func271::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func272
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ConfirmWindow::Close", typeid(void (ConfirmWindow::*)()), "!534889fb488b7f70", argdata, 1, 6, &func);
}

FUNC_NAKED void ConfirmWindow::Close()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func272::func)
		 : "rdi"
	);
}

namespace _func273
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ConfirmWindow::MouseClick", typeid(void (ConfirmWindow::*)(int , int )), ".807f0800741a", argdata, 3, 6, &func);
}

FUNC_NAKED void ConfirmWindow::MouseClick(int mX, int mY)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mX
			// rdx has mY
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func273::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func274
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ConfirmWindow::constructor", typeid(void (ConfirmWindow::*)()), ".534889fb4883ec10e8????????488d7b20488d54240f", argdata, 1, 6, &func);
}

FUNC_NAKED void ConfirmWindow::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func274::func)
		 : "rdi"
	);
}

namespace _func275
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x109};
	static FunctionDefinition funcObj("ConfirmWindow::SetText", typeid(void (ConfirmWindow::*)(const TextString &, int , bool , const TextString &, const TextString &)), ".41574189cf41564189d641554989f541544d89cc554c89c5534889fb4883ec38", argdata, 6, 6, &func);
}

FUNC_NAKED void ConfirmWindow::SetText(const TextString &text_, int minWidth, bool autoCenter, const TextString &yesText_, const TextString &noText_)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has text_
			// rdx has minWidth
			// rcx has autoCenter
			// r8 has yesText_
			// r9 has noText_
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func275::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "r9"
	);
}

namespace _func276
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ConfirmWindow::SetPosition", typeid(void (ConfirmWindow::*)(Point )), ".41564155415455534889fb4883ec10", argdata, 2, 6, &func);
}

FUNC_NAKED void ConfirmWindow::SetPosition(Point pos)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func276::func)
		 : "rdi", "rsi"
	);
}

namespace _func277
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ConfirmWindow::Open", typeid(void (ConfirmWindow::*)()), ".415741564155415455534889fb4883ec28", argdata, 1, 6, &func);
}

FUNC_NAKED void ConfirmWindow::Open()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func277::func)
		 : "rdi"
	);
}

namespace _func278
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ConfirmWindow::OnRender", typeid(void (ConfirmWindow::*)()), ".41574156415541544989fc55534881ec98000000488b7f70", argdata, 1, 6, &func);
}

FUNC_NAKED void ConfirmWindow::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func278::func)
		 : "rdi"
	);
}

namespace _func279
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ConfirmWindow::MouseMove", typeid(void (ConfirmWindow::*)(int , int )), ".41545553807f08004889fb", argdata, 3, 6, &func);
}

FUNC_NAKED void ConfirmWindow::MouseMove(int mX, int mY)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mX
			// rdx has mY
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func279::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func280
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ControlButton::OnRender", typeid(void (ControlButton::*)()), "415455534889fb4883ec608b4730", argdata, 1, 6, &func);
}

FUNC_NAKED void ControlButton::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func280::func)
		 : "rdi"
	);
}

namespace _func281
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ControlsScreen::OnInit", typeid(void (ControlsScreen::*)()), "41574156415541544989fc55534881ece80000004883bf3006000000", argdata, 1, 6, &func);
}

FUNC_NAKED void ControlsScreen::OnInit()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func281::func)
		 : "rdi"
	);
}

namespace _func282
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ControlsScreen::OnLoop", typeid(void (ControlsScreen::*)()), "41564155415449bcb76ddbb66ddbb66d554889fd534883ec4048638728060000", argdata, 1, 6, &func);
}

FUNC_NAKED void ControlsScreen::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func282::func)
		 : "rdi"
	);
}

namespace _func283
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ControlsScreen::OnRender", typeid(void (ControlsScreen::*)()), "415741564155415455534889fb4881ec1802000080bf7001000000", argdata, 1, 6, &func);
}

FUNC_NAKED void ControlsScreen::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func283::func)
		 : "rdi"
	);
}

namespace _func284
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CooldownSystemBox::constructor", typeid(void (CooldownSystemBox::*)(Point , ShipSystem *, bool )), "4157415641554989fd41545589cdb901000000534889f34881ece8010000", argdata, 4, 6, &func);
}

FUNC_NAKED void CooldownSystemBox::constructor(Point pos, ShipSystem *sys, bool roundDown)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
			// rdx has sys
			// rcx has roundDown
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func284::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func285
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CooldownSystemBox::OnRender", typeid(void (CooldownSystemBox::*)(bool )), "4154400fb6f655534889fb4883ec50", argdata, 2, 6, &func);
}

FUNC_NAKED void CooldownSystemBox::OnRender(bool ignoreStatus)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ignoreStatus
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func285::func)
		 : "rdi", "rsi"
	);
}

namespace _func286
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CreditScreen::OnRender", typeid(void (CreditScreen::*)()), "415641554154554889fd534883ec60", argdata, 1, 6, &func);
}

FUNC_NAKED void CreditScreen::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func286::func)
		 : "rdi"
	);
}

namespace _func287
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CreditScreen::constructor", typeid(void (CreditScreen::*)()), "48c74708????????48c74710????????c747180000000048c7472800000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CreditScreen::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func287::func)
		 : "rdi"
	);
}

namespace _func288
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CreditScreen::Start", typeid(void (CreditScreen::*)(const std::string &, const std::vector<std::string> &)), "4157415641554154554889d5534889fb4881ecd8010000", argdata, 3, 6, &func);
}

FUNC_NAKED void CreditScreen::Start(const std::string &shipName, const std::vector<std::string> &crewNames)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shipName
			// rdx has crewNames
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func288::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func289
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CreditScreen::Done", typeid(bool (CreditScreen::*)()), "488b4730482b472848baabaaaaaaaaaaaaaa", argdata, 1, 2, &func);
}

FUNC_NAKED bool CreditScreen::Done()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func289::func)
		 : "rdi"
	);
}

namespace _func290
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CrewAI::PrioritizeIntruderRoom", typeid(int (CrewAI::*)(CrewMember *, int , int )), "41574156415541544989f45589d5534889fb4883ec18", argdata, 4, 2, &func);
}

FUNC_NAKED int CrewAI::PrioritizeIntruderRoom(CrewMember *crew, int roomId, int target)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has crew
			// rdx has roomId
			// rcx has target
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func290::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func291
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewAI::CheckForHealing", typeid(void (CrewAI::*)()), ".4156415541544531e45531ed534889fb4883ec20", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewAI::CheckForHealing()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func291::func)
		 : "rdi"
	);
}

namespace _func292
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x2ff, 0x106};
	static FunctionDefinition funcObj("CrewAI::PrioritizeTask", typeid(int (CrewAI::*)(CrewTask , int )), ".415641554989fd41544189d4554863e95389f34883ec10", argdata, 3, 2, &func);
}

FUNC_NAKED int CrewAI::PrioritizeTask(CrewTask task, int crewId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// task
		"pushq 8(%%rbp)\n\t"		// task
			// rdi has this
			// rsi has crewId
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func292::func)
		 : "rdi", "rsi"
	);
}

namespace _func293
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewAI::AssignCrewmembers", typeid(void (CrewAI::*)()), ".415631d241554531ed415449bcabaaaaaaaaaaaaaa5553", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewAI::AssignCrewmembers()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func293::func)
		 : "rdi"
	);
}

namespace _func294
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewAI::UpdateCrewMember", typeid(void (CrewAI::*)(int )), ".41574863f641564155415455534889fb4883ec38", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewAI::UpdateCrewMember(int crewId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has crewId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func294::func)
		 : "rdi", "rsi"
	);
}

namespace _func295
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewAI::UpdateIntruders", typeid(void (CrewAI::*)()), ".415641554154554889fd534883ec10488b4730488b57284839d0", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewAI::UpdateIntruders()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func295::func)
		 : "rdi"
	);
}

namespace _func296
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewAI::CheckForProblems", typeid(void (CrewAI::*)()), ".41574989ff41564d89fe4155415455534881ec88000000488b07", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewAI::CheckForProblems()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func296::func)
		 : "rdi"
	);
}

namespace _func297
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewAI::UpdateDrones", typeid(void (CrewAI::*)()), ".415741564531f6415541545531ed534889fb4881eca8000000488b5710", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewAI::UpdateDrones()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func297::func)
		 : "rdi"
	);
}

namespace _func298
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewAI::OnLoop", typeid(void (CrewAI::*)()), ".415741564155415455534889fb4883ec48488b37", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewAI::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func298::func)
		 : "rdi"
	);
}

namespace _func299
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewAnimation::destructor", typeid(void (CrewAnimation::*)()), "41574889f841564155415455534883ec68", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewAnimation::destructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func299::func)
		 : "rdi"
	);
}

namespace _func300
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewAnimation::GetFiringFrame", typeid(int (CrewAnimation::*)()), ".8b475c83f8ff", argdata, 1, 2, &func);
}

FUNC_NAKED int CrewAnimation::GetFiringFrame()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func300::func)
		 : "rdi"
	);
}

namespace _func301
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewAnimation::OnRenderProps", typeid(void (CrewAnimation::*)()), "!.41554531ed415449bc000000000000803f55", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewAnimation::OnRenderProps()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func301::func)
		 : "rdi"
	);
}

namespace _func302
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x106, 0x102};
	static FunctionDefinition funcObj("CrewAnimation::OnRender", typeid(void (CrewAnimation::*)(float , int , bool )), ".41544189f45589d5534889fb4883ec50", argdata, 4, 6, &func);
}

FUNC_NAKED void CrewAnimation::OnRender(float scale, int selectedState, bool outlineOnly)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has scale
			// rsi has selectedState
			// rdx has outlineOnly
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func302::func)
		 : "rdi", "xmm0", "rsi", "rdx"
	);
}

namespace _func303
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewAnimation::FireShot", typeid(bool (CrewAnimation::*)()), "!.53488d9fd80800004889df", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewAnimation::FireShot()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func303::func)
		 : "rdi"
	);
}

namespace _func304
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewAnimation::RenderIcon", typeid(void (CrewAnimation::*)(bool )), ".4155415455534889fb4881ecf80000004084f6", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewAnimation::RenderIcon(bool border)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has border
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func304::func)
		 : "rdi", "rsi"
	);
}

namespace _func305
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x109, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::OnUpdate", typeid(void (CrewAnimation::*)(Pointf , bool , bool , bool , bool , bool )), ".415455534889fb4883ec308b4760", argdata, 7, 6, &func);
}

FUNC_NAKED void CrewAnimation::OnUpdate(Pointf position, bool moving, bool fighting, bool repairing, bool dying, bool onFire)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"subq $8, %%rsp\n\t"
		"pushq 8(%%rbp)\n\t"		// onFire
			// rdi has this
			// rsi has position
			// rdx has moving
			// rcx has fighting
			// r8 has repairing
			// r9 has dying
		"call *%0\n\t"
		"addq $8, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func305::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "r9"
	);
}

namespace _func306
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewAnimation::GetDeathSound", typeid(std::string (CrewAnimation::*)()), ".534889fb4883ec3080beec09000000", argdata, 2, 2, &func);
}

FUNC_NAKED std::string CrewAnimation::GetDeathSound()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func306::func)
		 : "rdi", "rsi"
	);
}

namespace _func307
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewAnimation::GetShootingSound", typeid(std::string (CrewAnimation::*)()), ".534889fb4883ec30", argdata, 2, 2, &func);
}

FUNC_NAKED std::string CrewAnimation::GetShootingSound()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func307::func)
		 : "rdi", "rsi"
	);
}

namespace _func308
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewAnimation::SetupStrips", typeid(void (CrewAnimation::*)()), ".4157488d87e009000041564889c64155415455534889fb4881ec08020000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewAnimation::SetupStrips()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func308::func)
		 : "rdi"
	);
}

namespace _func309
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CrewAnimation::OnInit", typeid(void (CrewAnimation::*)(const std::string &, Pointf , bool )), ".415783f20141564155415455534889fb4889f74881ec08010000", argdata, 4, 6, &func);
}

FUNC_NAKED void CrewAnimation::OnInit(const std::string &name, Pointf position, bool enemy)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has name
			// rdx has position
			// rcx has enemy
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func309::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func310
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("CrewAnimation::constructor", typeid(void (CrewAnimation::*)(int , const std::string &, Pointf , bool )), ".415741564155415455534881ec98000000", argdata, 5, 6, &func);
}

FUNC_NAKED void CrewAnimation::constructor(int shipId, const std::string &race, Pointf unk, bool hostile)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shipId
			// rdx has race
			// rcx has unk
			// r8 has hostile
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func310::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func311
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewAnimation::OnUpdateEffects", typeid(void (CrewAnimation::*)()), ".415741564155415455534889fb4883ec6848897c2430", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewAnimation::OnUpdateEffects()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func311::func)
		 : "rdi"
	);
}

namespace _func312
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewBlueprint::destructor", typeid(void (CrewBlueprint::*)()), "4154554889fd534883ec1048c707????????488bbfe8000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewBlueprint::destructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func312::func)
		 : "rdi"
	);
}

namespace _func313
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x109};
	static FunctionDefinition funcObj("CrewBlueprint::RenderSkill", typeid(void (CrewBlueprint::*)(int , int , int , int , int )), "415641554189d54963d141544189f45589cd534489c34883ec40488b87b8000000", argdata, 6, 6, &func);
}

FUNC_NAKED void CrewBlueprint::RenderSkill(int x, int y, int length, int height, int skill)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
			// rcx has length
			// r8 has height
			// r9 has skill
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func313::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "r9"
	);
}

namespace _func314
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewBlueprint::RandomSkills", typeid(void (CrewBlueprint::*)(int )), "415431c0554889fd534883ec4085f6", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewBlueprint::RandomSkills(int worldLevel)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has worldLevel
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func314::func)
		 : "rdi", "rsi"
	);
}

namespace _func315
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("CrewBlueprint::RenderIcon", typeid(void (CrewBlueprint::*)(float )), "4157415641554154554889fd53488d5f084881ece80200004889de", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewBlueprint::RenderIcon(float opacity)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has opacity
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func315::func)
		 : "rdi", "xmm0"
	);
}

namespace _func316
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewBlueprint::GetNameShort", typeid(std::string (CrewBlueprint::*)()), "415541544c8d6678554889fd534889f34883ec28", argdata, 2, 2, &func);
}

FUNC_NAKED std::string CrewBlueprint::GetNameShort()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func316::func)
		 : "rdi", "rsi"
	);
}

namespace _func317
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewBox::MouseClick", typeid(bool (CrewBox::*)()), "0fb6477884c0", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewBox::MouseClick()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func317::func)
		 : "rdi"
	);
}

namespace _func318
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewBox::OnRenderSkillLevel", typeid(void (CrewBox::*)()), ".534889fb4883ec1080bf4c01000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewBox::OnRenderSkillLevel()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func318::func)
		 : "rdi"
	);
}

namespace _func319
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewBox::RenderIcon", typeid(void (CrewBox::*)()), ".55534889fb4883ec18488b7f20488b07", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewBox::RenderIcon()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func319::func)
		 : "rdi"
	);
}

namespace _func320
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewBox::RenderLabels", typeid(void (CrewBox::*)()), ".55534889fb4883ec48488b7720488d7c2420", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewBox::RenderLabels()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func320::func)
		 : "rdi"
	);
}

namespace _func321
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewBox::RenderCloneDying", typeid(void (CrewBox::*)()), ".80bf3401000000755c488b4720", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewBox::RenderCloneDying()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func321::func)
		 : "rdi"
	);
}

namespace _func322
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CrewBox::constructor", typeid(void (CrewBox::*)(Point , CrewMember *, int )), ".41574889f048c1f8204156415541544189cc554889d5534889fb4c8d6b304881eca8000000", argdata, 4, 6, &func);
}

FUNC_NAKED void CrewBox::constructor(Point pos, CrewMember *crew, int number)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
			// rdx has crew
			// rcx has number
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func322::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func323
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewBox::destructor", typeid(void (CrewBox::*)()), ".415641554154554889fd534883ec10488bbf58010000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewBox::destructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func323::func)
		 : "rdi"
	);
}

namespace _func324
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewBox::OnLoop", typeid(void (CrewBox::*)(bool )), "!.5589f5534889fb4883ec08488b7f20488b07", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewBox::OnLoop(bool selected)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has selected
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func324::func)
		 : "rdi", "rsi"
	);
}

namespace _func325
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CrewBox::GetSelected", typeid(CrewMember *(CrewBox::*)(int , int )), ".4157415641554c8daf6803000041544189d431d25589f5", argdata, 3, 2, &func);
}

FUNC_NAKED CrewMember *CrewBox::GetSelected(int mouseX, int mouseY)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mouseX
			// rdx has mouseY
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func325::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func326
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewBox::OnRender", typeid(void (CrewBox::*)()), ".415741564155415455534889fb488dbfe0010000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewBox::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func326::func)
		 : "rdi"
	);
}

namespace _func327
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewControl::ClearCrewBoxes", typeid(void (CrewControl::*)()), "41544989fc5553488b4f68488b57604889c84829d048c1f80385c0", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewControl::ClearCrewBoxes()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func327::func)
		 : "rdi"
	);
}

namespace _func328
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x109};
	static FunctionDefinition funcObj("CrewControl::LButton", typeid(void (CrewControl::*)(int , int , int , int , bool )), ".41574589c741564189ce41554189d541544189f455534889fb4883ec38", argdata, 6, 6, &func);
}

FUNC_NAKED void CrewControl::LButton(int mX, int mY, int wX, int wY, bool shiftHeld)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mX
			// rdx has mY
			// rcx has wX
			// r8 has wY
			// r9 has shiftHeld
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func328::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "r9"
	);
}

namespace _func329
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CrewControl::RButton", typeid(void (CrewControl::*)(int , int , bool )), ".41545553807f54004889fb", argdata, 4, 6, &func);
}

FUNC_NAKED void CrewControl::RButton(int mX, int mY, bool shiftHeld)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mX
			// rdx has mY
			// rcx has shiftHeld
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func329::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func330
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewControl::ClearDeadCrew", typeid(void (CrewControl::*)(std::vector<CrewMember*> *)), ".415431c0554889f553488b4e0831db", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewControl::ClearDeadCrew(std::vector<CrewMember*> *crew)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has crew
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func330::func)
		 : "rdi", "rsi"
	);
}

namespace _func331
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewControl::UpdateCrewBoxes", typeid(void (CrewControl::*)()), ".415731d241564155415455534889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewControl::UpdateCrewBoxes()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func331::func)
		 : "rdi"
	);
}

namespace _func332
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewControl::LinkShip", typeid(void (CrewControl::*)(ShipManager *)), ".534889374889fb", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewControl::LinkShip(ShipManager *ship)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ship
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func332::func)
		 : "rdi", "rsi"
	);
}

namespace _func333
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewControl::OnLoop", typeid(void (CrewControl::*)()), ".415455488dafc8000000534889fb4889ef4883ec30", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewControl::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func333::func)
		 : "rdi"
	);
}

namespace _func334
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CrewControl::SelectPotentialCrew", typeid(void (CrewControl::*)(CrewMember *, bool )), ".55534889fb4889f74883ec184885f64889742408", argdata, 3, 6, &func);
}

FUNC_NAKED void CrewControl::SelectPotentialCrew(CrewMember *crew, bool allowTeleportLeaving)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has crew
			// rdx has allowTeleportLeaving
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func334::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func335
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewControl::KeyDown", typeid(void (CrewControl::*)(SDLKey )), ".4157415641554989fd415455534881ecc8010000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewControl::KeyDown(SDLKey key)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has key
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func335::func)
		 : "rdi", "rsi"
	);
}

namespace _func336
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewControl::OnRender", typeid(void (CrewControl::*)()), ".415741564c8db7f000000041554989fd415455534883ec58", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewControl::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func336::func)
		 : "rdi"
	);
}

namespace _func337
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("CrewControl::MouseMove", typeid(void (CrewControl::*)(int , int , int , int )), ".41574989ff415641554589c541544189cc5589d55389f34881ec18010000", argdata, 5, 6, &func);
}

FUNC_NAKED void CrewControl::MouseMove(int mX, int mY, int wX, int wY)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mX
			// rdx has mY
			// rcx has wX
			// r8 has wY
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func337::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func338
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewCustomizeBox::CheckContents", typeid(void (CrewCustomizeBox::*)()), "534889fb4883ec2080bf6807000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewCustomizeBox::CheckContents()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func338::func)
		 : "rdi"
	);
}

namespace _func339
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewDrone::OnLoop", typeid(void (CrewDrone::*)()), "41564155415455488daf48070000534889fb4889ef", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewDrone::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func339::func)
		 : "rdi"
	);
}

namespace _func340
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x109};
	static FunctionDefinition funcObj("CrewDrone::constructor", typeid(void (CrewDrone::*)(const std::string &, const std::string &, int , const DroneBlueprint *, CrewAnimation *)), ".41574989d7415641554189cd41544d89c4554c89cd534889fb4881ec58010000", argdata, 6, 6, &func);
}

FUNC_NAKED void CrewDrone::constructor(const std::string &type, const std::string &name, int shipId, const DroneBlueprint *blueprint, CrewAnimation *anim)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has type
			// rdx has name
			// rcx has shipId
			// r8 has blueprint
			// r9 has anim
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func340::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "r9"
	);
}

namespace _func341
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewDrone::ProvidesVision", typeid(bool (CrewDrone::*)()), ".8b57084889f885d2", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewDrone::ProvidesVision()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func341::func)
		 : "rdi"
	);
}

namespace _func342
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewDrone::destructor", typeid(void (CrewDrone::*)()), ".415641554154554889fd534883ec10488b87e808000048c707????????48c78748070000????????488d78e84881ff????????0f8526030000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewDrone::destructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func342::func)
		 : "rdi"
	);
}

namespace _func343
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewDrone::SetCurrentShip", typeid(void (CrewDrone::*)(int )), ".488b87c000000089b78c010000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewDrone::SetCurrentShip(int shipId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shipId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func343::func)
		 : "rdi", "rsi"
	);
}

namespace _func344
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewEquipBox::RemoveItem", typeid(void (CrewEquipBox::*)()), "534889fb488bbf800000004885ff", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewEquipBox::RemoveItem()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func344::func)
		 : "rdi"
	);
}

namespace _func345
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewEquipBox::GetConfirmDelete", typeid(bool (CrewEquipBox::*)()), ".0fb68730030000c6873003000000", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewEquipBox::GetConfirmDelete()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func345::func)
		 : "rdi"
	);
}

namespace _func346
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewEquipBox::CloseRename", typeid(void (CrewEquipBox::*)()), ".80bfba020000007507", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewEquipBox::CloseRename()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func346::func)
		 : "rdi"
	);
}

namespace _func347
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CrewEquipBox::RenderLabels", typeid(void (CrewEquipBox::*)(bool , bool )), ".4154554889fd534883ec60488b47704885c0", argdata, 3, 6, &func);
}

FUNC_NAKED void CrewEquipBox::RenderLabels(bool dragging, bool isNew)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has dragging
			// rdx has isNew
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func347::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func348
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewEquipBox::MouseClick", typeid(void (CrewEquipBox::*)()), ".55534889fb4883ec3848837f7000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewEquipBox::MouseClick()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func348::func)
		 : "rdi"
	);
}

namespace _func349
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewEquipBox::OnTextInput", typeid(void (CrewEquipBox::*)(SDLKey )), ".5589f553488d9fc00200004883ec084889df", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewEquipBox::OnTextInput(SDLKey key)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has key
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func349::func)
		 : "rdi", "rsi"
	);
}

namespace _func350
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewEquipBox::OnTextEvent", typeid(void (CrewEquipBox::*)(CEvent::TextEvent )), ".5589f553488d9fc00200004883ec084889df", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewEquipBox::OnTextEvent(CEvent::TextEvent event)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has event
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func350::func)
		 : "rdi", "rsi"
	);
}

namespace _func351
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CrewEquipBox::constructor", typeid(void (CrewEquipBox::*)(Point , ShipManager *, int )), ".415741564189ce41554989d5ba4300000041544989f449c1fc20", argdata, 4, 6, &func);
}

FUNC_NAKED void CrewEquipBox::constructor(Point pos, ShipManager *ship, int slot)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
			// rdx has ship
			// rcx has slot
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func351::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func352
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewEquipBox::OnRender", typeid(void (CrewEquipBox::*)(bool )), ".415541545589f5534889fb", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewEquipBox::OnRender(bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func352::func)
		 : "rdi", "rsi"
	);
}

namespace _func353
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewManifest::constructor", typeid(void (CrewManifest::*)()), "4155415455534889fb4c8d63284881ec88000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewManifest::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func353::func)
		 : "rdi"
	);
}

namespace _func354
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewManifest::OnKeyDown", typeid(void (CrewManifest::*)(SDLKey )), ".41554189f541544989fc5531ed5331db4883ec08", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewManifest::OnKeyDown(SDLKey key)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has key
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func354::func)
		 : "rdi", "rsi"
	);
}

namespace _func355
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewManifest::OnKeyUp", typeid(void (CrewManifest::*)(SDLKey )), ".41554189f541544989fc5531ed5331db4883ec08", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewManifest::OnKeyUp(SDLKey key)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has key
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func355::func)
		 : "rdi", "rsi"
	);
}

namespace _func356
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewManifest::OnTextInput", typeid(void (CrewManifest::*)(SDLKey )), ".41554189f541544989fc5531ed5331db4883ec08", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewManifest::OnTextInput(SDLKey key)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has key
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func356::func)
		 : "rdi", "rsi"
	);
}

namespace _func357
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewManifest::OnTextEvent", typeid(void (CrewManifest::*)(CEvent::TextEvent )), ".41554189f541544989fc5531ed5331db4883ec08", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewManifest::OnTextEvent(CEvent::TextEvent event)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has event
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func357::func)
		 : "rdi", "rsi"
	);
}

namespace _func358
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewManifest::Update", typeid(void (CrewManifest::*)()), ".415431d231c9554889fd", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewManifest::Update()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func358::func)
		 : "rdi"
	);
}

namespace _func359
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewManifest::OnInit", typeid(void (CrewManifest::*)(ShipManager *)), ".4157415641554989f5415455534889fb4883ec38488b8fc0000000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewManifest::OnInit(ShipManager *ship)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ship
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func359::func)
		 : "rdi", "rsi"
	);
}

namespace _func360
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewManifest::Close", typeid(void (CrewManifest::*)()), "!.41544989fc5531ed53488b97b8000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewManifest::Close()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func360::func)
		 : "rdi"
	);
}

namespace _func361
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CrewManifest::MouseClick", typeid(void (CrewManifest::*)(int , int )), "!.55534889fb4883ec088b87a8010000", argdata, 3, 6, &func);
}

FUNC_NAKED void CrewManifest::MouseClick(int mX, int mY)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mX
			// rdx has mY
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func361::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func362
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewManifest::OnRender", typeid(void (CrewManifest::*)()), ".4155415455534889fb4883ec68", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewManifest::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func362::func)
		 : "rdi"
	);
}

namespace _func363
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CrewManifest::MouseMove", typeid(void (CrewManifest::*)(int , int )), ".4157488d87d0000000415641554189d541544189f4554889fd4889c7534883ec18", argdata, 3, 6, &func);
}

FUNC_NAKED void CrewManifest::MouseMove(int mX, int mY)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mX
			// rdx has mY
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func363::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func364
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::InsideRoom", typeid(bool (CrewMember::*)(int )), "39b79c0000000f94c0", argdata, 2, 2, &func);
}

FUNC_NAKED bool CrewMember::InsideRoom(int roomId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func364::func)
		 : "rdi", "rsi"
	);
}

namespace _func365
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::GetRoomDamage", typeid(Damage (CrewMember::*)()), ".4889f8c70700000000c7470400000000", argdata, 2, 2, &func);
}

FUNC_NAKED Damage CrewMember::GetRoomDamage()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func365::func)
		 : "rdi", "rsi"
	);
}

namespace _func366
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::GetUniqueRepairing", typeid(std::string (CrewMember::*)()), ".53be????????4889fb4883ec10", argdata, 2, 2, &func);
}

FUNC_NAKED std::string CrewMember::GetUniqueRepairing()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func366::func)
		 : "rdi", "rsi"
	);
}

namespace _func367
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::CanTeleport", typeid(bool (CrewMember::*)()), ".53488b87c00000004889fb83786003", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::CanTeleport()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func367::func)
		 : "rdi"
	);
}

namespace _func368
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::Jump", typeid(void (CrewMember::*)()), ".488b87e804000083400c01", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::Jump()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func368::func)
		 : "rdi"
	);
}

namespace _func369
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::SetOutOfGame", typeid(void (CrewMember::*)()), ".8b05????????c6871002000001c6872002000001", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::SetOutOfGame()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func369::func)
		 : "rdi"
	);
}

namespace _func370
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::PositionShift", typeid(float (CrewMember::*)()), ".f30f10470cf30f2a8fb4000000", argdata, 1, 2, &func);
}

FUNC_NAKED float CrewMember::PositionShift()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func370::func)
		 : "rdi"
	);
}

namespace _func371
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::OnRender", typeid(void (CrewMember::*)(bool )), ".55534889fb4883ec1880bf2002000000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::OnRender(bool outlineOnly)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has outlineOnly
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func371::func)
		 : "rdi", "rsi"
	);
}

namespace _func372
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::CanHeal", typeid(bool (CrewMember::*)()), ".534889fbf30f10472c0f2e4730", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::CanHeal()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func372::func)
		 : "rdi"
	);
}

namespace _func373
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::SaveState", typeid(void (CrewMember::*)(int )), "!.41544989fc5589f55331dbf30f1087f0060000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::SaveState(int fileHelper)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has fileHelper
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func373::func)
		 : "rdi", "rsi"
	);
}

namespace _func374
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::destructor", typeid(void (CrewMember::*)()), ".415641554989fd415455534883ec1048c707", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::destructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func374::func)
		 : "rdi"
	);
}

namespace _func375
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::Cleanup", typeid(void (CrewMember::*)()), "!.534889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::Cleanup()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func375::func)
		 : "rdi"
	);
}

namespace _func376
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::LoadState", typeid(void (CrewMember::*)(int )), ".41544989fc89f75589f553", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::LoadState(int fileHelper)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has fileHelper
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func376::func)
		 : "rdi", "rsi"
	);
}

namespace _func377
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::SetCurrentSystem", typeid(void (CrewMember::*)(ShipSystem *)), ".554889f5534889fb4883ec08488b07c6872802000000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::SetCurrentSystem(ShipSystem *sys)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has sys
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func377::func)
		 : "rdi", "rsi"
	);
}

namespace _func378
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::IsManningArtillery", typeid(bool (CrewMember::*)()), ".83bfa00000000b0f94c0", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::IsManningArtillery()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func378::func)
		 : "rdi"
	);
}

namespace _func379
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::IncreaseSkill", typeid(void (CrewMember::*)(int )), ".4156415541545589f5534889fb4883ec20488b07", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::IncreaseSkill(int skillId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has skillId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func379::func)
		 : "rdi", "rsi"
	);
}

namespace _func380
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::CheckSkills", typeid(void (CrewMember::*)()), ".415455534889fb488bbf30020000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::CheckSkills()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func380::func)
		 : "rdi"
	);
}

namespace _func381
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::MasterSkill", typeid(void (CrewMember::*)(int )), ".488b87f80200004863f6", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::MasterSkill(int skillId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has skillId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func381::func)
		 : "rdi", "rsi"
	);
}

namespace _func382
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::GetSkillFromSystem", typeid(int (*)(int )), ".83ff01742b83ff06", argdata, 1, 2, &func);
}

FUNC_NAKED int CrewMember::GetSkillFromSystem(int systemId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has systemId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func382::func)
		 : "rdi"
	);
}

namespace _func383
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::SetResisted", typeid(void (CrewMember::*)(bool )), ".4088b7dc060000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::SetResisted(bool resisted)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has resisted
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func383::func)
		 : "rdi", "rsi"
	);
}

namespace _func384
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::GetResisted", typeid(bool (CrewMember::*)()), ".0fb687dc060000", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::GetResisted()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func384::func)
		 : "rdi"
	);
}

namespace _func385
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CrewMember::SetSkillProgress", typeid(void (CrewMember::*)(int , int )), ".488b87f80200004863f6", argdata, 3, 6, &func);
}

FUNC_NAKED void CrewMember::SetSkillProgress(int skillId, int skillLevel)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has skillId
			// rdx has skillLevel
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func385::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func386
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::GetSkillLevel", typeid(int (CrewMember::*)(int )), ".83fe05b801000000", argdata, 2, 2, &func);
}

FUNC_NAKED int CrewMember::GetSkillLevel(int skillId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has skillId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func386::func)
		 : "rdi", "rsi"
	);
}

namespace _func387
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::GetSkillProgress", typeid(std::pair<int, int> (CrewMember::*)(int )), ".488b87f80200004863f6488d14f0", argdata, 2, 2, &func);
}

FUNC_NAKED std::pair<int, int> CrewMember::GetSkillProgress(int skillId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has skillId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func387::func)
		 : "rdi", "rsi"
	);
}

namespace _func388
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::GetSkillModifier", typeid(float (CrewMember::*)(int )), "!.83fe0589f2b801000000", argdata, 2, 2, &func);
}

FUNC_NAKED float CrewMember::GetSkillModifier(int skillId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has skillId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func388::func)
		 : "rdi", "rsi"
	);
}

namespace _func389
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::BadAtCombat", typeid(bool (CrewMember::*)()), ".488b07534889fb", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::BadAtCombat()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func389::func)
		 : "rdi"
	);
}

namespace _func390
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::EmptySlot", typeid(void (CrewMember::*)()), ".534889fb4883ec108b97ac00000085d2", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::EmptySlot()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func390::func)
		 : "rdi"
	);
}

namespace _func391
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::NeedsSlot", typeid(bool (CrewMember::*)()), ".80bf20020000007509", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::NeedsSlot()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func391::func)
		 : "rdi"
	);
}

namespace _func392
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("CrewMember::DirectModifyHealth", typeid(bool (CrewMember::*)(float )), ".530f57d24889fb4883ec30f30f105f2c0f2ed3", argdata, 2, 2, &func);
}

FUNC_NAKED bool CrewMember::DirectModifyHealth(float health)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has health
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func392::func)
		 : "rdi", "xmm0"
	);
}

namespace _func393
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("CrewMember::ModifyHealth", typeid(void (CrewMember::*)(float )), "!.534889fbbf????????4883ec10", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::ModifyHealth(float health)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has health
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func393::func)
		 : "rdi", "xmm0"
	);
}

namespace _func394
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("CrewMember::ApplyDamage", typeid(bool (CrewMember::*)(float )), ".534889fb4883ec10f30f104f2cf30f114c240c", argdata, 2, 2, &func);
}

FUNC_NAKED bool CrewMember::ApplyDamage(float damage)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has damage
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func394::func)
		 : "rdi", "xmm0"
	);
}

namespace _func395
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::RepairingSystem", typeid(bool (CrewMember::*)()), ".534883bf88000000004889fb", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::RepairingSystem()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func395::func)
		 : "rdi"
	);
}

namespace _func396
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::Sabotaging", typeid(bool (CrewMember::*)()), ".534889fb488bbf880000004885ff", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::Sabotaging()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func396::func)
		 : "rdi"
	);
}

namespace _func397
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::RepairingFire", typeid(bool (CrewMember::*)()), ".31c04883bf8800000000", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::RepairingFire()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func397::func)
		 : "rdi"
	);
}

namespace _func398
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::SelectSabotageTarget", typeid(Pointf (CrewMember::*)()), ".55534889fb4883ec38488bbf88000000", argdata, 1, 2, &func);
}

FUNC_NAKED Pointf CrewMember::SelectSabotageTarget()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func398::func)
		 : "rdi"
	);
}

namespace _func399
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::SavePosition", typeid(void (CrewMember::*)()), ".488b87ac000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::SavePosition()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func399::func)
		 : "rdi"
	);
}

namespace _func400
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::ClearPosition", typeid(void (CrewMember::*)()), ".c787e4060000ffffffff", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::ClearPosition()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func400::func)
		 : "rdi"
	);
}

namespace _func401
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::GetSavedPosition", typeid(Slot (CrewMember::*)()), ".488b87e0060000", argdata, 1, 10, &func);
}

FUNC_NAKED Slot CrewMember::GetSavedPosition()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func401::func)
		 : "rdi"
	);
}

namespace _func402
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x2ff};
	static FunctionDefinition funcObj("CrewMember::SetSavePosition", typeid(void (CrewMember::*)(Slot )), ".4889b7e0060000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::SetSavePosition(Slot position)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// position
		"pushq 8(%%rbp)\n\t"		// position
			// rdi has this
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func402::func)
		 : "rdi"
	);
}

namespace _func403
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::StopRepairing", typeid(void (CrewMember::*)()), ".534883bf88000000004889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::StopRepairing()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func403::func)
		 : "rdi"
	);
}

namespace _func404
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::Repairing", typeid(bool (CrewMember::*)()), ".4883bf88000000000f95c0", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::Repairing()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func404::func)
		 : "rdi"
	);
}

namespace _func405
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::SetFrozen", typeid(void (CrewMember::*)(bool )), ".4084f6741b80bfd401000000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::SetFrozen(bool frozen)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has frozen
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func405::func)
		 : "rdi", "rsi"
	);
}

namespace _func406
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::SetFrozenLocation", typeid(void (CrewMember::*)(bool )), ".4088b7d5010000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::SetFrozenLocation(bool frozenLocation)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has frozenLocation
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func406::func)
		 : "rdi", "rsi"
	);
}

namespace _func407
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x2ff};
	static FunctionDefinition funcObj("CrewMember::SetTask", typeid(void (CrewMember::*)(CrewTask )), ".4889b7d80100008997e0010000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::SetTask(CrewTask task)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// task
		"pushq 8(%%rbp)\n\t"		// task
			// rdi has this
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func407::func)
		 : "rdi"
	);
}

namespace _func408
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CrewMember::FindSlot", typeid(Slot (CrewMember::*)(int , int , bool )), ".4155415455534889fb4883ec18488bbff0010000", argdata, 4, 10, &func);
}

FUNC_NAKED Slot CrewMember::FindSlot(int unk1, int roomId, bool unk2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk1
			// rdx has roomId
			// rcx has unk2
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func408::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func409
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::CheckRoomPath", typeid(bool (CrewMember::*)(int )), ".415531c9baffffffff41544531e4554889fd5389f34883ec38", argdata, 2, 2, &func);
}

FUNC_NAKED bool CrewMember::CheckRoomPath(int roomId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func409::func)
		 : "rdi", "rsi"
	);
}

namespace _func410
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::NeedsIntruderSlot", typeid(bool (CrewMember::*)()), ".80bf31050000008b4708", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::NeedsIntruderSlot()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func410::func)
		 : "rdi"
	);
}

namespace _func411
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::SetPosition", typeid(void (CrewMember::*)(Point )), ".f30f2ace4889f248c1fa2055f30f2ac2534889fb4883ec18", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::SetPosition(Point pos)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func411::func)
		 : "rdi", "rsi"
	);
}

namespace _func412
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::ClearTask", typeid(void (CrewMember::*)()), ".8b879c000000c787e0010000ffffffff", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::ClearTask()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func412::func)
		 : "rdi"
	);
}

namespace _func413
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::ClearPath", typeid(void (CrewMember::*)()), ".55534889fb4883ec38488b07", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::ClearPath()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func413::func)
		 : "rdi"
	);
}

namespace _func414
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::SetRoom", typeid(void (CrewMember::*)(int )), ".4155415455534889fb4883ec184883bff001000000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::SetRoom(int roomId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func414::func)
		 : "rdi", "rsi"
	);
}

namespace _func415
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::IsBusy", typeid(bool (CrewMember::*)()), ".4883bf8800000000b801000000", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::IsBusy()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func415::func)
		 : "rdi"
	);
}

namespace _func416
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::OnInit", typeid(bool (CrewMember::*)()), ".c747241e00000048c7878000000000000000", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::OnInit()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func416::func)
		 : "rdi"
	);
}

namespace _func417
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::GetFinalGoal", typeid(Point (CrewMember::*)()), ".f30f1005????????0f2e4768", argdata, 1, 2, &func);
}

FUNC_NAKED Point CrewMember::GetFinalGoal()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func417::func)
		 : "rdi"
	);
}

namespace _func418
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::GetNextGoal", typeid(Point (CrewMember::*)()), ".534889fb4883ec20f30f104720", argdata, 1, 2, &func);
}

FUNC_NAKED Point CrewMember::GetNextGoal()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func418::func)
		 : "rdi"
	);
}

namespace _func419
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::CloseDoorBehind", typeid(void (CrewMember::*)(Door *)), ".4889b780000000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::CloseDoorBehind(Door *door)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has door
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func419::func)
		 : "rdi", "rsi"
	);
}

namespace _func420
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::GetMoveSpeed", typeid(float (CrewMember::*)()), ".55be????????31ed534889fb4883ec38", argdata, 1, 2, &func);
}

FUNC_NAKED float CrewMember::GetMoveSpeed()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func420::func)
		 : "rdi"
	);
}

namespace _func421
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::Restart", typeid(void (CrewMember::*)()), ".4155415449bcabaaaaaaaaaaaaaa5531ed534889fb4883ec18", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::Restart()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func421::func)
		 : "rdi"
	);
}

namespace _func422
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("CrewMember::SetDamageBoost", typeid(void (CrewMember::*)(float )), ".f30f1187d4060000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::SetDamageBoost(float damageBoost)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has damageBoost
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func422::func)
		 : "rdi", "xmm0"
	);
}

namespace _func423
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::SetHealthBoost", typeid(void (CrewMember::*)(int )), ".538b87d00600004889fb39f0", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::SetHealthBoost(int healthBoost)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has healthBoost
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func423::func)
		 : "rdi", "rsi"
	);
}

namespace _func424
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::InitializeSkills", typeid(void (CrewMember::*)()), ".554889fd5331db4883ec08", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::InitializeSkills()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func424::func)
		 : "rdi"
	);
}

namespace _func425
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::SetCloneReady", typeid(void (CrewMember::*)(bool )), ".534889fb4883ec2080bf2002000000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::SetCloneReady(bool cloneReady)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has cloneReady
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func425::func)
		 : "rdi", "rsi"
	);
}

namespace _func426
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::Kill", typeid(void (CrewMember::*)(bool )), ".5589f5534889fb4883ec284883bf8800000000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::Kill(bool noClone)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has noClone
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func426::func)
		 : "rdi", "rsi"
	);
}

namespace _func427
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::NeedFrozenLocation", typeid(bool (CrewMember::*)()), ".31c080bfd401000000", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::NeedFrozenLocation()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func427::func)
		 : "rdi"
	);
}

namespace _func428
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::CheckForTeleport", typeid(void (CrewMember::*)()), ".55534889fb4883ec08488bafc0000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::CheckForTeleport()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func428::func)
		 : "rdi"
	);
}

namespace _func429
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::SetCurrentShip", typeid(void (CrewMember::*)(int )), ".488b87c000000089b78c010000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::SetCurrentShip(int shipId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shipId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func429::func)
		 : "rdi", "rsi"
	);
}

namespace _func430
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::CheckFighting", typeid(void (CrewMember::*)()), ".4883bfb801000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::CheckFighting()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func430::func)
		 : "rdi"
	);
}

namespace _func431
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::SetDeathNumber", typeid(void (CrewMember::*)(int )), ".3b35????????89b734050000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::SetDeathNumber(int deathNum)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has deathNum
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func431::func)
		 : "rdi", "rsi"
	);
}

namespace _func432
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::ForceMindControl", typeid(void (CrewMember::*)(bool )), ".4088b731050000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::ForceMindControl(bool force)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has force
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func432::func)
		 : "rdi", "rsi"
	);
}

namespace _func433
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::RenderSkillUpAnimation", typeid(void (CrewMember::*)(Point )), ".41574989ff415641554531ed41544989f449c1fc20554889f5534883ec38", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::RenderSkillUpAnimation(Point pos)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func433::func)
		 : "rdi", "rsi"
	);
}

namespace _func434
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::Clone", typeid(void (CrewMember::*)()), ".55534889fb4883ec28c6871002000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::Clone()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func434::func)
		 : "rdi"
	);
}

namespace _func435
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::UpdateHealth", typeid(void (CrewMember::*)()), ".55534889fb4883ec488b872402000085c0", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::UpdateHealth()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func435::func)
		 : "rdi"
	);
}

namespace _func436
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::OnRenderPath", typeid(void (CrewMember::*)()), ".534889fb4883ec108b4f0885c9", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::OnRenderPath()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func436::func)
		 : "rdi"
	);
}

namespace _func437
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::SetPath", typeid(bool (CrewMember::*)(Path *)), ".4157415641554154554889f5534889fb4883ec28", argdata, 2, 2, &func);
}

FUNC_NAKED bool CrewMember::SetPath(Path *path)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has path
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func437::func)
		 : "rdi", "rsi"
	);
}

namespace _func438
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CrewMember::SetRoomPath", typeid(void (CrewMember::*)(int , int )), ".415455534889fb4883ec30488bbff0010000", argdata, 3, 6, &func);
}

FUNC_NAKED void CrewMember::SetRoomPath(int slotId, int roomId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has slotId
			// rdx has roomId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func438::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func439
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::GetLocation", typeid(Point (CrewMember::*)()), ".534889fb4883ec20f30f104710", argdata, 1, 2, &func);
}

FUNC_NAKED Point CrewMember::GetLocation()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func439::func)
		 : "rdi"
	);
}

namespace _func440
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::AtGoal", typeid(bool (CrewMember::*)()), ".f30f105f1c", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::AtGoal()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func440::func)
		 : "rdi"
	);
}

namespace _func441
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::AtFinalGoal", typeid(bool (CrewMember::*)()), ".f30f10470cf30f2a8fb4000000", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::AtFinalGoal()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func441::func)
		 : "rdi"
	);
}

namespace _func442
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::OnRenderHealth", typeid(void (CrewMember::*)()), ".4155415455534889fb4883ec7880bf2002000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::OnRenderHealth()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func442::func)
		 : "rdi"
	);
}

namespace _func443
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::GetIntegerHealth", typeid(int (CrewMember::*)()), ".31c080bf2002000000", argdata, 1, 2, &func);
}

FUNC_NAKED int CrewMember::GetIntegerHealth()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func443::func)
		 : "rdi"
	);
}

namespace _func444
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::GetRepairingId", typeid(int (CrewMember::*)()), ".488bbf880000004885ff", argdata, 1, 2, &func);
}

FUNC_NAKED int CrewMember::GetRepairingId()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func444::func)
		 : "rdi"
	);
}

namespace _func445
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("CrewMember::WithinRect", typeid(bool (CrewMember::*)(int , int , int , int )), ".85c9784c4585c0783f", argdata, 5, 2, &func);
}

FUNC_NAKED bool CrewMember::WithinRect(int x, int y, int w, int h)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
			// rcx has w
			// r8 has h
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func445::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func446
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::GetLongName", typeid(std::string (CrewMember::*)()), ".5380bed0020000004889fb", argdata, 2, 2, &func);
}

FUNC_NAKED std::string CrewMember::GetLongName()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func446::func)
		 : "rdi", "rsi"
	);
}

namespace _func447
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CrewMember::SetName", typeid(void (CrewMember::*)(TextString *, bool )), ".41544189d4554889f5534889fb488dbfc80200004883ec40", argdata, 3, 6, &func);
}

FUNC_NAKED void CrewMember::SetName(TextString *name, bool force)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has name
			// rdx has force
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func447::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func448
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::GetName", typeid(std::string (CrewMember::*)()), ".5380bec0020000004889fb", argdata, 2, 2, &func);
}

FUNC_NAKED std::string CrewMember::GetName()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func448::func)
		 : "rdi", "rsi"
	);
}

namespace _func449
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CrewMember::SetCurrentTarget", typeid(void (CrewMember::*)(CrewTarget *, bool )), ".41544189d4554889f553488b074889fb", argdata, 3, 6, &func);
}

FUNC_NAKED void CrewMember::SetCurrentTarget(CrewTarget *target, bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has target
			// rdx has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func449::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func450
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::GetNewGoal", typeid(bool (CrewMember::*)()), ".41574989ff41564155415455534883ec28", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::GetNewGoal()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func450::func)
		 : "rdi"
	);
}

namespace _func451
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CrewMember::MoveToRoom", typeid(bool (CrewMember::*)(int , int , bool )), ".4157415641554189d541544189cc5589f5534889fb4883ec48", argdata, 4, 2, &func);
}

FUNC_NAKED bool CrewMember::MoveToRoom(int roomId, int slotId, bool forceMove)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
			// rdx has slotId
			// rcx has forceMove
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func451::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func452
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::SetMindControl", typeid(void (CrewMember::*)(bool )), ".5589f5534889fb4883ec084038b731050000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::SetMindControl(bool controlled)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has controlled
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func452::func)
		 : "rdi", "rsi"
	);
}

namespace _func453
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::RestorePosition", typeid(bool (CrewMember::*)()), ".415741564155415455534889fb4883ec48488b07", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::RestorePosition()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func453::func)
		 : "rdi"
	);
}

namespace _func454
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CrewMember::ContainsPoint", typeid(bool (CrewMember::*)(int , int )), ".f30f1005????????f30f594718", argdata, 3, 2, &func);
}

FUNC_NAKED bool CrewMember::ContainsPoint(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func454::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func455
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("CrewMember::SetMedbay", typeid(void (CrewMember::*)(float )), ".534889fb4883ec10488b07f30f1144240c", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::SetMedbay(float health)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has health
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func455::func)
		 : "rdi", "xmm0"
	);
}

namespace _func456
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::StartTeleport", typeid(void (CrewMember::*)()), "!.53488b9fc000000031f60f57c0", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::StartTeleport()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func456::func)
		 : "rdi"
	);
}

namespace _func457
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::StartTeleportArrive", typeid(void (CrewMember::*)()), "!.53488b9fc000000031f60f57c0", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::StartTeleportArrive()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func457::func)
		 : "rdi"
	);
}

namespace _func458
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::StartRepair", typeid(void (CrewMember::*)(Repairable *)), ".55534889fb4883ec28f30f10470c", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::StartRepair(Repairable *toRepair)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has toRepair
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func458::func)
		 : "rdi", "rsi"
	);
}

namespace _func459
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::UpdateRepair", typeid(void (CrewMember::*)()), ".55534889fb4883ec48488bbf88000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::UpdateRepair()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func459::func)
		 : "rdi"
	);
}

namespace _func460
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::UpdateMovement", typeid(void (CrewMember::*)()), ".534889fb4883ec30488b87c000000083786006", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::UpdateMovement()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func460::func)
		 : "rdi"
	);
}

namespace _func461
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::OnLoop", typeid(void (CrewMember::*)()), ".415741564155415455534889fb4883ec7880bf2002000000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMember::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func461::func)
		 : "rdi"
	);
}

namespace _func462
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::GetTooltip", typeid(std::string (CrewMember::*)()), ".4157415641554154554889f5", argdata, 2, 2, &func);
}

FUNC_NAKED std::string CrewMember::GetTooltip()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func462::func)
		 : "rdi", "rsi"
	);
}

namespace _func463
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::SetSex", typeid(void (CrewMember::*)(bool )), ".5589f5534889fb4883ec08488bbfc0000000", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::SetSex(bool male)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has male
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func463::func)
		 : "rdi", "rsi"
	);
}

namespace _func464
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMember::CycleColorLayer", typeid(void (CrewMember::*)(int )), ".4155415449bcabaaaaaaaaaaaaaa55534889fb4883ec48", argdata, 2, 6, &func);
}

FUNC_NAKED void CrewMember::CycleColorLayer(int unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func464::func)
		 : "rdi", "rsi"
	);
}

namespace _func465
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("CrewMember::constructor", typeid(void (CrewMember::*)(CrewBlueprint &, int , bool , CrewAnimation *)), ".415741564189d641554d89c541544189cc554889f5534889fb488d7f404881ecb8000000", argdata, 5, 6, &func);
}

FUNC_NAKED void CrewMember::constructor(CrewBlueprint &blueprint, int shipId, bool intruder, CrewAnimation *animation)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has blueprint
			// rdx has shipId
			// rcx has intruder
			// r8 has animation
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func465::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func466
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::Functional", typeid(bool (CrewMember::*)()), ".4883ec08488b07", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::Functional()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func466::func)
		 : "rdi"
	);
}

namespace _func467
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::CountForVictory", typeid(bool (CrewMember::*)()), ".488b07534889fb", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::CountForVictory()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func467::func)
		 : "rdi"
	);
}

namespace _func468
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::CanSabotage", typeid(bool (CrewMember::*)()), ".0fb687bc000000", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::CanSabotage()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func468::func)
		 : "rdi"
	);
}

namespace _func469
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::CanMan", typeid(bool (CrewMember::*)()), ".31c080bfbc00000000", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::CanMan()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func469::func)
		 : "rdi"
	);
}

namespace _func470
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::CanRepair", typeid(bool (CrewMember::*)()), ".5380bfbc00000000", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::CanRepair()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func470::func)
		 : "rdi"
	);
}

namespace _func471
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMember::GetControllable", typeid(bool (CrewMember::*)()), ".538b570831c04889fb85d2", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMember::GetControllable()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func471::func)
		 : "rdi"
	);
}

namespace _func472
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMemberFactory::destructor", typeid(void (CrewMemberFactory::*)()), "554889fd534883ec08488b7718488b57104889f04829d048c1f8034885c0", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMemberFactory::destructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func472::func)
		 : "rdi"
	);
}

namespace _func473
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMemberFactory::Restart", typeid(void (CrewMemberFactory::*)()), ".53488b4f184889fb488b47104889ca4829c248c1fa034885d2", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMemberFactory::Restart()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func473::func)
		 : "rdi"
	);
}

namespace _func474
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMemberFactory::CountCloneReadyCrew", typeid(int (CrewMemberFactory::*)(bool )), ".41564989fe415541545553488b4710488b57184829c2", argdata, 2, 2, &func);
}

FUNC_NAKED int CrewMemberFactory::CountCloneReadyCrew(bool player)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has player
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func474::func)
		 : "rdi", "rsi"
	);
}

namespace _func475
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewPortraitList", typeid(void (CrewMemberFactory::*)(std::vector<CrewMember*> *, int )), ".415731c94989ff4156415549bdffffffffffffff1f41544989f45589d55331db4883ec18", argdata, 3, 6, &func);
}

FUNC_NAKED void CrewMemberFactory::GetCrewPortraitList(std::vector<CrewMember*> *vec, int teamId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has vec
			// rdx has teamId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func475::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func476
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewList", typeid(void (CrewMemberFactory::*)(std::vector<CrewMember*> *, int , bool )), ".41574531c04531ff415641554989fd41544989f45589cd5389d34883ec18", argdata, 4, 6, &func);
}

FUNC_NAKED void CrewMemberFactory::GetCrewList(std::vector<CrewMember*> *vec, int unk, bool unk2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has vec
			// rdx has unk
			// rcx has unk2
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func476::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func477
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMemberFactory::GetPlayerCrewCount", typeid(int (CrewMemberFactory::*)()), "!.8b07c3906666662e0f1f840000000000", argdata, 1, 2, &func);
}

FUNC_NAKED int CrewMemberFactory::GetPlayerCrewCount()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func477::func)
		 : "rdi"
	);
}

namespace _func478
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMemberFactory::GetEnemyCloneCount", typeid(int (CrewMemberFactory::*)()), "!.8b4708c36666662e0f1f840000000000", argdata, 1, 2, &func);
}

FUNC_NAKED int CrewMemberFactory::GetEnemyCloneCount()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func478::func)
		 : "rdi"
	);
}

namespace _func479
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewCount", typeid(int (CrewMemberFactory::*)(bool )), ".8b47044084f6", argdata, 2, 2, &func);
}

FUNC_NAKED int CrewMemberFactory::GetCrewCount(bool enemy)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has enemy
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func479::func)
		 : "rdi", "rsi"
	);
}

namespace _func480
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMemberFactory::GetEnemyCrewCount", typeid(int (CrewMemberFactory::*)()), "!.8b4704c36666662e0f1f840000000000", argdata, 1, 2, &func);
}

FUNC_NAKED int CrewMemberFactory::GetEnemyCrewCount()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func480::func)
		 : "rdi"
	);
}

namespace _func481
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMemberFactory::IsRace", typeid(bool (*)(const std::string &)), ".53be????????", argdata, 1, 2, &func);
}

FUNC_NAKED bool CrewMemberFactory::IsRace(const std::string &species)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has species
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func481::func)
		 : "rdi"
	);
}

namespace _func482
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CrewMemberFactory::CreateBoarderDrone", typeid(BoarderDrone *(CrewMemberFactory::*)(int , const DroneBlueprint *)), ".415641554189f5", argdata, 3, 2, &func);
}

FUNC_NAKED BoarderDrone *CrewMemberFactory::CreateBoarderDrone(int shipId, const DroneBlueprint *bp)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shipId
			// rdx has bp
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func482::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func483
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CrewMemberFactory::CreateBattleDrone", typeid(BattleDrone *(CrewMemberFactory::*)(int , const DroneBlueprint *)), ".415641554989d541544189f4554889fdbf20090000534883ec40", argdata, 3, 2, &func);
}

FUNC_NAKED BattleDrone *CrewMemberFactory::CreateBattleDrone(int shipId, const DroneBlueprint *bp)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shipId
			// rdx has bp
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func483::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func484
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCloneReadyList", typeid(void (CrewMemberFactory::*)(std::vector<CrewMember*> &, bool )), ".4157415641554989fd41544189d431d2554889f55331db4883ec18", argdata, 3, 6, &func);
}

FUNC_NAKED void CrewMemberFactory::GetCloneReadyList(std::vector<CrewMember*> &vec, bool player)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has vec
			// rdx has player
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func484::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func485
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("CrewMemberFactory::CreateRepairDrone", typeid(RepairDrone *(CrewMemberFactory::*)(int , const DroneBlueprint *)), ".41570f57c94989d741564989fe0f28c1415541545589f5534883ec68", argdata, 3, 2, &func);
}

FUNC_NAKED RepairDrone *CrewMemberFactory::CreateRepairDrone(int shipId, const DroneBlueprint *bp)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shipId
			// rdx has bp
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func485::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func486
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMemberFactory::GetRandomFriendlyName", typeid(std::pair<std::string, bool> (CrewMemberFactory::*)(const std::string &)), ".4157415641554989f54154554889fd534889d34883ec68", argdata, 2, 2, &func);
}

FUNC_NAKED std::pair<std::string, bool> CrewMemberFactory::GetRandomFriendlyName(const std::string &race)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has race
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func486::func)
		 : "rdi", "rsi"
	);
}

namespace _func487
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewNames", typeid(std::vector<std::string> (CrewMemberFactory::*)()), ".415631d241554989fd41544989f4555331db4883ec20", argdata, 2, 2, &func);
}

FUNC_NAKED std::vector<std::string> CrewMemberFactory::GetCrewNames()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func487::func)
		 : "rdi", "rsi"
	);
}

namespace _func488
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMemberFactory::OnLoop", typeid(void (CrewMemberFactory::*)()), ".415741564155415455534889fb4881ecb8000000488b5710", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMemberFactory::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func488::func)
		 : "rdi"
	);
}

namespace _func489
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewMemberFactory::RemoveExcessCrew", typeid(void (CrewMemberFactory::*)()), "!.415431c0554889fd53488b4f1031db488b57184829ca", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewMemberFactory::RemoveExcessCrew()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func489::func)
		 : "rdi"
	);
}

namespace _func490
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CrewMemberFactory::CreateCrewMember", typeid(CrewMember *(CrewMemberFactory::*)(CrewBlueprint *, int , bool )), ".415741564189ce41554189d541544989f455488d6e08", argdata, 4, 2, &func);
}

FUNC_NAKED CrewMember *CrewMemberFactory::CreateCrewMember(CrewBlueprint *bp, int shipId, bool intruder)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has bp
			// rdx has shipId
			// rcx has intruder
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func490::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

CrewMemberFactory *Global_CrewMemberFactory_Factory;

namespace _var491
{
	static VariableDefinition varObj("Global_CrewMemberFactory_Factory", "!f30f11834802000031c9bf(???????\?)ba020000004889e6", &Global_CrewMemberFactory_Factory);
}

namespace _func492
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("CrewStoreBox::Purchase", typeid(void (CrewStoreBox::*)()), "415741564531f641554989fd4154555331db4881ec18010000", argdata, 1, 6, &func);
}

FUNC_NAKED void CrewStoreBox::Purchase()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func492::func)
		 : "rdi"
	);
}

namespace _func493
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("CrewStoreBox::constructor", typeid(void (CrewStoreBox::*)(ShipManager *, int , const std::string &)), "41574989ff415641554154554889f5", argdata, 4, 6, &func);
}

FUNC_NAKED void CrewStoreBox::constructor(ShipManager *ship, int worldLevel, const std::string &type)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ship
			// rdx has worldLevel
			// rcx has type
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func493::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func494
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x106, 0x102};
	static FunctionDefinition funcObj("DamageMessage::constructor", typeid(void (DamageMessage::*)(float , Pointf , DamageMessage::MessageType )), "534889fb4883ec5085f648c707", argdata, 4, 6, &func);
}

FUNC_NAKED void DamageMessage::constructor(float length, Pointf pos, DamageMessage::MessageType type)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has length
			// rsi has pos
			// rdx has type
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func494::func)
		 : "rdi", "xmm0", "rsi", "rdx"
	);
}

namespace _func495
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("DamageMessage::constructor2", typeid(void (DamageMessage::*)(float , int , Pointf , bool )), "415741564155415455534889fb4881ec3803000084d2", argdata, 5, 6, &func);
}

FUNC_NAKED void DamageMessage::constructor2(float length, int amount, Pointf pos, bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has length
			// rsi has amount
			// rdx has pos
			// rcx has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func495::func)
		 : "rdi", "xmm0", "rsi", "rdx", "rcx"
	);
}

namespace _func496
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("DefenseDrone::ValidTargetObject", typeid(bool (DefenseDrone::*)(Targetable *)), "4885f60f84b7000000", argdata, 2, 2, &func);
}

FUNC_NAKED bool DefenseDrone::ValidTargetObject(Targetable *target)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has target
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func496::func)
		 : "rdi", "rsi"
	);
}

namespace _func497
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("DefenseDrone::PickTarget", typeid(void (DefenseDrone::*)()), "55534889fb4883ec4880bf5d02000000", argdata, 1, 6, &func);
}

FUNC_NAKED void DefenseDrone::PickTarget()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func497::func)
		 : "rdi"
	);
}

namespace _func498
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("DefenseDrone::SetWeaponTarget", typeid(void (DefenseDrone::*)(Targetable *)), "4154554889fd53488b074889f3", argdata, 2, 6, &func);
}

FUNC_NAKED void DefenseDrone::SetWeaponTarget(Targetable *target)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has target
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func498::func)
		 : "rdi", "rsi"
	);
}

namespace _func499
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("DefenseDrone::GetTooltip", typeid(std::string (DefenseDrone::*)()), "554889f5be????????534889fb4883ec38488d542420", argdata, 2, 2, &func);
}

FUNC_NAKED std::string DefenseDrone::GetTooltip()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func499::func)
		 : "rdi", "rsi"
	);
}

namespace _func500
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Description::copy_assign_2", typeid(Description &(Description::*)(Description &&)), "554889f5534889fb4883ec08e8????????0fb64508488d7510488d7b10884308e8????????0fb64518488d7520488d7b20884318e8????????0fb64528488d7548488d7b488843288b45308943308b45348943348b45388943388b453c89433c0fb64540884340e8????????0fb64550488d7558", argdata, 2, 2, &func);
}

FUNC_NAKED Description &Description::copy_assign_2(Description &&other)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has other
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func500::func)
		 : "rdi", "rsi"
	);
}

namespace _func501
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Description::copy_assign_1", typeid(Description &(Description::*)(const Description &)), ".554889f5534889fb4883ec08e8????????0fb64508488d7510488d7b10884308e8????????0fb64518488d7520488d7b20884318e8????????0fb64528488d7548488d7b488843288b45308943308b45348943348b45388943388b453c89433c0fb64540884340e8????????0fb64550488d7558", argdata, 2, 2, &func);
}

FUNC_NAKED Description &Description::copy_assign_1(const Description &other)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has other
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func501::func)
		 : "rdi", "rsi"
	);
}

namespace _func502
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Description::destructor", typeid(void (Description::*)()), "534889fb4883ec10488b4758488d78e8", argdata, 1, 6, &func);
}

FUNC_NAKED void Description::destructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func502::func)
		 : "rdi"
	);
}

namespace _func503
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Door::FakeClose", typeid(void (Door::*)()), "55534889fb4883ec080fb64724c6472c00", argdata, 1, 6, &func);
}

FUNC_NAKED void Door::FakeClose()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func503::func)
		 : "rdi"
	);
}

namespace _func504
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Door::IsSealed", typeid(bool (Door::*)(int )), "8b8f4c0200008b570885c9", argdata, 2, 2, &func);
}

FUNC_NAKED bool Door::IsSealed(int shipId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shipId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func504::func)
		 : "rdi", "rsi"
	);
}

namespace _func505
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Door::FakeOpen", typeid(void (Door::*)()), "55534889fb4883ec0883bfb400000004c6472c01", argdata, 1, 6, &func);
}

FUNC_NAKED void Door::FakeOpen()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func505::func)
		 : "rdi"
	);
}

namespace _func506
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Door::OnLoop", typeid(void (Door::*)()), "55534889fb4883ec188b874c02000085c0", argdata, 1, 6, &func);
}

FUNC_NAKED void Door::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func506::func)
		 : "rdi"
	);
}

namespace _func507
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("DoorBox::constructor", typeid(void (DoorBox::*)(Point , ShipSystem *, ShipManager *)), "41554989cdb901000000415455534889fb488dab700200004c8da3000300004883ec48", argdata, 4, 6, &func);
}

FUNC_NAKED void DoorBox::constructor(Point pos, ShipSystem *sys, ShipManager *ship)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
			// rdx has sys
			// rcx has ship
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func507::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func508
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("DroneBlueprint::RenderIcon", typeid(void (DroneBlueprint::*)(float )), "4156415541544989fc55534881ec20010000", argdata, 2, 6, &func);
}

FUNC_NAKED void DroneBlueprint::RenderIcon(float scale)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has scale
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func508::func)
		 : "rdi", "xmm0"
	);
}

namespace _func509
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("DroneStoreBox::constructor", typeid(void (DroneStoreBox::*)(ShipManager *, Equipment *, const DroneBlueprint *)), "41554989d541544989f4be", argdata, 4, 6, &func);
}

FUNC_NAKED void DroneStoreBox::constructor(ShipManager *ship, Equipment *equip, const DroneBlueprint *bp)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ship
			// rdx has equip
			// rcx has bp
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func509::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func510
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("DroneSystem::RemoveDrone", typeid(void (DroneSystem::*)(int )), "31c085f60f888e00000041545553488b8f48020000", argdata, 2, 6, &func);
}

FUNC_NAKED void DroneSystem::RemoveDrone(int slot)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has slot
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func510::func)
		 : "rdi", "rsi"
	);
}

namespace _func511
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("DroneSystem::UpdateBonusPower", typeid(void (DroneSystem::*)()), "415741564531f6415541545531ed534889fb4883ec18488b9748020000", argdata, 1, 6, &func);
}

FUNC_NAKED void DroneSystem::UpdateBonusPower()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func511::func)
		 : "rdi"
	);
}

namespace _func512
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("DroneSystem::OnLoop", typeid(void (DroneSystem::*)()), ".41574989ff41564155415455534883ec38", argdata, 1, 6, &func);
}

FUNC_NAKED void DroneSystem::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func512::func)
		 : "rdi"
	);
}

namespace _func513
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("DroneSystem::SetBonusPower", typeid(void (DroneSystem::*)(int , int )), ".5589f5534889fb4883ec08", argdata, 3, 6, &func);
}

FUNC_NAKED void DroneSystem::SetBonusPower(int amount, int permanentPower)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has amount
			// rdx has permanentPower
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func513::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func514
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("DroneSystem::DePowerDrone", typeid(bool (DroneSystem::*)(Drone *, bool )), "415484d24989f4554889fd53", argdata, 3, 2, &func);
}

FUNC_NAKED bool DroneSystem::DePowerDrone(Drone *drone, bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has drone
			// rdx has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func514::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func515
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("DropBox::OnRender", typeid(void (DropBox::*)()), "415741564155415455534889fb4883ec78e8", argdata, 1, 6, &func);
}

FUNC_NAKED void DropBox::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func515::func)
		 : "rdi"
	);
}

namespace _func516
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("DropBox::GetHeight", typeid(int (DropBox::*)()), "488b57104889d04885c0", argdata, 1, 2, &func);
}

FUNC_NAKED int DropBox::GetHeight()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func516::func)
		 : "rdi"
	);
}

namespace _func517
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("EnergyAlien::OnLoop", typeid(void (EnergyAlien::*)()), "534889fbe8????????488b83c000000083786003", argdata, 1, 6, &func);
}

FUNC_NAKED void EnergyAlien::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func517::func)
		 : "rdi"
	);
}

namespace _func518
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("EnergyAlien::GetRoomDamage", typeid(Damage (EnergyAlien::*)()), "80be41070000004889f8", argdata, 2, 2, &func);
}

FUNC_NAKED Damage EnergyAlien::GetRoomDamage()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func518::func)
		 : "rdi", "rsi"
	);
}

namespace _func519
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("Equipment::MouseClick", typeid(void (Equipment::*)(int , int )), "534889fbe8????????4863831802000083f8ff", argdata, 3, 6, &func);
}

FUNC_NAKED void Equipment::MouseClick(int mX, int mY)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mX
			// rdx has mY
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func519::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func520
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Equipment::OnLoop", typeid(void (Equipment::*)()), ".41554531ed41545531ed534889fb4883ec08", argdata, 1, 6, &func);
}

FUNC_NAKED void Equipment::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func520::func)
		 : "rdi"
	);
}

namespace _func521
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x1ff};
	static FunctionDefinition funcObj("Equipment::MouseUp", typeid(void (Equipment::*)(int , int )), ".534889fb4883ec7080bf2402000000", argdata, 3, 6, &func);
}

FUNC_NAKED void Equipment::MouseUp(int mX, int mY)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"subq $8, %%rsp\n\t"
		"pushq 8(%%rbp)\n\t"		// mY
			// rdi has this
			// rsi has mX
		"call *%0\n\t"
		"addq $8, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func521::func)
		 : "rdi", "rsi"
	);
}

namespace _func522
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("Equipment::AddDrone", typeid(void (Equipment::*)(DroneBlueprint *, bool , bool )), ".41554154554889f5534889fb4883ec4884c9", argdata, 4, 6, &func);
}

FUNC_NAKED void Equipment::AddDrone(DroneBlueprint *bp, bool unk1, bool unk2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has bp
			// rdx has unk1
			// rcx has unk2
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func522::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func523
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("Equipment::AddAugment", typeid(void (Equipment::*)(AugmentBlueprint *, bool , bool )), ".4154554889f5488d7608534889fb4883ec60", argdata, 4, 6, &func);
}

FUNC_NAKED void Equipment::AddAugment(AugmentBlueprint *bp, bool unk1, bool unk2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has bp
			// rdx has unk1
			// rcx has unk2
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func523::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func524
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Equipment::GetCargoHold", typeid(std::vector<std::string> (Equipment::*)()), ".41554989fd41544989f455534883ec08", argdata, 2, 2, &func);
}

FUNC_NAKED std::vector<std::string> Equipment::GetCargoHold()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func524::func)
		 : "rdi", "rsi"
	);
}

namespace _func525
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("Equipment::AddWeapon", typeid(void (Equipment::*)(WeaponBlueprint *, bool , bool )), ".415641554989f541545589cd534889fb4883ec5084c9", argdata, 4, 6, &func);
}

FUNC_NAKED void Equipment::AddWeapon(WeaponBlueprint *bp, bool unk1, bool unk2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has bp
			// rdx has unk1
			// rcx has unk2
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func525::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func526
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Equipment::AddToCargo", typeid(void (Equipment::*)(std::string &)), ".554889fd534889f34883ec38488d7c2420", argdata, 2, 6, &func);
}

FUNC_NAKED void Equipment::AddToCargo(std::string &name)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has name
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func526::func)
		 : "rdi", "rsi"
	);
}

namespace _func527
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Equipment::OnInit", typeid(void (Equipment::*)(ShipManager *)), ".4157415641554154554889f5534889fb4881ec98000000", argdata, 2, 6, &func);
}

FUNC_NAKED void Equipment::OnInit(ShipManager *ship)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ship
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func527::func)
		 : "rdi", "rsi"
	);
}

namespace _func528
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("EquipmentBox::SetPosition", typeid(void (EquipmentBox::*)(Point )), "48897758897760", argdata, 2, 6, &func);
}

FUNC_NAKED void EquipmentBox::SetPosition(Point pos)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func528::func)
		 : "rdi", "rsi"
	);
}

namespace _func529
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("EquipmentBox::MouseMove", typeid(void (EquipmentBox::*)(int , int )), ".8b476031c939c6", argdata, 3, 6, &func);
}

FUNC_NAKED void EquipmentBox::MouseMove(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func529::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func530
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("EquipmentBox::Restart", typeid(void (EquipmentBox::*)()), ".48c747700000000048c7477800000000", argdata, 1, 6, &func);
}

FUNC_NAKED void EquipmentBox::Restart()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func530::func)
		 : "rdi"
	);
}

namespace _func531
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x2ff};
	static FunctionDefinition funcObj("EquipmentBox::AddItem", typeid(void (EquipmentBox::*)(EquipmentBoxItem )), ".488b44240848894770", argdata, 2, 6, &func);
}

FUNC_NAKED void EquipmentBox::AddItem(EquipmentBoxItem item)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// item
		"pushq 8(%%rbp)\n\t"		// item
			// rdi has this
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func531::func)
		 : "rdi"
	);
}

namespace _func532
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("EquipmentBox::CanHoldWeapon", typeid(bool (EquipmentBox::*)()), ".488b47704885c07407", argdata, 1, 2, &func);
}

FUNC_NAKED bool EquipmentBox::CanHoldWeapon()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func532::func)
		 : "rdi"
	);
}

namespace _func533
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("EquipmentBox::CanHoldDrone", typeid(bool (EquipmentBox::*)()), ".48837f7000488b4778", argdata, 1, 2, &func);
}

FUNC_NAKED bool EquipmentBox::CanHoldDrone()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func533::func)
		 : "rdi"
	);
}

namespace _func534
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("EquipmentBox::GetType", typeid(int (EquipmentBox::*)()), ".48837f70007411", argdata, 1, 2, &func);
}

FUNC_NAKED int EquipmentBox::GetType()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func534::func)
		 : "rdi"
	);
}

namespace _func535
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("EquipmentBox::OnRender", typeid(void (EquipmentBox::*)(bool )), "!.41545589f54189ec534889fb4883ec30", argdata, 2, 6, &func);
}

FUNC_NAKED void EquipmentBox::OnRender(bool isEmpty)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has isEmpty
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func535::func)
		 : "rdi", "rsi"
	);
}

namespace _func536
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("EquipmentBox::destructor", typeid(void (EquipmentBox::*)()), ".534889fb4883ec1048c707????????488b7f28e8????????488b7b30e8????????488b7b38e8????????488b7b40e8????????488b7b08e8????????488b4320488d78e84881ff????????750e", argdata, 1, 6, &func);
}

FUNC_NAKED void EquipmentBox::destructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func536::func)
		 : "rdi"
	);
}

namespace _func537
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("EquipmentBox::UpdateBoxImage", typeid(void (EquipmentBox::*)(bool )), ".41545589f5", argdata, 2, 6, &func);
}

FUNC_NAKED void EquipmentBox::UpdateBoxImage(bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func537::func)
		 : "rdi", "rsi"
	);
}

namespace _func538
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("EquipmentBox::RenderLabels", typeid(void (EquipmentBox::*)(bool )), ".5589f5", argdata, 2, 6, &func);
}

FUNC_NAKED void EquipmentBox::RenderLabels(bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func538::func)
		 : "rdi", "rsi"
	);
}

namespace _func539
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("EquipmentBox::constructor", typeid(void (EquipmentBox::*)(Point , int )), ".554889f048c1f820534889fb4883ec38", argdata, 3, 6, &func);
}

FUNC_NAKED void EquipmentBox::constructor(Point pos, int slot)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
			// rdx has slot
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func539::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func540
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("EquipmentBox::GetItemValue", typeid(int (EquipmentBox::*)()), ".488b47704885c0740f", argdata, 1, 2, &func);
}

FUNC_NAKED int EquipmentBox::GetItemValue()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func540::func)
		 : "rdi"
	);
}

namespace _func541
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("EquipmentBox::SetBlueprint", typeid(void (EquipmentBox::*)(InfoBox *, bool )), ".5531c04889f5534889fb4883ec18", argdata, 3, 6, &func);
}

FUNC_NAKED void EquipmentBox::SetBlueprint(InfoBox *infoBox, bool detailedBox)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has infoBox
			// rdx has detailedBox
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func541::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func542
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("EquipmentBox::GetBlueprint", typeid(Blueprint *(EquipmentBox::*)()), ".488b47784885c07407", argdata, 1, 2, &func);
}

FUNC_NAKED Blueprint *EquipmentBox::GetBlueprint()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func542::func)
		 : "rdi"
	);
}

namespace _func543
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("EventGenerator::GetImageFromList", typeid(std::string (EventGenerator::*)(const std::string &)), "415541544989d455488daec80100004889d6534889fb4889ef4883ec18", argdata, 3, 2, &func);
}

FUNC_NAKED std::string EventGenerator::GetImageFromList(const std::string &listName)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has listName
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func543::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func544
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("EventGenerator::GetSectorDescription", typeid(SectorDescription (EventGenerator::*)(const std::string &, int )), ".41574189cf41564989f641554989fd415455498d6e48534889d34883ec58", argdata, 4, 2, &func);
}

FUNC_NAKED SectorDescription EventGenerator::GetSectorDescription(const std::string &type, int level)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has type
			// rcx has level
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func544::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func545
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("EventGenerator::GetSpecificSector", typeid(SectorDescription (EventGenerator::*)(const std::string &)), ".4157415641554c8d6e1841544989d4554889f5534889fb4881ecd8000000", argdata, 3, 2, &func);
}

FUNC_NAKED SectorDescription EventGenerator::GetSpecificSector(const std::string &name)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has name
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func545::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func546
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("EventGenerator::CreateEvent", typeid(LocationEvent *(EventGenerator::*)(const std::string &, int , bool )), ".415741564155415455488d6f78534889f34881ec88020000", argdata, 4, 2, &func);
}

FUNC_NAKED LocationEvent *EventGenerator::CreateEvent(const std::string &name, int worldLevel, bool ignoreUnique)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has name
			// rdx has worldLevel
			// rcx has ignoreUnique
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func546::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func547
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("EventGenerator::GetBaseEvent", typeid(LocationEvent *(EventGenerator::*)(const std::string &, int , char , int )), ".5589cd534889fb4883ec184183f8ff", argdata, 5, 2, &func);
}

FUNC_NAKED LocationEvent *EventGenerator::GetBaseEvent(const std::string &name, int worldLevel, char ignoreUnique, int seed)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has name
			// rdx has worldLevel
			// rcx has ignoreUnique
			// r8 has seed
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func547::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

EventGenerator *Global_EventGenerator_Generator;

namespace _var548
{
	static VariableDefinition varObj("Global_EventGenerator_Generator", "!", &Global_EventGenerator_Generator);
}

namespace _func549
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("EventSystem::AddEvent", typeid(void (EventSystem::*)(int )), "85f6781a488b5718488b4720", argdata, 2, 6, &func);
}

FUNC_NAKED void EventSystem::AddEvent(int id)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has id
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func549::func)
		 : "rdi", "rsi"
	);
}

namespace _func550
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("EventSystem::PollEvent", typeid(bool (EventSystem::*)(int )), "85f6781c488b0f488b5708", argdata, 2, 2, &func);
}

FUNC_NAKED bool EventSystem::PollEvent(int id)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has id
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func550::func)
		 : "rdi", "rsi"
	);
}

EventSystem *Global_EventSystem_EventManager;

namespace _var551
{
	static VariableDefinition varObj("Global_EventSystem_EventManager", "!488b7b088b348a3bb7700600007e62be06000000bf(???????\?)", &Global_EventSystem_EventManager);
}

namespace _func552
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("EventsParser::PullMinMax", typeid(RandomAmount (EventsParser::*)(rapidxml::xml_node<char> *, const std::string &)), "41544989d4554889f5be????????4883c540", argdata, 3, 2, &func);
}

FUNC_NAKED RandomAmount EventsParser::PullMinMax(rapidxml::xml_node<char> *node, const std::string &name)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has node
			// rdx has name
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func552::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func553
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("EventsParser::ProcessModifyItem", typeid(ResourcesTemplate (EventsParser::*)(ResourcesTemplate &, rapidxml::xml_node<char> *, const std::string &)), ".41574d89c741564989f64c89c641554989fd4154554889d5534889cb4883ec38", argdata, 5, 2, &func);
}

FUNC_NAKED ResourcesTemplate EventsParser::ProcessModifyItem(ResourcesTemplate &resources, rapidxml::xml_node<char> *node, const std::string &unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has resources
			// rcx has node
			// r8 has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func553::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func554
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("EventsParser::ProcessShipEvent", typeid(ShipTemplate (EventsParser::*)(rapidxml::xml_node<char> *)), ".415741564989d641554989fd41544d8d664055534881ec98030000", argdata, 3, 2, &func);
}

FUNC_NAKED ShipTemplate EventsParser::ProcessShipEvent(rapidxml::xml_node<char> *node)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has node
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func554::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func555
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("EventsParser::ProcessEvent", typeid(std::string (EventsParser::*)(rapidxml::xml_node<char> *, const std::string &)), ".415741564989f6be????????41554989cd4154", argdata, 4, 2, &func);
}

FUNC_NAKED std::string EventsParser::ProcessEvent(rapidxml::xml_node<char> *node, const std::string &eventName)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has node
			// rcx has eventName
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func555::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func556
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("EventsParser::ProcessEventList", typeid(std::vector<std::string> (EventsParser::*)(rapidxml::xml_node<char> *, const std::string &)), ".41554989cd41544989f4", argdata, 4, 2, &func);
}

FUNC_NAKED std::vector<std::string> EventsParser::ProcessEventList(rapidxml::xml_node<char> *node, const std::string &listName)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has node
			// rcx has listName
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func556::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func557
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("EventsParser::ProcessBaseNode", typeid(void (EventsParser::*)(rapidxml::xml_node<char> *, EventGenerator &)), ".415741564989fe41554989d54154554889f54c8d7d4053", argdata, 3, 6, &func);
}

FUNC_NAKED void EventsParser::ProcessBaseNode(rapidxml::xml_node<char> *node, EventGenerator &generator)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has node
			// rdx has generator
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func557::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func558
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("EventsParser::AddEvents", typeid(void (EventsParser::*)(EventGenerator &, char *, const std::string &)), ".41574989d741564155415455534881ecc8000100", argdata, 4, 6, &func);
}

FUNC_NAKED void EventsParser::AddEvents(EventGenerator &generator, char *file, const std::string &fileName)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has generator
			// rdx has file
			// rcx has fileName
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func558::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func559
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("EventsParser::AddAllEvents", typeid(void (EventsParser::*)()), ".415531d2", argdata, 1, 6, &func);
}

FUNC_NAKED void EventsParser::AddAllEvents()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func559::func)
		 : "rdi"
	);
}

EventsParser *Global_EventsParser_Parser;

namespace _var560
{
	static VariableDefinition varObj("Global_EventsParser_Parser", "!488d4c24104889c54889c2be????????bf(???????\?)", &Global_EventsParser_Parser);
}

namespace _func561
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("ExplosionAnimation::OnInit", typeid(void (ExplosionAnimation::*)(rapidxml::xml_node<char> *, const std::string &, Point )), "415741564989fe4155415455534889f34881ec380200008b7f28", argdata, 4, 6, &func);
}

FUNC_NAKED void ExplosionAnimation::OnInit(rapidxml::xml_node<char> *node, const std::string &name, Point glowOffset)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has node
			// rdx has name
			// rcx has glowOffset
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func561::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func562
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("FTLButton::OnRender", typeid(void (FTLButton::*)()), "4157be0100000041564155415455534889fb4881ecf8000000488bbf10010000", argdata, 1, 6, &func);
}

FUNC_NAKED void FTLButton::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func562::func)
		 : "rdi"
	);
}

namespace _func563
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("FTLButton::MouseMove", typeid(void (FTLButton::*)(int , int , bool )), ".4157415641554189d541544189cc5589f531f6534889fb4883ec08", argdata, 4, 6, &func);
}

FUNC_NAKED void FTLButton::MouseMove(int mX, int mY, bool silent)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mX
			// rdx has mY
			// rcx has silent
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func563::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func564
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("FileHelper::deleteFile", typeid(void (*)(const std::string &)), "534889fb488b3f31f6e8????????85c07406", argdata, 1, 6, &func);
}

FUNC_NAKED void FileHelper::deleteFile(const std::string &fileName)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has fileName
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func564::func)
		 : "rdi"
	);
}

namespace _func565
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("FileHelper::getResourceFile", typeid(std::string (*)()), ".534889fb4883ec20", argdata, 1, 2, &func);
}

FUNC_NAKED std::string FileHelper::getResourceFile()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func565::func)
		 : "rdi"
	);
}

namespace _func566
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("FileHelper::getUserFolder", typeid(std::string (*)()), ".534889fb4883ec10", argdata, 1, 2, &func);
}

FUNC_NAKED std::string FileHelper::getUserFolder()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func566::func)
		 : "rdi"
	);
}

namespace _func567
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("FileHelper::getSaveFile", typeid(std::string (*)()), ".534889fb4883ec20", argdata, 1, 2, &func);
}

FUNC_NAKED std::string FileHelper::getSaveFile()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func567::func)
		 : "rdi"
	);
}

namespace _func568
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::initFileHelper", typeid(void (*)()), ".4883ec28c605????????01", argdata, 0, 6, &func);
}

FUNC_NAKED void FileHelper::initFileHelper()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func568::func)
	);
}

namespace _func569
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("FileHelper::fileExists", typeid(bool (*)(const std::string &)), ".4883ec08488b3f31f6", argdata, 1, 2, &func);
}

FUNC_NAKED bool FileHelper::fileExists(const std::string &fileName)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has fileName
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func569::func)
		 : "rdi"
	);
}

namespace _func570
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("FileHelper::renameFile", typeid(void (*)(const std::string &, const std::string &)), "!.488b36488b3f", argdata, 2, 6, &func);
}

FUNC_NAKED void FileHelper::renameFile(const std::string &fileName, const std::string &newName)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has fileName
			// rsi has newName
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func570::func)
		 : "rdi", "rsi"
	);
}

namespace _func571
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("FileHelper::createBinaryFile", typeid(int (*)(const std::string &)), ".534889fb488b3f31f6", argdata, 1, 2, &func);
}

FUNC_NAKED int FileHelper::createBinaryFile(const std::string &fileName)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has fileName
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func571::func)
		 : "rdi"
	);
}

namespace _func572
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::saveFileExists", typeid(bool (*)()), ".4155bf????????415455534883ec28", argdata, 0, 2, &func);
}

FUNC_NAKED bool FileHelper::saveFileExists()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func572::func)
	);
}

namespace _func573
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::readSaveFile", typeid(int (*)()), ".4155bf????????415455534883ec28", argdata, 0, 2, &func);
}

FUNC_NAKED int FileHelper::readSaveFile()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func573::func)
	);
}

namespace _func574
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::readStatsFile", typeid(int (*)()), ".4155bf????????415455534883ec28", argdata, 0, 2, &func);
}

FUNC_NAKED int FileHelper::readStatsFile()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func574::func)
	);
}

namespace _func575
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::createSaveFile", typeid(int (*)()), ".488b05????????488905", argdata, 0, 2, &func);
}

FUNC_NAKED int FileHelper::createSaveFile()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func575::func)
	);
}

namespace _func576
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::createStatsFile", typeid(int (*)()), ".488b05????????488905", argdata, 0, 2, &func);
}

FUNC_NAKED int FileHelper::createStatsFile()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func576::func)
	);
}

namespace _func577
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::deleteSaveFile", typeid(void (*)()), "!.53bf????????e8", argdata, 0, 6, &func);
}

FUNC_NAKED void FileHelper::deleteSaveFile()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func577::func)
	);
}

namespace _func578
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::deleteAllSaveFiles", typeid(void (*)()), ".534883ec20e8", argdata, 0, 6, &func);
}

FUNC_NAKED void FileHelper::deleteAllSaveFiles()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func578::func)
	);
}

namespace _func579
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("FileHelper::getPosition", typeid(int (*)(int )), "!.8b05????????c3", argdata, 1, 2, &func);
}

FUNC_NAKED int FileHelper::getPosition(int file)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has file
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func579::func)
		 : "rdi"
	);
}

namespace _func580
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("FileHelper::readBinaryFile", typeid(int (*)(const std::string &)), ".53488b3f31f631c0", argdata, 1, 2, &func);
}

FUNC_NAKED int FileHelper::readBinaryFile(const std::string &fileName)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has fileName
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func580::func)
		 : "rdi"
	);
}

namespace _func581
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("FileHelper::writeFloat", typeid(bool (*)(int , float )), ".415741564155415455534883ec18", argdata, 2, 2, &func);
}

FUNC_NAKED bool FileHelper::writeFloat(int file, float data)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has file
			// xmm0 has data
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func581::func)
		 : "rdi", "xmm0"
	);
}

namespace _func582
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("FileHelper::writeInt", typeid(bool (*)(int , int )), ".415789f141564155415455534883ec18", argdata, 2, 2, &func);
}

FUNC_NAKED bool FileHelper::writeInt(int file, int data)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has file
			// rsi has data
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func582::func)
		 : "rdi", "rsi"
	);
}

namespace _func583
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("FileHelper::writeData", typeid(bool (*)(int , void *, int )), ".41574156415541544989f455534863da4883ec18", argdata, 3, 2, &func);
}

FUNC_NAKED bool FileHelper::writeData(int file, void *data, int len)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has file
			// rsi has data
			// rdx has len
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func583::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func584
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("FileHelper::writeString", typeid(bool (*)(int , const std::string &)), ".41574156415541545589fd534883ec28", argdata, 2, 2, &func);
}

FUNC_NAKED bool FileHelper::writeString(int file, const std::string &data)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has file
			// rsi has data
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func584::func)
		 : "rdi", "rsi"
	);
}

namespace _func585
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("FileHelper::closeBinaryFile", typeid(void (*)(int )), ".81fffffeff7f53", argdata, 1, 6, &func);
}

FUNC_NAKED void FileHelper::closeBinaryFile(int file)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has file
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func585::func)
		 : "rdi"
	);
}

namespace _func586
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("FileHelper::readString", typeid(std::string (*)(int )), ".4157415641554989fd4154555389f34883ec28", argdata, 2, 2, &func);
}

FUNC_NAKED std::string FileHelper::readString(int file)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has file
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func586::func)
		 : "rdi", "rsi"
	);
}

namespace _func587
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("FileHelper::readFloat", typeid(float (*)(int )), ".41554154555389fb4883ec18", argdata, 1, 2, &func);
}

FUNC_NAKED float FileHelper::readFloat(int file)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has file
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func587::func)
		 : "rdi"
	);
}

namespace _func588
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("FileHelper::readInteger", typeid(int (*)(int )), ".41554154555389fb4883ec18", argdata, 1, 2, &func);
}

FUNC_NAKED int FileHelper::readInteger(int file)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has file
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func588::func)
		 : "rdi"
	);
}

namespace _func589
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("FileHelper::seekPosition", typeid(bool (*)(int , int )), ".4883ec0831d2", argdata, 2, 2, &func);
}

FUNC_NAKED bool FileHelper::seekPosition(int file, int pos)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has file
			// rsi has pos
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func589::func)
		 : "rdi", "rsi"
	);
}

namespace _func590
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("FileHelper::readBuffer", typeid(char *(*)(int , int , bool )), ".4157415641554189d541545589fd0fb6fa534863de01df4883ec08", argdata, 3, 2, &func);
}

FUNC_NAKED char *FileHelper::readBuffer(int file, int len, bool nullTerminate)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has file
			// rsi has len
			// rdx has nullTerminate
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func590::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func591
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("FileHelper::readData", typeid(void (*)(int , void *, int )), ".41554889f141545589d55389fb4883ec08", argdata, 3, 6, &func);
}

FUNC_NAKED void FileHelper::readData(int file, void *data, int len)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has file
			// rsi has data
			// rdx has len
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func591::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func592
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Fire::OnLoop", typeid(void (Fire::*)()), "55534889fb4883ec0880bfd801000000", argdata, 1, 6, &func);
}

FUNC_NAKED void Fire::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func592::func)
		 : "rdi"
	);
}

namespace _func593
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Fire::UpdateDeathTimer", typeid(void (Fire::*)(int )), ".5589f5534889fb4883ec18488b07ff505084c0", argdata, 2, 6, &func);
}

FUNC_NAKED void Fire::UpdateDeathTimer(int connectedFires)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has connectedFires
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func593::func)
		 : "rdi", "rsi"
	);
}

namespace _func594
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Fire::UpdateStartTimer", typeid(void (Fire::*)(int )), ".5589f5534889fb4883ec18488b07ff505084c0", argdata, 2, 6, &func);
}

FUNC_NAKED void Fire::UpdateStartTimer(int doorLevel)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has doorLevel
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func594::func)
		 : "rdi", "rsi"
	);
}

namespace _func595
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("FocusWindow::MouseClick", typeid(void (FocusWindow::*)(int , int )), "807f1400750af3c3", argdata, 3, 6, &func);
}

FUNC_NAKED void FocusWindow::MouseClick(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func595::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func596
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("GameOver::OpenText", typeid(void (GameOver::*)(const std::string &)), "415741564155415455534889fb488d7f704881ecf8000000", argdata, 2, 6, &func);
}

FUNC_NAKED void GameOver::OpenText(const std::string &text)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has text
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func596::func)
		 : "rdi", "rsi"
	);
}

namespace _func597
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("GameOver::OnRender", typeid(void (GameOver::*)()), "415741564155415455534889fb4881ec1802000080bfd800000000", argdata, 1, 6, &func);
}

FUNC_NAKED void GameOver::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func597::func)
		 : "rdi"
	);
}

namespace _func598
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("GameOver::OnLoop", typeid(void (GameOver::*)()), "4154554889fdbf????????534883ec40", argdata, 1, 6, &func);
}

FUNC_NAKED void GameOver::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func598::func)
		 : "rdi"
	);
}

namespace _func599
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("GenericButton::SetLocation", typeid(void (GenericButton::*)(Point )), "8b57084889f08b4f0c48c1f82039d6", argdata, 2, 6, &func);
}

FUNC_NAKED void GenericButton::SetLocation(Point pos)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func599::func)
		 : "rdi", "rsi"
	);
}

namespace _func600
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("GenericButton::SetActive", typeid(void (GenericButton::*)(bool )), ".4084f640887748", argdata, 2, 6, &func);
}

FUNC_NAKED void GenericButton::SetActive(bool active)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has active
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func600::func)
		 : "rdi", "rsi"
	);
}

namespace _func601
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("GenericButton::MouseMove", typeid(void (GenericButton::*)(int , int , bool )), ".8b4710440fb6474939c6", argdata, 4, 6, &func);
}

FUNC_NAKED void GenericButton::MouseMove(int x, int y, bool silent)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
			// rcx has silent
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func601::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func602
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("GenericButton::OnClick", typeid(void (GenericButton::*)()), "!.f3c3662e0f1f8400000000000f1f4000f3c3662e0f1f8400000000000f1f4000f3c3662e0f1f8400000000000f1f400053", argdata, 1, 6, &func);
}

FUNC_NAKED void GenericButton::OnClick()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func602::func)
		 : "rdi"
	);
}

namespace _func603
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("GenericButton::OnRightClick", typeid(void (GenericButton::*)()), "!.f3c3662e0f1f8400000000000f1f4000f3c3662e0f1f8400000000000f1f400053", argdata, 1, 6, &func);
}

FUNC_NAKED void GenericButton::OnRightClick()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func603::func)
		 : "rdi"
	);
}

namespace _func604
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("GenericButton::ResetPrimitives", typeid(void (GenericButton::*)()), "!.f3c3662e0f1f8400000000000f1f400053", argdata, 1, 6, &func);
}

FUNC_NAKED void GenericButton::ResetPrimitives()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func604::func)
		 : "rdi"
	);
}

namespace _func605
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x10a};
	static FunctionDefinition funcObj("font_text_width", typeid(float (*)(freetype::font_data &, const char *, float )), "85ff7e7e", argdata, 3, 2, &func);
}

FUNC_NAKED float __stdcall font_text_width(freetype::font_data &fontData, const char *str, float size)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has fontData
			// rsi has str
			// xmm0 has size
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func605::func)
		 : "rdi", "rsi", "xmm0"
	);
}

namespace _func606
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("random32", typeid(int (*)()), "48b82d7f954c2df45158480faf05????????4883c001488905????????48c1e821", argdata, 0, 0, &func);
}

FUNC_NAKED int __stdcall random32()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func606::func)
	);
}

namespace _func607
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("srandom32", typeid(void (*)(unsigned int )), ".89f8488905", argdata, 1, 6, &func);
}

FUNC_NAKED void __stdcall srandom32(unsigned int seed)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has seed
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func607::func)
		 : "rdi"
	);
}

namespace _func608
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("getSkillBonus", typeid(float (*)(int , int )), "83ff05772d89ff", argdata, 2, 2, &func);
}

FUNC_NAKED float __stdcall getSkillBonus(int skill, int level)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has skill
			// rsi has level
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func608::func)
		 : "rdi", "rsi"
	);
}

namespace _func609
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("GetValue", typeid(void (*)(ResourceEvent &, const std::string &, int , int )), "41554189cd41544c63e2554889fd534889f3", argdata, 4, 6, &func);
}

FUNC_NAKED void __stdcall GetValue(ResourceEvent &ref, const std::string &type, int level, int worldLevel)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has ref
			// rsi has type
			// rdx has level
			// rcx has worldLevel
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func609::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func610
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("GenerateReward", typeid(void (*)(ResourceEvent &, RewardDesc &, int )), ".41574989f741564155415455534881ec08020000", argdata, 3, 6, &func);
}

FUNC_NAKED void __stdcall GenerateReward(ResourceEvent &ref, RewardDesc &reward, int worldLevel)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has ref
			// rsi has reward
			// rdx has worldLevel
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func610::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func611
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x10a};
	static FunctionDefinition funcObj("Globals::AimAhead", typeid(float (*)(Pointf , Pointf , float )), "4883ec18f30f59d2660fd60424488b1424", argdata, 3, 2, &func);
}

FUNC_NAKED float Globals::AimAhead(Pointf delta, Pointf vr, float muzzleV)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has delta
			// rsi has vr
			// xmm0 has muzzleV
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func611::func)
		 : "rdi", "rsi", "xmm0"
	);
}

namespace _func612
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Globals::GetNextSpaceId", typeid(int (*)()), "8b15????????b865000000", argdata, 0, 0, &func);
}

FUNC_NAKED int Globals::GetNextSpaceId()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func612::func)
	);
}

TextLibrary *Global_Globals_Library;

namespace _var613
{
	static VariableDefinition varObj("Global_Globals_Library", "!4189e8488d4c2460ba010000004c89e7be(???????\?)", &Global_Globals_Library);
}

int *Globals_GetNextSpaceId_id;

namespace _var614
{
	static VariableDefinition varObj("Globals_GetNextSpaceId_id", "!8b15(???????\?)b865000000", &Globals_GetNextSpaceId_id);
}

namespace _func615
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("HackBox::constructor", typeid(void (HackBox::*)(Point , HackingSystem *, ShipManager *)), "41554989cd31c94154554889d5534889fb4c8da3180300004883ec68", argdata, 4, 6, &func);
}

FUNC_NAKED void HackBox::constructor(Point pos, HackingSystem *sys, ShipManager *ship)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
			// rdx has sys
			// rcx has ship
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func615::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func616
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("HackingDrone::OnLoop", typeid(void (HackingDrone::*)()), "55bd05000000534889fb4883ec48", argdata, 1, 6, &func);
}

FUNC_NAKED void HackingDrone::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func616::func)
		 : "rdi"
	);
}

namespace _func617
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("HackingDrone::SetMovementTarget", typeid(void (HackingDrone::*)(Targetable *)), "554889f5534889fb4883ec184885f60f84b3000000", argdata, 2, 6, &func);
}

FUNC_NAKED void HackingDrone::SetMovementTarget(Targetable *target)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has target
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func617::func)
		 : "rdi", "rsi"
	);
}

namespace _func618
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("HackingSystem::BlowHackingDrone", typeid(void (HackingSystem::*)()), "80bf60020000007507f3c3", argdata, 1, 6, &func);
}

FUNC_NAKED void HackingSystem::BlowHackingDrone()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func618::func)
		 : "rdi"
	);
}

namespace _func619
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("HackingSystem::OnLoop", typeid(void (HackingSystem::*)()), "55534889fb4883ec38e8????????80bb7002000000", argdata, 1, 6, &func);
}

FUNC_NAKED void HackingSystem::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func619::func)
		 : "rdi"
	);
}

namespace _func620
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("InfoBox::constructor", typeid(void (InfoBox::*)()), "5331d24889fb31f64883ec10e8????????488d7b10", argdata, 1, 6, &func);
}

FUNC_NAKED void InfoBox::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func620::func)
		 : "rdi"
	);
}

namespace _func621
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("InfoBox::SetBlueprintWeapon", typeid(void (InfoBox::*)(const WeaponBlueprint *, int , bool , int )), ".41574589c7415641554189d531d24154554889f5534889fb4c8d63304883ec58", argdata, 5, 6, &func);
}

FUNC_NAKED void InfoBox::SetBlueprintWeapon(const WeaponBlueprint *bp, int status, bool hasWeaponSystem, int yShift)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has bp
			// rdx has status
			// rcx has hasWeaponSystem
			// r8 has yShift
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func621::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func622
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("InfoBox::SetBlueprintDrone", typeid(void (InfoBox::*)(const DroneBlueprint *, int , bool , int )), ".41574156415541544989f4488d761055534889fb488d7f104c8d73304881ec18020000", argdata, 5, 6, &func);
}

FUNC_NAKED void InfoBox::SetBlueprintDrone(const DroneBlueprint *bp, int status, bool hasDroneSystem, int yShift)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has bp
			// rdx has status
			// rcx has hasDroneSystem
			// r8 has yShift
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func622::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func623
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("InfoBox::SetBlueprint", typeid(void (InfoBox::*)(const ItemBlueprint *)), "!.4154554889f5488d7610534889fb", argdata, 2, 6, &func);
}

FUNC_NAKED void InfoBox::SetBlueprint(const ItemBlueprint *bp)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has bp
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func623::func)
		 : "rdi", "rsi"
	);
}

namespace _func624
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("InfoBox::SetBlueprintCrew", typeid(void (InfoBox::*)(const CrewBlueprint *, int , bool )), ".415741564c8d771041554989f54154554889fd53488d5e104881ecc8000000", argdata, 4, 6, &func);
}

FUNC_NAKED void InfoBox::SetBlueprintCrew(const CrewBlueprint *bp, int yShift, bool detailedCrew)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has bp
			// rdx has yShift
			// rcx has detailedCrew
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func624::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func625
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("InfoBox::SetBlueprintAugment", typeid(void (InfoBox::*)(const AugmentBlueprint *)), ".4154554889f5488d7610534889fb", argdata, 2, 6, &func);
}

FUNC_NAKED void InfoBox::SetBlueprintAugment(const AugmentBlueprint *bp)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has bp
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func625::func)
		 : "rdi", "rsi"
	);
}

namespace _func626
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("InfoBox::IsEmpty", typeid(bool (InfoBox::*)()), ".55534889fb4883ec28837f7cff", argdata, 1, 2, &func);
}

FUNC_NAKED bool InfoBox::IsEmpty()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func626::func)
		 : "rdi"
	);
}

namespace _func627
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("InfoBox::CalcBoxHeight", typeid(int (InfoBox::*)()), ".4156415541544989fc55534881eca0000000837f7401", argdata, 1, 2, &func);
}

FUNC_NAKED int InfoBox::CalcBoxHeight()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func627::func)
		 : "rdi"
	);
}

namespace _func628
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x109, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetSystemId", typeid(void (InfoBox::*)(int , int , int , int , int , int )), ".4157415641554589cd41544189f455534889fb4883ec2883feff", argdata, 7, 6, &func);
}

FUNC_NAKED void InfoBox::SetSystemId(int systemId, int maxPower, int currentLevel, int upgrade, int yShift, int forceSystemWidth)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"subq $8, %%rsp\n\t"
		"pushq 8(%%rbp)\n\t"		// forceSystemWidth
			// rdi has this
			// rsi has systemId
			// rdx has maxPower
			// rcx has currentLevel
			// r8 has upgrade
			// r9 has yShift
		"call *%0\n\t"
		"addq $8, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func628::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "r9"
	);
}

namespace _func629
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("InfoBox::SetDescription", typeid(void (InfoBox::*)(Description *, int , int , InfoBox::ExpandDir )), ".41564589c641554189d541544189cc554889f5534889fb", argdata, 5, 6, &func);
}

FUNC_NAKED void InfoBox::SetDescription(Description *desc, int width, int height, InfoBox::ExpandDir dir)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has desc
			// rdx has width
			// rcx has height
			// r8 has dir
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func629::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func630
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x109};
	static FunctionDefinition funcObj("InfoBox::SetText", typeid(void (InfoBox::*)(const std::string &, const std::string &, int , int , InfoBox::ExpandDir )), ".41574989ff41564589ce41554d8d6f1041545589cd534489c34881eca8000000", argdata, 6, 6, &func);
}

FUNC_NAKED void InfoBox::SetText(const std::string &title, const std::string &text, int width, int height, InfoBox::ExpandDir dir)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has title
			// rdx has text
			// rcx has width
			// r8 has height
			// r9 has dir
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func630::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "r9"
	);
}

namespace _func631
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("InfoBox::SetSystem", typeid(void (InfoBox::*)(ShipSystem *, int , int , int )), ".4157415641554154554889f5534889fb4883ec384885f6", argdata, 5, 6, &func);
}

FUNC_NAKED void InfoBox::SetSystem(ShipSystem *system, int upgrade, int yShift, int forceSystemWidth)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has system
			// rdx has upgrade
			// rcx has yShift
			// r8 has forceSystemWidth
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func631::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func632
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("InfoBox::Clear", typeid(void (InfoBox::*)()), ".55be????????534889fb4883ec28", argdata, 1, 6, &func);
}

FUNC_NAKED void InfoBox::Clear()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func632::func)
		 : "rdi"
	);
}

namespace _func633
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("InfoBox::OnRender", typeid(void (InfoBox::*)()), ".4157415641554989fd415455534881ec68020000", argdata, 1, 6, &func);
}

FUNC_NAKED void InfoBox::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func633::func)
		 : "rdi"
	);
}

GL_Color *Global_InfoBox_detailsBarOff;

namespace _var634
{
	static VariableDefinition varObj("Global_InfoBox_detailsBarOff", "!f30f2a8424b0000000443b642420ba(???????\?)b8(???????\?)", &Global_InfoBox_detailsBarOff);
}

GL_Color *Global_InfoBox_detailsBarOn;

namespace _var635
{
	static VariableDefinition varObj("Global_InfoBox_detailsBarOn", "", &Global_InfoBox_detailsBarOn);
}

namespace _func636
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("InputBox::TextEvent", typeid(void (InputBox::*)(CEvent::TextEvent )), "4155415455534889fb4883ec1883fe01", argdata, 2, 6, &func);
}

FUNC_NAKED void InputBox::TextEvent(CEvent::TextEvent event)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has event
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func636::func)
		 : "rdi", "rsi"
	);
}

namespace _func637
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("InputBox::StartInput", typeid(void (InputBox::*)()), "534889fb488d7f3831d2", argdata, 1, 6, &func);
}

FUNC_NAKED void InputBox::StartInput()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func637::func)
		 : "rdi"
	);
}

namespace _func638
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("IonDrone::GetRoomDamage", typeid(Damage (IonDrone::*)()), "554889f5534889fb4883ec08c70700000000", argdata, 2, 2, &func);
}

FUNC_NAKED Damage IonDrone::GetRoomDamage()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func638::func)
		 : "rdi", "rsi"
	);
}

namespace _func639
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x10a, 0x102};
	static FunctionDefinition funcObj("IonDroneAnimation::constructor", typeid(void (IonDroneAnimation::*)(int , Pointf , bool )), "41574156415541544189d45589f5be", argdata, 4, 6, &func);
}

FUNC_NAKED void IonDroneAnimation::constructor(int iShipId, Pointf position, bool enemy)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has iShipId
			// xmm0 has position
			// rdx has enemy
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func639::func)
		 : "rdi", "rsi", "xmm0", "rdx"
	);
}

namespace _func640
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ItemStoreBox::constructor", typeid(void (ItemStoreBox::*)(ShipManager *, const std::string &)), "41544989f4554889d5534889fb4883ec20488b02", argdata, 3, 6, &func);
}

FUNC_NAKED void ItemStoreBox::constructor(ShipManager *ship, const std::string &resourceName)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ship
			// rdx has resourceName
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func640::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func641
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("LaserBlast::OnUpdate", typeid(void (LaserBlast::*)()), "534889fb4883ec1080bfc400000000745f", argdata, 1, 6, &func);
}

FUNC_NAKED void LaserBlast::OnUpdate()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func641::func)
		 : "rdi"
	);
}

namespace _func642
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("LaserBlast::OnInit", typeid(void (LaserBlast::*)()), "538b477c4889fb394778c7474001000000", argdata, 1, 6, &func);
}

FUNC_NAKED void LaserBlast::OnInit()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func642::func)
		 : "rdi"
	);
}

void **VTable_LaserBlast;

namespace _var643
{
	static VariableDefinition varObj("VTable_LaserBlast", "!b8b7600bb64589e84c89e741f7ed4489e849c70424(???????\?)c1f81f49c7442408(???????\?)", &VTable_LaserBlast);
}

void **VTable_Targetable_LaserBlast;

namespace _var644
{
	static VariableDefinition varObj("VTable_Targetable_LaserBlast", "", &VTable_Targetable_LaserBlast);
}

namespace _func645
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("LocationEvent::ClearEvent", typeid(void (LocationEvent::*)(bool )), "4157415641554154554889fd534883ec3883bfc404000001", argdata, 2, 6, &func);
}

FUNC_NAKED void LocationEvent::ClearEvent(bool force)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has force
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func645::func)
		 : "rdi", "rsi"
	);
}

namespace _func646
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("LocationEvent::constructor", typeid(void (LocationEvent::*)()), "53be????????4889fb4883ec10488d54240fe8????????488d7b18", argdata, 1, 6, &func);
}

FUNC_NAKED void LocationEvent::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func646::func)
		 : "rdi"
	);
}

namespace _func647
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("LockdownShard::Update", typeid(void (LockdownShard::*)()), "534889fbbf????????e8????????f30f5905????????f30f5883d8000000", argdata, 1, 6, &func);
}

FUNC_NAKED void LockdownShard::Update()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func647::func)
		 : "rdi"
	);
}

namespace _func648
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("MainMenu::constructor", typeid(void (MainMenu::*)()), "41570f57c04156415541544c8d673855534889fb4c8dbbe80100004c8db378020000488dab08030000", argdata, 1, 6, &func);
}

FUNC_NAKED void MainMenu::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func648::func)
		 : "rdi"
	);
}

namespace _func649
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("MainMenu::OnRender", typeid(void (MainMenu::*)()), ".415741564155415455534889fb4881ecf8040000", argdata, 1, 6, &func);
}

FUNC_NAKED void MainMenu::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func649::func)
		 : "rdi"
	);
}

namespace _func650
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("MainMenu::Open", typeid(bool (MainMenu::*)()), ".415741564155415455534889fb488dbfa02200004881ec08020000", argdata, 1, 2, &func);
}

FUNC_NAKED bool MainMenu::Open()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func650::func)
		 : "rdi"
	);
}

namespace _func651
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("MainMenu::MouseMove", typeid(void (MainMenu::*)(int , int )), ".4155415455534889fb4883ec3880bf3837000000", argdata, 3, 6, &func);
}

FUNC_NAKED void MainMenu::MouseMove(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func651::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func652
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("MainMenu::OnLoop", typeid(void (MainMenu::*)()), ".415741564155415455534889fb4881ec38020000", argdata, 1, 6, &func);
}

FUNC_NAKED void MainMenu::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func652::func)
		 : "rdi"
	);
}

namespace _func653
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("MainMenu::MouseClick", typeid(void (MainMenu::*)(int , int )), ".534889fb4883ec5080bf3837000000", argdata, 3, 6, &func);
}

FUNC_NAKED void MainMenu::MouseClick(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func653::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func654
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("MantisAnimation::__DO_NOT_HOOK_1", typeid(void (*)()), "!c3660f1f840000000000f3c3660f1f440000f3c3660f1f440000", argdata, 0, 4, &func);
}

FUNC_NAKED void MantisAnimation::__DO_NOT_HOOK_1()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func654::func)
	);
}

namespace _func655
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("MantisAnimation::GetDeathSound", typeid(std::string (MantisAnimation::*)()), ".53be????????4889fb4883ec10", argdata, 2, 2, &func);
}

FUNC_NAKED std::string MantisAnimation::GetDeathSound()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func655::func)
		 : "rdi", "rsi"
	);
}

namespace _func656
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("MantisAnimation::__DO_NOT_HOOK_2", typeid(void (*)()), ".53486347584889fb488b5710", argdata, 0, 4, &func);
}

FUNC_NAKED void MantisAnimation::__DO_NOT_HOOK_2()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func656::func)
	);
}

namespace _func657
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("MantisAnimation::FireShot", typeid(bool (MantisAnimation::*)()), ".53486347584889fb488b5710", argdata, 1, 2, &func);
}

FUNC_NAKED bool MantisAnimation::FireShot()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func657::func)
		 : "rdi"
	);
}

namespace _func658
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("MantisAnimation::__DO_NOT_HOOK_3", typeid(void (*)()), ".534889fb4883ec30803d????????007577e8????????89c1", argdata, 0, 4, &func);
}

FUNC_NAKED void MantisAnimation::__DO_NOT_HOOK_3()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func658::func)
	);
}

namespace _func659
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("MantisAnimation::GetShootingSound", typeid(std::string (MantisAnimation::*)()), ".534889fb4883ec30803d????????007577e8????????89c1", argdata, 2, 2, &func);
}

FUNC_NAKED std::string MantisAnimation::GetShootingSound()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func659::func)
		 : "rdi", "rsi"
	);
}

namespace _func660
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("MenuScreen::OnRender", typeid(void (MenuScreen::*)()), "41564155415455534889fb4881eca000000080bf0803000000", argdata, 1, 6, &func);
}

FUNC_NAKED void MenuScreen::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func660::func)
		 : "rdi"
	);
}

namespace _func661
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("MenuScreen::constructor", typeid(void (MenuScreen::*)()), "41564155415455534889fb488d6b784881ece0000000", argdata, 1, 6, &func);
}

FUNC_NAKED void MenuScreen::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func661::func)
		 : "rdi"
	);
}

namespace _func662
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("MindBox::constructor", typeid(void (MindBox::*)(Point , MindSystem *)), "415431c9554889d5534889fb4883ec60", argdata, 3, 6, &func);
}

FUNC_NAKED void MindBox::constructor(Point pos, MindSystem *sys)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
			// rdx has sys
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func662::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func663
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("MindSystem::SetArmed", typeid(void (MindSystem::*)(int )), "83fe01534889fb740f", argdata, 2, 6, &func);
}

FUNC_NAKED void MindSystem::SetArmed(int armed)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has armed
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func663::func)
		 : "rdi", "rsi"
	);
}

namespace _func664
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("MindSystem::InitiateMindControl", typeid(void (MindSystem::*)()), "415741564155415455534889fb4883ec48488bb780020000", argdata, 1, 6, &func);
}

FUNC_NAKED void MindSystem::InitiateMindControl()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func664::func)
		 : "rdi"
	);
}

namespace _func665
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("MindSystem::OnLoop", typeid(void (MindSystem::*)()), "415455534889fb4883ec20e8????????488b8380020000", argdata, 1, 6, &func);
}

FUNC_NAKED void MindSystem::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func665::func)
		 : "rdi"
	);
}

namespace _func666
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x10a};
	static FunctionDefinition funcObj("Missile::constructor", typeid(void (Missile::*)(Pointf , int , int , Pointf , float )), "41574989ff4156415541545589f55389d34881ecf8000000f30f11542404", argdata, 6, 6, &func);
}

FUNC_NAKED void Missile::constructor(Pointf _position, int _ownerId, int _targetId, Pointf _target, float _heading)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has _position
			// rdx has _ownerId
			// rcx has _targetId
			// r8 has _target
			// xmm0 has _heading
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func666::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "xmm0"
	);
}

namespace _func667
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("MouseControl::OnLoop", typeid(void (MouseControl::*)()), "5380bf0c010000004889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void MouseControl::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func667::func)
		 : "rdi"
	);
}

namespace _func668
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("MouseControl::InstantTooltip", typeid(void (MouseControl::*)()), "!.c6872001000001c3", argdata, 1, 6, &func);
}

FUNC_NAKED void MouseControl::InstantTooltip()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func668::func)
		 : "rdi"
	);
}

namespace _func669
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("MouseControl::MeasureTooltip", typeid(Point (MouseControl::*)(int )), ".41550f57c941544189f40f28c155534889fb4883ec48", argdata, 2, 2, &func);
}

FUNC_NAKED Point MouseControl::MeasureTooltip(int unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func669::func)
		 : "rdi", "rsi"
	);
}

namespace _func670
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("MouseControl::QueueStaticTooltip", typeid(void (MouseControl::*)(Point )), "!.4889b740010000c3", argdata, 2, 6, &func);
}

FUNC_NAKED void MouseControl::QueueStaticTooltip(Point pos)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func670::func)
		 : "rdi", "rsi"
	);
}

namespace _func671
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("MouseControl::OnRender", typeid(void (MouseControl::*)()), ".41574989ff41564155415455534881ecc801000080bf0d01000000", argdata, 1, 6, &func);
}

FUNC_NAKED void MouseControl::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func671::func)
		 : "rdi"
	);
}

namespace _func672
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("MouseControl::SetTooltip", typeid(void (MouseControl::*)(const std::string &)), ".41544989f4554889fd53488b06488b58e84885db", argdata, 2, 6, &func);
}

FUNC_NAKED void MouseControl::SetTooltip(const std::string &tooltip)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has tooltip
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func672::func)
		 : "rdi", "rsi"
	);
}

namespace _func673
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("MouseControl::SetTooltipTitle", typeid(void (MouseControl::*)(const std::string &)), ".488b8728010000488378e800", argdata, 2, 6, &func);
}

FUNC_NAKED void MouseControl::SetTooltipTitle(const std::string &tooltip)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has tooltip
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func673::func)
		 : "rdi", "rsi"
	);
}

namespace _func674
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("MouseControl::SetDoor", typeid(void (MouseControl::*)(int )), ".554889fd5389f34883ec0883fe01", argdata, 2, 6, &func);
}

FUNC_NAKED void MouseControl::SetDoor(int state)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has state
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func674::func)
		 : "rdi", "rsi"
	);
}

MouseControl *Global_MouseControl_Mouse;

namespace _var675
{
	static VariableDefinition varObj("Global_MouseControl_Mouse", "!0f85570400008b85a401000083f8ff740abf(???????\?)", &Global_MouseControl_Mouse);
}

namespace _func676
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("OptionsScreen::OnInit", typeid(void (OptionsScreen::*)()), "4155415455534889fbbf????????488dabe00800004883ec68", argdata, 1, 6, &func);
}

FUNC_NAKED void OptionsScreen::OnInit()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func676::func)
		 : "rdi"
	);
}

namespace _func677
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("OptionsScreen::OnLoop", typeid(void (OptionsScreen::*)()), "41574156415549bdb76ddbb66ddbb66d4154554889fd", argdata, 1, 6, &func);
}

FUNC_NAKED void OptionsScreen::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func677::func)
		 : "rdi"
	);
}

void **VTable_OuterHull;

namespace _var678
{
	static VariableDefinition varObj("VTable_OuterHull", "!498dbd880000000f28caf3410f1195840000000f28c249c74500(???????\?)", &VTable_OuterHull);
}

namespace _func679
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("OxygenSystem::constructor", typeid(void (OxygenSystem::*)(int , int , int , int )), "4154554863eebe02000000534889fb", argdata, 5, 6, &func);
}

FUNC_NAKED void OxygenSystem::constructor(int numRooms, int roomId, int shipId, int startingPower)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has numRooms
			// rdx has roomId
			// rcx has shipId
			// r8 has startingPower
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func679::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func680
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("OxygenSystem::GetRefillSpeed", typeid(float (OxygenSystem::*)()), ".5380bf24020000004889fb8b8720020000", argdata, 1, 2, &func);
}

FUNC_NAKED float OxygenSystem::GetRefillSpeed()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func680::func)
		 : "rdi"
	);
}

namespace _func681
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x10a};
	static FunctionDefinition funcObj("OxygenSystem::ModifyRoomOxygen", typeid(void (OxygenSystem::*)(int , float )), ".488b87480200004863f6", argdata, 3, 6, &func);
}

FUNC_NAKED void OxygenSystem::ModifyRoomOxygen(int roomId, float value)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
			// xmm0 has value
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func681::func)
		 : "rdi", "rsi", "xmm0"
	);
}

namespace _func682
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x10a, 0x102};
	static FunctionDefinition funcObj("OxygenSystem::ComputeAirLoss", typeid(void (OxygenSystem::*)(int , float , bool )), ".415541544989fc5589d55389f34883ec38", argdata, 4, 6, &func);
}

FUNC_NAKED void OxygenSystem::ComputeAirLoss(int roomId, float value, bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
			// xmm0 has value
			// rdx has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func682::func)
		 : "rdi", "rsi", "xmm0", "rdx"
	);
}

namespace _func683
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("OxygenSystem::UpdateBreach", typeid(void (OxygenSystem::*)(int , int , bool )), ".85d289d07e1a", argdata, 4, 6, &func);
}

FUNC_NAKED void OxygenSystem::UpdateBreach(int roomId, int hasBreach, bool unk3)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
			// rdx has hasBreach
			// rcx has unk3
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func683::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func684
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("OxygenSystem::UpdateAirlock", typeid(void (OxygenSystem::*)(int , int )), ".4154555389d34883ec2085d2", argdata, 3, 6, &func);
}

FUNC_NAKED void OxygenSystem::UpdateAirlock(int roomId, int unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
			// rdx has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func684::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func685
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("OxygenSystem::EmptyOxygen", typeid(void (OxygenSystem::*)(int )), ".488b87480200004863f6", argdata, 2, 6, &func);
}

FUNC_NAKED void OxygenSystem::EmptyOxygen(int roomId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func685::func)
		 : "rdi", "rsi"
	);
}

namespace _func686
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("PDSFire::CollisionCheck", typeid(void (PDSFire::*)(Collideable *)), "554889f5534889fb4889f74883ec58488b06", argdata, 2, 6, &func);
}

FUNC_NAKED void PDSFire::CollisionCheck(Collideable *other)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has other
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func686::func)
		 : "rdi", "rsi"
	);
}

namespace _func687
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Point::RelativeDistance", typeid(int (Point::*)(Point )), "8b178b470429f248c1fe2029f00fafd20fafc001d0", argdata, 2, 2, &func);
}

FUNC_NAKED int Point::RelativeDistance(Point other)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has other
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func687::func)
		 : "rdi", "rsi"
	);
}

namespace _func688
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Point::Distance", typeid(int (Point::*)(Point )), ".8b178b470429f248c1fe2029f00fafd20fafc001d0", argdata, 2, 2, &func);
}

FUNC_NAKED int Point::Distance(Point other)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has other
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func688::func)
		 : "rdi", "rsi"
	);
}

namespace _func689
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b};
	static FunctionDefinition funcObj("Pointf::constructor", typeid(void (Pointf::*)(float , float )), "f30f1107f30f114f04c3", argdata, 3, 6, &func);
}

FUNC_NAKED void Pointf::constructor(float x, float y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has x
			// xmm1 has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func689::func)
		 : "rdi", "xmm0", "xmm1"
	);
}

namespace _func690
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Pointf::RelativeDistance", typeid(float (Pointf::*)(Pointf )), "660fd64424f0488b4424f0f30f1007", argdata, 2, 2, &func);
}

FUNC_NAKED float Pointf::RelativeDistance(Pointf other)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has other
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func690::func)
		 : "rdi", "rsi"
	);
}

namespace _func691
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Pointf::Normalize", typeid(Pointf (Pointf::*)()), "4883ec28f30f100ff30f104704", argdata, 1, 2, &func);
}

FUNC_NAKED Pointf Pointf::Normalize()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func691::func)
		 : "rdi"
	);
}

namespace _func692
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("PowerManager::GetPowerManager", typeid(PowerManager *(*)(int )), "5389fb4883ec30488b05????????488b0d????????4889c2", argdata, 1, 2, &func);
}

FUNC_NAKED PowerManager *PowerManager::GetPowerManager(int iShipId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has iShipId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func692::func)
		 : "rdi"
	);
}

namespace _func693
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Projectile::ForceRenderLayer", typeid(int (Projectile::*)()), ".!b8ffffffffc3662e0f1f840000000000f3c3662e0f1f8400000000000f1f40004889b7f0020000", argdata, 1, 2, &func);
}

FUNC_NAKED int Projectile::ForceRenderLayer()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func693::func)
		 : "rdi"
	);
}

namespace _func694
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Projectile::CollisionCheck", typeid(void (Projectile::*)(Collideable *)), ".4154554889f5534889fb4883ec60448b673c488b064889f7", argdata, 2, 6, &func);
}

FUNC_NAKED void Projectile::CollisionCheck(Collideable *other)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has other
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func694::func)
		 : "rdi", "rsi"
	);
}

namespace _func695
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("Projectile::constructor", typeid(void (Projectile::*)(Pointf , int , int , Pointf )), ".4157415641554154554889fd534881ecf8000000", argdata, 5, 6, &func);
}

FUNC_NAKED void Projectile::constructor(Pointf position, int ownerId, int targetId, Pointf target)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has position
			// rdx has ownerId
			// rcx has targetId
			// r8 has target
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func695::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func696
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Projectile::Initialize", typeid(void (Projectile::*)(const WeaponBlueprint &)), ".415731d2415641554c8daed000000041544989f4554889fd5331db4881ec28010000", argdata, 2, 6, &func);
}

FUNC_NAKED void Projectile::Initialize(const WeaponBlueprint &bp)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has bp
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func696::func)
		 : "rdi", "rsi"
	);
}

namespace _func697
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Projectile::destructor", typeid(void (Projectile::*)()), ".415641554154554889fd534883ec10488b872802000048c707????????48c74708????????48c78738020000????????488d78e84881ff????????0f8507030000", argdata, 1, 6, &func);
}

FUNC_NAKED void Projectile::destructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func697::func)
		 : "rdi"
	);
}

namespace _func698
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ProjectileFactory::constructor", typeid(void (ProjectileFactory::*)(const WeaponBlueprint *, int )), "415741564989fe488d7f284d8dbec8000000415541544d8da680000000554889f553498d9e880000004881ec08010000", argdata, 3, 6, &func);
}

FUNC_NAKED void ProjectileFactory::constructor(const WeaponBlueprint *bp, int shipId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has bp
			// rdx has shipId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func698::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func699
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ProjectileFactory::SelectChargeGoal", typeid(void (ProjectileFactory::*)()), ".803d????????00534889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void ProjectileFactory::SelectChargeGoal()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func699::func)
		 : "rdi"
	);
}

namespace _func700
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ProjectileFactory::IsChargedGoal", typeid(bool (ProjectileFactory::*)()), ".488b47208b808401000085c0", argdata, 1, 2, &func);
}

FUNC_NAKED bool ProjectileFactory::IsChargedGoal()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func700::func)
		 : "rdi"
	);
}

namespace _func701
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ProjectileFactory::SetHacked", typeid(void (ProjectileFactory::*)(int )), "!.89b7240600004881c758010000", argdata, 2, 6, &func);
}

FUNC_NAKED void ProjectileFactory::SetHacked(int hacked)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has hacked
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func701::func)
		 : "rdi", "rsi"
	);
}

namespace _func702
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ProjectileFactory::SetCurrentShip", typeid(void (ProjectileFactory::*)(Targetable *)), ".4839b74801000074274885f6", argdata, 2, 6, &func);
}

FUNC_NAKED void ProjectileFactory::SetCurrentShip(Targetable *ship)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ship
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func702::func)
		 : "rdi", "rsi"
	);
}

namespace _func703
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("ProjectileFactory::SetCooldownModifier", typeid(void (ProjectileFactory::*)(float )), ".f30f104f0cf30f5e4f10", argdata, 2, 6, &func);
}

FUNC_NAKED void ProjectileFactory::SetCooldownModifier(float mod)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has mod
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func703::func)
		 : "rdi", "xmm0"
	);
}

namespace _func704
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ProjectileFactory::ForceCoolup", typeid(void (ProjectileFactory::*)()), ".5380bff2000000004889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void ProjectileFactory::ForceCoolup()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func704::func)
		 : "rdi"
	);
}

namespace _func705
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("ProjectileFactory::RenderChargeBar", typeid(void (ProjectileFactory::*)(float )), "!.4881c758010000", argdata, 2, 6, &func);
}

FUNC_NAKED void ProjectileFactory::RenderChargeBar(float unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func705::func)
		 : "rdi", "xmm0"
	);
}

namespace _func706
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x106};
	static FunctionDefinition funcObj("ProjectileFactory::OnRender", typeid(void (ProjectileFactory::*)(float , bool )), "!.530f28c8488d9f580100004883ec10", argdata, 3, 6, &func);
}

FUNC_NAKED void ProjectileFactory::OnRender(float alpha, bool forceVisual)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has alpha
			// rsi has forceVisual
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func706::func)
		 : "rdi", "xmm0", "rsi"
	);
}

namespace _func707
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ProjectileFactory::FireNextShot", typeid(bool (ProjectileFactory::*)()), ".8b972006000031c085d2", argdata, 1, 2, &func);
}

FUNC_NAKED bool ProjectileFactory::FireNextShot()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func707::func)
		 : "rdi"
	);
}

namespace _func708
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ProjectileFactory::StringToWeapon", typeid(int (*)(const std::string &)), ".53be????????4889fbe8????????85c0", argdata, 1, 2, &func);
}

FUNC_NAKED int ProjectileFactory::StringToWeapon(const std::string &str)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has str
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func708::func)
		 : "rdi"
	);
}

namespace _func709
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ProjectileFactory::GetProjectile", typeid(Projectile *(ProjectileFactory::*)()), ".4157415641554154554889fd488dbf58010000534883ec58", argdata, 1, 2, &func);
}

FUNC_NAKED Projectile *ProjectileFactory::GetProjectile()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func709::func)
		 : "rdi"
	);
}

namespace _func710
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ProjectileFactory::SpendMissiles", typeid(int (ProjectileFactory::*)()), ".55534889fb4883ec288b8708060000", argdata, 1, 2, &func);
}

FUNC_NAKED int ProjectileFactory::SpendMissiles()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func710::func)
		 : "rdi"
	);
}

namespace _func711
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ProjectileFactory::NumTargetsRequired", typeid(int (ProjectileFactory::*)()), ".488b472083b88401000001", argdata, 1, 2, &func);
}

FUNC_NAKED int ProjectileFactory::NumTargetsRequired()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func711::func)
		 : "rdi"
	);
}

namespace _func712
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ProjectileFactory::SaveProjectile", typeid(void (*)(Projectile *, int )), ".5589f5534889fb4883ec08488b07", argdata, 2, 6, &func);
}

FUNC_NAKED void ProjectileFactory::SaveProjectile(Projectile *p, int fd)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has p
			// rsi has fd
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func712::func)
		 : "rdi", "rsi"
	);
}

namespace _func713
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ProjectileFactory::LoadProjectile", typeid(Projectile *(*)(int )), ".5589fd534883ec58", argdata, 1, 2, &func);
}

FUNC_NAKED Projectile *ProjectileFactory::LoadProjectile(int fd)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has fd
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func713::func)
		 : "rdi"
	);
}

namespace _func714
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ProjectileFactory::Fire", typeid(void (ProjectileFactory::*)(std::vector<Pointf> &, int )), ".41544189d4554889f553488b87000100004889fb482b87f800000048c1f80385c0", argdata, 3, 6, &func);
}

FUNC_NAKED void ProjectileFactory::Fire(std::vector<Pointf> &points, int target)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has points
			// rdx has target
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func714::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func715
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ProjectileFactory::Update", typeid(void (ProjectileFactory::*)()), ".4157415641554989fd415455534881ec88010000", argdata, 1, 6, &func);
}

FUNC_NAKED void ProjectileFactory::Update()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func715::func)
		 : "rdi"
	);
}

namespace _func716
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ReactorButton::Accept", typeid(void (ReactorButton::*)()), "55534889fb4883ec288b878c000000", argdata, 1, 6, &func);
}

FUNC_NAKED void ReactorButton::Accept()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func716::func)
		 : "rdi"
	);
}

namespace _func717
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ReactorButton::OnClick", typeid(void (ReactorButton::*)()), "55534889fb4883ec28488bbf90000000", argdata, 1, 6, &func);
}

FUNC_NAKED void ReactorButton::OnClick()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func717::func)
		 : "rdi"
	);
}

namespace _func718
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ReactorButton::OnRightClick", typeid(void (ReactorButton::*)()), "534889fb4883ec208b878c000000", argdata, 1, 6, &func);
}

FUNC_NAKED void ReactorButton::OnRightClick()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func718::func)
		 : "rdi"
	);
}

namespace _func719
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ReactorButton::OnRender", typeid(void (ReactorButton::*)()), "415741564155415455534889fb4881ec3805000048897c2440", argdata, 1, 6, &func);
}

FUNC_NAKED void ReactorButton::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func719::func)
		 : "rdi"
	);
}

void **VTable_RepairAnimation;

namespace _var720
{
	static VariableDefinition varObj("VTable_RepairAnimation", "!0f85060100004c8d6c2430bf2009000049c70424(???????\?)", &VTable_RepairAnimation);
}

namespace _func721
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("RepairStoreBox::constructor", typeid(void (RepairStoreBox::*)(ShipManager *, bool , int )), "4157415641554189cd41544989f4", argdata, 4, 6, &func);
}

FUNC_NAKED void RepairStoreBox::constructor(ShipManager *ship, bool repairAll, int price)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ship
			// rdx has repairAll
			// rcx has price
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func721::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func722
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ResourceControl::constructor", typeid(void (ResourceControl::*)()), "4155be0a00000041545548bdffffffffffffff1f534889fb488d7f20", argdata, 1, 6, &func);
}

FUNC_NAKED void ResourceControl::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func722::func)
		 : "rdi"
	);
}

namespace _func723
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x2ff, 0x10a, 0x109};
	static FunctionDefinition funcObj("ResourceControl::RenderImage", typeid(int (ResourceControl::*)(GL_Texture *, int , int , int , GL_Color , float , bool )), ".4883ec284885f64889f7660fd60424488b0424660fd60c24", argdata, 8, 2, &func);
}

FUNC_NAKED int ResourceControl::RenderImage(GL_Texture *tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has this
			// rsi has tex
			// rdx has x
			// rcx has y
			// r8 has rotation
			// xmm0 has opacity
			// r9 has mirror
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func723::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "xmm0", "r9"
	);
}

namespace _func724
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x2ff, 0x10a, 0x109};
	static FunctionDefinition funcObj("ResourceControl::CreateImagePrimitive", typeid(GL_Primitive *(ResourceControl::*)(GL_Texture *, int , int , int , GL_Color , float , bool )), ".4883ec284885f64889f7660fd60424488b0424660fd60c24", argdata, 8, 2, &func);
}

FUNC_NAKED GL_Primitive *ResourceControl::CreateImagePrimitive(GL_Texture *tex, int unk1, int unk2, int unk3, GL_Color color, float alpha, bool mirror)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has this
			// rsi has tex
			// rdx has unk1
			// rcx has unk2
			// r8 has unk3
			// xmm0 has alpha
			// r9 has mirror
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func724::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "xmm0", "r9"
	);
}

namespace _func725
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ResourceControl::OnInit", typeid(void (ResourceControl::*)(int )), ".534889fb89b7a0000000c7870801000000000000", argdata, 2, 6, &func);
}

FUNC_NAKED void ResourceControl::OnInit(int imageSwappingMode)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has imageSwappingMode
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func725::func)
		 : "rdi", "rsi"
	);
}

namespace _func726
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ResourceControl::LoadFile", typeid(char *(ResourceControl::*)(const std::string &)), ".415541544531e4554889f5", argdata, 2, 2, &func);
}

FUNC_NAKED char *ResourceControl::LoadFile(const std::string &fileName)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has fileName
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func726::func)
		 : "rdi", "rsi"
	);
}

namespace _func727
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ResourceControl::GetImageData", typeid(ImageDesc (ResourceControl::*)(GL_Texture *)), ".534889d04989d14889fb488d7e604883ec10", argdata, 3, 2, &func);
}

FUNC_NAKED ImageDesc ResourceControl::GetImageData(GL_Texture *tex)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has tex
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func727::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func728
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ResourceControl::GetImageId", typeid(GL_Texture *(ResourceControl::*)(const std::string &)), ".4154554889f5be????????534889fb4883ec60", argdata, 2, 2, &func);
}

FUNC_NAKED GL_Texture *ResourceControl::GetImageId(const std::string &dir)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has dir
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func728::func)
		 : "rdi", "rsi"
	);
}

namespace _func729
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x2ff, 0x10a, 0x109};
	static FunctionDefinition funcObj("ResourceControl::RenderImageString", typeid(int (ResourceControl::*)(std::string &, int , int , int , GL_Color , float , bool )), ".41574589c7415641554589cd41544189d45589cd534883ec38", argdata, 8, 2, &func);
}

FUNC_NAKED int ResourceControl::RenderImageString(std::string &tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has this
			// rsi has tex
			// rdx has x
			// rcx has y
			// r8 has rotation
			// xmm0 has opacity
			// r9 has mirror
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func729::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "xmm0", "r9"
	);
}

namespace _func730
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x2ff, 0x10a, 0x109};
	static FunctionDefinition funcObj("ResourceControl::CreateImagePrimitiveString", typeid(GL_Primitive *(ResourceControl::*)(const std::string &, int , int , int , GL_Color , float , bool )), ".41574589c7415641554589cd41544189d45589cd534883ec38", argdata, 8, 2, &func);
}

FUNC_NAKED GL_Primitive *ResourceControl::CreateImagePrimitiveString(const std::string &tex, int x, int y, int rotation, GL_Color color, float alpha, bool mirror)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has this
			// rsi has tex
			// rdx has x
			// rcx has y
			// r8 has rotation
			// xmm0 has alpha
			// r9 has mirror
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func730::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "xmm0", "r9"
	);
}

namespace _func731
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b};
	static FunctionDefinition funcObj("ResourceControl::RenderLoadingBar", typeid(void (ResourceControl::*)(float , float )), ".415455534889fb4883ec604883bf5001000000", argdata, 3, 6, &func);
}

FUNC_NAKED void ResourceControl::RenderLoadingBar(float initialProgress, float finalProgress)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has initialProgress
			// xmm1 has finalProgress
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func731::func)
		 : "rdi", "xmm0", "xmm1"
	);
}

namespace _func732
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ResourceControl::GetFontData", typeid(freetype::font_data &(ResourceControl::*)(int , bool )), ".41548d46fa55534889fb4883ec3083f802", argdata, 3, 2, &func);
}

FUNC_NAKED freetype::font_data &ResourceControl::GetFontData(int fontType, bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has fontType
			// rdx has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func732::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func733
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ResourceControl::PreloadResources", typeid(bool (ResourceControl::*)(bool )), ".415741564155415455534889fb4881ec88000000408874241f", argdata, 2, 2, &func);
}

FUNC_NAKED bool ResourceControl::PreloadResources(bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func733::func)
		 : "rdi", "rsi"
	);
}

ResourceControl *Global_ResourceControl_GlobalResources;

namespace _var734
{
	static VariableDefinition varObj("Global_ResourceControl_GlobalResources", "!be(???????\?)488983100100004889c24889e7", &Global_ResourceControl_GlobalResources);
}

namespace _func735
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("RockAnimation::__DO_NOT_HOOK_1", typeid(void (*)()), "f3c3660f1f44000053be????????4889fb4883ec10488d54240fe8????????4883c4104889d85bc353be????????4889fb4883ec10", argdata, 0, 4, &func);
}

FUNC_NAKED void RockAnimation::__DO_NOT_HOOK_1()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func735::func)
	);
}

namespace _func736
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("RockAnimation::GetDeathSound", typeid(std::string (RockAnimation::*)()), ".53be????????4889fb4883ec10488d54240f", argdata, 2, 2, &func);
}

FUNC_NAKED std::string RockAnimation::GetDeathSound()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func736::func)
		 : "rdi", "rsi"
	);
}

namespace _func737
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("RockAnimation::__DO_NOT_HOOK_2", typeid(void (*)()), ".534889fb4883ec30803d????????007577e8????????89c1", argdata, 0, 4, &func);
}

FUNC_NAKED void RockAnimation::__DO_NOT_HOOK_2()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func737::func)
	);
}

namespace _func738
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("RockAnimation::__DO_NOT_HOOK_3", typeid(void (*)()), ".534889fb4883ec30803d????????007577e8????????89c1", argdata, 0, 4, &func);
}

FUNC_NAKED void RockAnimation::__DO_NOT_HOOK_3()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func738::func)
	);
}

namespace _func739
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("RockAnimation::GetShootingSound", typeid(std::string (RockAnimation::*)()), ".534889fb4883ec30803d????????007577e8????????89c1", argdata, 2, 2, &func);
}

FUNC_NAKED std::string RockAnimation::GetShootingSound()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func739::func)
		 : "rdi", "rsi"
	);
}

namespace _func740
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("RockAnimation::constructor", typeid(void (RockAnimation::*)(const std::string &, int , Pointf , bool )), ".41544189cc5589d5534889fb4883ec50", argdata, 5, 6, &func);
}

FUNC_NAKED void RockAnimation::constructor(const std::string &subRace, int iShipId, Pointf position, bool enemy)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has subRace
			// rdx has iShipId
			// rcx has position
			// r8 has enemy
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func740::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func741
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Room::destructor", typeid(void (Room::*)()), "41574156415541544989fc55534883ec5848c707", argdata, 1, 6, &func);
}

FUNC_NAKED void Room::destructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func741::func)
		 : "rdi"
	);
}

namespace _func742
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x109, 0x1ff};
	static FunctionDefinition funcObj("Room::constructor", typeid(void (Room::*)(int , int , int , int , int , int )), ".41574989ff41564589ce4155415455534489c3410fafde4881ec78010000", argdata, 7, 6, &func);
}

FUNC_NAKED void Room::constructor(int iShipId, int x, int y, int w, int h, int roomId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"subq $8, %%rsp\n\t"
		"pushq 8(%%rbp)\n\t"		// roomId
			// rdi has this
			// rsi has iShipId
			// rdx has x
			// rcx has y
			// r8 has w
			// r9 has h
		"call *%0\n\t"
		"addq $8, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func742::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "r9"
	);
}

namespace _func743
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Room::GetEmptySlots", typeid(int (Room::*)(bool )), ".400fb6f6488b4750488d14b6488d14d0488b4210482b028b4a188b520848c1f80348c1e0064801c84829d0", argdata, 2, 2, &func);
}

FUNC_NAKED int Room::GetEmptySlots(bool intruder)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has intruder
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func743::func)
		 : "rdi", "rsi"
	);
}

namespace _func744
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x106};
	static FunctionDefinition funcObj("Room::OnRenderFloor", typeid(void (Room::*)(float , bool )), ".4883ec28f30f100d????????f30f5c8fb8000000488bbfc0000000", argdata, 3, 6, &func);
}

FUNC_NAKED void Room::OnRenderFloor(float alpha, bool experimental)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has alpha
			// rsi has experimental
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func744::func)
		 : "rdi", "xmm0", "rsi"
	);
}

namespace _func745
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("Room::OnRenderWalls", typeid(void (Room::*)(float )), ".534889fb4883ec10807f6800", argdata, 2, 6, &func);
}

FUNC_NAKED void Room::OnRenderWalls(float alpha)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has alpha
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func745::func)
		 : "rdi", "xmm0"
	);
}

namespace _func746
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ScoreKeeper::constructor", typeid(void (ScoreKeeper::*)()), "4157415641554c8daf8000000041544c8da78001000055488dafa000000053488d9f900000004883ec48", argdata, 1, 6, &func);
}

FUNC_NAKED void ScoreKeeper::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func746::func)
		 : "rdi"
	);
}

namespace _func747
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ScoreKeeper::GetShipId_DO_NOT_USE_DIRECTLY", typeid(std::pair<int, int> (ScoreKeeper::*)(const std::string &)), ".4157415641554531ed41544989f45553", argdata, 2, 2, &func);
}

FUNC_NAKED std::pair<int, int> ScoreKeeper::GetShipId_DO_NOT_USE_DIRECTLY(const std::string &blueprintName)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has blueprintName
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func747::func)
		 : "rdi", "rsi"
	);
}

namespace _func748
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ScoreKeeper::GetShipBlueprint", typeid(std::string (ScoreKeeper::*)(int )), ".4863d2534889fb", argdata, 3, 2, &func);
}

FUNC_NAKED std::string ScoreKeeper::GetShipBlueprint(int index)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has index
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func748::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func749
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ScoreKeeper::SaveGame", typeid(void (ScoreKeeper::*)(int )), "!.41544989fc5589f5", argdata, 2, 6, &func);
}

FUNC_NAKED void ScoreKeeper::SaveGame(int fd)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has fd
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func749::func)
		 : "rdi", "rsi"
	);
}

namespace _func750
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ScoreKeeper::LoadGame", typeid(void (ScoreKeeper::*)(int )), ".41544989fc89f75589f5534883ec20", argdata, 2, 6, &func);
}

FUNC_NAKED void ScoreKeeper::LoadGame(int fd)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has fd
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func750::func)
		 : "rdi", "rsi"
	);
}

namespace _func751
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ScoreKeeper::GetShipUnlocked", typeid(bool (ScoreKeeper::*)(int , int )), ".83fa02760b31c0", argdata, 3, 2, &func);
}

FUNC_NAKED bool ScoreKeeper::GetShipUnlocked(int shipId, int shipVariant)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shipId
			// rdx has shipVariant
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func751::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func752
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ScoreKeeper::SetVictory", typeid(void (ScoreKeeper::*)(bool )), ".4084f64088b798010000", argdata, 2, 6, &func);
}

FUNC_NAKED void ScoreKeeper::SetVictory(bool victory)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has victory
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func752::func)
		 : "rdi", "rsi"
	);
}

namespace _func753
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ScoreKeeper::AddScrapCollected", typeid(void (ScoreKeeper::*)(int )), ".5589f5534889fb", argdata, 2, 6, &func);
}

FUNC_NAKED void ScoreKeeper::AddScrapCollected(int scrap)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has scrap
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func753::func)
		 : "rdi", "rsi"
	);
}

namespace _func754
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ScoreKeeper::SaveScores", typeid(void (ScoreKeeper::*)(int , std::vector<TopScore> &)), ".415741564989d6415549bdabaaaaaaaaaaaaaa415455534883ec48", argdata, 3, 6, &func);
}

FUNC_NAKED void ScoreKeeper::SaveScores(int file, std::vector<TopScore> &topScores)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has file
			// rdx has topScores
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func754::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func755
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ScoreKeeper::AddTopScoreList", typeid(int (ScoreKeeper::*)(TopScore &, std::vector<TopScore> &)), ".415448b8abaaaaaaaaaaaaaa4989f4554889d5534883ec50", argdata, 3, 2, &func);
}

FUNC_NAKED int ScoreKeeper::AddTopScoreList(TopScore &score, std::vector<TopScore> &topScoreList)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has score
			// rdx has topScoreList
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func755::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func756
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ScoreKeeper::AddTopScoreType", typeid(void (ScoreKeeper::*)(TopScore &, int )), ".4157488d46084189d7baffffffff41564989fe", argdata, 3, 6, &func);
}

FUNC_NAKED void ScoreKeeper::AddTopScoreType(TopScore &topScore, int type)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has topScore
			// rdx has type
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func756::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func757
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ScoreKeeper::Save", typeid(void (ScoreKeeper::*)(bool )), ".4156415541545589f5534889fb", argdata, 2, 6, &func);
}

FUNC_NAKED void ScoreKeeper::Save(bool newHighScore)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has newHighScore
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func757::func)
		 : "rdi", "rsi"
	);
}

namespace _func758
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ScoreKeeper::WipeProfile", typeid(void (ScoreKeeper::*)(bool )), ".415741564531f641554531ed41544989fc", argdata, 2, 6, &func);
}

FUNC_NAKED void ScoreKeeper::WipeProfile(bool permanent)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has permanent
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func758::func)
		 : "rdi", "rsi"
	);
}

namespace _func759
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("ScoreKeeper::UnlockShip", typeid(void (ScoreKeeper::*)(int , int , bool , bool )), ".415741564189ce41554189d541544589c4554889fd5389f34883ec28", argdata, 5, 6, &func);
}

FUNC_NAKED void ScoreKeeper::UnlockShip(int shipType, int shipVariant, bool save, bool hidePopup)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shipType
			// rdx has shipVariant
			// rcx has save
			// r8 has hidePopup
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func759::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func760
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ScoreKeeper::LoadVersionFour", typeid(void (ScoreKeeper::*)(int , int )), ".41574889f8415641554189d54154555389f34881ec98000000", argdata, 3, 6, &func);
}

FUNC_NAKED void ScoreKeeper::LoadVersionFour(int file, int version)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has file
			// rdx has version
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func760::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func761
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ScoreKeeper::OnInit", typeid(void (ScoreKeeper::*)()), ".415631f64155415455534889fb488dab880500004c8da3a80b00004883ec70", argdata, 1, 6, &func);
}

FUNC_NAKED void ScoreKeeper::OnInit()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func761::func)
		 : "rdi"
	);
}

namespace _func762
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("ScoreKeeper::RenderTopScores", typeid(void (ScoreKeeper::*)(const std::vector<TopScore> &, Point , int )), ".4157415641554989f5415455534881ec68020000", argdata, 4, 6, &func);
}

FUNC_NAKED void ScoreKeeper::RenderTopScores(const std::vector<TopScore> &topScoreList, Point position, int newHighScore)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has topScoreList
			// rdx has position
			// rcx has newHighScore
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func762::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func763
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ScoreKeeper::CheckTypes", typeid(void (ScoreKeeper::*)()), ".4155ba01000000415455534889fb4c8da3880700004883ec18", argdata, 1, 6, &func);
}

FUNC_NAKED void ScoreKeeper::CheckTypes()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func763::func)
		 : "rdi"
	);
}

namespace _func764
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ScoreKeeper::SetupTopShip", typeid(void (ScoreKeeper::*)(int )), ".41545589f5534889fb4883ec40", argdata, 2, 6, &func);
}

FUNC_NAKED void ScoreKeeper::SetupTopShip(int variant)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has variant
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func764::func)
		 : "rdi", "rsi"
	);
}

namespace _func765
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ScoreKeeper::CycleLeft", typeid(void (ScoreKeeper::*)()), "!.55bd09000000534889fb4883ec08", argdata, 1, 6, &func);
}

FUNC_NAKED void ScoreKeeper::CycleLeft()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func765::func)
		 : "rdi"
	);
}

namespace _func766
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ScoreKeeper::CycleRight", typeid(void (ScoreKeeper::*)()), "!.5531ed534889fb4883ec08", argdata, 1, 6, &func);
}

FUNC_NAKED void ScoreKeeper::CycleRight()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func766::func)
		 : "rdi"
	);
}

namespace _func767
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ScoreKeeper::MouseClick", typeid(void (ScoreKeeper::*)(int , int )), ".55534889fb4883ec0880bf280c000000", argdata, 3, 6, &func);
}

FUNC_NAKED void ScoreKeeper::MouseClick(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func767::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func768
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ScoreKeeper::KeyDown", typeid(bool (ScoreKeeper::*)(SDLKey )), ".5589f5534889fb4883ec18", argdata, 2, 2, &func);
}

FUNC_NAKED bool ScoreKeeper::KeyDown(SDLKey key)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has key
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func768::func)
		 : "rdi", "rsi"
	);
}

namespace _func769
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ScoreKeeper::Open", typeid(void (ScoreKeeper::*)(bool )), ".4157ba0d000000", argdata, 2, 6, &func);
}

FUNC_NAKED void ScoreKeeper::Open(bool fromGameOver)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has fromGameOver
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func769::func)
		 : "rdi", "rsi"
	);
}

namespace _func770
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ScoreKeeper::OnRender", typeid(void (ScoreKeeper::*)(bool )), ".4157415641554189f5415455534889fb4881ec28020000", argdata, 2, 6, &func);
}

FUNC_NAKED void ScoreKeeper::OnRender(bool lastPlaythrough)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has lastPlaythrough
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func770::func)
		 : "rdi", "rsi"
	);
}

ScoreKeeper *Global_ScoreKeeper_Keeper;

namespace _var771
{
	static VariableDefinition varObj("Global_ScoreKeeper_Keeper", "!488b3b488b07ff5028488b7b08488b07ff502831f6bf(???????\?)", &Global_ScoreKeeper_Keeper);
}

namespace _func772
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::GetDlcEnabled", typeid(bool (*)()), "31c0803d????????007505c30f1f40004883ec08", argdata, 0, 0, &func);
}

FUNC_NAKED bool Settings::GetDlcEnabled()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func772::func)
	);
}

namespace _func773
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Settings::GetHotkeyName", typeid(std::string (*)(const std::string &)), ".415741564155415455534883ec58488d6c2440", argdata, 2, 2, &func);
}

FUNC_NAKED std::string Settings::GetHotkeyName(const std::string &name)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has name
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func773::func)
		 : "rdi", "rsi"
	);
}

namespace _func774
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Settings::GetHotkey", typeid(SDLKey (*)(const std::string &)), ".415741564155415455534883ec2848897c2418", argdata, 1, 2, &func);
}

FUNC_NAKED SDLKey Settings::GetHotkey(const std::string &hotkeyName)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has hotkeyName
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func774::func)
		 : "rdi"
	);
}

namespace _func775
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Settings::SetHotkey", typeid(void (*)(const std::string &, SDLKey )), ".415741564155415455534883ec5848897c2420", argdata, 2, 6, &func);
}

FUNC_NAKED void Settings::SetHotkey(const std::string &hotkeyName, SDLKey key)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has hotkeyName
			// rsi has key
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func775::func)
		 : "rdi", "rsi"
	);
}

namespace _func776
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::SaveSettings", typeid(void (*)()), ".415741564155415455534881ecc8010000", argdata, 0, 6, &func);
}

FUNC_NAKED void Settings::SaveSettings()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func776::func)
	);
}

namespace _func777
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::GetCommandConsole", typeid(char (*)()), "!.0fb605????????c3", argdata, 0, 0, &func);
}

FUNC_NAKED char Settings::GetCommandConsole()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func777::func)
	);
}

namespace _func778
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::ResetHotkeys", typeid(void (*)()), ".415641be????????4155415441bc????????55534883ec30", argdata, 0, 6, &func);
}

FUNC_NAKED void Settings::ResetHotkeys()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func778::func)
	);
}

namespace _func779
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::LoadSettings", typeid(void (*)()), ".415741564155415455534881ec58020000", argdata, 0, 6, &func);
}

FUNC_NAKED void Settings::LoadSettings()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func779::func)
	);
}

SettingValues *Global_Settings_Settings;

namespace _var780
{
	static VariableDefinition varObj("Global_Settings_Settings", "!4155415441bc(???????\?)55534883ec30", &Global_Settings_Settings);
}

namespace _func781
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Shields::Jump", typeid(void (Shields::*)()), "534889fb4883ec30e8????????f30f100d", argdata, 1, 6, &func);
}

FUNC_NAKED void Shields::Jump()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func781::func)
		 : "rdi"
	);
}

namespace _func782
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Shields::OnLoop", typeid(void (Shields::*)()), ".41564155415455534889fb4c8d6b104883ec30", argdata, 1, 6, &func);
}

FUNC_NAKED void Shields::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func782::func)
		 : "rdi"
	);
}

namespace _func783
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("Shields::constructor", typeid(void (Shields::*)(int , int , int , const std::string &)), ".4154554c89c54189c889d189f231f6534889fb4883ec40", argdata, 5, 6, &func);
}

FUNC_NAKED void Shields::constructor(int roomId, int shipId, int startingPower, const std::string &shieldFile)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
			// rdx has shipId
			// rcx has startingPower
			// r8 has shieldFile
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func783::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func784
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Shields::AddSuperShield", typeid(void (Shields::*)(Point )), ".55ba050000004889f5534889fb4883ec08", argdata, 2, 6, &func);
}

FUNC_NAKED void Shields::AddSuperShield(Point pos)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func784::func)
		 : "rdi", "rsi"
	);
}

namespace _func785
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x2ff};
	static FunctionDefinition funcObj("Shields::SetBaseEllipse", typeid(void (Shields::*)(Globals::Ellipse )), ".660fd64424f8488b4424f84889b750020000", argdata, 2, 6, &func);
}

FUNC_NAKED void Shields::SetBaseEllipse(Globals::Ellipse ellipse)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// ellipse
		"pushq 8(%%rbp)\n\t"		// ellipse
			// rdi has this
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func785::func)
		 : "rdi"
	);
}

namespace _func786
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Shields::InstantCharge", typeid(void (Shields::*)()), ".55534889fb488dabd00200004883ec38", argdata, 1, 6, &func);
}

FUNC_NAKED void Shields::InstantCharge()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func786::func)
		 : "rdi"
	);
}

namespace _func787
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b};
	static FunctionDefinition funcObj("Shields::RenderBase", typeid(void (Shields::*)(float , float )), ".41550f28f9415455534889fb4883ec68", argdata, 3, 6, &func);
}

FUNC_NAKED void Shields::RenderBase(float alpha, float superShieldOverwrite)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has alpha
			// xmm1 has superShieldOverwrite
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func787::func)
		 : "rdi", "xmm0", "xmm1"
	);
}

namespace _func788
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x10a, 0x10b, 0x8ff, 0x102};
	static FunctionDefinition funcObj("Shields::CollisionReal", typeid(CollisionResponse (Shields::*)(float , float , Damage , bool )), ".415741564189d641554989f5415455534889fb488d7f04", argdata, 6, 2, &func);
}

FUNC_NAKED CollisionResponse Shields::CollisionReal(float x, float y, Damage damage, bool force)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 64(%%rbp)\n\t"		// damage
		"pushq 56(%%rbp)\n\t"		// damage
		"pushq 48(%%rbp)\n\t"		// damage
		"pushq 40(%%rbp)\n\t"		// damage
		"pushq 32(%%rbp)\n\t"		// damage
		"pushq 24(%%rbp)\n\t"		// damage
		"pushq 16(%%rbp)\n\t"		// damage
		"pushq 8(%%rbp)\n\t"		// damage
			// rdi has implicit_output
			// rsi has this
			// xmm0 has x
			// xmm1 has y
			// rdx has force
		"call *%0\n\t"
		"addq $64, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func788::func)
		 : "rdi", "rsi", "xmm0", "xmm1", "rdx"
	);
}

GL_Color *Global_COLOR_GREEN;

namespace _var789
{
	static VariableDefinition varObj("Global_COLOR_GREEN", "!f30fc2cf01488bbbf8020000f30f101d(???????\?)f30f5edd", &Global_COLOR_GREEN);
}

namespace _func790
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Ship::GetBaseEllipse", typeid(Globals::Ellipse (Ship::*)()), "534889fb4883ec20f30f108fc4020000", argdata, 1, 10, &func);
}

FUNC_NAKED Globals::Ellipse Ship::GetBaseEllipse()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func790::func)
		 : "rdi"
	);
}

namespace _func791
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Ship::RoomLocked", typeid(bool (Ship::*)(int )), ".4c8b8778040000488b8f8004000048b835c2724f232cf7344c29c148c1f903", argdata, 2, 2, &func);
}

FUNC_NAKED bool Ship::RoomLocked(int roomId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func791::func)
		 : "rdi", "rsi"
	);
}

namespace _func792
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("Ship::OnRenderJump", typeid(void (Ship::*)(float )), ".41564155415455534889fb4883ec208b7f08", argdata, 2, 6, &func);
}

FUNC_NAKED void Ship::OnRenderJump(float progress)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has progress
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func792::func)
		 : "rdi", "xmm0"
	);
}

namespace _func793
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Ship::OnRenderBase", typeid(void (Ship::*)(bool )), ".41554189f5415455534889fb4883ec288b7f08", argdata, 2, 6, &func);
}

FUNC_NAKED void Ship::OnRenderBase(bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func793::func)
		 : "rdi", "rsi"
	);
}

namespace _func794
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Ship::OnRenderFloor", typeid(void (Ship::*)(bool )), ".5589f5534889fb4883ec1880bf7004000000", argdata, 2, 6, &func);
}

FUNC_NAKED void Ship::OnRenderFloor(bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func794::func)
		 : "rdi", "rsi"
	);
}

namespace _func795
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Ship::OnRenderSparks", typeid(void (Ship::*)()), ".5531c94889fd5331db4883ec08488b5710488b47184829d048c1f8034885c07429", argdata, 1, 6, &func);
}

FUNC_NAKED void Ship::OnRenderSparks()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func795::func)
		 : "rdi"
	);
}

namespace _func796
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Ship::OnRenderBreaches", typeid(void (Ship::*)()), ".41544531e45531ed53488b57404889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void Ship::OnRenderBreaches()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func796::func)
		 : "rdi"
	);
}

namespace _func797
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("Ship::GetSelectedRoomId", typeid(int (Ship::*)(int , int , bool )), "!.41544189cc5589d5538b7f08", argdata, 4, 2, &func);
}

FUNC_NAKED int Ship::GetSelectedRoomId(int x, int y, bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
			// rcx has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func797::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func798
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Ship::SetSelectedRoom", typeid(void (Ship::*)(int )), ".415431c94189f4554889fd53488b5710", argdata, 2, 6, &func);
}

FUNC_NAKED void Ship::SetSelectedRoom(int roomId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func798::func)
		 : "rdi", "rsi"
	);
}

namespace _func799
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("Ship::SetRoomBlackout", typeid(void (Ship::*)(int , bool )), "!.4863c60fb6f2", argdata, 3, 6, &func);
}

FUNC_NAKED void Ship::SetRoomBlackout(int roomId, bool blackout)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
			// rdx has blackout
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func799::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func800
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("Ship::GetAvailableRoomSlot", typeid(int (Ship::*)(int , bool )), "!.4863c60fb6f2", argdata, 3, 2, &func);
}

FUNC_NAKED int Ship::GetAvailableRoomSlot(int roomId, bool intruder)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
			// rdx has intruder
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func800::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func801
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Ship::EmptySlots", typeid(int (Ship::*)(int )), ".41544863f64c8d24f500000000554889fd", argdata, 2, 2, &func);
}

FUNC_NAKED int Ship::EmptySlots(int roomId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func801::func)
		 : "rdi", "rsi"
	);
}

namespace _func802
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("Ship::FullRoom", typeid(bool (Ship::*)(int , bool )), ".488b4f10488b47184829c848c1f80339c6", argdata, 3, 2, &func);
}

FUNC_NAKED bool Ship::FullRoom(int roomId, bool intruder)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
			// rdx has intruder
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func802::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func803
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("Ship::OnRenderWalls", typeid(void (Ship::*)(bool , bool )), ".41574531ff41564c8db7500400004155440fb6ee41544189d45531ed534889fb4883ec18", argdata, 3, 6, &func);
}

FUNC_NAKED void Ship::OnRenderWalls(bool forceView, bool doorControlMode)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has forceView
			// rdx has doorControlMode
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func803::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func804
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Ship::OnLoop", typeid(void (Ship::*)(std::vector<float> &)), ".415741564989fe41554154554889f553488d9f500400004883ec68", argdata, 2, 6, &func);
}

FUNC_NAKED void Ship::OnLoop(std::vector<float> &oxygenLevels)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has oxygenLevels
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func804::func)
		 : "rdi", "rsi"
	);
}

namespace _func805
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Ship::BreachRandomHull", typeid(void (Ship::*)(int )), ".4156415541544989fc554863ee534883ec40", argdata, 2, 6, &func);
}

FUNC_NAKED void Ship::BreachRandomHull(int roomId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func805::func)
		 : "rdi", "rsi"
	);
}

namespace _func806
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x10a};
	static FunctionDefinition funcObj("Ship::LockdownRoom", typeid(void (Ship::*)(int , Pointf )), ".41574989ff4156415541545589f5534881ec38010000", argdata, 3, 6, &func);
}

FUNC_NAKED void Ship::LockdownRoom(int roomId, Pointf pos)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
			// xmm0 has pos
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func806::func)
		 : "rdi", "rsi", "xmm0"
	);
}

namespace _func807
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Ship::OnInit", typeid(void (Ship::*)(ShipBlueprint *)), "!.41574989ff41564155415455534889f34881ec28030100", argdata, 2, 6, &func);
}

FUNC_NAKED void Ship::OnInit(ShipBlueprint *bp)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has bp
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func807::func)
		 : "rdi", "rsi"
	);
}

namespace _noop808
{
	static NoOpDefinition noOpObj("Global__NOP__Ship_OnInit_0", "!.39c27d0b(c6840cb000000001)");
}

namespace _noop809
{
	static NoOpDefinition noOpObj("Global__NOP__Ship_OnInit_1", "!.39c27d03(c60101)");
}

namespace _noop810
{
	static NoOpDefinition noOpObj("Global__NOP__Ship_OnInit_2", "!.89c67d03(c60101)");
}

namespace _noop811
{
	static NoOpDefinition noOpObj("Global__NOP__Ship_OnInit_3", "!.39c17d0b(c684149000000001)");
}

namespace _noop812
{
	static NoOpDefinition noOpObj("Global__NOP__Ship_OnInit_4", "!.39c17d03(c60201)");
}

namespace _noop813
{
	static NoOpDefinition noOpObj("Global__NOP__Ship_OnInit_5", "!.89c67e03(c60201)");
}

namespace _func814
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipAI::constructor", typeid(void (ShipAI::*)(bool )), "5589f5534889fb488d7f104883ec0848c747f800000000", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipAI::constructor(bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func814::func)
		 : "rdi", "rsi"
	);
}

namespace _func815
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipAI::SetStalemate", typeid(void (ShipAI::*)(bool )), ".4084f6740980bf9801000000", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipAI::SetStalemate(bool stalemate)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has stalemate
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func815::func)
		 : "rdi", "rsi"
	);
}

namespace _func816
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipAI::OnLoop", typeid(void (ShipAI::*)(bool )), ".41545589f5534889fb4883ec304084f6488b07", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipAI::OnLoop(bool hostile)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has hostile
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func816::func)
		 : "rdi", "rsi"
	);
}

namespace _func817
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipAI::GetTeleportCommand", typeid(std::pair<int, int> (ShipAI::*)()), "5348837f08004889fb", argdata, 1, 2, &func);
}

FUNC_NAKED std::pair<int, int> ShipAI::GetTeleportCommand()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func817::func)
		 : "rdi"
	);
}

namespace _func818
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipBlueprint::destructor", typeid(void (ShipBlueprint::*)()), "4154554889fd534883ec10488b874002000048c707", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipBlueprint::destructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func818::func)
		 : "rdi"
	);
}

namespace _func819
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipBuilder::constructor", typeid(void (ShipBuilder::*)()), "534889fb488d7f184883ec30", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipBuilder::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func819::func)
		 : "rdi"
	);
}

namespace _func820
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipBuilder::MouseMove", typeid(void (ShipBuilder::*)(int , int )), ".4157488d87201100004989ff41564889c7415541545589d55389f34881ec08010000", argdata, 3, 6, &func);
}

FUNC_NAKED void ShipBuilder::MouseMove(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func820::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func821
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipBuilder::ClearShipAchievements", typeid(void (ShipBuilder::*)()), ".488b87f81d0000c787101e0000ffffffff", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipBuilder::ClearShipAchievements()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func821::func)
		 : "rdi"
	);
}

namespace _func822
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipBuilder::SetupShipAchievements", typeid(void (ShipBuilder::*)()), ".4156be????????41554989fd415455534883ec50", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipBuilder::SetupShipAchievements()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func822::func)
		 : "rdi"
	);
}

namespace _func823
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipBuilder::CreateEquipmentBoxes", typeid(void (ShipBuilder::*)()), ".41574989ff41564155415455534883ec48488bb710110000", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipBuilder::CreateEquipmentBoxes()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func823::func)
		 : "rdi"
	);
}

namespace _func824
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipBuilder::CreateSystemBoxes", typeid(void (ShipBuilder::*)()), ".4157415641554154554889fd534883ec18488bb700120000", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipBuilder::CreateSystemBoxes()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func824::func)
		 : "rdi"
	);
}

namespace _func825
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipBuilder::OnRender", typeid(void (ShipBuilder::*)()), ".4155415455534889fb4883ec7880bf5814000000", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipBuilder::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func825::func)
		 : "rdi"
	);
}

namespace _func826
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipBuilder::OnLoop", typeid(void (ShipBuilder::*)()), ".415741564155415455534889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipBuilder::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func826::func)
		 : "rdi"
	);
}

namespace _func827
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipBuilder::CheckTypes", typeid(void (ShipBuilder::*)()), ".4155ba01000000415455534889fb4c8da3580b00004883ec18", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipBuilder::CheckTypes()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func827::func)
		 : "rdi"
	);
}

namespace _func828
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipBuilder::SwitchShip", typeid(void (ShipBuilder::*)(int , int )), ".41554189f541544c63e255534889fb4883ec28", argdata, 3, 6, &func);
}

FUNC_NAKED void ShipBuilder::SwitchShip(int shipType, int shipVariant)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shipType
			// rdx has shipVariant
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func828::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func829
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipBuilder::CycleShipNext", typeid(void (ShipBuilder::*)()), "!.41564989fe415541545553488b3f4885ff", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipBuilder::CycleShipNext()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func829::func)
		 : "rdi"
	);
}

namespace _func830
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipBuilder::SwapType", typeid(void (ShipBuilder::*)(int )), "!.5589f5534889fb4883ec08488b3f4885ff", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipBuilder::SwapType(int variant)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has variant
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func830::func)
		 : "rdi", "rsi"
	);
}

namespace _func831
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipBuilder::CycleShipPrevious", typeid(void (ShipBuilder::*)()), "!.41564989fe415541545553488b3f4885ff", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipBuilder::CycleShipPrevious()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func831::func)
		 : "rdi"
	);
}

namespace _func832
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipBuilder::OnKeyDown", typeid(void (ShipBuilder::*)(SDLKey )), ".5589f5534889fb4883ec0880bf5814000000", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipBuilder::OnKeyDown(SDLKey key)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has key
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func832::func)
		 : "rdi", "rsi"
	);
}

namespace _func833
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipBuilder::MouseClick", typeid(void (ShipBuilder::*)(int , int )), ".415455534889fb4883ec3080bf701b000000", argdata, 3, 6, &func);
}

FUNC_NAKED void ShipBuilder::MouseClick(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func833::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func834
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipBuilder::Open", typeid(void (ShipBuilder::*)()), ".4157415641554154554889fd534881ece8030000", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipBuilder::Open()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func834::func)
		 : "rdi"
	);
}

namespace _func835
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipButton::constructor", typeid(void (ShipButton::*)(int , int )), "41574156415541544189d45589f5534889fb4881ec38030000", argdata, 3, 6, &func);
}

FUNC_NAKED void ShipButton::constructor(int shipType, int shipVariant)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shipType
			// rdx has shipVariant
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func835::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func836
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipButton::OnInit", typeid(void (ShipButton::*)(const std::string &, Point )), ".4889d1534889fb48c1f920", argdata, 3, 6, &func);
}

FUNC_NAKED void ShipButton::OnInit(const std::string &imgName, Point pos)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has imgName
			// rdx has pos
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func836::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func837
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipButton::MouseMove", typeid(void (ShipButton::*)(int , int )), "!.41554189f5415455534889fb4883ec18", argdata, 3, 6, &func);
}

FUNC_NAKED void ShipButton::MouseMove(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func837::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func838
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipButton::OnRender", typeid(void (ShipButton::*)()), ".55534889fb4883ec4880bf9800000000", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipButton::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func838::func)
		 : "rdi"
	);
}

namespace _func839
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipEvent::constructor", typeid(void (ShipEvent::*)(const ShipEvent &)), "415641554989f5488d760841544989fc488d7f08", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipEvent::constructor(const ShipEvent &event)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has event
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func839::func)
		 : "rdi", "rsi"
	);
}

namespace _func840
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipGenerator::UpgradeSystem", typeid(bool (*)(ShipManager *, std::vector<int> &, unsigned int )), "4157415641554189d541544989fc55534883ec38", argdata, 3, 2, &func);
}

FUNC_NAKED bool ShipGenerator::UpgradeSystem(ShipManager *ship, std::vector<int> &systemMaxes, unsigned int sysId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has ship
			// rsi has systemMaxes
			// rdx has sysId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func840::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func841
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleCrewList", typeid(std::vector<CrewBlueprint> (*)(ShipManager *, const std::string &, unsigned int )), ".41574156415541544989d4554889fd534881ec88010000", argdata, 4, 2, &func);
}

FUNC_NAKED std::vector<CrewBlueprint> ShipGenerator::GetPossibleCrewList(ShipManager *ship, const std::string &crewList, unsigned int flags)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has ship
			// rdx has crewList
			// rcx has flags
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func841::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func842
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleWeaponList", typeid(std::vector<WeaponBlueprint*> (*)(ShipManager *, const std::string &, int , unsigned int )), ".4157415641554589c5415455534889fb4889f74883ec68", argdata, 5, 2, &func);
}

FUNC_NAKED std::vector<WeaponBlueprint*> ShipGenerator::GetPossibleWeaponList(ShipManager *ship, const std::string &weaponList, int scrap, unsigned int flags)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has ship
			// rdx has weaponList
			// rcx has scrap
			// r8 has flags
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func842::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func843
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x109};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleDroneList", typeid(std::vector<DroneBlueprint*> (*)(ShipManager *, const std::string &, int , unsigned int , bool )), ".415741564989d6415541544589c4554889fd4889f7534489cb4881ec88000000", argdata, 6, 2, &func);
}

FUNC_NAKED std::vector<DroneBlueprint*> ShipGenerator::GetPossibleDroneList(ShipManager *ship, const std::string &droneList, int scrap, unsigned int flags, bool repeat)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has ship
			// rdx has droneList
			// rcx has scrap
			// r8 has flags
			// r9 has repeat
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func843::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "r9"
	);
}

namespace _func844
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipGenerator::GenerateSystemMaxes", typeid(std::vector<int> (*)(const ShipBlueprint &, int )), ".415741564989fe41554c8dae3001000041545589d55331db4883ec28", argdata, 3, 2, &func);
}

FUNC_NAKED std::vector<int> ShipGenerator::GenerateSystemMaxes(const ShipBlueprint &ship, int level)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has ship
			// rdx has level
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func844::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func845
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleSystemUpgrades0", typeid(std::vector<int> (*)(ShipManager *, std::vector<int> &, int , int )), ".41574989ff41564989d64155415455534889f331f64883ec58", argdata, 5, 2, &func);
}

FUNC_NAKED std::vector<int> ShipGenerator::GetPossibleSystemUpgrades0(ShipManager *ship, std::vector<int> &systemMaxes, int scrap, int type)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has ship
			// rdx has systemMaxes
			// rcx has scrap
			// r8 has type
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func845::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func846
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleSystemUpgrades1", typeid(std::vector<int> (*)(ShipManager *, std::vector<int> &, int , int )), ".415741564989fe41554989d54154554889f531f6534883ec58", argdata, 5, 2, &func);
}

FUNC_NAKED std::vector<int> ShipGenerator::GetPossibleSystemUpgrades1(ShipManager *ship, std::vector<int> &systemMaxes, int scrap, int type)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has ship
			// rdx has systemMaxes
			// rcx has scrap
			// r8 has type
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func846::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func847
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleSystemUpgrades2", typeid(std::vector<int> (*)(ShipManager *, std::vector<int> &, int , int )), ".415741564989fe41554989d54154554889f531f6534883ec58", argdata, 5, 2, &func);
}

FUNC_NAKED std::vector<int> ShipGenerator::GetPossibleSystemUpgrades2(ShipManager *ship, std::vector<int> &systemMaxes, int scrap, int type)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has ship
			// rdx has systemMaxes
			// rcx has scrap
			// r8 has type
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func847::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func848
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipGenerator::CreateShip", typeid(ShipManager *(*)(const std::string &, int , ShipEvent &)), ".41574156415541544189f4554889d5534881ec18050000", argdata, 3, 2, &func);
}

FUNC_NAKED ShipManager *ShipGenerator::CreateShip(const std::string &name, int sector, ShipEvent &event)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has name
			// rsi has sector
			// rdx has event
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func848::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func849
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleSystemUpgrades", typeid(std::vector<int> (*)(ShipManager *, std::vector<int> &, int , int )), ".41574989ff41564989d641554154554889f531f6534489c34883ec58", argdata, 5, 2, &func);
}

FUNC_NAKED std::vector<int> ShipGenerator::GetPossibleSystemUpgrades(ShipManager *ship, std::vector<int> &systemMaxes, int scrap, int type)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has ship
			// rdx has systemMaxes
			// rcx has scrap
			// r8 has type
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func849::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func850
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("ShipGraph::GetSlotRenderPosition", typeid(Point (ShipGraph::*)(int , int , bool )), "41554c63ea41544989fc5589cd5389f34883ec28", argdata, 4, 2, &func);
}

FUNC_NAKED Point ShipGraph::GetSlotRenderPosition(int slotId, int roomId, bool intruder)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has slotId
			// rdx has roomId
			// rcx has intruder
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func850::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func851
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipGraph::DoorCount", typeid(int (ShipGraph::*)(int )), ".488b4f30488b573831c04829ca48c1fa02", argdata, 2, 2, &func);
}

FUNC_NAKED int ShipGraph::DoorCount(int roomId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func851::func)
		 : "rdi", "rsi"
	);
}

namespace _func852
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("ShipGraph::ConnectingDoor", typeid(Door *(ShipGraph::*)(int , int , int , int )), ".415741564189d641554589c541544189cc5589f5534889fb4883ec68", argdata, 5, 2, &func);
}

FUNC_NAKED Door *ShipGraph::ConnectingDoor(int x1, int y1, int x2, int y2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x1
			// rdx has y1
			// rcx has x2
			// r8 has y2
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func852::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func853
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("ShipGraph::ConnectedGridSquares", typeid(int (ShipGraph::*)(int , int , int , int )), ".41574189cf41564589c641b82300000041554531ed41544989fcbf23000000", argdata, 5, 2, &func);
}

FUNC_NAKED int ShipGraph::ConnectedGridSquares(int x1, int y1, int x2, int y2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x1
			// rdx has y1
			// rcx has x2
			// r8 has y2
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func853::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func854
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipGraph::ConnectedGridSquaresPoint", typeid(int (ShipGraph::*)(Point , Point )), "!.4889d14889f24989c8", argdata, 3, 2, &func);
}

FUNC_NAKED int ShipGraph::ConnectedGridSquaresPoint(Point p1, Point p2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has p1
			// rdx has p2
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func854::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func855
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipGraph::ConnectingDoor", typeid(Door *(ShipGraph::*)(Point , Point )), "!.4889d14889f24989c8", argdata, 3, 2, &func);
}

FUNC_NAKED Door *ShipGraph::ConnectingDoor(Point p1, Point p2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has p1
			// rdx has p2
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func855::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func856
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipGraph::GetNumSlots", typeid(int (ShipGraph::*)(int )), ".488b074863f6488b04f0", argdata, 2, 2, &func);
}

FUNC_NAKED int ShipGraph::GetNumSlots(int room)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has room
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func856::func)
		 : "rdi", "rsi"
	);
}

namespace _func857
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipGraph::PopClosestDoor", typeid(int (ShipGraph::*)(std::vector<int> &, std::vector<float> &)), ".554889f5534883ec08", argdata, 3, 2, &func);
}

FUNC_NAKED int ShipGraph::PopClosestDoor(std::vector<int> &doors, std::vector<float> &distances)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has doors
			// rdx has distances
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func857::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func858
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("ShipGraph::ConvertToWorldAngle", typeid(float (ShipGraph::*)(float )), ".f30f584758", argdata, 2, 2, &func);
}

FUNC_NAKED float ShipGraph::ConvertToWorldAngle(float ang)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has ang
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func858::func)
		 : "rdi", "xmm0"
	);
}

namespace _func859
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("ShipGraph::ConvertToLocalAngle", typeid(float (ShipGraph::*)(float )), ".f30f5c4758", argdata, 2, 2, &func);
}

FUNC_NAKED float ShipGraph::ConvertToLocalAngle(float ang)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has ang
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func859::func)
		 : "rdi", "xmm0"
	);
}

namespace _func860
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("ShipGraph::ConvertToWorldPosition", typeid(Pointf (ShipGraph::*)(Pointf )), ".534889fb4883ec20f30f2a7f48", argdata, 2, 2, &func);
}

FUNC_NAKED Pointf ShipGraph::ConvertToWorldPosition(Pointf local)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has local
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func860::func)
		 : "rdi", "xmm0"
	);
}

namespace _func861
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x106};
	static FunctionDefinition funcObj("ShipGraph::ConvertToLocalPosition", typeid(Pointf (ShipGraph::*)(Pointf , bool )), ".4883ec184084f6660fd60424", argdata, 3, 2, &func);
}

FUNC_NAKED Pointf ShipGraph::ConvertToLocalPosition(Pointf world, bool past)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has world
			// rsi has past
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func861::func)
		 : "rdi", "xmm0", "rsi"
	);
}

namespace _func862
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipGraph::ComputeCenter", typeid(void (ShipGraph::*)()), ".41574989ff41564155415455534883ec18", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipGraph::ComputeCenter()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func862::func)
		 : "rdi"
	);
}

namespace _func863
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipGraph::ContainsPoint", typeid(bool (ShipGraph::*)(int , int )), ".8b4f6831c039f1", argdata, 3, 2, &func);
}

FUNC_NAKED bool ShipGraph::ContainsPoint(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func863::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func864
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("ShipGraph::GetSelectedRoom", typeid(int (ShipGraph::*)(int , int , bool )), ".41574531c04989ff41564531f6415541544189f45589d5530fb6d94883ec08", argdata, 4, 2, &func);
}

FUNC_NAKED int ShipGraph::GetSelectedRoom(int x, int y, bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
			// rcx has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func864::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func865
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipGraph::RoomCount", typeid(int (ShipGraph::*)()), ".488b4708482b0748c1f803", argdata, 1, 2, &func);
}

FUNC_NAKED int ShipGraph::RoomCount()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func865::func)
		 : "rdi"
	);
}

namespace _func866
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipGraph::GetRoomShape", typeid(Globals::Rect (ShipGraph::*)(int )), ".4883ec184c8b0e4c8b46084889f84d29c849c1f8034d85c0", argdata, 2, 10, &func);
}

FUNC_NAKED Globals::Rect ShipGraph::GetRoomShape(int room)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has room
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func866::func)
		 : "rdi", "rsi"
	);
}

namespace _func867
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipGraph::GetRoomOxygen", typeid(float (ShipGraph::*)(int )), ".85f60f57c0", argdata, 2, 2, &func);
}

FUNC_NAKED float ShipGraph::GetRoomOxygen(int room)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has room
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func867::func)
		 : "rdi", "rsi"
	);
}

namespace _func868
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipGraph::GetRoomBlackedOut", typeid(bool (ShipGraph::*)(int )), ".85f6b801000000", argdata, 2, 2, &func);
}

FUNC_NAKED bool ShipGraph::GetRoomBlackedOut(int room)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has room
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func868::func)
		 : "rdi", "rsi"
	);
}

namespace _func869
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipGraph::GetDoors", typeid(std::vector<Door*> (ShipGraph::*)(int )), ".41564531c04989f6415541544189d4554889fd53", argdata, 3, 2, &func);
}

FUNC_NAKED std::vector<Door*> ShipGraph::GetDoors(int roomId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has roomId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func869::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func870
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipGraph::IsRoomConnected", typeid(bool (ShipGraph::*)(int , int )), ".41564155415441bc010000005589d55389f34883ec20", argdata, 3, 2, &func);
}

FUNC_NAKED bool ShipGraph::IsRoomConnected(int room1, int room2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has room1
			// rdx has room2
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func870::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func871
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipGraph::GetShipInfo", typeid(ShipGraph *(*)(int )), ".5389fb4881ec90000000", argdata, 1, 2, &func);
}

FUNC_NAKED ShipGraph *ShipGraph::GetShipInfo(int shipId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has shipId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func871::func)
		 : "rdi"
	);
}

namespace _func872
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("ShipGraph::Dijkstra", typeid(Path (ShipGraph::*)(Point , Point , int )), ".41574989f741564155415455534889d348c1eb204881ecc8000000", argdata, 5, 2, &func);
}

FUNC_NAKED Path ShipGraph::Dijkstra(Point start, Point goal, int shipId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has start
			// rcx has goal
			// r8 has shipId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func872::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func873
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("ShipGraph::FindPath", typeid(Path (ShipGraph::*)(Point , Point , int )), ".415741564989f641554154554889d548c1ed20534889fb4883ec58", argdata, 5, 2, &func);
}

FUNC_NAKED Path ShipGraph::FindPath(Point p1, Point p2, int shipId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has p1
			// rcx has p2
			// r8 has shipId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func873::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func874
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("ShipGraph::GetClosestSlot", typeid(Slot (ShipGraph::*)(Point , int , bool )), ".41574889f04531ff48c1e820415641554189f54154440fb6e1554889fd534889c34881eca8000000", argdata, 4, 10, &func);
}

FUNC_NAKED Slot ShipGraph::GetClosestSlot(Point pos, int shipId, bool intruder)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
			// rdx has shipId
			// rcx has intruder
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func874::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func875
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipInfo::AddAugmentation", typeid(char (ShipInfo::*)(const std::string &)), "415731c041564155415455534889fb4883ec48837f6002", argdata, 2, 2, &func);
}

FUNC_NAKED char ShipInfo::AddAugmentation(const std::string &augment)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has augment
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func875::func)
		 : "rdi", "rsi"
	);
}

namespace _func876
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipInfo::HasAugmentation", typeid(bool (ShipInfo::*)(const std::string &)), "4157488d47084989f7415641554989fd4154554889c5534883ec28", argdata, 2, 2, &func);
}

FUNC_NAKED bool ShipInfo::HasAugmentation(const std::string &augment)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has augment
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func876::func)
		 : "rdi", "rsi"
	);
}

namespace _func877
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipInfo::GetAugmentationValue", typeid(float (ShipInfo::*)(const std::string &)), ".4157415641554989fd415455534883ec48488d7c2430", argdata, 2, 2, &func);
}

FUNC_NAKED float ShipInfo::GetAugmentationValue(const std::string &augment)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has augment
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func877::func)
		 : "rdi", "rsi"
	);
}

namespace _func878
{
	static void *func = 0;
	static short argdata[] = {0x106};
	static FunctionDefinition funcObj("ShipManager::GetShieldPower", typeid(ShieldPower (ShipManager::*)()), "488b87800000004885c0741c", argdata, 1, 10, &func);
}

FUNC_NAKED ShieldPower ShipManager::GetShieldPower()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func878::func)
		 : "rsi"
	);
}

namespace _func879
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::CanFitSystem", typeid(bool (ShipManager::*)(int )), ".415483fe054989fc5553", argdata, 2, 2, &func);
}

FUNC_NAKED bool ShipManager::CanFitSystem(int systemId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has systemId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func879::func)
		 : "rdi", "rsi"
	);
}

namespace _func880
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::CanFitSubsystem", typeid(bool (ShipManager::*)(int )), ".41544989fc5553488b5728488b47304829d0", argdata, 2, 2, &func);
}

FUNC_NAKED bool ShipManager::CanFitSubsystem(int systemId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has systemId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func880::func)
		 : "rdi", "rsi"
	);
}

namespace _func881
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipManager::DamageHull", typeid(int (ShipManager::*)(int , bool )), ".41544189d45589f553488b074889fb", argdata, 3, 2, &func);
}

FUNC_NAKED int ShipManager::DamageHull(int dmg, bool force)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has dmg
			// rdx has force
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func881::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func882
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipManager::ModifyScrapCount", typeid(void (ShipManager::*)(int , bool )), ".41545589f5534889fb4883ec3085f6", argdata, 3, 6, &func);
}

FUNC_NAKED void ShipManager::ModifyScrapCount(int scrap, bool income)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has scrap
			// rdx has income
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func882::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func883
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipManager::GetCrewmember", typeid(CrewMember *(ShipManager::*)(int , bool )), ".4156415541544989fc5589f553488bb7c8000000", argdata, 3, 2, &func);
}

FUNC_NAKED CrewMember *ShipManager::GetCrewmember(int slot, bool present)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has slot
			// rdx has present
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func883::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func884
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::FindCrew", typeid(CrewMember *(ShipManager::*)(const CrewBlueprint *)), ".415731c931d2", argdata, 2, 2, &func);
}

FUNC_NAKED CrewMember *ShipManager::FindCrew(const CrewBlueprint *bp)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has bp
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func884::func)
		 : "rdi", "rsi"
	);
}

namespace _func885
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::ResetScrapLevel", typeid(void (ShipManager::*)()), ".8b05????????c787700600001e00000083f801", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipManager::ResetScrapLevel()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func885::func)
		 : "rdi"
	);
}

namespace _func886
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::CountCrew", typeid(int (ShipManager::*)(char )), ".41574989ff41564155415455534883ec08488b8fc0000000", argdata, 2, 2, &func);
}

FUNC_NAKED int ShipManager::CountCrew(char boarders)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has boarders
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func886::func)
		 : "rdi", "rsi"
	);
}

namespace _func887
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipManager::CountCrewShipId", typeid(int (ShipManager::*)(int , int )), ".415741564989fe4155415455534883ec18488b87c8000000", argdata, 3, 2, &func);
}

FUNC_NAKED int ShipManager::CountCrewShipId(int roomId, int shipId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
			// rdx has shipId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func887::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func888
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::IsCrewOverFull", typeid(bool (ShipManager::*)()), ".538b470831f64889fb", argdata, 1, 2, &func);
}

FUNC_NAKED bool ShipManager::IsCrewOverFull()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func888::func)
		 : "rdi"
	);
}

namespace _func889
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::IsCrewFull", typeid(bool (ShipManager::*)()), ".538b470831f64889fb", argdata, 1, 2, &func);
}

FUNC_NAKED bool ShipManager::IsCrewFull()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func889::func)
		 : "rdi"
	);
}

namespace _func890
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::DoSensorsProvide", typeid(bool (ShipManager::*)(int )), ".4883ec08488b87580600004863401c83f8ff", argdata, 2, 2, &func);
}

FUNC_NAKED bool ShipManager::DoSensorsProvide(int vision)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has vision
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func890::func)
		 : "rdi", "rsi"
	);
}

namespace _func891
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::SetDestroyed", typeid(void (ShipManager::*)()), "!.5531c94889fd5331db4883ec08488b5728", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipManager::SetDestroyed()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func891::func)
		 : "rdi"
	);
}

namespace _func892
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::JumpLeave", typeid(void (ShipManager::*)()), ".415431c055534889fb4883ec2083af1006000001", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipManager::JumpLeave()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func892::func)
		 : "rdi"
	);
}

namespace _func893
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x7ff};
	static FunctionDefinition funcObj("ShipManager::DamageCrew", typeid(char (ShipManager::*)(CrewMember *, DamageParameter )), ".4156415541545553807c245e004889f3", argdata, 3, 2, &func);
}

FUNC_NAKED char ShipManager::DamageCrew(CrewMember *crew, DamageParameter dmg)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"subq $8, %%rsp\n\t"
		"pushq 56(%%rbp)\n\t"		// dmg
		"pushq 48(%%rbp)\n\t"		// dmg
		"pushq 40(%%rbp)\n\t"		// dmg
		"pushq 32(%%rbp)\n\t"		// dmg
		"pushq 24(%%rbp)\n\t"		// dmg
		"pushq 16(%%rbp)\n\t"		// dmg
		"pushq 8(%%rbp)\n\t"		// dmg
			// rdi has this
			// rsi has crew
		"call *%0\n\t"
		"addq $56, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func893::func)
		 : "rdi", "rsi"
	);
}

namespace _func894
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::JumpArrive", typeid(void (ShipManager::*)()), ".55534889fb488dbf200600004883ec28", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipManager::JumpArrive()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func894::func)
		 : "rdi"
	);
}

namespace _func895
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::InstantPowerShields", typeid(void (ShipManager::*)()), ".53488b87580600004889fb48630083f8ff", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipManager::InstantPowerShields()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func895::func)
		 : "rdi"
	);
}

namespace _func896
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::CheckSpreadDamage", typeid(void (ShipManager::*)()), ".41574989ff41564155415455534883ec28488b4f28", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipManager::CheckSpreadDamage()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func896::func)
		 : "rdi"
	);
}

namespace _func897
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::GetSystemPower", typeid(int (ShipManager::*)(int )), ".488b87580600004863f6486304b083f8ff740d", argdata, 2, 2, &func);
}

FUNC_NAKED int ShipManager::GetSystemPower(int systemId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has systemId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func897::func)
		 : "rdi", "rsi"
	);
}

namespace _func898
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::CheckVision", typeid(void (ShipManager::*)()), ".415741564155415455534889fb4883ec28488b8758060000", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipManager::CheckVision()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func898::func)
		 : "rdi"
	);
}

namespace _func899
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::ClearStatusAll", typeid(void (ShipManager::*)()), "!.5531c94889fd5331db4883ec08488b5728", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipManager::ClearStatusAll()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func899::func)
		 : "rdi"
	);
}

namespace _func900
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::ClearStatusSystem", typeid(void (ShipManager::*)(int )), ".83fe11743383feff7426", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipManager::ClearStatusSystem(int system)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has system
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func900::func)
		 : "rdi", "rsi"
	);
}

namespace _func901
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("ShipManager::DO_NOT_HOOK", typeid(void (*)()), ".83fe11743b83feff742e", argdata, 0, 4, &func);
}

FUNC_NAKED void ShipManager::DO_NOT_HOOK()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func901::func)
	);
}

namespace _func902
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipManager::SetSystemPowerLoss", typeid(void (ShipManager::*)(int , int )), ".83fe11743b83feff742e", argdata, 3, 6, &func);
}

FUNC_NAKED void ShipManager::SetSystemPowerLoss(int systemId, int powerLoss)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has systemId
			// rdx has powerLoss
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func902::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func903
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::ForceDecreaseSystemPower", typeid(bool (ShipManager::*)(int )), ".83feff743b488b87580600004863f6486304b083f8ff7428488b5728488b3cc24885ff741b488b07be01000000488b8008010000", argdata, 2, 2, &func);
}

FUNC_NAKED bool ShipManager::ForceDecreaseSystemPower(int sys)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has sys
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func903::func)
		 : "rdi", "rsi"
	);
}

namespace _func904
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::GetSystemInRoom", typeid(ShipSystem *(ShipManager::*)(int )), ".415531d24989fd41545589f55331db4883ec08488b4f28", argdata, 2, 2, &func);
}

FUNC_NAKED ShipSystem *ShipManager::GetSystemInRoom(int roomId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func904::func)
		 : "rdi", "rsi"
	);
}

namespace _func905
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::GetSystemRoom", typeid(int (ShipManager::*)(int )), ".83feff7433488b87580600004863f6", argdata, 2, 2, &func);
}

FUNC_NAKED int ShipManager::GetSystemRoom(int sysId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has sysId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func905::func)
		 : "rdi", "rsi"
	);
}

namespace _func906
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::GetSystem", typeid(ShipSystem *(ShipManager::*)(int )), ".83feff7423488b87580600004863f6", argdata, 2, 2, &func);
}

FUNC_NAKED ShipSystem *ShipManager::GetSystem(int systemId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has systemId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func906::func)
		 : "rdi", "rsi"
	);
}

namespace _func907
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::SystemFunctions", typeid(bool (ShipManager::*)(int )), ".488b87580600004863f6486304b083f8ff7415", argdata, 2, 2, &func);
}

FUNC_NAKED bool ShipManager::SystemFunctions(int systemId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has systemId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func907::func)
		 : "rdi", "rsi"
	);
}

namespace _func908
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::GetDodgeFactor", typeid(int (ShipManager::*)()), ".534889fb4883ec10488b9758060000", argdata, 1, 2, &func);
}

FUNC_NAKED int ShipManager::GetDodgeFactor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func908::func)
		 : "rdi"
	);
}

namespace _func909
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::GetDodged", typeid(bool (ShipManager::*)()), ".415455534889fb4883ec20807f1c00", argdata, 1, 2, &func);
}

FUNC_NAKED bool ShipManager::GetDodged()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func909::func)
		 : "rdi"
	);
}

namespace _func910
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::HasSystem", typeid(char (ShipManager::*)(int )), ".83fe11741b488b8758060000", argdata, 2, 2, &func);
}

FUNC_NAKED char ShipManager::HasSystem(int systemId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has systemId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func910::func)
		 : "rdi", "rsi"
	);
}

namespace _func911
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::GetSystemPowerMax", typeid(int (ShipManager::*)(int )), ".488b87580600004863f6486304b083f8ff740d", argdata, 2, 2, &func);
}

FUNC_NAKED int ShipManager::GetSystemPowerMax(int systemId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has systemId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func911::func)
		 : "rdi", "rsi"
	);
}

namespace _func912
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipManager::CanUpgrade", typeid(int (ShipManager::*)(int , int )), ".83fe117453", argdata, 3, 2, &func);
}

FUNC_NAKED int ShipManager::CanUpgrade(int systemId, int amount)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has systemId
			// rdx has amount
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func912::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func913
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipManager::CommandCrewMoveRoom", typeid(bool (ShipManager::*)(CrewMember *, int )), "!.4889f731c989d6baffffffff", argdata, 3, 2, &func);
}

FUNC_NAKED bool ShipManager::CommandCrewMoveRoom(CrewMember *crew, int roomId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has crew
			// rdx has roomId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func913::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func914
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("ShipManager::GetSelectedCrewPoint", typeid(CrewMember *(ShipManager::*)(int , int , bool )), ".415741564989fe41554189d5415455534883ec38", argdata, 4, 2, &func);
}

FUNC_NAKED CrewMember *ShipManager::GetSelectedCrewPoint(int x, int y, bool intruder)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
			// rcx has intruder
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func914::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func915
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("ShipManager::GetTooltip", typeid(std::string (ShipManager::*)(int , int )), ".415741564989fe41554189cd41544989f4", argdata, 4, 2, &func);
}

FUNC_NAKED std::string ShipManager::GetTooltip(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has x
			// rcx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func915::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func916
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::GetWeaponList", typeid(std::vector<ProjectileFactory*> (ShipManager::*)()), ".41545553488b86580600004889fb83780cff", argdata, 2, 2, &func);
}

FUNC_NAKED std::vector<ProjectileFactory*> ShipManager::GetWeaponList()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func916::func)
		 : "rdi", "rsi"
	);
}

namespace _func917
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::GetDroneCount", typeid(int (ShipManager::*)()), ".488b8758060000837810ff7413", argdata, 1, 2, &func);
}

FUNC_NAKED int ShipManager::GetDroneCount()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func917::func)
		 : "rdi"
	);
}

namespace _func918
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::ModifyDroneCount", typeid(void (ShipManager::*)(int )), ".488b8758060000837810ff7523", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipManager::ModifyDroneCount(int drones)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has drones
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func918::func)
		 : "rdi", "rsi"
	);
}

namespace _func919
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::GetOxygenPercentage", typeid(int (ShipManager::*)()), ".488b8758060000837808ff742b", argdata, 1, 2, &func);
}

FUNC_NAKED int ShipManager::GetOxygenPercentage()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func919::func)
		 : "rdi"
	);
}

namespace _func920
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::RemoveItem", typeid(void (ShipManager::*)(const std::string &)), ".41574156415541544989f455534889fb4883ec48", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipManager::RemoveItem(const std::string &name)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has name
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func920::func)
		 : "rdi", "rsi"
	);
}

namespace _func921
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipManager::AddWeapon", typeid(int (ShipManager::*)(const WeaponBlueprint *, int )), ".488b875806000083780cff7413", argdata, 3, 2, &func);
}

FUNC_NAKED int ShipManager::AddWeapon(const WeaponBlueprint *bp, int slot)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has bp
			// rdx has slot
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func921::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func922
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::ModifyMissileCount", typeid(void (ShipManager::*)(int )), ".488b875806000083780cff7523", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipManager::ModifyMissileCount(int missiles)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has missiles
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func922::func)
		 : "rdi", "rsi"
	);
}

namespace _func923
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::GetDroneList", typeid(std::vector<Drone*> (ShipManager::*)()), ".41545553488b86580600004889fb837810ff", argdata, 2, 2, &func);
}

FUNC_NAKED std::vector<Drone*> ShipManager::GetDroneList()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func923::func)
		 : "rdi", "rsi"
	);
}

namespace _func924
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::IsSystemHacked", typeid(int (ShipManager::*)(int )), ".83fe11741b488b87580600004863d6", argdata, 2, 2, &func);
}

FUNC_NAKED int ShipManager::IsSystemHacked(int systemId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has systemId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func924::func)
		 : "rdi", "rsi"
	);
}

namespace _func925
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::ExportBattleState", typeid(void (ShipManager::*)(int )), ".4157415641554154554889fd5389f34883ec28", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipManager::ExportBattleState(int file)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has file
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func925::func)
		 : "rdi", "rsi"
	);
}

namespace _func926
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::StartFire", typeid(void (ShipManager::*)(int )), "!.4881c7d8000000", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipManager::StartFire(int roomId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func926::func)
		 : "rdi", "rsi"
	);
}

namespace _func927
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::GetFireCount", typeid(int (ShipManager::*)(int )), "!.4881c7d8000000", argdata, 2, 2, &func);
}

FUNC_NAKED int ShipManager::GetFireCount(int roomId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has roomId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func927::func)
		 : "rdi", "rsi"
	);
}

namespace _func928
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("ShipManager::TeleportCrew", typeid(std::vector<CrewMember*> (ShipManager::*)(int , bool )), ".4157415641554989fd41544989f455534883ec18", argdata, 4, 2, &func);
}

FUNC_NAKED std::vector<CrewMember*> ShipManager::TeleportCrew(int roomId, bool intruders)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has roomId
			// rcx has intruders
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func928::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func929
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x109};
	static FunctionDefinition funcObj("ShipManager::AddCrewMemberFromBlueprint", typeid(CrewMember *(ShipManager::*)(CrewBlueprint *, int , bool , int , bool )), ".41574989ff415641554589cd4154554889f5", argdata, 6, 2, &func);
}

FUNC_NAKED CrewMember *ShipManager::AddCrewMemberFromBlueprint(CrewBlueprint *bp, int slot, bool init, int roomId, bool intruder)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has bp
			// rdx has slot
			// rcx has init
			// r8 has roomId
			// r9 has intruder
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func929::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "r9"
	);
}

namespace _func930
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x7ff};
	static FunctionDefinition funcObj("ShipManager::DamageSystem", typeid(void (ShipManager::*)(int , DamageParameter )), ".41574989ff4156415541545589f5534883ec48", argdata, 3, 6, &func);
}

FUNC_NAKED void ShipManager::DamageSystem(int systemId, DamageParameter damage)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"subq $8, %%rsp\n\t"
		"pushq 56(%%rbp)\n\t"		// damage
		"pushq 48(%%rbp)\n\t"		// damage
		"pushq 40(%%rbp)\n\t"		// damage
		"pushq 32(%%rbp)\n\t"		// damage
		"pushq 24(%%rbp)\n\t"		// damage
		"pushq 16(%%rbp)\n\t"		// damage
		"pushq 8(%%rbp)\n\t"		// damage
			// rdi has this
			// rsi has systemId
		"call *%0\n\t"
		"addq $56, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func930::func)
		 : "rdi", "rsi"
	);
}

namespace _func931
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("ShipManager::CheckCrystalAugment", typeid(void (ShipManager::*)(Pointf )), ".4157be????????4156415541544989fc55534883ec68", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipManager::CheckCrystalAugment(Pointf pos)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has pos
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func931::func)
		 : "rdi", "xmm0"
	);
}

namespace _func932
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::PrepareSuperBarrage", typeid(void (ShipManager::*)()), ".415741564155415455534889fb4881ec980000004883bf0006000000", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipManager::PrepareSuperBarrage()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func932::func)
		 : "rdi"
	);
}

namespace _func933
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::RestoreCrewPositions", typeid(bool (ShipManager::*)()), ".415531d2bf????????415455534883ec684889e6", argdata, 1, 2, &func);
}

FUNC_NAKED bool ShipManager::RestoreCrewPositions()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func933::func)
		 : "rdi"
	);
}

namespace _func934
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::UpdateEnvironment", typeid(void (ShipManager::*)()), ".4157488d87d800000041564989fe4889c74155415455534883ec78", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipManager::UpdateEnvironment()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func934::func)
		 : "rdi"
	);
}

namespace _func935
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("ShipManager::SelectRandomCrew", typeid(CrewBlueprint (ShipManager::*)(int , const std::string &)), ".41574156415541544989fc554889cd534883ec68", argdata, 4, 2, &func);
}

FUNC_NAKED CrewBlueprint ShipManager::SelectRandomCrew(int seed, const std::string &racePref)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has seed
			// rcx has racePref
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func935::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func936
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x10a, 0x10b, 0x7ff, 0x102};
	static FunctionDefinition funcObj("ShipManager::CollisionMoving", typeid(CollisionResponse (ShipManager::*)(Pointf , Pointf , DamageParameter , bool )), ".41574989ff488d7f044156415541544189d4554889f5534881ec08010000", argdata, 6, 2, &func);
}

FUNC_NAKED CollisionResponse ShipManager::CollisionMoving(Pointf start, Pointf finish, DamageParameter damage, bool raytrace)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"subq $8, %%rsp\n\t"
		"pushq 56(%%rbp)\n\t"		// damage
		"pushq 48(%%rbp)\n\t"		// damage
		"pushq 40(%%rbp)\n\t"		// damage
		"pushq 32(%%rbp)\n\t"		// damage
		"pushq 24(%%rbp)\n\t"		// damage
		"pushq 16(%%rbp)\n\t"		// damage
		"pushq 8(%%rbp)\n\t"		// damage
			// rdi has implicit_output
			// rsi has this
			// xmm0 has start
			// xmm1 has finish
			// rdx has raytrace
		"call *%0\n\t"
		"addq $56, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func936::func)
		 : "rdi", "rsi", "xmm0", "xmm1", "rdx"
	);
}

namespace _func937
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x7ff, 0x106};
	static FunctionDefinition funcObj("ShipManager::DamageArea", typeid(bool (ShipManager::*)(Pointf , DamageParameter , char )), ".4157b901000000415641554189f5415455534889fb4881ecc8000000", argdata, 4, 2, &func);
}

FUNC_NAKED bool ShipManager::DamageArea(Pointf location, DamageParameter dmg, char forceHit)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"subq $8, %%rsp\n\t"
		"pushq 56(%%rbp)\n\t"		// dmg
		"pushq 48(%%rbp)\n\t"		// dmg
		"pushq 40(%%rbp)\n\t"		// dmg
		"pushq 32(%%rbp)\n\t"		// dmg
		"pushq 24(%%rbp)\n\t"		// dmg
		"pushq 16(%%rbp)\n\t"		// dmg
		"pushq 8(%%rbp)\n\t"		// dmg
			// rdi has this
			// xmm0 has location
			// rsi has forceHit
		"call *%0\n\t"
		"addq $56, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func937::func)
		 : "rdi", "xmm0", "rsi"
	);
}

namespace _func938
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::PrepareSuperDrones", typeid(void (ShipManager::*)()), ".415741564155415455534889fb4883ec58488b87b8090000", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipManager::PrepareSuperDrones()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func938::func)
		 : "rdi"
	);
}

namespace _func939
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::RenderChargeBars", typeid(void (ShipManager::*)()), ".4155415455534889fb4883ec388b5708", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipManager::RenderChargeBars()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func939::func)
		 : "rdi"
	);
}

namespace _func940
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::RenderWeapons", typeid(void (ShipManager::*)()), ".41574156415541544c8da718010000554889fd4c89e7534883ec68", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipManager::RenderWeapons()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func940::func)
		 : "rdi"
	);
}

namespace _func941
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipManager::OnRender", typeid(void (ShipManager::*)(char , char )), ".4157415641554989fd4154555389f34881ec98000000", argdata, 3, 6, &func);
}

FUNC_NAKED void ShipManager::OnRender(char showInterior, char doorControlMode)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has showInterior
			// rdx has doorControlMode
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func941::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func942
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::CreateCrewDrone", typeid(CrewDrone *(ShipManager::*)(const DroneBlueprint *)), ".55534889fb4883ec188b4670", argdata, 2, 2, &func);
}

FUNC_NAKED CrewDrone *ShipManager::CreateCrewDrone(const DroneBlueprint *bp)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has bp
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func942::func)
		 : "rdi", "rsi"
	);
}

namespace _func943
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::CreateSpaceDrone", typeid(SpaceDrone *(ShipManager::*)(const DroneBlueprint *)), ".41554154554889f5534883ec38837e7007", argdata, 2, 2, &func);
}

FUNC_NAKED SpaceDrone *ShipManager::CreateSpaceDrone(const DroneBlueprint *bp)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has bp
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func943::func)
		 : "rdi", "rsi"
	);
}

namespace _func944
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipManager::AddDrone", typeid(Drone *(ShipManager::*)(const DroneBlueprint *, int )), ".4155415455534889fb4883ec18488b8758060000", argdata, 3, 2, &func);
}

FUNC_NAKED Drone *ShipManager::AddDrone(const DroneBlueprint *bp, int slot)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has bp
			// rdx has slot
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func944::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func945
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::AddEquipmentFromList", typeid(void (ShipManager::*)(std::vector<std::string> *)), ".415641554154554889f5534883ec30", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipManager::AddEquipmentFromList(std::vector<std::string> *equipmentList)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has equipmentList
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func945::func)
		 : "rdi", "rsi"
	);
}

namespace _func946
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::AddSystem", typeid(int (ShipManager::*)(int )), ".415741564155415455534889fb4881ece8000000", argdata, 2, 2, &func);
}

FUNC_NAKED int ShipManager::AddSystem(int systemId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has systemId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func946::func)
		 : "rdi", "rsi"
	);
}

namespace _func947
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::CreateSystems", typeid(int (ShipManager::*)()), ".4154488d8fb007000055534889fb4883ec20", argdata, 1, 2, &func);
}

FUNC_NAKED int ShipManager::CreateSystems()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func947::func)
		 : "rdi"
	);
}

namespace _func948
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b, 0x7ff};
	static FunctionDefinition funcObj("ShipManager::DamageBeam", typeid(bool (ShipManager::*)(Pointf , Pointf , DamageParameter )), ".4157415641554154554889fd534881ece8000000", argdata, 4, 2, &func);
}

FUNC_NAKED bool ShipManager::DamageBeam(Pointf location1, Pointf location2, DamageParameter dmg)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"subq $8, %%rsp\n\t"
		"pushq 56(%%rbp)\n\t"		// dmg
		"pushq 48(%%rbp)\n\t"		// dmg
		"pushq 40(%%rbp)\n\t"		// dmg
		"pushq 32(%%rbp)\n\t"		// dmg
		"pushq 24(%%rbp)\n\t"		// dmg
		"pushq 16(%%rbp)\n\t"		// dmg
		"pushq 8(%%rbp)\n\t"		// dmg
			// rdi has this
			// xmm0 has location1
			// xmm1 has location2
		"call *%0\n\t"
		"addq $56, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func948::func)
		 : "rdi", "xmm0", "xmm1"
	);
}

namespace _func949
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::UpdateCrewMembers", typeid(void (ShipManager::*)()), ".415731c94156415541544989fc555331db4881ec38010000", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipManager::UpdateCrewMembers()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func949::func)
		 : "rdi"
	);
}

namespace _func950
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::ImportBattleState", typeid(void (ShipManager::*)(int )), "!.4157415641554154554889fd5389f34883ec18", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipManager::ImportBattleState(int file)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has file
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func950::func)
		 : "rdi", "rsi"
	);
}

namespace _func951
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::OnLoop", typeid(void (ShipManager::*)()), ".41574989ffbe????????41564155415455534881ec48010000", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipManager::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func951::func)
		 : "rdi"
	);
}

namespace _func952
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::ExportShip", typeid(void (ShipManager::*)(int )), ".41574989ff415641554154555389f3488db75807000089df4881ec78010000", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipManager::ExportShip(int file)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has file
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func952::func)
		 : "rdi", "rsi"
	);
}

namespace _func953
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x109, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddCrewMemberFromString", typeid(CrewMember *(ShipManager::*)(const std::string &, const std::string &, char , int , char , char )), ".415741564589c641554154554889fd534881ec58020000", argdata, 7, 2, &func);
}

FUNC_NAKED CrewMember *ShipManager::AddCrewMemberFromString(const std::string &name, const std::string &race, char intruder, int roomId, char init, char male)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"subq $8, %%rsp\n\t"
		"pushq 8(%%rbp)\n\t"		// male
			// rdi has this
			// rsi has name
			// rdx has race
			// rcx has intruder
			// r8 has roomId
			// r9 has init
		"call *%0\n\t"
		"addq $8, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func953::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "r9"
	);
}

namespace _func954
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::AddInitialCrew", typeid(void (ShipManager::*)(std::vector<CrewBlueprint> &)), ".41574156415541544989f4be????????554889fd534881ec88010000", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipManager::AddInitialCrew(std::vector<CrewBlueprint> &blueprints)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has blueprints
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func954::func)
		 : "rdi", "rsi"
	);
}

namespace _func955
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::Restart", typeid(void (ShipManager::*)()), ".415641554154554889fd534883ec208b4708", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipManager::Restart()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func955::func)
		 : "rdi"
	);
}

namespace _func956
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipManager::SaveToBlueprint", typeid(ShipBlueprint (ShipManager::*)(bool )), ".4157415641554189d54154554889f5534889fb4883ec48", argdata, 3, 2, &func);
}

FUNC_NAKED ShipBlueprint ShipManager::SaveToBlueprint(bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func956::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func957
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipManager::OnInit", typeid(int (ShipManager::*)(ShipBlueprint *, int )), ".4156415541544c8da7800600005589d5534889fb4c89e74883ec50", argdata, 3, 2, &func);
}

FUNC_NAKED int ShipManager::OnInit(ShipBlueprint *bp, int shipLevel)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has bp
			// rdx has shipLevel
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func957::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func958
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::ImportShip", typeid(void (ShipManager::*)(int )), ".415741564189f64155415455534889fb4c8dab800600004c8dbb880700004881ec18040000", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipManager::ImportShip(int file)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has file
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func958::func)
		 : "rdi", "rsi"
	);
}

namespace _func959
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipManager::constructor", typeid(int (ShipManager::*)(int )), ".415741564989fe488dbfd800000041554154555389f34881ec98000000", argdata, 2, 2, &func);
}

FUNC_NAKED int ShipManager::constructor(int shipId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shipId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func959::func)
		 : "rdi", "rsi"
	);
}

namespace _func960
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::destructor", typeid(void (ShipManager::*)()), ".415641554989fd4154555348c707", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipManager::destructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func960::func)
		 : "rdi"
	);
}

namespace _func961
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipManager::destructor2", typeid(void (ShipManager::*)()), "!.534889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipManager::destructor2()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func961::func)
		 : "rdi"
	);
}

namespace _func962
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipObject::GetAugmentationCount", typeid(int (ShipObject::*)()), "8b570831c0488b0d????????85d2", argdata, 1, 2, &func);
}

FUNC_NAKED int ShipObject::GetAugmentationCount()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func962::func)
		 : "rdi"
	);
}

namespace _func963
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipObject::ClearShipInfo", typeid(void (ShipObject::*)()), ".538b570831c085d20f94c0488d14004801c2488d1490", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipObject::ClearShipInfo()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func963::func)
		 : "rdi"
	);
}

namespace _func964
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipObject::GetAugmentationList", typeid(std::vector<std::string> (ShipObject::*)()), ".415631c04155415455538b56084889fb85d20f94c0488d14004801c2488d1490", argdata, 2, 2, &func);
}

FUNC_NAKED std::vector<std::string> ShipObject::GetAugmentationList()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func964::func)
		 : "rdi", "rsi"
	);
}

namespace _func965
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipObject::HasAugmentation", typeid(int (ShipObject::*)(const std::string &)), ".415741564155415455534889fb4883ec38488d7c2420", argdata, 2, 2, &func);
}

FUNC_NAKED int ShipObject::HasAugmentation(const std::string &augment)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has augment
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func965::func)
		 : "rdi", "rsi"
	);
}

namespace _func966
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipObject::HasEquipment", typeid(int (ShipObject::*)(const std::string &)), ".415741564155415455534889f34883ec68", argdata, 2, 2, &func);
}

FUNC_NAKED int ShipObject::HasEquipment(const std::string &equip)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has equip
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func966::func)
		 : "rdi", "rsi"
	);
}

namespace _func967
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipObject::GetAugmentationValue", typeid(float (ShipObject::*)(const std::string &)), ".415741564155415455534889fb4883ec58488d7c2430", argdata, 2, 2, &func);
}

FUNC_NAKED float ShipObject::GetAugmentationValue(const std::string &augment)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has augment
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func967::func)
		 : "rdi", "rsi"
	);
}

namespace _func968
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipObject::AddAugmentation", typeid(bool (ShipObject::*)(const std::string &)), ".415741564155415455534889fb4883ec58488d7c2430", argdata, 2, 2, &func);
}

FUNC_NAKED bool ShipObject::AddAugmentation(const std::string &augment)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has augment
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func968::func)
		 : "rdi", "rsi"
	);
}

namespace _func969
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipObject::RemoveAugmentation", typeid(void (ShipObject::*)(const std::string &)), ".415741564155415455534889fb4883ec48488d7c2420", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipObject::RemoveAugmentation(const std::string &augment)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has augment
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func969::func)
		 : "rdi", "rsi"
	);
}

ShipInfo **Global_ShipObject_ShipInfoList;

namespace _var970
{
	static VariableDefinition varObj("Global_ShipObject_ShipInfoList", "!8b570831c0488b0d(???????\?)85d20f94c0488d14004801c2", &Global_ShipObject_ShipInfoList);
}

namespace _func971
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipSelect::constructor", typeid(void (ShipSelect::*)()), "53ba6e0000004889fbbe700000004883ec10", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipSelect::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func971::func)
		 : "rdi"
	);
}

namespace _func972
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipSelect::ClearShipButtons", typeid(void (ShipSelect::*)()), ".554889fd534883ec08488b4f30488b57284889c84829d048c1f80385c0", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipSelect::ClearShipButtons()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func972::func)
		 : "rdi"
	);
}

namespace _func973
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipSelect::OnLoop", typeid(void (ShipSelect::*)()), ".415741564155415455534889fb4881ec0801000080bf5005000000", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipSelect::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func973::func)
		 : "rdi"
	);
}

namespace _func974
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipSelect::KeyDown", typeid(int (ShipSelect::*)(SDLKey )), "!.4881c748050000", argdata, 2, 2, &func);
}

FUNC_NAKED int ShipSelect::KeyDown(SDLKey key)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has key
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func974::func)
		 : "rdi", "rsi"
	);
}

namespace _func975
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipSelect::MouseClick", typeid(void (ShipSelect::*)()), "!.5380bf50050000004889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipSelect::MouseClick()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func975::func)
		 : "rdi"
	);
}

namespace _func976
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipSelect::Close", typeid(void (ShipSelect::*)()), "!.c64758004881c748050000", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipSelect::Close()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func976::func)
		 : "rdi"
	);
}

namespace _func977
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipSelect::GetSelectedShip", typeid(int (ShipSelect::*)()), "!.8b475cc3", argdata, 1, 2, &func);
}

FUNC_NAKED int ShipSelect::GetSelectedShip()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func977::func)
		 : "rdi"
	);
}

namespace _func978
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipSelect::SelectShip", typeid(void (ShipSelect::*)(int )), ".415789f241564989fe4155415455534881eca8020000", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipSelect::SelectShip(int shipType)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shipType
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func978::func)
		 : "rdi", "rsi"
	);
}

namespace _func979
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipSelect::PreSelectShip", typeid(void (ShipSelect::*)(int )), "!.85f6534889fb", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipSelect::PreSelectShip(int shipType)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shipType
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func979::func)
		 : "rdi", "rsi"
	);
}

namespace _func980
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipSelect::MouseMove", typeid(void (ShipSelect::*)(int , int )), ".41574189f74156415541544189d4554889fd534881ec18010000", argdata, 3, 6, &func);
}

FUNC_NAKED void ShipSelect::MouseMove(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func980::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func981
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipSelect::Open", typeid(void (ShipSelect::*)(int , int )), ".41574989ff41564155415455534881ecc8010000", argdata, 3, 6, &func);
}

FUNC_NAKED void ShipSelect::Open(int currentId, int currentType)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has currentId
			// rdx has currentType
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func981::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func982
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipSelect::OnRender", typeid(void (ShipSelect::*)()), ".41564155415455534889fb4883ec5080bf5005000000", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipSelect::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func982::func)
		 : "rdi"
	);
}

namespace _func983
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipStatus::RenderHealth", typeid(void (ShipStatus::*)(bool )), "4155415455534881ec880000004084f6", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipStatus::RenderHealth(bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func983::func)
		 : "rdi", "rsi"
	);
}

namespace _func984
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x10a};
	static FunctionDefinition funcObj("ShipStatus::OnInit", typeid(void (ShipStatus::*)(Point , float )), "415741564155415455534889fb4881ece8010000f30f114708", argdata, 3, 6, &func);
}

FUNC_NAKED void ShipStatus::OnInit(Point unk, float unk2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk
			// xmm0 has unk2
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func984::func)
		 : "rdi", "rsi", "xmm0"
	);
}

namespace _func985
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipStatus::RenderEvadeOxygen", typeid(void (ShipStatus::*)(bool )), "415741564155415455534889fb4881ec580300004084f6", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipStatus::RenderEvadeOxygen(bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func985::func)
		 : "rdi", "rsi"
	);
}

namespace _func986
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipStatus::OnRender", typeid(void (ShipStatus::*)()), "4155415455534889fb4881ec88000000e8????????f30f2a03", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipStatus::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func986::func)
		 : "rdi"
	);
}

namespace _func987
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipStatus::RenderShields", typeid(void (ShipStatus::*)(bool )), "41574156415541544989fc55534883ec18488b7f10", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipStatus::RenderShields(bool renderText)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has renderText
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func987::func)
		 : "rdi", "rsi"
	);
}

namespace _func988
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipStatus::OnLoop", typeid(void (ShipStatus::*)()), "415541544531e4554889fd5331db4883ec48", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipStatus::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func988::func)
		 : "rdi"
	);
}

namespace _func989
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipSystem::ForceDecreasePower", typeid(bool (ShipSystem::*)(int )), "415641554154554889fd5380bf8c01000000", argdata, 2, 2, &func);
}

FUNC_NAKED bool ShipSystem::ForceDecreasePower(int powerLoss)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has powerLoss
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func989::func)
		 : "rdi", "rsi"
	);
}

namespace _func990
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipSystem::AddDamage", typeid(void (ShipSystem::*)(int )), ".8b87740100008b977801000029f08b775439d00f4fc231c985c00f48c1", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipSystem::AddDamage(int amount)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has amount
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func990::func)
		 : "rdi", "rsi"
	);
}

namespace _func991
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipSystem::Ioned", typeid(bool (ShipSystem::*)(int )), ".8b879c01000083f8ff0f94c285c00f9fc008d0", argdata, 2, 2, &func);
}

FUNC_NAKED bool ShipSystem::Ioned(int num)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has num
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func991::func)
		 : "rdi", "rsi"
	);
}

namespace _func992
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipSystem::destructor", typeid(void (ShipSystem::*)()), ".415441bc05000000554889fd534889eb4883ec10", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipSystem::destructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func992::func)
		 : "rdi"
	);
}

namespace _func993
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipSystem::SaveState", typeid(void (ShipSystem::*)(int )), "!.554889fd5389f34883ec088bb790010000", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipSystem::SaveState(int file)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has file
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func993::func)
		 : "rdi", "rsi"
	);
}

namespace _func994
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipSystem::LoadState", typeid(void (ShipSystem::*)(int )), ".5589f5534889fb89f74883ec08", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipSystem::LoadState(int file)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has file
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func994::func)
		 : "rdi", "rsi"
	);
}

namespace _func995
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipSystem::GetEffectivePower", typeid(int (ShipSystem::*)()), ".8b474831d285c0", argdata, 1, 2, &func);
}

FUNC_NAKED int ShipSystem::GetEffectivePower()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func995::func)
		 : "rdi"
	);
}

namespace _func996
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipSystem::SetBonusPower", typeid(void (ShipSystem::*)(int , int )), ".4154555380bf8c010000004889fb", argdata, 3, 6, &func);
}

FUNC_NAKED void ShipSystem::SetBonusPower(int amount, int permanentPower)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has amount
			// rdx has permanentPower
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func996::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func997
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipSystem::GetPowerCap", typeid(int (ShipSystem::*)()), ".8b979001000031c083fa07", argdata, 1, 2, &func);
}

FUNC_NAKED int ShipSystem::GetPowerCap()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func997::func)
		 : "rdi"
	);
}

namespace _func998
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipSystem::IsMannedBoost", typeid(int (ShipSystem::*)()), ".8b474885c07e21", argdata, 1, 2, &func);
}

FUNC_NAKED int ShipSystem::IsMannedBoost()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func998::func)
		 : "rdi"
	);
}

namespace _func999
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipSystem::GetLocked", typeid(bool (ShipSystem::*)()), ".8b879c01000083f8ff", argdata, 1, 2, &func);
}

FUNC_NAKED bool ShipSystem::GetLocked()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func999::func)
		 : "rdi"
	);
}

namespace _func1000
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipSystem::StopHacking", typeid(void (ShipSystem::*)()), "!.488b07c6872402000000", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipSystem::StopHacking()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1000::func)
		 : "rdi"
	);
}

namespace _func1001
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipSystem::UpgradeSystem", typeid(bool (ShipSystem::*)(int )), ".5589f5534889fb4883ec08488b07", argdata, 2, 2, &func);
}

FUNC_NAKED bool ShipSystem::UpgradeSystem(int amount)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has amount
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1001::func)
		 : "rdi", "rsi"
	);
}

namespace _func1002
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipSystem::GetMaxPower", typeid(int (ShipSystem::*)()), ".8b4f548b877401000031d2", argdata, 1, 2, &func);
}

FUNC_NAKED int ShipSystem::GetMaxPower()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1002::func)
		 : "rdi"
	);
}

namespace _func1003
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipSystem::CheckMaxPower", typeid(void (ShipSystem::*)()), ".4155415455534889fb4883ec0880bf8c01000000", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipSystem::CheckMaxPower()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1003::func)
		 : "rdi"
	);
}

namespace _func1004
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipSystem::IsSubsystem", typeid(bool (*)(int )), ".83ff0c741383ff06", argdata, 1, 2, &func);
}

FUNC_NAKED bool ShipSystem::IsSubsystem(int systemType)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has systemType
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1004::func)
		 : "rdi"
	);
}

namespace _func1005
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x109, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::RenderPowerBoxes", typeid(void (ShipSystem::*)(int , int , int , int , int , int , bool )), ".41574989ff41564189ce41554189f541544589c4554489cd5389d34881ec88000000", argdata, 8, 6, &func);
}

FUNC_NAKED void ShipSystem::RenderPowerBoxes(int x, int y, int width, int height, int gap, int heightMod, bool flash)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// flash
		"pushq 8(%%rbp)\n\t"		// heightMod
			// rdi has this
			// rsi has x
			// rdx has y
			// rcx has width
			// r8 has height
			// r9 has gap
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1005::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "r9"
	);
}

namespace _func1006
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("ShipSystem::IncreasePower", typeid(bool (ShipSystem::*)(int , bool )), ".534889fb4883ec108b879c010000", argdata, 3, 2, &func);
}

FUNC_NAKED bool ShipSystem::IncreasePower(int amount, bool force)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has amount
			// rdx has force
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1006::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1007
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipSystem::DecreasePower", typeid(bool (ShipSystem::*)(bool )), ".55534889fb4883ec080fb6878c010000", argdata, 2, 2, &func);
}

FUNC_NAKED bool ShipSystem::DecreasePower(bool force)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has force
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1007::func)
		 : "rdi", "rsi"
	);
}

namespace _func1008
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("ShipSystem::DamageOverTime", typeid(bool (ShipSystem::*)(float )), ".55534889fb", argdata, 2, 2, &func);
}

FUNC_NAKED bool ShipSystem::DamageOverTime(float unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1008::func)
		 : "rdi", "xmm0"
	);
}

namespace _func1009
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipSystem::CheckForRepower", typeid(void (ShipSystem::*)()), ".415541544531e455534889fb4883ec08", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipSystem::CheckForRepower()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1009::func)
		 : "rdi"
	);
}

namespace _func1010
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipSystem::LockSystem", typeid(void (ShipSystem::*)(int )), ".83fe00751b8b879c010000", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipSystem::LockSystem(int lock)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has lock
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1010::func)
		 : "rdi", "rsi"
	);
}

namespace _func1011
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipSystem::ClearStatus", typeid(void (ShipSystem::*)()), ".83bf9001000007", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipSystem::ClearStatus()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1011::func)
		 : "rdi"
	);
}

namespace _func1012
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipSystem::SetPowerCap", typeid(void (ShipSystem::*)(int )), "!.53488b074889fb89b790010000", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipSystem::SetPowerCap(int cap)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has cap
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1012::func)
		 : "rdi", "rsi"
	);
}

namespace _func1013
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipSystem::SetPowerLoss", typeid(int (ShipSystem::*)(int )), "!.53488b074889fb89b794010000", argdata, 2, 2, &func);
}

FUNC_NAKED int ShipSystem::SetPowerLoss(int power)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has power
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1013::func)
		 : "rdi", "rsi"
	);
}

namespace _func1014
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x106};
	static FunctionDefinition funcObj("ShipSystem::PartialRepair", typeid(bool (ShipSystem::*)(float , bool )), ".5531c0534889fb4883ec18", argdata, 3, 2, &func);
}

FUNC_NAKED bool ShipSystem::PartialRepair(float speed, bool autoRepair)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has speed
			// rsi has autoRepair
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1014::func)
		 : "rdi", "xmm0", "rsi"
	);
}

namespace _func1015
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipSystem::AddLock", typeid(void (ShipSystem::*)(int )), ".8b879c01000083f8ff", argdata, 2, 6, &func);
}

FUNC_NAKED void ShipSystem::AddLock(int lock)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has lock
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1015::func)
		 : "rdi", "rsi"
	);
}

namespace _func1016
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipSystem::OnLoop", typeid(void (ShipSystem::*)()), ".415455538b879c0100004889fb85c0", argdata, 1, 6, &func);
}

FUNC_NAKED void ShipSystem::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1016::func)
		 : "rdi"
	);
}

namespace _func1017
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("ShipSystem::NameToSystemId", typeid(int (*)(const std::string &)), ".53be????????4889fb", argdata, 1, 2, &func);
}

FUNC_NAKED int ShipSystem::NameToSystemId(const std::string &name)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has name
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1017::func)
		 : "rdi"
	);
}

namespace _func1018
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("ShipSystem::SystemIdToName", typeid(std::string (*)(int )), ".534889fb4883ec1083fe11488d54240f", argdata, 2, 2, &func);
}

FUNC_NAKED std::string ShipSystem::SystemIdToName(int systemId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has systemId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1018::func)
		 : "rdi", "rsi"
	);
}

namespace _func1019
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("ShipSystem::GetLevelDescription", typeid(std::string (*)(int , int , bool )), ".4156415541544189d455534889fb4881ec10020000", argdata, 4, 2, &func);
}

FUNC_NAKED std::string ShipSystem::GetLevelDescription(int systemId, int level, bool tooltip)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has systemId
			// rdx has level
			// rcx has tooltip
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1019::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func1020
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("ShipSystem::constructor", typeid(void (ShipSystem::*)(int , int , int , int )), ".41574989ff41564189f641554589c54154555389d389ca4881ecd8010000", argdata, 5, 6, &func);
}

FUNC_NAKED void ShipSystem::constructor(int systemId, int roomId, int shipId, int startingPower)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has systemId
			// rdx has roomId
			// rcx has shipId
			// r8 has startingPower
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1020::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func1021
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("ShipSystem::PartialDamage", typeid(bool (ShipSystem::*)(float )), "55534889fbbf????????4883ec18f30f1144240c", argdata, 2, 2, &func);
}

FUNC_NAKED bool ShipSystem::PartialDamage(float amount)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has amount
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1021::func)
		 : "rdi", "xmm0"
	);
}

namespace _func1022
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("SoundControl::StopPlaylist", typeid(void (SoundControl::*)(int )), "415541544989fc55534883ec38803f000f84c8000000", argdata, 2, 6, &func);
}

FUNC_NAKED void SoundControl::StopPlaylist(int fadeOut)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has fadeOut
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1022::func)
		 : "rdi", "rsi"
	);
}

namespace _func1023
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("SoundControl::StartPlaylist", typeid(void (SoundControl::*)(std::vector<std::string> &)), ".41574156415541544989fc55534883ec58803f004889742420", argdata, 2, 6, &func);
}

FUNC_NAKED void SoundControl::StartPlaylist(std::vector<std::string> &playlist)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has playlist
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1023::func)
		 : "rdi", "rsi"
	);
}

namespace _func1024
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x10a, 0x102};
	static FunctionDefinition funcObj("SoundControl::PlaySoundMix", typeid(int (SoundControl::*)(const std::string &, float , char )), ".415731c04156415541544989fc55534883ec48803f00", argdata, 4, 2, &func);
}

FUNC_NAKED int SoundControl::PlaySoundMix(const std::string &soundName, float volume, char loop)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has soundName
			// xmm0 has volume
			// rdx has loop
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1024::func)
		 : "rdi", "rsi", "xmm0", "rdx"
	);
}

SoundControl *Global_SoundControl_Sounds;

namespace _var1025
{
	static VariableDefinition varObj("Global_SoundControl_Sounds", "!488b8360020000488378e80074cf4881c36002000031d2bf(???????\?)", &Global_SoundControl_Sounds);
}

namespace _func1026
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("SpaceDrone::SetMovementTarget", typeid(void (SpaceDrone::*)(Targetable *)), "554889f5534889fb4883ec084885f6744f488b06", argdata, 2, 6, &func);
}

FUNC_NAKED void SpaceDrone::SetMovementTarget(Targetable *target)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has target
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1026::func)
		 : "rdi", "rsi"
	);
}

namespace _func1027
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("SpaceDrone::SetDeployed", typeid(void (SpaceDrone::*)(bool )), ".5589f5534889fb4883ec08488b07ff506084c0743b", argdata, 2, 6, &func);
}

FUNC_NAKED void SpaceDrone::SetDeployed(bool deployed)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has deployed
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1027::func)
		 : "rdi", "rsi"
	);
}

namespace _func1028
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x7ff, 0x108};
	static FunctionDefinition funcObj("SpaceDrone::CollisionMoving", typeid(CollisionResponse (SpaceDrone::*)(Pointf , Pointf , DamageParameter , bool )), ".41554154554889f5534889fb488d7f044883ec18", argdata, 6, 2, &func);
}

FUNC_NAKED CollisionResponse SpaceDrone::CollisionMoving(Pointf start, Pointf finish, DamageParameter damage, bool raytrace)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"subq $8, %%rsp\n\t"
		"pushq 56(%%rbp)\n\t"		// damage
		"pushq 48(%%rbp)\n\t"		// damage
		"pushq 40(%%rbp)\n\t"		// damage
		"pushq 32(%%rbp)\n\t"		// damage
		"pushq 24(%%rbp)\n\t"		// damage
		"pushq 16(%%rbp)\n\t"		// damage
		"pushq 8(%%rbp)\n\t"		// damage
			// rdi has implicit_output
			// rsi has this
			// rdx has start
			// rcx has finish
			// r8 has raytrace
		"call *%0\n\t"
		"addq $56, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1028::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func1029
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x10a, 0x10b};
	static FunctionDefinition funcObj("SpaceDrone::UpdateAimingAngle", typeid(float (SpaceDrone::*)(Pointf , float , float )), ".530f28e14889fb4883ec30660fd60424", argdata, 4, 2, &func);
}

FUNC_NAKED float SpaceDrone::UpdateAimingAngle(Pointf location, float percentage, float forceDesired)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has location
			// xmm0 has percentage
			// xmm1 has forceDesired
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1029::func)
		 : "rdi", "rsi", "xmm0", "xmm1"
	);
}

namespace _func1030
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SpaceDrone::GetNextProjectile", typeid(Projectile *(SpaceDrone::*)()), ".415741564155415455534889fb4883ec68488b07", argdata, 1, 2, &func);
}

FUNC_NAKED Projectile *SpaceDrone::GetNextProjectile()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1030::func)
		 : "rdi"
	);
}

namespace _func1031
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SpaceManager::constructor", typeid(void (SpaceManager::*)()), "!415455534889fb488d7f18488dabe00100004c8da3700200004883ec10", argdata, 1, 6, &func);
}

FUNC_NAKED void SpaceManager::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1031::func)
		 : "rdi"
	);
}

namespace _func1032
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SpaceManager::GetScreenShake", typeid(int (SpaceManager::*)()), ".0fb687b0040000", argdata, 1, 2, &func);
}

FUNC_NAKED int SpaceManager::GetScreenShake()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1032::func)
		 : "rdi"
	);
}

namespace _func1033
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("SpaceManager::SaveSpace", typeid(void (SpaceManager::*)(int )), ".41544189f455530fb6b7500300004889fb4489e7", argdata, 2, 6, &func);
}

FUNC_NAKED void SpaceManager::SaveSpace(int fileHelper)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has fileHelper
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1033::func)
		 : "rdi", "rsi"
	);
}

namespace _func1034
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("SpaceManager::SwitchBeacon", typeid(ImageDesc (SpaceManager::*)()), ".488b96d80300004889f8", argdata, 2, 2, &func);
}

FUNC_NAKED ImageDesc SpaceManager::SwitchBeacon()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1034::func)
		 : "rdi", "rsi"
	);
}

namespace _func1035
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("SpaceManager::SwitchPlanet", typeid(ImageDesc (SpaceManager::*)(const std::string &)), ".4157415641554989d541544989fc4889d755534889f3", argdata, 3, 2, &func);
}

FUNC_NAKED ImageDesc SpaceManager::SwitchPlanet(const std::string &name)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has name
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1035::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1036
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SpaceManager::UpdatePlanetImage", typeid(void (SpaceManager::*)()), ".55534889fb4883ec68488bb710010000", argdata, 1, 6, &func);
}

FUNC_NAKED void SpaceManager::UpdatePlanetImage()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1036::func)
		 : "rdi"
	);
}

namespace _func1037
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x4ff, 0x4ff, 0x4ff};
	static FunctionDefinition funcObj("SpaceManager::SwitchImages", typeid(void (SpaceManager::*)(ImageDesc , ImageDesc , ImageDesc )), ".55534889fb4883ec68488b8424a0000000", argdata, 4, 6, &func);
}

FUNC_NAKED void SpaceManager::SwitchImages(ImageDesc planet, ImageDesc unk1, ImageDesc unk2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 96(%%rbp)\n\t"		// unk2
		"pushq 88(%%rbp)\n\t"		// unk2
		"pushq 80(%%rbp)\n\t"		// unk2
		"pushq 72(%%rbp)\n\t"		// unk2
		"pushq 64(%%rbp)\n\t"		// unk1
		"pushq 56(%%rbp)\n\t"		// unk1
		"pushq 48(%%rbp)\n\t"		// unk1
		"pushq 40(%%rbp)\n\t"		// unk1
		"pushq 32(%%rbp)\n\t"		// planet
		"pushq 24(%%rbp)\n\t"		// planet
		"pushq 16(%%rbp)\n\t"		// planet
		"pushq 8(%%rbp)\n\t"		// planet
			// rdi has this
		"call *%0\n\t"
		"addq $96, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1037::func)
		 : "rdi"
	);
}

namespace _func1038
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("SpaceManager::SwitchBackground", typeid(ImageDesc (SpaceManager::*)(const std::string &)), ".415641be????????41554989d541544989f4554889fd534883ec30", argdata, 3, 2, &func);
}

FUNC_NAKED ImageDesc SpaceManager::SwitchBackground(const std::string &name)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has name
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1038::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1039
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("SpaceManager::StartAsteroids", typeid(void (SpaceManager::*)(int , bool )), ".4883ec28488b87d8000000482b87d00000000fb6ca", argdata, 3, 6, &func);
}

FUNC_NAKED void SpaceManager::StartAsteroids(int shieldCount, bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shieldCount
			// rdx has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1039::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1040
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("SpaceManager::SetFireLevel", typeid(void (SpaceManager::*)(bool )), ".55488dafa0030000bad0840000534889fb4883ec28", argdata, 2, 6, &func);
}

FUNC_NAKED void SpaceManager::SetFireLevel(bool state)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has state
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1040::func)
		 : "rdi", "rsi"
	);
}

namespace _func1041
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("SpaceManager::SetPlanetaryDefense", typeid(void (SpaceManager::*)(char , int )), ".41544189f4be204e000055488dafa0030000534889fb4881ec90000000", argdata, 3, 6, &func);
}

FUNC_NAKED void SpaceManager::SetPlanetaryDefense(char state, int target)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has state
			// rdx has target
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1041::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1042
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("SpaceManager::SetPulsarLevel", typeid(void (SpaceManager::*)(bool )), ".55488dafa0030000ba50460000534889fb4883ec28", argdata, 2, 6, &func);
}

FUNC_NAKED void SpaceManager::SetPulsarLevel(bool pulsarLevel)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pulsarLevel
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1042::func)
		 : "rdi", "rsi"
	);
}

namespace _func1043
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SpaceManager::DangerousEnvironment", typeid(bool (SpaceManager::*)()), ".0fb6977003000084d2", argdata, 1, 2, &func);
}

FUNC_NAKED bool SpaceManager::DangerousEnvironment()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1043::func)
		 : "rdi"
	);
}

namespace _func1044
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("SpaceManager::MouseMove", typeid(void (SpaceManager::*)(int , int , int )), ".41574989ff41564531f641554189f541544189d45589cd5331db4883ec08", argdata, 4, 6, &func);
}

FUNC_NAKED void SpaceManager::MouseMove(int x, int y, int unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
			// rcx has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1044::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func1045
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("SpaceManager::GetSelectedDrone", typeid(SpaceDrone *(SpaceManager::*)(int , int , int )), ".41574156415541544989fc55534883ec184c8b87e8000000", argdata, 4, 2, &func);
}

FUNC_NAKED SpaceDrone *SpaceManager::GetSelectedDrone(int x, int y, int unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
			// rcx has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1045::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func1046
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SpaceManager::GetFlashOpacity", typeid(float (SpaceManager::*)()), ".530f57c04883ec10", argdata, 1, 2, &func);
}

FUNC_NAKED float SpaceManager::GetFlashOpacity()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1046::func)
		 : "rdi"
	);
}

namespace _func1047
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SpaceManager::GetColorTint", typeid(GL_Color (SpaceManager::*)()), ".80bf7c04000000", argdata, 1, 10, &func);
}

FUNC_NAKED GL_Color SpaceManager::GetColorTint()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1047::func)
		 : "rdi"
	);
}

namespace _func1048
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SpaceManager::OnRenderFleet", typeid(void (SpaceManager::*)()), ".41564989fe4155415455534883ec2080bf7c04000000", argdata, 1, 6, &func);
}

FUNC_NAKED void SpaceManager::OnRenderFleet()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1048::func)
		 : "rdi"
	);
}

namespace _func1049
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SpaceManager::OnRenderForeground", typeid(void (SpaceManager::*)()), ".55534889fb4883ec4880bf7c04000000", argdata, 1, 6, &func);
}

FUNC_NAKED void SpaceManager::OnRenderForeground()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1049::func)
		 : "rdi"
	);
}

namespace _func1050
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("SpaceManager::SetDangerZone", typeid(void (SpaceManager::*)(int )), ".4157415641554989fd41544189f455534883ec28", argdata, 2, 6, &func);
}

FUNC_NAKED void SpaceManager::SetDangerZone(int fleetType)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has fleetType
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1050::func)
		 : "rdi", "rsi"
	);
}

namespace _func1051
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x10a};
	static FunctionDefinition funcObj("SpaceManager::OnRenderAsteroids", typeid(void (SpaceManager::*)(int , float )), ".554889fd534883ec1880bfc800000000", argdata, 3, 6, &func);
}

FUNC_NAKED void SpaceManager::OnRenderAsteroids(int fieldLayers, float unk2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has fieldLayers
			// xmm0 has unk2
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1051::func)
		 : "rdi", "rsi", "xmm0"
	);
}

namespace _func1052
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("SpaceManager::OnRenderProjectiles", typeid(void (SpaceManager::*)(int , int )), ".415741564189d6415541544189f455534889fb4883ec28", argdata, 3, 6, &func);
}

FUNC_NAKED void SpaceManager::OnRenderProjectiles(int unk1, int unk2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk1
			// rdx has unk2
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1052::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1053
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SpaceManager::OnInit", typeid(void (SpaceManager::*)()), ".55be????????534889fb4883ec58", argdata, 1, 6, &func);
}

FUNC_NAKED void SpaceManager::OnInit()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1053::func)
		 : "rdi"
	);
}

namespace _func1054
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SpaceManager::Restart", typeid(void (SpaceManager::*)()), "!.41545553488b0f4889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void SpaceManager::Restart()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1054::func)
		 : "rdi"
	);
}

namespace _func1055
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SpaceManager::ClearEnvironment", typeid(void (SpaceManager::*)()), ".c6875003000000c6875103000000", argdata, 1, 6, &func);
}

FUNC_NAKED void SpaceManager::ClearEnvironment()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1055::func)
		 : "rdi"
	);
}

namespace _func1056
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SpaceManager::Clear", typeid(void (SpaceManager::*)()), "!.41545553488b87d0000000", argdata, 1, 6, &func);
}

FUNC_NAKED void SpaceManager::Clear()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1056::func)
		 : "rdi"
	);
}

namespace _func1057
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SpaceManager::ClearProjectiles", typeid(void (SpaceManager::*)()), ".41545553488b0f4889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void SpaceManager::ClearProjectiles()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1057::func)
		 : "rdi"
	);
}

namespace _func1058
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("SpaceManager::UpdateProjectile", typeid(void (SpaceManager::*)(Projectile *)), ".415741564531f641554531ed41544531e4554889fd4889f7534889f34883ec08", argdata, 2, 6, &func);
}

FUNC_NAKED void SpaceManager::UpdateProjectile(Projectile *proj)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has proj
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1058::func)
		 : "rdi", "rsi"
	);
}

namespace _func1059
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("SpaceManager::TransferProjectile", typeid(void (SpaceManager::*)(Projectile *)), "!.554889f7534889f34883ec08", argdata, 2, 6, &func);
}

FUNC_NAKED void SpaceManager::TransferProjectile(Projectile *proj)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has proj
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1059::func)
		 : "rdi", "rsi"
	);
}

namespace _func1060
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SpaceManager::OnRenderBackground", typeid(void (SpaceManager::*)()), ".41564989fe4155415455534883ec1080bf7c04000000", argdata, 1, 6, &func);
}

FUNC_NAKED void SpaceManager::OnRenderBackground()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1060::func)
		 : "rdi"
	);
}

namespace _func1061
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("SpaceManager::AddProjectile", typeid(void (SpaceManager::*)(Projectile *)), ".4883ec18488b4708483b47104889742408", argdata, 2, 6, &func);
}

FUNC_NAKED void SpaceManager::AddProjectile(Projectile *proj)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has proj
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1061::func)
		 : "rdi", "rsi"
	);
}

namespace _func1062
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("SpaceManager::LoadSpace", typeid(void (SpaceManager::*)(int )), ".415741564189f64155415455534889fb89f74883ec48", argdata, 2, 6, &func);
}

FUNC_NAKED void SpaceManager::LoadSpace(int fileHelper)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has fileHelper
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1062::func)
		 : "rdi", "rsi"
	);
}

namespace _func1063
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("SpaceManager::AddShip", typeid(void (SpaceManager::*)(ShipManager *)), ".415455534889fb4883ec30488b87d8000000", argdata, 2, 6, &func);
}

FUNC_NAKED void SpaceManager::AddShip(ShipManager *ship)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ship
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1063::func)
		 : "rdi", "rsi"
	);
}

namespace _func1064
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SpaceManager::UpdatePDS", typeid(void (SpaceManager::*)()), ".415731d241564531f64155415449bcabaaaaaaaaaaaaaa554889fd4c8dad98040000534881ec28010000", argdata, 1, 6, &func);
}

FUNC_NAKED void SpaceManager::UpdatePDS()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1064::func)
		 : "rdi"
	);
}

namespace _func1065
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SpaceManager::OnLoopNebulas", typeid(void (SpaceManager::*)()), ".415748ba398ee3388ee3388e415641554989fd415455534881ecc8010000", argdata, 1, 6, &func);
}

FUNC_NAKED void SpaceManager::OnLoopNebulas()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1065::func)
		 : "rdi"
	);
}

namespace _func1066
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SpaceManager::OnLoop", typeid(void (SpaceManager::*)()), ".41574156415541544989fc488dbf1804000055534883ec48", argdata, 1, 6, &func);
}

FUNC_NAKED void SpaceManager::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1066::func)
		 : "rdi"
	);
}

namespace _func1067
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("SpaceManager::SetNebula", typeid(void (SpaceManager::*)(bool )), ".4157415641554154554889fd534881ec98000000", argdata, 2, 6, &func);
}

FUNC_NAKED void SpaceManager::SetNebula(bool state)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has state
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1067::func)
		 : "rdi", "rsi"
	);
}

namespace _func1068
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("SpaceManager::SetStorm", typeid(void (SpaceManager::*)(bool )), ".4883ec28be01000000c6873a04000001", argdata, 2, 6, &func);
}

FUNC_NAKED void SpaceManager::SetStorm(bool state)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has state
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1068::func)
		 : "rdi", "rsi"
	);
}

namespace _func1069
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::SetPosition", typeid(void (StarMap::*)(Point )), "4889b7a0000000", argdata, 2, 6, &func);
}

FUNC_NAKED void StarMap::SetPosition(Point unk0)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk0
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1069::func)
		 : "rdi", "rsi"
	);
}

namespace _func1070
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::SetOpen", typeid(void (StarMap::*)(bool )), "!.4084f6488b07", argdata, 2, 6, &func);
}

FUNC_NAKED void StarMap::SetOpen(bool unk0)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk0
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1070::func)
		 : "rdi", "rsi"
	);
}

namespace _func1071
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::GetNextDangerMove", typeid(int (StarMap::*)()), ".8b8f0805000085c9", argdata, 1, 2, &func);
}

FUNC_NAKED int StarMap::GetNextDangerMove()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1071::func)
		 : "rdi"
	);
}

namespace _func1072
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::KeyDown", typeid(void (StarMap::*)(int )), ".80bfb808000000", argdata, 2, 6, &func);
}

FUNC_NAKED void StarMap::KeyDown(int unk0)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk0
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1072::func)
		 : "rdi", "rsi"
	);
}

namespace _func1073
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::Close", typeid(void (StarMap::*)()), ".534889fb4883ec2080bf3c08000000", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::Close()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1073::func)
		 : "rdi"
	);
}

namespace _func1074
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::Open", typeid(void (StarMap::*)()), ".53807f08004889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::Open()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1074::func)
		 : "rdi"
	);
}

namespace _func1075
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::InitMapTitle", typeid(void (StarMap::*)()), ".41554154554889fd534883ec68488bbf38050000", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::InitMapTitle()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1075::func)
		 : "rdi"
	);
}

namespace _func1076
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::InitNoFuelText", typeid(void (StarMap::*)()), ".41554989fd415455534883ec38488bbf80050000", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::InitNoFuelText()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1076::func)
		 : "rdi"
	);
}

namespace _func1077
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::InitBossMessageBox", typeid(void (StarMap::*)()), ".55534889fb4883ec38488baf78070000", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::InitBossMessageBox()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1077::func)
		 : "rdi"
	);
}

namespace _func1078
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::OnLanguageChange", typeid(void (StarMap::*)()), "!.534889fbe8????????4889dfe8", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::OnLanguageChange()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1078::func)
		 : "rdi"
	);
}

namespace _func1079
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::GetRandomSectorChoice", typeid(int (StarMap::*)()), ".4883ec08803d????????00753b", argdata, 1, 2, &func);
}

FUNC_NAKED int StarMap::GetRandomSectorChoice()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1079::func)
		 : "rdi"
	);
}

namespace _func1080
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::NeighboringSector", typeid(void (StarMap::*)(int )), ".31c085f67867", argdata, 2, 6, &func);
}

FUNC_NAKED void StarMap::NeighboringSector(int unk0)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk0
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1080::func)
		 : "rdi", "rsi"
	);
}

namespace _func1081
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("StarMap::GetSelectedSector", typeid(void (StarMap::*)(int , int , int )), ".41554989fd415441bcffffffff5589cd534883ec18", argdata, 4, 6, &func);
}

FUNC_NAKED void StarMap::GetSelectedSector(int unk0, int unk1, int unk2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk0
			// rdx has unk1
			// rcx has unk2
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1081::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func1082
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::StartSecretSector", typeid(void (StarMap::*)()), ".4883ec28488b87b0080000c687b908000001", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::StartSecretSector()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1082::func)
		 : "rdi"
	);
}

namespace _func1083
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::ReachSector", typeid(void (StarMap::*)(Sector *)), ".41574989ff41564155415455534883ec58488b7e10", argdata, 2, 6, &func);
}

FUNC_NAKED void StarMap::ReachSector(Sector *unk0)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk0
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1083::func)
		 : "rdi", "rsi"
	);
}

namespace _func1084
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::UpdateSectorMap", typeid(void (StarMap::*)(Sector *)), "!.4885f6743b", argdata, 2, 6, &func);
}

FUNC_NAKED void StarMap::UpdateSectorMap(Sector *unk0)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk0
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1084::func)
		 : "rdi", "rsi"
	);
}

namespace _func1085
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::SaveGame", typeid(void (StarMap::*)(int )), ".415731d24156415541545589f5534889fb4883ec48", argdata, 2, 6, &func);
}

FUNC_NAKED void StarMap::SaveGame(int file)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has file
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1085::func)
		 : "rdi", "rsi"
	);
}

namespace _func1086
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::InitStatistics", typeid(void (StarMap::*)()), "!.f3c366666666662e0f1f840000000000", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::InitStatistics()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1086::func)
		 : "rdi"
	);
}

namespace _func1087
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::PrintStatistics", typeid(void (StarMap::*)()), "!.f3c366666666662e0f1f840000000000", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::PrintStatistics()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1087::func)
		 : "rdi"
	);
}

namespace _func1088
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::AnalyzeMap", typeid(void (StarMap::*)()), "!.f3c366666666662e0f1f840000000000", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::AnalyzeMap()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1088::func)
		 : "rdi"
	);
}

namespace _func1089
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::ModifyPursuit", typeid(void (StarMap::*)(int )), ".01b708050000", argdata, 2, 6, &func);
}

FUNC_NAKED void StarMap::ModifyPursuit(int unk0)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk0
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1089::func)
		 : "rdi", "rsi"
	);
}

namespace _func1090
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::AtBeacon", typeid(void (StarMap::*)()), ".488b87880000000fb64020", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::AtBeacon()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1090::func)
		 : "rdi"
	);
}

namespace _func1091
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::GetWaitLocation", typeid(void (StarMap::*)()), ".80bfc0000000007427", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::GetWaitLocation()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1091::func)
		 : "rdi"
	);
}

namespace _func1092
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::StartBeacon", typeid(void (StarMap::*)()), ".8b970005000031c085d2", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::StartBeacon()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1092::func)
		 : "rdi"
	);
}

namespace _func1093
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("StarMap::LocationsConnected", typeid(bool (StarMap::*)(Location *, Location *)), ".488b7e08488b76104829fe48c1fe034885f6", argdata, 3, 2, &func);
}

FUNC_NAKED bool StarMap::LocationsConnected(Location *unk0, Location *unk1)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk0
			// rdx has unk1
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1093::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1094
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b};
	static FunctionDefinition funcObj("StarMap::PointToGrid", typeid(Point (StarMap::*)(float , float )), ".4883ec280f28d90f28e0488d7c2410", argdata, 3, 2, &func);
}

FUNC_NAKED Point StarMap::PointToGrid(float x, float y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has x
			// xmm1 has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1094::func)
		 : "rdi", "xmm0", "xmm1"
	);
}

namespace _func1095
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::TravelToLocation", typeid(void (StarMap::*)(Location *)), ".80bea0000000004889b788000000", argdata, 2, 6, &func);
}

FUNC_NAKED void StarMap::TravelToLocation(Location *unk0)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk0
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1095::func)
		 : "rdi", "rsi"
	);
}

namespace _func1096
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::ForceExitBeacon", typeid(void (StarMap::*)()), ".488b8788000000c6402001", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::ForceExitBeacon()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1096::func)
		 : "rdi"
	);
}

namespace _func1097
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::OnRenderFogEffect", typeid(void (StarMap::*)()), "!.f3c366666666662e0f1f840000000000", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::OnRenderFogEffect()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1097::func)
		 : "rdi"
	);
}

namespace _func1098
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::LocationHasBoss", typeid(void (StarMap::*)(Location *)), ".48638fa00a0000488b97b00a0000", argdata, 2, 6, &func);
}

FUNC_NAKED void StarMap::LocationHasBoss(Location *unk0)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk0
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1098::func)
		 : "rdi", "rsi"
	);
}

namespace _func1099
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::LocationHasStore", typeid(void (StarMap::*)(Location *)), ".488b46304885c0", argdata, 2, 6, &func);
}

FUNC_NAKED void StarMap::LocationHasStore(Location *unk0)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk0
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1099::func)
		 : "rdi", "rsi"
	);
}

namespace _func1100
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::LocationHasShip", typeid(void (StarMap::*)(Location *)), ".488b46304885c0", argdata, 2, 6, &func);
}

FUNC_NAKED void StarMap::LocationHasShip(Location *unk0)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk0
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1100::func)
		 : "rdi", "rsi"
	);
}

namespace _func1101
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::AdvanceWorldLevel", typeid(void (StarMap::*)()), ".55534889fb4883ec488b8700050000", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::AdvanceWorldLevel()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1101::func)
		 : "rdi"
	);
}

namespace _func1102
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("StarMap::GetLocationText", typeid(std::string (StarMap::*)(const Location *)), ".41554154554889fd534889f3", argdata, 3, 2, &func);
}

FUNC_NAKED std::string StarMap::GetLocationText(const Location *loc)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has loc
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1102::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1103
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::ReverseBossPath", typeid(void (StarMap::*)()), ".488b8fb80a0000488b87b00a0000", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::ReverseBossPath()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1103::func)
		 : "rdi"
	);
}

namespace _func1104
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::ForceBossJump", typeid(void (StarMap::*)()), ".80bfa80a000000c687a90a000001", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::ForceBossJump()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1104::func)
		 : "rdi"
	);
}

namespace _func1105
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::ClearBoss", typeid(void (StarMap::*)()), ".41544989fc5531ed53488b572831db488b4730c687c80a000000", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::ClearBoss()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1105::func)
		 : "rdi"
	);
}

namespace _func1106
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::SetBossStage", typeid(void (StarMap::*)(int )), ".89b7500c0000", argdata, 2, 6, &func);
}

FUNC_NAKED void StarMap::SetBossStage(int stage)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has stage
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1106::func)
		 : "rdi", "rsi"
	);
}

namespace _func1107
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::CheckGameOver", typeid(void (StarMap::*)()), ".31c083bfa40a000004", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::CheckGameOver()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1107::func)
		 : "rdi"
	);
}

namespace _func1108
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::RenderLabels", typeid(void (StarMap::*)()), ".415741564155415455534889fb4881ec98000000", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::RenderLabels()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1108::func)
		 : "rdi"
	);
}

namespace _func1109
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::DeleteMap", typeid(void (StarMap::*)()), ".41554154554889fd534883ec184c8baf380c0000", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::DeleteMap()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1109::func)
		 : "rdi"
	);
}

namespace _func1110
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("StarMap::MouseClick", typeid(void (StarMap::*)(int , int )), ".55534889fb4883ec2880bfc006000000", argdata, 3, 6, &func);
}

FUNC_NAKED void StarMap::MouseClick(int unk0, int unk1)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk0
			// rdx has unk1
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1110::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1111
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::AddSectorColumn", typeid(void (StarMap::*)()), ".415741564155415455bd56555555534889fb4881ec48010000", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::AddSectorColumn()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1111::func)
		 : "rdi"
	);
}

namespace _func1112
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::PushSectorColumn", typeid(void (StarMap::*)()), "!.41544989fc31d25531ed53", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::PushSectorColumn()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1112::func)
		 : "rdi"
	);
}

namespace _func1113
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::SelectNewSector", typeid(void (StarMap::*)(int )), "!.534c8b87900800004889fb488b8f980800004c29c148c1f903", argdata, 2, 6, &func);
}

FUNC_NAKED void StarMap::SelectNewSector(int unk0)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk0
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1113::func)
		 : "rdi", "rsi"
	);
}

namespace _func1114
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::GenerateSectorMap", typeid(void (StarMap::*)()), ".415741564155415455534889fb4881ec18010000488bb798080000", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::GenerateSectorMap()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1114::func)
		 : "rdi"
	);
}

namespace _func1115
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("StarMap::DrawConnection", typeid(void (StarMap::*)(const Pointf &, const Pointf &, const GL_Color *)), ".4157415641554989d541544989f4554889fd4889d7534889cb4881ec98000000", argdata, 4, 6, &func);
}

FUNC_NAKED void StarMap::DrawConnection(const Pointf &pos1, const Pointf &pos2, const GL_Color *color)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos1
			// rdx has pos2
			// rcx has color
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1115::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func1116
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("StarMap::SetupNoFuel", typeid(void (StarMap::*)(int , const std::string &)), ".415741564989fe41554154554889d5534881ecb8000000", argdata, 3, 6, &func);
}

FUNC_NAKED void StarMap::SetupNoFuel(int seed, const std::string &forceEscape)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has seed
			// rdx has forceEscape
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1116::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1117
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::TurnIntoFleetLocation", typeid(void (StarMap::*)(Location *)), ".41554154554889fd534889f34883ec38488b7e30", argdata, 2, 6, &func);
}

FUNC_NAKED void StarMap::TurnIntoFleetLocation(Location *loc)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has loc
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1117::func)
		 : "rdi", "rsi"
	);
}

namespace _func1118
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::UpdateBoss", typeid(void (StarMap::*)()), ".554889fd534883ec288b87a00a0000", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::UpdateBoss()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1118::func)
		 : "rdi"
	);
}

namespace _func1119
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::UpdateDangerZone", typeid(void (StarMap::*)()), ".415455534889fb4883ec4080bf3c08000000", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::UpdateDangerZone()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1119::func)
		 : "rdi"
	);
}

namespace _func1120
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::GetNewLocation", typeid(Location *(StarMap::*)()), ".5331c080bfc0000000004889fb", argdata, 1, 2, &func);
}

FUNC_NAKED Location *StarMap::GetNewLocation()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1120::func)
		 : "rdi"
	);
}

namespace _func1121
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::OnLoop", typeid(void (StarMap::*)()), ".41564155415455534889fb4883ec20807f0800", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1121::func)
		 : "rdi"
	);
}

namespace _func1122
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::GenerateNebulas", typeid(void (StarMap::*)(const std::vector<std::string> &)), ".41574156415541544989f455534881ecb8000000", argdata, 2, 6, &func);
}

FUNC_NAKED void StarMap::GenerateNebulas(const std::vector<std::string> &names)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has names
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1122::func)
		 : "rdi", "rsi"
	);
}

namespace _func1123
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::GenerateEvents", typeid(void (StarMap::*)(bool )), ".4157415641554989fd41545589f55348bbabaaaaaaaaaaaaaa4881ec58010000", argdata, 2, 6, &func);
}

FUNC_NAKED void StarMap::GenerateEvents(bool tutorial)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has tutorial
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1123::func)
		 : "rdi", "rsi"
	);
}

namespace _func1124
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::AddConnections", typeid(void (StarMap::*)(Location *)), ".415641554989fd41544c8da7800c0000554889f5534c89e34883ec10", argdata, 2, 6, &func);
}

FUNC_NAKED void StarMap::AddConnections(Location *unk0)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk0
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1124::func)
		 : "rdi", "rsi"
	);
}

namespace _func1125
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::MapConnected", typeid(void (StarMap::*)()), ".53488bb7880c00004889fb488dbf780c0000", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::MapConnected()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1125::func)
		 : "rdi"
	);
}

namespace _func1126
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("StarMap::ConnectLocations", typeid(void (StarMap::*)(Point , Point )), ".415741564155415455488d6f4853488d5f404883ec38", argdata, 3, 6, &func);
}

FUNC_NAKED void StarMap::ConnectLocations(Point unk0, Point unk1)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk0
			// rdx has unk1
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1126::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1127
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::PopulateGrid", typeid(void (StarMap::*)(Point )), ".415541544989fc5553488d5f404883ec38", argdata, 2, 6, &func);
}

FUNC_NAKED void StarMap::PopulateGrid(Point unk0)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk0
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1127::func)
		 : "rdi", "rsi"
	);
}

namespace _func1128
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("StarMap::PopClosestLoc", typeid(Location *(StarMap::*)(std::vector<Location*> &, std::map<Location*, int> &)), ".4157415641554989f541544989d455534883ec28488b4e08", argdata, 3, 2, &func);
}

FUNC_NAKED Location *StarMap::PopClosestLoc(std::vector<Location*> &vec, std::map<Location*, int> &map)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has vec
			// rdx has map
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1128::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1129
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("StarMap::AddQuest", typeid(bool (StarMap::*)(const std::string &, bool )), ".415731c941b8ffffffff415641554989fd4154554889f5534883ec78", argdata, 3, 2, &func);
}

FUNC_NAKED bool StarMap::AddQuest(const std::string &questEvent, bool force)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has questEvent
			// rdx has force
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1129::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1130
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("StarMap::GenerateMap", typeid(Location *(StarMap::*)(bool , bool )), ".41574156415541544189f455534889fb4881ec38010000", argdata, 3, 2, &func);
}

FUNC_NAKED Location *StarMap::GenerateMap(bool tutorial, bool seed)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has tutorial
			// rdx has seed
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1130::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1131
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::NewGame", typeid(Location *(StarMap::*)(bool )), ".415741564989fe41554189f5415455534883ec78", argdata, 2, 2, &func);
}

FUNC_NAKED Location *StarMap::NewGame(bool unk0)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk0
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1131::func)
		 : "rdi", "rsi"
	);
}

namespace _func1132
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("StarMap::Dijkstra", typeid(std::vector<Location*> (StarMap::*)(Location *, Location *, bool )), ".415741564155415455534881ecf8000000", argdata, 5, 2, &func);
}

FUNC_NAKED std::vector<Location*> StarMap::Dijkstra(Location *start, Location *finish, bool include_unknown)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has start
			// rcx has finish
			// r8 has include_unknown
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1132::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func1133
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x109, 0x1ff};
	static FunctionDefinition funcObj("StarMap::OnTouch", typeid(void (StarMap::*)(TouchAction , int , int , int , int , int )), ".41574989ff41564189ce41554589cd41544589c45589d55389f34881ec98000000", argdata, 7, 6, &func);
}

FUNC_NAKED void StarMap::OnTouch(TouchAction unk0, int unk1, int unk2, int unk3, int unk4, int unk5)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"subq $8, %%rsp\n\t"
		"pushq 8(%%rbp)\n\t"		// unk5
			// rdi has this
			// rsi has unk0
			// rdx has unk1
			// rcx has unk2
			// r8 has unk3
			// r9 has unk4
		"call *%0\n\t"
		"addq $8, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1133::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "r9"
	);
}

namespace _func1134
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("StarMap::MouseMove", typeid(void (StarMap::*)(int , int )), ".415741564989fe41554189d541544189f455534881ec88000000", argdata, 3, 6, &func);
}

FUNC_NAKED void StarMap::MouseMove(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1134::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1135
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x2ff};
	static FunctionDefinition funcObj("StarMap::RenderSectorName", typeid(void (StarMap::*)(Sector *, GL_Color )), ".4157415641554989f541544989fc55534881ecf8010000", argdata, 3, 6, &func);
}

FUNC_NAKED void StarMap::RenderSectorName(Sector *unk0, GL_Color unk1)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// unk1
		"pushq 8(%%rbp)\n\t"		// unk1
			// rdi has this
			// rsi has unk0
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1135::func)
		 : "rdi", "rsi"
	);
}

namespace _func1136
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::constructor", typeid(void (StarMap::*)()), ".41574989ff41564d8db7d80100004155", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1136::func)
		 : "rdi"
	);
}

namespace _func1137
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StarMap::LoadGame", typeid(Location *(StarMap::*)(int )), ".415741564189f64155415455534889fb89f74881ecf8030000", argdata, 2, 2, &func);
}

FUNC_NAKED Location *StarMap::LoadGame(int fileHelper)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has fileHelper
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1137::func)
		 : "rdi", "rsi"
	);
}

namespace _func1138
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b, 0x106};
	static FunctionDefinition funcObj("StarMap::RenderLeftInsetButton", typeid(void (StarMap::*)(float , float , bool )), ".41544189f455534889fb4883ec50", argdata, 4, 6, &func);
}

FUNC_NAKED void StarMap::RenderLeftInsetButton(float unk0, float unk1, bool unk2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has unk0
			// xmm1 has unk1
			// rsi has unk2
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1138::func)
		 : "rdi", "xmm0", "xmm1", "rsi"
	);
}

namespace _func1139
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::RenderDistressButtons", typeid(void (StarMap::*)()), ".4156be????????41554154554889fd", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::RenderDistressButtons()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1139::func)
		 : "rdi"
	);
}

namespace _func1140
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StarMap::OnRender", typeid(void (StarMap::*)()), ".415741564155415455534889fb4881ec78010000", argdata, 1, 6, &func);
}

FUNC_NAKED void StarMap::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1140::func)
		 : "rdi"
	);
}

namespace _func1141
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("StatusEffect::GetNebulaEffect", typeid(StatusEffect (*)()), "4883ec08803d????????007433660f6f05????????48b8020000000700000048ba0000000002000000", argdata, 0, 10, &func);
}

FUNC_NAKED StatusEffect StatusEffect::GetNebulaEffect()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1141::func)
	);
}

namespace _func1142
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Store::KeyDown", typeid(bool (Store::*)(SDLKey )), "5383bf2c060000024889fb", argdata, 2, 2, &func);
}

FUNC_NAKED bool Store::KeyDown(SDLKey key)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has key
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1142::func)
		 : "rdi", "rsi"
	);
}

namespace _func1143
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Store::OnLoop", typeid(void (Store::*)()), ".5531c94889fd5331db4883ec08488b9778040000", argdata, 1, 6, &func);
}

FUNC_NAKED void Store::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1143::func)
		 : "rdi"
	);
}

namespace _func1144
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Store::Close", typeid(void (Store::*)()), "!.534889fbc6470800488bbf48060000", argdata, 1, 6, &func);
}

FUNC_NAKED void Store::Close()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1144::func)
		 : "rdi"
	);
}

namespace _func1145
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Store::constructor", typeid(void (Store::*)()), ".415455534889fb488d6b284c8d63684883ec10", argdata, 1, 6, &func);
}

FUNC_NAKED void Store::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1145::func)
		 : "rdi"
	);
}

namespace _func1146
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Store::SaveStore", typeid(void (Store::*)(int )), ".41574156415541545589f5534889fb4883ec18", argdata, 2, 6, &func);
}

FUNC_NAKED void Store::SaveStore(int file)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has file
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1146::func)
		 : "rdi", "rsi"
	);
}

namespace _func1147
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("Store::RelinkShip", typeid(void (Store::*)(ShipManager *, Equipment *)), ".41554989fd4531c041544989d4554889f55331db4883ec08", argdata, 3, 6, &func);
}

FUNC_NAKED void Store::RelinkShip(ShipManager *ship, Equipment *equip)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ship
			// rdx has equip
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1147::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1148
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Store::HasType", typeid(bool (Store::*)(int )), ".39b730060000", argdata, 2, 2, &func);
}

FUNC_NAKED bool Store::HasType(int type)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has type
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1148::func)
		 : "rdi", "rsi"
	);
}

namespace _func1149
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Store::Clear", typeid(void (Store::*)()), ".554889fd534883ec08488bb780040000", argdata, 1, 6, &func);
}

FUNC_NAKED void Store::Clear()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1149::func)
		 : "rdi"
	);
}

namespace _func1150
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("Store::InitHeading", typeid(void (Store::*)(int , Point )), ".554863ee", argdata, 3, 6, &func);
}

FUNC_NAKED void Store::InitHeading(int index, Point pos)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has index
			// rdx has pos
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1150::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1151
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Store::DrawBuySellTabText", typeid(void (*)()), ".55be????????534883ec58488d54241f488d7c2440", argdata, 0, 6, &func);
}

FUNC_NAKED void Store::DrawBuySellTabText()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1151::func)
	);
}

namespace _func1152
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Store::SetPositions", typeid(void (Store::*)()), ".4157ba2a000000bec60000004156415541545531ed534889fb4883ec78", argdata, 1, 6, &func);
}

FUNC_NAKED void Store::SetPositions()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1152::func)
		 : "rdi"
	);
}

namespace _func1153
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("Store::LoadStore", typeid(void (Store::*)(int , int )), ".4157415641554189f5415455534889fb4883ec68", argdata, 3, 6, &func);
}

FUNC_NAKED void Store::LoadStore(int file, int worldLevel)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has file
			// rdx has worldLevel
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1153::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1154
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Store::SetPosition", typeid(void (Store::*)(Point )), "!.534889fb", argdata, 2, 6, &func);
}

FUNC_NAKED void Store::SetPosition(Point pos)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1154::func)
		 : "rdi", "rsi"
	);
}

namespace _func1155
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("Store::CreateStoreBoxes", typeid(void (Store::*)(int , Equipment *)), ".4157415641554189f541544989fc55534881ec88000000", argdata, 3, 6, &func);
}

FUNC_NAKED void Store::CreateStoreBoxes(int type, Equipment *equip)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has type
			// rdx has equip
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1155::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1156
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("Store::OnInit", typeid(void (Store::*)(ShipManager *, Equipment *, int )), "!.415641554989d541544189cc554889f553", argdata, 4, 6, &func);
}

FUNC_NAKED void Store::OnInit(ShipManager *shopper, Equipment *equip, int worldLevel)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shopper
			// rdx has equip
			// rcx has worldLevel
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1156::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func1157
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("Store::MouseMove", typeid(void (Store::*)(int , int )), ".415741564189d641554189f5415455534889fb4883ec78", argdata, 3, 6, &func);
}

FUNC_NAKED void Store::MouseMove(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1157::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1158
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("Store::MouseClick", typeid(void (Store::*)(int , int )), ".41564189d641554189f5415455534889fb4883ec40", argdata, 3, 6, &func);
}

FUNC_NAKED void Store::MouseClick(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1158::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1159
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Store::OnRender", typeid(void (Store::*)()), ".415741564989fe4155415455534881ecd8010000", argdata, 1, 6, &func);
}

FUNC_NAKED void Store::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1159::func)
		 : "rdi"
	);
}

namespace _func1160
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Store::destructor", typeid(void (Store::*)()), ".415531c94154554889fd5331db4883ec18", argdata, 1, 6, &func);
}

FUNC_NAKED void Store::destructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1160::func)
		 : "rdi"
	);
}

namespace _func1161
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("StoreBox::MouseClick", typeid(void (StoreBox::*)(int , int )), "807f60007412807f6100740c", argdata, 3, 6, &func);
}

FUNC_NAKED void StoreBox::MouseClick(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1161::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1162
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StoreBox::Activate", typeid(void (StoreBox::*)()), ".4883ec28488b8718010000", argdata, 1, 6, &func);
}

FUNC_NAKED void StoreBox::Activate()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1162::func)
		 : "rdi"
	);
}

namespace _func1163
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StoreBox::SetPosition", typeid(void (StoreBox::*)(Point )), ".554889f248c1fa2053488d5f184883ec18", argdata, 2, 6, &func);
}

FUNC_NAKED void StoreBox::SetPosition(Point pos)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1163::func)
		 : "rdi", "rsi"
	);
}

namespace _func1164
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("StoreBox::InitBlueprint", typeid(void (StoreBox::*)(Blueprint *)), ".554889f5488d7610534889fb488dbfb0000000", argdata, 2, 6, &func);
}

FUNC_NAKED void StoreBox::InitBlueprint(Blueprint *bp)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has bp
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1164::func)
		 : "rdi", "rsi"
	);
}

namespace _func1165
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("StoreBox::constructor", typeid(void (StoreBox::*)(const std::string &, ShipManager *, Equipment *)), ".41574989d7415641554989f5415455534889fb", argdata, 4, 6, &func);
}

FUNC_NAKED void StoreBox::constructor(const std::string &buttonImage, ShipManager *shopper, Equipment *equip)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has buttonImage
			// rdx has shopper
			// rcx has equip
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1165::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func1166
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StoreBox::OnLoop", typeid(void (StoreBox::*)()), "!.538b871001000031f64889fb85c0", argdata, 1, 6, &func);
}

FUNC_NAKED void StoreBox::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1166::func)
		 : "rdi"
	);
}

namespace _func1167
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StoreBox::Purchase", typeid(void (StoreBox::*)()), ".534889fbbe", argdata, 1, 6, &func);
}

FUNC_NAKED void StoreBox::Purchase()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1167::func)
		 : "rdi"
	);
}

namespace _func1168
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("StoreBox::OnRender", typeid(void (StoreBox::*)()), ".415741564155415455534889fb488d7f184881ecc8040000", argdata, 1, 6, &func);
}

FUNC_NAKED void StoreBox::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1168::func)
		 : "rdi"
	);
}

namespace _func1169
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("SystemBox::OnRender", typeid(void (SystemBox::*)(bool )), "4157b8010000004156415541545589f5534889fb4883ec58", argdata, 2, 6, &func);
}

FUNC_NAKED void SystemBox::OnRender(bool ignoreStatus)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ignoreStatus
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1169::func)
		 : "rdi", "rsi"
	);
}

namespace _func1170
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("SystemBox::MouseClick", typeid(bool (SystemBox::*)(bool )), ".41544189f4554889fd5331db4883ec20", argdata, 2, 2, &func);
}

FUNC_NAKED bool SystemBox::MouseClick(bool shift)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shift
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1170::func)
		 : "rdi", "rsi"
	);
}

namespace _func1171
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("SystemBox::constructor", typeid(void (SystemBox::*)(Point , ShipSystem *, bool )), ".4157415641be01000000415541544189cc55534889fb", argdata, 4, 6, &func);
}

FUNC_NAKED void SystemBox::constructor(Point pos, ShipSystem *sys, bool playerUI)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
			// rdx has sys
			// rcx has playerUI
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1171::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func1172
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("SystemBox::KeyDown", typeid(void (SystemBox::*)(SDLKey , bool )), ".415541544189d45589f5534889fb4883ec38", argdata, 3, 6, &func);
}

FUNC_NAKED void SystemBox::KeyDown(SDLKey key, bool shift)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has key
			// rdx has shift
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1172::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1173
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("SystemBox::MouseMove", typeid(void (SystemBox::*)(int , int )), ".5589f5534889fb4883ec388b87ac010000", argdata, 3, 6, &func);
}

FUNC_NAKED void SystemBox::MouseMove(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1173::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1174
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("SystemControl::GetSystemBox", typeid(SystemBox *(SystemControl::*)(int )), "415531d24989fd41545589f55331db4883ec08488b4f10488b47184829c848c1f8034885c07522eb57", argdata, 2, 2, &func);
}

FUNC_NAKED SystemBox *SystemControl::GetSystemBox(int systemId)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has systemId
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1174::func)
		 : "rdi", "rsi"
	);
}

namespace _func1175
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("SystemControl::GetPowerBars", typeid(SystemControl::PowerBars *(*)(int , int , int , bool )), ".41574189f24189d34189cf415641554c63ee41545589fd534863df4989d84889d84881ec88000000", argdata, 4, 2, &func);
}

FUNC_NAKED SystemControl::PowerBars *SystemControl::GetPowerBars(int width, int height, int gap, bool useShieldGap)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has width
			// rsi has height
			// rdx has gap
			// rcx has useShieldGap
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1175::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func1176
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SystemControl::RenderPowerBar", typeid(void (SystemControl::*)()), ".415741564989fe4155415455534883ec28488b3f", argdata, 1, 6, &func);
}

FUNC_NAKED void SystemControl::RenderPowerBar()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1176::func)
		 : "rdi"
	);
}

namespace _func1177
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SystemControl::CreateSystemBoxes", typeid(void (SystemControl::*)()), ".415731d231f641564155415455534889fb4883ec58488d7c2430", argdata, 1, 6, &func);
}

FUNC_NAKED void SystemControl::CreateSystemBoxes()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1177::func)
		 : "rdi"
	);
}

Point *Global_SystemControl_weapon_position;

namespace _var1178
{
	static VariableDefinition varObj("Global_SystemControl_weapon_position", "!488b442430488d7c243031d231f6488905(???????\?)e8????????488b442430488b7318488b5310488905(???????\?)", &Global_SystemControl_weapon_position);
}

Point *Global_SystemControl_drone_position;

namespace _var1179
{
	static VariableDefinition varObj("Global_SystemControl_drone_position", "", &Global_SystemControl_drone_position);
}

namespace _func1180
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("SystemCustomBox::constructor", typeid(void (SystemCustomBox::*)(Point , ShipSystem *, ShipManager *)), "41544989cc31c9554889f5534889fb4883ec40", argdata, 4, 6, &func);
}

FUNC_NAKED void SystemCustomBox::constructor(Point pos, ShipSystem *sys, ShipManager *ship)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
			// rdx has sys
			// rcx has ship
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1180::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func1181
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SystemStoreBox::CanHold", typeid(bool (SystemStoreBox::*)()), "534883bf18010000004889fb", argdata, 1, 2, &func);
}

FUNC_NAKED bool SystemStoreBox::CanHold()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1181::func)
		 : "rdi"
	);
}

namespace _func1182
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("SystemStoreBox::SetExtraData", typeid(void (SystemStoreBox::*)(int )), ".55534889fb4883ec38837f0804", argdata, 2, 6, &func);
}

FUNC_NAKED void SystemStoreBox::SetExtraData(int droneChoice)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has droneChoice
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1182::func)
		 : "rdi", "rsi"
	);
}

namespace _func1183
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SystemStoreBox::Activate", typeid(void (SystemStoreBox::*)()), ".534889fb4883ec20488bbf180100008b83e0000000", argdata, 1, 6, &func);
}

FUNC_NAKED void SystemStoreBox::Activate()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1183::func)
		 : "rdi"
	);
}

namespace _func1184
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("SystemStoreBox::constructor", typeid(void (SystemStoreBox::*)(ShipManager *, Equipment *, int )), ".41568d41fa41554989d541544989f45589cd534889fb4883ec5083f802", argdata, 4, 6, &func);
}

FUNC_NAKED void SystemStoreBox::constructor(ShipManager *shopper, Equipment *equip, int sys)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shopper
			// rdx has equip
			// rcx has sys
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1184::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func1185
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("SystemStoreBox::Purchase", typeid(void (SystemStoreBox::*)()), ".534889fb4883ec30e8????????8b7308", argdata, 1, 6, &func);
}

FUNC_NAKED void SystemStoreBox::Purchase()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1185::func)
		 : "rdi"
	);
}

namespace _func1186
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("SystemStoreBox::MouseMove", typeid(void (SystemStoreBox::*)(int , int )), ".41544189d45589f5534889fb4883ec308b8710010000", argdata, 3, 6, &func);
}

FUNC_NAKED void SystemStoreBox::MouseMove(int mX, int mY)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mX
			// rdx has mY
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1186::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1187
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TabbedWindow::Close", typeid(void (TabbedWindow::*)()), "538b57684889fb488b4738", argdata, 1, 6, &func);
}

FUNC_NAKED void TabbedWindow::Close()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1187::func)
		 : "rdi"
	);
}

namespace _func1188
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("TeleportBox::constructor", typeid(void (TeleportBox::*)(Point , TeleportSystem *)), "4155b9010000004989d5415455534889fb4c8da370020000488dab000300004883ec58", argdata, 3, 6, &func);
}

FUNC_NAKED void TeleportBox::constructor(Point pos, TeleportSystem *sys)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
			// rdx has sys
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1188::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1189
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TeleportSystem::Jump", typeid(void (TeleportSystem::*)()), "534889fbe8????????c78344020000000000005b", argdata, 1, 6, &func);
}

FUNC_NAKED void TeleportSystem::Jump()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1189::func)
		 : "rdi"
	);
}

namespace _func1190
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("TeleportSystem::SetHackingLevel", typeid(void (TeleportSystem::*)(int )), ".5589f5534889fb4883ec0883fe017e09", argdata, 2, 6, &func);
}

FUNC_NAKED void TeleportSystem::SetHackingLevel(int hackingLevel)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has hackingLevel
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1190::func)
		 : "rdi", "rsi"
	);
}

namespace _func1191
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TeleportSystem::OnRenderFloor", typeid(void (TeleportSystem::*)()), ".415741564155415455534889fb4883ec38", argdata, 1, 6, &func);
}

FUNC_NAKED void TeleportSystem::OnRenderFloor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1191::func)
		 : "rdi"
	);
}

namespace _func1192
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("TeleportSystem::constructor", typeid(void (TeleportSystem::*)(int , int , int , int )), ".5589d5534889fb4883ec08", argdata, 5, 6, &func);
}

FUNC_NAKED void TeleportSystem::constructor(int systemId, int roomId, int shipId, int startingPower)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has systemId
			// rdx has roomId
			// rcx has shipId
			// r8 has startingPower
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1192::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func1193
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TeleportSystem::GetChargedPercent", typeid(float (TeleportSystem::*)()), ".f30f108744020000", argdata, 1, 2, &func);
}

FUNC_NAKED float TeleportSystem::GetChargedPercent()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1193::func)
		 : "rdi"
	);
}

namespace _func1194
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TeleportSystem::Charged", typeid(bool (TeleportSystem::*)()), ".534889fb", argdata, 1, 2, &func);
}

FUNC_NAKED bool TeleportSystem::Charged()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1194::func)
		 : "rdi"
	);
}

namespace _func1195
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TeleportSystem::ClearCrewLocations", typeid(void (TeleportSystem::*)()), ".41564155415455534c63a77c0200004889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void TeleportSystem::ClearCrewLocations()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1195::func)
		 : "rdi"
	);
}

namespace _func1196
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("TeleportSystem::UpdateCrewLocation", typeid(void (TeleportSystem::*)(int )), ".488b97500200004863c689f148c1e806488d14c2b801000000", argdata, 2, 6, &func);
}

FUNC_NAKED void TeleportSystem::UpdateCrewLocation(int unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1196::func)
		 : "rdi", "rsi"
	);
}

namespace _func1197
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("TeleportSystem::SetArmed", typeid(void (TeleportSystem::*)(int )), ".534889fb4883ec3083fe01", argdata, 2, 6, &func);
}

FUNC_NAKED void TeleportSystem::SetArmed(int armed)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has armed
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1197::func)
		 : "rdi", "rsi"
	);
}

namespace _func1198
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TeleportSystem::ForceReady", typeid(void (TeleportSystem::*)()), "!.c787440200000000c84231f6", argdata, 1, 6, &func);
}

FUNC_NAKED void TeleportSystem::ForceReady()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1198::func)
		 : "rdi"
	);
}

namespace _func1199
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TeleportSystem::CanSend", typeid(bool (TeleportSystem::*)()), ".534889fb4883ec308b4f1885c9", argdata, 1, 2, &func);
}

FUNC_NAKED bool TeleportSystem::CanSend()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1199::func)
		 : "rdi"
	);
}

namespace _func1200
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TeleportSystem::CanReceive", typeid(bool (TeleportSystem::*)()), ".5589f5534889fb4883ec0880bf4902000000", argdata, 1, 2, &func);
}

FUNC_NAKED bool TeleportSystem::CanReceive()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1200::func)
		 : "rdi"
	);
}

namespace _func1201
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TeleportSystem::OnLoop", typeid(void (TeleportSystem::*)()), ".534889fb4883ec30", argdata, 1, 6, &func);
}

FUNC_NAKED void TeleportSystem::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1201::func)
		 : "rdi"
	);
}

namespace _func1202
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TeleportSystem::InitiateTeleport", typeid(void (TeleportSystem::*)()), ".534889fb4883ec20", argdata, 1, 6, &func);
}

FUNC_NAKED void TeleportSystem::InitiateTeleport()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1202::func)
		 : "rdi"
	);
}

namespace _func1203
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TextButton::ResetPrimitives", typeid(void (TextButton::*)()), "554889fd5331db4883ec08488b7c1d50", argdata, 1, 6, &func);
}

FUNC_NAKED void TextButton::ResetPrimitives()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1203::func)
		 : "rdi"
	);
}

namespace _func1204
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TextButton::GetIdealButtonWidth", typeid(int (TextButton::*)()), "55534889fb4883ec3880bfe800000000", argdata, 1, 2, &func);
}

FUNC_NAKED int TextButton::GetIdealButtonWidth()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1204::func)
		 : "rdi"
	);
}

namespace _func1205
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x109};
	static FunctionDefinition funcObj("TextButton::OnInit", typeid(void (TextButton::*)(Point , Point , int , TextString *, int )), "415741564d89c641554989d541544989f44c89c6554489cd534889fb488dbfe0000000", argdata, 6, 6, &func);
}

FUNC_NAKED void TextButton::OnInit(Point pos, Point size, int cornerInset, TextString *buttonLabel, int font)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
			// rdx has size
			// rcx has cornerInset
			// r8 has buttonLabel
			// r9 has font
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1205::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "r9"
	);
}

namespace _func1206
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TextButton::OnRender", typeid(void (TextButton::*)()), "4157415641554989fd415455534883ec5880bfd000000000", argdata, 1, 6, &func);
}

FUNC_NAKED void TextButton::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1206::func)
		 : "rdi"
	);
}

namespace _func1207
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TextButton::destructor", typeid(void (TextButton::*)()), "534889fb4883ec1048c707????????488b7f50", argdata, 1, 6, &func);
}

FUNC_NAKED void TextButton::destructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1207::func)
		 : "rdi"
	);
}

namespace _func1208
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TextButton::GetSize", typeid(Point (TextButton::*)()), "4155415455534889fb4883ec1880bfd000000000751a", argdata, 1, 2, &func);
}

FUNC_NAKED Point TextButton::GetSize()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1208::func)
		 : "rdi"
	);
}

namespace _func1209
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("TextButton::OnInitRect", typeid(void (TextButton::*)(Globals::Rect &, int , TextString &, int )), "41574156415541544989cc554889f5534889fb4883ec488954240c", argdata, 5, 6, &func);
}

FUNC_NAKED void TextButton::OnInitRect(Globals::Rect &rect, int cornerInset, TextString &buttonLabel, int font)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has rect
			// rdx has cornerInset
			// rcx has buttonLabel
			// r8 has font
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1209::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func1210
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("TextButton::SetBaseImage", typeid(void (TextButton::*)(const std::string &, Point , int )), "4154488b065553488378e800", argdata, 4, 6, &func);
}

FUNC_NAKED void TextButton::SetBaseImage(const std::string &name, Point pos, int autoWidthMin)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has name
			// rdx has pos
			// rcx has autoWidthMin
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1210::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func1211
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("TextButton::SetAutoWidth", typeid(void (TextButton::*)(bool , bool , int , int )), "4585c04088b7d0000000", argdata, 5, 6, &func);
}

FUNC_NAKED void TextButton::SetAutoWidth(bool autoWidth, bool autoRightAlign, int margin, int min)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has autoWidth
			// rdx has autoRightAlign
			// rcx has margin
			// r8 has min
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1211::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func1212
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TextButton::UpdateAutoWidth", typeid(void (TextButton::*)()), ".4155415455534889fb4883ec1880bfd000000000", argdata, 1, 6, &func);
}

FUNC_NAKED void TextButton::UpdateAutoWidth()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1212::func)
		 : "rdi"
	);
}

namespace _func1213
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TextButton::constructor", typeid(void (TextButton::*)()), "55534889fb488d7f08488d6b284883ec28", argdata, 1, 6, &func);
}

FUNC_NAKED void TextButton::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1213::func)
		 : "rdi"
	);
}

namespace _func1214
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x2ff};
	static FunctionDefinition funcObj("TextButton::SetInactiveColor", typeid(void (TextButton::*)(GL_Color )), ".!80bf8000000000660fd64c24f0", argdata, 2, 6, &func);
}

FUNC_NAKED void TextButton::SetInactiveColor(GL_Color color)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has this
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1214::func)
		 : "rdi"
	);
}

namespace _func1215
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x2ff};
	static FunctionDefinition funcObj("TextButton::SetActiveColor", typeid(void (TextButton::*)(GL_Color )), ".!80bf8000000000660fd64c24f0", argdata, 2, 6, &func);
}

FUNC_NAKED void TextButton::SetActiveColor(GL_Color color)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has this
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1215::func)
		 : "rdi"
	);
}

namespace _func1216
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x2ff};
	static FunctionDefinition funcObj("TextButton::SetSelectedColor", typeid(void (TextButton::*)(GL_Color )), ".!80bf8000000000660fd64c24f0", argdata, 2, 6, &func);
}

FUNC_NAKED void TextButton::SetSelectedColor(GL_Color color)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has this
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1216::func)
		 : "rdi"
	);
}

namespace _func1217
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x2ff};
	static FunctionDefinition funcObj("TextButton::SetTextColor", typeid(void (TextButton::*)(GL_Color )), ".80bf8000000000660fd64c24f8", argdata, 2, 6, &func);
}

FUNC_NAKED void TextButton::SetTextColor(GL_Color color)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// color
		"pushq 8(%%rbp)\n\t"		// color
			// rdi has this
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1217::func)
		 : "rdi"
	);
}

namespace _func1218
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TextButton::InitPrimitives", typeid(void (TextButton::*)()), "415741564989fe4155415455534881ecb800000080bf8000000000", argdata, 1, 6, &func);
}

FUNC_NAKED void TextButton::InitPrimitives()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1218::func)
		 : "rdi"
	);
}

namespace _func1219
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("TextInput::constructor", typeid(void (TextInput::*)(int , TextInput::AllowedCharType , const std::string &)), "!41544189d45589f54889ce534889fb", argdata, 4, 6, &func);
}

FUNC_NAKED void TextInput::constructor(int maxChars, TextInput::AllowedCharType allowedCharType, const std::string &prompt)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has maxChars
			// rdx has allowedCharType
			// rcx has prompt
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1219::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func1220
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("TextInput::OnRender", typeid(void (TextInput::*)(int , Point )), ".4156b9ffffffff41554189f54889fe41544989d431d255534889fb4883ec70", argdata, 3, 6, &func);
}

FUNC_NAKED void TextInput::OnRender(int font, Point pos)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has font
			// rdx has pos
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1220::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1221
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TextInput::OnLoop", typeid(void (TextInput::*)()), ".!538b473839473c", argdata, 1, 6, &func);
}

FUNC_NAKED void TextInput::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1221::func)
		 : "rdi"
	);
}

namespace _func1222
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("TextInput::OnTextEvent", typeid(void (TextInput::*)(CEvent::TextEvent )), ".53807f40004889fb", argdata, 2, 6, &func);
}

FUNC_NAKED void TextInput::OnTextEvent(CEvent::TextEvent event)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has event
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1222::func)
		 : "rdi", "rsi"
	);
}

namespace _func1223
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TextInput::GetActive", typeid(bool (TextInput::*)()), ".!0fb64740c3", argdata, 1, 2, &func);
}

FUNC_NAKED bool TextInput::GetActive()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1223::func)
		 : "rdi"
	);
}

namespace _func1224
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("TextInput::GetText", typeid(std::string (TextInput::*)()), ".53b9ffffffff4889fb31d2", argdata, 2, 2, &func);
}

FUNC_NAKED std::string TextInput::GetText()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1224::func)
		 : "rdi", "rsi"
	);
}

namespace _func1225
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TextInput::Start", typeid(void (TextInput::*)()), ".534883ec30488b4710482b4708", argdata, 1, 6, &func);
}

FUNC_NAKED void TextInput::Start()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1225::func)
		 : "rdi"
	);
}

namespace _func1226
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TextInput::Stop", typeid(void (TextInput::*)()), ".!c6474000", argdata, 1, 6, &func);
}

FUNC_NAKED void TextInput::Stop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1226::func)
		 : "rdi"
	);
}

namespace _func1227
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("TextInput::SetText", typeid(int (TextInput::*)(const std::string &)), ".55488d6f08534889fb4883ec28", argdata, 2, 2, &func);
}

FUNC_NAKED int TextInput::SetText(const std::string &text)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has text
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1227::func)
		 : "rdi", "rsi"
	);
}

namespace _func1228
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("TextInput::OnTextInput", typeid(void (TextInput::*)(int )), ".41564155415455534889fb4883ec30807f4000", argdata, 2, 6, &func);
}

FUNC_NAKED void TextInput::OnTextInput(int asciiChar)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has asciiChar
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1228::func)
		 : "rdi", "rsi"
	);
}

namespace _func1229
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("TextLibrary::GetText", typeid(std::string (TextLibrary::*)(const std::string &, const std::string &)), "41574156415541544989fc5553488d5e384883ec48", argdata, 4, 2, &func);
}

FUNC_NAKED std::string TextLibrary::GetText(const std::string &name, const std::string &lang)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has name
			// rcx has lang
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1229::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func1230
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("TextString::GetText", typeid(std::string (TextString::*)()), "53807e08004889fb", argdata, 2, 2, &func);
}

FUNC_NAKED std::string TextString::GetText()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1230::func)
		 : "rdi", "rsi"
	);
}

namespace _func1231
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("TimerHelper::Start", typeid(void (TimerHelper::*)(int )), "83feffc6471101c7470800000000", argdata, 2, 6, &func);
}

FUNC_NAKED void TimerHelper::Start(int goal)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has goal
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1231::func)
		 : "rdi", "rsi"
	);
}

namespace _func1232
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TimerHelper::Running", typeid(bool (TimerHelper::*)()), "!.0fb64711c3", argdata, 1, 2, &func);
}

FUNC_NAKED bool TimerHelper::Running()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1232::func)
		 : "rdi"
	);
}

namespace _func1233
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("TimerHelper::ResetMinMax", typeid(void (TimerHelper::*)(int , int )), ".8917897704", argdata, 3, 6, &func);
}

FUNC_NAKED void TimerHelper::ResetMinMax(int min, int max)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has min
			// rdx has max
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1233::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1234
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("TimerHelper::SetMaxTime", typeid(void (TimerHelper::*)(float )), ".f30f104f08f30f5e4f0c", argdata, 2, 6, &func);
}

FUNC_NAKED void TimerHelper::SetMaxTime(float max)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has max
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1234::func)
		 : "rdi", "xmm0"
	);
}

namespace _func1235
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TimerHelper::Stop", typeid(void (TimerHelper::*)()), "!.c6471100c3", argdata, 1, 6, &func);
}

FUNC_NAKED void TimerHelper::Stop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1235::func)
		 : "rdi"
	);
}

namespace _func1236
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TimerHelper::Update", typeid(void (TimerHelper::*)()), ".53807f11004889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void TimerHelper::Update()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1236::func)
		 : "rdi"
	);
}

namespace _func1237
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TimerHelper::Done", typeid(bool (TimerHelper::*)()), ".0fb6471184c0", argdata, 1, 2, &func);
}

FUNC_NAKED bool TimerHelper::Done()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1237::func)
		 : "rdi"
	);
}

namespace _func1238
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TutorialManager::constructor", typeid(void (TutorialManager::*)()), "534889fb488d7f084883ec10c647f800", argdata, 1, 6, &func);
}

FUNC_NAKED void TutorialManager::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1238::func)
		 : "rdi"
	);
}

namespace _func1239
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("TutorialManager::Running", typeid(bool (TutorialManager::*)()), "!.0fb607c3", argdata, 1, 2, &func);
}

FUNC_NAKED bool TutorialManager::Running()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1239::func)
		 : "rdi"
	);
}

namespace _func1240
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108, 0x109, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TutorialManager::OnInit", typeid(void (TutorialManager::*)(ShipManager *, CommandGui *, CrewControl *, Upgrades *, CombatControl *, SystemControl *, TabbedWindow *)), ".415455534889fb4883ec404889b790010000", argdata, 8, 6, &func);
}

FUNC_NAKED void TutorialManager::OnInit(ShipManager *ship, CommandGui *gui, CrewControl *crewControl, Upgrades *upgradesScreen, CombatControl *combatControl, SystemControl *sysControl, TabbedWindow *unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// unk
		"pushq 8(%%rbp)\n\t"		// sysControl
			// rdi has this
			// rsi has ship
			// rdx has gui
			// rcx has crewControl
			// r8 has upgradesScreen
			// r9 has combatControl
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1240::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8", "r9"
	);
}

TutorialManager *Global_TutorialManager_Tutorial;

namespace _var1241
{
	static VariableDefinition varObj("Global_TutorialManager_Tutorial", "!498b07488b7810488b07ff908000000084c00f84????????bf(???????\?)", &Global_TutorialManager_Tutorial);
}

namespace _func1242
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("UnlockArrow::constructor", typeid(void (UnlockArrow::*)(Point , int , int )), "554889f5534889fb4883ec28803d????????00", argdata, 4, 6, &func);
}

FUNC_NAKED void UnlockArrow::constructor(Point pos, int unk1, int unk2)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
			// rdx has unk1
			// rcx has unk2
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1242::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func1243
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("UnlockArrow::MouseMove", typeid(bool (UnlockArrow::*)(int , int )), ".837f0403", argdata, 3, 2, &func);
}

FUNC_NAKED bool UnlockArrow::MouseMove(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1243::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1244
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("UnlockArrow::OnRender", typeid(void (UnlockArrow::*)()), ".534889fb4883ec308b0785c0", argdata, 1, 6, &func);
}

FUNC_NAKED void UnlockArrow::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1244::func)
		 : "rdi"
	);
}

namespace _func1245
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("UpgradeBox::OnRender", typeid(void (UpgradeBox::*)()), "415741564989fe4155415455534881ecd801000080bf5901000000", argdata, 1, 6, &func);
}

FUNC_NAKED void UpgradeBox::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1245::func)
		 : "rdi"
	);
}

namespace _func1246
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("UpgradeBox::MouseMove", typeid(void (UpgradeBox::*)(int , int )), ".48833f007412", argdata, 3, 6, &func);
}

FUNC_NAKED void UpgradeBox::MouseMove(int mX, int mY)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mX
			// rdx has mY
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1246::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1247
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("UpgradeBox::MouseClick", typeid(void (UpgradeBox::*)(int , int )), ".534889fb4883ec20488b074885c0", argdata, 3, 6, &func);
}

FUNC_NAKED void UpgradeBox::MouseClick(int mX, int mY)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mX
			// rdx has mY
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1247::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1248
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("UpgradeBox::MouseRightClick", typeid(void (UpgradeBox::*)(int , int )), ".534889fb4883ec20488b074885c0", argdata, 3, 6, &func);
}

FUNC_NAKED void UpgradeBox::MouseRightClick(int mX, int mY)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mX
			// rdx has mY
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1248::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1249
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("UpgradeBox::Undo", typeid(void (UpgradeBox::*)()), ".538b47204889fb85c0", argdata, 1, 6, &func);
}

FUNC_NAKED void UpgradeBox::Undo()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1249::func)
		 : "rdi"
	);
}

namespace _func1250
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("UpgradeBox::Accept", typeid(void (UpgradeBox::*)()), ".534889fb4883ec20488b3f4885ff", argdata, 1, 6, &func);
}

FUNC_NAKED void UpgradeBox::Accept()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1250::func)
		 : "rdi"
	);
}

namespace _func1251
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("UpgradeBox::constructorEmpty", typeid(void (UpgradeBox::*)(Point , bool )), ".41554189d541544989f449c1fc20554889f5534889fb488d7f384883ec38", argdata, 3, 6, &func);
}

FUNC_NAKED void UpgradeBox::constructorEmpty(Point pos, bool subsystem)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
			// rdx has subsystem
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1251::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1252
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("UpgradeBox::constructorSystem", typeid(void (UpgradeBox::*)(ShipManager *, ShipSystem *, Point , bool )), ".41574589c741564c8d773841554989cd41544989d455488dafc8000000534889fb4883ec38", argdata, 5, 6, &func);
}

FUNC_NAKED void UpgradeBox::constructorSystem(ShipManager *ship, ShipSystem *sys, Point pos, bool subsystem)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ship
			// rdx has sys
			// rcx has pos
			// r8 has subsystem
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1252::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func1253
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("UpgradeBox::destructor", typeid(void (UpgradeBox::*)()), ".534889fb4883ec10488bbf60010000", argdata, 1, 6, &func);
}

FUNC_NAKED void UpgradeBox::destructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1253::func)
		 : "rdi"
	);
}

namespace _func1254
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("Upgrades::MouseMove", typeid(void (Upgrades::*)(int , int )), "!41554989fd41544189d45589f55331db4883ec08", argdata, 3, 6, &func);
}

FUNC_NAKED void Upgrades::MouseMove(int mX, int mY)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mX
			// rdx has mY
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1254::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1255
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("Upgrades::MouseRightClick", typeid(void (Upgrades::*)(int , int )), ".415431c94989fc5531ed534883ec20", argdata, 3, 6, &func);
}

FUNC_NAKED void Upgrades::MouseRightClick(int mX, int mY)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mX
			// rdx has mY
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1255::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1256
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Upgrades::Close", typeid(void (Upgrades::*)()), ".41554154554889fd534883ec28807f0800", argdata, 1, 6, &func);
}

FUNC_NAKED void Upgrades::Close()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1256::func)
		 : "rdi"
	);
}

namespace _func1257
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Upgrades::OnLoop", typeid(void (Upgrades::*)()), ".4155415455534889fb4883ec68807f0800", argdata, 1, 6, &func);
}

FUNC_NAKED void Upgrades::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1257::func)
		 : "rdi"
	);
}

namespace _func1258
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Upgrades::ConfirmUpgrades", typeid(void (Upgrades::*)()), ".415531c941bd????????41544989fc5531ed534883ec28", argdata, 1, 6, &func);
}

FUNC_NAKED void Upgrades::ConfirmUpgrades()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1258::func)
		 : "rdi"
	);
}

namespace _func1259
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("Upgrades::MouseClick", typeid(void (Upgrades::*)(int , int )), ".41554189d541544189f4554889fd5331db4883ec28", argdata, 3, 6, &func);
}

FUNC_NAKED void Upgrades::MouseClick(int mX, int mY)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has mX
			// rdx has mY
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1259::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1260
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Upgrades::ClearUpgradeBoxes", typeid(void (Upgrades::*)()), ".41544989fc55534883ec10488b4f30488b57284889c84829d048c1f80385c0", argdata, 1, 6, &func);
}

FUNC_NAKED void Upgrades::ClearUpgradeBoxes()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1260::func)
		 : "rdi"
	);
}

namespace _func1261
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("Upgrades::OnInit", typeid(void (Upgrades::*)(ShipManager *)), ".41574989ff41564155415455534881ecb8000000", argdata, 2, 6, &func);
}

FUNC_NAKED void Upgrades::OnInit(ShipManager *ship)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ship
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1261::func)
		 : "rdi", "rsi"
	);
}

namespace _func1262
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("Upgrades::OnRender", typeid(void (Upgrades::*)()), ".415455534889fb4883ec50488b7f20", argdata, 1, 6, &func);
}

FUNC_NAKED void Upgrades::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1262::func)
		 : "rdi"
	);
}

namespace _func1263
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("WarningMessage::RenderWithAlpha", typeid(void (WarningMessage::*)(float )), "41570f28f041564155415455534889fb4883ec48", argdata, 2, 6, &func);
}

FUNC_NAKED void WarningMessage::RenderWithAlpha(float alpha)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has alpha
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1263::func)
		 : "rdi", "xmm0"
	);
}

namespace _func1264
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WarningMessage::constructor", typeid(void (WarningMessage::*)()), ".0f57c0534889fb488d7f2831d24883ec20", argdata, 1, 6, &func);
}

FUNC_NAKED void WarningMessage::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1264::func)
		 : "rdi"
	);
}

namespace _func1265
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x10a, 0x101};
	static FunctionDefinition funcObj("WarningMessage::InitImage", typeid(void (WarningMessage::*)(const std::string &, Point , float , bool )), ".41564189ce415541544989f4554889d5534889fb488dbfa80000004c8d6b604883ec10", argdata, 5, 6, &func);
}

FUNC_NAKED void WarningMessage::InitImage(const std::string &imageName, Point position, float time, bool flash)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has imageName
			// rdx has position
			// xmm0 has time
			// rcx has flash
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1265::func)
		 : "rdi", "rsi", "rdx", "xmm0", "rcx"
	);
}

namespace _func1266
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x10a, 0x2ff, 0x101, 0x108};
	static FunctionDefinition funcObj("WarningMessage::InitText", typeid(void (WarningMessage::*)(const TextString &, Point , float , GL_Color , bool , bool )), ".41574589c741564189ce41554154554889f5534889fb488d7f384883ec28", argdata, 7, 6, &func);
}

FUNC_NAKED void WarningMessage::InitText(const TextString &text, Point position, float time, GL_Color textColor, bool centerText, bool flash)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// textColor
		"pushq 8(%%rbp)\n\t"		// textColor
			// rdi has this
			// rsi has text
			// rdx has position
			// xmm0 has time
			// rcx has centerText
			// r8 has flash
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1266::func)
		 : "rdi", "rsi", "rdx", "xmm0", "rcx", "r8"
	);
}

namespace _func1267
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WarningMessage::OnLoop", typeid(void (WarningMessage::*)()), ".55488d6f08534889fb4889ef4883ec08", argdata, 1, 6, &func);
}

FUNC_NAKED void WarningMessage::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1267::func)
		 : "rdi"
	);
}

namespace _func1268
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WarningMessage::OnRender", typeid(void (WarningMessage::*)()), ".53807f1e004889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void WarningMessage::OnRender()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1268::func)
		 : "rdi"
	);
}

namespace _func1269
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WarningMessage::SetImage", typeid(void (WarningMessage::*)(const std::string &)), ".4155415455534889fb4883ec08807f3000", argdata, 2, 6, &func);
}

FUNC_NAKED void WarningMessage::SetImage(const std::string &imageName)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has imageName
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1269::func)
		 : "rdi", "rsi"
	);
}

namespace _func1270
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WarningMessage::SetText", typeid(void (WarningMessage::*)(const TextString &)), ".4155415455534889fb4883ec08807f3000", argdata, 2, 6, &func);
}

FUNC_NAKED void WarningMessage::SetText(const TextString &text)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has text
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1270::func)
		 : "rdi", "rsi"
	);
}

namespace _func1271
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x2ff};
	static FunctionDefinition funcObj("WarningMessage::SetText", typeid(void (WarningMessage::*)(const TextString &, GL_Color )), ".415741564155415455534889fb4883ec18807f3000", argdata, 3, 6, &func);
}

FUNC_NAKED void WarningMessage::SetText(const TextString &text, GL_Color textColor)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// textColor
		"pushq 8(%%rbp)\n\t"		// textColor
			// rdi has this
			// rsi has text
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1271::func)
		 : "rdi", "rsi"
	);
}

namespace _func1272
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WarningMessage::SetPosition", typeid(void (WarningMessage::*)(Point )), ".807f300048897728", argdata, 2, 6, &func);
}

FUNC_NAKED void WarningMessage::SetPosition(Point position)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has position
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1272::func)
		 : "rdi", "rsi"
	);
}

namespace _func1273
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WarningMessage::SetLoop", typeid(void (WarningMessage::*)(bool )), "!.0f57c0400fb6f64883c708", argdata, 2, 6, &func);
}

FUNC_NAKED void WarningMessage::SetLoop(bool loop)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has loop
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1273::func)
		 : "rdi", "rsi"
	);
}

namespace _func1274
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WarningMessage::SetSound", typeid(void (WarningMessage::*)(const std::string &)), "!.4881c7b8000000", argdata, 2, 6, &func);
}

FUNC_NAKED void WarningMessage::SetSound(const std::string &sound)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has sound
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1274::func)
		 : "rdi", "rsi"
	);
}

namespace _func1275
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WarningMessage::Start", typeid(void (WarningMessage::*)()), ".53807f1c004889fb", argdata, 1, 6, &func);
}

FUNC_NAKED void WarningMessage::Start()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1275::func)
		 : "rdi"
	);
}

namespace _func1276
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WeaponAnimation::StartFire", typeid(bool (WeaponAnimation::*)()), "530fb687c10000004889fb84c0", argdata, 1, 2, &func);
}

FUNC_NAKED bool WeaponAnimation::StartFire()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1276::func)
		 : "rdi"
	);
}

namespace _func1277
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("WeaponAnimation::SetFireTime", typeid(void (WeaponAnimation::*)(float )), "8b470889c22b97c8000000", argdata, 2, 6, &func);
}

FUNC_NAKED void WeaponAnimation::SetFireTime(float time)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has time
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1277::func)
		 : "rdi", "xmm0"
	);
}

namespace _func1278
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WeaponAnimation::Update", typeid(void (WeaponAnimation::*)()), "415455534889fb4883ec1080bfc100000000", argdata, 1, 6, &func);
}

FUNC_NAKED void WeaponAnimation::Update()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1278::func)
		 : "rdi"
	);
}

namespace _func1279
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a};
	static FunctionDefinition funcObj("WeaponBlueprint::RenderIcon", typeid(void (WeaponBlueprint::*)(float )), "!488db738010000", argdata, 2, 6, &func);
}

FUNC_NAKED void WeaponBlueprint::RenderIcon(float scale)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// xmm0 has scale
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1279::func)
		 : "rdi", "xmm0"
	);
}

namespace _func1280
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("WeaponBlueprint::GetDescription", typeid(std::string (WeaponBlueprint::*)(bool )), ".4157415641554989fd4154554889f5534881ec08010000", argdata, 3, 2, &func);
}

FUNC_NAKED std::string WeaponBlueprint::GetDescription(bool tooltip)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has implicit_output
			// rsi has this
			// rdx has tooltip
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1280::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1281
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WeaponBlueprint::constructor", typeid(void (WeaponBlueprint::*)()), ".534889fb488d7f08be????????4883ec20", argdata, 1, 6, &func);
}

FUNC_NAKED void WeaponBlueprint::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1281::func)
		 : "rdi"
	);
}

namespace _func1282
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WeaponBlueprint::destructor", typeid(void (WeaponBlueprint::*)()), ".4154554889fd534883ec10488b8788010000", argdata, 1, 6, &func);
}

FUNC_NAKED void WeaponBlueprint::destructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1282::func)
		 : "rdi"
	);
}

namespace _func1283
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("WeaponBox::RenderBox", typeid(void (WeaponBox::*)(bool , bool )), "41570fb6d2400fb6f641564155415455534889fb4881ec68030000", argdata, 3, 6, &func);
}

FUNC_NAKED void WeaponBox::RenderBox(bool dragging, bool flashPowerBox)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has dragging
			// rdx has flashPowerBox
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1283::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1284
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x107};
	static FunctionDefinition funcObj("WeaponBox::GenerateTooltip", typeid(std::string (WeaponBox::*)()), "554889f5534889fb4889f74883ec38488b06", argdata, 2, 2, &func);
}

FUNC_NAKED std::string WeaponBox::GenerateTooltip()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"subq $8, %%rsp\n\t"
		"pushq 8(%%rbp)\n\t"		// implicit_output
			// rdi has this
		"call *%0\n\t"
		"addq $8, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1284::func)
		 : "rdi"
	);
}

namespace _func1285
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WeaponControl::constructor", typeid(void (WeaponControl::*)()), "4157be03000000415641554989fd415455498dad3802000053498d9d180300004881ec58030000", argdata, 1, 6, &func);
}

FUNC_NAKED void WeaponControl::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1285::func)
		 : "rdi"
	);
}

namespace _func1286
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("WeaponControl::SetAutofiring", typeid(void (WeaponControl::*)(bool , bool )), ".41554189d54154554889fd534883ec484084f64088b7e0000000", argdata, 3, 6, &func);
}

FUNC_NAKED void WeaponControl::SetAutofiring(bool on, bool simple)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has on
			// rdx has simple
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1286::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1287
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("WeaponControl::Fire", typeid(void (WeaponControl::*)(std::vector<Pointf> &, int , bool )), ".4155415455534889fb4883ec28488bbfd80000004885ff", argdata, 4, 6, &func);
}

FUNC_NAKED void WeaponControl::Fire(std::vector<Pointf> &points, int target, bool autoFire)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has points
			// rdx has target
			// rcx has autoFire
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1287::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func1288
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WeaponControl::OnRender", typeid(void (WeaponControl::*)(bool )), ".41545589f5be03000000534889fb4883ec10488b7f18", argdata, 2, 6, &func);
}

FUNC_NAKED void WeaponControl::OnRender(bool unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1288::func)
		 : "rdi", "rsi"
	);
}

namespace _func1289
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("WeaponControl::LButton", typeid(bool (WeaponControl::*)(int , int , bool )), ".80bf30010000007427530fb69f3101000084db", argdata, 4, 2, &func);
}

FUNC_NAKED bool WeaponControl::LButton(int x, int y, bool holdingShift)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
			// rcx has holdingShift
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1289::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func1290
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("WeaponControl::MouseMove", typeid(void (WeaponControl::*)(int , int )), ".41544189d45589f5534889fb", argdata, 3, 6, &func);
}

FUNC_NAKED void WeaponControl::MouseMove(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1290::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1291
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WeaponControl::KeyDown", typeid(bool (WeaponControl::*)(SDLKey )), ".4155415441bc010000005589f5534889fb4883ec28", argdata, 2, 2, &func);
}

FUNC_NAKED bool WeaponControl::KeyDown(SDLKey key)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has key
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1291::func)
		 : "rdi", "rsi"
	);
}

namespace _func1292
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WeaponControl::LinkShip", typeid(void (WeaponControl::*)(ShipManager *)), ".55534889fb4883ec28", argdata, 2, 6, &func);
}

FUNC_NAKED void WeaponControl::LinkShip(ShipManager *ship)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ship
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1292::func)
		 : "rdi", "rsi"
	);
}

namespace _func1293
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("WeaponStoreBox::__DO_NOT_HOOK", typeid(void (*)()), "41554989d541544989f4be", argdata, 0, 4, &func);
}

FUNC_NAKED void WeaponStoreBox::__DO_NOT_HOOK()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1293::func)
	);
}

namespace _func1294
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("WeaponStoreBox::constructor", typeid(void (WeaponStoreBox::*)(ShipManager *, Equipment *, const WeaponBlueprint *)), ".41554989d541544989f4be", argdata, 4, 6, &func);
}

FUNC_NAKED void WeaponStoreBox::constructor(ShipManager *ship, Equipment *equip, const WeaponBlueprint *weaponBp)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ship
			// rdx has equip
			// rcx has weaponBp
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1294::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func1295
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WeaponSystem::RemoveWeapon", typeid(void (WeaponSystem::*)(int )), "31c085f60f88d800000041564155415455534889fb4883ec20", argdata, 2, 6, &func);
}

FUNC_NAKED void WeaponSystem::RemoveWeapon(int slot)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has slot
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1295::func)
		 : "rdi", "rsi"
	);
}

namespace _func1296
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("WeaponSystem::SetBonusPower", typeid(void (WeaponSystem::*)(int , int )), ".5589f5534889fb4883ec08e8????????39e8", argdata, 3, 6, &func);
}

FUNC_NAKED void WeaponSystem::SetBonusPower(int amount, int permanentPower)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has amount
			// rdx has permanentPower
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1296::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1297
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WeaponSystem::OnLoop", typeid(void (WeaponSystem::*)()), ".415741564155415455534889fb4883ec38e8????????488b9350020000", argdata, 1, 6, &func);
}

FUNC_NAKED void WeaponSystem::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1297::func)
		 : "rdi"
	);
}

namespace _func1298
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("WeaponSystemBox::constructor", typeid(void (WeaponSystemBox::*)(Point , ShipSystem *, WeaponControl *)), "554889cdb901000000534889fb4883ec08e8????????488dbb70020000", argdata, 4, 6, &func);
}

FUNC_NAKED void WeaponSystemBox::constructor(Point pos, ShipSystem *sys, WeaponControl *weapCtrl)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has pos
			// rdx has sys
			// rcx has weapCtrl
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1298::func)
		 : "rdi", "rsi", "rdx", "rcx"
	);
}

namespace _func1299
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102, 0x101, 0x108};
	static FunctionDefinition funcObj("WindowFrame::constructor", typeid(void (WindowFrame::*)(int , int , int , int )), "41574156415541545589d55389f34881ecc8000000", argdata, 5, 6, &func);
}

FUNC_NAKED void WindowFrame::constructor(int x, int y, int w, int h)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
			// rcx has w
			// r8 has h
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1299::func)
		 : "rdi", "rsi", "rdx", "rcx", "r8"
	);
}

namespace _func1300
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WindowFrame::destructor", typeid(void (WindowFrame::*)()), "!.534889fb488b7f10", argdata, 1, 6, &func);
}

FUNC_NAKED void WindowFrame::destructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1300::func)
		 : "rdi"
	);
}

namespace _func1301
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("WindowFrame::Draw", typeid(void (WindowFrame::*)(int , int )), ".41544189d45589f5534889fb", argdata, 3, 6, &func);
}

FUNC_NAKED void WindowFrame::Draw(int x, int y)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has x
			// rdx has y
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1301::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1302
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WindowFrame::DrawMask", typeid(void (WindowFrame::*)(int )), ".5389f24889fbbf01000000", argdata, 2, 6, &func);
}

FUNC_NAKED void WindowFrame::DrawMask(int unk)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has unk
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1302::func)
		 : "rdi", "rsi"
	);
}

namespace _func1303
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WorldManager::constructor", typeid(void (WorldManager::*)()), "534889fb488d7f104883ec10", argdata, 1, 6, &func);
}

FUNC_NAKED void WorldManager::constructor()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1303::func)
		 : "rdi"
	);
}

namespace _func1304
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WorldManager::OnInit", typeid(int (WorldManager::*)()), ".415455488d6f10534889fb4889ef", argdata, 1, 2, &func);
}

FUNC_NAKED int WorldManager::OnInit()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1304::func)
		 : "rdi"
	);
}

namespace _func1305
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WorldManager::CreateStore", typeid(void (WorldManager::*)(LocationEvent *)), ".554889f5534889fb4883ec08488bb6d0040000", argdata, 2, 6, &func);
}

FUNC_NAKED void WorldManager::CreateStore(LocationEvent *event)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has event
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1305::func)
		 : "rdi", "rsi"
	);
}

namespace _func1306
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("WorldManager::CheckRequirements", typeid(bool (WorldManager::*)(LocationEvent *, bool )), ".415455534889f34883ec204885f6", argdata, 3, 2, &func);
}

FUNC_NAKED bool WorldManager::CheckRequirements(LocationEvent *event, bool hidden)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has event
			// rdx has hidden
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1306::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1307
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WorldManager::AddBoarders", typeid(bool (WorldManager::*)(BoardingEvent &)), ".4154554889fd534883ec20488b07488b5010", argdata, 2, 2, &func);
}

FUNC_NAKED bool WorldManager::AddBoarders(BoardingEvent &boardingEvent)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has boardingEvent
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1307::func)
		 : "rdi", "rsi"
	);
}

namespace _func1308
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WorldManager::HostileEnvironment", typeid(bool (WorldManager::*)()), ".534889fb488d7f10", argdata, 1, 2, &func);
}

FUNC_NAKED bool WorldManager::HostileEnvironment()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1308::func)
		 : "rdi"
	);
}

namespace _func1309
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("WorldManager::ModifyEnvironment", typeid(void (WorldManager::*)(int , int )), ".83fe01534889fb", argdata, 3, 6, &func);
}

FUNC_NAKED void WorldManager::ModifyEnvironment(int envFlag, int envTarget)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has envFlag
			// rdx has envTarget
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1309::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1310
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x2ff, 0x101, 0x108};
	static FunctionDefinition funcObj("WorldManager::ModifyStatusEffect", typeid(void (WorldManager::*)(StatusEffect , ShipManager *, int )), ".41554889d04989fd48c1f82041544989cc4889f148c1f920", argdata, 4, 6, &func);
}

FUNC_NAKED void WorldManager::ModifyStatusEffect(StatusEffect effect, ShipManager *target, int targetType)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
		"pushq 16(%%rbp)\n\t"		// effect
		"pushq 8(%%rbp)\n\t"		// effect
			// rdi has this
			// rcx has target
			// r8 has targetType
		"call *%0\n\t"
		"addq $16, %%rsp\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1310::func)
		 : "rdi", "rcx", "r8"
	);
}

namespace _func1311
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WorldManager::ModifyResources", typeid(LocationEvent *(WorldManager::*)(LocationEvent *)), ".41574989f7488db65803000041564d8db78803000041554154554889fd534881ecd8020000", argdata, 2, 2, &func);
}

FUNC_NAKED LocationEvent *WorldManager::ModifyResources(LocationEvent *event)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has event
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1311::func)
		 : "rdi", "rsi"
	);
}

namespace _func1312
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WorldManager::CheckStatusEffects", typeid(void (WorldManager::*)(std::vector<StatusEffect> &)), "!.415741564989fe41554531ed41544c8da7001500005531ed534889f34883ec08", argdata, 2, 6, &func);
}

FUNC_NAKED void WorldManager::CheckStatusEffects(std::vector<StatusEffect> &vec)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has vec
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1312::func)
		 : "rdi", "rsi"
	);
}

namespace _func1313
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WorldManager::CreateChoiceBox", typeid(void (WorldManager::*)(LocationEvent *)), ".4157488d87501500004989ff41564889c741554154554889f5534889c34881ec08030000", argdata, 2, 6, &func);
}

FUNC_NAKED void WorldManager::CreateChoiceBox(LocationEvent *event)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has event
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1313::func)
		 : "rdi", "rsi"
	);
}

namespace _func1314
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WorldManager::CreateChoiceBox0", typeid(void (WorldManager::*)(LocationEvent *)), ".554889f5534889fb4883ec08488b07488b7810488b17", argdata, 2, 6, &func);
}

FUNC_NAKED void WorldManager::CreateChoiceBox0(LocationEvent *event)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has event
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1314::func)
		 : "rdi", "rsi"
	);
}

namespace _func1315
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106, 0x102};
	static FunctionDefinition funcObj("WorldManager::CreateShip", typeid(CompleteShip *(WorldManager::*)(ShipEvent *, bool )), ".4156415541544989fc55534881ec60030000", argdata, 3, 2, &func);
}

FUNC_NAKED CompleteShip *WorldManager::CreateShip(ShipEvent *shipEvent, bool boss)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has shipEvent
			// rdx has boss
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1315::func)
		 : "rdi", "rsi", "rdx"
	);
}

namespace _func1316
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WorldManager::CreateLocation", typeid(void (WorldManager::*)(Location *)), ".41574156415541544989f455534889fb4881ecf8030000", argdata, 2, 6, &func);
}

FUNC_NAKED void WorldManager::CreateLocation(Location *loc)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has loc
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1316::func)
		 : "rdi", "rsi"
	);
}

namespace _func1317
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WorldManager::UpdateLocation", typeid(void (WorldManager::*)(LocationEvent *)), ".4157415641554154554889fd534889f34881ec88030000", argdata, 2, 6, &func);
}

FUNC_NAKED void WorldManager::UpdateLocation(LocationEvent *event)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has event
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1317::func)
		 : "rdi", "rsi"
	);
}

namespace _func1318
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WorldManager::UpdateLocation0", typeid(void (WorldManager::*)(LocationEvent *)), ".554889f5534889fb4883ec08488b07488b7810488b17", argdata, 2, 6, &func);
}

FUNC_NAKED void WorldManager::UpdateLocation0(LocationEvent *event)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has event
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1318::func)
		 : "rdi", "rsi"
	);
}

namespace _func1319
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WorldManager::ClearLocation", typeid(void (WorldManager::*)()), ".415741564155415455534889fb488d7f104881ec68020000", argdata, 1, 6, &func);
}

FUNC_NAKED void WorldManager::ClearLocation()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1319::func)
		 : "rdi"
	);
}

namespace _func1320
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WorldManager::LoadGame", typeid(void (WorldManager::*)(const std::string &)), ".415741564155415455534889fb4881ece8010000", argdata, 2, 6, &func);
}

FUNC_NAKED void WorldManager::LoadGame(const std::string &fileName)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has fileName
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1320::func)
		 : "rdi", "rsi"
	);
}

namespace _func1321
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WorldManager::SaveGame", typeid(void (WorldManager::*)()), ".415455534889fb4883ec20488bbfb8110000", argdata, 1, 6, &func);
}

FUNC_NAKED void WorldManager::SaveGame()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1321::func)
		 : "rdi"
	);
}

namespace _func1322
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WorldManager::CreateNewGame", typeid(void (WorldManager::*)()), ".554889fd5331db4883ec28488b07488b78104881c718010000", argdata, 1, 6, &func);
}

FUNC_NAKED void WorldManager::CreateNewGame()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1322::func)
		 : "rdi"
	);
}

namespace _func1323
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("WorldManager::StartGame", typeid(void (WorldManager::*)(ShipManager *)), ".4154554889f5534889fb4883ec20", argdata, 2, 6, &func);
}

FUNC_NAKED void WorldManager::StartGame(ShipManager *ship)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
			// rsi has ship
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1323::func)
		 : "rdi", "rsi"
	);
}

namespace _func1324
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WorldManager::Restart", typeid(void (WorldManager::*)()), "!.534889fbe8????????e8????????e8", argdata, 1, 6, &func);
}

FUNC_NAKED void WorldManager::Restart()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1324::func)
		 : "rdi"
	);
}

namespace _func1325
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WorldManager::OnLoop", typeid(void (WorldManager::*)()), ".415731f64989ff41564155415455534881ecf8000000", argdata, 1, 6, &func);
}

FUNC_NAKED void WorldManager::OnLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1325::func)
		 : "rdi"
	);
}

namespace _func1326
{
	static void *func = 0;
	static short argdata[] = {0x107};
	static FunctionDefinition funcObj("WorldManager::PauseLoop", typeid(void (WorldManager::*)()), ".41554154554889fd534883ec28488b3f", argdata, 1, 6, &func);
}

FUNC_NAKED void WorldManager::PauseLoop()
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has this
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1326::func)
		 : "rdi"
	);
}

namespace _func1327
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b, 0x106, 0x102};
	static FunctionDefinition funcObj("freetype::easy_measurePrintLines", typeid(Pointf (*)(int , float , float , int , const std::string &)), "554889d089fd5389f34883ec38", argdata, 5, 2, &func);
}

FUNC_NAKED Pointf freetype::easy_measurePrintLines(int fontSize, float x, float y, int line_length, const std::string &text)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has fontSize
			// xmm0 has x
			// xmm1 has y
			// rsi has line_length
			// rdx has text
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1327::func)
		 : "rdi", "xmm0", "xmm1", "rsi", "rdx"
	);
}

namespace _func1328
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x106};
	static FunctionDefinition funcObj("freetype::easy_measureWidth", typeid(int (*)(int , const std::string &)), ".5389fb4883ec30488b36488d54241e", argdata, 2, 2, &func);
}

FUNC_NAKED int freetype::easy_measureWidth(int fontSize, const std::string &text)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has fontSize
			// rsi has text
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1328::func)
		 : "rdi", "rsi"
	);
}

namespace _func1329
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b, 0x106};
	static FunctionDefinition funcObj("freetype::easy_print", typeid(Pointf (*)(int , float , float , const std::string &)), ".5389fb4883ec30488b36488d54241e", argdata, 4, 2, &func);
}

FUNC_NAKED Pointf freetype::easy_print(int fontSize, float x, float y, const std::string &text)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has fontSize
			// xmm0 has x
			// xmm1 has y
			// rsi has text
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1329::func)
		 : "rdi", "xmm0", "xmm1", "rsi"
	);
}

namespace _func1330
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b, 0x106};
	static FunctionDefinition funcObj("freetype::easy_printRightAlign", typeid(Pointf (*)(int , float , float , const std::string &)), ".5389fb4883ec30488b36488d54241e", argdata, 4, 2, &func);
}

FUNC_NAKED Pointf freetype::easy_printRightAlign(int fontSize, float x, float y, const std::string &text)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has fontSize
			// xmm0 has x
			// xmm1 has y
			// rsi has text
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1330::func)
		 : "rdi", "xmm0", "xmm1", "rsi"
	);
}

namespace _func1331
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b, 0x106, 0x102};
	static FunctionDefinition funcObj("freetype::easy_printNewlinesCentered", typeid(Pointf (*)(int , float , float , int , const std::string &)), ".554889d089fd5389f34883ec38", argdata, 5, 2, &func);
}

FUNC_NAKED Pointf freetype::easy_printNewlinesCentered(int fontSize, float x, float y, int line_length, const std::string &text)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has fontSize
			// xmm0 has x
			// xmm1 has y
			// rsi has line_length
			// rdx has text
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1331::func)
		 : "rdi", "xmm0", "xmm1", "rsi", "rdx"
	);
}

namespace _func1332
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b, 0x106, 0x102};
	static FunctionDefinition funcObj("freetype::easy_printAutoNewlines", typeid(Pointf (*)(int , float , float , int , const std::string &)), ".554889d089fd5389f34883ec38", argdata, 5, 2, &func);
}

FUNC_NAKED Pointf freetype::easy_printAutoNewlines(int fontSize, float x, float y, int line_length, const std::string &text)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has fontSize
			// xmm0 has x
			// xmm1 has y
			// rsi has line_length
			// rdx has text
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1332::func)
		 : "rdi", "xmm0", "xmm1", "rsi", "rdx"
	);
}

namespace _func1333
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b, 0x106};
	static FunctionDefinition funcObj("freetype::easy_printCenter", typeid(Pointf (*)(int , float , float , const std::string &)), ".5389fb4883ec30488b36488d54241e", argdata, 4, 2, &func);
}

FUNC_NAKED Pointf freetype::easy_printCenter(int fontSize, float x, float y, const std::string &text)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has fontSize
			// xmm0 has x
			// xmm1 has y
			// rsi has text
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1333::func)
		 : "rdi", "xmm0", "xmm1", "rsi"
	);
}

namespace _func1334
{
	static void *func = 0;
	static short argdata[] = {0x107, 0x10a, 0x10b, 0x106, 0x102, 0x101};
	static FunctionDefinition funcObj("freetype::easy_printAutoShrink", typeid(void (*)(int , float , float , int , bool , const std::string &)), ".41578d47cc415641554989cd4154555389fb4883ec5883f801", argdata, 6, 6, &func);
}

FUNC_NAKED void freetype::easy_printAutoShrink(int fontId, float x, float y, int maxWidth, bool centered, const std::string &text)
{
	__asm__
	(
		"pushq %%rbp\n\t"
		"movq %%rsp, %%rbp\n\t"
			// rdi has fontId
			// xmm0 has x
			// xmm1 has y
			// rsi has maxWidth
			// rdx has centered
			// rcx has text
		"call *%0\n\t"
		"movq %%rbp, %%rsp\n\t"
		"popq %%rbp\n\t"
		"ret\n\t"
		 :: "m"(_func1334::func)
		 : "rdi", "xmm0", "xmm1", "rsi", "rdx", "rcx"
	);
}

