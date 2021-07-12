#include "CustomRewards.h"

#include <boost/lexical_cast.hpp>

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

                    if (strcmp(child2->name(), "reward") == 0)
                    {
                        ParseRewardGenerator(child2, newReward);
                    }
                }

                rewards[rewardName] = newReward;
            }
        }
    }
    catch (std::exception)
    {
        MessageBoxA(GetDesktopWindow(), "Error parsing <rewards> in hyperspace.xml", "Error", MB_ICONERROR | MB_SETFOREGROUND);
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

    return false;
}

bool CustomRewardsManager::GetCustomResourceReward(CustomResourceReward& ret, const std::string& type, int level)
{
    if (GenerateReward_LocalType != nullptr)
    {
        bool success = GenerateReward_LocalType->GetCustomResourceReward(ret, type, level);
        if (success) return success;
    }

    if (type == "scrap")
    {
        auto it = defaultRewards.scrap.find(level);
        if (it != defaultRewards.scrap.end())
        {
            ret = it->second;
            return true;
        }
    }
    else if (type == "fuel")
    {
        auto it = defaultRewards.fuel.find(level);
        if (it != defaultRewards.fuel.end())
        {
            ret = it->second;
            return true;
        }
    }
    else if (type == "missiles")
    {
        auto it = defaultRewards.missiles.find(level);
        if (it != defaultRewards.missiles.end())
        {
            ret = it->second;
            return true;
        }
    }
    else if (type == "droneparts")
    {
        auto it = defaultRewards.drones.find(level);
        if (it != defaultRewards.drones.end())
        {
            ret = it->second;
            return true;
        }
    }
    return false;
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
        auto bps = blueprintManager->GetRandomWeapon(1, true);
        resourceEvent.weapon = bps[0];
    }
    if (drone)
    {
        auto bps = blueprintManager->GetRandomDrone(1, true);
        resourceEvent.drone = bps[0];
    }
    if (augment)
    {
        auto bps = blueprintManager->GetRandomAugment(1, true);
        resourceEvent.augment = bps[0];
    }

    return bonus;
}

HOOK_GLOBAL(GenerateReward, (ResourceEvent &resourceEvent, RewardDesc &reward, int worldLevel) -> void)
{
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
    CustomRewardsManager* customRewards = CustomRewardsManager::GetInstance();
    if (customRewards == nullptr) return super(resourceEvent, type, level, worldLevel);

    CustomResourceReward customResource;
    CustomScrapScaling customScaling;

    bool foundCustomReward = false;
    bool foundCustomScaling = false;

    foundCustomReward = customRewards->GetCustomResourceReward(customResource, type, level);

    if (type == "scrap")
    {
        foundCustomScaling = customRewards->GetCustomScrapScaling(customScaling, type, level);
    }

    if (!(foundCustomReward || foundCustomScaling)) return super(resourceEvent, type, level, worldLevel);

    if (!foundCustomReward) customResource.SetDefault(type, level);

    if (type == "scrap")
    {
        if (!foundCustomScaling) customScaling.SetDefault();

        float randomScrap = customResource.GetReward();
        resourceEvent.scrap = customScaling.GetReward(worldLevel, randomScrap);
    }
    if (type == "fuel")
    {
        resourceEvent.fuel = customResource.GetReward();
    }
    else if (type == "missiles")
    {
        resourceEvent.missiles = customResource.GetReward();
    }
    else if (type == "droneparts")
    {
        resourceEvent.drones = customResource.GetReward();
    }
}
