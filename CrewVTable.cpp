#include "CustomCrew.h"


static bool __attribute__((fastcall)) CrewMember_GetControllable(CrewMember *_this)
{
    bool req = _this->iShipId == 0 && !_this->bDead && !_this->bMindControlled;

    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto def = custom->GetDefinition(_this->species);

    auto ex = CM_EX(_this);
    if (ex->temporaryPowerActive && def.powerDef.tempPower.controllable.enabled)
    {
        return def.powerDef.tempPower.controllable.value && req;
    }

    return def.controllable && req;
}

static bool __attribute__((fastcall)) CrewMember_CanSuffocate(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto def = custom->GetDefinition(_this->species);

    auto ex = CM_EX(_this);
    if (ex->temporaryPowerActive && def.powerDef.tempPower.canSuffocate.enabled)
    {
        return def.powerDef.tempPower.canSuffocate.value;
    }

    return def.canSuffocate;
}

static bool __attribute__((fastcall)) CrewMember_CanFight(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto def = custom->GetDefinition(_this->species);

    auto ex = CM_EX(_this);
    if (ex->temporaryPowerActive && def.powerDef.tempPower.canFight.enabled)
    {
        return def.powerDef.tempPower.canFight.value;
    }

    return def.canFight;
}

static bool __attribute__((fastcall)) CrewMember_CanRepair(CrewMember *_this)
{
    bool req = !_this->intruder && !_this->bDead && _this->crewAnim->status != 3;

    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto def = custom->GetDefinition(_this->species);

    auto ex = CM_EX(_this);
    if (ex->temporaryPowerActive && def.powerDef.tempPower.canRepair.enabled)
    {
        return def.powerDef.tempPower.canRepair.value && req;
    }

    return def.canRepair && req;
}

static bool __attribute__((fastcall)) CrewMember_CanSabotage(CrewMember *_this)
{
    bool req = _this->intruder;

    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto def = custom->GetDefinition(_this->species);

    auto ex = CM_EX(_this);
    if (ex->temporaryPowerActive && def.powerDef.tempPower.canSabotage.enabled)
    {
        return def.powerDef.tempPower.canSabotage.value && req;
    }

    return def.canSabotage && req;
}

static bool __attribute__((fastcall)) CrewMember_CanMan(CrewMember *_this)
{
    bool req = !_this->intruder && _this->fStunTime == 0.f && _this->crewAnim->status != 3;
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto def = custom->GetDefinition(_this->species);

    auto ex = CM_EX(_this);
    if (ex->temporaryPowerActive && def.powerDef.tempPower.canMan.enabled)
    {
        return def.powerDef.tempPower.canMan.value && req;
    }

    return def.canMan && req;
}


static bool __attribute__((fastcall)) CrewMember_CanBurn(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    return custom->GetDefinition(_this->species).canBurn;
}

static int __attribute__((fastcall)) CrewMember_GetMaxHealth(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    CrewMember_Extend* ex = CM_EX(_this);
    if (_this->GetShipObject()->HasAugmentation("HEALTH_BOOST"))
    {
        float augAmount = _this->GetShipObject()->GetAugmentationValue("HEALTH_BOOST");
        if (augAmount != ex->augHealthMultiplier)
        {
            _this->health.second /= ex->augHealthMultiplier;
            _this->health.second *= augAmount;
            _this->health.first *= (augAmount / ex->augHealthMultiplier);
        }
        ex->augHealthMultiplier = augAmount;
    }
    else
    {
        ex->augHealthMultiplier = 1.f;
    }
    return custom->GetDefinition(_this->species).maxHealth * ex->augHealthMultiplier;
}

static float __attribute__((fastcall)) CrewMember_GetMoveSpeedMultiplier(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto def = custom->GetDefinition(_this->species);

    auto ex = CM_EX(_this);
    if (ex->temporaryPowerActive && def.powerDef.tempPower.moveSpeedMultiplier.enabled)
    {
        return def.powerDef.tempPower.moveSpeedMultiplier.value;
    }

    return def.moveSpeedMultiplier;
}

static float __attribute__((fastcall)) CrewMember_GetRepairSpeed(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto def = custom->GetDefinition(_this->species);

    CrewMember_Extend* ex = CM_EX(_this);
    if (_this->GetShipObject()->HasAugmentation("REPAIR_BOOST"))
    {
        float augAmount = _this->GetShipObject()->GetAugmentationValue("REPAIR_BOOST");
        ex->augRepairSpeedMultiplier = augAmount;
        if (ex->temporaryPowerActive && def.powerDef.tempPower.repairSpeed.enabled)
        {
            return def.powerDef.tempPower.repairSpeed.value * ex->augRepairSpeedMultiplier;
        }
    }
    else
    {
        ex->augRepairSpeedMultiplier = 1.f;
    }

    return def.repairSpeed * ex->augRepairSpeedMultiplier;
}

static float __attribute__((fastcall)) CrewMember_GetDamageMultiplier(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto def = custom->GetDefinition(_this->species);

    auto ex = CM_EX(_this);
    if (_this->GetShipObject()->HasAugmentation("DAMAGE_BOOST"))
    {
        float augAmount = _this->GetShipObject()->GetAugmentationValue("DAMAGE_BOOST");
        ex->augDamageMultiplier = augAmount;
        if (ex->temporaryPowerActive && def.powerDef.tempPower.damageMultiplier.enabled)
        {
            return def.powerDef.tempPower.damageMultiplier.value * ex->augDamageMultiplier;
        }
    }
    else
    {
        ex->augDamageMultiplier = 1.f;
    }

    return def.damageMultiplier * ex->augDamageMultiplier;
}

static bool __attribute__((fastcall)) CrewMember_ProvidesPower(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();

    return custom->GetDefinition(_this->species).providesPower;
}

static float __attribute__((fastcall)) CrewMember_FireRepairMultiplier(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto def = custom->GetDefinition(_this->species);

    CrewMember_Extend* ex = CM_EX(_this);
    if (_this->GetShipObject()->HasAugmentation("REPAIR_BOOST"))
    {
        float augAmount = _this->GetShipObject()->GetAugmentationValue("REPAIR_BOOST");
        ex->augRepairSpeedMultiplier = augAmount;
    }
    else
    {
        ex->augRepairSpeedMultiplier = 1.f;
    }
    return custom->GetDefinition(_this->species).fireRepairMultiplier * ex->augRepairSpeedMultiplier;
}

static bool __attribute__((fastcall)) CrewMember_IsTelepathic(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto def = custom->GetDefinition(_this->species);

    auto ex = CM_EX(_this);
    if (ex->temporaryPowerActive && def.powerDef.tempPower.isTelepathic.enabled)
    {
        return def.powerDef.tempPower.isTelepathic.value;
    }

    return def.isTelepathic;
}

static float __attribute__((fastcall)) CrewMember_GetSuffocationModifier(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto def = custom->GetDefinition(_this->species);

    auto ex = CM_EX(_this);
    if (ex->temporaryPowerActive && def.powerDef.tempPower.suffocationModifier.enabled)
    {
        return def.powerDef.tempPower.suffocationModifier.value;
    }

    return custom->GetDefinition(_this->species).suffocationModifier;
}

static bool __attribute__((fastcall)) CrewMember_IsAnaerobic(CrewMember *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    return custom->GetDefinition(_this->species).isAnaerobic;
}

static bool __attribute__((fastcall)) CrewMember_HasSpecialPower(CrewMember *_this)
{
    auto ex = CM_EX(_this);

    return ex->hasSpecialPower;
}

static std::pair<float, float> __attribute__((fastcall)) CrewMember_GetPowerCooldown(CrewMember *_this)
{
    auto ex = CM_EX(_this);

    return ex->powerCooldown;
}

static bool __attribute__((fastcall)) CrewMember_PowerReady(CrewMember *_this)
{
    auto ex = CM_EX(_this);

    auto readyState = ex->PowerReady();

    return readyState == PowerReadyState::POWER_READY;
}

static void __attribute__((fastcall)) CrewMember_ResetPower(CrewMember *_this)
{
    auto ex = CM_EX(_this);

    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto jumpCooldown = custom->GetDefinition(_this->species).powerDef.jumpCooldown;

    if (jumpCooldown == ActivatedPowerDefinition::JUMP_COOLDOWN_FULL)
    {
        ex->powerCooldown.first = ex->powerCooldown.second;
    }
    else if (jumpCooldown == ActivatedPowerDefinition::JUMP_COOLDOWN_RESET)
    {
        ex->powerCooldown.first = 0;
    }

}

static void __attribute__((fastcall)) CrewMember_ActivatePower(CrewMember *_this)
{
    auto ex = CM_EX(_this);

    ex->PreparePower();
}

void SetupVTable(CrewMember *crew)
{
    void** vtable = *(void***)crew;

    DWORD dwOldProtect, dwBkup;
    VirtualProtect(&vtable[0], sizeof(void*) * 57, PAGE_EXECUTE_READWRITE, &dwOldProtect);

    vtable[23] = (void*)&CrewMember_GetControllable;
    vtable[25] = (void*)&CrewMember_CanFight;
    vtable[26] = (void*)&CrewMember_CanRepair;
    vtable[27] = (void*)&CrewMember_CanSabotage;
    vtable[28] = (void*)&CrewMember_CanMan;
    vtable[31] = (void*)&CrewMember_CanSuffocate;
    vtable[32] = (void*)&CrewMember_CanBurn;
    vtable[33] = (void*)&CrewMember_GetMaxHealth;
    vtable[40] = (void*)&CrewMember_GetMoveSpeedMultiplier;
    vtable[41] = (void*)&CrewMember_GetRepairSpeed;
    vtable[42] = (void*)&CrewMember_GetDamageMultiplier;
    vtable[43] = (void*)&CrewMember_ProvidesPower;
    vtable[45] = (void*)&CrewMember_FireRepairMultiplier;
    vtable[46] = (void*)&CrewMember_IsTelepathic;
    vtable[47] = (void*)&CrewMember_GetPowerCooldown;
    vtable[48] = (void*)&CrewMember_PowerReady;
    vtable[49] = (void*)&CrewMember_ActivatePower;
    vtable[50] = (void*)&CrewMember_HasSpecialPower;
    vtable[51] = (void*)&CrewMember_ResetPower;
    vtable[52] = (void*)&CrewMember_GetSuffocationModifier;
    vtable[55] = (void*)&CrewMember_IsAnaerobic;

    VirtualProtect(&vtable[0], sizeof(void*) * 57, dwOldProtect, &dwBkup);
}



HOOK_METHOD_PRIORITY(CrewMember, constructor, 500, (CrewBlueprint& bp, int shipId, bool intruder, CrewAnimation* animation) -> void)
{
    super(bp, shipId, intruder, animation);

    CustomCrewManager *custom = CustomCrewManager::GetInstance();

    if (custom->IsRace(species) && !IsDrone())
    {
        SetupVTable(this);
        health.first = GetMaxHealth();
    }
}



static bool __attribute__((fastcall)) CrewAnimation_CustomDeath(CrewAnimation *_this)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (!custom->IsRace(_this->race)) return false;
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
    if (custom->IsRace(race) && !bDrone)
    {
        SetupVTable(this);
    }
}




