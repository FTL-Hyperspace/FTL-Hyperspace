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
                ParseResourceRewardNode(child, defaultRewards);
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
                        ParseResourceRewardNode(child2, newReward.rewards);
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

void CustomRewardsManager::ParseResourceRewardNode(rapidxml::xml_node<char> *node, ResourceRewards& rewards)
{
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string name = std::string(child->name());

        if (name == "scrap")
        {
            CustomScrapReward reward;

            int level = -1;

            if (child->first_attribute("level"))
            {
                level = GetRewardLevel(child->first_attribute("level")->value());
            }

            if (child->first_attribute("min"))
            {
                reward.minimum = boost::lexical_cast<int>(child->first_attribute("min")->value());
            }

            if (child->first_attribute("max"))
            {
                reward.maximum = boost::lexical_cast<int>(child->first_attribute("max")->value());
            }

            if (child->first_attribute("baseAmount"))
            {
                reward.baseAmount = boost::lexical_cast<float>(child->first_attribute("baseAmount")->value());
            }

            if (child->first_attribute("sectorAmount"))
            {
                reward.sectorAmount = boost::lexical_cast<float>(child->first_attribute("sectorAmount")->value());
            }

            rewards.scrap[level] = reward;
        }

        if (name == "fuel")
        {
            CustomResourceReward reward;

            int level = -1;

            if (child->first_attribute("level"))
            {
                level = GetRewardLevel(child->first_attribute("level")->value());
            }

            if (child->first_attribute("min"))
            {
                reward.minimum = boost::lexical_cast<int>(child->first_attribute("min")->value());
            }

            if (child->first_attribute("max"))
            {
                reward.maximum = boost::lexical_cast<int>(child->first_attribute("max")->value());
            }

            rewards.fuel[level] = reward;
        }

        if (name == "missiles")
        {
            CustomResourceReward reward;

            int level = -1;

            if (child->first_attribute("level"))
            {
                level = GetRewardLevel(child->first_attribute("level")->value());
            }

            if (child->first_attribute("min"))
            {
                reward.minimum = boost::lexical_cast<int>(child->first_attribute("min")->value());
            }

            if (child->first_attribute("max"))
            {
                reward.maximum = boost::lexical_cast<int>(child->first_attribute("max")->value());
            }

            rewards.missiles[level] = reward;
        }

        if (name == "droneparts")
        {
            CustomResourceReward reward;

            int level = -1;

            if (child->first_attribute("level"))
            {
                level = GetRewardLevel(child->first_attribute("level")->value());
            }

            if (child->first_attribute("min"))
            {
                reward.minimum = boost::lexical_cast<int>(child->first_attribute("min")->value());
            }

            if (child->first_attribute("max"))
            {
                reward.maximum = boost::lexical_cast<int>(child->first_attribute("max")->value());
            }

            rewards.drones[level] = reward;
        }
    }
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

bool ResourceRewards::GetReward(ResourceEvent &resourceEvent, const std::string &type, int level, int worldLevel)
{
    if (type == "scrap")
    {
        auto it = scrap.find(level);
        if (it != scrap.end())
        {
            resourceEvent.scrap = it->second.GetReward(worldLevel);
            return true;
        }
    }
    else if (type == "fuel")
    {
        auto it = fuel.find(level);
        if (it != fuel.end())
        {
            resourceEvent.fuel = it->second.GetReward();
            return true;
        }
    }
    else if (type == "missiles")
    {
        auto it = missiles.find(level);
        if (it != missiles.end())
        {
            resourceEvent.missiles = it->second.GetReward();
            return true;
        }
    }
    else if (type == "droneparts")
    {
        auto it = drones.find(level);
        if (it != drones.end())
        {
            resourceEvent.drones = it->second.GetReward();
            return true;
        }
    }
    return false;
}

std::string CustomRewardGenerator::GetReward(ResourceEvent &resourceEvent, int level, int worldLevel, ResourceRewards& resourceRewards)
{
    std::vector<std::string> resourcesRemaining = resources;

    bool hasCustom;

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
            hasCustom = resourceRewards.GetReward(resourceEvent, "scrap", reward->second.overrideLevel, worldLevel);
            if (!hasCustom) GetValue(resourceEvent, "scrap", reward->second.overrideLevel, worldLevel);
        }
        else
        {
            hasCustom = resourceRewards.GetReward(resourceEvent, "scrap", level, worldLevel);
            if (!hasCustom) GetValue(resourceEvent, "scrap", level, worldLevel);
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
                hasCustom = resourceRewards.GetReward(resourceEvent, resource, reward->second.overrideLevel, worldLevel);
                if (!hasCustom) GetValue(resourceEvent, resource, reward->second.overrideLevel, worldLevel);
            }
            else
            {
                hasCustom = resourceRewards.GetReward(resourceEvent, resource, level, worldLevel);
                if (!hasCustom) GetValue(resourceEvent, resource, level, worldLevel);
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

    auto customReward = customRewards->rewards.find(reward.reward);
    if (customReward != customRewards->rewards.end())
    {
        RewardDesc tempReward = reward;

        int rewardWorldLevel = worldLevel;
        if (*G_->difficulty == 0)
        {
            rewardWorldLevel += 1; // EASY
        }
        else if (*G_->difficulty == 2 && rewardWorldLevel > 0)
        {
            rewardWorldLevel -= 1; // HARD
        }

        if (tempReward.level == 3)
        {
            tempReward.level = random32()%3;
        }

        std::string bonus = customReward->second.GetReward(resourceEvent, tempReward.level, rewardWorldLevel);
        if (!bonus.empty())
        {
            tempReward.reward = bonus;
            GenerateReward(resourceEvent, tempReward, worldLevel);
        }
    }
    else
    {
        super(resourceEvent, reward, worldLevel);
    }
}

HOOK_GLOBAL(GetValue, (ResourceEvent &resourceEvent, const std::string &type, int level, int worldLevel) -> void)
{
    bool hasCustom = CustomRewardsManager::GetInstance()->defaultRewards.GetReward(resourceEvent, type, level, worldLevel);
    if (!hasCustom)
    {
        super(resourceEvent, type, level, worldLevel);
    }
}
