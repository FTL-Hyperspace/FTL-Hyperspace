#include "CustomLocalization.h"
#include <algorithm>
#include <string.h>

namespace
{

class FreeTypeFont {
    std::unique_ptr<freetype::font_data> fontData;
public:
    FreeTypeFont(const void *buffer, std::size_t bufferSize, float hDefault, bool glow, float outline):
        fontData(new freetype::font_data)
    {
        struct OutlineScope
        {
            float oldOutline;
            // TODO: FIX OUTLINE STUFF MAC
            OutlineScope(float outline)
            {
                // oldOutline = *Global_freetype_sil_freetype_outline;
                // *Global_freetype_sil_freetype_outline = outline;
            }
            ~OutlineScope()
            {
                // *Global_freetype_sil_freetype_outline = oldOutline;
            }
        } outlineScope{outline};
        fontData->init(buffer, bufferSize, hDefault, glow);
    }

    ~FreeTypeFont()
    {
        if (fontData)
            fontData->clean();
    }

    freetype::font_data* data() const {
        return fontData.get();
    }

    void AdjustForSizeType(int sizeType)
    {
        // REF: ResourceControl::GetChineseFont()
        // We don't exactly know what sizeType means for each value.
        // It's highly likely to be a kind of enum, but the default case suggests that it may also be an actual size.
        float fontSize, h, lineHeightOffset, baselineOffset;
        switch (sizeType)
        {
        case 5:
            fontSize = 11.0f;
            h = 15.0f;
            lineHeightOffset = -2.0f;
            baselineOffset = 1.0f;
            break;
        default:
            fontSize = (float)sizeType;
            h = std::roundf((fontSize * 4.0f) / 3.0f);
            lineHeightOffset = 0.0f;
            baselineOffset = 0.0f;
            break;
        case 9:
            fontSize = 13.0f;
            h = 17.0f;
            lineHeightOffset = 0.0f;
            baselineOffset = 1.0f;
            break;
        case 10:
            fontSize = 14.0f;
            h = 19.0f;
            lineHeightOffset = 1.0f;
            baselineOffset = 0.0f;
            break;
        case 0xc:
            fontSize = 16.0f;
            h = 21.0f;
            lineHeightOffset = 2.0f;
            baselineOffset = -2.0f;
            break;
        case 0xd:
            fontSize = 17.0f;
            h = 23.0f;
            lineHeightOffset = 3.0f;
            baselineOffset = -3.0f;
            break;
        case 0xe:
            fontSize = 20.0f;
            h = 27.0f;
            lineHeightOffset = 11.0f;
            baselineOffset = 7.0f;
            break;
        case 0x10:
            fontSize = 20.0f;
            h = 27.0f;
            lineHeightOffset = -3.0f;
            baselineOffset = 7.0f;
            break;
        case 0x12:
            fontSize = 32.0f;
            h = 43.0f;
            lineHeightOffset = -3.0f;
            baselineOffset = -3.0f;
            break;
        case 0x14:
            fontSize = 48.0f;
            h = 64.0f;
            lineHeightOffset = -2.0f;
            baselineOffset = -4.0f;
            break;
        case 0x18:
            fontSize = 27.0f;
            h = 36.0f;
            lineHeightOffset = 22.0f;
            baselineOffset = 13.0f;
            break;
        case 0x33:
        case 0x3d:
            fontSize = 11.0f;
            h = 15.0f;
            lineHeightOffset = -3.0f;
            baselineOffset = 0.0f;
            break;
        case 0x34:
            fontSize = 18.0f;
            h = 24.0f;
            lineHeightOffset = 3.0f;
            baselineOffset = 0.0f;
            break;
        case 0x35:
            fontSize = 27.0f;
            h = 36.0f;
            lineHeightOffset = 7.0f;
            baselineOffset = 1.0f;
            break;
        case 0x3b:
            fontSize = 18.0f;
            h = 24.0f;
            lineHeightOffset = -3.0f;
            baselineOffset = 1.0f;
            break;
        case 0x3e:
            fontSize = 16.0f;
            h = 21.0f;
            lineHeightOffset = 6.0f;
            baselineOffset = 2.0f;
            break;
        case 0x3f:
            fontSize = 24.0f;
            h = 32.0f;
            lineHeightOffset = 11.0f;
            baselineOffset = 2.0f;
            break;
        case 0x40:
            fontSize = 31.0f;
            h = 41.0f;
            lineHeightOffset = 17.0f;
            baselineOffset = 3.0f;
        }
        fontData->h = h;
        fontData->fontsize = fontSize;
        fontData->baseline = std::roundf(font_baseline(fontData->font, fontSize)) + baselineOffset;
        fontData->lineHeight = std::roundf(font_height(fontData->font, fontSize)) + lineHeightOffset;
    }
};

// Font data comes in pair: (normal, outlined).
static std::unordered_map<std::string, std::pair<FreeTypeFont*, FreeTypeFont*>> g_customFontOverrides;

void AddLanguage(const char *langcode)
{
    auto itBegin = std::begin(*Global_OptionsScreen_languageList);
    auto itEnd = std::end(*Global_OptionsScreen_languageList);
    if (std::find(itBegin, itEnd, langcode) == itEnd)
    {
        Global_OptionsScreen_languageList->push_back(langcode);
        printf("Added a new language %s.\n", langcode);
    }
}

void AddFontOverride(ResourceControl *resources, const char *langcode, const char *fontOverride)
{
    std::string unused;
    std::size_t size = 0;
    const char *buffer = resources->LoadFromResourceFile(fontOverride, size, &unused);

    printf("%s: %p %d\n", fontOverride, buffer, size);

    // REF: ResourceControl::PreloadFont()
    // h=12, no glow and outline=0.0 / 2.0 is the vanilla parameters for `fonts/zh-Hans/black.ttf`.
    // Not sure if it's relevant (h value is definitely changed in runtime by AdjustForSizeType() call)
    // or require customization (outline = 2.0 seems a good default to me?).
    // TODO: Allow customization for these values from XML?
    auto fontPair = std::make_pair(
        new FreeTypeFont{buffer, size, 12, false, 0.0f},
        new FreeTypeFont{buffer, size, 12, false, 2.0f}
    );
    if (g_customFontOverrides.insert({langcode, fontPair}).second)
    {
        printf("Added an override font %s for language %s.\n", fontOverride, langcode);
    }
}

const char *getNonEmptyAttribute(rapidxml::xml_node<char> *node, const char *attributeName)
{
    auto attr = node->first_attribute(attributeName);
    return (attr && (*attr->value() != '\0')) ? attr->value() : nullptr;
}

}

void ParseLanguagesNode(ResourceControl *resources, rapidxml::xml_node<char> *node)
{
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        if (strcmp(child->name(), "language") != 0)
            continue;

        auto langcode = getNonEmptyAttribute(child, "langcode");
        if (!langcode)
            continue;

        auto fontOverride = getNonEmptyAttribute(child, "fontOverride");
        if (fontOverride)
            AddFontOverride(resources, langcode, fontOverride);

        AddLanguage(langcode);
    }
}

HOOK_METHOD(ResourceControl, GetFontData, (int size, bool ignoreLanguage) -> freetype::font_data&)
{
    LOG_HOOK("HOOK_METHOD -> ResourceControl::GetFontData -> Begin (CustomLocalization.cpp)\n")

    if (!ignoreLanguage)
    {
        // REF: ResourceControl::GetFontData()
        if (size - 6U < 3) { size = 9; }
        else if (size == 0xb) { size = 0xc; }
        else if (size == 0) { return super(size, ignoreLanguage); }

        auto it = g_customFontOverrides.find(G_->GetTextLibrary()->currentLanguage);
        if (it != std::end(g_customFontOverrides))
        {
            auto &font = (size - 0x3eU >= 2) ? it->second.first : it->second.second;
            font->AdjustForSizeType(size);
            return *font->data();
        }
    }

    return super(size, ignoreLanguage);
}

HOOK_METHOD(LanguageChooser, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> LanguageChooser::OnRender -> Begin (CustomLocalization.cpp)\n")

    // Reimplementation summary:
    // Vanilla FTL temporarily switches language before rendering the LAST button (zh-Hans) in the list.
    // This is to make the button properly render the button text with zh-Hans font.
    // We're expanding this logic to switch language before rendering ALL buttons,
    // so that each button properly utilizes FontOverride set.

    const std::size_t numLanguages = Global_OptionsScreen_languageList->size();
    auto oldLanguage = G_->GetTextLibrary()->currentLanguage;

    Point drawPoint{496, 360 - static_cast<int>(numLanguages) * 37 / 2};
    std::string background;
    int drawHeight;
    for (std::size_t i = 0; i < numLanguages; ++i)
    {
        if (i == 0)
        {
            drawHeight = 46;
            background = "optionsUI/language_top.png";
        }
        else if (i < numLanguages - 1)
        {
            background = "optionsUI/language_mid.png";
            drawHeight = 37;
        }
        else
        {
            background = "optionsUI/language_bottom.png";
        }
        
        G_->GetResources()->RenderImageString(background, drawPoint.x, drawPoint.y, 0, COLOR_WHITE, 1.f, false);
        G_->GetTextLibrary()->SetLanguage((*Global_OptionsScreen_languageList)[i]);
        this->buttons[i]->OnRender();
        drawPoint.y += drawHeight;
    }

    G_->GetTextLibrary()->SetLanguage(oldLanguage);
}

