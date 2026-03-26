#pragma once

/**
 * GameAccess::Seeding
 *
 * Deterministic RNG testing utilities.
 * Allows tests to set specific random seeds for reproducible results.
 */

namespace GameAccess
{
    /**
     * Utilities for seeded/deterministic testing
     */
    class Seeding
    {
    public:
        // Set the random seed for the game
        static void setSeed(unsigned int seed);
    };
}
