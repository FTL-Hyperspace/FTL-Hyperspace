#pragma GCC push_options
#pragma GCC optimize ("O1")
#include "CustomCrew.h"
#include "PALMemoryProtection.h"

int requiresFullControl = 0;

bool CrewMember::_HS_GetControllable()
{
    bool req = this->iShipId == 0 && !this->bDead && !this->bMindControlled;

    if (!req)
    {
        return false;
    }
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    bool ret = false;
    ex->CalculateStat(CrewStat::CONTROLLABLE, def, &ret);
    if (!ret && !requiresFullControl)
    {
        ret = def->selectable;
    }
    return ret && req;
}

bool CrewMember::_HS_CanSuffocate()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    bool ret = false;
    ex->CalculateStat(CrewStat::CAN_SUFFOCATE, def, &ret);
    return ret;
}

bool CrewMember::_HS_CanFight()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    bool ret = false;
    ex->CalculateStat(CrewStat::CAN_FIGHT, def, &ret);
    return ret;
}

bool CrewMember::_HS_CanRepair()
{
    bool req = !this->intruder && !this->bDead && this->crewAnim->status != 3;
    if (!req)
    {
        return false;
    }
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    bool ret = false;
    ex->CalculateStat(CrewStat::CAN_REPAIR, def, &ret);
    return ret && req;
}

bool CrewMember::_HS_CanSabotage()
{
    bool req = this->intruder;
    if (!req)
    {
        return false;
    }
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    bool ret = false;
    ex->CalculateStat(CrewStat::CAN_SABOTAGE, def, &ret);
    return ret && req;
}

bool CrewMember::_HS_CanMan()
{
    bool req = !this->intruder && this->fStunTime == 0.f && this->crewAnim->status != 3;
    if (!req)
    {
        return false;
    }
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    bool ret = false;
    ex->CalculateStat(CrewStat::CAN_MAN, def, &ret);
    return ret && req;
}

bool CrewMember::_HS_CanBurn()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    bool ret = false;
    ex->CalculateStat(CrewStat::CAN_BURN, def, &ret);
    return ret;
}

int CrewMember::_HS_GetMaxHealth()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    this->health.second = ex->CalculateStat(CrewStat::MAX_HEALTH, def);
    return this->health.second;
}

float CrewMember::_HS_GetMoveSpeedMultiplier()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    return ex->CalculateStat(CrewStat::MOVE_SPEED_MULTIPLIER, def);
}

float CrewMember::_HS_GetRepairSpeed()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    return ex->CalculateStat(CrewStat::REPAIR_SPEED_MULTIPLIER, def);
}

float CrewMember::_HS_GetDamageMultiplier()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    float damage = ex->CalculateStat(CrewStat::DAMAGE_MULTIPLIER, def);
    if (this->crewAnim->status == 7)
    {
        return damage * ex->CalculateStat(CrewStat::RANGED_DAMAGE_MULTIPLIER, def);
    }
    else
    {
        return damage;
    }
}

bool CrewMember::_HS_ProvidesPower()
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();

    return custom->GetDefinition(this->species)->providesPower;
}

float CrewMember::_HS_FireRepairMultiplier()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    return ex->CalculateStat(CrewStat::FIRE_REPAIR_MULTIPLIER, def);
}

bool CrewMember::_HS_IsTelepathic()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    bool ret = false;
    ex->CalculateStat(CrewStat::IS_TELEPATHIC, def, &ret);
    return ret;
}

float CrewMember::_HS_GetSuffocationModifier()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    return ex->CalculateStat(CrewStat::SUFFOCATION_MODIFIER, def);
}

bool CrewMember::_HS_IsAnaerobic()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    bool ret = false;
    ex->CalculateStat(CrewStat::IS_ANAEROBIC, def, &ret);
    return ret;
}

bool CrewMember::_HS_HasSpecialPower()
{
    auto ex = CM_EX(this);

    return ex->hasSpecialPower;
}

std::pair<float, float> CrewMember::_HS_GetPowerCooldown()
{
    auto ex = CM_EX(this);
    return ex->powerCooldown;
}

bool CrewMember::_HS_PowerReady()
{
    auto ex = CM_EX(this);

    auto readyState = ex->PowerReady();

    return readyState == PowerReadyState::POWER_READY;
}

void CrewMember::_HS_ResetPower()
{
    auto ex = CM_EX(this);

    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto def = custom->GetDefinition(this->species);
    auto powerDef = ex->GetPowerDef();

    auto jumpCooldown = powerDef->jumpCooldown;

    if (jumpCooldown == ActivatedPowerDefinition::JUMP_COOLDOWN_FULL)
    {
        ex->powerCooldown.first = ex->powerCooldown.second;
    }
    else if (jumpCooldown == ActivatedPowerDefinition::JUMP_COOLDOWN_RESET)
    {
        ex->powerCooldown.first = 0;
    }

    ex->powerCharges.first = std::min(ex->powerCharges.second, ex->powerCharges.first + (int)ex->CalculateStat(CrewStat::POWER_CHARGES_PER_JUMP, def));
}

void CrewMember::_HS_ActivatePower()
{
    auto ex = CM_EX(this);

    ex->PreparePower();
}

void SetupVTable(CrewMember *crew)
{
    void** vtable = *(void***)crew;

    MEMPROT_SAVE_PROT(dwOldProtect);
    MEMPROT_PAGESIZE();
    MEMPROT_UNPROTECT(&vtable[0], sizeof(void*) * 57, dwOldProtect);

    vtable[23] = (void*)&CrewMember::_HS_GetControllable;
    vtable[25] = (void*)&CrewMember::_HS_CanFight;
    vtable[26] = (void*)&CrewMember::_HS_CanRepair;
    vtable[27] = (void*)&CrewMember::_HS_CanSabotage;
    vtable[28] = (void*)&CrewMember::_HS_CanMan;
    vtable[31] = (void*)&CrewMember::_HS_CanSuffocate;
    vtable[32] = (void*)&CrewMember::_HS_CanBurn;
    vtable[33] = (void*)&CrewMember::_HS_GetMaxHealth;
    vtable[40] = (void*)&CrewMember::_HS_GetMoveSpeedMultiplier;
    vtable[41] = (void*)&CrewMember::_HS_GetRepairSpeed;
    vtable[42] = (void*)&CrewMember::_HS_GetDamageMultiplier;
    vtable[43] = (void*)&CrewMember::_HS_ProvidesPower;
    vtable[45] = (void*)&CrewMember::_HS_FireRepairMultiplier;
    vtable[46] = (void*)&CrewMember::_HS_IsTelepathic;
    vtable[47] = (void*)&CrewMember::_HS_GetPowerCooldown;
    vtable[48] = (void*)&CrewMember::_HS_PowerReady;
    vtable[49] = (void*)&CrewMember::_HS_ActivatePower;
    vtable[50] = (void*)&CrewMember::_HS_HasSpecialPower;
    vtable[51] = (void*)&CrewMember::_HS_ResetPower;
    vtable[52] = (void*)&CrewMember::_HS_GetSuffocationModifier;
    vtable[55] = (void*)&CrewMember::_HS_IsAnaerobic;

    MEMPROT_REPROTECT(&vtable[0], sizeof(void*) * 57, dwOldProtect);
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



bool CrewAnimation::_HS_CustomDeath()
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (!custom->IsRace(this->race)) return false;
    return custom->GetDefinition(this->race)->hasCustomDeathAnimation;
}

void SetupVTable(CrewAnimation *anim)
{
    void** vtable = *(void***)anim;

    MEMPROT_SAVE_PROT(dwOldProtect);
    MEMPROT_PAGESIZE();
    MEMPROT_UNPROTECT(&vtable[0], sizeof(void*) * 12, dwOldProtect);

    vtable[12] = (void*)&CrewAnimation::_HS_CustomDeath;

    MEMPROT_REPROTECT(&vtable[0], sizeof(void*) * 12, dwOldProtect);
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

HOOK_METHOD_PRIORITY(RockAnimation, constructor, 500, (const std::string &subRace, int iShipId, Pointf position, bool enemy) -> void)
{
    super(subRace, iShipId, position, enemy);

    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (custom->IsRace(subRace))
    {
        SetupVTable(this);
    }
}

#pragma GCC pop_options


