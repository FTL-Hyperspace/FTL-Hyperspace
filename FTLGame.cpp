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
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::GetShipAchievements", typeid(void *(*)(void *, AchievementTracker *, const std::string &)), "578d7c240883e4f0ff77fc5589f889e557565383ec5c8b40048b3f894db4c744240802000000c744240400000000", argdata, 3, 0, &func);
}

__declspec(naked) void *AchievementTracker::GetShipAchievements(void *unk, AchievementTracker *tracker, const std::string &name)
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
		"push [ebp+16]\n\t"		// name
		"push [ebp+12]\n\t"		// tracker
		"mov ecx, [ebp+8]\n\t"	// unk
	);
	__asm__("call %0\n\t" :: "m"(_func1::func));
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

namespace _func2
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SetAchievement", typeid(void (AchievementTracker::*)(const std::string &, bool , bool )), "578d7c240883e4f0ff77fc5589e557565381ec????????8b0789458c0fb6470488857fffffff8b411889c2", argdata, 4, 5, &func);
}

__declspec(naked) void AchievementTracker::SetAchievement(const std::string &achievement, bool noPopup, bool sendToServer)
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
		"push [ebp+16]\n\t"		// sendToServer
		"push [ebp+12]\n\t"		// noPopup
		"push [ebp+8]\n\t"		// achievement
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
		"ret 12\n\t"
	);
}

namespace _func3
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::UnlockShip", typeid(void (AchievementTracker::*)(int , int )), "578d7c240883e4f0ff77fc5589e55783ec148b57048b0783fa0274??8b790c8d04408d04872", argdata, 3, 5, &func);
}

__declspec(naked) void AchievementTracker::UnlockShip(int shipId, int shipType)
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
		"push [ebp+12]\n\t"		// shipType
		"push [ebp+8]\n\t"		// shipId
	);
	__asm__("call %0\n\t" :: "m"(_func3::func));
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

namespace _func4
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::SetSectorEight", typeid(void (AchievementTracker::*)()), "578d7c240883e4f0ff77fc5589e55756538d45d08d7dd881ec????????894d84897dd0890424c744240801000000", argdata, 1, 5, &func);
}

__declspec(naked) void AchievementTracker::SetSectorEight()
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
	__asm__("call %0\n\t" :: "m"(_func4::func));
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

namespace _func5
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::GetShipMarker", typeid(int (AchievementTracker::*)(const std::string &, const std::string &)), "578d7c240883e4f0ff77fc5589f889e557565383ec5c8b3f8b70048b5f048b4e04", argdata, 3, 1, &func);
}

__declspec(naked) int AchievementTracker::GetShipMarker(const std::string &baseName, const std::string &thisName)
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
		"push [ebp+12]\n\t"		// thisName
		"push [ebp+8]\n\t"		// baseName
	);
	__asm__("call %0\n\t" :: "m"(_func5::func));
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

namespace _func6
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SetFlag", typeid(void (AchievementTracker::*)(const std::string &)), "5789c88d7c240883e4f0ff77fc5589e557565383ec4c8b582c8b17894dc083c128894dcc85db8955c4", argdata, 2, 5, &func);
}

__declspec(naked) void AchievementTracker::SetFlag(const std::string &flagName)
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
		"push [ebp+8]\n\t"		// flagName
	);
	__asm__("call %0\n\t" :: "m"(_func6::func));
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

namespace _func7
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::GetFlag", typeid(bool (AchievementTracker::*)(const std::string &)), "578d51288d7c240883e4f0ff77fc5589e557565383ec4c8b078b792c8955cc85ff8945c4", argdata, 2, 1, &func);
}

__declspec(naked) bool AchievementTracker::GetFlag(const std::string &flagName)
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
		"push [ebp+8]\n\t"		// flagName
	);
	__asm__("call %0\n\t" :: "m"(_func7::func));
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

namespace _func8
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SaveProfile", typeid(void (AchievementTracker::*)(int )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec2c8b008b71188945e48b411c", argdata, 2, 5, &func);
}

__declspec(naked) void AchievementTracker::SaveProfile(int file)
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
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::LoadProfile", typeid(void (AchievementTracker::*)(int , int )), "578d7c240883e4f0ff77fc5589f889e557565381ec????????8b3f8b4004894d80893c24", argdata, 3, 5, &func);
}

__declspec(naked) void AchievementTracker::LoadProfile(int file, int version)
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
		"push [ebp+12]\n\t"		// version
		"push [ebp+8]\n\t"		// file
	);
	__asm__("call %0\n\t" :: "m"(_func9::func));
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

namespace _func10
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::SetVictoryAchievement", typeid(void (AchievementTracker::*)()), "578d7c240883e4f0ff77fc5589e55756538d7dc089ce83ec6c8b516c8b5970897db889d001d874??", argdata, 1, 5, &func);
}

__declspec(naked) void AchievementTracker::SetVictoryAchievement()
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
	__asm__("call %0\n\t" :: "m"(_func10::func));
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

namespace _func11
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("Animation::OnRender", typeid(void (Animation::*)(float , GL_Color , bool )), "5589e557565389cb83e4f083ec408b451c84c089c775??0fb6b984000000f30f104508", argdata, 4, 5, &func);
}

__declspec(naked) void Animation::OnRender(float opacity, GL_Color color, bool mirror)
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
		"push [ebp+28]\n\t"		// mirror
		"push [ebp+24]\n\t"		// color
		"push [ebp+20]\n\t"		// color
		"push [ebp+16]\n\t"		// color
		"push [ebp+12]\n\t"		// color
		"push [ebp+8]\n\t"		// opacity
	);
	__asm__("call %0\n\t" :: "m"(_func11::func));
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
		"ret 24\n\t"
	);
}

namespace _func12
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Animation::Update", typeid(void (Animation::*)()), "57660fefdb8d7c240883e4f0ff77fc5589e557565389cb83ec4c", argdata, 1, 5, &func);
}

__declspec(naked) void Animation::Update()
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
	__asm__("call %0\n\t" :: "m"(_func12::func));
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

namespace _func13
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Animation::SetCurrentFrame", typeid(void (Animation::*)(int )), "8b5104538b5c24088d42ff39d80f4fc385c07e??660fefc0660fefdbf30f2ac0898180000000660fefd2f30f104924", argdata, 2, 5, &func);
}

__declspec(naked) void Animation::SetCurrentFrame(int frame)
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
		"push [ebp+8]\n\t"		// frame
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
		"ret 4\n\t"
	);
}

namespace _func14
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Animation::Start", typeid(void (Animation::*)(bool )), "578d7c240883e4f0ff77fc5589e5575389cb83ec20803f000f85????????660fefd2f30f10492cc6413200", argdata, 2, 5, &func);
}

__declspec(naked) void Animation::Start(bool reset)
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
		"push [ebp+8]\n\t"		// reset
	);
	__asm__("call %0\n\t" :: "m"(_func14::func));
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

namespace _func15
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Animation::AddSoundQueue", typeid(void (Animation::*)(int , const std::string &)), "578d7c240883e4f0ff77fc5589e557565383ec3c8b178b770485d278??8b99880000008b818c00000029d8c1f802", argdata, 3, 5, &func);
}

__declspec(naked) void Animation::AddSoundQueue(int unk, const std::string &sound)
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
		"push [ebp+12]\n\t"		// sound
		"push [ebp+8]\n\t"		// unk
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
		"ret 8\n\t"
	);
}

namespace _func16
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Animation::SetAnimationId", typeid(void (Animation::*)(GL_Texture *)), "8b442404390174??89c2890185d274??8b500489510889c285d274??8b400889410c", argdata, 2, 5, &func);
}

__declspec(naked) void Animation::SetAnimationId(GL_Texture *tex)
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
		"push [ebp+8]\n\t"		// tex
	);
	__asm__("call %0\n\t" :: "m"(_func16::func));
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

namespace _func17
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Animation::destructor", typeid(void (Animation::*)()), "558d91a400000089e557565383e4f083ec208b819c000000894c241839d074??890424e8????????8b4424188bb08c00000089f38974241c8bb088000000", argdata, 1, 5, &func);
}

__declspec(naked) void Animation::destructor()
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
	__asm__("call %0\n\t" :: "m"(_func17::func));
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

namespace _func18
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Animation::StartReverse", typeid(void (Animation::*)(bool )), "578d7c240883e4f0ff77fc5589e5575389cb83ec208b0784c00f85????????660fefd2f30f10412cc6413200c64130010f2ed00f87????????f30f104924", argdata, 2, 5, &func);
}

__declspec(naked) void Animation::StartReverse(bool reset)
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
		"push [ebp+8]\n\t"		// reset
	);
	__asm__("call %0\n\t" :: "m"(_func18::func));
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

namespace _func19
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Animation::SetProgress", typeid(void (Animation::*)(float )), "f30f10512480793000f30f104c24048b5104f30f59ca660fefdb660fefc0f30f11492cf30f2ada74??f30f5ecaf30f5fc80f28c1f30f59c383ea01", argdata, 2, 5, &func);
}

__declspec(naked) void Animation::SetProgress(float progress)
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
		"push [ebp+8]\n\t"		// progress
	);
	__asm__("call %0\n\t" :: "m"(_func19::func));
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

namespace _func20
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AnimationControl::GetAnimation", typeid(Animation *(*)(Animation &, AnimationControl *, const std::string &)), "578d7c240883e4f0ff77fc5589e557565381ec????????8b07898dacfeffff8985b0feffff8b4704c70424????????", argdata, 3, 0, &func);
}

__declspec(naked) Animation *AnimationControl::GetAnimation(Animation &animRef, AnimationControl *animControl, const std::string &animName)
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
		"push [ebp+16]\n\t"		// animName
		"push [ebp+12]\n\t"		// animControl
		"mov ecx, [ebp+8]\n\t"	// animRef
	);
	__asm__("call %0\n\t" :: "m"(_func20::func));
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

namespace _func21
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
		"ret\n\t"
	);
}

namespace _func22
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::SetLoop", typeid(void (AnimationTracker::*)(bool , float )), ".8b442404f30f10442408f30f114114c7411800000000884108", argdata, 3, 5, &func);
}

__declspec(naked) void AnimationTracker::SetLoop(bool loop, float loopDelay)
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
		"push [ebp+12]\n\t"		// loopDelay
		"push [ebp+8]\n\t"		// loop
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
		"ret 8\n\t"
	);
}

namespace _func23
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::Stop", typeid(void (AnimationTracker::*)(bool )), ".807c240400c6411000660fefc074??f30f10410cf30f11410c", argdata, 2, 5, &func);
}

__declspec(naked) void AnimationTracker::Stop(bool resetTime)
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
		"push [ebp+8]\n\t"		// resetTime
	);
	__asm__("call %0\n\t" :: "m"(_func23::func));
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

namespace _func24
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::Start", typeid(void (AnimationTracker::*)(float )), ".f30f10442404c6411200c6411001f30f11410cc6411100", argdata, 2, 5, &func);
}

__declspec(naked) void AnimationTracker::Start(float time)
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
		"push [ebp+8]\n\t"		// time
	);
	__asm__("call %0\n\t" :: "m"(_func24::func));
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

namespace _func25
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::StartReverse", typeid(void (AnimationTracker::*)(float )), ".660fefc9c6411200f30f10442404c64110010f2ec876??f30f104104", argdata, 2, 5, &func);
}

__declspec(naked) void AnimationTracker::StartReverse(float time)
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
		"push [ebp+8]\n\t"		// time
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
		"ret 4\n\t"
	);
}

namespace _func26
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::Progress", typeid(float (AnimationTracker::*)(float )), ".83ec0480791000f30f104c2408660fefc074??0f2ec10f28d077??f30f10410cf30f5ec1", argdata, 2, 1, &func);
}

__declspec(naked) float AnimationTracker::Progress(float speed)
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
		"push [ebp+8]\n\t"		// speed
	);
	__asm__("call %0\n\t" :: "m"(_func26::func));
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

namespace _func27
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::SetProgress", typeid(void (AnimationTracker::*)(float )), ".f30f104104f30f59442404f30f11410c", argdata, 2, 5, &func);
}

__declspec(naked) void AnimationTracker::SetProgress(float time)
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
		"push [ebp+8]\n\t"		// time
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
		"ret 4\n\t"
	);
}

namespace _func28
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::GetAlphaLevel", typeid(float (AnimationTracker::*)(bool )), ".5589e583ec04f30f1005????????f30f1015????????807d0800f30f594104f30f10490cf30f5cc80f28d8", argdata, 2, 1, &func);
}

__declspec(naked) float AnimationTracker::GetAlphaLevel(bool reverse)
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
		"push [ebp+8]\n\t"		// reverse
	);
	__asm__("call %0\n\t" :: "m"(_func28::func));
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

namespace _func29
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ArmamentControl::Dragging", typeid(bool (ArmamentControl::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec10837970ff74??8b43688b536c8d4960890424", argdata, 1, 1, &func);
}

__declspec(naked) bool ArmamentControl::Dragging()
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
	__asm__("call %0\n\t" :: "m"(_func29::func));
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

namespace _func30
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ArmamentControl::SetPosition", typeid(void (ArmamentControl::*)(int , int )), "5589e5565383e4f083ec108b450839411c8b550c74??89411c89512031db8b51408b414489ce", argdata, 3, 5, &func);
}

__declspec(naked) void ArmamentControl::SetPosition(int x, int y)
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
		"ret 8\n\t"
	);
}

namespace _func31
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ArtillerySystem::OnLoop", typeid(void (ArtillerySystem::*)()), "578d7c240883e4f0ff77fc5589e557565389cf83ec5c894db0e8????????89f9e8????????85c0", argdata, 1, 5, &func);
}

__declspec(naked) void ArtillerySystem::OnLoop()
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
		"ret\n\t"
	);
}

namespace _func32
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
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::Initialize", typeid(float (AsteroidGenerator::*)(int , int , bool )), ".5589e55389cb8b550c8b451083e4f089918c00000089d1c1e91f01cad1fa", argdata, 4, 1, &func);
}

__declspec(naked) float AsteroidGenerator::Initialize(int numberOfShips, int shieldCount, bool unk)
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
		"push [ebp+16]\n\t"		// unk
		"push [ebp+12]\n\t"		// shieldCount
		"push [ebp+8]\n\t"		// numberOfShips
	);
	__asm__("call %0\n\t" :: "m"(_func33::func));
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

namespace _func34
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::SetNumShips", typeid(void (AsteroidGenerator::*)(int )), ".8b442404894170", argdata, 2, 5, &func);
}

__declspec(naked) void AsteroidGenerator::SetNumShips(int ships)
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
		"push [ebp+8]\n\t"		// ships
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
		"ret 4\n\t"
	);
}

namespace _func35
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AsteroidGenerator::GetNextAsteroid", typeid(Projectile *(AsteroidGenerator::*)()), ".8b41083b41180f84????????578d7c240883e4f0ff77fc5589e557", argdata, 1, 1, &func);
}

__declspec(naked) Projectile *AsteroidGenerator::GetNextAsteroid()
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
	static FunctionDefinition funcObj("AsteroidGenerator::OnLoop", typeid(void (AsteroidGenerator::*)()), ".80b9880000000075??c38db600000000578d7c240883e4f0", argdata, 1, 5, &func);
}

__declspec(naked) void AsteroidGenerator::OnLoop()
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
	static FunctionDefinition funcObj("AsteroidGenerator::GetNextState", typeid(float (AsteroidGenerator::*)()), ".5589e5538b417489cb83e4f085c075??803d??????????", argdata, 1, 1, &func);
}

__declspec(naked) float AsteroidGenerator::GetNextState()
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
	__asm__("call %0\n\t" :: "m"(_func37::func));
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

namespace _func38
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AsteroidGenerator::UpdateState", typeid(void (AsteroidGenerator::*)()), ".5589e55389cbb9????????83e4f083ec10e8????????d95c240c", argdata, 1, 5, &func);
}

__declspec(naked) void AsteroidGenerator::UpdateState()
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
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::SaveAsteroids", typeid(bool (AsteroidGenerator::*)(void *)), ".5589e5565389ce83e4f083ec108b5d08", argdata, 2, 1, &func);
}

__declspec(naked) bool AsteroidGenerator::SaveAsteroids(void *file)
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
	__asm__("call %0\n\t" :: "m"(_func39::func));
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

namespace _func40
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::LoadAsteroids", typeid(void (AsteroidGenerator::*)(void *)), ".5589e5565389cb83e4f083ec108b7508", argdata, 2, 5, &func);
}

__declspec(naked) void AsteroidGenerator::LoadAsteroids(void *file)
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
	__asm__("call %0\n\t" :: "m"(_func40::func));
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

namespace _func41
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AugmentEquipBox::RenderIcon", typeid(void (AugmentEquipBox::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec10e8????????8b434c660fefc0c744240800000000f7d8f30f2ac0", argdata, 1, 5, &func);
}

__declspec(naked) void AugmentEquipBox::RenderIcon()
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
	static FunctionDefinition funcObj("AugmentEquipBox::CheckContents", typeid(void (AugmentEquipBox::*)()), "8b818400000085c074??578d7c240883e4f0ff77fc5589e557565389cb8d4dc4", argdata, 1, 5, &func);
}

__declspec(naked) void AugmentEquipBox::CheckContents()
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
	__asm__("call %0\n\t" :: "m"(_func42::func));
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

namespace _func43
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AugmentEquipBox::RemoveItem", typeid(void (AugmentEquipBox::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec4c8b818400000085c074??", argdata, 1, 5, &func);
}

__declspec(naked) void AugmentEquipBox::RemoveItem()
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
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetBlueprintList", typeid(std::vector<std::string> &(*)(std::vector<std::string> &, BlueprintManager *, const std::string &)), "578d7c240883e4f0ff77fc5589f889e557565389cb83ec4c8b3f8b40048945c0e8????????84c08d87f4000000", argdata, 3, 0, &func);
}

__declspec(naked) std::vector<std::string> &BlueprintManager::GetBlueprintList(std::vector<std::string> &vec, BlueprintManager *bpM, const std::string &str)
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
		"ret 12\n\t"
	);
}

namespace _func45
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetShipBlueprint", typeid(ShipBlueprint *(BlueprintManager::*)(const std::string &, int )), "578d7c240883e4f0ff77fc5589e55756538d45d883ec5c8b1f8945d08b77048d7dd0894db48b038b5304", argdata, 3, 1, &func);
}

__declspec(naked) ShipBlueprint *BlueprintManager::GetShipBlueprint(const std::string &name, int sector)
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
		"push [ebp+12]\n\t"		// sector
		"push [ebp+8]\n\t"		// name
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
		"ret 8\n\t"
	);
}

namespace _func46
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetDroneBlueprint", typeid(DroneBlueprint *(BlueprintManager::*)(const std::string &)), ".578d7c240883e4f0ff77fc5589e557565389cb8d4dd083ec4c8b378dbbf4000000c70424????????e8????????", argdata, 2, 1, &func);
}

__declspec(naked) DroneBlueprint *BlueprintManager::GetDroneBlueprint(const std::string &name)
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
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetAugmentValue", typeid(float (BlueprintManager::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d714c89cb83c35083ec2c8b3f89f1", argdata, 2, 1, &func);
}

__declspec(naked) float BlueprintManager::GetAugmentValue(const std::string &name)
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
		"ret 4\n\t"
	);
}

namespace _func48
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetAugmentBlueprint", typeid(AugmentBlueprint *(BlueprintManager::*)(const std::string &)), ".578d7c240883e4f0ff77fc5589e557565389cb8d4dd083ec4c8b378dbbf4000000", argdata, 2, 1, &func);
}

__declspec(naked) AugmentBlueprint *BlueprintManager::GetAugmentBlueprint(const std::string &name)
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
	__asm__("call %0\n\t" :: "m"(_func48::func));
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

namespace _func49
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetItemBlueprint", typeid(ItemBlueprint *(BlueprintManager::*)(const std::string &)), "578d91c80000008d7c240883e4f0ff77fc5589e557565383ec3c8b99cc000000894dcc", argdata, 2, 1, &func);
}

__declspec(naked) ItemBlueprint *BlueprintManager::GetItemBlueprint(const std::string &name)
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
		"ret 4\n\t"
	);
}

namespace _func50
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::ProcessWeaponBlueprint", typeid(WeaponBlueprint *(*)(WeaponBlueprint *, BlueprintManager *, rapidxml::xml_node<char> *)), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec????????8b18899d14ffffff8b5804e8????????8b8514ffffff8d8d4cffffff8b7318895c2404890424e8????????8d954cffffff83ec088d4f1c", argdata, 3, 0, &func);
}

__declspec(naked) WeaponBlueprint *BlueprintManager::ProcessWeaponBlueprint(WeaponBlueprint *bp, BlueprintManager *bpM, rapidxml::xml_node<char> *node)
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
		"push [ebp+16]\n\t"		// node
		"push [ebp+12]\n\t"		// bpM
		"mov ecx, [ebp+8]\n\t"	// bp
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
		"ret 12\n\t"
	);
}

namespace _func51
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::ProcessDescription", typeid(Description *(*)(Description *, BlueprintManager *, rapidxml::xml_node<char> *)), "578d7c240883e4f0ff77fc5589e557565383ec7c8b5f04894d94e8????????8b5b1885db0f84????????8d75cce9????????895c2404893424e8????????", argdata, 3, 0, &func);
}

__declspec(naked) Description *BlueprintManager::ProcessDescription(Description *desc, BlueprintManager *bpM, rapidxml::xml_node<char> *node)
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
		"push [ebp+16]\n\t"		// node
		"push [ebp+12]\n\t"		// bpM
		"mov ecx, [ebp+8]\n\t"	// desc
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
		"ret 12\n\t"
	);
}

namespace _func52
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::ProcessEffectsBlueprint", typeid(EffectsBlueprint *(*)(EffectsBlueprint *, BlueprintManager *, rapidxml::xml_node<char> *)), "57660fefc08d7c240883e4f0ff77fc5589f889e557565389cf83ec5c8b308b58040f11018d41300f1141100f114120", argdata, 3, 0, &func);
}

__declspec(naked) EffectsBlueprint *BlueprintManager::ProcessEffectsBlueprint(EffectsBlueprint *bp, BlueprintManager *bpM, rapidxml::xml_node<char> *node)
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
		"push [ebp+16]\n\t"		// node
		"push [ebp+12]\n\t"		// bpM
		"mov ecx, [ebp+8]\n\t"	// bp
	);
	__asm__("call %0\n\t" :: "m"(_func52::func));
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

namespace _func53
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetCrewBlueprint", typeid(CrewBlueprint *(*)(CrewBlueprint *, BlueprintManager *, const std::string &)), "578d7c240883e4f0ff77fc5589f889e557565389cb83ec6c8b3f8b7004e8????????8d47648d5768", argdata, 3, 0, &func);
}

__declspec(naked) CrewBlueprint *BlueprintManager::GetCrewBlueprint(CrewBlueprint *bp, BlueprintManager *bpM, const std::string &name)
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
		"push [ebp+16]\n\t"		// name
		"push [ebp+12]\n\t"		// bpM
		"mov ecx, [ebp+8]\n\t"	// bp
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
		"ret 12\n\t"
	);
}

namespace _func54
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetRandomAugment", typeid(AugmentBlueprint *(*)(AugmentBlueprint *, BlueprintManager *)), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b078b57040fb64f08895424088d504c", argdata, 2, 0, &func);
}

__declspec(naked) AugmentBlueprint *BlueprintManager::GetRandomAugment(AugmentBlueprint *bp, BlueprintManager *bpM)
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
		"push [ebp+12]\n\t"		// bpM
		"mov ecx, [ebp+8]\n\t"	// bp
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
		"ret 8\n\t"
	);
}

namespace _func55
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BoarderPodDrone::constructor", typeid(void (BoarderPodDrone::*)(int , int , const DroneBlueprint &)), "578d7c240883e4f0ff77fc5589fa89e557565389cfbb????????81ec????????8b028b720889c18985acfeffff8b4204890c248974240889f989b5bcfeffff", argdata, 4, 5, &func);
}

__declspec(naked) void BoarderPodDrone::constructor(int _iShipId, int _selfId, const DroneBlueprint &_bp)
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
		"push [ebp+16]\n\t"		// _bp
		"push [ebp+12]\n\t"		// _selfId
		"push [ebp+8]\n\t"		// _iShipId
	);
	__asm__("call %0\n\t" :: "m"(_func55::func));
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

namespace _func56
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BoarderPodDrone::SetMovementTarget", typeid(void (BoarderPodDrone::*)(Targetable *)), "578d7c240883e4f0ff77fc5589e5575383ec208b0785c074??8b1089cb89815001000089c1ff521c89434c8b43048d4df0", argdata, 2, 5, &func);
}

__declspec(naked) void BoarderPodDrone::SetMovementTarget(Targetable *target)
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
		"push [ebp+8]\n\t"		// target
	);
	__asm__("call %0\n\t" :: "m"(_func56::func));
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

namespace _func57
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
		"ret\n\t"
	);
}

namespace _func58
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::IncomingFire", typeid(bool (BossShip::*)()), ".f30f108144010000f30f5c8140010000f30f100d????????0f2ec876??", argdata, 1, 1, &func);
}

__declspec(naked) bool BossShip::IncomingFire()
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
	__asm__("call %0\n\t" :: "m"(_func58::func));
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

namespace _func59
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
		"ret 4\n\t"
	);
}

namespace _func60
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
		"ret 4\n\t"
	);
}

namespace _func61
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
		"ret 4\n\t"
	);
}

namespace _func62
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
		"ret\n\t"
	);
}

namespace _func63
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
		"ret\n\t"
	);
}

namespace _func64
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
		"ret\n\t"
	);
}

namespace _func65
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
	__asm__("call %0\n\t" :: "m"(_func65::func));
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

namespace _func66
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::GetEvent", typeid(LocationEvent *(BossShip::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb", argdata, 1, 1, &func);
}

__declspec(naked) LocationEvent *BossShip::GetEvent()
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
	__asm__("call %0\n\t" :: "m"(_func66::func));
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

namespace _func67
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
	__asm__("call %0\n\t" :: "m"(_func67::func));
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

namespace _func68
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("Button::SetLocation", typeid(void (Button::*)(const Point )), "578d7c240883e4f0ff77fc5589e55783ec148b078b570489042489542404e8????????8b7dfc83ec08c98d67f85fc20800909090909090909090909090909090f3c39090909090909090909090909090c20800", argdata, 2, 5, &func);
}

__declspec(naked) void Button::SetLocation(const Point pos)
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
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// pos
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
		"ret 8\n\t"
	);
}

namespace _func69
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Button::OnInit", typeid(void (Button::*)(const std::string &, int , int )), "578d7c240883e4f0ff77fc5589e55756538d55a881ec????????8b47048b1f894d948955a08945908b47088b3b", argdata, 4, 5, &func);
}

__declspec(naked) void Button::OnInit(const std::string &img, int x, int y)
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
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// img
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
		"ret 12\n\t"
	);
}

namespace _func70
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Button::constructor", typeid(void (Button::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8d49048d732483ec2c", argdata, 1, 5, &func);
}

__declspec(naked) void Button::constructor()
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
	__asm__("call %0\n\t" :: "m"(_func70::func));
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

namespace _func71
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Button::OnRender", typeid(void (Button::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b4154", argdata, 1, 5, &func);
}

__declspec(naked) void Button::OnRender()
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
	__asm__("call %0\n\t" :: "m"(_func71::func));
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

namespace _func72
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Button::SetInactiveImage", typeid(void (Button::*)(GL_Texture *)), "5589e5565383e4f083ec108b450839414874??8941488b018b40303d????????75??8d59548d71608b03", argdata, 2, 5, &func);
}

__declspec(naked) void Button::SetInactiveImage(GL_Texture *texture)
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
		"push [ebp+8]\n\t"		// texture
	);
	__asm__("call %0\n\t" :: "m"(_func72::func));
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

namespace _func73
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Button::SetActiveImage", typeid(void (Button::*)(GL_Texture *)), ".5589e5565383e4f083ec108b450839414c74??89414c8b018b40303d????????75??8d59548d7160", argdata, 2, 5, &func);
}

__declspec(naked) void Button::SetActiveImage(GL_Texture *texture)
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
		"push [ebp+8]\n\t"		// texture
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
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Button::SetImageBase", typeid(void (Button::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d45a889cb83ec7c8b3f8945a08b178b770489d0", argdata, 2, 5, &func);
}

__declspec(naked) void Button::SetImageBase(const std::string &imageBase)
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
		"push [ebp+8]\n\t"		// imageBase
	);
	__asm__("call %0\n\t" :: "m"(_func74::func));
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

namespace _func75
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CachedImage::destructor", typeid(void (CachedImage::*)()), "558d511089e55389cb83e4f083ec108b4108c701????????39d074??890424e8????????89d9e8????????", argdata, 1, 5, &func);
}

__declspec(naked) void CachedImage::destructor()
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
		"ret\n\t"
	);
}

namespace _func76
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::SetImagePath", typeid(void (CachedImage::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565389cbb9????????83ec1c8b07890424e8????????83ec04", argdata, 2, 5, &func);
}

__declspec(naked) void CachedImage::SetImagePath(const std::string &imagePath)
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
		"push [ebp+8]\n\t"		// imagePath
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
		"ret 4\n\t"
	);
}

namespace _func77
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CAchievement::OnRender", typeid(void (CAchievement::*)(Point , int , bool )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b078b57048b77088b7f0c898568ffffff895584", argdata, 4, 5, &func);
}

__declspec(naked) void CAchievement::OnRender(Point pos, int selected, bool unk)
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
		"push [ebp+20]\n\t"		// unk
		"push [ebp+16]\n\t"		// selected
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// pos
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
		"ret 16\n\t"
	);
}

namespace _func78
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CAchievement::constructor", typeid(void (CAchievement::*)()), "578d41088d7c240883e4f0ff77fc5589e557565389cf8d75d08d5dd883ec3c8901", argdata, 1, 5, &func);
}

__declspec(naked) void CAchievement::constructor()
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
		"ret\n\t"
	);
}

namespace _func79
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
	__asm__("call %0\n\t" :: "m"(_func80::func));
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

namespace _func81
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
	__asm__("call %0\n\t" :: "m"(_func81::func));
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

namespace _func82
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
		"ret 8\n\t"
	);
}

namespace _func83
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
	__asm__("call %0\n\t" :: "m"(_func83::func));
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

namespace _func84
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
		"ret 4\n\t"
	);
}

namespace _func85
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
	__asm__("call %0\n\t" :: "m"(_func85::func));
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

namespace _func86
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
	__asm__("call %0\n\t" :: "m"(_func86::func));
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

namespace _func87
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
	__asm__("call %0\n\t" :: "m"(_func87::func));
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

namespace _func88
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
	__asm__("call %0\n\t" :: "m"(_func88::func));
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

namespace _func89
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
	__asm__("call %0\n\t" :: "m"(_func89::func));
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

namespace _func90
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
	__asm__("call %0\n\t" :: "m"(_func90::func));
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

namespace _func91
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
		"ret\n\t"
	);
}

namespace _func92
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
		"ret 4\n\t"
	);
}

namespace _func93
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
	__asm__("call %0\n\t" :: "m"(_func93::func));
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

namespace _func94
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
	__asm__("call %0\n\t" :: "m"(_func94::func));
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

namespace _func95
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
	__asm__("call %0\n\t" :: "m"(_func95::func));
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

namespace _func96
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
	__asm__("call %0\n\t" :: "m"(_func96::func));
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

namespace _func97
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
		"ret\n\t"
	);
}

namespace _func98
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
	__asm__("call %0\n\t" :: "m"(_func98::func));
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

namespace _func99
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
	__asm__("call %0\n\t" :: "m"(_func99::func));
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

namespace _func100
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
	__asm__("call %0\n\t" :: "m"(_func100::func));
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

namespace _func101
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
	__asm__("call %0\n\t" :: "m"(_func101::func));
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

namespace _func102
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
	__asm__("call %0\n\t" :: "m"(_func102::func));
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

namespace _func103
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
	__asm__("call %0\n\t" :: "m"(_func103::func));
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

namespace _func104
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
		"ret\n\t"
	);
}

namespace _func105
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
		"ret\n\t"
	);
}

namespace _func106
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
	__asm__("call %0\n\t" :: "m"(_func106::func));
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

namespace _func107
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
	__asm__("call %0\n\t" :: "m"(_func107::func));
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

namespace _func108
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnEvent", typeid(void (CApp::*)(const InputEvent *)), ".578d7c240883e4f0ff77fc5589e55783ec148b07890424e8????????", argdata, 2, 5, &func);
}

__declspec(naked) void CApp::OnEvent(const InputEvent *inputEvent)
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
		"push [ebp+8]\n\t"		// inputEvent
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
		"ret 4\n\t"
	);
}

namespace _func109
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CEvent::OnEvent", typeid(void (CEvent::*)(const InputEvent *)), "578d7c240883e4f0ff77fc5589e557565383ec4c8b1f8b4304f20f104308f20f1105????????83e80783f81b77??", argdata, 2, 5, &func);
}

__declspec(naked) void CEvent::OnEvent(const InputEvent *event)
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
		"push [ebp+8]\n\t"		// event
	);
	__asm__("call %0\n\t" :: "m"(_func109::func));
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

namespace _func110
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
	__asm__("call %0\n\t" :: "m"(_func110::func));
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

namespace _func111
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CFPS::OnLoop", typeid(void (CFPS::*)()), "578d7c240883e4f0ff77fc5589e55756538d7dd889ce8d5de083ec5ca1????????f20f1015????????893c24f20f5851088945c4", argdata, 1, 5, &func);
}

__declspec(naked) void CFPS::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func111::func));
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

namespace _func112
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ChoiceBox::OnRender", typeid(void (ChoiceBox::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????e8????????8b4350c78528feffff09000000", argdata, 1, 5, &func);
}

__declspec(naked) void ChoiceBox::OnRender()
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
		"ret\n\t"
	);
}

namespace _func114
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
	__asm__("call %0\n\t" :: "m"(_func114::func));
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

namespace _func115
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
		"ret\n\t"
	);
}

namespace _func116
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
		"ret\n\t"
	);
}

namespace _func117
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::OnRenderCombat", typeid(void (CombatControl::*)()), "80b9a80e0000000f84????????578d7c240883e4f0ff77fc5589e557565389cb83ec6c8bb15c07000085f6", argdata, 1, 5, &func);
}

__declspec(naked) void CombatControl::OnRenderCombat()
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
	__asm__("call %0\n\t" :: "m"(_func117::func));
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

namespace _func118
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::AddEnemyShip", typeid(void (CombatControl::*)(CompleteShip *)), "578d7c240883e4f0ff77fc5589e557565383ec5c8b915c0700008b0785d274??c6816011000000", argdata, 2, 5, &func);
}

__declspec(naked) void CombatControl::AddEnemyShip(CompleteShip *ship)
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
	__asm__("call %0\n\t" :: "m"(_func118::func));
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

namespace _func119
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::UpdateAiming", typeid(void (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b817007000083f8ff", argdata, 1, 5, &func);
}

__declspec(naked) void CombatControl::UpdateAiming()
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
	__asm__("call %0\n\t" :: "m"(_func119::func));
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

namespace _func120
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::UpdateTarget", typeid(bool (CombatControl::*)()), "57660fefc98d7c240883e4f0ff77fc5589e557565389cb81ec????????f30f2a4908f30f1081c40e0000f30f5cc1", argdata, 1, 1, &func);
}

__declspec(naked) bool CombatControl::UpdateTarget()
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
	__asm__("call %0\n\t" :: "m"(_func120::func));
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

namespace _func121
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::DrawHostileBox", typeid(void (CombatControl::*)(GL_Color , int )), "578d7c240883e4f0ff77fc5589e55756538d5dd089ce83ec7c8b471089d9c744240400000000c70424????????8945b8e8????????8b86680700000345d4", argdata, 3, 5, &func);
}

__declspec(naked) void CombatControl::DrawHostileBox(GL_Color color, int stencilBit)
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
		"push [ebp+24]\n\t"		// stencilBit
		"push [ebp+20]\n\t"		// color
		"push [ebp+16]\n\t"		// color
		"push [ebp+12]\n\t"		// color
		"push [ebp+8]\n\t"		// color
	);
	__asm__("call %0\n\t" :: "m"(_func121::func));
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
		"ret 20\n\t"
	);
}

namespace _func122
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("CombatControl::OnInit", typeid(void (CombatControl::*)(Point )), "578d7c240883e4f0ff77fc5589e5575389cb83ec208b078b57048981640700008b816411000089916807000085c00f84????????8d8b68110000e8????????a1????????", argdata, 2, 5, &func);
}

__declspec(naked) void CombatControl::OnInit(Point pos)
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
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// pos
	);
	__asm__("call %0\n\t" :: "m"(_func122::func));
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

namespace _func123
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::OnLoop", typeid(void (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e557565331f689cb83ec2c8b91440700008b814807000029d0c1f80285c074??", argdata, 1, 5, &func);
}

__declspec(naked) void CombatControl::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func123::func));
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

namespace _func124
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatDrone::constructor", typeid(void (CombatDrone::*)(int , int , const DroneBlueprint *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec7c8b57048b078b77088d7da889542404890424", argdata, 4, 5, &func);
}

__declspec(naked) void CombatDrone::constructor(int iShipId, int selfId, const DroneBlueprint *bp)
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
		"push [ebp+16]\n\t"		// bp
		"push [ebp+12]\n\t"		// selfId
		"push [ebp+8]\n\t"		// iShipId
	);
	__asm__("call %0\n\t" :: "m"(_func124::func));
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

namespace _func125
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CombatDrone::SetWeaponTarget", typeid(void (CombatDrone::*)(Targetable *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b3785f6", argdata, 2, 5, &func);
}

__declspec(naked) void CombatDrone::SetWeaponTarget(Targetable *target)
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
		"push [ebp+8]\n\t"		// target
	);
	__asm__("call %0\n\t" :: "m"(_func125::func));
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

namespace _func126
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
	__asm__("call %0\n\t" :: "m"(_func126::func));
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

namespace _func127
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
		"ret 4\n\t"
	);
}

namespace _func128
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
		"ret 12\n\t"
	);
}

namespace _func129
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::KeyDown", typeid(void (CommandGui::*)(SDLKey , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c80b984420000008b47048b378945b4", argdata, 3, 5, &func);
}

__declspec(naked) void CommandGui::KeyDown(SDLKey key, bool shiftHeld)
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
		"push [ebp+12]\n\t"		// shiftHeld
		"push [ebp+8]\n\t"		// key
	);
	__asm__("call %0\n\t" :: "m"(_func129::func));
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

namespace _func130
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::RenderStatic", typeid(void (CommandGui::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec6c803d??????????0f85????????8b83081700008b4808c70424????????81c1????????e8????????", argdata, 1, 5, &func);
}

__declspec(naked) void CommandGui::RenderStatic()
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
	__asm__("call %0\n\t" :: "m"(_func130::func));
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

namespace _func131
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::constructor", typeid(void (CommandGui::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8db3881e00008dbb7c2e000081ec????????e8????????8d8b78010000e8????????8d8b20030000e8????????8d8bc8030000e8????????", argdata, 1, 5, &func);
}

__declspec(naked) void CommandGui::constructor()
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
	__asm__("call %0\n\t" :: "m"(_func131::func));
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

namespace _func132
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::AddEnemyShip", typeid(void (CommandGui::*)(CompleteShip *)), "578d7c240883e4f0ff77fc5589e557565389cb81c1????????83ec5c8b378d7dc0", argdata, 2, 5, &func);
}

__declspec(naked) void CommandGui::AddEnemyShip(CompleteShip *ship)
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
	__asm__("call %0\n\t" :: "m"(_func132::func));
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

namespace _func133
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::Victory", typeid(void (CommandGui::*)()), "578d7c240883e4f0ff77fc5589e557565381ec????????8b8108170000898d7cffffff8b400880b868060000000f85????????", argdata, 1, 5, &func);
}

__declspec(naked) void CommandGui::Victory()
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
	__asm__("call %0\n\t" :: "m"(_func133::func));
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

namespace _func134
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::OnInit", typeid(void (CommandGui::*)()), "578d7c240883e4f0ff77fc5589e55756538d992003000089cf8d75cc81ec????????898d54ffffff89d9e8????????ba????????8d8d5cffffffc70424????????", argdata, 1, 5, &func);
}

__declspec(naked) void CommandGui::OnInit()
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
	__asm__("call %0\n\t" :: "m"(_func134::func));
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

namespace _func135
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::MouseMove", typeid(void (CommandGui::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389ceb9????????81ec????????8b1f8b7f04891c24897c2404e8????????8b960c1700008b8610170000", argdata, 3, 5, &func);
}

__declspec(naked) void CommandGui::MouseMove(int mX, int mY)
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
		"push [ebp+12]\n\t"		// mY
		"push [ebp+8]\n\t"		// mX
	);
	__asm__("call %0\n\t" :: "m"(_func135::func));
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

namespace _func136
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::LButtonDown", typeid(void (CommandGui::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b470480b984420000008b37", argdata, 4, 5, &func);
}

__declspec(naked) void CommandGui::LButtonDown(int mX, int mY, bool shiftHeld)
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
		"push [ebp+16]\n\t"		// shiftHeld
		"push [ebp+12]\n\t"		// mY
		"push [ebp+8]\n\t"		// mX
	);
	__asm__("call %0\n\t" :: "m"(_func136::func));
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

namespace _func137
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::OnLoop", typeid(void (CommandGui::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c0fb6b18442000089f084c00f85????????8b81d83f000085c074??", argdata, 1, 5, &func);
}

__declspec(naked) void CommandGui::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func137::func));
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

namespace _func138
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::CheckGameover", typeid(void (CommandGui::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8d45a883ec7c8b89081700008945a0c745a4000000008b7108c645a800", argdata, 1, 5, &func);
}

__declspec(naked) void CommandGui::CheckGameover()
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
	__asm__("call %0\n\t" :: "m"(_func138::func));
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

namespace _func139
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::IsGameOver", typeid(bool (CommandGui::*)()), "803d??????????75??5589e55389cb8b890817000083e4f085c974??8b41088b108b524481fa????????75??80b8990400000075??e8????????84c0", argdata, 1, 1, &func);
}

__declspec(naked) bool CommandGui::IsGameOver()
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
		"ret\n\t"
	);
}

namespace _func140
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::PauseLoop", typeid(void (CompleteShip::*)()), "558b490889e583e4f0e8????????c9c3578d7c240883e4f0ff77fc", argdata, 1, 5, &func);
}

__declspec(naked) void CompleteShip::PauseLoop()
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
		"ret\n\t"
	);
}

namespace _func141
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::Restart", typeid(void (CompleteShip::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb83ec108b4908e8????????8b43088d4b18c744240400000000", argdata, 1, 5, &func);
}

__declspec(naked) void CompleteShip::Restart()
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
	__asm__("call %0\n\t" :: "m"(_func141::func));
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

namespace _func142
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
		"ret 12\n\t"
	);
}

namespace _func143
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
	__asm__("call %0\n\t" :: "m"(_func143::func));
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

namespace _func144
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
	__asm__("call %0\n\t" :: "m"(_func144::func));
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

namespace _func145
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddBoarders", typeid(void (CompleteShip::*)(int , const std::string &, bool )), ".578d7c240883e4f0ff77fc5589f889e557565389cf8d4d8c81ec????????8b10", argdata, 4, 5, &func);
}

__declspec(naked) void CompleteShip::AddBoarders(int amount, const std::string &race, bool unk2)
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
	__asm__("call %0\n\t" :: "m"(_func145::func));
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

namespace _func146
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
		"ret 8\n\t"
	);
}

namespace _func147
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember1", typeid(CrewMember *(CompleteShip::*)(const std::string &, const std::string &, bool )), ".578d7c240883e4f0ff77fc5589e557565381ec????????8b4708", argdata, 4, 1, &func);
}

__declspec(naked) CrewMember *CompleteShip::AddCrewMember1(const std::string &race, const std::string &name, bool hostile)
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
		"push [ebp+16]\n\t"		// hostile
		"push [ebp+12]\n\t"		// name
		"push [ebp+8]\n\t"		// race
	);
	__asm__("call %0\n\t" :: "m"(_func147::func));
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

namespace _func148
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
		"ret 8\n\t"
	);
}

namespace _func149
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
		"ret 8\n\t"
	);
}

namespace _func150
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
	__asm__("call %0\n\t" :: "m"(_func150::func));
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

namespace _func151
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
	__asm__("call %0\n\t" :: "m"(_func151::func));
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

namespace _func152
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
	__asm__("call %0\n\t" :: "m"(_func152::func));
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

namespace _func153
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
	__asm__("call %0\n\t" :: "m"(_func153::func));
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

namespace _func154
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
	__asm__("call %0\n\t" :: "m"(_func154::func));
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

namespace _func155
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
	__asm__("call %0\n\t" :: "m"(_func155::func));
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

namespace _func156
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
	__asm__("call %0\n\t" :: "m"(_func156::func));
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

namespace _func157
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
	__asm__("call %0\n\t" :: "m"(_func157::func));
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

namespace _func158
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
		"ret 4\n\t"
	);
}

namespace _func159
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
	__asm__("call %0\n\t" :: "m"(_func160::func));
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

namespace _func161
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
	__asm__("call %0\n\t" :: "m"(_func161::func));
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

namespace _func162
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
	__asm__("call %0\n\t" :: "m"(_func162::func));
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

namespace _func163
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
	__asm__("call %0\n\t" :: "m"(_func163::func));
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

namespace _func164
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ConfirmWindow::SetText", typeid(void (ConfirmWindow::*)(const TextString &, int , bool , const TextString &, const TextString &)), "578d7c240883e4f0ff77fc5589f889e557565389cb83ec7c8b5008", argdata, 6, 5, &func);
}

__declspec(naked) void ConfirmWindow::SetText(const TextString &text_, int minWidth, bool autoCenter, const TextString &yesText_, const TextString &noText_)
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
		"push [ebp+24]\n\t"		// noText_
		"push [ebp+20]\n\t"		// yesText_
		"push [ebp+16]\n\t"		// autoCenter
		"push [ebp+12]\n\t"		// minWidth
		"push [ebp+8]\n\t"		// text_
	);
	__asm__("call %0\n\t" :: "m"(_func164::func));
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
		"ret 20\n\t"
	);
}

namespace _func165
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ConfirmWindow::OnRender", typeid(void (ConfirmWindow::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b8184000000", argdata, 1, 5, &func);
}

__declspec(naked) void ConfirmWindow::OnRender()
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
	__asm__("call %0\n\t" :: "m"(_func165::func));
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

namespace _func166
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("ConfirmWindow::SetPosition", typeid(void (ConfirmWindow::*)(Point )), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b078b570489042489542404e8????????8b838400000083ec08", argdata, 2, 5, &func);
}

__declspec(naked) void ConfirmWindow::SetPosition(Point pos)
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
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// pos
	);
	__asm__("call %0\n\t" :: "m"(_func166::func));
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

namespace _func167
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ConfirmWindow::Open", typeid(void (ConfirmWindow::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec3ce8????????807b7c000f84????????8b938000000089d085c00f84????????8b52088b03", argdata, 1, 5, &func);
}

__declspec(naked) void ConfirmWindow::Open()
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
	__asm__("call %0\n\t" :: "m"(_func167::func));
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

namespace _func168
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ConfirmWindow::MouseClick", typeid(void (ConfirmWindow::*)(int , int )), "8079040074??5589e55389cb83e4f083ec1080b9c80000000075??80bbb80100000074??80bbb90100000074??8b03", argdata, 3, 5, &func);
}

__declspec(naked) void ConfirmWindow::MouseClick(int mX, int mY)
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
		"push [ebp+12]\n\t"		// mY
		"push [ebp+8]\n\t"		// mX
	);
	__asm__("call %0\n\t" :: "m"(_func168::func));
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

namespace _func169
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ConfirmWindow::MouseMove", typeid(void (ConfirmWindow::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565383ec1c807904008b378b7f0474??89cb", argdata, 3, 5, &func);
}

__declspec(naked) void ConfirmWindow::MouseMove(int mX, int mY)
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
		"push [ebp+12]\n\t"		// mY
		"push [ebp+8]\n\t"		// mX
	);
	__asm__("call %0\n\t" :: "m"(_func169::func));
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

namespace _func170
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ConfirmWindow::constructor", typeid(void (ConfirmWindow::*)()), "5589e55389cb83e4f0e8????????8d43248d8b88000000c703????????c7432000000000c643240089431c8d434cc6433401c7433800000000c7434000000000894344", argdata, 1, 5, &func);
}

__declspec(naked) void ConfirmWindow::constructor()
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
	__asm__("call %0\n\t" :: "m"(_func170::func));
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

namespace _func171
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CreditScreen::OnRender", typeid(void (CreditScreen::*)()), "578d7c240883e4f0ff77fc5589e557565389ce8d7dd881ec????????e8????????b9????????e8????????8d45d88d4dd0c744240400000000", argdata, 1, 5, &func);
}

__declspec(naked) void CreditScreen::OnRender()
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
	__asm__("call %0\n\t" :: "m"(_func171::func));
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

namespace _func172
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CreditScreen::constructor", typeid(void (CreditScreen::*)()), "8d410cc7410800000000c6410c00c7412000000000c64124008941048d4124c7413400000000c7413c00000000c741400000000089411cc7414400000000c7414800000000", argdata, 1, 5, &func);
}

__declspec(naked) void CreditScreen::constructor()
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
	__asm__("call %0\n\t" :: "m"(_func172::func));
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

namespace _func173
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CreditScreen::Start", typeid(void (CreditScreen::*)(const std::string &, const std::vector<std::string> &)), "578d7c240883e4f0ff77fc5589f889e557565389cf8d9d20ffffff81ec????????8b088b4004c744240400000000899d18ffffffc78500ffffff100000008985b8feffff8d8500ffffff", argdata, 3, 5, &func);
}

__declspec(naked) void CreditScreen::Start(const std::string &shipName, const std::vector<std::string> &crewNames)
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
		"push [ebp+12]\n\t"		// crewNames
		"push [ebp+8]\n\t"		// shipName
	);
	__asm__("call %0\n\t" :: "m"(_func173::func));
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

namespace _func174
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CreditScreen::Done", typeid(bool (CreditScreen::*)()), "55660fefc089e553bb????????83e4f083ec108b51402b513cc1fa0369d2????????89d0f7e3b8????????d1ea8d1492c1e20329d0f30f2ac00f2e01", argdata, 1, 1, &func);
}

__declspec(naked) bool CreditScreen::Done()
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
	__asm__("call %0\n\t" :: "m"(_func174::func));
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

namespace _func175
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAI::UpdateDrones", typeid(void (CrewAI::*)()), "578d7c240883e4f0ff77fc5589e557565381ec????????8b510c8b4110c745940000000029d0c1f80285c00f84????????89cfeb??", argdata, 1, 5, &func);
}

__declspec(naked) void CrewAI::UpdateDrones()
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
	__asm__("call %0\n\t" :: "m"(_func175::func));
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

namespace _func176
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAI::AssignCrewmembers", typeid(void (CrewAI::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b49308b463429c8c1f80269c0????????", argdata, 1, 5, &func);
}

__declspec(naked) void CrewAI::AssignCrewmembers()
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
	__asm__("call %0\n\t" :: "m"(_func176::func));
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

namespace _func177
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x3ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAI::PrioritizeTask", typeid(int (CrewAI::*)(CrewTask , int )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec2c8b700c8b188b50048b4008", argdata, 3, 1, &func);
}

__declspec(naked) int CrewAI::PrioritizeTask(CrewTask task, int crewId)
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
		"push [ebp+20]\n\t"		// crewId
		"push [ebp+16]\n\t"		// task
		"push [ebp+12]\n\t"		// task
		"push [ebp+8]\n\t"		// task
	);
	__asm__("call %0\n\t" :: "m"(_func177::func));
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

namespace _func178
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAI::UpdateIntruders", typeid(void (CrewAI::*)()), "8b511c8b411839d00f84????????5729c2c1fa028d7c240883e4f0ff77fc5589e557565331db89ce83ec3c", argdata, 1, 5, &func);
}

__declspec(naked) void CrewAI::UpdateIntruders()
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
	__asm__("call %0\n\t" :: "m"(_func178::func));
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

namespace _func179
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAI::PrioritizeIntruderRoom", typeid(int (CrewAI::*)(CrewMember *, int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b078b77048b7f088945e4897dd889c78b4078c70424????????", argdata, 4, 1, &func);
}

__declspec(naked) int CrewAI::PrioritizeIntruderRoom(CrewMember *crew, int roomId, int target)
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
		"push [ebp+16]\n\t"		// target
		"push [ebp+12]\n\t"		// roomId
		"push [ebp+8]\n\t"		// crew
	);
	__asm__("call %0\n\t" :: "m"(_func179::func));
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

namespace _func180
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewAI::UpdateCrewMember", typeid(void (CrewAI::*)(int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec5c8b410c8b178b3c908b87a80100008b9fa4010000", argdata, 2, 5, &func);
}

__declspec(naked) void CrewAI::UpdateCrewMember(int crewId)
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
		"push [ebp+8]\n\t"		// crewId
	);
	__asm__("call %0\n\t" :: "m"(_func180::func));
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

namespace _func181
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAI::CheckForHealing", typeid(void (CrewAI::*)()), "8b510c8b4110c641070029d0c1f80285c00f84????????578d7c240883e4f0ff77fc5589e557565389ce31db83ec3c", argdata, 1, 5, &func);
}

__declspec(naked) void CrewAI::CheckForHealing()
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
	__asm__("call %0\n\t" :: "m"(_func181::func));
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

namespace _func182
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAI::OnLoop", typeid(void (CrewAI::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec6c8b018d4dd0890424e8????????8b55d08b460c", argdata, 1, 5, &func);
}

__declspec(naked) void CrewAI::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func182::func));
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

namespace _func183
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAI::CheckForProblems", typeid(void (CrewAI::*)()), "578d7c240883e4f0ff77fc5589e557565389cf83ec7c8b01c64108018b4004890424", argdata, 1, 5, &func);
}

__declspec(naked) void CrewAI::CheckForProblems()
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
	__asm__("call %0\n\t" :: "m"(_func183::func));
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

namespace _func184
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::constructor", typeid(void (CrewAnimation::*)(int , const std::string &, Pointf , bool )), "578d7c240883e4f0ff77fc5589e557565381ec????????8b57048b078b5f088b770c894da0", argdata, 5, 5, &func);
}

__declspec(naked) void CrewAnimation::constructor(int shipId, const std::string &race, Pointf unk, bool hostile)
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
		"push [ebp+24]\n\t"		// hostile
		"push [ebp+20]\n\t"		// unk
		"push [ebp+16]\n\t"		// unk
		"push [ebp+12]\n\t"		// race
		"push [ebp+8]\n\t"		// shipId
	);
	__asm__("call %0\n\t" :: "m"(_func184::func));
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
		"ret 20\n\t"
	);
}

namespace _func185
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::GetDeathSound", typeid(std::string &(*)(std::string &, CrewAnimation *)), "578d7c240883e4f0ff77fc5589e5575389cb83ec308b0780b8c40900000074??803d??????????0f85????????", argdata, 2, 0, &func);
}

__declspec(naked) std::string &CrewAnimation::GetDeathSound(std::string &strRef, CrewAnimation *anim)
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
		"push [ebp+12]\n\t"		// anim
		"mov ecx, [ebp+8]\n\t"	// strRef
	);
	__asm__("call %0\n\t" :: "m"(_func185::func));
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

namespace _func186
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::GetShootingSound", typeid(std::string &(*)(std::string &, CrewAnimation *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c803d??????????0f84????????e8????????89c189c8ba????????8d75d0f7ea", argdata, 2, 0, &func);
}

__declspec(naked) std::string &CrewAnimation::GetShootingSound(std::string &strRef, CrewAnimation *anim)
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
		"push [ebp+12]\n\t"		// anim
		"mov ecx, [ebp+8]\n\t"	// strRef
	);
	__asm__("call %0\n\t" :: "m"(_func186::func));
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

namespace _func187
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::OnRender", typeid(void (CrewAnimation::*)(float , int , bool )), "578d7c240883e4f0ff77fc5589f889e557565383ec7c8b59048b7008f30f102f8b7f04", argdata, 4, 5, &func);
}

__declspec(naked) void CrewAnimation::OnRender(float scale, int selectedState, bool outlineOnly)
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
		"push [ebp+16]\n\t"		// outlineOnly
		"push [ebp+12]\n\t"		// selectedState
		"push [ebp+8]\n\t"		// scale
	);
	__asm__("call %0\n\t" :: "m"(_func187::func));
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

namespace _func188
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAnimation::OnRenderProps", typeid(void (CrewAnimation::*)()), "578d7c240883e4f0ff77fc5589e557565389cb31f683ec3ce8????????8b93900800008b8394080000", argdata, 1, 5, &func);
}

__declspec(naked) void CrewAnimation::OnRenderProps()
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
	__asm__("call %0\n\t" :: "m"(_func188::func));
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

namespace _func189
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::OnInit", typeid(void (CrewAnimation::*)(const std::string &, Pointf , bool )), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????8b078b570889c18985dcfeffff", argdata, 4, 5, &func);
}

__declspec(naked) void CrewAnimation::OnInit(const std::string &name, Pointf position, bool enemy)
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
		"push [ebp+20]\n\t"		// enemy
		"push [ebp+16]\n\t"		// position
		"push [ebp+12]\n\t"		// position
		"push [ebp+8]\n\t"		// name
	);
	__asm__("call %0\n\t" :: "m"(_func189::func));
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

namespace _func190
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAnimation::SetupStrips", typeid(void (CrewAnimation::*)()), "578d7c240883e4f0ff77fc5589e557568d8578feffff5389cf81ec????????898570feffff8b91ac0900008b81a80900008d8d70feffff", argdata, 1, 5, &func);
}

__declspec(naked) void CrewAnimation::SetupStrips()
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
	__asm__("call %0\n\t" :: "m"(_func190::func));
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

namespace _func191
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::OnUpdate", typeid(void (CrewAnimation::*)(Pointf , bool , bool , bool , bool , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b078b57048b4f088b770c8945c08b47108955c48b57148b7f188945bc8b433883f8060f84????????84d20f85????????80bbec09000000", argdata, 7, 5, &func);
}

__declspec(naked) void CrewAnimation::OnUpdate(Pointf position, bool moving, bool fighting, bool repairing, bool dying, bool onFire)
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
		"push [ebp+32]\n\t"		// onFire
		"push [ebp+28]\n\t"		// dying
		"push [ebp+24]\n\t"		// repairing
		"push [ebp+20]\n\t"		// fighting
		"push [ebp+16]\n\t"		// moving
		"push [ebp+12]\n\t"		// position
		"push [ebp+8]\n\t"		// position
	);
	__asm__("call %0\n\t" :: "m"(_func191::func));
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
		"ret 28\n\t"
	);
}

namespace _func192
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAnimation::destructor", typeid(void (CrewAnimation::*)()), "5589e557565383e4f083ec308b81c8090000c701????????894c242085c074??890424e8????????8b4c24208b81a80900008d91b009000039d074??890424", argdata, 1, 5, &func);
}

__declspec(naked) void CrewAnimation::destructor()
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
	__asm__("call %0\n\t" :: "m"(_func192::func));
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

namespace _func193
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAnimation::FireShot", typeid(bool (CrewAnimation::*)()), "5589e5538d999c08000083e4f089d9e8????????89d9e8????????8b5dfc", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewAnimation::FireShot()
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
	__asm__("call %0\n\t" :: "m"(_func193::func));
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

namespace _func194
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAnimation::GetFiringFrame", typeid(int (CrewAnimation::*)()), "8b413483f8ff74??8b513c89d183e1fd83f90174??83fa0274??83f8010f94c00fb6c083c001c389f68dbc270000000083f8020f94c0", argdata, 1, 1, &func);
}

__declspec(naked) int CrewAnimation::GetFiringFrame()
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
	__asm__("call %0\n\t" :: "m"(_func194::func));
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

namespace _func195
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewBlueprint::RandomSkills", typeid(void (CrewBlueprint::*)(int )), "578d7c240883e4f0ff77fc5589fa89e557565389cb83ec3c8b07c745d80000000085c0", argdata, 2, 5, &func);
}

__declspec(naked) void CrewBlueprint::RandomSkills(int worldLevel)
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
		"push [ebp+8]\n\t"		// worldLevel
	);
	__asm__("call %0\n\t" :: "m"(_func195::func));
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

namespace _func196
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewBlueprint::RenderSkill", typeid(void (CrewBlueprint::*)(int , int , int , int , int )), "57660fefc0660fefc98d7c240883e4f0ff77fc5589e557565383ec7c8b078b57108b77088b5f0c8945d48b47048bb904010000", argdata, 6, 5, &func);
}

__declspec(naked) void CrewBlueprint::RenderSkill(int x, int y, int length, int height, int skill)
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
		"push [ebp+24]\n\t"		// skill
		"push [ebp+20]\n\t"		// height
		"push [ebp+16]\n\t"		// length
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func196::func));
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
		"ret 20\n\t"
	);
}

namespace _func197
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewBlueprint::RenderIcon", typeid(void (CrewBlueprint::*)(float )), "578d7c240883e4f0ff77fc5589e557568d8520ffffff5389ce8d9d20ffffff81ec????????898518ffffff8b51088b4104f30f10278dbd18fffffff30f11a5b0fdffff01c289042489f989542404", argdata, 2, 5, &func);
}

__declspec(naked) void CrewBlueprint::RenderIcon(float opacity)
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
		"push [ebp+8]\n\t"		// opacity
	);
	__asm__("call %0\n\t" :: "m"(_func197::func));
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

namespace _func198
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewBlueprint::destructor", typeid(void (CrewBlueprint::*)()), "5589e557565389ce83e4f083ec108b811c010000c701????????85c074??890424e8????????8bbe140100008b9e1001000039df74??", argdata, 1, 5, &func);
}

__declspec(naked) void CrewBlueprint::destructor()
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
	__asm__("call %0\n\t" :: "m"(_func198::func));
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

namespace _func199
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewBox::constructor", typeid(void (CrewBox::*)(Point , CrewMember *, int )), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec????????8b70088b088b50048b580c", argdata, 4, 5, &func);
}

__declspec(naked) void CrewBox::constructor(Point pos, CrewMember *crew, int number)
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
		"push [ebp+20]\n\t"		// number
		"push [ebp+16]\n\t"		// crew
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// pos
	);
	__asm__("call %0\n\t" :: "m"(_func199::func));
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

namespace _func200
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewBox::OnRender", typeid(void (CrewBox::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81c1????????83ec6ce8????????8d8b74020000e8????????", argdata, 1, 5, &func);
}

__declspec(naked) void CrewBox::OnRender()
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
	__asm__("call %0\n\t" :: "m"(_func200::func));
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

namespace _func201
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewBox::GetSelected", typeid(CrewMember *(CrewBox::*)(int , int )), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec????????8b308b4004c744240c00000000", argdata, 3, 1, &func);
}

__declspec(naked) CrewMember *CrewBox::GetSelected(int mouseX, int mouseY)
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
		"push [ebp+12]\n\t"		// mouseY
		"push [ebp+8]\n\t"		// mouseX
	);
	__asm__("call %0\n\t" :: "m"(_func201::func));
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

namespace _func202
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewBox::OnLoop", typeid(void (CrewBox::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b49208b378b11", argdata, 2, 5, &func);
}

__declspec(naked) void CrewBox::OnLoop(bool selected)
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
		"push [ebp+8]\n\t"		// selected
	);
	__asm__("call %0\n\t" :: "m"(_func202::func));
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

namespace _func203
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewBox::OnRenderSkillLevel", typeid(void (CrewBox::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec3080b9300100000075??8b43048d4de8", argdata, 1, 5, &func);
}

__declspec(naked) void CrewBox::OnRenderSkillLevel()
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
	__asm__("call %0\n\t" :: "m"(_func203::func));
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

namespace _func204
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewControl::OnRender", typeid(void (CrewControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec7c8b793c8b414029f8c1f80285c0", argdata, 1, 5, &func);
}

__declspec(naked) void CrewControl::OnRender()
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
	__asm__("call %0\n\t" :: "m"(_func204::func));
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

namespace _func205
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewControl::OnLoop", typeid(void (CrewControl::*)()), "578d7c240883e4f0ff77fc5589e557568db18c0000005389cb83ec6c89f1e8????????80bb9e000000000f85????????89d9", argdata, 1, 5, &func);
}

__declspec(naked) void CrewControl::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func205::func));
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

namespace _func206
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewControl::UpdateCrewBoxes", typeid(void (CrewControl::*)()), "578d7c240883e4f0ff77fc5589e55756538d45dc89cbb9????????83ec5cc745dc00000000c745e000000000890424c744240400000000", argdata, 1, 5, &func);
}

__declspec(naked) void CrewControl::UpdateCrewBoxes()
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
	__asm__("call %0\n\t" :: "m"(_func206::func));
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

namespace _func207
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewControl::LinkShip", typeid(void (CrewControl::*)(ShipManager *)), "5589e55389cb8b450883e4f08901e8????????c7432000000000c7431c000000008b5dfc", argdata, 2, 5, &func);
}

__declspec(naked) void CrewControl::LinkShip(ShipManager *ship)
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
	__asm__("call %0\n\t" :: "m"(_func207::func));
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

namespace _func208
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewControl::MouseMove", typeid(void (CrewControl::*)(int , int , int , int )), "578d7c240883e4f0ff77fc5589e557565381ec????????8b57088b378b4704", argdata, 5, 5, &func);
}

__declspec(naked) void CrewControl::MouseMove(int mX, int mY, int wX, int wY)
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
		"push [ebp+20]\n\t"		// wY
		"push [ebp+16]\n\t"		// wX
		"push [ebp+12]\n\t"		// mY
		"push [ebp+8]\n\t"		// mX
	);
	__asm__("call %0\n\t" :: "m"(_func208::func));
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

namespace _func209
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewControl::LButton", typeid(void (CrewControl::*)(int , int , int , int , bool )), "578d7c240883e4f0ff77fc5589f889e557565389cb83ec5c8b178b89840000008b7f048955b48b50088b400c", argdata, 6, 5, &func);
}

__declspec(naked) void CrewControl::LButton(int mX, int mY, int wX, int wY, bool shiftHeld)
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
		"push [ebp+24]\n\t"		// shiftHeld
		"push [ebp+20]\n\t"		// wY
		"push [ebp+16]\n\t"		// wX
		"push [ebp+12]\n\t"		// mY
		"push [ebp+8]\n\t"		// mX
	);
	__asm__("call %0\n\t" :: "m"(_func209::func));
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
		"ret 20\n\t"
	);
}

namespace _func210
{
	static void *func = 0;
	static short argdata[] = {0x4ff};
	static FunctionDefinition funcObj("CrewControl::ClearDeadCrew", typeid(void (*)(std::vector<CrewMember*> )), "5589e557565383e4f083ec208b45088b50048b3089d029f0c1f80285c00f84????????31db", argdata, 1, 4, &func);
}

__declspec(naked) void CrewControl::ClearDeadCrew(std::vector<CrewMember*> crew)
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
		"push [ebp+20]\n\t"		// crew
		"push [ebp+16]\n\t"		// crew
		"push [ebp+12]\n\t"		// crew
		"push [ebp+8]\n\t"		// crew
	);
	__asm__("call %0\n\t" :: "m"(_func210::func));
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

namespace _func211
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewControl::ClearCrewBoxes", typeid(void (CrewControl::*)()), "5589e557565389ce83e4f083ec108b513c8b494089c829d083f8037e??31db908b3c9a85ff", argdata, 1, 5, &func);
}

__declspec(naked) void CrewControl::ClearCrewBoxes()
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
	__asm__("call %0\n\t" :: "m"(_func211::func));
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

namespace _func212
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewDrone::constructor", typeid(void (CrewDrone::*)(const std::string &, const std::string &, int , const DroneBlueprint *, CrewAnimation *)), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec????????8b70048b088b580c89b574feffff8b70088b4010899d5cfeffff8b5904", argdata, 6, 5, &func);
}

__declspec(naked) void CrewDrone::constructor(const std::string &type, const std::string &name, int shipId, const DroneBlueprint *blueprint, CrewAnimation *anim)
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
		"push [ebp+24]\n\t"		// anim
		"push [ebp+20]\n\t"		// blueprint
		"push [ebp+16]\n\t"		// shipId
		"push [ebp+12]\n\t"		// name
		"push [ebp+8]\n\t"		// type
	);
	__asm__("call %0\n\t" :: "m"(_func212::func));
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
		"ret 20\n\t"
	);
}

namespace _func213
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewDrone::OnLoop", typeid(void (CrewDrone::*)()), "578d7c240883e4f0ff77fc5589e557568db15c0700005389cb83ec4c89f1e8????????80bbfc0100000074??80bb7007000000", argdata, 1, 5, &func);
}

__declspec(naked) void CrewDrone::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func213::func));
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

namespace _func214
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewDrone::ProvidesVision", typeid(bool (CrewDrone::*)()), "8b410485c074??0fb6813d05000084c074??8b815c0700008d915c0700008b40303d????????75??0fb68170070000c3f3c35589d1", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewDrone::ProvidesVision()
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
	__asm__("call %0\n\t" :: "m"(_func214::func));
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

namespace _func215
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewDrone::SetCurrentShip", typeid(void (CrewDrone::*)(int )), ".578d7c240883e4f0ff77fc5589e55783ec148b07890424e8????????8b7dfc83ec04c98d67f85f", argdata, 2, 5, &func);
}

__declspec(naked) void CrewDrone::SetCurrentShip(int shipId)
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
		"push [ebp+8]\n\t"		// shipId
	);
	__asm__("call %0\n\t" :: "m"(_func215::func));
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

namespace _func216
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewDrone::destructor", typeid(void (CrewDrone::*)()), "558d910809000089e557565383e4f083ec208b8100090000c701????????894c2", argdata, 1, 5, &func);
}

__declspec(naked) void CrewDrone::destructor()
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
	__asm__("call %0\n\t" :: "m"(_func216::func));
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

namespace _func217
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewEquipBox::RemoveItem", typeid(void (CrewEquipBox::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b496885c974??80bb6e0200000075??c70424????????e8????????", argdata, 1, 5, &func);
}

__declspec(naked) void CrewEquipBox::RemoveItem()
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
	__asm__("call %0\n\t" :: "m"(_func217::func));
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

namespace _func218
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::constructor", typeid(void (CrewEquipBox::*)(Point , ShipManager *, int )), "578d7c240883e4f0ff77fc5589e557565389cb8d4d9881ec????????8b77088b07", argdata, 4, 5, &func);
}

__declspec(naked) void CrewEquipBox::constructor(Point pos, ShipManager *ship, int slot)
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
		"push [ebp+20]\n\t"		// slot
		"push [ebp+16]\n\t"		// ship
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// pos
	);
	__asm__("call %0\n\t" :: "m"(_func218::func));
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

namespace _func219
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewEquipBox::GetConfirmDelete", typeid(bool (CrewEquipBox::*)()), "0fb681d0020000c681d002000000", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewEquipBox::GetConfirmDelete()
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
	__asm__("call %0\n\t" :: "m"(_func219::func));
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

namespace _func220
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::RenderLabels", typeid(void (CrewEquipBox::*)(bool , bool )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b51608b078b770485d20f84????????0fb68b6c02000083f10109c889f138c10f87????????f30f102d????????", argdata, 3, 5, &func);
}

__declspec(naked) void CrewEquipBox::RenderLabels(bool dragging, bool isNew)
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
		"push [ebp+12]\n\t"		// isNew
		"push [ebp+8]\n\t"		// dragging
	);
	__asm__("call %0\n\t" :: "m"(_func220::func));
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

namespace _func221
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::OnRender", typeid(void (CrewEquipBox::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389ceb9????????83ec6c8b1fe8????????83f8018d968c0000000f9fc00fb6c089d1", argdata, 2, 5, &func);
}

__declspec(naked) void CrewEquipBox::OnRender(bool unk)
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
	__asm__("call %0\n\t" :: "m"(_func221::func));
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

namespace _func222
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::OnTextInput", typeid(void (CrewEquipBox::*)(SDLKey )), "578d7c240883e4f0ff77fc5589e55756538d997002000083ec1c89d98b37e8????????84c074??893424", argdata, 2, 5, &func);
}

__declspec(naked) void CrewEquipBox::OnTextInput(SDLKey key)
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
	__asm__("call %0\n\t" :: "m"(_func222::func));
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

namespace _func223
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::OnTextEvent", typeid(void (CrewEquipBox::*)(CEvent::TextEvent )), ".578d7c240883e4f0ff77fc5589e55756538d997002000083ec1c89d98b37e8????????84c074??893424", argdata, 2, 5, &func);
}

__declspec(naked) void CrewEquipBox::OnTextEvent(CEvent::TextEvent event)
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
		"push [ebp+8]\n\t"		// event
	);
	__asm__("call %0\n\t" :: "m"(_func223::func));
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

namespace _func224
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::MouseClick", typeid(void (CrewEquipBox::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565383ec6c8b716085f60f84????????80b96c0200000089cb74??80bbcc0000000074??", argdata, 3, 5, &func);
}

__declspec(naked) void CrewEquipBox::MouseClick(int mX, int mY)
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
		"push [ebp+12]\n\t"		// mY
		"push [ebp+8]\n\t"		// mX
	);
	__asm__("call %0\n\t" :: "m"(_func224::func));
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

namespace _func225
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewEquipBox::CloseRename", typeid(void (CrewEquipBox::*)()), "80b96e0200000075??c38db6000000005581c1????????c641fe0089e583e4f0", argdata, 1, 5, &func);
}

__declspec(naked) void CrewEquipBox::CloseRename()
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
	__asm__("call %0\n\t" :: "m"(_func225::func));
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

namespace _func226
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::OnInit", typeid(void (CrewManifest::*)(ShipManager *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b078bb9d80000008b91d40000008945cc89f829d083f8037e??31f68b0cb285c974??8b01", argdata, 2, 5, &func);
}

__declspec(naked) void CrewManifest::OnInit(ShipManager *ship)
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
	__asm__("call %0\n\t" :: "m"(_func226::func));
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

namespace _func227
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewManifest::OnRender", typeid(void (CrewManifest::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????e8????????8b831c02000085c078??0f2805????????c70424????????0f2945c8", argdata, 1, 5, &func);
}

__declspec(naked) void CrewManifest::OnRender()
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
	__asm__("call %0\n\t" :: "m"(_func227::func));
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

namespace _func228
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewManifest::constructor", typeid(void (CrewManifest::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8d7d948d75d481ec????????e8????????8d4320c703????????89c1898554ffffff", argdata, 1, 5, &func);
}

__declspec(naked) void CrewManifest::constructor()
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
	__asm__("call %0\n\t" :: "m"(_func228::func));
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

namespace _func229
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewManifest::Update", typeid(void (CrewManifest::*)()), "578d7c240883e4f0ff77fc5589e55756538d45cc89ceb9????????83ec3cc745cc00000000c745d000000000890424c744240800000000", argdata, 1, 5, &func);
}

__declspec(naked) void CrewManifest::Update()
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
	__asm__("call %0\n\t" :: "m"(_func229::func));
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

namespace _func230
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::OnKeyDown", typeid(void (CrewManifest::*)(SDLKey )), "578d7c240883e4f0ff77fc5589e557565383ec1c8b91d40000008b81d80000008b3729d0c1f80285c074??89cf31db", argdata, 2, 5, &func);
}

__declspec(naked) void CrewManifest::OnKeyDown(SDLKey key)
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
	__asm__("call %0\n\t" :: "m"(_func230::func));
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

namespace _func231
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::OnKeyUp", typeid(void (CrewManifest::*)(SDLKey )), ".578d7c240883e4f0ff77fc5589e557565383ec1c8b91d40000008b81d80000008b3729d0c1f80285c074??", argdata, 2, 5, &func);
}

__declspec(naked) void CrewManifest::OnKeyUp(SDLKey key)
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
	__asm__("call %0\n\t" :: "m"(_func231::func));
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

namespace _func232
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::OnTextInput", typeid(void (CrewManifest::*)(SDLKey )), ".578d7c240883e4f0ff77fc5589e557565383ec1c8b91d40000008b81d80000008b3729d0c1f80285c074??89cf31db", argdata, 2, 5, &func);
}

__declspec(naked) void CrewManifest::OnTextInput(SDLKey key)
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
	__asm__("call %0\n\t" :: "m"(_func232::func));
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

namespace _func233
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::OnTextEvent", typeid(void (CrewManifest::*)(CEvent::TextEvent )), ".578d7c240883e4f0ff77fc5589e557565383ec1c8b91d40000008b81d80000008b3729d0c1f80285c074??89cf31db", argdata, 2, 5, &func);
}

__declspec(naked) void CrewManifest::OnTextEvent(CEvent::TextEvent event)
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
		"push [ebp+8]\n\t"		// event
	);
	__asm__("call %0\n\t" :: "m"(_func233::func));
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

namespace _func234
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewManifest::Close", typeid(void (CrewManifest::*)()), "5589e556538b91d40000008b81d800000031db83e4f089ce29d0c1f80285c075??eb??8b96d40000008b86d800000083c30129d0c1f802", argdata, 1, 5, &func);
}

__declspec(naked) void CrewManifest::Close()
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
	__asm__("call %0\n\t" :: "m"(_func234::func));
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

namespace _func235
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::MouseClick", typeid(void (CrewManifest::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec1c8b891c0200008b078b570485c978??8d8e2002000089542404890424e8????????83ec08", argdata, 3, 5, &func);
}

__declspec(naked) void CrewManifest::MouseClick(int mX, int mY)
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
		"push [ebp+12]\n\t"		// mY
		"push [ebp+8]\n\t"		// mX
	);
	__asm__("call %0\n\t" :: "m"(_func235::func));
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

namespace _func236
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::MouseMove", typeid(void (CrewManifest::*)(int , int )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec2c8b308b40048945e48d81e000000089c1", argdata, 3, 5, &func);
}

__declspec(naked) void CrewManifest::MouseMove(int mX, int mY)
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
		"push [ebp+12]\n\t"		// mY
		"push [ebp+8]\n\t"		// mX
	);
	__asm__("call %0\n\t" :: "m"(_func236::func));
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

namespace _func237
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CanSabotage", typeid(bool (CrewMember::*)()), ".0fb68198000000", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::CanSabotage()
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
	__asm__("call %0\n\t" :: "m"(_func237::func));
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

namespace _func238
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CanRepair", typeid(bool (CrewMember::*)()), "80b9980000000074??31c0c38d7426008b015589e55389cb8b8088000000", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::CanRepair()
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
	__asm__("call %0\n\t" :: "m"(_func238::func));
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

namespace _func239
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CanMan", typeid(bool (CrewMember::*)()), "0fb6819800000084c075??f30f1081080700000f2e05????????76??f3c3", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::CanMan()
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
	__asm__("call %0\n\t" :: "m"(_func239::func));
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

namespace _func240
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CanHeal", typeid(bool (CrewMember::*)()), "f30f1041280f2e412c7a??75??5589e55389cb83e4f080796c0075??8b8300020000", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::CanHeal()
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
	__asm__("call %0\n\t" :: "m"(_func240::func));
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

namespace _func241
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::OnRender", typeid(void (CrewMember::*)(bool )), ".578d7c240883e4f0ff77fc5589e5575383ec3080b9fc010000008b3f74??8d65f85b5f5d8d67f8", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::OnRender(bool outlineOnly)
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
		"push [ebp+8]\n\t"		// outlineOnly
	);
	__asm__("call %0\n\t" :: "m"(_func241::func));
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

namespace _func242
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetRoomDamage", typeid(Damage *(*)(Damage *, CrewMember *)), "89c8c701????????c7410400000000c7410800000000c7410c00000000c7411000000000c7411400000000c7411800000000c7411c00000000c6412000", argdata, 2, 0, &func);
}

__declspec(naked) Damage *CrewMember::GetRoomDamage(Damage *dmg, CrewMember *crew)
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
		"push [ebp+12]\n\t"		// crew
		"mov ecx, [ebp+8]\n\t"	// dmg
	);
	__asm__("call %0\n\t" :: "m"(_func242::func));
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

namespace _func243
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::constructor", typeid(void (CrewMember::*)(CrewBlueprint &, int , bool , CrewAnimation *)), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec????????8b308b5808", argdata, 5, 5, &func);
}

__declspec(naked) void CrewMember::constructor(CrewBlueprint &blueprint, int shipId, bool intruder, CrewAnimation *animation)
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
		"push [ebp+16]\n\t"		// intruder
		"push [ebp+12]\n\t"		// shipId
		"push [ebp+8]\n\t"		// blueprint
	);
	__asm__("call %0\n\t" :: "m"(_func243::func));
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

namespace _func244
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::Jump", typeid(void (CrewMember::*)(bool )), "8b81f00400005589e583e4f083400c018b01ff90cc000000", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::Jump(bool outlineOnly)
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
		"push [ebp+8]\n\t"		// outlineOnly
	);
	__asm__("call %0\n\t" :: "m"(_func244::func));
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

namespace _func245
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::NeedsIntruderSlot", typeid(bool (CrewMember::*)()), ".80b93d050000008b410475??398160010000", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::NeedsIntruderSlot()
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
	__asm__("call %0\n\t" :: "m"(_func245::func));
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

namespace _func246
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::SetOutOfGame", typeid(void (CrewMember::*)()), ".a1????????c681e001000001c681fc01000001c7810807000000000000", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::SetOutOfGame()
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
	__asm__("call %0\n\t" :: "m"(_func246::func));
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

namespace _func247
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::PositionShift", typeid(float (CrewMember::*)()), ".55660fefc989e583ec04f30f2a8990000000f30f1015????????f30f104108f30f5cc1", argdata, 1, 1, &func);
}

__declspec(naked) float CrewMember::PositionShift()
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
	__asm__("call %0\n\t" :: "m"(_func247::func));
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

namespace _func248
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SaveState", typeid(void (CrewMember::*)(int )), ".578d7c240883e4f0ff77fc5589f889e557565389cf31f683ec1c8b18f30f108108070000f30f11442404891c24e8????????", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SaveState(int fileHelper)
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
		"push [ebp+8]\n\t"		// fileHelper
	);
	__asm__("call %0\n\t" :: "m"(_func248::func));
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

namespace _func249
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CanTeleport", typeid(bool (CrewMember::*)()), ".8b819c000000837838030f84????????55660fefc9", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::CanTeleport()
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
	__asm__("call %0\n\t" :: "m"(_func249::func));
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

namespace _func250
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::destructor", typeid(void (CrewMember::*)()), ".5589e5575653", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::destructor()
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
	__asm__("call %0\n\t" :: "m"(_func250::func));
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

namespace _func251
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Cleanup", typeid(void (CrewMember::*)()), ".5589e55389cb", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::Cleanup()
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
	__asm__("call %0\n\t" :: "m"(_func251::func));
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

namespace _func252
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::LoadState", typeid(void (CrewMember::*)(int )), ".578d7c240883e4f0ff77fc5589f889e557565389cf83ec2c8b30893424e8????????d95de48b45e4893424", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::LoadState(int fileHelper)
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
		"push [ebp+8]\n\t"		// fileHelper
	);
	__asm__("call %0\n\t" :: "m"(_func252::func));
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

namespace _func253
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetCurrentSystem", typeid(void (CrewMember::*)(ShipSystem *)), ".578d7c240883e4f0ff77fc", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SetCurrentSystem(ShipSystem *sys)
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
		"push [ebp+8]\n\t"		// sys
	);
	__asm__("call %0\n\t" :: "m"(_func253::func));
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

namespace _func254
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::IsManningArtillery", typeid(bool (CrewMember::*)()), ".83797c0b0f94c0", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::IsManningArtillery()
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
	__asm__("call %0\n\t" :: "m"(_func254::func));
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

namespace _func255
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::IncreaseSkill", typeid(void (CrewMember::*)(int )), ".578d7c240883e4f0ff77fc55", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::IncreaseSkill(int skillId)
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
		"push [ebp+8]\n\t"		// skillId
	);
	__asm__("call %0\n\t" :: "m"(_func255::func));
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

namespace _func256
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CheckSkills", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc55", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::CheckSkills()
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
	__asm__("call %0\n\t" :: "m"(_func256::func));
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

namespace _func257
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::MasterSkill", typeid(void (CrewMember::*)(int )), ".8b81140300008b5424048d04d08b5004", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::MasterSkill(int skillId)
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
		"push [ebp+8]\n\t"		// skillId
	);
	__asm__("call %0\n\t" :: "m"(_func257::func));
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

namespace _func258
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillFromSystem", typeid(int (*)(int )), ".8b54240483fa0174??83fa0674??", argdata, 1, 2, &func);
}

__declspec(naked) int CrewMember::GetSkillFromSystem(int systemId)
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
		"push [ebp+8]\n\t"		// systemId
	);
	__asm__("call %0\n\t" :: "m"(_func258::func));
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

namespace _func259
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetResisted", typeid(void (CrewMember::*)(bool )), ".8b4424048881f4060000", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SetResisted(bool resisted)
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
		"push [ebp+8]\n\t"		// resisted
	);
	__asm__("call %0\n\t" :: "m"(_func259::func));
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

namespace _func260
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetResisted", typeid(bool (CrewMember::*)()), ".0fb681f4060000c681f406000000", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::GetResisted()
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
	__asm__("call %0\n\t" :: "m"(_func260::func));
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

namespace _func261
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetSkillProgress", typeid(void (CrewMember::*)(int , int )), ".8b81140300008b5424048b4c2408", argdata, 3, 5, &func);
}

__declspec(naked) void CrewMember::SetSkillProgress(int skillId, int skillLevel)
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
		"push [ebp+12]\n\t"		// skillLevel
		"push [ebp+8]\n\t"		// skillId
	);
	__asm__("call %0\n\t" :: "m"(_func261::func));
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

namespace _func262
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillLevel", typeid(int (CrewMember::*)(int )), ".8b542404b8????????83fa0577??8b8114030000", argdata, 2, 1, &func);
}

__declspec(naked) int CrewMember::GetSkillLevel(int skillId)
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
		"push [ebp+8]\n\t"		// skillId
	);
	__asm__("call %0\n\t" :: "m"(_func262::func));
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

namespace _func263
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillProgress", typeid(std::pair<int, int> (CrewMember::*)(int )), ".558b811403000089e58b55085d8d14d08b02", argdata, 2, 1, &func);
}

__declspec(naked) std::pair<int, int> CrewMember::GetSkillProgress(int skillId)
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
		"push [ebp+8]\n\t"		// skillId
	);
	__asm__("call %0\n\t" :: "m"(_func263::func));
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

namespace _func264
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillModifier", typeid(void (CrewMember::*)(int )), ".55b8????????89e55383e4f083ec10", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::GetSkillModifier(int skillId)
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
		"push [ebp+8]\n\t"		// skillId
	);
	__asm__("call %0\n\t" :: "m"(_func264::func));
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

namespace _func265
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::BadAtCombat", typeid(bool (CrewMember::*)()), ".5589e55389cb83e4f083ec108b01", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::BadAtCombat()
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
	__asm__("call %0\n\t" :: "m"(_func265::func));
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

namespace _func266
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::EmptySlot", typeid(void (CrewMember::*)()), ".8b818800000085c00f88????????578d7c240883e4f0", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::EmptySlot()
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
	__asm__("call %0\n\t" :: "m"(_func266::func));
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

namespace _func267
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::NeedsSlot", typeid(bool (CrewMember::*)()), ".0fb681fc01000084c075??83b98c000000ff74??", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::NeedsSlot()
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
	__asm__("call %0\n\t" :: "m"(_func267::func));
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

namespace _func268
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::DirectModifyHealth", typeid(void (CrewMember::*)(float )), ".57660fefc98d7c240883e4f0ff77fc5589e557565383ec4cf30f1041280f2ec8f30f10170f83????????f30f2cf0f30f58c2", argdata, 2, 5, &func);
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
	__asm__("call %0\n\t" :: "m"(_func268::func));
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

namespace _func269
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ModifyHealth", typeid(void (CrewMember::*)(float )), ".578d7c240883e4f0ff77fc5589e55753", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::ModifyHealth(float health)
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
	__asm__("call %0\n\t" :: "m"(_func269::func));
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

namespace _func270
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ApplyDamage", typeid(bool (CrewMember::*)(float )), ".578d7c240883e4f0ff77fc5589e5", argdata, 2, 1, &func);
}

__declspec(naked) bool CrewMember::ApplyDamage(float damage)
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
		"push [ebp+8]\n\t"		// damage
	);
	__asm__("call %0\n\t" :: "m"(_func270::func));
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

namespace _func271
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::RepairingSystem", typeid(bool (CrewMember::*)()), ".8b516885d274??8b810002000085c0", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::RepairingSystem()
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
	__asm__("call %0\n\t" :: "m"(_func271::func));
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

namespace _func272
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Sabotaging", typeid(bool (CrewMember::*)()), ".8b416885c074??5589e5538b10", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::Sabotaging()
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
	__asm__("call %0\n\t" :: "m"(_func272::func));
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

namespace _func273
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::RepairingFire", typeid(bool (CrewMember::*)()), ".8b516831c085d274??8b9100020000", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::RepairingFire()
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
	__asm__("call %0\n\t" :: "m"(_func273::func));
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

namespace _func274
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::SelectSabotageTarget", typeid(void *(CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e5", argdata, 1, 1, &func);
}

__declspec(naked) void *CrewMember::SelectSabotageTarget()
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
	__asm__("call %0\n\t" :: "m"(_func274::func));
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

namespace _func275
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::SavePosition", typeid(void (CrewMember::*)()), ".8b81880000008981f80600008b818c0000008981fc0600008b8190000000898100070000", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::SavePosition()
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
	__asm__("call %0\n\t" :: "m"(_func275::func));
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

namespace _func276
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::ClearPosition", typeid(void (CrewMember::*)()), ".c781fc060000ffffffffc781f8060000ffffffff", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::ClearPosition()
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
	__asm__("call %0\n\t" :: "m"(_func276::func));
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

namespace _func277
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSavedPosition", typeid(void (*)(Slot *, CrewMember *)), ".8b54240489c88b8af806000089088b8afc060000894804", argdata, 2, 4, &func);
}

__declspec(naked) void CrewMember::GetSavedPosition(Slot *ret, CrewMember *crew)
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
		"push [ebp+12]\n\t"		// crew
		"mov ecx, [ebp+8]\n\t"	// ret
	);
	__asm__("call %0\n\t" :: "m"(_func277::func));
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

namespace _func278
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x4ff};
	static FunctionDefinition funcObj("CrewMember::SetSavePosition", typeid(void (CrewMember::*)(Slot )), ".8b4424048981f80600008b4424088981fc060000", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SetSavePosition(Slot position)
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
		"push [ebp+20]\n\t"		// position
		"push [ebp+16]\n\t"		// position
		"push [ebp+12]\n\t"		// position
		"push [ebp+8]\n\t"		// position
	);
	__asm__("call %0\n\t" :: "m"(_func278::func));
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

namespace _func279
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::StopRepairing", typeid(void (CrewMember::*)()), ".8b416885c074??8b015589e5", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::StopRepairing()
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
	__asm__("call %0\n\t" :: "m"(_func279::func));
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

namespace _func280
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Repairing", typeid(bool (CrewMember::*)()), ".8b416885c00f95c0", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::Repairing()
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
	__asm__("call %0\n\t" :: "m"(_func280::func));
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

namespace _func281
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetFrozen", typeid(void (CrewMember::*)(bool )), ".8b44240484c074??80b9a00100000074??8881a0010000", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SetFrozen(bool frozen)
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
		"push [ebp+8]\n\t"		// frozen
	);
	__asm__("call %0\n\t" :: "m"(_func281::func));
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

namespace _func282
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetFrozenLocation", typeid(void (CrewMember::*)(bool )), ".8b4424048881a1010000", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SetFrozenLocation(bool frozenLocation)
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
		"push [ebp+8]\n\t"		// frozenLocation
	);
	__asm__("call %0\n\t" :: "m"(_func282::func));
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

namespace _func283
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x3ff};
	static FunctionDefinition funcObj("CrewMember::SetCrewTask", typeid(void (CrewMember::*)(CrewTask )), ".8b4424048981a40100008b4424088981a8010000", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SetCrewTask(CrewTask task)
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
		"push [ebp+16]\n\t"		// task
		"push [ebp+12]\n\t"		// task
		"push [ebp+8]\n\t"		// task
	);
	__asm__("call %0\n\t" :: "m"(_func283::func));
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

namespace _func284
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::FindSlot", typeid(Slot *(CrewMember::*)(int , int , bool )), ".578d7c240883e4f0ff77fc5589f889e557", argdata, 4, 1, &func);
}

__declspec(naked) Slot *CrewMember::FindSlot(int unk1, int roomId, bool unk2)
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
		"push [ebp+16]\n\t"		// unk2
		"push [ebp+12]\n\t"		// roomId
		"push [ebp+8]\n\t"		// unk1
	);
	__asm__("call %0\n\t" :: "m"(_func284::func));
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

namespace _func285
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::CheckRoomPath", typeid(bool (CrewMember::*)(int )), ".578d7c240883e4f0ff77fc5589e55756", argdata, 2, 1, &func);
}

__declspec(naked) bool CrewMember::CheckRoomPath(int roomId)
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
		"push [ebp+8]\n\t"		// roomId
	);
	__asm__("call %0\n\t" :: "m"(_func285::func));
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

namespace _func286
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("CrewMember::SetPosition", typeid(void (CrewMember::*)(Point )), ".57660fefc9660fefc08d7c240883e4f0ff77fc5589e5", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SetPosition(Point pos)
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
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// pos
	);
	__asm__("call %0\n\t" :: "m"(_func286::func));
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

namespace _func287
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::ClearTask", typeid(void (CrewMember::*)()), ".8b4178c781ac010000ffffffffc781a401000004000000", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::ClearTask()
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
	__asm__("call %0\n\t" :: "m"(_func287::func));
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

namespace _func288
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::ClearPath", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::ClearPath()
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
	__asm__("call %0\n\t" :: "m"(_func288::func));
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

namespace _func289
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetRoom", typeid(void (CrewMember::*)(int )), ".578d7c240883e4f0ff77fc5589e5", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SetRoom(int roomId)
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
		"push [ebp+8]\n\t"		// roomId
	);
	__asm__("call %0\n\t" :: "m"(_func289::func));
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

namespace _func290
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::IsBusy", typeid(bool (CrewMember::*)()), ".8b5168b8????????85d274??f3c3", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::IsBusy()
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
	__asm__("call %0\n\t" :: "m"(_func290::func));
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

namespace _func291
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::OnInit", typeid(bool (CrewMember::*)()), ".c741201e000000c7416400000000b8????????", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::OnInit()
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
	__asm__("call %0\n\t" :: "m"(_func291::func));
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

namespace _func292
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetFinalGoal", typeid(void *(CrewMember::*)()), ".f30f1005????????0f2e41547a??74??8b414c8b5150", argdata, 1, 1, &func);
}

__declspec(naked) void *CrewMember::GetFinalGoal()
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
	__asm__("call %0\n\t" :: "m"(_func292::func));
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

namespace _func293
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetNextGoal", typeid(void *(CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e55753", argdata, 1, 1, &func);
}

__declspec(naked) void *CrewMember::GetNextGoal()
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
	__asm__("call %0\n\t" :: "m"(_func293::func));
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

namespace _func294
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::CloseDoorBehind", typeid(void (CrewMember::*)(Door *)), ".8b442404894164", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::CloseDoorBehind(Door *door)
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
		"push [ebp+8]\n\t"		// door
	);
	__asm__("call %0\n\t" :: "m"(_func294::func));
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

namespace _func295
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetMoveSpeed", typeid(float (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e55756", argdata, 1, 1, &func);
}

__declspec(naked) float CrewMember::GetMoveSpeed()
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
	__asm__("call %0\n\t" :: "m"(_func295::func));
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

namespace _func296
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Restart", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::Restart()
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
	__asm__("call %0\n\t" :: "m"(_func296::func));
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

namespace _func297
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetDamageBoost", typeid(void (CrewMember::*)(float )), ".f30f10442404f30f1181ec060000", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SetDamageBoost(float damageBoost)
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
		"push [ebp+8]\n\t"		// damageBoost
	);
	__asm__("call %0\n\t" :: "m"(_func297::func));
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

namespace _func298
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetHealthBoost", typeid(void (CrewMember::*)(int )), ".558b81e806000089e5538b550883e4f039d074??", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SetHealthBoost(int healthBoost)
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
		"push [ebp+8]\n\t"		// healthBoost
	);
	__asm__("call %0\n\t" :: "m"(_func298::func));
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

namespace _func299
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::InitializeSkills", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::InitializeSkills()
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
	__asm__("call %0\n\t" :: "m"(_func299::func));
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

namespace _func300
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetCloneReady", typeid(void (CrewMember::*)(bool )), ".578d7c240883e4f0ff77fc5589e557", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SetCloneReady(bool cloneReady)
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
		"push [ebp+8]\n\t"		// cloneReady
	);
	__asm__("call %0\n\t" :: "m"(_func300::func));
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

namespace _func301
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Kill", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::Kill()
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
	__asm__("call %0\n\t" :: "m"(_func301::func));
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

namespace _func302
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::NeedFrozenLocation", typeid(bool (CrewMember::*)()), ".0fb681a00100005589e584c074??660fefc9", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::NeedFrozenLocation()
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
	__asm__("call %0\n\t" :: "m"(_func302::func));
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

namespace _func303
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetCurrentShip", typeid(void (CrewMember::*)(int )), ".8b4424048b919c000000898160010000", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SetCurrentShip(int shipId)
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
		"push [ebp+8]\n\t"		// shipId
	);
	__asm__("call %0\n\t" :: "m"(_func303::func));
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

namespace _func304
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CheckFighting", typeid(void (CrewMember::*)()), ".8b818801000085c00f958199000000", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::CheckFighting()
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
	__asm__("call %0\n\t" :: "m"(_func304::func));
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

namespace _func305
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetDeathNumber", typeid(void (CrewMember::*)(int )), ".8b4424043b05????????898140050000", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SetDeathNumber(int deathNum)
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
		"push [ebp+8]\n\t"		// deathNum
	);
	__asm__("call %0\n\t" :: "m"(_func305::func));
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

namespace _func306
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ForceMindControl", typeid(void (CrewMember::*)(bool )), ".8b44240488813d050000", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::ForceMindControl(bool force)
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
		"push [ebp+8]\n\t"		// force
	);
	__asm__("call %0\n\t" :: "m"(_func306::func));
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

namespace _func307
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("CrewMember::RenderSkillUpAnimation", typeid(void (CrewMember::*)(Point )), ".578d7c240883e4f0ff77fc5589e557565383ec7c8b17", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::RenderSkillUpAnimation(Point pos)
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
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// pos
	);
	__asm__("call %0\n\t" :: "m"(_func307::func));
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

namespace _func308
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Clone", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e5", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::Clone()
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
	__asm__("call %0\n\t" :: "m"(_func308::func));
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

namespace _func309
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::UpdateHealth", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc55", argdata, 1, 5, &func);
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
	__asm__("call %0\n\t" :: "m"(_func309::func));
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

namespace _func310
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::OnRenderPath", typeid(void (CrewMember::*)()), ".8b410485c00f85????????660fefc9f30f104108f30f1015????????", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::OnRenderPath()
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
	__asm__("call %0\n\t" :: "m"(_func310::func));
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

namespace _func311
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::SetPath", typeid(bool (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::SetPath()
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
	__asm__("call %0\n\t" :: "m"(_func311::func));
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

namespace _func312
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetRoomPath", typeid(void (CrewMember::*)(int , int )), ".578d7c240883e4f0ff77fc5589e55756", argdata, 3, 5, &func);
}

__declspec(naked) void CrewMember::SetRoomPath(int roomId, int slotId)
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
		"push [ebp+12]\n\t"		// slotId
		"push [ebp+8]\n\t"		// roomId
	);
	__asm__("call %0\n\t" :: "m"(_func312::func));
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

namespace _func313
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetLocation", typeid(void *(CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb83ec30", argdata, 1, 1, &func);
}

__declspec(naked) void *CrewMember::GetLocation()
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
	__asm__("call %0\n\t" :: "m"(_func313::func));
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

namespace _func314
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::AtGoal", typeid(bool (CrewMember::*)()), ".f30f104918f30f101d????????f30f10410855f30f5cc1f30f1015????????", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::AtGoal()
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
	__asm__("call %0\n\t" :: "m"(_func314::func));
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

namespace _func315
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::AtFinalGoal", typeid(bool (CrewMember::*)()), ".660fefc9f30f1015????????f30f10410831c055f30f2a899000000089e5", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::AtFinalGoal()
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
	__asm__("call %0\n\t" :: "m"(_func315::func));
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

namespace _func316
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::OnRenderHealth", typeid(void (CrewMember::*)()), ".80b9fc0100000074??f3c3908d7426008b819c000000837838030f84????????57", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::OnRenderHealth()
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
	__asm__("call %0\n\t" :: "m"(_func316::func));
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

namespace _func317
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetIntegerHealth", typeid(int (CrewMember::*)()), ".31c080b9fc0100000075??f30f2c4128ba????????85c00f4ec2", argdata, 1, 1, &func);
}

__declspec(naked) int CrewMember::GetIntegerHealth()
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
	__asm__("call %0\n\t" :: "m"(_func317::func));
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

namespace _func318
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetRepairingId", typeid(int (CrewMember::*)()), ".8b496885c974??558b01", argdata, 1, 1, &func);
}

__declspec(naked) int CrewMember::GetRepairingId()
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
	__asm__("call %0\n\t" :: "m"(_func318::func));
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

namespace _func319
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::WithinRect", typeid(bool (CrewMember::*)(int , int , int , int )), ".538b4424108b5c24088b54241485c078??85d278??", argdata, 5, 1, &func);
}

__declspec(naked) bool CrewMember::WithinRect(int x, int y, int w, int h)
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
		"push [ebp+20]\n\t"		// h
		"push [ebp+16]\n\t"		// w
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func319::func));
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

namespace _func320
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetLongName", typeid(std::string &(*)(std::string &, CrewMember *)), ".578d7c240883e4f0ff77fc5589e557", argdata, 2, 2, &func);
}

__declspec(naked) std::string &CrewMember::GetLongName(std::string &str, CrewMember *crew)
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
		"push [ebp+12]\n\t"		// crew
		"mov ecx, [ebp+8]\n\t"	// str
	);
	__asm__("call %0\n\t" :: "m"(_func320::func));
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
		"ret 8\n\t"
	);
}

namespace _func321
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x9ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetName", typeid(void (CrewMember::*)(TextString , bool )), ".578d7c240883e4f0ff77fc5589e55756", argdata, 3, 5, &func);
}

__declspec(naked) void CrewMember::SetName(TextString name, bool force)
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
		"push [ebp+44]\n\t"		// force
		"push [ebp+40]\n\t"		// name
		"push [ebp+36]\n\t"		// name
		"push [ebp+32]\n\t"		// name
		"push [ebp+28]\n\t"		// name
		"push [ebp+24]\n\t"		// name
		"push [ebp+20]\n\t"		// name
		"push [ebp+16]\n\t"		// name
		"push [ebp+12]\n\t"		// name
		"push [ebp+8]\n\t"		// name
	);
	__asm__("call %0\n\t" :: "m"(_func321::func));
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

namespace _func322
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetName", typeid(std::string &(*)(std::string &, CrewMember *)), ".578d7c240883e4f0ff77fc5589e5575389cb83ec10", argdata, 2, 2, &func);
}

__declspec(naked) std::string &CrewMember::GetName(std::string &str, CrewMember *crew)
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
		"push [ebp+12]\n\t"		// crew
		"mov ecx, [ebp+8]\n\t"	// str
	);
	__asm__("call %0\n\t" :: "m"(_func322::func));
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
		"ret 8\n\t"
	);
}

namespace _func323
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetCurrentTarget", typeid(void (CrewMember::*)(CrewTarget *, bool )), ".5589e55756538b0189cb8b75088b7d0c83e4f08b40643d????????75??", argdata, 3, 5, &func);
}

__declspec(naked) void CrewMember::SetCurrentTarget(CrewTarget *target, bool unk)
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
		"push [ebp+8]\n\t"		// target
	);
	__asm__("call %0\n\t" :: "m"(_func323::func));
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

namespace _func324
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CheckForTeleport", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e557565383ec1c", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::CheckForTeleport()
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
	__asm__("call %0\n\t" :: "m"(_func324::func));
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

namespace _func325
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetNewGoal", typeid(char (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b496485c974??e8????????f30f1005????????", argdata, 1, 1, &func);
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
	__asm__("call %0\n\t" :: "m"(_func325::func));
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

namespace _func326
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::MoveToRoom", typeid(bool (CrewMember::*)(int , int , bool )), ".578d7c240883e4f0ff77fc5589e55756", argdata, 4, 1, &func);
}

__declspec(naked) bool CrewMember::MoveToRoom(int roomId, int slotId, bool forceMove)
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
		"push [ebp+16]\n\t"		// forceMove
		"push [ebp+12]\n\t"		// slotId
		"push [ebp+8]\n\t"		// roomId
	);
	__asm__("call %0\n\t" :: "m"(_func326::func));
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

namespace _func327
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetMindControl", typeid(void (CrewMember::*)(bool )), ".578d7c240883e4f0ff77fc5589e55753", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SetMindControl(bool controlled)
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
		"push [ebp+8]\n\t"		// controlled
	);
	__asm__("call %0\n\t" :: "m"(_func327::func));
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

namespace _func328
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::RestorePosition", typeid(bool (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::RestorePosition()
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
	__asm__("call %0\n\t" :: "m"(_func328::func));
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

namespace _func329
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ContainsPoint", typeid(bool (CrewMember::*)(int , int )), ".f30f1005????????f30f594114f30f104908660fefd20f28d9f30f2a542404", argdata, 3, 1, &func);
}

__declspec(naked) bool CrewMember::ContainsPoint(int x, int y)
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
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func329::func));
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

namespace _func330
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetMedbay", typeid(void (CrewMember::*)(float )), ".5589e55389cb83e4f083ec108b11", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SetMedbay(float health)
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
	__asm__("call %0\n\t" :: "m"(_func330::func));
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

namespace _func331
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::StartTeleport", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::StartTeleport()
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
	__asm__("call %0\n\t" :: "m"(_func331::func));
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

namespace _func332
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::StartTeleportArrive", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e55753", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::StartTeleportArrive()
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
	__asm__("call %0\n\t" :: "m"(_func332::func));
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

namespace _func333
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::StartRepair", typeid(void (CrewMember::*)(Repairable *)), ".57660fefc98d7c240883e4f0ff77fc5589e5575383ec308b3ff30f2a8990000000", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::StartRepair(Repairable *toRepair)
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
		"push [ebp+8]\n\t"		// toRepair
	);
	__asm__("call %0\n\t" :: "m"(_func333::func));
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

namespace _func334
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::UpdateRepair", typeid(void (CrewMember::*)()), ".57660fefc98d7c240883e4f0ff77fc5589e557", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::UpdateRepair()
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
	__asm__("call %0\n\t" :: "m"(_func334::func));
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

namespace _func335
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::UpdateMovement", typeid(void (CrewMember::*)()), ".8b819c0000008b403883f8060f84????????660fefc00f2e41280f83????????578d7c2408", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::UpdateMovement()
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
	__asm__("call %0\n\t" :: "m"(_func335::func));
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

namespace _func336
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::OnLoop", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e55756", argdata, 1, 5, &func);
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
	__asm__("call %0\n\t" :: "m"(_func336::func));
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

namespace _func337
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetSex", typeid(void (CrewMember::*)(bool )), ".5589e556538b750889cb8b899c00000083e4f089f08881c4090000e8????????89f08883100300008d65f85b", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SetSex(bool male)
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
		"push [ebp+8]\n\t"		// male
	);
	__asm__("call %0\n\t" :: "m"(_func337::func));
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

namespace _func338
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::CycleColorLayer", typeid(void (CrewMember::*)(int )), ".578d7c240883e4f0ff77fc5589e55756", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::CycleColorLayer(int unk)
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
	__asm__("call %0\n\t" :: "m"(_func338::func));
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

namespace _func339
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Functional", typeid(bool (CrewMember::*)()), "8b018b80880000003d????????75??0fb681fc01000083f001c38db6000000005589e583e4f0ffd0c9", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::Functional()
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
	__asm__("call %0\n\t" :: "m"(_func339::func));
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

namespace _func340
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::InsideRoom", typeid(bool (CrewMember::*)(int )), ".8b4424043941780f94c0", argdata, 2, 1, &func);
}

__declspec(naked) bool CrewMember::InsideRoom(int roomId)
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
		"push [ebp+8]\n\t"		// roomId
	);
	__asm__("call %0\n\t" :: "m"(_func340::func));
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

namespace _func341
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ShipDamage", typeid(bool (CrewMember::*)(float )), ".578d7c240883e4f0ff77fc5589e55783ec14f30f1007f30f110424e8????????8b7dfc83ec04", argdata, 2, 1, &func);
}

__declspec(naked) bool CrewMember::ShipDamage(float damage)
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
		"push [ebp+8]\n\t"		// damage
	);
	__asm__("call %0\n\t" :: "m"(_func341::func));
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

namespace _func342
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetControllable", typeid(bool (CrewMember::*)()), "8b410485c074??31c0c38db6000000008b015589e55389cb8b808800000083e4f0", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::GetControllable()
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
	__asm__("call %0\n\t" :: "m"(_func342::func));
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

namespace _func343
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetUniqueRepairing", typeid(std::string &(*)(std::string &, CrewMember *)), ".8d510889c8c7410872657061c7410406000000c6410e008911ba????????6689510c", argdata, 2, 0, &func);
}

__declspec(naked) std::string &CrewMember::GetUniqueRepairing(std::string &strRef, CrewMember *crew)
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
		"push [ebp+12]\n\t"		// crew
		"mov ecx, [ebp+8]\n\t"	// strRef
	);
	__asm__("call %0\n\t" :: "m"(_func343::func));
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

namespace _func344
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x3ff};
	static FunctionDefinition funcObj("CrewMember::SetTask", typeid(void (CrewMember::*)(CrewTask )), "8b4424048981a40100008b4424088981a80100008b44240c8981ac010000", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SetTask(CrewTask task)
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
		"push [ebp+16]\n\t"		// task
		"push [ebp+12]\n\t"		// task
		"push [ebp+8]\n\t"		// task
	);
	__asm__("call %0\n\t" :: "m"(_func344::func));
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

namespace _func345
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMemberFactory::destructor", typeid(void (CrewMemberFactory::*)()), "5589e557565389ce83e4f083ec108b79108b510c89f829d0c1f80285c074??", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMemberFactory::destructor()
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
	__asm__("call %0\n\t" :: "m"(_func345::func));
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

namespace _func346
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMemberFactory::Restart", typeid(void (CrewMemberFactory::*)()), ".5589e557565389cb83e4f0", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMemberFactory::Restart()
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
	__asm__("call %0\n\t" :: "m"(_func346::func));
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

namespace _func347
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMemberFactory::CountCloneReadyCrew", typeid(int (CrewMemberFactory::*)()), ".5589e557565383e4f0", argdata, 1, 1, &func);
}

__declspec(naked) int CrewMemberFactory::CountCloneReadyCrew()
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
	__asm__("call %0\n\t" :: "m"(_func347::func));
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

namespace _func348
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMemberFactory::GetPlayerCrewCount", typeid(int (CrewMemberFactory::*)()), ".8b01", argdata, 1, 1, &func);
}

__declspec(naked) int CrewMemberFactory::GetPlayerCrewCount()
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
	__asm__("call %0\n\t" :: "m"(_func348::func));
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

namespace _func349
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMemberFactory::GetEnemyCloneCount", typeid(int (CrewMemberFactory::*)()), ".8b4108", argdata, 1, 1, &func);
}

__declspec(naked) int CrewMemberFactory::GetEnemyCloneCount()
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
	__asm__("call %0\n\t" :: "m"(_func349::func));
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

namespace _func350
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewCount", typeid(int (CrewMemberFactory::*)(bool )), ".807c2404008b41040f4401", argdata, 2, 1, &func);
}

__declspec(naked) int CrewMemberFactory::GetCrewCount(bool enemy)
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
		"push [ebp+8]\n\t"		// enemy
	);
	__asm__("call %0\n\t" :: "m"(_func350::func));
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

namespace _func351
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMemberFactory::GetEnemyCrewCount", typeid(int (CrewMemberFactory::*)()), ".8b4104", argdata, 1, 1, &func);
}

__declspec(naked) int CrewMemberFactory::GetEnemyCrewCount()
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
	__asm__("call %0\n\t" :: "m"(_func351::func));
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

namespace _func352
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::IsRace", typeid(bool (*)(const std::string &)), ".8d4c240483e4f0ff71fc5589e5", argdata, 1, 2, &func);
}

__declspec(naked) bool CrewMemberFactory::IsRace(const std::string &species)
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
		"push [ebp+8]\n\t"		// species
	);
	__asm__("call %0\n\t" :: "m"(_func352::func));
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

namespace _func353
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetRandomFriendlyName", typeid(std::pair<std::string, bool> &(CrewMemberFactory::*)(const std::string &)), ".578d7c240883e4f0ff77fc5589e5", argdata, 2, 1, &func);
}

__declspec(naked) std::pair<std::string, bool> &CrewMemberFactory::GetRandomFriendlyName(const std::string &unk)
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
	__asm__("call %0\n\t" :: "m"(_func353::func));
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

namespace _func354
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewNames", typeid(std::vector<std::string> *(*)(std::vector<std::string> &, CrewMemberFactory *)), ".578d7c240883e4f0ff77fc5589e55756", argdata, 2, 0, &func);
}

__declspec(naked) std::vector<std::string> *CrewMemberFactory::GetCrewNames(std::vector<std::string> &vec, CrewMemberFactory *factory)
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
		"push [ebp+12]\n\t"		// factory
		"mov ecx, [ebp+8]\n\t"	// vec
	);
	__asm__("call %0\n\t" :: "m"(_func354::func));
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

namespace _func355
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::CreateRepairDrone", typeid(RepairDrone *(CrewMemberFactory::*)(int , const DroneBlueprint *)), ".578d7c240883e4f0ff77fc5589e55756", argdata, 3, 1, &func);
}

__declspec(naked) RepairDrone *CrewMemberFactory::CreateRepairDrone(int shipId, const DroneBlueprint *bp)
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
		"push [ebp+12]\n\t"		// bp
		"push [ebp+8]\n\t"		// shipId
	);
	__asm__("call %0\n\t" :: "m"(_func355::func));
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

namespace _func356
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewPortraitList", typeid(void (CrewMemberFactory::*)(std::vector<CrewMember*> *, int )), ".578d7c240883e4f0ff77fc5589f889e55756", argdata, 3, 5, &func);
}

__declspec(naked) void CrewMemberFactory::GetCrewPortraitList(std::vector<CrewMember*> *vec, int teamId)
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
		"push [ebp+12]\n\t"		// teamId
		"push [ebp+8]\n\t"		// vec
	);
	__asm__("call %0\n\t" :: "m"(_func356::func));
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

namespace _func357
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCloneReadyList", typeid(void (CrewMemberFactory::*)(std::vector<CrewMember*> &, bool )), ".578d7c240883e4f0ff77fc5589e557565383ec4c", argdata, 3, 5, &func);
}

__declspec(naked) void CrewMemberFactory::GetCloneReadyList(std::vector<CrewMember*> &vec, bool unk)
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
		"push [ebp+8]\n\t"		// vec
	);
	__asm__("call %0\n\t" :: "m"(_func357::func));
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

namespace _func358
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::CreateBattleDrone", typeid(BattleDrone *(CrewMemberFactory::*)(int , const DroneBlueprint *)), ".578d7c240883e4f0ff77fc5589f889e5", argdata, 3, 1, &func);
}

__declspec(naked) BattleDrone *CrewMemberFactory::CreateBattleDrone(int shipId, const DroneBlueprint *bp)
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
		"push [ebp+12]\n\t"		// bp
		"push [ebp+8]\n\t"		// shipId
	);
	__asm__("call %0\n\t" :: "m"(_func358::func));
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

namespace _func359
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewList", typeid(void (CrewMemberFactory::*)(std::vector<CrewMember*> *, int , bool )), ".578d7c240883e4f0ff77fc5589e557", argdata, 4, 5, &func);
}

__declspec(naked) void CrewMemberFactory::GetCrewList(std::vector<CrewMember*> *vec, int unk, bool unk2)
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
		"push [ebp+8]\n\t"		// vec
	);
	__asm__("call %0\n\t" :: "m"(_func359::func));
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

namespace _func360
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::CreateBoarderDrone", typeid(BoarderDrone *(CrewMemberFactory::*)(int , const DroneBlueprint *)), ".578d7c240883e4f0ff77fc5589e5", argdata, 3, 1, &func);
}

__declspec(naked) BoarderDrone *CrewMemberFactory::CreateBoarderDrone(int shipId, const DroneBlueprint *bp)
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
		"push [ebp+12]\n\t"		// bp
		"push [ebp+8]\n\t"		// shipId
	);
	__asm__("call %0\n\t" :: "m"(_func360::func));
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

namespace _func361
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMemberFactory::OnLoop", typeid(void (CrewMemberFactory::*)()), ".578d7c240883e4f0ff77fc5589e5", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMemberFactory::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func361::func));
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

namespace _func362
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMemberFactory::RemoveExcessCrew", typeid(void (CrewMemberFactory::*)()), ".5589e557565331db", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMemberFactory::RemoveExcessCrew()
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
	__asm__("call %0\n\t" :: "m"(_func362::func));
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

namespace _func363
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::CreateCrewMember", typeid(CrewMember *(CrewMemberFactory::*)(CrewBlueprint *, int , bool )), ".578d7c240883e4f0ff77fc5589e557", argdata, 4, 1, &func);
}

__declspec(naked) CrewMember *CrewMemberFactory::CreateCrewMember(CrewBlueprint *bp, int shipId, bool intruder)
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
		"push [ebp+16]\n\t"		// intruder
		"push [ebp+12]\n\t"		// shipId
		"push [ebp+8]\n\t"		// bp
	);
	__asm__("call %0\n\t" :: "m"(_func363::func));
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

namespace _func364
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewStoreBox::Purchase", typeid(void (CrewStoreBox::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????898dacfeffffe8????????b9????????e8????????8bb73c020000", argdata, 1, 5, &func);
}

__declspec(naked) void CrewStoreBox::Purchase()
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
	__asm__("call %0\n\t" :: "m"(_func364::func));
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

namespace _func365
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
	__asm__("call %0\n\t" :: "m"(_func365::func));
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

namespace _func366
{
	static void *func = 0;
	static short argdata[] = {0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_SetColorTint", typeid(void (*)(GL_Color )), "8d4c240483e4f0ff71fc5589e55183ec14a1????????3b05????????74??85c074??8b1189108b51048950048b51088950088b510c89500c", argdata, 1, 6, &func);
}

__declspec(naked) void CSurface::GL_SetColorTint(GL_Color color)
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
		"push [ebp+20]\n\t"		// color
		"push [ebp+16]\n\t"		// color
		"push [ebp+12]\n\t"		// color
		"push [ebp+8]\n\t"		// color
	);
	__asm__("call %0\n\t" :: "m"(_func366::func));
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

namespace _func367
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
	__asm__("call %0\n\t" :: "m"(_func367::func));
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

namespace _func368
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_Rotate2", typeid(void (*)(float , float , float , float )), "5589e55653bb????????83e4f081ec????????8d44243cf30f110424f30f105d08894424088d442438f30f114c2424f30f1154242889442404f30f115c242ce8????????660fefe4", argdata, 4, 6, &func);
}

__declspec(naked) void CSurface::GL_Rotate2(float angle, float x, float y, float z)
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
		"push [ebp+20]\n\t"		// z
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// angle
	);
	__asm__("call %0\n\t" :: "m"(_func368::func));
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

namespace _func369
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::IsFrameBufferSupported", typeid(bool (*)()), ".5589e583e4f0e8????????85c0c9", argdata, 0, 2, &func);
}

__declspec(naked) bool CSurface::IsFrameBufferSupported()
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
	__asm__("call %0\n\t" :: "m"(_func369::func));
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

namespace _func370
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::StartFrame", typeid(void (*)()), ".5589e583e4f0e8????????e8????????", argdata, 0, 6, &func);
}

__declspec(naked) void CSurface::StartFrame()
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
	__asm__("call %0\n\t" :: "m"(_func370::func));
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

namespace _func371
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::FinishFrame", typeid(void (*)()), ".5589e583e4f0e8????????", argdata, 0, 6, &func);
}

__declspec(naked) void CSurface::FinishFrame()
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
	__asm__("call %0\n\t" :: "m"(_func371::func));
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

namespace _func372
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_ClearAll", typeid(void (*)()), ".55660fefc089e583e4f083ec20f30f1144240cc744241400000000", argdata, 0, 6, &func);
}

__declspec(naked) void CSurface::GL_ClearAll()
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
	__asm__("call %0\n\t" :: "m"(_func372::func));
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

namespace _func373
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_ClearColor", typeid(void (*)()), ".55660fefc089e583e4f083ec10f30f1144240cf30f11442408", argdata, 0, 6, &func);
}

__declspec(naked) void CSurface::GL_ClearColor()
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
	__asm__("call %0\n\t" :: "m"(_func373::func));
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

namespace _func374
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::SetViewPort", typeid(int (*)(int , int , int , int )), ".5589e583e4f083ec108b45148944240c8b4510894424088b450c89442404", argdata, 4, 2, &func);
}

__declspec(naked) int CSurface::SetViewPort(int left, int bottom, int h, int w)
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
		"push [ebp+20]\n\t"		// w
		"push [ebp+16]\n\t"		// h
		"push [ebp+12]\n\t"		// bottom
		"push [ebp+8]\n\t"		// left
	);
	__asm__("call %0\n\t" :: "m"(_func374::func));
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

namespace _func375
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PopScissor", typeid(void (*)()), ".5589e583e4f083ec10a1????????8b15????????89c129d1c1f90485c974??83e810", argdata, 0, 6, &func);
}

__declspec(naked) void CSurface::GL_PopScissor()
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
	__asm__("call %0\n\t" :: "m"(_func375::func));
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

namespace _func376
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_SetStencilMode", typeid(void (*)(GL_StencilMode , int , int )), ".5589e5565383e4f083ec108b45088b5d0c8b751083f801a3????????891d????????8935????????0f84????????0f82????????", argdata, 3, 6, &func);
}

__declspec(naked) void CSurface::GL_SetStencilMode(GL_StencilMode stencilMode, int unk1, int unk2)
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
		"push [ebp+12]\n\t"		// unk1
		"push [ebp+8]\n\t"		// stencilMode
	);
	__asm__("call %0\n\t" :: "m"(_func376::func));
	__asm__
	(
		"add esp, 12\n\t"
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

namespace _func377
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PopStencilMode", typeid(void (*)()), ".8b15????????8b0d????????89d029c8c1f80269c0????????85c075??c36690558d4440fd83ea0c89e556", argdata, 0, 6, &func);
}

__declspec(naked) void CSurface::GL_PopStencilMode()
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
	__asm__("call %0\n\t" :: "m"(_func377::func));
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

namespace _func378
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_OrthoProjection", typeid(int (*)(float , float , float , float , float , float )), ".5589e583e4f083ec20f30f10451cf30f11442414f30f104518f30f11442410f30f104514f30f1144240c", argdata, 6, 2, &func);
}

__declspec(naked) int CSurface::GL_OrthoProjection(float mx1, float mx2, float mx3, float mx4, float mx5, float mx6)
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
		"push [ebp+28]\n\t"		// mx6
		"push [ebp+24]\n\t"		// mx5
		"push [ebp+20]\n\t"		// mx4
		"push [ebp+16]\n\t"		// mx3
		"push [ebp+12]\n\t"		// mx2
		"push [ebp+8]\n\t"		// mx1
	);
	__asm__("call %0\n\t" :: "m"(_func378::func));
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

namespace _func379
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_LoadIdentity", typeid(int (*)()), ".55b8????????89e583e4f083ec100f105010c70424????????0f1048200f104030", argdata, 0, 2, &func);
}

__declspec(naked) int CSurface::GL_LoadIdentity()
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
	__asm__("call %0\n\t" :: "m"(_func379::func));
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

namespace _func380
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PushMatrix", typeid(int (*)()), ".a1????????83f80f77??89c10f2805????????c1e106", argdata, 0, 2, &func);
}

__declspec(naked) int CSurface::GL_PushMatrix()
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
	__asm__("call %0\n\t" :: "m"(_func380::func));
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

namespace _func381
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PopMatrix", typeid(int (*)()), ".5589e583e4f083ec30a1????????85c0", argdata, 0, 2, &func);
}

__declspec(naked) int CSurface::GL_PopMatrix()
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
	__asm__("call %0\n\t" :: "m"(_func381::func));
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

namespace _func382
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_Rotate", typeid(void (*)(float , float , float , float )), ".55660fefe489e5565383e4f081ec????????f30f1055080f2ed4f30f104d0cf30f104510f30f105d147a??", argdata, 4, 6, &func);
}

__declspec(naked) void CSurface::GL_Rotate(float angle, float x, float y, float z)
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
		"push [ebp+20]\n\t"		// z
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// angle
	);
	__asm__("call %0\n\t" :: "m"(_func382::func));
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

namespace _func383
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_Scale", typeid(void (*)(float , float , float )), ".55b9????????89e583e4f083ec10f30f1005????????f30f10550c0f2ed0f30f104d10f30f105d080f9bc20f45d10f2ec80f9bc00f45c1", argdata, 3, 6, &func);
}

__declspec(naked) void CSurface::GL_Scale(float x, float y, float z)
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
		"push [ebp+16]\n\t"		// z
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func383::func));
	__asm__
	(
		"add esp, 12\n\t"
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

namespace _func384
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_Translate", typeid(bool (*)(float , float , float )), ".55660fefc0b9????????89e583e4f083ec20f30f105d0c0f2ed8", argdata, 3, 2, &func);
}

__declspec(naked) bool CSurface::GL_Translate(float x, float y, float z)
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
		"push [ebp+16]\n\t"		// z
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func384::func));
	__asm__
	(
		"add esp, 12\n\t"
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

namespace _func385
{
	static void *func = 0;
	static short argdata[] = {0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_SetColor", typeid(int (*)(GL_Color )), ".5589e583e4f083ec208b4508f30f104508f30f11442410", argdata, 1, 2, &func);
}

__declspec(naked) int CSurface::GL_SetColor(GL_Color color)
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
		"push [ebp+20]\n\t"		// color
		"push [ebp+16]\n\t"		// color
		"push [ebp+12]\n\t"		// color
		"push [ebp+8]\n\t"		// color
	);
	__asm__("call %0\n\t" :: "m"(_func385::func));
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

namespace _func386
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_SetColor", typeid(int (*)(float , float , float , float )), "5589e583e4f083ec208b4508f30f104508f30f11442410a3????????8b450cf30f10450cf30f11442414a3????????8b4510f30f104510f30f11442418a3????????", argdata, 4, 2, &func);
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
	__asm__("call %0\n\t" :: "m"(_func386::func));
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

namespace _func387
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_RemoveColorTint", typeid(void (*)()), ".a1????????3b05????????74??83e810a3????????", argdata, 0, 6, &func);
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
	__asm__("call %0\n\t" :: "m"(_func387::func));
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

namespace _func388
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GetColorTint", typeid(GL_Color &(*)(GL_Color *)), ".8b15????????8b0d????????5539d189e58b450874??29ca83e2f08d5411f0", argdata, 1, 2, &func);
}

__declspec(naked) GL_Color &CSurface::GetColorTint(GL_Color *ref)
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
	__asm__("call %0\n\t" :: "m"(_func388::func));
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

namespace _func389
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_EnableBlend", typeid(bool (*)()), ".5589e583e4f083ec10c744240804000000", argdata, 0, 2, &func);
}

__declspec(naked) bool CSurface::GL_EnableBlend()
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
	__asm__("call %0\n\t" :: "m"(_func389::func));
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

namespace _func390
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_DisableBlend", typeid(bool (*)()), ".5589e583e4f083ec10c744240800000000", argdata, 0, 2, &func);
}

__declspec(naked) bool CSurface::GL_DisableBlend()
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
	__asm__("call %0\n\t" :: "m"(_func390::func));
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

namespace _func391
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_ForceAntialias", typeid(bool (*)()), ".8b442404a2????????", argdata, 0, 2, &func);
}

__declspec(naked) bool CSurface::GL_ForceAntialias()
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
	__asm__("call %0\n\t" :: "m"(_func391::func));
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

namespace _func392
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawLine", typeid(bool (*)(float , float , float , float , float , GL_Color )), ".5589e583e4f081ec????????a1????????8b15????????f30f107d1c", argdata, 6, 2, &func);
}

__declspec(naked) bool CSurface::GL_DrawLine(float x1, float y1, float x2, float y2, float lineWidth, GL_Color color)
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
		"push [ebp+40]\n\t"		// color
		"push [ebp+36]\n\t"		// color
		"push [ebp+32]\n\t"		// color
		"push [ebp+28]\n\t"		// color
		"push [ebp+24]\n\t"		// lineWidth
		"push [ebp+20]\n\t"		// y2
		"push [ebp+16]\n\t"		// x2
		"push [ebp+12]\n\t"		// y1
		"push [ebp+8]\n\t"		// x1
	);
	__asm__("call %0\n\t" :: "m"(_func392::func));
	__asm__
	(
		"add esp, 36\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 36\n\t"
	);
}

namespace _func393
{
	static void *func = 0;
	static short argdata[] = {0x2ff, 0x2ff, 0x2ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawTriangle", typeid(bool (*)(Point , Point , Point , GL_Color )), ".5589e557565383e4f081ec????????", argdata, 4, 2, &func);
}

__declspec(naked) bool CSurface::GL_DrawTriangle(Point vertex1, Point vertex2, Point vertex3, GL_Color color)
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
		"push [ebp+44]\n\t"		// color
		"push [ebp+40]\n\t"		// color
		"push [ebp+36]\n\t"		// color
		"push [ebp+32]\n\t"		// color
		"push [ebp+28]\n\t"		// vertex3
		"push [ebp+24]\n\t"		// vertex3
		"push [ebp+20]\n\t"		// vertex2
		"push [ebp+16]\n\t"		// vertex2
		"push [ebp+12]\n\t"		// vertex1
		"push [ebp+8]\n\t"		// vertex1
	);
	__asm__("call %0\n\t" :: "m"(_func393::func));
	__asm__
	(
		"add esp, 40\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 40\n\t"
	);
}

namespace _func394
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawRect", typeid(bool (*)(float , float , float , float , GL_Color )), ".5589e583e4f081ec????????a1????????8b15????????f30f106d08f30f10650c", argdata, 5, 2, &func);
}

__declspec(naked) bool CSurface::GL_DrawRect(float x1, float y1, float x2, float y2, GL_Color color)
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
		"push [ebp+36]\n\t"		// color
		"push [ebp+32]\n\t"		// color
		"push [ebp+28]\n\t"		// color
		"push [ebp+24]\n\t"		// color
		"push [ebp+20]\n\t"		// y2
		"push [ebp+16]\n\t"		// x2
		"push [ebp+12]\n\t"		// y1
		"push [ebp+8]\n\t"		// x1
	);
	__asm__("call %0\n\t" :: "m"(_func394::func));
	__asm__
	(
		"add esp, 32\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 32\n\t"
	);
}

namespace _func395
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawRectOutline", typeid(bool (*)(int , int , int , int , GL_Color , float )), ".5589e583e4f081ec????????8b55108b4514f30f106520f30f11642424", argdata, 6, 2, &func);
}

__declspec(naked) bool CSurface::GL_DrawRectOutline(int x1, int y1, int x2, int y2, GL_Color color, float lineWidth)
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
		"push [ebp+40]\n\t"		// lineWidth
		"push [ebp+36]\n\t"		// color
		"push [ebp+32]\n\t"		// color
		"push [ebp+28]\n\t"		// color
		"push [ebp+24]\n\t"		// color
		"push [ebp+20]\n\t"		// y2
		"push [ebp+16]\n\t"		// x2
		"push [ebp+12]\n\t"		// y1
		"push [ebp+8]\n\t"		// x1
	);
	__asm__("call %0\n\t" :: "m"(_func395::func));
	__asm__
	(
		"add esp, 36\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 36\n\t"
	);
}

namespace _func396
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitImage", typeid(bool (*)(GL_Texture *, float , float , float , float , float , GL_Color , bool )), ".5589e5565383e4f081ec????????8b5520", argdata, 8, 2, &func);
}

__declspec(naked) bool CSurface::GL_BlitImage(GL_Texture *tex, float x, float y, float x2, float y2, float rotation, GL_Color color, bool mirror)
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
		"push [ebp+48]\n\t"		// mirror
		"push [ebp+44]\n\t"		// color
		"push [ebp+40]\n\t"		// color
		"push [ebp+36]\n\t"		// color
		"push [ebp+32]\n\t"		// color
		"push [ebp+28]\n\t"		// rotation
		"push [ebp+24]\n\t"		// y2
		"push [ebp+20]\n\t"		// x2
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// tex
	);
	__asm__("call %0\n\t" :: "m"(_func396::func));
	__asm__
	(
		"add esp, 44\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 44\n\t"
	);
}

namespace _func397
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitPixelImage", typeid(bool (*)(GL_Texture *, float , float , float , float , float , GL_Color , bool )), ".5589e557565383e4f081ec????????8b5520", argdata, 8, 2, &func);
}

__declspec(naked) bool CSurface::GL_BlitPixelImage(GL_Texture *tex, float x, float y, float x2, float y2, float rotation, GL_Color color, bool mirror)
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
		"push [ebp+48]\n\t"		// mirror
		"push [ebp+44]\n\t"		// color
		"push [ebp+40]\n\t"		// color
		"push [ebp+36]\n\t"		// color
		"push [ebp+32]\n\t"		// color
		"push [ebp+28]\n\t"		// rotation
		"push [ebp+24]\n\t"		// y2
		"push [ebp+20]\n\t"		// x2
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// tex
	);
	__asm__("call %0\n\t" :: "m"(_func397::func));
	__asm__
	(
		"add esp, 44\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 44\n\t"
	);
}

namespace _func398
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitImagePartial", typeid(bool (*)(GL_Texture *, float , float , float , float , float , float , float , float , float , GL_Color , bool )), ".5589e557565383e4f083ec60807d4000", argdata, 12, 2, &func);
}

__declspec(naked) bool CSurface::GL_BlitImagePartial(GL_Texture *tex, float x, float y, float size_x, float size_y, float start_x, float end_x, float start_y, float end_y, float alpha, GL_Color color, bool mirror)
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
		"push [ebp+64]\n\t"		// mirror
		"push [ebp+60]\n\t"		// color
		"push [ebp+56]\n\t"		// color
		"push [ebp+52]\n\t"		// color
		"push [ebp+48]\n\t"		// color
		"push [ebp+44]\n\t"		// alpha
		"push [ebp+40]\n\t"		// end_y
		"push [ebp+36]\n\t"		// start_y
		"push [ebp+32]\n\t"		// end_x
		"push [ebp+28]\n\t"		// start_x
		"push [ebp+24]\n\t"		// size_y
		"push [ebp+20]\n\t"		// size_x
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// tex
	);
	__asm__("call %0\n\t" :: "m"(_func398::func));
	__asm__
	(
		"add esp, 60\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 60\n\t"
	);
}

namespace _func399
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitPixelImageWide", typeid(bool (*)(GL_Texture *, float , float , int , int , float , GL_Color , bool )), ".5589e557565383e4f081ec????????", argdata, 8, 2, &func);
}

__declspec(naked) bool CSurface::GL_BlitPixelImageWide(GL_Texture *tex, float x, float y, int x2, int y2, float opacity, GL_Color color, bool mirror)
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
		"push [ebp+48]\n\t"		// mirror
		"push [ebp+44]\n\t"		// color
		"push [ebp+40]\n\t"		// color
		"push [ebp+36]\n\t"		// color
		"push [ebp+32]\n\t"		// color
		"push [ebp+28]\n\t"		// opacity
		"push [ebp+24]\n\t"		// y2
		"push [ebp+20]\n\t"		// x2
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// tex
	);
	__asm__("call %0\n\t" :: "m"(_func399::func));
	__asm__
	(
		"add esp, 44\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 44\n\t"
	);
}

namespace _func400
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_RenderPrimitive", typeid(void (*)(GL_Primitive *)), ".5589e55383e4f083ec208b5d0885db0f84????????a1????????8b15????????39d00f84????????29d0", argdata, 1, 6, &func);
}

__declspec(naked) void CSurface::GL_RenderPrimitive(GL_Primitive *primitive)
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
		"push [ebp+8]\n\t"		// primitive
	);
	__asm__("call %0\n\t" :: "m"(_func400::func));
	__asm__
	(
		"add esp, 4\n\t"
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

namespace _func401
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_RenderPrimitiveWithAlpha", typeid(void (*)(GL_Primitive *, float )), ".5589e55383e4f083ec208b5d0885db0f84????????a1????????8b15????????39d00f84????????", argdata, 2, 6, &func);
}

__declspec(naked) void CSurface::GL_RenderPrimitiveWithAlpha(GL_Primitive *primitive, float alpha)
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
		"push [ebp+12]\n\t"		// alpha
		"push [ebp+8]\n\t"		// primitive
	);
	__asm__("call %0\n\t" :: "m"(_func401::func));
	__asm__
	(
		"add esp, 8\n\t"
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

namespace _func402
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_RenderPrimitiveWithColor", typeid(void (*)(GL_Primitive *, GL_Color )), ".5589e55383e4f083ec208b5d08f30f10450cf30f105d1085dbf30f106d14f30f1065180f84????????a1????????8b15????????39d00f84????????", argdata, 2, 6, &func);
}

__declspec(naked) void CSurface::GL_RenderPrimitiveWithColor(GL_Primitive *primitive, GL_Color color)
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
		"push [ebp+24]\n\t"		// color
		"push [ebp+20]\n\t"		// color
		"push [ebp+16]\n\t"		// color
		"push [ebp+12]\n\t"		// color
		"push [ebp+8]\n\t"		// primitive
	);
	__asm__("call %0\n\t" :: "m"(_func402::func));
	__asm__
	(
		"add esp, 20\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 20\n\t"
	);
}

namespace _func403
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_DestroyPrimitive", typeid(void (*)(GL_Primitive *)), ".5589e55383e4f083ec108b5d0885db74??8b4324890424e8????????891c24e8????????", argdata, 1, 6, &func);
}

__declspec(naked) void CSurface::GL_DestroyPrimitive(GL_Primitive *primitive)
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
		"push [ebp+8]\n\t"		// primitive
	);
	__asm__("call %0\n\t" :: "m"(_func403::func));
	__asm__
	(
		"add esp, 4\n\t"
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

namespace _func404
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateRectPrimitive", typeid(GL_Primitive *(*)(float , float , float , float , GL_Color )), ".5589e55383e4f083ec50f30f10450cc70424????????f30f11442434f30f1144243cf30f584514f30f104d08f30f105510f30f58d1", argdata, 5, 2, &func);
}

__declspec(naked) GL_Primitive *CSurface::GL_CreateRectPrimitive(float x, float y, float w, float h, GL_Color color)
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
		"push [ebp+36]\n\t"		// color
		"push [ebp+32]\n\t"		// color
		"push [ebp+28]\n\t"		// color
		"push [ebp+24]\n\t"		// color
		"push [ebp+20]\n\t"		// h
		"push [ebp+16]\n\t"		// w
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func404::func));
	__asm__
	(
		"add esp, 32\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 32\n\t"
	);
}

namespace _func405
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::AddTexVertices", typeid(void (*)(std::vector<GL_TexVertex> *, float , float , float , float , float , float , float , float )), "8d4c240483e4f0ff71fc5589e55756535183ec388b39f30f105104f30f1059088b17", argdata, 9, 6, &func);
}

__declspec(naked) void CSurface::AddTexVertices(std::vector<GL_TexVertex> *vec, float x1, float y1, float u1, float v1, float x2, float y2, float u2, float v2)
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
		"push [ebp+40]\n\t"		// v2
		"push [ebp+36]\n\t"		// u2
		"push [ebp+32]\n\t"		// y2
		"push [ebp+28]\n\t"		// x2
		"push [ebp+24]\n\t"		// v1
		"push [ebp+20]\n\t"		// u1
		"push [ebp+16]\n\t"		// y1
		"push [ebp+12]\n\t"		// x1
		"push [ebp+8]\n\t"		// vec
	);
	__asm__("call %0\n\t" :: "m"(_func405::func));
	__asm__
	(
		"add esp, 36\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 36\n\t"
	);
}

namespace _func406
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateMultiImagePrimitive", typeid(GL_Primitive *(*)(GL_Texture *, std::vector<GL_TexVertex> *, GL_Color )), "8d4c240483e4f0ff71fc5589e55756535183ec588b71048b198b4604", argdata, 3, 2, &func);
}

__declspec(naked) GL_Primitive *CSurface::GL_CreateMultiImagePrimitive(GL_Texture *tex, std::vector<GL_TexVertex> *vec, GL_Color color)
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
		"push [ebp+28]\n\t"		// color
		"push [ebp+24]\n\t"		// color
		"push [ebp+20]\n\t"		// color
		"push [ebp+16]\n\t"		// color
		"push [ebp+12]\n\t"		// vec
		"push [ebp+8]\n\t"		// tex
	);
	__asm__("call %0\n\t" :: "m"(_func406::func));
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

namespace _func407
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateImagePrimitive", typeid(GL_Primitive *(*)(GL_Texture *, float , float , float , float , float , GL_Color )), "8d4c240483e4f0ff71fc5589e556535183ec5c8b31f30f105118f30f1035????????0f2ed6f30f10690cf30f106110f30f116dc0f30f1165c4", argdata, 7, 2, &func);
}

__declspec(naked) GL_Primitive *CSurface::GL_CreateImagePrimitive(GL_Texture *tex, float x, float y, float size_x, float size_y, float rotate, GL_Color color)
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
		"push [ebp+44]\n\t"		// color
		"push [ebp+40]\n\t"		// color
		"push [ebp+36]\n\t"		// color
		"push [ebp+32]\n\t"		// color
		"push [ebp+28]\n\t"		// rotate
		"push [ebp+24]\n\t"		// size_y
		"push [ebp+20]\n\t"		// size_x
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// tex
	);
	__asm__("call %0\n\t" :: "m"(_func407::func));
	__asm__
	(
		"add esp, 40\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 40\n\t"
	);
}

namespace _func408
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateMultiLinePrimitive", typeid(GL_Primitive *(*)(std::vector<GL_Line> &, GL_Color , float )), "5589e557565383e4f083ec508b7d08f30f10651c8b77042b3789f2c1fa040f2e25????????0f8a????????0f85????????8d0c95????????89d08954244c", argdata, 3, 2, &func);
}

__declspec(naked) GL_Primitive *CSurface::GL_CreateMultiLinePrimitive(std::vector<GL_Line> &vec, GL_Color color, float thickness)
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
		"push [ebp+28]\n\t"		// thickness
		"push [ebp+24]\n\t"		// color
		"push [ebp+20]\n\t"		// color
		"push [ebp+16]\n\t"		// color
		"push [ebp+12]\n\t"		// color
		"push [ebp+8]\n\t"		// vec
	);
	__asm__("call %0\n\t" :: "m"(_func408::func));
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

namespace _func409
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("DamageMessage::constructor", typeid(void (DamageMessage::*)(float , Pointf , DamageMessage::MessageType )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b4f0c8b47048b5708f30f1007c703????????f30f114304c643080085c9", argdata, 4, 5, &func);
}

__declspec(naked) void DamageMessage::constructor(float length, Pointf pos, DamageMessage::MessageType type)
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
		"push [ebp+20]\n\t"		// type
		"push [ebp+16]\n\t"		// pos
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// length
	);
	__asm__("call %0\n\t" :: "m"(_func409::func));
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

namespace _func410
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("DebugHelper::CrashCatcher", typeid(int (*)(void *)), "8d4c240483e4f0ff71fc5589e55756535181ec????????8b018d8d30f8ffffc785acf2ffff00000000c685b0f2ffff00898590f2ffff8d85b0f2ffff8985a8f2ffffe8????????", argdata, 1, 0, &func);
}

__declspec(naked) int DebugHelper::CrashCatcher(void *exception_pointers)
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
		"push [ebp+8]\n\t"		// exception_pointers
	);
	__asm__("call %0\n\t" :: "m"(_func410::func));
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

namespace _func411
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("DefenseDrone::ValidTargetObject", typeid(bool (DefenseDrone::*)(Targetable *)), "5589e55756538b5d0883e4f085db74??8b430483f80274??", argdata, 2, 1, &func);
}

__declspec(naked) bool DefenseDrone::ValidTargetObject(Targetable *other)
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
		"push [ebp+8]\n\t"		// other
	);
	__asm__("call %0\n\t" :: "m"(_func411::func));
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

namespace _func412
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("DefenseDrone::PickTarget", typeid(void (DefenseDrone::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c80b955020000000f84????????0fb6710c", argdata, 1, 5, &func);
}

__declspec(naked) void DefenseDrone::PickTarget()
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
	__asm__("call %0\n\t" :: "m"(_func412::func));
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

namespace _func413
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Description::copy_assign_1", typeid(Description &(Description::*)(Description &&)), "578d7c240883e4f0ff77fc5589e557565389ce83ec1c8b1f891c24e8????????0fb643188d4e1c83ec048846188d431c890424e8????????0fb643348d4e3883ec04", argdata, 2, 1, &func);
}

__declspec(naked) Description &Description::copy_assign_1(Description &&other)
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
		"push [ebp+8]\n\t"		// other
	);
	__asm__("call %0\n\t" :: "m"(_func413::func));
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

namespace _func414
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Description::copy_assign_2", typeid(Description &(Description::*)(const Description &)), ".578d7c240883e4f0ff77fc5589e557565389ce83ec1c8b1f891c24e8????????0fb643188d4e1c83ec048846188d431c890424e8????????0fb643348d4e3883ec04", argdata, 2, 1, &func);
}

__declspec(naked) Description &Description::copy_assign_2(const Description &other)
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
		"push [ebp+8]\n\t"		// other
	);
	__asm__("call %0\n\t" :: "m"(_func414::func));
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

namespace _func415
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Description::destructor", typeid(void (Description::*)()), "558d918c00000089e55389cb83e4f083ec108b818400000039d074??890424e8????????8b43688d537039d074??890424e8????????8b43388d534039d0", argdata, 1, 5, &func);
}

__declspec(naked) void Description::destructor()
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
	__asm__("call %0\n\t" :: "m"(_func415::func));
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

namespace _func416
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Door::FakeClose", typeid(void (Door::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c80791800c641200075??", argdata, 1, 5, &func);
}

__declspec(naked) void Door::FakeClose()
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
	__asm__("call %0\n\t" :: "m"(_func416::func));
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

namespace _func417
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Door::IsSealed", typeid(bool (Door::*)(int )), "8b913c0200008b410485d27e??85c00f94c00fb6c08b511c85d274??80791800", argdata, 2, 1, &func);
}

__declspec(naked) bool Door::IsSealed(int shipId)
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
	__asm__("call %0\n\t" :: "m"(_func417::func));
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

namespace _func418
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Door::FakeOpen", typeid(void (Door::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c83b9b400000004", argdata, 1, 5, &func);
}

__declspec(naked) void Door::FakeOpen()
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
	__asm__("call %0\n\t" :: "m"(_func418::func));
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

namespace _func419
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("DroneBlueprint::RenderIcon", typeid(void (DroneBlueprint::*)(float )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????e8????????8b83b8000000", argdata, 2, 5, &func);
}

__declspec(naked) void DroneBlueprint::RenderIcon(float scale)
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
		"push [ebp+8]\n\t"		// scale
	);
	__asm__("call %0\n\t" :: "m"(_func419::func));
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

namespace _func420
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("DroneSystem::RemoveDrone", typeid(void (DroneSystem::*)(int )), "5731c08d7c240883e4f0ff77fc5589e557565383ec4c8b1f85db0f88????????89ce", argdata, 2, 5, &func);
}

__declspec(naked) void DroneSystem::RemoveDrone(int slot)
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
		"push [ebp+8]\n\t"		// slot
	);
	__asm__("call %0\n\t" :: "m"(_func420::func));
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

namespace _func421
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("DroneSystem::UpdateBonusPower", typeid(void (DroneSystem::*)()), "578d7c240883e4f0ff77fc5589e557565383ec2c8b81700100008b91c0010000c745e4000000008945dc8b81c401000029d0c1f802", argdata, 1, 5, &func);
}

__declspec(naked) void DroneSystem::UpdateBonusPower()
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
	__asm__("call %0\n\t" :: "m"(_func421::func));
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

namespace _func422
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("DroneSystem::SetBonusPower", typeid(void (DroneSystem::*)(int , int )), ".5589e556538b750889cb83e4f0e8????????39f089d90f4fc6898370010000", argdata, 3, 5, &func);
}

__declspec(naked) void DroneSystem::SetBonusPower(int amount, int permanentPower)
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
		"push [ebp+12]\n\t"		// permanentPower
		"push [ebp+8]\n\t"		// amount
	);
	__asm__("call %0\n\t" :: "m"(_func422::func));
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

namespace _func423
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("DropBox::OnRender", typeid(void (DropBox::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????e8????????8b43148b7c830c89f8", argdata, 1, 5, &func);
}

__declspec(naked) void DropBox::OnRender()
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
	__asm__("call %0\n\t" :: "m"(_func423::func));
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

namespace _func424
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("DropBox::GetHeight", typeid(int (DropBox::*)()), "8b510c89d085c074??8b42080381ac0000000381a8000000c38db42600000000b8????????0381ac000000", argdata, 1, 1, &func);
}

__declspec(naked) int DropBox::GetHeight()
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
	__asm__("call %0\n\t" :: "m"(_func424::func));
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

namespace _func425
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("EnergyAlien::OnLoop", typeid(void (EnergyAlien::*)()), "5589e55389cb83e4f0e8????????8b839c0000008378380374??80bbfc0100000075??c6835907000000c6835a07000000", argdata, 1, 5, &func);
}

__declspec(naked) void EnergyAlien::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func425::func));
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

namespace _func426
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("EnergyAlien::GetRoomDamage", typeid(Damage *(*)(Damage *, EnergyAlien *)), "8b54240489c880ba590700000074??80ba5a0700000074??c700????????c7400400000000c7400800000000c7400c00000000c7401000000000c7401400000000c7401800000000c7401c00000000c6402000c74024ffffffffc74028ffffffffc6402c00c6402d00", argdata, 2, 0, &func);
}

__declspec(naked) Damage *EnergyAlien::GetRoomDamage(Damage *dmg, EnergyAlien *crew)
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
		"push [ebp+12]\n\t"		// crew
		"mov ecx, [ebp+8]\n\t"	// dmg
	);
	__asm__("call %0\n\t" :: "m"(_func426::func));
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

namespace _func427
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
	__asm__("call %0\n\t" :: "m"(_func427::func));
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

namespace _func428
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Equipment::OnLoop", typeid(void (Equipment::*)()), "8b81400200002b813c020000c1f80285c00f84????????578d7c240883e4f0ff77fc5589e55756", argdata, 1, 5, &func);
}

__declspec(naked) void Equipment::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func428::func));
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

namespace _func429
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Equipment::MouseClick", typeid(void (Equipment::*)(int , int )), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b078b570489042489542404e8????????8b835c02000083ec0883f8ff74??8b933c0200008b0c82", argdata, 3, 5, &func);
}

__declspec(naked) void Equipment::MouseClick(int mX, int mY)
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
		"push [ebp+12]\n\t"		// mY
		"push [ebp+8]\n\t"		// mX
	);
	__asm__("call %0\n\t" :: "m"(_func429::func));
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

namespace _func430
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Equipment::MouseUp", typeid(void (Equipment::*)(int , int )), "80b968020000000f84????????578d7c240883e4f0ff77fc5589e557565389cb83ec4c80b934020000000f85????????8b815c02000083f8ff0f84????????8b916002000039d0", argdata, 3, 5, &func);
}

__declspec(naked) void Equipment::MouseUp(int mX, int mY)
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
		"push [ebp+12]\n\t"		// mY
		"push [ebp+8]\n\t"		// mX
	);
	__asm__("call %0\n\t" :: "m"(_func430::func));
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

namespace _func431
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
	__asm__("call %0\n\t" :: "m"(_func431::func));
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

namespace _func432
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
	__asm__("call %0\n\t" :: "m"(_func432::func));
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

namespace _func433
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::SetBlueprint", typeid(void (EquipmentBox::*)(InfoBox *, bool )), "5731c08d7c240883e4f0ff77fc5589e557565389cb83ec1c80b98100000000", argdata, 3, 5, &func);
}

__declspec(naked) void EquipmentBox::SetBlueprint(InfoBox *infoBox, bool detailedBox)
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
		"push [ebp+12]\n\t"		// detailedBox
		"push [ebp+8]\n\t"		// infoBox
	);
	__asm__("call %0\n\t" :: "m"(_func433::func));
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

namespace _func434
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("EquipmentBox::Free", typeid(void (EquipmentBox::*)()), "5589e55389cb83e4f083ec108b4130c701????????890424e8????????8b4334890424", argdata, 1, 5, &func);
}

__declspec(naked) EquipmentBox::~EquipmentBox()
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
	__asm__("call %0\n\t" :: "m"(_func434::func));
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

namespace _func435
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("EquipmentBox::CanHoldWeapon", typeid(bool (EquipmentBox::*)()), ".8b416085c074??85c00f95c0", argdata, 1, 1, &func);
}

__declspec(naked) bool EquipmentBox::CanHoldWeapon()
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
	__asm__("call %0\n\t" :: "m"(_func435::func));
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

namespace _func436
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("EquipmentBox::CanHoldDrone", typeid(bool (EquipmentBox::*)()), ".8b416085c08b416474??85c0", argdata, 1, 1, &func);
}

__declspec(naked) bool EquipmentBox::CanHoldDrone()
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
	__asm__("call %0\n\t" :: "m"(_func436::func));
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

namespace _func437
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("EquipmentBox::GetType", typeid(int (EquipmentBox::*)()), ".8b51608b44240485d274??3c01", argdata, 1, 1, &func);
}

__declspec(naked) int EquipmentBox::GetType()
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
	__asm__("call %0\n\t" :: "m"(_func437::func));
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

namespace _func438
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::OnRender", typeid(void (EquipmentBox::*)(bool )), ".578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b37e8????????660fefc0c74424080000000089f7", argdata, 2, 5, &func);
}

__declspec(naked) void EquipmentBox::OnRender(bool isEmpty)
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
		"push [ebp+8]\n\t"		// isEmpty
	);
	__asm__("call %0\n\t" :: "m"(_func438::func));
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

namespace _func439
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::UpdateBoxImage", typeid(void (EquipmentBox::*)(bool )), ".578d7c240883e4f0ff77fc5589e55756538db560ffffff89cb81ec????????8b07", argdata, 2, 5, &func);
}

__declspec(naked) void EquipmentBox::UpdateBoxImage(bool unk)
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
	__asm__("call %0\n\t" :: "m"(_func439::func));
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

namespace _func440
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::RenderLabels", typeid(void (EquipmentBox::*)(bool )), ".578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b4160", argdata, 2, 5, &func);
}

__declspec(naked) void EquipmentBox::RenderLabels(bool unk)
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
	__asm__("call %0\n\t" :: "m"(_func440::func));
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

namespace _func441
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::MouseMove", typeid(int (EquipmentBox::*)(int , int )), "538b415031db8b54240839c27e??03415839c27d??8b41543944240c7e??", argdata, 3, 1, &func);
}

__declspec(naked) int EquipmentBox::MouseMove(int x, int y)
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
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func441::func));
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

namespace _func442
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x4ff};
	static FunctionDefinition funcObj("EquipmentBox::AddItem", typeid(void (EquipmentBox::*)(EquipmentBoxItem )), ".8b4424048941608b4424088941648b44240c8941688b442410", argdata, 2, 5, &func);
}

__declspec(naked) void EquipmentBox::AddItem(EquipmentBoxItem item)
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
		"push [ebp+20]\n\t"		// item
		"push [ebp+16]\n\t"		// item
		"push [ebp+12]\n\t"		// item
		"push [ebp+8]\n\t"		// item
	);
	__asm__("call %0\n\t" :: "m"(_func442::func));
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

namespace _func443
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("EquipmentBox::Restart", typeid(void (EquipmentBox::*)()), ".660fefc05589e50f1141605d", argdata, 1, 5, &func);
}

__declspec(naked) void EquipmentBox::Restart()
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
	__asm__("call %0\n\t" :: "m"(_func443::func));
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

namespace _func444
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("EquipmentBox::SetPosition", typeid(void (EquipmentBox::*)(Point )), "5589e58b55088b450c5d89514889414c895150894154", argdata, 2, 5, &func);
}

__declspec(naked) void EquipmentBox::SetPosition(Point pos)
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
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// pos
	);
	__asm__("call %0\n\t" :: "m"(_func444::func));
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

namespace _func445
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("EquipmentBox::GetItemValue", typeid(int (EquipmentBox::*)()), "8b416085c074??8b401c8b4070c366908b416485c075??8b416c85c074??8b500885d2", argdata, 1, 1, &func);
}

__declspec(naked) int EquipmentBox::GetItemValue()
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
	__asm__("call %0\n\t" :: "m"(_func445::func));
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

namespace _func446
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventGenerator::GetBaseEvent", typeid(LocationEvent *(EventGenerator::*)(const std::string &, int , char , int )), "578d7c240883e4f0ff77fc5589e557565383ec4c8b4704894dc48b1f8945bc8b47088945c08b470c83f8ff74??803d??????????8904240f85????????e8????????8b7dc48d4f60c6876c01000001c6876d01000000891c24", argdata, 5, 1, &func);
}

__declspec(naked) LocationEvent *EventGenerator::GetBaseEvent(const std::string &name, int worldLevel, char ignoreUnique, int seed)
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
		"push [ebp+20]\n\t"		// seed
		"push [ebp+16]\n\t"		// ignoreUnique
		"push [ebp+12]\n\t"		// worldLevel
		"push [ebp+8]\n\t"		// name
	);
	__asm__("call %0\n\t" :: "m"(_func446::func));
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

namespace _func447
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventGenerator::CreateEvent1", typeid(LocationEvent *(EventGenerator::*)(const std::string &, int )), "578d7c240883e4f0ff77fc5589e557565381ec????????8b5f048b37898dc4fcffff899dbcfcffff8b5f088d7944899dacfcffff89342489f9e8????????83ec04", argdata, 3, 1, &func);
}

__declspec(naked) LocationEvent *EventGenerator::CreateEvent1(const std::string &name, int worldLevel)
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
		"push [ebp+12]\n\t"		// worldLevel
		"push [ebp+8]\n\t"		// name
	);
	__asm__("call %0\n\t" :: "m"(_func447::func));
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

namespace _func448
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventGenerator::GetSpecificSector", typeid(Sector *(*)(SectorDescription *, EventGenerator *, const std::string &)), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????8b078b7f04c744240807690fc789c389851cffffff83c00c", argdata, 3, 0, &func);
}

__declspec(naked) Sector *EventGenerator::GetSpecificSector(SectorDescription *desc, EventGenerator *eventGenerator, const std::string &name)
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
		"push [ebp+16]\n\t"		// name
		"push [ebp+12]\n\t"		// eventGenerator
		"mov ecx, [ebp+8]\n\t"	// desc
	);
	__asm__("call %0\n\t" :: "m"(_func448::func));
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

namespace _func449
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventGenerator::GetImageFromList", typeid(void (*)(std::string &, EventGenerator *, const std::string &)), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b1f8b7f0481c3????????893c2489d9", argdata, 3, 4, &func);
}

__declspec(naked) void EventGenerator::GetImageFromList(std::string &ret, EventGenerator *eventGenerator, const std::string &listName)
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
		"push [ebp+16]\n\t"		// listName
		"push [ebp+12]\n\t"		// eventGenerator
		"mov ecx, [ebp+8]\n\t"	// ret
	);
	__asm__("call %0\n\t" :: "m"(_func449::func));
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

namespace _func450
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::PullMinMax", typeid(RandomAmount *(EventsParser::*)(rapidxml::xml_node<char> *, const std::string &)), "578d7c240883e4f0ff77fc5589e557565389cb8d4da083ec7c8b47088b7704c70424????????894594e8????????", argdata, 3, 1, &func);
}

__declspec(naked) RandomAmount *EventsParser::PullMinMax(rapidxml::xml_node<char> *node, const std::string &name)
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
	__asm__("call %0\n\t" :: "m"(_func450::func));
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

namespace _func451
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::ProcessEvent", typeid(void **(EventsParser::*)(rapidxml::xml_node<char> *, const std::string &, EventTemplate &)), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????8b07898d2cfeffff8b5f08898528feffff8b4704c70424????????89c1898524feffffe8????????83ec0485c074??", argdata, 4, 1, &func);
}

__declspec(naked) void **EventsParser::ProcessEvent(rapidxml::xml_node<char> *node, const std::string &event, EventTemplate &eventref)
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
	__asm__("call %0\n\t" :: "m"(_func451::func));
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

namespace _func452
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::ProcessShipEvent", typeid(ShipTemplate *(*)(ShipTemplate *, EventsParser *, rapidxml::xml_node<char> *)), "578d7c240883e4f0ff77fc5589e557565381ec????????8b078b7704c70424????????89cf898d50fbffff898540fbffffe8????????8d8dbcfbffff83ec04c6471800", argdata, 3, 2, &func);
}

__declspec(naked) ShipTemplate *EventsParser::ProcessShipEvent(ShipTemplate *event, EventsParser *parser, rapidxml::xml_node<char> *node)
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
		"push [ebp+16]\n\t"		// node
		"push [ebp+12]\n\t"		// parser
		"mov ecx, [ebp+8]\n\t"	// event
	);
	__asm__("call %0\n\t" :: "m"(_func452::func));
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
		"ret 12\n\t"
	);
}

namespace _func453
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::ProcessModifyItem", typeid(ResourcesTemplate *(EventsParser::*)(ResourcesTemplate &, rapidxml::xml_node<char> *, const std::string &)), "578d7c240883e4f0ff77fc5589f889e55756538d55d889cf83ec6c8b308b58048955d08975a48b70088b400c", argdata, 4, 1, &func);
}

__declspec(naked) ResourcesTemplate *EventsParser::ProcessModifyItem(ResourcesTemplate &resources, rapidxml::xml_node<char> *node, const std::string &unk)
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
		"push [ebp+16]\n\t"		// unk
		"push [ebp+12]\n\t"		// node
		"push [ebp+8]\n\t"		// resources
	);
	__asm__("call %0\n\t" :: "m"(_func453::func));
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

namespace _func454
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("EventsParser::AddAllEvents", typeid(void (EventsParser::*)()), "578d7c240883e4f0ff77fc5589e55756538d75d08d7dd883ec5c894db4b9????????", argdata, 1, 5, &func);
}

__declspec(naked) void EventsParser::AddAllEvents()
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
	__asm__("call %0\n\t" :: "m"(_func454::func));
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

namespace _func455
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::AddEvents", typeid(void (EventsParser::*)(EventGenerator &, char *, const std::string &)), "57b8????????8d7c240883e4f0ff77fc5589e5575653e8????????29c48b77048b4708898d80fffeff8b1f85f6898578fffeff0f84????????", argdata, 4, 5, &func);
}

__declspec(naked) void EventsParser::AddEvents(EventGenerator &generator, char *file, const std::string &fileName)
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
		"push [ebp+16]\n\t"		// fileName
		"push [ebp+12]\n\t"		// file
		"push [ebp+8]\n\t"		// generator
	);
	__asm__("call %0\n\t" :: "m"(_func455::func));
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

namespace _func456
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("EventSystem::AddEvent", typeid(void (EventSystem::*)(int )), "538b54240885d278??8b590c8b411029d8c1f80239c27d??830493015b", argdata, 2, 5, &func);
}

__declspec(naked) void EventSystem::AddEvent(int id)
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
		"push [ebp+8]\n\t"		// id
	);
	__asm__("call %0\n\t" :: "m"(_func456::func));
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

namespace _func457
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::deleteFile", typeid(void (*)(const std::string &)), "8d4c240483e4f031c0ff71fc5589e5575653518d75d883ec588b39668945d8", argdata, 1, 6, &func);
}

__declspec(naked) void FileHelper::deleteFile(const std::string &fileName)
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
		"push [ebp+8]\n\t"		// fileName
	);
	__asm__("call %0\n\t" :: "m"(_func457::func));
	__asm__
	(
		"add esp, 4\n\t"
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

namespace _func458
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::getResourceFile", typeid(std::string &(*)(const std::string &)), ".8d4c240483e4f0ff71fc5589e557565351", argdata, 1, 2, &func);
}

__declspec(naked) std::string &FileHelper::getResourceFile(const std::string &str)
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
	__asm__("call %0\n\t" :: "m"(_func458::func));
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

namespace _func459
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::getUserFolder", typeid(std::string &(*)(std::string &)), ".8d4c240483e4f0ff71fc5589e5575653", argdata, 1, 2, &func);
}

__declspec(naked) std::string &FileHelper::getUserFolder(std::string &str)
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
	__asm__("call %0\n\t" :: "m"(_func459::func));
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

namespace _func460
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::getSaveFile", typeid(std::string &(*)(std::string &)), ".8d4c240483e4f0ff71fc5589e557565351", argdata, 1, 2, &func);
}

__declspec(naked) std::string &FileHelper::getSaveFile(std::string &str)
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
	__asm__("call %0\n\t" :: "m"(_func460::func));
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

namespace _func461
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::initFileHelper", typeid(void (*)()), ".8d4c240483e4f0ff71fc5589e5575653", argdata, 0, 6, &func);
}

__declspec(naked) void FileHelper::initFileHelper()
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
	__asm__("call %0\n\t" :: "m"(_func461::func));
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

namespace _func462
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::fileLength", typeid(int (*)(int )), ".8d4c240483e4f0ff71fc5589e55183ec14", argdata, 1, 2, &func);
}

__declspec(naked) int FileHelper::fileLength(int file)
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
	__asm__("call %0\n\t" :: "m"(_func462::func));
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

namespace _func463
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::fileExists", typeid(bool (*)(const std::string &)), ".8d4c240483e4f031c0ff71fc5589e55756", argdata, 1, 2, &func);
}

__declspec(naked) bool FileHelper::fileExists(const std::string &fileName)
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
	__asm__("call %0\n\t" :: "m"(_func463::func));
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

namespace _func464
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::renameFile", typeid(void (*)(const std::string &, const std::string &)), ".8d4c240483e4f0ff71fc5589e5575653518d45b88d75d8", argdata, 2, 6, &func);
}

__declspec(naked) void FileHelper::renameFile(const std::string &fileName, const std::string &newName)
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
		"push [ebp+12]\n\t"		// newName
		"push [ebp+8]\n\t"		// fileName
	);
	__asm__("call %0\n\t" :: "m"(_func464::func));
	__asm__
	(
		"add esp, 8\n\t"
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

namespace _func465
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::createBinaryFile", typeid(int (*)(const std::string &)), ".8d4c240483e4f031d2ff71fc5589e5575653518dbd08fcffff81ec????????", argdata, 1, 2, &func);
}

__declspec(naked) int FileHelper::createBinaryFile(const std::string &fileName)
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
	__asm__("call %0\n\t" :: "m"(_func465::func));
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

namespace _func466
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::createSaveFile", typeid(int (*)()), ".a1????????a3????????b8????????", argdata, 0, 2, &func);
}

__declspec(naked) int FileHelper::createSaveFile()
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
	__asm__("call %0\n\t" :: "m"(_func466::func));
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

namespace _func467
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::createStatsFile", typeid(int (*)()), ".a1????????a3????????b8????????", argdata, 0, 2, &func);
}

__declspec(naked) int FileHelper::createStatsFile()
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
	__asm__("call %0\n\t" :: "m"(_func467::func));
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

namespace _func468
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::deleteSaveFile", typeid(void (*)()), ".5589e55383e4f083ec10c70424????????e8????????", argdata, 0, 6, &func);
}

__declspec(naked) void FileHelper::deleteSaveFile()
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
	__asm__("call %0\n\t" :: "m"(_func468::func));
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

namespace _func469
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::deleteAllSaveFiles", typeid(void (*)()), ".8d4c240483e4f0ff71fc5589e5575653518d45b8", argdata, 0, 6, &func);
}

__declspec(naked) void FileHelper::deleteAllSaveFiles()
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
	__asm__("call %0\n\t" :: "m"(_func469::func));
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

namespace _func470
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::getPosition", typeid(int (*)(int )), ".8d4c240483e4f0ff71fc5589e55183ec14", argdata, 1, 2, &func);
}

__declspec(naked) int FileHelper::getPosition(int file)
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
	__asm__("call %0\n\t" :: "m"(_func470::func));
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

namespace _func471
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::readBinaryFile", typeid(int (*)(const std::string &)), ".8d4c240483e4f0ff71fc5589e5575653", argdata, 1, 2, &func);
}

__declspec(naked) int FileHelper::readBinaryFile(const std::string &fileName)
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
	__asm__("call %0\n\t" :: "m"(_func471::func));
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

namespace _func472
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::closeBinaryFile", typeid(void (*)(int )), ".8d4c240483e4f0ff71fc5589e5535183ec10", argdata, 1, 6, &func);
}

__declspec(naked) void FileHelper::closeBinaryFile(int file)
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
	__asm__("call %0\n\t" :: "m"(_func472::func));
	__asm__
	(
		"add esp, 4\n\t"
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

namespace _func473
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::readString", typeid(std::string &(*)(const std::string &, int )), ".8d4c240483e4f0ff71fc5589e55756535183ec48", argdata, 2, 2, &func);
}

__declspec(naked) std::string &FileHelper::readString(const std::string &str, int file)
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
		"push [ebp+12]\n\t"		// file
		"push [ebp+8]\n\t"		// str
	);
	__asm__("call %0\n\t" :: "m"(_func473::func));
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

namespace _func474
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::readFloat", typeid(float (*)(int )), ".8d4c240483e4f0ff71fc5589e557565351", argdata, 1, 2, &func);
}

__declspec(naked) float FileHelper::readFloat(int file)
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
	__asm__("call %0\n\t" :: "m"(_func474::func));
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

namespace _func475
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::readInteger", typeid(int (*)(int )), ".8d4c240483e4f0ff71fc5589e55756535183ec48", argdata, 1, 2, &func);
}

__declspec(naked) int FileHelper::readInteger(int file)
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
	__asm__("call %0\n\t" :: "m"(_func475::func));
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

namespace _func476
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::seekPosition", typeid(bool (*)(int , int )), ".8d4c240483e4f0ff71fc5589e5535183ec10", argdata, 2, 2, &func);
}

__declspec(naked) bool FileHelper::seekPosition(int file, int pos)
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
		"push [ebp+8]\n\t"		// file
	);
	__asm__("call %0\n\t" :: "m"(_func476::func));
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

namespace _func477
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::readBuffer", typeid(char *(*)(int , int , bool )), ".8d4c240483e4f0ff71fc5589e55756", argdata, 3, 2, &func);
}

__declspec(naked) char *FileHelper::readBuffer(int file, int len, bool unk)
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
		"push [ebp+16]\n\t"		// unk
		"push [ebp+12]\n\t"		// len
		"push [ebp+8]\n\t"		// file
	);
	__asm__("call %0\n\t" :: "m"(_func477::func));
	__asm__
	(
		"add esp, 12\n\t"
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

namespace _func478
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::readData", typeid(void (*)(int , void *, int )), ".8d4c240483e4f0ff71fc5589e557565351", argdata, 3, 6, &func);
}

__declspec(naked) void FileHelper::readData(int file, void *data, int len)
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
		"push [ebp+16]\n\t"		// len
		"push [ebp+12]\n\t"		// data
		"push [ebp+8]\n\t"		// file
	);
	__asm__("call %0\n\t" :: "m"(_func478::func));
	__asm__
	(
		"add esp, 12\n\t"
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

namespace _func479
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::writeData", typeid(bool (*)(int , void *, int )), ".8d4c240483e4f0ff71fc5589e5575653", argdata, 3, 2, &func);
}

__declspec(naked) bool FileHelper::writeData(int file, void *data, int len)
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
		"push [ebp+16]\n\t"		// len
		"push [ebp+12]\n\t"		// data
		"push [ebp+8]\n\t"		// file
	);
	__asm__("call %0\n\t" :: "m"(_func479::func));
	__asm__
	(
		"add esp, 12\n\t"
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

namespace _func480
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::readSaveFile", typeid(int (*)()), ".8d4c240483e4f0ff71fc5589e55351", argdata, 0, 2, &func);
}

__declspec(naked) int FileHelper::readSaveFile()
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
	__asm__("call %0\n\t" :: "m"(_func480::func));
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

namespace _func481
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::readStatsFile", typeid(int (*)()), ".8d4c240483e4f0ff71fc5589e553518d45f483ec20", argdata, 0, 2, &func);
}

__declspec(naked) int FileHelper::readStatsFile()
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
	__asm__("call %0\n\t" :: "m"(_func481::func));
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

namespace _func482
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::saveFileExists", typeid(bool (*)()), ".8d4c240483e4f0ff71fc5589e553518d45f483ec2089442408", argdata, 0, 2, &func);
}

__declspec(naked) bool FileHelper::saveFileExists()
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
	__asm__("call %0\n\t" :: "m"(_func482::func));
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

namespace _func483
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::writeFloat", typeid(bool (*)(int , float )), ".8d4c240483e4f0ff71fc5589e5565351", argdata, 2, 2, &func);
}

__declspec(naked) bool FileHelper::writeFloat(int file, float data)
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
		"push [ebp+12]\n\t"		// data
		"push [ebp+8]\n\t"		// file
	);
	__asm__("call %0\n\t" :: "m"(_func483::func));
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

namespace _func484
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::writeString", typeid(bool (*)(int , const std::string &)), ".8d4c240483e4f0ff71fc5589e55756535183ec488b41048b318b38", argdata, 2, 2, &func);
}

__declspec(naked) bool FileHelper::writeString(int file, const std::string &data)
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
		"push [ebp+12]\n\t"		// data
		"push [ebp+8]\n\t"		// file
	);
	__asm__("call %0\n\t" :: "m"(_func484::func));
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

namespace _func485
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::writeInt", typeid(bool (*)(int , int )), "8d4c240483e4f0ff71fc5589e556535183ec3c803d??????????8b41048b198945e075??", argdata, 2, 2, &func);
}

__declspec(naked) bool FileHelper::writeInt(int file, int data)
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
		"push [ebp+12]\n\t"		// data
		"push [ebp+8]\n\t"		// file
	);
	__asm__("call %0\n\t" :: "m"(_func485::func));
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

namespace _func486
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_measurePrintLines", typeid(double (*)(int , float , float , int , const std::string &)), "8d4c240483e4f0ff71fc5589e5575653518d75d883ec488b018975d08945c08b410c8945bc8b41108b38", argdata, 5, 10, &func);
}

__declspec(naked) double freetype::easy_measurePrintLines(int fontData, float x, float y, int width, const std::string &text)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
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
	__asm__("call %0\n\t" :: "m"(_func486::func));
	__asm__
	(
		"add esp, 20\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 20\n\t"
	);
}

namespace _func487
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_print", typeid(int (*)(int , float , float , const std::string &)), "8d4c240483e4f0ff71fc5589e5575653518d7dd883ec588b01897dd0", argdata, 4, 2, &func);
}

__declspec(naked) int freetype::easy_print(int fontData, float x, float y, const std::string &text)
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
	__asm__("call %0\n\t" :: "m"(_func487::func));
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

namespace _func488
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printRightAlign", typeid(int (*)(int , float , float , const std::string &)), ".8d4c240483e4f0ff71fc5589e5575653518d7dd883ec588b01897dd0f30f104104f30f1049088945c08b410c", argdata, 4, 2, &func);
}

__declspec(naked) int freetype::easy_printRightAlign(int fontData, float x, float y, const std::string &text)
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
	__asm__("call %0\n\t" :: "m"(_func488::func));
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

namespace _func489
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printNewlinesCentered", typeid(int (*)(int , float , float , int , const std::string &)), ".8d4c240483e4f0ff71fc5589e557565351", argdata, 5, 2, &func);
}

__declspec(naked) int freetype::easy_printNewlinesCentered(int fontData, float x, float y, int width, const std::string &text)
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
	__asm__("call %0\n\t" :: "m"(_func489::func));
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

namespace _func490
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printAutoNewlines", typeid(int (*)(int , float , float , int , const std::string &)), ".8d4c240483e4f0ff71fc5589e5575653518d75d883ec68", argdata, 5, 2, &func);
}

__declspec(naked) int freetype::easy_printAutoNewlines(int fontData, float x, float y, int width, const std::string &text)
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
	__asm__("call %0\n\t" :: "m"(_func490::func));
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

namespace _func491
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printCenter", typeid(double (*)(int , float , float , const std::string &)), ".8d4c240483e4f0ff71fc5589e5575653518d7dd883ec588b01", argdata, 4, 10, &func);
}

__declspec(naked) double freetype::easy_printCenter(int fontData, float x, float y, const std::string &text)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+20]\n\t"		// text
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// fontData
	);
	__asm__("call %0\n\t" :: "m"(_func491::func));
	__asm__
	(
		"add esp, 16\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 16\n\t"
	);
}

namespace _func492
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printAutoShrink", typeid(int (*)(int , float , float , int , char , const std::string &)), ".8d4c240483e4f0ff71fc5589e55756535181ec????????8b5110", argdata, 6, 2, &func);
}

__declspec(naked) int freetype::easy_printAutoShrink(int fontData, float x, float y, int width, char unk, const std::string &text)
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
	__asm__("call %0\n\t" :: "m"(_func492::func));
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

namespace _func493
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("GameOver::OpenText", typeid(void (GameOver::*)(const std::string &)), "578d7c240883e4f0ff77fc5589f889e557565389cf83c14c81ec????????8b00c641b801", argdata, 2, 5, &func);
}

__declspec(naked) void GameOver::OpenText(const std::string &text)
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
		"push [ebp+8]\n\t"		// text
	);
	__asm__("call %0\n\t" :: "m"(_func493::func));
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

namespace _func494
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("GameOver::OnRender", typeid(void (GameOver::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????80b9d0000000000f85????????807940000f85????????8b4728bb????????890424e8????????", argdata, 1, 5, &func);
}

__declspec(naked) void GameOver::OnRender()
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
	__asm__("call %0\n\t" :: "m"(_func494::func));
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

namespace _func495
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("GenericButton::SetLocation", typeid(void (GenericButton::*)(Point )), "5589e557568b4508538b59048b550c83e4f08b710839d874??89c78941048b0129df89d301790c29f3015910895108ff50308d65f45b5e5f5dc20800", argdata, 2, 5, &func);
}

__declspec(naked) void GenericButton::SetLocation(Point pos)
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
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// pos
	);
	__asm__("call %0\n\t" :: "m"(_func495::func));
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

namespace _func496
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
	__asm__("call %0\n\t" :: "m"(_func496::func));
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

namespace _func497
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("GenericButton::MouseMove", typeid(void (GenericButton::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589e5575383ec108b178b410c8b5f048b7f0839c27e??03411439c27c??c6414100", argdata, 4, 5, &func);
}

__declspec(naked) void GenericButton::MouseMove(int x, int y, bool silent)
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
		"push [ebp+16]\n\t"		// silent
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func497::func));
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

namespace _func498
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("GenericButton::OnRightClick", typeid(void (GenericButton::*)()), "f3c39090909090909090909090909090", argdata, 1, 5, &func);
}

__declspec(naked) void GenericButton::OnRightClick()
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
	__asm__("call %0\n\t" :: "m"(_func498::func));
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

namespace _func499
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("GenericButton::ResetPrimitives", typeid(void (GenericButton::*)()), ".f3c39090909090909090909090909090", argdata, 1, 5, &func);
}

__declspec(naked) void GenericButton::ResetPrimitives()
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
	__asm__("call %0\n\t" :: "m"(_func499::func));
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

namespace _func500
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("GenericButton::OnClick", typeid(void (GenericButton::*)()), ".f3c39090909090909090909090909090", argdata, 1, 5, &func);
}

__declspec(naked) void GenericButton::OnClick()
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
	__asm__("call %0\n\t" :: "m"(_func500::func));
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

namespace _func501
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("font_text_width", typeid(float (*)(freetype::font_data &, const char *, float )), "5589e557565383e4f083ec408b4d088b750c85c9", argdata, 3, 0, &func);
}

__declspec(naked) float __stdcall font_text_width(freetype::font_data &fontData, const char *str, float size)
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
		"push [ebp+16]\n\t"		// size
		"push [ebp+12]\n\t"		// str
		"push [ebp+8]\n\t"		// fontData
	);
	__asm__("call %0\n\t" :: "m"(_func501::func));
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

namespace _func502
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("random32", typeid(int (*)()), "556905????????????????89e556536935????????????????83e4f801c6b8????????f725????????01f283c00183d200a3????????8915????????", argdata, 0, 0, &func);
}

__declspec(naked) int __stdcall random32()
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
	__asm__("call %0\n\t" :: "m"(_func502::func));
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

namespace _func503
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("srandom32", typeid(void (*)(unsigned int )), "55c705????????????????89e583e4f88b4508a3????????", argdata, 1, 6, &func);
}

__declspec(naked) void __stdcall srandom32(unsigned int seed)
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
		"push [ebp+8]\n\t"		// seed
	);
	__asm__("call %0\n\t" :: "m"(_func503::func));
	__asm__
	(
		"add esp, 4\n\t"
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

namespace _func504
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("getSkillBonus", typeid(float (*)(int , int )), "83ec048b4424088b54240c83f80577??ff2485????????89f68dbc270000000085d2660fefc074??83fa010f84????????", argdata, 2, 0, &func);
}

__declspec(naked) float __stdcall getSkillBonus(int skill, int level)
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
		"push [ebp+12]\n\t"		// level
		"push [ebp+8]\n\t"		// skill
	);
	__asm__("call %0\n\t" :: "m"(_func504::func));
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

namespace _func505
{
	static void *func = 0;
	static short argdata[] = {0x2ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("Globals::AimAhead", typeid(float (*)(Pointf , Pointf , float )), "5589e583e4f083ec20f30f106510f30f1045140f28f40f28d0f30f59e4f30f59c0f30f104d08f30f105d0cf30f59f1f30f106d18f30f59d3f30f59ed", argdata, 3, 2, &func);
}

__declspec(naked) float Globals::AimAhead(Pointf delta, Pointf vr, float muzzleV)
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
		"push [ebp+24]\n\t"		// muzzleV
		"push [ebp+20]\n\t"		// vr
		"push [ebp+16]\n\t"		// vr
		"push [ebp+12]\n\t"		// delta
		"push [ebp+8]\n\t"		// delta
	);
	__asm__("call %0\n\t" :: "m"(_func505::func));
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

namespace _func506
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Globals::GetNextSpaceId", typeid(int (*)()), "8b15????????8d420185d2ba????????0f44c2a3????????", argdata, 0, 0, &func);
}

__declspec(naked) int Globals::GetNextSpaceId()
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
	__asm__("call %0\n\t" :: "m"(_func506::func));
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

namespace _func507
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("HackingDrone::OnLoop", typeid(void (HackingDrone::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec6ce8????????", argdata, 1, 5, &func);
}

__declspec(naked) void HackingDrone::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func507::func));
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

namespace _func508
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("HackingSystem::BlowHackingDrone", typeid(void (HackingSystem::*)()), "80b9d80100000075??c38db6000000005781c1????????8d7c240883e4f0ff77fc5589e55783ec14c70424????????e8????????8b7dfc", argdata, 1, 5, &func);
}

__declspec(naked) void HackingSystem::BlowHackingDrone()
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
	__asm__("call %0\n\t" :: "m"(_func508::func));
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

namespace _func509
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("HackingSystem::OnLoop", typeid(void (HackingSystem::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec4ce8????????80bbe4010000000f84????????80bbc0010000000f84????????8b8bac070000", argdata, 1, 5, &func);
}

__declspec(naked) void HackingSystem::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func509::func));
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

namespace _func510
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("InfoBox::OnRender", typeid(void (InfoBox::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????8b018b91c8000000", argdata, 1, 5, &func);
}

__declspec(naked) void InfoBox::OnRender()
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
	__asm__("call %0\n\t" :: "m"(_func510::func));
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

namespace _func511
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("InfoBox::Clear", typeid(int (InfoBox::*)()), "578d7c240883e4f0ff77fc5589e55756538d45cc8d75d489cb83c10c", argdata, 1, 1, &func);
}

__declspec(naked) int InfoBox::Clear()
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
	__asm__("call %0\n\t" :: "m"(_func511::func));
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

namespace _func512
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetDescription", typeid(int (InfoBox::*)(Description *, int , int , InfoBox::ExpandDir )), "578d7c240883e4f0ff77fc5589e557565389cb83c10c83ec2c8b378b5708", argdata, 5, 1, &func);
}

__declspec(naked) int InfoBox::SetDescription(Description *desc, int width, int height, InfoBox::ExpandDir dir)
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
		"push [ebp+20]\n\t"		// dir
		"push [ebp+16]\n\t"		// height
		"push [ebp+12]\n\t"		// width
		"push [ebp+8]\n\t"		// desc
	);
	__asm__("call %0\n\t" :: "m"(_func512::func));
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

namespace _func513
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetText", typeid(void (InfoBox::*)(const std::string &, const std::string &, int , int , InfoBox::ExpandDir )), ".578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b47048b37c78550ffffff00000000c68554ffffff00c68564ffffff01c7856cffffff00000000", argdata, 6, 5, &func);
}

__declspec(naked) void InfoBox::SetText(const std::string &title, const std::string &text, int width, int height, InfoBox::ExpandDir dir)
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
		"push [ebp+24]\n\t"		// dir
		"push [ebp+20]\n\t"		// height
		"push [ebp+16]\n\t"		// width
		"push [ebp+12]\n\t"		// text
		"push [ebp+8]\n\t"		// title
	);
	__asm__("call %0\n\t" :: "m"(_func513::func));
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
		"ret 20\n\t"
	);
}

namespace _func514
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetBlueprintWeapon", typeid(void (InfoBox::*)(const WeaponBlueprint *, int , bool , int )), "578d7c240883e4f0ff77fc5589e557565389cb8d4d9c81ec????????8b47048b378945948b470cc744240400000000893424894588e8????????8d461c", argdata, 5, 5, &func);
}

__declspec(naked) void InfoBox::SetBlueprintWeapon(const WeaponBlueprint *bp, int status, bool hasWeaponSystem, int yShift)
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
		"push [ebp+20]\n\t"		// yShift
		"push [ebp+16]\n\t"		// hasWeaponSystem
		"push [ebp+12]\n\t"		// status
		"push [ebp+8]\n\t"		// bp
	);
	__asm__("call %0\n\t" :: "m"(_func514::func));
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

namespace _func515
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetBlueprintDrone", typeid(void (InfoBox::*)(const DroneBlueprint *, int , bool , int )), ".578d7c240883e4f0ff77fc5589f889e557565389cf83c10c81ec????????8b50048b30899558fdffff8b50088b400c89b544fdffff899548fdffff898554fdffff8d461c", argdata, 5, 5, &func);
}

__declspec(naked) void InfoBox::SetBlueprintDrone(const DroneBlueprint *bp, int status, bool hasDroneSystem, int yShift)
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
		"push [ebp+20]\n\t"		// yShift
		"push [ebp+16]\n\t"		// hasDroneSystem
		"push [ebp+12]\n\t"		// status
		"push [ebp+8]\n\t"		// bp
	);
	__asm__("call %0\n\t" :: "m"(_func515::func));
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

namespace _func516
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetBlueprint", typeid(void (InfoBox::*)(const ItemBlueprint *)), "578d7c240883e4f0ff77fc5589e557565389cb83c10c83ec1c8b378d461c890424", argdata, 2, 5, &func);
}

__declspec(naked) void InfoBox::SetBlueprint(const ItemBlueprint *bp)
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
		"push [ebp+8]\n\t"		// bp
	);
	__asm__("call %0\n\t" :: "m"(_func516::func));
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

namespace _func517
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetBlueprintCrew", typeid(void (InfoBox::*)(const CrewBlueprint *, int , bool )), ".5789ca8d7c240883e4f0ff77fc5589e55756538d720c81ec????????8b078b5f08898d78fdffffc782c000000031010000c782c4000000b6000000c7821c0100004300000089c1", argdata, 4, 5, &func);
}

__declspec(naked) void InfoBox::SetBlueprintCrew(const CrewBlueprint *bp, int yShift, bool detailedCrew)
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
		"push [ebp+16]\n\t"		// detailedCrew
		"push [ebp+12]\n\t"		// yShift
		"push [ebp+8]\n\t"		// bp
	);
	__asm__("call %0\n\t" :: "m"(_func517::func));
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

namespace _func518
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetBlueprintAugment", typeid(void (InfoBox::*)(const AugmentBlueprint *)), ".578d7c240883e4f0ff77fc5589e557565389cb83c10c83ec1c8b378d461c890424", argdata, 2, 5, &func);
}

__declspec(naked) void InfoBox::SetBlueprintAugment(const AugmentBlueprint *bp)
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
		"push [ebp+8]\n\t"		// bp
	);
	__asm__("call %0\n\t" :: "m"(_func518::func));
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

namespace _func519
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("InfoBox::CalcBoxHeight", typeid(int (InfoBox::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????83b9ac000000010f84????????8b8fd000000085c90f85????????c78500ffffff30000000807f5c00", argdata, 1, 1, &func);
}

__declspec(naked) int InfoBox::CalcBoxHeight()
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
	__asm__("call %0\n\t" :: "m"(_func519::func));
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

namespace _func520
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("InfoBox::IsEmpty", typeid(bool (InfoBox::*)()), "83b9b4000000ff74??31c0c38d742600578d7c240883e4f0ff77fc5589e557565389cb83ec4c80792400", argdata, 1, 1, &func);
}

__declspec(naked) bool InfoBox::IsEmpty()
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
	__asm__("call %0\n\t" :: "m"(_func520::func));
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

namespace _func521
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("IonDrone::GetRoomDamage", typeid(Damage *(*)(Damage *, IonDrone *)), "5589e556538b7508c701????????89cbc7410400000000c741080000000083e4f0c7410c00000000c7411000000000c7411400000000c7411800000000c7411c00000000c6412000c74124ffffffffc74128ffffffffc6412c00c6412d00c6412e01", argdata, 2, 0, &func);
}

__declspec(naked) Damage *IonDrone::GetRoomDamage(Damage *dmg, IonDrone *crew)
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
		"push [ebp+12]\n\t"		// crew
		"mov ecx, [ebp+8]\n\t"	// dmg
	);
	__asm__("call %0\n\t" :: "m"(_func521::func));
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

namespace _func522
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
	__asm__("call %0\n\t" :: "m"(_func522::func));
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

namespace _func523
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("LocationEvent::ClearEvent", typeid(void (LocationEvent::*)(bool )), "578d7c240883e4f0ff77fc5589e557565383ec4c83b910060000018b0775??", argdata, 2, 5, &func);
}

__declspec(naked) void LocationEvent::ClearEvent(bool force)
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
		"push [ebp+8]\n\t"		// force
	);
	__asm__("call %0\n\t" :: "m"(_func523::func));
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

namespace _func524
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
	__asm__("call %0\n\t" :: "m"(_func524::func));
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

namespace _func525
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MainMenu::Open", typeid(void (MainMenu::*)()), "578d7c240883e4f0ff77fc5589e557565381ec????????80b92003000000898da4fdffff0f85????????8d8510feffff89859cfdffff8d85f8fdffff", argdata, 1, 5, &func);
}

__declspec(naked) void MainMenu::Open()
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
	__asm__("call %0\n\t" :: "m"(_func525::func));
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

namespace _func526
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MainMenu::OnLoop", typeid(void (MainMenu::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????80b910340000000f85????????a1????????89f9", argdata, 1, 5, &func);
}

__declspec(naked) void MainMenu::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func526::func));
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

namespace _func527
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MainMenu::constructor", typeid(void (MainMenu::*)()), "578d412c8d7c240883e4f0ff77fc5589e557565389cb8dbb040100008db37001000083ec4cc60100", argdata, 1, 5, &func);
}

__declspec(naked) void MainMenu::constructor()
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
	__asm__("call %0\n\t" :: "m"(_func527::func));
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

namespace _func528
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MainMenu::MouseClick", typeid(void (MainMenu::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565383ec4c80b910340000008b078b57040f85????????80b9d03100000089cb", argdata, 3, 5, &func);
}

__declspec(naked) void MainMenu::MouseClick(int x, int y)
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
	__asm__("call %0\n\t" :: "m"(_func528::func));
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

namespace _func529
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MainMenu::MouseMove", typeid(void (MainMenu::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565383ec5c80b910340000008b078b77048945b40f85????????80b95c2f00000089cf0f85????????80b9d031000000", argdata, 3, 5, &func);
}

__declspec(naked) void MainMenu::MouseMove(int x, int y)
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
	__asm__("call %0\n\t" :: "m"(_func529::func));
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

namespace _func530
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("MantisAnimation::__DO_NOT_HOOK", typeid(void (*)()), "5e5f5d8d67f85fc20400908d742600e8????????89c1e9????????8d7426000f1040080f114308eb??", argdata, 0, 4, &func);
}

__declspec(naked) void MantisAnimation::__DO_NOT_HOOK()
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
	__asm__("call %0\n\t" :: "m"(_func530::func));
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

namespace _func531
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("MantisAnimation::GetShootingSound", typeid(std::string &(*)(std::string &, MantisAnimation *)), ".578d7c240883e4f0ff77fc5589e557565389cb83ec3c803d??????????0f84????????e8????????89c189c8ba????????", argdata, 2, 0, &func);
}

__declspec(naked) std::string &MantisAnimation::GetShootingSound(std::string &strRef, MantisAnimation *anim)
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
		"push [ebp+12]\n\t"		// anim
		"mov ecx, [ebp+8]\n\t"	// strRef
	);
	__asm__("call %0\n\t" :: "m"(_func531::func));
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

namespace _func532
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("MantisAnimation::__DO_NOT_HOOK2", typeid(void (*)()), "578d41088d7c240883e4f0ff77fc5589e5575389cb83ec108901", argdata, 0, 4, &func);
}

__declspec(naked) void MantisAnimation::__DO_NOT_HOOK2()
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
	__asm__("call %0\n\t" :: "m"(_func532::func));
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

namespace _func533
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("MantisAnimation::GetDeathSound", typeid(std::string &(*)(std::string &, MantisAnimation *)), ".578d41088d7c240883e4f0ff77fc5589e5575389cb83ec108901", argdata, 2, 0, &func);
}

__declspec(naked) std::string &MantisAnimation::GetDeathSound(std::string &strRef, MantisAnimation *anim)
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
		"push [ebp+12]\n\t"		// anim
		"mov ecx, [ebp+8]\n\t"	// strRef
	);
	__asm__("call %0\n\t" :: "m"(_func533::func));
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

namespace _func534
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MantisAnimation::FireShot", typeid(bool (MantisAnimation::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec208b41308b5108694938cc0000008d04408d04820308c70424????????83c120e8????????8b5308d95df48b45f4", argdata, 1, 1, &func);
}

__declspec(naked) bool MantisAnimation::FireShot()
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
	__asm__("call %0\n\t" :: "m"(_func534::func));
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

namespace _func535
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MenuScreen::OnRender", typeid(void (MenuScreen::*)()), "578d7c240883e4f0ff77fc5589e557565381ec????????80b9c0020000000f84????????", argdata, 1, 5, &func);
}

__declspec(naked) void MenuScreen::OnRender()
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
	__asm__("call %0\n\t" :: "m"(_func535::func));
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

namespace _func536
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MenuScreen::constructor", typeid(void (MenuScreen::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8db564ffffff81ec????????e8????????8d4b44c703????????c7432000000000c7432800000000c7432c00000000", argdata, 1, 5, &func);
}

__declspec(naked) void MenuScreen::constructor()
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
	__asm__("call %0\n\t" :: "m"(_func536::func));
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

namespace _func537
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("MouseControl::SetTooltip", typeid(std::string &(MouseControl::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b3f8b5f0485db", argdata, 2, 1, &func);
}

__declspec(naked) std::string &MouseControl::SetTooltip(const std::string &tooltip)
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
		"push [ebp+8]\n\t"		// tooltip
	);
	__asm__("call %0\n\t" :: "m"(_func537::func));
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

namespace _func538
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MouseControl::MeasureTooltip", typeid(Point (MouseControl::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb8d4dd883ec4c8b37", argdata, 3, 1, &func);
}

__declspec(naked) Point MouseControl::MeasureTooltip(int unk)
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
		"push [ebp+8]\n\t"		// implicit_output
	);
	__asm__("call %0\n\t" :: "m"(_func538::func));
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

namespace _func539
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("MouseControl::QueueStaticTooltip", typeid(void (MouseControl::*)(Point )), ".5589e58b45088b550c5d898164010000", argdata, 2, 5, &func);
}

__declspec(naked) void MouseControl::QueueStaticTooltip(Point pos)
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
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// pos
	);
	__asm__("call %0\n\t" :: "m"(_func539::func));
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

namespace _func540
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MouseControl::OnLoop", typeid(void (MouseControl::*)()), "5589e55389cb83e4f083ec1080b91c0100000074??f30f1005????????0f2e8318010000", argdata, 1, 5, &func);
}

__declspec(naked) void MouseControl::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func540::func));
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

namespace _func541
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MouseControl::InstantTooltip", typeid(void (MouseControl::*)()), ".c6812801000001", argdata, 1, 5, &func);
}

__declspec(naked) void MouseControl::InstantTooltip()
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
	__asm__("call %0\n\t" :: "m"(_func541::func));
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

namespace _func542
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::UpdateBreach", typeid(void (OxygenSystem::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589e5575383ec108b47048b1f8b570885c07e??", argdata, 4, 5, &func);
}

__declspec(naked) void OxygenSystem::UpdateBreach(int roomId, int hasBreach, bool unk3)
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
		"push [ebp+16]\n\t"		// unk3
		"push [ebp+12]\n\t"		// hasBreach
		"push [ebp+8]\n\t"		// roomId
	);
	__asm__("call %0\n\t" :: "m"(_func542::func));
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

namespace _func543
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::UpdateAirlock", typeid(void (OxygenSystem::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565383ec4c8b5f048b1785db7e??8b81c4010000", argdata, 3, 5, &func);
}

__declspec(naked) void OxygenSystem::UpdateAirlock(int roomId, int unk)
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
		"push [ebp+8]\n\t"		// roomId
	);
	__asm__("call %0\n\t" :: "m"(_func543::func));
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

namespace _func544
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::EmptyOxygen", typeid(void (OxygenSystem::*)(int )), ".8b81c40100008b542404c70490????????", argdata, 2, 5, &func);
}

__declspec(naked) void OxygenSystem::EmptyOxygen(int roomId)
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
		"push [ebp+8]\n\t"		// roomId
	);
	__asm__("call %0\n\t" :: "m"(_func544::func));
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

namespace _func545
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::ModifyRoomOxygen", typeid(void (OxygenSystem::*)(int , float )), "8b81c40100008b5424048d0490f30f1000f30f58442408f30f1100", argdata, 3, 5, &func);
}

__declspec(naked) void OxygenSystem::ModifyRoomOxygen(int roomId, float value)
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
		"push [ebp+12]\n\t"		// value
		"push [ebp+8]\n\t"		// roomId
	);
	__asm__("call %0\n\t" :: "m"(_func545::func));
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

namespace _func546
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::ComputeAirLoss", typeid(void (OxygenSystem::*)(int , float , bool )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec3c8b18f30f106804", argdata, 4, 5, &func);
}

__declspec(naked) void OxygenSystem::ComputeAirLoss(int roomId, float value, bool unk)
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
		"push [ebp+16]\n\t"		// unk
		"push [ebp+12]\n\t"		// value
		"push [ebp+8]\n\t"		// roomId
	);
	__asm__("call %0\n\t" :: "m"(_func546::func));
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

namespace _func547
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("OxygenSystem::GetRefillSpeed", typeid(float (OxygenSystem::*)()), "5589e55389cb83e4f083ec1083b9a8010000017e??80b9ac0100000074??b9????????e8????????d95c240c8b5dfcf30f1044240cf30f5905????????f30f1144240c", argdata, 1, 1, &func);
}

__declspec(naked) float OxygenSystem::GetRefillSpeed()
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
	__asm__("call %0\n\t" :: "m"(_func547::func));
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

namespace _func548
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::constructor", typeid(void (OxygenSystem::*)(int , int , int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b4f0c8b47048b57088b37c70424????????894c240c8944240489d989542408e8????????", argdata, 5, 5, &func);
}

__declspec(naked) void OxygenSystem::constructor(int numRooms, int roomId, int shipId, int startingPower)
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
		"push [ebp+20]\n\t"		// startingPower
		"push [ebp+16]\n\t"		// shipId
		"push [ebp+12]\n\t"		// roomId
		"push [ebp+8]\n\t"		// numRooms
	);
	__asm__("call %0\n\t" :: "m"(_func548::func));
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

namespace _func549
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("Point::RelativeDistance", typeid(int (Point::*)(Point )), "558b018b510489e52b45082b550c5d0fafc00fafd201d0", argdata, 2, 1, &func);
}

__declspec(naked) int Point::RelativeDistance(Point other)
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
		"push [ebp+12]\n\t"		// other
		"push [ebp+8]\n\t"		// other
	);
	__asm__("call %0\n\t" :: "m"(_func549::func));
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

namespace _func550
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("Point::Distance", typeid(int (Point::*)(Point )), "55660fefc089e583e4f083ec208b118b41042b55082b450c0fafd20fafc001d0f30f2ac0f30f51c80f2ec97a??f30f2cc1c9", argdata, 2, 1, &func);
}

__declspec(naked) int Point::Distance(Point other)
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
		"push [ebp+12]\n\t"		// other
		"push [ebp+8]\n\t"		// other
	);
	__asm__("call %0\n\t" :: "m"(_func550::func));
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

namespace _func551
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
	__asm__("call %0\n\t" :: "m"(_func551::func));
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

namespace _func552
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("Pointf::RelativeDistance", typeid(float (Pointf::*)(Pointf )), "5589e583ec04f30f1009f30f104104f30f5c4d08f30f5c450cf30f59c9f30f59c0f30f58c1f30f110424", argdata, 2, 1, &func);
}

__declspec(naked) float Pointf::RelativeDistance(Pointf other)
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
		"push [ebp+12]\n\t"		// other
		"push [ebp+8]\n\t"		// other
	);
	__asm__("call %0\n\t" :: "m"(_func552::func));
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

namespace _func553
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Projectile::CollisionCheck", typeid(void (Projectile::*)(Collideable *)), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b378b79348b0689f1ff5028", argdata, 2, 5, &func);
}

__declspec(naked) void Projectile::CollisionCheck(Collideable *other)
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
	__asm__("call %0\n\t" :: "m"(_func553::func));
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

namespace _func554
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Projectile::constructor", typeid(void (Projectile::*)(Pointf , int , int , Pointf )), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????8b078b57048b5f088b4f0cc7460805000000c6460c018985f0feffff8995f4feffff8b47108b5714", argdata, 5, 5, &func);
}

__declspec(naked) void Projectile::constructor(Pointf position, int ownerId, int targetId, Pointf target)
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
		"push [ebp+28]\n\t"		// target
		"push [ebp+24]\n\t"		// target
		"push [ebp+20]\n\t"		// targetId
		"push [ebp+16]\n\t"		// ownerId
		"push [ebp+12]\n\t"		// position
		"push [ebp+8]\n\t"		// position
	);
	__asm__("call %0\n\t" :: "m"(_func554::func));
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
		"ret 24\n\t"
	);
}

namespace _func555
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::constructor", typeid(void (ProjectileFactory::*)(const WeaponBlueprint *, int )), "578d7c240883e4f0ff77fc5589e557565389ce83c12081ec????????8b07c741e800000000", argdata, 3, 5, &func);
}

__declspec(naked) void ProjectileFactory::constructor(const WeaponBlueprint *bp, int shipId)
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
		"push [ebp+12]\n\t"		// shipId
		"push [ebp+8]\n\t"		// bp
	);
	__asm__("call %0\n\t" :: "m"(_func555::func));
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

namespace _func556
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::SelectChargeGoal", typeid(int (ProjectileFactory::*)()), ".5589e55389cb83e4f0803d??????????75??e8????????", argdata, 1, 1, &func);
}

__declspec(naked) int ProjectileFactory::SelectChargeGoal()
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
	__asm__("call %0\n\t" :: "m"(_func556::func));
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

namespace _func557
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::IsChargedGoal", typeid(bool (ProjectileFactory::*)()), ".8b411c8b80d801000085c07e??", argdata, 1, 1, &func);
}

__declspec(naked) bool ProjectileFactory::IsChargedGoal()
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
	__asm__("call %0\n\t" :: "m"(_func557::func));
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

namespace _func558
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SetHacked", typeid(void (ProjectileFactory::*)(int )), ".5781c1????????8d7c240883e4f0ff77fc5589e5", argdata, 2, 5, &func);
}

__declspec(naked) void ProjectileFactory::SetHacked(int hacked)
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
		"push [ebp+8]\n\t"		// hacked
	);
	__asm__("call %0\n\t" :: "m"(_func558::func));
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

namespace _func559
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SetCurrentShip", typeid(void (ProjectileFactory::*)(Targetable *)), ".8b44240439814001000074??85c074??c7811c06000000000000", argdata, 2, 5, &func);
}

__declspec(naked) void ProjectileFactory::SetCurrentShip(Targetable *ship)
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
	__asm__("call %0\n\t" :: "m"(_func559::func));
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

namespace _func560
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SetCooldownModifier", typeid(void (ProjectileFactory::*)(float )), ".f30f1041080f28c8f30f10542404f30f104118", argdata, 2, 5, &func);
}

__declspec(naked) void ProjectileFactory::SetCooldownModifier(float mod)
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
		"push [ebp+8]\n\t"		// mod
	);
	__asm__("call %0\n\t" :: "m"(_func560::func));
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

namespace _func561
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::ForceCoolup", typeid(void (ProjectileFactory::*)()), ".80b9f60000000074??8b411cf30f10410cf30f114108c7812c06000001000000", argdata, 1, 5, &func);
}

__declspec(naked) void ProjectileFactory::ForceCoolup()
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
	__asm__("call %0\n\t" :: "m"(_func561::func));
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

namespace _func562
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::RenderChargeBar", typeid(void (ProjectileFactory::*)(float )), ".5781c1????????8d7c240883e4f0ff77fc5589e5", argdata, 2, 5, &func);
}

__declspec(naked) void ProjectileFactory::RenderChargeBar(float unk)
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
	__asm__("call %0\n\t" :: "m"(_func562::func));
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

namespace _func563
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::StringToWeapon", typeid(int (*)(const std::string &)), "8d4c240483e4f0ff71fc5589e5535183ec108b19c70424????????89d9e8????????83ec0485c075??8d65f8", argdata, 1, 0, &func);
}

__declspec(naked) int ProjectileFactory::StringToWeapon(const std::string &str)
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
	__asm__("call %0\n\t" :: "m"(_func563::func));
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

namespace _func564
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
	__asm__("call %0\n\t" :: "m"(_func564::func));
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

namespace _func565
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
	__asm__("call %0\n\t" :: "m"(_func565::func));
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

namespace _func566
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::SpendMissiles", typeid(int (ProjectileFactory::*)()), "8b811406000085c00f8e????????578d7c240883e4f0ff77fc5589e55756538d7dd08d45cc8d75d889cb83ec3c89f9c745cc14000000c744240400000000", argdata, 1, 1, &func);
}

__declspec(naked) int ProjectileFactory::SpendMissiles()
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
	__asm__("call %0\n\t" :: "m"(_func566::func));
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

namespace _func567
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::OnRender", typeid(void (ProjectileFactory::*)(float , bool )), "578d7c240883e4f0ff77fc5589e557538d994801000083ec20807f0400f30f100774??8d9948010000c70424????????f30f1145f489d9", argdata, 3, 5, &func);
}

__declspec(naked) void ProjectileFactory::OnRender(float alpha, bool forceVisual)
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
		"push [ebp+12]\n\t"		// forceVisual
		"push [ebp+8]\n\t"		// alpha
	);
	__asm__("call %0\n\t" :: "m"(_func567::func));
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

namespace _func568
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::NumTargetsRequired", typeid(int (ProjectileFactory::*)()), "8b411c83b8d8010000017e??8b812c06000085c0b8????????0f4f812c060000c38b8134010000", argdata, 1, 1, &func);
}

__declspec(naked) int ProjectileFactory::NumTargetsRequired()
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
	__asm__("call %0\n\t" :: "m"(_func568::func));
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

namespace _func569
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
	__asm__("call %0\n\t" :: "m"(_func569::func));
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

namespace _func570
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::CreateImagePrimitive", typeid(GL_Primitive *(ResourceControl::*)(GL_Texture *, int , int , int , GL_Color , float , bool )), "5589e583e4f083ec408b45088b552c85c00f84????????660fefe489c185c9f30f104d20f30f106d1cf30f104518f30f2a6514", argdata, 8, 1, &func);
}

__declspec(naked) GL_Primitive *ResourceControl::CreateImagePrimitive(GL_Texture *tex, int unk1, int unk2, int unk3, GL_Color color, float alpha, bool mirror)
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
		"push [ebp+44]\n\t"		// mirror
		"push [ebp+40]\n\t"		// alpha
		"push [ebp+36]\n\t"		// color
		"push [ebp+32]\n\t"		// color
		"push [ebp+28]\n\t"		// color
		"push [ebp+24]\n\t"		// color
		"push [ebp+20]\n\t"		// unk3
		"push [ebp+16]\n\t"		// unk2
		"push [ebp+12]\n\t"		// unk1
		"push [ebp+8]\n\t"		// tex
	);
	__asm__("call %0\n\t" :: "m"(_func570::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 40\n\t"
	);
}

namespace _func571
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
	__asm__("call %0\n\t" :: "m"(_func571::func));
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

namespace _func572
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::LoadFile", typeid(char *(ResourceControl::*)(const std::string &)), "5589e557565389cf31db83e4f083ec408d442430c744240c10000000c744240800000000c744243064617461c74424342e646174894424288b4508", argdata, 2, 1, &func);
}

__declspec(naked) char *ResourceControl::LoadFile(const std::string &fileName)
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
	__asm__("call %0\n\t" :: "m"(_func572::func));
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

namespace _func573
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::GetImageId", typeid(GL_Texture *(ResourceControl::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d459081ec????????8b1f8b3d????????", argdata, 2, 1, &func);
}

__declspec(naked) GL_Texture *ResourceControl::GetImageId(const std::string &dir)
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
		"push [ebp+8]\n\t"		// dir
	);
	__asm__("call %0\n\t" :: "m"(_func573::func));
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

namespace _func574
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::RenderImage", typeid(int (ResourceControl::*)(GL_Texture *, int , int , int , GL_Color , float , bool )), "5589e583e4f083ec408b45088b552c85c00f84????????660fefd289c185c9f30f104d20f30f106d1cf30f104518", argdata, 8, 1, &func);
}

__declspec(naked) int ResourceControl::RenderImage(GL_Texture *tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror)
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
		"push [ebp+44]\n\t"		// mirror
		"push [ebp+40]\n\t"		// opacity
		"push [ebp+36]\n\t"		// color
		"push [ebp+32]\n\t"		// color
		"push [ebp+28]\n\t"		// color
		"push [ebp+24]\n\t"		// color
		"push [ebp+20]\n\t"		// rotation
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// tex
	);
	__asm__("call %0\n\t" :: "m"(_func574::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 40\n\t"
	);
}

namespace _func575
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::RenderImageString", typeid(int (ResourceControl::*)(std::string &, int , int , int , GL_Color , float , bool )), "578d7c240883e4f0ff77fc5589e557565383ec5c8b570c8b07f30f1077208b5f048b7708f30f1175d08955d48b5724", argdata, 8, 1, &func);
}

__declspec(naked) int ResourceControl::RenderImageString(std::string &tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror)
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
		"push [ebp+44]\n\t"		// mirror
		"push [ebp+40]\n\t"		// opacity
		"push [ebp+36]\n\t"		// color
		"push [ebp+32]\n\t"		// color
		"push [ebp+28]\n\t"		// color
		"push [ebp+24]\n\t"		// color
		"push [ebp+20]\n\t"		// rotation
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// tex
	);
	__asm__("call %0\n\t" :: "m"(_func575::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 40\n\t"
	);
}

namespace _func576
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::CreateImagePrimitiveString", typeid(GL_Primitive *(ResourceControl::*)(const std::string &, int , int , int , GL_Color , float , bool )), ".578d7c240883e4f0ff77fc5589e557565383ec5c8b570c8b07f30f1077208b5f048b7708f30f1175d08955d48b5724890424", argdata, 8, 1, &func);
}

__declspec(naked) GL_Primitive *ResourceControl::CreateImagePrimitiveString(const std::string &tex, int x, int y, int rotation, GL_Color color, float alpha, bool mirror)
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
		"push [ebp+44]\n\t"		// mirror
		"push [ebp+40]\n\t"		// alpha
		"push [ebp+36]\n\t"		// color
		"push [ebp+32]\n\t"		// color
		"push [ebp+28]\n\t"		// color
		"push [ebp+24]\n\t"		// color
		"push [ebp+20]\n\t"		// rotation
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// tex
	);
	__asm__("call %0\n\t" :: "m"(_func576::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 40\n\t"
	);
}

namespace _func577
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::GetFontData", typeid(freetype::font_data &(ResourceControl::*)(int , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b37", argdata, 3, 1, &func);
}

__declspec(naked) freetype::font_data &ResourceControl::GetFontData(int fontType, bool unk)
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
		"push [ebp+8]\n\t"		// fontType
	);
	__asm__("call %0\n\t" :: "m"(_func577::func));
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

namespace _func578
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("RockAnimation::constructor", typeid(void (RockAnimation::*)(const std::string &, int , Pointf , bool )), "578d7c240883e4f0ff77fc5589f889e557565381ec????????898de0feffff8b57048b0f8b58108d8520ffffff8b77088b7f0c8995e4feffff898518ffffff", argdata, 5, 5, &func);
}

__declspec(naked) void RockAnimation::constructor(const std::string &subRace, int iShipId, Pointf position, bool enemy)
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
		"push [ebp+24]\n\t"		// enemy
		"push [ebp+20]\n\t"		// position
		"push [ebp+16]\n\t"		// position
		"push [ebp+12]\n\t"		// iShipId
		"push [ebp+8]\n\t"		// subRace
	);
	__asm__("call %0\n\t" :: "m"(_func578::func));
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
		"ret 20\n\t"
	);
}

namespace _func579
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("RockAnimation::__DO_NOT_HOOK", typeid(void (*)()), "5f5d8d67f85fc20400908d742600e8????????89c1e9????????8d7426000f1040080f114308", argdata, 0, 4, &func);
}

__declspec(naked) void RockAnimation::__DO_NOT_HOOK()
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
	__asm__("call %0\n\t" :: "m"(_func579::func));
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

namespace _func580
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("RockAnimation::__DO_NOT_HOOK2", typeid(void (*)()), ".5f5d8d67f85fc20400908d742600e8????????89c1e9????????8d7426000f1040080f114308", argdata, 0, 4, &func);
}

__declspec(naked) void RockAnimation::__DO_NOT_HOOK2()
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
	__asm__("call %0\n\t" :: "m"(_func580::func));
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

namespace _func581
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("RockAnimation::GetShootingSound", typeid(std::string &(*)(std::string &, RockAnimation *)), ".578d7c240883e4f0ff77fc5589e557565389cb83ec3c803d??????????0f84????????", argdata, 2, 0, &func);
}

__declspec(naked) std::string &RockAnimation::GetShootingSound(std::string &strRef, RockAnimation *anim)
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
		"push [ebp+12]\n\t"		// anim
		"mov ecx, [ebp+8]\n\t"	// strRef
	);
	__asm__("call %0\n\t" :: "m"(_func581::func));
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

namespace _func582
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("RockAnimation::__DO_NOT_HOOK3", typeid(void (*)()), "578d41088d7c240883e4f0ff77fc5589e5575389cb83ec108901", argdata, 0, 4, &func);
}

__declspec(naked) void RockAnimation::__DO_NOT_HOOK3()
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
	__asm__("call %0\n\t" :: "m"(_func582::func));
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

namespace _func583
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("RockAnimation::__DO_NOT_HOOK4", typeid(void (*)()), ".578d41088d7c240883e4f0ff77fc5589e5575389cb83ec108901", argdata, 0, 4, &func);
}

__declspec(naked) void RockAnimation::__DO_NOT_HOOK4()
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
	__asm__("call %0\n\t" :: "m"(_func583::func));
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

namespace _func584
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("RockAnimation::GetDeathSound", typeid(std::string &(*)(std::string &, RockAnimation *)), ".578d41088d7c240883e4f0ff77fc5589e5575389cb83ec108901", argdata, 2, 0, &func);
}

__declspec(naked) std::string &RockAnimation::GetDeathSound(std::string &strRef, RockAnimation *anim)
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
		"push [ebp+12]\n\t"		// anim
		"mov ecx, [ebp+8]\n\t"	// strRef
	);
	__asm__("call %0\n\t" :: "m"(_func584::func));
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

namespace _func585
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Room::GetEmptySlots", typeid(int (Room::*)(bool )), "530fb65424088b41348b49288d1c928d1c988b43082b03c1f802c1e0052b430403430c2b0491", argdata, 2, 1, &func);
}

__declspec(naked) int Room::GetEmptySlots(bool intruder)
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
		"push [ebp+8]\n\t"		// intruder
	);
	__asm__("call %0\n\t" :: "m"(_func585::func));
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

namespace _func586
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Room::constructor", typeid(void (Room::*)(int , int , int , int , int , int )), "578d7c240883e4f0ff77fc5589e557565381ec????????8b57048b078b7714898d9cfeffffc7410400000000c701????????", argdata, 7, 5, &func);
}

__declspec(naked) void Room::constructor(int iShipId, int x, int y, int w, int h, int roomId)
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
		"push [ebp+28]\n\t"		// roomId
		"push [ebp+24]\n\t"		// h
		"push [ebp+20]\n\t"		// w
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// iShipId
	);
	__asm__("call %0\n\t" :: "m"(_func586::func));
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
		"ret 24\n\t"
	);
}

namespace _func587
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Room::OnRenderFloor", typeid(void (Room::*)(float , bool )), "5589e55383e4f083ec308b517cf30f1005????????f30f5c4178f30f100d????????891424f30f5905????????f30f2cc0660fefc08d1c0005????????f30f2ac0b8????????", argdata, 3, 5, &func);
}

__declspec(naked) void Room::OnRenderFloor(float alpha, bool experimental)
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
		"push [ebp+12]\n\t"		// experimental
		"push [ebp+8]\n\t"		// alpha
	);
	__asm__("call %0\n\t" :: "m"(_func587::func));
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

namespace _func588
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Room::OnRenderWalls", typeid(void (Room::*)(float )), "8079400074??8079240074??c20400905589e55389cb83e4f083ec108b819c000000f30f105d08f30f115c2404", argdata, 2, 5, &func);
}

__declspec(naked) void Room::OnRenderWalls(float alpha)
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
		"push [ebp+8]\n\t"		// alpha
	);
	__asm__("call %0\n\t" :: "m"(_func588::func));
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

namespace _func589
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Room::__DO_NOT_HOOK", typeid(void (*)()), "890424e8????????89742404893c2489c1c744240800000000e8????????89433883ec0c8d65f45b5e5f5d", argdata, 0, 4, &func);
}

__declspec(naked) void Room::__DO_NOT_HOOK()
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
	__asm__("call %0\n\t" :: "m"(_func589::func));
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

namespace _func590
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Room::destructor", typeid(void (Room::*)()), ".5589e557565389ce83e4f083ec20", argdata, 1, 5, &func);
}

__declspec(naked) void Room::destructor()
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
	__asm__("call %0\n\t" :: "m"(_func590::func));
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

namespace _func591
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
	__asm__("call %0\n\t" :: "m"(_func591::func));
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

namespace _func592
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::GetShipBlueprint", typeid(std::string *(*)(std::string *, ScoreKeeper *, int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b4704", argdata, 3, 0, &func);
}

__declspec(naked) std::string *ScoreKeeper::GetShipBlueprint(std::string *str, ScoreKeeper *scoreKeeper, int index)
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
		"push [ebp+16]\n\t"		// index
		"push [ebp+12]\n\t"		// scoreKeeper
		"mov ecx, [ebp+8]\n\t"	// str
	);
	__asm__("call %0\n\t" :: "m"(_func592::func));
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

namespace _func593
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ScoreKeeper::OnInit", typeid(void (ScoreKeeper::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8d75cc8d7dd481ec????????c70424????????e8????????8d45bc", argdata, 1, 5, &func);
}

__declspec(naked) void ScoreKeeper::OnInit()
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
	__asm__("call %0\n\t" :: "m"(_func593::func));
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

namespace _func594
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::Save", typeid(void (ScoreKeeper::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cbb9????????81ec????????8b37e8????????84c00f85????????8b15????????f30f1005????????", argdata, 2, 5, &func);
}

__declspec(naked) void ScoreKeeper::Save(bool newHighScore)
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
		"push [ebp+8]\n\t"		// newHighScore
	);
	__asm__("call %0\n\t" :: "m"(_func594::func));
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

namespace _func595
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::OnRender", typeid(void (ScoreKeeper::*)(bool )), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec????????80b9c40b0000008b00898528fdffff888530fdffff0f85????????0f2805????????b9????????8db5c0feffff", argdata, 2, 5, &func);
}

__declspec(naked) void ScoreKeeper::OnRender(bool lastPlaythrough)
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
		"push [ebp+8]\n\t"		// lastPlaythrough
	);
	__asm__("call %0\n\t" :: "m"(_func595::func));
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

namespace _func596
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::UnlockShip", typeid(void (ScoreKeeper::*)(int , int , bool , bool )), "5789c88d7c240883e4f0ff77fc5589e557565383ec5c8b57048b1f8955c48b570885db8b7f0c8955bc", argdata, 5, 5, &func);
}

__declspec(naked) void ScoreKeeper::UnlockShip(int shipType, int shipVariant, bool save, bool hidePopup)
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
		"push [ebp+20]\n\t"		// hidePopup
		"push [ebp+16]\n\t"		// save
		"push [ebp+12]\n\t"		// shipVariant
		"push [ebp+8]\n\t"		// shipType
	);
	__asm__("call %0\n\t" :: "m"(_func596::func));
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

namespace _func597
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::SetVictory", typeid(void (ScoreKeeper::*)(bool )), "8b44240484c088818802000074??83814802000001c20400", argdata, 2, 5, &func);
}

__declspec(naked) void ScoreKeeper::SetVictory(bool victory)
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
		"push [ebp+8]\n\t"		// victory
	);
	__asm__("call %0\n\t" :: "m"(_func597::func));
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

namespace _func598
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ScoreKeeper::constructor", typeid(void (ScoreKeeper::*)()), "5789c883c0148d7c240883e4f0ff77fc5589e557565389cf83ec5c89410c89c883c03c894db0c701????????", argdata, 1, 5, &func);
}

__declspec(naked) void ScoreKeeper::constructor()
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
	__asm__("call %0\n\t" :: "m"(_func598::func));
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

namespace _func599
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::GetShipIdType", typeid(int (ScoreKeeper::*)(const std::string &)), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 2, 1, &func);
}

__declspec(naked) int ScoreKeeper::GetShipIdType(const std::string &blueprintName)
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
		"push [ebp+8]\n\t"		// blueprintName
	);
	__asm__("call %0\n\t" :: "m"(_func599::func));
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

namespace _func600
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::LoadVersionFour", typeid(void (ScoreKeeper::*)(int , int )), "578d7c240883e4f0ff77fc5589f889e557565381ec????????8b4004898d28ffffff8b3f83f808898530ffffff898124130000", argdata, 3, 5, &func);
}

__declspec(naked) void ScoreKeeper::LoadVersionFour(int file, int version)
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
		"push [ebp+12]\n\t"		// version
		"push [ebp+8]\n\t"		// file
	);
	__asm__("call %0\n\t" :: "m"(_func600::func));
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

namespace _func601
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::WipeProfile", typeid(void (ScoreKeeper::*)(bool )), "578d7c240883e4f0ff77fc5589e557565383ec3c8b07894ddcb9????????8945d4e8????????c745e000000000c745e4000000008b4ddc8b75e4", argdata, 2, 5, &func);
}

__declspec(naked) void ScoreKeeper::WipeProfile(bool permanent)
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
		"push [ebp+8]\n\t"		// permanent
	);
	__asm__("call %0\n\t" :: "m"(_func601::func));
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

namespace _func602
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::MouseClick", typeid(void (ScoreKeeper::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c80b9c40b0000000f85????????0fb6812c06000084c0", argdata, 3, 5, &func);
}

__declspec(naked) void ScoreKeeper::MouseClick(int x, int y)
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
	__asm__("call %0\n\t" :: "m"(_func602::func));
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

namespace _func603
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::SetupTopShip", typeid(void (ScoreKeeper::*)(int )), "578d7c240883e4f0ff77fc5589e55756538d55d889cb83ec5c8b078955d08945b08b81dc0200008981e00200008b81800b0000", argdata, 2, 5, &func);
}

__declspec(naked) void ScoreKeeper::SetupTopShip(int variant)
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
		"push [ebp+8]\n\t"		// variant
	);
	__asm__("call %0\n\t" :: "m"(_func603::func));
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

namespace _func604
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ScoreKeeper::CheckTypes", typeid(void (ScoreKeeper::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8db3cc07000083ec3cc7442404010000008b81800b0000890424", argdata, 1, 5, &func);
}

__declspec(naked) void ScoreKeeper::CheckTypes()
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
	__asm__("call %0\n\t" :: "m"(_func604::func));
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

namespace _func605
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::AddTopScoreType", typeid(void (ScoreKeeper::*)(TopScore &, int )), "578d7c240883e4f0ff77fc5589e557565389ceb9????????81ec????????8b47048b1f8d7da8c7442404ffffffff", argdata, 3, 5, &func);
}

__declspec(naked) void ScoreKeeper::AddTopScoreType(TopScore &topScore, int type)
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
		"push [ebp+12]\n\t"		// type
		"push [ebp+8]\n\t"		// topScore
	);
	__asm__("call %0\n\t" :: "m"(_func605::func));
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

namespace _func606
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::AddTopScoreList", typeid(int (ScoreKeeper::*)(TopScore &, std::vector<TopScore> &)), "578d7c240883e4f0ff77fc5589e557565383ec7c8b77048b078b5e0489c28945948b0689d929c1", argdata, 3, 1, &func);
}

__declspec(naked) int ScoreKeeper::AddTopScoreList(TopScore &score, std::vector<TopScore> &topScoreList)
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
		"push [ebp+12]\n\t"		// topScoreList
		"push [ebp+8]\n\t"		// score
	);
	__asm__("call %0\n\t" :: "m"(_func606::func));
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

namespace _func607
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::RenderTopScores", typeid(void (ScoreKeeper::*)(const std::vector<TopScore> &, Point , int )), "578d7c240883e4f0ff77fc5589e557565381ec????????8b5f048b078b5708899de4faffff8b5f0c8985f8faffff899dd4faffff", argdata, 4, 5, &func);
}

__declspec(naked) void ScoreKeeper::RenderTopScores(const std::vector<TopScore> &topScoreList, Point position, int newHighScore)
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
		"push [ebp+20]\n\t"		// newHighScore
		"push [ebp+16]\n\t"		// position
		"push [ebp+12]\n\t"		// position
		"push [ebp+8]\n\t"		// topScoreList
	);
	__asm__("call %0\n\t" :: "m"(_func607::func));
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

namespace _func608
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ScoreKeeper::CycleLeft", typeid(void (ScoreKeeper::*)()), "578d7c240883e4f0ff77fc5589e557565389cebb????????83ec1c908d7426008b96800b000089f185d2", argdata, 1, 5, &func);
}

__declspec(naked) void ScoreKeeper::CycleLeft()
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
	__asm__("call %0\n\t" :: "m"(_func608::func));
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

namespace _func609
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ScoreKeeper::CycleRight", typeid(void (ScoreKeeper::*)()), "578d7c240883e4f0ff77fc5589e557565389ce31db83ec1c908db426000000008b96800b000089f183fa09", argdata, 1, 5, &func);
}

__declspec(naked) void ScoreKeeper::CycleRight()
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
	__asm__("call %0\n\t" :: "m"(_func609::func));
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

namespace _func610
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::Open", typeid(void (ScoreKeeper::*)(bool )), ".578d7c240883e4f0ff77fc5589e557565389ce83c10c", argdata, 2, 5, &func);
}

__declspec(naked) void ScoreKeeper::Open(bool fromGameOver)
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
		"push [ebp+8]\n\t"		// fromGameOver
	);
	__asm__("call %0\n\t" :: "m"(_func610::func));
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

namespace _func611
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::KeyDown", typeid(bool (ScoreKeeper::*)(SDLKey )), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c0fb681c40b00008b3784c0", argdata, 2, 1, &func);
}

__declspec(naked) bool ScoreKeeper::KeyDown(SDLKey key)
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
		"push [ebp+8]\n\t"		// key
	);
	__asm__("call %0\n\t" :: "m"(_func611::func));
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

namespace _func612
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::AddScrapCollected", typeid(void (ScoreKeeper::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cbb9????????83ec3c8b37e8????????84c0", argdata, 2, 5, &func);
}

__declspec(naked) void ScoreKeeper::AddScrapCollected(int scrap)
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
		"push [ebp+8]\n\t"		// scrap
	);
	__asm__("call %0\n\t" :: "m"(_func612::func));
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

namespace _func613
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::SaveScores", typeid(void (ScoreKeeper::*)(int , std::vector<TopScore> &)), "578d7c240883e4f0ff77fc5589f889e557565383ec7c8b40048b3f8b1889458c", argdata, 3, 5, &func);
}

__declspec(naked) void ScoreKeeper::SaveScores(int file, std::vector<TopScore> &topScores)
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
		"push [ebp+12]\n\t"		// topScores
		"push [ebp+8]\n\t"		// file
	);
	__asm__("call %0\n\t" :: "m"(_func613::func));
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

namespace _func614
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
	__asm__("call %0\n\t" :: "m"(_func614::func));
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

namespace _func615
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::GetDlcEnabled", typeid(bool (*)()), "0fb605????????84c075??c38d74260055b9????????89e583e4f0e8????????", argdata, 0, 0, &func);
}

__declspec(naked) bool Settings::GetDlcEnabled()
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
	__asm__("call %0\n\t" :: "m"(_func615::func));
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

namespace _func616
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Settings::GetHotkeyName", typeid(std::string &(*)(std::string &, const std::string &)), "8d4c240483e4f0ff71fc5589e5575653518d75cc8d7dd483ec788b01", argdata, 2, 2, &func);
}

__declspec(naked) std::string &Settings::GetHotkeyName(std::string &strRef, const std::string &name)
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
		"push [ebp+8]\n\t"		// strRef
	);
	__asm__("call %0\n\t" :: "m"(_func616::func));
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

namespace _func617
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Settings::GetHotkey", typeid(SDLKey (*)(const std::string &)), ".5589e557565383e4f0", argdata, 1, 2, &func);
}

__declspec(naked) SDLKey Settings::GetHotkey(const std::string &hotkeyName)
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
		"push [ebp+8]\n\t"		// hotkeyName
	);
	__asm__("call %0\n\t" :: "m"(_func617::func));
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

namespace _func618
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
	__asm__("call %0\n\t" :: "m"(_func618::func));
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

namespace _func619
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::GetSelectedRoomId", typeid(int (Ship::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589e557565383ec2c8b41048b57048b378b5f08", argdata, 4, 1, &func);
}

__declspec(naked) int Ship::GetSelectedRoomId(int x, int y, bool unk)
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
		"push [ebp+16]\n\t"		// unk
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func619::func));
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

namespace _func620
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Ship::LockdownRoom", typeid(void (Ship::*)(int , Pointf )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b078b570889c68985d0feffff8b47048995ccfeffff8985c8feffff8b4104890424", argdata, 3, 5, &func);
}

__declspec(naked) void Ship::LockdownRoom(int roomId, Pointf pos)
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
		"push [ebp+16]\n\t"		// pos
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// roomId
	);
	__asm__("call %0\n\t" :: "m"(_func620::func));
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

namespace _func621
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::RoomLocked", typeid(bool (Ship::*)(int )), "538b81bc0300008b89c00300008b5c240829c1c1f90469c9????????85c974??3b98ec00000074??05????????31d2eb??05????????3b9810ffffff", argdata, 2, 1, &func);
}

__declspec(naked) bool Ship::RoomLocked(int roomId)
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
		"push [ebp+8]\n\t"		// roomId
	);
	__asm__("call %0\n\t" :: "m"(_func621::func));
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

namespace _func622
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::FullRoom", typeid(bool (Ship::*)(int , bool )), "578d7c240883e4f0ff77fc5589e557565383ec1c8b59088b410c8b178b770429d8", argdata, 3, 1, &func);
}

__declspec(naked) bool Ship::FullRoom(int roomId, bool intruder)
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
		"push [ebp+12]\n\t"		// intruder
		"push [ebp+8]\n\t"		// roomId
	);
	__asm__("call %0\n\t" :: "m"(_func622::func));
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

namespace _func623
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::EmptySlots", typeid(int (Ship::*)(int )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec1c8b008b51088b0c828d1c85????????8b5134", argdata, 2, 1, &func);
}

__declspec(naked) int Ship::EmptySlots(int roomId)
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
		"push [ebp+8]\n\t"		// roomId
	);
	__asm__("call %0\n\t" :: "m"(_func623::func));
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

namespace _func624
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::GetAvailableRoomSlot", typeid(int (Ship::*)(int , bool )), "578d7c240883e4f0ff77fc5589e55783ec148b178b41088b0c900fb64704", argdata, 3, 1, &func);
}

__declspec(naked) int Ship::GetAvailableRoomSlot(int roomId, bool intruder)
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
		"push [ebp+12]\n\t"		// intruder
		"push [ebp+8]\n\t"		// roomId
	);
	__asm__("call %0\n\t" :: "m"(_func624::func));
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

namespace _func625
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Ship::OnRenderBreaches", typeid(void (Ship::*)()), "8b51208b412429d0c1f80285c074??5589e557565389ce31db83e4f0eb??66908b462483c301", argdata, 1, 5, &func);
}

__declspec(naked) void Ship::OnRenderBreaches()
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
	__asm__("call %0\n\t" :: "m"(_func625::func));
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

namespace _func626
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::OnRenderWalls", typeid(void (Ship::*)(bool , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c0fb6078b770431ff8845cc8b410c2b4108c1f80285c075??e9????????8b43088b0cb8f30f110424", argdata, 3, 5, &func);
}

__declspec(naked) void Ship::OnRenderWalls(bool forceView, bool doorControlMode)
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
		"push [ebp+12]\n\t"		// doorControlMode
		"push [ebp+8]\n\t"		// forceView
	);
	__asm__("call %0\n\t" :: "m"(_func626::func));
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

namespace _func627
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::OnInit", typeid(void (Ship::*)(ShipBlueprint &)), "57b8????????8d7c240883e4f0ff77fc5589e5575653e8????????29c48b0789cb8db5a4fffeff898544fefeffa1????????85c00f84????????8b3d????????85ff", argdata, 2, 5, &func);
}

__declspec(naked) void Ship::OnInit(ShipBlueprint &bp)
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
		"push [ebp+8]\n\t"		// bp
	);
	__asm__("call %0\n\t" :: "m"(_func627::func));
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

namespace _func628
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Ship::OnRenderSparks", typeid(void (Ship::*)()), "8b51088b410c29d0c1f80285c074??5589e5565389ce31db83e4f0908d7426008b0c9a83c301", argdata, 1, 5, &func);
}

__declspec(naked) void Ship::OnRenderSparks()
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
	__asm__("call %0\n\t" :: "m"(_func628::func));
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

namespace _func629
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::SetRoomBlackout", typeid(void (Ship::*)(int , bool )), "578d7c240883e4f0ff77fc5589e55783ec148b178b41088b0c900fb64704890424e8????????8b7dfc", argdata, 3, 5, &func);
}

__declspec(naked) void Ship::SetRoomBlackout(int roomId, bool blackout)
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
		"push [ebp+12]\n\t"		// blackout
		"push [ebp+8]\n\t"		// roomId
	);
	__asm__("call %0\n\t" :: "m"(_func629::func));
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

namespace _func630
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::OnRenderBase", typeid(void (Ship::*)(bool )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec5c8b008945d08b4104890424e8????????", argdata, 2, 5, &func);
}

__declspec(naked) void Ship::OnRenderBase(bool unk)
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
	__asm__("call %0\n\t" :: "m"(_func630::func));
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

namespace _func631
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Ship::OnRenderFloor", typeid(void (Ship::*)()), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec2c80b9b803000000", argdata, 1, 5, &func);
}

__declspec(naked) void Ship::OnRenderFloor()
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
	__asm__("call %0\n\t" :: "m"(_func631::func));
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

namespace _func632
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipAI::constructor", typeid(void (ShipAI::*)(bool )), "5589e556538b750889cbc741040000000083e4f083c108e8????????8d4b74e8????????89f0c683a900000000", argdata, 2, 5, &func);
}

__declspec(naked) void ShipAI::constructor(bool unk)
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
	__asm__("call %0\n\t" :: "m"(_func632::func));
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

namespace _func633
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipAI::SetStalemate", typeid(void (ShipAI::*)(bool )), ".8b44240484c074??80b9ec0000000075??c781f0000000000000008881ec000000", argdata, 2, 5, &func);
}

__declspec(naked) void ShipAI::SetStalemate(bool stalemate)
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
		"push [ebp+8]\n\t"		// stalemate
	);
	__asm__("call %0\n\t" :: "m"(_func633::func));
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

namespace _func634
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBlueprint::destructor", typeid(void (ShipBlueprint::*)()), "578d91f80200008d7c240883e4f0ff77fc5589e557565389cb83ec1c8b81f0020000c701????????39d074??890424", argdata, 1, 5, &func);
}

__declspec(naked) void ShipBlueprint::destructor()
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
	__asm__("call %0\n\t" :: "m"(_func634::func));
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

namespace _func635
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
	__asm__("call %0\n\t" :: "m"(_func635::func));
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

namespace _func636
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::MouseClick", typeid(void (ShipBuilder::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c80b9bc190000008b07", argdata, 3, 5, &func);
}

__declspec(naked) void ShipBuilder::MouseClick(int x, int y)
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
	__asm__("call %0\n\t" :: "m"(_func636::func));
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

namespace _func637
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::SwitchShip", typeid(void (ShipBuilder::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b178b7f0489b9001c0000", argdata, 3, 5, &func);
}

__declspec(naked) void ShipBuilder::SwitchShip(int shipType, int shipVariant)
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
		"push [ebp+12]\n\t"		// shipVariant
		"push [ebp+8]\n\t"		// shipType
	);
	__asm__("call %0\n\t" :: "m"(_func637::func));
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

namespace _func638
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::CreateEquipmentBoxes", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8bb94c0f00008b91480f000089f829d0c1f802", argdata, 1, 5, &func);
}

__declspec(naked) void ShipBuilder::CreateEquipmentBoxes()
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
	__asm__("call %0\n\t" :: "m"(_func638::func));
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

namespace _func639
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::CreateSystemBoxes", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec4c8bb9941000008b919010000089f829d0c1f802", argdata, 1, 5, &func);
}

__declspec(naked) void ShipBuilder::CreateSystemBoxes()
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
	__asm__("call %0\n\t" :: "m"(_func639::func));
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

namespace _func640
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::SetupShipAchievements", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec5c8b816c1c0000c781781c0000ffffffff8981701c0000", argdata, 1, 5, &func);
}

__declspec(naked) void ShipBuilder::SetupShipAchievements()
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
	__asm__("call %0\n\t" :: "m"(_func640::func));
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

namespace _func641
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::ClearShipAchievements", typeid(void (ShipBuilder::*)()), "8b816c1c0000c781781c0000ffffffff8981701c0000c390908db426000000005589e5575653", argdata, 1, 5, &func);
}

__declspec(naked) void ShipBuilder::ClearShipAchievements()
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
	__asm__("call %0\n\t" :: "m"(_func641::func));
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

namespace _func642
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::SwapType", typeid(int (ShipBuilder::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b098b3785c9", argdata, 2, 1, &func);
}

__declspec(naked) int ShipBuilder::SwapType(int variant)
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
		"push [ebp+8]\n\t"		// variant
	);
	__asm__("call %0\n\t" :: "m"(_func642::func));
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

namespace _func643
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::CycleShipNext", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b0985c974??", argdata, 1, 5, &func);
}

__declspec(naked) void ShipBuilder::CycleShipNext()
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
	__asm__("call %0\n\t" :: "m"(_func643::func));
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

namespace _func644
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::CycleShipPrevious", typeid(void (ShipBuilder::*)()), ".578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b0985c974??", argdata, 1, 5, &func);
}

__declspec(naked) void ShipBuilder::CycleShipPrevious()
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
	__asm__("call %0\n\t" :: "m"(_func644::func));
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

namespace _func645
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::Open", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565381ec????????898d38fbffff", argdata, 1, 5, &func);
}

__declspec(naked) void ShipBuilder::Open()
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
	__asm__("call %0\n\t" :: "m"(_func645::func));
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

namespace _func646
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::OnRender", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????80b960120000000f85????????e8????????8b831c0f00008d7dd0", argdata, 1, 5, &func);
}

__declspec(naked) void ShipBuilder::OnRender()
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
	__asm__("call %0\n\t" :: "m"(_func646::func));
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

namespace _func647
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::OnLoop", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389cbb9????????81ec????????e8????????84c0", argdata, 1, 5, &func);
}

__declspec(naked) void ShipBuilder::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func647::func));
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

namespace _func648
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::constructor", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83c10c8d7dd08d75d883ec3cc741f800000000c741fc00000000", argdata, 1, 5, &func);
}

__declspec(naked) void ShipBuilder::constructor()
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
	__asm__("call %0\n\t" :: "m"(_func648::func));
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

namespace _func649
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::MouseMove", typeid(void (ShipBuilder::*)(int , int )), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec????????8b308b4004898570feffff8d81540f000089b574feffff", argdata, 3, 5, &func);
}

__declspec(naked) void ShipBuilder::MouseMove(int x, int y)
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
	__asm__("call %0\n\t" :: "m"(_func649::func));
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

namespace _func650
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::OnKeyDown", typeid(void (ShipBuilder::*)(SDLKey )), "5789c88d7c240883e4f0ff77fc5589e557565383ec2c80b96012000000894de4", argdata, 2, 5, &func);
}

__declspec(naked) void ShipBuilder::OnKeyDown(SDLKey key)
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
	__asm__("call %0\n\t" :: "m"(_func650::func));
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

namespace _func651
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipButton::constructor", typeid(void (ShipButton::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????8b0789c389857cfdffff8b4704898580fdffffe8????????", argdata, 3, 5, &func);
}

__declspec(naked) void ShipButton::constructor(int shipType, int shipVariant)
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
		"push [ebp+12]\n\t"		// shipVariant
		"push [ebp+8]\n\t"		// shipType
	);
	__asm__("call %0\n\t" :: "m"(_func651::func));
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

namespace _func652
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("ShipButton::OnInit", typeid(void (ShipButton::*)(const std::string &, Point )), ".578d7c240883e4f0ff77fc5589e5575389cb83ec10807b70008b17", argdata, 3, 5, &func);
}

__declspec(naked) void ShipButton::OnInit(const std::string &imgName, Point pos)
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
		"push [ebp+16]\n\t"		// pos
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// imgName
	);
	__asm__("call %0\n\t" :: "m"(_func652::func));
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

namespace _func653
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipButton::MouseMove", typeid(bool (ShipButton::*)(int , int )), ".578d7c240883e4f0ff77fc5589f889e557565389cf83ec2c807970008b108b4004", argdata, 3, 1, &func);
}

__declspec(naked) bool ShipButton::MouseMove(int x, int y)
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
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func653::func));
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

namespace _func654
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipButton::OnRender", typeid(void (ShipButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec7c8079700075??807972000f84????????", argdata, 1, 5, &func);
}

__declspec(naked) void ShipButton::OnRender()
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
	__asm__("call %0\n\t" :: "m"(_func654::func));
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

namespace _func655
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipEvent::constructor", typeid(void (ShipEvent::*)(const ShipEvent &)), "578d7c240883e4f0ff77fc5589f889e557565389cf83c10483ec2c8b100fb6028b5a088955e48841fc", argdata, 1, 4, &func);
}

__declspec(naked) void ShipEvent::constructor(const ShipEvent &event)
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
		"push [ebp+8]\n\t"		// event
	);
	__asm__("call %0\n\t" :: "m"(_func655::func));
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

namespace _func656
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::CreateShip", typeid(ShipManager *(*)(const std::string &, int , ShipEvent &)), "8d4c240483e4f0ff71fc5589e55756535131db81ec????????8b01c7850cfbffff00000000c78510fbffff00000000c78514fbffff000000008985f0faffff8b4104898500fbffff8b4108", argdata, 3, 2, &func);
}

__declspec(naked) ShipManager *ShipGenerator::CreateShip(const std::string &name, int sector, ShipEvent &event)
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
		"push [ebp+16]\n\t"		// event
		"push [ebp+12]\n\t"		// sector
		"push [ebp+8]\n\t"		// name
	);
	__asm__("call %0\n\t" :: "m"(_func656::func));
	__asm__
	(
		"add esp, 12\n\t"
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

namespace _func657
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
	__asm__("call %0\n\t" :: "m"(_func657::func));
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

namespace _func658
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetSlotRenderPosition", typeid(Point (ShipGraph::*)(int , int , char )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec4c8b188b70048b40088945c08b01", argdata, 5, 1, &func);
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
	__asm__("call %0\n\t" :: "m"(_func658::func));
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

namespace _func659
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
	__asm__("call %0\n\t" :: "m"(_func659::func));
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

namespace _func660
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
	__asm__("call %0\n\t" :: "m"(_func660::func));
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

namespace _func661
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
	__asm__("call %0\n\t" :: "m"(_func661::func));
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

namespace _func662
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
	__asm__("call %0\n\t" :: "m"(_func662::func));
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

namespace _func663
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
	__asm__("call %0\n\t" :: "m"(_func663::func));
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

namespace _func664
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x2ff};
	static FunctionDefinition funcObj("ShipGraph::ConnectedGridSquaresPoint", typeid(int (ShipGraph::*)(Point , Point )), ".578d7c240883e4f0ff77fc5589e5575383ec108b5f088b078b5704", argdata, 3, 1, &func);
}

__declspec(naked) int ShipGraph::ConnectedGridSquaresPoint(Point p1, Point p2)
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
	__asm__("call %0\n\t" :: "m"(_func664::func));
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

namespace _func665
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
	__asm__("call %0\n\t" :: "m"(_func665::func));
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

namespace _func666
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
	__asm__("call %0\n\t" :: "m"(_func666::func));
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

namespace _func667
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
	__asm__("call %0\n\t" :: "m"(_func667::func));
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

namespace _func668
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
	__asm__("call %0\n\t" :: "m"(_func668::func));
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

namespace _func669
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
	__asm__("call %0\n\t" :: "m"(_func669::func));
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

namespace _func670
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
	__asm__("call %0\n\t" :: "m"(_func670::func));
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

namespace _func671
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
	__asm__("call %0\n\t" :: "m"(_func671::func));
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

namespace _func672
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
	__asm__("call %0\n\t" :: "m"(_func672::func));
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

namespace _func673
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
	__asm__("call %0\n\t" :: "m"(_func673::func));
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

namespace _func674
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipGraph::ComputeCenter", typeid(int (ShipGraph::*)()), ".578d7c240883e4f0ff77fc5589e557565383ec4c8b79048b01", argdata, 1, 1, &func);
}

__declspec(naked) int ShipGraph::ComputeCenter()
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
	__asm__("call %0\n\t" :: "m"(_func674::func));
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

namespace _func675
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ContainsPoint", typeid(bool (ShipGraph::*)(int , int )), ".538b514431c08b5c240839da7f??03514c39d37f??", argdata, 3, 1, &func);
}

__declspec(naked) bool ShipGraph::ContainsPoint(int x, int y)
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
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func675::func));
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

namespace _func676
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetSelectedRoom", typeid(int (ShipGraph::*)(int , int , bool )), ".578d7c240883e4f0ff77fc5589e557565389fb89ce83ec2c8b43040fb6530831db", argdata, 4, 1, &func);
}

__declspec(naked) int ShipGraph::GetSelectedRoom(int x, int y, bool unk)
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
		"push [ebp+16]\n\t"		// unk
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func676::func));
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

namespace _func677
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipGraph::RoomCount", typeid(int (ShipGraph::*)()), ".8b41042b01c1f802", argdata, 1, 1, &func);
}

__declspec(naked) int ShipGraph::RoomCount()
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
	__asm__("call %0\n\t" :: "m"(_func677::func));
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

namespace _func678
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetRoomShape", typeid(Globals::Rect *(ShipGraph::*)(int )), ".5789c88d7c240883e4f0ff77fc5589e557565383ec2c8b178b7f04", argdata, 2, 1, &func);
}

__declspec(naked) Globals::Rect *ShipGraph::GetRoomShape(int room)
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
	__asm__("call %0\n\t" :: "m"(_func678::func));
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

namespace _func679
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetRoomOxygen", typeid(float (ShipGraph::*)(int )), ".53660fefc083ec048b54240c85d278??8b198b410429d8c1f80239c27d??8b0493", argdata, 2, 1, &func);
}

__declspec(naked) float ShipGraph::GetRoomOxygen(int room)
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
	__asm__("call %0\n\t" :: "m"(_func679::func));
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

namespace _func680
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetRoomBlackedOut", typeid(bool (ShipGraph::*)(int )), ".5653b8????????8b5c240c85db78??8b318b510429f2c1fa02", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipGraph::GetRoomBlackedOut(int room)
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
	__asm__("call %0\n\t" :: "m"(_func680::func));
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

namespace _func681
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetClosestSlot", typeid(Slot *(*)(Slot *, ShipGraph *, Point , int , bool )), "578d7c240883e4f0ff77fc5589e557565381ec????????8b078b7704898d6cffffff8b10894588", argdata, 5, 0, &func);
}

__declspec(naked) Slot *ShipGraph::GetClosestSlot(Slot *slot, ShipGraph *graph, Point pos, int shipId, bool intruder)
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
		"push [ebp+28]\n\t"		// intruder
		"push [ebp+24]\n\t"		// shipId
		"push [ebp+20]\n\t"		// pos
		"push [ebp+16]\n\t"		// pos
		"push [ebp+12]\n\t"		// graph
		"mov ecx, [ebp+8]\n\t"	// slot
	);
	__asm__("call %0\n\t" :: "m"(_func681::func));
	__asm__
	(
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

namespace _func682
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipInfo::AddAugmentation", typeid(char (ShipInfo::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565389ce8d560483ec5c894dbc8b0f89d3894db4890c24", argdata, 2, 1, &func);
}

__declspec(naked) char ShipInfo::AddAugmentation(const std::string &augment)
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
	__asm__("call %0\n\t" :: "m"(_func682::func));
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

namespace _func683
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipInfo::HasAugmentation", typeid(bool (ShipInfo::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565389ce8d560483ec4c894dc88b0f89d3894dc4890c2489cf", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipInfo::HasAugmentation(const std::string &augment)
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
	__asm__("call %0\n\t" :: "m"(_func683::func));
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

namespace _func684
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipInfo::GetAugmentationValue", typeid(float (ShipInfo::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d55a881ec????????8b07894d8c8955a08b308b580489458089f001d874??", argdata, 2, 1, &func);
}

__declspec(naked) float ShipInfo::GetAugmentationValue(const std::string &augment)
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
	__asm__("call %0\n\t" :: "m"(_func684::func));
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

namespace _func685
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
	__asm__("call %0\n\t" :: "m"(_func685::func));
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

namespace _func686
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
	__asm__("call %0\n\t" :: "m"(_func686::func));
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

namespace _func687
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
	__asm__("call %0\n\t" :: "m"(_func687::func));
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

namespace _func688
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::OnRender", typeid(void (ShipManager::*)(char , char )), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec????????803d??????????8b188b4004889d44ffffff898530ffffff0f84????????", argdata, 3, 5, &func);
}

__declspec(naked) void ShipManager::OnRender(char showInterior, char doorControlMode)
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
		"push [ebp+12]\n\t"		// doorControlMode
		"push [ebp+8]\n\t"		// showInterior
	);
	__asm__("call %0\n\t" :: "m"(_func688::func));
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

namespace _func689
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CountCrew", typeid(int (ShipManager::*)(char )), "5589e557565383e4f083ec100fb645088b51648844240f8b416829d0c1f80285c00f84????????", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::CountCrew(char boarders)
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
	__asm__("call %0\n\t" :: "m"(_func689::func));
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

namespace _func690
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::TeleportCrew", typeid(std::vector<CrewMember*> *(*)(std::vector<CrewMember*> *, ShipManager *, int , bool )), "578d7c240883e4f0ff77fc5589f889e557565383ec3c8b3f8b70040fb64008", argdata, 4, 0, &func);
}

__declspec(naked) std::vector<CrewMember*> *ShipManager::TeleportCrew(std::vector<CrewMember*> *crewList, ShipManager *ship, int roomId, bool intruders)
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
		"push [ebp+20]\n\t"		// intruders
		"push [ebp+16]\n\t"		// roomId
		"push [ebp+12]\n\t"		// ship
		"mov ecx, [ebp+8]\n\t"	// crewList
	);
	__asm__("call %0\n\t" :: "m"(_func690::func));
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

namespace _func691
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::OnInit", typeid(int (ShipManager::*)(ShipBlueprint *, int )), "578d7c240883e4f0ff77fc5589fa89e55756538d99e0040000", argdata, 3, 1, &func);
}

__declspec(naked) int ShipManager::OnInit(ShipBlueprint *bp, int shipLevel)
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
		"push [ebp+12]\n\t"		// shipLevel
		"push [ebp+8]\n\t"		// bp
	);
	__asm__("call %0\n\t" :: "m"(_func691::func));
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

namespace _func692
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::HasSystem", typeid(char (ShipManager::*)(int )), "8b44240483f81174??8b91c8040000833c82ff0f95c0c204008db42600000000b8????????", argdata, 2, 1, &func);
}

__declspec(naked) char ShipManager::HasSystem(int systemId)
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
		"push [ebp+8]\n\t"		// systemId
	);
	__asm__("call %0\n\t" :: "m"(_func692::func));
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

namespace _func693
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemInRoom", typeid(ShipSystem *(ShipManager::*)(int )), "8b51188b411c29d0c1f80285c074??5589e557565389ce31db83e4f0eb??66908b41383b450874??8b461c83c301", argdata, 2, 1, &func);
}

__declspec(naked) ShipSystem *ShipManager::GetSystemInRoom(int roomId)
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
		"push [ebp+8]\n\t"		// roomId
	);
	__asm__("call %0\n\t" :: "m"(_func693::func));
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

namespace _func694
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::OnLoop", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565389ce8d8d1cffffff81ec????????", argdata, 1, 5, &func);
}

__declspec(naked) void ShipManager::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func694::func));
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

namespace _func695
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SetSystemPowerLoss", typeid(void (ShipManager::*)(int , int )), "578d7c240883e4f0ff77fc5589e55783ec148b078b7f0483f81174??83f8ff74??8b91c8040000", argdata, 3, 5, &func);
}

__declspec(naked) void ShipManager::SetSystemPowerLoss(int systemId, int powerLoss)
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
		"push [ebp+12]\n\t"		// powerLoss
		"push [ebp+8]\n\t"		// systemId
	);
	__asm__("call %0\n\t" :: "m"(_func695::func));
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

namespace _func696
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::CreateSystems", typeid(int (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b810807000085c0", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::CreateSystems()
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
	__asm__("call %0\n\t" :: "m"(_func696::func));
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

namespace _func697
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddSystem", typeid(int (ShipManager::*)(int )), "8b810807000085c00f84????????578d7c240883e4f0ff77fc5589e557568db104070000", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::AddSystem(int systemId)
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
		"push [ebp+8]\n\t"		// systemId
	);
	__asm__("call %0\n\t" :: "m"(_func697::func));
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

namespace _func698
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::UpdateCrewMembers", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565331db89cf81ec????????8b5118", argdata, 1, 5, &func);
}

__declspec(naked) void ShipManager::UpdateCrewMembers()
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
	__asm__("call %0\n\t" :: "m"(_func698::func));
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

namespace _func699
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::UpdateEnvironment", typeid(void (ShipManager::*)()), "578d41708d7c240883e4f0ff77fc5589e557565389cf89c1", argdata, 1, 5, &func);
}

__declspec(naked) void ShipManager::UpdateEnvironment()
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
	__asm__("call %0\n\t" :: "m"(_func699::func));
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

namespace _func700
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddCrewMemberFromBlueprint", typeid(CrewMember *(ShipManager::*)(CrewBlueprint *, int , bool , int , bool )), "578d7c240883e4f0ff77fc5589e557565389ce8d4d9c81ec????????8b0789c389458c8b47048945908b4708", argdata, 6, 1, &func);
}

__declspec(naked) CrewMember *ShipManager::AddCrewMemberFromBlueprint(CrewBlueprint *bp, int slot, bool init, int roomId, bool intruder)
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
		"push [ebp+24]\n\t"		// intruder
		"push [ebp+20]\n\t"		// roomId
		"push [ebp+16]\n\t"		// init
		"push [ebp+12]\n\t"		// slot
		"push [ebp+8]\n\t"		// bp
	);
	__asm__("call %0\n\t" :: "m"(_func700::func));
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

namespace _func701
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddCrewMemberFromString", typeid(CrewMember *(ShipManager::*)(const std::string &, const std::string &, char , int , char , char )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b078b770c8b490489855cfdffff89b570fdffff8b47048b771085c9898568fdffff89b558fdffff", argdata, 7, 1, &func);
}

__declspec(naked) CrewMember *ShipManager::AddCrewMemberFromString(const std::string &name, const std::string &race, char intruder, int roomId, char init, char male)
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
		"push [ebp+28]\n\t"		// male
		"push [ebp+24]\n\t"		// init
		"push [ebp+20]\n\t"		// roomId
		"push [ebp+16]\n\t"		// intruder
		"push [ebp+12]\n\t"		// race
		"push [ebp+8]\n\t"		// name
	);
	__asm__("call %0\n\t" :: "m"(_func701::func));
	__asm__
	(
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

namespace _func702
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetOxygenPercentage", typeid(int (ShipManager::*)()), "8b81c8040000837808ff74??55660fefc989e583e4f083ec208b4124f30f1005????????f30f5980d0010000f30f5ac8f20f110c24e8????????dd5c2418f20f2c442418", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::GetOxygenPercentage()
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
	__asm__("call %0\n\t" :: "m"(_func702::func));
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

namespace _func703
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::DamageCrew", typeid(char (ShipManager::*)(CrewMember *, int , int , int , int , int , int , int , int , char , int , int , int , int )), "578d7c240883e4f0ff77fc5589f889e557565383ec2c807832008b1f8b7f2875??3b7b04", argdata, 15, 1, &func);
}

__declspec(naked) char ShipManager::DamageCrew(CrewMember *crew, int iDamage, int iShieldPiercing, int fireChance, int breachChance, int stunChance, int iIonDamage, int iSystemDamage, int iPersDamage, char bHullBuster, int ownerId, int selfId, int bLockdown, int iStun)
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
		"push [ebp+60]\n\t"		// iStun
		"push [ebp+56]\n\t"		// bLockdown
		"push [ebp+52]\n\t"		// selfId
		"push [ebp+48]\n\t"		// ownerId
		"push [ebp+44]\n\t"		// bHullBuster
		"push [ebp+40]\n\t"		// iPersDamage
		"push [ebp+36]\n\t"		// iSystemDamage
		"push [ebp+32]\n\t"		// iIonDamage
		"push [ebp+28]\n\t"		// stunChance
		"push [ebp+24]\n\t"		// breachChance
		"push [ebp+20]\n\t"		// fireChance
		"push [ebp+16]\n\t"		// iShieldPiercing
		"push [ebp+12]\n\t"		// iDamage
		"push [ebp+8]\n\t"		// crew
	);
	__asm__("call %0\n\t" :: "m"(_func703::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 56\n\t"
	);
}

namespace _func704
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::RemoveItem", typeid(void (ShipManager::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d45d889cb83ec5c8b378945d0894dac", argdata, 2, 5, &func);
}

__declspec(naked) void ShipManager::RemoveItem(const std::string &name)
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
		"push [ebp+8]\n\t"		// name
	);
	__asm__("call %0\n\t" :: "m"(_func704::func));
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

namespace _func705
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::DamageArea", typeid(char (ShipManager::*)(Pointf , int , int , int , int , int , int , int , int , char , int , int , int , int , char )), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????8b47088b5f3cf30f105704f30f100f8945908b4710f30f118d78fffffff30f119574ffffff", argdata, 16, 1, &func);
}

__declspec(naked) char ShipManager::DamageArea(Pointf location, int iDamage, int iShieldPiercing, int fireChance, int breachChance, int stunChance, int iIonDamage, int iSystemDamage, int iPersDamage, char bHullBuster, int ownerId, int selfId, int bLockdown, int iStun, char forceHit)
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
		"push [ebp+68]\n\t"		// forceHit
		"push [ebp+64]\n\t"		// iStun
		"push [ebp+60]\n\t"		// bLockdown
		"push [ebp+56]\n\t"		// selfId
		"push [ebp+52]\n\t"		// ownerId
		"push [ebp+48]\n\t"		// bHullBuster
		"push [ebp+44]\n\t"		// iPersDamage
		"push [ebp+40]\n\t"		// iSystemDamage
		"push [ebp+36]\n\t"		// iIonDamage
		"push [ebp+32]\n\t"		// stunChance
		"push [ebp+28]\n\t"		// breachChance
		"push [ebp+24]\n\t"		// fireChance
		"push [ebp+20]\n\t"		// iShieldPiercing
		"push [ebp+16]\n\t"		// iDamage
		"push [ebp+12]\n\t"		// location
		"push [ebp+8]\n\t"		// location
	);
	__asm__("call %0\n\t" :: "m"(_func705::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret 64\n\t"
	);
}

namespace _func706
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SelectRandomCrew", typeid(CrewBlueprint *(*)(CrewBlueprint &, ShipManager *, int , const std::string &)), "578d7c240883e4f0ff77fc5589e557565383ec5c8b47048b7708894da883f8ff", argdata, 4, 0, &func);
}

__declspec(naked) CrewBlueprint *ShipManager::SelectRandomCrew(CrewBlueprint &bp, ShipManager *ship, int seed, const std::string &unk)
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
		"push [ebp+16]\n\t"		// seed
		"push [ebp+12]\n\t"		// ship
		"mov ecx, [ebp+8]\n\t"	// bp
	);
	__asm__("call %0\n\t" :: "m"(_func706::func));
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

namespace _func707
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::ClearStatusAll", typeid(void (ShipManager::*)()), "5589e5565331db89ce83e4f083ec108b51188b411c29d0c1f80285c074??66908b0c9a", argdata, 1, 5, &func);
}

__declspec(naked) void ShipManager::ClearStatusAll()
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
	__asm__("call %0\n\t" :: "m"(_func707::func));
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

namespace _func708
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::PrepareSuperDrones", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec7c8b816c0800003b81700800000f84????????8b0d????????ba????????83f90274??83f901", argdata, 1, 5, &func);
}

__declspec(naked) void ShipManager::PrepareSuperDrones()
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
	__asm__("call %0\n\t" :: "m"(_func708::func));
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

namespace _func709
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::JumpLeave", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec3c83a994040000018b51188b8194040000c681d80400000185c0", argdata, 1, 5, &func);
}

__declspec(naked) void ShipManager::JumpLeave()
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
	__asm__("call %0\n\t" :: "m"(_func709::func));
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

namespace _func710
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ModifyScrapCount", typeid(void (ShipManager::*)(int , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b378b470485f6", argdata, 3, 5, &func);
}

__declspec(naked) void ShipManager::ModifyScrapCount(int scrap, bool income)
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
		"push [ebp+12]\n\t"		// income
		"push [ebp+8]\n\t"		// scrap
	);
	__asm__("call %0\n\t" :: "m"(_func710::func));
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

namespace _func711
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::DoSensorsProvide", typeid(bool (ShipManager::*)(int )), "578d7c240883e4f0ff77fc5589e557565383ec1c8b81c80400008b3f8b701c83feff74??", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipManager::DoSensorsProvide(int vision)
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
		"push [ebp+8]\n\t"		// vision
	);
	__asm__("call %0\n\t" :: "m"(_func711::func));
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

namespace _func712
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::IsCrewFull", typeid(bool (ShipManager::*)()), "5731c08d7c240883e4f0ff77fc5589e5575389cb83ec108b5104b9????????85d20f95c0890424e8????????83ec04837b0401b9????????19d2", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::IsCrewFull()
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
	__asm__("call %0\n\t" :: "m"(_func712::func));
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

namespace _func713
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::IsCrewOverFull", typeid(bool (ShipManager::*)()), "5731c08d7c240883e4f0ff77fc5589e5575389cb83ec108b5104b9????????85d20f95c0890424e8????????83ec04837b040119d283e2fe", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::IsCrewOverFull()
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
	__asm__("call %0\n\t" :: "m"(_func713::func));
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

namespace _func714
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CreateCrewDrone", typeid(CrewDrone *(ShipManager::*)(const DroneBlueprint *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b178b82b800000083f8020f84????????83f8030f85????????89542404", argdata, 2, 1, &func);
}

__declspec(naked) CrewDrone *ShipManager::CreateCrewDrone(const DroneBlueprint *bp)
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
		"push [ebp+8]\n\t"		// bp
	);
	__asm__("call %0\n\t" :: "m"(_func714::func));
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

namespace _func715
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CreateSpaceDrone", typeid(SpaceDrone *(ShipManager::*)(const DroneBlueprint *)), "578d7c240883e4f0ff77fc5589e557565383ec3c8b3fc745dc0000000083bfb8000000070f87????????8b87b800000089cbff2485????????8db42600000000e8????????c70424????????8945d4", argdata, 2, 1, &func);
}

__declspec(naked) SpaceDrone *ShipManager::CreateSpaceDrone(const DroneBlueprint *bp)
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
		"push [ebp+8]\n\t"		// bp
	);
	__asm__("call %0\n\t" :: "m"(_func715::func));
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

namespace _func716
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CommandCrewMoveRoom", typeid(bool (ShipManager::*)(CrewMember *, int )), "578d7c240883e4f0ff77fc5589e55783ec148b47048b0fc744240800000000c7442404ffffffff890424", argdata, 3, 1, &func);
}

__declspec(naked) bool ShipManager::CommandCrewMoveRoom(CrewMember *crew, int roomId)
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
		"push [ebp+12]\n\t"		// roomId
		"push [ebp+8]\n\t"		// crew
	);
	__asm__("call %0\n\t" :: "m"(_func716::func));
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

namespace _func717
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemRoom", typeid(int (ShipManager::*)(int )), "55b8????????89e5538b550883e4f083faff74??8b99c80400008b149383faff74??8b49188b0c9185c9", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::GetSystemRoom(int sysId)
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
		"push [ebp+8]\n\t"		// sysId
	);
	__asm__("call %0\n\t" :: "m"(_func717::func));
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

namespace _func718
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetWeaponList", typeid(std::vector<ProjectileFactory*> &(*)(std::vector<ProjectileFactory*> &, ShipManager *)), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b078b90c8040000837a0cff75??c701????????c741040000000089d8c7410800000000", argdata, 2, 0, &func);
}

__declspec(naked) std::vector<ProjectileFactory*> &ShipManager::GetWeaponList(std::vector<ProjectileFactory*> &wepList, ShipManager *ship)
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
		"push [ebp+12]\n\t"		// ship
		"mov ecx, [ebp+8]\n\t"	// wepList
	);
	__asm__("call %0\n\t" :: "m"(_func718::func));
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

namespace _func719
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddDrone", typeid(Drone *(ShipManager::*)(const DroneBlueprint *, int )), "578d7c240883e4f0ff77fc5589e557565383ec1c8b81c80400008b1f8b7704837810ff", argdata, 3, 1, &func);
}

__declspec(naked) Drone *ShipManager::AddDrone(const DroneBlueprint *bp, int slot)
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
		"push [ebp+12]\n\t"		// slot
		"push [ebp+8]\n\t"		// bp
	);
	__asm__("call %0\n\t" :: "m"(_func719::func));
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

namespace _func720
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::Restart", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565389cf83ec4c8b410485c075??c641100189f9e8????????8b8fc00400008b97bc04000089c8", argdata, 1, 5, &func);
}

__declspec(naked) void ShipManager::Restart()
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
	__asm__("call %0\n\t" :: "m"(_func720::func));
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

namespace _func721
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemPower", typeid(int (ShipManager::*)(int )), "558b81c804000089e583e4f08b55088b049083f8ff74??8b51188b0c82e8????????", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::GetSystemPower(int systemId)
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
		"push [ebp+8]\n\t"		// systemId
	);
	__asm__("call %0\n\t" :: "m"(_func721::func));
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

namespace _func722
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CountCrewShipId", typeid(int (ShipManager::*)(int , int )), "5589e557565383e4f083ec108b41688b51648944240c29d0c1f80285c074??894c240431db31ffeb??8db4260000000001c78b44240c", argdata, 3, 1, &func);
}

__declspec(naked) int ShipManager::CountCrewShipId(int roomId, int shipId)
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
		"push [ebp+8]\n\t"		// roomId
	);
	__asm__("call %0\n\t" :: "m"(_func722::func));
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

namespace _func723
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystem", typeid(ShipSystem *(ShipManager::*)(int )), "8b44240483f8ff74??8b91c80400008b048283f8ff74??8b51188b0482", argdata, 2, 1, &func);
}

__declspec(naked) ShipSystem *ShipManager::GetSystem(int systemId)
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
		"push [ebp+8]\n\t"		// systemId
	);
	__asm__("call %0\n\t" :: "m"(_func723::func));
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

namespace _func724
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ExportShip", typeid(void (ShipManager::*)(int )), "5789c805????????8d7c240883e4f0ff77fc5589e557565381ec????????8b3789cf89442404898d90feffff893424e8????????80bf68060000008d85c0feffff89c1898594feffff", argdata, 2, 5, &func);
}

__declspec(naked) void ShipManager::ExportShip(int file)
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
	__asm__("call %0\n\t" :: "m"(_func724::func));
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

namespace _func725
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::destructor", typeid(void (ShipManager::*)()), ".578d7c240883e4f0ff77fc5589e557565389ce", argdata, 1, 5, &func);
}

__declspec(naked) void ShipManager::destructor()
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
	__asm__("call %0\n\t" :: "m"(_func725::func));
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

namespace _func726
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::destructor2", typeid(void (ShipManager::*)()), ".5589e55389cb83e4f083ec10e8????????891c24e8????????8b5dfc", argdata, 1, 5, &func);
}

__declspec(naked) void ShipManager::destructor2()
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
	__asm__("call %0\n\t" :: "m"(_func726::func));
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

namespace _func727
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ImportShip", typeid(void (ShipManager::*)(int )), "578d7c240883e4f0ff77fc5589e55756538d85dcfcffff89ce8d9de4fcffff81ec????????8b3f898d4cfbffff890424897c2404e8????????", argdata, 2, 5, &func);
}

__declspec(naked) void ShipManager::ImportShip(int file)
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
	__asm__("call %0\n\t" :: "m"(_func727::func));
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

namespace _func728
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::CheckVision", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b81c8040000c645b7008b701c83feff74??", argdata, 1, 5, &func);
}

__declspec(naked) void ShipManager::CheckVision()
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
	__asm__("call %0\n\t" :: "m"(_func728::func));
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

namespace _func729
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::IsSystemHacked", typeid(bool (ShipManager::*)(int )), "5383ec048b54240c83fa1174??8b99c804000031c0833c93ff75??83c4045bc20400891424e8????????83ec04", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipManager::IsSystemHacked(int systemId)
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
		"push [ebp+8]\n\t"		// systemId
	);
	__asm__("call %0\n\t" :: "m"(_func729::func));
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

namespace _func730
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSelectedCrewPoint", typeid(CrewMember *(ShipManager::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589e557565383ec4c8b078b51648945d48b47048945d00fb64708", argdata, 4, 1, &func);
}

__declspec(naked) CrewMember *ShipManager::GetSelectedCrewPoint(int x, int y, bool intruder)
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
		"push [ebp+16]\n\t"		// intruder
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func730::func));
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

namespace _func731
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::RenderWeapons", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e5578db994000000565389ce89f983ec5ce8????????8945c08b86c8040000", argdata, 1, 5, &func);
}

__declspec(naked) void ShipManager::RenderWeapons()
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
	__asm__("call %0\n\t" :: "m"(_func731::func));
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

namespace _func732
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::DamageSystem", typeid(void (ShipManager::*)(int , int , int , int , int , int , int , int , int , char , int , int , int , int )), "578d7c240883e4f0ff77fc5589f889e557565383ec6c8b308b58048b4018897db089cf8975c485c0", argdata, 15, 5, &func);
}

__declspec(naked) void ShipManager::DamageSystem(int roomId, int iDamage, int iShieldPiercing, int fireChance, int breachChance, int stunChance, int iIonDamage, int iSystemDamage, int iPersDamage, char bHullBuster, int ownerId, int selfId, int bLockdown, int iStun)
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
		"push [ebp+60]\n\t"		// iStun
		"push [ebp+56]\n\t"		// bLockdown
		"push [ebp+52]\n\t"		// selfId
		"push [ebp+48]\n\t"		// ownerId
		"push [ebp+44]\n\t"		// bHullBuster
		"push [ebp+40]\n\t"		// iPersDamage
		"push [ebp+36]\n\t"		// iSystemDamage
		"push [ebp+32]\n\t"		// iIonDamage
		"push [ebp+28]\n\t"		// stunChance
		"push [ebp+24]\n\t"		// breachChance
		"push [ebp+20]\n\t"		// fireChance
		"push [ebp+16]\n\t"		// iShieldPiercing
		"push [ebp+12]\n\t"		// iDamage
		"push [ebp+8]\n\t"		// roomId
	);
	__asm__("call %0\n\t" :: "m"(_func732::func));
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
		"ret 56\n\t"
	);
}

namespace _func733
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ClearStatusSystem", typeid(void (ShipManager::*)(int )), "5589e583e4f083ec108b450883f81174??83f8ff74??8b91c80400008b048283f8ff74??8b51188b0c8285c974??e8????????c9", argdata, 2, 5, &func);
}

__declspec(naked) void ShipManager::ClearStatusSystem(int system)
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
		"push [ebp+8]\n\t"		// system
	);
	__asm__("call %0\n\t" :: "m"(_func733::func));
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

namespace _func734
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::ResetScrapLevel", typeid(void (ShipManager::*)()), "a1????????c781d40400001e00000083f80174??83f80274??f3c3908d742600c781d404000000000000c3908d742600c781d40400000a000000", argdata, 1, 5, &func);
}

__declspec(naked) void ShipManager::ResetScrapLevel()
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
	__asm__("call %0\n\t" :: "m"(_func734::func));
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

namespace _func735
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::HasAugmentation", typeid(int (ShipObject::*)(const std::string &)), "5789ca8d7c240883e4f0ff77fc5589e55756538d4dd883ec5c8b07894dd08b308b580489f0", argdata, 2, 1, &func);
}

__declspec(naked) int ShipObject::HasAugmentation(const std::string &augment)
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
	__asm__("call %0\n\t" :: "m"(_func735::func));
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

namespace _func736
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::GetAugmentationValue", typeid(float (ShipObject::*)(const std::string &)), "5789ca8d7c240883e4f0ff77fc5589e55756538d4d9081ec????????8b07894d888b308b5804", argdata, 2, 1, &func);
}

__declspec(naked) float ShipObject::GetAugmentationValue(const std::string &augment)
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
	__asm__("call %0\n\t" :: "m"(_func736::func));
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

namespace _func737
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::RemoveAugmentation", typeid(void (ShipObject::*)(const std::string &)), ".5789ca8d7c240883e4f0ff77fc5589e55756538d4d9081ec????????8b07894d888b308b580489f001d874??85f675??c70424????????e8????????8d74260083fb0f895dd00f87????????", argdata, 2, 5, &func);
}

__declspec(naked) void ShipObject::RemoveAugmentation(const std::string &augment)
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
		"push [ebp+8]\n\t"		// augment
	);
	__asm__("call %0\n\t" :: "m"(_func737::func));
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

namespace _func738
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::HasEquipment", typeid(int (ShipObject::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d75a881ec????????8b3f898d70ffffff8975a0", argdata, 2, 1, &func);
}

__declspec(naked) int ShipObject::HasEquipment(const std::string &equip)
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
		"push [ebp+8]\n\t"		// equip
	);
	__asm__("call %0\n\t" :: "m"(_func738::func));
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

namespace _func739
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::GetAugmentationList", typeid(std::map<std::string, int> &(*)(std::vector<std::string> &, ShipObject *)), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec4c8b008b400485c0", argdata, 2, 0, &func);
}

__declspec(naked) std::map<std::string, int> &ShipObject::GetAugmentationList(std::vector<std::string> &vec, ShipObject *shipObj)
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
		"push [ebp+12]\n\t"		// shipObj
		"mov ecx, [ebp+8]\n\t"	// vec
	);
	__asm__("call %0\n\t" :: "m"(_func739::func));
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

namespace _func740
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::AddAugmentation", typeid(void (ShipObject::*)(const std::string &)), "5789ca8d7c240883e4f0ff77fc5589e55756538d75d883ec4c8b078975d0", argdata, 2, 5, &func);
}

__declspec(naked) void ShipObject::AddAugmentation(const std::string &augment)
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
		"push [ebp+8]\n\t"		// augment
	);
	__asm__("call %0\n\t" :: "m"(_func740::func));
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

namespace _func741
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("ShipObject::__DO_NOT_HOOK", typeid(void (*)()), "89b5a4feffffe9????????c70424????????e8????????89c60fb68590feffff89f1894424088b8594feffff894424048b858cfeffff890424", argdata, 0, 4, &func);
}

__declspec(naked) void ShipObject::__DO_NOT_HOOK()
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
	__asm__("call %0\n\t" :: "m"(_func741::func));
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

namespace _func742
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipObject::GetAugmentationCount", typeid(int (ShipObject::*)()), ".8b510431c085d20f94c06bc0340305????????8b4030", argdata, 1, 1, &func);
}

__declspec(naked) int ShipObject::GetAugmentationCount()
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
	__asm__("call %0\n\t" :: "m"(_func742::func));
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

namespace _func743
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSelect::SelectShip", typeid(void (ShipSelect::*)(int )), "578d7c240883e4f0ff77fc5589e55756538d9d48f9ffff81ec????????8b07", argdata, 2, 5, &func);
}

__declspec(naked) void ShipSelect::SelectShip(int shipType)
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
		"push [ebp+8]\n\t"		// shipType
	);
	__asm__("call %0\n\t" :: "m"(_func743::func));
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

namespace _func744
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSelect::constructor", typeid(void (ShipSelect::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec10c74424046e000000c70424????????e8????????8d4b08", argdata, 1, 5, &func);
}

__declspec(naked) void ShipSelect::constructor()
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
	__asm__("call %0\n\t" :: "m"(_func744::func));
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

namespace _func745
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSelect::ClearShipButtons", typeid(int (ShipSelect::*)()), ".5589e55756538b792089ce8b511c83e4f089f829d083f8037e??31db", argdata, 1, 1, &func);
}

__declspec(naked) int ShipSelect::ClearShipButtons()
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
	__asm__("call %0\n\t" :: "m"(_func745::func));
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

namespace _func746
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSelect::MouseMove", typeid(void (ShipSelect::*)(int , int )), ".578d7c240883e4f0ff77fc5589e557565381ec????????8b1780b94805000000", argdata, 3, 5, &func);
}

__declspec(naked) void ShipSelect::MouseMove(int x, int y)
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
	__asm__("call %0\n\t" :: "m"(_func746::func));
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

namespace _func747
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSelect::OnLoop", typeid(void (ShipSelect::*)()), ".80b9480500000075??f3c3908d742600578d7c240883e4f0ff77fc5589e557568db144050000", argdata, 1, 5, &func);
}

__declspec(naked) void ShipSelect::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func747::func));
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

namespace _func748
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSelect::KeyDown", typeid(int (ShipSelect::*)(SDLKey )), ".5781c1????????8d7c240883e4f0ff77fc5589e55783ec148b07", argdata, 2, 1, &func);
}

__declspec(naked) int ShipSelect::KeyDown(SDLKey key)
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
		"push [ebp+8]\n\t"		// key
	);
	__asm__("call %0\n\t" :: "m"(_func748::func));
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

namespace _func749
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSelect::MouseClick", typeid(void (ShipSelect::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb83ec1080b948050000000f85????????80b9bc01000000", argdata, 1, 5, &func);
}

__declspec(naked) void ShipSelect::MouseClick()
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
	__asm__("call %0\n\t" :: "m"(_func749::func));
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

namespace _func750
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSelect::PreSelectShip", typeid(void (ShipSelect::*)(int )), ".578d7c240883e4f0ff77fc5589e5575389cb83ec108b0785c078??83b9780100000274??89d9890424e8????????83ec048d65f8", argdata, 2, 5, &func);
}

__declspec(naked) void ShipSelect::PreSelectShip(int shipType)
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
		"push [ebp+8]\n\t"		// shipType
	);
	__asm__("call %0\n\t" :: "m"(_func750::func));
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

namespace _func751
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSelect::Close", typeid(void (ShipSelect::*)()), ".5581c1????????c681f0faffff0089e583e4f0", argdata, 1, 5, &func);
}

__declspec(naked) void ShipSelect::Close()
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
	__asm__("call %0\n\t" :: "m"(_func751::func));
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

namespace _func752
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSelect::GetSelectedShip", typeid(int (ShipSelect::*)()), ".8b4138", argdata, 1, 1, &func);
}

__declspec(naked) int ShipSelect::GetSelectedShip()
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
	__asm__("call %0\n\t" :: "m"(_func752::func));
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

namespace _func753
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSelect::Open", typeid(void (ShipSelect::*)(int , int )), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 3, 5, &func);
}

__declspec(naked) void ShipSelect::Open(int currentId, int currentType)
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
		"push [ebp+12]\n\t"		// currentType
		"push [ebp+8]\n\t"		// currentId
	);
	__asm__("call %0\n\t" :: "m"(_func753::func));
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

namespace _func754
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSelect::OnRender", typeid(void (ShipSelect::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec6c80b948050000000f85????????807b34000f84????????8b7b148b731039f774??89f68dbc27000000008b06", argdata, 1, 5, &func);
}

__declspec(naked) void ShipSelect::OnRender()
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
	__asm__("call %0\n\t" :: "m"(_func754::func));
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

namespace _func755
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
	__asm__("call %0\n\t" :: "m"(_func755::func));
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

namespace _func756
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ShipStatus::OnInit", typeid(void (ShipStatus::*)(Point , float )), "578d7c240883e4f0ff77fc5589e55756538db5c0feffff81ec????????8b078b5704f30f104708", argdata, 3, 5, &func);
}

__declspec(naked) void ShipStatus::OnInit(Point unk, float unk2)
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
		"push [ebp+8]\n\t"		// unk
	);
	__asm__("call %0\n\t" :: "m"(_func756::func));
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

namespace _func757
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipStatus::RenderEvadeOxygen", typeid(void (ShipStatus::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????803f008b490c0f84????????e8????????", argdata, 2, 5, &func);
}

__declspec(naked) void ShipStatus::RenderEvadeOxygen(bool unk)
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
	__asm__("call %0\n\t" :: "m"(_func757::func));
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

namespace _func758
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
	__asm__("call %0\n\t" :: "m"(_func758::func));
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

namespace _func759
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::CheckForRepower", typeid(void (ShipSystem::*)()), ".8b414083e80383f801", argdata, 1, 5, &func);
}

__declspec(naked) void ShipSystem::CheckForRepower()
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
	__asm__("call %0\n\t" :: "m"(_func759::func));
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

namespace _func760
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::NameToSystemId", typeid(int (*)(const std::string &)), ".8d4c240483e4f0ff71fc5589e5535183ec108b19c70424????????89d9e8????????83ec0485c075??", argdata, 1, 2, &func);
}

__declspec(naked) int ShipSystem::NameToSystemId(const std::string &name)
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
	__asm__("call %0\n\t" :: "m"(_func760::func));
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

namespace _func761
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
	__asm__("call %0\n\t" :: "m"(_func761::func));
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

namespace _func762
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
	__asm__("call %0\n\t" :: "m"(_func762::func));
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

namespace _func763
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::OnLoop", typeid(void (ShipSystem::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b812801000085c0", argdata, 1, 5, &func);
}

__declspec(naked) void ShipSystem::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func763::func));
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

namespace _func764
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::Ioned", typeid(bool (ShipSystem::*)(int )), "538b812801000083f8ff0f94c285c00f9fc008d075??83b9a8010000017e??8b911c0100008b415483fa077e??", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipSystem::Ioned(int num)
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
		"push [ebp+8]\n\t"		// num
	);
	__asm__("call %0\n\t" :: "m"(_func764::func));
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

namespace _func765
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SetPowerLoss", typeid(int (ShipSystem::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b338b0f8b8680000000898b200100003d????????0f85????????", argdata, 2, 1, &func);
}

__declspec(naked) int ShipSystem::SetPowerLoss(int power)
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
		"push [ebp+8]\n\t"		// power
	);
	__asm__("call %0\n\t" :: "m"(_func765::func));
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

namespace _func766
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::constructor", typeid(void (ShipSystem::*)(int , int , int , int )), "578d7c240883e4f0ff77fc5589e557565381ec????????8b078b5f048b770c898d24feffff898504feffff8b4708", argdata, 5, 5, &func);
}

__declspec(naked) void ShipSystem::constructor(int systemId, int roomId, int shipId, int startingPower)
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
		"push [ebp+20]\n\t"		// startingPower
		"push [ebp+16]\n\t"		// shipId
		"push [ebp+12]\n\t"		// roomId
		"push [ebp+8]\n\t"		// systemId
	);
	__asm__("call %0\n\t" :: "m"(_func766::func));
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

namespace _func767
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::GetPowerCap", typeid(int (ShipSystem::*)()), "8b811c01000083f8077f??85c0ba????????0f48c2c38d76008dbc27000000008b415485c0", argdata, 1, 1, &func);
}

__declspec(naked) int ShipSystem::GetPowerCap()
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
	__asm__("call %0\n\t" :: "m"(_func767::func));
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

namespace _func768
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SetPowerCap", typeid(void (ShipSystem::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b338b0f8b8680000000898b1c010000", argdata, 2, 5, &func);
}

__declspec(naked) void ShipSystem::SetPowerCap(int cap)
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
		"push [ebp+8]\n\t"		// cap
	);
	__asm__("call %0\n\t" :: "m"(_func768::func));
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

namespace _func769
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::LockSystem", typeid(void (ShipSystem::*)(int )), "578d7c240883e4f0ff77fc5589e55783ec148b0783f80075??8b812801000085c0", argdata, 2, 5, &func);
}

__declspec(naked) void ShipSystem::LockSystem(int lock)
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
		"push [ebp+8]\n\t"		// lock
	);
	__asm__("call %0\n\t" :: "m"(_func769::func));
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

namespace _func770
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::ForceDecreasePower", typeid(void (ShipSystem::*)(int )), "578d7c240883e4f0ff77fc5589e557565383ec2c80b918010000008b1f74??", argdata, 2, 5, &func);
}

__declspec(naked) void ShipSystem::ForceDecreasePower(int powerLoss)
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
		"push [ebp+8]\n\t"		// powerLoss
	);
	__asm__("call %0\n\t" :: "m"(_func770::func));
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

namespace _func771
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::GetEffectivePower", typeid(int (ShipSystem::*)()), "8b414831d285c07e??80794c0074??8b810401000039810001000074??8b8170010000034150", argdata, 1, 1, &func);
}

__declspec(naked) int ShipSystem::GetEffectivePower()
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
	__asm__("call %0\n\t" :: "m"(_func771::func));
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

namespace _func772
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::GetMaxPower", typeid(int (ShipSystem::*)()), "538b59548b910001000001da2b91040100002b91200100008b891c01000083f9077f??85c9b8????????0f49c139c20f4ec2", argdata, 1, 1, &func);
}

__declspec(naked) int ShipSystem::GetMaxPower()
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
	__asm__("call %0\n\t" :: "m"(_func772::func));
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

namespace _func773
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SetBonusPower", typeid(void (ShipSystem::*)(int , int )), "80b918010000000f84????????5589e5578bb904010000568bb100010000538b595489f829f083e4f089da29c28b811c010000", argdata, 3, 5, &func);
}

__declspec(naked) void ShipSystem::SetBonusPower(int amount, int permanentPower)
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
		"push [ebp+12]\n\t"		// permanentPower
		"push [ebp+8]\n\t"		// amount
	);
	__asm__("call %0\n\t" :: "m"(_func773::func));
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

namespace _func774
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::__DO_NOT_HOOK", typeid(void (*)()), "55c701????????89e583e4f0e8????????c9c390909090909090909090909090b8????????", argdata, 1, 5, &func);
}

__declspec(naked) void ShipSystem::__DO_NOT_HOOK()
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
	__asm__("call %0\n\t" :: "m"(_func774::func));
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

namespace _func775
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::PartialDamage", typeid(bool (ShipSystem::*)(float )), ".578d7c240883e4f0ff77fc5589e55783ec14f30f1007f30f110424e8????????8b7dfc83ec04", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipSystem::PartialDamage(float amount)
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
		"push [ebp+8]\n\t"		// amount
	);
	__asm__("call %0\n\t" :: "m"(_func775::func));
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

namespace _func776
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::IsSubsystem", typeid(bool (*)(int )), "8b54240483fa060f94c183fa0c0f94c008c875??83ea0783fa01", argdata, 1, 2, &func);
}

__declspec(naked) bool ShipSystem::IsSubsystem(int systemType)
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
		"push [ebp+8]\n\t"		// systemType
	);
	__asm__("call %0\n\t" :: "m"(_func776::func));
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

namespace _func777
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::ClearStatus", typeid(void (ShipSystem::*)()), "83b91c010000077e??8b812001000085c07e??8b4140c7811c010000e8030000c7812001000000000000c781240100000100000083e80383f80176??55", argdata, 1, 5, &func);
}

__declspec(naked) void ShipSystem::ClearStatus()
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
	__asm__("call %0\n\t" :: "m"(_func777::func));
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

namespace _func778
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SoundControl::PlaySoundMix", typeid(int (SoundControl::*)(const std::string &, float , char )), "578d7c240883e4f0ff77fc5589e557565331db81ec????????8039008b07f30f104704f30f11458889458c74??80b9b80000000075??", argdata, 4, 1, &func);
}

__declspec(naked) int SoundControl::PlaySoundMix(const std::string &soundName, float volume, char loop)
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
	__asm__("call %0\n\t" :: "m"(_func778::func));
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

namespace _func779
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SoundControl::StopPlaylist", typeid(void (SoundControl::*)(int )), "578d7c240883e4f0ff77fc5589e55783ec148039008b0774??890424e8????????83ec048b7dfcc98d67f8", argdata, 2, 5, &func);
}

__declspec(naked) void SoundControl::StopPlaylist(int fadeOut)
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
		"push [ebp+8]\n\t"		// fadeOut
	);
	__asm__("call %0\n\t" :: "m"(_func779::func));
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

namespace _func780
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceDrone::UpdateAimingAngle", typeid(float (SpaceDrone::*)(Pointf , float , float )), "578d7c240883e4f0ff77fc5589e557565383ec3c8b178b7704f30f1089400100000f2e0d????????", argdata, 4, 1, &func);
}

__declspec(naked) float SpaceDrone::UpdateAimingAngle(Pointf location, float percentage, float forceDesired)
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
		"push [ebp+20]\n\t"		// forceDesired
		"push [ebp+16]\n\t"		// percentage
		"push [ebp+12]\n\t"		// location
		"push [ebp+8]\n\t"		// location
	);
	__asm__("call %0\n\t" :: "m"(_func780::func));
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

namespace _func781
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceDrone::SetDeployed", typeid(void (SpaceDrone::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b018b378b5030", argdata, 2, 5, &func);
}

__declspec(naked) void SpaceDrone::SetDeployed(bool deployed)
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
		"push [ebp+8]\n\t"		// deployed
	);
	__asm__("call %0\n\t" :: "m"(_func781::func));
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

namespace _func782
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceDrone::SetMovementTarget", typeid(void (SpaceDrone::*)(Targetable *)), "5589e556538b750883e4f085f674??8b0689cb89f1ff501c89434c8b0689f1ff501c894348", argdata, 2, 5, &func);
}

__declspec(naked) void SpaceDrone::SetMovementTarget(Targetable *target)
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
		"push [ebp+8]\n\t"		// target
	);
	__asm__("call %0\n\t" :: "m"(_func782::func));
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

namespace _func783
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::constructor", typeid(void (SpaceManager::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8d490c8db3640100008dbbd001000083ec1cc741f400000000c741f800000000", argdata, 1, 5, &func);
}

__declspec(naked) void SpaceManager::constructor()
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
	__asm__("call %0\n\t" :: "m"(_func783::func));
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

namespace _func784
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::GetScreenShake", typeid(int (SpaceManager::*)()), ".0fb68188030000c6818803000000", argdata, 1, 1, &func);
}

__declspec(naked) int SpaceManager::GetScreenShake()
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
	__asm__("call %0\n\t" :: "m"(_func784::func));
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

namespace _func785
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SaveSpace", typeid(void (SpaceManager::*)(void *)), ".578d7c240883e4f0ff77fc", argdata, 2, 5, &func);
}

__declspec(naked) void SpaceManager::SaveSpace(void *fileHelper)
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
		"push [ebp+8]\n\t"		// fileHelper
	);
	__asm__("call %0\n\t" :: "m"(_func785::func));
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

namespace _func786
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::SwitchBeacon", typeid(void (SpaceManager::*)()), ".8b54240489c88b8ae802000089088b8aec0200008948048b8af00200008948088b8af4020000", argdata, 1, 5, &func);
}

__declspec(naked) void SpaceManager::SwitchBeacon()
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
	__asm__("call %0\n\t" :: "m"(_func786::func));
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

namespace _func787
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SwitchPlanet", typeid(ImageDesc *(SpaceManager::*)(const std::string &)), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 2, 1, &func);
}

__declspec(naked) ImageDesc *SpaceManager::SwitchPlanet(const std::string &name)
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
	__asm__("call %0\n\t" :: "m"(_func787::func));
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

namespace _func788
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::UpdatePlanetImage", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 5, &func);
}

__declspec(naked) void SpaceManager::UpdatePlanetImage()
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
	__asm__("call %0\n\t" :: "m"(_func788::func));
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

namespace _func789
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x7ff, 0x7ff, 0x7ff};
	static FunctionDefinition funcObj("SpaceManager::SwitchImages", typeid(void (SpaceManager::*)(ImageDesc , ImageDesc , ImageDesc )), ".578d7c240883e4f0", argdata, 4, 5, &func);
}

__declspec(naked) void SpaceManager::SwitchImages(ImageDesc planet, ImageDesc unk1, ImageDesc unk2)
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
		"push [ebp+88]\n\t"		// unk2
		"push [ebp+84]\n\t"		// unk2
		"push [ebp+80]\n\t"		// unk2
		"push [ebp+76]\n\t"		// unk2
		"push [ebp+72]\n\t"		// unk2
		"push [ebp+68]\n\t"		// unk2
		"push [ebp+64]\n\t"		// unk2
		"push [ebp+60]\n\t"		// unk1
		"push [ebp+56]\n\t"		// unk1
		"push [ebp+52]\n\t"		// unk1
		"push [ebp+48]\n\t"		// unk1
		"push [ebp+44]\n\t"		// unk1
		"push [ebp+40]\n\t"		// unk1
		"push [ebp+36]\n\t"		// unk1
		"push [ebp+32]\n\t"		// planet
		"push [ebp+28]\n\t"		// planet
		"push [ebp+24]\n\t"		// planet
		"push [ebp+20]\n\t"		// planet
		"push [ebp+16]\n\t"		// planet
		"push [ebp+12]\n\t"		// planet
		"push [ebp+8]\n\t"		// planet
	);
	__asm__("call %0\n\t" :: "m"(_func789::func));
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
		"ret 84\n\t"
	);
}

namespace _func790
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SwitchBackground", typeid(void (*)(ImageDesc *, SpaceManager *, const std::string &)), ".578d7c240883e4f0", argdata, 3, 4, &func);
}

__declspec(naked) void SpaceManager::SwitchBackground(ImageDesc *ret, SpaceManager *space, const std::string &name)
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
		"push [ebp+16]\n\t"		// name
		"push [ebp+12]\n\t"		// space
		"mov ecx, [ebp+8]\n\t"	// ret
	);
	__asm__("call %0\n\t" :: "m"(_func790::func));
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

namespace _func791
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::StartAsteroids", typeid(void (SpaceManager::*)(int , bool )), ".5789ca83c10c8d7c2408", argdata, 3, 5, &func);
}

__declspec(naked) void SpaceManager::StartAsteroids(int shieldCount, bool unk)
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
		"push [ebp+8]\n\t"		// shieldCount
	);
	__asm__("call %0\n\t" :: "m"(_func791::func));
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

namespace _func792
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetPlanetaryDefense", typeid(void (SpaceManager::*)(char , int )), ".578d7c240883e4f0ff77fc5589e557565389cb81ec????????", argdata, 3, 5, &func);
}

__declspec(naked) void SpaceManager::SetPlanetaryDefense(char state, int target)
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
		"push [ebp+8]\n\t"		// state
	);
	__asm__("call %0\n\t" :: "m"(_func792::func));
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

namespace _func793
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetPulsarLevel", typeid(void (SpaceManager::*)(bool )), ".578d7c240883e4f0ff77fc5589f889e557", argdata, 2, 5, &func);
}

__declspec(naked) void SpaceManager::SetPulsarLevel(bool pulsarLevel)
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
		"push [ebp+8]\n\t"		// pulsarLevel
	);
	__asm__("call %0\n\t" :: "m"(_func793::func));
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

namespace _func794
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::DangerousEnvironment", typeid(bool (SpaceManager::*)()), ".0fb6919802000084d274??83b99c0200000174??", argdata, 1, 1, &func);
}

__declspec(naked) bool SpaceManager::DangerousEnvironment()
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
	__asm__("call %0\n\t" :: "m"(_func794::func));
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

namespace _func795
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::MouseMove", typeid(void (SpaceManager::*)(int , int , int )), ".578d7c240883e4f0ff77fc5589e557565383ec2c8b07", argdata, 4, 5, &func);
}

__declspec(naked) void SpaceManager::MouseMove(int x, int y, int unk)
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
		"push [ebp+16]\n\t"		// unk
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func795::func));
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

namespace _func796
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::GetSelectedDrone", typeid(SpaceDrone *(SpaceManager::*)(int , int , int )), ".578d7c240883e4f0ff77fc5589e557565383ec2c8b078b91a80000008945e0", argdata, 4, 1, &func);
}

__declspec(naked) SpaceDrone *SpaceManager::GetSelectedDrone(int x, int y, int unk)
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
		"push [ebp+16]\n\t"		// unk
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func796::func));
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

namespace _func797
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::GetFlashOpacity", typeid(float (SpaceManager::*)()), ".57660fefc08d7c240883e4f0ff77fc5589e5575383ec2080b9dc02000000", argdata, 1, 1, &func);
}

__declspec(naked) float SpaceManager::GetFlashOpacity()
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
	__asm__("call %0\n\t" :: "m"(_func797::func));
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

namespace _func798
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::GetColorTint", typeid(GL_Color *(SpaceManager::*)()), ".5589c80f2805????????89e58b55080f110180ba600300000075??f30f100d????????", argdata, 1, 1, &func);
}

__declspec(naked) GL_Color *SpaceManager::GetColorTint()
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
	__asm__("call %0\n\t" :: "m"(_func798::func));
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

namespace _func799
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnRenderBackground", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e55756", argdata, 1, 5, &func);
}

__declspec(naked) void SpaceManager::OnRenderBackground()
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
	__asm__("call %0\n\t" :: "m"(_func799::func));
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

namespace _func800
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnRenderFleet", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 5, &func);
}

__declspec(naked) void SpaceManager::OnRenderFleet()
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
	__asm__("call %0\n\t" :: "m"(_func800::func));
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

namespace _func801
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnRenderForeground", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 5, &func);
}

__declspec(naked) void SpaceManager::OnRenderForeground()
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
	__asm__("call %0\n\t" :: "m"(_func801::func));
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

namespace _func802
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetDangerZone", typeid(void (SpaceManager::*)(int )), ".578d7c240883e4f0ff77fc5589e557", argdata, 2, 5, &func);
}

__declspec(naked) void SpaceManager::SetDangerZone(int fleetType)
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
		"push [ebp+8]\n\t"		// fleetType
	);
	__asm__("call %0\n\t" :: "m"(_func802::func));
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

namespace _func803
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::OnRenderAsteroids", typeid(void (SpaceManager::*)(int , float )), ".578d7c240883e4f0ff77fc5589e55756", argdata, 3, 5, &func);
}

__declspec(naked) void SpaceManager::OnRenderAsteroids(int fieldLayers, float unk2)
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
		"push [ebp+8]\n\t"		// fieldLayers
	);
	__asm__("call %0\n\t" :: "m"(_func803::func));
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

namespace _func804
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::OnRenderProjectiles", typeid(void (SpaceManager::*)(int , int )), ".578d7c240883e4f0ff77fc5589f889e5575653", argdata, 3, 5, &func);
}

__declspec(naked) void SpaceManager::OnRenderProjectiles(int unk1, int unk2)
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
	__asm__("call %0\n\t" :: "m"(_func804::func));
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

namespace _func805
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnInit", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e557568d45d8", argdata, 1, 5, &func);
}

__declspec(naked) void SpaceManager::OnInit()
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
	__asm__("call %0\n\t" :: "m"(_func805::func));
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

namespace _func806
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::Restart", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e55756", argdata, 1, 5, &func);
}

__declspec(naked) void SpaceManager::Restart()
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
	__asm__("call %0\n\t" :: "m"(_func806::func));
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

namespace _func807
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::ClearEnvironment", typeid(void (SpaceManager::*)()), ".c6818802000000c6818902000000c6819802000000c7819c02000002000000", argdata, 1, 5, &func);
}

__declspec(naked) void SpaceManager::ClearEnvironment()
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
	__asm__("call %0\n\t" :: "m"(_func807::func));
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

namespace _func808
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::Clear", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 1, 5, &func);
}

__declspec(naked) void SpaceManager::Clear()
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
	__asm__("call %0\n\t" :: "m"(_func808::func));
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

namespace _func809
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::ClearProjectiles", typeid(void (SpaceManager::*)()), ".5589e55756538b1189ce", argdata, 1, 5, &func);
}

__declspec(naked) void SpaceManager::ClearProjectiles()
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
	__asm__("call %0\n\t" :: "m"(_func809::func));
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

namespace _func810
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::UpdateProjectile", typeid(void (SpaceManager::*)(Projectile *)), ".578d7c240883e4f0ff77fc5589e557", argdata, 2, 5, &func);
}

__declspec(naked) void SpaceManager::UpdateProjectile(Projectile *proj)
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
		"push [ebp+8]\n\t"		// proj
	);
	__asm__("call %0\n\t" :: "m"(_func810::func));
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

namespace _func811
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::TransferProjectile", typeid(void (SpaceManager::*)(Projectile *)), ".5589e556538b5d0883e4f0", argdata, 2, 5, &func);
}

__declspec(naked) void SpaceManager::TransferProjectile(Projectile *proj)
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
		"push [ebp+8]\n\t"		// proj
	);
	__asm__("call %0\n\t" :: "m"(_func811::func));
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

namespace _func812
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::AddShip", typeid(void (SpaceManager::*)(ShipManager *)), ".578d7c240883e4f0ff77fc5589f8", argdata, 2, 5, &func);
}

__declspec(naked) void SpaceManager::AddShip(ShipManager *ship)
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
	__asm__("call %0\n\t" :: "m"(_func812::func));
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

namespace _func813
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::AddProjectile", typeid(void (SpaceManager::*)(Projectile *)), ".578d7c240883e4f0ff77fc5589e55783ec148b41043b410874??85c08b17", argdata, 2, 5, &func);
}

__declspec(naked) void SpaceManager::AddProjectile(Projectile *proj)
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
		"push [ebp+8]\n\t"		// proj
	);
	__asm__("call %0\n\t" :: "m"(_func813::func));
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

namespace _func814
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::LoadSpace", typeid(void (SpaceManager::*)(int )), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 2, 5, &func);
}

__declspec(naked) void SpaceManager::LoadSpace(int fileHelper)
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
		"push [ebp+8]\n\t"		// fileHelper
	);
	__asm__("call %0\n\t" :: "m"(_func814::func));
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

namespace _func815
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::UpdatePDS", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 5, &func);
}

__declspec(naked) void SpaceManager::UpdatePDS()
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
	__asm__("call %0\n\t" :: "m"(_func815::func));
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

namespace _func816
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnLoopNebulas", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e5", argdata, 1, 5, &func);
}

__declspec(naked) void SpaceManager::OnLoopNebulas()
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
	__asm__("call %0\n\t" :: "m"(_func816::func));
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

namespace _func817
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnLoop", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 5, &func);
}

__declspec(naked) void SpaceManager::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func817::func));
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

namespace _func818
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetNebula", typeid(void (SpaceManager::*)(bool )), ".578d7c240883e4f0ff77fc5589e55756", argdata, 2, 5, &func);
}

__declspec(naked) void SpaceManager::SetNebula(bool state)
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
		"push [ebp+8]\n\t"		// state
	);
	__asm__("call %0\n\t" :: "m"(_func818::func));
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

namespace _func819
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetStorm", typeid(void (SpaceManager::*)(bool )), ".578d7c240883e4f0ff77fc5589e5", argdata, 2, 5, &func);
}

__declspec(naked) void SpaceManager::SetStorm(bool state)
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
		"push [ebp+8]\n\t"		// state
	);
	__asm__("call %0\n\t" :: "m"(_func819::func));
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

namespace _func820
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetFireLevel", typeid(void (SpaceManager::*)(bool )), "578d7c240883e4f0ff77fc5589f889e55756538d99b802000089cf8d75d083ec3c8b0088818802000089d9", argdata, 2, 5, &func);
}

__declspec(naked) void SpaceManager::SetFireLevel(bool state)
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
		"push [ebp+8]\n\t"		// state
	);
	__asm__("call %0\n\t" :: "m"(_func820::func));
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

namespace _func821
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("StarMap::SetPosition", typeid(void (StarMap::*)(Point )), "5589e58b45088b550c5d89415c895160c208008d", argdata, 2, 5, &func);
}

__declspec(naked) void StarMap::SetPosition(Point unk0)
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
		"push [ebp+12]\n\t"		// unk0
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func821::func));
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

namespace _func822
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::KeyDown", typeid(void (StarMap::*)(int )), ".80b91007000000741a5653837c240c31741e837c", argdata, 2, 5, &func);
}

__declspec(naked) void StarMap::KeyDown(int unk0)
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
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func822::func));
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

namespace _func823
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::GetNextDangerMove", typeid(int (StarMap::*)()), ".56538b999804000085db78??83fb0119d283e2e083c24083fb0119c0", argdata, 1, 1, &func);
}

__declspec(naked) int StarMap::GetNextDangerMove()
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
	__asm__("call %0\n\t" :: "m"(_func823::func));
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

namespace _func824
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::Open", typeid(void (StarMap::*)()), ".80790400740ac389f68dbc2700000000578d7c24", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::Open()
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
	__asm__("call %0\n\t" :: "m"(_func824::func));
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

namespace _func825
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::Close", typeid(void (StarMap::*)()), ".80b9c0060000000f85b6000000578d7c240883e4", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::Close()
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
	__asm__("call %0\n\t" :: "m"(_func825::func));
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

namespace _func826
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::SetOpen", typeid(void (StarMap::*)(bool )), ".578d7c240883e4f0ff77fc5589e557565389cb83", argdata, 2, 5, &func);
}

__declspec(naked) void StarMap::SetOpen(bool unk0)
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
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func826::func));
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

namespace _func827
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::InitMapTitle", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565389ce8d", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::InitMapTitle()
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
	__asm__("call %0\n\t" :: "m"(_func827::func));
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

namespace _func828
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::InitNoFuelText", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb8d", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::InitNoFuelText()
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
	__asm__("call %0\n\t" :: "m"(_func828::func));
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

namespace _func829
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::InitBossMessageBox", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::InitBossMessageBox()
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
	__asm__("call %0\n\t" :: "m"(_func829::func));
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

namespace _func830
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::OnLanguageChange", typeid(void (StarMap::*)()), ".5589e55389cb83e4f0e812f7ffff89d9e8ebfaff", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::OnLanguageChange()
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
	__asm__("call %0\n\t" :: "m"(_func830::func));
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

namespace _func831
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::GetRandomSectorChoice", typeid(int (StarMap::*)()), ".5589e583e4f0803d????????007435e8a46e1500", argdata, 1, 1, &func);
}

__declspec(naked) int StarMap::GetRandomSectorChoice()
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
	__asm__("call %0\n\t" :: "m"(_func831::func));
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

namespace _func832
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::NeighboringSector", typeid(void (StarMap::*)(int )), ".565331c08b5c240c85db78438bb1fc0600008b91", argdata, 2, 5, &func);
}

__declspec(naked) void StarMap::NeighboringSector(int unk0)
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
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func832::func));
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

namespace _func833
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::GetSelectedSector", typeid(void (StarMap::*)(int , int , int )), ".578d7c240883e4f0ff77fc5589fa89e557565389", argdata, 4, 5, &func);
}

__declspec(naked) void StarMap::GetSelectedSector(int unk0, int unk1, int unk2)
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
		"push [ebp+12]\n\t"		// unk1
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func833::func));
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

namespace _func834
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::StartSecretSector", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e55756538d75d0", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::StartSecretSector()
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
	__asm__("call %0\n\t" :: "m"(_func834::func));
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

namespace _func835
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::ReachSector", typeid(void (StarMap::*)(Sector *)), ".578d7c240883e4f0ff77fc5589e557565383ec6c", argdata, 2, 5, &func);
}

__declspec(naked) void StarMap::ReachSector(Sector *unk0)
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
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func835::func));
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

namespace _func836
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::UpdateSectorMap", typeid(void (StarMap::*)(Sector *)), ".578d7c240883e4f0ff77fc5589f889e557565389", argdata, 2, 5, &func);
}

__declspec(naked) void StarMap::UpdateSectorMap(Sector *unk0)
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
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func836::func));
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

namespace _func837
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::SaveGame", typeid(void (StarMap::*)(int )), ".578d7c240883e4f0ff77fc5589f889e557565389", argdata, 2, 5, &func);
}

__declspec(naked) void StarMap::SaveGame(int file)
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
	__asm__("call %0\n\t" :: "m"(_func837::func));
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

namespace _func838
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::InitStatistics", typeid(void (StarMap::*)()), ".f3c38db426000000008dbc2700000000f3c38db4", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::InitStatistics()
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
	__asm__("call %0\n\t" :: "m"(_func838::func));
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

namespace _func839
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::PrintStatistics", typeid(void (StarMap::*)()), ".f3c38db426000000008dbc2700000000f3c38db4", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::PrintStatistics()
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
	__asm__("call %0\n\t" :: "m"(_func839::func));
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

namespace _func840
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::AnalyzeMap", typeid(void (StarMap::*)()), ".f3c38db426000000008dbc27000000008b442404", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::AnalyzeMap()
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
	__asm__("call %0\n\t" :: "m"(_func840::func));
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

namespace _func841
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::ModifyPursuit", typeid(void (StarMap::*)(int )), ".8b442404018198040000c2040090669031c083b9", argdata, 2, 5, &func);
}

__declspec(naked) void StarMap::ModifyPursuit(int unk0)
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
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func841::func));
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

namespace _func842
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::AtBeacon", typeid(void (StarMap::*)()), ".31c083b9800000003b7f4656538b999804000085", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::AtBeacon()
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
	__asm__("call %0\n\t" :: "m"(_func842::func));
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

namespace _func843
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::GetWaitLocation", typeid(void (StarMap::*)()), ".80797c00741a80b9ac060000007411c6417c00c6", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::GetWaitLocation()
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
	__asm__("call %0\n\t" :: "m"(_func843::func));
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

namespace _func844
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::StartBeacon", typeid(void (StarMap::*)()), ".8b919004000031c085d27e04c38d760056538b71", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::StartBeacon()
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
	__asm__("call %0\n\t" :: "m"(_func844::func));
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

namespace _func845
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::LocationsConnected", typeid(void (StarMap::*)(Location *, Location *)), ".538b4424088b5c240c8b48088b500c29cac1fa02", argdata, 3, 5, &func);
}

__declspec(naked) void StarMap::LocationsConnected(Location *unk0, Location *unk1)
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
		"push [ebp+12]\n\t"		// unk1
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func845::func));
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

namespace _func846
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::PointToGrid", typeid(void (StarMap::*)(float , float )), ".578d7c240883e4f0ff77fc5589e5578d4df083ec", argdata, 3, 5, &func);
}

__declspec(naked) void StarMap::PointToGrid(float unk0, float unk1)
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
		"push [ebp+12]\n\t"		// unk1
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func846::func));
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

namespace _func847
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::TravelToLocation", typeid(void (StarMap::*)(Location *)), ".538b44240880787c008941507404c6407c008b58", argdata, 2, 5, &func);
}

__declspec(naked) void StarMap::TravelToLocation(Location *unk0)
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
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func847::func));
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

namespace _func848
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::ForceExitBeacon", typeid(void (StarMap::*)()), ".8b4150c6401401c3908db42600000000f3c38db4", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::ForceExitBeacon()
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
	__asm__("call %0\n\t" :: "m"(_func848::func));
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

namespace _func849
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::OnRenderFogEffect", typeid(void (StarMap::*)()), ".f3c38db426000000008dbc2700000000568b9174", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::OnRenderFogEffect()
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
	__asm__("call %0\n\t" :: "m"(_func849::func));
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

namespace _func850
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::LocationHasBoss", typeid(void (StarMap::*)(Location *)), ".568b917408000031c0538b99680800008b74240c", argdata, 2, 5, &func);
}

__declspec(naked) void StarMap::LocationHasBoss(Location *unk0)
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
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func850::func));
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

namespace _func851
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::LocationHasStore", typeid(void (StarMap::*)(Location *)), ".56538b54240c8b422085c074258b801c06000085", argdata, 2, 5, &func);
}

__declspec(naked) void StarMap::LocationHasStore(Location *unk0)
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
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func851::func));
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

namespace _func852
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::LocationHasShip", typeid(void (StarMap::*)(Location *)), ".8b4424048b402085c074070fb6401cc2040031c0", argdata, 2, 5, &func);
}

__declspec(naked) void StarMap::LocationHasShip(Location *unk0)
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
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func852::func));
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

namespace _func853
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::AdvanceWorldLevel", typeid(void (StarMap::*)()), ".8b819004000083c00183f8038981900400007f01", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::AdvanceWorldLevel()
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
	__asm__("call %0\n\t" :: "m"(_func853::func));
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

namespace _func854
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::ReverseBossPath", typeid(void (StarMap::*)()), ".568b8174080000538b997808000080b170080000", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::ReverseBossPath()
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
	__asm__("call %0\n\t" :: "m"(_func854::func));
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

namespace _func855
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::ForceBossJump", typeid(void (StarMap::*)()), ".80b97008000000c6817108000001751a8b817808", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::ForceBossJump()
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
	__asm__("call %0\n\t" :: "m"(_func855::func));
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

namespace _func856
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::ClearBoss", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565331db89", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::ClearBoss()
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
	__asm__("call %0\n\t" :: "m"(_func856::func));
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

namespace _func857
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::SetBossStage", typeid(void (StarMap::*)(int )), ".8b4424048981e4090000c2040090669031c083b9", argdata, 2, 5, &func);
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
	__asm__("call %0\n\t" :: "m"(_func857::func));
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

namespace _func858
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::CheckGameOver", typeid(void (StarMap::*)()), ".31c083b96c080000047405f3c38d76008b817408", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::CheckGameOver()
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
	__asm__("call %0\n\t" :: "m"(_func858::func));
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

namespace _func859
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::RenderLabels", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565389cf81", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::RenderLabels()
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
	__asm__("call %0\n\t" :: "m"(_func859::func));
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

namespace _func860
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::DeleteMap", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b81d80900008b99dc09000039d8", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::DeleteMap()
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
	__asm__("call %0\n\t" :: "m"(_func860::func));
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

namespace _func861
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::MouseClick", typeid(void (StarMap::*)(int , int )), ".578d7c240883e4f0ff77fc5589e557565389cb83", argdata, 3, 5, &func);
}

__declspec(naked) void StarMap::MouseClick(int unk0, int unk1)
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
		"push [ebp+12]\n\t"		// unk1
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func861::func));
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

namespace _func862
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::AddSectorColumn", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565389cebb", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::AddSectorColumn()
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
	__asm__("call %0\n\t" :: "m"(_func862::func));
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

namespace _func863
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::PushSectorColumn", typeid(void (StarMap::*)()), ".5589e557565389cf83e4f083ec208b81fc060000", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::PushSectorColumn()
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
	__asm__("call %0\n\t" :: "m"(_func863::func));
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

namespace _func864
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::SelectNewSector", typeid(void (StarMap::*)(int )), ".578d7c240883e4f0ff77fc5589f889e557565389", argdata, 2, 5, &func);
}

__declspec(naked) void StarMap::SelectNewSector(int unk0)
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
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func864::func));
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

namespace _func865
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::GenerateSectorMap", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb81", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::GenerateSectorMap()
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
	__asm__("call %0\n\t" :: "m"(_func865::func));
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

namespace _func866
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::constructor", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb8d", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::constructor()
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
	__asm__("call %0\n\t" :: "m"(_func866::func));
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

namespace _func867
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("StarMap::RenderSectorName", typeid(void (StarMap::*)(Sector *, GL_Color )), ".578d7c240883e4f0ff77fc5589e55756538d85d0", argdata, 3, 5, &func);
}

__declspec(naked) void StarMap::RenderSectorName(Sector *unk0, GL_Color unk1)
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
		"push [ebp+24]\n\t"		// unk1
		"push [ebp+20]\n\t"		// unk1
		"push [ebp+16]\n\t"		// unk1
		"push [ebp+12]\n\t"		// unk1
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func867::func));
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
		"ret 20\n\t"
	);
}

namespace _func868
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::UpdateDangerZone", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83ec4c80b9c0060000000f85????????80b980080000000f85????????8bb38000000083fe3b0f8f????????89d9e8????????01f083f83b898380000000", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::UpdateDangerZone()
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
	__asm__("call %0\n\t" :: "m"(_func868::func));
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

namespace _func869
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::GetNewLocation", typeid(void (StarMap::*)()), ".31c080797c00747880b9ac06000000755c5589e5", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::GetNewLocation()
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
	__asm__("call %0\n\t" :: "m"(_func869::func));
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

namespace _func870
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::OnLoop", typeid(void (StarMap::*)()), ".80790400750ac389f68dbc2700000000578d7c24", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func870::func));
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

namespace _func871
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::UpdateBoss", typeid(void (StarMap::*)()), ".80b98008000000740c5589e583e4f0e8acf3ffff", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::UpdateBoss()
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
	__asm__("call %0\n\t" :: "m"(_func871::func));
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

namespace _func872
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::GenerateEvents", typeid(void (StarMap::*)(bool )), ".578d7c240883e4f0ff77fc5589e557565381ec????????8b81a00600008b919c0600008b37898de8feffff898504ffffff29d0c1f802", argdata, 2, 5, &func);
}

__declspec(naked) void StarMap::GenerateEvents(bool tutorial)
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
		"push [ebp+8]\n\t"		// tutorial
	);
	__asm__("call %0\n\t" :: "m"(_func872::func));
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

namespace _func873
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::AddConnections", typeid(void (StarMap::*)(Location *)), ".578d7c240883e4f0ff77fc5589e557565383ec2c", argdata, 2, 5, &func);
}

__declspec(naked) void StarMap::AddConnections(Location *unk0)
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
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func873::func));
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

namespace _func874
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::MapConnected", typeid(void (StarMap::*)()), ".578d810c0a00008d7c240883e4f0ff77fc5589e5", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::MapConnected()
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
	__asm__("call %0\n\t" :: "m"(_func874::func));
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

namespace _func875
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x2ff};
	static FunctionDefinition funcObj("StarMap::ConnectLocations", typeid(void (StarMap::*)(Point , Point )), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 3, 5, &func);
}

__declspec(naked) void StarMap::ConnectLocations(Point unk0, Point unk1)
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
		"push [ebp+20]\n\t"		// unk1
		"push [ebp+16]\n\t"		// unk1
		"push [ebp+12]\n\t"		// unk0
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func875::func));
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

namespace _func876
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("StarMap::PopulateGrid", typeid(void (StarMap::*)(Point )), ".5789c883c02c8d7c240883e4f0ff77fc5589e5575653", argdata, 2, 5, &func);
}

__declspec(naked) void StarMap::PopulateGrid(Point unk0)
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
		"push [ebp+12]\n\t"		// unk0
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func876::func));
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

namespace _func877
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::PopClosestLoc", typeid(Location *(StarMap::*)(std::vector<Location*> &, std::map<Location*, int> &)), ".578d7c240883e4f0ff77fc5589e557565383ec4c8b07", argdata, 3, 1, &func);
}

__declspec(naked) Location *StarMap::PopClosestLoc(std::vector<Location*> &vec, std::map<Location*, int> &map)
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
		"push [ebp+12]\n\t"		// map
		"push [ebp+8]\n\t"		// vec
	);
	__asm__("call %0\n\t" :: "m"(_func877::func));
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

namespace _func878
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::Dijkstra0", typeid(void (*)(std::vector<Location*> &, StarMap *, Location *, Location *, bool )), ".578d7c240883e4f0ff77fc5589e55756538d45a431f681ec????????89bd70ffffff", argdata, 5, 4, &func);
}

__declspec(naked) void StarMap::Dijkstra0(std::vector<Location*> &ref, StarMap *starMap, Location *start, Location *finish, bool include_unknown)
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
		"push [ebp+24]\n\t"		// include_unknown
		"push [ebp+20]\n\t"		// finish
		"push [ebp+16]\n\t"		// start
		"push [ebp+12]\n\t"		// starMap
		"mov ecx, [ebp+8]\n\t"	// ref
	);
	__asm__("call %0\n\t" :: "m"(_func878::func));
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
		"ret 20\n\t"
	);
}

namespace _func879
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::AddQuest", typeid(bool (StarMap::*)(const std::string &, bool )), ".578d7c240883e4f0ff77fc5589f889e557565389cf83ec5c8b100fb64004", argdata, 3, 1, &func);
}

__declspec(naked) bool StarMap::AddQuest(const std::string &questEvent, bool force)
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
		"push [ebp+12]\n\t"		// force
		"push [ebp+8]\n\t"		// questEvent
	);
	__asm__("call %0\n\t" :: "m"(_func879::func));
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

namespace _func880
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::GenerateMap", typeid(Location *(StarMap::*)(bool , bool )), ".578d7c240883e4f0ff77fc5589e557565381ec????????", argdata, 3, 1, &func);
}

__declspec(naked) Location *StarMap::GenerateMap(bool tutorial, bool seed)
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
		"push [ebp+12]\n\t"		// seed
		"push [ebp+8]\n\t"		// tutorial
	);
	__asm__("call %0\n\t" :: "m"(_func880::func));
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

namespace _func881
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::NewGame", typeid(Location *(StarMap::*)(bool )), ".578d7c240883e4f0ff77fc5589e557565389ce83", argdata, 2, 1, &func);
}

__declspec(naked) Location *StarMap::NewGame(bool unk0)
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
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func881::func));
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

namespace _func882
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::Dijkstra1", typeid(void (*)(std::vector<Location*> &, StarMap *, Location *, Location *, bool )), ".578d7c240883e4f0ff77fc5589f889e557565381", argdata, 5, 4, &func);
}

__declspec(naked) void StarMap::Dijkstra1(std::vector<Location*> &ref, StarMap *starMap, Location *start, Location *finish, bool include_unknown)
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
		"push [ebp+24]\n\t"		// include_unknown
		"push [ebp+20]\n\t"		// finish
		"push [ebp+16]\n\t"		// start
		"push [ebp+12]\n\t"		// starMap
		"mov ecx, [ebp+8]\n\t"	// ref
	);
	__asm__("call %0\n\t" :: "m"(_func882::func));
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
		"ret 20\n\t"
	);
}

namespace _func883
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::MouseMove", typeid(void (StarMap::*)(int , int )), ".578d7c240883e4f0ff77fc5589e557565381ec8c", argdata, 3, 5, &func);
}

__declspec(naked) void StarMap::MouseMove(int x, int y)
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
	__asm__("call %0\n\t" :: "m"(_func883::func));
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

namespace _func884
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::OnTouch", typeid(void (StarMap::*)(TouchAction , int , int , int , int , int )), ".578d7c240883e4f0ff77fc5589e557565389ce81", argdata, 7, 5, &func);
}

__declspec(naked) void StarMap::OnTouch(TouchAction unk0, int unk1, int unk2, int unk3, int unk4, int unk5)
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
		"push [ebp+28]\n\t"		// unk5
		"push [ebp+24]\n\t"		// unk4
		"push [ebp+20]\n\t"		// unk3
		"push [ebp+16]\n\t"		// unk2
		"push [ebp+12]\n\t"		// unk1
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func884::func));
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
		"ret 24\n\t"
	);
}

namespace _func885
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::LoadGame", typeid(Location *(StarMap::*)(int )), ".578d7c240883e4f0ff77fc5589f889e557565389", argdata, 2, 1, &func);
}

__declspec(naked) Location *StarMap::LoadGame(int fileHelper)
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
		"push [ebp+8]\n\t"		// fileHelper
	);
	__asm__("call %0\n\t" :: "m"(_func885::func));
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

namespace _func886
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::RenderLeftInsetButton", typeid(void (StarMap::*)(float , float , bool )), ".578d7c240883e4f0ff77fc5589e557565389cb83", argdata, 4, 5, &func);
}

__declspec(naked) void StarMap::RenderLeftInsetButton(float unk0, float unk1, bool unk2)
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
		"push [ebp+12]\n\t"		// unk1
		"push [ebp+8]\n\t"		// unk0
	);
	__asm__("call %0\n\t" :: "m"(_func886::func));
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

namespace _func887
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::RenderDistressButtons", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e55756538d7dc8", argdata, 1, 5, &func);
}

__declspec(naked) void StarMap::RenderDistressButtons()
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
	__asm__("call %0\n\t" :: "m"(_func887::func));
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

namespace _func888
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::OnRender", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb81ec????????80b91007000000", argdata, 1, 5, &func);
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
	__asm__("call %0\n\t" :: "m"(_func888::func));
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

namespace _func889
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::DrawConnection", typeid(void (StarMap::*)(const Pointf &, const Pointf &, const GL_Color *)), "578d7c240883e4f0ff77fc5589e557565381ec????????8b078b57048b5f08894db889458089d689957cffffff8b5004", argdata, 4, 5, &func);
}

__declspec(naked) void StarMap::DrawConnection(const Pointf &pos1, const Pointf &pos2, const GL_Color *color)
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
		"push [ebp+16]\n\t"		// color
		"push [ebp+12]\n\t"		// pos2
		"push [ebp+8]\n\t"		// pos1
	);
	__asm__("call %0\n\t" :: "m"(_func889::func));
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

namespace _func890
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::TurnIntoFleetLocation", typeid(void (StarMap::*)(Location *)), "578d7c240883e4f0ff77fc5589e557565383ec4c8b1f8b4320c6431c01c6839c00000000", argdata, 2, 5, &func);
}

__declspec(naked) void StarMap::TurnIntoFleetLocation(Location *loc)
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
		"push [ebp+8]\n\t"		// loc
	);
	__asm__("call %0\n\t" :: "m"(_func890::func));
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

namespace _func891
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::GetLocationText", typeid(std::string &(*)(std::string &, StarMap *, const Location *)), "578d41088d7c240883e4f0ff77fc5589e557565389ce83ec7c8b1f8d7dd08901", argdata, 3, 0, &func);
}

__declspec(naked) std::string &StarMap::GetLocationText(std::string &strRef, StarMap *starMap, const Location *loc)
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
		"push [ebp+16]\n\t"		// loc
		"push [ebp+12]\n\t"		// starMap
		"mov ecx, [ebp+8]\n\t"	// strRef
	);
	__asm__("call %0\n\t" :: "m"(_func891::func));
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

namespace _func892
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::SetupNoFuel", typeid(void (StarMap::*)(int , const std::string &)), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????833fff8b77040f84????????8b81ac090000c68543ffffff00803d??????????c683c8090000018983ac090000", argdata, 3, 5, &func);
}

__declspec(naked) void StarMap::SetupNoFuel(int seed, const std::string &forceEscape)
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
		"push [ebp+12]\n\t"		// forceEscape
		"push [ebp+8]\n\t"		// seed
	);
	__asm__("call %0\n\t" :: "m"(_func892::func));
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

namespace _func893
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::GenerateNebulas", typeid(void (StarMap::*)(const std::vector<std::string> &)), "578d7c240883e4f0ff77fc5589e557565381ec????????8b0789c78945888b40048b17", argdata, 2, 5, &func);
}

__declspec(naked) void StarMap::GenerateNebulas(const std::vector<std::string> &names)
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
		"push [ebp+8]\n\t"		// names
	);
	__asm__("call %0\n\t" :: "m"(_func893::func));
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

namespace _func894
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("StatusEffect::GetNebulaEffect", typeid(StatusEffect *(*)()), "5589e55383e4f083ec10803d??????????8b5d0874??660f6f05????????c703????????0f2905????????a1????????894304a1????????", argdata, 0, 2, &func);
}

__declspec(naked) StatusEffect *StatusEffect::GetNebulaEffect()
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
	__asm__("call %0\n\t" :: "m"(_func894::func));
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

namespace _func895
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::OnInit", typeid(void (Store::*)(ShipManager *, Equipment *, int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b078b918c0400008945e48b47048945dc8b4708", argdata, 4, 5, &func);
}

__declspec(naked) void Store::OnInit(ShipManager *shopper, Equipment *equip, int worldLevel)
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
		"push [ebp+16]\n\t"		// worldLevel
		"push [ebp+12]\n\t"		// equip
		"push [ebp+8]\n\t"		// shopper
	);
	__asm__("call %0\n\t" :: "m"(_func895::func));
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

namespace _func896
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::CreateStoreBoxes", typeid(void (Store::*)(int , Equipment *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec7c8b178b47048955a08945a4", argdata, 3, 5, &func);
}

__declspec(naked) void Store::CreateStoreBoxes(int type, Equipment *equip)
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
		"push [ebp+12]\n\t"		// equip
		"push [ebp+8]\n\t"		// type
	);
	__asm__("call %0\n\t" :: "m"(_func896::func));
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

namespace _func897
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Store::KeyDown", typeid(void (Store::*)(SDLKey )), "578d7c240883e4f0ff77fc5589e55783ec1483b964060000028b077e??83f83189cf", argdata, 2, 5, &func);
}

__declspec(naked) void Store::KeyDown(SDLKey key)
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
	__asm__("call %0\n\t" :: "m"(_func897::func));
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

namespace _func898
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Store::OnLoop", typeid(void (Store::*)()), "8b918c0400008b819004000029d0c1f80285c074??5589e5565389ce31db83e4f08b0c9a83c301", argdata, 1, 5, &func);
}

__declspec(naked) void Store::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func898::func));
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

namespace _func899
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Store::Close", typeid(void (Store::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec10c64104008b897c06000085c974??8b01c70424????????ff5030", argdata, 1, 5, &func);
}

__declspec(naked) void Store::Close()
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
	__asm__("call %0\n\t" :: "m"(_func899::func));
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

namespace _func900
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::MouseMove", typeid(void (Store::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b07898560feffff8b4704898564feffff8d81b0040000", argdata, 3, 5, &func);
}

__declspec(naked) void Store::MouseMove(int x, int y)
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
	__asm__("call %0\n\t" :: "m"(_func900::func));
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

namespace _func901
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Store::constructor", typeid(void (Store::*)()), "5589e55389cb83e4f0e8????????8d43288d8b90000000c703????????c7432400000000c64328008943208d4344c6433801c7434000000000", argdata, 1, 5, &func);
}

__declspec(naked) void Store::constructor()
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
	__asm__("call %0\n\t" :: "m"(_func901::func));
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

namespace _func902
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Store::SaveStore", typeid(void (Store::*)(int )), "5589e557565389cb83e4f083ec208b8164060000894424048b4508890424e8????????8b836406000085c00f8e????????31f68b84b3680600008d3c76", argdata, 2, 5, &func);
}

__declspec(naked) void Store::SaveStore(int file)
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
	__asm__("call %0\n\t" :: "m"(_func902::func));
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

namespace _func903
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::RelinkShip", typeid(void (Store::*)(ShipManager *, Equipment *)), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b47048b1f8945e48999a40400008b898c0400008b8690040000", argdata, 3, 5, &func);
}

__declspec(naked) void Store::RelinkShip(ShipManager *ship, Equipment *equip)
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
		"push [ebp+12]\n\t"		// equip
		"push [ebp+8]\n\t"		// ship
	);
	__asm__("call %0\n\t" :: "m"(_func903::func));
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

namespace _func904
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Store::HasType", typeid(bool (Store::*)()), "8b4424043b816806000074??3b816c06000074??3b817006000074??3981740600000f94c0c20400908db42600000000b8????????", argdata, 1, 1, &func);
}

__declspec(naked) bool Store::HasType()
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
	__asm__("call %0\n\t" :: "m"(_func904::func));
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

namespace _func905
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Store::Clear", typeid(void (Store::*)()), "5589e55756538bb99004000089ce8b918c04000083e4f089f829d0c1f80285c074??31db8b0c9a85c9", argdata, 1, 5, &func);
}

__declspec(naked) void Store::Clear()
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
	__asm__("call %0\n\t" :: "m"(_func905::func));
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

namespace _func906
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Store::InitHeading", typeid(void (Store::*)(int , Point )), "578d7c240883e4f0ff77fc5589e557565389ce83ec7c8b1f8d7da4c745a000000000c645a400897d9c", argdata, 3, 5, &func);
}

__declspec(naked) void Store::InitHeading(int index, Point pos)
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
		"push [ebp+16]\n\t"		// pos
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// index
	);
	__asm__("call %0\n\t" :: "m"(_func906::func));
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

namespace _func907
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Store::DrawBuySellTabText", typeid(void (Store::*)()), "8d4c240483e4f0ff71fc5589e5575653518d45d08d75a08d5dd881ec????????c745d873746f72c745dc655f746189442404", argdata, 1, 5, &func);
}

__declspec(naked) void Store::DrawBuySellTabText()
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
	__asm__("call %0\n\t" :: "m"(_func907::func));
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

namespace _func908
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::MouseClick", typeid(void (Store::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b078b7f04890424897c2404894584e8????????8b837c06000083ec08", argdata, 3, 5, &func);
}

__declspec(naked) void Store::MouseClick(int x, int y)
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
	__asm__("call %0\n\t" :: "m"(_func908::func));
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

namespace _func909
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Store::OnRender", typeid(void (Store::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????e8????????8b837c06000085c074??0f2805????????c70424????????0f298518ffffff8b851cffffff89442404", argdata, 1, 5, &func);
}

__declspec(naked) void Store::OnRender()
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
	__asm__("call %0\n\t" :: "m"(_func909::func));
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

namespace _func910
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Store::SetPositions", typeid(void (Store::*)()), "578d7c240883e4f0ff77fc5589e557565389cf31f683ec7cc64105018d4dd0c74424042a000000c70424????????e8????????83ec088b45d08b55d489f9", argdata, 1, 5, &func);
}

__declspec(naked) void Store::SetPositions()
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
	__asm__("call %0\n\t" :: "m"(_func910::func));
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

namespace _func911
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::LoadStore", typeid(void (Store::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????8b078b918c040000898550ffffff8b47048bb990040000898538ffffff89f8", argdata, 3, 5, &func);
}

__declspec(naked) void Store::LoadStore(int file, int worldLevel)
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
		"push [ebp+12]\n\t"		// worldLevel
		"push [ebp+8]\n\t"		// file
	);
	__asm__("call %0\n\t" :: "m"(_func911::func));
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

namespace _func912
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("Store::SetPosition", typeid(void (Store::*)(Point )), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b078b570489042489542404e8????????", argdata, 2, 5, &func);
}

__declspec(naked) void Store::SetPosition(Point pos)
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
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// pos
	);
	__asm__("call %0\n\t" :: "m"(_func912::func));
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

namespace _func913
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StoreBox::MouseClick", typeid(void (StoreBox::*)(int , int )), "8079640075??c208008db426000000008079650074??8b015589e583e4f0", argdata, 3, 5, &func);
}

__declspec(naked) void StoreBox::MouseClick(int x, int y)
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
	__asm__("call %0\n\t" :: "m"(_func913::func));
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

namespace _func914
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StoreBox::Activate", typeid(void (StoreBox::*)()), "578d7c240883e4f0ff77fc5589e5575383ec308b81380100008b80d40400003981e80000007e??b9????????c70424????????8d5de8e8????????8d45e083ec04", argdata, 1, 5, &func);
}

__declspec(naked) void StoreBox::Activate()
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
	__asm__("call %0\n\t" :: "m"(_func914::func));
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

namespace _func915
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StoreBox::InitBlueprint", typeid(void (StoreBox::*)(Blueprint *)), "578d7c240883e4f0ff77fc5589e557565389ce81c1????????83ec4c8b1f8b83b8000000898170ffffff8d431c890424e8????????", argdata, 2, 5, &func);
}

__declspec(naked) void StoreBox::InitBlueprint(Blueprint *bp)
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
		"push [ebp+8]\n\t"		// bp
	);
	__asm__("call %0\n\t" :: "m"(_func915::func));
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

namespace _func916
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StoreBox::constructor", typeid(void (StoreBox::*)(const std::string &, ShipManager *, Equipment *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b07c701????????c74104ffffffffc741080000000089c28945c48b47048945c08b470889d78b7704", argdata, 4, 5, &func);
}

__declspec(naked) void StoreBox::constructor(const std::string &buttonImage, ShipManager *shopper, Equipment *equip)
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
		"push [ebp+16]\n\t"		// equip
		"push [ebp+12]\n\t"		// shopper
		"push [ebp+8]\n\t"		// buttonImage
	);
	__asm__("call %0\n\t" :: "m"(_func916::func));
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

namespace _func917
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StoreBox::OnLoop", typeid(void (StoreBox::*)()), "5731c08d7c240883e4f0ff77fc5589e5575389cb83ec108b913001000085d27e??80b9f80000000074??", argdata, 1, 5, &func);
}

__declspec(naked) void StoreBox::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func917::func));
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

namespace _func918
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SystemBox::OnRender", typeid(void (SystemBox::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389ce83ec7c0fb641508b1fc781b401000000000000", argdata, 2, 5, &func);
}

__declspec(naked) void SystemBox::OnRender(bool ignoreStatus)
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
		"push [ebp+8]\n\t"		// ignoreStatus
	);
	__asm__("call %0\n\t" :: "m"(_func918::func));
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

namespace _func919
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SystemControl::CreateSystemBoxes", typeid(void (SystemControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8d4ddc83ec5cc744240400000000c70424????????e8????????8b45dc8b55e0", argdata, 1, 5, &func);
}

__declspec(naked) void SystemControl::CreateSystemBoxes()
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
	__asm__("call %0\n\t" :: "m"(_func919::func));
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

namespace _func920
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SystemControl::GetSystemBox", typeid(SystemBox *(SystemControl::*)(int )), "8b51088b410c29d0c1f80285c074??5589e557565389ce31db83e4f0eb??66908b4140", argdata, 2, 1, &func);
}

__declspec(naked) SystemBox *SystemControl::GetSystemBox(int systemId)
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
		"push [ebp+8]\n\t"		// systemId
	);
	__asm__("call %0\n\t" :: "m"(_func920::func));
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

namespace _func921
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SystemStoreBox::SetExtraData", typeid(void (SystemStoreBox::*)(int )), "578d7c240883e4f0ff77fc5589e557565383ec4c837904048b0789819001000074??", argdata, 2, 5, &func);
}

__declspec(naked) void SystemStoreBox::SetExtraData(int droneChoice)
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
		"push [ebp+8]\n\t"		// droneChoice
	);
	__asm__("call %0\n\t" :: "m"(_func921::func));
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

namespace _func922
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemStoreBox::constructor", typeid(void (SystemStoreBox::*)(ShipManager *, Equipment *, int )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b078b57048945808b470889c7894584", argdata, 4, 5, &func);
}

__declspec(naked) void SystemStoreBox::constructor(ShipManager *shopper, Equipment *equip, int sys)
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
		"push [ebp+16]\n\t"		// sys
		"push [ebp+12]\n\t"		// equip
		"push [ebp+8]\n\t"		// shopper
	);
	__asm__("call %0\n\t" :: "m"(_func922::func));
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

namespace _func923
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::SetHackingLevel", typeid(void (TeleportSystem::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b3783fe01", argdata, 2, 5, &func);
}

__declspec(naked) void TeleportSystem::SetHackingLevel(int hackingLevel)
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
		"push [ebp+8]\n\t"		// hackingLevel
	);
	__asm__("call %0\n\t" :: "m"(_func923::func));
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

namespace _func924
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::OnRenderFloor", typeid(void (TeleportSystem::*)()), "578d7c240883e4f0ff77fc5589e557565389cf83ec7c803d??????????0f84????????803d??????????0f84????????", argdata, 1, 5, &func);
}

__declspec(naked) void TeleportSystem::OnRenderFloor()
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
	__asm__("call %0\n\t" :: "m"(_func924::func));
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

namespace _func925
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::constructor", typeid(void (TeleportSystem::*)(int , int , int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b77048b57088b078b4f0c8954240889742404894c240c890424", argdata, 5, 5, &func);
}

__declspec(naked) void TeleportSystem::constructor(int systemId, int roomId, int shipId, int startingPower)
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
		"push [ebp+20]\n\t"		// startingPower
		"push [ebp+16]\n\t"		// shipId
		"push [ebp+12]\n\t"		// roomId
		"push [ebp+8]\n\t"		// systemId
	);
	__asm__("call %0\n\t" :: "m"(_func925::func));
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

namespace _func926
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::GetChargedPercent", typeid(float (TeleportSystem::*)()), ".83ec04f30f1081c0010000f30f5e05????????f30f110424d9042483c404", argdata, 1, 1, &func);
}

__declspec(naked) float TeleportSystem::GetChargedPercent()
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
	__asm__("call %0\n\t" :: "m"(_func926::func));
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

namespace _func927
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::Charged", typeid(bool (TeleportSystem::*)()), ".5589e55389cb83e4f0e8????????31d284c075??8b03", argdata, 1, 1, &func);
}

__declspec(naked) bool TeleportSystem::Charged()
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
	__asm__("call %0\n\t" :: "m"(_func927::func));
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

namespace _func928
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::ClearCrewLocations", typeid(void (TeleportSystem::*)()), "5589e557565383e4f083ec208b99e4010000c781e001000000000000894c241c8d7b1f89fec1ee05c1e602893424e8????????", argdata, 1, 5, &func);
}

__declspec(naked) void TeleportSystem::ClearCrewLocations()
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
	__asm__("call %0\n\t" :: "m"(_func928::func));
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

namespace _func929
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::UpdateCrewLocation", typeid(void (TeleportSystem::*)(int )), ".5389ca8b4c24088b82cc01000089cbc1eb058d1c98b8????????d3e08b0b85c1", argdata, 2, 5, &func);
}

__declspec(naked) void TeleportSystem::UpdateCrewLocation(int unk)
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
	__asm__("call %0\n\t" :: "m"(_func929::func));
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

namespace _func930
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::SetArmed", typeid(void (TeleportSystem::*)(int )), ".578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b07", argdata, 2, 5, &func);
}

__declspec(naked) void TeleportSystem::SetArmed(int armed)
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
		"push [ebp+8]\n\t"		// armed
	);
	__asm__("call %0\n\t" :: "m"(_func930::func));
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

namespace _func931
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::ForceReady", typeid(void (TeleportSystem::*)()), ".578d7c240883e4f0ff77fc5589e55783ec14c781c00100000000c842c70424????????e8????????8b7dfc", argdata, 1, 5, &func);
}

__declspec(naked) void TeleportSystem::ForceReady()
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
	__asm__("call %0\n\t" :: "m"(_func931::func));
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

namespace _func932
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::CanSend", typeid(bool (TeleportSystem::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b490c85c975??80bbc401000000", argdata, 1, 1, &func);
}

__declspec(naked) bool TeleportSystem::CanSend()
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
	__asm__("call %0\n\t" :: "m"(_func932::func));
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

namespace _func933
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::CanReceive", typeid(bool (TeleportSystem::*)()), ".5589e556538b750883e4f080b9c50100000075??8b410c85c074??8b0189cbff502c84c0", argdata, 1, 1, &func);
}

__declspec(naked) bool TeleportSystem::CanReceive()
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
	__asm__("call %0\n\t" :: "m"(_func933::func));
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

namespace _func934
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::InitiateTeleport", typeid(void (TeleportSystem::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb83ec30e8????????83e80131d283f80277??", argdata, 1, 5, &func);
}

__declspec(naked) void TeleportSystem::InitiateTeleport()
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
	__asm__("call %0\n\t" :: "m"(_func934::func));
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

namespace _func935
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::OnLoop", typeid(void (TeleportSystem::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83ec4ce8????????8b0389d9", argdata, 1, 5, &func);
}

__declspec(naked) void TeleportSystem::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func935::func));
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

namespace _func936
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::Jump", typeid(void (TeleportSystem::*)()), ".5589e55389cb83e4f0e8????????c783c0010000000000008b5dfc", argdata, 1, 5, &func);
}

__declspec(naked) void TeleportSystem::Jump()
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
	__asm__("call %0\n\t" :: "m"(_func936::func));
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

namespace _func937
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextButton::ResetPrimitives", typeid(void (TextButton::*)()), "5589e55756538d79548d594889ce83e4f083ec108b0383c304890424e8????????c743fc0000000039fb75??", argdata, 1, 5, &func);
}

__declspec(naked) void TextButton::ResetPrimitives()
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
	__asm__("call %0\n\t" :: "m"(_func937::func));
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

namespace _func938
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextButton::GetIdealButtonWidth", typeid(int (TextButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c80b9dc000000000f85????????8d81c40000008d7dd0", argdata, 1, 1, &func);
}

__declspec(naked) int TextButton::GetIdealButtonWidth()
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
	__asm__("call %0\n\t" :: "m"(_func938::func));
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

namespace _func939
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("TextButton::__DO_NOT_HOOK", typeid(void (*)()), ".83c30439f375??8d65f85b5e5dc204008d742600ffd08d65f85b", argdata, 0, 4, &func);
}

__declspec(naked) void TextButton::__DO_NOT_HOOK()
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
	__asm__("call %0\n\t" :: "m"(_func939::func));
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

namespace _func940
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextButton::constructor", typeid(void (TextButton::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb8d49048d7324", argdata, 1, 5, &func);
}

__declspec(naked) void TextButton::constructor()
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
	__asm__("call %0\n\t" :: "m"(_func940::func));
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

namespace _func941
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextButton::OnInit", typeid(void (TextButton::*)(int , int , int , int , int , TextString *, int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b4f0c8b078b57148b7704894dd08b4f108945c88b4708", argdata, 8, 5, &func);
}

__declspec(naked) void TextButton::OnInit(int x, int y, int w, int h, int cornerInset, TextString *buttonLabel, int font)
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
		"push [ebp+32]\n\t"		// font
		"push [ebp+28]\n\t"		// buttonLabel
		"push [ebp+24]\n\t"		// cornerInset
		"push [ebp+20]\n\t"		// h
		"push [ebp+16]\n\t"		// w
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func941::func));
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
		"ret 28\n\t"
	);
}

namespace _func942
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextButton::OnRender", typeid(void (TextButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????80b9b4000000000f85????????8b474885c0", argdata, 1, 5, &func);
}

__declspec(naked) void TextButton::OnRender()
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
	__asm__("call %0\n\t" :: "m"(_func942::func));
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

namespace _func943
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextButton::destructor", typeid(void (TextButton::*)()), "5589e55389cb81c3????????83e4f083ec108b4148c701????????890424e8????????8b4380890424e8????????8b4384890424e8????????8b4394890424", argdata, 1, 5, &func);
}

__declspec(naked) void TextButton::destructor()
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
	__asm__("call %0\n\t" :: "m"(_func943::func));
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

namespace _func944
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextButton::GetSizeX", typeid(int64_t (TextButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c80b9b40000000075??8b83a80000008b93ac000000", argdata, 1, 1, &func);
}

__declspec(naked) int64_t TextButton::GetSizeX()
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
	__asm__("call %0\n\t" :: "m"(_func944::func));
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

namespace _func945
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextButton::OnInitRect", typeid(void (TextButton::*)(Globals::Rect &, int , TextString &, int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b378b47088b57048b4e0c8945b88b470c8955b4894c24048b4e08", argdata, 5, 5, &func);
}

__declspec(naked) void TextButton::OnInitRect(Globals::Rect &rect, int cornerInset, TextString &buttonLabel, int font)
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
		"push [ebp+20]\n\t"		// font
		"push [ebp+16]\n\t"		// buttonLabel
		"push [ebp+12]\n\t"		// cornerInset
		"push [ebp+8]\n\t"		// rect
	);
	__asm__("call %0\n\t" :: "m"(_func945::func));
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

namespace _func946
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextInput::constructor", typeid(void (TextInput::*)(int , TextInput::AllowedCharType , const std::string &)), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b078b4f088b57048945d48d43088b710489038b3989f901f174??85ff75??c70424????????e8????????83fe0f8975e40f87????????83fe010f84????????85f689c10f85????????8b45d4897304c60431008d4b44c7431800000000c7431c00000000c7432000000000", argdata, 4, 5, &func);
}

__declspec(naked) void TextInput::constructor(int maxChars, TextInput::AllowedCharType allowedCharType, const std::string &prompt)
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
		"push [ebp+16]\n\t"		// prompt
		"push [ebp+12]\n\t"		// allowedCharType
		"push [ebp+8]\n\t"		// maxChars
	);
	__asm__("call %0\n\t" :: "m"(_func946::func));
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

namespace _func947
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("TextInput::OnRender", typeid(void (TextInput::*)(int , Point )), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????8b07898564ffffff8b4704", argdata, 3, 5, &func);
}

__declspec(naked) void TextInput::OnRender(int font, Point pos)
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
		"push [ebp+16]\n\t"		// pos
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// font
	);
	__asm__("call %0\n\t" :: "m"(_func947::func));
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

namespace _func948
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextInput::OnLoop", typeid(void (TextInput::*)()), ".5589e5538b413083e4f039413474??c7414c000000008d5944", argdata, 1, 5, &func);
}

__declspec(naked) void TextInput::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func948::func));
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

namespace _func949
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TextInput::OnTextEvent", typeid(void (TextInput::*)(CEvent::TextEvent )), ".8079380074??5589e557565383e4f083ec20837d080877??", argdata, 2, 5, &func);
}

__declspec(naked) void TextInput::OnTextEvent(CEvent::TextEvent event)
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
		"push [ebp+8]\n\t"		// event
	);
	__asm__("call %0\n\t" :: "m"(_func949::func));
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

namespace _func950
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextInput::GetActive", typeid(bool (TextInput::*)()), ".0fb64138c3", argdata, 1, 1, &func);
}

__declspec(naked) bool TextInput::GetActive()
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
	__asm__("call %0\n\t" :: "m"(_func950::func));
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

namespace _func951
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TextInput::GetText", typeid(std::string &(*)(std::string &, TextInput *)), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b07c7442408ffffffffc744240400000000890424", argdata, 2, 0, &func);
}

__declspec(naked) std::string &TextInput::GetText(std::string &strRef, TextInput *textInput)
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
		"push [ebp+12]\n\t"		// textInput
		"mov ecx, [ebp+8]\n\t"	// strRef
	);
	__asm__("call %0\n\t" :: "m"(_func951::func));
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

namespace _func952
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextInput::Start", typeid(void (TextInput::*)()), ".578d7c240883e4f0ff77fc5589e5575383ec408b411c", argdata, 1, 5, &func);
}

__declspec(naked) void TextInput::Start()
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
	__asm__("call %0\n\t" :: "m"(_func952::func));
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

namespace _func953
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextInput::Stop", typeid(void (TextInput::*)()), ".55c641380089e583e4f0e8????????", argdata, 1, 5, &func);
}

__declspec(naked) void TextInput::Stop()
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
	__asm__("call %0\n\t" :: "m"(_func953::func));
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

namespace _func954
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TextInput::SetText", typeid(int (TextInput::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565389ce8d5de083ec2c", argdata, 2, 1, &func);
}

__declspec(naked) int TextInput::SetText(const std::string &text)
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
		"push [ebp+8]\n\t"		// text
	);
	__asm__("call %0\n\t" :: "m"(_func954::func));
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

namespace _func955
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TextInput::OnTextInput", typeid(void (TextInput::*)(int )), ".8079380074??578d7c240883e4f0ff77fc5589e557565383ec6c", argdata, 2, 5, &func);
}

__declspec(naked) void TextInput::OnTextInput(int asciiChar)
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
		"push [ebp+8]\n\t"		// asciiChar
	);
	__asm__("call %0\n\t" :: "m"(_func955::func));
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

namespace _func956
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextLibrary::GetText", typeid(std::string &(*)(std::string &, TextLibrary *, const std::string &, const std::string &)), "578d7c240883e4f0ff77fc5589e557565383ec4c8b07894dc889c18945bc8b47048b59208d511c", argdata, 4, 0, &func);
}

__declspec(naked) std::string &TextLibrary::GetText(std::string &strRef, TextLibrary *textLibrary, const std::string &name, const std::string &lang)
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
		"push [ebp+20]\n\t"		// lang
		"push [ebp+16]\n\t"		// name
		"push [ebp+12]\n\t"		// textLibrary
		"mov ecx, [ebp+8]\n\t"	// strRef
	);
	__asm__("call %0\n\t" :: "m"(_func956::func));
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

namespace _func957
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TextString::GetText", typeid(std::string &(*)(std::string &, TextString *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b17807a1800", argdata, 2, 0, &func);
}

__declspec(naked) std::string &TextString::GetText(std::string &ref, TextString *textString)
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
		"push [ebp+12]\n\t"		// textString
		"mov ecx, [ebp+8]\n\t"	// ref
	);
	__asm__("call %0\n\t" :: "m"(_func957::func));
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

namespace _func958
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TimerHelper::Start", typeid(void (TimerHelper::*)(int )), "5589e55653c6411101c741080000000083e4f0837d08ff74??660fefc0f30f2a4508f30f11410c", argdata, 2, 5, &func);
}

__declspec(naked) void TimerHelper::Start(int goal)
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
		"push [ebp+8]\n\t"		// goal
	);
	__asm__("call %0\n\t" :: "m"(_func958::func));
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

namespace _func959
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TimerHelper::Running", typeid(bool (TimerHelper::*)()), ".0fb64111", argdata, 1, 1, &func);
}

__declspec(naked) bool TimerHelper::Running()
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
	__asm__("call %0\n\t" :: "m"(_func959::func));
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

namespace _func960
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TimerHelper::ResetMinMax", typeid(void (TimerHelper::*)(int , int )), ".8b44240889018b442404894104", argdata, 3, 5, &func);
}

__declspec(naked) void TimerHelper::ResetMinMax(int min, int max)
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
		"push [ebp+12]\n\t"		// max
		"push [ebp+8]\n\t"		// min
	);
	__asm__("call %0\n\t" :: "m"(_func960::func));
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

namespace _func961
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TimerHelper::SetMaxTime", typeid(void (TimerHelper::*)(float )), ".f30f104108f30f5e410cf30f104c2404f30f11490cf30f59c1", argdata, 2, 5, &func);
}

__declspec(naked) void TimerHelper::SetMaxTime(float max)
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
		"push [ebp+8]\n\t"		// max
	);
	__asm__("call %0\n\t" :: "m"(_func961::func));
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

namespace _func962
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TimerHelper::Stop", typeid(void (TimerHelper::*)()), ".c6411100", argdata, 1, 5, &func);
}

__declspec(naked) void TimerHelper::Stop()
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
	__asm__("call %0\n\t" :: "m"(_func962::func));
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

namespace _func963
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TimerHelper::Update", typeid(void (TimerHelper::*)()), ".8079110075??c389f68dbc27000000005589e55389cbb9????????83e4f0", argdata, 1, 5, &func);
}

__declspec(naked) void TimerHelper::Update()
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
	__asm__("call %0\n\t" :: "m"(_func963::func));
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

namespace _func964
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TimerHelper::Done", typeid(bool (TimerHelper::*)()), ".0fb6411184c074??f30f1041080f2e410c76??5589e55756530fb6711083e4f0", argdata, 1, 1, &func);
}

__declspec(naked) bool TimerHelper::Done()
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
	__asm__("call %0\n\t" :: "m"(_func964::func));
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

namespace _func965
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TopScore::copy_constructor", typeid(void (TopScore::*)(const TopScore &)), "578d41088d7c240883e4f0ff77fc5589e557565389cb83ec3c8b3789018b16", argdata, 2, 5, &func);
}

__declspec(naked) void TopScore::copy_constructor(const TopScore &other)
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
	__asm__("call %0\n\t" :: "m"(_func965::func));
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

namespace _func966
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TutorialManager::constructor", typeid(void (TutorialManager::*)()), "578d7c240883e4f0ff77fc5589e5575389cb8d490483ec20c641fc00e8????????8d8300010000", argdata, 1, 5, &func);
}

__declspec(naked) void TutorialManager::constructor()
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
	__asm__("call %0\n\t" :: "m"(_func966::func));
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

namespace _func967
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TutorialManager::Running", typeid(bool (TutorialManager::*)()), ".0fb601", argdata, 1, 1, &func);
}

__declspec(naked) bool TutorialManager::Running()
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
	__asm__("call %0\n\t" :: "m"(_func967::func));
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

namespace _func968
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TutorialManager::OnInit", typeid(void (TutorialManager::*)(ShipManager *, CommandGui *, CrewControl *, Upgrades *, CombatControl *, SystemControl *, TabbedWindow *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec7c8b470c8b378b4f048b5708c745b412000000", argdata, 8, 5, &func);
}

__declspec(naked) void TutorialManager::OnInit(ShipManager *ship, CommandGui *gui, CrewControl *crewControl, Upgrades *upgradesScreen, CombatControl *combatControl, SystemControl *sysControl, TabbedWindow *unk)
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
		"push [ebp+32]\n\t"		// unk
		"push [ebp+28]\n\t"		// sysControl
		"push [ebp+24]\n\t"		// combatControl
		"push [ebp+20]\n\t"		// upgradesScreen
		"push [ebp+16]\n\t"		// crewControl
		"push [ebp+12]\n\t"		// gui
		"push [ebp+8]\n\t"		// ship
	);
	__asm__("call %0\n\t" :: "m"(_func968::func));
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
		"ret 28\n\t"
	);
}

namespace _func969
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("UnlockArrow::constructor", typeid(void (UnlockArrow::*)(Point , int , int )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec4c8b10803d??????????8b4808c74708ffffffffc7470cffffffffc74710000000008955c4", argdata, 4, 5, &func);
}

__declspec(naked) void UnlockArrow::constructor(Point pos, int unk1, int unk2)
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
		"push [ebp+20]\n\t"		// unk2
		"push [ebp+16]\n\t"		// unk1
		"push [ebp+12]\n\t"		// pos
		"push [ebp+8]\n\t"		// pos
	);
	__asm__("call %0\n\t" :: "m"(_func969::func));
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

namespace _func970
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("UnlockArrow::MouseMove", typeid(bool (UnlockArrow::*)(int , int )), ".8379040374??8b510831c0395424047e??035110395424047d??8b510c395424087e??", argdata, 3, 1, &func);
}

__declspec(naked) bool UnlockArrow::MouseMove(int x, int y)
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
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func970::func));
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

namespace _func971
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("UnlockArrow::OnRender", typeid(void (UnlockArrow::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83ec6c8b0185c0", argdata, 1, 5, &func);
}

__declspec(naked) void UnlockArrow::OnRender()
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
	__asm__("call %0\n\t" :: "m"(_func971::func));
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

namespace _func972
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WarningMessage::Start", typeid(void (WarningMessage::*)()), "8079140075??578d7c240883e4f0ff77fc5589e5575389cb", argdata, 1, 5, &func);
}

__declspec(naked) void WarningMessage::Start()
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
	__asm__("call %0\n\t" :: "m"(_func972::func));
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

namespace _func973
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WarningMessage::OnRender", typeid(void (WarningMessage::*)()), "807916000f85????????807914000f84????????578d7c240883e4f0ff77fc5589e55753", argdata, 1, 5, &func);
}

__declspec(naked) void WarningMessage::OnRender()
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
	__asm__("call %0\n\t" :: "m"(_func973::func));
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

namespace _func974
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("WeaponBlueprint::__DO_NOT_HOOK", typeid(void (*)()), "5589e55389cb83e4f083ec108b81c4000000c701????????85c074??890424e8????????8b83a00000008d93a8000000c703????????39d0", argdata, 0, 4, &func);
}

__declspec(naked) void WeaponBlueprint::__DO_NOT_HOOK()
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
	__asm__("call %0\n\t" :: "m"(_func974::func));
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

namespace _func975
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponBlueprint::constructor", typeid(void (WeaponBlueprint::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb8d4904", argdata, 1, 5, &func);
}

__declspec(naked) void WeaponBlueprint::constructor()
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
	__asm__("call %0\n\t" :: "m"(_func975::func));
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

namespace _func976
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponBlueprint::destructor", typeid(void (WeaponBlueprint::*)()), "558d91e401000089e557565389ce83e4f083ec108b81dc010000c701????????39d074??890424e8????????8bbebc0100008b9eb801000039df74??", argdata, 1, 5, &func);
}

__declspec(naked) void WeaponBlueprint::destructor()
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
	__asm__("call %0\n\t" :: "m"(_func976::func));
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

namespace _func977
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponBlueprint::GetDescription", typeid(void (*)(std::string &, WeaponBlueprint *, bool )), "578d7c240883e4f0ff77fc5589f889e557565381ec????????8b40048b3f898da8feffff89c6", argdata, 3, 4, &func);
}

__declspec(naked) void WeaponBlueprint::GetDescription(std::string &strRef, WeaponBlueprint *_this, bool tooltip)
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
		"push [ebp+16]\n\t"		// tooltip
		"push [ebp+12]\n\t"		// _this
		"mov ecx, [ebp+8]\n\t"	// strRef
	);
	__asm__("call %0\n\t" :: "m"(_func977::func));
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

namespace _func978
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
	__asm__("call %0\n\t" :: "m"(_func978::func));
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

namespace _func979
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponControl::OnRender", typeid(void (WeaponControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b490c8b37c70424????????e8????????83ec0484c00f84????????", argdata, 1, 5, &func);
}

__declspec(naked) void WeaponControl::OnRender()
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
	__asm__("call %0\n\t" :: "m"(_func979::func));
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

namespace _func980
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::LButton", typeid(void (WeaponControl::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565383ec2c80b9d8000000008b1f8b77048b570874??0fb681d900000084c0", argdata, 3, 5, &func);
}

__declspec(naked) void WeaponControl::LButton(int x, int y)
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
	__asm__("call %0\n\t" :: "m"(_func980::func));
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

namespace _func981
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::MouseMove", typeid(void (WeaponControl::*)(int , int )), ".578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b378b7f04893424897c2404", argdata, 3, 5, &func);
}

__declspec(naked) void WeaponControl::MouseMove(int x, int y)
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
	__asm__("call %0\n\t" :: "m"(_func981::func));
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

namespace _func982
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::LinkShip", typeid(void (WeaponControl::*)(ShipManager *)), ".578d7c240883e4f0ff77fc5589e5575389cb83ec108b07890424e8????????8b0383ec04", argdata, 2, 5, &func);
}

__declspec(naked) void WeaponControl::LinkShip(ShipManager *ship)
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
	__asm__("call %0\n\t" :: "m"(_func982::func));
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

namespace _func983
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponControl::constructor", typeid(void (WeaponControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cf8db518feffff81ec????????898d10fdffffc70424????????e8????????8d8f9800000083ec04c707????????c7878c00000000000000c7879000000000000000", argdata, 1, 5, &func);
}

__declspec(naked) void WeaponControl::constructor()
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
	__asm__("call %0\n\t" :: "m"(_func983::func));
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

namespace _func984
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::SetAutofiring", typeid(void (WeaponControl::*)(bool , bool )), "578d7c240883e4f0ff77fc5589e557565389ce83ec5c8b078b7f04f30f101d????????84c08881940000000f84????????f30f1005????????f30f100d????????", argdata, 3, 5, &func);
}

__declspec(naked) void WeaponControl::SetAutofiring(bool on, bool simple)
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
		"push [ebp+12]\n\t"		// simple
		"push [ebp+8]\n\t"		// on
	);
	__asm__("call %0\n\t" :: "m"(_func984::func));
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

namespace _func985
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::KeyDown", typeid(void (WeaponControl::*)(SDLKey )), "578d7c240883e4f0ff77fc5589e557565389ce83ec4c8b3f893c24e8????????83ec0484c0", argdata, 2, 5, &func);
}

__declspec(naked) void WeaponControl::KeyDown(SDLKey key)
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
	__asm__("call %0\n\t" :: "m"(_func985::func));
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

namespace _func986
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponSystem::RemoveWeapon", typeid(void (WeaponSystem::*)(int )), "578d7c240883e4f0ff77fc5589e557565383ec4c8b3f85ff78??", argdata, 2, 5, &func);
}

__declspec(naked) void WeaponSystem::RemoveWeapon(int slot)
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
		"push [ebp+8]\n\t"		// slot
	);
	__asm__("call %0\n\t" :: "m"(_func986::func));
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

namespace _func987
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponSystem::SetBonusPower", typeid(void (WeaponSystem::*)(int , int )), "5589e556538b750889cb83e4f0e8????????39f089d90f4fc6", argdata, 3, 5, &func);
}

__declspec(naked) void WeaponSystem::SetBonusPower(int amount, int permanentPower)
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
		"push [ebp+12]\n\t"		// permanentPower
		"push [ebp+8]\n\t"		// amount
	);
	__asm__("call %0\n\t" :: "m"(_func987::func));
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

namespace _func988
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WindowFrame::Draw", typeid(void (WindowFrame::*)(int , int )), "5589e55389cb83e4f083ec10e8????????660fefc0c744240800000000f30f2a450cf30f11442404", argdata, 3, 5, &func);
}

__declspec(naked) void WindowFrame::Draw(int x, int y)
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
	__asm__("call %0\n\t" :: "m"(_func988::func));
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

namespace _func989
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WindowFrame::DrawMask", typeid(void (WindowFrame::*)(int )), "5589e55389cb83e4f083ec108b4508c70424????????8944240889442404e8????????8b4314890424e8????????", argdata, 2, 5, &func);
}

__declspec(naked) void WindowFrame::DrawMask(int unk)
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
	__asm__("call %0\n\t" :: "m"(_func989::func));
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

namespace _func990
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WindowFrame::constructor", typeid(void (WindowFrame::*)(int , int , int , int )), "578d7c240883e4f0ff77fc5589e55756538d5dd081ec????????8b77048b07898d58ffffff895dc8c745d077696e64c745d46f775f628975a0", argdata, 5, 5, &func);
}

__declspec(naked) void WindowFrame::constructor(int x, int y, int w, int h)
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
		"push [ebp+20]\n\t"		// h
		"push [ebp+16]\n\t"		// w
		"push [ebp+12]\n\t"		// y
		"push [ebp+8]\n\t"		// x
	);
	__asm__("call %0\n\t" :: "m"(_func990::func));
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

namespace _func991
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WindowFrame::destructor", typeid(void (WindowFrame::*)()), "5589e55389cb83e4f083ec108b4110890424e8????????8b4314890424e8????????8b4318890424e8????????8b5dfc", argdata, 1, 5, &func);
}

__declspec(naked) void WindowFrame::destructor()
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
	__asm__("call %0\n\t" :: "m"(_func991::func));
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

namespace _func992
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
	__asm__("call %0\n\t" :: "m"(_func992::func));
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

namespace _func993
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
	__asm__("call %0\n\t" :: "m"(_func993::func));
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

namespace _func994
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
	__asm__("call %0\n\t" :: "m"(_func994::func));
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

namespace _func995
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CreateLocation", typeid(void (WorldManager::*)(Location *)), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????898d54fbffffc6814612000000b9????????8b3f", argdata, 2, 5, &func);
}

__declspec(naked) void WorldManager::CreateLocation(Location *loc)
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
		"push [ebp+8]\n\t"		// loc
	);
	__asm__("call %0\n\t" :: "m"(_func995::func));
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

namespace _func996
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::SaveGame", typeid(void (WorldManager::*)()), "578d7c240883e4f0ff77fc5589e557565389cf83ec3c8b89e40d0000e8????????84c074??8d65f45b5e5f5d", argdata, 1, 5, &func);
}

__declspec(naked) void WorldManager::SaveGame()
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
	__asm__("call %0\n\t" :: "m"(_func996::func));
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

namespace _func997
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CreateChoiceBox", typeid(void (WorldManager::*)(LocationEvent *)), "5789c805????????8d7c240883e4f0ff77fc5589e557565389cb89c681ec????????8b3f", argdata, 2, 5, &func);
}

__declspec(naked) void WorldManager::CreateChoiceBox(LocationEvent *event)
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
		"push [ebp+8]\n\t"		// event
	);
	__asm__("call %0\n\t" :: "m"(_func997::func));
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

namespace _func998
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::UpdateLocation", typeid(void (WorldManager::*)(LocationEvent *)), "578d7c240883e4f0ff77fc5589e557565381ec????????8b3f898d70fbffff807f1c000f85????????8d85bcfbffff89ce898568fbffff8d85c4fbffff898564fbffff8d874406000089f1890424", argdata, 2, 5, &func);
}

__declspec(naked) void WorldManager::UpdateLocation(LocationEvent *event)
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
		"push [ebp+8]\n\t"		// event
	);
	__asm__("call %0\n\t" :: "m"(_func998::func));
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

namespace _func999
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::ModifyResources", typeid(LocationEvent *(WorldManager::*)(LocationEvent *)), "578d7c240883e4f0ff77fc5589e557565389ce8d8d2cfeffff81ec????????8b078985d8fcffff", argdata, 2, 1, &func);
}

__declspec(naked) LocationEvent *WorldManager::ModifyResources(LocationEvent *event)
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
		"push [ebp+8]\n\t"		// event
	);
	__asm__("call %0\n\t" :: "m"(_func999::func));
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

namespace _func1000
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::ModifyEnvironment", typeid(void (WorldManager::*)(int , int )), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b078b570483f801", argdata, 3, 5, &func);
}

__declspec(naked) void WorldManager::ModifyEnvironment(int envFlag, int envTarget)
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
		"push [ebp+12]\n\t"		// envTarget
		"push [ebp+8]\n\t"		// envFlag
	);
	__asm__("call %0\n\t" :: "m"(_func1000::func));
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

namespace _func1001
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CheckStatusEffects", typeid(void (WorldManager::*)(std::vector<StatusEffect> &)), "5789ca81c2????????8d7c240883e4f0ff77fc5589e5575653", argdata, 2, 5, &func);
}

__declspec(naked) void WorldManager::CheckStatusEffects(std::vector<StatusEffect> &vec)
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
		"push [ebp+8]\n\t"		// vec
	);
	__asm__("call %0\n\t" :: "m"(_func1001::func));
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

namespace _func1002
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::StartGame", typeid(void (WorldManager::*)(ShipManager *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b098b3785c9", argdata, 2, 5, &func);
}

__declspec(naked) void WorldManager::StartGame(ShipManager *ship)
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
	__asm__("call %0\n\t" :: "m"(_func1002::func));
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

namespace _func1003
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::Restart", typeid(void (WorldManager::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb83ec10e8????????e8????????", argdata, 1, 5, &func);
}

__declspec(naked) void WorldManager::Restart()
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
	__asm__("call %0\n\t" :: "m"(_func1003::func));
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

namespace _func1004
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::LoadGame", typeid(void (WorldManager::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565389cb8db51cfeffff81ec????????8b07c7852cfeffff00000000c78530feffff00000000c78534feffff00000000c78538feffff00000000c7853cfeffff00000000", argdata, 2, 5, &func);
}

__declspec(naked) void WorldManager::LoadGame(const std::string &fileName)
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
		"push [ebp+8]\n\t"		// fileName
	);
	__asm__("call %0\n\t" :: "m"(_func1004::func));
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

namespace _func1005
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::OnLoop", typeid(void (WorldManager::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????c70424????????e8????????83ec0484c074??8d65f45b5e5f5d8d67f85f", argdata, 1, 5, &func);
}

__declspec(naked) void WorldManager::OnLoop()
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
	__asm__("call %0\n\t" :: "m"(_func1005::func));
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

namespace _func1006
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::CreateNewGame", typeid(void (WorldManager::*)()), "578d7c240883e4f0ff77fc5589e557565389ce8d5dd88d7dd083ec3c8b018b480881c1????????e8????????8b068b5008895dd08b8aa4060000", argdata, 1, 5, &func);
}

__declspec(naked) void WorldManager::CreateNewGame()
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
	__asm__("call %0\n\t" :: "m"(_func1006::func));
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

namespace _func1007
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::HostileEnvironment", typeid(bool (WorldManager::*)()), "5589e55389cb83c10883e4f0e8????????84c075??8b038b4808b8????????8b91f007000085d274??", argdata, 1, 1, &func);
}

__declspec(naked) bool WorldManager::HostileEnvironment()
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
	__asm__("call %0\n\t" :: "m"(_func1007::func));
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

