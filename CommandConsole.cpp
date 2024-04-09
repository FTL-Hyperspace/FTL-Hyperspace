#include "CommandConsole.h"
#include "ShipUnlocks.h"
#include "CustomStore.h"
#include "CustomOptions.h"
#include "CustomEvents.h"
#include "CustomScoreKeeper.h"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

CommandConsole CommandConsole::instance = CommandConsole();
PrintHelper PrintHelper::instance = PrintHelper();
bool speedEnabled = true;
static bool squishyTextEnabled = false;
static std::string squishyText = "";

HOOK_METHOD(MouseControl, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MouseControl::OnRender -> Begin (CommandConsole.cpp)\n")
    if(squishyTextEnabled)
        freetype::easy_printRightAlign(51, 1280.f, 10.f, squishyText.c_str());
    super();
}

bool CommandConsole::RunCommand(CommandGui *commandGui, const std::string& cmd)
{
    hs_log_file("%s\n", cmd.c_str());

    std::string command = cmd;

    std::string cmdName = command.substr(0, command.find(" "));
    boost::to_upper(cmdName);

    if (cmdName == "SQUISHY")
    {
        if (command.length() > 8)
        {
            std::string squishyTitle = boost::trim_copy(command.substr(8));
            hs_log_file("Squishy is awesome\n");
            if(!squishyTitle.empty())
            {
                squishyTextEnabled = true;
                squishyText = squishyTitle;
            }
            return true;
        }
    }
    if (cmdName == "STORE")
    {
        if (command.length() == 5)
        {
            commandGui->CreateNewStore(commandGui->starMap->worldLevel);
        }
        else
        {
            try
            {
                int sector = boost::lexical_cast<int>(boost::trim_copy(command.substr(6)));
                commandGui->CreateNewStore(sector);
            }
            catch (boost::bad_lexical_cast const &e)
            {
                printf("boost::bad_lexical_cast in RunCommand STORE\n");
            }
        }
        return true;
    }
    if (cmdName == "FORCE_STORE")
    {
        if (command.length() > 12)
        {
            std::string storeId = boost::trim_copy(command.substr(12));

            CustomStore::instance->forceCustomStore = storeId;
        }
        return true;
    }
    if (cmdName == "EXIT")
    {
        commandGui->starMap->bOpen = true;
        commandGui->starMap->bChoosingNewSector = true;
    }
    if (cmdName == "KILL" && command.length() > 5)
    {
        std::string crewName = boost::trim_copy(command.substr(5));

        for (auto i : commandGui->shipComplete->shipManager->vCrewList)
        {
            if (i->blueprint.crewName.data == crewName)
            {
                i->health.first = 0;
                break;
            }
        }
        return true;
    }
    if (cmdName == "SKILL")
    {
        for (auto i : G_->GetCrewFactory()->crewMembers)
        {
            if (i->iShipId == 0)
            { 
                for (int skill = 0; skill<6; skill++)
                {
                    i->MasterSkill(skill);
                }
            }
        }
        G_->GetSoundControl()->PlaySoundMix("levelup", -1.f, false);
    }
    if (cmdName == "DELETECREW" || cmdName == "COOLSWORDBRO")
    {
        if (commandGui->shipComplete->shipManager->current_target)
        {
            for (auto i : commandGui->shipComplete->shipManager->current_target->vCrewList)
            {
                i->health.first = 0;
            }
        }
        return true;
    }
    if (cmdName == "SPEED" && command.length() > 5)
    {
        // TODO: In the future we could force vsync off by calling `graphics_set_display_attr("vsync", 0);`
        try
        {
            int speedFactor = boost::lexical_cast<int>(boost::trim_copy(command.substr(6)));
            G_->GetCFPS()->speedLevel = speedFactor;
        }
        catch (boost::bad_lexical_cast const &e)
        {
            printf("boost::bad_lexical_cast in RunCommand SPEED\n");
        }

        return true;
    }
    if (cmdName == "LUA" && command.length() > 3)
    {
        std::string luaCode = boost::trim_copy(command.substr(4));
        Global::GetInstance()->getLuaContext()->runLuaString(luaCode);
    }
    if (command == "SYS ALL")
    {
        ShipManager *ship = commandGui->shipComplete->shipManager;
        
        for (int systemId = 0; systemId< 17; systemId++) {
            if (systemId == 16)
            {
                ship->AddSystem(20);
            } 
            else
            {
            if (!ship->HasSystem(systemId) && !(systemId == 13 && ship->HasSystem(5)) && !(systemId == 5 && ship->HasSystem(13)))
                ship->AddSystem(systemId);
            } 
        }
        return true;
    }
    if (cmdName == "DAMAGESYS" && command.length() > 9)
    {
        ShipSystem* sys = commandGui->shipComplete->shipManager->GetSystem(ShipSystem::NameToSystemId(boost::trim_copy(command.substr(10))));

        if (sys)
        {
            sys->healthState.first = 0;
        }

        return true;
    }
    if (cmdName == "DEBUG")
    {
        return true;
    }
    if (command == "SHIP ALL")
    {
        CustomShipUnlocks::instance->UnlockAllShips();
        return true;
    }
    if (cmdName == "SHIP_CUSTOM")
    {
        std::string shipName = boost::trim_copy(command.substr(11));

        if (CustomShipUnlocks::instance->CustomShipHasUnlock(shipName))
        {
            CustomShipUnlocks::instance->UnlockShip(shipName, false, true, false);
        }
        return true;
    }
    if (cmdName == "SHIP_CUSTOM_LOCK")
    {
        std::string shipName = boost::trim_copy(command.substr(16));

        CustomShipUnlocks::instance->RemoveShipUnlock(shipName);

        return true;
    }
    if(cmdName == "RICH")
    {
        commandGui->shipComplete->shipManager->ModifyScrapCount(9999999 , false);
        commandGui->shipComplete->shipManager->ModifyMissileCount(800);
        commandGui->shipComplete->shipManager->fuel_count += 800;
        commandGui->shipComplete->shipManager->ModifyDroneCount(800);
        return true;
    }
    if(cmdName == "POOR")
    {
        commandGui->shipComplete->shipManager->ModifyScrapCount(-9999999 , false);
        commandGui->shipComplete->shipManager->ModifyMissileCount(-800);
        commandGui->shipComplete->shipManager->fuel_count -= 800;
        if (commandGui->shipComplete->shipManager->fuel_count < 0) commandGui->shipComplete->shipManager->fuel_count = 0;
        commandGui->shipComplete->shipManager->ModifyDroneCount(-800);
        return true;
    }
    /*
    if(cmdName == "JUMPEVENT")
    {
        if (command.length() > 10)
        {
            jumpEvent = boost::trim_copy(command.substr(10));
        }
        else
        {
            jumpEvent = "";
        }
        jumpEventLoop = false;
        return true;
    }
    */
    if(cmdName == "LOADEVENT")
    {
        if (command.length() > 10)
        {
            std::string eventName = boost::trim_copy(command.substr(10));
            CustomEventsParser::GetInstance()->LoadEvent(G_->GetWorld(), eventName, false, -1);
        }
        return true;
    }
    if(cmdName == "VARIABLE" || cmdName == "VAR")
    {
        std::vector<std::string> cmdList = std::vector<std::string>();
        boost::split(cmdList, cmd, boost::is_any_of(" "), boost::token_compress_on);
        if (cmdList.size() >= 2)
        {
            std::string varName = cmdList[1];
            if (cmdList.size() >= 3)
            {
                try
                {
                    int v = boost::lexical_cast<int>(boost::trim_copy(cmdList[2]));
                    playerVariables[varName] = v;
                }
                catch (boost::bad_lexical_cast const &e)
                {
                    printf("boost::bad_lexical_cast in RunCommand %s\n", cmdName.c_str());
                }
            }
            hs_log_file("Variable %s = %d\n", varName.c_str(), playerVariables[varName]);
        }
        return true;
    }
    if(cmdName == "METAVARIABLE" || cmdName == "METAVAR" || cmdName == "MVAR")
    {
        std::vector<std::string> cmdList = std::vector<std::string>();
        boost::split(cmdList, cmd, boost::is_any_of(" "), boost::token_compress_on);
        if (cmdList.size() >= 2)
        {
            std::string varName = cmdList[1];
            if (cmdList.size() >= 3)
            {
                try
                {
                    int v = boost::lexical_cast<int>(boost::trim_copy(cmdList[2]));
                    metaVariables[varName] = v;
                }
                catch (boost::bad_lexical_cast const &e)
                {
                    printf("boost::bad_lexical_cast in RunCommand %s\n", cmdName.c_str());
                }
            }
            hs_log_file("Metavariable %s = %d\n", varName.c_str(), metaVariables[varName]);
        }
        return true;
    }


    return false;
}

//===============================================

static AnimationTracker *g_consoleMessage;
static bool shouldOpenConsole = true;

HOOK_METHOD(CommandGui, KeyDown, (SDLKey key, bool shiftHeld) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::KeyDown -> Begin (CommandConsole.cpp)\n")
    if (key == Settings::GetHotkey("speed"))
    {
        //shouldOpen = !shouldOpen;

        speedEnabled = !speedEnabled;
    }

    auto custom = CustomOptionsManager::GetInstance();
    if (key == Settings::GetHotkey("info"))
    {
        custom->altMode = !custom->altMode;
        custom->altModeChanged = true;
        G_->GetSoundControl()->PlaySoundMix(custom->altMode ? "moreInfoOn" : "moreInfoOff", -1.f, false);
    }

    if (CommandConsole::GetInstance()->enabled && key == Settings::GetHotkey("console"))
    {
        if (!writeErrorDialog.bOpen &&
            !menuBox.bOpen &&
            !gameOverScreen.bOpen &&
            !shipComplete->shipManager->bJumping &&
            !inputBox.bOpen &&
            key != Settings::GetHotkey("options"))
        {
            bool shouldCheckConsoleKey = true;

            for (auto i : focusWindows)
            {
                if (i->bOpen)
                {
                    shouldCheckConsoleKey = false;
                    break;
                }
            }

            if (shouldCheckConsoleKey)
            {
                inputBox.StartInput();
            }
        }
    }

    shouldOpenConsole = false;
    super(key, shiftHeld);
    shouldOpenConsole = true;
}


HOOK_STATIC(Settings, GetCommandConsole, () -> char)
{
    LOG_HOOK("HOOK_STATIC -> Settings::GetCommandConsole -> Begin (CommandConsole.cpp)\n")
    return shouldOpenConsole && CommandConsole::GetInstance()->enabled; //&& CommandConsole::GetInstance()->shouldOpen;
}

HOOK_METHOD(CommandGui, RunCommand, (std::string& command) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::RunCommand -> Begin (CommandConsole.cpp)\n")
    if (!CommandConsole::GetInstance()->RunCommand(this, command))
    {
        super(command);
        if(command == "GOD")
            PowerManager::GetPowerManager(0)->currentPower.second = CustomShipSelect::GetInstance()->GetDefinition(shipComplete->shipManager->myBlueprint.blueprintName).maxReactorLevel;
    }
}

HOOK_METHOD(CFPS, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CFPS::OnLoop -> Begin (CommandConsole.cpp)\n")
    int oldSpeedLevel = speedLevel;

    if (!speedEnabled)
    {
        speedLevel = 0;
    }

    super();

    speedLevel = oldSpeedLevel;
}

void PrintHelper::Render()
{
    if (messages.size() > 0)
    {
        if (timer <= duration)
        {
            std::string screenMessage = std::string();
            //Maybe change to just translate each message by the height of the previous one, but the Pointf.y value doesn't seem to be useful for that.
            for (const auto& message : messages)
            {
                screenMessage += message;
                screenMessage += "\n";
            }
            freetype::easy_printAutoNewlines(font, x, y, lineLength, screenMessage);
            float increment = useSpeed ? G_->GetCFPS()->GetSpeedFactor() * 0.0625 : 1.0 / G_->GetCFPS()->NumFrames;
            timer += increment;
        }
        else
        {
            timer = 0;
            messages.pop_front();
        }
    }  
}

void PrintHelper::AddMessage(const std::string message)
{

    timer = 0;
    messages.push_back(message);
    if (messages.size() > messageLimit)
    {
        messages.pop_front();
    }
}

HOOK_METHOD(MouseControl, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MouseControl::OnRender -> Begin (CommandConsole.cpp)\n")
    PrintHelper::GetInstance()->Render();
    super();
}
