#include "CommandConsole.h"
#include "ShipUnlocks.h"
#include "CustomStore.h"
#include "CustomOptions.h"
#include "CustomEvents.h"
#include "CustomShipGenerator.h"
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
    if(cmdName == "SWITCH")
    {
        if (command.length() > 7)
        {
            std::string shipName = boost::trim_copy(command.substr(7));
            hs_log_file("Loading new ship %s\n", shipName.c_str());

            ShipBlueprint* bp = G_->GetBlueprints()->GetShipBlueprint(shipName, -1);
            if (bp->blueprintName != "DEFAULT" && bp->blueprintName != G_->GetWorld()->playerShip->shipManager->myBlueprint.blueprintName)
            {
                //hs_log_file("step 0\n");
                //WorldManager *world = G_->GetWorld();
                //SpaceManager *space = &world->space;

                //world->playerShip->destructor(0);
                //hs_log_file("step 1\n");
                ShipManager *newShip = new ShipManager(0);
                newShip->OnInit(bp, 0);

                //hs_log_file("step 2\n");
                //CompleteShip *newCompleteShip = new CompleteShip(space,true, 0);
                //world->playerShip = newCompleteShip;

                //hs_log_file("step 3 bis\n");
                G_->GetWorld()->playerShip->SetShip(newShip);
                //newCompleteShip = world->playerShip;
                //CommandGui *gui = world->commandGui;

                //hs_log_file("step 3\n");
                //newCompleteShip->SetShip(newShip);
                //newCompleteShip = world->playerShip;
                //CommandGui *gui = world->commandGui;
    
                //hs_log_file("step 4\n");
                //world->starMap.shipManager = newShip;
                //gui->LinkShip(newCompleteShip);

                //hs_log_file("step 5\n");
            }
        }
        
        
        return true;
    }
    if(cmdName == "SWITCH2")
    {
        if (command.length() > 8)
        {
            // All signature exposed
            // CommandGUI::LinkShip (window/AMD64)
            // ScoreKeeper::SetShipBlueprint (window)
            // ShipGraph::Restart()
            // PowerManager::RestartAll()
            // CommandGui::Restart() (window)

            std::string shipName = boost::trim_copy(command.substr(7));
            hs_log_file("Loading new ship %s\n", shipName.c_str());
            WorldManager *world = G_->GetWorld();
            SpaceManager *space = &world->space;
            CommandGui *gui = world->commandGui;
            ScoreKeeper *scoreKeeper = G_->GetScoreKeeper();
            hs_log_file("setp 1\n");

            ShipManager *oldShip = world->playerShip->shipManager;
            for (auto i : oldShip->GetWeaponList())
                oldShip->RemoveItem(i->blueprint->name);
            hs_log_file("setp 2\n");

            //for (auto i : space->drones)
            //{
            //    hs_log_file("spacedrone\n");
            //    i->destructor();
            //}

            //for (auto i : oldShip->GetDroneList())
            //    oldShip->RemoveItem(i->blueprint->name);

            //TODO
            // Remove all deployed drone, the destructor should be taking care of that according to the code but it crashes
            // clear the beacon
            // clear system box, especially the artillery box
            // defense drone do not fire when deployed from a switched ship
            // gdb freaks out on the store::OnRender() resource_list_files_next, (most likely related to the point below) only happen with destructor() (not 2)
            // something related png in scorekeeper is the main reason for the second switch crash

            //for (auto i : gui->sysControl.sysBoxes)
            //{   
            //    hs_log_file("LookSysBox %d\n", i->pSystem->GetId());
            //    if (i->pSystem->GetId() == 11)
            //    {
            //        hs_log_file("DeletedArtiBox\n");
            //        i->destroy();
            //    }
            //}
            
            hs_log_file("setp 3\n");
            ShipBlueprint* bp = G_->GetBlueprints()->GetShipBlueprint(shipName, -1);
            hs_log_file("setp 3.1\n");
            ShipManager *ship = new ShipManager(0);
            hs_log_file("setp 3.2\n");
            ship->OnInit(bp, 0);
            
            hs_log_file("setp 4\n");
            world->playerShip->SetShip(ship);
            world->starMap.shipManager = ship;
            
            hs_log_file("setp 5\n");
            scoreKeeper->SetShipBlueprint(&shipName);

            hs_log_file("setp 6\n");

            hs_log_file("setp 7\n");
            //for (auto i : gui->storeTrash)
            //{   
            //    hs_log_file("storeTrashGUI\n");
            //    i->RelinkShip(gui->shipComplete->shipManager, &(gui->equipScreen));
            //}
            hs_log_file("setp 8\n");

            // From this point on it may be best to copy the method of CommandGui::Restart
            // Not copy, actually call it
        
            gui->LinkShip(world->playerShip);
            oldShip->destructor2();
            // Maybe do the whole WorldManager::Restart minus the reset of position
            hs_log_file("setp 9\n");
            //ShipGraph::Restart();
            //PowerManager::RestartAll();
            //gui->Restart();
            // CreateNewGamePart
            // Ship::ClearImages(&this->playerShip->shipManager->ship); those two could be nice to have, but I doubt its necessary to avoid crash
            // Ship::LoadImages(&this->playerShip->shipManager->ship);
            // space->Clear(); redundant with ClearLocation
            hs_log_file("setp 10\n");
            //world->bossShip->ClearLocation();
            
            hs_log_file("setp 11\n");
            world->ClearLocation();
            
            

            hs_log_file("Done\n");
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
