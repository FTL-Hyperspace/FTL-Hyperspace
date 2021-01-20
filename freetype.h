#pragma once
#include "Global.h"

class freetype_hack
{
public:
    static Pointf& easy_measurePrintLines(int fontData, float x, float y, int width, const std::string& text);
    static Pointf& easy_printCenter(int fontData, float x, float y, const std::string& text);
    static Pointf* internalReturn;
};
