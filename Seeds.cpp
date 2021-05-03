#include "Global.h"
#include "FTLGame.h"
#include "MainMenu.h"
#include "Seeds.h"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <fstream>



TextInput* SeedInputBox::seedInput;
Pointf SeedInputBox::drawLocation;
float SeedInputBox::width = 158.f;
float SeedInputBox::height = 21.f;
bool SeedInputBox::firstClick = true;
bool SeedInputBox::seedsEnabled = true;
std::string SeedInputBox::prompt;

HOOK_GLOBAL(srandom32, (unsigned int seed) -> void)
{
    if (!SeedInputBox::seedsEnabled) return super(seed);
    srand(seed);
}

HOOK_GLOBAL(random32, () -> unsigned int)
{
    if (!SeedInputBox::seedsEnabled) return super();
	return rand() << 15 | rand();
}

HOOK_METHOD(Store, OnInit, (ShipManager *shopper, Equipment *equip, int worldLevel) -> void)
{
    if (!SeedInputBox::seedsEnabled) return super(shopper, equip, worldLevel);

    Location *storeLoc = G_->GetWorld()->starMap.currentLoc;

    int a = storeLoc->loc.x;
    int b = storeLoc->loc.y;
    int storeSeed = ((a + b) * (a + b + 1)) / 2 + b;


    srand(storeSeed ^ G_->GetWorld()->starMap.currentSectorSeed);

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
    TextLibrary::GetText(txt, G_->GetTextLibrary(), SeedInputBox::seedsEnabled ? "seed_prompt" : "seed_prompt_disabled", G_->GetTextLibrary()->currentLanguage);
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
    if (!SeedInputBox::seedsEnabled) return super(x, y);
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
    FileHelper::writeInt(file, Global::worldLevelSeed);
    FileHelper::writeInt(file, Global::isCustomSeed);
    super(file);
}

static bool startingNewGame = false;

HOOK_METHOD(StarMap, NewGame, (bool unk) -> Location*)
{
    if (!SeedInputBox::seedsEnabled) return super(unk);

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

	Location* ret = super(unk);

	startingNewGame = false;

	return ret;
}

HOOK_METHOD(StarMap, LoadGame, (int fh) -> Location*)
{
    loadingMap = true;

    Global::currentSeed = FileHelper::readInteger(fh);
    Global::worldLevelSeed = FileHelper::readInteger(fh);
    Global::isCustomSeed = FileHelper::readInteger(fh);

	Location *ret = super(fh);

	loadingMap = false;

    return ret;
}

HOOK_METHOD(StarMap, AdvanceWorldLevel, () -> void)
{
    super();

    SetSeed(Global::worldLevelSeed);
    Global::worldLevelSeed = SeededRandom32();
}

int eventNumber = 0;

HOOK_METHOD(StarMap, GenerateMap, (bool unk, bool seed) -> Location*)
{
    if (!SeedInputBox::seedsEnabled) return super(unk, seed);
	if (startingNewGame)
	{
		this->currentSectorSeed = Global::currentSeed;
		Global::worldLevelSeed = currentSectorSeed;

        startingNewGame = false;
	}
	else
    {
        if (!seed)
        {
            if (bSecretSector)
            {
                SetSeed(currentSectorSeed);
            }
            else
            {
                int a = currentSector->location.x;
                int b = currentSector->location.y;

                SetSeed((((a + b) * (a + b + 1)) / 2 + b)^Global::worldLevelSeed^0xf8072a96);
            }
            currentSectorSeed = SeededRandom32();
            SetSeed(currentSectorSeed);
        }
        else
        {
            SetSeed(currentSectorSeed);
        }
    }

    Location *ret = super(unk, true);

    return ret;
}

HOOK_METHOD_PRIORITY(StarMap, GenerateMap, 1000, (bool unk, bool seed) -> Location*)
{
    generatingMap = true;

    if (!loadingMap)
    {
        Global::lastDelayedQuestSeeds = Global::delayedQuestSeeds;
        Global::delayedQuestIndex = 0;
        Global::delayedQuestSeeds.clear();

        Global::bossFleetSeed = (currentSectorSeed ^ 0x46157fab) & 0x7fffffff;
    }

    auto ret = super(unk, seed);

    generatingMap = false;

    return ret;
}

HOOK_METHOD(StarMap, GenerateSectorMap, () -> void)
{
    //printf("Generating sector map seed: %d\n", generateSectorMapSeed);
    if (!SeedInputBox::seedsEnabled) return super();

    this->sectorMapSeed = Global::currentSeed;
    srandom32(this->sectorMapSeed);

	super();
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


HOOK_METHOD(StarMap, GetNewLocation, () -> Location*)
{
    if (!readyToTravel || outOfFuel) return super();

    auto ret = super();

    if (SeedInputBox::seedsEnabled)
    {
        int a = currentLoc->loc.x;
        int b = currentLoc->loc.y;
        Global::questSeed = ((((a + b) * (a + b + 1)) / 2 + b)^currentSectorSeed^0x282b2048) & 0x7fffffff;
    }

    return ret;
}

// New game quest seeds
HOOK_METHOD_PRIORITY(StarMap, NewGame, 500, (bool unk) -> Location*)
{
    Global::questSeed = 0;
    Global::delayedQuestSeeds.clear();
    Global::lastDelayedQuestSeeds.clear();

    Global::bossFleetSeed = 0;

    auto ret = super(unk);

    if (SeedInputBox::seedsEnabled)
    {
        int a = currentLoc->loc.x;
        int b = currentLoc->loc.y;
        Global::questSeed = ((((a + b) * (a + b + 1)) / 2 + b)^currentSectorSeed^0x282b2048) & 0x7fffffff;
    }

    return ret;
}

// Load quest seeds
HOOK_METHOD_PRIORITY(StarMap, LoadGame, 500, (int fh) -> Location*)
{
    Global::questSeed = FileHelper::readInteger(fh);
    Global::delayedQuestSeeds.clear();
    Global::lastDelayedQuestSeeds.clear();

    int numDelayedQuests = FileHelper::readInteger(fh);
    for (int i=0; i<numDelayedQuests; ++i)
    {
        Global::delayedQuestSeeds.push_back(FileHelper::readInteger(fh));
    }

    Global::bossFleetSeed = FileHelper::readInteger(fh);

    auto ret = super(fh);

    return ret;
}

HOOK_METHOD(EventGenerator, GetBaseEvent, (const std::string& name, int worldLevel, char ignoreUnique, int seed) -> LocationEvent*)
{
    if (boost::algorithm::starts_with(name, "QUEST ")) //loading a saved quest
    {
        std::string name2 = name.substr(6);
        std::vector<std::string> s = std::vector<std::string>();
        boost::split(s, name2, boost::is_any_of(" "));
        if (SeedInputBox::seedsEnabled) srandom32(std::stoi(s[0]));
        return super(s[1], worldLevel, ignoreUnique, seed);
    }

    return super(name, worldLevel, ignoreUnique, seed);
}

//Save quest seeds
HOOK_METHOD_PRIORITY(StarMap, SaveGame, 500, (int file) -> void)
{
    FileHelper::writeInt(file, Global::questSeed);

    FileHelper::writeInt(file, Global::delayedQuestSeeds.size());
    for (auto i : Global::delayedQuestSeeds)
    {
        FileHelper::writeInt(file, i);
    }

    FileHelper::writeInt(file, Global::bossFleetSeed);

    super(file);
}

HOOK_METHOD(StarMap, UpdateBoss, () -> void)
{
    if (!SeedInputBox::seedsEnabled) return super();

    int saveSeed = random32();
    srandom32(Global::bossFleetSeed);
    super();
    Global::bossFleetSeed = random32();
    srandom32(saveSeed);
}

HOOK_METHOD(StarMap, AdvanceWorldLevel, () -> void)
{
    super();

    if (SeedInputBox::seedsEnabled && bSecretSector)
    {
        srandom32(currentSectorSeed&0x7fffffff);
    }
}
