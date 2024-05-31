#pragma once
#include "Global.h"
#include "CustomDamage.h"
#include "StatBoost.h"
#include <memory>

struct ErosionEffect;

struct RoomAnimDef
{
    enum class RoomAnimType
    {
        DEFAULT,
        STRETCH,
        CENTER,
        RANDOM_POSITION
    };

    int renderLayer;
    RoomAnimType animType = RoomAnimType::DEFAULT;
    int animBorder = 0;
    std::string animName;
    std::string tileAnim;
    std::string wallAnim;

    void ParseRoomAnimNode(rapidxml::xml_node<char> *node);
};

struct RoomAnim
{
    std::unique_ptr<Animation> anim;
    std::vector<Animation> tileAnims;
    std::unique_ptr<Animation> wallAnim;
    int renderLayer;
    Pointf pos = {0.f, 0.f};
    int w = 0;
    int h = 0;

    void OnUpdate();
    void OnRender();
    void SaveState(int fd);
    void LoadState(int fd, Room *room);

    RoomAnim()
    {
    }

    RoomAnim(RoomAnimDef &def) :
    renderLayer{def.renderLayer}
    {
        if (!def.animName.empty())
        {
            anim.reset(new Animation(G_->GetAnimationControl()->GetAnimation(def.animName)));
            anim->Start(true);
            anim->tracker.SetLoop(true, 0.f);
        }

        if (!def.wallAnim.empty())
        {
            wallAnim.reset(new Animation(G_->GetAnimationControl()->GetAnimation(def.wallAnim)));
            wallAnim->Start(true);
            wallAnim->tracker.SetLoop(true, 0.f);
        }
    }

    RoomAnim(RoomAnimDef &def, Room *room) : RoomAnim(def)
    {
        if (room)
        {
            pos.x = room->rect.x;
            pos.y = room->rect.y;
            w = room->rect.w/35;
            h = room->rect.h/35;

            switch (def.animType)
            {
            case RoomAnimDef::RoomAnimType::STRETCH:
                {
                    float x = room->rect.w - 2*def.animBorder;
                    float y = room->rect.h - 2*def.animBorder;
                    anim->fScale = x / anim->info.frameWidth;
                    anim->fYStretch = y / (anim->info.frameHeight * anim->fScale);
                    anim->position.x = room->rect.x + def.animBorder;
                    anim->position.y = room->rect.y + def.animBorder;
                }
                break;
            case RoomAnimDef::RoomAnimType::CENTER:
                {
                    anim->position.x = room->rect.x + (room->rect.w - anim->info.frameWidth)/2;
                    anim->position.y = room->rect.y + (room->rect.h - anim->info.frameHeight)/2;
                }
                break;
            case RoomAnimDef::RoomAnimType::RANDOM_POSITION:
                {
                    int x = room->rect.w - 2*def.animBorder - anim->info.frameWidth + 1;
                    int y = room->rect.h - 2*def.animBorder - anim->info.frameHeight + 1;
                    if (x>0) anim->position.x = room->rect.x + def.animBorder + random32()%x;
                    if (y>0) anim->position.y = room->rect.y + def.animBorder + random32()%y;
                }
                break;
            default:
                anim->position.x = room->rect.x;
                anim->position.y = room->rect.y;
                break;
            }

            if (!def.tileAnim.empty())
            {
                Animation tileAnim = G_->GetAnimationControl()->GetAnimation(def.tileAnim);
                tileAnim.position.x = room->rect.x;
                tileAnim.position.y = room->rect.y;
                tileAnim.Start(true);
                tileAnim.tracker.SetLoop(true, 0.f);

                for (int i=0; i<h; ++i)
                {
                    for (int j=0; j<w; ++j)
                    {
                        tileAnims.push_back(tileAnim);
                        tileAnims.back().position.x += 35*j;
                        tileAnims.back().position.y += 35*i;
                    }
                }
            }
        }
    }
};

struct RoomStatBoost
{
    StatBoost statBoost;
    std::unique_ptr<RoomAnim> roomAnim;

    RoomStatBoost(StatBoost &&_statBoost, Room *room) : statBoost{std::move(_statBoost)}
    {
        if (statBoost.def->roomAnim)
        {
            roomAnim.reset(new RoomAnim(*statBoost.def->roomAnim, room));
        }
    }

    RoomStatBoost(StatBoost &_statBoost, Room *room) : statBoost{_statBoost}
    {
        if (statBoost.def->roomAnim)
        {
            roomAnim.reset(new RoomAnim(*statBoost.def->roomAnim, room));
        }
    }
};

struct Room_Extend
{
    Room *orig;

    std::vector<RoomAnim> roomAnims;
    bool sensorBlind = false;

    float sysDamageResistChance = 0.f;
    float ionDamageResistChance = 0.f;
    float hullDamageResistChance = 0.f;

    int timeDilation = 0;
    TemporalSystem_Wrapper* timeDilationSource = nullptr;
    Animation* speedUpAnim = nullptr;
    Animation* slowDownAnim = nullptr;

    struct Erosion
    {
        float timer = 0.f;
        float speed = 0.f;
        float systemRepairMultiplier = 1.f;
        RoomAnim *anim = nullptr;

        float amount = 0.f; // currently only used for new breaches to track progress
    };

    Erosion erosion;

    std::vector<RoomStatBoost> statBoosts = std::vector<RoomStatBoost>();

    void StartErosion(const ErosionEffect& effect);
    void StopErosion();

    ~Room_Extend();

    //CrewMember *captain;
};

Room_Extend* Get_Room_Extend(Room* c);

#define RM_EX Get_Room_Extend
