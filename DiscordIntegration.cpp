#ifdef _WIN32

#include "DiscordIntegration.h"
#include <ctime>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

// Rich presence integration

DiscordHandler DiscordHandler::_instance = DiscordHandler();

void DiscordHandler::ParseDiscordNode(rapidxml::xml_node<char>* node)
{
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        if (strcmp(child->name(), "miniships") == 0) // Miniship icons for the small icon on the bottom left of presence
        {
            for (auto minishipChild = child->first_node(); minishipChild; minishipChild = minishipChild->next_sibling())
            {
                if (strcmp(minishipChild->name(), "miniship") == 0)
                {
                    miniships.push_back(minishipChild->value());
                }
            }
        }

        if (strcmp(child->name(), "appId") == 0) // App ID if the mod has a custom Discord application, needed to add your own miniships
        {
            appId = child->value();
        }

        if (strcmp(child->name(), "icon") == 0) // large icon that shows up on the left side of presence
        {
            largeImageKey = child->value();
        }
    }
}


void DiscordHandler::Initialize()
{
    DiscordEventHandlers handlers = {};

    Discord_Initialize(appId.c_str(), &handlers, 1, "212680");

    initialized = true;
}

void DiscordHandler::Shutdown()
{
    Discord_Shutdown();
    initialized = false;
}

void DiscordHandler::SetState(const std::string& state_)
{
    state = state_;
}

void DiscordHandler::SetDetails(const std::string& details_)
{
    details = details_;
}

void DiscordHandler::SetSmallImageText(const std::string& text)
{
    smallImageText = text;
}

void DiscordHandler::SetLargeImageText(const std::string& text)
{
    largeImageText = text;
}

void DiscordHandler::SetLargeImageKey(const std::string& key)
{
    largeImageKey = key;
}

void DiscordHandler::SetSmallImageKey(const std::string& key)
{
    smallImageKey = key;
}

void DiscordHandler::StartTime()
{
    startTimestamp = time(0);
}

void DiscordHandler::UpdatePresence()
{
    if (initialized &&
        (lastLargeImageKey != largeImageKey ||
         lastSmallImageKey != smallImageKey ||
         lastLargeImageText != largeImageText ||
         lastSmallImageText != smallImageText ||
         lastState != state ||
         lastDetails != details ||
         lastTime != startTimestamp)) // Only update presence if something has changed
    {
        DiscordRichPresence *presence = new DiscordRichPresence();

        presence->largeImageKey = largeImageKey.c_str();
        presence->smallImageKey = smallImageKey.c_str();
        presence->state = state.c_str();
        presence->details = details.c_str();
        presence->startTimestamp = startTimestamp;
        presence->largeImageText = largeImageText.c_str();
        presence->smallImageText = smallImageText.c_str();

        Discord_UpdatePresence(presence);

        lastState = state;
        lastDetails = details;
        lastTime = startTimestamp;
        lastLargeImageText = largeImageText;
        lastSmallImageText = smallImageText;
        lastLargeImageKey = largeImageKey;
        lastSmallImageKey = smallImageKey;
    }
}

void DiscordHandler::StopTime()
{
    startTimestamp = 0;
}

// =========================================


HOOK_METHOD(MainMenu, OnLoop, () -> void)
{
    super();

    if (!DiscordHandler::GetInstance()->Enabled())
        return;

    if (shipBuilder.bOpen)
    {
        DiscordHandler::GetInstance()->SetState(G_->GetTextLibrary()->GetText("discord_hangar"));
    }
    else
    {
        DiscordHandler::GetInstance()->SetState(G_->GetTextLibrary()->GetText("discord_main_menu"));
    }
    DiscordHandler::GetInstance()->SetDetails("");
    DiscordHandler::GetInstance()->SetSmallImageKey("");
    DiscordHandler::GetInstance()->StopTime();
    DiscordHandler::GetInstance()->UpdatePresence();
}

HOOK_METHOD(WorldManager, StartGame, (ShipManager *ship) -> void)
{
    super(ship);

    DiscordHandler::GetInstance()->StartTime();
    DiscordHandler::GetInstance()->UpdatePresence();
}

HOOK_METHOD(WorldManager, LoadGame, (const std::string& fileName) -> void)
{
    super(fileName);

    DiscordHandler::GetInstance()->StartTime();
    DiscordHandler::GetInstance()->UpdatePresence();
}

HOOK_METHOD(WorldManager, Restart, () -> void)
{
    super();

    DiscordHandler::GetInstance()->StartTime();
    DiscordHandler::GetInstance()->UpdatePresence();
}

HOOK_METHOD(StarMap, GenerateMap, (bool tutorial, bool seed) -> Location*)
{
    Location* ret = super(tutorial, seed);

    if (!DiscordHandler::GetInstance()->Enabled())
        return ret;

    std::string ship = G_->GetTextLibrary()->GetText("discord_ship");

    boost::replace_all(ship, "\\1", shipManager->myBlueprint.shipClass.GetText());

    std::string shipType = "A";
    std::string shipId = shipManager->myBlueprint.blueprintName;

    if (boost::ends_with(shipId, "_2"))
    {
        shipType = "B";
    }
    else if (boost::ends_with(shipId, "_3"))
    {
        shipType = "C";
    }

    boost::replace_all(ship, "\\2", shipType);

    std::string state = G_->GetTextLibrary()->GetText("discord_exploring");
    std::string details = G_->GetTextLibrary()->GetText("discord_sector");

    boost::replace_all(details, "\\1", currentSector->description.name.GetText());
    boost::replace_all(details, "\\2", bSecretSector ? "?" : boost::lexical_cast<std::string>(currentSector->level + 1));

    DiscordHandler::GetInstance()->SetState(state);
    DiscordHandler::GetInstance()->SetDetails(details);

    if (DiscordHandler::GetInstance()->ValidMiniship("miniship_" + shipManager->myBlueprint.imgFile))
    {
        DiscordHandler::GetInstance()->SetSmallImageKey("miniship_" + shipManager->myBlueprint.imgFile);
    }
    else
    {
        DiscordHandler::GetInstance()->SetSmallImageKey("miniship_question");
    }

    DiscordHandler::GetInstance()->SetSmallImageText(ship);
    DiscordHandler::GetInstance()->UpdatePresence();

    return ret;
}

HOOK_METHOD(WorldManager, OnLoop, () -> void)
{
    super();

    if (!DiscordHandler::GetInstance()->Enabled())
        return;

    std::string state;

    if (playerShip && playerShip->enemyShip && playerShip->enemyShip->shipManager->_targetable.hostile)
    {
        if (playerShip->enemyShip->IsBoss())
        {
            state = G_->GetTextLibrary()->GetText("discord_battle_boss");
            boost::replace_all(state, "\\1", boost::lexical_cast<std::string>(bossShip->currentStage));
        }
        else
        {
            state = G_->GetTextLibrary()->GetText("discord_battle");
        }
    }
    else
    {
        state = G_->GetTextLibrary()->GetText("discord_exploring");
    }

    if (playerShip->shipManager->bDestroyed)
    {
        state = G_->GetTextLibrary()->GetText("discord_dying");
    }

    auto gameOver = G_->GetCApp()->gui->gameOverScreen;

    if (gameOver.bOpen)
    {
        if (gameOver.bVictory)
        {
            state = G_->GetTextLibrary()->GetText("discord_victory");
        }
        else
        {
            state = G_->GetTextLibrary()->GetText("discord_dead");
        }
    }


    std::string details = G_->GetTextLibrary()->GetText("discord_sector");

    boost::replace_all(details, "\\1", starMap.currentSector->description.name.GetText());
    boost::replace_all(details, "\\2", starMap.bSecretSector ? "?" : boost::lexical_cast<std::string>(starMap.currentSector->level + 1));

    DiscordHandler::GetInstance()->SetState(state);
    DiscordHandler::GetInstance()->SetDetails(details);

    DiscordHandler::GetInstance()->UpdatePresence();
}

HOOK_METHOD(CApp, OnExit, () -> void)
{
    DiscordHandler::GetInstance()->Shutdown();
    super();
}

#endif // _WIN32
