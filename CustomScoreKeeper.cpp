#include "CustomScoreKeeper.h"
#include "CustomShipSelect.h"
#include "freetype.h"
#include "ShipUnlocks.h"
#include "SaveFile.h"
#include <boost/lexical_cast.hpp>

CustomScoreKeeper* CustomScoreKeeper::instance = new CustomScoreKeeper();

void CustomScoreKeeper::AddTopScore(TopScore& topScore, int type = 0)
{
    auto scoreKeeper = G_->GetScoreKeeper();

    std::string blueprintName = topScore.blueprint;

    auto bp = G_->GetBlueprints()->GetShipBlueprint(blueprintName, -1);

    if (bp)
    {
        topScore.image = G_->GetResources()->GetImageId("customizeUI/miniship_" + bp->imgFile + ".png");
    }


    if (customShipScores.find(topScore.blueprint) == customShipScores.end())
    {
        customShipScores[topScore.blueprint] = std::vector<TopScore>();
    }

    if (type == 0 || type == 1)
    {
        scoreKeeper->newestHighScore = scoreKeeper->AddTopScoreList(topScore, scoreKeeper->topScores);
    }
    if (type == 0 || type == 2)
    {
        scoreKeeper->newestShipBest = scoreKeeper->AddTopScoreList(topScore, customShipScores[topScore.blueprint]);

        if (scoreKeeper->newestShipBest != -1)
        {
            scoreKeeper->newestShipType = 100 + CustomShipSelect::GetInstance()->GetShipButtonIdFromName(topScore.blueprint);
            scoreKeeper->newestShipLayout = type;
        }
    }

    if (customShipScores[topScore.blueprint].size() > 4)
    {
        customShipScores[topScore.blueprint].resize(4);
    }
}

std::vector<TopScore> CustomScoreKeeper::GetTopScores(const std::string& shipName, int variant)
{
    std::string blueprintName = shipName;

    if (variant == 1)
    {
        blueprintName.append("_2");
    }
    if (variant == 2)
    {
        blueprintName.append("_3");
    }

    if (customShipScores.find(shipName) != customShipScores.end())
    {
        return customShipScores[shipName];
    }
    else
    {
        return std::vector<TopScore>();
    }
}

void CustomScoreKeeper::LoadShipScores(int file)
{
    int shipScoreLen = FileHelper::readInteger(file);

    for (int i = 0; i < shipScoreLen; i++)
    {
        std::string shipBlueprint = FileHelper::readString(file);
        customShipScores[shipBlueprint] = std::vector<TopScore>();
        int numShipScores = FileHelper::readInteger(file);

        for (int j = 0; j < numShipScores; j++)
        {
            TopScore score = TopScore();

            score.name = FileHelper::readString(file);
            score.blueprint = FileHelper::readString(file);
            score.sector = FileHelper::readInteger(file);
            score.score = FileHelper::readInteger(file);
            score.victory = FileHelper::readInteger(file);
            score.difficulty = FileHelper::readInteger(file);
            score.advancedContent = FileHelper::readInteger(file);

            AddTopScore(score, 2);
        }
    }
}

void CustomScoreKeeper::SaveShipScores(int file)
{
    int shipScoreLen = customShipScores.size();

    FileHelper::writeInt(file, shipScoreLen);

    for (auto i : customShipScores)
    {
        FileHelper::writeString(file, i.first);
        FileHelper::writeInt(file, i.second.size());

        for (auto score : i.second)
        {
            FileHelper::writeString(file, score.name);
            FileHelper::writeString(file, score.blueprint);
            FileHelper::writeInt(file, score.sector);
            FileHelper::writeInt(file, score.score  );
            FileHelper::writeInt(file, score.victory);
            FileHelper::writeInt(file, score.difficulty);
            FileHelper::writeInt(file, score.advancedContent);
        }
    }
}

void CustomScoreKeeper::WipeProfile()
{
    customShipScores.clear();
}

HOOK_METHOD(ScoreKeeper, CycleLeft, () -> void)
{
    if (selectedShip >= 100)
    {
        auto customSel = CustomShipSelect::GetInstance();

        selectedShip = customSel->CycleShipPrevious(selectedShip, selectedLayout);
        SetupTopShip(selectedLayout);

        return;
    }

    super();
}

HOOK_METHOD(ScoreKeeper, CycleRight, () -> void)
{
    if (selectedShip >= 100)
    {
        auto customSel = CustomShipSelect::GetInstance();

        selectedShip = customSel->CycleShipNext(selectedShip, selectedLayout);
        SetupTopShip(selectedLayout);

        return;
    }

    super();
}

HOOK_METHOD(ScoreKeeper, SetupTopShip, (int variant) -> void)
{
    if (selectedShip >= 100)
    {
        shipAchievements.clear();
        selectedLayout = variant;

        CheckTypes();
        return;
    }

    super(variant);
}



HOOK_METHOD(ScoreKeeper, AddTopScoreType, (TopScore& topScore, int type) -> void)
{
    if (CustomShipSelect::GetInstance()->IsCustomShip(topScore.blueprint))
    {
        CustomScoreKeeper::instance->AddTopScore(topScore, type);
        return;
    }

    super(topScore, type);
}

HOOK_METHOD(ScoreKeeper, CheckTypes, () -> void)
{
    if (selectedShip >= 100)
    {
        auto customSel = CustomShipSelect::GetInstance();

        ShipButtonDefinition def = customSel->GetShipButtonDefinition(selectedShip - 100);

        if (!CustomShipUnlocks::instance->GetCustomShipUnlocked(def.name))
        {
            typeA.bActive = false;
            typeA.bRenderOff = true;
            typeA.bRenderSelected = false;
        }
        else
        {
            typeA.SetActive(selectedLayout != 0);
            typeA.bRenderOff = false;
            typeA.bRenderSelected = selectedLayout == 0;
        }

        if (!def.typeB || !CustomShipUnlocks::instance->GetCustomShipUnlocked(def.name + "_2"))
        {
            typeB.bActive = false;
            typeB.bRenderOff = true;
            typeB.bRenderSelected = false;
        }
        else
        {
            typeB.SetActive(selectedLayout != 1);
            typeB.bRenderOff = false;
            typeB.bRenderSelected = selectedLayout == 1;
        }

        if (!def.typeC || !CustomShipUnlocks::instance->GetCustomShipUnlocked(def.name + "_3"))
        {
            typeC.bActive = false;
            typeC.bRenderOff = true;
            typeC.bRenderSelected = false;
        }
        else
        {
            typeC.SetActive(selectedLayout != 2);
            typeC.bRenderOff = false;
            typeC.bRenderSelected = selectedLayout == 2;
        }

        Point typeAPos(typeALoc.x, typeALoc.y);
        typeA.SetLocation(typeAPos);

        Point typeBPos(typeBLoc.x, typeBLoc.y);
        typeB.SetLocation(typeBPos);

        Point typeCPos(typeCLoc.x, typeCLoc.y);
        typeC.SetLocation(typeCPos);

        bool buttonsActive = customSel->CountUnlockedShips(selectedLayout) > 1;
        leftButton.SetActive(buttonsActive);
        rightButton.SetActive(buttonsActive);

        return;
    }


    super();
}

HOOK_METHOD(ScoreKeeper, MouseClick, (int x, int y) -> void)
{
    auto customSel = CustomShipSelect::GetInstance();

    if (shipSelect.bOpen)
    {
        shipSelect.MouseClick();
        if (shipSelect.selectedShip != -1)
        {
            selectedShip = shipSelect.selectedShip;
            SetupTopShip(shipSelect.currentType);
            shipSelect.Close();
        }
    }
    else
    {
        gotCloseEvent = closeButton.bActive && closeButton.bHover;
        if (rightButtons[activatedRight].bActive && rightButtons[activatedRight].bHover)
        {
            activatedRight = !activatedRight;
        }
        if (leftButtons[activatedLeft].bActive && leftButtons[activatedLeft].bHover)
        {
            activatedLeft = !activatedLeft;
        }

        if (activatedLeft)
        {
            if (leftButton.bActive && leftButton.bHover)
            {
                CycleLeft();
            }
            if (rightButton.bActive && rightButton.bHover)
            {
                CycleRight();
            }

            if (listButton.bActive && listButton.bHover)
            {
                shipSelect.Open(selectedShip, selectedLayout);
            }
            else if (typeA.bActive && typeA.bHover)
            {
                selectedLayout = 0;
                CheckTypes();
            }
            else if (typeB.bActive && typeB.bHover)
            {
                selectedLayout = 1;
                CheckTypes();
            }
            else if (typeC.bActive && typeC.bHover)
            {
                selectedLayout = 2;
                CheckTypes();
            }
        }
    }

    if (customSel->IsOpen() && !customSel->FirstPage())
    {
        if (customSel->GetSelectedId() != -1)
        {
            selectedShip = customSel->GetSelectedId();
            SetupTopShip(shipSelect.currentType);
            shipSelect.Close();
            CheckTypes();
        }
    }
}

HOOK_METHOD(ScoreKeeper, WipeProfile, (bool permanent) -> void)
{
    CustomScoreKeeper::instance->WipeProfile();

    super(permanent);
}


HOOK_METHOD(AchievementTracker, LoadProfile, (int file, int version) -> void)
{
    super(file, version);

    if (CustomShipUnlocks::instance->loadVersion == SaveFileHandler::version)
    {
        CustomShipUnlocks::instance->LoadCurrent(file);
        CustomScoreKeeper::instance->LoadShipScores(file);
    }
}

HOOK_METHOD(AchievementTracker, SaveProfile, (int file) -> void)
{
    super(file);

    CustomShipUnlocks::instance->Save(file);
    CustomScoreKeeper::instance->SaveShipScores(file);
}

HOOK_METHOD(ScoreKeeper, Open, (bool fromGameOver) -> void)
{
    super(fromGameOver);

    if (newestShipType == -1 || !fromGameOver)
    {
        auto customSel = CustomShipSelect::GetInstance();

        customSel->OnInit(&shipSelect);

        if (customSel->hideFirstPage)
        {
            if (customSel->CustomShipOrder())
            {
                selectedShip = customSel->GetShipButtonIdFromName(customSel->customShipOrder[0]) + 100;
            }
            else
            {
                selectedShip = 100;
            }

            SetupTopShip(0);
        }
    }
}

HOOK_METHOD(ScoreKeeper, OnRender, (bool lastPlaythrough) -> void)
{
    bool isCustomShip = selectedShip >= 100;

    if (shipSelect.bOpen)
    {
        CSurface::GL_SetColorTint(COLOR_TINT);

        shipSelect.OnLoop();
    }

    G_->GetResources()->RenderImage(leftBox[activatedLeft], 0, 0, 0, COLOR_WHITE, 1.f, false);
    G_->GetResources()->RenderImage(rightBox[activatedRight], 645, 0, 0, COLOR_WHITE, 1.f, false);

    leftButtons[activatedLeft].OnRender();
    rightButtons[activatedRight].OnRender();

    std::string topScoresText = G_->GetTextLibrary()->GetText("stats_topscores");
    std::string shipBestText = G_->GetTextLibrary()->GetText("stats_shipbest");
    std::string statsText = G_->GetTextLibrary()->GetText("stats_stats");
    std::string achievementsText = G_->GetTextLibrary()->GetText("stats_achievements");

    int font = 64;
    int yBase = 0;

    while (freetype_hack::easy_measurePrintLines(64, 0, 0, 999, topScoresText).x > 254.f
        || freetype_hack::easy_measurePrintLines(64, 0, 0, 999, shipBestText).x > 218.f
        || freetype_hack::easy_measurePrintLines(64, 0, 0, 999, statsText).x > 134.f
        || freetype_hack::easy_measurePrintLines(64, 0, 0, 999, achievementsText).x > 324.f)
    {
        yBase += 4;
        font -= 1;
        if (yBase == 8)
        {
            font = 62;
            break;
        }
    }

    if (freetype_hack::easy_measurePrintLines(font, 0, 0, 999, statsText).x > 134.f)
    {
        yBase += 3;
    }

    int yPos = yBase + 46;

    CSurface::GL_SetColor(25.f / 255.f, 49.f / 255.f, 51.f / 255.f, 1.f);

    freetype::easy_printCenter(font, 188, yPos, topScoresText);
    freetype::easy_printCenter(font, 477, yPos, shipBestText);
    freetype::easy_printCenter(font, 753, yPos, statsText);
    freetype::easy_printCenter(font, 1023, yPos, achievementsText);

    CSurface::GL_SetColor(COLOR_WHITE);

    Point pos1 = Point(112, 88);
    Point pos2 = Point(112, 88);
    Point pos3 = Point(700, 150);
    Point pos4 = Point(705, 100);

    leftButton.SetLocation(Point(shipListCenter.x - listButton.GetSize() / 2 - 37, shipListCenter.y));
    listButton.SetLocation(Point(shipListCenter.x - listButton.GetSize() / 2 - 37 + leftButton.imageSize.x + 5, shipListCenter.y));
    rightButton.SetLocation(Point(shipListCenter.x - listButton.GetSize() / 2 - 37 + leftButton.imageSize.x + 5 + listButton.GetSize() + 5, shipListCenter.y));

    if (!activatedLeft)
    {
        RenderTopScores(topScores, pos1, newestHighScore);
    }
    else
    {
        std::string shipName = GetShipBlueprint(selectedShip);
        std::string shipBlueprintName = shipName;

        if (selectedLayout == 1)
        {
            shipBlueprintName.append("_2");
        }
        if (selectedLayout == 2)
        {
            shipBlueprintName.append("_3");
        }

        auto shipBlueprint = G_->GetBlueprints()->GetShipBlueprint(shipBlueprintName, -1);

        freetype::easy_printCenter(24, pos2.x + 105, pos2.y + 3, shipBlueprint->shipClass.GetText());

        int shipBest = -1;
        if (newestShipType == selectedShip && newestShipLayout == selectedLayout)
        {
            shipBest = newestShipBest;
        }

        if (isCustomShip)
        {
            RenderTopScores(CustomScoreKeeper::instance->GetTopScores(shipBlueprintName, selectedLayout), Point(pos2.x, pos2.y + 116), shipBest);
        }
        else if (selectedShip != -1)
        {
            RenderTopScores(shipScores[selectedShip][selectedLayout], Point(pos2.x, pos2.y + 116), shipBest);
        }

        for (auto i : buttons)
        {
            i->OnRender();
        }

        for (int i = 0; i < shipAchievements.size(); i++)
        {
            auto item = shipAchievements[i];
            item.first->OnRender(item.second, selectedShipAch == i, true);
        }
    }


    if (activatedRight)
    {
        CSurface::GL_SetColor(COLOR_WHITE);
        freetype::easy_print(24, pos4.x, pos4.y, G_->GetTextLibrary()->GetText("progression_heading"));
        freetype::easy_print(24, pos4.x, pos4.y + 160, G_->GetTextLibrary()->GetText("distance_heading"));
        freetype::easy_print(24, pos4.x, pos4.y + 330, G_->GetTextLibrary()->GetText("skill_heading"));

        for (int i = 0; i < achievements.size(); i++)
        {
            auto item = achievements[i];
            item.first->OnRender(item.second, selectedAch == i, true);
        }
    }
    else
    {
        CSurface::GL_SetColor(COLOR_WHITE);
        freetype::easy_print(24, pos3.x - 5, pos3.y - 50, G_->GetTextLibrary()->GetText("records_heading"));

        int statsYPos = pos3.y;

        for (auto i : stats)
        {
            if (lastPlaythrough && i.current == i.max)
            {
                CSurface::GL_SetColor(COLOR_YELLOW);
            }

            std::string scoreText = G_->GetTextLibrary()->GetText("most_" + i.desc_id);
            freetype::easy_print(13, pos3.x, statsYPos, scoreText);
            freetype::easy_printCenter(13, pos3.x + 465, statsYPos, std::to_string(i.max));

            CSurface::GL_SetColor(COLOR_WHITE);

            statsYPos += 20;
        }

        statsYPos -= 20;

        freetype::easy_print(24, pos3.x - 5, statsYPos + 30, G_->GetTextLibrary()->GetText("crew_heading"));

        statsYPos += 75;
        int crewStatsLimit = statsYPos + 180;

        for (auto i : crewStats)
        {
            if (i.newStat)
            {
                CSurface::GL_SetColor(COLOR_YELLOW);
            }
            else
            {
                CSurface::GL_SetColor(COLOR_WHITE);
            }

            std::string scoreText = G_->GetTextLibrary()->GetText("most_" + i.title_id);
            freetype::easy_print(13, pos3.x, statsYPos, scoreText);
            freetype::easy_printCenter(13, pos3.x + 465, statsYPos, std::to_string(i.max));

            if (!i.name.empty())
            {
                Pointf endPos = freetype_hack::easy_printCenter(13, pos3.x + 365, statsYPos, i.name);

                CSurface::GL_SetColor(COLOR_WHITE);
                auto crewBp = G_->GetBlueprints()->GetCrewBlueprint(i.species);

                if (crewBp)
                {
                    crewBp->male = i.male;
                    CSurface::GL_PushMatrix();
                    CSurface::GL_Translate(endPos.x - 30.f, statsYPos + 8, 0);

                    crewBp->RenderIcon(1.f);
                    CSurface::GL_PopMatrix();
                }

                delete crewBp;

            }

            if (statsYPos + 21 == crewStatsLimit)
            {
                break;
            }
            statsYPos += 21;
        }

        std::string statsPrefix = "";
        CSurface::GL_SetColor(COLOR_WHITE);

        if (lastPlaythrough)
        {
            freetype::easy_print(24, pos3.x - 5, statsYPos + 5, G_->GetTextLibrary()->GetText("stats_heading"));
        }
        else
        {
            freetype::easy_print(24, pos3.x - 5, statsYPos + 5, G_->GetTextLibrary()->GetText("total_heading"));

            statsPrefix = "total_";
        }

        statsYPos += 55;

        for (auto i : stats)
        {
            std::string scoreText = G_->GetTextLibrary()->GetText(statsPrefix + i.desc_id);
            freetype::easy_print(13, pos3.x, statsYPos, scoreText);
            if (lastPlaythrough)
            {
                freetype::easy_printCenter(13, pos3.x + 465, statsYPos, std::to_string(i.current));
            }
            else
            {
                freetype::easy_printCenter(13, pos3.x + 465, statsYPos, std::to_string(i.total));
            }

            statsYPos += 20;
        }


        statsYPos += 20;

        if (lastPlaythrough)
        {
            freetype::easy_print(13, pos3.x, statsYPos, G_->GetTextLibrary()->GetText("final_score"));
            freetype::easy_printCenter(13, pos3.x + 465, statsYPos, std::to_string(currentScore.score));
        }
        else
        {
            freetype::easy_print(13, pos3.x, statsYPos, G_->GetTextLibrary()->GetText("total_games"));
            freetype::easy_printCenter(13, pos3.x + 465, statsYPos, std::to_string(gamesPlayed));

            statsYPos += 20;

            freetype::easy_print(13, pos3.x, statsYPos, G_->GetTextLibrary()->GetText("total_victories"));
            freetype::easy_printCenter(13, pos3.x + 465, statsYPos, std::to_string(victories));
        }
    }

    if (!infoBox.IsEmpty())
    {
        infoBox.OnRender();
    }

    closeButton.OnRender();
    CSurface::GL_RemoveColorTint();
    if (shipSelect.bOpen)
    {
        shipSelect.OnRender();
    }
}

HOOK_METHOD(ScoreKeeper, KeyDown, (SDLKey key) -> bool)
{
    if (key == SDLKey::SDLK_UP
        || key == SDLKey::SDLK_LEFT
        || key == SDLKey::SDLK_RIGHT
        || key == SDLKey::SDLK_DOWN)
    {
        return true;
    }

    if (key == SDLKey::SDLK_ESCAPE && CustomShipSelect::GetInstance()->IsOpen())
    {
        super(key);

        return true;
    }

    super(key);
}
