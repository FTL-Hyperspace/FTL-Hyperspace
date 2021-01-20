#pragma once
#include "Global.h"

class SaveFileHandler
{
public:
    enum class InheritMode
    {
        FORCE_OLD,
        ASK_PLAYER,
        FORCE_NEW
    };

    void CreateTransferFile();
    void DeleteTransferFile();
    bool TransferFileExists();
    void ParseSaveFileNode(rapidxml::xml_node<char>* node);
    static SaveFileHandler* instance;

    std::string savePrefix = "hs";
    bool firstTime;
    bool welcomeDialog;

    InheritMode inheritMode = InheritMode::FORCE_OLD;
    static const int version = 1;
private:

};
