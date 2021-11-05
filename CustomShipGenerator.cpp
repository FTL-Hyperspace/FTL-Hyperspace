#include "CustomShipGenerator.h"

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
