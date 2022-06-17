#include "CustomFleetShips.h"
#include "CustomEvents.h"
#include "boost/lexical_cast.hpp"

static std::unordered_map<std::string, FleetDefinition> g_fleetDefs = std::unordered_map<std::string, FleetDefinition>();

void ParseFleetShipNode(rapidxml::xml_node<char>* node)
{
    FleetDefinition fleetDef;

    std::string defName = "default";
    if (node->first_attribute("name"))
    {
        defName = node->first_attribute("name")->value();
    }

    fleetDef.fleetName = defName;

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string name = child->name();
        std::string val = child->value();

        if (name == "ship")
        {
            int layer = 0;

            if (child->first_attribute("layer"))
            {
                layer = boost::lexical_cast<int>(child->first_attribute("layer")->value());
            }

            fleetDef.shipTextures[layer].push_back(val);
        }
        if (name == "numShips")
        {
            int layer = 0;

            if (child->first_attribute("layer"))
            {
                layer = boost::lexical_cast<int>(child->first_attribute("layer")->value());
            }

            fleetDef.numShips[layer] = boost::lexical_cast<int>(val);
        }
        if (name == "bigShip")
        {
            fleetDef.bigShip = val;
        }
    }

    g_fleetDefs[defName] = fleetDef;
}

static std::array<std::vector<CustomFleetShip>, 5> g_currentFleetShips = std::array<std::vector<CustomFleetShip>, 5>();

void CreateFleetShips(SpaceManager *space, const FleetDefinition& def, bool rightSide, bool firing, bool autoDarkening, bool fillFullSpace=false)
{
    int minX = -40;
    int maxX = 1280;

    if (!fillFullSpace)
    {
        minX = rightSide ? 540 : -40;
        maxX = rightSide ? 1280 : 720;
    }

    for (int layer = 0; layer < 5; layer++)
    {
        if (def.shipTextures[layer].size() > 0)
        {
            for (int i = 0; i < def.numShips[layer]; i++)
            {
                CustomFleetShip ship = CustomFleetShip();

                std::string randShip = def.shipTextures[layer][random32() % def.shipTextures[layer].size()];

                ship.fleetShip.image = G_->GetResources()->GetImageId("ship/fleet/" + randShip + ".png");

                int xPos = (random32() % ((maxX + 1) - minX)) + minX;
                int yPos = (720 / def.numShips[layer]) * i + (random32() % (720 / def.numShips[layer]));

                ship.fleetShip.location = Point(xPos, yPos);
                ship.mirror = rightSide;
                ship.autoDarkening = autoDarkening;

                int currSize = g_currentFleetShips[layer].size();

                if (currSize > 0)
                {
                    g_currentFleetShips[layer].insert(g_currentFleetShips[layer].begin() + (random32() % currSize), ship);
                }
                else
                {
                    g_currentFleetShips[layer].push_back(ship);
                }
            }
        }
    }

    if (firing)
    {
        space->fleetShip = G_->GetResources()->GetImageData(G_->GetResources()->GetImageId("ship/fleet/" + def.bigShip + ".png"));
        space->fleetShip.x = 550;
        space->fleetShip.y = 447;
        space->fleetShip.w = space->fleetShip.w * 2 - 100;
        space->fleetShip.h += 25;
    }
}

static EventFleet g_leftFleet;
static EventFleet g_rightFleet;

void CreateFullFleet(SpaceManager *space, EventFleet& leftFleet, EventFleet& rightFleet)
{
    if (!leftFleet.fleetDefName.empty())
    {
        CreateFleetShips(space, g_fleetDefs[leftFleet.fleetDefName], false, leftFleet.firing, leftFleet.autoDarkening, rightFleet.fleetDefName.empty());
        g_leftFleet = leftFleet;
    }

    if (!rightFleet.fleetDefName.empty())
    {
        CreateFleetShips(space, g_fleetDefs[rightFleet.fleetDefName], true, rightFleet.firing, rightFleet.autoDarkening);
        g_rightFleet = rightFleet;
    }
}

void ClearCustomFleet(SpaceManager *space)
{
    space->fleetShip = G_->GetResources()->GetImageData(G_->GetResources()->GetImageId("ship/fleet/fleet_big.png"));
    space->fleetShip.x = 550;
    space->fleetShip.y = 447;
    space->fleetShip.w = space->fleetShip.w * 2 - 100;
    space->fleetShip.h += 25;

    for (auto& layer : g_currentFleetShips)
    {
        layer.clear();
    }

    g_leftFleet = EventFleet();
    g_rightFleet = EventFleet();

}

HOOK_METHOD(WorldManager, CreateLocation, (Location* loc) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateLocation -> Begin (CustomFleetShips.cpp)\n")
    super(loc);

    ClearCustomFleet(&space);

    auto customEvents = CustomEventsParser::GetInstance();
    auto customEvent = customEvents->GetCustomEvent(loc);

    if (customEvent != nullptr)
    {
        CreateFullFleet(&space, customEvent->leftFleet, customEvent->rightFleet);
    }
}

HOOK_METHOD(WorldManager, UpdateLocation, (LocationEvent* loc) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::UpdateLocation -> Begin (CustomFleetShips.cpp)\n")
    super(loc);

    auto customEvents = CustomEventsParser::GetInstance();
    auto customEvent = customEvents->GetCustomEvent(loc->eventName);

    if (customEvent != nullptr)
    {
        if (customEvent->clearCustomFleet)
        {
            ClearCustomFleet(&space);
        }

        if ((!customEvent->leftFleet.fleetDefName.empty() || !customEvent->rightFleet.fleetDefName.empty()) &&
            !(customEvent->leftFleet.fleetDefName == g_leftFleet.fleetDefName && customEvent->rightFleet.fleetDefName == g_rightFleet.fleetDefName))
        {
            ClearCustomFleet(&space);
            CreateFullFleet(&space, customEvent->leftFleet, customEvent->rightFleet);
        }
    }
}

HOOK_METHOD(SpaceManager, OnRenderFleet, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::OnRenderFleet -> Begin (CustomFleetShips.cpp)\n")
    int fleetCount = 0;

    for (auto& i : g_currentFleetShips)
    {
        fleetCount += i.size();
    }

    if (fleetCount == 0)
    {
        return super();
    }

    GL_Color tintColor = COLOR_WHITE;
    float maxTint = 0.f;

    if (gamePaused)
    {
        tintColor.r = ((1.f - shipHealth) * 0.4f) + 0.4f;
        tintColor.g = 0.4f;
        tintColor.b = 0.4f;

        maxTint = 0.4f;
    }
    else
    {
        float factor = ((1.f - shipHealth) * (1.f - shipHealth)) * 0.5f;
        tintColor.g = 1.f - factor;
        tintColor.b = 1.f - factor;

        maxTint = (1.f - factor);
    }

    maxTint *= 0.6f;

    CSurface::GL_PushStencilMode();

    float tintOpacity = maxTint;
    float constant = maxTint / fleetCount;

    for (auto& layer : g_currentFleetShips)
    {
        for (auto i : layer)
        {
            CSurface::GL_SetStencilMode(STENCIL_USE, 128, 128);
            G_->GetResources()->RenderImage(i.fleetShip.image, i.fleetShip.location.x, i.fleetShip.location.y + 5, 0, GL_Color(0.f, 0.f, 0.f, 1.f), 0.6f, i.mirror);

            CSurface::GL_SetStencilMode(STENCIL_SET, 128, 128);
            G_->GetResources()->RenderImage(i.fleetShip.image, i.fleetShip.location.x, i.fleetShip.location.y, 0, tintColor, 1.f, i.mirror);

            CSurface::GL_SetStencilMode(STENCIL_IGNORE, 128, 128);

            auto color = COLOR_WHITE;

            if (i.autoDarkening)
            {
                color = GL_Color(tintColor.r - tintOpacity, tintColor.g - tintOpacity, tintColor.b - tintOpacity, 1.f);
                tintOpacity -= constant;
            }

            G_->GetResources()->RenderImage(i.fleetShip.image, i.fleetShip.location.x, i.fleetShip.location.y, 0, color, 1.f, i.mirror);
        }
    }

    CSurface::GL_PopStencilMode();


    if (bPDS)
    {
        G_->GetResources()->RenderImage(fleetShip.tex, fleetShip.x, fleetShip.y, 0, tintColor, 1.f, false);
    }
}

HOOK_METHOD(SpaceManager, SaveSpace, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::SaveSpace -> Begin (CustomFleetShips.cpp)\n")
    super(file);

    if (!g_leftFleet.fleetDefName.empty())
    {
        FileHelper::writeInt(file, 1);

        FileHelper::writeString(file, g_leftFleet.fleetDefName);
        FileHelper::writeInt(file, g_leftFleet.firing);
        FileHelper::writeInt(file, g_leftFleet.autoDarkening);
    }
    else
    {
        FileHelper::writeInt(file, 0);
    }

    if (!g_rightFleet.fleetDefName.empty())
    {
        FileHelper::writeInt(file, 1);

        FileHelper::writeString(file, g_rightFleet.fleetDefName);
        FileHelper::writeInt(file, g_rightFleet.firing);
        FileHelper::writeInt(file, g_rightFleet.autoDarkening);
    }
    else
    {
        FileHelper::writeInt(file, 0);
    }
}

HOOK_METHOD(SpaceManager, LoadSpace, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::LoadSpace -> Begin (CustomFleetShips.cpp)\n")
    super(file);

    EventFleet left;
    EventFleet right;

    if (FileHelper::readInteger(file))
    {
        left.fleetDefName = FileHelper::readString(file);
        left.firing = FileHelper::readInteger(file);
        left.autoDarkening = FileHelper::readInteger(file);
    }


    if (FileHelper::readInteger(file))
    {
        right.fleetDefName = FileHelper::readString(file);
        right.firing = FileHelper::readInteger(file);
        right.autoDarkening = FileHelper::readInteger(file);
    }

    CreateFullFleet(this, left, right);
}
