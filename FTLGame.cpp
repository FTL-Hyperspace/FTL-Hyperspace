#include "FTLGame.h"
#include "zhl_internal.h"

using namespace ZHL;

namespace _func0
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::LoadAchievementDescriptions", typeid(void (AchievementTracker::*)()), "57b8????????8d7c240883e4f0ff77fc5589e5575653e8????????8d9da4fffeff29c48db5acfffeff", argdata, 1, 5, &func);
}

__declspec(naked) void AchievementTracker::LoadAchievementDescriptions()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func0::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func1
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AnimationTracker::Update", typeid(void (AnimationTracker::*)()), "807910000f84????????5589e55389cb83e4f083ec1080790800", argdata, 1, 5, &func);
}

__declspec(naked) void AnimationTracker::Update()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func1::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func2
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AsteroidGenerator::constructor", typeid(void (AsteroidGenerator::*)()), "5589e557565389cb83e4f083ec20c70424????????e8????????8d500cc70424????????89c789542414e8????????8d880002000089470cc703????????c7430800000000c7430c00000000", argdata, 1, 5, &func);
}

__declspec(naked) void AsteroidGenerator::constructor()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func2::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func3
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::Initialize", typeid(float (AsteroidGenerator::*)(int , int , bool )), ".5589e55389cb8b550c8b451083e4f089918c00000089d1c1e91f01cad1fa", argdata, 4, 1, &func);
}

__declspec(naked) float AsteroidGenerator::Initialize(int numberOfShips, int unk2, bool unk3)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+16]\n\t"		// unk3
		"push [ebp+12]\n\t"		// unk2
		"push [ebp+8]\n\t"		// numberOfShips
	);
	__asm__("call %0\n\t" :: "m"(_func3::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 12\n\t"
	);
}

namespace _func4
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetBlueprintList", typeid(std::vector<std::string> &(*)(std::vector<std::string> &, BlueprintManager *, std::string &)), "578d7c240883e4f0ff77fc5589f889e557565389cb83ec4c8b3f8b40048945c0e8????????84c08d87f4000000", argdata, 3, 0, &func);
}

__declspec(naked) std::vector<std::string> &BlueprintManager::GetBlueprintList(std::vector<std::string> &vec, BlueprintManager *bpM, std::string &str)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+16]\n\t"		// str
		"push [ebp+12]\n\t"		// bpM
		"mov ecx, [ebp+8]\n\t"	// vec
	);
	__asm__("call %0\n\t" :: "m"(_func4::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 12\n\t"
	);
}

namespace _func5
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::Restart", typeid(void (BossShip::*)()), "c7813401000000000000c7816001000001000000c6815c01000001c38d742600f30f108144010000f30f5c8140010000f30f100d????????0f2ec876??83b934010000010f95c0", argdata, 1, 5, &func);
}

__declspec(naked) void BossShip::Restart()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func5::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func6
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::IncomingFire", typeid(char (BossShip::*)()), ".f30f108144010000f30f5c8140010000f30f100d????????0f2ec876??", argdata, 1, 1, &func);
}

__declspec(naked) char BossShip::IncomingFire()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func6::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func7
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BossShip::constructor", typeid(void (BossShip::*)(SpaceManager *)), ".578d7c240883e4f0ff77fc5589e5575389cb83ec108b0783c318c744240801000000c744240400000000", argdata, 2, 5, &func);
}

__declspec(naked) void BossShip::constructor(SpaceManager *space)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// space
	);
	__asm__("call %0\n\t" :: "m"(_func7::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func8
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BossShip::SaveBoss", typeid(void (BossShip::*)(void *)), ".5589e557565389cf83e4f083ec108b5d088b8134010000891c2489442404", argdata, 2, 5, &func);
}

__declspec(naked) void BossShip::SaveBoss(void *file)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// file
	);
	__asm__("call %0\n\t" :: "m"(_func8::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func9
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BossShip::LoadBoss", typeid(int (BossShip::*)(void *)), ".578d7c240883e4f0ff77fc5589e557565389ce83ec3c8b07890424", argdata, 2, 1, &func);
}

__declspec(naked) int BossShip::LoadBoss(void *file)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// file
	);
	__asm__("call %0\n\t" :: "m"(_func9::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func10
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::ClearLocation", typeid(int (BossShip::*)()), ".89c88b490885c974??5589e55389c38b01", argdata, 1, 1, &func);
}

__declspec(naked) int BossShip::ClearLocation()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func10::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func11
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::Defeated", typeid(char (BossShip::*)()), ".83b9340100000374??31c0c38d7426008b490880b99904000000", argdata, 1, 1, &func);
}

__declspec(naked) char BossShip::Defeated()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func11::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func12
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::GetSubEvent", typeid(int (BossShip::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83ec4c", argdata, 1, 1, &func);
}

__declspec(naked) int BossShip::GetSubEvent()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func12::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func13
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::StartStage", typeid(void (BossShip::*)()), ".578d7c240883e4f0ff77fc5589e557565389ce8dbd20ffffff", argdata, 1, 5, &func);
}

__declspec(naked) void BossShip::StartStage()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func13::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func14
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::GetEvent", typeid(int (BossShip::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb", argdata, 1, 1, &func);
}

__declspec(naked) int BossShip::GetEvent()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func14::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func15
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::OnLoop", typeid(void (BossShip::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83ec4c", argdata, 1, 5, &func);
}

__declspec(naked) void BossShip::OnLoop()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func15::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func16
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("Button::SetLocation", typeid(int (Button::*)(Point )), "578d7c240883e4f0ff77fc5589e55783ec148b078b570489042489542404e8????????8b7dfc83ec08c98d67f85fc20800909090909090909090909090909090f3c39090909090909090909090909090c20800", argdata, 2, 1, &func);
}

__declspec(naked) int Button::SetLocation(Point pos)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// pos
	);
	__asm__("call %0\n\t" :: "m"(_func16::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func17
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnInputFocus", typeid(int (CApp::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec1080b9f734000000", argdata, 1, 1, &func);
}

__declspec(naked) int CApp::OnInputFocus()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func17::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func18
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnInputBlur", typeid(int (CApp::*)()), ".5789c88d7c240883e4f0ff77fc5589e5575383ec10c681f7340000008b4908803d??????????", argdata, 1, 1, &func);
}

__declspec(naked) int CApp::OnInputBlur()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func18::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func19
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnExit", typeid(int (CApp::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb83ec10e8????????c70424????????", argdata, 1, 1, &func);
}

__declspec(naked) int CApp::OnExit()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func19::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func20
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnMButtonDown", typeid(void (CApp::*)(int , int )), ".80b9bc3400000074??c208008d74260080791000", argdata, 3, 5, &func);
}

__declspec(naked) void CApp::OnMButtonDown(int x, int y)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func20::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func21
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnTextEvent", typeid(void (CApp::*)(CEvent::TextEvent )), ".578d7c240883e4f0ff77fc55", argdata, 2, 5, &func);
}

__declspec(naked) void CApp::OnTextEvent(CEvent::TextEvent textEvent)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// textEvent
	);
	__asm__("call %0\n\t" :: "m"(_func21::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func22
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnTextInput", typeid(void (CApp::*)(int )), ".578d7c240883e4f0ff77fc5589e55783ec1480b9bc34000000", argdata, 2, 5, &func);
}

__declspec(naked) void CApp::OnTextInput(int unk)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// unk
	);
	__asm__("call %0\n\t" :: "m"(_func22::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func23
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnRequestExit", typeid(int (CApp::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb83ec108b490885c974??8b430c", argdata, 1, 1, &func);
}

__declspec(naked) int CApp::OnRequestExit()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func23::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func24
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnMouseMove", typeid(int (CApp::*)(int , int , int , int , bool , bool , bool )), ".57660fefc08d7c240883e4f0ff77fc5589e557565389cb83ec2c8b072b81103500008b5704", argdata, 8, 1, &func);
}

__declspec(naked) int CApp::OnMouseMove(int x, int y, int xdiff, int ydiff, bool holdingLMB, bool holdingRMB, bool holdingMMB)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+32]\n\t"		// holdingMMB
		"push [ebp+28]\n\t"		// holdingRMB
		"push [ebp+24]\n\t"		// holdingLMB
		"push [ebp+20]\n\t"		// ydiff
		"push [ebp+16]\n\t"		// xdiff
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func24::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 28\n\t"
	);
}

namespace _func25
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnRButtonUp", typeid(void (CApp::*)(int , int )), ".57660fefc08d7c240883e4f0ff77fc5589e5575389cb83ec208b072b81103500008b5704", argdata, 3, 5, &func);
}

__declspec(naked) void CApp::OnRButtonUp(int x, int y)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func25::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func26
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnLButtonUp", typeid(void (CApp::*)(int , int )), ".57660fefc08d7c240883e4f0ff77fc5589e557", argdata, 3, 5, &func);
}

__declspec(naked) void CApp::OnLButtonUp(int x, int y)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func26::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func27
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnRButtonDown", typeid(void (CApp::*)(int , int )), ".57660fefc08d7c240883e4f0ff77fc5589e55753", argdata, 3, 5, &func);
}

__declspec(naked) void CApp::OnRButtonDown(int x, int y)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func27::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func28
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnLButtonDown", typeid(void (CApp::*)(int , int )), ".57660fefc08d7c240883e4f0ff77fc5589e5", argdata, 3, 5, &func);
}

__declspec(naked) void CApp::OnLButtonDown(int x, int y)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func28::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func29
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnLanguageChange", typeid(void (CApp::*)()), ".578d7c240883e4f0ff77fc5589e55756", argdata, 1, 5, &func);
}

__declspec(naked) void CApp::OnLanguageChange()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func29::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func30
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnKeyUp", typeid(void (CApp::*)(SDLKey )), ".578d7c240883e4f0ff77fc5589e557565383ec4c", argdata, 2, 5, &func);
}

__declspec(naked) void CApp::OnKeyUp(SDLKey key)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// key
	);
	__asm__("call %0\n\t" :: "m"(_func30::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func31
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnKeyDown", typeid(void (CApp::*)(SDLKey )), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 2, 5, &func);
}

__declspec(naked) void CApp::OnKeyDown(SDLKey key)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// key
	);
	__asm__("call %0\n\t" :: "m"(_func31::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func32
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::constructor", typeid(void (CApp::*)()), ".5589e55389cb83e4f0e8", argdata, 1, 5, &func);
}

__declspec(naked) void CApp::constructor()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func32::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func33
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::ParseArgs", typeid(void (CApp::*)(int , const char **)), ".555789cd565383ec04c68541350000008b5424188b4c241c83fa017e??", argdata, 3, 5, &func);
}

__declspec(naked) void CApp::ParseArgs(int unk, const char **args)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// args
		"push [ebp+8]\n\t"		// unk
	);
	__asm__("call %0\n\t" :: "m"(_func33::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func34
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnLoop", typeid(void (CApp::*)()), ".578d7c240883e4f0ff77fc5589e557565389cbb9????????83ec4ce8????????", argdata, 1, 5, &func);
}

__declspec(naked) void CApp::OnLoop()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func34::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func35
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::SetupWindow", typeid(int (CApp::*)()), ".5589e55389cb83e4f0", argdata, 1, 1, &func);
}

__declspec(naked) int CApp::SetupWindow()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func35::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func36
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnCleanup", typeid(void (CApp::*)()), ".5589e5565389cb83e4f083ec10", argdata, 1, 5, &func);
}

__declspec(naked) void CApp::OnCleanup()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func36::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func37
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::GenInputEvents", typeid(void (CApp::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb", argdata, 1, 5, &func);
}

__declspec(naked) void CApp::GenInputEvents()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func37::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func38
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnSuspend", typeid(void (CApp::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 5, &func);
}

__declspec(naked) void CApp::OnSuspend()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func38::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func39
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnResume", typeid(void (CApp::*)()), "!.80b9bc3400000075??8079100074??c35589e55389cb8b4908", argdata, 1, 5, &func);
}

__declspec(naked) void CApp::OnResume()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func39::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func40
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::TranslateMouse", typeid(Pointf (CApp::*)(int , int )), ".57660fefc08d7c240883e4f0ff77fc5589e55783ec248b072b8110350000", argdata, 4, 1, &func);
}

__declspec(naked) Pointf CApp::TranslateMouse(int x, int y)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// implicit_output
	);
	__asm__("call %0\n\t" :: "m"(_func40::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 12\n\t"
	);
}

namespace _func41
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::UpdateFullScreen", typeid(void (CApp::*)()), ".803d??????????74??c38db6000000005589e5575653", argdata, 1, 5, &func);
}

__declspec(naked) void CApp::UpdateFullScreen()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func41::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func42
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::UpdateWindowSettings", typeid(int (CApp::*)()), ".80b90c35000000c781ec34000000000000c781f034000000000000c7811035000000000000", argdata, 1, 1, &func);
}

__declspec(naked) int CApp::UpdateWindowSettings()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func42::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func43
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnRender", typeid(void (CApp::*)()), ".578d7c240883e4f0ff77fc5589e55756", argdata, 1, 5, &func);
}

__declspec(naked) void CApp::OnRender()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func43::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func44
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnInit", typeid(int (CApp::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 1, &func);
}

__declspec(naked) int CApp::OnInit()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func44::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func45
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnExecute", typeid(int (CApp::*)()), ".578d7c240883e4f0ff77fc5589e557565389cfb9????????81ec????????c70424????????e8????????89f9", argdata, 1, 1, &func);
}

__declspec(naked) int CApp::OnExecute()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func45::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func46
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnEvent", typeid(int (CApp::*)(void *)), ".578d7c240883e4f0ff77fc5589e55783ec148b07890424e8????????", argdata, 2, 1, &func);
}

__declspec(naked) int CApp::OnEvent(void *inputEvent)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// inputEvent
	);
	__asm__("call %0\n\t" :: "m"(_func46::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func47
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CFPS::GetSpeedFactor", typeid(float (CFPS::*)()), "83ec04f30f104118f30f110424d9042483c404c39090909090909090909090905589e583e4f083ec10a1????????85c074??890424e8????????a1????????85c074??", argdata, 1, 1, &func);
}

__declspec(naked) float CFPS::GetSpeedFactor()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func47::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func48
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::RenderTarget", typeid(void (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????8b81a400000085c074??8b401c83b8b8000000020f84????????8d8518ffffff", argdata, 1, 5, &func);
}

__declspec(naked) void CombatControl::RenderTarget()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func48::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func49
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::GetCurrentTarget", typeid(ShipManager *(CombatControl::*)()), "8b815c07000085c074??8b4008c3669031c0c3908db6000000008dbf000000008b895c07000085c974??558b0189e583e4f0ff5010c9", argdata, 1, 1, &func);
}

__declspec(naked) ShipManager *CombatControl::GetCurrentTarget()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func49::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func50
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::CurrentTargetIsBoss", typeid(char (CombatControl::*)()), "8b895c07000085c974??558b0189e583e4f0ff5010c9c389f68dbc270000000031c0c3908db6000000008dbf00000000578d7c240883e4f0ff77fc5589f889e5", argdata, 1, 1, &func);
}

__declspec(naked) char CombatControl::CurrentTargetIsBoss()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func50::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func51
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::CanTargetSelf", typeid(char (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e557565383ec5c8b81a400000085c074??8b401c83b8b80000000374??", argdata, 1, 1, &func);
}

__declspec(naked) char CombatControl::CanTargetSelf()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func51::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func52
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::RunCommand", typeid(void (CommandGui::*)(std::string &)), "578d7c240883e4f0ff77fc5589e55756538d459081ec????????8b378945888d45a8898d7cffffff8d4d88c7458c00000000c6459000", argdata, 2, 5, &func);
}

__declspec(naked) void CommandGui::RunCommand(std::string &command)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// command
	);
	__asm__("call %0\n\t" :: "m"(_func52::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func53
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::CreateNewStore", typeid(Store *(CommandGui::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b178dbbdc380000c70424????????", argdata, 2, 1, &func);
}

__declspec(naked) Store *CommandGui::CreateNewStore(int sectorNumber)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// sectorNumber
	);
	__asm__("call %0\n\t" :: "m"(_func53::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func54
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::GetWorldCoordinates", typeid(void *(CommandGui::*)(Point , bool )), "578d7c240883e4f0ff77fc5589e557565389cb8d4dd883ec3c8b078b77048b7f088945d4e8????????", argdata, 3, 1, &func);
}

__declspec(naked) void *CommandGui::GetWorldCoordinates(Point point, bool fromTarget)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+16]\n\t"		// fromTarget
		"push [ebp+12]\n\t"		// point
		"push [ebp+8]\n\t"		// point
	);
	__asm__("call %0\n\t" :: "m"(_func54::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 12\n\t"
	);
}

namespace _func55
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::PauseLoop", typeid(int (CompleteShip::*)()), "558b490889e583e4f0e8????????c9c3578d7c240883e4f0ff77fc", argdata, 1, 1, &func);
}

__declspec(naked) int CompleteShip::PauseLoop()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func55::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func56
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::Restart", typeid(int (CompleteShip::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb83ec108b4908e8????????8b43088d4b18c744240400000000", argdata, 1, 1, &func);
}

__declspec(naked) int CompleteShip::Restart()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func56::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func57
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::constructor", typeid(void (CompleteShip::*)(SpaceManager *, bool , int )), ".578d7c240883e4f0ff77fc5589e5575389cb83ec108b47048b4f088b17c703????????c7430800000000", argdata, 4, 5, &func);
}

__declspec(naked) void CompleteShip::constructor(SpaceManager *space, bool unk, int unk2)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+16]\n\t"		// unk2
		"push [ebp+12]\n\t"		// unk
		"push [ebp+8]\n\t"		// space
	);
	__asm__("call %0\n\t" :: "m"(_func57::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 12\n\t"
	);
}

namespace _func58
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::SetShip", typeid(void (CompleteShip::*)(ShipManager *)), ".5783c1188d7c240883e4f0ff77fc5589e55783ec148b078b90bc0700008941f089042489542404e8????????", argdata, 2, 5, &func);
}

__declspec(naked) void CompleteShip::SetShip(ShipManager *ship)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// ship
	);
	__asm__("call %0\n\t" :: "m"(_func58::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func59
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::OnInit", typeid(void (CompleteShip::*)(const ShipBlueprint *, int )), ".578d7c240883e4f0ff77fc5589f889e557565389cb83ec2c8b50048b3fc70424????????8955e4e8????????", argdata, 3, 5, &func);
}

__declspec(naked) void CompleteShip::OnInit(const ShipBlueprint *blueprint, int unk)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// unk
		"push [ebp+8]\n\t"		// blueprint
	);
	__asm__("call %0\n\t" :: "m"(_func59::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func60
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddBoarders", typeid(void (CompleteShip::*)(int , std::string &, bool )), ".578d7c240883e4f0ff77fc5589f889e557565389cf8d4d8c81ec????????8b10", argdata, 4, 5, &func);
}

__declspec(naked) void CompleteShip::AddBoarders(int amount, std::string &race, bool unk2)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+16]\n\t"		// unk2
		"push [ebp+12]\n\t"		// race
		"push [ebp+8]\n\t"		// amount
	);
	__asm__("call %0\n\t" :: "m"(_func60::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 12\n\t"
	);
}

namespace _func61
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember", typeid(CrewMember *(CompleteShip::*)(const CrewBlueprint *, bool )), ".578d7c240883e4f0ff77fc5589e557565381ec????????8b07898d50feffff8b7f04", argdata, 3, 1, &func);
}

__declspec(naked) CrewMember *CompleteShip::AddCrewMember(const CrewBlueprint *blueprint, bool hostile)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// hostile
		"push [ebp+8]\n\t"		// blueprint
	);
	__asm__("call %0\n\t" :: "m"(_func61::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func62
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember1", typeid(CrewMember *(CompleteShip::*)(std::string &, bool )), ".578d7c240883e4f0ff77fc5589e557565381ec????????8b4708", argdata, 3, 1, &func);
}

__declspec(naked) CrewMember *CompleteShip::AddCrewMember1(std::string &race, bool hostile)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// hostile
		"push [ebp+8]\n\t"		// race
	);
	__asm__("call %0\n\t" :: "m"(_func62::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func63
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddDrone", typeid(Drone *(CompleteShip::*)(const DroneBlueprint *, int )), ".578d7c240883e4f0ff77fc5589e55783ec14", argdata, 3, 1, &func);
}

__declspec(naked) Drone *CompleteShip::AddDrone(const DroneBlueprint *blueprint, int unk)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// unk
		"push [ebp+8]\n\t"		// blueprint
	);
	__asm__("call %0\n\t" :: "m"(_func63::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func64
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember2", typeid(CrewMember *(CompleteShip::*)(CrewMember *, int )), ".578d7c240883e4f0ff77fc5589e557565383ec1c8b378b7f0485f6", argdata, 3, 1, &func);
}

__declspec(naked) CrewMember *CompleteShip::AddCrewMember2(CrewMember *member, int unk)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// unk
		"push [ebp+8]\n\t"		// member
	);
	__asm__("call %0\n\t" :: "m"(_func64::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func65
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::SaveState", typeid(char (CompleteShip::*)(int )), ".5589e583e4f083ec108b8130010000894424048b4508", argdata, 2, 1, &func);
}

__declspec(naked) char CompleteShip::SaveState(int unk)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// unk
	);
	__asm__("call %0\n\t" :: "m"(_func65::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func66
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::LoadState", typeid(void (CompleteShip::*)(int )), ".578d7c240883e4f0ff77fc5589e5575389cb83ec208b07890424", argdata, 2, 5, &func);
}

__declspec(naked) void CompleteShip::LoadState(int unk)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// unk
	);
	__asm__("call %0\n\t" :: "m"(_func66::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func67
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::InitiateTeleport", typeid(int (CompleteShip::*)(int , int )), ".578d7c240883e4f0ff77fc5589e557565383ec4c8b811c0100003981180100008b178b7704", argdata, 3, 1, &func);
}

__declspec(naked) int CompleteShip::InitiateTeleport(int room, int shipId)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// shipId
		"push [ebp+8]\n\t"		// room
	);
	__asm__("call %0\n\t" :: "m"(_func67::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func68
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::OnLoop", typeid(void (CompleteShip::*)()), ".578d7c240883e4f0ff77fc5589e557565389cf31db83ec2c8b4908e8????????", argdata, 1, 5, &func);
}

__declspec(naked) void CompleteShip::OnLoop()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func68::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func69
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::GetTeleportingParty", typeid(void (CompleteShip::*)()), ".5589e557565389cb83e4f083ec208b7d088bb7280100008b872401000039c60f84????????", argdata, 1, 5, &func);
}

__declspec(naked) void CompleteShip::GetTeleportingParty()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func69::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func70
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::KillRandomCrew", typeid(CrewMember *(CompleteShip::*)()), ".558b490889e583e4f0e8????????c9", argdata, 1, 1, &func);
}

__declspec(naked) CrewMember *CompleteShip::KillRandomCrew()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func70::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func71
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::CountCrew", typeid(int (CompleteShip::*)(bool )), ".578d7c240883e4f0ff77fc5589e55783ec140fb6078b4908890424e8????????8b7dfc", argdata, 2, 1, &func);
}

__declspec(naked) int CompleteShip::CountCrew(bool boarders)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// boarders
	);
	__asm__("call %0\n\t" :: "m"(_func71::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func72
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::Jump", typeid(CrewMember **(CompleteShip::*)()), ".8b811801000089811c0100008b8124010000898128010000", argdata, 1, 1, &func);
}

__declspec(naked) CrewMember **CompleteShip::Jump()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func72::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func73
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::SetEnemyShip", typeid(void (CompleteShip::*)(CompleteShip *)), ".5783c1188d7c240883e4f0ff77fc5589e55783ec14", argdata, 2, 5, &func);
}

__declspec(naked) void CompleteShip::SetEnemyShip(CompleteShip *other)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// other
	);
	__asm__("call %0\n\t" :: "m"(_func73::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func74
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::DeadCrew", typeid(bool (CompleteShip::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83ec1c0fb64114b9????????", argdata, 1, 1, &func);
}

__declspec(naked) bool CompleteShip::DeadCrew()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func74::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func75
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::TeleportCrew", typeid(void (CompleteShip::*)(ShipManager *, int , bool )), ".578d7c240883e4f0ff77fc5589e557", argdata, 4, 5, &func);
}

__declspec(naked) void CompleteShip::TeleportCrew(ShipManager *other, int room, bool comingBack)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+16]\n\t"		// comingBack
		"push [ebp+12]\n\t"		// room
		"push [ebp+8]\n\t"		// other
	);
	__asm__("call %0\n\t" :: "m"(_func75::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 12\n\t"
	);
}

namespace _func76
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::OnRender", typeid(void (CompleteShip::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb83ec108b43048b490c", argdata, 1, 5, &func);
}

__declspec(naked) void CompleteShip::OnRender()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func76::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func77
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::OnRenderSpace", typeid(void (CompleteShip::*)()), ".578d7c240883e4f0ff77fc5589e55783ec14", argdata, 1, 5, &func);
}

__declspec(naked) void CompleteShip::OnRenderSpace()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func77::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func78
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::OnRenderShip", typeid(void (CompleteShip::*)(bool , bool )), ".578d7c240883e4f0ff77fc5589e557565389cb", argdata, 3, 5, &func);
}

__declspec(naked) void CompleteShip::OnRenderShip(bool unk1, bool unk2)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// unk2
		"push [ebp+8]\n\t"		// unk1
	);
	__asm__("call %0\n\t" :: "m"(_func78::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func79
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewEquipBox::RemoveItem", typeid(int (CrewEquipBox::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b496885c974??80bb6e0200000075??c70424????????e8????????", argdata, 1, 1, &func);
}

__declspec(naked) int CrewEquipBox::RemoveItem()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func79::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func80
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::UpdateHealth", typeid(void (CrewMember::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8bb10002000085f60f85????????807b6c00", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::UpdateHealth()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func80::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func81
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::OnLoop", typeid(void (CrewMember::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????80b9fc01000000", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::OnLoop()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func81::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func82
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::DirectModifyHealth", typeid(void (CrewMember::*)(float )), "57660fefc98d7c240883e4f0ff77fc5589e557565383ec4cf30f1041280f2ec8f30f10170f83????????f30f2cf0f30f58c2", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::DirectModifyHealth(float health)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// health
	);
	__asm__("call %0\n\t" :: "m"(_func82::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func83
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetNewGoal", typeid(char (CrewMember::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b496485c974??e8????????f30f1005????????", argdata, 1, 1, &func);
}

__declspec(naked) char CrewMember::GetNewGoal()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func83::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func84
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::constructor", typeid(void (CrewMember::*)(CrewBlueprint &, int , bool , CrewAnimation *)), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec????????8b308b5808", argdata, 5, 5, &func);
}

__declspec(naked) void CrewMember::constructor(CrewBlueprint &blueprint, int unk, bool unk2, CrewAnimation *animation)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+20]\n\t"		// animation
		"push [ebp+16]\n\t"		// unk2
		"push [ebp+12]\n\t"		// unk
		"push [ebp+8]\n\t"		// blueprint
	);
	__asm__("call %0\n\t" :: "m"(_func84::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 16\n\t"
	);
}

namespace _func85
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::OnRender", typeid(void (CrewMember::*)(bool )), "578d7c240883e4f0ff77fc5589e5575383ec3080b9fc010000008b3f74??8d65f85b5f5d", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::OnRender(bool unk)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// unk
	);
	__asm__("call %0\n\t" :: "m"(_func85::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func86
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_SetColor", typeid(int (*)(float , float , float , float )), "5589e583e4f083ec208b4508f30f104508f30f11442410a3????????8b450cf30f10450cf30f11442414a3????????8b4510f30f104510f30f11442418a3????????8b4514f30f104514f30f1144241ca3????????", argdata, 4, 2, &func);
}

__declspec(naked) int CSurface::GL_SetColor(float r, float g, float b, float a)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+20]\n\t"		// a
		"push [ebp+16]\n\t"		// b
		"push [ebp+12]\n\t"		// g
		"push [ebp+8]\n\t"		// r
	);
	__asm__("call %0\n\t" :: "m"(_func86::func));
	__asm__
	(
		"add esp, 16\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 16\n\t"
	);
}

namespace _func87
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_GetColor", typeid(GL_Color &(*)()), "8b4424048b15????????89108b15????????8950048b15????????8950088b15????????89500cc3908db42600000000a1????????3b05????????74??83e810a3????????f3c390908db426000000008b15????????8b0d????????55", argdata, 0, 2, &func);
}

__declspec(naked) GL_Color &CSurface::GL_GetColor()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func87::func));
	__asm__
	(
		"add esp, 0\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func88
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_SetColorTint", typeid(void (*)(float , float , float , float )), "8d4c240483e4f0ff71fc5589e55183ec14a1????????3b05????????74??85c074??8b1189108b51048950048b51088950088b510c89500c", argdata, 4, 6, &func);
}

__declspec(naked) void CSurface::GL_SetColorTint(float r, float g, float b, float a)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+20]\n\t"		// a
		"push [ebp+16]\n\t"		// b
		"push [ebp+12]\n\t"		// g
		"push [ebp+8]\n\t"		// r
	);
	__asm__("call %0\n\t" :: "m"(_func88::func));
	__asm__
	(
		"add esp, 16\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 16\n\t"
	);
}

namespace _func89
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_RemoveColorTint", typeid(void (*)()), "a1????????3b05????????74??83e810a3????????f3c390908db426000000008b15????????8b0d????????5539d189e5", argdata, 0, 6, &func);
}

__declspec(naked) void CSurface::GL_RemoveColorTint()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func89::func));
	__asm__
	(
		"add esp, 0\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func90
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GetColorTint", typeid(GL_Color &(*)(GL_Color &)), "8b15????????8b0d????????5539d189e58b450874??29ca83e2f08d5411f08b0a89088b4a04894804", argdata, 1, 2, &func);
}

__declspec(naked) GL_Color &CSurface::GetColorTint(GL_Color &ref)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// ref
	);
	__asm__("call %0\n\t" :: "m"(_func90::func));
	__asm__
	(
		"add esp, 4\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func91
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Equipment::OnInit", typeid(void (Equipment::*)(ShipManager *)), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????8b078bb948020000", argdata, 2, 5, &func);
}

__declspec(naked) void Equipment::OnInit(ShipManager *ship)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// ship
	);
	__asm__("call %0\n\t" :: "m"(_func91::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func92
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::constructor", typeid(void (EquipmentBox::*)(Point , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec6c8b35????????8b47048b178b4f088d7dd8c703????????c7431c000000008973088b35????????89434c", argdata, 3, 5, &func);
}

__declspec(naked) void EquipmentBox::constructor(Point pos, int slot)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+16]\n\t"		// slot
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// pos
	);
	__asm__("call %0\n\t" :: "m"(_func92::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 12\n\t"
	);
}

namespace _func93
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("EquipmentBox::IsEmpty", typeid(char (EquipmentBox::*)()), "8b516031c085d274??f3c3908d7426008b516485d275??8b516c85d2", argdata, 1, 1, &func);
}

__declspec(naked) char EquipmentBox::IsEmpty()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func93::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func94
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("EquipmentBox::GetBlueprint", typeid(Blueprint *(EquipmentBox::*)()), "8b416485c074??8b401cc3908d7426008b416085c075??8b416885c074??", argdata, 1, 1, &func);
}

__declspec(naked) Blueprint *EquipmentBox::GetBlueprint()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func94::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func95
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventGenerator::GetBaseEvent", typeid(LocationEvent *(EventGenerator::*)(std::string &, int , char , int )), "578d7c240883e4f0ff77fc5589e557565383ec4c8b4704894dc48b1f8945bc8b47088945c08b470c83f8ff74??803d??????????8904240f85????????e8????????8b7dc48d4f60c6876c01000001c6876d01000000891c24", argdata, 5, 1, &func);
}

__declspec(naked) LocationEvent *EventGenerator::GetBaseEvent(std::string &name, int unk1, char load, int unk3)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+20]\n\t"		// unk3
		"push [ebp+16]\n\t"		// load
		"push [ebp+12]\n\t"		// unk1
		"push [ebp+8]\n\t"		// name
	);
	__asm__("call %0\n\t" :: "m"(_func95::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 16\n\t"
	);
}

namespace _func96
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::PullMinMax", typeid(RandomAmount *(EventsParser::*)(rapidxml::xml_node<char> *, std::string &)), "578d7c240883e4f0ff77fc5589e557565389cb8d4da083ec7c8b47088b7704c70424????????894594e8????????", argdata, 3, 1, &func);
}

__declspec(naked) RandomAmount *EventsParser::PullMinMax(rapidxml::xml_node<char> *node, std::string &name)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// name
		"push [ebp+8]\n\t"		// node
	);
	__asm__("call %0\n\t" :: "m"(_func96::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func97
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::ProcessEvent", typeid(void **(EventsParser::*)(rapidxml::xml_node<char> *, std::string &, EventTemplate &)), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????8b07898d2cfeffff8b5f08898528feffff8b4704c70424????????89c1898524feffffe8????????83ec0485c074??", argdata, 4, 1, &func);
}

__declspec(naked) void **EventsParser::ProcessEvent(rapidxml::xml_node<char> *node, std::string &event, EventTemplate &eventref)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+16]\n\t"		// eventref
		"push [ebp+12]\n\t"		// event
		"push [ebp+8]\n\t"		// node
	);
	__asm__("call %0\n\t" :: "m"(_func97::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 12\n\t"
	);
}

namespace _func98
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_print", typeid(int (*)(int , float , float , std::string &)), "8d4c240483e4f0ff71fc5589e5575653518d7dd883ec588b01897dd0", argdata, 4, 2, &func);
}

__declspec(naked) int freetype::easy_print(int fontData, float x, float y, std::string &text)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+20]\n\t"		// text
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// fontData
	);
	__asm__("call %0\n\t" :: "m"(_func98::func));
	__asm__
	(
		"add esp, 16\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 16\n\t"
	);
}

namespace _func99
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printRightAlign", typeid(int (*)(int , float , float , std::string &)), ".8d4c240483e4f0ff71fc5589e5575653518d7dd883ec588b01897dd0f30f104104f30f1049088945c08b410c", argdata, 4, 2, &func);
}

__declspec(naked) int freetype::easy_printRightAlign(int fontData, float x, float y, std::string &text)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+20]\n\t"		// text
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// fontData
	);
	__asm__("call %0\n\t" :: "m"(_func99::func));
	__asm__
	(
		"add esp, 16\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 16\n\t"
	);
}

namespace _func100
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printNewlinesCentered", typeid(int (*)(int , float , float , int , std::string &)), ".8d4c240483e4f0ff71fc5589e557565351", argdata, 5, 2, &func);
}

__declspec(naked) int freetype::easy_printNewlinesCentered(int fontData, float x, float y, int width, std::string &text)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+24]\n\t"		// text
		"push [ebp+20]\n\t"		// width
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// fontData
	);
	__asm__("call %0\n\t" :: "m"(_func100::func));
	__asm__
	(
		"add esp, 20\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 20\n\t"
	);
}

namespace _func101
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printAutoNewlines", typeid(int (*)(int , float , float , int , std::string &)), ".8d4c240483e4f0ff71fc5589e5575653518d75d883ec68", argdata, 5, 2, &func);
}

__declspec(naked) int freetype::easy_printAutoNewlines(int fontData, float x, float y, int width, std::string &text)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+24]\n\t"		// text
		"push [ebp+20]\n\t"		// width
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// fontData
	);
	__asm__("call %0\n\t" :: "m"(_func101::func));
	__asm__
	(
		"add esp, 20\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 20\n\t"
	);
}

namespace _func102
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printCenter", typeid(int (*)(int , float , float , std::string &)), ".8d4c240483e4f0ff71fc5589e5575653518d7dd883ec588b01", argdata, 4, 2, &func);
}

__declspec(naked) int freetype::easy_printCenter(int fontData, float x, float y, std::string &text)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+20]\n\t"		// text
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// fontData
	);
	__asm__("call %0\n\t" :: "m"(_func102::func));
	__asm__
	(
		"add esp, 16\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 16\n\t"
	);
}

namespace _func103
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printAutoShrink", typeid(int (*)(int , float , float , int , char , std::string &)), ".8d4c240483e4f0ff71fc5589e55756535181ec????????8b5110", argdata, 6, 2, &func);
}

__declspec(naked) int freetype::easy_printAutoShrink(int fontData, float x, float y, int width, char unk, std::string &text)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+28]\n\t"		// text
		"push [ebp+24]\n\t"		// unk
		"push [ebp+20]\n\t"		// width
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// fontData
	);
	__asm__("call %0\n\t" :: "m"(_func103::func));
	__asm__
	(
		"add esp, 24\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 24\n\t"
	);
}

namespace _func104
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("GenericButton::SetLocation", typeid(void *(GenericButton::*)(Point )), "5589e557568b4508538b59048b550c83e4f08b710839d874??89c78941048b0129df89d301790c29f3015910895108ff50308d65f45b5e5f5dc20800", argdata, 2, 1, &func);
}

__declspec(naked) void *GenericButton::SetLocation(Point pos)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// pos
	);
	__asm__("call %0\n\t" :: "m"(_func104::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func105
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("GenericButton::SetActive", typeid(void (GenericButton::*)(bool )), "8b44240484c088414075??c6414200c6414300c204008d76008dbc27000000005589e583e4f083ec10", argdata, 2, 5, &func);
}

__declspec(naked) void GenericButton::SetActive(bool active)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// active
	);
	__asm__("call %0\n\t" :: "m"(_func105::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func106
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("LaserBlast::OnUpdate", typeid(void (LaserBlast::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec4080b9b00000000074??8d8b4c010000", argdata, 1, 5, &func);
}

__declspec(naked) void LaserBlast::OnUpdate()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func106::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func107
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MainMenu::OnRender", typeid(void (MainMenu::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????80b910340000000f85????????80b948200000000f84????????", argdata, 1, 5, &func);
}

__declspec(naked) void MainMenu::OnRender()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func107::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func108
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Pointf::constructor", typeid(void (Pointf::*)(float , float )), "f30f10442404f30f1101f30f10442408f30f114104c20800908db426000000005589e583ec04f30f1009f30f104104f30f5c4d08f30f5c450cf30f59c9f30f59c0f30f58c1f30f110424", argdata, 3, 5, &func);
}

__declspec(naked) void Pointf::constructor(float x, float y)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func108::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func109
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::StringToWeapon", typeid(int (*)(std::string &)), "8d4c240483e4f0ff71fc5589e5535183ec108b19c70424????????89d9e8????????83ec0485c075??8d65f8", argdata, 1, 0, &func);
}

__declspec(naked) int ProjectileFactory::StringToWeapon(std::string &str)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// str
	);
	__asm__("call %0\n\t" :: "m"(_func109::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func110
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::Fire", typeid(void (ProjectileFactory::*)(std::vector<Pointf> &, int )), "578d7c240883e4f0ff77fc5589e557565383ec2c8b47048b1f8945e4", argdata, 3, 5, &func);
}

__declspec(naked) void ProjectileFactory::Fire(std::vector<Pointf> &points, int target)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// target
		"push [ebp+8]\n\t"		// points
	);
	__asm__("call %0\n\t" :: "m"(_func110::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func111
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::FireNextShot", typeid(char (ProjectileFactory::*)()), "8b912c06000031c085d27e??0fb681f600000084c074??8b411c8b911801000039900c0100007e??31c0c3908d74260080b9f50000000075??", argdata, 1, 1, &func);
}

__declspec(naked) char ProjectileFactory::FireNextShot()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func111::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func112
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ResourceControl::constructor", typeid(void (ResourceControl::*)()), "8d4118f30f1005????????c7410401000000c7410800000000f30f11411089018d4134c7410c00000000c7411400000000f30f11412c89411c8d4150c7411800000000c7412001000000f30f1141488941388d4164c7412400000000c741280000000089415c", argdata, 1, 5, &func);
}

__declspec(naked) void ResourceControl::constructor()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func112::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func113
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::CreateImagePrimitive", typeid(void (ResourceControl::*)(GL_Texture *, int , int , int , GL_Color , float , char )), "5589e583e4f083ec408b45088b552c85c00f84????????660fefe489c185c9f30f104d20f30f106d1cf30f104518f30f2a6514", argdata, 8, 5, &func);
}

__declspec(naked) void ResourceControl::CreateImagePrimitive(GL_Texture *tex, int unk1, int unk2, int unk3, GL_Color color, float unk4, char unk5)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+44]\n\t"		// unk5
		"push [ebp+40]\n\t"		// unk4
		"push [ebp+36]\n\t"		// color
		"push [ebp+32]\n\t"		// color
		"push [ebp+28]\n\t"		// color
		"push [ebp+24]\n\t"		// color
		"push [ebp+20]\n\t"		// unk3
		"push [ebp+16]\n\t"		// unk2
		"push [ebp+12]\n\t"		// unk1
		"push [ebp+8]\n\t"		// tex
	);
	__asm__("call %0\n\t" :: "m"(_func113::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 40\n\t"
	);
}

namespace _func114
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::OnInit", typeid(void (ResourceControl::*)(int )), ".5589e55389cb", argdata, 2, 5, &func);
}

__declspec(naked) void ResourceControl::OnInit(int imageSwappingMode)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// imageSwappingMode
	);
	__asm__("call %0\n\t" :: "m"(_func114::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func115
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::LoadFile", typeid(char *(ResourceControl::*)(std::string &)), "5589e557565389cf31db83e4f083ec408d442430c744240c10000000c744240800000000c744243064617461c74424342e646174894424288b4508", argdata, 2, 1, &func);
}

__declspec(naked) char *ResourceControl::LoadFile(std::string &fileName)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// fileName
	);
	__asm__("call %0\n\t" :: "m"(_func115::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func116
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::GetShipUnlocked", typeid(char (ScoreKeeper::*)(int , int )), "5731c08d7c240883e4f0ff77fc5589e557565381ec????????8b5f048b37", argdata, 3, 1, &func);
}

__declspec(naked) char ScoreKeeper::GetShipUnlocked(int shipId, int shipVariant)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// shipVariant
		"push [ebp+8]\n\t"		// shipId
	);
	__asm__("call %0\n\t" :: "m"(_func116::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func117
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::GetCommandConsole", typeid(char (*)()), "0fb605????????c3908db426000000005589e583e4f083ec100fb605????????c70424????????83f001a2????????", argdata, 0, 0, &func);
}

__declspec(naked) char Settings::GetCommandConsole()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func117::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func118
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0xfff, 0x1ff};
	static FunctionDefinition funcObj("Shields::CollisionReal", typeid(void *(Shields::*)(float , float , Damage , bool )), "578d7c240883e4f0ff77fc5589e557565389ce83c10481ec????????8b47408b1ff30f105f04c741fc00000000f30f105708", argdata, 5, 1, &func);
}

__declspec(naked) void *Shields::CollisionReal(float x, float y, Damage damage, bool unk)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+76]\n\t"		// unk
		"push [ebp+72]\n\t"		// damage
		"push [ebp+68]\n\t"		// damage
		"push [ebp+64]\n\t"		// damage
		"push [ebp+60]\n\t"		// damage
		"push [ebp+56]\n\t"		// damage
		"push [ebp+52]\n\t"		// damage
		"push [ebp+48]\n\t"		// damage
		"push [ebp+44]\n\t"		// damage
		"push [ebp+40]\n\t"		// damage
		"push [ebp+36]\n\t"		// damage
		"push [ebp+32]\n\t"		// damage
		"push [ebp+28]\n\t"		// damage
		"push [ebp+24]\n\t"		// damage
		"push [ebp+20]\n\t"		// damage
		"push [ebp+16]\n\t"		// damage
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func118::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 72\n\t"
	);
}

namespace _func119
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::CheckTypes", typeid(void *(ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8db32c0a000083ec3cc7442404010000008b8124110000b9????????890424e8????????83ec0884c00f85????????c70424????????89f1e8????????c6834a0a000000", argdata, 1, 1, &func);
}

__declspec(naked) void *ShipBuilder::CheckTypes()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func119::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func120
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetShipInfo", typeid(ShipGraph *(*)(int )), "8d4c240483e4f0ff71fc5589e55756535181ec????????a1????????8b15????????8b1929c2", argdata, 1, 2, &func);
}

__declspec(naked) ShipGraph *ShipGraph::GetShipInfo(int shipId)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// shipId
	);
	__asm__("call %0\n\t" :: "m"(_func120::func));
	__asm__
	(
		"add esp, 4\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func121
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetSlotWorldPosition", typeid(Point (ShipGraph::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565383ec3c8b57048b018d4dd88b1f8b0490890424e8????????", argdata, 4, 1, &func);
}

__declspec(naked) Point ShipGraph::GetSlotWorldPosition(int x, int y)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// implicit_output
	);
	__asm__("call %0\n\t" :: "m"(_func121::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 12\n\t"
	);
}

namespace _func122
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetSlotRenderPosition", typeid(Point (ShipGraph::*)(int , int , char )), ".578d7c240883e4f0ff77fc5589f889e557565389cf83ec4c8b188b70048b40088945c08b01", argdata, 5, 1, &func);
}

__declspec(naked) Point ShipGraph::GetSlotRenderPosition(int x, int y, char unk)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+20]\n\t"		// unk
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// implicit_output
		"mov ecX, ecx\n\t	// this\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func122::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 16\n\t"
	);
}

namespace _func123
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::DoorCount", typeid(int (ShipGraph::*)(int )), ".538b411c8b59188b54240829d8c1f80239c27d??85d278??8b04935bc20400", argdata, 2, 1, &func);
}

__declspec(naked) int ShipGraph::DoorCount(int unk)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// unk
	);
	__asm__("call %0\n\t" :: "m"(_func123::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func124
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetDoors", typeid(std::vector<Door*> &(ShipGraph::*)(int )), ".578d7c240883e4f0ff77fc5589e557565383ec3c8b37c701????????c7410400000000", argdata, 2, 1, &func);
}

__declspec(naked) std::vector<Door*> &ShipGraph::GetDoors(int unk)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// unk
	);
	__asm__("call %0\n\t" :: "m"(_func124::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func125
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::IsRoomConnected", typeid(int (ShipGraph::*)(int , int )), ".578d7c240883e4f0ff77fc5589e557565383ec2c8b1f8b7704bf????????", argdata, 3, 1, &func);
}

__declspec(naked) int ShipGraph::IsRoomConnected(int room1, int room2)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// room2
		"push [ebp+8]\n\t"		// room1
	);
	__asm__("call %0\n\t" :: "m"(_func125::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func126
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ConnectingDoor", typeid(int (ShipGraph::*)(int , int , int , int )), ".578d7c240883e4f0ff77fc5589f889e557565389cb8d4de083ec5c8b378b7f048b50088b400c", argdata, 5, 1, &func);
}

__declspec(naked) int ShipGraph::ConnectingDoor(int x1, int y1, int x2, int y2)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+20]\n\t"		// y2
		"push [ebp+16]\n\t"		// x2
		"push [ebp+12]\n\t"		// y1
		"push [ebp+8]\n\t"		// x1
	);
	__asm__("call %0\n\t" :: "m"(_func126::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 16\n\t"
	);
}

namespace _func127
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ConnectedGridSquares", typeid(int (ShipGraph::*)(int , int , int , int )), ".578d7c240883e4f0ff77fc5589e557565389ce8d4de083ec6c8b078b5f0889c28945a88b47048b7f0c", argdata, 5, 1, &func);
}

__declspec(naked) int ShipGraph::ConnectedGridSquares(int x1, int y1, int x2, int y2)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+20]\n\t"		// y2
		"push [ebp+16]\n\t"		// x2
		"push [ebp+12]\n\t"		// y1
		"push [ebp+8]\n\t"		// x1
	);
	__asm__("call %0\n\t" :: "m"(_func127::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 16\n\t"
	);
}

namespace _func128
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x2ff};
	static FunctionDefinition funcObj("ShipGraph::ConnectedGridSquares", typeid(int (ShipGraph::*)(Point , Point )), ".578d7c240883e4f0ff77fc5589e5575383ec108b5f088b078b5704", argdata, 3, 1, &func);
}

__declspec(naked) int ShipGraph::ConnectedGridSquares(Point p1, Point p2)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+20]\n\t"		// p2
		"push [ebp+16]\n\t"		// p2
		"push [ebp+12]\n\t"		// p1
		"push [ebp+8]\n\t"		// p1
	);
	__asm__("call %0\n\t" :: "m"(_func128::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 16\n\t"
	);
}

namespace _func129
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x2ff};
	static FunctionDefinition funcObj("ShipGraph::ConnectingDoor", typeid(int (ShipGraph::*)(Point , Point )), ".578d7c240883e4f0ff77fc5589e5575383ec108b5f088b078b57048b7f0c895c2408890424", argdata, 3, 1, &func);
}

__declspec(naked) int ShipGraph::ConnectingDoor(Point p1, Point p2)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+20]\n\t"		// p2
		"push [ebp+16]\n\t"		// p2
		"push [ebp+12]\n\t"		// p1
		"push [ebp+8]\n\t"		// p1
	);
	__asm__("call %0\n\t" :: "m"(_func129::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 16\n\t"
	);
}

namespace _func130
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetNumSlots", typeid(int (ShipGraph::*)(int )), ".8b5424048b018b04908b50348b421c2b4214c1f802c1e005", argdata, 2, 1, &func);
}

__declspec(naked) int ShipGraph::GetNumSlots(int room)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// room
	);
	__asm__("call %0\n\t" :: "m"(_func130::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func131
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::PopClosestDoor", typeid(int (*)(std::vector<int> &, std::vector<float> &)), ".5589e557565383e4f083ec208b45088b388b450c8b0f8b0089442418f30f2c14888b45088b400489442410", argdata, 2, 0, &func);
}

__declspec(naked) int ShipGraph::PopClosestDoor(std::vector<int> &unk, std::vector<float> &unk2)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// unk2
		"push [ebp+8]\n\t"		// unk
	);
	__asm__("call %0\n\t" :: "m"(_func131::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func132
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::Dijkstra", typeid(int (ShipGraph::*)(Point , Point , int )), ".578d7c240883e4f0ff77fc5589f889e557565381ec????????89bd70ffffff8b3f898d74ffffff8b5804", argdata, 4, 1, &func);
}

__declspec(naked) int ShipGraph::Dijkstra(Point p1, Point p2, int unk)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+24]\n\t"		// unk
		"push [ebp+20]\n\t"		// p2
		"push [ebp+16]\n\t"		// p2
		"push [ebp+12]\n\t"		// p1
		"push [ebp+8]\n\t"		// p1
	);
	__asm__("call %0\n\t" :: "m"(_func132::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 20\n\t"
	);
}

namespace _func133
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::FindPath", typeid(int (ShipGraph::*)(Point , Point , int )), ".578d7c240883e4f0ff77fc5589f889e557565383ec6c8b500c", argdata, 4, 1, &func);
}

__declspec(naked) int ShipGraph::FindPath(Point p1, Point p2, int unk)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+24]\n\t"		// unk
		"push [ebp+20]\n\t"		// p2
		"push [ebp+16]\n\t"		// p2
		"push [ebp+12]\n\t"		// p1
		"push [ebp+8]\n\t"		// p1
	);
	__asm__("call %0\n\t" :: "m"(_func133::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 20\n\t"
	);
}

namespace _func134
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ConvertToWorldAngle", typeid(float (ShipGraph::*)(float )), ".83ec04f30f10442408f30f584134f30f110424d9042483c404", argdata, 2, 1, &func);
}

__declspec(naked) float ShipGraph::ConvertToWorldAngle(float ang)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// ang
	);
	__asm__("call %0\n\t" :: "m"(_func134::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func135
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ConvertToLocalAngle", typeid(float (ShipGraph::*)(float )), ".83ec04f30f10442408f30f5c4134f30f110424d90424", argdata, 2, 1, &func);
}

__declspec(naked) float ShipGraph::ConvertToLocalAngle(float ang)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// ang
	);
	__asm__("call %0\n\t" :: "m"(_func135::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func136
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("ShipGraph::ConvertToWorldPosition", typeid(int64_t (ShipGraph::*)(Pointf )), ".57660feff6660fefff8d7c240883e4f0ff77fc5589e5575389cb83ec20f30f2a7124f30f2a7928660f7ef2660f7ef8", argdata, 2, 1, &func);
}

__declspec(naked) int64_t ShipGraph::ConvertToWorldPosition(Pointf p)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// p
		"push [ebp+8]\n\t"		// p
	);
	__asm__("call %0\n\t" :: "m"(_func136::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func137
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ConvertToLocalPosition", typeid(Pointf (ShipGraph::*)(Pointf , char )), ".578d7c240883e4f0ff77fc5589e55783ec14807f0800f30f10692cf30f105930f30f10613474??", argdata, 4, 1, &func);
}

__declspec(naked) Pointf ShipGraph::ConvertToLocalPosition(Pointf p, char unk)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+20]\n\t"		// unk
		"push [ebp+16]\n\t"		// p
		"push [ebp+12]\n\t"		// p
		"push [ebp+8]\n\t"		// implicit_output
	);
	__asm__("call %0\n\t" :: "m"(_func137::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 16\n\t"
	);
}

namespace _func138
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipInfo::AddAugmentation", typeid(char (ShipInfo::*)(std::string &)), "578d7c240883e4f0ff77fc5589e557565389ce8d560483ec5c894dbc8b0f89d3894db4890c24", argdata, 2, 1, &func);
}

__declspec(naked) char ShipInfo::AddAugmentation(std::string &augment)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// augment
	);
	__asm__("call %0\n\t" :: "m"(_func138::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func139
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::constructor", typeid(int (ShipManager::*)(int )), "578d7c240883e4f0ff77fc5589e557565389ce83c17083ec6c8b1fc7419c00000000", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::constructor(int shipId)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// shipId
	);
	__asm__("call %0\n\t" :: "m"(_func139::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func140
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddInitialCrew", typeid(void (ShipManager::*)(std::vector<CrewBlueprint> &)), "578d7c240883e4f0ff77fc5589f889e557565389cf8d8d90feffff81ec????????", argdata, 2, 5, &func);
}

__declspec(naked) void ShipManager::AddInitialCrew(std::vector<CrewBlueprint> &blueprints)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// blueprints
	);
	__asm__("call %0\n\t" :: "m"(_func140::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func141
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetDodgeFactor", typeid(int (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565383ec2c8bb1c8040000837e04ff74??c70424????????89cb", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::GetDodgeFactor()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func141::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func142
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::OnRender", typeid(void (ShipManager::*)(bool , bool )), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec????????803d??????????8b188b4004889d44ffffff898530ffffff0f84????????", argdata, 3, 5, &func);
}

__declspec(naked) void ShipManager::OnRender(bool unk1, bool unk2)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// unk2
		"push [ebp+8]\n\t"		// unk1
	);
	__asm__("call %0\n\t" :: "m"(_func142::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func143
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CountCrew", typeid(int (ShipManager::*)(bool )), "5589e557565383e4f083ec100fb645088b51648844240f8b416829d0c1f80285c00f84????????", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::CountCrew(bool boarders)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// boarders
	);
	__asm__("call %0\n\t" :: "m"(_func143::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func144
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::TeleportCrew", typeid(int (ShipManager::*)(ShipManager *, int , bool )), "578d7c240883e4f0ff77fc5589f889e557565383ec3c8b3f8b70040fb64008", argdata, 4, 1, &func);
}

__declspec(naked) int ShipManager::TeleportCrew(ShipManager *other, int room, bool comingBack)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+16]\n\t"		// comingBack
		"push [ebp+12]\n\t"		// room
		"push [ebp+8]\n\t"		// other
	);
	__asm__("call %0\n\t" :: "m"(_func144::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 12\n\t"
	);
}

namespace _func145
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::HasAugmentation", typeid(char (ShipObject::*)(std::string &)), "5789ca8d7c240883e4f0ff77fc5589e55756538d4dd883ec5c8b07894dd08b308b580489f0", argdata, 2, 1, &func);
}

__declspec(naked) char ShipObject::HasAugmentation(std::string &augment)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// augment
	);
	__asm__("call %0\n\t" :: "m"(_func145::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func146
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::GetAugmentationValue", typeid(float (ShipObject::*)(std::string &)), "5789ca8d7c240883e4f0ff77fc5589e55756538d4d9081ec????????8b07894d888b308b5804", argdata, 2, 1, &func);
}

__declspec(naked) float ShipObject::GetAugmentationValue(std::string &augment)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// augment
	);
	__asm__("call %0\n\t" :: "m"(_func146::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func147
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipStatus::RenderHealth", typeid(void (ShipStatus::*)(bool )), "578d7c240883e4f0ff77fc5589e557565381ec????????803f000f85????????89cb8b79148bb180000000", argdata, 2, 5, &func);
}

__declspec(naked) void ShipStatus::RenderHealth(bool unk)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// unk
	);
	__asm__("call %0\n\t" :: "m"(_func147::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func148
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::DamageOverTime", typeid(char (ShipSystem::*)(float )), "578d7c240883e4f0ff77fc5589e557565389cbb9????????83ec2cf30f100ff30f114de4e8????????d95de031c0f30f1045e0f30f5945e4f30f5883080100000f2e05????????f30f118308010000", argdata, 2, 1, &func);
}

__declspec(naked) char ShipSystem::DamageOverTime(float unk)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// unk
	);
	__asm__("call %0\n\t" :: "m"(_func148::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func149
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::CheckForRepower", typeid(int (ShipSystem::*)()), ".8b414083e80383f801", argdata, 1, 1, &func);
}

__declspec(naked) int ShipSystem::CheckForRepower()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func149::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func150
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::NameToSystemId", typeid(int (*)(std::string &)), ".8d4c240483e4f0ff71fc5589e5535183ec108b19c70424????????89d9e8????????83ec0485c075??", argdata, 1, 2, &func);
}

__declspec(naked) int ShipSystem::NameToSystemId(std::string &name)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// name
	);
	__asm__("call %0\n\t" :: "m"(_func150::func));
	__asm__
	(
		"add esp, 4\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func151
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::IsMannedBoost", typeid(int (ShipSystem::*)()), "8b414885c07e??80794c0074??8b9104010000399100010000ba????????", argdata, 1, 1, &func);
}

__declspec(naked) int ShipSystem::IsMannedBoost()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func151::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func152
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SystemIdToName", typeid(std::string &(*)(std::string &, int )), "8d4c240483e4f0ff71fc5589e5535183ec108b41048b1983f8110f87????????ff2485????????89f68dbc2700000000c70424????????89d9e8????????83ec048d65f8", argdata, 2, 2, &func);
}

__declspec(naked) std::string &ShipSystem::SystemIdToName(std::string &strRef, int systemId)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// systemId
		"push [ebp+8]\n\t"		// strRef
	);
	__asm__("call %0\n\t" :: "m"(_func152::func));
	__asm__
	(
		"add esp, 8\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func153
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SoundControl::PlaySoundMix", typeid(int (SoundControl::*)(std::string &, float , char )), "578d7c240883e4f0ff77fc5589e557565331db81ec????????8039008b07f30f104704f30f11458889458c74??80b9b80000000075??", argdata, 4, 1, &func);
}

__declspec(naked) int SoundControl::PlaySoundMix(std::string &soundName, float volume, char loop)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+16]\n\t"		// loop
		"push [ebp+12]\n\t"		// volume
		"push [ebp+8]\n\t"		// soundName
	);
	__asm__("call %0\n\t" :: "m"(_func153::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 12\n\t"
	);
}

namespace _func154
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetPlanetaryDefense", typeid(int (SpaceManager::*)(char , int )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b47048b378db9b8020000", argdata, 3, 1, &func);
}

__declspec(naked) int SpaceManager::SetPlanetaryDefense(char unk, int target)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// target
		"push [ebp+8]\n\t"		// unk
	);
	__asm__("call %0\n\t" :: "m"(_func154::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

namespace _func155
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::OnRender", typeid(void (StarMap::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????80b910070000000f84????????8d8d18ffffff", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::OnRender()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func155::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func156
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::SetBossStage", typeid(void (StarMap::*)(int )), "8b4424048981e4090000c2040090669031c083b96c0800000474??f3c38d76008b8174080000", argdata, 2, 5, &func);
}

__declspec(naked) void StarMap::SetBossStage(int stage)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// stage
	);
	__asm__("call %0\n\t" :: "m"(_func156::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 4\n\t"
	);
}

namespace _func157
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::Fire", typeid(void (WeaponControl::*)(std::vector<Pointf> &, int , bool )), "578d7c240883e4f0ff77fc5589f889e557565383ec3c8b91900000008b70048b3f8b400885d28975d00f84????????", argdata, 4, 5, &func);
}

__declspec(naked) void WeaponControl::Fire(std::vector<Pointf> &points, int target, bool autoFire)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+16]\n\t"		// autoFire
		"push [ebp+12]\n\t"		// target
		"push [ebp+8]\n\t"		// points
	);
	__asm__("call %0\n\t" :: "m"(_func157::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 12\n\t"
	);
}

namespace _func158
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::constructor", typeid(void (WorldManager::*)()), "578d7c240883e4f0ff77fc5589e5575389cb8d490883ec10c741f800000000c741fc00000000", argdata, 1, 5, &func);
}

__declspec(naked) void WorldManager::constructor()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func158::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func159
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::OnInit", typeid(int (WorldManager::*)()), "578d7c240883e4f0ff77fc5589e557568d71085389cb83ec1c89f1e8????????c70424????????e8????????", argdata, 1, 1, &func);
}

__declspec(naked) int WorldManager::OnInit()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func159::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func160
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CreateShip", typeid(CompleteShip *(WorldManager::*)(ShipEvent *, bool )), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????807f04008b1f0f85????????c70424????????e8????????89c7", argdata, 2, 0, &func);
}

__declspec(naked) CompleteShip *WorldManager::CreateShip(ShipEvent *shipEvent, bool boss)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// boss
		"push [ebp+8]\n\t"		// shipEvent
	);
	__asm__("call %0\n\t" :: "m"(_func160::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 8\n\t"
	);
}

