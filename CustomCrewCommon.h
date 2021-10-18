#pragma once

struct StatBoostDefinition;

struct ExplosionDefinition
{
    Damage damage;
    bool shipFriendlyFire = false;
    std::vector<StatBoostDefinition*> statBoosts;
};
