#include "Global.h"

class freetype_hack
{
public:
    static Pointf& easy_measurePrintLines(int fontData, float x, float y, int width, std::string& text);
    static Pointf* internalReturn;
};
