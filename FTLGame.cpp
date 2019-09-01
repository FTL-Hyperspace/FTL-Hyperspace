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
	static FunctionDefinition funcObj("AchievementTracker::GetShipAchievements", typeid(void *(*)(void *, AchievementTracker *, std::string &)), "578d7c240883e4f0ff77fc5589f889e557565383ec5c8b40048b3f894db4c744240802000000c744240400000000", argdata, 3, 0, &func);
}

__declspec(naked) void *AchievementTracker::GetShipAchievements(void *unk, AchievementTracker *tracker, std::string &name)
{
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
		"ret 24\n\t"
	);
}

namespace _func3
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
		"ret\n\t"
	);
}

namespace _func4
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::GetAlphaLevel", typeid(float (AnimationTracker::*)(bool )), "5589e583ec04f30f1005????????f30f1015????????807d0800f30f594104f30f10490cf30f5cc80f28d8", argdata, 2, 1, &func);
}

__declspec(naked) float AnimationTracker::GetAlphaLevel(bool unk)
{
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
		"ret 4\n\t"
	);
}

namespace _func5
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
		"ret 12\n\t"
	);
}

namespace _func7
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
	__asm__("call %0\n\t" :: "m"(_func8::func));
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

namespace _func9
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
		"ret\n\t"
	);
}

namespace _func10
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
		"ret\n\t"
	);
}

namespace _func12
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
		"ret 4\n\t"
	);
}

namespace _func13
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
		"ret 12\n\t"
	);
}

namespace _func15
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetShipBlueprint", typeid(ShipBlueprint *(BlueprintManager::*)(std::string &, int )), "578d7c240883e4f0ff77fc5589e55756538d45d883ec5c8b1f8945d08b77048d7dd0894db48b038b5304", argdata, 3, 1, &func);
}

__declspec(naked) ShipBlueprint *BlueprintManager::GetShipBlueprint(std::string &name, int unk)
{
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
		"push [ebp+8]\n\t"		// name
	);
	__asm__("call %0\n\t" :: "m"(_func15::func));
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

namespace _func16
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
		"ret\n\t"
	);
}

namespace _func17
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
		"ret 4\n\t"
	);
}

namespace _func21
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
	__asm__("call %0\n\t" :: "m"(_func21::func));
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

namespace _func22
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
	__asm__("call %0\n\t" :: "m"(_func22::func));
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

namespace _func23
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
		"ret\n\t"
	);
}

namespace _func25
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
	__asm__("call %0\n\t" :: "m"(_func25::func));
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

namespace _func26
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
		"ret\n\t"
	);
}

namespace _func27
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("Button::SetLocation", typeid(void (Button::*)(Point )), "578d7c240883e4f0ff77fc5589e55783ec148b078b570489042489542404e8????????8b7dfc83ec08c98d67f85fc20800909090909090909090909090909090f3c39090909090909090909090909090c20800", argdata, 2, 5, &func);
}

__declspec(naked) void Button::SetLocation(Point pos)
{
	__asm__
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
	static short argdata[] = {0x101, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Button::OnInit", typeid(void (Button::*)(std::string &, Point )), "578d7c240883e4f0ff77fc5589e55756538d55a881ec????????8b47048b1f894d948955a08945908b47088b3b", argdata, 3, 5, &func);
}

__declspec(naked) void Button::OnInit(std::string &img, Point pos)
{
	__asm__
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
		"push [ebp+8]\n\t"		// img
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
		"ret 12\n\t"
	);
}

namespace _func29
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
		"ret\n\t"
	);
}

namespace _func31
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
		"ret 16\n\t"
	);
}

namespace _func32
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
	__asm__("call %0\n\t" :: "m"(_func32::func));
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

namespace _func33
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
		"ret\n\t"
	);
}

namespace _func34
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
	__asm__("call %0\n\t" :: "m"(_func34::func));
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

namespace _func35
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
	__asm__("call %0\n\t" :: "m"(_func35::func));
	__asm__
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

namespace _func36
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
		"ret 4\n\t"
	);
}

namespace _func37
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
		"ret 4\n\t"
	);
}

namespace _func38
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
	__asm__("call %0\n\t" :: "m"(_func38::func));
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

namespace _func39
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
		"ret 28\n\t"
	);
}

namespace _func40
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
		"ret 8\n\t"
	);
}

namespace _func41
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
		"ret 8\n\t"
	);
}

namespace _func42
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
		"ret 8\n\t"
	);
}

namespace _func43
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
		"ret 8\n\t"
	);
}

namespace _func44
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
	__asm__("call %0\n\t" :: "m"(_func44::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func45
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
	__asm__("call %0\n\t" :: "m"(_func45::func));
	__asm__
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

namespace _func46
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
	__asm__("call %0\n\t" :: "m"(_func46::func));
	__asm__
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

namespace _func47
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
	__asm__("call %0\n\t" :: "m"(_func47::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func48
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
		"ret 8\n\t"
	);
}

namespace _func49
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
	__asm__("call %0\n\t" :: "m"(_func49::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
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
	__asm__("call %0\n\t" :: "m"(_func51::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func52
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
		"ret\n\t"
	);
}

namespace _func53
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
	__asm__("call %0\n\t" :: "m"(_func53::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func54
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
	__asm__("call %0\n\t" :: "m"(_func54::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func55
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
		"ret 12\n\t"
	);
}

namespace _func56
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
		"ret\n\t"
	);
}

namespace _func57
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
	__asm__("call %0\n\t" :: "m"(_func57::func));
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

namespace _func58
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
		"ret\n\t"
	);
}

namespace _func59
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
	__asm__("call %0\n\t" :: "m"(_func59::func));
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

namespace _func60
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
	__asm__("call %0\n\t" :: "m"(_func60::func));
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

namespace _func61
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
	__asm__("call %0\n\t" :: "m"(_func63::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
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
	__asm__("call %0\n\t" :: "m"(_func64::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
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
		"ret\n\t"
	);
}

namespace _func66
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
		"ret\n\t"
	);
}

namespace _func68
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
		"ret 4\n\t"
	);
}

namespace _func69
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
	__asm__("call %0\n\t" :: "m"(_func69::func));
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

namespace _func70
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
		"ret 12\n\t"
	);
}

namespace _func71
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
		"ret\n\t"
	);
}

namespace _func72
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
		"ret 12\n\t"
	);
}

namespace _func74
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
		"ret 8\n\t"
	);
}

namespace _func76
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
		"ret 12\n\t"
	);
}

namespace _func77
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
	__asm__("call %0\n\t" :: "m"(_func77::func));
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

namespace _func78
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
	__asm__("call %0\n\t" :: "m"(_func78::func));
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

namespace _func79
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
		"ret 8\n\t"
	);
}

namespace _func80
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
		"ret 8\n\t"
	);
}

namespace _func81
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
		"ret 4\n\t"
	);
}

namespace _func82
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
		"ret 8\n\t"
	);
}

namespace _func84
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
		"ret\n\t"
	);
}

namespace _func85
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
		"ret\n\t"
	);
}

namespace _func86
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
		"ret\n\t"
	);
}

namespace _func87
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
	__asm__("call %0\n\t" :: "m"(_func87::func));
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

namespace _func88
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
	__asm__("call %0\n\t" :: "m"(_func88::func));
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

namespace _func89
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
		"ret 4\n\t"
	);
}

namespace _func90
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
	__asm__("call %0\n\t" :: "m"(_func90::func));
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

namespace _func91
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
		"ret 12\n\t"
	);
}

namespace _func92
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
		"ret\n\t"
	);
}

namespace _func93
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
		"ret\n\t"
	);
}

namespace _func94
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
		"ret 8\n\t"
	);
}

namespace _func95
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
		"ret\n\t"
	);
}

namespace _func96
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::constructor", typeid(void (CrewAnimation::*)(int , std::string &, Pointf , char )), "578d7c240883e4f0ff77fc5589e557565381ec????????8b57048b078b5f088b770c894da0", argdata, 5, 5, &func);
}

__declspec(naked) void CrewAnimation::constructor(int shipId, std::string &race, Pointf unk, char hostile)
{
	__asm__
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
		"ret 20\n\t"
	);
}

namespace _func97
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
	__asm__("call %0\n\t" :: "m"(_func97::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func98
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
		"ret 16\n\t"
	);
}

namespace _func99
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ShipDamage", typeid(bool (CrewMember::*)(float )), "578d7c240883e4f0ff77fc5589e55783ec14f30f1007f30f110424e8????????8b7dfc83ec04", argdata, 2, 1, &func);
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
	__asm__("call %0\n\t" :: "m"(_func99::func));
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

namespace _func100
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
	__asm__("call %0\n\t" :: "m"(_func100::func));
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

namespace _func101
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
	__asm__("call %0\n\t" :: "m"(_func101::func));
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

namespace _func102
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
		"ret\n\t"
	);
}

namespace _func103
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
	__asm__("call %0\n\t" :: "m"(_func103::func));
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

namespace _func104
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
	__asm__("call %0\n\t" :: "m"(_func104::func));
	__asm__
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

namespace _func105
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Jump", typeid(void (CrewMember::*)()), "8b81f00400005589e583e4f083400c018b01ff90cc000000", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::Jump()
{
	__asm__
	(
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
	__asm__("call %0\n\t" :: "m"(_func108::func));
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

namespace _func109
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::OnRender", typeid(void (CrewMember::*)()), ".660fefc9f30f1015????????f30f10410855f30f2a8990000000", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::OnRender()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
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
		"ret\n\t"
	);
}

namespace _func110
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SaveState", typeid(void (CrewMember::*)(int )), ".578d7c240883e4f0ff77fc55", argdata, 2, 5, &func);
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
		"ret 4\n\t"
	);
}

namespace _func111
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
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::LoadState", typeid(void (CrewMember::*)(int )), ".578d7c240883e4f0ff77fc5589f8", argdata, 2, 5, &func);
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
	__asm__("call %0\n\t" :: "m"(_func115::func));
	__asm__
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

namespace _func116
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
		"ret 4\n\t"
	);
}

namespace _func118
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
		"ret\n\t"
	);
}

namespace _func119
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
		"ret 4\n\t"
	);
}

namespace _func120
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
		"ret 4\n\t"
	);
}

namespace _func122
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
		"ret\n\t"
	);
}

namespace _func123
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
		"ret 8\n\t"
	);
}

namespace _func124
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
		"ret 4\n\t"
	);
}

namespace _func126
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
		"ret\n\t"
	);
}

namespace _func128
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
	__asm__("call %0\n\t" :: "m"(_func128::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func129
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
		"ret\n\t"
	);
}

namespace _func130
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
		"ret 4\n\t"
	);
}

namespace _func131
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
		"ret 4\n\t"
	);
}

namespace _func132
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
		"ret 4\n\t"
	);
}

namespace _func133
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
		"ret\n\t"
	);
}

namespace _func134
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
		"ret\n\t"
	);
}

namespace _func135
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
		"ret\n\t"
	);
}

namespace _func136
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
		"ret\n\t"
	);
}

namespace _func137
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
	static FunctionDefinition funcObj("CrewMember::GetSavedPosition", typeid(Slot *(CrewMember::*)()), ".8b54240489c88b8af806000089088b8afc060000894804", argdata, 1, 1, &func);
}

__declspec(naked) Slot *CrewMember::GetSavedPosition()
{
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
		"ret 16\n\t"
	);
}

namespace _func141
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
	__asm__("call %0\n\t" :: "m"(_func142::func));
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

namespace _func143
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
		"ret 4\n\t"
	);
}

namespace _func145
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
		"ret 12\n\t"
	);
}

namespace _func147
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
		"ret 4\n\t"
	);
}

namespace _func148
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
	__asm__("call %0\n\t" :: "m"(_func148::func));
	__asm__
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

namespace _func149
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
	__asm__("call %0\n\t" :: "m"(_func149::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func150
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
	__asm__("call %0\n\t" :: "m"(_func150::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func151
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
		"ret\n\t"
	);
}

namespace _func153
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
		"ret\n\t"
	);
}

namespace _func154
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
		"ret\n\t"
	);
}

namespace _func155
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
	__asm__("call %0\n\t" :: "m"(_func159::func));
	__asm__
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

namespace _func160
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
		"ret 4\n\t"
	);
}

namespace _func161
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
		"ret 4\n\t"
	);
}

namespace _func163
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
		"ret\n\t"
	);
}

namespace _func164
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
	__asm__("call %0\n\t" :: "m"(_func164::func));
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

namespace _func165
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
		"ret 4\n\t"
	);
}

namespace _func166
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
		"ret\n\t"
	);
}

namespace _func167
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
		"ret 4\n\t"
	);
}

namespace _func168
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
		"ret 4\n\t"
	);
}

namespace _func169
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
	static FunctionDefinition funcObj("CrewMember::UpdateHealth", typeid(bool (CrewMember::*)()), ".578d7c240883e4f0ff77fc55", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::UpdateHealth()
{
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
	__asm__("call %0\n\t" :: "m"(_func171::func));
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

namespace _func172
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
	__asm__("call %0\n\t" :: "m"(_func173::func));
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

namespace _func174
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
	__asm__("call %0\n\t" :: "m"(_func174::func));
	__asm__
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

namespace _func175
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
	__asm__("call %0\n\t" :: "m"(_func175::func));
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

namespace _func176
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
	__asm__("call %0\n\t" :: "m"(_func176::func));
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

namespace _func177
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
		"ret\n\t"
	);
}

namespace _func178
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
		"ret\n\t"
	);
}

namespace _func180
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
	__asm__("call %0\n\t" :: "m"(_func180::func));
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

namespace _func181
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
	__asm__("call %0\n\t" :: "m"(_func181::func));
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

namespace _func182
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
	__asm__("call %0\n\t" :: "m"(_func182::func));
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

namespace _func183
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x9ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetName", typeid(void (CrewMember::*)(TextString , bool )), ".578d7c240883e4f0ff77fc5589e55756", argdata, 3, 5, &func);
}

__declspec(naked) void CrewMember::SetName(TextString name, bool unk)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+44]\n\t"		// unk
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
		"ret 40\n\t"
	);
}

namespace _func184
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
	__asm__("call %0\n\t" :: "m"(_func184::func));
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

namespace _func185
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
	__asm__("call %0\n\t" :: "m"(_func185::func));
	__asm__
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

namespace _func186
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
	__asm__("call %0\n\t" :: "m"(_func186::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func187
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
	__asm__("call %0\n\t" :: "m"(_func187::func));
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

namespace _func188
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::MoveToRoom", typeid(bool (CrewMember::*)(int , int , bool )), ".578d7c240883e4f0ff77fc5589e55756", argdata, 4, 1, &func);
}

__declspec(naked) bool CrewMember::MoveToRoom(int roomId, int slotId, bool unk)
{
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
		"push [ebp+12]\n\t"		// slotId
		"push [ebp+8]\n\t"		// roomId
	);
	__asm__("call %0\n\t" :: "m"(_func188::func));
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

namespace _func189
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
		"ret 4\n\t"
	);
}

namespace _func190
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
	__asm__("call %0\n\t" :: "m"(_func190::func));
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

namespace _func191
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
	__asm__("call %0\n\t" :: "m"(_func191::func));
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

namespace _func192
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
		"ret 4\n\t"
	);
}

namespace _func193
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
	__asm__("call %0\n\t" :: "m"(_func193::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
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
	__asm__("call %0\n\t" :: "m"(_func194::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
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
		"ret\n\t"
	);
}

namespace _func197
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
		"ret\n\t"
	);
}

namespace _func198
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
		"ret 4\n\t"
	);
}

namespace _func200
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
		"ret 4\n\t"
	);
}

namespace _func201
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
		"ret\n\t"
	);
}

namespace _func202
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
	__asm__("call %0\n\t" :: "m"(_func202::func));
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

namespace _func203
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
	__asm__("call %0\n\t" :: "m"(_func205::func));
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

namespace _func206
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
	__asm__("call %0\n\t" :: "m"(_func206::func));
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

namespace _func207
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
	__asm__("call %0\n\t" :: "m"(_func207::func));
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

namespace _func208
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
	__asm__("call %0\n\t" :: "m"(_func208::func));
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

namespace _func209
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
	__asm__("call %0\n\t" :: "m"(_func209::func));
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

namespace _func210
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::IsRace", typeid(bool (*)(std::string &)), ".8d4c240483e4f0ff71fc5589e5", argdata, 1, 2, &func);
}

__declspec(naked) bool CrewMemberFactory::IsRace(std::string &species)
{
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
	__asm__("call %0\n\t" :: "m"(_func210::func));
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

namespace _func211
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetRandomFriendlyName", typeid(std::pair<std::string, bool> &(CrewMemberFactory::*)(std::string &)), ".578d7c240883e4f0ff77fc5589e5", argdata, 2, 1, &func);
}

__declspec(naked) std::pair<std::string, bool> &CrewMemberFactory::GetRandomFriendlyName(std::string &unk)
{
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
	__asm__("call %0\n\t" :: "m"(_func211::func));
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

namespace _func212
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
	__asm__("call %0\n\t" :: "m"(_func212::func));
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

namespace _func213
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
	__asm__("call %0\n\t" :: "m"(_func213::func));
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

namespace _func214
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewPortraitList", typeid(void (CrewMemberFactory::*)(std::vector<CrewMember*> &, int )), ".578d7c240883e4f0ff77fc5589f889e55756", argdata, 3, 5, &func);
}

__declspec(naked) void CrewMemberFactory::GetCrewPortraitList(std::vector<CrewMember*> &vec, int unk)
{
	__asm__
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
	__asm__("call %0\n\t" :: "m"(_func214::func));
	__asm__
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

namespace _func215
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
		"ret 8\n\t"
	);
}

namespace _func216
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
	__asm__("call %0\n\t" :: "m"(_func216::func));
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

namespace _func217
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewList", typeid(void (CrewMemberFactory::*)(std::vector<CrewMember*> &, int , bool )), ".578d7c240883e4f0ff77fc5589e557", argdata, 4, 5, &func);
}

__declspec(naked) void CrewMemberFactory::GetCrewList(std::vector<CrewMember*> &vec, int unk, bool unk2)
{
	__asm__
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
		"ret 12\n\t"
	);
}

namespace _func218
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::CreateBoarderDrone", typeid(void (CrewMemberFactory::*)(int , const DroneBlueprint *)), ".578d7c240883e4f0ff77fc5589e5", argdata, 3, 5, &func);
}

__declspec(naked) void CrewMemberFactory::CreateBoarderDrone(int shipId, const DroneBlueprint *bp)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+12]\n\t"		// bp
		"push [ebp+8]\n\t"		// shipId
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
		"ret 8\n\t"
	);
}

namespace _func219
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
	__asm__("call %0\n\t" :: "m"(_func219::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func220
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
		"ret\n\t"
	);
}

namespace _func221
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
	__asm__("call %0\n\t" :: "m"(_func221::func));
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

namespace _func222
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrystalAlien::constructor", typeid(void (CrystalAlien::*)(const CrewBlueprint &, int , bool )), "578d7c240883e4f0ff77fc5589e557565389ce8d4dc0", argdata, 4, 5, &func);
}

__declspec(naked) void CrystalAlien::constructor(const CrewBlueprint &bp, int shipId, bool intruder)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+16]\n\t"		// intruder
		"push [ebp+12]\n\t"		// shipId
		"push [ebp+8]\n\t"		// bp
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
		"ret 12\n\t"
	);
}

namespace _func223
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
	__asm__("call %0\n\t" :: "m"(_func223::func));
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

namespace _func224
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
	__asm__("call %0\n\t" :: "m"(_func224::func));
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

namespace _func225
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
	__asm__("call %0\n\t" :: "m"(_func225::func));
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

namespace _func226
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_Rotate2", typeid(void (*)(float , float , float , float )), "5589e55653bb????????83e4f081ec????????8d44243cf30f110424f30f105d08894424088d442438f30f114c2424f30f1154242889442404f30f115c242ce8????????660fefe4", argdata, 4, 6, &func);
}

__declspec(naked) void CSurface::GL_Rotate2(float unk1, float unk2, float unk3, float unk4)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+20]\n\t"		// unk4
		"push [ebp+16]\n\t"		// unk3
		"push [ebp+12]\n\t"		// unk2
		"push [ebp+8]\n\t"		// unk1
	);
	__asm__("call %0\n\t" :: "m"(_func226::func));
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

namespace _func227
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
	__asm__("call %0\n\t" :: "m"(_func227::func));
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

namespace _func228
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
	__asm__("call %0\n\t" :: "m"(_func228::func));
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

namespace _func229
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
	__asm__("call %0\n\t" :: "m"(_func229::func));
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

namespace _func230
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
	__asm__("call %0\n\t" :: "m"(_func230::func));
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

namespace _func231
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
	__asm__("call %0\n\t" :: "m"(_func231::func));
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

namespace _func232
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
	__asm__("call %0\n\t" :: "m"(_func232::func));
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

namespace _func233
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
	__asm__("call %0\n\t" :: "m"(_func233::func));
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

namespace _func234
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
	__asm__("call %0\n\t" :: "m"(_func234::func));
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

namespace _func235
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
	__asm__("call %0\n\t" :: "m"(_func235::func));
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

namespace _func236
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
	__asm__("call %0\n\t" :: "m"(_func236::func));
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

namespace _func237
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
	__asm__("call %0\n\t" :: "m"(_func237::func));
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

namespace _func238
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
	__asm__("call %0\n\t" :: "m"(_func238::func));
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

namespace _func239
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
	__asm__("call %0\n\t" :: "m"(_func239::func));
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

namespace _func240
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_Rotate", typeid(void (*)(float , float , float , float )), ".55660fefe489e5565383e4f081ec????????f30f1055080f2ed4f30f104d0cf30f104510f30f105d147a??", argdata, 4, 6, &func);
}

__declspec(naked) void CSurface::GL_Rotate(float unk1, float unk2, float unk3, float unk4)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+20]\n\t"		// unk4
		"push [ebp+16]\n\t"		// unk3
		"push [ebp+12]\n\t"		// unk2
		"push [ebp+8]\n\t"		// unk1
	);
	__asm__("call %0\n\t" :: "m"(_func240::func));
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

namespace _func241
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
	__asm__("call %0\n\t" :: "m"(_func241::func));
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

namespace _func242
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
	__asm__("call %0\n\t" :: "m"(_func242::func));
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

namespace _func243
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
	__asm__("call %0\n\t" :: "m"(_func243::func));
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

namespace _func244
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
	__asm__("call %0\n\t" :: "m"(_func244::func));
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

namespace _func245
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
	__asm__("call %0\n\t" :: "m"(_func245::func));
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

namespace _func246
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GetColorTint", typeid(GL_Color &(*)(GL_Color &)), ".8b15????????8b0d????????5539d189e58b450874??29ca83e2f08d5411f0", argdata, 1, 2, &func);
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
	__asm__("call %0\n\t" :: "m"(_func246::func));
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

namespace _func247
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
	__asm__("call %0\n\t" :: "m"(_func247::func));
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

namespace _func248
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
	__asm__("call %0\n\t" :: "m"(_func248::func));
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

namespace _func249
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
	__asm__("call %0\n\t" :: "m"(_func249::func));
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

namespace _func250
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
	__asm__("call %0\n\t" :: "m"(_func250::func));
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

namespace _func251
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
	__asm__("call %0\n\t" :: "m"(_func251::func));
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

namespace _func252
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
	__asm__("call %0\n\t" :: "m"(_func252::func));
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

namespace _func253
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
	__asm__("call %0\n\t" :: "m"(_func253::func));
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

namespace _func254
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
	__asm__("call %0\n\t" :: "m"(_func254::func));
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

namespace _func255
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
	__asm__("call %0\n\t" :: "m"(_func255::func));
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

namespace _func256
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitImagePartial", typeid(bool (*)(GL_Texture *, float , float , float , float , float , float , float , float , float , GL_Color , bool )), ".5589e557565383e4f083ec60807d4000", argdata, 12, 2, &func);
}

__declspec(naked) bool CSurface::GL_BlitImagePartial(GL_Texture *tex, float x, float y, float x2, float y2, float x3, float y3, float x4, float y4, float rotation, GL_Color color, bool mirror)
{
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
		"push [ebp+44]\n\t"		// rotation
		"push [ebp+40]\n\t"		// y4
		"push [ebp+36]\n\t"		// x4
		"push [ebp+32]\n\t"		// y3
		"push [ebp+28]\n\t"		// x3
		"push [ebp+24]\n\t"		// y2
		"push [ebp+20]\n\t"		// x2
		"push [ebp+16]\n\t"		// y
		"push [ebp+12]\n\t"		// x
		"push [ebp+8]\n\t"		// tex
	);
	__asm__("call %0\n\t" :: "m"(_func256::func));
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

namespace _func257
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
	__asm__("call %0\n\t" :: "m"(_func257::func));
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

namespace _func258
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
	__asm__("call %0\n\t" :: "m"(_func258::func));
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

namespace _func259
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
	__asm__("call %0\n\t" :: "m"(_func259::func));
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

namespace _func260
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
	__asm__("call %0\n\t" :: "m"(_func260::func));
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

namespace _func261
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
		"ret\n\t"
	);
}

namespace _func262
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
	__asm__("call %0\n\t" :: "m"(_func263::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func264
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
	__asm__("call %0\n\t" :: "m"(_func265::func));
	__asm__
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

namespace _func266
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
	__asm__("call %0\n\t" :: "m"(_func266::func));
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

namespace _func267
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
		"ret\n\t"
	);
}

namespace _func269
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
	__asm__("call %0\n\t" :: "m"(_func269::func));
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

namespace _func270
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
		"ret\n\t"
	);
}

namespace _func271
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
	static FunctionDefinition funcObj("EquipmentBox::OnRender", typeid(void (EquipmentBox::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b37e8????????660fefc0c74424080000000089f7", argdata, 1, 5, &func);
}

__declspec(naked) void EquipmentBox::OnRender()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
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
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func273
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
	__asm__("call %0\n\t" :: "m"(_func273::func));
	__asm__
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

namespace _func274
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
	__asm__("call %0\n\t" :: "m"(_func274::func));
	__asm__
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

namespace _func275
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
	__asm__("call %0\n\t" :: "m"(_func275::func));
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

namespace _func276
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
		"ret 16\n\t"
	);
}

namespace _func277
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
		"ret\n\t"
	);
}

namespace _func278
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
		"ret 8\n\t"
	);
}

namespace _func279
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
	__asm__("call %0\n\t" :: "m"(_func279::func));
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

namespace _func280
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
		"ret 8\n\t"
	);
}

namespace _func281
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
	__asm__("call %0\n\t" :: "m"(_func281::func));
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

namespace _func282
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
	__asm__("call %0\n\t" :: "m"(_func282::func));
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

namespace _func283
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::ParseBoolean", typeid(bool (*)(std::string &)), "8d4c240483e4f0ff71fc5589e5535183ec108b19c70424????????89d9e8????????83ec0485c075??b8????????8d65f859", argdata, 2, 3, &func);
}

__declspec(naked) bool EventsParser::ParseBoolean(std::string &str)
{
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
	__asm__("call %0\n\t" :: "m"(_func283::func));
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

namespace _func284
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_measurePrintLines", typeid(double (*)(int , float , float , int , std::string &)), "8d4c240483e4f0ff71fc5589e5575653518d75d883ec488b018975d08945c08b410c8945bc8b41108b38", argdata, 5, 10, &func);
}

__declspec(naked) double freetype::easy_measurePrintLines(int fontData, float x, float y, int width, std::string &text)
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
	__asm__("call %0\n\t" :: "m"(_func284::func));
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

namespace _func285
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
	__asm__("call %0\n\t" :: "m"(_func285::func));
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

namespace _func286
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
	__asm__("call %0\n\t" :: "m"(_func286::func));
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

namespace _func287
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
	__asm__("call %0\n\t" :: "m"(_func287::func));
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

namespace _func288
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
	__asm__("call %0\n\t" :: "m"(_func288::func));
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

namespace _func289
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
	__asm__("call %0\n\t" :: "m"(_func289::func));
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

namespace _func290
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
	__asm__("call %0\n\t" :: "m"(_func290::func));
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

namespace _func291
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
	__asm__("call %0\n\t" :: "m"(_func291::func));
	__asm__
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

namespace _func292
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
	__asm__("call %0\n\t" :: "m"(_func292::func));
	__asm__
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

namespace _func293
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
	__asm__("call %0\n\t" :: "m"(_func293::func));
	__asm__
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

namespace _func294
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
	__asm__("call %0\n\t" :: "m"(_func294::func));
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

namespace _func295
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
	__asm__("call %0\n\t" :: "m"(_func297::func));
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

namespace _func298
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
	__asm__("call %0\n\t" :: "m"(_func298::func));
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

namespace _func299
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
		"ret\n\t"
	);
}

namespace _func301
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
	__asm__("call %0\n\t" :: "m"(_func302::func));
	__asm__
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

namespace _func303
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
		"ret 8\n\t"
	);
}

namespace _func304
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
	__asm__("call %0\n\t" :: "m"(_func304::func));
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

namespace _func305
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
	__asm__("call %0\n\t" :: "m"(_func305::func));
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

namespace _func306
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
		"ret 4\n\t"
	);
}

namespace _func308
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
		"ret 4\n\t"
	);
}

namespace _func309
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
		"ret 4\n\t"
	);
}

namespace _func311
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
		"ret 4\n\t"
	);
}

namespace _func312
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
	__asm__("call %0\n\t" :: "m"(_func314::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func315
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
	__asm__("call %0\n\t" :: "m"(_func315::func));
	__asm__
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

namespace _func316
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
		"ret 4\n\t"
	);
}

namespace _func317
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
		"ret 4\n\t"
	);
}

namespace _func318
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::GetImageId", typeid(void *(ResourceControl::*)(std::string &)), "578d7c240883e4f0ff77fc5589e55756538d459081ec????????8b1f8b3d????????", argdata, 2, 1, &func);
}

__declspec(naked) void *ResourceControl::GetImageId(std::string &name)
{
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
		"ret 4\n\t"
	);
}

namespace _func319
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
		"ret 40\n\t"
	);
}

namespace _func320
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
	__asm__("call %0\n\t" :: "m"(_func320::func));
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

namespace _func321
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
	__asm__("call %0\n\t" :: "m"(_func321::func));
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

namespace _func322
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
	__asm__("call %0\n\t" :: "m"(_func322::func));
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

namespace _func323
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
	__asm__("call %0\n\t" :: "m"(_func323::func));
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

namespace _func324
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
	__asm__("call %0\n\t" :: "m"(_func324::func));
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

namespace _func325
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
		"ret 72\n\t"
	);
}

namespace _func326
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
		"ret\n\t"
	);
}

namespace _func327
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
		"ret 8\n\t"
	);
}

namespace _func328
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
	__asm__("call %0\n\t" :: "m"(_func328::func));
	__asm__
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

namespace _func329
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
	__asm__("call %0\n\t" :: "m"(_func329::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func330
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
		"ret\n\t"
	);
}

namespace _func331
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
	__asm__("call %0\n\t" :: "m"(_func333::func));
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

namespace _func334
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
		"ret\n\t"
	);
}

namespace _func338
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
		"ret\n\t"
	);
}

namespace _func339
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
	__asm__("call %0\n\t" :: "m"(_func339::func));
	__asm__
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

namespace _func340
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("ShipButton::OnInit", typeid(void (ShipButton::*)(std::string &, Point )), ".578d7c240883e4f0ff77fc5589e5575389cb83ec10807b70008b17", argdata, 3, 5, &func);
}

__declspec(naked) void ShipButton::OnInit(std::string &unk, Point pos)
{
	__asm__
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
		"push [ebp+8]\n\t"		// unk
	);
	__asm__("call %0\n\t" :: "m"(_func340::func));
	__asm__
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

namespace _func341
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
		"ret 8\n\t"
	);
}

namespace _func342
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
	__asm__("call %0\n\t" :: "m"(_func342::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func343
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
	__asm__("call %0\n\t" :: "m"(_func343::func));
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

namespace _func344
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
	__asm__("call %0\n\t" :: "m"(_func344::func));
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

namespace _func345
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
	__asm__("call %0\n\t" :: "m"(_func345::func));
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

namespace _func346
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
	__asm__("call %0\n\t" :: "m"(_func346::func));
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

namespace _func347
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
		"ret 4\n\t"
	);
}

namespace _func348
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
		"ret 8\n\t"
	);
}

namespace _func349
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
		"ret 16\n\t"
	);
}

namespace _func350
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
		"ret 16\n\t"
	);
}

namespace _func351
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
		"ret 16\n\t"
	);
}

namespace _func352
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
	__asm__("call %0\n\t" :: "m"(_func352::func));
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

namespace _func353
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
		"ret 20\n\t"
	);
}

namespace _func356
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
	__asm__("call %0\n\t" :: "m"(_func356::func));
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

namespace _func357
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
	__asm__("call %0\n\t" :: "m"(_func357::func));
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

namespace _func358
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
		"ret 4\n\t"
	);
}

namespace _func359
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
	__asm__("call %0\n\t" :: "m"(_func359::func));
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

namespace _func360
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
		"ret 16\n\t"
	);
}

namespace _func361
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
	__asm__("call %0\n\t" :: "m"(_func361::func));
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

namespace _func362
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
	__asm__("call %0\n\t" :: "m"(_func362::func));
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

namespace _func363
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
	__asm__("call %0\n\t" :: "m"(_func364::func));
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

namespace _func365
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
	__asm__("call %0\n\t" :: "m"(_func365::func));
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

namespace _func366
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
	__asm__("call %0\n\t" :: "m"(_func366::func));
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

namespace _func367
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
	__asm__("call %0\n\t" :: "m"(_func367::func));
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

namespace _func368
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
	__asm__("call %0\n\t" :: "m"(_func368::func));
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

namespace _func369
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
	__asm__("call %0\n\t" :: "m"(_func369::func));
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

namespace _func370
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
	__asm__("call %0\n\t" :: "m"(_func370::func));
	__asm__
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

namespace _func371
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
	__asm__("call %0\n\t" :: "m"(_func371::func));
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

namespace _func372
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
	__asm__("call %0\n\t" :: "m"(_func372::func));
	__asm__
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

namespace _func373
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
	__asm__("call %0\n\t" :: "m"(_func373::func));
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

namespace _func374
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
	__asm__("call %0\n\t" :: "m"(_func374::func));
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

namespace _func375
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
	__asm__("call %0\n\t" :: "m"(_func375::func));
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

namespace _func376
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::HasSystem", typeid(bool (ShipManager::*)(int )), "8b44240483f81174??8b91c8040000833c82ff0f95c0c204008db42600000000b8????????", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipManager::HasSystem(int systemId)
{
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
	__asm__("call %0\n\t" :: "m"(_func376::func));
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

namespace _func377
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
	__asm__("call %0\n\t" :: "m"(_func377::func));
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

namespace _func378
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
	__asm__("call %0\n\t" :: "m"(_func378::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func379
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
	__asm__("call %0\n\t" :: "m"(_func379::func));
	__asm__
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

namespace _func380
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
	__asm__("call %0\n\t" :: "m"(_func380::func));
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

namespace _func381
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
	__asm__("call %0\n\t" :: "m"(_func381::func));
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

namespace _func382
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
	__asm__("call %0\n\t" :: "m"(_func382::func));
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

namespace _func383
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
	__asm__("call %0\n\t" :: "m"(_func383::func));
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

namespace _func384
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
	__asm__("call %0\n\t" :: "m"(_func384::func));
	__asm__
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

namespace _func385
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
	__asm__("call %0\n\t" :: "m"(_func385::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func386
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
	__asm__("call %0\n\t" :: "m"(_func386::func));
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

namespace _func387
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
	__asm__("call %0\n\t" :: "m"(_func387::func));
	__asm__
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

namespace _func388
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
	__asm__("call %0\n\t" :: "m"(_func388::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func389
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
	__asm__("call %0\n\t" :: "m"(_func389::func));
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

namespace _func390
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
	__asm__("call %0\n\t" :: "m"(_func390::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func391
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
	__asm__("call %0\n\t" :: "m"(_func391::func));
	__asm__
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

namespace _func392
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
	__asm__("call %0\n\t" :: "m"(_func392::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func393
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
	__asm__("call %0\n\t" :: "m"(_func393::func));
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

namespace _func394
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSelect::Open", typeid(void (ShipSelect::*)()), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 1, 5, &func);
}

__declspec(naked) void ShipSelect::Open()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
	);
	__asm__("call %0\n\t" :: "m"(_func394::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func395
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
	__asm__("call %0\n\t" :: "m"(_func395::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func396
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
	__asm__("call %0\n\t" :: "m"(_func396::func));
	__asm__
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

namespace _func397
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
	__asm__("call %0\n\t" :: "m"(_func397::func));
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

namespace _func398
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
	__asm__("call %0\n\t" :: "m"(_func398::func));
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

namespace _func399
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
	__asm__("call %0\n\t" :: "m"(_func399::func));
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

namespace _func400
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
	__asm__("call %0\n\t" :: "m"(_func400::func));
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

namespace _func401
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
	__asm__("call %0\n\t" :: "m"(_func401::func));
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

namespace _func402
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
	__asm__("call %0\n\t" :: "m"(_func402::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func403
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
	__asm__("call %0\n\t" :: "m"(_func403::func));
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

namespace _func404
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SetPowerLoss", typeid(void (ShipSystem::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b338b0f8b8680000000898b200100003d????????0f85????????", argdata, 2, 5, &func);
}

__declspec(naked) void ShipSystem::SetPowerLoss(int power)
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
		"push [ebp+8]\n\t"		// power
	);
	__asm__("call %0\n\t" :: "m"(_func404::func));
	__asm__
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

namespace _func405
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
	__asm__("call %0\n\t" :: "m"(_func405::func));
	__asm__
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

namespace _func406
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
	__asm__("call %0\n\t" :: "m"(_func406::func));
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

namespace _func407
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
	__asm__("call %0\n\t" :: "m"(_func407::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func408
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
	__asm__("call %0\n\t" :: "m"(_func408::func));
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

namespace _func409
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
		"ret 4\n\t"
	);
}

namespace _func410
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
	__asm__("call %0\n\t" :: "m"(_func410::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func411
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SwitchPlanet", typeid(ImageDesc *(SpaceManager::*)(std::string &)), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 2, 1, &func);
}

__declspec(naked) ImageDesc *SpaceManager::SwitchPlanet(std::string &name)
{
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
	__asm__("call %0\n\t" :: "m"(_func413::func));
	__asm__
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

namespace _func414
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SwitchBackground", typeid(ImageDesc *(SpaceManager::*)(std::string &)), ".578d7c240883e4f0", argdata, 2, 1, &func);
}

__declspec(naked) ImageDesc *SpaceManager::SwitchBackground(std::string &name)
{
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
		"ret 8\n\t"
	);
}

namespace _func416
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetPlanetaryDefense", typeid(void (SpaceManager::*)(char , int )), ".578d7c240883e4f0ff77fc5589e557565389cb81ec????????", argdata, 3, 5, &func);
}

__declspec(naked) void SpaceManager::SetPlanetaryDefense(char unk, int target)
{
	__asm__
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
		"push [ebp+8]\n\t"		// unk
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
		"ret 8\n\t"
	);
}

namespace _func417
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
	__asm__("call %0\n\t" :: "m"(_func417::func));
	__asm__
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

namespace _func418
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
	__asm__("call %0\n\t" :: "m"(_func418::func));
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

namespace _func419
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
		"ret 12\n\t"
	);
}

namespace _func420
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
	__asm__("call %0\n\t" :: "m"(_func420::func));
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

namespace _func421
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
	__asm__("call %0\n\t" :: "m"(_func421::func));
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

namespace _func422
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
	__asm__("call %0\n\t" :: "m"(_func422::func));
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

namespace _func423
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
	__asm__("call %0\n\t" :: "m"(_func424::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
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
	__asm__("call %0\n\t" :: "m"(_func426::func));
	__asm__
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

namespace _func427
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
		"ret 8\n\t"
	);
}

namespace _func428
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
		"ret 8\n\t"
	);
}

namespace _func429
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
		"ret\n\t"
	);
}

namespace _func430
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
		"ret\n\t"
	);
}

namespace _func431
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
		"ret\n\t"
	);
}

namespace _func432
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
	__asm__("call %0\n\t" :: "m"(_func432::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func433
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
		"ret\n\t"
	);
}

namespace _func434
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
		"ret 4\n\t"
	);
}

namespace _func435
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
	__asm__("call %0\n\t" :: "m"(_func435::func));
	__asm__
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

namespace _func436
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
	__asm__("call %0\n\t" :: "m"(_func436::func));
	__asm__
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

namespace _func437
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
	__asm__("call %0\n\t" :: "m"(_func437::func));
	__asm__
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

namespace _func438
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
		"ret\n\t"
	);
}

namespace _func440
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
		"ret\n\t"
	);
}

namespace _func441
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
	__asm__("call %0\n\t" :: "m"(_func441::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func442
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::SetNebula", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e55756", argdata, 1, 5, &func);
}

__declspec(naked) void SpaceManager::SetNebula()
{
	__asm__
	(
		"push ebp\n\t"
		"mov ebp, esp\n\t"
		"push edx\n\t"
		"push eax\n\t"
		"push ecx\n\t"
		"push ebx\n\t"
		"push esi\n\t"
		"push edi\n\t"
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
		"ret\n\t"
	);
}

namespace _func443
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::SetStorm", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e5", argdata, 1, 5, &func);
}

__declspec(naked) void SpaceManager::SetStorm()
{
	__asm__
	(
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
		"ret\n\t"
	);
}

namespace _func445
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
	__asm__("call %0\n\t" :: "m"(_func445::func));
	__asm__
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

namespace _func446
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::DrawConnection", typeid(void (StarMap::*)(const Pointf &, const Pointf &, const GL_Color &)), "578d7c240883e4f0ff77fc5589e557565381ec????????8b078b57048b5f08894db889458089d689957cffffff8b5004", argdata, 4, 5, &func);
}

__declspec(naked) void StarMap::DrawConnection(const Pointf &pos1, const Pointf &pos2, const GL_Color &color)
{
	__asm__
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
	__asm__("call %0\n\t" :: "m"(_func446::func));
	__asm__
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

namespace _func447
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
	__asm__("call %0\n\t" :: "m"(_func447::func));
	__asm__
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

namespace _func448
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TextInput::SetText", typeid(int (TextInput::*)(std::string &)), "578d7c240883e4f0ff77fc5589e557565389ce8d5de083ec2c", argdata, 2, 1, &func);
}

__declspec(naked) int TextInput::SetText(std::string &text)
{
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
		"ret 4\n\t"
	);
}

namespace _func449
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextLibrary::GetText", typeid(std::string &(*)(std::string &, TextLibrary *, std::string &, std::string &)), "578d7c240883e4f0ff77fc5589e557565383ec4c8b07894dc889c18945bc8b47048b59208d511c", argdata, 4, 0, &func);
}

__declspec(naked) std::string &TextLibrary::GetText(std::string &strRef, TextLibrary *textLibrary, std::string &name, std::string &lang)
{
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
	__asm__("call %0\n\t" :: "m"(_func449::func));
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

namespace _func450
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
	__asm__("call %0\n\t" :: "m"(_func450::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func451
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
		"ret\n\t"
	);
}

namespace _func452
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
	__asm__("call %0\n\t" :: "m"(_func452::func));
	__asm__
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

namespace _func453
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
		"ret 8\n\t"
	);
}

namespace _func454
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
		"ret 8\n\t"
	);
}

namespace _func457
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
	__asm__("call %0\n\t" :: "m"(_func457::func));
	__asm__
	(
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		"ret\n\t"
	);
}

namespace _func458
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
	__asm__("call %0\n\t" :: "m"(_func458::func));
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

namespace _func459
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
	__asm__("call %0\n\t" :: "m"(_func459::func));
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

