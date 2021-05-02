#pragma once

class SeedInputBox
{
public:
    static bool seedsEnabled;
    static Pointf drawLocation;
    static float width;
    static float height;
    static bool firstClick;
    static TextInput *seedInput;
    static std::string prompt;
};

static unsigned int nextSeed;
unsigned int SeededRandom32();
void SetSeed(UINT);

static bool loadingMap = false;
static bool generatingMap = false;
