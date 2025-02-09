#include "CustomAchievements.h"
#include "CustomShipSelect.h"
#include "Resources.h"
#include "Seeds.h"

#include <boost/lexical_cast.hpp>

CustomAchievementTracker* CustomAchievementTracker::instance = new CustomAchievementTracker();

void CustomAchievementTracker::OnInitStats()
{
    if (!achievementButtonLeft)
    {
        achievementButtonLeft = new Button();
        achievementButtonLeft->OnInit("customizeUI/button_arrow", Point(1152, 95));
    }

    if (!achievementButtonRight)
    {
        achievementButtonRight = new Button();
        achievementButtonRight->OnInit("customizeUI/button_arrow", Point(1192, 95));
        achievementButtonRight->bMirror = true;
    }

    if (!statsInitTextures)
    {
        ResourceControl *resources = G_->GetResources();
        if (resources->ImageExists("scoreUI/score_main_right_2a.png"))
        {
            statsBack1 = resources->GetImageId("scoreUI/score_main_right_2a.png");
        }
        if (resources->ImageExists("scoreUI/score_main_right_2b.png"))
        {
            statsBack2 = resources->GetImageId("scoreUI/score_main_right_2b.png");
        }
        if (resources->ImageExists("scoreUI/score_main_right_border.png"))
        {
            statsBorder = resources->GetImageId("scoreUI/score_main_right_border.png");
        }

        statsInitTextures = true;
    }
}

void CustomAchievementTracker::ParseAchievements(rapidxml::xml_node<char> *node)
{
    if (smallOutline == nullptr) smallOutline = CSurface::GL_CreateRectOutlinePrimitive(0, 0, 32, 32, GL_Color(1.f, 1.f, 1.f, 1.f), 2.f);
    if (largeOutline == nullptr) largeOutline = CSurface::GL_CreateRectOutlinePrimitive(0, 0, 64, 64, GL_Color(1.f, 1.f, 1.f, 1.f), 2.f);
    if (largeOverlay == nullptr) largeOverlay = CSurface::GL_CreateRectPrimitive(0, 0, 64, 64, GL_Color(0.f, 0.f, 0.f, 0.75f));

    for (auto achNode = node->first_node(); achNode; achNode = achNode->next_sibling())
    {
        std::string nodeName = achNode->name();

        if (nodeName == "achievement")
        {
            ParseAchievement(achNode);
        }
        else if (nodeName == "page")
        {
            int height = 9999;

            for (auto child = achNode->first_node(); child; child = child->next_sibling())
            {
                if (strcmp(child->name(), "section") == 0)
                {
                    CustomAchievementSection section = CustomAchievementSection();
                    section.heading.data = "";
                    section.heading.isLiteral = true;

                    if (child->first_attribute("id"))
                    {
                        section.heading.data = child->first_attribute("id")->value();
                        section.heading.isLiteral = false;
                    }
                    if (child->first_attribute("text"))
                    {
                        section.heading.data = child->first_attribute("text")->value();
                        section.heading.isLiteral = true;
                    }

                    if (child->first_attribute("secretId"))
                    {
                        section.secretHeading.data = child->first_attribute("secretId")->value();
                        section.secretHeading.isLiteral = false;
                    }
                    if (child->first_attribute("secretText"))
                    {
                        section.secretHeading.data = child->first_attribute("secretText")->value();
                        section.secretHeading.isLiteral = true;
                    }

                    if (child->first_attribute("hidden"))
                    {
                        section.hidden = EventsParser::ParseBoolean(child->first_attribute("hidden")->value());
                    }

                    for (auto achChild = child->first_node(); achChild; achChild = achChild->next_sibling())
                    {
                        std::string achName;
                        if (strcmp(achChild->name(), "achievement") == 0 && achChild->first_attribute("name"))
                        {
                            achName = achChild->first_attribute("name")->value();
                            ParseAchievement(achChild);
                        }
                        else
                        {
                            achName = achChild->name();
                        }
                        auto it = customAchievements.find(achName);
                        if (it != customAchievements.end())
                        {
                            section.achievements.push_back(&(it->second));
                        }
                    }

                    int secHeight = section.GetMaxHeight();
                    if (height + secHeight > 500)
                    {
                        height = 0;
                        achievementPages.emplace_back();
                    }
                    height += secHeight;

                    CustomAchievementPage &page = achievementPages.back();
                    page.achievements.emplace_back(std::move(section));
                }
            }
        }
        else if (nodeName == "statsBorderColor")
        {
            ParseColorNode(achievementPagesBoxOutlineColor, achNode);
        }
        else if (nodeName == "statsTextColor")
        {
            ParseColorNode(achievementPagesBoxTextColor, achNode);
        }
    }
}

void CustomAchievementTracker::ParseAchievement(rapidxml::xml_node<char> *node)
{
    bool define;
    std::string achName;

    if (node->first_attribute("name"))
    {
        define = true;
        achName = node->first_attribute("name")->value();
    }
    else if (node->first_attribute("load"))
    {
        define = false;
        achName = node->first_attribute("load")->value();
    }
    else // fallback
    {
        define = true;
        achName = "";
    }

    CustomAchievement &ach = customAchievements[achName];
    ach.ach.gap_ex_custom = -2; // misc custom achievement
    ach.ach.name_id = achName;

    ach.ach.multiDifficulty = true;
    ach.ach.dimension = 64;
    ach.ach.outline = largeOutline;
    ach.ach.mini_outline = smallOutline;
    ach.ach.lockOverlay = largeOverlay;

    if (define)
    {
        std::string varName = "";
        ach.ParseAchievement(node, &varName);

        if (!varName.empty())
        {
            variableAchievements[varName].push_back(&customAchievements[achName]);
        }
        UpdateAchievement(ach);
    }
}

CustomAchievement& CustomAchievementTracker::ParseShipAchievement(rapidxml::xml_node<char> *node, const std::string& ship)
{
    bool define;
    std::string achName;

    if (node->first_attribute("name"))
    {
        define = true;
        achName = node->first_attribute("name")->value();
    }
    else if (node->first_attribute("load"))
    {
        define = false;
        achName = node->first_attribute("load")->value();
    }
    else // fallback
    {
        define = true;
        achName = "";
    }

    CustomAchievement &ach = customAchievements[achName];
    ach.ach.gap_ex_custom = -4; // misc custom ship achievement
    ach.ach.name_id = achName;

    ach.ach.multiDifficulty = true;
    ach.ach.dimension = 64;
    ach.ach.outline = largeOutline;
    ach.ach.mini_outline = smallOutline;
    ach.ach.lockOverlay = largeOverlay;

    if (define)
    {
        ach.ach.ship = ship;

        std::string varName = "";
        ach.ParseAchievement(node, &varName);

        if (!varName.empty())
        {
            variableAchievements[varName].push_back(&customAchievements[achName]);
        }
        UpdateAchievement(ach);
    }
    else if (ach.ach.ship.empty())
    {
        ach.ach.ship = ship;
    }

    return ach;
}

void CustomAchievement::ParseAchievement(rapidxml::xml_node<char> *node, std::string *varName)
{
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string nodeName = child->name();
        std::string nodeValue = child->value();

        if (nodeName == "name")
        {
            if (child->first_attribute("id"))
            {
                name.data = child->first_attribute("id")->value();
                name.isLiteral = false;
            }
            if (!nodeValue.empty())
            {
                name.data = nodeValue;
                name.isLiteral = true;
            }
        }
        if (nodeName == "description")
        {
            if (child->first_attribute("id"))
            {
                description.data = child->first_attribute("id")->value();
                description.isLiteral = false;
            }
            if (!nodeValue.empty())
            {
                description.data = nodeValue;
                description.isLiteral = true;
            }
        }
        if (nodeName == "header")
        {
            if (child->first_attribute("id"))
            {
                ach.header.data = child->first_attribute("id")->value();
                ach.header.isLiteral = false;
            }
            if (!nodeValue.empty())
            {
                ach.header.data = nodeValue;
                ach.header.isLiteral = true;
            }
        }
        if (nodeName == "secretName")
        {
            if (child->first_attribute("id"))
            {
                secretName.data = child->first_attribute("id")->value();
                secretName.isLiteral = false;
            }
            if (!nodeValue.empty())
            {
                secretName.data = nodeValue;
                secretName.isLiteral = true;
            }
        }
        if (nodeName == "secretDescription")
        {
            if (child->first_attribute("id"))
            {
                secretDescription.data = child->first_attribute("id")->value();
                secretDescription.isLiteral = false;
            }
            if (!nodeValue.empty())
            {
                secretDescription.data = nodeValue;
                secretDescription.isLiteral = true;
            }
        }
        if (nodeName == "icon")
        {
            ach.icon.SetImagePath("achievements/"+nodeValue+".png");
        }
        if (nodeName == "lockImage")
        {
            ach.lockImage.SetImagePath("achievements/"+nodeValue+".png");
        }
        if (nodeName == "variable" && child->first_attribute("name") && child->first_attribute("amount"))
        {
            if (varName) *varName = child->first_attribute("name")->value();

            ach.progress.second = boost::lexical_cast<int>(child->first_attribute("amount")->value());
            ach.progress.first = 0;
        }
        if (nodeName == "multiDifficulty")
        {
            ach.multiDifficulty = EventsParser::ParseBoolean(child->value());
        }
        if (nodeName == "hidden")
        {
            hidden = true;
        }
        if (nodeName == "sound")
        {
            sound = nodeValue;
        }
    }
}

void CustomAchievementTracker::LoadVersionThree(int file)
{
    // achievementUnlocks

    int length = FileHelper::readInteger(file);

    for (int i = 0; i < length; i++)
    {
        std::string k = FileHelper::readString(file);
        int v = FileHelper::readInteger(file);
        if (v != -1) achievementUnlocks[k] = v;
    }

    UpdateAchievements();
}

void CustomAchievementTracker::Save(int file)
{
    // achievementUnlocks

    int length = achievementUnlocks.size();

    FileHelper::writeInt(file, length);

    for (auto &i : achievementUnlocks)
    {
        FileHelper::writeString(file, i.first);
        FileHelper::writeInt(file, i.second);
    }
}

CustomAchievement &CustomAchievementTracker::GetAchievement(const std::string &name)
{
    return customAchievements[name];
}

int CustomAchievementTracker::GetAchievementStatus(const std::string &name)
{
    auto it = achievementUnlocks.find(name);
    if (it != achievementUnlocks.end()) return it->second;
    return -1;
}

void CustomAchievementTracker::UpdateAchievement(CustomAchievement &ach)
{
    int status = GetAchievementStatus(ach.ach.name_id);

    ach.ach.unlocked = status != -1;
    ach.ach.difficulty = status;

    if (ach.ach.unlocked)
    {
        ach.ach.name = ach.name;
        ach.ach.description = ach.description;
    }
    else
    {
        ach.ach.name = ach.secretName.data.empty() ? ach.name : ach.secretName;
        ach.ach.description = ach.secretDescription.data.empty() ? ach.description : ach.secretDescription;
    }
}

void CustomAchievementTracker::UpdateAchievements()
{
    for (auto &it : customAchievements)
    {
        UpdateAchievement(it.second);
    }
}

void CustomAchievementTracker::UpdateVariableAchievements(const std::string &varName, int varValue, bool inGame)
{
    auto vAchievements = variableAchievements.find(varName);
    if (vAchievements != variableAchievements.end())
    {
        for (CustomAchievement *ach : vAchievements->second)
        {
            ach->ach.progress.first = varValue;
            if (ach->ach.progress.first >= ach->ach.progress.second)
            {
                if (inGame)
                {
                    SetAchievement(ach->ach.name_id, false);
                }
                else if (ach->ach.ship.empty()) // if not in game don't award ship achievements
                {
                    // if not in game then set the achievement to EASY
                    int diff = *Global::difficulty;
                    *Global::difficulty = 0;
                    SetAchievement(ach->ach.name_id, false);
                    *Global::difficulty = diff;
                }
            }
        }
    }
}

bool CustomAchievementTracker::CheckShipAchievement(CustomAchievement &ach)
{
    // This method checks if a ship achievement belongs to the current ship.

    std::string &ship = G_->GetAchievementTracker()->currentShip;
    auto customSel = CustomShipSelect::GetInstance();
    int shipId = customSel->GetShipButtonIdFromName(ship);

    if (shipId != -1)
    {
        ShipButtonDefinition &buttonDef = customSel->GetShipButtonDefinition(shipId);

        int layout = 0;
        if (ship == buttonDef.name + "_2")
        {
            layout = 1;
        }
        else if (ship == buttonDef.name + "_3")
        {
            layout = 2;
        }

        for (CustomAchievement *sAch : buttonDef.shipAchievements[layout])
        {
            if (sAch == &ach) return true;
        }
    }

    return false;
}

void CustomAchievementTracker::SetAchievement(const std::string &name, bool noPopup)
{
    if (!SeedInputBox::seedsAllowAchievements && Global::IsSeededRun()) return;

    int oldDiff = GetAchievementStatus(name);
    int newDiff = *Global::difficulty;

    if (newDiff > oldDiff)
    {
        CustomAchievement &ach = GetAchievement(name);

        if (!ach.ach.ship.empty() && !CheckShipAchievement(ach)) return; // wrong ship for achievement

        achievementUnlocks[name] = newDiff;

        UpdateAchievement(ach);

        if (ach.ach.multiDifficulty || oldDiff == -1)
        {
            ach.ach.newAchievement = newDiff > -1;

            if (!noPopup && G_->GetSettings()->achPopups)
            {
                G_->GetAchievementTracker()->recentlyUnlocked.push_back(&ach.ach);
            }
        }
    }
}

void CustomAchievementTracker::RemoveAchievement(const std::string &name)
{
    if (GetAchievementStatus(name) != -1)
    {
        CustomAchievement &ach = GetAchievement(name);
        ach.ach.newAchievement = false;
        achievementUnlocks[name] = -1;
        UpdateAchievement(ach);
    }
}

void CustomAchievementTracker::ResetFlags()
{
    for (auto &it : customAchievements)
    {
        it.second.ach.newAchievement = false;
    }
}

void CustomAchievementTracker::WipeProfile()
{
    achievementUnlocks.clear();

    UpdateAchievements();
    ResetFlags();
}

// Stats page

bool CustomAchievementPage::RenderBackground(Point pos)
{
    GL_Texture *tex1 = CustomAchievementTracker::instance->statsBack1;
    GL_Texture *tex2 = CustomAchievementTracker::instance->statsBack2;

    if (!tex1)
    {
        return false;
    }
    if (!tex2)
    {
        G_->GetResources()->RenderImage(tex1, pos.x, pos.y, 0, COLOR_WHITE, 1.f, false);
        return true;
    }

    int size_x = tex1->width_;
    int size_y = tex1->height_;

    CSurface::GL_BlitImagePartial(tex1, pos.x, pos.y, 36.f, size_y, 0.f, 36.f/size_x, 0.f, 1.f, 1.f, COLOR_WHITE, false);
    CSurface::GL_BlitImagePartial(tex1, pos.x+564.f, pos.y, size_x-564.f, size_y, 564.f/size_x, 1.f, 0.f, 1.f, 1.f, COLOR_WHITE, false);

    float y = 100.f;
    float y0 = 0.f;
    float y1;

    for (CustomAchievementSection &section : achievements)
    {
        if (section.Visible())
        {
            y1 = y+53.f;
            CSurface::GL_BlitImagePartial(tex1, pos.x+36.f, y0, 528.f, y1-y0, 36.f/size_x, 564.f/size_x, y0/size_y, y1/size_y, 1.f, COLOR_WHITE, false);
            y0 = y1;
            y += section.GetHeight();
            y1 = y-23.f;
            CSurface::GL_BlitImagePartial(tex2, pos.x+36.f, y0, 528.f, y1-y0, 36.f/size_x, 564.f/size_x, y0/size_y, y1/size_y, 1.f, COLOR_WHITE, false);
            y0 = y1;
        }
    }
    CSurface::GL_BlitImagePartial(tex1, pos.x+36.f, y0, 528.f, size_y-y0, 36.f/size_x, 564.f/size_x, y0/size_y, 1.f, 1.f, COLOR_WHITE, false);

    return true;
}

void CustomAchievementPage::OnRender(Point pos)
{
    pos.y += 100;
    for (CustomAchievementSection &section : achievements)
    {
        if (section.Visible())
        {
            section.OnRender(pos);
            pos.y += section.GetHeight();
        }
    }
}

void CustomAchievementPage::MouseMove(int mX, int mY)
{
    mY -= 100;
    for (CustomAchievementSection &section : achievements)
    {
        if (section.Visible())
        {
            section.MouseMove(mX, mY);
            mY -= section.GetHeight();
        }
    }
}

bool CustomAchievementPage::Visible()
{
    for (CustomAchievementSection &section : achievements)
    {
        if (section.Visible()) return true;
    }
    return false;
}

int CustomAchievementSection::GetHeight()
{
    int numAch = GetVisibleAchievements();
    if (numAch < 1) return 160;
    return 90 + 70*((numAch+6)/7);
}

int CustomAchievementSection::GetMaxHeight()
{
    int numAch = achievements.size();
    if (numAch < 1) return 160;
    return 90 + 70*((numAch+6)/7);
}

int CustomAchievementSection::GetVisibleAchievements()
{
    int numAch = 0;
    for (CustomAchievement *ach : achievements)
    {
        if (!ach->hidden || ach->ach.unlocked)
        {
            numAch++;
        }
    }
    return numAch;
}

int CustomAchievementSection::GetUnlockedAchievements()
{
    int numAch = 0;
    for (CustomAchievement *ach : achievements)
    {
        if (ach->ach.unlocked)
        {
            numAch++;
        }
    }
    return numAch;
}

bool CustomAchievementSection::Visible()
{
    for (CustomAchievement *ach : achievements)
    {
        if (ach->ach.unlocked)
        {
            return true;
        }
    }
    return !hidden;
}

void CustomAchievementSection::OnRender(Point pos)
{
    CSurface::GL_SetColor(CustomAchievementTracker::instance->achievementPagesBoxTextColor);
    if (GetUnlockedAchievements() < 1 && !secretHeading.data.empty())
    {
        freetype::easy_print(24, pos.x+60, pos.y, secretHeading.GetText());
    }
    else
    {
        freetype::easy_print(24, pos.x+60, pos.y, heading.GetText());
    }

    int height = GetHeight();

    GL_Texture *tex = CustomAchievementTracker::instance->statsBorder;
    if (tex)
    {
        int w2 = tex->width_/2;
        int h2 = tex->height_/2;
        int x0 = pos.x + 300 - w2;
        int y0 = pos.y + 95 - h2;
        int x1 = pos.x + tex->width_;
        int y1 = pos.y + height - 65 + h2;

        int borderHeight = height-76;

        float halfHeight = ((float)h2)/tex->height_;

        CSurface::GL_BlitImagePartial(tex, x0, y0, tex->width_, h2, 0.f, 1.f, 0.f, halfHeight, 1.f, COLOR_WHITE, false);
        CSurface::GL_BlitImagePartial(tex, x0, y0+h2, tex->width_, height-160, 0.f, 1.f, halfHeight, 1.f-halfHeight, 1.f, COLOR_WHITE, false);
        CSurface::GL_BlitImagePartial(tex, x0, y1-h2, tex->width_, h2, 0.f, 1.f, 1.f-halfHeight, 1.f, 1.f, COLOR_WHITE, false);
    }
    else
    {
        CSurface::GL_DrawRectOutline(pos.x+36, pos.y+53, 528, height-76, CustomAchievementTracker::instance->achievementPagesBoxOutlineColor, 4.f);
    }

    int i=-1;
    int j=0;

    for (CustomAchievement *ach : achievements)
    {
        if (ach->hidden && !ach->ach.unlocked) continue;
        i++;
        if (i>=7)
        {
            i=0;
            j++;
        }
        ach->ach.OnRender({pos.x+59+70*i, pos.y+63+70*j}, selectedAch == ach, true);
    }
}

void CustomAchievementSection::MouseMove(int mX, int mY)
{
    selectedAch = nullptr;

    mX -= 59;
    mY -= 63;

    int i=-1;
    int j=0;

    for (CustomAchievement *ach : achievements)
    {
        if (ach->hidden && !ach->ach.unlocked) continue;
        i++;
        if (i>=7)
        {
            i=0;
            j++;
        }
        int x = 70*i;
        int y = 70*j;

        if (mX > x && mX < x+64 && mY > y && mY < y+64)
        {
            G_->GetAchievementTracker()->SetTooltip(&ach->ach);
            selectedAch = ach;
        }
    }
}

int CustomAchievementTracker::NextPage(int page)
{
    do
    {
        page += 1;
        if (page > achievementPages.size()) page = 0;
    }
    while (page > 0 && !achievementPages[page-1].Visible());
    return page;
}
int CustomAchievementTracker::PrevPage(int page)
{
    do
    {
        page -= 1;
        if (page < 0) page = achievementPages.size();
    }
    while (page > 0 && !achievementPages[page-1].Visible());
    return page;
}

// Fix invalid memory access

static bool inSetSectorEight = false;

HOOK_METHOD(AchievementTracker, SetSectorEight, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::SetSectorEight -> Begin (CustomAchievements.cpp)\n")
    inSetSectorEight = true;
    super();
    inSetSectorEight = false;
}

HOOK_METHOD(ScoreKeeper, GetShipId, (const std::string &blueprintName) -> std::pair<int, int>)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::GetShipId -> Begin (CustomAchievements.cpp)\n")
    std::pair<int, int> ret = super(blueprintName);
    if (ret.first == -1 && inSetSectorEight) ret.first = 8; // dummy valid ship id, this affects type C unlock and crystal cruiser doesn't have a type C or any s8-related unlocks
    return ret;
}

HOOK_METHOD(AchievementTracker, CheckShipAchievements, (int shipId, bool hidePopups) -> void)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::CheckShipAchievements -> Begin (CustomAchievements.cpp)\n")
    if (shipId == -1) return;
    super(shipId, hidePopups);
}

std::vector<CAchievement*> CustomAchievementTracker::GetShipAchievementsCustom(const std::string &ship, int layout, bool showHidden)
{
    auto customSel = CustomShipSelect::GetInstance();
    int shipId = customSel->GetShipButtonIdFromName(ship);

    std::vector<CAchievement*> ret;

    if (shipId != -1)
    {
        ShipButtonDefinition &buttonDef = customSel->GetShipButtonDefinition(shipId);

        for (CustomAchievement *sAch : buttonDef.shipAchievements[layout])
        {
            if (showHidden || sAch->ach.unlocked || !sAch->hidden) ret.push_back(&sAch->ach);
        }
    }

    return ret;
}

std::vector<CAchievement*> CustomAchievementTracker::GetShipAchievementsCustom(int shipId, int layout, bool showHidden)
{
    auto customSel = CustomShipSelect::GetInstance();

    std::vector<CAchievement*> ret;

    if (shipId >= 100)
    {
        ShipButtonDefinition &buttonDef = customSel->GetShipButtonDefinition(shipId-100);

        for (CustomAchievement *sAch : buttonDef.shipAchievements[layout])
        {
            if (showHidden || sAch->ach.unlocked || !sAch->hidden) ret.push_back(&sAch->ach);
        }
    }

    return ret;
}

// Custom achievements sounds
static std::string g_customAchSounds = "";

HOOK_METHOD(AchievementTracker, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::OnLoop -> Begin (CustomAchievements.cpp)\n")

    if (recentlyUnlocked.size() > 0)
    {
        CAchievement *ach = recentlyUnlocked.front();
        if (ach)
        {
            CustomAchievementTracker *customTracker = CustomAchievementTracker::instance;
            CustomAchievement &customAch = customTracker->GetAchievement(ach->name_id);

            if (customAch.sound != "")
            {
                g_customAchSounds = customAch.sound;
            }
        }
    }

    super();
    g_customAchSounds = "";
}

HOOK_METHOD(SoundControl, PlaySoundMix, (const std::string &soundName, float volume, bool loop) -> int)
{
    LOG_HOOK("HOOK_METHOD -> SoundControl::PlaySoundMix -> Begin (CustomAchievements.cpp)\n")

    if (g_customAchSounds != "")
    {
        return super(g_customAchSounds, volume, loop);
    }
    return super(soundName, volume, loop);
}
