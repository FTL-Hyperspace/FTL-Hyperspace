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

HOOK_METHOD(MainMenu, Open, () -> void)
{
#ifdef _WIN32 // At some point we need to lock this behind a FTL Version as this is 1.6.9 specific (this itbButtonActive doesn't exist in later versions)
    itbButtonActive = false;
#endif // _WIN32

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

HOOK_METHOD(ResourceControl, RenderImage, (GL_Texture* tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror) -> int)
{
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
