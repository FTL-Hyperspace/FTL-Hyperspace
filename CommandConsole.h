#include "Global.h"


class CommandConsole
{
public:
    bool enabled;
    bool RunCommand(CommandGui *commandGui, std::string& command);
    static CommandConsole *GetInstance() { return &instance; }
private:
    static CommandConsole instance;
};

