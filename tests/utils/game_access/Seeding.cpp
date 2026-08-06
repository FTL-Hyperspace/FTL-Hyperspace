#include "Seeding.h"
#include "../../../Global.h"
#include "../../../Seeds.h"

namespace GameAccess
{
    void Seeding::setSeed(unsigned int seed)
    {
        SetSeed(seed);
    }
}
