#include "Global.h"
#include <vector>

struct CustomHotkey
{
    std::string hotkeyName;
    SDLKey defaultValue;
    int page;
    int index; // -1
};
extern std::vector<CustomHotkey> customHotkeys;

