#pragma once

#include <boost/crc.hpp>

int GenerateLocationSeed(int a, int b);

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

class SeededRng
{
    std::mt19937 engine;

public:
    unsigned int seed;
    int counter;
    unsigned int current;

    SeededRng(unsigned int s)
    {
        seed = s;
        counter = 0;

        engine = std::mt19937(seed);
        current = seed;
    }

    SeededRng(unsigned int s, int c)
    {
        seed = s;
        counter = c;

        engine = std::mt19937(seed);

        if (counter >= 2)
        {
            engine.discard(counter);
            current = engine();
        }
        else if (counter == 1)
        {
            current = engine();
        }
        else
        {
            current = seed;
        }
    }

    void Import(int fh)
    {
        seed = FileHelper::readInteger(fh);
        counter = FileHelper::readInteger(fh);

        engine = std::mt19937(seed);

        if (counter >= 2)
        {
            engine.discard(counter);
            current = engine();
        }
        else if (counter == 1)
        {
            current = engine();
        }
        else
        {
            current = seed;
        }
    }

    void Export(int file)
    {
        FileHelper::writeInt(file, seed);
        FileHelper::writeInt(file, counter);
    }

    unsigned int operator()()
    {
        counter++;
        current = engine();
        return current;
    }

    void reset(unsigned int s)
    {
        seed = s;
        counter = 0;

        engine.seed(seed);
        current = seed;
    }
};

extern SeededRng worldRng;
extern SeededRng secretRng;

static unsigned int nextSeed;
unsigned int SeededRandom32();
void SetSeed(UINT);

extern bool loadingMap;
static bool generatingMap = false;
