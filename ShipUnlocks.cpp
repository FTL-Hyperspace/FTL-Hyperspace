#include "ShipUnlocks.h"
#include "SaveFile.h"
#include "CustomScoreKeeper.h"
#include "SaveFile.h"
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
    }


    if (customShipUnlocks.find(shipName) == customShipUnlocks.end())
    {
        customShipUnlocks[shipName] = std::vector<ShipUnlock>();
    }

    customShipUnlocks[shipName].push_back(shipUnlock);
}

void CustomShipUnlocks::LoadVersionOne(int file)
{
    int customShipsLen = FileHelper::readInteger(file);

    for (int i = 0; i < customShipsLen; i++)
    {
        customUnlockedShips.push_back(FileHelper::readString(file));
    }
}

void CustomShipUnlocks::Save(int file)
{
    int customShipsLen = customUnlockedShips.size();

    FileHelper::writeInt(file, customShipsLen);

    for (auto i : customUnlockedShips)
    {
        FileHelper::writeString(file, i);
    }
}

void CustomShipUnlocks::UnlockShip(const std::string& ship, bool silent, bool checkMultiUnlocks)
{
    if (Global::isCustomSeed && G_->GetWorld()->bStartedGame) return;
    if (GetCustomShipUnlocked(ship)) return;

    if (!silent && customShipUnlockAchievements.find(ship) != customShipUnlockAchievements.end())
    {
        CAchievement* ach = customShipUnlockAchievements[ship];
        ach->unlocked = true;

        G_->GetAchievementTracker()->recentlyUnlocked.push_back(ach);
    }

    customUnlockedShips.push_back(ship);

    if (checkMultiUnlocks)
    {
        CheckMultiUnlocks();
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

void CustomShipUnlocks::WipeProfile()
{
    customUnlockedShips.clear();
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
    super();

    CustomShipUnlocks::instance->CreateUnlockAchievements();
}

HOOK_METHOD(ScoreKeeper, GetShipUnlocked, (int shipId, int shipVariant) -> bool)
{
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
    CustomShipUnlocks::instance->WipeProfile();

    super(permanent);
}

HOOK_METHOD(ScoreKeeper, OnInit, () -> void)
{
    CustomShipUnlocks::instance->loadVersion = 0;

    std::string versionFileName;
    FileHelper::getUserFolder(versionFileName);
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
    if (G_->GetCApp()->menu.shipBuilder.bOpen)
    {
        return;
    }

    super(ach, noPopup, sendToServer);
}

HOOK_METHOD(AchievementTracker, UnlockShip, (int type, int variant) -> void)
{
    auto ach = shipUnlocks[type][variant];
    ach->unlocked = true;
    recentlyUnlocked.push_back(ach);
}

HOOK_METHOD(StarMap, AdvanceWorldLevel, () -> void)
{
    super();

    CustomShipUnlocks::instance->CheckSectorUnlocks(G_->GetAchievementTracker()->currentShip, worldLevel);
}

HOOK_METHOD(AchievementTracker, SetVictoryAchievement, () -> void)
{
    super();

    CustomShipUnlocks::instance->CheckBasicUnlock(currentShip, ShipUnlock::UnlockType::DEFEAT_FLAGSHIP);
}

HOOK_METHOD(CommandGui, Victory, () -> void)
{
    super();

    CustomShipUnlocks::instance->CheckBasicUnlock(G_->GetAchievementTracker()->currentShip, ShipUnlock::UnlockType::VICTORY_ANY);
}

static bool loadingFile = false;

HOOK_METHOD(ScoreKeeper, UnlockShip, (int shipId, int shipType, bool save, bool hidePopup) -> void)
{
    if (loadingFile)
    {
        save = false;
        hidePopup = true;
    }

    return super(shipId, shipType, save, hidePopup);
}

HOOK_METHOD(ScoreKeeper, LoadVersionFour, (int file, int version) -> void)
{
    loadingFile = true;
    super(file, version);
    loadingFile = false;

    CustomShipUnlocks::instance->CheckMultiUnlocks();
}
