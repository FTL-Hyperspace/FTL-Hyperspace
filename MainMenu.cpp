#include "MainMenu.h"
#include <boost/lexical_cast.hpp>

CustomMainMenu CustomMainMenu::instance = CustomMainMenu();

void CustomMainMenu::ParseTitleScreenNode(rapidxml::xml_node<char> *node)
{
    if (node->first_attribute("enabled"))
    {
        customTitleScreen = EventsParser::ParseBoolean(node->first_attribute("enabled")->value());
    }
    if (node->first_attribute("logo_x"))
    {
        logoX = boost::lexical_cast<int>(node->first_attribute("logo_x")->value());
    }
    if (node->first_attribute("logo_y"))
    {
        logoY = boost::lexical_cast<int>(node->first_attribute("logo_y")->value());
    }

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string name = child->name();
        std::string val = child->value();

        if (name == "splashImages")
        {
            for (auto splash = child->first_node(); splash; splash = splash->next_sibling())
            {
                if (strcmp(splash->name(), "splashImage") == 0)
                {
                    SplashImage splashImage = SplashImage();

                    if (splash->first_attribute("x"))
                        splashImage.x = boost::lexical_cast<int>(splash->first_attribute("x")->value());
                    if (splash->first_attribute("y"))
                        splashImage.y = boost::lexical_cast<int>(splash->first_attribute("y")->value());
                    if (splash->first_attribute("center"))
                        splashImage.center = EventsParser::ParseBoolean(splash->first_attribute("center")->value());
                    if (splash->first_attribute("chance"))
                        splashImage.chance = boost::lexical_cast<int>(splash->first_attribute("chance")->value());

                    splashImage.image = splash->value();

                    splashImages.push_back(splashImage);
                }
            }
        }
    }
}

static SplashImage* currentSplashImage = nullptr;
static GL_Texture* splashImageTexture = nullptr;

#ifndef __linux__
void removeItbButtonFromRenderTargets(MainMenu &mainMenu)
{
    std::vector<Button*>::iterator it = std::find(mainMenu.buttons.begin(), mainMenu.buttons.end(), &mainMenu.itbButton);
    if (it != mainMenu.buttons.end()) mainMenu.buttons.erase(it);
}
#endif

HOOK_METHOD(MainMenu, Open, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MainMenu::Open -> Begin (MainMenu.cpp)\n")
#ifndef __linux__
    // This is oddly enough only different on linux, windows and mac both feature the itb button as an extra member and an active bool
    itbButtonActive = false;
    // Make sure we're removing this->itbButton from this->buttons to prevent rendering it.
    removeItbButtonFromRenderTargets(*this);
#endif

    if (CustomMainMenu::GetInstance()->splashImages.size() > 0)
    {
        splashImageTexture = nullptr;

        auto splashImages = CustomMainMenu::GetInstance()->splashImages;
        splashImages.erase(std::remove_if(splashImages.begin(), splashImages.end(), [](const SplashImage& s) { return s.chance > 0; } ), splashImages.end());

        if (splashImages.size() > 0)
        {
            currentSplashImage = new SplashImage(splashImages[random32() % splashImages.size()]);
        }


        for (auto i : CustomMainMenu::GetInstance()->splashImages)
        {
            if (i.chance > 0)
            {
                if (random32() % 10000 <= i.chance)
                {
                    currentSplashImage = &i;
                    break;
                }
            }
        }
    }

    super();
}

/* Rewrote this to debug the crash, leaving this in in case someone needs this in the future
HOOK_METHOD_PRIORITY(ResourceControl, RenderImage, 9999, (GL_Texture* image, int x, int y, int rotation, GL_Color color, float alpha, bool mirror) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ResourceControl::RenderImage -> Begin (MainMenu.cpp)\n")

    if (image)
    {
        float size_x = (float)image->width_;
        float size_y = (float)image->height_;

        color.a = alpha;

        CSurface::GL_BlitPixelImage(image, (float)x, (float)y, size_x, size_y, (float)rotation, color, mirror );
    }
}
*/

HOOK_METHOD(ResourceControl, RenderImage, (GL_Texture* tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ResourceControl::RenderImage -> Begin (MainMenu.cpp)\n")
    if (tex == G_->GetCApp()->menu.glowy)
    {
        if (currentSplashImage)
        {
            if (!splashImageTexture)
            {
                splashImageTexture = GetImageId("main_menus/splash_" + currentSplashImage->image + ".png");
            }

            int splashX = currentSplashImage->x;
            int splashY = currentSplashImage->y;


            if (currentSplashImage->center)
            {
                splashX -= splashImageTexture->width_ / 2;
                splashY -= splashImageTexture->height_ / 2;
            }

            super(splashImageTexture, splashX, splashY, 0.f, COLOR_WHITE, 1.f, false);
        }



        return super(tex, CustomMainMenu::GetInstance()->logoX, CustomMainMenu::GetInstance()->logoY, rotation, color, opacity, mirror);
    }

    return super(tex, x, y, rotation, color, opacity, mirror);
}

HOOK_METHOD(ResourceControl, GetImageId, (const std::string& dir) -> GL_Texture*)
{
    LOG_HOOK("HOOK_METHOD -> ResourceControl::GetImageId -> Begin (MainMenu.cpp)\n")
    if (CustomMainMenu::GetInstance()->customTitleScreen)
    {
        if (dir == "main_menus/main_base2.png")
        {
            return super("main_menus/main_base2_hyperspace.png");
        }
        if (dir == "main_menus/main_FTL2.png")
        {
            return super("main_menus/main_FTL2_hyperspace.png");
        }
    }

    return super(dir);
}
