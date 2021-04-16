#include "CommandConsole.h"
#include "ShipUnlocks.h"
#include "CustomStore.h"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

CommandConsole CommandConsole::instance = CommandConsole();

int speedEnabled = true;

bool CommandConsole::RunCommand(CommandGui *commandGui, const std::string& cmd)
{
    std::string command = cmd;

    std::string cmdName = command.substr(0, command.find(" "));
    boost::to_upper(cmdName);

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
    if (cmdName == "DELETECREW")
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
            CustomShipUnlocks::instance->UnlockShip(shipName, false, true);
        }
        return true;
    }


    return false;
}

//===============================================

static AnimationTracker *g_consoleMessage;


HOOK_METHOD(CommandGui, KeyDown, (SDLKey key, bool shiftHeld) -> void)
{
    // TODO: Allow user to customise speedhack and console key

    if (key == 96)
    {
        //shouldOpen = !shouldOpen;

        speedEnabled = !speedEnabled;
    }

    super(key, shiftHeld);
}


HOOK_STATIC(Settings, GetCommandConsole, () -> char)
{
    return CommandConsole::GetInstance()->enabled; //&& CommandConsole::GetInstance()->shouldOpen;
}

HOOK_METHOD(CommandGui, RunCommand, (std::string& command) -> void)
{
    if (!CommandConsole::GetInstance()->RunCommand(this, command))
    {
        super(command);
    }
}

HOOK_METHOD(CFPS, OnLoop, () -> void)
{
    int oldSpeedLevel = speedLevel;

    if (!speedEnabled)
    {
        speedLevel = 0;
    }

    super();

    speedLevel = oldSpeedLevel;
}

