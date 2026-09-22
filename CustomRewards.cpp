#include "CustomOptions.h"
#include "CustomRewards.h"

#include <boost/lexical_cast.hpp>

static bool ARIMCostFix()
{
    return CustomOptionsManager::GetInstance()->autoRewardItemModifyCostFix.currentValue;
}

static bool ARIMOverwriteFix()
{
    return CustomOptionsManager::GetInstance()->autoRewardItemModifyOverwriteFix.currentValue;
}

static bool AutoRewardBasePriority()
{
    return CustomOptionsManager::GetInstance()->autoRewardBasePriority.currentValue;
}

CustomRewardsManager *CustomRewardsManager::instance = new CustomRewardsManager();

void CustomRewardsManager::ParseRewardsNode(rapidxml::xml_node<char> *node)
{
    try
    {
        for (auto child = node->first_node(); child; child = child->next_sibling())
        {
            if (strcmp(child->name(), "resourceRewards") == 0)
            {
                ParseResourceRewardsNode(child, defaultRewards);
            }

            if (strcmp(child->name(), "rewardScaling") == 0)
            {
                RewardScaling scaling;

                int difficulty = ParseRewardScalingNode(child, scaling);

                defaultScaling[difficulty] = scaling;
            }

            if (strcmp(child->name(), "reward") == 0)
            {
                std::string rewardName = child->first_attribute("name")->value();
                CustomRewardType newReward;

                for (auto child2 = child->first_node(); child2; child2 = child2->next_sibling())
                {
                    if (strcmp(child2->name(), "skipIfWeapon") == 0)
                    {
                        newReward.skipIfWeapon = true;
                    }
                    if (strcmp(child2->name(), "skipIfDrone") == 0)
                    {
                        newReward.skipIfDrone = true;
                    }
                    if (strcmp(child2->name(), "skipIfAugment") == 0)
                    {
                        newReward.skipIfAugment = true;
                    }

                    if (strcmp(child2->name(), "weapon") == 0)
                    {
                        newReward.weapon = true;
                    }
                    if (strcmp(child2->name(), "drone") == 0)
                    {
                        newReward.drone = true;
                    }
                    if (strcmp(child2->name(), "augment") == 0)
                    {
                        newReward.augment = true;
                    }

                    if (strcmp(child2->name(), "resourceRewards") == 0)
                    {
                        ParseResourceRewardsNode(child2, newReward.rewards);
                    }

                    if (strcmp(child2->name(), "rewardScaling") == 0)
                    {
                        RewardScaling scaling;

                        int difficulty = ParseRewardScalingNode(child2, scaling);

                        newReward.scaling[difficulty] = scaling;
                    }

                    if (strcmp(child2->name(), "reward") == 0)
                    {
                        ParseRewardGenerator(child2, newReward);
                    }
                }

                rewards[rewardName] = newReward;
            }
        }
    }
    catch (rapidxml::parse_error& e)
    {
        ErrorMessage(std::string("Error parsing <rewards> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (std::exception &e)
    {
        ErrorMessage(std::string("Error parsing <rewards> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (const char* e)
    {
        ErrorMessage(std::string("Error parsing <rewards> in hyperspace.xml\n") + std::string(e));
    }
    catch (...)
    {
        ErrorMessage("Error parsing <rewards> in hyperspace.xml\n");
    }
}

void CustomRewardsManager::ParseResourceRewardsNode(rapidxml::xml_node<char> *node, ResourceRewards& rewards)
{
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        int level = -1;
        bool isValid = false;

        std::string name = std::string(child->name());
        if (child->first_attribute("level"))
        {
            level = GetRewardLevel(child->first_attribute("level")->value());
        }

        CustomResourceReward resourceReward;
        isValid = ParseResourceNode(child, resourceReward);
        if (isValid)
        {
            if (name == "scrap")
            {
                rewards.scrap[level] = resourceReward;
            }
            else if (name == "fuel")
            {
                rewards.fuel[level] = resourceReward;
            }
            else if (name == "missiles")
            {
                rewards.missiles[level] = resourceReward;
            }
            else if (name == "droneparts")
            {
                rewards.drones[level] = resourceReward;
            }
        }

        if (name == "scrap")
        {
            CustomScrapScaling scrapScaling;
            isValid = ParseScrapScaling(child, scrapScaling);
            if (isValid)
            {
                rewards.scrapScaling[level] = scrapScaling;
            }
        }
    }
}

int CustomRewardsManager::ParseRewardScalingNode(rapidxml::xml_node<char> *node, RewardScaling& rewards)
{
    int difficulty = 1;
    if (node->first_attribute("difficulty"))
    {
        difficulty = boost::lexical_cast<int>(node->first_attribute("difficulty")->value());
    }

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        bool isValid = false;

        std::string name = std::string(child->name());

        if (name == "scrap")
        {
            CustomScrapScaling scrapScaling;
            isValid = ParseScrapScaling(child, scrapScaling);
            if (isValid)
            {
                rewards.scrap = scrapScaling;
            }
        }
    }

    return difficulty;
}

bool CustomRewardsManager::ParseScrapScaling(rapidxml::xml_node<char> *node, CustomScrapScaling& scaling)
{
    bool isValid = false;

    if (node->first_attribute("baseAmount"))
    {
        isValid = true;
        scaling.baseAmount = boost::lexical_cast<float>(node->first_attribute("baseAmount")->value());
    }

    if (node->first_attribute("sectorAmount"))
    {
        isValid = true;
        scaling.sectorAmount = boost::lexical_cast<float>(node->first_attribute("sectorAmount")->value());
    }

    if (node->first_attribute("difficultyAmount"))
    {
        isValid = true;
        scaling.difficultyAmount = boost::lexical_cast<int>(node->first_attribute("difficultyAmount")->value());
    }

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        isValid = true;
        scaling.amounts.push_back(boost::lexical_cast<float>(child->value()));
    }

    return isValid;
}

bool CustomRewardsManager::ParseResourceNode(rapidxml::xml_node<char> *node, CustomResourceReward& reward)
{
    bool isValid = false;

    if (node->first_attribute("min"))
    {
        isValid = true;
        reward.minimum = boost::lexical_cast<int>(node->first_attribute("min")->value());
    }

    if (node->first_attribute("max"))
    {
        isValid = true;
        reward.maximum = boost::lexical_cast<int>(node->first_attribute("max")->value());
    }

    return isValid;
}

void CustomRewardsManager::ParseBonusRewardNode(rapidxml::xml_node<char> *node, CustomBonusReward& rewards)
{
    if (node->first_attribute("roll"))
    {
        rewards.roll = boost::lexical_cast<int>(node->first_attribute("roll")->value());
    }
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::pair<std::string,int> bonus;
        bonus.first = child->name();
        bonus.second = 1;

        if (child->first_attribute("chance"))
        {
            bonus.second = boost::lexical_cast<int>(child->first_attribute("chance")->value());
        }

        rewards.bonusRewards.push_back(bonus);
    }
}

void CustomRewardsManager::ParseRewardGenerator(rapidxml::xml_node<char> *node, CustomRewardType& rewards)
{
    int level = -1;
    CustomRewardGenerator newRewardGenerator;

    if (node->first_attribute("level"))
    {
        level = GetRewardLevel(node->first_attribute("level")->value());
    }

    if (node->first_attribute("minResources"))
    {
        newRewardGenerator.minResources = boost::lexical_cast<int>(node->first_attribute("minResources")->value());
    }

    if (node->first_attribute("maxResources"))
    {
        newRewardGenerator.maxResources = boost::lexical_cast<int>(node->first_attribute("maxResources")->value());
    }

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        if (strcmp(child->name(), "resource") == 0)
        {
            std::string resourceName = child->first_attribute("name")->value();
            CustomReward newCustomReward;

            if (child->first_attribute("level"))
            {
                newCustomReward.overrideLevel = GetRewardLevel(child->first_attribute("level")->value());
            }

            newRewardGenerator.rewards[resourceName] = newCustomReward;
            if (resourceName != "scrap")
            {
                newRewardGenerator.resources.push_back(resourceName);
            }
        }

        if (strcmp(child->name(), "bonus") == 0)
        {
            ParseBonusRewardNode(child, newRewardGenerator.bonus);
        }
    }

    if (level == -1)
    {
        rewards.defaultRewardGenerator = newRewardGenerator;
    }
    else
    {
        rewards.rewardGenerators[level] = newRewardGenerator;
    }
}

bool CustomRewardsManager::GetCustomScrapScaling(CustomScrapScaling& ret, const std::string& type, int level)
{
    if (GenerateReward_LocalType != nullptr)
    {
        bool success = GenerateReward_LocalType->GetCustomScrapScaling(ret, type, level);
        if (success) return success;
    }

    auto it = defaultRewards.scrapScaling.find(level);
    if (it != defaultRewards.scrapScaling.end())
    {
        ret = it->second;
        ret.difficultyAmount += (1 - *G_->difficulty);
        return true;
    }

    auto scaling_it = defaultScaling.find(*G_->difficulty);
    if (scaling_it != defaultScaling.end())
    {
        ret = scaling_it->second.scrap;
        return true;
    }

    scaling_it = defaultScaling.find(1);
    if (scaling_it != defaultScaling.end())
    {
        ret = scaling_it->second.scrap;
        ret.difficultyAmount += (1 - *G_->difficulty);
        return true;
    }

    return false;
}

void CustomRewardsManager::GetCustomResourceReward(CustomResourceReward& ret, const std::string& type, int level)
{
    if (GenerateReward_LocalType != nullptr)
    {
        GenerateReward_LocalType->GetCustomResourceReward(ret, type, level);
    }

    if (type == "scrap")
    {
        auto it = defaultRewards.scrap.find(level);
        if (it != defaultRewards.scrap.end())
        {
            ret = it->second;
        }
    }
    else if (type == "fuel")
    {
        auto it = defaultRewards.fuel.find(level);
        if (it != defaultRewards.fuel.end())
        {
            ret = it->second;
        }
    }
    else if (type == "missiles")
    {
        auto it = defaultRewards.missiles.find(level);
        if (it != defaultRewards.missiles.end())
        {
            ret = it->second;
        }
    }
    else if (type == "droneparts")
    {
        auto it = defaultRewards.drones.find(level);
        if (it != defaultRewards.drones.end())
        {
            ret = it->second;
        }
    }
}

std::string CustomRewardGenerator::GetReward(ResourceEvent &resourceEvent, int level, int worldLevel, ResourceRewards& resourceRewards)
{
    std::vector<std::string> resourcesRemaining = resources;

    // Roll the number of different resource types to include.
    int numResources = minResources;
    if (maxResources > minResources)
    {
        numResources = minResources + random32()%(maxResources-minResources+1);
    }

    // Check and roll scrap reward.
    auto reward = rewards.find("scrap");
    if (reward != rewards.end())
    {
        if (reward->second.overrideLevel != -1)
        {
            GetValue(resourceEvent, "scrap", reward->second.overrideLevel, worldLevel);
        }
        else
        {
            GetValue(resourceEvent, "scrap", level, worldLevel);
        }
    }

    // Check and roll resource rewards.
    for (int i=0; i<numResources; ++i)
    {
        if (resourcesRemaining.empty()) break;

        auto it = resourcesRemaining.begin() + random32()%resourcesRemaining.size();
        std::string resource = *it;
        resourcesRemaining.erase(it);

        reward = rewards.find(resource);
        if (reward != rewards.end())
        {
            if (reward->second.overrideLevel != -1)
            {
                GetValue(resourceEvent, resource, reward->second.overrideLevel, worldLevel);
            }
            else
            {
                GetValue(resourceEvent, resource, level, worldLevel);
            }
        }
    }

    // Roll for bonus reward
    if (bonus.roll)
    {
        return bonus.GetBonusReward();
    }

    return "";
}

std::string CustomRewardType::GetReward(ResourceEvent &resourceEvent, int level, int worldLevel)
{
    auto blueprintManager = G_->GetBlueprints();

    std::string bonus = "";

    // Skip this reward if there is already an item
    if (skipIfWeapon && resourceEvent.weapon != nullptr && resourceEvent.weapon->type != -1) return bonus;
    if (skipIfDrone && resourceEvent.drone != nullptr && resourceEvent.drone->type != -1) return bonus;
    if (skipIfAugment && resourceEvent.augment != nullptr) return bonus;

    // Pick a level-specific reward generator if specified, otherwise pick the default
    auto it = rewardGenerators.find(level);
    if (it != rewardGenerators.end())
    {
        bonus = it->second.GetReward(resourceEvent, level, worldLevel, rewards);
    }
    else
    {
        bonus = defaultRewardGenerator.GetReward(resourceEvent, level, worldLevel, rewards);
    }

    // Add items
    if (weapon)
    {
        std::vector<WeaponBlueprint*> bps = blueprintManager->GetRandomWeapon(1, true);
        resourceEvent.weapon = bps[0];
    }
    if (drone)
    {
        std::vector<DroneBlueprint*> bps = blueprintManager->GetRandomDrone(1, true);
        resourceEvent.drone = bps[0];
    }
    if (augment)
    {
        std::vector<AugmentBlueprint*> bps = blueprintManager->GetRandomAugment(1, true);
        resourceEvent.augment = bps[0];
    }

    return bonus;
}

HOOK_GLOBAL(GenerateReward, (ResourceEvent &resourceEvent, RewardDesc &reward, int worldLevel) -> void)
{
    LOG_HOOK("HOOK_GLOBAL -> GenerateReward -> Begin (CustomRewards.cpp)\n")
    if (reward.level == -1) return;

    auto customRewards = CustomRewardsManager::GetInstance();
    if (customRewards == nullptr) return super(resourceEvent, reward, worldLevel);

    auto customReward = customRewards->rewards.find(reward.reward);
    if (customReward != customRewards->rewards.end())
    {
        customRewards->GenerateReward_LocalType = &(customReward->second);

        RewardDesc tempReward = reward;

        if (tempReward.level == 3)
        {
            tempReward.level = random32()%3;
        }

        std::string bonus = customReward->second.GetReward(resourceEvent, tempReward.level, worldLevel);
        if (!bonus.empty())
        {
            tempReward.reward = bonus;
            GenerateReward(resourceEvent, tempReward, worldLevel);
        }

        customRewards->GenerateReward_LocalType = nullptr;
    }
    else
    {
        super(resourceEvent, reward, worldLevel);
    }
}

HOOK_GLOBAL(GetValue, (ResourceEvent &resourceEvent, const std::string &type, int level, int worldLevel) -> void)
{
    LOG_HOOK("HOOK_GLOBAL -> GetValue -> Begin (CustomRewards.cpp)\n")
    CustomRewardsManager* customRewards = CustomRewardsManager::GetInstance();
    if (customRewards == nullptr) return super(resourceEvent, type, level, worldLevel);

    CompleteShip *playerShip = G_->GetWorld()->playerShip;
    CustomResourceReward customResource;
    customResource.SetDefault(type, level);
    customRewards->GetCustomResourceReward(customResource, type, level);
    
    if (type == "scrap" && !(ARIMCostFix() && playerShip->shipManager->currentScrap < resourceEvent.scrap * -1))
    {
        CustomScrapScaling customScaling;
        bool foundCustomScaling = false;
        foundCustomScaling = customRewards->GetCustomScrapScaling(customScaling, type, level);
        if (!foundCustomScaling) customScaling.SetDefault();

        int trueWorldLevel = G_->GetWorld()->starMap.worldLevel; // something before this func already modifies worldLevel based on difficulty, which we don't want here
        float randomScrap = customResource.GetReward();
        resourceEvent.scrap = customScaling.GetReward(trueWorldLevel, randomScrap) + (ARIMOverwriteFix() ? resourceEvent.scrap : 0);
    }
    else if (type == "fuel" && !(ARIMCostFix() && playerShip->shipManager->fuel_count < resourceEvent.fuel * -1))
    {
        resourceEvent.fuel = customResource.GetReward() + (ARIMOverwriteFix() ? resourceEvent.fuel : 0);
    }
    else if (type == "missiles" && !(ARIMCostFix() && playerShip->shipManager->GetMissileCount() < resourceEvent.missiles * -1))
    {
        resourceEvent.missiles = customResource.GetReward() + (ARIMOverwriteFix() ? resourceEvent.missiles : 0);
    }
    else if (type == "droneparts" && !(ARIMCostFix() && playerShip->shipManager->GetDroneCount() < resourceEvent.drones * -1))
    {
        resourceEvent.drones = customResource.GetReward() + (ARIMOverwriteFix() ? resourceEvent.drones : 0);
    }
}
