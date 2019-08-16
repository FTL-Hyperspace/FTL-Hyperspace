#include "FTLGame.h"
#include "zhl_internal.h"

using namespace ZHL;

namespace _func0
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SaveProfile", typeid(int (AchievementTracker::*)(FileHelper *)), "55565383ec70894c2428c744244418e16500c7442448642375008d4424708944244cc7442450ccff4000", argdata, 2, 1, &func);
}

__declspec(naked) int AchievementTracker::SaveProfile(FileHelper *fileHelper)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// fileHelper
		call _func0::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func1
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::WipeProfile", typeid(int (AchievementTracker::*)()), ".538B", argdata, 1, 1, &func);
}

__declspec(naked) int AchievementTracker::WipeProfile()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func1::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func2
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::CheckCrystalUnlock", typeid(int (AchievementTracker::*)()), ".5557", argdata, 1, 1, &func);
}

__declspec(naked) int AchievementTracker::CheckCrystalUnlock()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func2::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func3
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::GetAchievement", typeid(CAchievement *(AchievementTracker::*)(std_string *)), ".5557", argdata, 2, 1, &func);
}

__declspec(naked) CAchievement *AchievementTracker::GetAchievement(std_string *ach)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// ach
		call _func3::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func4
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::GetShipMarker", typeid(CAchievement *(*)(std_string *, std_string *)), ".5553", argdata, 2, 0, &func);
}

__declspec(naked) CAchievement *AchievementTracker::GetShipMarker(std_string *unk1, std_string *unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func4::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func5
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SetInfoBox", typeid(int (*)(CAchievement *, InfoBox *)), ".5581", argdata, 2, 0, &func);
}

__declspec(naked) int AchievementTracker::SetInfoBox(CAchievement *ach, InfoBox *infobox)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// infobox
		push [ebp+8]		// ach
		call _func5::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func6
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::OnRender", typeid(int (AchievementTracker::*)()), ".5557", argdata, 1, 1, &func);
}

__declspec(naked) int AchievementTracker::OnRender()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func6::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func7
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SetTooltip", typeid(int (*)(CAchievement *)), ".5581", argdata, 1, 0, &func);
}

__declspec(naked) int AchievementTracker::SetTooltip(CAchievement *ach)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// ach
		call _func7::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func8
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::OnLoop", typeid(int (AchievementTracker::*)()), ".5583", argdata, 1, 1, &func);
}

__declspec(naked) int AchievementTracker::OnLoop()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func8::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func9
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::ResetFlags", typeid(int (AchievementTracker::*)()), ".5383", argdata, 1, 1, &func);
}

__declspec(naked) int AchievementTracker::ResetFlags()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func9::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func10
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::constructor", typeid(int (AchievementTracker::*)()), ".5557", argdata, 1, 1, &func);
}

__declspec(naked) int AchievementTracker::constructor()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func10::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func11
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SaveGame", typeid(int (AchievementTracker::*)(int )), ".5589", argdata, 2, 1, &func);
}

__declspec(naked) int AchievementTracker::SaveGame(int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func11::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func12
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::UnlockShip", typeid(void (AchievementTracker::*)(int , int )), ".5383", argdata, 3, 5, &func);
}

__declspec(naked) void AchievementTracker::UnlockShip(int shipType, int shipVariant)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// shipVariant
		push [ebp+8]		// shipType
		call _func12::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func13
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::GetShipAchievements", typeid(void *(AchievementTracker::*)(int , std_string *)), ".5553", argdata, 3, 1, &func);
}

__declspec(naked) void *AchievementTracker::GetShipAchievements(int unk1, std_string *unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func13::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func14
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::CheckShipAchievements", typeid(int (AchievementTracker::*)(int , bool )), ".5581", argdata, 3, 1, &func);
}

__declspec(naked) int AchievementTracker::CheckShipAchievements(int shipType, bool unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// shipType
		call _func14::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func15
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::ForceUnlock", typeid(int (AchievementTracker::*)(std_string *, int , int )), ".5553", argdata, 4, 1, &func);
}

__declspec(naked) int AchievementTracker::ForceUnlock(std_string *unk1, int unk2, int unk3)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func15::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func16
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::LoadProfile", typeid(int (AchievementTracker::*)(int , int )), ".5583", argdata, 3, 1, &func);
}

__declspec(naked) int AchievementTracker::LoadProfile(int unk1, int unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func16::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func17
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SetAchievement", typeid(int (AchievementTracker::*)(std_string *, bool , bool )), ".5553", argdata, 4, 1, &func);
}

__declspec(naked) int AchievementTracker::SetAchievement(std_string *ach, bool unk1, bool unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk2
		push [ebp+12]		// unk1
		push [ebp+8]		// ach
		call _func17::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func18
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::SetVictoryAchievement", typeid(int (AchievementTracker::*)()), ".5583", argdata, 1, 1, &func);
}

__declspec(naked) int AchievementTracker::SetVictoryAchievement()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func18::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func19
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::LoadGame", typeid(int (AchievementTracker::*)(int )), ".5553", argdata, 2, 1, &func);
}

__declspec(naked) int AchievementTracker::LoadGame(int unk1)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk1
		call _func19::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func20
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::GetFlag", typeid(bool (AchievementTracker::*)(std_string *)), ".5756", argdata, 2, 1, &func);
}

__declspec(naked) bool AchievementTracker::GetFlag(std_string *flag)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// flag
		call _func20::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func21
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::GetFlagValue", typeid(int (AchievementTracker::*)(int )), ".5756", argdata, 2, 1, &func);
}

__declspec(naked) int AchievementTracker::GetFlagValue(int unk1)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk1
		call _func21::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func22
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::SetSectorEight", typeid(int (AchievementTracker::*)()), ".5581", argdata, 1, 1, &func);
}

__declspec(naked) int AchievementTracker::SetSectorEight()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func22::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func23
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SetFlag", typeid(int (AchievementTracker::*)(std_string *)), ".5756", argdata, 2, 1, &func);
}

__declspec(naked) int AchievementTracker::SetFlag(std_string *flag)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// flag
		call _func23::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func24
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::destructor", typeid(int (AchievementTracker::*)()), "5583ec78894c2420c744244418e16500c7442448b42475008d4424708944244cc7442450495f410089642454", argdata, 1, 1, &func);
}

__declspec(naked) int AchievementTracker::destructor()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func24::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func25
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::LoadAchievementDescriptions", typeid(int (AchievementTracker::*)()), "5589e5575653b8????????e8????????29c4898de4fbfeffc7851cfcfeff18e16500c78520fcfeffd62475008d45e8898524fcfeffc78528fcfeff0d974100", argdata, 1, 1, &func);
}

__declspec(naked) int AchievementTracker::LoadAchievementDescriptions()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func25::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func26
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetCrewBlueprint", typeid(CrewBlueprint *(BlueprintManager::*)(int , std::string *)), "5583ec78894c2414c744243418e16500c7442438d43b75008d4424708944243c", argdata, 3, 1, &func);
}

__declspec(naked) CrewBlueprint *BlueprintManager::GetCrewBlueprint(int unk, std::string *raceName)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// raceName
		push [ebp+8]		// unk
		call _func26::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func27
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::OnLoop", typeid(int (BossShip::*)()), "5581ec????????894c242cc744245418e16500c7442458002075008d8424900000008944245cc7442460e818400089642464", argdata, 1, 1, &func);
}

__declspec(naked) int BossShip::OnLoop()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func27::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func28
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::ClearLocation", typeid(int (BossShip::*)()), ".5383", argdata, 1, 1, &func);
}

__declspec(naked) int BossShip::ClearLocation()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func28::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func29
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::Defeated", typeid(bool (BossShip::*)()), ".83B9", argdata, 1, 1, &func);
}

__declspec(naked) bool BossShip::Defeated()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func29::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func30
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::GetSubEvent", typeid(void *(BossShip::*)()), ".5581", argdata, 1, 1, &func);
}

__declspec(naked) void *BossShip::GetSubEvent()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func30::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func31
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::constructor", typeid(int (BossShip::*)()), ".5583", argdata, 1, 1, &func);
}

__declspec(naked) int BossShip::constructor()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func31::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func32
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BossShip::LoadBoss", typeid(int (BossShip::*)(FileHelper *)), ".5557", argdata, 2, 1, &func);
}

__declspec(naked) int BossShip::LoadBoss(FileHelper *fileHelper)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// fileHelper
		call _func32::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func33
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BossShip::SaveBoss", typeid(int (BossShip::*)(FileHelper *)), ".5756", argdata, 2, 1, &func);
}

__declspec(naked) int BossShip::SaveBoss(FileHelper *fileHelper)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// fileHelper
		call _func33::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func34
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::StartStage", typeid(int (BossShip::*)()), ".5589", argdata, 1, 1, &func);
}

__declspec(naked) int BossShip::StartStage()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func34::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func35
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::GetEvent", typeid(int (BossShip::*)()), ".5589", argdata, 1, 1, &func);
}

__declspec(naked) int BossShip::GetEvent()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func35::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func36
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Button::SetLocation", typeid(int (Button::*)(int , int )), "5383ec1889cb8b442420890424e8????????83ec048b44242489042489d9e8????????83ec0483c4185b", argdata, 3, 1, &func);
}

__declspec(naked) int Button::SetLocation(int x, int y)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func36::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func37
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Button::SetLocationX", typeid(int (Button::*)(int )), "5383ec088b4424108b511c39c274??8b592c29d389411c01d889412ce8????????", argdata, 2, 1, &func);
}

__declspec(naked) int Button::SetLocationX(int x)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// x
		call _func37::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func38
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Button::SetLocationY", typeid(int (Button::*)(int )), "5383ec088b4424108b512039c274??8b593029d389412001d8894130e8????????", argdata, 2, 1, &func);
}

__declspec(naked) int Button::SetLocationY(int y)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// y
		call _func38::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func39
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Button::SetActive", typeid(int (Button::*)(bool )), "8b44240488416084c075??c6416200c6416300", argdata, 2, 1, &func);
}

__declspec(naked) int Button::SetActive(bool active)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// active
		call _func39::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func40
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CAchievement::OnRender", typeid(int (CAchievement::*)(int , int , int , bool )), "55575681ec????????894c24288b8424200100008944242c8b942424010000895424308a8c242c010000884c2434", argdata, 5, 1, &func);
}

__declspec(naked) int CAchievement::OnRender(int x, int y, int unk1, bool unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// unk2
		push [ebp+16]		// unk1
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func40::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func41
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CAchievement::destructor", typeid(int (CAchievement::*)()), ".5583ec68894c2418c744243418e16500c7442438a42475008d442460", argdata, 1, 1, &func);
}

__declspec(naked) int CAchievement::destructor()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func41::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func42
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CAchievement::constructor", typeid(int (CAchievement::*)()), "5581ec????????894c241cc744245418e16500c7442458ba2475008d8424900000008944245cc7442460dc63410089642464", argdata, 1, 1, &func);
}

__declspec(naked) int CAchievement::constructor()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func42::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func43
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnMButtonDown", typeid(int (CApp::*)(int , int )), "8079180075??83ec0c8b4910e8????????83c40c", argdata, 3, 1, &func);
}

__declspec(naked) int CApp::OnMButtonDown(int unk1, int unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func43::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func44
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnExit", typeid(int (CApp::*)()), ".5383", argdata, 1, 1, &func);
}

__declspec(naked) int CApp::OnExit()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func44::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func45
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnRequestExit", typeid(int (CApp::*)()), ".5383", argdata, 1, 1, &func);
}

__declspec(naked) int CApp::OnRequestExit()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func45::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func46
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnEvent", typeid(bool (CApp::*)(int )), ".83EC", argdata, 2, 1, &func);
}

__declspec(naked) bool CApp::OnEvent(int event)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// event
		call _func46::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func47
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnInputBlur", typeid(bool (CApp::*)()), ".5383", argdata, 1, 1, &func);
}

__declspec(naked) bool CApp::OnInputBlur()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func47::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func48
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnInputFocus", typeid(int (CApp::*)()), ".5383", argdata, 1, 1, &func);
}

__declspec(naked) int CApp::OnInputFocus()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func48::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func49
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnKeyUp", typeid(int (CApp::*)(int )), "5583ec78894c2420c744244418e16500c7442448782075008d4424708944244cc7442450cd404000", argdata, 2, 1, &func);
}

__declspec(naked) int CApp::OnKeyUp(int key)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// key
		call _func49::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func50
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnKeyDown", typeid(int (CApp::*)(int )), "5581ec????????894c2420c744244418e16500c74424487e2075008d8424800000008944244cc744245058454000896424548d44242c890424e8????????83bc2490000000000f84????????", argdata, 2, 1, &func);
}

__declspec(naked) int CApp::OnKeyDown(int key)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// key
		call _func50::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func51
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::constructor", typeid(int (CApp::*)()), ".5583", argdata, 1, 1, &func);
}

__declspec(naked) int CApp::constructor()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func51::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func52
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnLoop", typeid(int (CApp::*)()), "5583ec78894c241cc744244418e16500c74424488e2075008d4424708944244cc7442450284c4000", argdata, 1, 1, &func);
}

__declspec(naked) int CApp::OnLoop()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func52::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func53
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnRender", typeid(int (CApp::*)()), "565383ec2489cbe8????????80bb311a00000074??8b83201a0000890424e8????????c744240cd0020000c744240800050000", argdata, 1, 1, &func);
}

__declspec(naked) int CApp::OnRender()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func53::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func54
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::SetupWindow", typeid(bool (CApp::*)()), ".5556", argdata, 1, 1, &func);
}

__declspec(naked) bool CApp::SetupWindow()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func54::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func55
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnInit", typeid(int (CApp::*)()), "5383ec2889cbc70424????????e8????????890424e8????????", argdata, 1, 1, &func);
}

__declspec(naked) int CApp::OnInit()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func55::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func56
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnExecute", typeid(void (CApp::*)()), "55565381ec????????894c2440c744247018e16500c74424749c2075008d84242001000089442478", argdata, 1, 5, &func);
}

__declspec(naked) void CApp::OnExecute()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func56::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func57
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::TranslateMouse", typeid(int64_t (CApp::*)(int , int )), ".83EC", argdata, 3, 1, &func);
}

__declspec(naked) int64_t CApp::TranslateMouse(int x, int y)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func57::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func58
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnRButtonUp", typeid(void (CApp::*)(int , int )), "5383ec1889cb8b442424894424048b442420890424e8????????83ec08807b180075??", argdata, 3, 5, &func);
}

__declspec(naked) void CApp::OnRButtonUp(int x, int y)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func58::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func59
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnRButtonDown", typeid(int (CApp::*)(int , int )), ".5383", argdata, 3, 1, &func);
}

__declspec(naked) int CApp::OnRButtonDown(int x, int y)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func59::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func60
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnMouseMove", typeid(int (CApp::*)(int , int , int , int , int , int , int )), ".83EC", argdata, 8, 1, &func);
}

__declspec(naked) int CApp::OnMouseMove(int x, int y, int unk4, int unk5, int unk6, int unk7, int unk8)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+32]		// unk8
		push [ebp+28]		// unk7
		push [ebp+24]		// unk6
		push [ebp+20]		// unk5
		push [ebp+16]		// unk4
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func60::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 28
	}
}

namespace _func61
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnLButtonDown", typeid(void (CApp::*)(int , int )), ".5383", argdata, 3, 5, &func);
}

__declspec(naked) void CApp::OnLButtonDown(int x, int y)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func61::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func62
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnLButtonUp", typeid(bool (CApp::*)(int , int )), ".5383", argdata, 3, 1, &func);
}

__declspec(naked) bool CApp::OnLButtonUp(int x, int y)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func62::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func63
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CEvent::GetShiftState", typeid(bool (*)()), "83ec0ce8????????a8030f95c083c40cc3", argdata, 0, 0, &func);
}

__declspec(naked) bool CEvent::GetShiftState()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func63::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func64
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CEvent::GetCtrlState", typeid(bool (*)()), "83ec0ce8????????a8c00f95c083c40cc3", argdata, 0, 0, &func);
}

__declspec(naked) bool CEvent::GetCtrlState()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func64::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func65
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CFPS::OnLoop", typeid(void (CFPS::*)()), "5383ec1889cbd905????????dc4108dd1c24e8????????dd0424d9c9", argdata, 1, 5, &func);
}

__declspec(naked) void CFPS::OnLoop()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func65::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func66
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CombatAI::PrioritizeSystem", typeid(unsigned int (CombatAI::*)(int )), "555381ec????????894c2418c744243418e16500c7442438ae2575008d8424800000008944243cc74424407fb04100896424448d44241c", argdata, 2, 1, &func);
}

__declspec(naked) unsigned int CombatAI::PrioritizeSystem(int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func66::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func67
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::RenderShipStatus", typeid(int (CombatControl::*)(float , float )), "5557565381ec????????89ce8b9c24f00000008bbc24f4000000e8????????c744240800000000897c2404891c24", argdata, 3, 1, &func);
}

__declspec(naked) int CombatControl::RenderShipStatus(float unk1, float unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func67::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func68
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::RenderTarget", typeid(int (CombatControl::*)()), "5557565381ec????????894c2448c784248400000018e16500c7842488000000547e75008d842460020000", argdata, 1, 1, &func);
}

__declspec(naked) int CombatControl::RenderTarget()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func68::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func69
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::ClearSysBoxes", typeid(int (CombatControl::*)()), "565383ec0489ce8b81c00300008b91c403000029c283fa037e??bb????????", argdata, 1, 1, &func);
}

__declspec(naked) int CombatControl::ClearSysBoxes()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func69::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func70
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::ClearCrewSelection", typeid(int (CombatControl::*)()), ".8b81d803000085c074??83ec0c8b4808e8????????83c40c", argdata, 1, 1, &func);
}

__declspec(naked) int CombatControl::ClearCrewSelection()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func70::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func71
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::GetCurrentTarget", typeid(ShipManager *(CombatControl::*)()), "!.8b81d803000085c074??8b4008c3b8????????c3", argdata, 1, 1, &func);
}

__declspec(naked) ShipManager *CombatControl::GetCurrentTarget()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func71::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func72
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::KeyDown", typeid(int (CombatControl::*)(int )), "565383ec1489cb8b7424208d4914893424e8????????83ec04", argdata, 2, 1, &func);
}

__declspec(naked) int CombatControl::KeyDown(int key)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// key
		call _func72::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func73
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::CanTargetSelf", typeid(bool (CombatControl::*)()), "5589e583ec78894d9cc745bc18e16500c745c0c87d75008d45f88945c4", argdata, 1, 1, &func);
}

__declspec(naked) bool CombatControl::CanTargetSelf()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func73::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func74
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::MouseClick", typeid(bool (CombatControl::*)(int , int , bool )), "57565383ec1089cb8b7424208b7c2424c68168090000018d4914c744240800000000897c2404893424", argdata, 4, 1, &func);
}

__declspec(naked) bool CombatControl::MouseClick(int x, int y, bool unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func74::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func75
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::MouseMove", typeid(bool (CombatControl::*)(int , int )), "5557565383ec2c89ce8b7c24408b6c2444c781dc03000000000000897c241cdb44241cd99960090000896c241c", argdata, 3, 1, &func);
}

__declspec(naked) bool CombatControl::MouseMove(int x, int y)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func75::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func76
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::constructor", typeid(int (CommandGui::*)()), "5589e557565381ec????????898d20feffffc785bcfeffff18e16500c785c0feffff948175008d45e8", argdata, 1, 1, &func);
}

__declspec(naked) int CommandGui::constructor()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func76::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func77
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::KeyDown", typeid(int (CommandGui::*)(int , char )), "555381ec????????894c241c8a8424f400000088442424c744244418e16500c74424483a7f75008d9424e0000000", argdata, 3, 1, &func);
}

__declspec(naked) int CommandGui::KeyDown(int key, char unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// key
		call _func77::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func78
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::RunCommand", typeid(int (CommandGui::*)(char **)), "5581ec????????894c2428c744244418e16500c7442448b27f7500", argdata, 2, 1, &func);
}

__declspec(naked) int CommandGui::RunCommand(char **command)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// command
		call _func78::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func79
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::LinkShip", typeid(int (CommandGui::*)(CompleteShip *)), "5581ec????????894c2424c744247418e16500c74424787a7f75008d8424a00100008944247c", argdata, 2, 1, &func);
}

__declspec(naked) int CommandGui::LinkShip(CompleteShip *ship)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// ship
		call _func79::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func80
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::RenderStatic", typeid(int (CommandGui::*)()), "55575681ec????????894c2440c744247418e16500c7442478968075008d8424000100008944247c", argdata, 1, 1, &func);
}

__declspec(naked) int CommandGui::RenderStatic()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func80::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func81
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::CreateNewStore", typeid(int (CommandGui::*)(int )), "5583ec68894c2414c744243418e16500c74424389e8075008d4424608944243cc7442440bc6e5800", argdata, 2, 1, &func);
}

__declspec(naked) int CommandGui::CreateNewStore(int sectorNumber)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// sectorNumber
		call _func81::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func82
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::Restart", typeid(int (CompleteShip::*)()), "5383ec1889cb8b4908e8????????8d4b18c7442404000000008b4308890424", argdata, 1, 1, &func);
}

__declspec(naked) int CompleteShip::Restart()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func82::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func83
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::PauseLoop", typeid(int (CompleteShip::*)()), ".83EC", argdata, 1, 1, &func);
}

__declspec(naked) int CompleteShip::PauseLoop()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func83::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func84
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::constructor", typeid(int (CompleteShip::*)(SpaceManager *, bool , int )), ".5383", argdata, 4, 1, &func);
}

__declspec(naked) int CompleteShip::constructor(SpaceManager *spaceMan, bool unk1, int unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk2
		push [ebp+12]		// unk1
		push [ebp+8]		// spaceMan
		call _func84::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func85
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::SetShip", typeid(int (CompleteShip::*)(ShipManager *)), ".83EC", argdata, 2, 1, &func);
}

__declspec(naked) int CompleteShip::SetShip(ShipManager *ship)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// ship
		call _func85::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func86
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::OnInit", typeid(int (CompleteShip::*)(const ShipBlueprint &, int )), ".5583", argdata, 3, 1, &func);
}

__declspec(naked) int CompleteShip::OnInit(const ShipBlueprint &bp, int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// bp
		call _func86::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func87
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddBoarders", typeid(int (CompleteShip::*)(int , std_string *, bool )), ".5557", argdata, 4, 1, &func);
}

__declspec(naked) int CompleteShip::AddBoarders(int unk1, std_string *unk2, bool unk3)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func87::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func88
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember", typeid(int (CompleteShip::*)(std_string *, std_string *, bool )), ".5557", argdata, 4, 1, &func);
}

__declspec(naked) int CompleteShip::AddCrewMember(std_string *unk1, std_string *unk2, bool unk3)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func88::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func89
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember", typeid(char *(CompleteShip::*)(CrewMember *, int )), ".5653", argdata, 3, 1, &func);
}

__declspec(naked) char *CompleteShip::AddCrewMember(CrewMember *crew, int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// crew
		call _func89::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func90
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::SaveState", typeid(bool (CompleteShip::*)(FileHelper *)), ".83EC", argdata, 2, 1, &func);
}

__declspec(naked) bool CompleteShip::SaveState(FileHelper *fileHelper)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// fileHelper
		call _func90::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func91
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::Jump", typeid(int (CompleteShip::*)()), ".8B81", argdata, 1, 1, &func);
}

__declspec(naked) int CompleteShip::Jump()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func91::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func92
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::SetEnemeyShip", typeid(int (CompleteShip::*)(CompleteShip *)), ".83EC", argdata, 2, 1, &func);
}

__declspec(naked) int CompleteShip::SetEnemeyShip(CompleteShip *enemy)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// enemy
		call _func92::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func93
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::DeadCrew", typeid(bool (CompleteShip::*)()), ".5653", argdata, 1, 1, &func);
}

__declspec(naked) bool CompleteShip::DeadCrew()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func93::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func94
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::TeleportCrew", typeid(void (CompleteShip::*)(ShipManager *, int , bool )), ".5383", argdata, 4, 5, &func);
}

__declspec(naked) void CompleteShip::TeleportCrew(ShipManager *ship, int unk1, bool unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk2
		push [ebp+12]		// unk1
		push [ebp+8]		// ship
		call _func94::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func95
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::OnRenderShip", typeid(int (CompleteShip::*)(bool , bool )), ".5756", argdata, 3, 1, &func);
}

__declspec(naked) int CompleteShip::OnRenderShip(bool unk1, bool unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func95::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func96
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::InitiateTeleport", typeid(int (CompleteShip::*)(int , int )), ".5581", argdata, 3, 1, &func);
}

__declspec(naked) int CompleteShip::InitiateTeleport(int unk1, int unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func96::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func97
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::OnLoop", typeid(int (CompleteShip::*)()), ".5557", argdata, 1, 1, &func);
}

__declspec(naked) int CompleteShip::OnLoop()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func97::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func98
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::LoadState", typeid(int (CompleteShip::*)(FileHelper *)), ".5583", argdata, 2, 1, &func);
}

__declspec(naked) int CompleteShip::LoadState(FileHelper *fileHelper)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// fileHelper
		call _func98::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func99
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember", typeid(int (CompleteShip::*)(const CrewBlueprint &, bool )), ".5589e557565381ec????????898d20ffffff8a450c888500ffffffc7853cffffff18e16500c78540ffffff942175008d55e8", argdata, 3, 1, &func);
}

__declspec(naked) int CompleteShip::AddCrewMember(const CrewBlueprint &bp, bool unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// bp
		call _func99::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func100
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::SetOutOfGame", typeid(int (CrewMember::*)()), "c681a801000001c681b001000001c781d004000000000000c6818d03000000a1????????40", argdata, 1, 1, &func);
}

__declspec(naked) int CrewMember::SetOutOfGame()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func100::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func101
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::OnRender", typeid(int (CrewMember::*)(bool )), "565383ec3489cb0fb674244080b9b0010000000f85????????d94110d97c241e", argdata, 2, 1, &func);
}

__declspec(naked) int CrewMember::OnRender(bool unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func101::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func102
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SaveState", typeid(int (CrewMember::*)(int )), "57565383ec2089cf8b742430d981d0040000d95c2404893424", argdata, 2, 1, &func);
}

__declspec(naked) int CrewMember::SaveState(int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func102::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func103
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillFromSystem", typeid(int (CrewMember::*)(int )), "8b44240483f80174??83f80674??85c074??83f8030f94c00fb6c08d0485????????", argdata, 2, 1, &func);
}

__declspec(naked) int CrewMember::GetSkillFromSystem(int systemId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// systemId
		call _func103::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func104
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetResisted", typeid(int (CrewMember::*)(int )), "!.8b4424048881bc040000c20400", argdata, 2, 1, &func);
}

__declspec(naked) int CrewMember::SetResisted(int resisted)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// resisted
		call _func104::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func105
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetResisted", typeid(int (CrewMember::*)()), "!.8a81bc040000c681bc04000000c3", argdata, 1, 1, &func);
}

__declspec(naked) int CrewMember::GetResisted()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func105::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func106
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetSkillProgress", typeid(int (CrewMember::*)(int , int )), "!.8b81100200008b4c24088b542404890cd0c20800", argdata, 3, 1, &func);
}

__declspec(naked) int CrewMember::SetSkillProgress(int skillId, int progress)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// progress
		push [ebp+8]		// skillId
		call _func106::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func107
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillLevel", typeid(int (CrewMember::*)(int )), "8b44240483f80577??8b91100200008d04c28b108b400439c2", argdata, 2, 1, &func);
}

__declspec(naked) int CrewMember::GetSkillLevel(int skillId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// skillId
		call _func107::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func108
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::IncreaseSkill", typeid(int (CrewMember::*)(int )), "555383ec64894c2410c744243418e16500c7442438905c75008d4424608944243c", argdata, 2, 1, &func);
}

__declspec(naked) int CrewMember::IncreaseSkill(int skillId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// skillId
		call _func108::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func109
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillProgress", typeid(int (CrewMember::*)(int )), "8b81100200008b5424048d14d08b028b520489d1", argdata, 2, 1, &func);
}

__declspec(naked) int CrewMember::GetSkillProgress(int skillId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// skillId
		call _func109::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func110
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::BadAtCombat", typeid(bool (CrewMember::*)()), "5383ec0889cb8b01ff9090000000d9e8dae9dfe0f6c44574??d94330", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::BadAtCombat()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func110::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func111
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::DirectModifyHealth", typeid(bool (CrewMember::*)(int , float )), "5583ec78894c2418c744244418e16500c7442448965c75008d4424708944244c", argdata, 3, 1, &func);
}

__declspec(naked) bool CrewMember::DirectModifyHealth(int edx, float health)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// health
		push [ebp+8]		// edx
		call _func111::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func112
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ApplyDamage", typeid(bool (CrewMember::*)(int , float )), "5383ec2889cbd9412cd95c241cd9442430d91c24e8????????83ec04d9ee", argdata, 3, 1, &func);
}

__declspec(naked) bool CrewMember::ApplyDamage(int edx, float health)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// health
		push [ebp+8]		// edx
		call _func112::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func113
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ModifyHealth", typeid(bool (CrewMember::*)(float )), "5383ec1889cbb9????????e8????????d84c2420d91c2489d9e8????????83ec0483c418", argdata, 2, 1, &func);
}

__declspec(naked) bool CrewMember::ModifyHealth(float health)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// health
		call _func113::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func114
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::SavePosition", typeid(void (CrewMember::*)()), ".57568db9c00400008db18c000000b9????????f3a55e", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::SavePosition()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func114::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func115
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::ClearPosition", typeid(void (CrewMember::*)()), "!.c781c4040000ffffffffc781c0040000ffffffffc3", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::ClearPosition()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func115::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func116
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetSavedPosition", typeid(void *(CrewMember::*)()), ".575689c88b74240c81c6????????b9????????89c7f3a55e", argdata, 1, 1, &func);
}

__declspec(naked) void *CrewMember::GetSavedPosition()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func116::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func117
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetSavePosition", typeid(void (CrewMember::*)(bool , int , int , int )), ".57568db9c0040000b9????????8d74240cf3a55e", argdata, 5, 5, &func);
}

__declspec(naked) void CrewMember::SetSavePosition(bool unk1, int unk2, int unk3, int unk4)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func117::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func118
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::StopRepairing", typeid(void (CrewMember::*)()), ".5383ec0889cb83796c0074??8b01ff505084c074??8b436c", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::StopRepairing()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func118::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func119
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Repairing", typeid(bool (CrewMember::*)()), "!.83796c000f95c0c3", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::Repairing()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func119::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func120
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Sabotaging", typeid(bool (CrewMember::*)()), "5383ec0889cbe8????????84c074??8b4b6c8b01ff503084c0", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::Sabotaging()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func120::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func121
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::SelectSabotageTarget", typeid(int64_t (CrewMember::*)()), "565383ec4489cbe8????????84c074??8b737c8b833c010000890424e8????????", argdata, 1, 1, &func);
}

__declspec(naked) int64_t CrewMember::SelectSabotageTarget()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func121::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func122
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::RepairingSoundEffect", typeid(bool (CrewMember::*)()), "5383ec0889cbe8????????84c074??83bbb4010000007f??8b0389d9ff505084c074??", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::RepairingSoundEffect()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func122::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func123
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CheckSkills", typeid(bool (CrewMember::*)()), "57565383ec1089cb8b89bc01000085c974??80bbb80100000074??8b01ff5050", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::CheckSkills()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func123::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func124
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetFrozen", typeid(bool (CrewMember::*)(bool )), "8a44240484c074??80b97c0100000075??c6817d01000000", argdata, 2, 1, &func);
}

__declspec(naked) bool CrewMember::SetFrozen(bool frozen)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// frozen
		call _func124::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func125
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetFrozenLocation", typeid(CrewMember *(CrewMember::*)(bool )), "!.8b44240488817d010000c20400", argdata, 2, 1, &func);
}

__declspec(naked) CrewMember *CrewMember::SetFrozenLocation(bool unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func125::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func126
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetTask", typeid(void (CrewMember::*)(bool , int , int )), "57568db980010000b9????????8d74240cf3a55e5f", argdata, 4, 5, &func);
}

__declspec(naked) void CrewMember::SetTask(bool unk1, int unk2, int unk3)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func126::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func127
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::FindSlot", typeid(int (CrewMember::*)(int , int , int , bool )), "5557565383ec3c89cb8b7c24508b6c24548a44245c8844241f8bb79001000085f6", argdata, 5, 1, &func);
}

__declspec(naked) int CrewMember::FindSlot(int unk1, int unk2, int unk3, bool unk4)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func127::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func128
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::CheckRoomPath", typeid(bool (CrewMember::*)(int , int )), "5557565383ec6c89cb8bb42480000000c744240c00000000c7442408ffffffff89742404", argdata, 3, 1, &func);
}

__declspec(naked) bool CrewMember::CheckRoomPath(int unk1, int unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func128::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func129
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::EmptySlot", typeid(void (CrewMember::*)()), "57565383ec2089cf8b998c00000085db78??83b9900000000078??", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::EmptySlot()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func129::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func130
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::ClearTask", typeid(int (CrewMember::*)()), "!.8b417c898184010000c78188010000ffffffffc7818001000004000000c3", argdata, 1, 1, &func);
}

__declspec(naked) int CrewMember::ClearTask()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func130::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func131
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetMoveSpeed", typeid(double (CrewMember::*)()), "5581ec????????894c2424c744244418e16500c74424489e5c75008d8424900000008944244c", argdata, 1, 9, &func);
}

__declspec(naked) double CrewMember::GetMoveSpeed()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push ecx
		push ebx
		push esi
		push edi
		call _func131::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func132
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Restart", typeid(unsigned int (CrewMember::*)()), "57565383ec3089cb8b01ff506c8944241cdb44241cd95330d95b2cc683b001000000", argdata, 1, 1, &func);
}

__declspec(naked) unsigned int CrewMember::Restart()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func132::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func133
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetDamageBoost", typeid(void (CrewMember::*)(float )), "!.d9442404d999b4040000c20400", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SetDamageBoost(float boost)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// boost
		call _func133::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func134
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetHealthBoost", typeid(int (CrewMember::*)(int )), "5383ec1889cb8b5424208b81b004000039d074??89d129c185c97e??894c240c", argdata, 2, 1, &func);
}

__declspec(naked) int CrewMember::SetHealthBoost(int boost)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// boost
		call _func134::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func135
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::InitializeSkills", typeid(void (CrewMember::*)()), "57565383ec1089cfbe????????bb????????891c2489f9e8????????83ec04", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::InitializeSkills()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func135::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func136
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetCloneReady", typeid(int (CrewMember::*)(bool )), "5583ec68894c24108b442470894424148844241bc744243418e16500", argdata, 2, 1, &func);
}

__declspec(naked) int CrewMember::SetCloneReady(bool cloneReady)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// cloneReady
		call _func136::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func137
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::Kill", typeid(int (CrewMember::*)(bool )), "5583ec68894c24148a44247088442418c744243418e16500c7442438b05c75008d542460", argdata, 2, 1, &func);
}

__declspec(naked) int CrewMember::Kill(bool unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func137::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func138
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetCurrentShip", typeid(int (CrewMember::*)(int )), "!.8b44240489813c0100008b91a0000000898268090000c20400", argdata, 2, 1, &func);
}

__declspec(naked) int CrewMember::SetCurrentShip(int unk1)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk1
		call _func138::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func139
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CheckFighting", typeid(void (CrewMember::*)()), "!.83b964010000000f95819d000000c3", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::CheckFighting()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func139::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func140
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetDeathNumber", typeid(int (CrewMember::*)(int )), "8b4424048981900300003b05????????7c??40a3????????c20400", argdata, 2, 1, &func);
}

__declspec(naked) int CrewMember::SetDeathNumber(int deathCount)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// deathCount
		call _func140::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func141
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ForceMindControl", typeid(CrewMember *(CrewMember::*)(bool )), "!.8b44240488818d030000c20400", argdata, 2, 1, &func);
}

__declspec(naked) CrewMember *CrewMember::ForceMindControl(bool mindControlled)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// mindControlled
		call _func141::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func142
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::RenderSkillUpAnimation", typeid(int (CrewMember::*)(int , int )), "5557565381ec????????894c24448b8424d0000000", argdata, 3, 1, &func);
}

__declspec(naked) int CrewMember::RenderSkillUpAnimation(int unk1, int unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func142::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func143
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::UpdateHealth", typeid(int (CrewMember::*)()), "5583ec68894c2410c744243418e16500c7442438bc5c75008d442460", argdata, 1, 1, &func);
}

__declspec(naked) int CrewMember::UpdateHealth()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func143::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func144
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetLocation", typeid(int64_t (CrewMember::*)()), "5383ec3889cbd905????????d84110d91c24e8????????", argdata, 1, 1, &func);
}

__declspec(naked) int64_t CrewMember::GetLocation()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func144::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func145
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::AtGoal", typeid(bool (CrewMember::*)()), "d9411cd9410cd8e1d9e1d905????????dde1dfe0ddd9f6c44575??d94110d86120", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::AtGoal()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func145::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func146
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::AtFinalGoal", typeid(bool (CrewMember::*)()), ".d9410cdaa194000000d9e1d905????????dde1dfe0ddd9f6c44575??", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::AtFinalGoal()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func146::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func147
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::OnRenderPath", typeid(void (CrewMember::*)()), "5383ec3889cb837904000f85????????e8????????84c075??83bb8c00000000", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::OnRenderPath()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func147::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func148
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::NeedFrozenLocation", typeid(bool (CrewMember::*)()), "5389cb80b97c0100000074??e8????????84c075??8a837d010000", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::NeedFrozenLocation()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func148::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func149
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::IsBusy", typeid(bool (CrewMember::*)()), "5389cb83796c0075??80b99d0000000075??e8????????84c074??8a837c010000eb??", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::IsBusy()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func149::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func150
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetCurrentSystem", typeid(bool (CrewMember::*)(ShipSystem *)), "565383ec1489cb8b742420c681b80100000089b1bc0100008b01ff505884c0", argdata, 2, 1, &func);
}

__declspec(naked) bool CrewMember::SetCurrentSystem(ShipSystem *system)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// system
		call _func150::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func151
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::OnRenderHealth", typeid(void (CrewMember::*)()), "5557565381ec????????89cb80b9b0010000000f85????????", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::OnRenderHealth()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func151::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func152
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetIntegerHealth", typeid(int (CrewMember::*)()), "80b9b00100000075??83ec08d9412cd97c2406668b442406b40c6689442404d96c2404", argdata, 1, 1, &func);
}

__declspec(naked) int CrewMember::GetIntegerHealth()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func152::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func153
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::WithinRect", typeid(bool (CrewMember::*)(int , int , int , int )), "565383ec048b5c24108b5424188b74241c85d279??01d385d279??", argdata, 5, 1, &func);
}

__declspec(naked) bool CrewMember::WithinRect(int x1, int x2, int y1, int y2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// y2
		push [ebp+16]		// y1
		push [ebp+12]		// x2
		push [ebp+8]		// x1
		call _func153::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func154
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetLongName", typeid(std::string *(CrewMember::*)(int )), "5383ec1889cb8b44242005????????890424e8????????83ec04", argdata, 2, 1, &func);
}

__declspec(naked) std::string *CrewMember::GetLongName(int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func154::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func155
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetName", typeid(int (CrewMember::*)(std::string *, bool )), "5583ec68894c24148a4424748844241bc744243418e16500", argdata, 3, 1, &func);
}

__declspec(naked) int CrewMember::SetName(std::string *name, bool unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// name
		call _func155::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func156
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetName", typeid(std::string *(CrewMember::*)(int )), ".5383ec1889cb8b44242005????????890424e8????????83ec0489d883c4185b", argdata, 2, 1, &func);
}

__declspec(naked) std::string *CrewMember::GetName(int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func156::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func157
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetCurrentTarget", typeid(int (CrewMember::*)(CrewTarget *, bool )), "57565383ec1089cb8b7424208a4424248844240f8b01ff504c", argdata, 3, 1, &func);
}

__declspec(naked) int CrewMember::SetCurrentTarget(CrewTarget *target, bool unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// target
		call _func157::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func158
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ContainsPoint", typeid(bool (CrewMember::*)(int , int , int , int )), "83ec08db44240cd9410cd905????????d84918d805????????d97c2402668b442402b40c66890424d92c24", argdata, 5, 1, &func);
}

__declspec(naked) bool CrewMember::ContainsPoint(int unk1, int unk2, int unk3, int unk4)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func158::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func159
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetMedbay", typeid(void (CrewMember::*)(float )), "5383ec0889cb8b01ff506084c075??d9eed9442410d9c9dae9dfe0f6c44575??", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SetMedbay(float unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func159::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func160
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::StartTeleport", typeid(int (CrewMember::*)()), ".83ec0c8b89a0000000e8????????83c40c", argdata, 1, 1, &func);
}

__declspec(naked) int CrewMember::StartTeleport()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func160::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func161
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::LoadState", typeid(int (CrewMember::*)(int )), "57565383ec2089cf8b742430893424e8????????d99fd0040000893424", argdata, 2, 1, &func);
}

__declspec(naked) int CrewMember::LoadState(int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func161::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func162
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::StartTeleportArrive", typeid(int (CrewMember::*)()), ".83ec0c8b89a0000000e8????????83c40c", argdata, 1, 1, &func);
}

__declspec(naked) int CrewMember::StartTeleportArrive()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func162::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func163
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Clone", typeid(int (CrewMember::*)()), "5583ec78894c241cc744244418e16500c7442448cc5c75008d442470", argdata, 1, 1, &func);
}

__declspec(naked) int CrewMember::Clone()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func163::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func164
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CheckForTeleport", typeid(void (CrewMember::*)()), "5383ec1889cb8b89a0000000e8????????84c074??c744240400000000", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::CheckForTeleport()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func164::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func165
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetPosition", typeid(void (CrewMember::*)(int , int )), "5383ec2889cb8b4424308b5424348944241cdb44241cd9510c", argdata, 3, 5, &func);
}

__declspec(naked) void CrewMember::SetPosition(int x, int y)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func165::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func166
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::StartRepair", typeid(bool (CrewMember::*)(Repairable *)), "57565383ec2089cbe8????????84c00f84????????8b0389d9ff5070", argdata, 2, 1, &func);
}

__declspec(naked) bool CrewMember::StartRepair(Repairable *repairing)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// repairing
		call _func166::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func167
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::UpdateRepair", typeid(int (CrewMember::*)()), "5583ec68894c2418c744243418e16500c7442438e05c75008d4424608944243cc7442440baaa4e00", argdata, 1, 1, &func);
}

__declspec(naked) int CrewMember::UpdateRepair()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func167::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func168
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetTooltip", typeid(TouchTooltip *(CrewMember::*)(int )), "5581ec????????894c2420c744244418e16500c7442448165d75008d8424b00000008944244c", argdata, 2, 1, &func);
}

__declspec(naked) TouchTooltip *CrewMember::GetTooltip(int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func168::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func169
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillTooltip", typeid(TouchTooltip *(CrewMember::*)(int , int , bool , bool , bool )), ".5589e581ec????????8a451c8885a7feffffc785ccfeffff18e16500c785d0feffff645d75008d55f8", argdata, 6, 1, &func);
}

__declspec(naked) TouchTooltip *CrewMember::GetSkillTooltip(int unk1, int unk2, bool unk3, bool unk4, bool unk5)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func169::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 20
	}
}

namespace _func170
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetPath", typeid(bool (CrewMember::*)(int )), "565383ec1489ce8b5c2420d9431cd9e8d9e0d9c9dae9dfe080e44580fc40", argdata, 2, 1, &func);
}

__declspec(naked) bool CrewMember::SetPath(int path)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// path
		call _func170::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func171
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetRoomPath", typeid(int (CrewMember::*)(int , int )), "5581ec????????894c2428c744245418e16500c7442458dc5d75008d8424900000008944245cc744246043d34e00", argdata, 3, 1, &func);
}

__declspec(naked) int CrewMember::SetRoomPath(int unk1, int unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func171::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func172
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::MoveToRoom", typeid(bool (CrewMember::*)(int , int , bool )), "5581ec????????894c242c8a8424c800000088442434c744246418e16500c7442468e25d75008d9424b0000000", argdata, 4, 1, &func);
}

__declspec(naked) bool CrewMember::MoveToRoom(int unk1, int unk2, bool unk3)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func172::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func173
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::RestorePosition", typeid(bool (CrewMember::*)()), "83ec1cc7442408010000008b81c4040000894424048b81c0040000890424e8????????", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::RestorePosition()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func173::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func174
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::ClearPath", typeid(int (CrewMember::*)()), "5581ec????????894c2438c744245418e16500c7442458e85d75008d8424900000008944245c", argdata, 1, 1, &func);
}

__declspec(naked) int CrewMember::ClearPath()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func174::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func175
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetRoom", typeid(double (CrewMember::*)(int )), "5557565383ec3c89cd83b990010000000f84????????e8????????89e9e8????????", argdata, 2, 9, &func);
}

__declspec(naked) double CrewMember::SetRoom(int room)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// room
		call _func175::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func176
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetMindControl", typeid(void (CrewMember::*)(bool )), "565383ec3489cb8a4424408844241f38818d0300000f84????????", argdata, 2, 5, &func);
}

__declspec(naked) void CrewMember::SetMindControl(bool mindControlled)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// mindControlled
		call _func176::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func177
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetNewGoal", typeid(bool (CrewMember::*)()), "5557565383ec4c89cd8b496885c974??e8????????c7456800000000", argdata, 1, 1, &func);
}

__declspec(naked) bool CrewMember::GetNewGoal()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func177::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func178
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::UpdateMovement", typeid(void (CrewMember::*)()), "5383ec5889cb8b81a0000000837838060f84????????d9412cd9eedae9dfe0f6c4050f84????????e8????????84c075??", argdata, 1, 5, &func);
}

__declspec(naked) void CrewMember::UpdateMovement()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func178::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func179
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::OnLoop", typeid(int (CrewMember::*)()), "5557565381ec????????894c242cc744246418e16500c7442468ee5d75008d8424e0000000", argdata, 1, 1, &func);
}

__declspec(naked) int CrewMember::OnLoop()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func179::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func180
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::CycleColorLayer", typeid(int (CrewMember::*)(int )), "5557565381ec????????894c2424c744244418e16500c74424486d6075008d8424800000008944244c", argdata, 2, 1, &func);
}

__declspec(naked) int CrewMember::CycleColorLayer(int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func180::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func181
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetSex", typeid(CrewMember *(CrewMember::*)(bool )), "565383ec1489cb8b7424208b89a000000089f20fb6c2890424", argdata, 2, 1, &func);
}

__declspec(naked) CrewMember *CrewMember::SetSex(bool male)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// male
		call _func181::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func182
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::constructor", typeid(int (CrewMember::*)(const CrewBlueprint &, int , bool , CrewAnimation *)), "5589e557565381ec????????898da8feffff8a45108885a4feffffc7850cffffff18e16500", argdata, 5, 1, &func);
}

__declspec(naked) int CrewMember::constructor(const CrewBlueprint &blueprint, int unk1, bool unk2, CrewAnimation *anim)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// anim
		push [ebp+16]		// unk2
		push [ebp+12]		// unk1
		push [ebp+8]		// blueprint
		call _func182::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func183
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::CreateCrewmember", typeid(void *(CrewMemberFactory::*)(int , int , bool )), "5589e581ec????????898d7cfeffff8a451088858bfeffff", argdata, 4, 1, &func);
}

__declspec(naked) void *CrewMemberFactory::CreateCrewmember(int unk1, int unk2, bool unk3)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func183::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func184
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::IsRace", typeid(bool (*)(std::string *)), "83ec1cc70424????????8b4c2420e8????????83ec0485c00f84????????c70424????????8b4c2420", argdata, 1, 0, &func);
}

__declspec(naked) bool CrewMemberFactory::IsRace(std::string *race)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// race
		call _func184::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func185
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::__BS_FUNCTION_DONT_USE", typeid(void (*)()), "!eb??c70424????????e8????????83ec0483c4185bc390c390", argdata, 0, 4, &func);
}

__declspec(naked) void CSurface::__BS_FUNCTION_DONT_USE()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func185::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func186
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::StartFrame", typeid(int (*)()), ".83ec1cc70424????????e8????????83ec0483c41c", argdata, 0, 2, &func);
}

__declspec(naked) int CSurface::StartFrame()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func186::func
		add esp, 0
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func187
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::FinishFrame", typeid(int (*)()), ".83ec0ce8????????e8????????83c40c", argdata, 0, 0, &func);
}

__declspec(naked) int CSurface::FinishFrame()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func187::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func188
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_ClearAll", typeid(int (*)()), ".83ec1cc70424????????e8????????83ec0483c41c", argdata, 0, 0, &func);
}

__declspec(naked) int CSurface::GL_ClearAll()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func188::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func189
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_ClearColor", typeid(int (*)()), ".83ec1cc70424????????e8????????83ec0483c41c", argdata, 0, 0, &func);
}

__declspec(naked) int CSurface::GL_ClearColor()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func189::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func190
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_SetViewPort", typeid(bool (*)(int , int , int , int )), ".83ec1c8b44242c8944240c8b442428894424088b44242489442404", argdata, 4, 2, &func);
}

__declspec(naked) bool CSurface::GL_SetViewPort(int x1, int y1, int x2, int y2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// y2
		push [ebp+16]		// x2
		push [ebp+12]		// y1
		push [ebp+8]		// x1
		call _func190::func
		add esp, 16
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func191
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PopScissor", typeid(int (*)()), ".83ec1c8b15????????a1????????89d129c1c1e90474??", argdata, 0, 0, &func);
}

__declspec(naked) int CSurface::GL_PopScissor()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func191::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func192
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_SetStencilMode", typeid(int (*)(int , int , int )), "565383ec148b4424208b5c24248b742428a3????????891d????????8935????????83f80174??", argdata, 3, 2, &func);
}

__declspec(naked) int CSurface::GL_SetStencilMode(int stencilMode, int unk1, int unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk2
		push [ebp+12]		// unk1
		push [ebp+8]		// stencilMode
		call _func192::func
		add esp, 12
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func193
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PopStencilMode", typeid(int (*)()), ".57565383ec108b1d????????8b0d????????89d829c8c1f8028d1480", argdata, 0, 0, &func);
}

__declspec(naked) int CSurface::GL_PopStencilMode()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func193::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func194
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_OrthoProjection", typeid(int (*)(float , float , float , float , float , float )), "83ec3cc70424????????e8????????83ec04e8????????d9442454dd5c2428d9442450dd5c2420d944244cdd5c2418d9442448dd5c2410", argdata, 6, 2, &func);
}

__declspec(naked) int CSurface::GL_OrthoProjection(float unk1, float unk2, float unk3, float unk4, float unk5, float unk6)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+28]		// unk6
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func194::func
		add esp, 24
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 24
	}
}

namespace _func195
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_LoadIdentity", typeid(int (*)()), ".83ec0ce8????????83c40c", argdata, 0, 0, &func);
}

__declspec(naked) int CSurface::GL_LoadIdentity()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func195::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func196
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PushMatrix", typeid(int (*)()), ".83ec0ce8????????83c40c", argdata, 0, 2, &func);
}

__declspec(naked) int CSurface::GL_PushMatrix()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func196::func
		add esp, 0
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func197
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PopMatrix", typeid(int (*)()), ".83ec0ce8????????83c40c", argdata, 0, 2, &func);
}

__declspec(naked) int CSurface::GL_PopMatrix()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func197::func
		add esp, 0
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func198
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_Rotate", typeid(int64_t (*)(float , float , float , float )), "83ec1cd9442420d9eed9c9dde1dfe0ddd980e44580fc4074??d944242c", argdata, 4, 2, &func);
}

__declspec(naked) int64_t CSurface::GL_Rotate(float angle, float x, float y, float z)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// z
		push [ebp+16]		// y
		push [ebp+12]		// x
		push [ebp+8]		// angle
		call _func198::func
		add esp, 16
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func199
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_Scale", typeid(int64_t (*)(float , float , float )), "83ec1cd9442420d9442424d9442428d9e8d9cbdde3dfe080e44580f44075??d9cadde3dfe080e44580f440", argdata, 3, 2, &func);
}

__declspec(naked) int64_t CSurface::GL_Scale(float x, float y, float z)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// z
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func199::func
		add esp, 12
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func200
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_Translate", typeid(int64_t (*)(float , float , float )), ".83ec1cd9442420d9442424d9442428d9eed9cbdde3dfe080e44580f44075??d9cadde3dfe080e445", argdata, 3, 2, &func);
}

__declspec(naked) int64_t CSurface::GL_Translate(float x, float y, float z)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// z
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func200::func
		add esp, 12
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func201
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_SetColor", typeid(int (*)(float , float , float , float )), ".83ec1cd944242cd95c240cd9442428d95c2408d9442424d95c2404d9442420d91c24", argdata, 4, 2, &func);
}

__declspec(naked) int CSurface::GL_SetColor(float r, float g, float b, float a)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// a
		push [ebp+16]		// b
		push [ebp+12]		// g
		push [ebp+8]		// r
		call _func201::func
		add esp, 16
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func202
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_RemoveColorTint", typeid(int (*)()), ".a1????????3b05????????74??83e810a3????????", argdata, 0, 0, &func);
}

__declspec(naked) int CSurface::GL_RemoveColorTint()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func202::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func203
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GetColorTint", typeid(Colorf *(*)(Colorf &)), "57568b44240c8b0d????????8b15????????39d175??d9e8d910d95004d95008", argdata, 1, 2, &func);
}

__declspec(naked) Colorf *CSurface::GetColorTint(Colorf &ref)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// ref
		call _func203::func
		add esp, 4
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func204
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_EnableBlend", typeid(int (*)()), ".83ec1cc70424????????e8????????83ec04c744240403030000c70424????????e8????????83ec0883c41c", argdata, 0, 0, &func);
}

__declspec(naked) int CSurface::GL_EnableBlend()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func204::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func205
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_DisableBlend", typeid(int (*)()), ".83ec1cc70424????????e8????????83ec0483c41c", argdata, 0, 0, &func);
}

__declspec(naked) int CSurface::GL_DisableBlend()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func205::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func206
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawLine", typeid(bool (*)(float , float , float , float , float , float , float , float , float )), ".83ec5cd9442470d91c24e8????????8d442410890424e8????????d9842480000000d84c241cd944247c", argdata, 9, 2, &func);
}

__declspec(naked) bool CSurface::GL_DrawLine(float x1, float y1, float x2, float y2, float lineWidth, float r, float g, float b, float a)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+40]		// a
		push [ebp+36]		// b
		push [ebp+32]		// g
		push [ebp+28]		// r
		push [ebp+24]		// lineWidth
		push [ebp+20]		// y2
		push [ebp+16]		// x2
		push [ebp+12]		// y1
		push [ebp+8]		// x1
		call _func206::func
		add esp, 36
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 36
	}
}

namespace _func207
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawRect", typeid(bool (*)(float , float , float , float , float , float , float , float )), "81ec????????8d442410890424e8????????d98424ac000000d84c241cd98424a8000000d84c2418d905????????dcf9", argdata, 8, 2, &func);
}

__declspec(naked) bool CSurface::GL_DrawRect(float x1, float y1, float x2, float y2, float r, float g, float b, float a)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+36]		// a
		push [ebp+32]		// b
		push [ebp+28]		// g
		push [ebp+24]		// r
		push [ebp+20]		// y2
		push [ebp+16]		// x2
		push [ebp+12]		// y1
		push [ebp+8]		// x1
		call _func207::func
		add esp, 32
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 32
	}
}

namespace _func208
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawRectOutline", typeid(bool (*)(float , float , float , float , float , float , float , float , float )), "81ec????????d984242c010000db842410010000d95c241cdb842414010000d95c2420db842418010000d95c2428db84241c010000d95c242cd9c0d80d????????d95c2424d91c24", argdata, 9, 2, &func);
}

__declspec(naked) bool CSurface::GL_DrawRectOutline(float x1, float y1, float x2, float y2, float width, float r, float g, float b, float a)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+40]		// a
		push [ebp+36]		// b
		push [ebp+32]		// g
		push [ebp+28]		// r
		push [ebp+24]		// width
		push [ebp+20]		// y2
		push [ebp+16]		// x2
		push [ebp+12]		// y1
		push [ebp+8]		// x1
		call _func208::func
		add esp, 36
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 36
	}
}

namespace _func209
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitImage", typeid(int (*)(GL_Texture *, float , float , float , float , float , float , float , float , float , bool )), ".83ec3c0fb64c2468d9442464d95c2420d9442460d95c241cd944245cd95c2418d9442458d95c2414d9442454d95c2410d9442450", argdata, 11, 2, &func);
}

__declspec(naked) int CSurface::GL_BlitImage(GL_Texture *tex, float unk2, float unk3, float unk4, float unk5, float unk6, float unk7, float unk8, float unk9, float unk10, bool unk11)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+48]		// unk11
		push [ebp+44]		// unk10
		push [ebp+40]		// unk9
		push [ebp+36]		// unk8
		push [ebp+32]		// unk7
		push [ebp+28]		// unk6
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// tex
		call _func209::func
		add esp, 44
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 44
	}
}

namespace _func210
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitPixelImage", typeid(bool (*)(GL_Texture *, float , float , float , float , float , float , float , float , float , bool )), ".83ec3c0fb64c24680fb615????????d9442464d95c2420d9442460d95c241cd944245cd95c2418d9442458d95c2414d9442454d95c2410d9442450d95c240c", argdata, 11, 2, &func);
}

__declspec(naked) bool CSurface::GL_BlitPixelImage(GL_Texture *tex, float unk2, float unk3, float unk4, float unk5, float unk6, float unk7, float unk8, float unk9, float unk10, bool unk11)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+48]		// unk11
		push [ebp+44]		// unk10
		push [ebp+40]		// unk9
		push [ebp+36]		// unk8
		push [ebp+32]		// unk7
		push [ebp+28]		// unk6
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// tex
		call _func210::func
		add esp, 44
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 44
	}
}

namespace _func211
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitImagePartial", typeid(int (*)(GL_Texture *, float , float , float , float , float , float , float , float , float , float , float , float , int , bool )), ".83ec3cd9442454d9442458807c24780075??d9c90fb615????????d9442464d95c242cd9442470d95c2428d944246cd95c2424d9442468d95c2420d9442460d95c241cd9c9d95c2418d944245cd95c2414d95c2410", argdata, 15, 2, &func);
}

__declspec(naked) int CSurface::GL_BlitImagePartial(GL_Texture *tex, float unk2, float unk3, float unk4, float unk5, float unk6, float unk7, float unk8, float unk9, float unk10, float unk11, float unk12, float unk13, int unk14, bool unk15)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+64]		// unk15
		push [ebp+60]		// unk14
		push [ebp+56]		// unk13
		push [ebp+52]		// unk12
		push [ebp+48]		// unk11
		push [ebp+44]		// unk10
		push [ebp+40]		// unk9
		push [ebp+36]		// unk8
		push [ebp+32]		// unk7
		push [ebp+28]		// unk6
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// tex
		call _func211::func
		add esp, 60
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 60
	}
}

namespace _func212
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_TilePixelImage", typeid(bool (*)(GL_Texture *, float , float , float , float , float , float , float , float , float , float , float )), "5557565383ec6c8bbc2480000000813d????????????????74??d97c245a668b44245ab40c6689442458d9842494000000", argdata, 12, 2, &func);
}

__declspec(naked) bool CSurface::GL_TilePixelImage(GL_Texture *tex, float unk2, float unk3, float unk4, float unk5, float unk6, float unk7, float unk8, float r, float g, float b, float a)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+52]		// a
		push [ebp+48]		// b
		push [ebp+44]		// g
		push [ebp+40]		// r
		push [ebp+36]		// unk8
		push [ebp+32]		// unk7
		push [ebp+28]		// unk6
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// tex
		call _func212::func
		add esp, 48
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 48
	}
}

namespace _func213
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_CreateFrameBuffer", typeid(void *(*)()), ".83ec4c8d44243489442404c70424????????ff15????????83ec088b44243489442404c70424????????ff15????????", argdata, 0, 0, &func);
}

__declspec(naked) void *CSurface::GL_CreateFrameBuffer()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func213::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func214
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BindFrameBuffer", typeid(int (*)(GL_FrameBuffer *)), ".83ec1c8b44242085c074??8b0089442404c70424????????ff15????????83ec08eb??", argdata, 1, 2, &func);
}

__declspec(naked) int CSurface::GL_BindFrameBuffer(GL_FrameBuffer *buf)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// buf
		call _func214::func
		add esp, 4
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func215
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitFrameBuffer", typeid(int (*)(GL_FrameBuffer *, float , float , bool )), ".57565383ec308a5c244ca1????????890424e8????????83ec048b4424408b400489442404a1????????", argdata, 4, 2, &func);
}

__declspec(naked) int CSurface::GL_BlitFrameBuffer(GL_FrameBuffer *buf, float unk1, float unk2, bool unk3)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// unk3
		push [ebp+16]		// unk2
		push [ebp+12]		// unk1
		push [ebp+8]		// buf
		call _func215::func
		add esp, 16
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func216
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_SetPrimitiveAntialias", typeid(int (*)(GL_Primitive *, bool )), ".8b4424048a54240885c074??885010", argdata, 2, 2, &func);
}

__declspec(naked) int CSurface::GL_SetPrimitiveAntialias(GL_Primitive *prim, bool unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// prim
		call _func216::func
		add esp, 8
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func217
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_DestroyPrimitive", typeid(void (*)(GL_Primitive *)), ".5383ec188b5c242085db74??8b432c85c074??890424e8????????891c24e8????????83c4185b", argdata, 1, 6, &func);
}

__declspec(naked) void CSurface::GL_DestroyPrimitive(GL_Primitive *prim)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// prim
		call _func217::func
		add esp, 4
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func218
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateTrianglePrimitive", typeid(GL_Primitive *(*)(int , int , int , int , int , int , char )), ".575683ec64db442470d95c2448db442474d95c244cdb442478d95c2450db44247cd95c2454db842480000000d95c2458db842484000000d95c245cc744242000000000c744241c000000008d442448", argdata, 7, 2, &func);
}

__declspec(naked) GL_Primitive *CSurface::GL_CreateTrianglePrimitive(int unk1, int unk2, int unk3, int unk4, int unk5, int unk6, char unk7)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+32]		// unk7
		push [ebp+28]		// unk6
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func218::func
		add esp, 28
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 28
	}
}

namespace _func219
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateRectPrimitive", typeid(GL_Primitive *(*)(float , float , float , float , float , float , float , float )), ".575683ec64d9442470d9442474d9c9d9542430d9c9d9542434d9c1d8442478d9542438d9c9d954243cd9c9d95c2440d844247cd9542444d9c9", argdata, 8, 2, &func);
}

__declspec(naked) GL_Primitive *CSurface::GL_CreateRectPrimitive(float x1, float y1, float x2, float y2, float r, float g, float b, float a)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+36]		// a
		push [ebp+32]		// b
		push [ebp+28]		// g
		push [ebp+24]		// r
		push [ebp+20]		// y2
		push [ebp+16]		// x2
		push [ebp+12]		// y1
		push [ebp+8]		// x1
		call _func219::func
		add esp, 32
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 32
	}
}

namespace _func220
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateMultiRectPrimitive", typeid(GL_Primitive *(*)(int , float , float , float , float )), "5557565383ec5c8b7424708b7e042b3ec1ff0489f8c1e005890424e8????????89c385ff0f8e????????89fdc1e504ba????????895c24388b0edb0411d9188b0e", argdata, 5, 2, &func);
}

__declspec(naked) GL_Primitive *CSurface::GL_CreateMultiRectPrimitive(int arr, float r, float g, float b, float a)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+24]		// a
		push [ebp+20]		// b
		push [ebp+16]		// g
		push [ebp+12]		// r
		push [ebp+8]		// arr
		call _func220::func
		add esp, 20
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 20
	}
}

namespace _func221
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateRectOutlinePrimitive", typeid(GL_Primitive *(*)(int , int , int , int , float , float , float , float , float )), ".575681ec????????d98424ac000000db842490000000db842494000000d9c2d80d????????d9cad9542430d9c1d8c3d9542434d9c1da842498000000d9542438d9c9d95c243cd9c0d8e4d9542440", argdata, 9, 2, &func);
}

__declspec(naked) GL_Primitive *CSurface::GL_CreateRectOutlinePrimitive(int x1, int y1, int x2, int y2, float width, float r, float g, float b, float a)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+40]		// a
		push [ebp+36]		// b
		push [ebp+32]		// g
		push [ebp+28]		// r
		push [ebp+24]		// width
		push [ebp+20]		// y2
		push [ebp+16]		// x2
		push [ebp+12]		// y1
		push [ebp+8]		// x1
		call _func221::func
		add esp, 36
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 36
	}
}

namespace _func222
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateMultiLinePrimitive", typeid(GL_Primitive *(*)(int , float , float , float , float , float )), ".57565383ec408b7424508b7e042b3ec1ff0489f8c1e004890424e8????????89c385ff7e??89f9c1e104ba????????", argdata, 6, 2, &func);
}

__declspec(naked) GL_Primitive *CSurface::GL_CreateMultiLinePrimitive(int arr, float width, float r, float g, float b, float a)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+28]		// a
		push [ebp+24]		// b
		push [ebp+20]		// g
		push [ebp+16]		// r
		push [ebp+12]		// width
		push [ebp+8]		// arr
		call _func222::func
		add esp, 24
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 24
	}
}

namespace _func223
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateCirclePrimitive", typeid(GL_Primitive *(*)(int , int , float , float , float , float , float )), ".5557565381ec????????db842470020000d9542438d99c2418010000db842474020000d954243cd99c241c0100008d742440bf????????bb????????bd????????43d905????????57da0c248d642404d835????????", argdata, 7, 2, &func);
}

__declspec(naked) GL_Primitive *CSurface::GL_CreateCirclePrimitive(int unk1, int unk2, float unk3, float unk4, float unk5, float unk6, float unk7)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+32]		// unk7
		push [ebp+28]		// unk6
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func223::func
		add esp, 28
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 28
	}
}

namespace _func224
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreatePiePartialPrimitive", typeid(GL_Primitive *(*)(int , int , float , float , float , float , float , float , float , float )), ".57565381ec????????8b9c24c00200008bbc24c4020000d98424cc020000d95c2438be????????d98424d0020000d9442438d9c9dae9dfe0f6c44575??83fe4a0f85????????d905????????d98424d8020000d8f1d99c24a0020000d98424dc020000d8f1", argdata, 10, 2, &func);
}

__declspec(naked) GL_Primitive *CSurface::GL_CreatePiePartialPrimitive(int unk1, int unk2, float unk3, float unk4, float unk5, float unk6, float unk7, float unk8, float unk9, float unk10)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+44]		// unk10
		push [ebp+40]		// unk9
		push [ebp+36]		// unk8
		push [ebp+32]		// unk7
		push [ebp+28]		// unk6
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func224::func
		add esp, 40
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 40
	}
}

namespace _func225
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawShield", typeid(bool (*)(int , int , float , float , int , int , float , float , float , float )), ".565381ec????????8b9c24a00000008bb424a4000000b8????????e8????????d9842498000000d8a424b4000000d95c2434d984249c000000d8b42498000000d84c2434d95c24388d442440890424", argdata, 10, 2, &func);
}

__declspec(naked) bool CSurface::GL_DrawShield(int x, int y, float unk3, float unk4, int unk5, int unk6, float unk7, float unk8, float unk9, float unk10)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+44]		// unk10
		push [ebp+40]		// unk9
		push [ebp+36]		// unk8
		push [ebp+32]		// unk7
		push [ebp+28]		// unk6
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func225::func
		add esp, 40
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 40
	}
}

namespace _func226
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawLaser", typeid(bool (*)(int , int , int , int , float , float , float )), ".57565381ec????????8bb424180100008b9c241c010000e8????????89f7c1ef1f01f7d1ffc744240800000000db842414010000d95c240489f8038424100100008944242cdb44242cd91c24e8????????", argdata, 7, 2, &func);
}

__declspec(naked) bool CSurface::GL_DrawLaser(int x1, int y1, int x2, int y2, float r, float g, float b)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+32]		// b
		push [ebp+28]		// g
		push [ebp+24]		// r
		push [ebp+20]		// y2
		push [ebp+16]		// x2
		push [ebp+12]		// y1
		push [ebp+8]		// x1
		call _func226::func
		add esp, 28
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 28
	}
}

namespace _func227
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawEllipse", typeid(bool (*)(int , int , int , int , float , float , float , float )), ".57565383ec708bbc24840000008bb4248c0000008d442448890424e8????????d9842490000000d84c2448d95c241cd9842494000000d84c244cd95c2420", argdata, 8, 2, &func);
}

__declspec(naked) bool CSurface::GL_DrawEllipse(int x1, int y1, int x2, int y2, float unk5, float unk6, float unk7, float unk8)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+36]		// unk8
		push [ebp+32]		// unk7
		push [ebp+28]		// unk6
		push [ebp+24]		// unk5
		push [ebp+20]		// y2
		push [ebp+16]		// x2
		push [ebp+12]		// y1
		push [ebp+8]		// x1
		call _func227::func
		add esp, 32
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 32
	}
}

namespace _func228
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawCirclePartial", typeid(bool (*)(int , int , float , float , float , float , float , float )), "5381ec????????8d442440890424e8????????d98424a0000000d84c2440d95c241cd98424a4000000d84c2444d95c2424", argdata, 8, 2, &func);
}

__declspec(naked) bool CSurface::GL_DrawCirclePartial(int x, int y, float unk3, float ang, float r, float g, float b, float a)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+36]		// a
		push [ebp+32]		// b
		push [ebp+28]		// g
		push [ebp+24]		// r
		push [ebp+20]		// ang
		push [ebp+16]		// unk3
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func228::func
		add esp, 32
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 32
	}
}

namespace _func229
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawCircle", typeid(bool (*)(int , int , float , float , float , float , float )), ".83ec2cd9442448d95c241cd9442444d95c2418d9442440d95c2414d944243cd95c2410c744240c0000b943d9442438d95c2408", argdata, 7, 2, &func);
}

__declspec(naked) bool CSurface::GL_DrawCircle(int x, int y, float unk3, float r, float g, float b, float a)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+32]		// a
		push [ebp+28]		// b
		push [ebp+24]		// g
		push [ebp+20]		// r
		push [ebp+16]		// unk3
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func229::func
		add esp, 28
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 28
	}
}

namespace _func230
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_PushScissor", typeid(bool (*)(int , int , int , int )), ".575683ec248b442430894424108b442434894424148b442438894424188b44243c8944241c", argdata, 4, 2, &func);
}

__declspec(naked) bool CSurface::GL_PushScissor(int unk1, int unk2, int unk3, int unk4)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func230::func
		add esp, 16
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func231
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_SetScissor", typeid(int (*)(int , int , int , int )), "83ec1ca1????????a3????????8b44242c8944240c8b442428894424088b442424894424048b442420", argdata, 4, 2, &func);
}

__declspec(naked) int CSurface::GL_SetScissor(int unk1, int unk2, int unk3, int unk4)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func231::func
		add esp, 16
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func232
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PushStencilMode", typeid(int (*)()), ".575683ec14a1????????3b05????????74??85c074??be????????b9????????89c7f3a5", argdata, 0, 0, &func);
}

__declspec(naked) int CSurface::GL_PushStencilMode()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func232::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func233
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_SetColorTint", typeid(int (*)(float , float , float , float )), ".575683ec14a1????????3b05????????74??85c074??b9????????89c78d742420f3a58305??????????eb??8d54242089542404890424b9????????", argdata, 4, 2, &func);
}

__declspec(naked) int CSurface::GL_SetColorTint(float r, float g, float b, float a)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// a
		push [ebp+16]		// b
		push [ebp+12]		// g
		push [ebp+8]		// r
		call _func233::func
		add esp, 16
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func234
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateMultiColorPrimitive", typeid(int (*)(GL_Texture *, int )), ".5557565383ec6cc744243418e16500c74424380ca575008d4424608944243cc7442440d0f96200896424448d44241c890424e8????????8b8c24840000008b51048b0139c2", argdata, 2, 2, &func);
}

__declspec(naked) int CSurface::GL_CreateMultiColorPrimitive(GL_Texture *tex, int arr)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// arr
		push [ebp+8]		// tex
		call _func234::func
		add esp, 8
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func235
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitMultiColorImage", typeid(int (*)(GL_Texture *, int , unsigned char )), ".5557565381ec????????8a8424a80000008844242bc744244418e16500c744244812a575008d9424800000008954244cc74424508ffd6200896424548d44242c", argdata, 3, 2, &func);
}

__declspec(naked) int CSurface::GL_BlitMultiColorImage(GL_Texture *tex, int arr, unsigned char unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk
		push [ebp+12]		// arr
		push [ebp+8]		// tex
		call _func235::func
		add esp, 12
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func236
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateMultiImagePrimitive", typeid(int (*)(GL_Texture *, int , float , float , float , float )), ".83ec1c8b5424248b4a048b0239c174??29c1c1f904f6c10374??894c2404c70424????????e8????????b8????????eb??d9442434d95c240cd9442430d95c2408d944242cd95c2404", argdata, 6, 2, &func);
}

__declspec(naked) int CSurface::GL_CreateMultiImagePrimitive(GL_Texture *tex, int arr, float r, float g, float b, float a)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+28]		// a
		push [ebp+24]		// b
		push [ebp+20]		// g
		push [ebp+16]		// r
		push [ebp+12]		// arr
		push [ebp+8]		// tex
		call _func236::func
		add esp, 24
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 24
	}
}

namespace _func237
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawFadingDottedLine", typeid(bool (*)(int , int , int , int , float , float , float , float , float , float )), ".55565381ec????????c784249400000018e16500c78424980000001ea575008d8424600100008984249c000000c78424a00000003109630089a424a40000008d44247c890424e8????????d9e8", argdata, 10, 2, &func);
}

__declspec(naked) bool CSurface::GL_DrawFadingDottedLine(int x1, int y1, int x2, int y2, float unk1, float unk2, float r, float g, float b, float a)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+44]		// a
		push [ebp+40]		// b
		push [ebp+36]		// g
		push [ebp+32]		// r
		push [ebp+28]		// unk2
		push [ebp+24]		// unk1
		push [ebp+20]		// y2
		push [ebp+16]		// x2
		push [ebp+12]		// y1
		push [ebp+8]		// x1
		call _func237::func
		add esp, 40
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 40
	}
}

namespace _func238
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_RenderPrimitiveWithColor", typeid(int (*)(GL_Primitive *, float , float , float , float )), ".55565381ec????????c744245418e16500c74424582aa575008d8424900000008944245cc7442460a30f6300896424648d44243c", argdata, 5, 2, &func);
}

__declspec(naked) int CSurface::GL_RenderPrimitiveWithColor(GL_Primitive *prim, float r, float g, float b, float a)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+24]		// a
		push [ebp+20]		// b
		push [ebp+16]		// g
		push [ebp+12]		// r
		push [ebp+8]		// prim
		call _func238::func
		add esp, 20
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 20
	}
}

namespace _func239
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_RenderPrimitiveWithAlpha", typeid(int (*)(GL_Primitive *, float )), ".83ec2cd9442434d95c2410d9e8d954240cd9542408d95c24048b442430890424e8????????83c42c", argdata, 2, 2, &func);
}

__declspec(naked) int CSurface::GL_RenderPrimitiveWithAlpha(GL_Primitive *prim, float alpha)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// alpha
		push [ebp+8]		// prim
		call _func239::func
		add esp, 8
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func240
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_RenderPrimitiveWithColor", typeid(int (*)(GL_Primitive *)), ".83ec2cd9e8d9542410d954240cd9542408d95c24048b442430890424e8????????", argdata, 1, 2, &func);
}

__declspec(naked) int CSurface::GL_RenderPrimitiveWithColor(GL_Primitive *prim)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// prim
		call _func240::func
		add esp, 4
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func241
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::AddTexVertices", typeid(int (*)(int , float , float , float , float , float , float , float , float )), ".5557565383ec4c8b5c24608b43048944241c8b1389c529d5c1fd048d7c2430b9????????b000", argdata, 9, 2, &func);
}

__declspec(naked) int CSurface::AddTexVertices(int arr, float unk2, float unk3, float unk4, float unk5, float unk6, float unk7, float unk8, float unk9)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+40]		// unk9
		push [ebp+36]		// unk8
		push [ebp+32]		// unk7
		push [ebp+28]		// unk6
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// arr
		call _func241::func
		add esp, 36
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 36
	}
}

namespace _func242
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateImagePartialPrimitive", typeid(GL_Primitive *(*)(GL_Texture *, float , float , float , float , float , float , float , float , float , float , float , float , int , bool )), ".83ec4cd9442464d944246880bc24880000000075??d9c9c744243000000000d9442474d95c242cd9842480000000d95c2428d944247cd95c2424", argdata, 15, 2, &func);
}

__declspec(naked) GL_Primitive *CSurface::GL_CreateImagePartialPrimitive(GL_Texture *tex, float unk2, float unk3, float unk4, float unk5, float unk6, float unk7, float unk8, float unk9, float unk10, float unk11, float unk12, float unk13, int unk14, bool unk15)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+64]		// unk15
		push [ebp+60]		// unk14
		push [ebp+56]		// unk13
		push [ebp+52]		// unk12
		push [ebp+48]		// unk11
		push [ebp+44]		// unk10
		push [ebp+40]		// unk9
		push [ebp+36]		// unk8
		push [ebp+32]		// unk7
		push [ebp+28]		// unk6
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// tex
		call _func242::func
		add esp, 60
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 60
	}
}

namespace _func243
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreatePixelImagePrimitive", typeid(GL_Primitive *(*)(GL_Texture *, float , float , float , float , float , float , float , float , float , bool )), ".83ec5cd944246cd9442470d9442478d944247cd98424800000008a942488000000d9e8d9cbdde3dfe0f6c44574??d9cadde3dfe0f6c44574??d9c9dde3dfe0dddbf6c44575??d9cad9c9eb??", argdata, 11, 2, &func);
}

__declspec(naked) GL_Primitive *CSurface::GL_CreatePixelImagePrimitive(GL_Texture *tex, float unk2, float unk3, float unk4, float unk5, float unk6, float unk7, float unk8, float unk9, float unk10, bool unk11)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+48]		// unk11
		push [ebp+44]		// unk10
		push [ebp+40]		// unk9
		push [ebp+36]		// unk8
		push [ebp+32]		// unk7
		push [ebp+28]		// unk6
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// tex
		call _func243::func
		add esp, 44
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 44
	}
}

namespace _func244
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateImagePrimitive", typeid(GL_Primitive *(*)(GL_Texture *, float , float , float , float , float , float , float , float , float )), ".83ec3cc744242800000000d9442464d95c2424d9442460d95c2420d944245cd95c241cd9442458d95c2418d9442454d95c2414d9442450d95c2410d944244cd95c240cd9442448d95c2408d9442444d95c24048b442440890424e8????????c6401001", argdata, 10, 2, &func);
}

__declspec(naked) GL_Primitive *CSurface::GL_CreateImagePrimitive(GL_Texture *tex, float unk2, float unk3, float unk4, float unk5, float unk6, float unk7, float unk8, float unk9, float unk10)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+44]		// unk10
		push [ebp+40]		// unk9
		push [ebp+36]		// unk8
		push [ebp+32]		// unk7
		push [ebp+28]		// unk6
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// tex
		call _func244::func
		add esp, 40
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 40
	}
}

namespace _func245
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Equipment::OnLoop", typeid(int (Equipment::*)()), "5557565383ec2c89cb8b41502b414cc1e8020f84????????c744241c000000008b4b48e8????????8b6c241c", argdata, 1, 1, &func);
}

__declspec(naked) int Equipment::OnLoop()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func245::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func246
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_print", typeid(int64_t (*)(int , float , float , char **)), "5383ec188b44242c8b188b442420890424b9????????e8????????83ec04", argdata, 4, 2, &func);
}

__declspec(naked) int64_t freetype::easy_print(int fontType, float x, float y, char **text)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// text
		push [ebp+16]		// y
		push [ebp+12]		// x
		push [ebp+8]		// fontType
		call _func246::func
		add esp, 16
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func247
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printAutoNewlines", typeid(int64_t (*)(int , float , float , int , std_string *)), "565383ec248b5c24308b4424408b30891c24b9????????e8????????83ec0489742414", argdata, 5, 2, &func);
}

__declspec(naked) int64_t freetype::easy_printAutoNewlines(int fontType, float x, float y, int unk, std_string *text)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+24]		// text
		push [ebp+20]		// unk
		push [ebp+16]		// y
		push [ebp+12]		// x
		push [ebp+8]		// fontType
		call _func247::func
		add esp, 20
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 20
	}
}

namespace _func248
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::print", typeid(int64_t (*)(int , float , float , char *)), "5581ec????????c744246418e16500c7442468f0a575008d8424100100008944246cc7442470ae64630089642474", argdata, 4, 2, &func);
}

__declspec(naked) int64_t freetype::print(int fontData, float x, float y, char *text)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// text
		push [ebp+16]		// y
		push [ebp+12]		// x
		push [ebp+8]		// fontData
		call _func248::func
		add esp, 16
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func249
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::printCenter", typeid(int (*)(int , float , float , char *)), "57565383ec408b5c24508b7c245c897c2414d903d97c242e668b44242eb40c668944242c", argdata, 4, 2, &func);
}

__declspec(naked) int freetype::printCenter(int fontData, float x, float y, char *text)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// text
		push [ebp+16]		// y
		push [ebp+12]		// x
		push [ebp+8]		// fontData
		call _func249::func
		add esp, 16
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func250
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::measurePrintLines", typeid(int64_t (*)(int , int , int , int , int , char *)), "5581ec????????c744246418e16500c7442468faa575008d8424b00000008944246cc74424703e6d6300896424748d44244c", argdata, 6, 2, &func);
}

__declspec(naked) int64_t freetype::measurePrintLines(int fontData, int x, int y, int unk1, int unk2, char *text)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+28]		// text
		push [ebp+24]		// unk2
		push [ebp+20]		// unk1
		push [ebp+16]		// y
		push [ebp+12]		// x
		push [ebp+8]		// fontData
		call _func250::func
		add esp, 24
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 24
	}
}

namespace _func251
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("GetValue", typeid(int (*)(int , void *, int , int )), "57565383ec208b5c24348b742438c70424????????89d9e8????????83ec0485c0", argdata, 4, 0, &func);
}

__declspec(naked) int __stdcall GetValue(int unk1, void *resource, int difficulty, int unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// unk2
		push [ebp+16]		// difficulty
		push [ebp+12]		// resource
		push [ebp+8]		// unk1
		call _func251::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

float *__ptr_g_CloneSkillLossPercent;

namespace _var252
{
	static VariableDefinition varObj("g_CloneSkillLossPercent", "!(cdcccc3d)00007a44cdcc4c3d", &__ptr_g_CloneSkillLossPercent);
}

namespace _func253
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetDescription", typeid(int (InfoBox::*)(Description *, bool )), "565383ec2489cb8b7424308a4424348844241f8d490c893424e8????????83ec048d4b10", argdata, 3, 1, &func);
}

__declspec(naked) int InfoBox::SetDescription(Description *desc, bool unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// desc
		call _func253::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func254
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MainMenu::Close", typeid(bool (MainMenu::*)()), "5383ec0889cb8d8914030000e8????????8d8bb8110000e8????????8d8b54180000e8????????c683b411000000", argdata, 1, 1, &func);
}

__declspec(naked) bool MainMenu::Close()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func254::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func255
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("MainMenu::SaveFileExists", typeid(bool (*)()), ".5583", argdata, 0, 0, &func);
}

__declspec(naked) bool MainMenu::SaveFileExists()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func255::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func256
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MainMenu::OnKeyDown", typeid(bool (MainMenu::*)(int , bool )), ".5383", argdata, 3, 1, &func);
}

__declspec(naked) bool MainMenu::OnKeyDown(int key, bool unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// key
		call _func256::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func257
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MainMenu::MouseMove", typeid(int (MainMenu::*)(int , int )), ".5589", argdata, 3, 1, &func);
}

__declspec(naked) int MainMenu::MouseMove(int x, int y)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func257::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func258
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MainMenu::MouseUp", typeid(int (MainMenu::*)(int , int )), ".80B9", argdata, 3, 1, &func);
}

__declspec(naked) int MainMenu::MouseUp(int x, int y)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func258::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func259
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MainMenu::MouseRClick", typeid(int (MainMenu::*)(int , int )), ".80B9", argdata, 3, 1, &func);
}

__declspec(naked) int MainMenu::MouseRClick(int x, int y)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func259::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func260
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MainMenu::OpenShipBuilder", typeid(int (MainMenu::*)()), ".83EC", argdata, 1, 1, &func);
}

__declspec(naked) int MainMenu::OpenShipBuilder()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func260::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func261
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MainMenu::Choice", typeid(int (MainMenu::*)()), ".8B81", argdata, 1, 1, &func);
}

__declspec(naked) int MainMenu::Choice()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func261::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func262
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("MainMenu::GetTutorialShip", typeid(ShipManager *(*)()), ".83EC", argdata, 0, 0, &func);
}

__declspec(naked) ShipManager *MainMenu::GetTutorialShip()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func262::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func263
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MainMenu::GetShip", typeid(ShipManager *(MainMenu::*)()), ".83EC", argdata, 1, 1, &func);
}

__declspec(naked) ShipManager *MainMenu::GetShip()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func263::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func264
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MainMenu::MouseClick", typeid(int (MainMenu::*)(int , int )), ".5589", argdata, 3, 1, &func);
}

__declspec(naked) int MainMenu::MouseClick(int x, int y)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func264::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func265
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MainMenu::OnLoop", typeid(int (MainMenu::*)()), ".5581", argdata, 1, 1, &func);
}

__declspec(naked) int MainMenu::OnLoop()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func265::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func266
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MainMenu::OnRender", typeid(int (MainMenu::*)()), "55575681ec????????894c244cc744247418e16500c7442478528a75008d842410010000", argdata, 1, 1, &func);
}

__declspec(naked) int MainMenu::OnRender()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func266::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func267
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MainMenu::Open", typeid(bool (MainMenu::*)()), "5589e581ec????????898d6cfbffffc785acfbffff18e16500c785b0fbffffcc8a75008d45f88985b4fbffffc785b8fbffff3ec55b00", argdata, 1, 1, &func);
}

__declspec(naked) bool MainMenu::Open()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func267::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func268
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MainMenu::constructor", typeid(int (MainMenu::*)()), ".5581", argdata, 1, 1, &func);
}

__declspec(naked) int MainMenu::constructor()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func268::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func269
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MindSystem::ReleaseCrew", typeid(int (MindSystem::*)()), "5583ec78894c2428c744244418e16500c74424480c7475008d4424708944244cc74424502eac5400", argdata, 1, 1, &func);
}

__declspec(naked) int MindSystem::ReleaseCrew()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func269::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func270
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MindSystem::Jump", typeid(bool (MindSystem::*)()), ".5383ec1889cbe8????????89d9e8????????c70424????????89d9e8????????83ec0483c4185b", argdata, 1, 1, &func);
}

__declspec(naked) bool MindSystem::Jump()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func270::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func271
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MindSystem::GetControlLimit", typeid(int (MindSystem::*)()), ".83ec0ce8????????8b0485????????83c40c", argdata, 1, 1, &func);
}

__declspec(naked) int MindSystem::GetControlLimit()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func271::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func272
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MindSystem::Charged", typeid(bool (MindSystem::*)()), "5383ec0889cbe8????????84c075??8b0389d9ff502ceb??b000", argdata, 1, 1, &func);
}

__declspec(naked) bool MindSystem::Charged()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func272::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func273
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MindSystem::CanUse", typeid(bool (MindSystem::*)()), "5383ec0889cb80b9a00100000074??8b01ff501084c075??8b03", argdata, 1, 1, &func);
}

__declspec(naked) bool MindSystem::CanUse()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func273::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func274
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("OxygenSystem::__BS_FUNCTION_DONT_USE", typeid(void (*)()), "!83ec0cb9????????e8????????83c40cc39083ec0ce8????????83c40cc3", argdata, 0, 4, &func);
}

__declspec(naked) void OxygenSystem::__BS_FUNCTION_DONT_USE()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func274::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func275
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("OxygenSystem::OnRender", typeid(int (OxygenSystem::*)()), ".83ec0ce8????????83c40c", argdata, 1, 1, &func);
}

__declspec(naked) int OxygenSystem::OnRender()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func275::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func276
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("OxygenSystem::Restart", typeid(int (OxygenSystem::*)()), ".5383", argdata, 1, 1, &func);
}

__declspec(naked) int OxygenSystem::Restart()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func276::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func277
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::constructor", typeid(int (OxygenSystem::*)(int , int , int , int )), ".5583", argdata, 5, 1, &func);
}

__declspec(naked) int OxygenSystem::constructor(int unk1, int unk2, int unk3, int unk4)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func277::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func278
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("OxygenSystem::GetRefillSpeed", typeid(double (OxygenSystem::*)()), ".5383", argdata, 1, 9, &func);
}

__declspec(naked) double OxygenSystem::GetRefillSpeed()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push ecx
		push ebx
		push esi
		push edi
		call _func278::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func279
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::ModifyRoomOxygen", typeid(int (OxygenSystem::*)(int , float )), ".8b819c0100008b5424048d0490d900d8442408d918", argdata, 3, 1, &func);
}

__declspec(naked) int OxygenSystem::ModifyRoomOxygen(int roomId, float oxygen)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// oxygen
		push [ebp+8]		// roomId
		call _func279::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func280
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::SetRoomOxygen", typeid(int (OxygenSystem::*)(int , float )), ".8b81", argdata, 3, 1, &func);
}

__declspec(naked) int OxygenSystem::SetRoomOxygen(int roomId, float oxygen)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// oxygen
		push [ebp+8]		// roomId
		call _func280::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func281
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::ComputeAirLoss", typeid(int (OxygenSystem::*)(int , float , bool )), ".5556", argdata, 4, 1, &func);
}

__declspec(naked) int OxygenSystem::ComputeAirLoss(int unk1, float unk2, bool unk3)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func281::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func282
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::UpdateAirlock", typeid(int (OxygenSystem::*)(int , int )), ".5583", argdata, 3, 1, &func);
}

__declspec(naked) int OxygenSystem::UpdateAirlock(int unk1, int unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func282::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func283
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::UpdateBreach", typeid(int (OxygenSystem::*)(int , int , bool )), ".83EC", argdata, 4, 1, &func);
}

__declspec(naked) int OxygenSystem::UpdateBreach(int unk1, int unk2, bool unk3)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func283::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func284
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::EmptyOxygen", typeid(int (OxygenSystem::*)(int )), ".8B81", argdata, 2, 1, &func);
}

__declspec(naked) int OxygenSystem::EmptyOxygen(int roomId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// roomId
		call _func284::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func285
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("OxygenSystem::RedistributeOxygen", typeid(int (OxygenSystem::*)()), ".5557", argdata, 1, 1, &func);
}

__declspec(naked) int OxygenSystem::RedistributeOxygen()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func285::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func286
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("OxygenSystem::OnLoop", typeid(int (OxygenSystem::*)()), ".5553", argdata, 1, 1, &func);
}

__declspec(naked) int OxygenSystem::OnLoop()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func286::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func287
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Point::__BS_FUNCTION_DONT_USE", typeid(void (*)()), "c70424????????e8????????83c41cc3c701????????c7410401000080", argdata, 0, 4, &func);
}

__declspec(naked) void Point::__BS_FUNCTION_DONT_USE()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func287::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func288
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Point::constructor", typeid(void (Point::*)(int , int )), ".8b44240489018b442408894104", argdata, 3, 5, &func);
}

__declspec(naked) void Point::constructor(int x, int y)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func288::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func289
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Pointf::__BS_FUNCTION_DONT_USE", typeid(void (*)()), "d9442430d91c2489d9e8????????83ec0c83c4285bc2040090d9e8d9e0d911", argdata, 0, 4, &func);
}

__declspec(naked) void Pointf::__BS_FUNCTION_DONT_USE()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func289::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func290
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Pointf::constructor", typeid(void (Pointf::*)(float , float )), ".d9442404d919d9442408d95904", argdata, 3, 5, &func);
}

__declspec(naked) void Pointf::constructor(float x, float y)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func290::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func291
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::SelectChargeGoal", typeid(int (ProjectileFactory::*)()), "5383ec0889cbe8????????8b4b1c99f7b9ec0000004289939004000083c4085b", argdata, 1, 1, &func);
}

__declspec(naked) int ProjectileFactory::SelectChargeGoal()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func291::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func292
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::IsChargedGoal", typeid(bool (ProjectileFactory::*)()), ".8B41", argdata, 1, 1, &func);
}

__declspec(naked) bool ProjectileFactory::IsChargedGoal()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func292::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func293
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SetHacked", typeid(int (ProjectileFactory::*)(int )), ".83EC", argdata, 2, 1, &func);
}

__declspec(naked) int ProjectileFactory::SetHacked(int hacked)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// hacked
		call _func293::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func294
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SetCurrentShip", typeid(int (ProjectileFactory::*)(Targetable *)), ".8B44", argdata, 2, 1, &func);
}

__declspec(naked) int ProjectileFactory::SetCurrentShip(Targetable *ship)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// ship
		call _func294::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func295
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SetCooldownModifier", typeid(void (ProjectileFactory::*)(float )), ".D944", argdata, 2, 5, &func);
}

__declspec(naked) void ProjectileFactory::SetCooldownModifier(float cooldownMod)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// cooldownMod
		call _func295::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func296
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::ForceCoolup", typeid(int (ProjectileFactory::*)()), ".5383", argdata, 1, 1, &func);
}

__declspec(naked) int ProjectileFactory::ForceCoolup()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func296::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func297
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::RenderChargeBar", typeid(int (ProjectileFactory::*)(float )), ".83EC", argdata, 2, 1, &func);
}

__declspec(naked) int ProjectileFactory::RenderChargeBar(float unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func297::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func298
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::OnRender", typeid(int (ProjectileFactory::*)(float , bool )), ".5653", argdata, 3, 1, &func);
}

__declspec(naked) int ProjectileFactory::OnRender(float unk1, bool unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func298::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func299
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SetMount", typeid(int (ProjectileFactory::*)(bool , int , int , int , int )), ".5756", argdata, 6, 1, &func);
}

__declspec(naked) int ProjectileFactory::SetMount(bool unk1, int unk2, int unk3, int unk4, int unk5)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func299::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 20
	}
}

namespace _func300
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SetAutoFire", typeid(bool (ProjectileFactory::*)(bool )), ".8A44", argdata, 2, 1, &func);
}

__declspec(naked) bool ProjectileFactory::SetAutoFire(bool autoFiring)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// autoFiring
		call _func300::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func301
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::ReadyToFire", typeid(bool (ProjectileFactory::*)()), ".83B9", argdata, 1, 1, &func);
}

__declspec(naked) bool ProjectileFactory::ReadyToFire()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func301::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func302
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::FireNextShot", typeid(bool (ProjectileFactory::*)()), ".5389", argdata, 1, 1, &func);
}

__declspec(naked) bool ProjectileFactory::FireNextShot()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func302::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func303
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::StringToWeapon", typeid(int (*)(std_string *)), ".83EC", argdata, 1, 2, &func);
}

__declspec(naked) int ProjectileFactory::StringToWeapon(std_string *weaponType)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// weaponType
		call _func303::func
		add esp, 4
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func304
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::QueuedShots", typeid(bool (ProjectileFactory::*)()), ".8B81", argdata, 1, 1, &func);
}

__declspec(naked) bool ProjectileFactory::QueuedShots()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func304::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func305
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::SpendMissiles", typeid(int (ProjectileFactory::*)()), ".5583", argdata, 1, 1, &func);
}

__declspec(naked) int ProjectileFactory::SpendMissiles()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func305::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func306
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::NumTargetsRequired", typeid(int (ProjectileFactory::*)()), ".8B41", argdata, 1, 1, &func);
}

__declspec(naked) int ProjectileFactory::NumTargetsRequired()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func306::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func307
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::ClearAiming", typeid(int (ProjectileFactory::*)()), ".5756", argdata, 1, 1, &func);
}

__declspec(naked) int ProjectileFactory::ClearAiming()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func307::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func308
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SetPowered", typeid(int (ProjectileFactory::*)(bool )), ".8B44", argdata, 2, 1, &func);
}

__declspec(naked) int ProjectileFactory::SetPowered(bool unk1)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk1
		call _func308::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func309
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::ReconnectProjectile", typeid(int (ProjectileFactory::*)(Projectile *)), ".5653", argdata, 2, 1, &func);
}

__declspec(naked) int ProjectileFactory::ReconnectProjectile(Projectile *proj)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// proj
		call _func309::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func310
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::GetBoostLevel", typeid(int (ProjectileFactory::*)()), ".8B41", argdata, 1, 1, &func);
}

__declspec(naked) int ProjectileFactory::GetBoostLevel()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func310::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func311
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SaveProjectile", typeid(int (*)(Projectile *, int )), ".5653", argdata, 2, 2, &func);
}

__declspec(naked) int ProjectileFactory::SaveProjectile(Projectile *proj, int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// proj
		call _func311::func
		add esp, 8
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func312
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::LoadProjectile", typeid(Projectile *(*)(int )), ".5581", argdata, 1, 2, &func);
}

__declspec(naked) Projectile *ProjectileFactory::LoadProjectile(int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func312::func
		add esp, 4
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func313
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SaveState", typeid(int (ProjectileFactory::*)(int )), ".5557", argdata, 2, 1, &func);
}

__declspec(naked) int ProjectileFactory::SaveState(int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func313::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func314
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::Fire", typeid(int (ProjectileFactory::*)(int , int )), ".5756", argdata, 3, 1, &func);
}

__declspec(naked) int ProjectileFactory::Fire(int pointfArr, int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// pointfArr
		call _func314::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func315
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::LoadState", typeid(int (ProjectileFactory::*)(FileHelper *)), ".5557", argdata, 2, 1, &func);
}

__declspec(naked) int ProjectileFactory::LoadState(FileHelper *fileHelper)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// fileHelper
		call _func315::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func316
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::constructor", typeid(int (ProjectileFactory::*)(WeaponBlueprint *, int )), "5589e5575681ec????????898d08ffffffc7853cffffff18e16500c78540ffffff802b75008d45f8898544ffffffc78548ffffff49d0430089a54cffffff", argdata, 3, 1, &func);
}

__declspec(naked) int ProjectileFactory::constructor(WeaponBlueprint *bp, int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// bp
		call _func316::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func317
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::PreloadImage", typeid(int (*)(void *, int )), "83ec2c8d44241c89442404c70424????????ff15????????83ec088b44241c890424ff15????????83ec04", argdata, 2, 0, &func);
}

__declspec(naked) int ResourceControl::PreloadImage(void *lump, int size)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// size
		push [ebp+8]		// lump
		call _func317::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func318
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::GetFontData", typeid(int (ResourceControl::*)(int )), "5583ec68894c2414c744243418e16500c744243802a775008d4424608944243cc7442440beda6300", argdata, 2, 1, &func);
}

__declspec(naked) int ResourceControl::GetFontData(int fontSize)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// fontSize
		call _func318::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func319
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::UnlockShip", typeid(int (ScoreKeeper::*)(int , char , bool , bool )), "55565383ec70894c24208a8424880000008844242b8a94248c000000", argdata, 5, 1, &func);
}

__declspec(naked) int ScoreKeeper::UnlockShip(int shipType, char shipVariant, bool unk1, bool unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// unk2
		push [ebp+16]		// unk1
		push [ebp+12]		// shipVariant
		push [ebp+8]		// shipType
		call _func319::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func320
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::GetShipUnlocked", typeid(bool (ScoreKeeper::*)(int , int )), "555383ec74894c2414c744243418e16500c7442438242c75008d4424708944243cc74424405ff24300896424448d44241c", argdata, 3, 1, &func);
}

__declspec(naked) bool ScoreKeeper::GetShipUnlocked(int shipType, int shipVariant)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// shipVariant
		push [ebp+8]		// shipType
		call _func320::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func321
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::SaveSettings", typeid(int (*)()), "5589e55381ec????????c7850cfeffff18e16500c78510feffff0ea875008d45f8898514feffff", argdata, 0, 0, &func);
}

__declspec(naked) int Settings::SaveSettings()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func321::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func322
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::GetCommandConsole", typeid(bool (*)()), ".!a0????????c3", argdata, 0, 0, &func);
}

__declspec(naked) bool Settings::GetCommandConsole()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func322::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func323
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::SetSelectedRoom", typeid(int (Ship::*)(int )), "57565383ec1089ce8b7c24208b41088b510c29c2c1ea0274??bb????????", argdata, 2, 1, &func);
}

__declspec(naked) int Ship::SetSelectedRoom(int roomIndex)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// roomIndex
		call _func323::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func324
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::GetRoomCenter", typeid(int64_t (Ship::*)(int )), "83ec1c8b4104890424e8????????8b54242089142489c1e8????????83ec04", argdata, 2, 1, &func);
}

__declspec(naked) int64_t Ship::GetRoomCenter(int roomIndex)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// roomIndex
		call _func324::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func325
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::BreachSpecificHull", typeid(bool (Ship::*)(int , int , int )), "5581ec????????894c2414c744243418e16500c7442438cc6475008d8424800000008944243cc744244025975000", argdata, 4, 1, &func);
}

__declspec(naked) bool Ship::BreachSpecificHull(int ignore, int roomId, int slot)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// slot
		push [ebp+12]		// roomId
		push ecx			// this
		mov ecx, [ebp+8]	// ignore
		call _func325::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func326
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::CycleShipNext", typeid(int (ShipBuilder::*)()), "5383ec1889cb8b0985c974??8b01ff5004", argdata, 1, 1, &func);
}

__declspec(naked) int ShipBuilder::CycleShipNext()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func326::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func327
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::CycleShipPrevious", typeid(int (ShipBuilder::*)()), "5383ec1889cb8b0985c974??8b01", argdata, 1, 1, &func);
}

__declspec(naked) int ShipBuilder::CycleShipPrevious()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func327::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func328
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::SwapType", typeid(int (ShipBuilder::*)(int )), "5383ec1889cb8b0985c974??8b01ff5004", argdata, 2, 1, &func);
}

__declspec(naked) int ShipBuilder::SwapType(int type)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// type
		call _func328::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func329
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::SwitchShip", typeid(int (ShipBuilder::*)(int , int )), "5583ec78894c2420c744244418e16500c74424483a9275008d4424708944244cc7442450ff6b5d00", argdata, 3, 1, &func);
}

__declspec(naked) int ShipBuilder::SwitchShip(int ship, int type)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// type
		push [ebp+8]		// ship
		call _func329::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func330
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::CheckTypes", typeid(int (ShipBuilder::*)()), "565383ec1489cbc7442404010000008b81b8080000890424b9????????e8????????83ec0884c0", argdata, 1, 1, &func);
}

__declspec(naked) int ShipBuilder::CheckTypes()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func330::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func331
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::Open", typeid(int (ShipBuilder::*)()), "55575681ec????????894c2440c744247418e16500c7442478c29475008d8424d00400008944247c", argdata, 1, 1, &func);
}

__declspec(naked) int ShipBuilder::Open()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func331::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func332
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetSlotWorldPosition", typeid(Point (ShipGraph::*)(int , int )), "83ec3c8b018b5424448b04908904248d4c2418e8????????83ec048b4c2420", argdata, 4, 1, &func);
}

__declspec(naked) Point ShipGraph::GetSlotWorldPosition(int room, int slot)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// slot
		push [ebp+12]		// room
		push [ebp+8]		// implicit_output
		call _func332::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func333
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::DoorCount", typeid(int (ShipGraph::*)(int )), "8b4424048b51188b491c29d1c1f90239c87d??85c079??b8????????", argdata, 2, 1, &func);
}

__declspec(naked) int ShipGraph::DoorCount(int room)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// room
		call _func333::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func334
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetNumSlots", typeid(int (ShipGraph::*)(int )), ".8b018b5424048b04908b50348b42202b42188b4a1c2b4a1489cac1fa02c1e20501d0", argdata, 2, 1, &func);
}

__declspec(naked) int ShipGraph::GetNumSlots(int room)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// room
		call _func334::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func335
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("ShipGraph::GetIntoRoom", typeid(int (ShipGraph::*)(int , Point )), "83ec2c8b44243085c078??8b51042b11c1fa0239d07c??c7442404ffffffffc70424????????", argdata, 3, 1, &func);
}

__declspec(naked) int ShipGraph::GetIntoRoom(int room, Point unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk
		push [ebp+12]		// unk
		push [ebp+8]		// room
		call _func335::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func336
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetSelectedRoom", typeid(int (ShipGraph::*)(int , int , bool )), "5557565383ec1c89ce8a4c24388b068b560429c2c1ea0274??bb????????0fb6e98d3c9d????????8b0c38896c2408", argdata, 4, 1, &func);
}

__declspec(naked) int ShipGraph::GetSelectedRoom(int unk1, int unk2, bool unk3)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func336::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func337
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipGraph::RoomCount", typeid(int (ShipGraph::*)()), "!.8b41042b01c1f802c3", argdata, 1, 1, &func);
}

__declspec(naked) int ShipGraph::RoomCount()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func337::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func338
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetRoomShape", typeid(int (ShipGraph::*)(RoomShape *, int )), "57565383ec1089cf8b5424208b4424248b328b520429f2c1fa0285d2", argdata, 3, 1, &func);
}

__declspec(naked) int ShipGraph::GetRoomShape(RoomShape *ref, int room)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// room
		push ecx			// this
		mov ecx, [ebp+8]	// ref
		call _func338::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func339
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipGraph::ComputeCenter", typeid(int (ShipGraph::*)()), "5557565383ec3c89ce8b41042b01c1e80274??bb????????c7442418ffffffffbf????????", argdata, 1, 1, &func);
}

__declspec(naked) int ShipGraph::ComputeCenter()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func339::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func340
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetRoomBlackedOut", typeid(bool (ShipGraph::*)(int )), "!8b44240485c078??8b118b490429d1c1f90239c87c??b001c20400b001c204008b04828a4024c20400", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipGraph::GetRoomBlackedOut(int room)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// room
		call _func340::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func341
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::TranslateToGrid", typeid(Point (*)(int , int )), "5557565383ec3c8b5c24508b742454bf????????89f0f7ef894424188954241c", argdata, 3, 2, &func);
}

__declspec(naked) Point ShipGraph::TranslateToGrid(int x, int y)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// y
		push [ebp+12]		// x
		push [ebp+8]		// implicit_output
		call _func341::func
		add esp, 12
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func342
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::TranslateFromGrid", typeid(Point (*)(int , int )), "83ec2c8b4424308b5424348d14928d0cd5????????29d1894c24048d0480", argdata, 3, 2, &func);
}

__declspec(naked) Point ShipGraph::TranslateFromGrid(int x, int y)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// y
		push [ebp+12]		// x
		push [ebp+8]		// implicit_output
		call _func342::func
		add esp, 12
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func343
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("ShipGraph::TranslateToGrid", typeid(Point (*)(Point )), "!.83ec1c8b442424894424048b442420890424e8????????83c41cc3", argdata, 2, 2, &func);
}

__declspec(naked) Point ShipGraph::TranslateToGrid(Point point)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// point
		push [ebp+12]		// point
		push [ebp+8]		// implicit_output
		call _func343::func
		add esp, 12
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func344
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("ShipGraph::TranslateFromGrid", typeid(Point (*)(Point )), "!.83ec1c8b442424894424048b442420890424e8????????83c41cc3", argdata, 2, 2, &func);
}

__declspec(naked) Point ShipGraph::TranslateFromGrid(Point point)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// point
		push [ebp+12]		// point
		push [ebp+8]		// implicit_output
		call _func344::func
		add esp, 12
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func345
{
	static void *func = 0;
	static short argdata[] = {0x2ff, 0x2ff};
	static FunctionDefinition funcObj("ShipGraph::Adjacent", typeid(bool (*)(Point , Point )), "565383ec148b5c24288b74242c891c24897424048d4c2420e8????????83ec0884c075??", argdata, 2, 2, &func);
}

__declspec(naked) bool ShipGraph::Adjacent(Point point1, Point point2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// point2
		push [ebp+16]		// point2
		push [ebp+12]		// point1
		push [ebp+8]		// point1
		call _func345::func
		add esp, 16
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func346
{
	static void *func = 0;
	static short argdata[] = {0x2ff};
	static FunctionDefinition funcObj("ShipGraph::Valid", typeid(bool (*)(Point )), "!.8b442408837c24042777??85c078??83f8270f9ec0c3b000c3b000c3", argdata, 1, 2, &func);
}

__declspec(naked) bool ShipGraph::Valid(Point point)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// point
		push [ebp+8]		// point
		call _func346::func
		add esp, 8
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func347
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::Adjacent", typeid(bool (*)(int , int , int , int )), "83ec2c8b44243c894424048b4424388904248d4c2410e8????????83ec088b442434894424048b442430", argdata, 4, 2, &func);
}

__declspec(naked) bool ShipGraph::Adjacent(int x1, int y1, int x2, int y2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// y2
		push [ebp+16]		// x2
		push [ebp+12]		// y1
		push [ebp+8]		// x1
		call _func347::func
		add esp, 16
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func348
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ConnectingDoor", typeid(int (ShipGraph::*)(int , int , int , int )), "5557565383ec5c89cd8b5c24708b7424748b7c247889742404891c24e8????????84c0", argdata, 5, 1, &func);
}

__declspec(naked) int ShipGraph::ConnectingDoor(int unk1, int unk2, int unk3, int unk4)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func348::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func349
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ConnectedGridSquares", typeid(int (ShipGraph::*)(int , int , int , int )), "5557565383ec2c89cb8b442444894424048b442440890424e8????????89c789d5", argdata, 5, 1, &func);
}

__declspec(naked) int ShipGraph::ConnectedGridSquares(int x1, int y1, int x2, int y2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// y2
		push [ebp+16]		// x2
		push [ebp+12]		// y1
		push [ebp+8]		// x1
		call _func349::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func350
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x2ff};
	static FunctionDefinition funcObj("ShipGraph::ConnectedGridSquares", typeid(int (ShipGraph::*)(Point , Point )), "83ec1c8b44242c8944240c8b442428894424088b442424894424048b442420890424", argdata, 3, 1, &func);
}

__declspec(naked) int ShipGraph::ConnectedGridSquares(Point point1, Point point2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// point2
		push [ebp+16]		// point2
		push [ebp+12]		// point1
		push [ebp+8]		// point1
		call _func350::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func351
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::PopClosestDoor", typeid(int (*)(int , int )), "5557565383ec3c8b4424508b388b378b4424548b28d944b500d97c242e668b44242eb40c", argdata, 2, 0, &func);
}

__declspec(naked) int ShipGraph::PopClosestDoor(int unk1, int unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func351::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func352
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::OnInit", typeid(int (ShipGraph::*)(int , int )), "5583ec78894c241cc744244418e16500c7442448346875008d4424708944244cc7442450a2a55100896424548d44242c890424", argdata, 3, 1, &func);
}

__declspec(naked) int ShipGraph::OnInit(int unk1, int unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func352::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func353
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetRoomNeighbors", typeid(int (ShipGraph::*)(int , int )), "555383ec74894c2418c744243418e16500c74424383a6875008d4424708944243cc744244085a75100", argdata, 3, 1, &func);
}

__declspec(naked) int ShipGraph::GetRoomNeighbors(int ignore, int room)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// room
		push ecx			// this
		mov ecx, [ebp+8]	// ignore
		call _func353::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func354
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetDoors", typeid(int (ShipGraph::*)(int , int )), "5583ec68894c2428c744244418e16500c7442448406875008d4424608944244cc7442450c7a8510089642454", argdata, 3, 1, &func);
}

__declspec(naked) int ShipGraph::GetDoors(int unk1, int unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func354::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func355
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetConnectedRooms", typeid(int (ShipGraph::*)(int , int , bool )), "5583ec68894c24148a4424788844241bc744243418e16500c7442438466875008d5424608954243c", argdata, 4, 1, &func);
}

__declspec(naked) int ShipGraph::GetConnectedRooms(int ignore, int room, bool unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk
		push [ebp+12]		// room
		push ecx			// this
		mov ecx, [ebp+8]	// ignore
		call _func355::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func356
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ConnectivityDFSHelper", typeid(int (ShipGraph::*)(int , int , int , int )), "5581ec????????894c2438c744245418e16500c74424584e6875008d8424a00000008944245cc7442460c4ad510089642464", argdata, 5, 1, &func);
}

__declspec(naked) int ShipGraph::ConnectivityDFSHelper(int unk1, int unk2, int unk3, int unk4)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func356::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func357
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ConnectivityDFS", typeid(int (ShipGraph::*)(int , int )), "5581ec????????894c2420c744244418e16500c7442448586875008d8424800000008944244cc744245070b0510089642454", argdata, 3, 1, &func);
}

__declspec(naked) int ShipGraph::ConnectivityDFS(int ignore, int unk1)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk1
		push ecx			// this
		mov ecx, [ebp+8]	// ignore
		call _func357::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func358
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::IsRoomConnected", typeid(bool (ShipGraph::*)(int , int )), "5583ec68894c2418c744243418e16500c7442438626875008d4424608944243cc7442440c7b15100", argdata, 3, 1, &func);
}

__declspec(naked) bool ShipGraph::IsRoomConnected(int room1, int room2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// room2
		push [ebp+8]		// room1
		call _func358::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func359
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x101, 0x2ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::Dijkstra", typeid(int (ShipGraph::*)(int , Point , Point , int )), "5589e581ec????????898d2cffffff8b4514898548ffffff8b551889954cffffffc7856cffffff18e16500c78570ffffff686875008d4df8", argdata, 5, 1, &func);
}

__declspec(naked) int ShipGraph::Dijkstra(int ignore, Point unk1, Point unk2, int unk3)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+28]		// unk3
		push [ebp+24]		// unk2
		push [ebp+20]		// unk2
		push [ebp+16]		// unk1
		push [ebp+12]		// unk1
		push ecx			// this
		mov ecx, [ebp+8]	// ignore
		call _func359::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 24
	}
}

namespace _func360
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x101, 0x2ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::FindPath", typeid(int (ShipGraph::*)(int , Point , Point , int )), "5581ec????????894c24208b8424ac000000894424288b9424b00000008954242cc744245418e16500c74424587c6875008d8c2490000000", argdata, 5, 1, &func);
}

__declspec(naked) int ShipGraph::FindPath(int ignore, Point unk1, Point unk2, int unk3)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+28]		// unk3
		push [ebp+24]		// unk2
		push [ebp+20]		// unk2
		push [ebp+16]		// unk1
		push [ebp+12]		// unk1
		push ecx			// this
		mov ecx, [ebp+8]	// ignore
		call _func360::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 24
	}
}

namespace _func361
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetClosestSlot", typeid(int (ShipGraph::*)(int , Point , int , bool )), "55565381ec????????894c24488b8424c40000008944243c8b9424c8000000895424408a8c24d0000000", argdata, 5, 1, &func);
}

__declspec(naked) int ShipGraph::GetClosestSlot(int ignore, Point unk1, int unk2, bool unk3)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+24]		// unk3
		push [ebp+20]		// unk2
		push [ebp+16]		// unk1
		push [ebp+12]		// unk1
		push ecx			// this
		mov ecx, [ebp+8]	// ignore
		call _func361::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 20
	}
}

namespace _func362
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetShipInfo", typeid(ShipGraph *(*)(int )), "555781ec????????c744244418e16500c7442448dc6875008d8424c00000008944244cc74424504acc5100896424548d44242c890424e8????????", argdata, 1, 2, &func);
}

__declspec(naked) ShipGraph *ShipGraph::GetShipInfo(int isEnemy)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// isEnemy
		call _func362::func
		add esp, 4
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func363
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("ShipGraph::Restart", typeid(int (*)()), "555781ec????????c744244418e16500c7442448646975008d8424c00000008944244cc7442450d5d45100896424548d44242c", argdata, 0, 0, &func);
}

__declspec(naked) int ShipGraph::Restart()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func363::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func364
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipInfo::HasAugmentation", typeid(int (ShipInfo::*)(std_string *)), "555383ec74894c241cc744244418e16500c7442448d27175008d4424708944244cc744245069115400", argdata, 2, 1, &func);
}

__declspec(naked) int ShipInfo::HasAugmentation(std_string *a1)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// a1
		call _func364::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func365
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ManipulateDoors", typeid(bool (ShipManager::*)(int , bool )), "83ec1cc7442404000000008b4424208904248b09e8????????83ec08", argdata, 3, 1, &func);
}

__declspec(naked) bool ShipManager::ManipulateDoors(int doorIndex, bool open)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// open
		push [ebp+8]		// doorIndex
		call _func365::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func366
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::ContainsMindControlledEnemy", typeid(bool (ShipManager::*)()), "5756538b99c40000008b81c800000029d8c1f80285c074??89c6", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::ContainsMindControlledEnemy()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func366::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func367
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::UpgradeAll", typeid(int (ShipManager::*)()), "57565383ec1089cbc70424????????e8????????c74004190000008b431c", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::UpgradeAll()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func367::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func368
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::CanFitSubsystem", typeid(bool (ShipManager::*)()), "57565389ce8b41188b511c29c2c1ea0274??bb????????bf????????8b0c988b01ff90a0000000", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::CanFitSubsystem()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func368::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func369
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::HackingStunPulse", typeid(void (ShipManager::*)(int , float )), "56538b74240cd9442410d9eedde9dfe0f6c40574??8b81c40000008b91c800000029c2", argdata, 3, 5, &func);
}

__declspec(naked) void ShipManager::HackingStunPulse(int unk1, float unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func369::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func370
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CountBoarders", typeid(int (ShipManager::*)(int )), "5557565383ec0c89ce8b81c40000008b91c800000029c2c1ea0274??", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::CountBoarders(int roomIndex)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// roomIndex
		call _func370::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func371
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::DamageHull", typeid(int (ShipManager::*)(int , bool )), "5383ec2889cb8a4424348844241f8b01ff504084c074", argdata, 3, 1, &func);
}

__declspec(naked) int ShipManager::DamageHull(int damage, bool checkAugments)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// checkAugments
		push [ebp+8]		// damage
		call _func371::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func372
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ModifyScrapCount", typeid(int (ShipManager::*)(int , bool )), "5581ec????????894c24188a8424940000008844241cc744244418e16500c744244884697500", argdata, 3, 1, &func);
}

__declspec(naked) int ShipManager::ModifyScrapCount(int amt, bool checkAugments)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// checkAugments
		push [ebp+8]		// amt
		call _func372::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func373
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetCrewmember", typeid(CrewMember *(ShipManager::*)(int , int )), "5557565383ec0c89ce8b81c40000008b91c800000029c2c1ea0274??bb????????", argdata, 3, 1, &func);
}

__declspec(naked) CrewMember *ShipManager::GetCrewmember(int index, int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// index
		call _func373::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func374
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::FindCrew", typeid(CrewMember *(ShipManager::*)(CrewBlueprint &)), "5557565383ec3c8b7c24508b99c4000000895c24248b81c8000000", argdata, 2, 1, &func);
}

__declspec(naked) CrewMember *ShipManager::FindCrew(CrewBlueprint &blueprint)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// blueprint
		call _func374::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func375
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::ResetScrapLevel", typeid(int (ShipManager::*)()), ".c781500400001e000000a1????????83f80175??c781500400000a000000c383f80275??c7815004000000000000", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::ResetScrapLevel()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func375::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func376
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetSystemCount", typeid(int (ShipManager::*)()), "57565389ce8b51188b411c29d0c1e80274??bb????????bf????????8b0c9a8b01", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::GetSystemCount()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func376::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func377
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetSubsystemCount", typeid(int (ShipManager::*)()), "57565389ce8b51188b411c29d0c1e80274??bb????????bf????????8b0c9a8b01ff90a00000003c01", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::GetSubsystemCount()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func377::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func378
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::CountPlayerCrew", typeid(int (ShipManager::*)()), "5557565383ec0c89ce8b81c40000008b91c800000029c2c1ea0274??", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::CountPlayerCrew()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func378::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func379
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CountCrew", typeid(int (ShipManager::*)(bool )), ".5557565383ec1c89ce8a4424308844240f", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::CountCrew(bool unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func379::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func380
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CountCrewShipId", typeid(int (ShipManager::*)(int , int )), ".5557565383ec0c89ce8b81c40000008b91c8000000", argdata, 3, 1, &func);
}

__declspec(naked) int ShipManager::CountCrewShipId(int unk1, int unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func380::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func381
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::CheckBatteryPower", typeid(int (ShipManager::*)()), ".5557565383ec2c89cf8b49188b471c29c8c1f80285c0", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::CheckBatteryPower()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func381::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func382
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::IsCrewOverFull", typeid(bool (ShipManager::*)()), "5383ec1889cb837904000f95c00fb6c0890424b9????????e8????????83ec04", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::IsCrewOverFull()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func382::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func383
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::IsCrewFull", typeid(bool (ShipManager::*)()), ".5383ec1889cb837904000f95c00fb6c0890424b9????????e8????????83ec04837b0401", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::IsCrewFull()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func383::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func384
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::CheckCloakAchievement", typeid(bool (ShipManager::*)()), ".8a812406000083f001", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::CheckCloakAchievement()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func384::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func385
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::PauseLoop", typeid(int (ShipManager::*)()), ".83ec0c81c1????????e8????????83c40c", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::PauseLoop()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func385::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func386
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::UpdateReactor", typeid(PowerManager *(ShipManager::*)()), "57565383ec1089cb8b4104890424e8????????89c1e8????????8b4304890424", argdata, 1, 1, &func);
}

__declspec(naked) PowerManager *ShipManager::UpdateReactor()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func386::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func387
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ResistDamage", typeid(bool (ShipManager::*)(int , int )), "5583ec78894c241cc744244418e16500c74424488e6975008d442470", argdata, 3, 1, &func);
}

__declspec(naked) bool ShipManager::ResistDamage(int unk1, int unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func387::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func388
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetShowHacking", typeid(bool (ShipManager::*)()), "!.8a81a0000000c3", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::GetShowHacking()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func388::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func389
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SetShowHacking", typeid(ShipManager *(ShipManager::*)(bool )), "!.8b4424048881a0000000c20400", argdata, 2, 1, &func);
}

__declspec(naked) ShipManager *ShipManager::SetShowHacking(bool showHacking)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// showHacking
		call _func389::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func390
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetLastDamage", typeid(int (ShipManager::*)()), "!.8b8118040000c7811804000000000000c3", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::GetLastDamage()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func390::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func391
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::SetDestroyed", typeid(int (ShipManager::*)()), "565383ec1489cec68115040000018b41188b511c29c2", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::SetDestroyed()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func391::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func392
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::Blowup", typeid(int (ShipManager::*)()), ".83ec1cc744240400000000c70424????????e8????????83ec0883c41c", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::Blowup()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func392::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func393
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::DrainSuperShields", typeid(void (ShipManager::*)()), ".8b89a400000085c974??83ec0ce8????????83c40c", argdata, 1, 5, &func);
}

__declspec(naked) void ShipManager::DrainSuperShields()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func393::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func394
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::PowerSuperShields", typeid(int (ShipManager::*)()), ".8b89a400000085c974??83ec0ce8????????83c40c", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::PowerSuperShields()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func394::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func395
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::SystemJump", typeid(int (ShipManager::*)()), "57565389ce8b41188b511c29c2c1ea0274??bb????????8d3c9d????????8b0c38", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::SystemJump()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func395::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func396
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::JumpLeave", typeid(int (ShipManager::*)()), "5583ec68894c2418c744243418e16500c7442438966975008d4424608944243c", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::JumpLeave()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func396::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func397
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::DamageCrew", typeid(bool (ShipManager::*)(CrewMember *, int , int , int , int , int , int , int , int , int , int , int , int )), "5557565383ec2c8b5c24408b6c2468807c24720075??3b6b0475??eb??", argdata, 14, 1, &func);
}

__declspec(naked) bool ShipManager::DamageCrew(CrewMember *crew, int unk2, int unk3, int unk4, int unk5, int unk6, int unk7, int unk8, int unk9, int unk10, int unk11, int unk12, int unk13)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+56]		// unk13
		push [ebp+52]		// unk12
		push [ebp+48]		// unk11
		push [ebp+44]		// unk10
		push [ebp+40]		// unk9
		push [ebp+36]		// unk8
		push [ebp+32]		// unk7
		push [ebp+28]		// unk6
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// crew
		call _func397::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 52
	}
}

namespace _func398
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AssignRoom", typeid(void (ShipManager::*)(CrewMember *, int )), "!83ec1c8b4424248904248b4c2420e8????????83ec0483c41cc20800", argdata, 3, 5, &func);
}

__declspec(naked) void ShipManager::AssignRoom(CrewMember *crew, int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// crew
		call _func398::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func399
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SaveSuperDrones", typeid(int (ShipManager::*)(int )), "5583ec78894c2420c744244418e16500c74424489c6975008d4424708944244c", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::SaveSuperDrones(int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func399::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func400
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::DestroyBoardingDrones", typeid(int (ShipManager::*)()), "57565383ec1089ce8b81c40000008b91c800000029c2c1ea0274??bb????????", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::DestroyBoardingDrones()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func400::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func401
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::IntrudersArrived", typeid(bool (ShipManager::*)()), "57565389ce83b988050000007e??8b81c40000008b91c800000029c2", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::IntrudersArrived()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func401::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func402
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CheckForRepair", typeid(int (ShipManager::*)(int , int , int , int )), "5557565383ec4c89cb8b6c24608b7c24648b4424688b54246c89c6", argdata, 5, 1, &func);
}

__declspec(naked) int ShipManager::CheckForRepair(int x1, int y1, int x2, int y2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// y2
		push [ebp+16]		// x2
		push [ebp+12]		// y1
		push [ebp+8]		// x1
		call _func402::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func403
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::CanReceiveTeleport", typeid(bool (ShipManager::*)()), ".8079100075??8379040074??8a8186050000c3b001", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::CanReceiveTeleport()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func403::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func404
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::OnCleanup", typeid(int (ShipManager::*)()), "57565383ec1089cb8b41188b511c29c2c1ea0274??be????????", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::OnCleanup()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func404::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func405
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetRandomTargettingPoint", typeid(Pointf (ShipManager::*)(bool )), "565383ec1489cb807c24200075??e8????????eb??e8????????8b4b18", argdata, 3, 1, &func);
}

__declspec(naked) Pointf ShipManager::GetRandomTargettingPoint(bool unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// implicit_output
		call _func405::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func406
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::CheckSpreadDamage", typeid(int (ShipManager::*)()), "5557565383ec5c89cd8b41188b511c29c2c1ea020f84????????c744243c000000008b54243c", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::CheckSpreadDamage()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func406::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func407
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x101};
	static FunctionDefinition funcObj("ShipManager::GetCrewList", typeid(CrewMember **(ShipManager::*)(int )), ".5557565383ec1c89cb8b7c24308bafc80000002bafc4000000c701????????c7410400000000", argdata, 2, 1, &func);
}

__declspec(naked) CrewMember **ShipManager::GetCrewList(int ignore)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push ecx			// this
		mov ecx, [ebp+8]	// ignore
		call _func407::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func408
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemList", typeid(ShipSystem **(ShipManager::*)(int )), ".5557565383ec1c89cb8b7c24308b6f1c2b6f18c701????????c7410400000000c7410800000000c1fd0274??", argdata, 2, 1, &func);
}

__declspec(naked) ShipSystem **ShipManager::GetSystemList(int ignore)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// ignore
		call _func408::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func409
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetAvailablePower", typeid(int (ShipManager::*)()), ".83ec1c8b4104890424e8????????89c1e8????????83c41c", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::GetAvailablePower()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func409::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func410
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemPower", typeid(int (ShipManager::*)(int )), ".83ec0c8b81440400008b5424108b049083f8ff74??8b51188b0c82", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::GetSystemPower(int systemId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// systemId
		call _func410::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func411
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::ClearStatus", typeid(int (ShipManager::*)()), "565383ec1489ce8b41188b511c29c2c1ea0274??bb????????8b0c98", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::ClearStatus()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func411::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func412
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemAvailablePower", typeid(int (ShipManager::*)(int )), "57565389cb8b81440400008b5424108b049083f8ff74??8d3485????????", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::GetSystemAvailablePower(int systemId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// systemId
		call _func412::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func413
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemDamage", typeid(int (ShipManager::*)(int )), ".8b81440400008b5424048b049083f8ff74??8b51188b1482", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::GetSystemDamage(int systemId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// systemId
		call _func413::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func414
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemPowerLevel", typeid(int (ShipManager::*)(int )), ".8b81440400008b5424048b049083f8ff74??8b51188b14828b423c8b5240", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::GetSystemPowerLevel(int systemId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// systemId
		call _func414::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func415
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemHealth", typeid(int (ShipManager::*)(int )), ".8b81440400008b5424048b049083f8ff74??8b51188b04828b80ec000000", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::GetSystemHealth(int systemId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// systemId
		call _func415::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func416
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::IncreaseSystemPower", typeid(int (ShipManager::*)(int )), ".83ec1c8b81440400008b5424208b049083f8ff74??8b51188b0c82c744240400000000", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::IncreaseSystemPower(int systemId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// systemId
		call _func416::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func417
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemInRoom", typeid(ShipSystem *(ShipManager::*)(int )), "5557565383ec0c89ce8b6c24208b41188b511c29c2c1ea0274??bb????????8d3c9d????????", argdata, 2, 1, &func);
}

__declspec(naked) ShipSystem *ShipManager::GetSystemInRoom(int roomIndex)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// roomIndex
		call _func417::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func418
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystem", typeid(ShipSystem *(ShipManager::*)(int )), ".8b44240483f8ff74??8b91440400008b048283f8ff74??8b51188b0482", argdata, 2, 1, &func);
}

__declspec(naked) ShipSystem *ShipManager::GetSystem(int systemId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// systemId
		call _func418::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func419
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemRoom", typeid(Room *(ShipManager::*)(int )), ".83ec1c8b442420890424e8????????83ec0485c074??8b1089c1ff5258", argdata, 2, 1, &func);
}

__declspec(naked) Room *ShipManager::GetSystemRoom(int systemId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// systemId
		call _func419::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func420
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ForceDecreaseSystemPower", typeid(bool (ShipManager::*)(int )), ".83ec1c8b442420890424e8????????83ec0485c074??8b10c70424????????89c1ff9284000000", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipManager::ForceDecreaseSystemPower(int systemId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// systemId
		call _func420::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func421
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ForceIncreaseSystemPower", typeid(bool (ShipManager::*)(int )), ".83ec1c8b442420890424e8????????83ec0485c074??8b10c70424????????89c1", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipManager::ForceIncreaseSystemPower(int systemId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// systemId
		call _func421::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func422
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SetSystemDividePower", typeid(bool (ShipManager::*)(int , int )), ".83ec1c8b44242083f81175??8b4104890424e8????????8b542424891424", argdata, 3, 1, &func);
}

__declspec(naked) bool ShipManager::SetSystemDividePower(int systemId, int dividePower)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// dividePower
		push [ebp+8]		// systemId
		call _func422::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func423
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SetSystemPowerLoss", typeid(bool (ShipManager::*)(int , int )), ".83ec1c8b44242083f81175??8b4104890424e8????????8b542424", argdata, 3, 1, &func);
}

__declspec(naked) bool ShipManager::SetSystemPowerLoss(int systemId, int powerLoss)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// powerLoss
		push [ebp+8]		// systemId
		call _func423::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func424
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SetSystemPowerLimit", typeid(bool (ShipManager::*)(int , int )), ".83ec1c8b44242083f81175??8b4104890424e8????????8b542424891424", argdata, 3, 1, &func);
}

__declspec(naked) bool ShipManager::SetSystemPowerLimit(int systemId, int powerCap)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// powerCap
		push [ebp+8]		// systemId
		call _func424::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func425
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ClearStatus", typeid(int (ShipManager::*)(int )), ".83ec1c8b44242083f81175??8b4104890424e8????????89c1e8????????eb??", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::ClearStatus(int systemId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// systemId
		call _func425::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func426
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SystemLocked", typeid(bool (ShipManager::*)(int )), ".83ec0c8b81440400008b5424108b049083f8ff74??8b51188b0c82e8????????eb??", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipManager::SystemLocked(int systemId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// systemId
		call _func426::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func427
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SystemFunctions", typeid(bool (ShipManager::*)(int )), ".83ec0c8b81440400008b5424108b049083f8ff74??8b51188b0c828b01", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipManager::SystemFunctions(int systemId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// systemId
		call _func427::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func428
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::DoorsFunction", typeid(bool (ShipManager::*)()), "5383ec1889cbc70424????????e8????????83ec0484c074??", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::DoorsFunction()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func428::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func429
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ManipulateAllDoors", typeid(bool (ShipManager::*)(bool )), "565383ec1489cb0fb6742420e8????????84c074??8d8bf400000081e6????????893424", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipManager::ManipulateAllDoors(bool open)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// open
		call _func429::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func430
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::HasSystem", typeid(bool (ShipManager::*)()), ".8b44240483f81174??8b9144040000833c82ff0f95c0c20400", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::HasSystem()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func430::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func431
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SetBoostFTL", typeid(bool (ShipManager::*)(bool )), "5383ec0889cb8a44241088442407c70424????????e8????????83ec0484c074??", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipManager::SetBoostFTL(bool unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func431::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func432
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SetCloaked", typeid(bool (ShipManager::*)(bool )), "565383ec1489cb0fb6742420c70424????????e8????????83ec04", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipManager::SetCloaked(bool cloaked)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// cloaked
		call _func432::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func433
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::CanCloak", typeid(bool (ShipManager::*)()), "5383ec1889cbc70424????????e8????????83ec0484c0", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::CanCloak()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func433::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func434
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SetSafe", typeid(bool (ShipManager::*)(bool )), "5383ec1889cbe8????????c6835406000001c70424????????89d9e8????????", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipManager::SetSafe(bool safe)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// safe
		call _func434::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func435
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::CloneHealing", typeid(bool (ShipManager::*)()), "5557565383ec2c89cec70424????????e8????????83ec04", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::CloneHealing()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func435::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func436
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::InstantPowerShields", typeid(bool (ShipManager::*)()), ".5383ec1889cbc70424????????e8????????83ec0484c074??", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::InstantPowerShields()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func436::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func437
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::Wait", typeid(bool (ShipManager::*)()), "565383ec1489cbc70424????????e8????????83ec0484c074??8b8ba80000008b01", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::Wait()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func437::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func438
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CanFitSystem", typeid(bool (ShipManager::*)(int )), "57565383ec1089ce837c24200575??c70424????????e8????????83ec04", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipManager::CanFitSystem(int systemId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// systemId
		call _func438::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func439
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::JumpArrive", typeid(int (ShipManager::*)()), "5583ec78894c2428c744244418e16500c7442448a26975008d4424708944244cc74424505809520089642454", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::JumpArrive()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func439::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func440
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SystemRoom", typeid(int (ShipManager::*)(int )), "83ec0c8b81440400008b5424108b049083f8ff74??8b51188b0c828b01ff5058eb??", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::SystemRoom(int systemId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// systemId
		call _func440::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func441
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemPowerMax", typeid(int (ShipManager::*)(int )), ".8b81440400008b5424048b049083f8ff74??8b51188b04828b4040", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::GetSystemPowerMax(int systemId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// systemId
		call _func441::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func442
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CanUpgrade", typeid(int (ShipManager::*)(int , int )), "565383ec1489ce8b5c242083fb1175??e8????????b8????????", argdata, 3, 1, &func);
}

__declspec(naked) int ShipManager::CanUpgrade(int systemId, int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// systemId
		call _func442::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func443
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::UpgradeSystem", typeid(int (ShipManager::*)(int , int )), ".57565383ec1089ce8b5c24208b44242489442404891c24", argdata, 3, 1, &func);
}

__declspec(naked) int ShipManager::UpgradeSystem(int systemId, int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// systemId
		call _func443::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func444
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CommandCrewMoveRoom", typeid(bool (*)(CrewMember *, int )), ".83ec1cc744240800000000c7442404ffffffff8b4424248904248b4c2420e8????????83ec0c", argdata, 2, 0, &func);
}

__declspec(naked) bool ShipManager::CommandCrewMoveRoom(CrewMember *crew, int room)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// room
		push [ebp+8]		// crew
		call _func444::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func445
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSelectedCrew", typeid(int (ShipManager::*)(int , int , int )), "5557565383ec3c89ce8b6c24508a4424588844241f8b81c40000008b91c8000000", argdata, 4, 1, &func);
}

__declspec(naked) int ShipManager::GetSelectedCrew(int unk1, int unk2, int unk3)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func445::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func446
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::ClearCrewSelection", typeid(unsigned int (ShipManager::*)()), "8b91c40000008b81c800000029d0c1e80274??53b8????????8b1482", argdata, 1, 1, &func);
}

__declspec(naked) unsigned int ShipManager::ClearCrewSelection()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func446::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func447
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::PowerWeapon", typeid(bool (ShipManager::*)(ProjectileFactory *, bool , bool )), ".57565383ec1089cb0fb67424240fb67c2428c70424????????", argdata, 4, 1, &func);
}

__declspec(naked) bool ShipManager::PowerWeapon(ProjectileFactory *weapon, bool unk1, bool unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk2
		push [ebp+12]		// unk1
		push [ebp+8]		// weapon
		call _func447::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func448
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::DePowerWeapon", typeid(bool (ShipManager::*)(ProjectileFactory *, bool )), ".565383ec1489cb0fb6742424c70424????????e8????????83ec0484c0", argdata, 3, 1, &func);
}

__declspec(naked) bool ShipManager::DePowerWeapon(ProjectileFactory *weapon, bool unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// weapon
		call _func448::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func449
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetDroneCount", typeid(int (ShipManager::*)()), ".5383ec0489cbc70424????????e8????????83ec0484c074??", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::GetDroneCount()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func449::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func450
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ModifyDroneCount", typeid(int (ShipManager::*)(int )), "5383ec1889cbc70424????????e8????????83ec0484c074??8b8bac000000", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::ModifyDroneCount(int amt)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// amt
		call _func450::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func451
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetWeaponTotal", typeid(int (ShipManager::*)()), ".5383ec0489cbc70424????????e8????????83ec0484c074??", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::GetWeaponTotal()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func451::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func452
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetDroneTotal", typeid(int (ShipManager::*)()), "5383ec0489cbc70424????????e8????????83ec0484c074??8b93ac0000008b829c010000", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::GetDroneTotal()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func452::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func453
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetOxygenPercentage", typeid(float (ShipManager::*)()), "5383ec2889cbc70424????????e8????????83ec0484c074??8b4324", argdata, 1, 1, &func);
}

__declspec(naked) float ShipManager::GetOxygenPercentage()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func453::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func454
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddWeapon", typeid(int (ShipManager::*)(const WeaponBlueprint *, int )), ".5383ec1889cbc70424????????e8????????83ec0484c074??", argdata, 3, 1, &func);
}

__declspec(naked) int ShipManager::AddWeapon(const WeaponBlueprint *weapon, int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// weapon
		call _func454::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func455
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetWeaponSystem", typeid(WeaponSystem *(ShipManager::*)()), "!.8b81a8000000c3", argdata, 1, 1, &func);
}

__declspec(naked) WeaponSystem *ShipManager::GetWeaponSystem()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func455::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func456
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetNextShot", typeid(int (ShipManager::*)()), "565383ec1489cb8b91f80500008b81f405000039c274??", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::GetNextShot()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func456::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func457
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ModifyMissileCount", typeid(int (ShipManager::*)(int )), ".5383ec1889cbc70424????????e8????????83ec0484c074??", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::ModifyMissileCount(int amt)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// amt
		call _func457::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func458
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddItem", typeid(int (ShipManager::*)(const ItemBlueprint *)), "83ec1c8b4424208b403083f80174??83f80274??85c074??eb??", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::AddItem(const ItemBlueprint *item)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// item
		call _func458::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func459
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetMissileCount", typeid(int (ShipManager::*)()), ".5383ec0489cbc70424????????e8????????83ec0484c074??8b83a80000008b80c0010000", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::GetMissileCount()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func459::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func460
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetSpaceDrones", typeid(int (ShipManager::*)()), ".5557565383ec1c89cb8b7424308b86dc0500008986e00500008baed4050000", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::GetSpaceDrones()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func460::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func461
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::IsSystemHacked", typeid(int (ShipManager::*)()), "565383ec0489cb8b742410893424e8????????83ec0484c074??", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::IsSystemHacked()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func461::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func462
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::ShipFlying", typeid(bool (ShipManager::*)()), "5383ec1889cbc70424????????e8????????83ec0483f8017f??c70424????????", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::ShipFlying()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func462::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func463
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::JumpCharging", typeid(bool (ShipManager::*)()), "!.83ec0ce8????????83c40cc3", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::JumpCharging()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func463::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func464
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetDodgeFactor", typeid(int (ShipManager::*)()), "565383ec2489cbc70424????????e8????????83ec0484c00f84????????c70424????????89d9e8????????83ec04", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::GetDodgeFactor()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func464::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func465
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetNetDodgeFactor", typeid(int (ShipManager::*)()), ".565383ec0489cbe8????????89c68b0389d9ff5010", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::GetNetDodgeFactor()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func465::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func466
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetDodged", typeid(bool (ShipManager::*)()), "555383ec64894c2414c744243418e16500c7442438a86975008d4424608944243c", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::GetDodged()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func466::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func467
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::DoSensorsProvide", typeid(bool (ShipManager::*)(int )), "5383ec1889cbc70424????????e8????????83ec0483f8010f8f????????837c242002", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipManager::DoSensorsProvide(int sensorLevel)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// sensorLevel
		call _func467::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func468
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::CheckVision", typeid(int (ShipManager::*)()), "5581ec????????894c2428c744245418e16500c7442458ae6975008d8424800000008944245c", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::CheckVision()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func468::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func469
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetDroneSystem", typeid(DroneSystem *(ShipManager::*)()), "!.8b81ac000000c3", argdata, 1, 1, &func);
}

__declspec(naked) DroneSystem *ShipManager::GetDroneSystem()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func469::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func470
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::ShutdownAllPower", typeid(int (ShipManager::*)()), "57565383ec1089cb8b411c2b4118c1e80274??bf????????8d34bd????????", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::ShutdownAllPower()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func470::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func471
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::DePowerDrone", typeid(bool (ShipManager::*)()), ".565383ec1489cb0fb6742424c70424????????e8????????83ec04", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::DePowerDrone()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func471::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func472
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetDroneList", typeid(int (ShipManager::*)()), ".5383ec1889cbc70424????????8b4c2420e8????????83ec0484c0", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::GetDroneList()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func472::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func473
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetOxygenLevels", typeid(void *(ShipManager::*)()), ".5383ec1889cbc70424????????8b4c2420e8????????83ec0484c074??8b542420", argdata, 1, 1, &func);
}

__declspec(naked) void *ShipManager::GetOxygenLevels()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func473::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func474
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetWeaponList", typeid(int (ShipManager::*)()), ".5383ec1889cbc70424????????8b4c2420e8????????83ec0484c0", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::GetWeaponList()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func474::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func475
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SetShowWeaponCharge", typeid(bool (ShipManager::*)(bool )), "5557565383ec2c89ce0fb67c24408b01ff504484c075??", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipManager::SetShowWeaponCharge(bool showCharge)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// showCharge
		call _func475::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func476
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::StartFire", typeid(bool (ShipManager::*)(int )), "83ec1c81c1????????c7442404020000008b442420890424e8????????83ec08", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipManager::StartFire(int roomId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// roomId
		call _func476::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func477
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetFireCountInRoom", typeid(int (ShipManager::*)(int )), ".83ec1c81c1????????8b442420890424e8????????83ec0483c41c", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::GetFireCountInRoom(int roomId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// roomId
		call _func477::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func478
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetFireCountTotal", typeid(int (ShipManager::*)()), ".57565383ec1089cfbb????????be????????eb??891c24", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::GetFireCountTotal()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func478::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func479
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetTooltip", typeid(void *(ShipManager::*)(int , int )), "5589e581ec????????894d90c745ac18e16500c745b0c06975008d45f88945b4", argdata, 3, 1, &func);
}

__declspec(naked) void *ShipManager::GetTooltip(int unk1, int unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func479::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func480
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetNewDroneArrivals", typeid(int (ShipManager::*)()), "5383ec188b91dc0500008b81e005000029d0c1e80274??8b1a81c1????????", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::GetNewDroneArrivals()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func480::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func481
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("ShipManager::SaveCrewPositions", typeid(int (*)()), "5583ec68c744243418e16500c7442438046a75008d4424608944243cc74424405e26520089642444", argdata, 0, 0, &func);
}

__declspec(naked) int ShipManager::SaveCrewPositions()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func481::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func482
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("ShipManager::RestoreCrewPositions", typeid(bool (*)()), ".5557565381ec????????c744244418e16500c74424480a6a75008d8424d0000000", argdata, 0, 0, &func);
}

__declspec(naked) bool ShipManager::RestoreCrewPositions()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func482::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func483
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ExportBattleState", typeid(int (ShipManager::*)(FileHelper *)), "5581ec????????894c2438c744245418e16500c7442458126a75008d842480000000", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::ExportBattleState(FileHelper *fileHelper)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// fileHelper
		call _func483::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func484
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddCrewMember", typeid(int (ShipManager::*)(CrewBlueprint *, int , bool , int , bool )), "5581ec????????894c241c8a8424980000008844242b8a9424a00000008854242ac744244418e16500", argdata, 6, 1, &func);
}

__declspec(naked) int ShipManager::AddCrewMember(CrewBlueprint *blueprint, int unk1, bool unk2, int unk3, bool unk4)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+24]		// unk4
		push [ebp+20]		// unk3
		push [ebp+16]		// unk2
		push [ebp+12]		// unk1
		push [ebp+8]		// blueprint
		call _func484::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 20
	}
}

namespace _func485
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSelectedCrew", typeid(int (ShipManager::*)(int , int , int , int , int , bool )), "5583ec68894c24248a8424840000008844242bc744244418e16500c7442448266a75008d5424608954244c", argdata, 7, 1, &func);
}

__declspec(naked) int ShipManager::GetSelectedCrew(int unk1, int unk2, int unk3, int unk4, int unk5, bool unk6)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+28]		// unk6
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func485::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 24
	}
}

namespace _func486
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::TeleportCrew", typeid(int (ShipManager::*)(int , int , bool )), "5583ec68894c24208a4424788844242bc744244418e16500c74424482c6a75008d542460", argdata, 4, 1, &func);
}

__declspec(naked) int ShipManager::TeleportCrew(int unk1, int unk2, bool unk3)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func486::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func487
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::KillRandomCrew", typeid(int (ShipManager::*)()), "555383ec74894c2428c744244418e16500c7442448326a75008d442470", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::KillRandomCrew()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func487::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func488
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetLeavingCrew", typeid(int (ShipManager::*)(int , bool )), ".5583ec68894c24248a4424748844242bc744244418e16500c7442448386a7500", argdata, 3, 1, &func);
}

__declspec(naked) int ShipManager::GetLeavingCrew(int unk2, bool unk3)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk3
		push [ebp+8]		// unk2
		call _func488::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func489
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddCrewMember", typeid(bool (ShipManager::*)(CrewMember *, int )), ".5383ec1889cb8b41048904248b4c2420e8????????83ec04", argdata, 3, 1, &func);
}

__declspec(naked) bool ShipManager::AddCrewMember(CrewMember *crew, int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// crew
		call _func489::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func490
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SetTarget", typeid(int (ShipManager::*)(ShipManager *)), "5581ec????????894c242cc744245418e16500c74424583e6a75008d8424900000008944245c", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::SetTarget(ShipManager *target)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// target
		call _func490::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func491
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CreateCrewDrone", typeid(int (ShipManager::*)(const DroneBlueprint *)), "565383ec2489cb8b5424308b423083f80275??895424048b4104", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::CreateCrewDrone(const DroneBlueprint *blueprint)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// blueprint
		call _func491::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func492
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::DamageShield", typeid(void *(ShipManager::*)(int , int , float , int , int , int , int , int , int , int , int , int , int , int , int , int , int , int , bool )), "55575681ec????????894c24548b842424010000894424608b942428010000895424648b84242c010000", argdata, 20, 1, &func);
}

__declspec(naked) void *ShipManager::DamageShield(int unk1, int unk2, float unk3, int unk4, int unk5, int unk6, int unk7, int unk8, int unk9, int unk10, int unk11, int unk12, int unk13, int unk14, int unk15, int unk16, int unk17, int unk18, bool unk19)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+80]		// unk19
		push [ebp+76]		// unk18
		push [ebp+72]		// unk17
		push [ebp+68]		// unk16
		push [ebp+64]		// unk15
		push [ebp+60]		// unk14
		push [ebp+56]		// unk13
		push [ebp+52]		// unk12
		push [ebp+48]		// unk11
		push [ebp+44]		// unk10
		push [ebp+40]		// unk9
		push [ebp+36]		// unk8
		push [ebp+32]		// unk7
		push [ebp+28]		// unk6
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func492::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 76
	}
}

namespace _func493
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::PulsarDamage", typeid(int (ShipManager::*)()), "555381ec????????894c242cc784248400000018e16500c78424880000004c6a75008d8424c00000008984248c000000", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::PulsarDamage()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func493::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func494
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::DamageSystem", typeid(int (ShipManager::*)(ShipSystem *, unsigned int , int , int , int , int , int , int , int , int , int , int , int , int )), "5581ec????????894c2434c744247418e16500c74424785c6a75008d8424b00000008944247c", argdata, 15, 1, &func);
}

__declspec(naked) int ShipManager::DamageSystem(ShipSystem *sys, unsigned int dmg, int unk1, int unk2, int unk3, int unk4, int unk5, int unk6, int unk7, int unk8, int unk9, int unk10, int unk11, int unk12)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+60]		// unk12
		push [ebp+56]		// unk11
		push [ebp+52]		// unk10
		push [ebp+48]		// unk9
		push [ebp+44]		// unk8
		push [ebp+40]		// unk7
		push [ebp+36]		// unk6
		push [ebp+32]		// unk5
		push [ebp+28]		// unk4
		push [ebp+24]		// unk3
		push [ebp+20]		// unk2
		push [ebp+16]		// unk1
		push [ebp+12]		// dmg
		push [ebp+8]		// sys
		call _func494::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 56
	}
}

namespace _func495
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CollisionMoving", typeid(void *(ShipManager::*)(int , float , float , float , float , int , int , int , int , int , int , int , int , int , int , int , int , int , bool )), ".5557565381ec????????894c24788b9c242c0100008bac24300100008a842468010000", argdata, 20, 1, &func);
}

__declspec(naked) void *ShipManager::CollisionMoving(int unk1, float unk2, float unk3, float unk4, float unk5, int unk6, int unk7, int unk8, int unk9, int unk10, int unk11, int unk12, int unk13, int unk14, int unk15, int unk16, int unk17, int unk18, bool unk19)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+80]		// unk19
		push [ebp+76]		// unk18
		push [ebp+72]		// unk17
		push [ebp+68]		// unk16
		push [ebp+64]		// unk15
		push [ebp+60]		// unk14
		push [ebp+56]		// unk13
		push [ebp+52]		// unk12
		push [ebp+48]		// unk11
		push [ebp+44]		// unk10
		push [ebp+40]		// unk9
		push [ebp+36]		// unk8
		push [ebp+32]		// unk7
		push [ebp+28]		// unk6
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func495::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 76
	}
}

namespace _func496
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::SunDamage", typeid(int (ShipManager::*)()), "5589e5575681ec????????898d40ffffffc7856cffffff18e16500c78570ffffff6a6a75008d45f8898574ffffffc78578ffffff7f595200", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::SunDamage()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func496::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func497
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::StartSubExplosion", typeid(int (ShipManager::*)()), "5581ec????????894c2414c744243418e16500c7442438786a75008d8424800000008944243c", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::StartSubExplosion()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func497::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func498
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::LoadSuperDrones", typeid(int (ShipManager::*)(int )), ".555381ec????????894c2414c744244418e16500c7442448806a75008d842480000000", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::LoadSuperDrones(int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func498::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func499
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::PrepareSuperDrones", typeid(int (ShipManager::*)()), "555381ec????????894c2418c744244418e16500c74424488a6a75008d842480000000", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::PrepareSuperDrones()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func499::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func500
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetArtilleryWeapons", typeid(void *(ShipManager::*)(int )), "5583ec78894c2424c744244418e16500c7442448946a75008d4424708944244c", argdata, 2, 1, &func);
}

__declspec(naked) void *ShipManager::GetArtilleryWeapons(int unk1)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk1
		call _func500::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func501
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::RenderWeapons", typeid(int (ShipManager::*)()), "55575681ec????????894c2430c744246418e16500c74424689a6a75008d8424b0000000", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::RenderWeapons()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func501::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func502
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::OnRender", typeid(int (ShipManager::*)(bool , bool )), "5589e5575681ec????????898de8feffff8a45088885fcfeffff8a550c", argdata, 3, 1, &func);
}

__declspec(naked) int ShipManager::OnRender(bool unk1, bool unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func502::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func503
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::RenderChargeBars", typeid(int (ShipManager::*)()), "5581ec????????894c2428c744245418e16500c7442458ba6a75008d8424900000008944245c", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::RenderChargeBars()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func503::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func504
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetAllTargettingPoints", typeid(void *(ShipManager::*)(int )), "5583ec68894c2414c744243418e16500c7442438c06a75008d4424608944243c", argdata, 2, 1, &func);
}

__declspec(naked) void *ShipManager::GetAllTargettingPoints(int unk1)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk1
		call _func504::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func505
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::UpdateEnvironment", typeid(int (ShipManager::*)()), "55565381ec????????894c2428c744246418e16500c7442468c66a75008d8424a0000000", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::UpdateEnvironment()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func505::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func506
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetFires", typeid(void *(ShipManager::*)(int , int )), "5383ec1889cb8b442424894424048b44242005????????890424e8????????83ec08", argdata, 3, 1, &func);
}

__declspec(naked) void *ShipManager::GetFires(int unk1, int unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func506::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func507
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CheckCrystalAugment", typeid(int (ShipManager::*)(int , int )), "5581ec????????894c2424c744245418e16500c7442458226b75008d8424a00000008944245cc7442460318c5200", argdata, 3, 1, &func);
}

__declspec(naked) int ShipManager::CheckCrystalAugment(int unk1, int unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func507::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func508
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::DamageArea", typeid(bool (ShipManager::*)(int , int , int , int , int , int , int , int , int , int , bool , int , int , int64_t , int , bool )), "55575681ec????????894c244c8b842440010000894424788b942444010000", argdata, 17, 1, &func);
}

__declspec(naked) bool ShipManager::DamageArea(int unk1, int unk2, int unk3, int unk4, int unk5, int unk6, int unk7, int unk8, int unk9, int unk10, bool unk11, int unk12, int unk13, int64_t unk14, int unk15, bool unk16)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+68]		// unk16
		push [ebp+64]		// unk15
		push [ebp+60]		// unk14
		push [ebp+56]		// unk13
		push [ebp+52]		// unk12
		push [ebp+48]		// unk11
		push [ebp+44]		// unk10
		push [ebp+40]		// unk9
		push [ebp+36]		// unk8
		push [ebp+32]		// unk7
		push [ebp+28]		// unk6
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func508::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 64
	}
}

namespace _func509
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::PrepareSuperBarrage", typeid(int (ShipManager::*)()), "5581ec????????894c2438c744247418e16500c74424786c6b75008d8424c00000008944247cc7842480000000e7a15200", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::PrepareSuperBarrage()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func509::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func510
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SelectRandomCrew", typeid(void *(ShipManager::*)(int , int , char *)), "555381ec????????894c2428c744244418e16500c7442448f46b75008d8424800000008944244c", argdata, 4, 1, &func);
}

__declspec(naked) void *ShipManager::SelectRandomCrew(int unk1, int unk2, char *unk3)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func510::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func511
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CreateSpaceDrone", typeid(int (ShipManager::*)(const DroneBlueprint *)), ".555381ec????????894c241cc744245418e16500c7442458486c75008d8424800000008944245c", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::CreateSpaceDrone(const DroneBlueprint *blueprint)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// blueprint
		call _func511::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func512
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CreateDrone", typeid(int (ShipManager::*)(const DroneBlueprint *)), ".565383ec1489cb8b742420893424e8????????83ec0485c0", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::CreateDrone(const DroneBlueprint *blueprint)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// blueprint
		call _func512::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func513
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddDrone", typeid(int (ShipManager::*)(const DroneBlueprint *, int )), ".565383ec1489cbc70424????????e8????????83ec0484c074??8b442420890424", argdata, 3, 1, &func);
}

__declspec(naked) int ShipManager::AddDrone(const DroneBlueprint *blueprint, int unk1)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk1
		push [ebp+8]		// blueprint
		call _func513::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func514
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::CreateArmory", typeid(int (ShipManager::*)()), "5589e581ec????????894d88c745ac18e16500c745b0626c75008d45f88945b4c745b8fbb35200", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::CreateArmory()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func514::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func515
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::CheckDlcEnabled", typeid(int (ShipManager::*)()), "5589e581ec????????894d88c745ac18e16500c745b0626c75008d45f8", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::CheckDlcEnabled()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func515::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func516
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddSystem", typeid(int (ShipManager::*)(int )), "555381ec????????894c2420c784249400000018e16500c78424980000007c6c75008d8424e00100008984249c000000c78424a0000000b4d5520089a424a4000000", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::AddSystem(int systemId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// systemId
		call _func516::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func517
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::CreateSystems", typeid(bool (ShipManager::*)()), "55575681ec????????894c2424c744244418e16500c7442448b46c75008d842490000000", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipManager::CreateSystems()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func517::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func518
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetMaxSystemLevel", typeid(void *(ShipManager::*)(int )), "5581ec????????894c241cc744244418e16500c7442448c06c75008d8424e00000008944244c", argdata, 2, 1, &func);
}

__declspec(naked) void *ShipManager::GetMaxSystemLevel(int systemId)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// systemId
		call _func518::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func519
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::DamageBeam", typeid(bool (ShipManager::*)(int , int , size_t , int , int , int , int , int , int , int , int , int , bool , int , bool )), "55575681ec????????894c245c8b842440010000894424608b942444010000", argdata, 16, 1, &func);
}

__declspec(naked) bool ShipManager::DamageBeam(int unk1, int unk2, size_t unk3, int unk4, int unk5, int unk6, int unk7, int unk8, int unk9, int unk10, int unk11, int unk12, bool unk13, int unk14, bool unk15)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+64]		// unk15
		push [ebp+60]		// unk14
		push [ebp+56]		// unk13
		push [ebp+52]		// unk12
		push [ebp+48]		// unk11
		push [ebp+44]		// unk10
		push [ebp+40]		// unk9
		push [ebp+36]		// unk8
		push [ebp+32]		// unk7
		push [ebp+28]		// unk6
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func519::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 60
	}
}

namespace _func520
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::UpdateCrewmembers", typeid(int (ShipManager::*)()), "5589e557565381ec????????898d80feffffc785ccfeffff18e16500c785d0feffff086e75008d45e88985d4feffff", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::UpdateCrewmembers()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func520::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func521
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::PowerDrone", typeid(bool (ShipManager::*)(Drone *, int , bool , bool )), "5557565383ec1c89cb8b7424300fb67c24380fb66c243cc70424????????e8????????", argdata, 5, 1, &func);
}

__declspec(naked) bool ShipManager::PowerDrone(Drone *drone, int unk1, bool unk2, bool unk3)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+20]		// unk3
		push [ebp+16]		// unk2
		push [ebp+12]		// unk1
		push [ebp+8]		// drone
		call _func521::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 16
	}
}

namespace _func522
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ImportBattleState", typeid(int (ShipManager::*)(int )), "5581ec????????894c2430c744245418e16500c7442458486e75008d8424800000008944245cc7442460c7135300", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::ImportBattleState(int unk1)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk1
		call _func522::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func523
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::KillEveryone", typeid(int (ShipManager::*)(bool )), "57565383ec1089ce8a4c24208b86c40000008b96c800000029c2", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::KillEveryone(bool unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func523::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func524
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::OnLoop", typeid(int (ShipManager::*)()), "5557565381ec????????894c2470c78424e400000018e16500c78424e8000000f46e75008d842490020000898424ec000000", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::OnLoop()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func524::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func525
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SaveToBlueprint", typeid(int (ShipManager::*)(int , bool )), "5589e557565381ec????????898dd8feffff8a450c88850fffffff", argdata, 3, 1, &func);
}

__declspec(naked) int ShipManager::SaveToBlueprint(int unk1, bool unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func525::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func526
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ExportShip", typeid(int (ShipManager::*)(int )), "5589e557565381ec????????898d70feffffc7859cfeffff18e16500c785a0fefffff46f7500", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::ExportShip(int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func526::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func527
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::KillCrew", typeid(int (ShipManager::*)(const CrewBlueprint *)), "565381ec????????89ce8d5c241c8b8424a000000089042489d9", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::KillCrew(const CrewBlueprint *blueprint)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// blueprint
		call _func527::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func528
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddCrewMember", typeid(int (ShipManager::*)(char *, char *, bool , int , bool )), "5581ec????????894c241c8a8424880100008844242a8a9424900100008854242bc744244418e16500", argdata, 6, 1, &func);
}

__declspec(naked) int ShipManager::AddCrewMember(char *unk1, char *unk2, bool unk3, int unk4, bool unk5)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+24]		// unk5
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func528::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 20
	}
}

namespace _func529
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddInitialCrew", typeid(int (ShipManager::*)(void *)), "5589e557565381ec????????898d7cfeffffc785bcfeffff18e16500c785c0feffff58707500", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::AddInitialCrew(void *unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func529::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func530
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::Restart", typeid(int (ShipManager::*)()), "5581ec????????894c2438c744247418e16500c7442478ac7075008d8424a00000008944247cc7842480000000b0ab5300", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::Restart()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func530::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func531
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::OnInit", typeid(bool (ShipManager::*)(const ShipBlueprint *, int )), "5557565381ec????????894c2434c744246418e16500c7442468b47075008d8424e0000000", argdata, 3, 1, &func);
}

__declspec(naked) bool ShipManager::OnInit(const ShipBlueprint *blueprint, int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// blueprint
		call _func531::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func532
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ImportShip", typeid(int (ShipManager::*)(int )), "5589e557565381ec????????898d0cfdffffc7858cfdffff18e16500c78590fdffffd07075008d45e8898594fdffff", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::ImportShip(int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func532::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func533
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::destructor", typeid(int (ShipManager::*)()), ".555381ec????????894c2444c744247418e16500c7442478367175008d8424c00000008944247c", argdata, 1, 1, &func);
}

__declspec(naked) int ShipManager::destructor()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func533::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func534
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::constructor", typeid(int (ShipManager::*)(int )), ".555781ec????????894c2438c744247418e16500c7442478447175008d8424f00000008944247c", argdata, 2, 1, &func);
}

__declspec(naked) int ShipManager::constructor(int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func534::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func535
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::HasAugmentation", typeid(int (ShipObject::*)(std_string *)), "5583ec68894c2414c744243418e16500c7442438d87175008d4424608944243c", argdata, 2, 1, &func);
}

__declspec(naked) int ShipObject::HasAugmentation(std_string *a2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// a2
		call _func535::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func536
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipObject::GetAugmentationCount", typeid(int (ShipObject::*)()), "837904000f94c00fb6c08d140001c28d1490a1????????8d0c90e8????????c3", argdata, 1, 1, &func);
}

__declspec(naked) int ShipObject::GetAugmentationCount()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func536::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func537
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipStatus::RenderHealth", typeid(int (ShipStatus::*)()), "5557565383ec7c89cb8b71148b89f80000008079120075??807910000f85????????eb??", argdata, 1, 1, &func);
}

__declspec(naked) int ShipStatus::RenderHealth()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func537::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func538
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipStatus::MouseMove", typeid(int (ShipStatus::*)(int , int )), "565383ec2489cb8b4424308b5424348d48fa81f9????????77??83fa077e??83fa2c", argdata, 3, 1, &func);
}

__declspec(naked) int ShipStatus::MouseMove(int x, int y)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// y
		push [ebp+8]		// x
		call _func538::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func539
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipStatus::OnRender", typeid(int (ShipStatus::*)()), "5383ec1889cbe8????????c744240800000000db4304d95c2404db03d91c24e8????????89d9e8????????", argdata, 1, 1, &func);
}

__declspec(naked) int ShipStatus::OnRender()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func539::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func540
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SaveState", typeid(bool (ShipSystem::*)(FileHelper *)), "565383ec1489ce8b5c24208b810801000089442404891c24e8????????8b860c010000", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipSystem::SaveState(FileHelper *fileHelper)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// fileHelper
		call _func540::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func541
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::LoadState", typeid(int (ShipSystem::*)(FileHelper *)), "565383ec1489cb8b742420893424e8????????898308010000", argdata, 2, 1, &func);
}

__declspec(naked) int ShipSystem::LoadState(FileHelper *fileHelper)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// fileHelper
		call _func541::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func542
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::GetPowerCap", typeid(int (ShipSystem::*)()), "8b910801000083fa077f??89d085d279??b8????????c38b414085c079??", argdata, 1, 1, &func);
}

__declspec(naked) int ShipSystem::GetPowerCap()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func542::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func543
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::TriggerIonPulse", typeid(void (ShipSystem::*)()), "!.c6818601000001c3", argdata, 1, 5, &func);
}

__declspec(naked) void ShipSystem::TriggerIonPulse()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func543::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func544
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x101};
	static FunctionDefinition funcObj("ShipSystem::GetInteriorImageName", typeid(char **(ShipSystem::*)(int )), "5383ec1889cb8b44242005????????890424e8????????83ec0489d883c418", argdata, 2, 1, &func);
}

__declspec(naked) char **ShipSystem::GetInteriorImageName(int ignore)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push ecx			// this
		mov ecx, [ebp+8]	// ignore
		call _func544::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func545
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::IsMannedBoost", typeid(int (ShipSystem::*)()), "8b413485c07e??8079380074??8b91ec0000003991f000000074??b8????????c3b8????????c3b8????????", argdata, 1, 1, &func);
}

__declspec(naked) int ShipSystem::IsMannedBoost()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func545::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func546
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::GetEffectivePower", typeid(int (ShipSystem::*)()), "5389cbe8????????85c07e??0fb69385010000eb??ba????????8b433c03834801000003837c010000", argdata, 1, 1, &func);
}

__declspec(naked) int ShipSystem::GetEffectivePower()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func546::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func547
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SetActiveManned", typeid(int (ShipSystem::*)(int )), "!.8b442404894134c20400", argdata, 2, 1, &func);
}

__declspec(naked) int ShipSystem::SetActiveManned(int manned)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// manned
		call _func547::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func548
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::GetLocked", typeid(bool (ShipSystem::*)()), "!.8b811401000085c07f??83f8ff74??83b980010000010f9fc0c3b001c3b001c3", argdata, 1, 1, &func);
}

__declspec(naked) bool ShipSystem::GetLocked()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func548::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func549
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::BlockedBoosted", typeid(bool (ShipSystem::*)(bool )), "5383ec0889cb807c24100074??8b91080100008b4940807b380074??8a8385010000eb??b000", argdata, 2, 1, &func);
}

__declspec(naked) bool ShipSystem::BlockedBoosted(bool blockedBoosted)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// blockedBoosted
		call _func549::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func550
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::OnRenderFloor", typeid(void (ShipSystem::*)()), "5383ec1889cbc78194010000ffffffff807938000f84????????e8????????83f80275??c70424????????89d9e8????????83ec0484c075??", argdata, 1, 5, &func);
}

__declspec(naked) void ShipSystem::OnRenderFloor()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func550::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func551
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::OnRender", typeid(int (ShipSystem::*)()), "565383ec3489cb8db15c01000089f1e8????????d905????????d95c242cd905????????d95c2428d905????????d95c242489d9e8????????84c0", argdata, 1, 1, &func);
}

__declspec(naked) int ShipSystem::OnRender()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func551::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func552
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::GetLockCount", typeid(int (ShipSystem::*)()), "!.8b8114010000c3", argdata, 1, 1, &func);
}

__declspec(naked) int ShipSystem::GetLockCount()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func552::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func553
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x101};
	static FunctionDefinition funcObj("ShipSystem::GetLockTimer", typeid(float (ShipSystem::*)(int )), ".575689c88b74240c81c6????????b9????????89c7f3a55e", argdata, 2, 1, &func);
}

__declspec(naked) float ShipSystem::GetLockTimer(int ignore)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push ecx			// this
		mov ecx, [ebp+8]	// ignore
		call _func553::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func554
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SetLockTimer", typeid(void (ShipSystem::*)(float )), "!.d9442404d99920010000c20400", argdata, 2, 5, &func);
}

__declspec(naked) void ShipSystem::SetLockTimer(float timer)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// timer
		call _func554::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func555
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::UpgradeSystem", typeid(int (ShipSystem::*)(int )), "565383ec0489cb8b7424108b01ff501001734001b3f000000084c075??01b3ec000000", argdata, 2, 1, &func);
}

__declspec(naked) int ShipSystem::UpgradeSystem(int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func555::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func556
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SetRepairOverTime", typeid(int (ShipSystem::*)(float )), "c681fd00000001d9442404d999f8000000", argdata, 2, 1, &func);
}

__declspec(naked) int ShipSystem::SetRepairOverTime(float repairAmt)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// repairAmt
		call _func556::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func557
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::OnLoop", typeid(int (ShipSystem::*)()), "565383ec2489cee8????????8b86880100008b968c01000029c2c1fa03", argdata, 1, 1, &func);
}

__declspec(naked) int ShipSystem::OnLoop()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func557::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func558
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SystemIdToName", typeid(char *(*)(int )), "5383ec388b5c2440837c2444110f87????????8b442444ff2485????????", argdata, 1, 0, &func);
}

__declspec(naked) char *ShipSystem::SystemIdToName(int id)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// id
		call _func558::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func559
{
	static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::NameToSystemId", typeid(int (*)(std_string *)), "83ec1cc70424????????8b4c2420e8????????83ec0485c00f84????????c70424????????8b4c2420e8????????83ec04", argdata, 1, 0, &func);
}

__declspec(naked) int ShipSystem::NameToSystemId(std_string *name)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// name
		call _func559::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func560
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::IonDamage", typeid(int (ShipSystem::*)(int )), "565383ec148b5c242085db7e??89ce891c24e8????????83ec048b06", argdata, 2, 1, &func);
}

__declspec(naked) int ShipSystem::IonDamage(int dmg)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// dmg
		call _func560::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func561
{
	static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("SpaceManager::__BS_FUNCTION_DONT_USE", typeid(void (*)()), "85c07f??8d4ef4892c24e8????????83ec0483eb0439fb75??83c42c5b5e5f5d", argdata, 0, 4, &func);
}

__declspec(naked) void SpaceManager::__BS_FUNCTION_DONT_USE()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func561::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func562
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::GetScreenShake", typeid(bool (SpaceManager::*)()), ".8a8164030000c6816403000000", argdata, 1, 1, &func);
}

__declspec(naked) bool SpaceManager::GetScreenShake()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func562::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func563
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SaveSpace", typeid(int (SpaceManager::*)(int , FileHelper *)), ".5756", argdata, 3, 1, &func);
}

__declspec(naked) int SpaceManager::SaveSpace(int ignore, FileHelper *fileHelper)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// fileHelper
		push ecx			// this
		mov ecx, [ebp+8]	// ignore
		call _func563::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func564
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SwitchBackground", typeid(void *(SpaceManager::*)(int , std_string *)), ".5583", argdata, 3, 1, &func);
}

__declspec(naked) void *SpaceManager::SwitchBackground(int unk, std_string *bg)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// bg
		push [ebp+8]		// unk
		call _func564::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func565
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::StartAsteroids", typeid(int (SpaceManager::*)(int , bool )), ".5583", argdata, 3, 1, &func);
}

__declspec(naked) int SpaceManager::StartAsteroids(int unk1, bool unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func565::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func566
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetFireLevel", typeid(int (SpaceManager::*)(bool )), ".5583", argdata, 2, 1, &func);
}

__declspec(naked) int SpaceManager::SetFireLevel(bool unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func566::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func567
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetPulsarLevel", typeid(int (SpaceManager::*)(bool )), ".5581", argdata, 2, 1, &func);
}

__declspec(naked) int SpaceManager::SetPulsarLevel(bool unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func567::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func568
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::DangerousEnvironment", typeid(bool (SpaceManager::*)()), ".8A81", argdata, 1, 1, &func);
}

__declspec(naked) bool SpaceManager::DangerousEnvironment()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func568::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func569
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::GetSelectedDrone", typeid(int (SpaceManager::*)(int , int , int )), ".5557", argdata, 4, 1, &func);
}

__declspec(naked) int SpaceManager::GetSelectedDrone(int unk1, int unk2, int unk3)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func569::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func570
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::GetFlashOpacity", typeid(float (SpaceManager::*)()), ".5383", argdata, 1, 1, &func);
}

__declspec(naked) float SpaceManager::GetFlashOpacity()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func570::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func571
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnRenderFleet", typeid(bool (SpaceManager::*)()), ".5557565383ec6c894c243c890c248d4c2440", argdata, 1, 1, &func);
}

__declspec(naked) bool SpaceManager::OnRenderFleet()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func571::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func572
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnRenderForeground", typeid(bool (SpaceManager::*)()), ".5557", argdata, 1, 1, &func);
}

__declspec(naked) bool SpaceManager::OnRenderForeground()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func572::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func573
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::SetDangerZone", typeid(bool (SpaceManager::*)()), ".5557", argdata, 1, 1, &func);
}

__declspec(naked) bool SpaceManager::SetDangerZone()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func573::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func574
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::OnRenderAsteroids", typeid(int (SpaceManager::*)(int , float )), ".5557", argdata, 3, 1, &func);
}

__declspec(naked) int SpaceManager::OnRenderAsteroids(int unk1, float unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func574::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func575
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::OnRenderProjectiles", typeid(int (SpaceManager::*)(int , int )), ".5557", argdata, 3, 1, &func);
}

__declspec(naked) int SpaceManager::OnRenderProjectiles(int unk1, int unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func575::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func576
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnInit", typeid(int (SpaceManager::*)()), ".5557", argdata, 1, 1, &func);
}

__declspec(naked) int SpaceManager::OnInit()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func576::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func577
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::ClearEnvironment", typeid(void (SpaceManager::*)()), ".C681", argdata, 1, 5, &func);
}

__declspec(naked) void SpaceManager::ClearEnvironment()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func577::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func578
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::Clear", typeid(void (SpaceManager::*)()), ".5756", argdata, 1, 5, &func);
}

__declspec(naked) void SpaceManager::Clear()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func578::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func579
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::UpdateProjectile", typeid(int (SpaceManager::*)(Projectile *)), ".5557", argdata, 2, 1, &func);
}

__declspec(naked) int SpaceManager::UpdateProjectile(Projectile *proj)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// proj
		call _func579::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func580
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::TransferProjectiles", typeid(int (SpaceManager::*)(Projectile *)), ".5653", argdata, 2, 1, &func);
}

__declspec(naked) int SpaceManager::TransferProjectiles(Projectile *proj)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// proj
		call _func580::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func581
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnRenderBackground", typeid(int (SpaceManager::*)()), ".5557565383ec5c89cb890c248d4c2440e8????????", argdata, 1, 1, &func);
}

__declspec(naked) int SpaceManager::OnRenderBackground()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func581::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func582
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::AddShip", typeid(int (SpaceManager::*)(ShipManager *)), ".5583ec68894c2410c744243418e16500c7442438483175008d4424608944243c", argdata, 2, 1, &func);
}

__declspec(naked) int SpaceManager::AddShip(ShipManager *ship)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// ship
		call _func582::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func583
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnLoopNebulas", typeid(int (SpaceManager::*)()), ".5557", argdata, 1, 1, &func);
}

__declspec(naked) int SpaceManager::OnLoopNebulas()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func583::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func584
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetNebula", typeid(int (SpaceManager::*)(bool )), ".5553", argdata, 2, 1, &func);
}

__declspec(naked) int SpaceManager::SetNebula(bool nebula)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// nebula
		call _func584::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func585
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetStorm", typeid(int (SpaceManager::*)(bool )), ".5583", argdata, 2, 1, &func);
}

__declspec(naked) int SpaceManager::SetStorm(bool storm)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// storm
		call _func585::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func586
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::UpdatePDS", typeid(int (SpaceManager::*)()), ".5581", argdata, 1, 1, &func);
}

__declspec(naked) int SpaceManager::UpdatePDS()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func586::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func587
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnLoop", typeid(int (SpaceManager::*)()), ".5553", argdata, 1, 1, &func);
}

__declspec(naked) int SpaceManager::OnLoop()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func587::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func588
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetPlanetaryDefense", typeid(int (SpaceManager::*)(bool , int )), ".55575681ec????????894c24108a8424a00000008844241bc744243418e16500c744243844327500", argdata, 3, 1, &func);
}

__declspec(naked) int SpaceManager::SetPlanetaryDefense(bool pds, int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// pds
		call _func588::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func589
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::LoadSpace", typeid(int (SpaceManager::*)(FileHelper *)), ".5553", argdata, 2, 1, &func);
}

__declspec(naked) int SpaceManager::LoadSpace(FileHelper *fileHelper)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// fileHelper
		call _func589::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func590
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SwitchImages", typeid(int (SpaceManager::*)(int )), ".5756", argdata, 2, 1, &func);
}

__declspec(naked) int SpaceManager::SwitchImages(int aLotOfArguments)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// aLotOfArguments
		call _func590::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func591
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SwitchPlanet", typeid(void *(SpaceManager::*)(std_string *)), ".5557", argdata, 2, 1, &func);
}

__declspec(naked) void *SpaceManager::SwitchPlanet(std_string *planet)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// planet
		call _func591::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func592
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::constructor", typeid(int (SpaceManager::*)()), ".5583", argdata, 1, 1, &func);
}

__declspec(naked) int SpaceManager::constructor()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func592::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func593
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::constructor", typeid(int (StarMap::*)()), "5589e5575681ec????????898da8f9ffffc7850cfaffff18e16500c78510faffff545475008d45f8", argdata, 1, 1, &func);
}

__declspec(naked) int StarMap::constructor()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func593::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func594
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("std_string::constructor", typeid(void *(*)(std_string *, char *, int )), "575383ec1489cb8b54242085d274??31c0b9????????89d7f2aef7d1", argdata, 3, 0, &func);
}

__declspec(naked) void *std_string::constructor(std_string *a1, char *str, int alloc)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// alloc
		push [ebp+12]		// str
		push [ebp+8]		// a1
		call _func594::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func595
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TimerHelper::Start", typeid(int (TimerHelper::*)(int )), "565383ec1489cb8b442420c6411101c741080000000083f8ff74??8944240cdb44240cd9590c", argdata, 2, 1, &func);
}

__declspec(naked) int TimerHelper::Start(int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func595::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func596
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TimerHelper::Running", typeid(bool (TimerHelper::*)()), ".8A41", argdata, 1, 1, &func);
}

__declspec(naked) bool TimerHelper::Running()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func596::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func597
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TimerHelper::ResetMinMax", typeid(void (TimerHelper::*)(int , int )), ".8B44", argdata, 3, 5, &func);
}

__declspec(naked) void TimerHelper::ResetMinMax(int min, int max)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// max
		push [ebp+8]		// min
		call _func597::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func598
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TimerHelper::SetMaxTime", typeid(void (TimerHelper::*)(float )), ".D944", argdata, 2, 5, &func);
}

__declspec(naked) void TimerHelper::SetMaxTime(float time)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// time
		call _func598::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func599
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TimerHelper::Stop", typeid(void (TimerHelper::*)()), ".C641", argdata, 1, 5, &func);
}

__declspec(naked) void TimerHelper::Stop()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func599::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func600
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TimerHelper::Update", typeid(void (TimerHelper::*)()), ".5383", argdata, 1, 5, &func);
}

__declspec(naked) void TimerHelper::Update()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push eax
		push ecx
		push ebx
		push esi
		push edi
		call _func600::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop eax
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func601
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TimerHelper::Done", typeid(bool (TimerHelper::*)()), ".8079", argdata, 1, 1, &func);
}

__declspec(naked) bool TimerHelper::Done()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func601::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func602
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponBlueprint::constructor", typeid(int (WeaponBlueprint::*)()), "5583ec78894c2414c744244418e16500c74424489e3975008d4424708944244c", argdata, 1, 1, &func);
}

__declspec(naked) int WeaponBlueprint::constructor()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func602::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func603
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponBlueprint::copy", typeid(int (WeaponBlueprint::*)(WeaponBlueprint &)), "83ec70894c241cc744245418e16500c7442458023975008d4424708944245cc7442460305c6900896424648d44243c890424e8????????8b942480000000", argdata, 2, 1, &func);
}

__declspec(naked) int WeaponBlueprint::copy(WeaponBlueprint &other)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// other
		call _func603::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func604
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::OnInit", typeid(int (WorldManager::*)()), "5583ec68894c241cc744244418e16500c7442448aa5575008d4424608944244cc7442450ed424b00896424548d44242c890424", argdata, 1, 1, &func);
}

__declspec(naked) int WorldManager::OnInit()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func604::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func605
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::PossibleDamage", typeid(int (WorldManager::*)(int , int , int )), ".5557", argdata, 4, 1, &func);
}

__declspec(naked) int WorldManager::PossibleDamage(int unk1, int unk2, int unk3)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func605::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 12
	}
}

namespace _func606
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CreateStore", typeid(int (WorldManager::*)(LocationEvent *)), ".565383ec1489cb", argdata, 2, 1, &func);
}

__declspec(naked) int WorldManager::CreateStore(LocationEvent *loc)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// loc
		call _func606::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func607
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CheckRequirements", typeid(bool (WorldManager::*)(LocationEvent *, bool )), ".5557", argdata, 3, 1, &func);
}

__declspec(naked) bool WorldManager::CheckRequirements(LocationEvent *loc, bool unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// loc
		call _func607::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func608
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::AddBoarders", typeid(bool (WorldManager::*)(BoardingEvent *)), ".5583", argdata, 2, 1, &func);
}

__declspec(naked) bool WorldManager::AddBoarders(BoardingEvent *event)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// event
		call _func608::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func609
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::CreateCommandGui", typeid(int (WorldManager::*)()), ".8B81", argdata, 1, 1, &func);
}

__declspec(naked) int WorldManager::CreateCommandGui()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func609::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func610
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::HostileEnvironment", typeid(bool (WorldManager::*)()), ".5383ec0889cb8d4908e8????????84c075??8b038b4808", argdata, 1, 1, &func);
}

__declspec(naked) bool WorldManager::HostileEnvironment()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func610::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func611
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::CheckMusic", typeid(int (WorldManager::*)()), ".5756", argdata, 1, 1, &func);
}

__declspec(naked) int WorldManager::CheckMusic()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func611::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func612
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::ModifyEnvironment", typeid(int (WorldManager::*)(int , int )), ".5383", argdata, 3, 1, &func);
}

__declspec(naked) int WorldManager::ModifyEnvironment(int hazard, int lvl)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// lvl
		push [ebp+8]		// hazard
		call _func612::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func613
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::ModifyStatusEffect", typeid(bool (WorldManager::*)(int , int , int , int , ShipManager *, int )), ".5557", argdata, 7, 1, &func);
}

__declspec(naked) bool WorldManager::ModifyStatusEffect(int unk1, int unk2, int unk3, int unk4, ShipManager *ship, int unk5)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+28]		// unk5
		push [ebp+24]		// ship
		push [ebp+20]		// unk4
		push [ebp+16]		// unk3
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func613::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 24
	}
}

namespace _func614
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::ModifyAllStatusEffects", typeid(int (WorldManager::*)(ShipManager *, int )), ".5557", argdata, 3, 1, &func);
}

__declspec(naked) int WorldManager::ModifyAllStatusEffects(ShipManager *ship, int unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// ship
		call _func614::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func615
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CheckStatusEffects", typeid(int (WorldManager::*)(int )), ".5557565383ec4c89cd8b4424608b308b500489d0", argdata, 2, 1, &func);
}

__declspec(naked) int WorldManager::CheckStatusEffects(int arr)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// arr
		call _func615::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func616
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::UpdateNameDefinitions", typeid(int (WorldManager::*)(LocationEvent *)), ".5589", argdata, 2, 1, &func);
}

__declspec(naked) int WorldManager::UpdateNameDefinitions(LocationEvent *loc)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// loc
		call _func616::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func617
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::constructor", typeid(int (WorldManager::*)()), ".5557", argdata, 1, 1, &func);
}

__declspec(naked) int WorldManager::constructor()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func617::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func618
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::RetrieveShipList", typeid(void *(WorldManager::*)(LocationEvent *)), ".5553", argdata, 2, 1, &func);
}

__declspec(naked) void *WorldManager::RetrieveShipList(LocationEvent *loc)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// loc
		call _func618::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func619
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::ClearLocation", typeid(int (WorldManager::*)()), ".5581", argdata, 1, 1, &func);
}

__declspec(naked) int WorldManager::ClearLocation()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func619::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func620
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::OnCleanup", typeid(int (WorldManager::*)()), ".5383", argdata, 1, 1, &func);
}

__declspec(naked) int WorldManager::OnCleanup()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func620::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func621
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::AddShip", typeid(int (WorldManager::*)(int , CompleteShip *)), ".5581", argdata, 3, 1, &func);
}

__declspec(naked) int WorldManager::AddShip(int ignore, CompleteShip *ship)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// ship
		push [ebp+8]		// ignore
		call _func621::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func622
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CreateShip", typeid(int (WorldManager::*)(ShipEvent *, bool )), ".5553", argdata, 3, 1, &func);
}

__declspec(naked) int WorldManager::CreateShip(ShipEvent *event, bool unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk
		push [ebp+8]		// event
		call _func622::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func623
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::FormatText", typeid(void *(WorldManager::*)(int , int )), ".5589", argdata, 3, 1, &func);
}

__declspec(naked) void *WorldManager::FormatText(int unk1, int unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func623::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func624
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::ModifyResources", typeid(void *(WorldManager::*)(LocationEvent *)), ".5589", argdata, 2, 1, &func);
}

__declspec(naked) void *WorldManager::ModifyResources(LocationEvent *loc)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// loc
		call _func624::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func625
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CreateChoiceBox", typeid(int (WorldManager::*)(LocationEvent *)), ".5589", argdata, 2, 1, &func);
}

__declspec(naked) int WorldManager::CreateChoiceBox(LocationEvent *loc)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// loc
		call _func625::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func626
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::UpdateLocation", typeid(int (WorldManager::*)(LocationEvent *)), ".5557", argdata, 2, 1, &func);
}

__declspec(naked) int WorldManager::UpdateLocation(LocationEvent *loc)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// loc
		call _func626::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func627
{
	static void *func = 0;
	static short argdata[] = {0x1ff, 0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CreateLocation", typeid(int (WorldManager::*)(int , Location *)), ".5557", argdata, 3, 1, &func);
}

__declspec(naked) int WorldManager::CreateLocation(int ignore, Location *loc)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// loc
		push ecx			// this
		mov ecx, [ebp+8]	// ignore
		call _func627::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func628
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::CreateNewGame", typeid(int (WorldManager::*)()), ".5583", argdata, 1, 1, &func);
}

__declspec(naked) int WorldManager::CreateNewGame()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func628::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func629
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::Restart", typeid(int (WorldManager::*)()), ".5383", argdata, 1, 1, &func);
}

__declspec(naked) int WorldManager::Restart()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func629::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func630
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::StartGame", typeid(int (WorldManager::*)(ShipManager *)), ".5583", argdata, 2, 1, &func);
}

__declspec(naked) int WorldManager::StartGame(ShipManager *playerShip)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// playerShip
		call _func630::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

namespace _func631
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CheckForNewLocation", typeid(bool (WorldManager::*)(int , bool )), ".5583", argdata, 3, 1, &func);
}

__declspec(naked) bool WorldManager::CheckForNewLocation(int unk1, bool unk2)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+12]		// unk2
		push [ebp+8]		// unk1
		call _func631::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 8
	}
}

namespace _func632
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::SaveGame", typeid(int (WorldManager::*)()), ".5583", argdata, 1, 1, &func);
}

__declspec(naked) int WorldManager::SaveGame()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func632::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func633
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::PrepareAutoSave", typeid(bool (WorldManager::*)()), ".5383", argdata, 1, 1, &func);
}

__declspec(naked) bool WorldManager::PrepareAutoSave()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func633::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func634
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::CheckLoadEvent", typeid(int (WorldManager::*)()), ".5589e581ec????????898d54fdffffc7857cfdffff18e16500c78580fdffffd05b75008d45f8898584fdffffc78588fdffff24354c00", argdata, 1, 1, &func);
}

__declspec(naked) int WorldManager::CheckLoadEvent()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func634::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func635
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::PauseLoop", typeid(int (WorldManager::*)()), ".5557", argdata, 1, 1, &func);
}

__declspec(naked) int WorldManager::PauseLoop()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func635::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func636
{
	static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::OnLoop", typeid(int (WorldManager::*)()), ".5589", argdata, 1, 1, &func);
}

__declspec(naked) int WorldManager::OnLoop()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		call _func636::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		ret
	}
}

namespace _func637
{
	static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::LoadGame", typeid(int (WorldManager::*)(char **)), ".5581", argdata, 2, 1, &func);
}

__declspec(naked) int WorldManager::LoadGame(char **unk)
{
	__asm
	{
		push ebp
		mov ebp, esp
		push edx
		push ecx
		push ebx
		push esi
		push edi
		push [ebp+8]		// unk
		call _func637::func
		pop edi
		pop esi
		pop ebx
		pop ecx
		pop edx
		mov esp, ebp
		pop ebp
		retn 4
	}
}

