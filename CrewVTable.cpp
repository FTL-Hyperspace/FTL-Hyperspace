#include "CustomCrew.h"


static bool __attribute__((fastcall)) CrewMember_CanSuffocate(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    return custom->GetDefinition(_this->species).canSuffocate;
}

static bool __attribute__((fastcall)) CrewMember_CanFight(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    return custom->GetDefinition(_this->species).canFight;
}

static bool __attribute__((fastcall)) CrewMember_CanBurn(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    return custom->GetDefinition(_this->species).canBurn;
}

static int __attribute__((fastcall)) CrewMember_GetMaxHealth(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    return custom->GetDefinition(_this->species).maxHealth;
}

static float __attribute__((fastcall)) CrewMember_GetMoveSpeedMultiplier(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    return custom->GetDefinition(_this->species).moveSpeedMultiplier;
}

static float __attribute__((fastcall)) CrewMember_GetRepairSpeed(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    return custom->GetDefinition(_this->species).repairSpeed;
}

static float __attribute__((fastcall)) CrewMember_GetDamageMultiplier(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    return custom->GetDefinition(_this->species).damageMultiplier;
}

static bool __attribute__((fastcall)) CrewMember_ProvidesPower(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    return custom->GetDefinition(_this->species).providesPower;
}

static float __attribute__((fastcall)) CrewMember_FireRepairMultiplier(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    return custom->GetDefinition(_this->species).fireRepairMultiplier;
}

static bool __attribute__((fastcall)) CrewMember_IsTelepathic(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    return custom->GetDefinition(_this->species).isTelepathic;
}

static float __attribute__((fastcall)) CrewMember_GetSuffocationModifier(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    return custom->GetDefinition(_this->species).suffocationModifier;
}

static bool __attribute__((fastcall)) CrewMember_IsAnaerobic(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    return custom->GetDefinition(_this->species).isAnaerobic;
}

void SetupVTable(CrewMember *crew)
{
    void** vtable = *(void***)crew;

    DWORD dwOldProtect, dwBkup;
    VirtualProtect(&vtable[0], sizeof(void*) * 57, PAGE_EXECUTE_READWRITE, &dwOldProtect);

    vtable[25] = (void*)&CrewMember_CanFight;
    vtable[31] = (void*)&CrewMember_CanSuffocate;
    vtable[32] = (void*)&CrewMember_CanBurn;
    vtable[33] = (void*)&CrewMember_GetMaxHealth;
    vtable[40] = (void*)&CrewMember_GetMoveSpeedMultiplier;
    vtable[41] = (void*)&CrewMember_GetRepairSpeed;
    vtable[42] = (void*)&CrewMember_GetDamageMultiplier;
    vtable[43] = (void*)&CrewMember_ProvidesPower;
    vtable[45] = (void*)&CrewMember_FireRepairMultiplier;
    vtable[46] = (void*)&CrewMember_IsTelepathic;
    vtable[52] = (void*)&CrewMember_GetSuffocationModifier;
    vtable[55] = (void*)&CrewMember_IsAnaerobic;

    VirtualProtect(&vtable[0], sizeof(void*) * 57, dwOldProtect, &dwBkup);
}



HOOK_METHOD_PRIORITY(CrewMember, constructor, 500, (CrewBlueprint& bp, int shipId, bool intruder, CrewAnimation* animation) -> void)
{
    super(bp, shipId, intruder, animation);

    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if ( custom->IsRace(species) )
    {
        SetupVTable(this);
        health.first = GetMaxHealth();
    }
}



static bool __attribute__((fastcall)) CrewAnimation_CustomDeath(CrewAnimation *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    return custom->GetDefinition(_this->race).hasCustomDeathAnimation;
}

void SetupVTable(CrewAnimation *anim)
{
    void** vtable = *(void***)anim;

    DWORD dwOldProtect, dwBkup;
    VirtualProtect(&vtable[0], sizeof(void*) * 12, PAGE_EXECUTE_READWRITE, &dwOldProtect);

    vtable[12] = (void*)&CrewAnimation_CustomDeath;

    VirtualProtect(&vtable[0], sizeof(void*) * 12, dwOldProtect, &dwBkup);
}



HOOK_METHOD_PRIORITY(CrewAnimation, constructor, 500, (int shipId, const std::string& race, Pointf unk, bool hostile) -> void)
{
    super(shipId, race, unk, hostile);

    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if ( custom->IsRace(race) )
    {
        SetupVTable(this);
    }
}




