#include "Global.h"
#include "FTLGame.h"
#include "MainMenu.h"
#include "Seeds.h"
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <fstream>
TextInput* seedInput = NULL;
int initialSectorSeed = 0;
Pointf* drawLocation = NULL;
float width = 134.f;
float height = 21.f;
bool firstClick = true;
//static bool first = true;

HOOK_GLOBAL(random32, () -> unsigned int)
{
	return rand();
}

HOOK_METHOD(ShipBuilder, constructor, () -> void)
{
	super();
	seedInput = new TextInput(10, TextInput::AllowedCharType::ALLOW_ANY, std::string("Seed"));
	drawLocation = new Pointf(1045.f, 460.f);
	seedInput->bActive = false;
}

HOOK_METHOD(ShipBuilder, OnRender, () -> void)
{
	super();
	if (seedInput)
	{
		CSurface::GL_DrawRect(drawLocation->x, drawLocation->y, width, height, GL_Color(0.f, 0.f, 0.f, 1.f));
		CSurface::GL_DrawRectOutline(drawLocation->x-1.f, drawLocation->y-1.f, width+1.f, height+1.f, COLOR_TINT, 1.f);
		seedInput->OnRender(0, Point((int)drawLocation->x+2+(width/2), (int)drawLocation->y+5));
	}
}
HOOK_METHOD(CApp, OnTextInput, (int charCode) -> void)
{
	if (seedInput)
	{
		if (seedInput->bActive)
		{
			if (charCode >= '0' && charCode <= '9')
				seedInput->OnTextInput(charCode);
			return;
		}
	}
	super(charCode);
}
HOOK_METHOD(CApp, OnTextEvent, (CEvent::TextEvent te) -> void)
{
	if (seedInput)
	{
		if (seedInput->bActive)
		{
			seedInput->OnTextEvent(te);
			return;
		}
	}
	super(te);
}

HOOK_METHOD(ShipBuilder, OnLoop, () -> void)
{
	super();
	if (seedInput)
	{
		seedInput->OnLoop();
	}
}

HOOK_METHOD(ShipBuilder, MouseClick, (int x, int y) -> void)
{
	if (seedInput)
	{
		if (x > drawLocation->x && x < drawLocation->x + width &&
			y > drawLocation->y && y < drawLocation->y + height)
		{
			if (firstClick)
			{
				seedInput->prompt = (std::string(""));
				firstClick = false;
			}
			seedInput->Start();
		}
		else
		{
			seedInput->Stop();
		}
	}
	super(x, y);
}

HOOK_METHOD(ShipBuilder, Open, () -> void)
{
	super();
	nextSeed = 0;
	firstClick = true;
}

HOOK_METHOD(StarMap, GenerateMap, (bool unk, bool seed) -> Location*)
{
	if (!seed)
	{
		this->currentSectorSeed = SeededRandom32();
	}
	else
	{
		SeededRandom32(); // generate a number so we move to the correct random state.
		printf("Incremented RNG state");
	}
	srand(this->currentSectorSeed);
	return super(unk, true);
}
HOOK_METHOD(StarMap, NewGame, (bool unk) -> Location*)
{
	std::string* str = new std::string();
	TextInput::GetText(*str, seedInput);
	if (strcmp(str->c_str(), "") == 0 || unk)
	{
		SetSeed(SeededRandom32());
	}
	else
	{
		SetSeed(boost::lexical_cast<unsigned int>(*str));
	}
	return super(unk);
}
HOOK_METHOD(StarMap, LoadGame, (int fh) -> Location*)
{
	SetSeed(1337);
	return super(fh);
}
HOOK_METHOD(StarMap, GenerateSectorMap, () -> void)
{
	this->sectorMapSeed = SeededRandom32();
	srand(this->sectorMapSeed);
	super();
}

HOOK_METHOD(StarMap, GetRandomSectorChoice, () -> int)
{
    int randN = SeededRandom32();
    int mod = randN % 10;
    int result = 2;
    if (mod > 1)
    {
        result = 3;
    }
    printf(std::string("Generated sector count: ").append(boost::lexical_cast<std::string>(result)).append(std::string("\n")).c_str());
    return result;
}
unsigned int SeededRandom32()
{
	return Global::seededRng();
}

void SetSeed(unsigned int seed)
{
	Global::seededRng = std::mt19937(seed);
	Global::currentSeed = seed;
	nextSeed = seed;
}
