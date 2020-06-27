#include "freetype.h"

Pointf* freetype_hack::internalReturn = 0;


HOOK_STATIC(freetype, easy_measurePrintLines, (int fontType, float x, float y, int width, const std::string& text) -> Pointf)
{
    Pointf ret = super(fontType, x, y, width, text);

    freetype_hack::internalReturn = &ret;

    return ret;
}


Pointf& freetype_hack::easy_measurePrintLines(int fontData, float x, float y, int width, const std::string& text)
{
    freetype::easy_measurePrintLines(fontData, x, y, width, text);
    return *freetype_hack::internalReturn;
}
