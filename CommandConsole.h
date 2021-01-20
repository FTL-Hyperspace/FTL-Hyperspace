#pragma once
#include "Global.h"


class CommandConsole
{
public:
    bool enabled;
    bool shouldOpen;
    bool RunCommand(CommandGui *commandGui, const std::string& command);


    static CommandConsole *GetInstance() { return &instance; }
private:
    static CommandConsole instance;
};

