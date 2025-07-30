#include "ShipUnlocks.h"
#include "SaveFile.h"
#include "CustomAchievements.h"
#include "CustomScoreKeeper.h"
#include "SaveFile.h"
#include "Resources.h"
#include "Seeds.h"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

CustomShipUnlocks* CustomShipUnlocks::instance = new CustomShipUnlocks();

void CustomShipUnlocks::ParseUnlockNode(rapidxml::xml_node<char> *node, const std::string& shipBlueprint)
{
    ShipUnlock shipUnlock = ShipUnlock();

    int variant = 0;

    if (node->first_attribute("variant"))
    {
        std::string variantStr = node->first_attribute("variant")->value();

        if (variantStr == "b")
        {
            variant = 1;
        }
        if (variantStr == "c")
        {
            variant = 2;
        }
    }

    std::string shipName = shipBlueprint;

    if (variant == 1)
    {
        shipName.append("_2");
    }
    if (variant == 2)
    {
        shipName.append("_3");
    }

    shipUnlock.unlocksShip = shipName;

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string name = child->name();
        std::string value = child->value();

        if (name == "type")
        {
            shipUnlock.type = (ShipUnlock::UnlockType) boost::lexical_cast<int>(value);
        }
        if (name == "shipReq")
        {
            shipUnlock.shipReq = value;
        }
        if (name == "value")
        {
            shipUnlock.value = boost::lexical_cast<int>(value);
        }
        if (name == "silent")
        {
            shipUnlock.silent = EventsParser::ParseBoolean(value);
        }
        if (name == "otherUnlocks")
        {
            for (auto unlockChild = child->first_node(); unlockChild; unlockChild = unlockChild->next_sibling())
            {
                if (strcmp(unlockChild->name(), "ship") == 0)
                {
                    shipUnlock.otherRequiredShips.push_back(unlockChild->value());
                }
            }
        }
        if (name == "victories")
        {
            for (auto unlockChild = child->first_node(); unlockChild; unlockChild = unlockChild->next_sibling())
            {
                if (strcmp(unlockChild->name(), "victory") == 0)
                {
                    if (unlockChild->first_attribute("type"))
                    {
                        shipUnlock.otherRequiredShips.push_back(std::string(unlockChild->value()) + " " + std::string(unlockChild->first_attribute("type")->value()));
                    }
                    else
                    {
                        shipUnlock.otherRequiredShips.push_back(unlockChild->value());
                    }
                }
            }
        }
    }


    if (customShipUnlocks.find(shipName) == customShipUnlocks.end())
    {
        customShipUnlocks[shipName] = std::vector<ShipUnlock>();
    }

    customShipUnlocks[shipName].push_back(shipUnlock);
}

void CustomShipUnlocks::ParseVictoryAchievements(rapidxml::xml_node<char> *node)
{
    if (!node->first_attribute("noFlagship") || !EventsParser::ParseBoolean(node->first_attribute("noFlagship")->value()))
    {
        std::string vName = "flagship";
        if (customVictories.find(vName) == customVictories.end())
        {
            customVictoryTypes.push_back(vName);
        }
        CustomVictoryAchievement vAch = CustomVictoryAchievement();
        vAch.victoryName = vName;
        vAch.name.data = "victory_ach_title";
        vAch.name.isLiteral = false;
        vAch.description.data = "victory_ach";
        vAch.description.isLiteral = false;
        vAch.quiet = true;
        customVictories[vName] = vAch;
    }

    for (auto victoryNode = node->first_node(); victoryNode; victoryNode = victoryNode->next_sibling())
    {
        std::string vName = victoryNode->name();
        if (customVictories.find(vName) == customVictories.end())
        {
            customVictoryTypes.push_back(vName);
        }

        CustomVictoryAchievement vAch = CustomVictoryAchievement();
        vAch.victoryName = vName;

        for (auto child = victoryNode->first_node(); child; child = child->next_sibling())
        {
            std::string name = child->name();
            std::string value = child->value();

            if (name == "name")
            {
                if (child->first_attribute("id"))
                {
                    vAch.name.data = child->first_attribute("id")->value();
                    vAch.name.isLiteral = false;
                }
                if (!value.empty())
                {
                    vAch.name.data = value;
                    vAch.name.isLiteral = true;
                }
            }
            if (name == "description")
            {
                if (child->first_attribute("id"))
                {
                    vAch.description.data = child->first_attribute("id")->value();
                    vAch.description.isLiteral = false;
                }
                if (!value.empty())
                {
                    vAch.description.data = value;
                    vAch.description.isLiteral = true;
                }
            }
            if (name == "icon")
            {
                vAch.icon = value;
            }
            if (name == "secretName")
            {
                if (child->first_attribute("id"))
                {
                    vAch.secretName.data = child->first_attribute("id")->value();
                    vAch.secretName.isLiteral = false;
                }
                if (!value.empty())
                {
                    vAch.secretName.data = value;
                    vAch.secretName.isLiteral = true;
                }
            }
            if (name == "secretDescription")
            {
                if (child->first_attribute("id"))
                {
                    vAch.secretDescription.data = child->first_attribute("id")->value();
                    vAch.secretDescription.isLiteral = false;
                }
                if (!value.empty())
                {
                    vAch.secretDescription.data = value;
                    vAch.secretDescription.isLiteral = true;
                }
            }
            if (name == "secretIcon")
            {
                vAch.secretIcon = value;
            }
            if (name == "color")
            {
                vAch.color.a = 1.f;
                ParseColorNode(vAch.color, child, true);
            }
            if (name == "quiet")
            {
                vAch.quiet = true;
            }
            if (name == "secret")
            {
                vAch.secret = true;
            }
            if (name == "filter")
            {
                CustomShipSelect::GetInstance()->AddShipVictoryFilter(vName);
            }
        }

        customVictories[vName] = vAch;
    }
}

void CustomShipUnlocks::LoadVersionOne(int file)
{
    // customUnlockedShips

    int customShipsLen = FileHelper::readInteger(file);

    for (int i = 0; i < customShipsLen; i++)
    {
        customUnlockedShips.push_back(FileHelper::readString(file));
    }
}

void CustomShipUnlocks::LoadVersionTwo(int file)
{
    // customUnlockedShips

    int customShipsLen = FileHelper::readInteger(file);

    for (int i = 0; i < customShipsLen; i++)
    {
        customUnlockedShips.push_back(FileHelper::readString(file));
    }

    // customUnlockQuestShips

    customShipsLen = FileHelper::readInteger(file);

    for (int i = 0; i < customShipsLen; i++)
    {
        std::string k = FileHelper::readString(file);
        int v = FileHelper::readInteger(file);
        if (v != -1) customUnlockQuestShips[k] = v;
    }

    // shipVictories

    customShipsLen = FileHelper::readInteger(file);

    for (int i = 0; i < customShipsLen; i++)
    {
        std::string k = FileHelper::readString(file);
        int v = FileHelper::readInteger(file);
        if (v != -1) shipVictories[k] = v;
    }

    // customShipVictories

    customShipsLen = FileHelper::readInteger(file);

    for (int i = 0; i < customShipsLen; i++)
    {
        std::string vicName = FileHelper::readString(file);
        int length2 = FileHelper::readInteger(file);
        for (int j = 0; j < length2; j++)
        {
            std::string k = FileHelper::readString(file);
            int v = FileHelper::readInteger(file);
            if (v != -1) customShipVictories[vicName][k] = v;
        }
    }
}

void CustomShipUnlocks::Save(int file)
{
    // customUnlockedShips

    int customShipsLen = customUnlockedShips.size();

    FileHelper::writeInt(file, customShipsLen);

    for (auto i : customUnlockedShips)
    {
        FileHelper::writeString(file, i);
    }

    // customUnlockQuestShips

    customShipsLen = customUnlockQuestShips.size();

    FileHelper::writeInt(file, customShipsLen);

    for (auto i : customUnlockQuestShips)
    {
        FileHelper::writeString(file, i.first);
        FileHelper::writeInt(file, i.second);
    }

    // shipVictories

    customShipsLen = shipVictories.size();

    FileHelper::writeInt(file, customShipsLen);

    for (auto i : shipVictories)
    {
        FileHelper::writeString(file, i.first);
        FileHelper::writeInt(file, i.second);
    }

    // customShipVictories

    FileHelper::writeInt(file, customShipVictories.size());

    for (auto& i : customShipVictories)
    {
        FileHelper::writeString(file, i.first);
        FileHelper::writeInt(file, i.second.size());
        for (auto j : i.second)
        {
            FileHelper::writeString(file, j.first);
            FileHelper::writeInt(file, j.second);
        }
    }
}

void CustomShipUnlocks::UnlockShip(const std::string& ship, bool silent, bool checkMultiUnlocks, bool isEvent)
{
    // unlock the ship
    if (SeedInputBox::seedsAllowUnlocks || !Global::IsSeededRun())
    {
        if (!GetCustomShipUnlocked(ship))
        {
            if (!silent && customShipUnlockAchievements.find(ship) != customShipUnlockAchievements.end())
            {
                CAchievement* ach = customShipUnlockAchievements[ship];
                ach->unlocked = true;

                if (G_->GetSettings()->achPopups) G_->GetAchievementTracker()->recentlyUnlocked.push_back(ach);
            }

            customUnlockedShips.push_back(ship);

            if (checkMultiUnlocks)
            {
                CheckMultiUnlocks();
            }
            //Unlock vanilla achievement for having every type A if necessary
            CustomShipSelect* customSel = CustomShipSelect::GetInstance();
            bool haveAllTypeA = true;
            if (!customSel->hideFirstPage)
            {
                for (const auto& unlockedTypes : G_->GetScoreKeeper()->unlocked)
                {
                    if (!unlockedTypes[0])
                    {
                        haveAllTypeA = false;
                        break;
                    }
                }
            }

            for (int i = 0; i < customSel->customShipOrder.size(); i++)
            {
                ShipButtonDefinition* def = customSel->GetOrderedShipButtonDefinition(i);
                if (def && def->VariantExists(0) && !GetCustomShipUnlocked(def->name, 0))
                {
                    haveAllTypeA = false;
                    break;
                }
            }

            if (haveAllTypeA)
            {
                G_->GetAchievementTracker()->SetAchievement("ACH_UNLOCK_ALL", false, true);
            }
        }
    }

    // unlock quest achievements
    if (SeedInputBox::seedsAllowAchievements || !Global::IsSeededRun())
    {
        if (isEvent && CheckCustomShipUnlockQuest(ship) < *Global::difficulty)
        {
            customUnlockQuestShips[ship] = *Global::difficulty;
            int shipId = CustomShipSelect::GetInstance()->GetShipButtonIdFromName(ship);

            if (shipId != -1)
            {
                ShipButtonDefinition &buttonDef = CustomShipSelect::GetInstance()->GetShipButtonDefinition(shipId);
                CAchievement* ach;

                if (buttonDef.splitUnlockQuestAchievement)
                {
                    ach = GetQuestAchievement(ship);
                    ach->unlocked = true;
                    ach->newAchievement = true;

                    ach->difficulty = *Global::difficulty;
                }
                else
                {
                    ach = GetQuestAchievement(buttonDef.name);
                    ach->unlocked = true;
                    ach->newAchievement = true;

                    int layout = 0;
                    if (ship == buttonDef.name + "_2")
                    {
                        layout = 1;
                    }
                    else if (ship == buttonDef.name + "_3")
                    {
                        layout = 2;
                    }

                    ach->shipDifficulties[layout] = *Global::difficulty;
                    if (!(ach->gap_ex_custom&1))
                    {
                        ach->difficulty = *Global::difficulty;
                    }
                }

                if (!silent && G_->GetSettings()->achPopups)
                {
                    G_->GetAchievementTracker()->recentlyUnlocked.push_back(ach);
                }
            }
        }
    }
}

void CustomShipUnlocks::CreateUnlockAchievements()
{
    for (auto i : customShipUnlocks)
    {
        CAchievement* ach = new CAchievement();
        std::string name = i.first;

        ShipBlueprint* bp = G_->GetBlueprints()->GetShipBlueprint(name, -1);

        ach->header.data = G_->GetTextLibrary()->GetText("ship_unlocked");
        ach->header.isLiteral = true;

        std::string typeStr = "type_a";
        if (boost::algorithm::ends_with(name, "_2"))
        {
            typeStr = "type_b";
        }
        else if (boost::algorithm::ends_with(name, "_3"))
        {
            typeStr = "type_c";
        }

        ach->name.data = bp->shipClass.GetText() + "\n" + G_->GetTextLibrary()->GetText(typeStr);
        ach->name.isLiteral = true;

        std::string iconFileName = bp->layoutFile;

        if (iconFileName.find("_2") != std::string::npos)
        {
            iconFileName.replace(iconFileName.find("_2"), 2, "");
        }

        if (iconFileName.find("_3") != std::string::npos)
        {
            iconFileName.replace(iconFileName.find("_3"), 2, "");
        }

        iconFileName.append("_1.png");

        ach->icon.SetImagePath("achievements/" + iconFileName);

        customShipUnlockAchievements[name] = ach;
    }
}

void CustomShipUnlocks::OnLanguageChange()
{
    for (auto i : customShipUnlockAchievements) delete i.second;
    customShipUnlockAchievements.clear();
    CreateUnlockAchievements();

    for (auto i : customShipQuestAchievements)
    {
        SetupQuestAchievementText(i.second);
    }

    for (auto i : customShipVictoryAchievements)
    {
        SetupVictoryAchievementText(i.second);
    }

    for (auto i : customVictories)
    {
        for (auto j : i.second.achievements)
        {
            SetupVictoryAchievementText(j.second);
        }
    }
}

HOOK_METHOD(AchievementTracker, OnLanguageChange, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::OnLanguageChange -> Begin (ShipUnlocks.cpp)\n")
    super();
    CustomShipUnlocks::instance->OnLanguageChange();
}

HOOK_METHOD(AchievementTracker, ResetFlags, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::ResetFlags -> Begin (ShipUnlocks.cpp)\n")
    super();
    CustomShipUnlocks::instance->ResetFlags();
    CustomAchievementTracker::instance->ResetFlags();
}

void CustomShipUnlocks::ResetFlags()
{
    for (auto& i : customShipQuestAchievements)
    {
        i.second->newAchievement = false;
    }
    for (auto& i : customShipVictoryAchievements)
    {
        i.second->newAchievement = false;
    }
    for (auto& i : customVictories)
    {
        for (auto& j : i.second.achievements)
        {
            j.second->newAchievement = false;
        }
    }
}

void CustomShipUnlocks::LockAchievement(CAchievement *ach)
{
    ach->unlocked = false;
    ach->newAchievement = false;
    ach->difficulty = -1;
    ach->shipDifficulties[0] = -1;
    ach->shipDifficulties[1] = -1;
    ach->shipDifficulties[2] = -1;
}

void CustomShipUnlocks::WipeProfile()
{
    customUnlockedShips.clear();
    customUnlockQuestShips.clear();
    shipVictories.clear();
    customShipVictories.clear();

    for (auto i : customShipQuestAchievements) LockAchievement(i.second);
    for (auto i : customShipVictoryAchievements) LockAchievement(i.second);

    for (auto& i : customVictories)
    {
        for (auto& j : i.second.achievements)
        {
            LockAchievement(j.second);
        }
    }
}

bool CustomShipUnlocks::ValidUnlock(const ShipUnlock& unlock, const std::string& currentShip, ShipUnlock::UnlockType type)
{
    return type == unlock.type && (unlock.shipReq.empty() || unlock.shipReq == currentShip);
}

bool CustomShipUnlocks::CheckVanillaUnlocks(const ShipUnlock& unlock, const std::string& currentShip)
{
    int shipId = G_->GetScoreKeeper()->GetShipId(unlock.unlocksShip).first;

    if (shipId == -1) return false;

    int variant = 0;

    if (boost::algorithm::ends_with(unlock.unlocksShip, "_2"))
    {
        variant = 1;
    }
    if (boost::algorithm::ends_with(unlock.unlocksShip, "_3"))
    {
        variant = 2;
    }

    G_->GetScoreKeeper()->UnlockShip(shipId, variant, true, false);
    customUnlockedShips.push_back(unlock.unlocksShip);

    CheckMultiUnlocks();

    return true;
}

void CustomShipUnlocks::CheckMultiUnlocks()
{
    for (auto i : customShipUnlocks)
    {
        for (auto unlock : i.second)
        {
            if (unlock.type == ShipUnlock::UnlockType::UNLOCK_OTHER)
            {
                bool shouldUnlock = true;

                for (auto shipCheck : unlock.otherRequiredShips)
                {
                    if (!CustomShipUnlocks::instance->GetCustomShipUnlocked(shipCheck))
                    {
                        shouldUnlock = false;
                        break;
                    }
                }

                if (shouldUnlock)
                {
                    UnlockShip(i.first, unlock.silent, false);
                }
            }
        }
    }
}

void CustomShipUnlocks::CheckMultiVictoryUnlocks()
{
    for (auto i : customShipUnlocks)
    {
        for (auto unlock : i.second)
        {
            if (unlock.type == ShipUnlock::UnlockType::VICTORY_CUSTOM)
            {
                bool shouldUnlock = true;

                for (auto shipCheck : unlock.otherRequiredShips)
                {
                    std::vector<std::string> s = std::vector<std::string>();
                    boost::split(s, shipCheck, boost::is_any_of(" "));

                    if (s.size() >= 2)
                    {
                        if (CheckCustomShipVictory(s[0], s[1]) == -1)
                        {
                            shouldUnlock = false;
                            break;
                        }
                    }
                    else
                    {
                        if (CheckCustomShipVictory(shipCheck) == -1)
                        {
                            shouldUnlock = false;
                            break;
                        }
                    }
                }

                if (shouldUnlock)
                {
                    UnlockShip(i.first, unlock.silent, false);
                }
            }
        }
    }
}

// this overload checks a specific victory on its own to see if it suffices to unlock something (for when achievements are locked)
void CustomShipUnlocks::CheckMultiVictoryUnlocks(std::string &victoryShip, std::string &victoryType)
{
    for (auto i : customShipUnlocks)
    {
        for (auto unlock : i.second)
        {
            if (unlock.type == ShipUnlock::UnlockType::VICTORY_CUSTOM)
            {
                if (unlock.otherRequiredShips.size() > 1) continue; // skip any check with more than one condition

                bool shouldUnlock = true;

                for (auto shipCheck : unlock.otherRequiredShips)
                {
                    std::vector<std::string> s = std::vector<std::string>();
                    boost::split(s, shipCheck, boost::is_any_of(" "));

                    if (s.size() >= 2)
                    {
                        if (s[0] != victoryShip || s[1] != victoryType)
                        {
                            shouldUnlock = false;
                            break;
                        }
                    }
                    else
                    {
                        if (shipCheck != victoryShip)
                        {
                            shouldUnlock = false;
                            break;
                        }
                    }
                }

                if (shouldUnlock)
                {
                    UnlockShip(i.first, unlock.silent, false);
                }
            }
        }
    }
}

void CustomShipUnlocks::CheckSectorUnlocks(const std::string& currentShip, int sector)
{
    for (auto i : customShipUnlocks)
    {
        for (auto unlock : i.second)
        {
            if (ValidUnlock(unlock, currentShip, ShipUnlock::UnlockType::REACH_SECTOR))
            {
                if (sector + 1 >= unlock.value)
                {
                    if (!CheckVanillaUnlocks(unlock, currentShip))
                    {
                        UnlockShip(i.first, unlock.silent);

                    }
                }
            }
        }
    }
}

void CustomShipUnlocks::CheckBasicUnlock(const std::string& currentShip, ShipUnlock::UnlockType type)
{
    for (auto i : customShipUnlocks)
    {
        for (auto unlock : i.second)
        {
            if (ValidUnlock(unlock, currentShip, type))
            {
                if (!CheckVanillaUnlocks(unlock, currentShip))
                {
                    UnlockShip(i.first, unlock.silent);
                }
            }
        }
    }
}

void CustomShipUnlocks::UnlockAllShips()
{
    for (auto i : customShipUnlocks)
    {
        UnlockShip(i.first, true, false);
    }
}


HOOK_METHOD(AchievementTracker, LoadAchievementDescriptions, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::LoadAchievementDescriptions -> Begin (ShipUnlocks.cpp)\n")
    super();

    CustomShipUnlocks::instance->CreateUnlockAchievements();
}

HOOK_METHOD(ScoreKeeper, GetShipUnlocked, (int shipId, int shipVariant) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::GetShipUnlocked -> Begin (ShipUnlocks.cpp)\n")
    CustomShipSelect* custom = CustomShipSelect::GetInstance();

    bool isCustomShip = shipId >= 100;

    std::string shipBlueprint;

    if (isCustomShip)
    {
        shipBlueprint = custom->GetShipBlueprint(shipId);
    }
    else
    {
        shipBlueprint = GetShipBlueprint(shipId);
    }

    if (shipVariant == 1)
    {
        shipBlueprint.append("_2");
    }
    if (shipVariant == 2)
    {
        shipBlueprint.append("_3");
    }

    if (isCustomShip)
    {
        if (CustomShipUnlocks::instance->CustomShipHasUnlock(shipBlueprint))
        {
            return CustomShipUnlocks::instance->GetCustomShipUnlocked(shipBlueprint);
        }
        else
        {
            return true;
        }
    }
    else
    {
        bool ret = super(shipId, shipVariant);


        if (!ret && CustomShipUnlocks::instance->CustomShipHasUnlock(shipBlueprint))
        {
            return CustomShipUnlocks::instance->GetCustomShipUnlocked(shipBlueprint);
        }

        return ret;
    }
}

HOOK_METHOD(ScoreKeeper, UnlockShip, (int shipId, int shipType, bool save, bool hidePopup) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::UnlockShip -> Begin (ShipUnlocks.cpp)\n")
    if (shipId >= 100 || hidePopup) return super(shipId, shipType, save, hidePopup);

    auto blueprint = GetShipBlueprint(shipId);

    if (shipType == 1)
    {
        blueprint.append("_2");
    }
    if (shipType == 2)
    {
        blueprint.append("_3");
    }

    if (CustomShipUnlocks::instance->CustomShipHasUnlock(blueprint))
    {
        if (CustomShipUnlocks::instance->GetCustomShipUnlocked(blueprint))
        {
            hidePopup = true;
        }
    }

    return super(shipId, shipType, save, hidePopup);
}

HOOK_METHOD(ScoreKeeper, WipeProfile, (bool permanent) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::WipeProfile -> Begin (ShipUnlocks.cpp)\n")
    CustomShipUnlocks::instance->WipeProfile();

    super(permanent);
}

HOOK_METHOD(ScoreKeeper, OnInit, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::OnInit -> Begin (ShipUnlocks.cpp)\n")
    CustomShipUnlocks::instance->loadVersion = 0;

    std::string versionFileName = FileHelper::getUserFolder();
    versionFileName.append(SaveFileHandler::instance->savePrefix + "_version.sav");

    if (FileHelper::fileExists(versionFileName))
    {
        int versionFile = FileHelper::readBinaryFile(versionFileName);

        CustomShipUnlocks::instance->loadVersion = FileHelper::readInteger(versionFile);

        FileHelper::closeBinaryFile(versionFile);
    }

    super();
}

HOOK_METHOD(AchievementTracker, SetAchievement, (const std::string& ach, bool noPopup, bool sendToServer) -> void)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::SetAchievement -> Begin (ShipUnlocks.cpp)\n")
    if (G_->GetCApp()->menu.shipBuilder.bOpen)
    {
        return;
    }

    super(ach, noPopup, sendToServer);
}

HOOK_METHOD(AchievementTracker, UnlockShip, (int type, int variant) -> void)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::UnlockShip -> Begin (ShipUnlocks.cpp)\n")
    auto ach = shipUnlocks[type][variant];
    ach->unlocked = true;
    if (G_->GetSettings()->achPopups) recentlyUnlocked.push_back(ach);
}

HOOK_METHOD(StarMap, AdvanceWorldLevel, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::AdvanceWorldLevel -> Begin (ShipUnlocks.cpp)\n")
    super();

    CustomShipUnlocks::instance->CheckSectorUnlocks(G_->GetAchievementTracker()->currentShip, worldLevel);
}

HOOK_METHOD(AchievementTracker, SetVictoryAchievement, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::SetVictoryAchievement -> Begin (ShipUnlocks.cpp)\n")

    bool achievementsOk = SeedInputBox::seedsAllowAchievements || !Global::IsSeededRun();

    // Award normal victory achievement
    if (achievementsOk) super();
    hs_log_file("Victory achieved: %s as %s\n", CustomShipUnlocks::instance->setCustomVictoryType.c_str(), currentShip.c_str());
    if (CustomShipUnlocks::instance->setCustomVictoryType == "flagship")
    {
        CustomShipUnlocks::instance->CheckBasicUnlock(currentShip, ShipUnlock::UnlockType::DEFEAT_FLAGSHIP);
    }

    // Award specific victory achievement
    if (achievementsOk)
    {
        CustomShipUnlocks::instance->SetVictoryAchievement(currentShip);
        if (!CustomShipUnlocks::instance->setCustomVictoryType.empty())
        {
            CustomShipUnlocks::instance->SetVictoryAchievement(currentShip, CustomShipUnlocks::instance->setCustomVictoryType);
        }
    }
    else // If achievements are locked then a single specific ending unlock should still work
    {
        CustomShipUnlocks::instance->CheckMultiVictoryUnlocks(currentShip, CustomShipUnlocks::instance->setCustomVictoryType);
    }

    CustomShipUnlocks::instance->setCustomVictoryType = "flagship";

    hs_log_file("Reset custom victory type: %s\n", CustomShipUnlocks::instance->setCustomVictoryType.c_str());
}

HOOK_METHOD(CommandGui, Victory, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::Victory -> Begin (ShipUnlocks.cpp)\n")
    super();

    CustomShipUnlocks::instance->CheckBasicUnlock(G_->GetAchievementTracker()->currentShip, ShipUnlock::UnlockType::VICTORY_ANY);
}

static bool loadingFile = false;

HOOK_METHOD(ScoreKeeper, UnlockShip, (int shipId, int shipType, bool save, bool hidePopup) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::UnlockShip -> Begin (ShipUnlocks.cpp)\n")
    if (loadingFile)
    {
        save = false;
        hidePopup = true;
    }

    return super(shipId, shipType, save, hidePopup);
}

HOOK_METHOD(ScoreKeeper, LoadVersionFour, (int file, int version) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::LoadVersionFour -> Begin (ShipUnlocks.cpp)\n")
    loadingFile = true;
    super(file, version);
    loadingFile = false;

    CustomShipUnlocks::instance->CheckMultiUnlocks();
    CustomShipUnlocks::instance->CheckMultiVictoryUnlocks();
}

// Unlock Quest Achievements

CAchievement* CustomShipUnlocks::GetQuestAchievement(std::string name)
{
    auto it = customShipQuestAchievements.find(name);
    if (it != customShipQuestAchievements.end())
    {
        return it->second;
    }
    return SetupQuestAchievement(name);
}

CAchievement* CustomShipUnlocks::SetupQuestAchievement(std::string name)
{
    if (smallOutline == nullptr) smallOutline = CSurface::GL_CreateRectOutlinePrimitive(0, 0, 32, 32, GL_Color(1.f, 1.f, 1.f, 1.f), 2.f);
    if (smallOverlay == nullptr) smallOverlay = CSurface::GL_CreateRectPrimitive(0, 0, 32, 32, GL_Color(0.f, 0.f, 0.f, 0.75f));

    CAchievement *ach = new CAchievement();
    ach->gap_ex_custom = 2;
    ach->name_id = name + "_QUEST";
    ach->ship = name;
    SetupQuestAchievementText(ach);
    ach->header.data = "";
    ach->header.isLiteral = true;
    ach->newAchievement = false;
    ach->multiDifficulty = true;
    ach->difficulty = -1;
    ach->shipDifficulties[0] = -1;
    ach->shipDifficulties[1] = -1;
    ach->shipDifficulties[2] = -1;
    ach->dimension = 32;
    ach->icon.SetImagePath("achievements/S_Q_on.png");
    ach->miniIcon.SetImagePath("achievements/S_Q_on.png");
    ach->miniIconLocked.SetImagePath("achievements/S_Q_off.png");
    ach->outline = smallOutline;
    ach->mini_outline = smallOutline;
    ach->lockOverlay = smallOverlay;

    int shipId = CustomShipSelect::GetInstance()->GetShipButtonIdFromName(name);

    if (shipId != -1)
    {
        ShipButtonDefinition &buttonDef = CustomShipSelect::GetInstance()->GetShipButtonDefinition(shipId);

        if (buttonDef.splitUnlockQuestAchievement)
        {
            ach->difficulty = CheckCustomShipUnlockQuest(name);
            ach->unlocked = ach->difficulty > -1;
        }
        else
        {
            ach->shipDifficulties[0] = CheckCustomShipUnlockQuest(buttonDef.name);
            ach->shipDifficulties[1] = CheckCustomShipUnlockQuest(buttonDef.name + "_2");
            ach->shipDifficulties[2] = CheckCustomShipUnlockQuest(buttonDef.name + "_3");
            ach->unlocked = ach->shipDifficulties[0] > -1 || ach->shipDifficulties[1] > -1 || ach->shipDifficulties[2] > -1;

            if (CustomShipUnlocks::instance->CustomShipHasUnlockQuest(CustomShipSelect::GetVariantName(ach->ship,1)) ||
                CustomShipUnlocks::instance->CustomShipHasUnlockQuest(CustomShipSelect::GetVariantName(ach->ship,2)))
            {
                ach->gap_ex_custom |= 1;
            }
            else
            {
                ach->difficulty = ach->shipDifficulties[0];
            }
        }
    }

    customShipQuestAchievements[name] = ach;
    return ach;
}

void CustomShipUnlocks::SetupQuestAchievementText(CAchievement* ach)
{
    ShipBlueprint* bp = G_->GetBlueprints()->GetShipBlueprint(ach->ship, -1);

    ach->name.data = G_->GetTextLibrary()->GetText("quest_ach_title");
    boost::algorithm::replace_all(ach->name.data, "\\1", bp->shipClass.GetText());
    ach->name.isLiteral = true;

    ach->description.data = G_->GetTextLibrary()->GetText("quest_ach");
    boost::algorithm::replace_all(ach->description.data, "\\1", bp->shipClass.GetText());
    ach->description.isLiteral = true;
}

// Victory Achievements

CAchievement* CustomShipUnlocks::GetVictoryAchievement(std::string name)
{
    auto it = customShipVictoryAchievements.find(name);
    if (it != customShipVictoryAchievements.end())
    {
        return it->second;
    }
    return SetupVictoryAchievement(name);
}

CAchievement* CustomShipUnlocks::SetupVictoryAchievement(std::string name)
{
    if (smallOutline == nullptr) smallOutline = CSurface::GL_CreateRectOutlinePrimitive(0, 0, 32, 32, GL_Color(1.f, 1.f, 1.f, 1.f), 2.f);
    if (smallOverlay == nullptr) smallOverlay = CSurface::GL_CreateRectPrimitive(0, 0, 32, 32, GL_Color(0.f, 0.f, 0.f, 0.75f));

    CAchievement *ach = new CAchievement();
    ach->gap_ex_custom = 4;
    ach->name_id = name + "_VICTORY";
    ach->ship = name;
    SetupVictoryAchievementText(ach);
    ach->header.data = "";
    ach->header.isLiteral = true;
    ach->newAchievement = false;
    ach->multiDifficulty = true;
    ach->difficulty = -1;
    ach->shipDifficulties[0] = -1;
    ach->shipDifficulties[1] = -1;
    ach->shipDifficulties[2] = -1;
    ach->dimension = 32;
    ach->icon.SetImagePath("achievements/S_V_on.png");
    ach->miniIcon.SetImagePath("achievements/S_V_on.png");
    ach->miniIconLocked.SetImagePath("achievements/S_V_off.png");
    ach->outline = smallOutline;
    ach->mini_outline = smallOutline;
    ach->lockOverlay = smallOverlay;

    int shipId = CustomShipSelect::GetInstance()->GetShipButtonIdFromName(name);

    if (shipId != -1)
    {
        ShipButtonDefinition &buttonDef = CustomShipSelect::GetInstance()->GetShipButtonDefinition(shipId);

        if (buttonDef.splitVictoryAchievement)
        {
            ach->difficulty = CheckCustomShipVictory(name);
            ach->unlocked = ach->difficulty > -1;
        }
        else
        {
            ach->shipDifficulties[0] = CheckCustomShipVictory(buttonDef.name);
            ach->shipDifficulties[1] = CheckCustomShipVictory(buttonDef.name + "_2");
            ach->shipDifficulties[2] = CheckCustomShipVictory(buttonDef.name + "_3");
            ach->unlocked = ach->shipDifficulties[0] > -1 || ach->shipDifficulties[1] > -1 || ach->shipDifficulties[2] > -1;

            if (((int)buttonDef.VariantExists(0)) + ((int)buttonDef.VariantExists(1)) + ((int)buttonDef.VariantExists(2)) > 1)
            {
                ach->gap_ex_custom |= 1;
            }
            else
            {
                ach->difficulty = std::max(ach->shipDifficulties[0], std::max(ach->shipDifficulties[1], ach->shipDifficulties[2]));
            }
        }
    }

    customShipVictoryAchievements[name] = ach;
    return ach;
}

void CustomShipUnlocks::SetupVictoryAchievementText(CAchievement* ach)
{
    ShipBlueprint* bp = G_->GetBlueprints()->GetShipBlueprint(ach->ship, -1);

    ach->name.data = G_->GetTextLibrary()->GetText("victory_ach_title");
    boost::algorithm::replace_all(ach->name.data, "\\1", bp->shipClass.GetText());
    ach->name.isLiteral = true;

    ach->description.data = G_->GetTextLibrary()->GetText("victory_ach");
    boost::algorithm::replace_all(ach->description.data, "\\1", bp->shipClass.GetText());
    ach->description.isLiteral = true;
}

void CustomShipUnlocks::SetVictoryAchievement(const std::string &ship)
{
    if (!SeedInputBox::seedsAllowAchievements && Global::IsSeededRun()) return;

    auto customSel = CustomShipSelect::GetInstance();
    if (customSel->IsCustomShip(ship) && CheckCustomShipVictory(ship) < *Global::difficulty)
    {
        shipVictories[ship] = *Global::difficulty;
        int shipId = customSel->GetShipButtonIdFromName(ship);

        if (shipId != -1)
        {
            ShipButtonDefinition &buttonDef = customSel->GetShipButtonDefinition(shipId);
            CAchievement* ach;

            if (buttonDef.splitVictoryAchievement)
            {
                ach = GetVictoryAchievement(ship);
                ach->unlocked = true;
                ach->newAchievement = true;

                ach->difficulty = *Global::difficulty;
            }
            else
            {
                ach = GetVictoryAchievement(buttonDef.name);
                ach->unlocked = true;
                ach->newAchievement = true;

                int layout = 0;
                if (ship == buttonDef.name + "_2")
                {
                    layout = 1;
                }
                else if (ship == buttonDef.name + "_3")
                {
                    layout = 2;
                }

                ach->shipDifficulties[layout] = *Global::difficulty;
                if (!(ach->gap_ex_custom&1))
                {
                    ach->difficulty = *Global::difficulty;
                }
            }

            if (G_->GetSettings()->achPopups) G_->GetAchievementTracker()->recentlyUnlocked.push_back(ach);
        }
        CheckMultiVictoryUnlocks();
    }
}

void CustomShipUnlocks::SetVictoryAchievement(const std::string &ship, const std::string& type)
{
    auto customSel = CustomShipSelect::GetInstance();
    hs_log_file("Victory %s for %s: old %d new %d\n", type.c_str(), ship.c_str(), CheckCustomShipVictory(ship,type), *Global::difficulty);
    if (CheckCustomShipVictory(ship,type) < *Global::difficulty)
    {
        customShipVictories[type][ship] = *Global::difficulty;

        if (customVictories.find(type) != customVictories.end())
        {
            int shipId = customSel->GetShipButtonIdFromName(ship);

            if (shipId != -1)
            {
                ShipButtonDefinition &buttonDef = customSel->GetShipButtonDefinition(shipId);
                CAchievement* ach;

                if (buttonDef.splitVictoryAchievement)
                {
                    ach = customVictories[type].GetVictoryAchievement(ship);
                    ach->unlocked = true;
                    ach->newAchievement = true;

                    ach->difficulty = *Global::difficulty;

                    hs_log_file("Award victory achievement for %s\n", ship.c_str());
                }
                else
                {
                    ach = customVictories[type].GetVictoryAchievement(buttonDef.name);
                    ach->unlocked = true;
                    ach->newAchievement = true;

                    int layout = 0;
                    if (ship == buttonDef.name + "_2")
                    {
                        layout = 1;
                    }
                    else if (ship == buttonDef.name + "_3")
                    {
                        layout = 2;
                    }

                    hs_log_file("Award victory achievement for %s layout %d\n", buttonDef.name.c_str(), layout);

                    ach->shipDifficulties[layout] = *Global::difficulty;
                    if (!(ach->gap_ex_custom&1))
                    {
                        ach->difficulty = *Global::difficulty;
                    }
                }

                if (!customVictories[type].quiet && G_->GetSettings()->achPopups) G_->GetAchievementTracker()->recentlyUnlocked.push_back(ach);
            }
            else
            {
                std::string baseName = ship;

                int layout = 0;
                if (boost::algorithm::ends_with(baseName, "_2"))
                {
                    layout = 1;
                    baseName.resize(baseName.size()-2);
                }
                else if (boost::algorithm::ends_with(baseName, "_3"))
                {
                    layout = 2;
                    baseName.resize(baseName.size()-2);
                }

                hs_log_file("Award victory achievement for non-custom ship %s layout %d\n", baseName.c_str(), layout);

                CAchievement* ach = customVictories[type].GetVictoryAchievement(baseName);
                ach->unlocked = true;
                ach->newAchievement = true;

                ach->shipDifficulties[layout] = *Global::difficulty;

                if (!customVictories[type].quiet && G_->GetSettings()->achPopups) G_->GetAchievementTracker()->recentlyUnlocked.push_back(ach);
            }

            for (auto& i : customVictories[type].achievements)
            {
                customVictories[type].SetupVictoryAchievementText(i.second);
                customVictories[type].SetupVictoryAchievementIcon(i.second);
            }
        }
        CheckMultiVictoryUnlocks();
    }
}

CAchievement* CustomVictoryAchievement::GetVictoryAchievement(std::string shipName)
{
    auto it = achievements.find(shipName);
    if (it != achievements.end())
    {
        return it->second;
    }
    return SetupVictoryAchievement(shipName);
}

CAchievement* CustomVictoryAchievement::SetupVictoryAchievement(std::string shipName)
{
    if (CustomShipUnlocks::instance->smallOutline == nullptr) CustomShipUnlocks::instance->smallOutline = CSurface::GL_CreateRectOutlinePrimitive(0, 0, 32, 32, GL_Color(1.f, 1.f, 1.f, 1.f), 2.f);
    if (CustomShipUnlocks::instance->smallOverlay == nullptr) CustomShipUnlocks::instance->smallOverlay = CSurface::GL_CreateRectPrimitive(0, 0, 32, 32, GL_Color(0.f, 0.f, 0.f, 0.75f));

    CAchievement *ach = new CAchievement();
    ach->gap_ex_custom = 6;
    ach->name_id = shipName + "_VICTORY " + victoryName;
    ach->ship = shipName;
    SetupVictoryAchievementText(ach);
    ach->header.data = "";
    ach->header.isLiteral = true;
    ach->newAchievement = false;
    ach->multiDifficulty = true;
    ach->difficulty = -1;
    ach->shipDifficulties[0] = -1;
    ach->shipDifficulties[1] = -1;
    ach->shipDifficulties[2] = -1;
    ach->dimension = 32;
    SetupVictoryAchievementIcon(ach);
    ach->outline = CustomShipUnlocks::instance->smallOutline;
    ach->mini_outline = CustomShipUnlocks::instance->smallOutline;
    ach->lockOverlay = CustomShipUnlocks::instance->smallOverlay;

    int shipId = CustomShipSelect::GetInstance()->GetShipButtonIdFromName(shipName);

    if (shipId != -1)
    {
        ShipButtonDefinition &buttonDef = CustomShipSelect::GetInstance()->GetShipButtonDefinition(shipId);

        if (buttonDef.splitVictoryAchievement)
        {
            ach->difficulty = CustomShipUnlocks::instance->CheckCustomShipVictory(shipName, victoryName);
            ach->unlocked = ach->difficulty > -1;
        }
        else
        {
            ach->shipDifficulties[0] = CustomShipUnlocks::instance->CheckCustomShipVictory(buttonDef.name, victoryName);
            ach->shipDifficulties[1] = CustomShipUnlocks::instance->CheckCustomShipVictory(buttonDef.name + "_2", victoryName);
            ach->shipDifficulties[2] = CustomShipUnlocks::instance->CheckCustomShipVictory(buttonDef.name + "_3", victoryName);
            ach->unlocked = ach->shipDifficulties[0] > -1 || ach->shipDifficulties[1] > -1 || ach->shipDifficulties[2] > -1;

            if (((int)buttonDef.VariantExists(0)) + ((int)buttonDef.VariantExists(1)) + ((int)buttonDef.VariantExists(2)) > 1)
            {
                ach->gap_ex_custom |= 1;
            }
            else
            {
                ach->difficulty = std::max(ach->shipDifficulties[0], std::max(ach->shipDifficulties[1], ach->shipDifficulties[2]));
            }
        }
    }
    else
    {
        ach->shipDifficulties[0] = CustomShipUnlocks::instance->CheckCustomShipVictory(shipName, victoryName);
        ach->shipDifficulties[1] = CustomShipUnlocks::instance->CheckCustomShipVictory(shipName + "_2", victoryName);
        ach->shipDifficulties[2] = CustomShipUnlocks::instance->CheckCustomShipVictory(shipName + "_3", victoryName);
        ach->unlocked = ach->shipDifficulties[0] > -1 || ach->shipDifficulties[1] > -1 || ach->shipDifficulties[2] > -1;
        ach->gap_ex_custom |= 1;
    }

    achievements[shipName] = ach;
    return ach;
}

void CustomVictoryAchievement::SetupVictoryAchievementText(CAchievement* ach)
{
    ShipBlueprint* bp = G_->GetBlueprints()->GetShipBlueprint(ach->ship, -1);

    bool secretLocked = SecretLocked();

    if (secretLocked && !secretName.data.empty())
    {
        ach->name.data = secretName.GetText();
    }
    else
    {
        ach->name.data = name.GetText();
    }
    boost::algorithm::replace_all(ach->name.data, "\\1", bp->shipClass.GetText());
    ach->name.isLiteral = true;

    if (secretLocked && !secretDescription.data.empty())
    {
        ach->description.data = secretDescription.GetText();
    }
    else
    {
        ach->description.data = description.GetText();
    }
    boost::algorithm::replace_all(ach->description.data, "\\1", bp->shipClass.GetText());
    ach->description.isLiteral = true;
}

void CustomVictoryAchievement::SetupVictoryAchievementIcon(CAchievement* ach)
{
    bool secretLocked = SecretLocked();

    if (secretLocked && !secretIcon.empty())
    {
        ach->icon.SetImagePath("achievements/"+secretIcon+"_on.png");
        ach->miniIcon.SetImagePath("achievements/"+secretIcon+"_on.png");
        ach->miniIconLocked.SetImagePath("achievements/"+secretIcon+"_off.png");
    }
    else
    {
        ach->icon.SetImagePath("achievements/"+icon+"_on.png");
        ach->miniIcon.SetImagePath("achievements/"+icon+"_on.png");
        ach->miniIconLocked.SetImagePath("achievements/"+icon+"_off.png");
    }
}

bool CustomVictoryAchievement::SecretLocked()
{
    return CustomShipUnlocks::instance->customShipVictories.count(victoryName) == 0 || CustomShipUnlocks::instance->customShipVictories[victoryName].empty();
}

// Custom achievement rendering

HOOK_METHOD(CAchievement, constructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CAchievement::constructor -> Begin (ShipUnlocks.cpp)\n")
    super();
    gap_ex_custom = 0;
}

HOOK_METHOD(CAchievement, OnRender, (Point pos, int selected, bool unk) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CAchievement::OnRender -> Begin (ShipUnlocks.cpp)\n")
    if (gap_ex_custom)
    {
        if (gap_ex_custom == -127) return; // dummy achievement, don't render

        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(pos.x, pos.y, 0.f);

        if (selected < 2)
        {
            icon.OnRender(GL_Color(1.f,1.f,1.f,1.f));
            if (!unlocked)
            {
                CSurface::GL_RenderPrimitive(lockOverlay);

                if (!lockImage.texture) lockImage.CreatePrimitive();
                if (lockImage.texture)
                {
                    int halfWidth = dimension/2;

                    CSurface::GL_PushMatrix();
                    CSurface::GL_Translate(halfWidth-lockImage.texture->width_/2, halfWidth-lockImage.texture->height_/2, 0.f);

                    lockImage.OnRender(GL_Color(1.f,1.f,1.f,1.f));

                    CSurface::GL_PopMatrix();
                }
            }
        }
        else
        {
            if (!unlocked)
            {
                miniIconLocked.OnRender(GL_Color(1.f,1.f,1.f,1.f));
            }
            else
            {
                miniIcon.OnRender(GL_Color(1.f,1.f,1.f,1.f));
            }
        }

        if (newAchievement && unk)
        {
            CSurface::GL_SetColor(GL_Color(1.f, 1.f, 50.f/255.f, 1.f));
            Point newPos = {0,0};
            freetype::easy_printCenter(12, dimension/2 - newPos.x, dimension == 32 ? 17 : 47, G_->GetTextLibrary()->GetText("new_achievement"));
            CSurface::GL_SetColor(GL_Color(1.f, 1.f, 1.f, 1.f));
        }

        if (unlocked && (gap_ex_custom&1)) // last bit signals whether the achievement is tracked for each layout
        {
            CSurface::GL_PushMatrix();

            int numPips = 3;
            float xPos = 1.f;

            CSurface::GL_Translate(xPos, 24.f, 0.f);

            if ((gap_ex_custom & ~1) == 2) // quest achievement
            {
                for (int i=0; i<numPips; ++i)
                {
                    if (shipDifficulties[i] == -1)
                    {
                        if (CustomShipUnlocks::instance->CustomShipHasUnlockQuest(CustomShipSelect::GetVariantName(ship,i)))
                        {
                            dotOff.OnRender(GL_Color(1.f, 1.f, 1.f, 1.f));
                        }
                    }
                    else
                    {
                        dotOn.OnRender(GL_Color(1.f, 1.f, 1.f, 1.f));
                    }
                    CSurface::GL_Translate(10.f, 0.f, 0.f);
                }
            }
            else if ((gap_ex_custom & ~1) == 4) // victory achievement
            {
                auto customSel = CustomShipSelect::GetInstance();
                int shipId = customSel->GetShipButtonIdFromName(ship);

                ShipButtonDefinition *buttonDef = nullptr;
                if (shipId != -1)
                {
                    buttonDef = &customSel->GetShipButtonDefinition(shipId);
                }
                else
                {
                    if (ship == "PLAYER_SHIP_CRYSTAL" || ship == "PLAYER_SHIP_ANAEROBIC")
                    {
                        int numPips = 2;
                        float xPos = 6.f;
                    }
                }

                for (int i=0; i<numPips; ++i)
                {
                    if (!buttonDef || buttonDef->VariantExists(i))
                    {
                        if (shipDifficulties[i] == -1)
                        {
                            dotOff.OnRender(GL_Color(1.f, 1.f, 1.f, 1.f));
                        }
                        else
                        {
                            dotOn.OnRender(GL_Color(1.f, 1.f, 1.f, 1.f));
                        }
                    }

                    CSurface::GL_Translate(10.f, 0.f, 0.f);
                }
            }
            else if ((gap_ex_custom & ~1) == 6) // specific victory achievement
            {
                std::vector<std::string> strs;
                boost::split(strs, name_id, boost::is_any_of(" "));

                std::string victoryType = "";
                if (strs.size() > 1)
                {
                    victoryType = strs[1];
                }

                CustomVictoryAchievement &victoryAch = CustomShipUnlocks::instance->customVictories[victoryType];

                auto customSel = CustomShipSelect::GetInstance();
                int shipId = customSel->GetShipButtonIdFromName(ship);

                ShipButtonDefinition *buttonDef = nullptr;
                if (shipId != -1)
                {
                    buttonDef = &customSel->GetShipButtonDefinition(shipId);
                }
                else
                {
                    if (ship == "PLAYER_SHIP_CRYSTAL" || ship == "PLAYER_SHIP_ANAEROBIC")
                    {
                        int numPips = 2;
                        float xPos = 6.f;
                    }
                }

                for (int i=0; i<numPips; ++i)
                {
                    if (!buttonDef || buttonDef->VariantExists(i))
                    {
                        if (shipDifficulties[i] == -1)
                        {
                            dotOff.OnRender(GL_Color(1.f, 1.f, 1.f, 1.f));
                        }
                        else if (victoryAch.color.a == -1.f)
                        {
                            dotOn.OnRender(GL_Color(1.f, 1.f, 1.f, 1.f));
                        }
                        else
                        {
                            std::string imagePath = "achievements/S_V_dot_outline.png";
                            G_->GetResources()->RenderImageString(imagePath, 0, 0, 0, GL_Color(1.f,1.f,1.f,1.f), 1.f, false);
                            imagePath = "achievements/S_V_dot_white.png";
                            G_->GetResources()->RenderImageString(imagePath, 0, 0, 0, victoryAch.color, 1.f, false);
                        }
                    }

                    CSurface::GL_Translate(10.f, 0.f, 0.f);
                }
            }

            CSurface::GL_PopMatrix();
        }

        switch (selected)
        {
        case 0:
            if (dimension != 32)
            {
                CSurface::GL_RenderPrimitiveWithColor(outline, GL_Color(200.f/255.f, 200.f/255.f, 200.f/255.f, 1.f));
            }
            break;
        case 1:
            if (dimension != 32)
            {
                CSurface::GL_RenderPrimitiveWithColor(outline, GL_Color(255.f/255.f, 230.f/255.f, 94.f/255.f, 1.f));
            }
            break;
        case 2:
            CSurface::GL_RenderPrimitiveWithColor(mini_outline, GL_Color(255.f/255.f, 230.f/255.f, 94.f/255.f, 1.f));
            break;
        }

        CSurface::GL_PopMatrix();
    }
    else
    {
        super(pos, selected, unk);
    }
}

HOOK_METHOD(AchievementTracker, SetTooltip, (CAchievement *ach) -> void)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::SetTooltip -> Begin (ShipUnlocks.cpp)\n")
    if (ach->gap_ex_custom) // if this is zero it's a vanilla achievement
    {
        G_->GetMouseControl()->SetTooltipTitle(ach->name.GetText());

        std::string tooltip = ach->description.GetText();

        if (ach->unlocked && ach->multiDifficulty)
        {
            tooltip += "\n";
            if (ach->gap_ex_custom&1) // last bit signals whether the achievement is tracked for each layout
            {
                for (int i=0; i<3; ++i)
                {
                    if (ach->shipDifficulties[i] > -1)
                    {
                        std::string tooltip2 = G_->GetTextLibrary()->GetText("achieved_with");
                        switch (i)
                        {
                        case 0:
                            tooltip2 = boost::algorithm::replace_all_copy(tooltip2, "\\1", G_->GetTextLibrary()->GetText("type_a"));
                            break;
                        case 1:
                            tooltip2 = boost::algorithm::replace_all_copy(tooltip2, "\\1", G_->GetTextLibrary()->GetText("type_b"));
                            break;
                        case 2:
                            tooltip2 = boost::algorithm::replace_all_copy(tooltip2, "\\1", G_->GetTextLibrary()->GetText("type_c"));
                            break;
                        }
                        switch (ach->shipDifficulties[i])
                        {
                        case 0:
                            tooltip2 = boost::algorithm::replace_all_copy(tooltip2, "\\2", G_->GetTextLibrary()->GetText("easy"));
                            break;
                        case 1:
                            tooltip2 = boost::algorithm::replace_all_copy(tooltip2, "\\2", G_->GetTextLibrary()->GetText("normal"));
                            break;
                        case 2:
                            tooltip2 = boost::algorithm::replace_all_copy(tooltip2, "\\2", G_->GetTextLibrary()->GetText("hard"));
                            break;
                        }
                        tooltip += "\n";
                        tooltip += tooltip2;
                    }
                }
            }
            else
            {
                switch (ach->difficulty)
                {
                case 0:
                    tooltip += "\n";
                    tooltip += G_->GetTextLibrary()->GetText("ach_easy");
                    break;
                case 1:
                    tooltip += "\n";
                    tooltip += G_->GetTextLibrary()->GetText("ach_normal");
                    break;
                case 2:
                    tooltip += "\n";
                    tooltip += G_->GetTextLibrary()->GetText("ach_hard");
                    break;
                }
            }
        }

        G_->GetMouseControl()->SetTooltip(tooltip);

        G_->GetMouseControl()->InstantTooltip();
    }
    else
    {
        super(ach);
    }
}
