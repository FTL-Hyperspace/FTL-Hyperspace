#include "CustomCrew.h"

#include "Resources.h"
#include <boost/lexical_cast.hpp>
#include <algorithm>


static const std::string CREW_SKILLS[6] =
{
    "piloting",
    "engines",
    "shields",
    "weapons",
    "repair",
    "combat"
};

CustomCrewManager CustomCrewManager::instance = CustomCrewManager();


void CustomCrewManager::AddCrewDefinition(CrewDefinition crew)
{
    blueprintNames[crew.race] = crew;
}


void CustomCrewManager::ParseCrewNode(rapidxml::xml_node<char> *node)
{
    try
    {
        for (auto child = node->first_node(); child; child = child->next_sibling())
        {
            if (child->first_attribute("name"))
            {
                std::string name = std::string(child->first_attribute("name")->value());

                CrewDefinition crew;

                crew.race = name;
                crew.deathSounds = std::vector<std::string>();
                crew.shootingSounds = std::vector<std::string>();

                crew.skillsDef = SkillsDefinition();
                crew.explosionDef = Damage();

                crew.explosionDef.iDamage = 0;
                crew.explosionDef.iShieldPiercing = 0;
                crew.explosionDef.fireChance = 0;
                crew.explosionDef.breachChance = 0;
                crew.explosionDef.stunChance = 0;
                crew.explosionDef.iIonDamage = 0;
                crew.explosionDef.iSystemDamage = 0;
                crew.explosionDef.iPersDamage = 0;
                crew.explosionDef.bHullBuster = false;
                crew.explosionDef.ownerId = -1;
                crew.explosionDef.selfId = -1;
                crew.explosionDef.bLockdown = false;
                crew.explosionDef.crystalShard = false;
                crew.explosionDef.bFriendlyFire = false;
                crew.explosionDef.iStun = 0;
                crew.explosionShipFriendlyFire = false;

                crew.powerDef.damage = Damage();
                crew.powerDef.damage.iDamage = 0;
                crew.powerDef.damage.iShieldPiercing = 0;
                crew.powerDef.damage.fireChance = 0;
                crew.powerDef.damage.breachChance = 0;
                crew.powerDef.damage.stunChance = 0;
                crew.powerDef.damage.iIonDamage = 0;
                crew.powerDef.damage.iSystemDamage = 0;
                crew.powerDef.damage.iPersDamage = 0;
                crew.powerDef.damage.bHullBuster = false;
                crew.powerDef.damage.ownerId = -1;
                crew.powerDef.damage.selfId = -1;
                crew.powerDef.damage.bLockdown = false;
                crew.powerDef.damage.crystalShard = false;
                crew.powerDef.damage.bFriendlyFire = false;
                crew.powerDef.damage.iStun = 0;
                crew.powerDef.sounds = std::vector<std::string>();
                crew.powerDef.buttonLabel = TextString();
                crew.powerDef.cooldownColor = GL_Color(133.f / 255.f, 231.f / 255.f, 237.f / 255.f, 1.f);
                crew.powerDef.req = ActivatedPowerRequirements();
                crew.powerDef.tempPower = TemporaryPowerDefinition();
                crew.powerDef.tempPower.cooldownColor = GL_Color(1.f, 1.f, 1.f, 1.f);

                try
                {
                    for (auto stat = child->first_node(); stat; stat = stat->next_sibling())
                    {
                        std::string str = std::string(stat->name());
                        std::string val = std::string(stat->value());

                        if (str == "canFight")
                        {
                            crew.canFight = EventsParser::ParseBoolean(val);
                        }
                        if (str == "canSuffocate")
                        {
                            crew.canSuffocate = EventsParser::ParseBoolean(val);
                        }
                        if (str == "canBurn")
                        {
                            crew.canBurn = EventsParser::ParseBoolean(val);
                        }
                        if (str == "maxHealth")
                        {
                            crew.maxHealth = boost::lexical_cast<int>(val);
                        }
                        if (str == "moveSpeedMultiplier")
                        {
                            crew.moveSpeedMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "repairSpeed")
                        {
                            crew.repairSpeed = boost::lexical_cast<float>(val);
                        }
                        if (str == "damageMultiplier")
                        {
                            crew.damageMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "fireRepairMultiplier")
                        {
                            crew.fireRepairMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "suffocationModifier")
                        {
                            crew.suffocationModifier = boost::lexical_cast<float>(val);
                        }
                        if (str == "providesPower")
                        {
                            crew.providesPower = EventsParser::ParseBoolean(val);
                        }
                        if (str == "bonusPower")
                        {
                            crew.bonusPower = boost::lexical_cast<int>(val);
                        }
                        if (str == "isTelepathic")
                        {
                            crew.isTelepathic = EventsParser::ParseBoolean(val);
                        }
                        if (str == "isAnaerobic")
                        {
                            crew.isAnaerobic = EventsParser::ParseBoolean(val);
                        }
                        if (str == "fireDamageMultiplier")
                        {
                            crew.fireDamageMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "canPhaseThroughDoors")
                        {
                            crew.canPhaseThroughDoors = EventsParser::ParseBoolean(val);
                        }
                        if (str == "deathSounds")
                        {
                            for (auto deathSoundNode = stat->first_node(); deathSoundNode; deathSoundNode = deathSoundNode->next_sibling())
                            {
                                if (strcmp(deathSoundNode->name(), "deathSound") == 0)
                                {
                                    crew.deathSounds.push_back(std::string(deathSoundNode->value()));
                                }
                            }
                        }
                        if (str == "shootingSounds")
                        {
                            for (auto shootingSoundNode = stat->first_node(); shootingSoundNode; shootingSoundNode = shootingSoundNode->next_sibling())
                            {
                                if (strcmp(shootingSoundNode->name(), "shootingSound") == 0)
                                {
                                    crew.shootingSounds.push_back(std::string(shootingSoundNode->value()));
                                }
                            }
                        }
                        if (str == "animBase")
                        {
                            crew.animBase = val;
                        }
                        if (str == "oxygenChangeSpeed")
                        {
                            crew.oxygenChangeSpeed = boost::lexical_cast<float>(val);
                        }
                        if (str == "damageTakenMultiplier")
                        {
                            crew.damageTakenMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "passiveHealAmount")
                        {
                            crew.passiveHealAmount = boost::lexical_cast<float>(val);
                        }
                        if (str == "passiveHealDelay")
                        {
                            crew.passiveHealDelay = boost::lexical_cast<int>(val);
                        }
                        if (str == "detectsLifeforms")
                        {
                            crew.detectsLifeforms = EventsParser::ParseBoolean(val);
                        }
                        if (str == "skills")
                        {
                            for (auto skillNode = stat->first_node(); skillNode; skillNode = skillNode->next_sibling())
                            {
                                std::string skillName = std::string(skillNode->name());

                                for (auto i : CREW_SKILLS)
                                {
                                    if (skillName == i)
                                    {
                                        if (skillNode->first_attribute("req"))
                                        {
                                            crew.skillsDef.skills[i].requirement = boost::lexical_cast<int>(skillNode->first_attribute("req")->value());
                                        }
                                    }
                                }
                            }
                        }
                        if (str == "hasCustomDeathAnimation")
                        {
                            crew.hasCustomDeathAnimation = EventsParser::ParseBoolean(val);
                        }
                        if (str == "deathEffect")
                        {
                            crew.hasDeathExplosion = true;
                            for (auto effectNode = stat->first_node(); effectNode; effectNode = effectNode->next_sibling())
                            {
                                std::string effectName = std::string(effectNode->name());


                                if (effectName == "damage")
                                {
                                    crew.explosionDef.iDamage = boost::lexical_cast<int>(effectNode->value());
                                }
                                if (effectName == "fireChance")
                                {
                                    crew.explosionDef.fireChance = boost::lexical_cast<int>(effectNode->value());
                                }
                                if (effectName == "breachChance")
                                {
                                    crew.explosionDef.breachChance = boost::lexical_cast<int>(effectNode->value());
                                }
                                if (effectName == "ion")
                                {
                                    crew.explosionDef.iIonDamage = boost::lexical_cast<int>(effectNode->value());
                                }
                                if (effectName == "sysDamage")
                                {
                                    crew.explosionDef.iSystemDamage = boost::lexical_cast<int>(effectNode->value());
                                }
                                if (effectName == "persDamage")
                                {
                                    crew.explosionDef.iPersDamage = boost::lexical_cast<int>(effectNode->value());
                                }
                                if (effectName == "hullBust")
                                {
                                    crew.explosionDef.bHullBuster = EventsParser::ParseBoolean(effectNode->value());
                                }
                                if (effectName == "lockdown")
                                {
                                    crew.explosionDef.bLockdown = EventsParser::ParseBoolean(effectNode->value());
                                }
                                if (effectName == "friendlyFire")
                                {
                                    crew.explosionDef.bFriendlyFire = EventsParser::ParseBoolean(effectNode->value());
                                }
                                if (effectName == "stun")
                                {
                                    crew.explosionDef.iStun = boost::lexical_cast<int>(effectNode->value());
                                }
                                if (effectName == "shipFriendlyFire")
                                {
                                    crew.explosionShipFriendlyFire = EventsParser::ParseBoolean(effectNode->value());
                                }
                            }
                        }
                        if (str == "powerEffect")
                        {
                            crew.powerDef.hasSpecialPower = true;
                            for (auto effectNode = stat->first_node(); effectNode; effectNode = effectNode->next_sibling())
                            {
                                std::string effectName = std::string(effectNode->name());

                                if (effectName == "powerSounds")
                                {
                                    for (auto soundNode = effectNode->first_node(); soundNode; soundNode = soundNode->next_sibling())
                                    {
                                        if (strcmp(soundNode->name(), "powerSound") == 0)
                                        {
                                            crew.powerDef.sounds.push_back(std::string(soundNode->value()));
                                        }
                                    }
                                }
                                if (effectName == "req")
                                {
                                    for (auto reqNode = effectNode->first_node(); reqNode; reqNode = reqNode->next_sibling())
                                    {
                                        std::string req = reqNode->name();

                                        if (req == "enemyShip")
                                        {
                                            crew.powerDef.req.enemyShip = true;
                                        }
                                        if (req == "playerShip")
                                        {
                                            crew.powerDef.req.playerShip = true;
                                        }
                                        if (req == "friendlyInRoom")
                                        {
                                            crew.powerDef.req.friendlyInRoom = true;
                                        }
                                        if (req == "enemyInRoom")
                                        {
                                            crew.powerDef.req.enemyInRoom = true;
                                        }
                                        if (req == "systemInRoom")
                                        {
                                            crew.powerDef.req.systemInRoom = true;
                                        }
                                    }
                                }

                                if (effectName == "damage")
                                {
                                    crew.powerDef.damage.iDamage = boost::lexical_cast<int>(effectNode->value());
                                }
                                if (effectName == "fireChance")
                                {
                                    crew.powerDef.damage.fireChance = boost::lexical_cast<int>(effectNode->value());
                                }
                                if (effectName == "breachChance")
                                {
                                    crew.powerDef.damage.breachChance = boost::lexical_cast<int>(effectNode->value());
                                }
                                if (effectName == "ion")
                                {
                                    crew.powerDef.damage.iIonDamage = boost::lexical_cast<int>(effectNode->value());
                                }
                                if (effectName == "sysDamage")
                                {
                                    crew.powerDef.damage.iSystemDamage = boost::lexical_cast<int>(effectNode->value());
                                }
                                if (effectName == "persDamage")
                                {
                                    crew.powerDef.damage.iPersDamage = boost::lexical_cast<int>(effectNode->value());
                                }
                                if (effectName == "hullBust")
                                {
                                    crew.powerDef.damage.bHullBuster = EventsParser::ParseBoolean(effectNode->value());
                                }
                                if (effectName == "lockdown")
                                {
                                    crew.powerDef.damage.bLockdown = EventsParser::ParseBoolean(effectNode->value());
                                }
                                if (effectName == "friendlyFire")
                                {
                                    crew.powerDef.damage.bFriendlyFire = EventsParser::ParseBoolean(effectNode->value());
                                }
                                if (effectName == "stun")
                                {
                                    crew.powerDef.damage.iStun = boost::lexical_cast<int>(effectNode->value());
                                }
                                if (effectName == "cooldown")
                                {
                                    crew.powerDef.cooldown = boost::lexical_cast<float>(effectNode->value());
                                }
                                if (effectName == "shipFriendlyFire")
                                {
                                    crew.powerDef.shipFriendlyFire = EventsParser::ParseBoolean(effectNode->value());
                                }
                                if (effectName == "win")
                                {
                                    crew.powerDef.win = EventsParser::ParseBoolean(effectNode->value());
                                }
                                if (effectName == "buttonText")
                                {
                                    if (effectNode->first_attribute("id"))
                                    {
                                        crew.powerDef.buttonLabel.data = effectNode->first_attribute("id")->value();
                                        crew.powerDef.buttonLabel.isLiteral = false;
                                    }
                                    else
                                    {
                                        crew.powerDef.buttonLabel.data = effectNode->value();
                                        crew.powerDef.buttonLabel.isLiteral = true;
                                    }
                                }
                                if (effectName == "tooltip")
                                {
                                    if (effectNode->first_attribute("id"))
                                    {
                                        crew.powerDef.tooltip.data = effectNode->first_attribute("id")->value();
                                        crew.powerDef.tooltip.isLiteral = false;
                                    }
                                    else
                                    {
                                        crew.powerDef.tooltip.data = effectNode->value();
                                        crew.powerDef.tooltip.isLiteral = true;
                                    }
                                }
                                if (effectName == "cooldownColor")
                                {
                                    ParseColorNode(crew.powerDef.cooldownColor, effectNode);
                                }
                                if (effectName == "effectAnim")
                                {
                                    crew.powerDef.effectAnim = effectNode->value();
                                }
                                if (effectName == "crewHealth")
                                {
                                    crew.powerDef.crewHealth = boost::lexical_cast<float>(effectNode->value());
                                }
                                if (effectName == "enemyHealth")
                                {
                                    crew.powerDef.enemyHealth = boost::lexical_cast<float>(effectNode->value());
                                }
                                if (effectName == "selfHealth")
                                {
                                    crew.powerDef.selfHealth = boost::lexical_cast<float>(effectNode->value());
                                }
                                if (effectName == "temporaryEffect")
                                {
                                    crew.powerDef.hasTemporaryPower = true;

                                    for (auto tempEffectNode = effectNode->first_node(); tempEffectNode; tempEffectNode = tempEffectNode->next_sibling())
                                    {
                                        std::string tempEffectName = std::string(tempEffectNode->name());

                                        if (tempEffectName == "duration")
                                        {
                                            crew.powerDef.tempPower.duration = boost::lexical_cast<float>(tempEffectNode->value());
                                        }
                                        if (tempEffectName == "cooldownColor")
                                        {
                                            ParseColorNode(crew.powerDef.tempPower.cooldownColor, tempEffectNode);
                                        }
                                        if (tempEffectName == "finishSounds")
                                        {
                                            for (auto soundNode = tempEffectNode->first_node(); soundNode; soundNode = soundNode->next_sibling())
                                            {
                                                if (strcmp(soundNode->name(), "finishSound") == 0)
                                                {
                                                    crew.powerDef.tempPower.sounds.push_back(std::string(soundNode->value()));
                                                }
                                            }
                                        }
                                        if (tempEffectName == "speedBoost")
                                        {
                                            crew.powerDef.tempPower.speedBoost = boost::lexical_cast<float>(tempEffectNode->value());
                                        }
                                        if (tempEffectName == "repairBoost")
                                        {
                                            crew.powerDef.tempPower.repairBoost = boost::lexical_cast<float>(tempEffectNode->value());
                                        }
                                        if (tempEffectName == "combatBoost")
                                        {
                                            crew.powerDef.tempPower.combatBoost = boost::lexical_cast<float>(tempEffectNode->value());
                                        }
                                        if (tempEffectName == "bonusPower")
                                        {
                                            crew.powerDef.tempPower.bonusPower = boost::lexical_cast<int>(tempEffectNode->value());
                                        }
                                        if (tempEffectName == "effectAnim")
                                        {
                                            crew.powerDef.tempPower.effectAnim = tempEffectNode->value();
                                        }
                                        if (tempEffectName == "invulnerable")
                                        {
                                            crew.powerDef.tempPower.invulnerable = EventsParser::ParseBoolean(tempEffectNode->value());
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                catch (boost::bad_lexical_cast const &e)
                {
                    MessageBoxA(GetDesktopWindow(), e.what(), "Error", MB_ICONERROR | MB_SETFOREGROUND);
                }

                AddCrewDefinition(crew);
            }
        }
    }
    catch (std::exception)
    {
        MessageBoxA(GetDesktopWindow(), "Error parsing <crew> in hyperspace.xml", "Error", MB_ICONERROR | MB_SETFOREGROUND);
    }

}


CrewMember* CustomCrewManager::CreateCrewMember(CrewBlueprint* bp, int shipId, bool intruder)
{
    std::string race = bp->name;
    if (!IsRace(race))
        return 0;

    Pointf unk = Pointf(0.f, 0.f);
    CrewAnimation* animation = new CrewAnimation(shipId, race, unk, intruder);

    CrewDefinition def = GetDefinition(race);

    CrewMember *crew;
    crew = new CrewMember(*bp, shipId, intruder, animation);

    return crew;
}

bool CustomCrewManager::IsRace(const std::string& race)
{
    return std::count_if(blueprintNames.begin(),
                         blueprintNames.end(),
                         [race](std::pair<std::string, CrewDefinition> i) { return i.first == race; } )
                          > 0;
}


PowerReadyState CrewMember_Extend::PowerReady()
{
    auto req = CustomCrewManager::GetInstance()->GetDefinition(orig->species).powerDef.req;

    ShipManager *ship;

    if (orig->currentShipId == 0)
    {
        ship = G_->GetWorld()->playerShip->shipManager;
    }
    else
    {
        ship = G_->GetWorld()->playerShip->enemyShip->shipManager;
    }

    if (temporaryPowerActive)
    {
        return POWER_NOT_READY_ACTIVATED;
    }
    else if (powerCooldown.first < powerCooldown.second)
    {
        return POWER_NOT_READY_COOLDOWN;
    }
    else if (!orig->intruder && req.enemyShip)
    {
        return POWER_NOT_READY_ENEMY_SHIP;
    }
    else if (orig->intruder && req.playerShip)
    {
        return POWER_NOT_READY_PLAYER_SHIP;
    }
    else if (!ship->GetSystemInRoom(orig->iRoomId) && req.systemInRoom)
    {
        return POWER_NOT_READY_SYSTEM_IN_ROOM;
    }
    else if (!req.enemyInRoom && !req.friendlyInRoom)
    {
        return POWER_READY;
    }
    else
    {
        bool enemyInRoom = false;
        bool friendlyInRoom = false;

        for (auto i : ship->vCrewList)
        {
            if (i->iRoomId == orig->iRoomId)
            {
                enemyInRoom = enemyInRoom || (i->intruder != orig->intruder);
                friendlyInRoom = friendlyInRoom || (i->intruder == orig->intruder);
            }
        }

        if (!enemyInRoom && req.enemyInRoom)
        {
            return POWER_NOT_READY_ENEMY_IN_ROOM;
        }
        else if (!friendlyInRoom && req.friendlyInRoom)
        {
            return POWER_NOT_READY_FRIENDLY_IN_ROOM;
        }
    }

    return POWER_READY;
}


void CrewMember_Extend::ActivatePower()
{
    ActivatedPowerDefinition powerDef = CustomCrewManager::GetInstance()->GetDefinition(orig->species).powerDef;

    ShipManager *ship;

    if (orig->currentShipId == 0)
    {
        ship = G_->GetWorld()->playerShip->shipManager;
    }
    else
    {
        ship = G_->GetWorld()->playerShip->enemyShip->shipManager;
    }

    if (hasTemporaryPower)
    {
        temporaryPowerActive = true;
        temporaryPowerDuration.first = powerDef.tempPower.duration;
    }
    powerCooldown.first = 0;

    powerActivated = true;

    if (powerDef.damage.bLockdown)
    {
        orig->ship->LockdownRoom(orig->iRoomId, Pointf(orig->x, orig->y));
    }

    if (powerDef.sounds.size() > 0)
    {
        int rng = rand();

        std::string sound = powerDef.sounds[rng % powerDef.sounds.size()];

        G_->GetSoundControl()->PlaySoundMix(sound, -1, false);
    }

    auto aex = CMA_EX(orig->crewAnim);

    if (aex->effectAnim != NULL)
    {

        aex->effectAnim->SetCurrentFrame(0);
        aex->effectAnim->tracker.SetLoop(false, -1);
        aex->effectAnim->Start(true);
    }

    if (aex->tempEffectAnim != NULL)
    {

        aex->tempEffectAnim->SetCurrentFrame(0);
        aex->tempEffectAnim->tracker.SetLoop(true, 0);
        aex->tempEffectAnim->Start(true);
    }

    if (powerDef.win)
    {
        G_->GetCApp()->gui->Victory();
    }

    if (powerDef.crewHealth > 0.f || powerDef.enemyHealth > 0.f)
    {
        for (auto i : ship->vCrewList)
        {
            if (i->iRoomId == orig->iRoomId && i != orig)
            {
                if (i->intruder == orig->intruder)
                {
                    i->DirectModifyHealth(powerDef.crewHealth);
                }
                else
                {
                    i->DirectModifyHealth(powerDef.enemyHealth);
                }
            }
        }
    }

    if (powerDef.selfHealth > 0.f)
    {
        orig->DirectModifyHealth(powerDef.selfHealth);
    }
}

void CrewMember_Extend::TemporaryPowerFinished()
{
    ActivatedPowerDefinition powerDef = CustomCrewManager::GetInstance()->GetDefinition(orig->species).powerDef;

    temporaryPowerActive = false;

    if (powerDef.tempPower.sounds.size() > 0)
    {
        int rng = rand();

        std::string sound = powerDef.tempPower.sounds[rng % powerDef.tempPower.sounds.size()];

        G_->GetSoundControl()->PlaySoundMix(sound, -1, false);
    }

    auto aex = CMA_EX(orig->crewAnim);

    if (aex->tempEffectAnim != NULL)
    {
        aex->tempEffectAnim->tracker.Stop(false);
    }
}

void CrewAnimation_Extend::OnInit(const std::string& name, Pointf position, bool enemy)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();


    if (custom->IsRace(orig->race))
    {
        auto def = custom->GetDefinition(orig->race);

        if (!def.powerDef.effectAnim.empty())
        {
            Animation *anim = new Animation();

            AnimationControl::GetAnimation(*anim, G_->GetAnimationControl(), def.powerDef.effectAnim);

            effectAnim = anim;



            //ex->effectAnim = effectAnim;
        }
        if (!def.powerDef.tempPower.effectAnim.empty())
        {
            Animation *anim = new Animation();

            AnimationControl::GetAnimation(*anim, G_->GetAnimationControl(), def.powerDef.tempPower.effectAnim);

            tempEffectAnim = anim;



            //ex->effectAnim = effectAnim;
        }
    }
}



//=================================

HOOK_METHOD_PRIORITY(CrewMember, constructor, -899, (CrewBlueprint& bp, int shipId, bool enemy, CrewAnimation *animation) -> void)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();

    super(bp, shipId, enemy, animation);

    CrewMember_Extend* ex = CM_EX(this);


    if (custom->IsRace(species))
    {
        auto def = custom->GetDefinition(species);

        if (def.animBase == "rock")
        {
            crewAnim = new RockAnimation(bp.name, shipId, Pointf(0, 0), enemy);
        }

        if (def.passiveHealAmount > 0.f)
        {
            ex->passiveHealTimer = new TimerHelper();
            ex->passiveHealTimer->Start(def.passiveHealDelay);
        }

        ex->powerCooldown.first = 0.f;
        ex->powerCooldown.second = def.powerDef.cooldown;
        ex->temporaryPowerDuration.second = def.powerDef.tempPower.duration;
        ex->temporaryPowerDuration.first = ex->temporaryPowerDuration.second;
        ex->hasSpecialPower = def.powerDef.hasSpecialPower;
        ex->hasTemporaryPower = def.powerDef.hasTemporaryPower;

        ex->hasEffectAnim = !def.powerDef.effectAnim.empty();
        ex->hasTempEffectAnim = !def.powerDef.tempPower.effectAnim.empty();


        auto skillsDef = def.skillsDef;

        blueprint.skillLevel[0].first = ((float)blueprint.skillLevel[0].first / blueprint.skillLevel[0].second) * (skillsDef.skills["piloting"].requirement * 2);
        blueprint.skillLevel[1].first = ((float)blueprint.skillLevel[1].first / blueprint.skillLevel[1].second) * (skillsDef.skills["engines"].requirement * 2);
        blueprint.skillLevel[2].first = ((float)blueprint.skillLevel[2].first / blueprint.skillLevel[2].second) * (skillsDef.skills["shields"].requirement * 2);
        blueprint.skillLevel[3].first = ((float)blueprint.skillLevel[3].first / blueprint.skillLevel[3].second) * (skillsDef.skills["weapons"].requirement * 2);
        blueprint.skillLevel[4].first = ((float)blueprint.skillLevel[4].first / blueprint.skillLevel[4].second) * (skillsDef.skills["repair"].requirement * 2);
        blueprint.skillLevel[5].first = ((float)blueprint.skillLevel[5].first / blueprint.skillLevel[5].second) * (skillsDef.skills["combat"].requirement * 2);

        blueprint.skillLevel[0].second = skillsDef.skills["piloting"].requirement * 2;
        blueprint.skillLevel[1].second = skillsDef.skills["engines"].requirement * 2;
        blueprint.skillLevel[2].second = skillsDef.skills["shields"].requirement * 2;
        blueprint.skillLevel[3].second = skillsDef.skills["weapons"].requirement * 2;
        blueprint.skillLevel[4].second = skillsDef.skills["repair"].requirement * 2;
        blueprint.skillLevel[5].second = skillsDef.skills["combat"].requirement * 2;

    }
}

HOOK_METHOD(CrewBlueprint, RandomSkills, (int worldLevel) -> void)
{
    auto custom = CustomCrewManager::GetInstance();
    super(worldLevel);


    if (custom->IsRace(name))
    {
        auto skillsDef = custom->GetDefinition(name).skillsDef;
        skillLevel[0].first = ((float)skillLevel[0].first / skillLevel[0].second) * (skillsDef.skills["piloting"].requirement * 2);
        skillLevel[1].first = ((float)skillLevel[1].first / skillLevel[1].second) * (skillsDef.skills["engines"].requirement * 2);
        skillLevel[2].first = ((float)skillLevel[2].first / skillLevel[2].second) * (skillsDef.skills["shields"].requirement * 2);
        skillLevel[3].first = ((float)skillLevel[3].first / skillLevel[3].second) * (skillsDef.skills["weapons"].requirement * 2);
        skillLevel[4].first = ((float)skillLevel[4].first / skillLevel[4].second) * (skillsDef.skills["repair"].requirement * 2);
        skillLevel[5].first = ((float)skillLevel[5].first / skillLevel[5].second) * (skillsDef.skills["combat"].requirement * 2);

        skillLevel[0].second = skillsDef.skills["piloting"].requirement * 2;
        skillLevel[1].second = skillsDef.skills["engines"].requirement * 2;
        skillLevel[2].second = skillsDef.skills["shields"].requirement * 2;
        skillLevel[3].second = skillsDef.skills["weapons"].requirement * 2;
        skillLevel[4].second = skillsDef.skills["repair"].requirement * 2;
        skillLevel[5].second = skillsDef.skills["combat"].requirement * 2;
    }
}

HOOK_METHOD_PRIORITY(CrewMember, UpdateHealth, 2000, () -> void)
{
    if (G_->GetCApp()->menu.shipBuilder.bOpen) return;

    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (iOnFire && CanBurn())
    {
        float fireMultiplier = 1.f;

        if (custom->IsRace(species))
        {
            fireMultiplier = custom->GetDefinition(species).fireDamageMultiplier;
        }

        DirectModifyHealth(G_->GetCFPS()->GetSpeedFactor() * -0.133f * fireMultiplier);
    }

    if (bSuffocating && !IsAnaerobic())
    {
        float mod = 1.f;

        ShipObject* shipObject = GetShipObject();

        ShipInfo* shipInfo = G_->GetShipInfo(iShipId);

        if (shipObject->HasAugmentation("O2_MASKS"))
        {
            mod = shipObject->GetAugmentationValue("O2_MASKS");
        }

        float multiplier = GetSuffocationMultiplier();

        DirectModifyHealth(G_->GetCFPS()->GetSpeedFactor() * -0.4f * mod * multiplier);
    }

    float mod = 1.f;
    if (IsDrone())
    {
        mod = 0.2f;
    }

    DirectModifyHealth(G_->GetCFPS()->GetSpeedFactor() * fMedbay * mod * 0.4f);
    CrewMember_Extend* ex = CM_EX(this);
    if (ex->isHealing)
    {
        if (custom->IsRace(species) && ex->passiveHealTimer)
        {
            DirectModifyHealth(G_->GetCFPS()->GetSpeedFactor() * custom->GetDefinition(species).passiveHealAmount * 0.4f);
        }
    }
    //super();
}
HOOK_METHOD_PRIORITY(CrewMember, DirectModifyHealth, 1000, (float health) -> void)
{
    auto custom = CustomCrewManager::GetInstance();

    if (custom->IsRace(species) && CM_EX(this)->temporaryPowerActive && custom->GetDefinition(species).powerDef.tempPower.invulnerable)
    {
        if (health < 0.f)
        {
            return;
        }
    }


    super(health);
    if (health < 0.f)
    {
        CrewMember_Extend* ex = CM_EX(this);
        ex->isHealing = false;
        CustomCrewManager *custom = CustomCrewManager::GetInstance();

        if (custom->IsRace(species) && ex->passiveHealTimer)
        {
            ex->passiveHealTimer->Start(custom->GetDefinition(species).passiveHealDelay);
        }
    }
}
HOOK_METHOD_PRIORITY(CrewMember, OnLoop, 1000, () -> void)
{
    super();


    auto custom = CustomCrewManager::GetInstance();
    CrewMember_Extend* ex = CM_EX(this);
    auto def = custom->GetDefinition(species);
    if (custom->IsRace(species))
    {
        if (ex->passiveHealTimer)
        {
            ex->passiveHealTimer->Update();
            if (ex->passiveHealTimer->Done())
            {
                ex->isHealing = true;
            }
        }

        if (ex->hasSpecialPower && !G_->GetCApp()->menu.shipBuilder.bOpen)
        {
            if (ex->temporaryPowerActive)
            {
                ex->temporaryPowerDuration.first = std::max(0.f, ex->temporaryPowerDuration.first - (float)(G_->GetCFPS()->GetSpeedFactor() * 0.0625));

                if (ex->temporaryPowerDuration.first <= 0.f)
                {
                    ex->TemporaryPowerFinished();
                }
            }
            else
            {
                ex->powerCooldown.first = std::min(ex->powerCooldown.second, (float)(G_->GetCFPS()->GetSpeedFactor() * 0.0625) + ex->powerCooldown.first);
            }
        }

        auto aex = CMA_EX(crewAnim);
        if (aex->effectAnim != NULL)
        {
            aex->effectAnim->Update();
        }
        if (aex->tempEffectAnim != NULL)
        {
            aex->tempEffectAnim->Update();
        }
    }
}

HOOK_METHOD(CrewMember, SaveState, (int file) -> void)
{
    auto ex = CM_EX(this);

    FileHelper::writeFloat(file, ex->powerCooldown.first);
    FileHelper::writeFloat(file, ex->powerCooldown.second);
    FileHelper::writeFloat(file, ex->temporaryPowerDuration.first);
    FileHelper::writeFloat(file, ex->temporaryPowerDuration.second);
    FileHelper::writeInt(file, ex->temporaryPowerActive);

    super(file);

}

HOOK_METHOD(CrewMember, LoadState, (int file) -> void)
{
    auto ex = CM_EX(this);

    ex->powerCooldown.first = FileHelper::readFloat(file);
    ex->powerCooldown.second = FileHelper::readFloat(file);
    ex->temporaryPowerDuration.first = FileHelper::readFloat(file);
    ex->temporaryPowerDuration.second = FileHelper::readFloat(file);
    ex->temporaryPowerActive = FileHelper::readInteger(file);

    if (ex->temporaryPowerActive && ex->hasTempEffectAnim)
    {
        auto aex = CMA_EX(crewAnim);
        aex->tempEffectAnim->SetCurrentFrame(0);
        aex->tempEffectAnim->tracker.SetLoop(true, 0);
        aex->tempEffectAnim->Start(true);
    }

    super(file);
}

HOOK_METHOD_PRIORITY(CrewMember, GetNewGoal, 2000, () -> bool)
{
    auto ex = CM_EX(this);

    if (last_door && !ex->canPhaseThroughDoors)
    {
        last_door->FakeClose();
    }


    last_door = 0;

    bool result = false;


    if (path.distance != -1.f)
    {
        Point pos = Point(std::floor(x), std::floor(y));

        int roomId = iRoomId;
        ShipGraph* shipGraph = ShipGraph::GetShipInfo(currentShipId);
        Point intoRoom = shipGraph->GetIntoRoom(roomId, pos);

        if (path.doors.size() > 0)
        {
            Door* door = path.doors.front();

            Point doorPos = door->GetCenterPoint();
            Point entryWay = door->GetEntryWay(iRoomId);

            Point gridPos = ShipGraph::TranslateToGrid(pos.x, pos.y);
            Point entryPos = ShipGraph::TranslateToGrid(entryWay.x, entryWay.y);

            if (entryPos.x != gridPos.x || entryPos.y != gridPos.y)
            {
                if (intoRoom.x == -1 || intoRoom.y == -1)
                {
                    goal_x = entryWay.x;
                    goal_y = entryWay.y;
                }
                else
                {
                    goal_x = intoRoom.x;
                    goal_y = intoRoom.y;
                }
                return true;
            }

            if (door->IsSealed(iShipId) && (!bMindControlled || door->lockedDown.running) && !ex->canPhaseThroughDoors)
            {
                bool up = false;
                bool right = false;
                bool down = false;
                bool left = false;

                if (blockingDoor)
                {
                    blockingDoor = door;
                    SetCurrentTarget(door, false);
                    return true;
                }
                else
                {
                    if (doorPos.y > entryWay.y)
                    {
                        down = true;
                    }
                    else if (doorPos.y < entryWay.y)
                    {
                        up = true;
                    }

                    if (doorPos.x > entryWay.x)
                    {
                        right = true;
                    }
                    else if (doorPos.x < entryWay.x)
                    {
                        left = true;
                    }

                    int offset = (G_->GetRNG() ? rand() : random32()) % 17;
                    if (door->bVertical)
                    {
                        if (left)
                        {
                            goal_x = doorPos.x + 8;
                        }
                        else
                        {
                            goal_x = doorPos.x - 8;
                        }

                        goal_y = offset + (doorPos.y - 8);

                    }
                    else
                    {
                        if (up)
                        {
                            goal_y = doorPos.y + 8;
                        }
                        else
                        {
                            goal_y = doorPos.y - 8;
                        }

                        goal_x = offset + (doorPos.x - 8);
                    }

                    blockingDoor = door;
                    SetCurrentTarget(door, false);
                    return true;
                }
            }

            if (door->bVertical)
            {
                if (std::abs(pos.y - entryWay.y) > 0.05)
                {
                    goal_x = x;
                    goal_y = entryWay.y;
                    return true;
                }
                if (doorPos.x < entryWay.x)
                {
                    goal_x = entryWay.x - 35;
                    goal_y = y;
                }
                if (doorPos.x > entryWay.x)
                {
                    goal_x = entryWay.x + 34;
                    goal_y = y;
                }
                path.doors.erase(path.doors.begin());
            }
            else
            {
                if (std::abs(pos.x - entryWay.x) > 0.05)
                {
                    goal_y = y;
                    goal_x = entryWay.x;
                    return true;
                }
                if (doorPos.y < entryWay.y)
                {
                    goal_y = entryWay.y - 35;
                    goal_x = x;
                }
                if (doorPos.y > entryWay.y)
                {
                    goal_y = entryWay.y + 34;
                    goal_x = x;
                }



                path.doors.erase(path.doors.begin());

            }

            if (!door->bOpen && !door->forcedOpen.running)
            {
                if (!ex->canPhaseThroughDoors)
                {
                    last_door = door;
                    door->FakeOpen();
                }
                else
                {
                    G_->GetSoundControl()->PlaySoundMix("phase", -1.f, false);
                }
            }


            return true;
        }
        else
        {
            if (intoRoom.x != -1 && intoRoom.y != -1)
            {
                goal_x = intoRoom.x;
                goal_y = intoRoom.y;

                return true;
            }
            else
            {
                Point finish = path.finish;
                goal_x = finish.x;
                goal_y = finish.y;

                if ( std::abs(path.finish.x - x) > 0.5 )
                {
                    return true;
                }

                x = path.finish.x;

                if ( std::abs(path.finish.y - y) > 0.5 )
                {
                    return true;
                }

                y = path.finish.y;

                path.distance = -1.f;
            }
        }
    }

    return result;
}



HOOK_METHOD(CrewMemberFactory, CreateCrewMember, (CrewBlueprint* bp, int shipId, bool intruder) -> CrewMember*)
{
    auto custom = CustomCrewManager::GetInstance();
    CrewMember *newCrew = custom->CreateCrewMember(bp, shipId, shipId == 1);

    if (newCrew)
    {
        crewMembers.push_back(newCrew);
        OnLoop();
        return newCrew;
    }

    return super(bp, shipId, intruder);
}


HOOK_STATIC(CrewMemberFactory, IsRace, (std::string& race) -> bool)
{
    auto custom = CustomCrewManager::GetInstance();

    if (custom->IsRace(race))
        return true;
    return super(race);
}

HOOK_METHOD(CrewMember, constructor, (CrewBlueprint& blueprint, int shipId, bool intruder, CrewAnimation *animation) -> void)
{
	super(blueprint, shipId, intruder, animation);

    auto custom = CustomCrewManager::GetInstance();
    if (custom->IsRace(species))
    {
        CrewMember_Extend* ex = CM_EX(this);
        ex->canPhaseThroughDoors = custom->GetDefinition(species).canPhaseThroughDoors;
    }
}

HOOK_STATIC(CrewAnimation, GetDeathSound, (std::string& strRef, CrewAnimation *anim) -> std::string&)
{
    auto custom = CustomCrewManager::GetInstance();

    std::string& ret = super(strRef, anim);

    if (custom->IsRace(anim->race))
    {
        auto def = custom->GetDefinition(anim->race);

        if (def.deathSounds.size() > 0)
        {
            int rng = 0;
            if (G_->GetRNG())
            {
                rng = rand();
            }
            else
            {
                rng = random32();
            }

            strRef.assign(def.deathSounds[rng % def.deathSounds.size()]);

            return strRef;
        }
    }

    return ret;
}

HOOK_STATIC(CrewAnimation, GetShootingSound, (std::string& strRef, CrewAnimation *anim) -> std::string&)
{
    auto custom = CustomCrewManager::GetInstance();

    std::string& ret = super(strRef, anim);

    if (custom->IsRace(anim->race))
    {
        auto def = custom->GetDefinition(anim->race);

        if (def.shootingSounds.size() > 0)
        {
            int rng = 0;
            if (G_->GetRNG())
            {
                rng = rand();
            }
            else
            {
                rng = random32();
            }

            strRef.assign(def.shootingSounds[rng % def.shootingSounds.size()]);

            return strRef;
        }
    }

    return ret;
}

HOOK_METHOD(OxygenSystem, EmptyOxygen, (int roomId) -> void)
{
    if (!G_->GetCApp()->menu.shipBuilder.bOpen)
        return;

    return super(roomId);
}

HOOK_METHOD(ShipManager, UpdateEnvironment, () -> void)
{
    if (!G_->GetCApp()->menu.shipBuilder.bOpen && systemKey[2] != -1)
    {
        for (auto const &x: vCrewList)
        {
            auto custom = CustomCrewManager::GetInstance();

            if (custom->IsRace(x->species))
            {
                float oxygenModifier = custom->GetDefinition(x->species).oxygenChangeSpeed;
                if (oxygenModifier != 0.f && !x->bDead)
                {
                    if (oxygenSystem->oxygenLevels[x->iRoomId] == 0.f)
                    {
                        oxygenSystem->oxygenLevels[x->iRoomId] = 0.0000001f;
                    }

                    oxygenSystem->ComputeAirLoss(x->iRoomId, -oxygenModifier, true);
                }
            }
        }
    }
    super();
}


HOOK_METHOD(CrewMember, ApplyDamage, (float damage) -> bool)
{
    auto custom = CustomCrewManager::GetInstance();

    if (custom->IsRace(species))
    {
        damage *= custom->GetDefinition(species).damageTakenMultiplier;
    }

    return super(damage);
}


static bool crewDetectLifeforms = false;

HOOK_METHOD(ShipManager, OnRender, (bool unk1, bool unk2) -> void)
{
    crewDetectLifeforms = true;
    super(unk1, unk2);
    crewDetectLifeforms = false;
}

HOOK_METHOD(CombatControl, CanTargetSelf, () -> bool)
{
    crewDetectLifeforms = true;
    bool ret = super();
    crewDetectLifeforms = false;

    return ret;
}

HOOK_METHOD(CombatControl, UpdateTarget, () -> bool)
{
    crewDetectLifeforms = true;
    return super();
    crewDetectLifeforms = false;
}

HOOK_METHOD(ShipObject, HasEquipment, (const std::string& name) -> int)
{
    if (name == "slug" && crewDetectLifeforms)
    {
        int ret = super(name);

        if (ret == 0)
        {
            auto custom = CustomCrewManager::GetInstance();

            ShipManager *currentShip;
            if (iShipId == 0)
            {
                currentShip = G_->GetWorld()->playerShip->shipManager;
            }
            else
            {
                currentShip = G_->GetWorld()->playerShip->shipManager->current_target;
            }


            for (auto i : currentShip->vCrewList)
            {
                if (custom->IsRace(i->species))
                {
                    if (custom->GetDefinition(i->species).detectsLifeforms && !i->intruder)
                    {
                        return 1;
                    }
                }
            }
        }

        return ret;
    }

    return super(name);
}


/*
HOOK_METHOD(ShipManager, OnLoop, () -> void)
{
    for (auto i : vCrewList)
    {
        CrewMember_Extend* ex = CM_EX(i);

        if (ex->lastShipId == -1)
        {
            ex->lastShipId = iShipId;
        }

        if ((ex->lastRoom != i->iRoomId || ex->lastShipId != i->iShipId) && ex->lastShipId == iShipId)
        {


            ShipSystem* sys = GetSystemInRoom(i->iRoomId);
            ShipSystem* lastSys = GetSystemInRoom(ex->lastRoom);


            if (lastSys && lastSys != sys)
            {
                ShipSystem_Extend* sys_ex = SYS_EX(lastSys);

                printf("Cleared power loss for: %s\n", lastSys->name.c_str());

                lastSys->SetPowerLoss(0);
            }
            if (sys)
            {
                ShipSystem_Extend* sys_ex = SYS_EX(sys);

                sys->SetPowerLoss(1);

                printf("Set power loss for: %s\n", sys->name.c_str());
            }

            ex->lastRoom = i->iRoomId;
            ex->lastShipId = i->iShipId;
        }
    }



    super();
}
*/

HOOK_METHOD(CrewMember, OnLoop, () -> void)
{
    super();

    auto custom = CustomCrewManager::GetInstance();

    if (custom->IsRace(species))
    {
        auto ex = CM_EX(this);

        if (custom->GetDefinition(species).hasDeathExplosion)
        {
            if (crewAnim->status == 3)
            {
                if (!ex->exploded && !ex->triggerExplosion)
                {
                    ex->triggerExplosion = true;
                }
            }
            else if (!bDead)
            {
                ex->triggerExplosion = false;
                ex->exploded = false;
            }
        }
    }
}

static bool shipFriendlyFire = false;
static bool blockDamageArea = false;

HOOK_STATIC(CrewMember, GetRoomDamage, (Damage *damage, CrewMember *crew) -> Damage*)
{
    Damage *ret = super(damage, crew);

    auto custom = CustomCrewManager::GetInstance();
    if (custom->IsRace(crew->species) && !blockDamageArea)
    {
        if (custom->GetDefinition(crew->species).hasDeathExplosion)
        {
            auto ex = CM_EX(crew);

            if (ex->triggerExplosion && !ex->exploded)
            {
                Damage *customDamage = &custom->GetDefinition(crew->species).explosionDef;

                damage->iDamage = customDamage->iDamage;
                damage->fireChance = customDamage->fireChance;
                damage->breachChance = customDamage->breachChance;
                damage->stunChance = customDamage->stunChance;
                damage->iIonDamage = customDamage->iIonDamage;
                damage->iSystemDamage = customDamage->iSystemDamage;
                damage->iPersDamage = customDamage->iPersDamage;
                damage->bHullBuster = customDamage->bHullBuster;
                damage->ownerId = crew->iShipId;
                damage->bLockdown = customDamage->bLockdown;
                damage->crystalShard = customDamage->crystalShard;
                damage->bFriendlyFire = customDamage->bFriendlyFire;
                damage->iStun = customDamage->iStun;
                shipFriendlyFire = custom->GetDefinition(crew->species).explosionShipFriendlyFire;

                ret = damage;

                ex->exploded = true;
            }
        }

        if (custom->GetDefinition(crew->species).powerDef.hasSpecialPower)
        {
            auto ex = CM_EX(crew);

            if (ex->powerActivated)
            {

                Damage *customDamage = &custom->GetDefinition(crew->species).powerDef.damage;

                damage->iDamage = customDamage->iDamage;
                damage->fireChance = customDamage->fireChance;
                damage->breachChance = customDamage->breachChance;
                damage->stunChance = customDamage->stunChance;
                damage->iIonDamage = customDamage->iIonDamage;
                damage->iSystemDamage = customDamage->iSystemDamage;
                damage->iPersDamage = customDamage->iPersDamage;
                damage->bHullBuster = customDamage->bHullBuster;
                damage->ownerId = crew->iShipId;
                damage->bLockdown = false;
                damage->crystalShard = customDamage->crystalShard;
                damage->bFriendlyFire = customDamage->bFriendlyFire;
                damage->iStun = customDamage->iStun;
                shipFriendlyFire = custom->GetDefinition(crew->species).powerDef.shipFriendlyFire;


                ret = damage;

                ex->powerActivated = false;
            }
        }
    }

    return ret;
}

HOOK_METHOD(ShipManager, UpdateCrewMembers, () -> void)
{
    blockDamageArea = true;
    super();
    blockDamageArea = false;

    for (auto i : vCrewList)
    {
        Damage* dmg = new Damage();

        CrewMember::GetRoomDamage(dmg, i);

        DamageArea(Pointf(i->x, i->y), dmg->iDamage, dmg->iShieldPiercing, dmg->fireChance, dmg->breachChance, dmg->stunChance, dmg->iIonDamage, dmg->iSystemDamage, dmg->iPersDamage, dmg->bHullBuster, dmg->ownerId, dmg->selfId, dmg->bLockdown, dmg->iStun, true);
    }
}

HOOK_METHOD(ShipManager, DamageCrew, (CrewMember *crew, int iDamage, int iShieldPiercing, int fireChance, int breachChance, int stunChance, int iIonDamage, int iSystemDamage, int iPersDamage, int bHullBuster, int ownerId, int selfId, int bLockdown, int iStun) -> char)
{
    Damage* dmg = (Damage*)&iDamage;

    return super(crew, iDamage, iShieldPiercing, fireChance, breachChance, stunChance, iIonDamage, iSystemDamage, iPersDamage, bHullBuster, ownerId, selfId, bLockdown, iStun);
}

HOOK_METHOD(ShipManager, DamageArea, (Pointf location,  int iDamage, int iShieldPiercing, int fireChance, int breachChance, int stunChance, int iIonDamage, int iSystemDamage, int iPersDamage, char bHullBuster, int ownerId, int selfId, int bLockdown, int iStun, bool forceHit) -> bool)
{
    if (blockDamageArea) return false;
    Damage* dmg = (Damage*)&iDamage;

    if (ownerId == iShipId && !shipFriendlyFire)
    {
        shipFriendlyFire = false;
        int roomId = ship.GetSelectedRoomId(location.x, location.y, true);

        if (roomId == -1)
            return false;

        if (!bJumping)
        {
            for (auto i : vCrewList)
            {
                if (i->iRoomId == roomId)
                {
                    DamageCrew(i, iDamage, iShieldPiercing, fireChance, breachChance, stunChance, iIonDamage, iSystemDamage, iPersDamage, bHullBuster, ownerId, selfId, bLockdown, iStun);
                }
            }
        }

        return true;
    }

    return super(location, iDamage, iShieldPiercing, fireChance, breachChance, stunChance, iIonDamage, iSystemDamage, iPersDamage, bHullBuster, ownerId, selfId, bLockdown, iStun, forceHit);
}

HOOK_METHOD(CrewBox, constructor, (Point pos, CrewMember *crew, int number) -> void)
{
    super(pos, crew, number);

    auto custom = CustomCrewManager::GetInstance();
    if (custom->IsRace(crew->species))
    {
        auto crewDef = custom->GetDefinition(crew->species);

        if (crewDef.powerDef.hasSpecialPower)
        {
            if (!crewDef.powerDef.buttonLabel.data.empty())
            {
                powerButton.label = crewDef.powerDef.buttonLabel;
            }
        }
    }
}

HOOK_METHOD_PRIORITY(CrewBox, OnRender, 1000, () -> void)
{
    //return super();
    mindControlled.Update();
    stunned.Update();

    auto crew = pCrew;
    auto health = crew->health;
    if (health.first > 25.f || health.first == 0.f)
    {
        flashHealthTracker.Stop(false);
    }

    GL_Color boxColor = GL_Color();
    if (!crew->bMindControlled)
    {
        auto selectionState = crew->selectionState;
        if (selectionState == 2)
        {
            boxColor.r = 0.921f;
            boxColor.g = 0.921f;
            boxColor.b = 0.921f;
        }
        else if (selectionState == 1)
        {
            boxColor.r = 0.47f;
            boxColor.g = 1.f;
            boxColor.b = 0.47f;
        }
        else if (flashHealthTracker.running && flashHealthTracker.Progress(-1.f) < 0.5f)
        {
            boxColor.r = 1.f;
            boxColor.g = 0.392f;
            boxColor.b = 0.392f;
        }
        else
        {
            boxColor.r = 0.392f;
            boxColor.g = 0.392f;
            boxColor.b = 0.392f;
        }

        if (crew->fStunTime > 0.f && crew->selectionState != 1)
        {
            boxColor.r = 1.f;
            boxColor.g = 1.f;
            boxColor.b = 0.392f;
        }
    }
    else
    {
        boxColor.r = 1.f;
        boxColor.g = 0.f;
        boxColor.b = 1.f;
    }


    if (!bSelectable)
    {
        boxColor.r = 0.494f;
        boxColor.g = 0.858f;
        boxColor.b = 0.882f;
    }


    boxColor.a = 0.25f;

    if (!mouseHover)
    {
        CSurface::GL_RenderPrimitiveWithColor(boxBackground, boxColor);
        boxColor.a = 1.f;
        CSurface::GL_RenderPrimitiveWithColor(boxOutline, boxColor);
    }
    else
    {
        CSurface::GL_RenderPrimitiveWithColor(skillBoxBackground, boxColor);
        boxColor.a = 1.f;
        CSurface::GL_RenderPrimitiveWithColor(skillBoxOutline, boxColor);
    }

    if (crew->HasSpecialPower())
    {
        auto ex = CM_EX(crew);

        std::pair<float, float> cooldown;

        if (ex->temporaryPowerActive)
        {
            cooldown = ex->temporaryPowerDuration;
        }
        else
        {
            cooldown = crew->GetPowerCooldown();
        }

        int cooldownHeight = std::floor((cooldown.first / cooldown.second) * (box.h - 6));

        GL_Primitive* prim = NULL;

        if (cooldownHeight == lastCooldownHeight && cooldownBar)
        {
            prim = cooldownBar;
        }
        else
        {
            CSurface::GL_DestroyPrimitive(cooldownBar);
            lastCooldownHeight = cooldownHeight;

            if (cooldownHeight <= 0)
            {
                cooldownBar = NULL;
            }
            else
            {
                GL_Color barColor = GL_Color(133.f / 255.f, 231.f / 255.f, 237.f / 255.f, 1.f);

                if (CustomCrewManager::GetInstance()->IsRace(crew->species))
                {
                    auto powerDef = CustomCrewManager::GetInstance()->GetDefinition(crew->species).powerDef;

                    if (ex->temporaryPowerActive)
                    {
                        barColor = powerDef.tempPower.cooldownColor;
                    }
                    else
                    {
                        barColor = powerDef.cooldownColor;
                    }
                }

                prim = CSurface::GL_CreateRectPrimitive(box.x - 1, (box.h - cooldownHeight) + box.y - 3, 4, cooldownHeight, barColor);

                cooldownBar = prim;
            }
        }

        if (prim)
        {
            CSurface::GL_RenderPrimitive(prim);
        }
    }

    int healthMaxWidth = box.w - 37;
    int healthWidth = std::floor((health.first / health.second) * healthMaxWidth);

    if (health.first != 0 && healthWidth == 0)
    {
        healthWidth = 1;
    }



    if (healthWidth == lastHealthWidth)
    {
        CSurface::GL_RenderPrimitive(healthBar);
    }
    else
    {
        lastHealthWidth = healthWidth;
        GL_Primitive *prim = NULL;
        if (health.first <= 0)
        {
            healthBar = NULL;
        }
        else
        {
            CSurface::GL_DestroyPrimitive(healthBar);

            GL_Color healthColor = GL_Color(0.f, 1.f, 0.f, 1.f);



            if (health.first < health.second)
            {
                if (healthWidth < healthMaxWidth / 2)
                {
                    healthColor.g = ((float)healthWidth) / ((float)healthMaxWidth / 2);
                }
                else
                {
                    healthColor.g = 1.f;
                }

                healthColor.r = 1.f;
            }

            if (healthColor.g >= 1.f)
            {
                healthColor.g = 1.f;
            }




            prim = CSurface::GL_CreateRectPrimitive(box.x + 33, box.y + box.h - 8, healthWidth, 4, healthColor);
            healthBar = prim;
        }

        if (prim)
        {
            CSurface::GL_RenderPrimitive(prim);
        }
    }

    if (mouseHover)
    {
        int skillOffset = 0;

        if (crew->HasSpecialPower())
        {
            powerButton.OnRender();
            skillOffset = 24;
        }

        int skillNumber = 0;

        for (auto i : crew->blueprint.skillLevel)
        {
            crew->blueprint.RenderSkill(box.x + box.w + 7, (box.y + skillOffset) + 24 * skillNumber, 40, 8, skillNumber);

            skillNumber++;
        }

        if (!sTooltip.empty())
        {
            Point tooltipPosition = Point(box.x + box.w + 95, box.y);
            auto mouse = G_->GetMouseControl();


            mouse->SetTooltip(sTooltip);
            mouse->QueueStaticTooltip(tooltipPosition);
            mouse->InstantTooltip();
        }
    }
}

HOOK_METHOD(CrewBox, GetSelected, (int mouseX, int mouseY) -> CrewMember*)
{
    auto ret = super(mouseX, mouseY);

    if (CustomCrewManager::GetInstance()->IsRace(pCrew->species))
    {
        auto def = CustomCrewManager::GetInstance()->GetDefinition(pCrew->species);
        if (pCrew->HasSpecialPower() && mouseX < powerButton.hitbox.x + powerButton.hitbox.w && mouseX > powerButton.hitbox.x && mouseY < powerButton.hitbox.y + powerButton.hitbox.h && mouseY > powerButton.hitbox.y)
        {
            std::string tooltip = "";
            if (pCrew->PowerReady())
            {
                if (!def.powerDef.tooltip.data.empty())
                {
                    tooltip = def.powerDef.tooltip.GetText();

                    if (!tooltip.empty())
                    {
                        std::string toReplace("\\1");
                        std::string replaceWith;

                        Settings::GetHotkeyName(replaceWith, "lockdown");

                        tooltip.replace(tooltip.find(toReplace), toReplace.length(), replaceWith);
                    }
                }
            }
            else
            {
                auto ex = CM_EX(pCrew);
                auto state = ex->PowerReady();

                std::string tooltipName = "";

                switch (state)
                {
                case POWER_NOT_READY_PLAYER_SHIP:
                    tooltipName = "power_not_ready_player_ship";
                    break;
                case POWER_NOT_READY_ENEMY_SHIP:
                    tooltipName = "power_not_ready_enemy_ship";
                    break;
                case POWER_NOT_READY_ENEMY_IN_ROOM:
                    tooltipName = "power_not_ready_enemy_in_room";
                    break;
                case POWER_NOT_READY_FRIENDLY_IN_ROOM:
                    tooltipName = "power_not_ready_friendly_in_room";
                    break;
                case POWER_NOT_READY_SYSTEM_IN_ROOM:
                    tooltipName = "power_not_ready_system_in_room";
                    break;
                case POWER_NOT_READY_ACTIVATED:
                    tooltipName = "power_not_ready_activated";
                    break;
                }

                if (!tooltipName.empty())
                {
                    tooltip = G_->GetTextLibrary()->GetText(tooltipName);
                }
            }

            if (!tooltip.empty())
            {
                sTooltip = tooltip;
            }
        }
    }

    return ret;
}


HOOK_METHOD(CrewMember, OnRender, (bool outlineOnly) -> void)
{
    super(outlineOnly);

    if (outlineOnly)
    {
        return;
    }


    auto ex = CMA_EX(crewAnim);

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(x, y);

    if (ex->effectAnim != NULL && !ex->effectAnim->tracker.done)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(-std::ceil((float)ex->effectAnim->info.frameWidth / 2), -std::ceil((float)ex->effectAnim->info.frameHeight / 2));
        ex->effectAnim->OnRender(1.f, COLOR_WHITE, false);
        CSurface::GL_PopMatrix();
    }

    if (ex->tempEffectAnim != NULL && !ex->tempEffectAnim->tracker.done && ex->tempEffectAnim->tracker.running)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(-std::ceil((float)ex->tempEffectAnim->info.frameWidth / 2), -std::ceil((float)ex->tempEffectAnim->info.frameHeight / 2));
        ex->tempEffectAnim->OnRender(1.f, COLOR_WHITE, false);
        CSurface::GL_PopMatrix();
    }

    CSurface::GL_PopMatrix();
}

static bool blockSetBonusPower = false;

HOOK_METHOD(ShipSystem, SetBonusPower, (int amount, int permanentPower) -> void)
{
    if (blockSetBonusPower) return;

    super(amount, permanentPower);
}

HOOK_METHOD(WeaponSystem, SetBonusPower, (int amount, int permanentPower) -> void)
{
    if (blockSetBonusPower) return;

    super(amount, permanentPower);
}

HOOK_METHOD(DroneSystem, SetBonusPower, (int amount, int permanentPower) -> void)
{
    if (blockSetBonusPower) return;

    super(amount, permanentPower);
}



HOOK_METHOD(ShipManager, OnLoop, () -> void)
{
    auto custom = CustomCrewManager::GetInstance();

    for (auto i : vSystemList)
    {
        int bonusPowerCounter = 0;
        int permanentPowerCounter = 0;

        for (auto j : vCrewList)
        {
            if (i->roomId == j->iRoomId)
            {
                if (custom->IsRace(j->species))
                {
                    auto def = custom->GetDefinition(j->species);

                    if (CM_EX(j)->temporaryPowerActive && def.powerDef.tempPower.bonusPower > 0)
                    {
                        bonusPowerCounter += def.powerDef.tempPower.bonusPower;

                        if (j->AtFinalGoal())
                        {
                            permanentPowerCounter += def.powerDef.tempPower.bonusPower;
                        }
                    }

                    bonusPowerCounter += def.bonusPower;

                    if (j->AtFinalGoal())
                    {
                        permanentPowerCounter += def.bonusPower;
                    }
                }

                if (j->ProvidesPower())
                {
                    bonusPowerCounter++;
                    if (j->AtFinalGoal())
                    {
                        permanentPowerCounter++;
                    }
                }
            }
        }

        i->SetBonusPower(bonusPowerCounter, permanentPowerCounter);
    }

    blockSetBonusPower = true;
    super();
    blockSetBonusPower = false;
}

