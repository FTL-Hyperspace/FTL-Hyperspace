#include "CustomShipGenerator.h"
#include "CustomShipSelect.h"
#include <boost/math/special_functions/fpclassify.hpp>

#include <boost/lexical_cast.hpp>

bool CustomShipGenerator::enabled = false;
std::unordered_map<std::string,CustomShipGenerator> CustomShipGenerator::customShipGenerators = std::unordered_map<std::string,CustomShipGenerator>();
CustomShipGenerator *CustomShipGenerator::defaultShipGenerator = nullptr;

std::array<CustomShipGenerator::SystemLevelScaling,3> CustomShipGenerator::defaultSystemLevelScaling = std::array<CustomShipGenerator::SystemLevelScaling,3>();

void CustomShipGenerator::Init()
{
    if (!enabled)
    {
        defaultSystemLevelScaling[0].enabled = true;
        defaultSystemLevelScaling[0].randomScaling.reserve(2);
        defaultSystemLevelScaling[0].randomScaling.push_back({-1,0});
        defaultSystemLevelScaling[0].randomScaling.push_back({0,1});

        defaultSystemLevelScaling[1].enabled = true;
        defaultSystemLevelScaling[1].randomScaling.reserve(3);
        defaultSystemLevelScaling[1].randomScaling.push_back({-1,0});
        defaultSystemLevelScaling[1].randomScaling.push_back({0,1});
        defaultSystemLevelScaling[1].randomScaling.push_back({2,2});

        defaultSystemLevelScaling[2].enabled = true;
        defaultSystemLevelScaling[2].randomScaling.reserve(3);
        defaultSystemLevelScaling[2].randomScaling.push_back({-1,0});
        defaultSystemLevelScaling[2].randomScaling.push_back({0,1});
        defaultSystemLevelScaling[2].randomScaling.push_back({2,2});

        enabled = true;
    }
}

void CustomShipGenerator::ParseGeneratorNode(rapidxml::xml_node<char> *node)
{
    try
    {
        for (auto genNode = node->first_node(); genNode; genNode = genNode->next_sibling())
        {
            std::string nodeName = genNode->name();

            if (nodeName == "shipGenerator")
            {
                CustomShipGenerator *generator = nullptr;

                if (genNode->first_attribute("name"))
                {
                    std::string name = genNode->first_attribute("name")->value();
                    if (defaultShipGenerator == nullptr)
                    {
                        customShipGenerators[name] = CustomShipGenerator();
                    }
                    else
                    {
                        customShipGenerators[name] = *defaultShipGenerator;
                    }
                    generator = &customShipGenerators[name];
                }
                else
                {
                    delete defaultShipGenerator;
                    defaultShipGenerator = new CustomShipGenerator();
                    generator = defaultShipGenerator;
                }

                for (auto child = genNode->first_node(); child; child = child->next_sibling())
                {
                    std::string name = child->name();
                    std::string val = child->value();

                    if (name == "difficultyMod")
                    {
                        int level = 1;
                        if (child->first_attribute("difficulty"))
                        {
                            level = boost::lexical_cast<int>(child->first_attribute("difficulty")->value());
                        }
                        if (level != -1)
                        {
                            generator->difficultyMod.at(level) = boost::lexical_cast<float>(val);
                        }
                    }

                    if (name == "sectorScaling")
                    {
                        int level = 1;
                        if (child->first_attribute("difficulty"))
                        {
                            level = boost::lexical_cast<int>(child->first_attribute("difficulty")->value());
                        }
                        if (level != -1)
                        {
                            SectorScaling &sectorScaling = generator->defaultSectorScaling.at(level);
                            sectorScaling.Parse(child);
                        }
                    }

                    if (name == "systemLevelScaling")
                    {
                        int level = 1;
                        int sysId = -1;
                        if (child->first_attribute("difficulty"))
                        {
                            level = boost::lexical_cast<int>(child->first_attribute("difficulty")->value());
                        }
                        if (child->first_attribute("system"))
                        {
                            sysId = ShipSystem::NameToSystemId(child->first_attribute("system")->value());
                        }
                        if (level != -1)
                        {
                            SystemLevelScaling &systemLevelScaling = generator->systemLevelScaling[sysId].at(level);
                            systemLevelScaling = *generator->GetSystemLevelScaling(level, sysId);
                            systemLevelScaling.Parse(child, level);
                        }
                    }
                }
            }
        }
    }
    catch (rapidxml::parse_error& e)
    {
        ErrorMessage(std::string("Error parsing <shipGenerators> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (std::exception &e)
    {
        ErrorMessage(std::string("Error parsing <shipGenerators> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (const char* e)
    {
        ErrorMessage(std::string("Error parsing <shipGenerators> in hyperspace.xml\n") + std::string(e));
    }
    catch (...)
    {
        ErrorMessage("Error parsing <shipGenerators> in hyperspace.xml\n");
    }
}

void CustomShipGenerator::SectorScaling::Parse(rapidxml::xml_node<char> *node)
{
    enabled = true;

    float minSector = 0.f;
    float maxSector = NAN;

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string name = child->name();
        std::string val = child->value();

        if (name == "minValue")
        {
            minValue = boost::lexical_cast<float>(val);
        }
        if (name == "maxValue")
        {
            maxValue = boost::lexical_cast<float>(val);
        }
        if (name == "minSector")
        {
            minSector = boost::lexical_cast<float>(val);
        }
        if (name == "maxSector")
        {
            maxSector = boost::lexical_cast<float>(val);
        }
    }

    if (boost::math::isnan(maxSector))
    {
        maxSector = minSector + 8.f;
    }

    sectorValue = (maxValue-minValue)/(maxSector-minSector);
    baseValue = minValue-minSector*sectorValue;
}

void CustomShipGenerator::SystemLevelScaling::Parse(rapidxml::xml_node<char> *node, int difficulty)
{
    enabled = true;

    bool newRandomScaling = false;

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string name = child->name();
        std::string val = child->value();

        if (name == "sectorScaling")
        {
            sectorScaling.Parse(child);
        }
        if (name == "randomScaling")
        {
            if (!newRandomScaling)
            {
                randomScaling.clear();
                newRandomScaling = true;
            }

            if (val.empty()) continue;

            int level = -1;
            int value = value = boost::lexical_cast<int>(val);;
            if (child->first_attribute("sector"))
            {
                level = boost::lexical_cast<int>(child->first_attribute("sector")->value());
            }
            randomScaling.push_back({level,value});
        }
    }

    if (randomScaling.empty())
    {
        randomScaling = defaultSystemLevelScaling[difficulty].randomScaling;
    }
}

CustomShipGenerator *CustomShipGenerator::GetShipGenerator(const std::string &name)
{
    auto it = customShipGenerators.find(name);
    if (it != customShipGenerators.end())
    {
        return &it->second;
    }
    hs_log_file("WARNING: No ship generator named '%s' found; using the default.\n", name.c_str());
    return defaultShipGenerator;
}

CustomShipGenerator *CustomShipGenerator::GetShipGenerator()
{
    return defaultShipGenerator;
}

ShipManager *CustomShipGenerator::CreateShip(const ShipBlueprint *shipBlueprint, int sector, ShipEvent& event)
{
    CustomShipSelect *customShipSelect = CustomShipSelect::GetInstance();
    CustomShipDefinition *customShip = &customShipSelect->GetDefinition(shipBlueprint->blueprintName);

	int level = sector + difficultyMod[*G_->difficulty];

	ShipBlueprint bp(*shipBlueprint);

    RemoveAugments(bp, level);
    SetMaximumHull(bp, level, customShip);

    ShipManager *ship = new ShipManager(1);

    std::vector<CrewDesc> crewOverride = event.crewOverride;
    int crewCount = InitShip(ship, bp, level, event, crewOverride, customShip);

    std::vector<int> systemMaxes = GenerateSystemMaxes(bp,level);
    std::vector<int> budget = GenerateShipBudget(level);

    AddSystems(ship, level, systemMaxes, budget);
    UpgradeSystems(ship, systemMaxes, budget);

    AddOverrideWeapons(ship, event);
    AddOverrideDrones(ship, event);

    unsigned int equipFlags = 3;
    AddWeapons(ship, bp, equipFlags);
    AddDrones(ship, bp, equipFlags);

    std::vector<Drone*> droneList = ship->GetDroneList();
	int numDrones = droneList.size();
	while (ship->GetDroneCount() < 2*numDrones) ship->ModifyDroneCount(1);

    AddCrew(ship, crewOverride, crewCount, equipFlags);

    ship->InstantPowerShields();

	if ((ship->HasSystem(SYS_DRONES) || ship->HasSystem(SYS_HACKING)) && ship->GetDroneCount() < 1)
	{
		ship->ModifyDroneCount(5);
	}

    if (customShip && customShip->forceAutomated.enabled)
    {
        ship->bAutomated = customShip->forceAutomated.value;
    }

    return ship;
}

void CustomShipGenerator::RemoveAugments(ShipBlueprint &bp, int level)
{
    // Remove zoltan shield on easy in sector 1
	if (*G_->difficulty == 0 && level == -1)
	{
		for (auto it = bp.augments.begin(); it != bp.augments.end(); )
		{
			if (*it == "ENERGY_SHIELD")
			{
				it = bp.augments.erase(it);
			}
			else
			{
				it++;
			}
		}
	}
}

void CustomShipGenerator::SetMaximumHull(ShipBlueprint &bp, int level, CustomShipDefinition *customShip)
{
    int maxHealth = customShip ? customShip->hpCap : 20;

    bp.health += level;
	if (maxHealth != -1 && bp.health > maxHealth) bp.health = maxHealth;
}

int CustomShipGenerator::InitShip(ShipManager *ship, ShipBlueprint &bp, int level, ShipEvent& event, std::vector<CrewDesc> &crewOverride, CustomShipDefinition *customShip)
{
    int crewCount = 0;

	if (bp.originalCrewCount == 0)
	{
		bp.defaultCrew.clear();
		ship->OnInit(&bp, 0);
		ship->bAutomated = crewOverride.empty() && (!customShip || customShip->crewList.empty());
	}
	else
	{
		std::string crewRace = bp.defaultCrew[0];
		bp.defaultCrew.clear();
		if (bp.originalCrewCount > 0)
		{
			crewCount = GetDefaultSectorScaling()->GetValue(level) * (bp.maxCrew - bp.originalCrewCount) + bp.originalCrewCount;
            ship->OnInit(&bp, 0);
			ship->bAutomated = false;
			if (crewOverride.empty())
			{
				crewOverride.push_back({crewRace, 1.f, 0});
			}
		}
	}

	return crewCount;
}

std::vector<int> CustomShipGenerator::GenerateSystemMaxes(ShipBlueprint &bp, int level)
{
    std::vector<int> systemMaxes = std::vector<int>();
    systemMaxes.reserve(21);
    systemMaxes.resize(21, 0);

    for (auto sysInfo : bp.systemInfo)
    {
        int sysId = sysInfo.first;
        ShipBlueprint::SystemTemplate &sysTemplate = sysInfo.second;

        int minPower = sysTemplate.powerLevel;
        int maxPower = sysTemplate.maxPower;

        SystemLevelScaling *systemScaling = GetSystemLevelScaling(*G_->difficulty, sysId);
        SectorScaling *sectorScaling = GetSectorScaling(&systemScaling->sectorScaling);

        int bonus = systemScaling->GetRandomScalingValue(level);

        int power = random32()%(bonus+1) + sectorScaling->GetValue(level) * (maxPower - minPower) + minPower;
        power = std::min(maxPower, std::max(power, minPower));
        systemMaxes[sysId] = power;
    }

    return systemMaxes;
}

std::vector<int> CustomShipGenerator::GenerateShipBudget(int level)
{
    std::vector<int> budget = {};
    budget.push_back(level/3 + (*G_->difficulty == 2 ? 2 : 1));
    budget.push_back(level+1);
    budget.push_back(level+2);
    return budget;
}

void CustomShipGenerator::AddSystems(ShipManager *ship, int level, std::vector<int> &systemMaxes, std::vector<int> &budget)
{
    level = std::max(0,level);
    for (unsigned int sysId=0; sysId<systemMaxes.size(); ++sysId) // must be unsigned
	{
	    if (sysId-16 < 4) continue;

		int sysChance;
		switch(*G_->difficulty)
		{
			case 0:
				sysChance = 10*(level + 1);
				break;
			case 2:
				sysChance = 10*(level + 3);
				break;
			default:
				sysChance = 10*(level + 2);
				break;
		}
		if (!ship->HasSystem(sysId) && systemMaxes[sysId] > 0 && random32()%100 < sysChance)
		{
			ShipGenerator::UpgradeSystem(ship, systemMaxes, sysId);
			if (sysId-3 < 2 || sysId == 9)
			{
			    if (budget.size() > 1)
                {
                    budget[1] -= 1;
                }
				else
                {
                    budget[0] -= 1;
                }
			}
			else
			{
				budget[0] -= (*G_->difficulty == 2 ? 1 : 2);
			}
		}
	}
}

void CustomShipGenerator::UpgradeSystems(ShipManager *ship, std::vector<int> &systemMaxes, std::vector<int> &budget)
{
    // Phase 1 upgrades, uses budget_1 for weapons/drones/teleporter/artillery
	while (budget[1] > 0)
	{
		std::vector<int> possibleUpgrades = GetPossibleSystemUpgrades(ship, systemMaxes, 2);
		if (possibleUpgrades.empty()) break;
		ShipGenerator::UpgradeSystem(ship, systemMaxes, possibleUpgrades[random32()%possibleUpgrades.size()]);
		budget[1] -= 1;
	}
	budget[0] += budget[1];

	// Phase 2 upgrades, uses budget_2 for shields/engines/cloaking
	while (budget[2] > 0)
	{
		std::vector<int> possibleUpgrades = GetPossibleSystemUpgrades(ship, systemMaxes, 1);
		if (possibleUpgrades.empty()) break;
		ShipGenerator::UpgradeSystem(ship, systemMaxes, possibleUpgrades[random32()%possibleUpgrades.size()]);
		budget[2] -= 1;
	}
	budget[0] += budget[2];

	// Phase 3 upgrades uses any remaining budget for any systems
	while (budget[0] > 0)
	{
		std::vector<int> possibleUpgrades = GetPossibleSystemUpgrades(ship, systemMaxes, 0);
		if (possibleUpgrades.empty()) break;
		ShipGenerator::UpgradeSystem(ship, systemMaxes, possibleUpgrades[random32()%possibleUpgrades.size()]);
		budget[0] -= 1;
	}
}

std::vector<int> CustomShipGenerator::GetPossibleSystemUpgrades(ShipManager *ship, std::vector<int> &systemMaxes, int type)
{
    std::vector<int> possibleUpgrades;

    for (unsigned int sysId=0; sysId<systemMaxes.size(); ++sysId)
	{
	    if (sysId-16 < 4) continue;

		if (type == 1)
		{
			if (!(sysId == 10 || sysId < 2)) continue; // shields, engines, cloaking
		}
		else if (type == 2)
		{
			if (!(sysId-3 < 2 || sysId == 9 || sysId == 11)) continue; // weapons, drones, teleporter, artillery
		}

		std::string sysName = ShipSystem::SystemIdToName(sysId);
		//SystemBlueprint *bp = G_->GetBlueprints()->GetSystemBlueprint(sysName);
		if (sysId == 11 && !ship->artillerySystems.empty())
		{
			for (ShipSystem *sys : ship->artillerySystems)
			{
				if (sys != nullptr && sys->powerState.second < systemMaxes[sysId])
				{
					possibleUpgrades.push_back(sysId);
				}
			}
		}
		else
		{
			ShipSystem *sys = ship->GetSystem(sysId);
			if (sys != nullptr && sys->powerState.second < systemMaxes[sysId])
			{
				possibleUpgrades.push_back(sysId);
			}
		}
	}

    return possibleUpgrades;
}

void CustomShipGenerator::AddOverrideWeapons(ShipManager *ship, ShipEvent& event)
{
    std::vector<std::string> weaponOverride = event.weaponOverride;
    int weaponPower = 0;
	while (event.weaponOverCount > 0)
	{
		event.weaponOverCount -= 1;
		int idx = random32()%weaponOverride.size();
		WeaponBlueprint *wBp = G_->GetBlueprints()->GetWeaponBlueprint(weaponOverride[idx]);
		weaponPower += wBp->power;
		ship->AddWeapon(wBp, -1);
		weaponOverride.erase(weaponOverride.begin()+idx);
	}
	int maxWeaponPower = ship->GetSystemPowerMax(SYS_WEAPONS);
	if (maxWeaponPower < weaponPower)
	{
		for (int i=0; i < weaponPower-maxWeaponPower; ++i)
		{
			ShipSystem *sys = ship->GetSystem(SYS_WEAPONS);
			if (sys == nullptr)
			{
				ship->AddSystem(SYS_WEAPONS);
				sys = ship->GetSystem(SYS_WEAPONS);
				PowerManager::GetPowerManager(1)->currentPower.second += sys->powerState.second;
			}
			else
			{
				std::pair<int,int> availablePower = ship->GetAvailablePower();
				PowerManager::GetPowerManager(1)->currentPower.second += 1;
				sys->UpgradeSystem(1);
			}
		}
	}
}

void CustomShipGenerator::AddOverrideDrones(ShipManager *ship, ShipEvent& event)
{
    std::vector<std::string> droneOverride = event.droneOverride;
    int dronePower = 0;
	while (event.droneOverCount > 0)
	{
		event.droneOverCount -= 1;
		int idx = random32()%droneOverride.size();
		DroneBlueprint *dBp = G_->GetBlueprints()->GetDroneBlueprint(droneOverride[idx]);
		dronePower += dBp->power;
		ship->AddDrone(dBp, -1);
		droneOverride.erase(droneOverride.begin()+idx);
	}
	int maxDronePower = ship->GetSystemPowerMax(SYS_DRONES);
	if (maxDronePower < dronePower)
	{
		for (int i=0; i < dronePower-maxDronePower; ++i)
		{
			ShipSystem *sys = ship->GetSystem(SYS_DRONES);
			if (sys == nullptr)
			{
				ship->AddSystem(SYS_DRONES);
				sys = ship->GetSystem(SYS_DRONES);
				std::pair<int,int> availablePower = ship->GetAvailablePower();
				PowerManager::GetPowerManager(1)->currentPower.second += sys->powerState.second;
			}
			else
			{
				std::pair<int,int> availablePower = ship->GetAvailablePower();
				PowerManager::GetPowerManager(1)->currentPower.second += 1;
				sys->UpgradeSystem(1);
			}
		}
	}
}

void CustomShipGenerator::AddWeapons(ShipManager *ship, ShipBlueprint &bp, unsigned int &flags)
{
    std::vector<WeaponBlueprint*> possibleWeaponList = ShipGenerator::GetPossibleWeaponList(ship, bp.loadWeapons, 0, flags);
	while (!possibleWeaponList.empty())
	{
		WeaponBlueprint *wBp = possibleWeaponList[random32()%possibleWeaponList.size()];
		if (wBp->type == 0 || (wBp->type == 1 && wBp->damage.iShieldPiercing < 4))
		{
			flags &= ~2;
		}
		if (wBp->damage.iDamage != 0)
		{
			flags &= ~1;
		}
		ship->AddWeapon(wBp, -1);

		possibleWeaponList = ShipGenerator::GetPossibleWeaponList(ship, bp.loadWeapons, 0, flags);
	}
}

void CustomShipGenerator::AddDrones(ShipManager *ship, ShipBlueprint &bp, unsigned int &flags)
{
    std::vector<DroneBlueprint*> possibleDroneList = ShipGenerator::GetPossibleDroneList(ship, bp.loadDrones, 0, flags, false);
	while (!possibleDroneList.empty())
	{
		DroneBlueprint *dBp = possibleDroneList[random32()%possibleDroneList.size()];
		if (dBp->type == 1) flags &= ~3;
		ship->AddDrone(dBp, -1);

		possibleDroneList = ShipGenerator::GetPossibleDroneList(ship, bp.loadDrones, 0, flags, false);
		if (possibleDroneList.empty())
		{
			possibleDroneList = ShipGenerator::GetPossibleDroneList(ship, bp.loadDrones, 0, flags, true); // allow repeats
		}
	}
}

void CustomShipGenerator::AddCrew(ShipManager *ship, std::vector<CrewDesc> &crewOverride, int crewCount, unsigned int &flags)
{
    if (!crewOverride.empty())
	{
		for (CrewDesc& crewDesc : crewOverride)
		{
			int amount;
			if (crewDesc.prop <= 0.f)
			{
				amount = crewDesc.amount;
			}
			else
			{
				float crewAmount = crewDesc.prop * crewCount;
				if (crewAmount <= 1.f)
				{
					amount = 1;
				}
				else
				{
					amount = crewAmount;
				}
			}
			std::vector<CrewBlueprint> crewList = std::vector<CrewBlueprint>();
			std::vector<CrewBlueprint> possibleCrewList = ShipGenerator::GetPossibleCrewList(ship, crewDesc.type, flags);
			while (!possibleCrewList.empty() && amount > 0)
			{
				crewList.push_back(possibleCrewList[random32()%possibleCrewList.size()]);
				amount -= 1;
				possibleCrewList = ShipGenerator::GetPossibleCrewList(ship, crewDesc.type, flags);
			}
			ship->AddInitialCrew(crewList);
		}
	}
}

CustomShipGenerator::SectorScaling *CustomShipGenerator::GetDefaultSectorScaling()
{
    auto ret = &defaultSectorScaling[*G_->difficulty];
    if (ret->enabled)
        return ret;
    else
        return &defaultSectorScaling[1];
}

CustomShipGenerator::SectorScaling *CustomShipGenerator::GetSectorScaling(CustomShipGenerator::SectorScaling *selectedScaling)
{
    return (selectedScaling && selectedScaling->enabled) ? selectedScaling : GetDefaultSectorScaling();
}

CustomShipGenerator::SystemLevelScaling *CustomShipGenerator::GetSystemLevelScaling(int difficulty, int sysId)
{
    auto it = systemLevelScaling.find(sysId);
    if (it != systemLevelScaling.end())
    {
        auto ret = &(it->second[difficulty]);
        if (ret->enabled)
            return ret;
        ret = &(it->second[1]);
        if (ret->enabled)
            return ret;
    }
    if (sysId == -1)
    {
        return &defaultSystemLevelScaling[difficulty];
    }
    else
    {
        return GetSystemLevelScaling(difficulty, -1);
    }
}

HOOK_STATIC_PRIORITY(ShipGenerator, CreateShip, -100, (const std::string& name, int sector, ShipEvent& event) -> ShipManager*)
{
    LOG_HOOK("HOOK_STATIC_PRIORITY -> ShipGenerator::CreateShip -> Begin (CustomShipGenerator.cpp)\n")
    if (!CustomShipGenerator::enabled) return super(name, sector, event);

    ShipManager *ret;

    if (event.shipSeed != 0) srandom32(event.shipSeed);
    ShipBlueprint *bp = G_->GetBlueprints()->GetShipBlueprint(name, sector);

    CustomShipGenerator *generator = CustomShipGenerator::GetShipGenerator();

    CustomShipSelect *customShipSelect = CustomShipSelect::GetInstance();
    CustomShipDefinition *customShip = &customShipSelect->GetDefinition(bp->blueprintName);
    if (customShip && !customShip->shipGenerator.empty())
    {
        generator = CustomShipGenerator::GetShipGenerator(customShip->shipGenerator);
    }

    // Lua callback: name, sector, ShipEvent, ShipBlueprint, ShipManager
    // Note that the ShipManager is initially a nil
    auto context = Global::GetInstance()->getLuaContext();
    lua_pushstring(context->GetLua(), name.c_str());
    lua_pushinteger(context->GetLua(), sector);
    SWIG_NewPointerObj(context->GetLua(), &event, context->getLibScript()->types.pShipEvent, 0);
    SWIG_NewPointerObj(context->GetLua(), bp, context->getLibScript()->types.pShipBlueprint, 0); // note to users, this is not a temporary copy for just this ship!
    lua_pushnil(context->GetLua());
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::GENERATOR_CREATE_SHIP, 5, 4); // can replace sector, change the ShipEvent or replace the blueprint

    // pre-empt won't actually do anything; instead it's based on whether the callback returns a ShipManager or not.
    if (SWIG_isptrtype(context->GetLua(), -1) && SWIG_IsOK(SWIG_ConvertPtr(context->GetLua(), -1, (void**)&ret, context->getLibScript()->types.pShipManager, SWIG_POINTER_DISOWN)))
    {
        // keep the ShipManager from the lua script
    }
    else
    {
        ShipEvent* pEvent = &event;
        ShipEvent* retEvent;
        ShipBlueprint* retBlueprint;
        if (lua_isinteger(context->GetLua(), -4)) sector = lua_tointeger(context->GetLua(), -4);
        if (SWIG_isptrtype(context->GetLua(), -3) && SWIG_IsOK(SWIG_ConvertPtr(context->GetLua(), -3, (void**)&retEvent, context->getLibScript()->types.pShipEvent, 0))) pEvent = retEvent;
        if (SWIG_isptrtype(context->GetLua(), -2) && SWIG_IsOK(SWIG_ConvertPtr(context->GetLua(), -2, (void**)&retBlueprint, context->getLibScript()->types.pShipBlueprint, 0))) bp = retBlueprint;

        // Note that pEvent and bp can either be the original event/blueprint or an alternate one, potentially a temporary lua copy, but it stays on the stack

        if (generator != nullptr)
        {
            ret = generator->CreateShip(bp, sector, *pEvent);
        }
        else
        {
            ret = super(bp->blueprintName, sector, *pEvent);
        }

        // Place the ShipManager on the last spot of the stack
        lua_pop(context->GetLua(), 1);
        SWIG_NewPointerObj(context->GetLua(), ret, context->getLibScript()->types.pShipManager, 0);
    }

    // The post-callback does not return anything, but can be used to modify the ShipManager after the main generator has run
    context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::GENERATOR_CREATE_SHIP_POST, 5, 0);

    lua_pop(context->GetLua(), 5);
    return ret;
}
/*
HOOK_STATIC_PRIORITY(ShipGenerator, CreateShip, 9999, (const std::string& name, int sector, ShipEvent& event) -> ShipManager*)
{
    LOG_HOOK("HOOK_STATIC_PRIORITY -> ShipGenerator::CreateShip -> Begin (CustomShipGenerator.cpp)\n")
	std::vector<CrewDesc> crewOverride = event.crewOverride;
	std::vector<std::string> weaponOverride = event.weaponOverride;
	std::vector<std::string> droneOverride = event.droneOverride;

	if (event.shipSeed != 0) srandom32(event.shipSeed);

	sector = sector - (*G_->difficulty == 0);
	int level = sector;

	if (sector <= -1) sector = 0;

	ShipBlueprint bp = *G_->GetBlueprints()->GetShipBlueprint(name, sector);

	// Remove zoltan shield on easy in sector 1
	if (*G_->difficulty == 0 && level == -1)
	{
		for (auto it = bp.augments.begin(); it != bp.augments.end(); )
		{
			if (*it == "ENERGY_SHIELD")
			{
				it = bp.augments.erase(it);
			}
			else
			{
				it++;
			}
		}
	}

	bp.health += level;
	if (bp.health > 20) bp.health = 20;

	ShipManager *ship = new ShipManager(1);

	int crewCount = 0;
	std::string crewRace = "human";

	if (bp.originalCrewCount == 0)
	{
		bp.defaultCrew.clear();
		ship->OnInit(&bp, 0);
		ship->bAutomated = event.crewOverride.empty();
	}
	else
	{
		crewRace = bp.defaultCrew[0];
		bp.defaultCrew.clear();
		if (bp.originalCrewCount > 0)
		{
			crewCount = std::min(1.f, sector*0.125f) * (bp.maxCrew - bp.originalCrewCount) + bp.originalCrewCount;
			ship->OnInit(&bp, 0);
			ship->bAutomated = false;
			if (event.crewOverride.empty())
			{
				crewOverride.push_back({crewRace, 1.f, 0});
			}
		}
	}

	// Generates a vector of system max levels, index is system ID, value is max level.
	// system Max = random32()%X + (int)(level*0.125*(maxPower-powerLevel) + powerLevel)
	// Where X = 1 if level < 0, else X = 2 if difficulty is easy or level < 2, else X = 3
	// Then the result is bounded by [powerLevel, maxPower]
	std::vector<int> systemMaxes = GenerateSystemMaxes(bp,level);

	int scrap = std::pow(sector+1, 1.8) * 25.0 + 150.0;
	ship->ModifyScrapCount((int)(scrap - ship->currentScrap), false);
	float scrap2 = scrap * 0.2f;

	int budget_1 = sector + 1;
	int budget_2 = level + 2;
	int budget_3 = sector/3 + (*G_->difficulty == 2 ? 2 : 1);

	for (unsigned int sysId=0; sysId<16; ++sysId) // must be unsigned
	{
		int sysChance;
		switch(*G_->difficulty)
		{
			case 0:
				sysChance = sector + 1;
				break;
			case 2:
				sysChance = sector + 3;
				break;
			default:
				sysChance = sector + 2;
				break;
		}
		if (!ship->HasSystem(sysId) && systemMaxes[sysId] > 0 && random32()%10 < sysChance)
		{
			UpgradeSystem(ship, systemMaxes, sysId);
			if (sysId-3 < 2 || sysId == 9)
			{
				budget_1 -= 1;
			}
			else
			{
				budget_3 -= (*G_->difficulty == 2 ? 1 : 2);
			}
		}
	}

	// Phase 1 upgrades, uses budget_1 for weapons/drones/teleporter/artillery
	while (budget_1 > 0)
	{
		//std::vector<int> possibleUpgrades = GetPossibleSystemUpgrades(ship, systemMaxes, scrap, 2);
		std::vector<int> possibleUpgrades = GetPossibleSystemUpgrades2(ship, systemMaxes);
		if (possibleUpgrades.empty()) break;
		UpgradeSystem(ship, systemMaxes, possibleUpgrades[random32()%possibleUpgrades.size()]);
		budget_1 -= 1;
	}

	// Phase 2 upgrades, uses budget_2 for shields/engines/cloaking
	while (budget_2 > 0)
	{
		//std::vector<int> possibleUpgrades = GetPossibleSystemUpgrades(ship, systemMaxes, scrap, 1);
		std::vector<int> possibleUpgrades = GetPossibleSystemUpgrades1(ship, systemMaxes);
		if (possibleUpgrades.empty()) break;
		UpgradeSystem(ship, systemMaxes, possibleUpgrades[random32()%possibleUpgrades.size()]);
		budget_2 -= 1;
	}

	// Phase 3 upgrades uses any remaining budget for any systems
	budget_3 = budget_1 + budget_2 + budget_3;
	while (budget_3 > 0)
	{
		//std::vector<int> possibleUpgrades = GetPossibleSystemUpgrades(ship, systemMaxes, scrap, 0);
		std::vector<int> possibleUpgrades = GetPossibleSystemUpgrades0(ship, systemMaxes);
		if (possibleUpgrades.empty()) break;
		UpgradeSystem(ship, systemMaxes, possibleUpgrades[random32()%possibleUpgrades.size()]);
		budget_3 -= 1;
	}

	int weaponPower = 0;
	while (event.weaponOverCount > 0)
	{
		event.weaponOverCount -= 1;
		int idx = random32()%weaponOverride.size();
		WeaponBlueprint *wBp = G_->GetBlueprints()->GetWeaponBlueprint(weaponOverride[idx]);
		weaponPower += wBp->power;
		ship->AddWeapon(wBp, -1);
		weaponOverride.erase(weaponOverride.begin()+idx);
	}
	int maxWeaponPower = ship->GetSystemPowerMax(SYS_WEAPONS);
	if (maxWeaponPower < weaponPower)
	{
		for (int i=0; i < weaponPower-maxWeaponPower; ++i)
		{
			ShipSystem *sys = ship->GetSystem(SYS_WEAPONS);
			if (sys == nullptr)
			{
				ship->AddSystem(SYS_WEAPONS);
				sys = ship->GetSystem(SYS_WEAPONS);
				PowerManager::GetPowerManager(1)->currentPower.second += sys->powerState.second;
			}
			else
			{
				std::pair<int,int> availablePower = ship->GetAvailablePower();
				PowerManager::GetPowerManager(1)->currentPower.second += 1;
				sys->UpgradeSystem(1);
			}
		}
	}

	int dronePower = 0;
	while (event.droneOverCount > 0)
	{
		event.droneOverCount -= 1;
		int idx = random32()%droneOverride.size();
		DroneBlueprint *dBp = G_->GetBlueprints()->GetDroneBlueprint(droneOverride[idx]);
		dronePower += dBp->power;
		ship->AddDrone(dBp, -1);
		droneOverride.erase(droneOverride.begin()+idx);
	}
	int maxDronePower = ship->GetSystemPowerMax(SYS_DRONES);
	if (maxDronePower < dronePower)
	{
		for (int i=0; i < dronePower-maxDronePower; ++i)
		{
			ShipSystem *sys = ship->GetSystem(SYS_DRONES);
			if (sys == nullptr)
			{
				ship->AddSystem(SYS_DRONES);
				sys = ship->GetSystem(SYS_DRONES);
				std::pair<int,int> availablePower = ship->GetAvailablePower();
				PowerManager::GetPowerManager(1)->currentPower.second += sys->powerState.second;
			}
			else
			{
				std::pair<int,int> availablePower = ship->GetAvailablePower();
				PowerManager::GetPowerManager(1)->currentPower.second += 1;
				sys->UpgradeSystem(1);
			}
		}
	}

	unsigned int weaponFlag = 3;
	std::vector<WeaponBlueprint*> possibleWeaponList = GetPossibleWeaponList(ship, bp.loadWeapons, scrap2, 3);
	while (!possibleWeaponList.empty())
	{
		WeaponBlueprint *wBp = possibleWeaponList[random32()%possibleWeaponList.size()];
		if (wBp->type == 0 || (wBp->type == 1 && wBp->damage.iShieldPiercing < 4))
		{
			weaponFlag &= ~2;
		}
		if (wBp->damage.iDamage != 0)
		{
			weaponFlag &= ~1;
		}
		ship->AddWeapon(wBp, -1);

		possibleWeaponList = GetPossibleWeaponList(ship, bp.loadWeapons, scrap2, weaponFlag);
	}

	std::vector<DroneBlueprint*> possibleDroneList = GetPossibleDroneList(ship, bp.loadDrones, scrap2, weaponFlag, false);
	while (!possibleDroneList.empty())
	{
		DroneBlueprint *dBp = possibleDroneList[random32()%possibleDroneList.size()];
		if (dBp->type == 1) weaponFlag &= ~3;
		ship->AddDrone(dBp, -1);

		possibleDroneList = GetPossibleDroneList(ship, bp.loadDrones, scrap2, weaponFlag, false);
		if (possibleDroneList.empty())
		{
			possibleDroneList = GetPossibleDroneList(ship, bp.loadDrones, scrap2, weaponFlag, true); // allow repeats
		}
	}

	std::vector<Drone*> droneList;
	ShipManager::GetDroneList(droneList, ship);
	int numDrones = droneList.size();
	while (ship->GetDroneCount() < 2*numDrones) ship->ModifyDroneCount(1);

	if (!crewOverride.empty())
	{
		for (CrewDesc& crewDesc : crewOverride)
		{
			int amount;
			if (crewDesc.prop <= 0.f)
			{
				amount = crewDesc.amount;
			}
			else
			{
				float crewAmount = crewDesc.prop * crewCount;
				if (crewAmount <= 1.f)
				{
					amount = 1;
				}
				else
				{
					amount = crewAmount;
				}
			}
			std::vector<CrewBlueprint> crewList = std::vector<CrewBlueprint>();
			std::vector<CrewBlueprint> possibleCrewList = GetPossibleCrewList(ship, crewDesc.type, weaponFlag);
			while (!possibleCrewList.empty() && amount > 0)
			{
				crewList.push_back(possibleCrewList[random32()%possibleCrewList.size()]);
				amount -= 1;
				possibleCrewList = GetPossibleCrewList(ship, crewDesc.type, weaponFlag);
			}
			ship->AddInitialCrew(crewList);
		}
	}

	ship->InstantPowerShields();

	if ((ship->HasSystem(SYS_DRONES) || ship->HasSystem(SYS_HACKING)) && ship->GetDroneCount() < 1)
	{
		ship->ModifyDroneCount(5);
	}

	return ship;
}
*/
