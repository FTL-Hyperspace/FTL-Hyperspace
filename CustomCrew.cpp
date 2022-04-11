#include "CrewMember_Extend.h"
#include "CustomCrew.h"
#include "CustomOptions.h"
#include "Resources.h"
#include "TemporalSystem.h"
#include "CustomDamage.h"
#include "ShipUnlocks.h"
#include "CustomEvents.h"

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>

TransformColorMode g_transformColorMode = TransformColorMode::KEEP_INDICES;
bool g_resistsMindControlStat = false;

static const std::string CREW_SKILLS[6] =
{
    "piloting",
    "engines",
    "shields",
    "weapons",
    "repair",
    "combat"
};

bool g_advancedCrewTooltips = true;
bool g_showEnemyPowers = true;
bool g_showAllyPowers = false;
int g_advancedCrewTooltipRounding = 2;

std::vector<ActivatedPowerDefinition> ActivatedPowerDefinition::powerDefs = std::vector<ActivatedPowerDefinition>();
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
                crew.repairSounds = std::vector<std::string>();

                crew.repairSounds.push_back("repair");

                crew.skillsDef = SkillsDefinition();
                crew.explosionDef = ExplosionDefinition();

                crew.explosionDef.damage.iDamage = 0;
                crew.explosionDef.damage.iShieldPiercing = 0;
                crew.explosionDef.damage.fireChance = 0;
                crew.explosionDef.damage.breachChance = 0;
                crew.explosionDef.damage.stunChance = 0;
                crew.explosionDef.damage.iIonDamage = 0;
                crew.explosionDef.damage.iSystemDamage = 0;
                crew.explosionDef.damage.iPersDamage = 0;
                crew.explosionDef.damage.bHullBuster = false;
                crew.explosionDef.damage.ownerId = -1;
                crew.explosionDef.damage.selfId = -1;
                crew.explosionDef.damage.bLockdown = false;
                crew.explosionDef.damage.crystalShard = false;
                crew.explosionDef.damage.bFriendlyFire = false;
                crew.explosionDef.damage.iStun = 0;
                crew.explosionDef.shipFriendlyFire = false;

                if (child->first_attribute("drone"))
                {
                    std::string droneType = child->first_attribute("drone")->value();

                    crew.canBurn = false;
                    crew.canRepair = false;
                    crew.canSabotage = false;
                    crew.canSuffocate = false;
                    crew.controllable = false;
                    crew.canFight = false;
                    crew.canMan = false;
                    crew.canTeleport = false;
                    crew.moveSpeedMultiplier = 0.5f;

                    if (droneType == "BOARDER")
                    {
                        crew.canFight = true;
                        crew.canSabotage = true;
                        crew.damageMultiplier = 1.2f;
                        crew.maxHealth = 150;
                    }
                    if (droneType == "BATTLE")
                    {
                        crew.canFight = true;
                        crew.damageMultiplier = 1.2f;
                        crew.maxHealth = 150;
                    }
                    if (droneType == "BOARDER_ION")
                    {
                        crew.canSabotage = true;
                        crew.maxHealth = 125;
                    }
                    if (droneType == "REPAIR")
                    {
                        crew.canRepair = true;
                        crew.maxHealth = 25;
                        crew.repairSpeed = 2.f;
                        crew.animBase = "repair";
                    }
                }

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
                        if (str == "controllable")
                        {
                            crew.controllable = EventsParser::ParseBoolean(val);
                        }
                        if (str == "selectable")
                        {
                            crew.selectable = EventsParser::ParseBoolean(val);
                        }
                        if (str == "canRepair")
                        {
                            crew.canRepair = EventsParser::ParseBoolean(val);
                        }
                        if (str == "canSabotage")
                        {
                            crew.canSabotage = EventsParser::ParseBoolean(val);
                        }
                        if (str == "canMan")
                        {
                            crew.canMan = EventsParser::ParseBoolean(val);
                        }
                        if (str == "canTeleport")
                        {
                            crew.canTeleport = EventsParser::ParseBoolean(val);
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
                        if (str == "stunMultiplier")
                        {
                            crew.stunMultiplier = boost::lexical_cast<float>(val);
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
                        if (str == "rangedDamageMultiplier")
                        {
                            crew.rangedDamageMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "doorDamageMultiplier")
                        {
                            crew.doorDamageMultiplier = boost::lexical_cast<float>(val);
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
                        if (str == "resistsMindControl")
                        {
                            crew.resistsMindControl = EventsParser::ParseBoolean(val);
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
                        if (str == "healSpeed")
                        {
                            crew.healSpeed = boost::lexical_cast<float>(val);
                        }
                        if (str == "powerDrain")
                        {
                            crew.powerDrain = boost::lexical_cast<int>(val);
                        }
                        if (str == "powerDrainFriendly")
                        {
                            crew.powerDrainFriendly = EventsParser::ParseBoolean(val);
                        }
                        if (str == "deathSounds")
                        {
                            bool male = true;
                            bool female = true;
                            if (stat->first_attribute("male"))
                            {
                                if (EventsParser::ParseBoolean(stat->first_attribute("male")->value()))
                                {
                                    female = false;
                                }
                                else
                                {
                                    male = false;
                                }
                            }
                            if (stat->first_attribute("female"))
                            {
                                if (EventsParser::ParseBoolean(stat->first_attribute("female")->value()))
                                {
                                    male = false;
                                }
                                else
                                {
                                    female = false;
                                }
                            }
                            for (auto deathSoundNode = stat->first_node(); deathSoundNode; deathSoundNode = deathSoundNode->next_sibling())
                            {
                                if (strcmp(deathSoundNode->name(), "deathSound") == 0)
                                {
                                    if (male) crew.deathSounds.push_back(std::string(deathSoundNode->value()));
                                    if (female) crew.deathSoundsFemale.push_back(std::string(deathSoundNode->value()));
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
                        if (str == "repairSounds")
                        {
                            crew.repairSounds.clear();

                            for (auto repairSoundNode = stat->first_node(); repairSoundNode; repairSoundNode = repairSoundNode->next_sibling())
                            {
                                if (strcmp(repairSoundNode->name(), "repairSound") == 0)
                                {
                                    crew.repairSounds.push_back(std::string(repairSoundNode->value()));
                                }
                            }

                            if (stat->first_attribute("animSoundFrame"))
                            {
                                crew.repairSoundFrame = boost::lexical_cast<int>(stat->first_attribute("animSoundFrame")->value());
                            }
                        }
                        if (str == "passiveStatBoosts")
                        {
                            for (auto statBoostNode = stat->first_node(); statBoostNode; statBoostNode = statBoostNode->next_sibling())
                            {
                                crew.passiveStatBoosts.push_back(StatBoostManager::GetInstance()->ParseStatBoostNode(statBoostNode, StatBoostDefinition::BoostSource::CREW));
                            }
                        }
                        if (str == "animBase")
                        {
                            crew.animBase = val;
                        }
                        if (str == "animSheet")
                        {
                            crew.animSheet[0] = val;
                            crew.animSheet[1] = val;
                        }
                        if (str == "animSheetFemale")
                        {
                            crew.animSheet[0] = val;
                        }
                        if (str == "shootTimer")
                        {
                            if (!val.empty())
                            {
                                crew.shootTimer.first = boost::lexical_cast<int>(val);
                                crew.shootTimer.second = boost::lexical_cast<int>(val);
                            }
                            if (stat->first_attribute("min"))
                            {
                                crew.shootTimer.first = boost::lexical_cast<int>(stat->first_attribute("min")->value());
                                if (crew.shootTimer.second == -1) crew.shootTimer.second = boost::lexical_cast<int>(stat->first_attribute("min")->value());
                            }
                            if (stat->first_attribute("max"))
                            {
                                crew.shootTimer.second = boost::lexical_cast<int>(stat->first_attribute("max")->value());
                                if (crew.shootTimer.second == -1) crew.shootTimer.first = boost::lexical_cast<int>(stat->first_attribute("max")->value());
                            }
                        }
                        if (str == "punchTimer")
                        {
                            if (!val.empty())
                            {
                                crew.punchTimer.first = boost::lexical_cast<int>(val);
                                crew.punchTimer.second = boost::lexical_cast<int>(val);
                            }
                            if (stat->first_attribute("min"))
                            {
                                crew.punchTimer.first = boost::lexical_cast<int>(stat->first_attribute("min")->value());
                                if (crew.punchTimer.second == -1) crew.punchTimer.second = boost::lexical_cast<int>(stat->first_attribute("min")->value());
                            }
                            if (stat->first_attribute("max"))
                            {
                                crew.punchTimer.second = boost::lexical_cast<int>(stat->first_attribute("max")->value());
                                if (crew.punchTimer.second == -1) crew.punchTimer.first = boost::lexical_cast<int>(stat->first_attribute("max")->value());
                            }
                        }
                        if (str == "canPunch")
                        {
                            crew.canPunch = EventsParser::ParseBoolean(val);
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
                        if (str == "truePassiveHealAmount")
                        {
                            crew.truePassiveHealAmount = boost::lexical_cast<float>(val);
                        }
                        if (str == "healAmount")
                        {
                            crew.healAmount = boost::lexical_cast<float>(val);
                        }
                        if (str == "trueHealAmount")
                        {
                            crew.trueHealAmount = boost::lexical_cast<float>(val);
                        }
                        if (str == "passiveHealDelay")
                        {
                            crew.passiveHealDelay = boost::lexical_cast<int>(val);
                        }
                        if (str == "detectsLifeforms")
                        {
                            crew.detectsLifeforms = EventsParser::ParseBoolean(val);
                        }
                        if (str == "healCrewAmount")
                        {
                            crew.healCrewAmount = boost::lexical_cast<float>(val);
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
                        if (str == "sabotageSpeedMultiplier")
                        {
                            crew.sabotageSpeedMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "defaultSkillLevel")
                        {
                            crew.defaultSkillLevel = boost::lexical_cast<int>(val);
                        }
                        if (str == "cloneLoseSkills")
                        {
                            crew.cloneLoseSkills = EventsParser::ParseBoolean(val);
                        }
                        if (str == "allDamageTakenMultiplier")
                        {
                            crew.allDamageTakenMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "damageEnemiesAmount")
                        {
                            crew.damageEnemiesAmount = boost::lexical_cast<float>(val);
                        }
                        if (str == "hackDoors")
                        {
                            crew.hackDoors = EventsParser::ParseBoolean(val);
                        }
                        if (str == "powerRechargeMultiplier")
                        {
                            crew.powerRechargeMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "nameRace")
                        {
                            crew.nameRace.push_back(stat->value());
                            if (stat->first_attribute("transformName"))
                            {
                                crew.transformName.push_back(stat->first_attribute("transformName")->value());
                            }
                            if (stat->first_attribute("changeIfSame"))
                            {
                                crew.changeIfSame = EventsParser::ParseBoolean(stat->first_attribute("changeIfSame")->value());
                            }
                        }
                        if (str == "droneAI")
                        {
                            crew.droneAI.hasCustomAI = true;
                            for (auto effectNode = stat->first_node(); effectNode; effectNode = effectNode->next_sibling())
                            {
                                std::string effectName = std::string(effectNode->name());

                                if (effectName == "fightAI")
                                {
                                    crew.droneAI.fightAI = true;
                                }
                                if (effectName == "repairAI")
                                {
                                    crew.droneAI.repairAI = true;
                                }
                                if (effectName == "manAI")
                                {
                                    crew.droneAI.manAI = true;
                                }
                                if (effectName == "batteryAI")
                                {
                                    crew.droneAI.batteryAI = true;
                                }
                                if (effectName == "returnToDroneRoom")
                                {
                                    crew.droneAI.returnToDroneRoom = true;
                                }
                            }
                        }
                        if (str == "droneMoveFromManningSlot")
                        {
                            crew.droneMoveFromManningSlot = EventsParser::ParseBoolean(val);
                        }
                        if (str == "deathEffect")
                        {
                            crew.hasDeathExplosion = true;
                            ParseDeathEffect(stat, &crew.explosionDef);
                        }
                        if (str == "powerEffect")
                        {
                            ActivatedPowerDefinition powerDef;
                            ParseAbilityEffect(stat, &powerDef);
                            powerDef.AssignIndex();
                            crew.powerDefIdx = powerDef.index;
                        }
                        if (str == "noSlot")
                        {
                            crew.noSlot = EventsParser::ParseBoolean(val);
                        }
                        if (str == "noClone")
                        {
                            crew.noClone = EventsParser::ParseBoolean(val);
                        }
                        if (str == "noAI")
                        {
                            crew.noAI = EventsParser::ParseBoolean(val);
                        }
                        if (str == "validTarget")
                        {
                            crew.validTarget = EventsParser::ParseBoolean(val);
                        }
                        if (str == "essential")
                        {
                            crew.essential = boost::lexical_cast<float>(val);
                        }
                    }
                }
                catch (boost::bad_lexical_cast const &e)
                {
                    ErrorMessage(std::string("Error parsing <crew> in hyperspace.xml\n") + std::string(e.what()));
                }

                AddCrewDefinition(crew);
            }
        }
    }
    catch (rapidxml::parse_error& e)
    {
        ErrorMessage(std::string("Error parsing <crew> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (std::exception &e)
    {
        ErrorMessage(std::string("Error parsing <crew> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (const char* e)
    {
        ErrorMessage(std::string("Error parsing <crew> in hyperspace.xml\n") + std::string(e));
    }
    catch (...)
    {
        ErrorMessage("Error parsing <crew> in hyperspace.xml\n");
    }
}

void CustomCrewManager::ParseDeathEffect(rapidxml::xml_node<char>* stat, ExplosionDefinition* explosionDef)
{
    ExplosionDefinition def;
    if (explosionDef != nullptr)
    {
        def = *explosionDef;
    }
    for (auto effectNode = stat->first_node(); effectNode; effectNode = effectNode->next_sibling())
    {
        std::string effectName = std::string(effectNode->name());

        if (effectName == "damage")
        {
            def.damage.iDamage = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "fireChance")
        {
            def.damage.fireChance = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "breachChance")
        {
            def.damage.breachChance = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "ion")
        {
            def.damage.iIonDamage = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "sysDamage")
        {
            def.damage.iSystemDamage = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "persDamage")
        {
            def.damage.iPersDamage = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "hullBust")
        {
            def.damage.bHullBuster = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "lockdown")
        {
            def.damage.bLockdown = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "friendlyFire")
        {
            def.damage.bFriendlyFire = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "stun")
        {
            def.damage.iStun = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "shipFriendlyFire")
        {
            def.shipFriendlyFire = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "transformRace")
        {
            def.transformRace = effectNode->value();
            def.transformRaceHealth = 0.f;
            def.transformRaceHealthFraction = 1.f;
            def.transformRaceDeathSound = false;

            if (effectNode->first_attribute("health"))
            {
                def.transformRaceHealth = boost::lexical_cast<float>(effectNode->first_attribute("health")->value());
                def.transformRaceHealthFraction = 0.f;
            }
            if (effectNode->first_attribute("healthFraction"))
            {
                def.transformRaceHealthFraction = boost::lexical_cast<float>(effectNode->first_attribute("healthFraction")->value());
            }
            if (effectNode->first_attribute("deathSound"))
            {
                def.transformRaceDeathSound = EventsParser::ParseBoolean(effectNode->first_attribute("deathSound")->value());
            }
        }
        if (effectName == "spawnCrew")
        {
            CrewSpawn* newSpawn = CrewSpawn::ParseCrewSpawn(effectNode, true);

            if (!newSpawn->race.empty())
            {
                def.crewSpawns.push_back(newSpawn);
            }
            else
            {
                delete newSpawn;
            }
        }
        if (effectName == "statBoosts")
        {
            for (auto statBoostNode = effectNode->first_node(); statBoostNode; statBoostNode = statBoostNode->next_sibling())
            {
                if (strcmp(statBoostNode->name(), "statBoost") == 0)
                {
                    def.statBoosts.push_back(StatBoostManager::GetInstance()->ParseStatBoostNode(statBoostNode, StatBoostDefinition::BoostSource::CREW));
                }
            }
        }
        if (effectName == "event")
        {
            def.event[0] = G_->GetEventsParser()->ProcessEvent(effectNode, "__crewDeath");
            def.event[1] = def.event[0];
        }
        if (effectName == "playerEvent")
        {
            def.event[0] = G_->GetEventsParser()->ProcessEvent(effectNode, "__crewDeath");
        }
        if (effectName == "enemyEvent")
        {
            def.event[1] = G_->GetEventsParser()->ProcessEvent(effectNode, "__crewDeath");
        }
    }
    if (!explosionDef)
    {
        explosionDef = new ExplosionDefinition();
    }
    *explosionDef = def;
}

void CustomCrewManager::ParseAbilityEffect(rapidxml::xml_node<char>* stat, ActivatedPowerDefinition* powerDef)
{
    ActivatedPowerDefinition def;
    if (powerDef != nullptr)
    {
        def = *powerDef;
    }
    def.hasSpecialPower = true;
    for (auto effectNode = stat->first_node(); effectNode; effectNode = effectNode->next_sibling())
    {
        std::string effectName = std::string(effectNode->name());

        if (effectName == "powerSounds")
        {
            if (effectNode->first_attribute("enemy"))
            {
                def.soundsEnemy = EventsParser::ParseBoolean(effectNode->first_attribute("enemy")->value());
            }

            for (auto soundNode = effectNode->first_node(); soundNode; soundNode = soundNode->next_sibling())
            {
                if (strcmp(soundNode->name(), "powerSound") == 0)
                {
                    def.sounds.push_back(std::string(soundNode->value()));
                }
            }
        }
        if (effectName == "req")
        {
            auto reqDef = ActivatedPowerRequirements();

            ParsePowerRequirementsNode(effectNode, &reqDef);

            if (effectNode->first_attribute("type"))
            {
                if (strcmp(effectNode->first_attribute("type")->value(), "player") == 0)
                {
                    def.playerReq = reqDef;
                }
                else if (strcmp(effectNode->first_attribute("type")->value(), "enemy") == 0)
                {
                    def.enemyReq = reqDef;
                }
                else
                {
                    def.enemyReq = reqDef;
                    def.playerReq = reqDef;
                }
            }
            else
            {
                def.enemyReq = reqDef;
                def.playerReq = reqDef;
            }
        }
        if (effectName == "chargeReq")
        {
            def.chargeReq = new ActivatedPowerRequirements();

            ParsePowerRequirementsNode(effectNode, def.chargeReq);
        }
        if (effectName == "jumpCooldown")
        {
            std::string v = effectNode->value();

            if (v == "full") def.jumpCooldown = ActivatedPowerDefinition::JUMP_COOLDOWN_FULL;
            else if (v == "reset") def.jumpCooldown = ActivatedPowerDefinition::JUMP_COOLDOWN_RESET;
            else if (v == "continue") def.jumpCooldown = ActivatedPowerDefinition::JUMP_COOLDOWN_CONTINUE;
        }
        if (effectName == "damage")
        {
            def.damage.iDamage = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "fireChance")
        {
            def.damage.fireChance = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "breachChance")
        {
            def.damage.breachChance = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "ion")
        {
            def.damage.iIonDamage = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "sysDamage")
        {
            def.damage.iSystemDamage = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "persDamage")
        {
            def.damage.iPersDamage = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "hullBust")
        {
            def.damage.bHullBuster = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "lockdown")
        {
            def.damage.bLockdown = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "friendlyFire")
        {
            def.damage.bFriendlyFire = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "stun")
        {
            def.damage.iStun = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "cooldown")
        {
            def.cooldown = boost::lexical_cast<float>(effectNode->value());
        }
        if (effectName == "powerCharges")
        {
            def.powerCharges = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "initialCharges")
        {
            def.chargesPerJump = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "chargesPerJump")
        {
            def.chargesPerJump = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "shipFriendlyFire")
        {
            def.shipFriendlyFire = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "win")
        {
            def.win = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "animFrame")
        {
            def.animFrame = boost::lexical_cast<int>(effectNode->value());
            if (effectNode->first_attribute("followCrew"))
            {
                def.followCrew = EventsParser::ParseBoolean(effectNode->first_attribute("followCrew")->value());
            }
        }
        if (effectName == "buttonText")
        {
            if (effectNode->first_attribute("id"))
            {
                def.buttonLabel.data = effectNode->first_attribute("id")->value();
                def.buttonLabel.isLiteral = false;
            }
            else
            {
                def.buttonLabel.data = effectNode->value();
                def.buttonLabel.isLiteral = true;
            }
        }
        if (effectName == "tooltip")
        {
            if (effectNode->first_attribute("id"))
            {
                def.tooltip.data = effectNode->first_attribute("id")->value();
                def.tooltip.isLiteral = false;
            }
            else
            {
                def.tooltip.data = effectNode->value();
                def.tooltip.isLiteral = true;
            }
        }
        if (effectName == "cooldownColor")
        {
            ParseColorNode(def.cooldownColor, effectNode);
        }
        if (effectName == "effectAnim")
        {
            def.effectAnim = effectNode->value();
        }
        if (effectName == "crewHealth")
        {
            def.crewHealth = boost::lexical_cast<float>(effectNode->value());
        }
        if (effectName == "enemyHealth")
        {
            def.enemyHealth = boost::lexical_cast<float>(effectNode->value());
        }
        if (effectName == "selfHealth")
        {
            def.selfHealth = boost::lexical_cast<float>(effectNode->value());
        }
        if (effectName == "activateWhenReady")
        {
            def.activateWhenReady = EventsParser::ParseBoolean(effectNode->value());

            if (effectNode->first_attribute("enemiesOnly"))
            {
                def.activateReadyEnemies = EventsParser::ParseBoolean(effectNode->first_attribute("enemiesOnly")->value());
            }
        }
        if (effectName == "transformRace")
        {
            def.transformRace = effectNode->value();
        }
        if (effectName == "spawnCrew")
        {
            CrewSpawn *newSpawn = CrewSpawn::ParseCrewSpawn(effectNode, true);
            if (!newSpawn->race.empty())
            {
                def.crewSpawns.push_back(newSpawn);
            }
        }
        if (effectName == "statBoosts")
        {
            for (auto statBoostNode = effectNode->first_node(); statBoostNode; statBoostNode = statBoostNode->next_sibling())
            {
                if (strcmp(statBoostNode->name(), "statBoost") == 0)
                {
                    def.statBoosts.push_back(StatBoostManager::GetInstance()->ParseStatBoostNode(statBoostNode, StatBoostDefinition::BoostSource::CREW));
                }
            }
        }
        if (effectName == "event")
        {
            def.event[0] = G_->GetEventsParser()->ProcessEvent(effectNode, "__crewAbility");
            def.event[1] = def.event[0];
        }
        if (effectName == "playerEvent")
        {
            def.event[0] = G_->GetEventsParser()->ProcessEvent(effectNode, "__crewAbility");
        }
        if (effectName == "enemyEvent")
        {
            def.event[1] = G_->GetEventsParser()->ProcessEvent(effectNode, "__crewAbility");
        }
        if (effectName == "temporaryEffect")
        {
            def.hasTemporaryPower = true;

            for (auto tempEffectNode = effectNode->first_node(); tempEffectNode; tempEffectNode = tempEffectNode->next_sibling())
            {
                std::string tempEffectName = std::string(tempEffectNode->name());

                if (tempEffectName == "duration")
                {
                    def.tempPower.duration = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "cooldownColor")
                {
                    ParseColorNode(def.tempPower.cooldownColor, tempEffectNode);
                }
                if (tempEffectName == "finishSounds")
                {
                    if (tempEffectNode->first_attribute("enemy"))
                    {
                        def.tempPower.soundsEnemy = EventsParser::ParseBoolean(tempEffectNode->first_attribute("enemy")->value());
                    }

                    for (auto soundNode = tempEffectNode->first_node(); soundNode; soundNode = soundNode->next_sibling())
                    {
                        if (strcmp(soundNode->name(), "finishSound") == 0)
                        {
                            def.tempPower.sounds.push_back(std::string(soundNode->value()));
                        }
                    }
                }
                if (tempEffectName == "stunMultiplier")
                {
                    def.tempPower.stunMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "moveSpeedMultiplier")
                {
                    def.tempPower.moveSpeedMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "repairSpeed")
                {
                    def.tempPower.repairSpeed = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "damageMultiplier")
                {
                    def.tempPower.damageMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "rangedDamageMultiplier")
                {
                    def.tempPower.rangedDamageMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "doorDamageMultiplier")
                {
                    def.tempPower.doorDamageMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "bonusPower")
                {
                    def.tempPower.bonusPower = boost::lexical_cast<int>(tempEffectNode->value());
                }
                if (tempEffectName == "animSheet")
                {
                    def.tempPower.animSheet = tempEffectNode->value();
                    if (tempEffectNode->first_attribute("baseVisible"))
                    {
                        def.tempPower.baseVisible = EventsParser::ParseBoolean(tempEffectNode->first_attribute("baseVisible")->value());
                    }
                }
                if (tempEffectName == "effectAnim")
                {
                    def.tempPower.effectAnim = tempEffectNode->value();
                }
                if (tempEffectName == "invulnerable")
                {
                    def.tempPower.invulnerable = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "hackDoors")
                {
                    def.tempPower.hackDoors = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "controllable")
                {
                    def.tempPower.controllable = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "canFight")
                {
                    def.tempPower.canFight = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "canRepair")
                {
                    def.tempPower.canRepair = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "canSabotage")
                {
                    def.tempPower.canSabotage = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "canMan")
                {
                    def.tempPower.canMan = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "canTeleport")
                {
                    def.tempPower.canTeleport = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "canSuffocate")
                {
                    def.tempPower.canSuffocate = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "suffocationModifier")
                {
                    def.tempPower.suffocationModifier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "oxygenChangeSpeed")
                {
                    def.tempPower.oxygenChangeSpeed = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "canPhaseThroughDoors")
                {
                    def.tempPower.canPhaseThroughDoors = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "detectsLifeforms")
                {
                    def.tempPower.detectsLifeforms = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "isTelepathic")
                {
                    def.tempPower.isTelepathic = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "resistsMindControl")
                {
                    def.tempPower.resistsMindControl = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "fireDamageMultiplier")
                {
                    def.tempPower.fireDamageMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "damageTakenMultiplier")
                {
                    def.tempPower.damageTakenMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "allDamageTakenMultiplier")
                {
                    def.tempPower.allDamageTakenMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "sabotageSpeedMultiplier")
                {
                    def.tempPower.sabotageSpeedMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "passiveHealAmount")
                {
                    def.tempPower.passiveHealAmount = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "healAmount")
                {
                    def.tempPower.healAmount = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "truePassiveHealAmount")
                {
                    def.tempPower.truePassiveHealAmount = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "trueHealAmount")
                {
                    def.tempPower.trueHealAmount = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "damageEnemiesAmount")
                {
                    def.tempPower.damageEnemiesAmount = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "animFrame")
                {
                    def.tempPower.animFrame = boost::lexical_cast<int>(tempEffectNode->value());
                }
                if (tempEffectName == "healCrewAmount")
                {
                    def.tempPower.healCrewAmount = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "effectFinishAnim")
                {
                    def.tempPower.effectFinishAnim = tempEffectNode->value();
                }
                if (tempEffectName == "powerDrain")
                {
                    def.tempPower.powerDrain = boost::lexical_cast<int>(tempEffectNode->value());
                }
                if (tempEffectName == "powerDrainFriendly")
                {
                    def.tempPower.powerDrainFriendly = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "powerRechargeMultiplier")
                {
                    def.tempPower.powerRechargeMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "statBoosts")
                {
                    for (auto statBoostNode = tempEffectNode->first_node(); statBoostNode; statBoostNode = statBoostNode->next_sibling())
                    {
                        def.tempPower.statBoosts.push_back(StatBoostManager::GetInstance()->ParseStatBoostNode(statBoostNode, StatBoostDefinition::BoostSource::CREW));
                    }
                }
                if (tempEffectName == "noClone")
                {
                    def.tempPower.noClone = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "noAI")
                {
                    def.tempPower.noAI = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "validTarget")
                {
                    def.tempPower.validTarget = EventsParser::ParseBoolean(tempEffectNode->value());
                }
            }
        }
    }
    if (!powerDef)
    {
        powerDef = new ActivatedPowerDefinition();
    }
    *powerDef = def;
}

void CustomCrewManager::ParsePowerRequirementsNode(rapidxml::xml_node<char> *node, ActivatedPowerRequirements *def)
{
    for (auto reqNode = node->first_node(); reqNode; reqNode = reqNode->next_sibling())
    {
        std::string req = reqNode->name();
        std::string reqVal = reqNode->value();

        if (req == "enemyShip")
        {
            def->enemyShip = true;
        }
        if (req == "playerShip")
        {
            def->playerShip = true;
        }
        if (req == "friendlyInRoom")
        {
            def->friendlyInRoom = true;
            def->checkRoomCrew = true;
        }
        if (req == "enemyInRoom")
        {
            def->enemyInRoom = true;
            def->checkRoomCrew = true;
        }
        if (req == "notMindControlled")
        {
            def->extraConditions.emplace_back(CrewExtraCondition::MIND_CONTROLLED, false);
        }
        if (req == "whiteList")
        {
            auto *whiteList = &def->whiteList;
            if (reqNode->first_attribute("enemy"))
            {
                whiteList = EventsParser::ParseBoolean(reqNode->first_attribute("enemy")->value()) ? &def->enemyWhiteList : &def->friendlyWhiteList;
            }
            if (reqNode->first_attribute("load"))
            {
                whiteList = new std::vector<std::string>(G_->GetBlueprints()->GetBlueprintList(reqNode->first_attribute("load")->value()));
            }
            for (auto crewChild = reqNode->first_node(); crewChild; crewChild = crewChild->next_sibling())
            {
                if (strcmp(crewChild->name(), "blueprintList") == 0 && crewChild->first_attribute("load"))
                {
                    std::vector<std::string> tempList = G_->GetBlueprints()->GetBlueprintList(crewChild->first_attribute("load")->value());
                    whiteList->insert(whiteList->end(),tempList.begin(),tempList.end());
                }
                else
                {
                    whiteList->push_back(crewChild->name());
                }
            }
            whiteList->shrink_to_fit();
            def->checkRoomCrew = true;
        }
        if (req == "blackList")
        {
            bool friendlyList = true;
            bool enemyList = true;
            if (reqNode->first_attribute("enemy"))
            {
                enemyList = EventsParser::ParseBoolean(reqNode->first_attribute("enemy")->value());
                friendlyList = !enemyList;
            }
            if (reqNode->first_attribute("load"))
            {
                if (friendlyList) def->friendlyBlackList = G_->GetBlueprints()->GetBlueprintList(reqNode->first_attribute("load")->value());
                if (enemyList) def->enemyBlackList = G_->GetBlueprints()->GetBlueprintList(reqNode->first_attribute("load")->value());
            }
            for (auto crewChild = reqNode->first_node(); crewChild; crewChild = crewChild->next_sibling())
            {
                if (strcmp(crewChild->name(), "blueprintList") == 0 && crewChild->first_attribute("load"))
                {
                    std::vector<std::string> tempList = G_->GetBlueprints()->GetBlueprintList(crewChild->first_attribute("load")->value());
                    if (friendlyList) def->friendlyBlackList.insert(def->friendlyBlackList.end(),tempList.begin(),tempList.end());
                    if (enemyList) def->enemyBlackList.insert(def->enemyBlackList.end(),tempList.begin(),tempList.end());
                }
                else
                {
                    if (friendlyList) def->friendlyBlackList.push_back(crewChild->name());
                    if (enemyList) def->enemyBlackList.push_back(crewChild->name());
                }
            }
            if (friendlyList) def->friendlyBlackList.shrink_to_fit();
            if (enemyList) def->enemyBlackList.shrink_to_fit();
            def->checkRoomCrew = true;
        }
        if (req == "systemInRoom")
        {
            def->systemInRoom = true;
            if (reqNode->first_attribute("damaged"))
            {
                def->systemDamaged = EventsParser::ParseBoolean(reqNode->first_attribute("damaged")->value());
            }
        }
        if (req == "hasClonebay")
        {
            def->hasClonebay = true;
        }
        if (req == "aiDisabled")
        {
            def->aiDisabled = true;
        }
        if (req == "outOfCombat")
        {
            def->outOfCombat = true;
        }
        if (req == "inCombat")
        {
            def->inCombat = true;
        }
        if (req == "isManning")
        {
            def->extraConditions.emplace_back(CrewExtraCondition::MANNING, true);
        }
        if (req == "requiredSystem")
        {
            def->requiredSystem = ShipSystem::NameToSystemId(reqNode->value());
            if (reqNode->first_attribute("functional"))
            {
                def->requiredSystemFunctional = EventsParser::ParseBoolean(reqNode->first_attribute("functional")->value());
            }
        }
        if (req == "minHealth")
        {
            def->minHealth = boost::lexical_cast<int>(reqVal);
        }
        if (req == "maxHealth")
        {
            def->maxHealth = boost::lexical_cast<int>(reqVal);
        }
        if (req == "extraConditions")
        {
            bool isOrCondition = reqNode->first_attribute("type") && strcmp(reqNode->first_attribute("type")->value(), "or") == 0;
            auto &extraConditions = isOrCondition ? def->extraOrConditions : def->extraConditions;
            CustomCrewManager::GetInstance()->ParseExtraConditionsNode(reqNode, extraConditions);
            if (isOrCondition)
            {
                if (reqNode->first_attribute("text"))
                {
                    def->extraOrConditionsTooltip.data = reqNode->first_attribute("text")->value();
                    def->extraOrConditionsTooltip.isLiteral = true;
                }
                else if (reqNode->first_attribute("textId"))
                {
                    def->extraOrConditionsTooltip.data = reqNode->first_attribute("textId")->value();
                    def->extraOrConditionsTooltip.isLiteral = false;
                }
                if (def->extraOrConditionsTooltip.data.empty())
                {
                    def->extraOrConditionsTooltip.data = "power_not_ready_generic";
                }
            }
        }
    }
}

void CustomCrewManager::ParseExtraConditionsNode(rapidxml::xml_node<char> *node, std::vector<std::pair<CrewExtraCondition,bool>> &extraConditions)
{
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        if (strcmp(child->name(), "burning") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::BURNING, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "suffocating") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::SUFFOCATING, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "mindControlled") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::MIND_CONTROLLED, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "stunned") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::STUNNED, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "repairing") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::REPAIRING, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "repairingSystem") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::REPAIRING_SYSTEM, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "repairingBreach") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::REPAIRING_BREACH, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "fighting") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::FIGHTING, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "sabotaging") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::SABOTAGING, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "shooting") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::SHOOTING, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "moving") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::MOVING, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "idle") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::IDLE, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "manning") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::MANNING, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "firefighting") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::FIREFIGHTING, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "dying") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::DYING, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "teleporting") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::TELEPORTING, EventsParser::ParseBoolean(child->value()));
        }
    }
}

CrewMember* CustomCrewManager::CreateCrewMember(CrewBlueprint* bp, int shipId, bool intruder)
{
    std::string race = bp->name;
    if (!IsRace(race))
        return 0;

    Pointf unk = Pointf(0.f, 0.f);
    CrewAnimation* animation = new CrewAnimation(shipId, race, unk, intruder);

    CrewDefinition* def = GetDefinition(race);

    CrewMember *crew;
    crew = new CrewMember(*bp, shipId, intruder, animation);


    return crew;
}

bool CustomCrewManager::IsRace(const std::string& race)
{
    return blueprintNames.find(race) != blueprintNames.end();
}

std::string CrewMember_Extend::GetRace()
{
    // Get effective race, including special race for ion intruder
    if (isIonDrone && CustomCrewManager::GetInstance()->IsRace("boarder_ion"))
    {
        return "boarder_ion";
    }
    return orig->species;
}

CrewDefinition *CrewMember_Extend::GetDefinition()
{
    if (isIonDrone)
    {
        if (CustomCrewManager::GetInstance()->IsRace("boarder_ion"))
        {
            return CustomCrewManager::GetInstance()->GetDefinition("boarder_ion");
        }
    }
    if (CustomCrewManager::GetInstance()->IsRace(orig->species))
    {
        return CustomCrewManager::GetInstance()->GetDefinition(orig->species);
    }
    return nullptr;
}

ActivatedPowerDefinition* CrewMember_Extend::GetPowerDef() const
{
    return &ActivatedPowerDefinition::powerDefs[powerDefIdx];
}

ActivatedPowerDefinition* CrewMember_Extend::CalculatePowerDef()
{
    CrewDefinition* def = CustomCrewManager::GetInstance()->GetDefinition(orig->species);

    if (!powerActivated && !temporaryPowerActive)
    {
        auto aex = CMA_EX(orig->crewAnim);
        if (aex->powerDone)
        {
            CalculateStat(CrewStat::POWER_EFFECT, def); //powerChange

            if (powerChange != powerDefIdx)
            {
                powerDefIdx = powerChange;
                auto newDef = &ActivatedPowerDefinition::powerDefs[powerChange];

                if (newDef->hasSpecialPower)
                {
                    int newPowerMaxCharges = CalculateStat(CrewStat::POWER_MAX_CHARGES, def);

                    if (hasSpecialPower)
                    {
                        powerCooldown.first = (powerCooldown.first/powerCooldown.second) * newDef->cooldown;
                        powerCooldown.second = newDef->cooldown;

                        if (powerCharges.second >= 0)
                        {
                            powerCharges.first = std::min(powerCharges.first, newPowerMaxCharges);
                        }
                        else
                        {
                            powerCharges.first = std::min(newDef->initialCharges, newPowerMaxCharges);
                        }
                        powerCharges.second = newPowerMaxCharges;
                    }
                    else
                    {
                        powerCooldown.first = 0.f;
                        powerCooldown.second = newDef->cooldown;
                        powerCharges.second = newPowerMaxCharges;
                        powerCharges.first = std::min(newDef->initialCharges, newPowerMaxCharges);
                    }
                }

                temporaryPowerDuration.second = newDef->tempPower.duration;
                temporaryPowerDuration.first = temporaryPowerDuration.second;

                hasSpecialPower = newDef->hasSpecialPower;
                hasTemporaryPower = newDef->hasTemporaryPower;

                if (orig->iShipId == 0)
                {
                    G_->GetCApp()->gui->crewControl.ClearCrewBoxes();
                    G_->GetCApp()->gui->crewControl.UpdateCrewBoxes();
                }

                return newDef;
            }
        }
    }

    if (hasSpecialPower)
    {
        int newPowerMaxCharges = CalculateStat(CrewStat::POWER_MAX_CHARGES, def);
        powerCharges.first = std::min(powerCharges.first, newPowerMaxCharges);
        powerCharges.second = newPowerMaxCharges;
    }

    return &ActivatedPowerDefinition::powerDefs[powerDefIdx];
}

PowerReadyState CrewMember_Extend::PowerReq(const ActivatedPowerRequirements *req)
{
    ShipManager *currentShip = G_->GetShipManager(orig->currentShipId);
    ShipManager *crewShip = G_->GetShipManager(orig->iShipId);
    int ownerId = orig->GetPowerOwner();
    ShipManager *ownerShip = G_->GetShipManager(ownerId);

    if (!orig->intruder && req->enemyShip)
    {
        return POWER_NOT_READY_ENEMY_SHIP;
    }
    if (orig->intruder && req->playerShip)
    {
        return POWER_NOT_READY_PLAYER_SHIP;
    }
    // known bug: GetSystemInRoom rarely crashes upon loading a saved run, usually on chargeReq (it crashes trying to dereference a system in vSystemList)
    if (currentShip && req->systemInRoom && !currentShip->GetSystemInRoom(orig->iRoomId))
    {
        return POWER_NOT_READY_SYSTEM_IN_ROOM;
    }
    else if (currentShip && req->systemDamaged)
    {
        auto sys = currentShip->GetSystemInRoom(orig->iRoomId);

        if (sys && sys->healthState.first == sys->healthState.second) return POWER_NOT_READY_SYSTEM_DAMAGED;
    }
    if (req->checkRoomCrew && currentShip)
    {
        bool enemyInRoom = !req->enemyInRoom;
        bool friendlyInRoom = !req->friendlyInRoom;
        bool whiteList = req->whiteList.empty();
        bool enemyWhiteList = req->enemyWhiteList.empty();
        bool friendlyWhiteList = req->friendlyWhiteList.empty();
        bool enemyBlackList = true;
        bool friendlyBlackList = true;

        for (auto i : currentShip->vCrewList)
        {
            if (i->iRoomId == orig->iRoomId && i != orig && !i->bDead)
            {
                if (i->iShipId != ownerId)
                {
                    enemyInRoom = true;
                    if (!whiteList)
                    {
                        for (const std::string& race : req->whiteList)
                        {
                            if (i->species == race)
                            {
                                whiteList = true;
                                break;
                            }
                        }
                    }
                    if (!enemyWhiteList)
                    {
                        for (const std::string& race : req->enemyWhiteList)
                        {
                            if (i->species == race)
                            {
                                enemyWhiteList = true;
                                break;
                            }
                        }
                    }
                    if (enemyBlackList)
                    {
                        for (const std::string& race : req->enemyBlackList)
                        {
                            if (i->species == race)
                            {
                                enemyBlackList = false;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    friendlyInRoom = true;
                    if (!whiteList)
                    {
                        for (const std::string& race : req->whiteList)
                        {
                            if (i->species == race)
                            {
                                whiteList = true;
                                break;
                            }
                        }
                    }
                    if (!friendlyWhiteList)
                    {
                        for (const std::string& race : req->friendlyWhiteList)
                        {
                            if (i->species == race)
                            {
                                friendlyWhiteList = true;
                                break;
                            }
                        }
                    }
                    if (friendlyBlackList)
                    {
                        for (const std::string& race : req->friendlyBlackList)
                        {
                            if (i->species == race)
                            {
                                friendlyBlackList = false;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if (!enemyInRoom)
        {
            return POWER_NOT_READY_ENEMY_IN_ROOM;
        }
        else if (!friendlyInRoom)
        {
            return POWER_NOT_READY_FRIENDLY_IN_ROOM;
        }
        else if (!whiteList)
        {
            return POWER_NOT_READY_WHITELIST;
        }
        else if (!enemyWhiteList)
        {
            return POWER_NOT_READY_ENEMY_WHITELIST;
        }
        else if (!friendlyWhiteList)
        {
            return POWER_NOT_READY_FRIENDLY_WHITELIST;
        }
        else if (!enemyBlackList)
        {
            return POWER_NOT_READY_ENEMY_BLACKLIST;
        }
        else if (!friendlyBlackList)
        {
            return POWER_NOT_READY_FRIENDLY_BLACKLIST;
        }
    }
    if ((!crewShip || !crewShip->HasSystem(13)) && req->hasClonebay)
    {
        return POWER_NOT_READY_HAS_CLONEBAY;
    }
    if (req->aiDisabled && ownerId == 1)
    {
        return POWER_NOT_READY_AI_DISABLED;
    }
    if (req->outOfCombat && (crewShip && crewShip->current_target && crewShip->current_target->_targetable.hostile))
    {
        return POWER_NOT_READY_OUT_OF_COMBAT;
    }
    if (req->inCombat && (crewShip && (!crewShip->current_target || !crewShip->current_target->_targetable.hostile)))
    {
        return POWER_NOT_READY_IN_COMBAT;
    }
    if (req->requiredSystem != -1)
    {
        if (!ownerShip || !ownerShip->HasSystem(req->requiredSystem))
        {
            return POWER_NOT_READY_SYSTEM;
        }
        ShipSystem* sys = ownerShip->GetSystem(req->requiredSystem);
        if (sys == nullptr)
        {
            return POWER_NOT_READY_SYSTEM;
        }
        if (req->requiredSystemFunctional && (sys->iHackEffect > 1 || sys->GetEffectivePower() == 0))
        {
            return POWER_NOT_READY_SYSTEM_FUNCTIONAL;
        }
    }
    if (req->minHealth.enabled && orig->health.first < req->minHealth.value)
    {
        return POWER_NOT_READY_MIN_HEALTH;
    }
    if (req->maxHealth.enabled && orig->health.first > req->maxHealth.value)
    {
        return POWER_NOT_READY_MAX_HEALTH;
    }

    if (!req->extraConditions.empty())
    {
        for (auto& condition : req->extraConditions)
        {
            if (CheckExtraCondition(condition.first) != condition.second)
            {
                return (PowerReadyState)((condition.second ? POWER_NOT_READY_EXTRACONDITION_FALSE : POWER_NOT_READY_EXTRACONDITION_TRUE) + (PowerReadyState)condition.first);
            }
        }
    }

    if (!req->extraOrConditions.empty())
    {
        for (auto& condition : req->extraOrConditions)
        {
            if (CheckExtraCondition(condition.first) == condition.second) return POWER_READY;
        }
        return POWER_NOT_READY_EXTRACONDITION_OR;
    }

    return POWER_READY;
}

PowerReadyState CrewMember_Extend::PowerReady()
{
    if (loadingGame) return POWER_NOT_READY_COOLDOWN;

    if (temporaryPowerActive)
    {
        return POWER_NOT_READY_ACTIVATED;
    }
    if (powerCharges.second >= 0 && powerCharges.first <= 0)
    {
        return POWER_NOT_READY_CHARGES;
    }
    if (powerCooldown.first < powerCooldown.second)
    {
        return POWER_NOT_READY_COOLDOWN;
    }

    auto powerDef = GetPowerDef();

    return PowerReq(orig->GetPowerOwner() == 0 ? &powerDef->playerReq : &powerDef->enemyReq);
}

Damage* CrewMember_Extend::GetPowerDamage()
{
    auto custom = CustomCrewManager::GetInstance();

    Damage* damage = new Damage;

    auto powerDef = GetPowerDef();

    Damage* newDamage = &(powerDef->damage);

    damage->iDamage = newDamage->iDamage;
    damage->fireChance = newDamage->fireChance;
    damage->breachChance = newDamage->breachChance;
    damage->stunChance = newDamage->stunChance;
    damage->iIonDamage = newDamage->iIonDamage;
    damage->iSystemDamage = newDamage->iSystemDamage;
    damage->iPersDamage = newDamage->iPersDamage;
    damage->bHullBuster = newDamage->bHullBuster;
    damage->ownerId = orig->GetPowerOwner();
    damage->selfId = selfId;
    damage->bLockdown = false;
    damage->crystalShard = newDamage->crystalShard;
    damage->bFriendlyFire = newDamage->bFriendlyFire;
    damage->iStun = newDamage->iStun;

    return damage;
}

void CrewMember_Extend::ActivateTemporaryPower()
{
    ActivatedPowerDefinition* powerDef = GetPowerDef();

    auto aex = CMA_EX(orig->crewAnim);

    aex->temporaryPowerActive = true;

    if (hasTemporaryPower)
    {
        temporaryPowerActive = true;
        temporaryPowerDuration.first = powerDef->tempPower.duration;
    }

    if (powerDef->tempPower.canPhaseThroughDoors.enabled)
    {
        canPhaseThroughDoors = powerDef->tempPower.canPhaseThroughDoors.value;
    }

    outgoingAbilityStatBoosts.clear();
    for (StatBoostDefinition* statBoostDef : powerDef->tempPower.statBoosts)
    {
        StatBoost statBoost = StatBoost(statBoostDef);

        statBoost.crewSource = orig;
        outgoingAbilityStatBoosts.push_back(statBoost);
    }

    StatBoostManager::GetInstance()->statCacheFrame++; // resets stat cache in case game is paused
}

void CrewMember_Extend::PreparePower()
{
    ActivatedPowerDefinition* powerDef = GetPowerDef();

    CrewAnimation_Extend* aex = CMA_EX(orig->crewAnim);
    aex->PreparePower(powerDef);
    aex->powerDone = false;

    int ownerShip = orig->GetPowerOwner();
    powerShip = orig->currentShipId;
    powerRoom = orig->iRoomId;
    aex->effectWorldPos = Pointf(orig->x, orig->y);

    if (powerDef->animFrame == -1)
    {
        ActivatePower();
    }
    if (powerDef->tempPower.animFrame == -1)
    {
        ActivateTemporaryPower();
    }

    aex = CMA_EX(orig->crewAnim); // In case orig->crewAnim has changed

    if (aex->effectAnim != nullptr)
    {
        aex->effectAnim->SetCurrentFrame(0);
        aex->effectAnim->tracker.SetLoop(false, -1);
        aex->effectAnim->Start(true);
    }

    if (aex->tempEffectAnim != nullptr)
    {
        aex->tempEffectAnim->SetCurrentFrame(0);
        aex->tempEffectAnim->tracker.SetLoop(true, 0);
        aex->tempEffectAnim->Start(true);
    }

    if (powerDef->sounds.size() > 0 && (powerDef->soundsEnemy || orig->iShipId == 0 || ownerShip == 0))
    {
        int rng = random32();

        std::string sound = powerDef->sounds[rng % powerDef->sounds.size()];

        G_->GetSoundControl()->PlaySoundMix(sound, -1.f, false);
    }

    if (aex->effectAnim != nullptr)
    {
        aex->effectPos = Pointf(orig->x - aex->effectAnim->info.frameWidth / 2, orig->y - aex->effectAnim->info.frameHeight / 2 + orig->PositionShift());
    }
}

void CrewMember_Extend::ActivatePower()
{
    if (!CustomCrewManager::GetInstance()->IsRace(orig->species))
    {
        return;
    }

    ActivatedPowerDefinition* powerDef = GetPowerDef();

    ShipManager *ship;

    if (powerShip == 0)
    {
        ship = G_->GetWorld()->playerShip->shipManager;
    }
    else
    {
        ship = G_->GetWorld()->playerShip->enemyShip ? G_->GetWorld()->playerShip->enemyShip->shipManager : nullptr;
    }

    powerCooldown.first = 0;
    powerCharges.first = std::max(0, powerCharges.first - 1);

    powerActivated = true;

    if (powerDef->damage.bLockdown)
    {
        orig->ship->LockdownRoom(orig->iRoomId, Pointf(orig->x, orig->y));
    }

    if (powerDef->win)
    {
        G_->GetSoundControl()->StopPlaylist(100);
        G_->GetSoundControl()->PlaySoundMix("victory", -1.f, false);

        G_->GetScoreKeeper()->SetVictory(true);
        CustomShipUnlocks::instance->setCustomVictoryType = "";
        hs_log_file("powerDef->win: Set custom victory type to null\n");
        G_->GetAchievementTracker()->SetVictoryAchievement();
        G_->GetCApp()->gui->gameover = true;
        G_->GetCApp()->gui->Victory();
    }

    int ownerShip = orig->GetPowerOwner();

    if ((powerDef->crewHealth || powerDef->enemyHealth) && ship)
    {
        for (auto i : ship->vCrewList)
        {
            if (i->iRoomId == powerRoom && i != orig)
            {
                if (i->iShipId == ownerShip)
                {
                    i->DirectModifyHealth(powerDef->crewHealth);
                }
                else
                {
                    i->DirectModifyHealth(powerDef->enemyHealth);
                }
            }
        }
    }

    if (orig->iRoomId == powerRoom && powerDef->selfHealth)
    {
        orig->DirectModifyHealth(powerDef->selfHealth);
    }

    auto aex = CMA_EX(orig->crewAnim);
    aex->powerDone = true;

    if (!powerDef->transformRace.empty())
    {
        originalRace = powerDef->transformRace;
        TransformRace(powerDef->transformRace);
    }

    if (!powerDef->statBoosts.empty())
    {
        for (auto i=0; i<2; ++i)
        {
            ShipManager *crewShip = G_->GetShipManager(i);
            if (crewShip)
            {
                for (auto otherCrew : crewShip->vCrewList)
                {
                    for (auto statBoostDef : powerDef->statBoosts)
                    {
                        StatBoost statBoost(statBoostDef);
                        statBoost.crewSource = orig;
                        statBoost.sourceShipId = ownerShip;
                        StatBoostManager::GetInstance()->CreateTimedAugmentBoost(statBoost, otherCrew);
                    }
                }
            }
        }
    }

    for (auto& i : powerDef->crewSpawns)
    {
        if (ship)
        {
            CrewSpawn::SpawnCrew(i, ship, ship->iShipId != ownerShip, aex->effectWorldPos);
        }
    }

    if (!powerDef->event[ownerShip].empty())
    {
        CustomEventsParser::QueueEvent(powerDef->event[ownerShip], -1);
    }
}

void CrewMember_Extend::TransformColors(CrewBlueprint& bp, CrewBlueprint *newBlueprint)
{
    int nLayers = std::min(bp.colorLayers.size(), newBlueprint->colorLayers.size());
    for (int i=0; i<nLayers; i++)
    {
        if (newBlueprint->colorLayers[i].size() == bp.colorLayers[i].size())
        {
            newBlueprint->colorChoices[i] = bp.colorChoices[i];
        }
        else if (newBlueprint->colorChoices[i] == -1)
        {
            newBlueprint->colorChoices[i] = random32() % newBlueprint->colorLayers[i].size();
        }
    }
    bp.colorLayers = newBlueprint->colorLayers;
    bp.colorChoices = newBlueprint->colorChoices;
}

bool CrewMember_Extend::TransformRace(const std::string& species)
{
    auto& equipList = G_->GetShipInfo(orig->iShipId)->equipList;

    auto it = equipList.find(orig->type);
    if (it != equipList.end())
    {
        if (it->second > 0) it->second -= 1;
    }

    auto newBlueprint = G_->GetBlueprints()->GetCrewBlueprint(species);

    orig->blueprint.powers = newBlueprint.powers;
    orig->blueprint.name = newBlueprint.name;
    orig->blueprint.desc = newBlueprint.desc;
    orig->blueprint.type = newBlueprint.type;
    orig->species = newBlueprint.name;
    orig->type = newBlueprint.name;

    if (g_transformColorMode == TransformColorMode::KEEP_INDICES)
    {
        originalColorRace = newBlueprint.name;

        TransformColors(orig->blueprint, &newBlueprint);

        orig->crewAnim->layerColors.clear();
        for (int i=0; i<orig->blueprint.colorLayers.size(); i++)
        {
            orig->crewAnim->layerColors.push_back(orig->blueprint.colorLayers[i][orig->blueprint.colorChoices[i]]);
        }
    }

    it = equipList.find(orig->type);
    if (it != equipList.end())
    {
        it->second += 1;
    }
    else
    {
        equipList[orig->type] = 1;
    }

    /*
    auto newCrewAnim = new CrewAnimation(orig->iShipId, orig->species, Pointf(0, 0), orig->iShipId == 1);

    orig->crewAnim->anims = newCrewAnim->anims;
    orig->crewAnim->baseStrip = newCrewAnim->baseStrip;
    orig->crewAnim->colorStrip = newCrewAnim->colorStrip;
    orig->crewAnim->bDrone = newCrewAnim->bDrone;
    orig->crewAnim->bGhost = newCrewAnim->bGhost;
    orig->crewAnim->race = newCrewAnim->race;

    delete newCrewAnim;
    */

    Initialize(orig->blueprint, orig->iShipId, orig->iShipId == 1, orig->crewAnim, true);

    if (orig->iShipId == 0)
    {
        G_->GetCApp()->gui->crewControl.ClearCrewBoxes();
        G_->GetCApp()->gui->crewControl.UpdateCrewBoxes();
    }

    StatBoostManager::GetInstance()->statCacheFrame++; // resets stat cache in case game is paused
    return true;
}

void CrewMember_Extend::TemporaryPowerFinished()
{
    if (!CustomCrewManager::GetInstance()->IsRace(orig->species))
    {
        return;
    }

    ActivatedPowerDefinition* powerDef = GetPowerDef();

    temporaryPowerActive = false;

    if (powerDef->tempPower.sounds.size() > 0  && (powerDef->tempPower.soundsEnemy || orig->iShipId == 0))
    {
        int rng = random32();

        std::string sound = powerDef->tempPower.sounds[rng % powerDef->tempPower.sounds.size()];

        G_->GetSoundControl()->PlaySoundMix(sound, -1, false);
    }

    auto aex = CMA_EX(orig->crewAnim);

    if (aex->tempEffectAnim != nullptr)
    {
        aex->tempEffectAnim->tracker.Stop(false);
    }

    aex->temporaryPowerActive = false;

    canPhaseThroughDoors = CustomCrewManager::GetInstance()->GetDefinition(orig->species)->canPhaseThroughDoors;

    if (aex->effectFinishAnim != nullptr)
    {
        aex->effectFinishAnim->SetCurrentFrame(0);
        aex->effectFinishAnim->tracker.SetLoop(false, -1);
        aex->effectFinishAnim->Start(true);
    }

}

void CrewAnimation_Extend::PreparePower(ActivatedPowerDefinition* def)
{
    if (effectAnim) effectAnim->destructor();
    if (effectFinishAnim) effectFinishAnim->destructor();
    if (tempEffectAnim) tempEffectAnim->destructor();
  //delete tempEffectStrip;
    effectAnim = nullptr;
    effectFinishAnim = nullptr;
    tempEffectAnim = nullptr;
    tempEffectStrip = nullptr;

    if (!def->effectAnim.empty())
    {
        effectAnim = new Animation(G_->GetAnimationControl()->GetAnimation(def->effectAnim));
    }
    if (!def->tempPower.effectFinishAnim.empty())
    {
        effectFinishAnim = new Animation(G_->GetAnimationControl()->GetAnimation(def->tempPower.effectFinishAnim));
    }
    if (!def->tempPower.effectAnim.empty())
    {
        tempEffectAnim = new Animation(G_->GetAnimationControl()->GetAnimation(def->tempPower.effectAnim));
    }
    if (!def->tempPower.animSheet.empty())
    {
        tempEffectStrip = G_->GetResources()->GetImageId("people/" + def->tempPower.animSheet + ".png");
    }

    tempEffectBaseVisible = def->tempPower.baseVisible;
}

void CrewAnimation_Extend::OnInit(const std::string& name, Pointf position, bool enemy)
{
    /*
    CustomCrewManager *custom = CustomCrewManager::GetInstance();


    if (custom->IsRace(orig->race))
    {
        auto def = custom->GetDefinition(orig->race);
    }
    */
}



//=================================

static bool blockAddSoundQueue = false;

HOOK_METHOD(Animation, AddSoundQueue, (int frame, const std::string& str) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Animation::AddSoundQueue -> Begin (CustomCrew.cpp)\n")
    if (blockAddSoundQueue) return;

    super(frame, str);
}

HOOK_METHOD_PRIORITY(CrewMember, constructor, -899, (CrewBlueprint& bp, int shipId, bool enemy, CrewAnimation *animation) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::constructor -> Begin (CustomCrew.cpp)\n")
    for (unsigned int i=0; i<bp.colorLayers.size(); ++i)
    {
        if (bp.colorChoices[i] >= (int) bp.colorLayers[i].size()) bp.colorLayers[i].resize(bp.colorChoices[i]+1, GL_Color(0.0,0.0,0.0,0.0));
    }

    super(bp, shipId, enemy, animation);

    CrewMember_Extend* ex = CM_EX(this);
    if (ex->originalColorRace.empty()) ex->originalColorRace = species;
    if (ex->originalRace.empty()) ex->originalRace = species;
    ex->Initialize(bp, shipId, enemy, animation);
}

static bool g_forceNoSlot = false;

void CrewMember_Extend::Initialize(CrewBlueprint& bp, int shipId, bool enemy, CrewAnimation *animation, bool isTransform)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (custom->IsRace(orig->species))
    {
        auto def = custom->GetDefinition(orig->species);
        auto powerDef = CalculatePowerDef();
        auto aex = CMA_EX(orig->crewAnim);

        if (!aex->isIonDrone)
        {
            Pointf lastPosition = Pointf(0, 0);
            std::vector<GL_Color> layerColors = std::vector<GL_Color>();
            std::vector<GL_Texture*> layerStrips = std::vector<GL_Texture*>();
            bool male = false;
            bool uniqueBoolShoot = false;
            bool uniqueBoolFire = false;
            bool uniqueBoolSparked = true;

            bool replaceLayers = false;

            if (animation)
            {
                layerColors = animation->layerColors;
                layerStrips = animation->layerStrips;
                male = animation->bMale;
                replaceLayers = true;
                lastPosition = animation->lastPosition;

                if (aex->crewAnimationType == "rock")
                {
                    uniqueBoolFire = animation->uniqueBool1;
                    uniqueBoolShoot = animation->uniqueBool2;
                }
                else if (aex->crewAnimationType == "mantis")
                {
                    uniqueBoolShoot = animation->uniqueBool1;
                }
                else if (aex->crewAnimationType == "repair")
                {
                    uniqueBoolSparked = animation->uniqueBool1;
                }
            }

            std::string animSheet = def->animSheet[male?1:0];
            if (animSheet.empty()) animSheet = bp.name;

            Animation* effectAnim = aex->effectAnim;
            Animation* effectFinishAnim = aex->effectFinishAnim;
            Animation* tempEffectAnim = aex->tempEffectAnim;
            GL_Texture* tempEffectStrip = aex->tempEffectStrip;

            aex->effectAnim = nullptr;
            aex->effectFinishAnim = nullptr;
            aex->tempEffectAnim = nullptr;
            aex->tempEffectStrip = nullptr;

            if (def->animBase == "rock")
            {
                blockAddSoundQueue = true;
                orig->crewAnim = new RockAnimation(animSheet, shipId, lastPosition, enemy);
                aex = CMA_EX(orig->crewAnim);
                aex->crewAnimationType = "rock";
                blockAddSoundQueue = false;
            }
            else if (def->animBase == "mantis")
            {
                orig->crewAnim = new MantisAnimation;
                orig->crewAnim->constructor(shipId, animSheet, lastPosition, enemy);
                aex = CMA_EX(orig->crewAnim);
                aex->isMantisAnimation = true;
                aex->crewAnimationType = "mantis";
            }
            else if (def->animBase == "repair")
            {
                orig->crewAnim = new RepairAnimation(shipId, animSheet, lastPosition, enemy);
                aex = CMA_EX(orig->crewAnim);
                aex->crewAnimationType = "repair";
            }
            else
            {
                orig->crewAnim = new CrewAnimation(shipId, animSheet, lastPosition, enemy);
                aex = CMA_EX(orig->crewAnim);
            }

            aex->effectAnim = effectAnim;
            aex->effectFinishAnim = effectFinishAnim;
            aex->tempEffectAnim = tempEffectAnim;
            aex->tempEffectStrip = tempEffectStrip;

            orig->crewAnim->bMale = male;

            if (replaceLayers && !orig->crewAnim->bDrone)
            {
                orig->crewAnim->layerColors = layerColors;

                if (g_transformColorMode == TransformColorMode::KEEP_COLORS)
                {
                    auto bpM = G_->GetBlueprints();
                    auto it = bpM->crewBlueprints.find(bp.name);
                    if (it != bpM->crewBlueprints.end() && it->second.colorLayers.size() < orig->crewAnim->layerColors.size())
                    {
                        orig->crewAnim->layerColors.resize(it->second.colorLayers.size());
                    }
                    orig->crewAnim->SetupStrips();

                    orig->crewAnim->layerColors = layerColors;
                }
                else
                {
                    orig->crewAnim->SetupStrips();
                }
            }

            if (animation)
            {
                orig->crewAnim->direction = animation->direction;
                orig->crewAnim->sub_direction = animation->sub_direction;
                orig->crewAnim->status = animation->status;
                orig->crewAnim->moveDirection = animation->moveDirection;
                orig->crewAnim->shots = animation->shots;
                orig->crewAnim->shootTimer.currTime = animation->shootTimer.currTime;
                orig->crewAnim->shootTimer.currGoal = animation->shootTimer.currGoal;
                orig->crewAnim->shootTimer.loop = animation->shootTimer.loop;
                orig->crewAnim->shootTimer.running = animation->shootTimer.running;
                orig->crewAnim->punchTimer.currTime = animation->punchTimer.currTime;
                orig->crewAnim->punchTimer.currGoal = animation->punchTimer.currGoal;
                orig->crewAnim->punchTimer.loop = animation->punchTimer.loop;
                orig->crewAnim->punchTimer.running = animation->punchTimer.running;
                orig->crewAnim->target = animation->target;
                orig->crewAnim->fDamageDone = animation->fDamageDone;
                orig->crewAnim->bFrozen = animation->bFrozen;
                orig->crewAnim->bTyping = animation->bTyping;
                orig->crewAnim->currentShip = animation->currentShip;
                orig->crewAnim->forcedAnimation = animation->forcedAnimation;
                orig->crewAnim->forcedDirection = animation->forcedDirection;
                orig->crewAnim->bStunned = animation->bStunned;
                orig->crewAnim->bDoorTarget = animation->bDoorTarget;

                //orig->crewAnim->anims.at(animation->direction).at(animation->status).SetProgress(animation->anims.at(animation->direction).at(animation->status).tracker.Progress(-1.f));

                if (aex->crewAnimationType == "rock")
                {
                    orig->crewAnim->uniqueBool1 = uniqueBoolFire;
                    orig->crewAnim->uniqueBool2 = uniqueBoolShoot;
                }
                else if (aex->crewAnimationType == "mantis")
                {
                    orig->crewAnim->uniqueBool1 = uniqueBoolShoot;
                }
                else if (aex->crewAnimationType == "repair")
                {
                    orig->crewAnim->uniqueBool1 = uniqueBoolSparked;
                }

                int numDirections = std::min(animation->anims.size(), orig->crewAnim->anims.size());
                for (int i=0; i<numDirections; ++i)
                {
                    int numStatus = std::min(animation->anims[i].size(), orig->crewAnim->anims[i].size());
                    for (int j=0; j<numStatus; ++j)
                    {
                        Animation &anim1 = animation->anims[i][j];
                        Animation &anim2 = orig->crewAnim->anims[i][j];
                        float animProgress = anim1.tracker.time != 0.f ? anim1.tracker.current_time/anim1.tracker.time : 0.f;

                        anim2.tracker.current_time = anim2.tracker.time * animProgress;
                        anim2.tracker.currentDelay = anim2.tracker.loopDelay * (anim1.tracker.loopDelay != 0.f ? anim1.tracker.currentDelay/anim1.tracker.loopDelay : 1.f);
                        anim2.tracker.loop = anim1.tracker.loop;
                        anim2.tracker.running = anim1.tracker.running;
                        anim2.tracker.reverse = anim1.tracker.reverse;
                        anim2.tracker.done = anim1.tracker.done;
                        anim2.tracker.running = anim1.tracker.running;

                        anim2.fadeOut = anim2.startFadeOut * (anim1.startFadeOut != 0.f ? anim1.fadeOut/anim1.startFadeOut : 1.f);

                        if (anim2.randomizeFrames)
                        {
                            if (anim2.info.numFrames != 0)
                            {
                                anim2.currentFrame = anim1.currentFrame % anim2.info.numFrames;
                            }
                        }
                        else
                        {
                            if (animProgress >= 1.f)
                            {
                                anim2.currentFrame = anim2.info.numFrames;
                            }
                            else if (animProgress < 0.f)
                            {
                                anim2.currentFrame = 0;
                            }
                            else
                            {
                                anim2.currentFrame = animProgress * anim2.info.numFrames;
                            }
                        }
                    }
                }
            }

            if (def->repairSoundFrame != -1 && def->repairSounds.size() > 0 && !enemy)
            {
                for (auto sound : def->repairSounds)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        orig->crewAnim->anims[i][2].AddSoundQueue(def->repairSoundFrame, sound);
                    }
                }
            }

            delete animation;
            animation = orig->crewAnim;
        }

        if (def->shootTimer.first != -1)
        {
            orig->crewAnim->shootTimer.minTime = def->shootTimer.first;
            orig->crewAnim->shootTimer.maxTime = def->shootTimer.second;
        }

        float limitGoal = orig->crewAnim->shootTimer.maxTime / 1000.f;
        if (orig->crewAnim->shootTimer.currGoal > limitGoal)
        {
            orig->crewAnim->shootTimer.currTime *= limitGoal/orig->crewAnim->shootTimer.currGoal;
            orig->crewAnim->shootTimer.currGoal = limitGoal;
        }
        else
        {
            limitGoal = orig->crewAnim->shootTimer.minTime / 1000.f;
            if (orig->crewAnim->shootTimer.currGoal < limitGoal)
            {
                orig->crewAnim->shootTimer.currTime *= limitGoal/orig->crewAnim->shootTimer.currGoal;
                orig->crewAnim->shootTimer.currGoal = limitGoal;
            }
        }

        if (def->punchTimer.first != -1)
        {
            orig->crewAnim->punchTimer.minTime = def->punchTimer.first;
            orig->crewAnim->punchTimer.maxTime = def->punchTimer.second;
        }

        limitGoal = orig->crewAnim->punchTimer.maxTime / 1000.f;
        if (orig->crewAnim->punchTimer.currGoal > limitGoal)
        {
            float goalMult = limitGoal/orig->crewAnim->punchTimer.currGoal;
            orig->crewAnim->punchTimer.currTime *= goalMult;
            orig->crewAnim->punchTimer.currGoal = limitGoal;
            orig->crewAnim->anims[orig->crewAnim->direction][1].tracker.time *= goalMult;
            orig->crewAnim->anims[orig->crewAnim->direction][1].tracker.current_time *= goalMult;
        }
        else
        {
            limitGoal = orig->crewAnim->punchTimer.minTime / 1000.f;
            if (orig->crewAnim->punchTimer.currGoal < limitGoal)
            {
                float goalMult = limitGoal/orig->crewAnim->punchTimer.currGoal;
                orig->crewAnim->punchTimer.currTime *= goalMult;
                orig->crewAnim->punchTimer.currGoal = limitGoal;
                orig->crewAnim->anims[orig->crewAnim->direction][1].tracker.time *= goalMult;
                orig->crewAnim->anims[orig->crewAnim->direction][1].tracker.current_time *= goalMult;
            }
        }

        aex->canPunch = def->canPunch;

        float passiveHealAmount = CalculateStat(CrewStat::PASSIVE_HEAL_AMOUNT, def);
        float truePassiveHealAmount = CalculateStat(CrewStat::TRUE_PASSIVE_HEAL_AMOUNT, def);
        if (passiveHealAmount != 0.f || truePassiveHealAmount != 0.f)
        {
            float passiveHealDelay = CalculateStat(CrewStat::PASSIVE_HEAL_DELAY, def);
            if (passiveHealDelay > 0 && passiveHealTimer == nullptr)
            {
                passiveHealTimer = new TimerHelper();
                passiveHealTimer->Start(passiveHealDelay);
            }
        }

        if (!isTransform) // might not need this at all since CalculatePowerDef() initializes this
        {
            powerCooldown.first = 0.f;
            powerCooldown.second = powerDef->cooldown;
            temporaryPowerDuration.second = powerDef->tempPower.duration;
            temporaryPowerDuration.first = temporaryPowerDuration.second;
            powerCharges.second = powerDef->powerCharges;
            powerCharges.first = std::min(powerDef->initialCharges, powerDef->powerCharges);
            hasSpecialPower = powerDef->hasSpecialPower;
            hasTemporaryPower = powerDef->hasTemporaryPower;
        }
        canPhaseThroughDoors = def->canPhaseThroughDoors;

        outgoingStatBoosts.clear();
        for (StatBoostDefinition* statBoostDef : def->passiveStatBoosts)
        {
            StatBoost statBoost = StatBoost(statBoostDef);

            statBoost.crewSource = orig;
            outgoingStatBoosts.push_back(statBoost);
        }
        outgoingAbilityStatBoosts.clear();
        for (StatBoostDefinition* statBoostDef : powerDef->tempPower.statBoosts)
        {
            StatBoost statBoost = StatBoost(statBoostDef);

            statBoost.crewSource = orig;
            outgoingAbilityStatBoosts.push_back(statBoost);
        }


        auto skillsDef = def->skillsDef;
        noSlot = def->noSlot || g_forceNoSlot;

        std::string skillOrder[6] = {"piloting", "engines", "shields", "weapons", "repair", "combat"};

        for (int i = 0; i < orig->blueprint.skillLevel.size(); i++)
        {
            orig->blueprint.skillLevel[i].first = ((float)orig->blueprint.skillLevel[i].first / orig->blueprint.skillLevel[i].second) * (skillsDef.skills[skillOrder[i]].requirement * 2);
            orig->blueprint.skillLevel[i].second = skillsDef.skills[skillOrder[i]].requirement * 2;
            int defaultSkillLevel = CalculateStat(CrewStat::DEFAULT_SKILL_LEVEL, def);

            if (orig->blueprint.skillLevel[i].first < (defaultSkillLevel / 2.f) * orig->blueprint.skillLevel[i].second)
            {
                orig->blueprint.skillLevel[i].first = ((defaultSkillLevel / 2.f) * orig->blueprint.skillLevel[i].second);
            }
        }

        g_forceNoSlot = false;
    }
}

HOOK_METHOD(CrewBlueprint, RandomSkills, (int worldLevel) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewBlueprint::RandomSkills -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();
    super(worldLevel);


    if (custom->IsRace(name))
    {
        auto skillsDef = custom->GetDefinition(name)->skillsDef;

        std::string skillOrder[6] = {"piloting", "engines", "shields", "weapons", "repair", "combat"};

        for (int i = 0; i < skillLevel.size(); i++)
        {

            skillLevel[i].first = ((float)skillLevel[i].first / skillLevel[i].second) * (skillsDef.skills[skillOrder[i]].requirement * 2);
            skillLevel[i].second = skillsDef.skills[skillOrder[i]].requirement * 2;
        }
    }
}

HOOK_METHOD_PRIORITY(CrewMember, UpdateHealth, 2000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::UpdateHealth -> Begin (CustomCrew.cpp)\n")
    if (G_->GetCApp()->menu.shipBuilder.bOpen) return;

    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto ex = CM_EX(this);

//    using std::chrono::steady_clock;
//    using std::chrono::duration_cast;
//    using std::chrono::duration;
//    using std::chrono::milliseconds;
//    auto t1 = steady_clock::now();

    auto def = custom->GetDefinition(this->species);

//    auto t2 = steady_clock::now();
//    duration<double, std::nano> ms_double = t2 - t1;
//    std::cout << "Definition time: " << ms_double.count();

    if (iOnFire && CanBurn())
    {
        float fireMultiplier = 1.f;

        if (custom->IsRace(species))
        {
            fireMultiplier = ex->CalculateStat(CrewStat::FIRE_DAMAGE_MULTIPLIER, def);
        }

        DirectModifyHealth(G_->GetCFPS()->GetSpeedFactor() * (iOnFire * -0.133f * fireMultiplier));
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


    if (custom->IsRace(species))
    {
        mod = ex->CalculateStat(CrewStat::HEAL_SPEED_MULTIPLIER, def);
    }

    float medbayRate = fMedbay;
    if (medbayRate > 1.f)
    {
        medbayRate = (medbayRate - 1.f) * 1.5f;
    }

    DirectModifyHealth(G_->GetCFPS()->GetSpeedFactor() * (medbayRate + ex->extraMedbay) * mod * 0.4f);

    if (custom->IsRace(species))
    {
        float passiveHealAmount = ex->CalculateStat(CrewStat::PASSIVE_HEAL_AMOUNT, def);
        float healAmount = ex->CalculateStat(CrewStat::ACTIVE_HEAL_AMOUNT, def);
        float trueHealAmount = ex->CalculateStat(CrewStat::TRUE_HEAL_AMOUNT, def);
        float truePassiveHealAmount = ex->CalculateStat(CrewStat::TRUE_PASSIVE_HEAL_AMOUNT, def);

        if (healAmount != 0.f)
        {
            if (healAmount > 0.f && health.first != health.second)
            {
                fMedbay += 0.0000000001;
            }
            DirectModifyHealth(G_->GetCFPS()->GetSpeedFactor() * healAmount * mod * 0.06245f);
        }
        if (ex->isHealing && passiveHealAmount != 0.f && health.first != health.second)
        {
            if (passiveHealAmount > 0.f && health.first != health.second)
            {
                fMedbay += 0.0000000001;
            }
            DirectModifyHealth(G_->GetCFPS()->GetSpeedFactor() * passiveHealAmount * mod * 0.06245f);
        }
        if (trueHealAmount != 0.f)
        {
            if (trueHealAmount > 0.f && health.first != health.second)
            {
                fMedbay += 0.0000000001;
            }
            DirectModifyHealth(G_->GetCFPS()->GetSpeedFactor() * trueHealAmount * 0.06245f);
        }
        if (ex->isHealing && truePassiveHealAmount != 0.f && health.first != health.second)
        {
            if (truePassiveHealAmount > 0.f && health.first != health.second)
            {
                fMedbay += 0.0000000001;
            }
            DirectModifyHealth(G_->GetCFPS()->GetSpeedFactor() * truePassiveHealAmount * 0.06245f);
        }
    }

    //super();
}
HOOK_METHOD_PRIORITY(CrewMember, DirectModifyHealth, 1000, (float healthMod) -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::DirectModifyHealth -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();
    CrewMember_Extend* ex = CM_EX(this);
    auto def = custom->GetDefinition(this->species);

    if (custom->IsRace(species))
    {
        if (healthMod < 0.f)
        {
            if (ex->temporaryPowerActive && ex->GetPowerDef()->tempPower.invulnerable)
            {
                return false;
            }
            else
            {
                healthMod *= ex->CalculateStat(CrewStat::ALL_DAMAGE_TAKEN_MULTIPLIER, def);
            }
        }

        if (health.first > 0.f && health.first + healthMod <= 0.f) // will die
        {
            ex->CalculateStat(CrewStat::DEATH_EFFECT, def);

            if (ex->hasDeathExplosion)
            {
                ExplosionDefinition *explosionDef = &ex->deathEffectChange;
                if (!explosionDef->transformRace.empty())
                {
                    health.first = 0.f; // prevent any damage from the following effects from applying, avoids infinite loops etc.

                    // we explode as part of the transform as the crewmember won't actually die and explode normally
                    bool oldBlockDamageArea = blockDamageArea;
                    blockDamageArea = false;

                    ex->triggerExplosion = true;
                    Damage damage = this->GetRoomDamage();
                    if (damage.ownerId != -1)
                    {
                        ShipManager *crewShip = G_->GetShipManager(currentShipId);
                        if (crewShip)
                        {
                            CustomDamage* oldDamage = CustomDamageManager::currentWeaponDmg;
                            CustomDamageManager::currentWeaponDmg = nullptr; // if triggered by a projectile we don't want that projectile's CustomDamage for this effect

                            crewShip->DamageArea(Pointf(x, y), *((DamageParameter*)&damage), true);

                            CustomDamageManager::currentWeaponDmg = oldDamage;
                        }
                    }

                    blockDamageArea = oldBlockDamageArea;

                    if (explosionDef->transformRaceDeathSound)
                    {
                        std::string deathSound = crewAnim->GetDeathSound();
                        G_->GetSoundControl()->PlaySoundMix(deathSound, -1.f, false);
                    }
                    ex->originalRace = explosionDef->transformRace;
                    ex->TransformRace(explosionDef->transformRace);
                    StatBoostManager::GetInstance()->statCacheFrame++; // resets stat cache for the death transform
                    auto newDef = custom->GetDefinition(explosionDef->transformRace); // use the new race for subsequent stat checks

                    health.first = ex->CalculateStat(CrewStat::MAX_HEALTH, newDef) * explosionDef->transformRaceHealthFraction + explosionDef->transformRaceHealth;
                    if (health.first <= 0.f) health.first = 1.0e-9f;
                    if (health.first > health.second) health.first = health.second;

                    if (ex->passiveHealTimer)
                    {
                        ex->isHealing = false;
                        ex->passiveHealTimer->Start(ex->CalculateStat(CrewStat::PASSIVE_HEAL_DELAY, newDef));
                    }

                    return false;
                }
            }
        }
    }

    bool ret = super(healthMod);

    if (custom->IsRace(species) && healthMod < 0.f && ex->passiveHealTimer)
    {
        ex->isHealing = false;
        ex->passiveHealTimer->Start(ex->CalculateStat(CrewStat::PASSIVE_HEAL_DELAY, def));
    }

	return ret;
}
HOOK_METHOD(CrewMember, SetHealthBoost, (int _healthBoost) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::SetHealthBoost -> Begin (CustomCrew.cpp)\n")
    int delta = _healthBoost - healthBoost;
    if (delta != 0)
    {
        health.second += delta;
        if (delta > 0)
        {
            health.first += delta;
        }
        else
        {
            health.first = std::min(health.first, health.second);
        }
        healthBoost = _healthBoost;
    }
    GetMaxHealth();
}
HOOK_METHOD_PRIORITY(CrewMember, OnLoop, 1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::OnLoop -> Begin (CustomCrew.cpp)\n")
    super();

    auto custom = CustomCrewManager::GetInstance();
    CrewMember_Extend* ex = CM_EX(this);

    if (ex->deathTimer)
    {
        ex->deathTimer->Update();
        if (ex->deathTimer->Done())
        {
            health.first = 0.f;
        }
    }

    if (custom->IsRace(species))
    {
        auto def = custom->GetDefinition(species);
        float delay = ex->CalculateStat(CrewStat::PASSIVE_HEAL_DELAY, def);
        if (!ex->passiveHealTimer && delay != 0)
        {
            ex->passiveHealTimer = new TimerHelper();
            ex->passiveHealTimer->Start(delay);
        }
        else if (ex->passiveHealTimer && delay == 0)
        {
            delete ex->passiveHealTimer;
            ex->passiveHealTimer = nullptr;
            ex->isHealing = true;
        }
        else if (ex->passiveHealTimer)
        {
            ex->passiveHealTimer->Update();
            if (ex->passiveHealTimer->Done())
            {
                ex->isHealing = true;
            }
        }
        else
        {
            ex->isHealing = true;
        }

        if (fStunTime != 0.f)
        {
            if (fStunTime < ex->prevStun)
            {
                auto def = custom->GetDefinition(species);
                float stunMultiplier = ex->CalculateStat(CrewStat::STUN_MULTIPLIER, def);

                if (stunMultiplier > 0.f)
                {
                    fStunTime = ex->prevStun - ((ex->prevStun - fStunTime) * (1.f / stunMultiplier));
                    if (fStunTime < 0.f)
                    {
                        fStunTime = 0.f;
                    }
                }
                else
                {
                    fStunTime = 0.f;
                }
            }
        }

        ex->prevStun = fStunTime;

        auto powerDef = ex->CalculatePowerDef();

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
                auto def = custom->GetDefinition(species);
                if (ex->powerCharges.second >= 0 && ex->powerCharges.first <= 0)
                {
                    ex->powerCooldown.first = 0.f;
                }
                else if (powerDef->chargeReq == nullptr || ex->PowerReq(powerDef->chargeReq) == POWER_READY)
                {
                    ex->powerCooldown.first = std::max(0.f, std::min(ex->powerCooldown.second, (float)(G_->GetCFPS()->GetSpeedFactor() * 0.0625 * ex->CalculateStat(CrewStat::POWER_RECHARGE_MULTIPLIER, def)) + ex->powerCooldown.first));
                }

                if (!IsDead())
                {
                    bool activateWhenReady = false;
                    // Only check activateWhenReady if not dying
                    if (crewAnim->status != 3) ex->CalculateStat(CrewStat::ACTIVATE_WHEN_READY, def, &activateWhenReady);
                    if (activateWhenReady)
                    {
                        if (ex->PowerReady() == POWER_READY)
                        {
                            if (!powerDef->activateReadyEnemies || (GetPowerOwner() == 1))
                            {
                                ex->PreparePower();
                            }
                        }
                    }
                    else // vanilla condition but for enemy controlling your crew with MIND_ORDER
                    {
                        if (iShipId == 0 && crewTarget && CanFight() && crewTarget->IsCrew() && HasSpecialPower() && ex->PowerReady() == POWER_READY &&
                            GetPowerOwner() == 1 && health.first > 0.5f*health.second)
                        {
                            if (!ship->RoomLocked(iRoomId))
                            {
                                ex->PreparePower();
                            }
                        }
                    }
                }
            }
        }

        auto aex = CMA_EX(crewAnim);

        if (aex->effectAnim != nullptr)
        {
            auto def = custom->GetDefinition(species);

            if (!aex->powerDone && powerDef->followCrew)
            {
                ex->powerShip = currentShipId;
                ex->powerRoom = iRoomId;
                aex->effectPos = Pointf(x - aex->effectAnim->info.frameWidth / 2, y - aex->effectAnim->info.frameHeight / 2 + PositionShift());
                aex->effectWorldPos = Pointf(x, y);
            }

            aex->effectAnim->Update();

            // Do it this way since ActivatePower() might delete aex if the crewmember transforms into a different race.
            bool activateTemporaryPower = !aex->temporaryPowerActive && powerDef->tempPower.animFrame != -1 && aex->effectAnim->tracker.running && aex->effectAnim->currentFrame == powerDef->tempPower.animFrame;

            if (!aex->powerDone && powerDef->animFrame != -1 && aex->effectAnim->tracker.running && aex->effectAnim->currentFrame == powerDef->animFrame)
            {
                ex->ActivatePower();
                aex = CMA_EX(crewAnim);
            }

            if (activateTemporaryPower)
            {
                ex->ActivateTemporaryPower();
            }
        }
        if (aex->tempEffectAnim != nullptr)
        {
            aex->tempEffectAnim->Update();
        }
        if (aex->effectFinishAnim != nullptr)
        {
            aex->effectFinishAnim->Update();
        }
    }
}

HOOK_METHOD(CrewMember, SaveState, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::SaveState -> Begin (CustomCrew.cpp)\n")
    auto ex = CM_EX(this);

    FileHelper::writeFloat(file, ex->selfId);

    FileHelper::writeFloat(file, health.first);
    FileHelper::writeFloat(file, health.second);

    FileHelper::writeInt(file, ex->noSlot);

    // Passive Heal
    if (ex->passiveHealTimer != nullptr)
    {
        FileHelper::writeFloat(file, ex->passiveHealTimer->currGoal);
        FileHelper::writeFloat(file, ex->passiveHealTimer->currTime);
    }
    else
    {
        FileHelper::writeFloat(file, -1.f);
        FileHelper::writeFloat(file, -1.f);
    }

    // Death Timer
    if (ex->deathTimer != nullptr)
    {
        FileHelper::writeFloat(file, ex->deathTimer->currGoal);
        FileHelper::writeFloat(file, ex->deathTimer->currTime);
    }
    else
    {
        FileHelper::writeFloat(file, -1.f);
        FileHelper::writeFloat(file, -1.f);
    }

    FileHelper::writeFloat(file, ex->powerCooldown.first);
    FileHelper::writeFloat(file, ex->powerCooldown.second);
    FileHelper::writeFloat(file, ex->temporaryPowerDuration.first);
    FileHelper::writeFloat(file, ex->temporaryPowerDuration.second);
    FileHelper::writeInt(file, ex->powerCharges.first);
    FileHelper::writeInt(file, ex->powerCharges.second);
    FileHelper::writeInt(file, ex->temporaryPowerActive);
    FileHelper::writeInt(file, ex->powerDefIdx);
    FileHelper::writeString(file, ex->originalColorRace);
    FileHelper::writeString(file, ex->originalRace);

    // Timed augment stat boosts
    std::vector<StatBoost*> timedStatBoostsSerial;
    for (auto& vStatBoost : ex->timedStatBoosts)
    {
        for (auto& statBoost : vStatBoost.second)
        {
            timedStatBoostsSerial.push_back(&statBoost);
        }
    }

    FileHelper::writeInt(file, timedStatBoostsSerial.size());
    for (auto statBoost : timedStatBoostsSerial)
    {
        FileHelper::writeInt(file, statBoost->def->realBoostId);
        FileHelper::writeInt(file, statBoost->iStacks);
        FileHelper::writeInt(file, statBoost->sourceShipId);
        FileHelper::writeFloat(file, statBoost->timerHelper.currGoal);
        FileHelper::writeFloat(file, statBoost->timerHelper.currTime);
    }

    super(file);

}

HOOK_METHOD(CrewMember, LoadState, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::LoadState -> Begin (CustomCrew.cpp)\n")
    auto ex = CM_EX(this);
    auto aex = CMA_EX(crewAnim);

    ex->selfId = FileHelper::readFloat(file);

    std::pair<float,float> customHealth;

    customHealth.first = FileHelper::readFloat(file);
    customHealth.second = FileHelper::readFloat(file);

    ex->noSlot = FileHelper::readInteger(file);

    // Passive Heal
    float timerGoal = FileHelper::readFloat(file);
    if (timerGoal != -1.f)
    {
        if (ex->passiveHealTimer == nullptr)
        {
            ex->passiveHealTimer = new TimerHelper(false);
        }
        ex->passiveHealTimer->Start(timerGoal);
        ex->passiveHealTimer->currTime = FileHelper::readFloat(file);
    }
    else
    {
        FileHelper::readFloat(file);
    }

    // Death Timer
    timerGoal = FileHelper::readFloat(file);
    if (timerGoal != -1.f)
    {
        if (ex->deathTimer == nullptr)
        {
            ex->deathTimer = new TimerHelper(false);
        }
        ex->deathTimer->Start(timerGoal);
        ex->deathTimer->currTime = FileHelper::readFloat(file);
    }
    else
    {
        FileHelper::readFloat(file);
    }

    ex->powerCooldown.first = FileHelper::readFloat(file);
    ex->powerCooldown.second = FileHelper::readFloat(file);
    ex->temporaryPowerDuration.first = FileHelper::readFloat(file);
    ex->temporaryPowerDuration.second = FileHelper::readFloat(file);
    ex->powerCharges.first = FileHelper::readInteger(file);
    ex->powerCharges.second = FileHelper::readInteger(file);
    ex->temporaryPowerActive = FileHelper::readInteger(file);
    ex->powerDefIdx = FileHelper::readInteger(file);
    ex->originalColorRace = FileHelper::readString(file);
    ex->originalRace = FileHelper::readString(file);

    // Timed augment stat boosts
    int timedStatBoostsSize = FileHelper::readInteger(file);

    for (int i=0; i<timedStatBoostsSize; ++i)
    {
        StatBoost statBoost(StatBoostDefinition::statBoostDefs.at(FileHelper::readInteger(file)));
        statBoost.iStacks = FileHelper::readInteger(file);
        statBoost.sourceShipId = FileHelper::readInteger(file);

        if (statBoost.def->duration != -1.f)
        {
            statBoost.timerHelper.Start(FileHelper::readFloat(file));
            statBoost.timerHelper.currTime = FileHelper::readFloat(file);
        }
        else
        {
            statBoost.timerHelper.currGoal = FileHelper::readFloat(file);
            statBoost.timerHelper.currTime = FileHelper::readFloat(file);
            statBoost.timerHelper.running = false;
        }

        auto& vStatBoosts = ex->timedStatBoosts[statBoost.def->stat];

        vStatBoosts.push_back(statBoost);
    }

    // Transformed color choices
    if (species != ex->originalColorRace)
    {
        auto bpM = G_->GetBlueprints();
        auto it = bpM->crewBlueprints.find(ex->originalColorRace);
        if (it != bpM->crewBlueprints.end())
        {
            blueprint.colorLayers = it->second.colorLayers;
            blueprint.colorChoices.resize(blueprint.colorLayers.size(), -1);
            unsigned int n = std::min(blueprint.colorLayers.size(), crewAnim->layerColors.size());
            unsigned int i;
            for (i=0; i<n; ++i)
            {
                if (blueprint.colorChoices[i] < blueprint.colorLayers[i].size())
                {
                    crewAnim->layerColors[i] = blueprint.colorLayers[i][blueprint.colorChoices[i]];
                }
            }
            for (; i<crewAnim->layerColors.size(); ++i)
            {
                crewAnim->layerColors[i] = GL_Color(0.0, 0.0, 0.0, 0.0);
            }
        }
    }

    // Set up saved power definition
    if (ex->powerDefIdx >= ActivatedPowerDefinition::powerDefs.size()) ex->powerDefIdx = 0; // bounds check

    auto powerDef = ex->GetPowerDef();
    ex->hasSpecialPower = powerDef->hasSpecialPower;
    ex->hasTemporaryPower = powerDef->hasTemporaryPower;
    aex->PreparePower(powerDef);
    aex->temporaryPowerActive = ex->temporaryPowerActive;

    if (aex->tempEffectAnim != nullptr && aex->temporaryPowerActive)
    {
        aex->tempEffectAnim->SetCurrentFrame(0);
        aex->tempEffectAnim->tracker.SetLoop(true, 0);
        aex->tempEffectAnim->Start(true);
    }

    super(file);

    health = customHealth;
    ex->statCache[(unsigned int)CrewStat::MAX_HEALTH].first = health.second;
    ex->statCache[(unsigned int)CrewStat::MAX_HEALTH].second = StatBoostManager::statCacheFrame;
}

HOOK_METHOD_PRIORITY(CrewMember, GetNewGoal, 2000, () -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::GetNewGoal -> Begin (CustomCrew.cpp)\n")
    auto ex = CM_EX(this);
    CustomCrewManager *custom = CustomCrewManager::GetInstance();

    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    ex->CalculateStat(CrewStat::CAN_PHASE_THROUGH_DOORS, def, &ex->canPhaseThroughDoors);

    if (!ex->canPhaseThroughDoors) return super();

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

                    int offset = random32() % 17;
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

HOOK_METHOD(BlueprintManager, GetCrewBlueprint, (const std::string &name) -> CrewBlueprint)
{
    LOG_HOOK("HOOK_METHOD -> BlueprintManager::GetCrewBlueprint -> Begin (CustomCrew.cpp)\n")
    std::vector<std::string> blueprintList = this->GetBlueprintList(name);
    if (blueprintList.empty())
    {
        return super(name);
    }
    else
    {
        return super(blueprintList[random32()%blueprintList.size()]);
    }
}

HOOK_METHOD(ShipManager, AddCrewMemberFromString, (const std::string& name, const std::string& race, bool intruder, int roomId, bool init, bool male) -> CrewMember*)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::AddCrewMemberFromString -> Begin (CustomCrew.cpp)\n")
    std::string actualRace = race;
    std::vector<std::string> blueprintList = G_->GetBlueprints()->GetBlueprintList(actualRace);

    while (!blueprintList.empty())
    {
        actualRace = blueprintList[random32()%blueprintList.size()];
        blueprintList = G_->GetBlueprints()->GetBlueprintList(actualRace);
    }

    return super(name, actualRace, intruder, roomId, init, male);
}

HOOK_METHOD(CompleteShip, AddCrewMember1, (const std::string &race, const std::string &name, bool hostile) -> CrewMember*)
{
    LOG_HOOK("HOOK_METHOD -> CompleteShip::AddCrewMember1 -> Begin (CustomCrew.cpp)\n")
    std::vector<std::string> blueprintList = G_->GetBlueprints()->GetBlueprintList(race);
    if (blueprintList.empty())
    {
        return super(race, name, hostile);
    }
    else
    {
        return AddCrewMember1(blueprintList[random32()%blueprintList.size()], name, hostile);
    }
}

HOOK_METHOD(CrewMemberFactory, CreateCrewMember, (CrewBlueprint* bp, int shipId, bool intruder) -> CrewMember*)
{
    LOG_HOOK("HOOK_METHOD -> CrewMemberFactory::CreateCrewMember -> Begin (CustomCrew.cpp)\n")
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
    LOG_HOOK("HOOK_STATIC -> CrewMemberFactory::IsRace -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    if (custom->IsRace(race))
        return true;
    return super(race);
}

HOOK_METHOD(CrewAnimation, GetDeathSound, () -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> CrewAnimation::GetDeathSound -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    std::string ret = super();

    if (custom->IsRace(this->race))
    {
        auto def = custom->GetDefinition(this->race);

        std::vector<std::string>& deathSounds = this->bMale ? def->deathSounds : def->deathSoundsFemale;

        if (deathSounds.size() > 0)
        {
            int rng = random32();

            ret.assign(deathSounds[rng % deathSounds.size()]);

            return ret;
        }
    }

    return ret;
}

HOOK_METHOD(RockAnimation, GetDeathSound, () -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> RockAnimation::GetDeathSound -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    std::string ret = super();

    if (custom->IsRace(this->race))
    {
        auto def = custom->GetDefinition(this->race);

        std::vector<std::string>& deathSounds = this->bMale ? def->deathSounds : def->deathSoundsFemale;

        if (deathSounds.size() > 0)
        {
            int rng = random32();

            ret.assign(deathSounds[rng % deathSounds.size()]);

            return ret;
        }
    }

    return ret;
}

HOOK_METHOD(MantisAnimation, GetDeathSound, () -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> MantisAnimation::GetDeathSound -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    std::string ret = super();

    if (custom->IsRace(this->race))
    {
        auto def = custom->GetDefinition(this->race);

        std::vector<std::string>& deathSounds = this->bMale ? def->deathSounds : def->deathSoundsFemale;

        if (deathSounds.size() > 0)
        {
            int rng = random32();

            ret.assign(deathSounds[rng % deathSounds.size()]);

            return ret;
        }
    }

    return ret;
}

HOOK_METHOD(CrewAnimation, GetShootingSound, () -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> CrewAnimation::GetShootingSound -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    std::string ret = super();

    if (custom->IsRace(this->race))
    {
        auto def = custom->GetDefinition(this->race);

        if (def->shootingSounds.size() > 0)
        {
            int rng = random32();

            ret.assign(def->shootingSounds[rng % def->shootingSounds.size()]);

            return ret;
        }
    }

    return ret;
}

HOOK_METHOD(RockAnimation, GetShootingSound, () -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> RockAnimation::GetShootingSound -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    std::string ret = super();

    if (custom->IsRace(this->race))
    {
        auto def = custom->GetDefinition(this->race);

        if (def->shootingSounds.size() > 0)
        {
            int rng = random32();

            ret.assign(def->shootingSounds[rng % def->shootingSounds.size()]);

            return ret;
        }
    }

    return ret;
}

HOOK_METHOD(MantisAnimation, GetShootingSound, () -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> MantisAnimation::GetShootingSound -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    std::string ret = super();

    if (custom->IsRace(this->race))
    {
        auto def = custom->GetDefinition(this->race);

        if (def->shootingSounds.size() > 0)
        {
            int rng = random32();

            ret.assign(def->shootingSounds[rng % def->shootingSounds.size()]);

            return ret;
        }
    }

    return ret;
}

HOOK_METHOD(CrewMember, GetUniqueRepairing, () -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::GetUniqueRepairing -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    std::string ret = super();

    if (custom->IsRace(this->species))
    {
        auto def = custom->GetDefinition(this->species);

        if (def->repairSounds.size() > 0 && def->repairSoundFrame == -1)
        {
            int rng = random32();

            ret.assign(def->repairSounds[rng % def->repairSounds.size()]);


            return ret;
        }
        else
        {
            ret.assign("");
            return ret;
        }
    }

    return ret;
}

HOOK_METHOD(OxygenSystem, EmptyOxygen, (int roomId) -> void)
{
    LOG_HOOK("HOOK_METHOD -> OxygenSystem::EmptyOxygen -> Begin (CustomCrew.cpp)\n")
    if (!G_->GetCApp()->menu.shipBuilder.bOpen)
        return;

    return super(roomId);
}

HOOK_METHOD(ShipManager, UpdateEnvironment, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::UpdateEnvironment -> Begin (CustomCrew.cpp)\n")
    if (!G_->GetCApp()->menu.shipBuilder.bOpen && systemKey[2] != -1)
    {
        for (auto const &x: vCrewList)
        {
            auto custom = CustomCrewManager::GetInstance();

            if (custom->IsRace(x->species))
            {
                auto def = custom->GetDefinition(x->species);
                auto ex = CM_EX(x);
                float oxygenModifier = ex->CalculateStat(CrewStat::OXYGEN_CHANGE_SPEED, def);

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
    LOG_HOOK("HOOK_METHOD -> CrewMember::ApplyDamage -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    if (custom->IsRace(species))
    {
        auto def = custom->GetDefinition(species);
        auto ex = CM_EX(this);
        float damageTakenMultiplier = ex->CalculateStat(CrewStat::DAMAGE_TAKEN_MULTIPLIER, def);

        damage = damage * (damageTakenMultiplier);
    }

    return super(damage);
}


static bool crewDetectLifeforms = false;

HOOK_METHOD(ShipManager, OnRender, (bool unk1, bool unk2) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnRender -> Begin (CustomCrew.cpp)\n")
    crewDetectLifeforms = true;
    super(unk1, unk2);
    crewDetectLifeforms = false;
}

HOOK_METHOD(CombatControl, CanTargetSelf, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::CanTargetSelf -> Begin (CustomCrew.cpp)\n")
    crewDetectLifeforms = true;
    bool ret = super();
    crewDetectLifeforms = false;

    return ret;
}

HOOK_METHOD(CombatControl, UpdateTarget, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::UpdateTarget -> Begin (CustomCrew.cpp)\n")
    crewDetectLifeforms = true;
    bool ret = super();
    crewDetectLifeforms = false;

    return ret;
}

HOOK_METHOD(ShipObject, HasEquipment, (const std::string& name) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipObject::HasEquipment -> Begin (CustomCrew.cpp)\n")
    if (name == "slug" && crewDetectLifeforms)
    {
        auto custom = CustomCrewManager::GetInstance();

        std::vector<CrewMember*> vCrewList;

        auto world = G_->GetWorld();

        ShipManager *playerShip = world->playerShip->shipManager;
        ShipManager *enemyShip = world->playerShip->enemyShip ? world->playerShip->enemyShip->shipManager : nullptr;

        if (playerShip != nullptr)
        {
            vCrewList.insert(vCrewList.end(), playerShip->vCrewList.begin(), playerShip->vCrewList.end());
        }
        if (enemyShip != nullptr)
        {
            vCrewList.insert(vCrewList.end(), enemyShip->vCrewList.begin(), enemyShip->vCrewList.end());
        }


        for (auto i : vCrewList)
        {
            if (custom->IsRace(i->species))
            {
                auto def = custom->GetDefinition(i->species);
                auto ex = CM_EX(i);

                if (i->iShipId == iShipId)
                {
//                        if (HasAugmentation("ALL_CREW_DETECT_LIFEFORMS"))
//                        {
//                            return GetAugmentationValue("ALL_CREW_DETECT_LIFEFORMS");
//                        }
                    bool detectsLifeforms;
                    ex->CalculateStat(CrewStat::DETECTS_LIFEFORMS, def, &detectsLifeforms);
                    if (detectsLifeforms && i->Functional())
                    {
                        return 1;
                    }
                }
            }
            else if (i->species == "slug") return 1;
        }

        return 0;
    }

    return super(name);
}

HOOK_METHOD(ShipSystem, SetPowerLoss, (int powerLoss) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::SetPowerLoss -> Begin (CustomCrew.cpp)\n")
    int ret = super(powerLoss);

    SYS_EX(this)->oldPowerLoss = powerLoss;

    return ret;
}

static bool blockClearStatus = false;

HOOK_METHOD(WorldManager, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::OnLoop -> Begin (CustomCrew.cpp)\n")
    super();


    if (!HostileEnvironment() && ships.size() == 0)
    {
        playerShip->shipManager->ClearStatusSystem(2);
        playerShip->shipManager->ClearStatusSystem(6);
        playerShip->shipManager->ClearStatusSystem(1);
    }
}

HOOK_METHOD(ShipManager, ClearStatusSystem, (int sys) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ClearStatusSystem -> Begin (CustomCrew.cpp)\n")
    if (blockClearStatus) return;

    super(sys);
}

HOOK_METHOD(ShipSystem, ClearStatus, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::ClearStatus -> Begin (CustomCrew.cpp)\n")
    SYS_EX(this)->oldPowerLoss = 0;
    super();

    //iTempPowerLoss = SYS_EX(this)->additionalPowerLoss;
}

HOOK_METHOD(ShipManager, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnLoop -> Begin (CustomCrew.cpp)\n")
    super();

    for (auto i : vSystemList)
    {
        ShipSystem_Extend* sys_ex = SYS_EX(i);

        sys_ex->additionalPowerLoss = 0;
    }

    auto custom = CustomCrewManager::GetInstance();

    for (auto i : vCrewList)
    {
        if (custom->IsRace(i->species))
        {
            auto def = custom->GetDefinition(i->species);
            CustomCrewManager *custom = CustomCrewManager::GetInstance();

            auto ex = CM_EX(i);
            int powerDrain = i->Functional() ? ex->CalculateStat(CrewStat::POWER_DRAIN, def) : 0;

            ShipSystem* sys = GetSystemInRoom(i->iRoomId);

            if (sys && sys->iSystemType != SYS_PILOT)
            {
                bool powerDrainFriendly = false;
                ex->CalculateStat(CrewStat::POWER_DRAIN_FRIENDLY, def, &powerDrainFriendly);
                if (i->intruder || powerDrainFriendly)
                {
                    ShipSystem_Extend* sys_ex = SYS_EX(sys);

                    sys_ex->additionalPowerLoss += powerDrain;
                }
            }

            if (def->changeIfSame)
            {
                int counter = 0;
                for (auto name : def->transformName)
                {
                    if (i->blueprint.crewNameLong.GetText() == name) // this is stupid
                    {
                        std::string newSpecies = def->nameRace.at(counter);
                        ++counter;

                        ex->originalRace = newSpecies;
                        ex->TransformRace(newSpecies);
                    }
                }
            }
            else
            {
                bool change = true;
                for (auto check : def->transformName)
                {
                    if (i->blueprint.crewNameLong.GetText() != check)
                    {
                        change = false;
                    }
                }
                if (change)
                {
                    std::string newSpecies = def->nameRace.at(0);

                    ex->originalRace = newSpecies;
                    ex->TransformRace(newSpecies);
                }
            }

            ex->CalculateStat(CrewStat::TRANSFORM_RACE, def);
            if (ex->transformRace != i->species) ex->TransformRace(ex->transformRace);
        }
    }

    for (auto i : vSystemList)
    {
        ShipSystem_Extend* sys_ex = SYS_EX(i);

        /*
        i->iTempPowerLoss = sys_ex->oldPowerLoss + sys_ex->additionalPowerLoss;
        int maxPowerLoss = i->powerState.second - (i->healthState.second - i->healthState.first);
        if (i->iTempPowerLoss >= maxPowerLoss)
        {
            i->iTempPowerLoss = maxPowerLoss;
        }
        */

        i->CheckMaxPower();
        i->CheckForRepower();
    }
}

HOOK_METHOD(ShipSystem, GetMaxPower, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::GetMaxPower -> Begin (CustomCrew.cpp)\n")
    ShipSystem_Extend* sys_ex = SYS_EX(this);
    iTempPowerLoss = sys_ex->oldPowerLoss + sys_ex->additionalPowerLoss;
    int maxPowerLoss = powerState.second - (healthState.second - healthState.first);
    if (iTempPowerLoss > maxPowerLoss) iTempPowerLoss = maxPowerLoss;
    return super();
}

HOOK_METHOD(ShipSystem, CheckMaxPower, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::CheckMaxPower -> Begin (CustomCrew.cpp)\n")
    ShipSystem_Extend* sys_ex = SYS_EX(this);
    iTempPowerLoss = sys_ex->oldPowerLoss + sys_ex->additionalPowerLoss;
    int maxPowerLoss = powerState.second - (healthState.second - healthState.first);
    if (iTempPowerLoss > maxPowerLoss) iTempPowerLoss = maxPowerLoss;
    super();
}

HOOK_METHOD(ShipSystem, CheckForRepower, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::CheckForRepower -> Begin (CustomCrew.cpp)\n")
    ShipSystem_Extend* sys_ex = SYS_EX(this);
    iTempPowerLoss = sys_ex->oldPowerLoss + sys_ex->additionalPowerLoss;
    int maxPowerLoss = powerState.second - (healthState.second - healthState.first);
    if (iTempPowerLoss > maxPowerLoss) iTempPowerLoss = maxPowerLoss;
    super();
}

HOOK_METHOD(ShipSystem, AddDamage, (int amount) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::AddDamage -> Begin (CustomCrew.cpp)\n")
    int newHealth = std::max(0, std::min(healthState.first - amount, healthState.second));

    ShipSystem_Extend* sys_ex = SYS_EX(this);
    iTempPowerLoss = sys_ex->oldPowerLoss + sys_ex->additionalPowerLoss;
    int maxPowerLoss = powerState.second - (healthState.second - newHealth);
    if (iTempPowerLoss > maxPowerLoss) iTempPowerLoss = maxPowerLoss;

    super(amount);
}

HOOK_METHOD(ShipSystem, DamageOverTime, (float speed) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::DamageOverTime -> Begin (CustomCrew.cpp)\n")
    auto ret = super(speed);
    if (ret)
    {
        int maxPowerLoss = powerState.second - (healthState.second - healthState.first);
        if (iTempPowerLoss > maxPowerLoss)
        {
            iTempPowerLoss = maxPowerLoss;
            iBonusPower = 0;
        }
    }
    return ret;
}

HOOK_METHOD(ShipSystem, PartialRepair, (float speed, bool autoRepair) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::PartialRepair -> Begin (CustomCrew.cpp)\n")
    auto ret = super(speed, autoRepair);
    if (ret)
    {
        ShipSystem_Extend* sys_ex = SYS_EX(this);
        iTempPowerLoss = sys_ex->oldPowerLoss + sys_ex->additionalPowerLoss;
        int maxPowerLoss = powerState.second - (healthState.second - healthState.first);
        if (iTempPowerLoss > maxPowerLoss) iTempPowerLoss = maxPowerLoss;
    }
    return ret;
}


HOOK_METHOD(CrewMember, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::OnLoop -> Begin (CustomCrew.cpp)\n")
    super();

    auto custom = CustomCrewManager::GetInstance();

    if (custom->IsRace(species))
    {
        auto ex = CM_EX(this);
        auto def = custom->GetDefinition(this->species);

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

        /*
        if (!ex->timedStatBoosts.empty())
        {
            int counter = 0;
            for (StatBoost statBoost : ex->timedStatBoosts)
            {
                if (statBoost.timerHelper)
                {
                    statBoost.timerHelper->Update();
                    if (statBoost.timerHelper->Done())
                    {
                        ex->timedStatBoosts.erase(ex->timedStatBoosts.begin() + counter);
                    }
                }
                else
                {
                    if (statBoost.duration != -1)
                    {
                        statBoost.timerHelper = new TimerHelper();
                        statBoost.timerHelper->Start(statBoost.duration);
                    }
                    else
                    {
                        // the "timed" stat boost is actually permanent
                    }
                }
            }
            ++counter;
        }
        */
    }
}

bool shipFriendlyFire = true;
bool blockDamageArea = false;

// We can't return just Damage (since it's a hidden parameter) like we could in the static variant, so reverse the logic and only return ANYTHING if we should, otherwise let the functions fall through and the stack will be unmodified.
HOOK_METHOD(IonDrone, GetRoomDamage, () -> Damage)
{
    LOG_HOOK("HOOK_METHOD -> IonDrone::GetRoomDamage -> Begin (CustomCrew.cpp)\n")
    if (!blockDamageArea)
        return super();
    return Damage();
}
HOOK_METHOD(EnergyAlien, GetRoomDamage, () -> Damage)
{
    LOG_HOOK("HOOK_METHOD -> EnergyAlien::GetRoomDamage -> Begin (CustomCrew.cpp)\n")
    if (!blockDamageArea)
        return super();
    return Damage();
}

HOOK_METHOD(CrewMember, GetRoomDamage, () -> Damage)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::GetRoomDamage -> Begin (CustomCrew.cpp)\n")
    Damage ret = super();

    auto custom = CustomCrewManager::GetInstance();
    if (!blockDamageArea)
    {
        if (custom->IsRace(this->species))
        {
            auto ex = CM_EX(this);

            if (ex->triggerExplosion && !ex->exploded)
            {
                ex->exploded = true;

                auto def = custom->GetDefinition(this->species);
                ex->CalculateStat(CrewStat::DEATH_EFFECT, def);

                if (ex->hasDeathExplosion)
                {
                    ExplosionDefinition *explosionDef = &ex->deathEffectChange;
                    Damage *customDamage = &explosionDef->damage;

                    ret.iDamage = customDamage->iDamage;
                    ret.fireChance = customDamage->fireChance;
                    ret.breachChance = customDamage->breachChance;
                    ret.stunChance = customDamage->stunChance;
                    ret.iIonDamage = customDamage->iIonDamage;
                    ret.iSystemDamage = customDamage->iSystemDamage;
                    ret.iPersDamage = customDamage->iPersDamage;
                    ret.bHullBuster = customDamage->bHullBuster;
                    ret.ownerId = this->GetPowerOwner();
                    ret.selfId = ex->selfId;
                    ret.bLockdown = customDamage->bLockdown;
                    ret.crystalShard = customDamage->crystalShard;
                    ret.bFriendlyFire = customDamage->bFriendlyFire;
                    ret.iStun = customDamage->iStun;
                    shipFriendlyFire = explosionDef->shipFriendlyFire;

                    if (!explosionDef->statBoosts.empty())
                    {
                        for (auto i=0; i<2; ++i)
                        {
                            ShipManager *crewShip = G_->GetShipManager(i);
                            if (crewShip)
                            {
                                for (auto otherCrew : crewShip->vCrewList)
                                {
                                    for (auto statBoostDef : explosionDef->statBoosts)
                                    {
                                        StatBoost statBoost(statBoostDef);
                                        statBoost.crewSource = this;
                                        statBoost.sourceShipId = this->iShipId;
                                        StatBoostManager::GetInstance()->CreateTimedAugmentBoost(statBoost, otherCrew);
                                    }
                                }
                            }
                        }
                    }
                    if (!explosionDef->crewSpawns.empty())
                    {
                        ShipManager *crewShip = G_->GetShipManager(this->currentShipId);
                        if (crewShip)
                        {
                            for (CrewSpawn* i : explosionDef->crewSpawns)
                            {
                                CrewSpawn::SpawnCrew(i, crewShip, this->currentShipId != this->iShipId, Pointf(this->x, this->y));
                            }
                        }
                    }
                    if (!explosionDef->event[this->iShipId].empty())
                    {
                        CustomEventsParser::QueueEvent(explosionDef->event[this->iShipId], -1);
                    }
                }
            }
        }
        else
        {
            // WARNING: Potential bug during migration to non-static methods!
            if (this->species == "energy")
            {
                ret = ((EnergyAlien*) this)->GetRoomDamage(); // TODO: Problematic, TODO: Should this just be super, but we already ran super?
            }
        }


        // WARNING: Potential bug during migration to non-static methods!
        if (CM_EX(this)->isIonDrone)
        {
            ret = ((IonDrone*) this)->GetRoomDamage(); // TODO: Problematic, TODO: Should this just be super, but we already ran super?
        }
    }

    return ret;
}

HOOK_METHOD(ShipManager, UpdateCrewMembers, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::UpdateCrewMembers -> Begin (CustomCrew.cpp)\n")
    blockDamageArea = true;
    super();
    blockDamageArea = false;


    CustomCrewManager *custom = CustomCrewManager::GetInstance();

    for (auto i : vCrewList)
    {
        Damage dmgI = i->GetRoomDamage();
        Damage *dmg = &dmgI;

        if (dmg->ownerId != -1) DamageArea(Pointf(i->x, i->y), *((DamageParameter*)dmg), true);

        if (custom->IsRace(i->species))
        {
            int ownerShip = i->GetPowerOwner();
            auto def = custom->GetDefinition(i->species);

            auto ex = CM_EX(i);
            if (i->iRoomId != -1)
            {
                // damageEnemiesAmount/healEnemiesAmount time dilation/temporal system
                // Didn't want to do this here but I don't think I have a choice
                float timeDilation = TemporalSystemParser::GetDilationStrength(RM_EX(ship.vRoomList[i->iRoomId])->timeDilation);

                float damageEnemies = ex->CalculateStat(CrewStat::DAMAGE_ENEMIES_AMOUNT, def) * G_->GetCFPS()->GetSpeedFactor() * 0.06245f * timeDilation;

                if (i->Functional() && damageEnemies != 0.f)
                {
                    for (auto crew : vCrewList)
                    {
                        if (crew->iRoomId == i->iRoomId && crew->iShipId != ownerShip)
                        {
                            crew->DirectModifyHealth(-damageEnemies);
                        }
                    }
                }
                float healCrewAmount = ex->CalculateStat(CrewStat::HEAL_CREW_AMOUNT, def);

                if (i->Functional() && healCrewAmount != 0.f)
                {
                    float healCrew = G_->GetCFPS()->GetSpeedFactor() * healCrewAmount * 0.06245f * timeDilation;

                    for (auto crew : vCrewList)
                    {
                        if (crew->iRoomId == i->iRoomId && crew->iShipId == ownerShip && crew != i)
                        {
                            if (healCrew > 0.f && crew->health.first != crew->health.second)
                            {
                                crew->fMedbay += 0.0000000001;
                            }
                            crew->DirectModifyHealth(healCrew);
                        }
                    }
                }
            }

            if (ex->powerActivated)
            {
                ShipManager* actualShip = this;
                if (ex->powerShip != iShipId)
                {
                    actualShip = current_target;
                    if (actualShip == nullptr)
                    {
                        actualShip = ex->powerShip ? (G_->GetWorld()->playerShip->enemyShip ? G_->GetWorld()->playerShip->enemyShip->shipManager : nullptr) : G_->GetWorld()->playerShip->shipManager;
                    }
                }

                if (actualShip)
                {
                    Damage* dmg = ex->GetPowerDamage();

                    shipFriendlyFire = ex->GetPowerDef()->shipFriendlyFire;
                    actualShip->DamageArea(CMA_EX(i->crewAnim)->effectWorldPos, *((DamageParameter*)dmg), true);

                    delete dmg;
                }
                ex->powerActivated = false;
            }
        }
    }
}


HOOK_METHOD(ShipManager, DamageCrew, (CrewMember *crew, DamageParameter dmgParameter) -> char)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::DamageCrew -> Begin (CustomCrew.cpp)\n")
    Damage* dmg = (Damage*)&dmgParameter;

    if (dmg->selfId == CM_EX(crew)->selfId)
    {
        return false;
    }

    return super(crew, dmgParameter);
}

HOOK_METHOD_PRIORITY(ShipManager, DamageArea, -1000, (Pointf location, DamageParameter damageParameter, bool forceHit) -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::DamageArea -> Begin (CustomCrew.cpp)\n")
    if (blockDamageArea) return false;
    Damage* dmg = (Damage*)&damageParameter;

    if (!shipFriendlyFire)
    {
        shipFriendlyFire = true;

        if (dmg->ownerId == iShipId)
        {
            int roomId = ship.GetSelectedRoomId(location.x, location.y, true);

            if (roomId == -1)
                return false;

            if (!bJumping)
            {
                for (auto i : vCrewList)
                {
                    if (i->iRoomId == roomId)
                    {
                        DamageCrew(i, damageParameter);
                    }
                }
            }

            return true;
        }
    }

    return super(location, damageParameter, forceHit);
}

HOOK_METHOD(CrewBox, constructor, (Point pos, CrewMember *crew, int number) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewBox::constructor -> Begin (CustomCrew.cpp)\n")
    super(pos, crew, number);

    auto custom = CustomCrewManager::GetInstance();
    if (custom->IsRace(crew->species))
    {
        auto ex = CM_EX(crew);
        auto powerDef = ex->GetPowerDef();

        if (powerDef->hasSpecialPower)
        {
            if (!powerDef->buttonLabel.data.empty())
            {
                powerButton.label = powerDef->buttonLabel;
            }

            if (powerDef->powerCharges > 0)
            {
                GL_Color boxColor = GL_Color();
                boxColor.r = 1.0f;
                boxColor.g = 1.0f;
                boxColor.b = 1.0f;
                boxColor.a = 1.0f;

                CSurface::GL_DestroyPrimitive(boxBackground);
                boxBackground = CSurface::GL_CreateRectPrimitive(box.x-8, box.y, box.w+7, box.h, boxColor);

                CSurface::GL_DestroyPrimitive(skillBoxBackground);

                std::vector<Globals::Rect> boxRects = std::vector<Globals::Rect>();
                boxRects.push_back({box.x-8, box.y, box.w+90, box.h});
                boxRects.push_back({box.x+box.w+3, box.y+box.h, 80, skillBox.h-box.h});

                skillBoxBackground = CSurface::GL_CreateMultiRectPrimitive(boxRects, boxColor);

                boxColor.a = 1.0f;

                CSurface::GL_DestroyPrimitive(boxOutline);

                std::vector<GL_Line> boxLines = std::vector<GL_Line>();
                boxLines.emplace_back(Pointf(box.x-8, box.y+1), Pointf(box.x+box.w, box.y+1)); //top
                boxLines.emplace_back(Pointf(box.x-8, box.y+box.h-1), Pointf(box.x+box.w, box.y+box.h-1)); //bottom
                boxLines.emplace_back(Pointf(box.x-7, box.y), Pointf(box.x-7, box.y+box.h)); //left
                boxLines.emplace_back(Pointf(box.x-1, box.y), Pointf(box.x-1, box.y+box.h)); //right of charge bar
                boxLines.emplace_back(Pointf(box.x+6, box.y), Pointf(box.x+6, box.y+box.h)); //right of cooldown bar
                boxLines.emplace_back(Pointf(box.x+box.w-1, box.y), Pointf(box.x+box.w-1, box.y+box.h)); //right

                boxOutline = CSurface::GL_CreateMultiLinePrimitive(boxLines, boxColor, 2);

                CSurface::GL_DestroyPrimitive(skillBoxOutline);

                boxLines = std::vector<GL_Line>();
                boxLines.emplace_back(Pointf(box.x-8, box.y+1), Pointf(skillBox.x+skillBox.w-1, box.y+1)); //top
                boxLines.emplace_back(Pointf(box.x-8, box.y+box.h-1), Pointf(box.x+box.w+5, box.y+box.h-1)); //bottom of box
                boxLines.emplace_back(Pointf(box.x-7, box.y), Pointf(box.x-7, box.y+box.h)); //left
                boxLines.emplace_back(Pointf(box.x-1, box.y), Pointf(box.x-1, box.y+box.h)); //right of charge bar
                boxLines.emplace_back(Pointf(box.x+6, box.y), Pointf(box.x+6, box.y+box.h)); //right of cooldown bar
                boxLines.emplace_back(Pointf(box.x+box.w+4, box.y+box.h), Pointf(box.x+box.w+4, skillBox.y+skillBox.h)); //left of skillBox
                boxLines.emplace_back(Pointf(box.x+box.w+3, box.y+skillBox.h-1), Pointf(skillBox.x+skillBox.w, box.y+skillBox.h-1)); //bottom of skillBox
                boxLines.emplace_back(Pointf(skillBox.x+skillBox.w-1, skillBox.y), Pointf(skillBox.x+skillBox.w-1, skillBox.y+skillBox.h)); //right of skillBox

                skillBoxOutline = CSurface::GL_CreateMultiLinePrimitive(boxLines, boxColor, 2);
            }
        }
    }
}

HOOK_METHOD_PRIORITY(CrewBox, OnRender, 1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewBox::OnRender -> Begin (CustomCrew.cpp)\n")
    //return super();
    mindControlled.Update();
    stunned.Update();

    auto crew = pCrew;
    auto health = crew->health;
    if (health.first > 25.f || health.first == 0.f || std::floor(health.first) == std::floor(health.second))
    {
        flashHealthTracker.Stop(false);
    }

    if (number < 0)
    {
        return;
    }

    GL_Color boxColor = GL_Color();
    GL_Color boxOutlineColor;
    if (!crew->bMindControlled)
    {
        if (!bSelectable)
        {
            boxColor.r = 0.494f;
            boxColor.g = 0.858f;
            boxColor.b = 0.882f;
        }
        else
        {
            auto selectionState = crew->selectionState;
            if (selectionState == 1)
            {
                boxColor.r = 0.47f;
                boxColor.g = 1.f;
                boxColor.b = 0.47f;
            }
            else if (crew->fStunTime > 0.f)
            {
                boxColor.r = 1.f;
                boxColor.g = 1.f;
                boxColor.b = 0.392f;
            }
            else if (selectionState == 2)
            {
                boxColor.r = 0.921f;
                boxColor.g = 0.921f;
                boxColor.b = 0.921f;
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
        }

        boxOutlineColor = boxColor;
    }
    else
    {
        if (crew->iShipId == 0)
        {
            if (!bSelectable)
            {
                boxColor.r = 0.494f;
                boxColor.g = 0.858f;
                boxColor.b = 0.882f;
            }
            else
            {
                boxColor.r = 1.f;
                boxColor.g = 0.f;
                boxColor.b = 1.f;
            }
            boxOutlineColor = boxColor;
        }
        else
        {
            if (!bSelectable)
            {
                boxColor.r = 1.f;
                boxColor.g = 0.f;
                boxColor.b = 0.f;
                boxOutlineColor.r = 0.494f;
                boxOutlineColor.g = 0.858f;
                boxOutlineColor.b = 0.882f;
            }
            else
            {
                auto selectionState = crew->selectionState;
                if (selectionState == 1)
                {
                    boxColor.r = 1.f;
                    boxColor.g = 0.47f;
                    boxColor.b = 0.47f;
                    boxOutlineColor.r = 0.47f;
                    boxOutlineColor.g = 1.f;
                    boxOutlineColor.b = 0.47f;
                }
                else if (crew->fStunTime > 0.f)
                {
                    boxColor.r = 1.f;
                    boxColor.g = 0.f;
                    boxColor.b = 0.f;
                    boxOutlineColor.r = 1.f;
                    boxOutlineColor.g = 1.f;
                    boxOutlineColor.b = 0.392f;
                }
                else if (selectionState == 2)
                {
                    boxColor.r = 1.f;
                    boxColor.g = 0.8f;
                    boxColor.b = 0.8f;
                    boxOutlineColor.r = 1.f;
                    boxOutlineColor.g = 0.8f;
                    boxOutlineColor.b = 0.8f;
                }
                else
                {
                    boxColor.r = 1.f;
                    boxColor.g = 0.f;
                    boxColor.b = 0.f;
                    boxOutlineColor.r = 0.6f;
                    boxOutlineColor.g = 0.3f;
                    boxOutlineColor.b = 0.3f;
                }
            }
        }
    }

    boxColor.a = 0.25f;
    boxOutlineColor.a = 1.f;

    if (!mouseHover)
    {
        CSurface::GL_RenderPrimitiveWithColor(boxBackground, boxColor);
        CSurface::GL_RenderPrimitiveWithColor(boxOutline, boxOutlineColor);
    }
    else
    {
        CSurface::GL_RenderPrimitiveWithColor(skillBoxBackground, boxColor);
        CSurface::GL_RenderPrimitiveWithColor(skillBoxOutline, boxOutlineColor);
    }

    if (crew->HasSpecialPower())
    {
        auto ex = CM_EX(crew);

        std::pair<float, float> cooldown;
        std::pair<int, int> charges = ex->powerCharges;

        if (ex->temporaryPowerActive)
        {
            cooldown = ex->temporaryPowerDuration;
        }
        else
        {
            cooldown = crew->GetPowerCooldown();
        }

        int cooldownHeight = std::floor((cooldown.first / cooldown.second) * (box.h - 6));

        GL_Primitive* prim = nullptr;

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
                cooldownBar = nullptr;
            }
            else
            {
                GL_Color barColor = GL_Color(133.f / 255.f, 231.f / 255.f, 237.f / 255.f, 1.f);

                if (CustomCrewManager::GetInstance()->IsRace(crew->species))
                {
                    auto powerDef = ex->GetPowerDef();

                    if (ex->temporaryPowerActive)
                    {
                        barColor = powerDef->tempPower.cooldownColor;
                    }
                    else
                    {
                        barColor = powerDef->cooldownColor;
                    }
                }

                if (charges.second > 0)
                {
                    prim = CSurface::GL_CreateRectPrimitive(box.x + 1, (box.h - cooldownHeight) + box.y - 3, 3, cooldownHeight, barColor);
                }
                else
                {
                    prim = CSurface::GL_CreateRectPrimitive(box.x - 1, (box.h - cooldownHeight) + box.y - 3, 4, cooldownHeight, barColor);
                }

                cooldownBar = prim;
            }
        }

        if (prim)
        {
            CSurface::GL_RenderPrimitive(prim);
        }

        if (charges.first > 0)
        {
            GL_Color barColor = GL_Color(133.f / 255.f, 231.f / 255.f, 237.f / 255.f, 1.f);

            if (CustomCrewManager::GetInstance()->IsRace(crew->species))
            {
                auto powerDef = ex->GetPowerDef();

                barColor = powerDef->cooldownColor;
            }

            if (charges.second > 7)
            {
                int chargesHeight = std::max(1, (box.h - 6) * charges.first / charges.second);

                CSurface::GL_DrawRect(box.x - 5, (box.h - chargesHeight) + box.y - 3, 2, chargesHeight, barColor);
            }
            else
            {
                int chargesGap = 1;
                int chargesMaxHeight = box.h - 6 - (chargesGap * (charges.second - 1));

                int segmentHeight = chargesMaxHeight / charges.second;
                int segmentRemainder = chargesMaxHeight % charges.second;

                int y0 = 0;
                int y1 = 0;

                for (int i=0; i<charges.first; ++i)
                {
                    y1 = y0 + segmentHeight;
                    if (i < segmentRemainder) y1++;
                    CSurface::GL_DrawRect(box.x - 5, box.y + box.h - y1 - 3, 2, y1 - y0, barColor);
                    y0 = y1 + chargesGap;
                }
            }
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
        CSurface::GL_DestroyPrimitive(healthBar);

        lastHealthWidth = healthWidth;
        GL_Primitive *prim = nullptr;
        if (health.first <= 0)
        {
            healthBar = nullptr;
        }
        else
        {
            //CSurface::GL_DestroyPrimitive(healthBar);

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
    LOG_HOOK("HOOK_METHOD -> CrewBox::GetSelected -> Begin (CustomCrew.cpp)\n")
    auto ret = super(mouseX, mouseY);

    bool appendHotkey = false;

    if (CustomCrewManager::GetInstance()->IsRace(pCrew->species))
    {
        auto ex = CM_EX(pCrew);
        if (pCrew->HasSpecialPower() && mouseX < powerButton.hitbox.x + powerButton.hitbox.w && mouseX > powerButton.hitbox.x && mouseY < powerButton.hitbox.y + powerButton.hitbox.h && mouseY > powerButton.hitbox.y)
        {
            auto powerDef = ex->GetPowerDef();

            std::string tooltip = "";
            if (!pCrew->GetPowerOwner() == 0)
            {
                tooltip = G_->GetTextLibrary()->GetText("power_not_ready_mind_enemy");
            }
            else if (pCrew->PowerReady())
            {
                appendHotkey = true;
                if (!powerDef->tooltip.data.empty())
                {
                    tooltip = powerDef->tooltip.GetText();
                }
            }
            else
            {
                auto ex = CM_EX(pCrew);
                auto state = ex->PowerReady();
                auto powerReq = &powerDef->playerReq;
                if (state == POWER_NOT_READY_COOLDOWN && powerDef->chargeReq != nullptr)
                {
                    powerReq = powerDef->chargeReq;
                    state = ex->PowerReq(powerReq);
                    if (state == POWER_READY) state = POWER_NOT_READY_COOLDOWN;
                }

                std::string tooltipName = "";
                std::string replaceValue = "";


                switch (state)
                {
                case POWER_NOT_READY_COOLDOWN:
                    tooltipName = "power_not_ready";
                    break;
                case POWER_NOT_READY_ACTIVATED:
                    tooltipName = "power_not_ready_activated";
                    break;
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
                case POWER_NOT_READY_WHITELIST:
                    tooltipName = "power_not_ready_whitelist";
                    break;
                case POWER_NOT_READY_ENEMY_WHITELIST:
                    tooltipName = "power_not_ready_enemy_whitelist";
                    break;
                case POWER_NOT_READY_FRIENDLY_WHITELIST:
                    tooltipName = "power_not_ready_friendly_whitelist";
                    break;
                case POWER_NOT_READY_ENEMY_BLACKLIST:
                    tooltipName = "power_not_ready_enemy_blacklist";
                    break;
                case POWER_NOT_READY_FRIENDLY_BLACKLIST:
                    tooltipName = "power_not_ready_friendly_blacklist";
                    break;
                case POWER_NOT_READY_SYSTEM_IN_ROOM:
                    tooltipName = "power_not_ready_system_in_room";
                    break;
                case POWER_NOT_READY_SYSTEM_DAMAGED:
                    tooltipName = "power_not_ready_system_damaged";
                    break;
                case POWER_NOT_READY_AI_DISABLED:
                    tooltipName = "power_not_ready_ai_disabled";
                    break;
                case POWER_NOT_READY_HAS_CLONEBAY:
                    tooltipName = "power_not_ready_has_clonebay";
                    break;
                case POWER_NOT_READY_OUT_OF_COMBAT:
                    tooltipName = "power_not_ready_out_of_combat";
                    break;
                case POWER_NOT_READY_IN_COMBAT:
                    tooltipName = "power_not_ready_in_combat";
                    break;
                case POWER_NOT_READY_SYSTEM:
                    tooltipName = "power_not_ready_system";
                    {
                        SystemBlueprint* bp = G_->GetBlueprints()->GetSystemBlueprint(ShipSystem::SystemIdToName(powerReq->requiredSystem));
                        if (bp != nullptr) replaceValue = bp->desc.title.GetText();
                    }
                    break;
                case POWER_NOT_READY_SYSTEM_FUNCTIONAL:
                    tooltipName = "power_not_ready_system_functional";
                    {
                        SystemBlueprint* bp = G_->GetBlueprints()->GetSystemBlueprint(ShipSystem::SystemIdToName(powerReq->requiredSystem));
                        if (bp != nullptr) replaceValue = bp->desc.title.GetText();
                    }
                    break;
                case POWER_NOT_READY_MIN_HEALTH:
                    tooltipName = "power_not_ready_min_health";
                    replaceValue = boost::lexical_cast<std::string>(powerReq->minHealth.value);
                    break;
                case POWER_NOT_READY_MAX_HEALTH:
                    tooltipName = "power_not_ready_max_health";
                    replaceValue = boost::lexical_cast<std::string>(powerReq->maxHealth.value);
                    break;
                case POWER_NOT_READY_CHARGES:
                    tooltipName = "power_not_ready_charges";
                    break;
                case POWER_NOT_READY_EXTRACONDITION_OR:
                    tooltip = powerReq->extraOrConditionsTooltip.GetText();
                    break;
                default:
                    if (state >= POWER_NOT_READY_EXTRACONDITION_FALSE)
                    {
                        tooltipName = powerReadyStateExtraTextFalse[state - POWER_NOT_READY_EXTRACONDITION_FALSE];
                    }
                    else if (state >= POWER_NOT_READY_EXTRACONDITION_TRUE)
                    {
                        tooltipName = powerReadyStateExtraTextTrue[state - POWER_NOT_READY_EXTRACONDITION_TRUE];
                    }
                    break;
                }

                if (!tooltipName.empty())
                {
                    tooltip = G_->GetTextLibrary()->GetText(tooltipName);
                    if (!replaceValue.empty())
                    {
                        boost::algorithm::replace_all(tooltip, "\\1", replaceValue);
                    }
                }
            }

            if (!tooltip.empty())
            {
                sTooltip = tooltip;
            }

            if (ex->GetPowerDef()->powerCharges > -1)
            {
                auto ex = CM_EX(pCrew);
                std::string tooltip = G_->GetTextLibrary()->GetText("power_number_charges");
                boost::algorithm::replace_all(tooltip, "\\1", boost::lexical_cast<std::string>(ex->powerCharges.first));
                boost::algorithm::replace_all(tooltip, "\\2", boost::lexical_cast<std::string>(ex->powerCharges.second));
                sTooltip = sTooltip + "\n" + tooltip;
            }

            if (appendHotkey)
            {
                auto ex = CM_EX(pCrew);
                std::string tooltip = G_->GetTextLibrary()->GetText("hotkey");
                std::string replaceWith = Settings::GetHotkeyName("lockdown");
                boost::algorithm::replace_all(tooltip, "\\1", replaceWith);
                sTooltip = sTooltip + "\n" + tooltip;
            }
        }
    }

    return ret;
}

HOOK_METHOD(CrewMember, OnRender, (bool outlineOnly) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::OnRender -> Begin (CustomCrew.cpp)\n")
    super(outlineOnly);

    if (outlineOnly) return;

    auto ex = CMA_EX(crewAnim);

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(x, y);

    if (ex->tempEffectAnim != nullptr && !ex->tempEffectAnim->tracker.done && ex->tempEffectAnim->tracker.running)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(-ex->tempEffectAnim->info.frameWidth / 2, -ex->tempEffectAnim->info.frameHeight / 2);
        CSurface::GL_Translate(0, PositionShift());
        ex->tempEffectAnim->OnRender(1.f, COLOR_WHITE, false);
        CSurface::GL_PopMatrix();
    }


    for (auto boostAnim : ex->boostAnim)
    {
        if (boostAnim.second != nullptr && !boostAnim.second->tracker.done && boostAnim.second->tracker.running)
        {
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(-boostAnim.second->info.frameWidth / 2, -boostAnim.second->info.frameHeight / 2);
            CSurface::GL_Translate(0, PositionShift());
            boostAnim.second->OnRender(1.f, COLOR_WHITE, false);
            CSurface::GL_PopMatrix();
        }
    }


    CSurface::GL_PopMatrix();
}

HOOK_METHOD(CrewMember, OnRenderHealth, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::OnRenderHealth -> Begin (CustomCrew.cpp)\n")
    auto ex = CMA_EX(crewAnim);

    if (ex->effectAnim != nullptr && !ex->effectAnim->tracker.done)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(ex->effectPos.x, ex->effectPos.y);
        ex->effectAnim->OnRender(1.f, COLOR_WHITE, false);
        CSurface::GL_PopMatrix();
    }

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(x, y);

    if (ex->effectFinishAnim != nullptr && !ex->effectFinishAnim->tracker.done)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(-ex->effectFinishAnim->info.frameWidth / 2, -ex->effectFinishAnim->info.frameHeight / 2);
        ex->effectFinishAnim->OnRender(1.f, COLOR_WHITE, false);
        CSurface::GL_PopMatrix();
    }

    CSurface::GL_PopMatrix();

    super();

}

HOOK_METHOD(CrewAnimation, OnRender, (float scale, int selectedState, bool outlineOnly) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewAnimation::OnRender -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();
    auto aex = CMA_EX(this);

    if (outlineOnly || (!aex->temporaryPowerActive || (custom->IsRace(race) && aex->tempEffectBaseVisible)))
    {
        super(scale, selectedState, outlineOnly);
    }

    if (!outlineOnly && aex->temporaryPowerActive && aex->tempEffectStrip)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(lastPosition.x - 17.f, lastPosition.y - 17.f);

        anims[direction][status].SetAnimationId(aex->tempEffectStrip);
        anims[direction][status].OnRender(1.f, COLOR_WHITE, false);

        CSurface::GL_PopMatrix();
    }
}

static bool blockSetBonusPower = false;

HOOK_METHOD(ShipSystem, SetBonusPower, (int amount, int permanentPower) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::SetBonusPower -> Begin (CustomCrew.cpp)\n")
    if (blockSetBonusPower) return;

    super(amount, permanentPower);
}

HOOK_METHOD(WeaponSystem, SetBonusPower, (int amount, int permanentPower) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponSystem::SetBonusPower -> Begin (CustomCrew.cpp)\n")
    if (blockSetBonusPower) return;

    super(amount, permanentPower);
}

HOOK_METHOD(DroneSystem, SetBonusPower, (int amount, int permanentPower) -> void)
{
    LOG_HOOK("HOOK_METHOD -> DroneSystem::SetBonusPower -> Begin (CustomCrew.cpp)\n")
    if (blockSetBonusPower) return;

    super(amount, permanentPower);
}



HOOK_METHOD(ShipManager, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnLoop -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    for (auto i : vSystemList)
    {
        int bonusPowerCounter = 0;
        int permanentPowerCounter = 0;

        for (auto j : vCrewList)
        {
            if (i->roomId == j->iRoomId && j->iShipId == iShipId && j->Functional())
            {
                if (custom->IsRace(j->species))
                {
                    auto def = custom->GetDefinition(j->species);

                    auto ex = CM_EX(j);

                    int bonusPower = ex->CalculateStat(CrewStat::BONUS_POWER, def);

                    bonusPowerCounter += bonusPower;

                    if (j->AtFinalGoal() && !j->IsDrone())
                    {
                        permanentPowerCounter += bonusPower;
                    }
                }

                if (j->ProvidesPower())
                {
                    bonusPowerCounter++;
                    if (j->AtFinalGoal() && !j->IsDrone())
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

static float sabotageMultiplier = 1.f;



HOOK_METHOD(ShipSystem, PartialDamage, (float amount) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::PartialDamage -> Begin (CustomCrew.cpp)\n")
    return super(amount * sabotageMultiplier);
}


HOOK_METHOD(CrewMember, UpdateRepair, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::UpdateRepair -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();
    auto ex = CM_EX(this);
    auto def = custom->GetDefinition(this->species);
    if (custom->IsRace(species))
    {
        sabotageMultiplier = ex->CalculateStat(CrewStat::SABOTAGE_SPEED_MULTIPLIER, def);
    }

    super();

    sabotageMultiplier = 1.f;
}

static bool windowFrameCheck = false;
static int windowFrameHeight = 0;

HOOK_METHOD(WindowFrame, constructor, (int x, int y, int w, int h) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WindowFrame::constructor -> Begin (CustomCrew.cpp)\n")
    if (windowFrameCheck)
    {
        h = windowFrameHeight;
        windowFrameCheck = false;
    }

    super(x, y, w, h);
}

bool blockAnimationUpdate = false;

HOOK_METHOD(AnimationTracker, Update, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> AnimationTracker::Update -> Begin (CustomCrew.cpp)\n")
    if (blockAnimationUpdate) return;

    super();
}

HOOK_METHOD(CrewMember, OnRenderHealth, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::OnRenderHealth -> Begin (CustomCrew.cpp)\n")
    bool fullHealth = std::floor(health.first) == std::floor(health.second);

    if (fullHealth)
    {
        flashHealthTracker.SetProgress(0.5f);
        blockAnimationUpdate = true;
    }

    super();

    blockAnimationUpdate = false;

    if (fullHealth)
    {
        flashHealthTracker.Start(0.5f);
    }
}

HOOK_METHOD(CrewAI, PrioritizeIntruderRoom, (CrewMember *crew, int roomId, int target) -> int)
{
    LOG_HOOK("HOOK_METHOD -> CrewAI::PrioritizeIntruderRoom -> Begin (CustomCrew.cpp)\n")
    if (!crew->CanSabotage() && !CM_EX(crew)->isIonDrone)
    {
        if (ship->CountCrewShipId(roomId, !crew->iShipId) == 0)
        {
            return 1000;
        }
    }

    return super(crew, roomId, target);
}

HOOK_METHOD(CrewMember, Clone, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::Clone -> Begin (CustomCrew.cpp)\n")
    bool cloneLoseSkills = false;
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto def = custom->GetDefinition(this->species);

    auto ex = CM_EX(this);
    ex->CalculateStat(CrewStat::CLONE_LOSE_SKILLS, def, &cloneLoseSkills);
    if (!CustomCrewManager::GetInstance()->IsRace(species) || cloneLoseSkills) return super();

    bOutOfGame = false;
    bDead = false;
    fStunTime = 0.f;
    Restart();

    crewAnim->status = 6;
    crewAnim->direction = 0;
    crewAnim->anims[0][6].tracker.SetLoop(false, 0.f);
    crewAnim->anims[0][6].Start(true);
    crewAnim->anims[0][6].StartReverse(true);
    G_->GetSoundControl()->PlaySoundMix("cloneArrive", -1.f, false);
}

static bool needsIntruderControllable = false;

HOOK_METHOD(CrewMember, GetIntruder, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::GetIntruder -> Begin (CustomCrew.cpp)\n")
    if (needsIntruderControllable)
    {
        switch (currentShipId)
        {
        case 0:
            // Player ship version - neither intruders nor MC'd enemies will go heal, nor will controllable crew nor noAI crew.
            return (iShipId != 0) || bMindControlled || GetControllable();
        case 1:
            // Enemy ship version - intruders won't go heal, nor will controllable crew nor noAI crew. MC'd player crew will go heal.
            return super() || GetControllable();
        }
    }
    // Anywhere outside CheckForHealing
    return super();
}

HOOK_METHOD(CrewAI, CheckForHealing, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewAI::CheckForHealing -> Begin (CustomCrew.cpp)\n")
    needsIntruderControllable = true;
    super();
    needsIntruderControllable = false;
}

HOOK_METHOD(CrewAI, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewAI::OnLoop -> Begin (CustomCrew.cpp)\n")
    super();
    if (ship->iShipId == 0)
    {
        bool wasCalm = bCalmShip;

        // Health threshold for crew to run to medbay is 25% when bCalmShip is false and 99% when bCalmShip is true
        bCalmShip = false;
        CheckForHealing();
        bCalmShip = wasCalm;
    }
}

HOOK_METHOD(CrewAI, UpdateCrewMember, (int crewId) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewAI::UpdateCrewMember -> Begin (CustomCrew.cpp)\n")
    auto crewMember = crewList[crewId];

    if (!crewMember->GetControllable() && !crewMember->bMindControlled && !crewMember->IsDead() && crewMember->iShipId == 0 && !crewMember->IsDrone())
    {
        super(crewId);
    }
    else
    {
        return super(crewId);
    }
}

HOOK_METHOD(CrewAI, PrioritizeTask, (CrewTask task, int crewId) -> int)
{
    LOG_HOOK("HOOK_METHOD -> CrewAI::PrioritizeTask -> Begin (CustomCrew.cpp)\n")
    if (task.taskId == 0 && !crewList[crewId]->CanMan())
    {
        return 1001;
    }

    return super(task, crewId);
}

HOOK_METHOD(CrewMember, GetSavedPosition, () -> Slot)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::GetSavedPosition -> Begin (CustomCrew.cpp)\n")
    // WARNING: Logic change, potential bug introduced during transition from static to member.
    Slot ret = super();

    if (!this->GetControllable())
    {
        ret.roomId = this->finalGoal.roomId;
        ret.slotId = this->finalGoal.slotId;
        ret.worldLocation = this->finalGoal.worldLocation;

        return ret;
    }

    return ret;
}

HOOK_METHOD(ShipManager, GetSelectedCrewPoint, (int mX, int mY, bool intruder) -> CrewMember*)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetSelectedCrewPoint -> Begin (CustomCrew.cpp)\n")
    if (vCrewList.empty())
    {
        return nullptr;
    }

    for (auto i : vCrewList)
    {
        if (i->ContainsPoint(mX, mY))
        {
            if (i->IsDead())
            {
                continue;
            }
            if (intruder != i->GetIntruder())
            {
                continue;
            }
            if (!i->GetControllable() && !intruder)
            {
                continue;
            }

            if (Point(i->x, i->y).Distance(Point(mX, mY)) <= 14)
            {
                return i;
            }
        }
    }

    return nullptr;
}

HOOK_METHOD(CrewControl, MouseMove, (int mX, int mY, int wX, int wY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewControl::MouseMove -> Begin (CustomCrew.cpp)\n")
    super(mX, mY, wX, wY);

    if (selectedDoor) return;

    for (auto i : shipManager->vCrewList)
    {
        if (i->Functional() && i->selectionState != 1 && std::find(potentialSelectedCrew.begin(), potentialSelectedCrew.end(), i) == potentialSelectedCrew.end())
        {
            Pointf pos = Pointf(i->x, i->y) - Pointf(17.f, 17.f);

            if (wX - pos.x < 35.f && wX - pos.x > 0.f && wY - pos.y < 35.f && wY - pos.y > 0.f)
            {
                potentialSelectedCrew.push_back(i);
                i->selectionState = 2;
            }
        }
    }

    selectedCrew.erase(std::remove_if(selectedCrew.begin(), selectedCrew.end(), [](CrewMember* crew) { return !crew->GetControllable(); }), selectedCrew.end());
}

HOOK_METHOD(CrewMember, GetTooltip, () -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::GetTooltip -> Begin (CustomCrew.cpp)\n")
    std::string ret = super();
    auto custom = CustomOptionsManager::GetInstance();
    if (custom->advancedCrewTooltips.currentValue)
    {
        auto ex = CM_EX(this);

        std::string tooltip = "";
        tooltip += "-" + this->blueprint.crewNameLong.GetText() + " (" + this->blueprint.desc.title.GetText() + "):" + '\n';
        int maxHealth = (int)this->health.second;
        if (this->health.first == 0)
        {
            tooltip += G_->GetTextLibrary()->GetText("advanced_health_tooltip") + ": " + G_->GetTextLibrary()->GetText("death_tooltip");
        }
        else if (this->health.first == this->health.second)
        {
            std::stringstream stream;
            tooltip += G_->GetTextLibrary()->GetText("advanced_health_tooltip") + ": " + std::to_string(maxHealth) + "/" + std::to_string(maxHealth) + " (100%)";
        }
        else if (custom->advancedCrewTooltipRounding.currentAmount == 0)
        {
            tooltip += G_->GetTextLibrary()->GetText("advanced_health_tooltip") + ": " + std::to_string((int)this->health.first) + "/" + std::to_string(maxHealth) + " (" + std::to_string((int)(this->health.first / maxHealth * 100)) + "%)";
        }
        else
        {
            std::stringstream stream;
            stream << std::fixed <<std::setprecision(custom->advancedCrewTooltipRounding.currentAmount) << this->health.first;
            tooltip += G_->GetTextLibrary()->GetText("advanced_health_tooltip") + ": " + stream.str() + "/" + std::to_string(maxHealth) + " (" + std::to_string((int)(this->health.first / maxHealth * 100)) + "%)";
        }

        if (ex->deathTimer)
        {
            tooltip += '\n';
            float timer = ex->deathTimer->currGoal - ex->deathTimer->currTime;

            if (timer > 0.f)
            {
                std::string currentText = G_->GetTextLibrary()->GetText("crew_death_time");
                std::stringstream stream;
                stream << std::fixed <<std::setprecision(1) << timer;
                currentText = boost::algorithm::replace_all_copy(currentText, "\\1", stream.str());
                tooltip += currentText;
            }
            else
            {
                std::string currentText = G_->GetTextLibrary()->GetText("crew_death_time_expired");
                tooltip += currentText;
            }
        }

        if (this->fStunTime != 0)
        {
            tooltip += '\n';
            std::stringstream stream;
            stream << std::fixed <<std::setprecision(1) << this->fStunTime * ex->CalculateStat(CrewStat::STUN_MULTIPLIER, CustomCrewManager::GetInstance()->GetDefinition(this->species));
            std::string currentText = G_->GetTextLibrary()->GetText("crew_stun_time");
            currentText = boost::algorithm::replace_all_copy(currentText, "\\1", stream.str());
            tooltip += currentText;
        }

        if (custom->showEnemyPowers.currentValue && this->iShipId == 1)
        {
            tooltip += '\n';
            for (auto j : this->blueprint.powers)
            {
                tooltip += "*" + j.GetText() + '\n';
            }
            boost::trim_right(tooltip);
        }
        else if (custom->showAllyPowers.currentValue && this->iShipId == 0)
        {
            tooltip += '\n';
            for (auto j : this->blueprint.powers)
            {
                tooltip += "*" + j.GetText() + '\n';
            }
            boost::trim_right(tooltip);
        }
        tooltip += '\n';

//        if (this->bMindControlled)
//        {
//            tooltip += G_->GetTextLibrary()->GetText("mind_controlled_tooltip");
//        }
        boost::trim_right(tooltip);
        ret.assign(tooltip);
        return ret;
    }
    else
    {
        return ret;
    }
}

HOOK_METHOD(CrewAnimation, FireShot, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CrewAnimation::FireShot -> Begin (CustomCrew.cpp)\n")
    if (CMA_EX(this)->isMantisAnimation)
    {
        anims[0][7].SetProgress(anims[direction][status].tracker.Progress(-1.f));
        anims[1][7].SetProgress(anims[direction][status].tracker.Progress(-1.f));
        anims[2][7].SetProgress(anims[direction][status].tracker.Progress(-1.f));
        anims[3][7].SetProgress(anims[direction][status].tracker.Progress(-1.f));

        auto frame = anims[direction][status].currentFrame;
        bool ret = false;

        if (frame == 3)
        {
            ret = false;
            if (!uniqueBool1)
            {
                uniqueBool1 = true;
                ret = true;
            }
        }
        else if (frame > 2)
        {
            ret = false;
        }
        else
        {
            uniqueBool1 = false;
            ret = false;
        }

        return ret;
    }

    return super();
}

HOOK_METHOD(CrewAnimation, GetFiringFrame, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> CrewAnimation::GetFiringFrame -> Begin (CustomCrew.cpp)\n")
    if (CMA_EX(this)->isMantisAnimation)
    {
        return -1;
    }

    return super();
}

CrewAnimation_Extend::~CrewAnimation_Extend()
{
    if (effectAnim) effectAnim->destructor();
    if (tempEffectAnim) tempEffectAnim->destructor();
    if (effectFinishAnim) effectFinishAnim->destructor();
    for (auto &it : boostAnim)
    {
        it.second->destructor();
    }
}

// Hack door ability
ShipManager* shipManagerForShip = nullptr;

HOOK_METHOD(ShipManager, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnLoop -> Begin (CustomCrew.cpp)\n")
    shipManagerForShip = this;
    super();
    shipManagerForShip = nullptr;
}

HOOK_METHOD(Ship, OnLoop, (std::vector<float> &oxygenLevels) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnLoop -> Begin (CustomCrew.cpp)\n")
    if (shipManagerForShip != nullptr)
    {
        CustomCrewManager *custom = CustomCrewManager::GetInstance();
        auto doors = std::unordered_map<Door*,int>();

        for (auto crew : shipManagerForShip->vCrewList)
        {
            if (custom->IsRace(crew->species) && !crew->IsDead() && crew->Functional() && crew->iRoomId >= 0)
            {
                auto ex = CM_EX(crew);
                auto def = custom->GetDefinition(crew->species);
                bool hackDoors;
                ex->CalculateStat(CrewStat::HACK_DOORS, def, &hackDoors);
                if (hackDoors)
                {

                    for (auto door : vDoorList)
                    {
                        if (door->iRoom1 == crew->iRoomId || door->iRoom2 == crew->iRoomId)
                        {
                            auto it = doors.emplace(door, 0);
                            it.first->second += (crew->intruder ? 1 : -1);
                        }
                    }
                    for (auto door : vOuterAirlocks)
                    {
                        if (door->iRoom1 == crew->iRoomId || door->iRoom2 == crew->iRoomId)
                        {
                            auto it = doors.emplace(door, 0);
                            it.first->second += (crew->intruder ? 1 : -1);
                        }
                    }
                }
            }
        }

        for (auto door : doors)
        {
            if (!door.first->iHacked && door.second > 0)
            {
                door.first->iHacked = 1;
            }
            else if (door.first->iHacked && door.second < 0)
            {
                door.first->iHacked = 0;
            }
        }
    }

    super(oxygenLevels);
}

// GetClosestSlot bug fix for unusual layouts
HOOK_METHOD(ShipGraph, GetClosestSlot, (Point pos, int shipId, bool intruder) -> Slot)
{
    LOG_HOOK("HOOK_METHOD -> ShipGraph::GetClosestSlot -> Begin (CustomCrew.cpp)\n")
    for (Room *room : this->rooms)
    {
        Globals::Rect rect = room->rect;
        if (pos.x >= rect.x && pos.x <= rect.x + rect.w && pos.y >= rect.y && pos.y <= rect.y + rect.h)
        {
            return super(pos, shipId, intruder);
        }
    }
    // default return if not in any room
    // TODO: Might have to call super first, not sure if compiler will be smart enough to handle this with the implicit value thing?
    Slot slot = Slot();
    slot.roomId = -1;
    slot.slotId = -1;
    slot.worldLocation = {-1,-1};
    return slot;
}

HOOK_METHOD(CrewControl, SelectPotentialCrew, (CrewMember *crew, bool allowTeleportLeaving) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewControl::SelectPotentialCrew -> Begin (CustomCrew.cpp)\n")
    if (!crew) return;

    if (!crew->GetControllable()) return;

    if (allowTeleportLeaving || (crew->crewAnim->status != 6) || crew->crewAnim->anims[0][6].tracker.reverse)
    {
        if (std::find(potentialSelectedCrew.begin(), potentialSelectedCrew.end(), crew) == potentialSelectedCrew.end())
        {
            potentialSelectedCrew.push_back(crew);
        }
    }
}

// Controllable MC - player using power
HOOK_METHOD(CrewControl, KeyDown, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewControl::KeyDown -> Begin (CustomCrew.cpp)\n")
    if (key == Settings::GetHotkey("lockdown"))
    {
        for (auto i : selectedCrew)
        {
            if (i->PowerReady() && i->GetPowerOwner() == 0)
            {
                CM_EX(i)->PreparePower();
            }
        }
    }
    else
    {
        super(key);
    }
}
HOOK_METHOD(CrewBox, MouseClick, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CrewBox::MouseClick -> Begin (CustomCrew.cpp)\n")
    if (powerButton.bActive && powerButton.bHover)
    {
        if (pCrew->PowerReady() && pCrew->GetPowerOwner() == 0)
        {
            CM_EX(pCrew)->PreparePower();
        }
        return true;
    }
    return false;
}

HOOK_METHOD(CrewControl, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewControl::OnLoop -> Begin (CustomCrew.cpp)\n")
    crewMessage.Update();
    if (crewMessage.done)
    {
        crewMessage.Stop(false);
    }

    UpdateCrewBoxes();
    if (!bUpdated)
    {
        mouseDown = false;
        return;
    }
    std::vector<CrewMember*> filteredSelectedCrew = std::vector<CrewMember*>();

    for (auto i : selectedCrew)
    {
        if (i->Functional() && !i->IsDead() && i->crewAnim->status != 3)
        {
            filteredSelectedCrew.push_back(i);
        }
    }

    selectedCrew = filteredSelectedCrew;

    std::vector<CrewMember*> filteredPotentialSelectedCrew = std::vector<CrewMember*>();

    for (auto i : potentialSelectedCrew)
    {
        if (i->Functional() && !i->IsDead() && i->crewAnim->status != 3)
        {
            filteredPotentialSelectedCrew.push_back(i);
        }
    }

    potentialSelectedCrew = filteredPotentialSelectedCrew;

    for (auto i : shipManager->vCrewList)
    {
        i->selectionState = 0;
    }
    if (combatControl->currentTarget)
    {
        for (auto i : combatControl->currentTarget->shipManager->vCrewList)
        {
            i->selectionState = 0;
        }
    }

    for (auto i : potentialSelectedCrew)
    {
        i->selectionState = 2;
    }

    for (auto i : selectedCrew)
    {
        i->selectionState = 1;
    }

    if (!selectedCrew.empty() || !potentialSelectedCrew.empty())
    {
        G_->GetMouseControl()->valid = 1;
        G_->GetMouseControl()->lastValid = 1;
    }

    if (selectedDoor)
    {
        G_->GetMouseControl()->SetDoor(selectedDoor->bOpen ? 2 : ((int)selectedDoor->forcedOpen.running) + 1);
    }

    std::string tooltip = shipManager->GetTooltip(worldCurrentMouse.x, worldCurrentMouse.y);

    if (tooltip.empty())
    {
        tooltip = combatControl->GetCrewTooltip(currentMouse.x, currentMouse.y);
    }

    if (!tooltip.empty())
    {
        G_->GetMouseControl()->SetTooltip(tooltip);
    }

    for (int i = 0; i < crewBoxes.size(); i++)
    {
        crewBoxes[i]->OnLoop(selectedCrewBox == i);
    }

    bUpdated = false;
}

// Show path for mind controlled enemy crew.
HOOK_METHOD(CrewMember, OnRenderPath, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::OnRenderPath -> Begin (CustomCrew.cpp)\n")
    bool setShipId = false;
    if (bMindControlled && iShipId == 1)
    {
        ShipManager *ship = G_->GetShipManager(0);
        if (ship && ship->HasAugmentation("MIND_ORDER"))
        {
            setShipId = true;
            iShipId = 0;
        }
    }
    super();

    if (setShipId) iShipId = 1;
}

// Refresh boxes when the mind control status changes on a crewmember
HOOK_METHOD(CrewMember, SetMindControl, (bool controlled) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::SetMindControl -> Begin (CustomCrew.cpp)\n")
    super(controlled);
    if (iShipId == 1)
    {
        ShipManager *playerShip = G_->GetShipManager(0);
        if (playerShip && playerShip->HasAugmentation("MIND_ORDER"))
        {
            if (bMindControlled)
            {
                G_->GetCrewFactory()->MoveCrewMemberToEnd(this);
            }
            G_->GetCApp()->gui->crewControl.ClearCrewBoxes();
            G_->GetCApp()->gui->crewControl.UpdateCrewBoxes();
        }
    }
}

// Selectable/controllable split - doesn't work properly with touchscreen
HOOK_METHOD(CrewControl, RButton, (int mX, int mY, bool shiftHeld) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewControl::RButton -> Begin (CustomCrew.cpp)\n")
    requiresFullControl = 1;
    super(mX, mY, shiftHeld);
    requiresFullControl = 0;
}

// Selectable/controllable split for player
HOOK_METHOD(ShipManager, RestoreCrewPositions, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::RestoreCrewPositions -> Begin (CustomCrew.cpp)\n")
    requiresFullControl = 1;
    bool ret = super();
    requiresFullControl = 0;
    return ret;
}

// Selectable/controllable split; requiresFullControl == 1 when player is ordering
HOOK_METHOD(ShipManager, CommandCrewMoveRoom, (CrewMember* crew, int room) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::CommandCrewMoveRoom -> Begin (CustomCrew.cpp)\n")
    if (requiresFullControl == 1 && !crew->GetControllable())
    {
        return false;
    }
    return super(crew, room);
}

// Selectable/controllable split for AI
HOOK_METHOD_PRIORITY(CrewAI, OnLoop, -100, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewAI::OnLoop -> Begin (CustomCrew.cpp)\n")
    requiresFullControl = -1;
    super();
    requiresFullControl = 0;
}

static std::unordered_map<CrewMember*, std::pair<bool, bool>> g_tempOutOfGame = std::unordered_map<CrewMember*, std::pair<bool, bool>>();

// Don't count noSlot crew towards crew counts
HOOK_METHOD(CrewMemberFactory, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMemberFactory::OnLoop -> Begin (CustomCrew.cpp)\n")
    for (auto i : crewMembers)
    {
        bool noSlot;
        CM_EX(i)->CalculateStat(CrewStat::NO_SLOT, CustomCrewManager::GetInstance()->GetDefinition(i->species), &noSlot);
        if (noSlot)
        {
            g_tempOutOfGame[i] = std::pair<bool, bool>(i->bOutOfGame, i->clone_ready);

            i->bOutOfGame = true;
            i->clone_ready = false;
        }
    }

    super();

    for (auto i : g_tempOutOfGame)
    {
        auto c = i.first;

        c->bOutOfGame = i.second.first;
        c->clone_ready = i.second.second;
    }

    g_tempOutOfGame.clear();
}


static bool g_inCrewCustomizeBox = false;

HOOK_METHOD(CrewCustomizeBox, CheckContents, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewCustomizeBox::CheckContents -> Begin (CustomCrew.cpp)\n")
    g_inCrewCustomizeBox = true;

    super();
    g_inCrewCustomizeBox = false;

}

// Get crewmember in slot; modified for noSlot
HOOK_METHOD(ShipManager, GetCrewmember, (int slot, bool present) -> CrewMember*)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetCrewmember -> Begin (CustomCrew.cpp)\n")
    if (vCrewList.empty()) return nullptr;

    int currSlot = 0;

    for (auto crew : vCrewList)
    {
        if (crew->iShipId == 1 || crew->IsDrone()) continue;
        bool noSlot;
        CM_EX(crew)->CalculateStat(CrewStat::NO_SLOT, CustomCrewManager::GetInstance()->GetDefinition(crew->species), &noSlot);
        if (noSlot) continue;

        if (currSlot == slot) return crew;

        currSlot++;
    }

    return nullptr;
}

// No Clone stat
HOOK_METHOD(CrewMember, CheckSkills, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::CheckSkills -> Begin (CustomCrew.cpp)\n")
    super();

    auto ex = CM_EX(this);
    if (ex->deathTimer && ex->deathTimer->currTime >= ex->deathTimer->currGoal)
    {
        clone_ready = false;
        return;
    }

    auto custom = CustomCrewManager::GetInstance();
    if (custom->IsRace(species))
    {
        ex->CalculateStat(CrewStat::NO_CLONE, custom->GetDefinition(species), &ex->noClone);
        if (ex->noClone)
        {
            clone_ready = false;
            return;
        }
    }
}

// Mind control resist/telepathy split
HOOK_METHOD(MindSystem, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MindSystem::OnLoop -> Begin (CustomCrew.cpp)\n")
    isTelepathicMindControl = g_resistsMindControlStat;
    super();
    isTelepathicMindControl = false;
}

// Mind control resist/telepathy split
HOOK_METHOD(CombatAI, UpdateMindControl, (bool unk) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatAI::UpdateMindControl -> Begin (CustomCrew.cpp)\n")
    isTelepathicMindControl = g_resistsMindControlStat;
    super(unk);
    isTelepathicMindControl = false;
}

// canTeleport
/*
HOOK_METHOD(CombatControl, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::OnLoop -> Begin (CustomCrew.cpp)\n")
    super();
    if (currentTarget && currentTarget->shipManager && shipManager->teleportSystem)
    {
        for (CrewMember* crew : currentTarget->shipManager->vCrewList)
        {
            if (!crew->IsDead())
            {
                CustomCrewManager* custom = CustomCrewManager::GetInstance();
                if (!crew->IsDrone())
                {
                    if (custom->IsRace(crew->species))
                    {
                        auto ex = CM_EX(crew);
                        auto def = CustomCrewManager::GetInstance()->GetDefinition(crew->species);
                        bool canTeleport;
                        ex->CalculateStat(CrewStat::CAN_TELEPORT, def, &canTeleport);
                        if (canTeleport)
                        {
                            shipManager->teleportSystem->bCanReceive = true;
                            return;
                        }
                    }
                    else
                    {
                        shipManager->teleportSystem->bCanReceive = true;
                        return;
                    }
                }
                else if (g_dronesCanTeleport)
                {
                    if (crew->CanTeleport())
                    {
                        shipManager->teleportSystem->bCanReceive = true;
                        return;
                    }
                }
            }
        }
    }
    shipManager->teleportSystem->bCanReceive = false;
}
*/

// Shoot when in melee without forcing to be a drone animation
HOOK_METHOD(CrewAnimation, OnUpdate, (Pointf position, bool moving, bool fighting, bool repairing, bool dying, bool onFire) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewAnimation::OnUpdate -> Begin (CustomCrew.cpp)\n")
    auto aex = CMA_EX(this);
    if (!aex->canPunch)
    {
        bool sharedSpot = bSharedSpot;
        bSharedSpot = false;
        super(position, moving, fighting, repairing, dying, onFire);
        bSharedSpot = sharedSpot;
    }
    else
    {
        super(position, moving, fighting, repairing, dying, onFire);
    }
}

// Door damage multiplier
HOOK_METHOD(Door, ApplyDamage, (float amount) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> Door::ApplyDamage -> Begin (CustomCrew.cpp)\n")
    if (currentCrewLoop)
    {
        CrewMember_Extend *ex = CM_EX(currentCrewLoop);
        CrewDefinition *def = ex->GetDefinition();
        if (def)
        {
            if (forcedOpen.running) return false;

            float damage = ex->CalculateStat(CrewStat::DOOR_DAMAGE_MULTIPLIER, def);
            int iDamage = (int)damage;
            float fDamage = damage - iDamage;
            if (fDamage > 0.f && random32() < fDamage*2147483648.f) iDamage++;

            if (iDamage > 0) health -= iDamage;
            gotHit.Start(0.f);

            if (health < 1)
            {
                forcedOpen.Start(0.f);
                health = baseHealth;
                lockedDown.Stop(false);
                baseHealth = lastbase;
                health = lastbase;
                bOpen = true;
            }

            return false;
        }
    }
    return super(amount);
}
