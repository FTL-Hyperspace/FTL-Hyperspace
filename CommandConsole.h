#pragma once
#include "Global.h"
#include <cstddef>


class CommandConsole
{
public:
    bool enabled;
    bool invertCaps = true;
    //bool shouldOpen;
    bool RunCommand(CommandGui *commandGui, const std::string& command);
    void InputData(CommandGui *commandGui, int key);
    size_t cursorPosition = 0;

    TextInput *textInput = nullptr;

    static CommandConsole *GetInstance() { return &instance; }
private:
    static CommandConsole instance;
};

class PrintHelper
{
public:
    void Render();
    void AddMessage(const std::string message);
    static PrintHelper *GetInstance() { return &instance; }

    int x = 100;
    int y = 100;
    int font = 10;
    int lineLength = 400;
    int messageLimit = 10;
    int duration = 5;
    bool useSpeed = false;

private:
    std::deque<std::string> messages;
    float timer = 0;
    static PrintHelper instance;
};

extern bool speedEnabled;

