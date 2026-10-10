#pragma once
#include <string>

/**
 * TestHelpers
 *
 * High-level utility functions for tests.
 * Provides convenient functions like screenshot capture
 * that don't fit into the core framework or game access layers.
 */

namespace TestHelpers
{

    // Screenshot utilities
    bool takeScreenshot(const std::string& filename);
}
