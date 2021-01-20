#pragma once
#include "Global.h"
#include <rapidxml.hpp>

struct SplashImage
{
    int x = 10;
    int y = 10;
    bool center;
    std::string image;
    int chance = -1;
};


class CustomMainMenu
{
public:
    CustomMainMenu()
    {
    }

    void ParseTitleScreenNode(rapidxml::xml_node<char> *node);

    static CustomMainMenu* GetInstance()
    {
        return &instance;
    }

    bool customTitleScreen = false;
    int logoX = 820;
    int logoY = 60;

    std::vector<SplashImage> splashImages = std::vector<SplashImage>();

private:
    static CustomMainMenu instance;
};
