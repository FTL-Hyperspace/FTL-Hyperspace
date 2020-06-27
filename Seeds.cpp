#include "Global.h"
#include "FTLGame.h"
#include "MainMenu.h"
#include "Seeds.h"
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <fstream>



TextInput* SeedInputBox::seedInput;
Pointf SeedInputBox::drawLocation;
float SeedInputBox::width = 158.f;
float SeedInputBox::height = 21.f;
bool SeedInputBox::firstClick = true;
std::string SeedInputBox::prompt;

HOOK_GLOBAL(srandom32, (unsigned int seed) -> void)
{
    srand(seed);
}

HOOK_GLOBAL(random32, () -> unsigned int)
{
	return rand() << 15 | rand();
}

HOOK_METHOD(Store, OnInit, (ShipManager *shopper, Equipment *equip, int worldLevel) -> void)
{
    StarMap starMap = G_->GetWorld()->starMap;

    Location *storeLoc = starMap.currentLoc;

    srand((int)(storeLoc->loc.x + storeLoc->loc.y) ^ starMap.currentSectorSeed);

    super(shopper, equip, worldLevel);
}

HOOK_METHOD(ShipBuilder, constructor, () -> void)
{
	super();
	SeedInputBox::seedInput = new TextInput(10, TextInput::AllowedCharType::ALLOW_ANY, "");
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

            std::string txt;
            TextInput::GetText(txt, SeedInputBox::seedInput);

            if (!txt.empty() && boost::lexical_cast<int64_t>(txt) > 4294967295)
            {
                SeedInputBox::seedInput->SetText("4294967295");
            }

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


HOOK_METHOD(StarMap, SaveGame, (int file) -> void)
{
    FileHelper::writeInt(file, Global::currentSeed);
    FileHelper::writeInt(file, Global::isCustomSeed);
    super(file);
}

static bool startingNewGame = false;

HOOK_METHOD(StarMap, NewGame, (bool unk) -> Location*)
{
	std::string str = std::string();
	TextInput::GetText(str, SeedInputBox::seedInput);
	if (str == "" || unk)
	{
	    int seed = SeededRandom32();
		SetSeed(seed);
		Global::currentSeed = seed;

		Global::isCustomSeed = false;
	}
	else
	{
	    int seed = boost::lexical_cast<unsigned int>(str);
		SetSeed(seed);
		Global::currentSeed = seed;
		Global::isCustomSeed = true;
	}

	startingNewGame = true;

	return super(unk);
}

HOOK_METHOD(StarMap, LoadGame, (int fh) -> Location*)
{
    Global::currentSeed = FileHelper::readInteger(fh);
    Global::isCustomSeed = FileHelper::readInteger(fh);

	Location *ret = super(fh);



    return ret;
}

int eventNumber = 0;
bool generatingMap = false;

HOOK_METHOD(StarMap, GenerateMap, (bool unk, bool seed) -> Location*)
{
	if (startingNewGame)
	{
		this->currentSectorSeed = Global::currentSeed;

        startingNewGame = false;
	}
	if (!seed)
    {
        currentSectorSeed = SeededRandom32();
    }

    if (seed)
    {
        SetSeed(currentSectorSeed);
    }

    generatingMap = true;
    eventNumber = 0;

    Location *ret = super(unk, true);

    generatingMap = false;
    eventNumber = 0;

    return ret;
}

HOOK_METHOD(StarMap, GenerateSectorMap, () -> void)
{
    //printf("Generating sector map seed: %d\n", generateSectorMapSeed);

    this->sectorMapSeed = Global::currentSeed;
    srand(this->sectorMapSeed);

	super();
}

HOOK_METHOD(StarMap, UpdateDangerZone, () -> void)
{
    eventNumber = 0;

    super();

    eventNumber = 0;
}

HOOK_METHOD(EventGenerator, GetBaseEvent, (const std::string& name, int worldLevel, char ignoreUnique, int seed) -> LocationEvent*)
{
    if (generatingMap)
    {
        eventNumber++;

        return super(name, worldLevel, ignoreUnique, G_->GetWorld()->starMap.currentSectorSeed ^ eventNumber);

    }
    else
    {
        if (G_->GetWorld()->bStartedGame)
        {
            eventNumber++;

            return super(name, worldLevel, ignoreUnique, G_->GetWorld()->starMap.currentSectorSeed ^ (((int)(G_->GetWorld()->starMap.currentLoc->loc.x + G_->GetWorld()->starMap.currentLoc->loc.y)) + eventNumber));
        }
    }



    return super(name, worldLevel, ignoreUnique, seed);
}


unsigned int SeededRandom32()
{

	unsigned int ret = Global::seededRng();

    return ret;
}



void SetSeed(unsigned int seed)
{
	Global::seededRng = std::mt19937(seed);
	//Global::currentSeed = seed;
	nextSeed = seed;
}



