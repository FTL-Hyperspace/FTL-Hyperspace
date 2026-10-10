#pragma once
#include <string>

/**
 * TestFramework::FileSystem
 *
 * Cross-platform file system utilities.
 * Centralizes all platform-specific code in one place.
 */

namespace TestFramework
{
    /**
     * FileSystem utilities for tests
     */
    class FileSystem
    {
    public:
        /**
         * Ensure directory exists, creating if necessary.
         * Works on macOS, Linux, and Windows.
         */
        static void ensureDirectory(const std::string& path);
    };
}
