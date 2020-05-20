#include "Global.h"
#include "FTLGame.h"
#include "MainMenu.h"
#include "Seeds.h"
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <fstream>


int initialSectorSeed = 0;

TextInput* SeedInputBox::seedInput;
Pointf SeedInputBox::drawLocation;
float SeedInputBox::width = 158.f;
float SeedInputBox::height = 21.f;
bool SeedInputBox::firstClick = true;
std::string SeedInputBox::prompt;

HOOK_GLOBAL(random32, () -> unsigned int)
{
	return rand();
}

HOOK_METHOD(ShipBuilder, constructor, () -> void)
{
	super();
	SeedInputBox::seedInput = new TextInput(9, TextInput::AllowedCharType::ALLOW_ANY, "");
	SeedInputBox::drawLocation = Pointf(1079.f, 71.f);
	SeedInputBox::seedInput->bActive = false;
}


HOOK_METHOD(ShipBuilder, Open, () -> void)
{
	super();
	nextSeed = 0;
	SeedInputBox::firstClick = true;

	std::string txt;
    TextLibrary::GetText(txt, G_->GetTextLibrary(), "seed_prompt", G_->GetTextLibrary()->currentLanguage);
    SeedInputBox::prompt = txt;

    SeedInputBox::seedInput->SetText("");
    SeedInputBox::seedInput->prompt = std::string(SeedInputBox::prompt);

    startButton.position.y = 15;
    startButton.hitbox.y = 15;
}

HOOK_METHOD(CApp, OnTextInput, (int charCode) -> void)
{
	if (SeedInputBox::seedInput)
	{
		if (SeedInputBox::seedInput->bActive)
		{
			if (charCode >= '0' && charCode <= '9')
				SeedInputBox::seedInput->OnTextInput(charCode);
			return;
		}
	}
	super(charCode);
}

HOOK_METHOD(CApp, OnTextEvent, (CEvent::TextEvent te) -> void)
{
	if (SeedInputBox::seedInput)
	{
		if (SeedInputBox::seedInput->bActive)
		{
			SeedInputBox::seedInput->OnTextEvent(te);
			return;
		}
	}
	super(te);
}

HOOK_METHOD(ShipBuilder, OnKeyDown, (SDLKey key) -> void)
{
    if (SeedInputBox::seedInput && SeedInputBox::seedInput->GetActive())
        return;

    super(key);
}

HOOK_METHOD(ShipBuilder, OnLoop, () -> void)
{
	super();
	if (SeedInputBox::seedInput && !bRenaming)
	{
		SeedInputBox::seedInput->OnLoop();
	}

    G_->GetMouseControl()->bHideMouse = bRenaming || SeedInputBox::seedInput->GetActive();
}

HOOK_METHOD(ShipBuilder, MouseMove, (int x, int y) -> void)
{
    if (SeedInputBox::seedInput->GetActive())
        return;

    super(x, y);
}

HOOK_METHOD(ShipBuilder, MouseClick, (int x, int y) -> void)
{
	if (SeedInputBox::seedInput && !bRenaming)
	{
		if (x > SeedInputBox::drawLocation.x && x < SeedInputBox::drawLocation.x + SeedInputBox::width &&
			y > SeedInputBox::drawLocation.y && y < SeedInputBox::drawLocation.y + SeedInputBox::height)
		{
			if (SeedInputBox::firstClick)
			{
				SeedInputBox::seedInput->prompt = std::string("");
				SeedInputBox::firstClick = false;
			}
			SeedInputBox::seedInput->Start();

		}
		else
		{
			SeedInputBox::seedInput->Stop();
		}
	}

    if (SeedInputBox::seedInput->GetActive())
        return;

	super(x, y);
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
	}
	srand(this->currentSectorSeed);
	return super(unk, true);
}

HOOK_METHOD(AchievementTracker, SetAchievement, (const std::string& ach, bool noPopup, bool sendToServer) -> void)
{
    if (Global::isCustomSeed && G_->GetWorld()->bStartedGame)
    {
        return;
    }

    return super(ach, noPopup, sendToServer);
}

HOOK_METHOD(ScoreKeeper, UnlockShip, (int shipId, int shipType, bool save, bool hidePopup) -> void)
{
    if (Global::isCustomSeed && G_->GetWorld()->bStartedGame)
    {
        return;
    }

    return super(shipId, shipType, save, hidePopup);
}

HOOK_METHOD(StarMap, NewGame, (bool unk) -> Location*)
{
	std::string str = std::string();
	TextInput::GetText(str, SeedInputBox::seedInput);
	if (str == "" || unk)
	{
		SetSeed(SeededRandom32());
		Global::isCustomSeed = false;
	}
	else
	{
		SetSeed(boost::lexical_cast<unsigned int>(str));
		Global::isCustomSeed = true;
	}
	return super(unk);
}

HOOK_METHOD(StarMap, LoadGame, (int fh) -> Location*)
{
    SetSeed(FileHelper::readInteger(fh));
    Global::isCustomSeed = FileHelper::readInteger(fh);

	Location *ret = super(fh);

    return ret;
}

HOOK_METHOD(StarMap, SaveGame, (int file) -> void)
{
    FileHelper::writeInt(file, Global::currentSeed);
    FileHelper::writeInt(file, Global::isCustomSeed);
    super(file);
}

HOOK_METHOD(StarMap, GenerateSectorMap, () -> void)
{
	this->sectorMapSeed = SeededRandom32();
	srand(this->sectorMapSeed);
	super();
}

HOOK_METHOD(StarMap, GetRandomSectorChoice, () -> int)
{
    return super();
    int randN = SeededRandom32();
    int mod = randN % 10;
    int result = 2;
    if (mod > 1)
    {
        result = mod > 5;
    }
    return result;
}

unsigned int SeededRandom32()
{
	return Global::seededRng() % 1000000000;
}

void SetSeed(unsigned int seed)
{
	Global::seededRng = std::mt19937(seed);
	Global::currentSeed = seed;
	nextSeed = seed;
}
