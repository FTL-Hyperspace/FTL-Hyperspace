#include "CustomShipGenerator.h"
#include "CustomShipSelect.h"

bool CustomShipGenerator::enabled = false;
std::unordered_map<std::string,CustomShipGenerator> CustomShipGenerator::customShipGenerators = std::unordered_map<std::string,CustomShipGenerator>();
CustomShipGenerator *CustomShipGenerator::defaultShipGenerator = nullptr;

CustomShipGenerator *CustomShipGenerator::GetShipGenerator(const std::string &name)
{
    auto it = customShipGenerators.find(name);
    if (it != customShipGenerators.end())
    {
        return &it->second;
    }
    return defaultShipGenerator;
}

ShipManager *CustomShipGenerator::CreateShip(const ShipBlueprint *shipBlueprint, int sector, ShipEvent& event)
{
    CustomShipSelect *customShipSelect = CustomShipSelect::GetInstance();
    CustomShipDefinition *customShip = &customShipSelect->GetDefinition(shipBlueprint->blueprintName);

    sector = sector - (*G_->difficulty == 0);
	int level = sector;
	if (sector <= -1) sector = 0;

	ShipBlueprint bp = *shipBlueprint;

    RemoveAugments(bp, level);
    SetMaximumHull(bp, level, customShip);

    ShipManager *ship = new ShipManager(1);

    std::vector<CrewDesc> crewOverride = event.crewOverride;
    int crewCount = InitShip(ship, bp, level, event, crewOverride, customShip);

    std::vector<int> systemMaxes = ShipGenerator::GenerateSystemMaxes(bp,level);
    std::vector<int> budget = GenerateShipBudget(level);

    AddSystems(ship, level, systemMaxes, budget);
    UpgradeSystems(ship, systemMaxes, budget);

    AddOverrideWeapons(ship, event);
    AddOverrideDrones(ship, event);

    unsigned int equipFlags = 3;
    AddWeapons(ship, bp, equipFlags);
    AddDrones(ship, bp, equipFlags);

    std::vector<Drone*> droneList;
	ShipManager::GetDroneList(droneList, ship);
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
    int maxHealth = 20;

    if (customShip && customShip->hpCap != -1)
    {
        maxHealth = customShip->hpCap;
    }

    bp.health += level;
	if (bp.health > maxHealth) bp.health = maxHealth;
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
			crewCount = std::max(0.f, std::min(level*0.125f, 1.f)) * (bp.maxCrew - bp.originalCrewCount) + bp.originalCrewCount;
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
    for (unsigned int sysId=0; sysId<16; ++sysId) // must be unsigned
	{
		int sysChance;
		switch(*G_->difficulty)
		{
			case 0:
				sysChance = level + 1;
				break;
			case 2:
				sysChance = level + 3;
				break;
			default:
				sysChance = level + 2;
				break;
		}
		if (!ship->HasSystem(sysId) && systemMaxes[sysId] > 0 && random32()%10 < sysChance)
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
		//std::vector<int> possibleUpgrades = GetPossibleSystemUpgrades(ship, systemMaxes, scrap, 2);
		std::vector<int> possibleUpgrades = ShipGenerator::GetPossibleSystemUpgrades2(ship, systemMaxes);
		if (possibleUpgrades.empty()) break;
		ShipGenerator::UpgradeSystem(ship, systemMaxes, possibleUpgrades[random32()%possibleUpgrades.size()]);
		budget[1] -= 1;
	}
	budget[0] += budget[1];

	// Phase 2 upgrades, uses budget_2 for shields/engines/cloaking
	while (budget[2] > 0)
	{
		//std::vector<int> possibleUpgrades = GetPossibleSystemUpgrades(ship, systemMaxes, scrap, 1);
		std::vector<int> possibleUpgrades = ShipGenerator::GetPossibleSystemUpgrades1(ship, systemMaxes);
		if (possibleUpgrades.empty()) break;
		ShipGenerator::UpgradeSystem(ship, systemMaxes, possibleUpgrades[random32()%possibleUpgrades.size()]);
		budget[2] -= 1;
	}
	budget[0] += budget[2];

	// Phase 3 upgrades uses any remaining budget for any systems
	while (budget[0] > 0)
	{
		//std::vector<int> possibleUpgrades = GetPossibleSystemUpgrades(ship, systemMaxes, scrap, 0);
		std::vector<int> possibleUpgrades = ShipGenerator::GetPossibleSystemUpgrades0(ship, systemMaxes);
		if (possibleUpgrades.empty()) break;
		ShipGenerator::UpgradeSystem(ship, systemMaxes, possibleUpgrades[random32()%possibleUpgrades.size()]);
		budget[0] -= 1;
	}
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
	while (maxWeaponPower < weaponPower)
	{
		for (int i=0; i < weaponPower-maxWeaponPower; ++i)
		{
			ShipSystem *sys = ship->GetSystem(SYS_WEAPONS);
			if (sys == nullptr)
			{
				ship->AddSystem(SYS_WEAPONS);
				sys = ship->GetSystem(SYS_WEAPONS);
				std::pair<int,int> availablePower = ship->GetAvailablePower();
				PowerManager::GetPowerManager(1)->currentPower.second = availablePower.second + sys->powerState.second;
			}
			else
			{
				std::pair<int,int> availablePower = ship->GetAvailablePower();
				PowerManager::GetPowerManager(1)->currentPower.second = availablePower.second + 1;
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
	while (maxDronePower < dronePower)
	{
		for (int i=0; i < dronePower-maxDronePower; ++i)
		{
			ShipSystem *sys = ship->GetSystem(SYS_DRONES);
			if (sys == nullptr)
			{
				ship->AddSystem(SYS_DRONES);
				sys = ship->GetSystem(SYS_DRONES);
				std::pair<int,int> availablePower = ship->GetAvailablePower();
				PowerManager::GetPowerManager(1)->currentPower.second = availablePower.second + sys->powerState.second;
			}
			else
			{
				std::pair<int,int> availablePower = ship->GetAvailablePower();
				PowerManager::GetPowerManager(1)->currentPower.second = availablePower.second + 1;
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

HOOK_STATIC_PRIORITY(ShipGenerator, CreateShip, -100, (const std::string& name, int sector, ShipEvent& event) -> ShipManager*)
{
    if (!CustomShipGenerator::enabled) return super(name, sector, event);

    if (event.shipSeed != 0) srandom32(event.shipSeed);
    ShipBlueprint *bp = G_->GetBlueprints()->GetShipBlueprint(name, sector);

    CustomShipGenerator *generator = CustomShipGenerator::GetShipGenerator(bp->blueprintName);
    if (generator != nullptr)
    {
        return generator->CreateShip(bp, sector, event);
    }
    else
    {
        return super(bp->blueprintName, sector, event);
    }
}
/*
HOOK_STATIC_PRIORITY(ShipGenerator, CreateShip, 9999, (const std::string& name, int sector, ShipEvent& event) -> ShipManager*)
{
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
	while (maxWeaponPower < weaponPower)
	{
		for (int i=0; i < weaponPower-maxWeaponPower; ++i)
		{
			ShipSystem *sys = ship->GetSystem(SYS_WEAPONS);
			if (sys == nullptr)
			{
				ship->AddSystem(SYS_WEAPONS);
				sys = ship->GetSystem(SYS_WEAPONS);
				std::pair<int,int> availablePower = ship->GetAvailablePower();
				PowerManager::GetPowerManager(1)->currentPower.second = availablePower.second + sys->powerState.second;
			}
			else
			{
				std::pair<int,int> availablePower = ship->GetAvailablePower();
				PowerManager::GetPowerManager(1)->currentPower.second = availablePower.second + 1;
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
	while (maxDronePower < dronePower)
	{
		for (int i=0; i < dronePower-maxDronePower; ++i)
		{
			ShipSystem *sys = ship->GetSystem(SYS_DRONES);
			if (sys == nullptr)
			{
				ship->AddSystem(SYS_DRONES);
				sys = ship->GetSystem(SYS_DRONES);
				std::pair<int,int> availablePower = ship->GetAvailablePower();
				PowerManager::GetPowerManager(1)->currentPower.second = availablePower.second + sys->powerState.second;
			}
			else
			{
				std::pair<int,int> availablePower = ship->GetAvailablePower();
				PowerManager::GetPowerManager(1)->currentPower.second = availablePower.second + 1;
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
