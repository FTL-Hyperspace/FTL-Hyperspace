#include "CommandConsole.h"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

CommandConsole CommandConsole::instance = CommandConsole();



bool CommandConsole::RunCommand(CommandGui *commandGui, std::string& command)
{
    boost::to_upper(command);
    std::string cmdName = command.substr(0, command.find(" "));

    if (cmdName == "STORE")
    {
        if (command == "STORE")
        {
            commandGui->CreateNewStore(G_->GetWorld()->starMap.worldLevel);
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
    if (cmdName == "EXIT")
    {
        commandGui->starMap->bOpen = true;
        commandGui->starMap->bChoosingNewSector = true;

    }
    if (cmdName == "DEBUG")
    {

        return true;
    }


    return false;
}


HOOK_STATIC(Settings, GetCommandConsole, () -> char)
{
    return CommandConsole::GetInstance()->enabled;
}

HOOK_METHOD(CommandGui, RunCommand, (std::string& command) -> void)
{
    if (!CommandConsole::GetInstance()->RunCommand(this, command))
    {
        super(command);
    }
}



