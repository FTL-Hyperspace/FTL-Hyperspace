#include "CommandConsole.h"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

CommandConsole CommandConsole::instance = CommandConsole();


bool CommandConsole::RunCommand(CommandGui *commandGui, const std::string& cmd)
{
    std::string command = cmd;
    boost::to_upper(command);

    std::string cmdName = command.substr(0, command.find(" "));

    if (cmdName == "STORE")
    {
        if (command == "STORE")
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
    if (cmdName == "EXIT")
    {
        commandGui->starMap->bOpen = true;
        commandGui->starMap->bChoosingNewSector = true;
    }
    if (cmdName == "BOSS")
    {
        //printf("%08X\n", G_->GetWorld()->bossShip);
        //G_->GetWorld()->CreateShip(NULL, true);
        //commandGui->starMap->SetBossStage(8);
    }
    if (cmdName == "DEBUG")
    {

        return true;
    }


    return false;
}

//===============================================

static AnimationTracker *g_consoleMessage;


HOOK_METHOD(CommandGui, constructor, () -> void)
{
    super();

    //g_consoleMessage = new AnimationTracker();
    //g_consoleMessage->time = 2.f;
    //g_consoleMessage->loop = true;
    //g_consoleMessage->Start(0.f);
}

HOOK_METHOD(CommandGui, RenderStatic, () -> void)
{
    super();

    //g_consoleMessage->Update()
}


HOOK_METHOD(CommandGui, KeyDown, (SDLKey key, bool shiftHeld) -> void)
{
    if (shiftHeld && key == SDLKey::SDLK_F9)
    {
        //shouldOpen = !shouldOpen;


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



